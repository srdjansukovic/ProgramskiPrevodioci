%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "defs.h"
  #include "symtab.h"
  #include "codegen.h"
  #include "stdbool.h"
  #include <string.h>

  int yyparse(void);
  int yylex(void);
  int yyerror(char *s);
  void warning(char *s);

  extern int yylineno;
  int out_lin = 0;
  char char_buffer[CHAR_BUFFER_LENGTH];
  int error_count = 0;
  int warning_count = 0;
  int var_num = 0;
  int fun_idx = -1;
  int fcall_idx = -1;
  int lab_num = -1;
  FILE *output;

  int var_idx = -1;
  int current_type = -1; // current variable type
  int fun_ret_type = -1; // current function return type
  bool has_return = false; // used to check whether function has return statement or not
  int param_num = 0;
  int arg_num = 0;
  int paso_current_type = -1;
  bool came_from_case = false;	// used in next steps of a parser where it is useful to know where parser came from
  int case_lit_counter = 0;
  char* case_literals[SYMBOL_TABLE_LENGTH];
  unsigned switch_id_type = 0;
  bool came_from_switch = false;
  int inc_exp_var_indexes[SYMBOL_TABLE_LENGTH];	// indeksi promenljivih koje se inkrementuju u nekom iskazu
  int num_inc_exp_vars = 0;	// broj promenljivih koje se inkrementuju
  int arops_in_statement[SYMBOL_TABLE_LENGTH]; // remembers order of arops in a single statement
  int arop_num = 0;

  int mul_prec1 = -1;
  int mul_prec2 = -1;
  int mul_prec3 = -1; // remember indexes of participants in a statement where precedence is important

  int para_num = 0; // number of para paso statements for naming the labels
  int para_iter_index = -1;

  int switch_num = 0;
  int switch_id_index = -1;

  int reverse_stack_push[SYMBOL_TABLE_LENGTH];
  int  num_inc_exp_vars_false;	// za izvrsavanje inkrementa nakon false labele ako se inkrement nalazi u zagradi if-a

%}

%union {
  int i;
  char *s;
}

%token <i> _TYPE
%token _IF
%token _ELSE
%token _RETURN
%token <s> _ID
%token <s> _INT_NUMBER
%token <s> _UINT_NUMBER
%token _LPAREN
%token _RPAREN
%token _LBRACKET
%token _RBRACKET
%token _ASSIGN
%token _SEMICOLON
%token <i> _AROP
%token <i> _RELOP
%token _COMMA
%token _INC
%token _PARA // for individual task
%token _PASO // for individual task
%token _SWITCH // for individual task
%token _CASE // for individual task
%token _BREAK // for individual task
%token _DEFAULT // for individual task
%token _END_SWITCH // for individual task
%token _QMARK
%token _COLON

%type <i> num_exp exp literal 
%type <i> function_call argument rel_exp if_part conditional_operator paso_part multiple_arguments

%nonassoc ONLY_IF
%nonassoc _ELSE

%nonassoc _AROP
%nonassoc CONDITIONAL_OP

%%

program
  : global_var_list function_list
      {  
        if(lookup_symbol("main", FUN) == NO_INDEX)
          err("undefined reference to 'main'");
      }
  ;

global_var_list
  : /* empty */
  | global_var_list global_var
  ;

global_var
  : _TYPE _ID 
	{
        if(lookup_symbol($2, GVAR) == NO_INDEX){
           var_idx = insert_symbol($2, GVAR, $1, NO_ATR, NO_ATR, 0);
		   code("\n%s:\n\t\tWORD\t1", $2);
		}
        else 
           err("redefinition of '%s'", $2);	  
	}
	_SEMICOLON
  ;
  

function_list
  : function
  | function_list function
  ;

function
  : _TYPE _ID
      {
		fun_ret_type = $1; // remembers function return type
        fun_idx = lookup_symbol($2, FUN);
        if(fun_idx == NO_INDEX)
          fun_idx = insert_symbol($2, FUN, $1, NO_ATR, NO_ATR, 0);
        else 
          err("redefinition of function '%s'", $2);

        code("\n%s:", $2);
        code("\n\t\tPUSH\t%%14");
        code("\n\t\tMOV \t%%15,%%14");
      }
    _LPAREN parameter _RPAREN body
      {
		if(has_return == false && $1 != VOID)
			warn("function is expected to have a return statement");
		
		//print_symtab();/////////////////////////////////////////////////////////////////////////////////
        clear_symbols(fun_idx + 1);
        var_num = 0;
        param_num = 0;
		has_return = false;	// resets the value to false for future use

        code("\n@%s_exit:", $2);
        code("\n\t\tMOV \t%%14,%%15");
        code("\n\t\tPOP \t%%14");
        code("\n\t\tRET");
      }
  ;

parameter
  : /* empty */
      { set_atr1(fun_idx, 0); }

  | multiple_parameters // ispravka sa kontrolne tacke 1
  ;

multiple_parameters
  : _TYPE _ID
	{
		if($1 == VOID)		
			err("invalid type of data with parameter: void");	// forbids e.g. int fun(void a){}

        insert_symbol($2, PAR, $1, ++param_num, NO_ATR, 0);
        set_atr1(fun_idx, param_num);
        set_atr2(fun_idx, $1, param_num-1);
	}
  | multiple_parameters _COMMA _TYPE _ID
	{
		if($3 == VOID)		
			err("invalid type of data with parameter: void");

		insert_symbol($4, PAR, $3, ++param_num, NO_ATR, 0);
        set_atr1(fun_idx, param_num);
        set_atr2(fun_idx, $3, param_num-1);
	}
  ;


body
  : _LBRACKET variable_list
      {
        if(var_num)
          code("\n\t\tSUBS\t%%15,$%d,%%15", 4*var_num);
        code("\n@%s_body:", get_name(fun_idx));
      }
    statement_list _RBRACKET
  ;

variable_list
  : /* empty */
  | variable_list variable
  ;

variable
  : _TYPE 	
	  {	
		current_type = $1; // remembers type of variables
		if($1 == VOID)		
			err("invalid type of data with variable: void");	// forbids e.g. void c;
	  }
	id_list _SEMICOLON

  ;

id_list
	: _ID
      {
        if(lookup_symbol($1, VAR|PAR) == NO_INDEX)
           var_idx = insert_symbol($1, VAR, current_type, ++var_num, NO_ATR, 0);
        else 
           err("redefinition of '%s'", $1);
      }
	| id_list _COMMA _ID
      {
        if(lookup_symbol($3, VAR|PAR) == NO_INDEX)
           var_idx = insert_symbol($3, VAR, current_type, ++var_num, NO_ATR, 0);
        else 
           err("redefinition of '%s'", $3);
      }
	;

statement_list
  : /* empty */
  | statement_list statement
  ;

statement
  : compound_statement
  | assignment_statement
  | if_statement
  | return_statement
  | post_increment_statement
  | para_statement
  | switch_statement
  | function_call _SEMICOLON // funk(4, 5);
	{
		while(num_inc_exp_vars > 0){
			int type = get_type(inc_exp_var_indexes[num_inc_exp_vars-1]);
			code("\n\t\t%s\t", ar_instructions[(type - 1) * AROP_NUMBER]);
			gen_sym_name(inc_exp_var_indexes[num_inc_exp_vars-1]);
			code(",$1,");
			free_if_reg(inc_exp_var_indexes[num_inc_exp_vars-1]);
			int free_reg = take_reg();
			gen_sym_name(free_reg);
			set_type(free_reg, type);
			gen_mov(free_reg, inc_exp_var_indexes[num_inc_exp_vars-1]);

			num_inc_exp_vars--;
		}
	}
  ;

post_increment_statement
	: _ID _INC _SEMICOLON
	  {
		int idx = lookup_symbol($1, VAR|PAR|GVAR);
		if(idx == NO_INDEX){
			err("invalid id %s with postincrement statement", $1);		// if _ID is not variable or parameter
		}
		else{
			int type = get_type(idx);
			code("\n\t\t%s\t", ar_instructions[(type - 1) * AROP_NUMBER]);
			gen_sym_name(idx);
			code(",$1,");
			int free_reg = take_reg();
			gen_sym_name(free_reg);
			gen_mov(free_reg, idx);
			free_if_reg(idx);
		}
	  }
	;

compound_statement
  : _LBRACKET statement_list _RBRACKET
  ;

assignment_statement
  : _ID _ASSIGN num_exp _SEMICOLON
      {
        int idx = lookup_symbol($1, VAR|PAR|GVAR);
        if(idx == NO_INDEX)
          err("invalid lvalue '%s' in assignment", $1);
        else
          if(get_type(idx) != get_type($3))
            err("incompatible types in assignment");
        gen_mov($3, idx);
		while(num_inc_exp_vars > 0){
			if(idx != inc_exp_var_indexes[num_inc_exp_vars-1]){		// uslov if dodat ako je sa leve strane jednakosti promenljiva koju sa 
																	// desne strane inkrementujemo, tada ne treba da se izvrsi inkrement 
																	// asemblerski iskaz
				int type = get_type(inc_exp_var_indexes[num_inc_exp_vars-1]);
				code("\n\t\t%s\t", ar_instructions[(type - 1) * AROP_NUMBER]);
				gen_sym_name(inc_exp_var_indexes[num_inc_exp_vars-1]);
				code(",$1,");
				free_if_reg(inc_exp_var_indexes[num_inc_exp_vars-1]);
				int free_reg = take_reg();
				gen_sym_name(free_reg);
				set_type(free_reg, type);
				gen_mov(free_reg, inc_exp_var_indexes[num_inc_exp_vars-1]);

			}
				num_inc_exp_vars--;
		}
      }
  ;

num_exp
  : exp
  | num_exp _AROP exp
    {	
    	if($2 == DIV && atoi(get_name($3)) == 0){
    		err("cannot divide with zero");
    	}
    	
        if(get_type($1) != get_type($3)){
          err("invalid operands: arithmetic operation");	
		  mul_prec2 = 0;
		}

		if(mul_prec2 != 0){ // da ne bismo pristupali nedozvoljenoj memoriji

			if($2 == ADD || $2 == SUB){
				mul_prec1 = $1;
			}
			int t1 = get_type($1); 
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			if(($2 == MUL || $2 == DIV) && mul_prec1 != -1) {

					//subs $1, mul_prec1, $1
					if(t1 == INT)
						code("\n\t\t%s\t", "SUBS");
					else if(t1 == UINT)
						code("\n\t\t%s\t", "SUBU");
					gen_sym_name($1);
					code(",");
					gen_sym_name(mul_prec1);
					code(",");
					gen_sym_name($1);
				   //muls
				code("\n\t\t%s\t", ar_instructions[$2 + (t1 - 1) * AROP_NUMBER]);
				gen_sym_name($1);
				code(",");
				gen_sym_name($3);
				code(",");
				free_if_reg($3);
				free_if_reg($1); /////////////////////////// probaj zakomentarisati
				int free_reg = take_reg();
				gen_sym_name(free_reg);

					//adds free_reg, mul_prec1, free_reg
					if(t1 == INT)
						code("\n\t\t%s\t", "ADDS");
					else if(t1 == UINT)
						code("\n\t\t%s\t", "ADDU");
					gen_sym_name(free_reg);
					code(",");
					gen_sym_name(mul_prec1);
					code(",");
					gen_sym_name(free_reg);
					$$ = free_reg;
					set_type($$, t1);
					//mul_prec1 = $1;
			}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			else{   
				code("\n\t\t%s\t", ar_instructions[$2 + (t1 - 1) * AROP_NUMBER]);
				gen_sym_name($1);
				code(",");
				gen_sym_name($3);
				code(",");
				free_if_reg($3);
				//free_if_reg($1);/////////////////////////////
				$$ = take_reg();
				gen_sym_name($$);
				set_type($$, t1);
				//mul_prec2 = $$; // used as a flag, anything except for 0 is acceptable
				//mul_prec1 = 0;
			}
		} // if(mul_prec2 != 0)

    }
  ;

exp
  : literal
  | _ID
      {
        $$ = lookup_symbol($1, VAR|PAR|GVAR);
        if($$ == NO_INDEX)
          err("'%s' undeclared", $1);
      }
  | _ID _INC 
	  {
        int idx = lookup_symbol($1, VAR|PAR|GVAR);
        $$ = idx;
        if($$ == NO_INDEX)
          err("'%s' undeclared", $1);

		if(lookup_symbol($1, VAR|PAR|GVAR) == NO_INDEX)
			err("invalid id %s with postincrement statement", $1);			// if _ID is not variable or parameter	

		if($$ != NO_INDEX) 
			inc_exp_var_indexes[num_inc_exp_vars++] = lookup_symbol($1, VAR|PAR|GVAR);
      }	
  | function_call // sadrzi indeks registra u koji je smestena vrednost %13 pri pozivu
      {
        $$ = take_reg();
        gen_mov(FUN_REG, $$);
      }
  | _LPAREN num_exp _RPAREN
      { $$ = $2; }
  | conditional_operator
  ;

literal
  : _INT_NUMBER
      { 
		if(came_from_case){
			int i;
			case_literals[case_lit_counter - 1] = $1;
			for(i = 0; i < case_lit_counter-1; ++i){
				  if(strcmp(case_literals[i], $1) == 0)
					err("constants in case expressions should be unique and the same type");	// throws error if either of the conditions
																								// is not met
			}

		}
		$$ = insert_literal($1, INT); 
		if(came_from_switch && switch_id_type != get_type($$) && came_from_case){
			err("case constants must be the same type as switch variable");
			came_from_switch = false;	// used to remember variable right after 'switch'
		}
			came_from_case = false; // only important literal in the entire statement is the one after 'case'
   	  }

  | _UINT_NUMBER
      { 
		if(came_from_case){
			int i;
			case_literals[case_lit_counter - 1] = $1;
			for(i = 0; i < case_lit_counter - 1; ++i){
				if(strcmp(case_literals[i], $1) == 0)
					err("constants in case expressions should be unique and the same type");
			}

		}
		$$ = insert_literal($1, UINT); 
		if(came_from_switch && switch_id_type != get_type($$) && came_from_case){
			err("case constants must be the same type as switch variable");
			came_from_switch = false;	// used to remember variable right after 'switch'
		}
			came_from_case = false; // only important literal in the entire statement is the one after 'case' 
	  }
  ;

function_call
  : _ID 
      {
        fcall_idx = lookup_symbol($1, FUN);
        if(fcall_idx == NO_INDEX)
          err("'%s' is not a function", $1);
      }
    _LPAREN argument _RPAREN
      {
        if(get_atr1(fcall_idx) != $4)
          err("wrong number of arguments");
        code("\n\t\t\tCALL\t%s", get_name(fcall_idx));
        if($4 > 0)
          code("\n\t\t\tADDS\t%%15,$%d,%%15", $4 * 4);
        set_type(FUN_REG, get_type(fcall_idx));
        $$ = FUN_REG;
		arg_num = 0; // resets number of arguments to 0 for future use
      }
  ;

argument
  : /* empty */
    { $$ = 0; }
  | multiple_arguments
  	{ // reverse stack pushing
  		int j;
  		for(j = arg_num-1; j >= 0; j--){
  			code("\n\t\t\tPUSH\t");
			gen_sym_name(reverse_stack_push[j]);
  		}
  	}
  ;

multiple_arguments
  : num_exp
    { 
      if(get_atr2(fcall_idx, arg_num++) != get_type($1)){		// atr2[arg_num] == type(num_exp) ?? 
        err("incompatible type for argument in '%s'", get_name(fcall_idx));
	  }
      free_if_reg($1);
      //code("\n\t\t\tPUSH\t");
      //gen_sym_name($1);
      reverse_stack_push[arg_num - 1] = $1;
      $$ = arg_num;
    }
  | multiple_arguments _COMMA num_exp
	{
      if(get_atr2(fcall_idx, arg_num++) != get_type($3))
        err("incompatible type for argument in '%s'",
            get_name(fcall_idx));
      $$ = arg_num;
      reverse_stack_push[arg_num - 1] = $3;
      //code("\n\t\t\tPUSH\t");
      //gen_sym_name($3);

	}
  ;

if_statement
  : if_part %prec ONLY_IF
      { code("\n@exit%d:", $1); }

  | if_part _ELSE statement
      { code("\n@exit%d:", $1); }
  ;

if_part
  : _IF _LPAREN
      {
        $<i>$ = ++lab_num;
        code("\n@if%d:", lab_num);
      }
    rel_exp
      {
        code("\n\t\t%s\t@false%d", opp_jumps[$4], $<i>3); 
        code("\n@true%d:", $<i>3);
        
        num_inc_exp_vars_false = num_inc_exp_vars;
        while(num_inc_exp_vars > 0){
			int type = get_type(inc_exp_var_indexes[num_inc_exp_vars-1]);
			code("\n\t\t%s\t", ar_instructions[(type - 1) * AROP_NUMBER]);
			gen_sym_name(inc_exp_var_indexes[num_inc_exp_vars-1]);
			code(",$1,");
			free_if_reg(inc_exp_var_indexes[num_inc_exp_vars-1]);
			int free_reg = take_reg();
			gen_sym_name(free_reg);
			set_type(free_reg, type);
			gen_mov(free_reg, inc_exp_var_indexes[num_inc_exp_vars-1]);

			num_inc_exp_vars--;
		}
      }
    _RPAREN statement
      {
        code("\n\t\tJMP \t@exit%d", $<i>3);
        code("\n@false%d:", $<i>3);
        
        num_inc_exp_vars = num_inc_exp_vars_false;       
        while(num_inc_exp_vars > 0){
			int type = get_type(inc_exp_var_indexes[num_inc_exp_vars-1]);
			code("\n\t\t%s\t", ar_instructions[(type - 1) * AROP_NUMBER]);
			gen_sym_name(inc_exp_var_indexes[num_inc_exp_vars-1]);
			code(",$1,");
			free_if_reg(inc_exp_var_indexes[num_inc_exp_vars-1]);
			int free_reg = take_reg();
			gen_sym_name(free_reg);
			set_type(free_reg, type);
			gen_mov(free_reg, inc_exp_var_indexes[num_inc_exp_vars-1]);

			num_inc_exp_vars--;
		}
        
        $$ = $<i>3;
      }
  ;

rel_exp
  : num_exp _RELOP num_exp
      {
        if(get_type($1) != get_type($3))
          err("invalid operands: relational operator");
        $$ = $2 + ((get_type($1) - 1) * RELOP_NUMBER);
        gen_cmp($1, $3);

      }
  ;



return_statement
  : _RETURN num_exp _SEMICOLON
      {
		has_return = true;
        if(get_type(fun_idx) != get_type($2))
          err("incompatible types in return");
		if(fun_ret_type == VOID)
		  err("void type function should not return value");
        gen_mov($2, FUN_REG);
        code("\n\t\tJMP \t@%s_exit", get_name(fun_idx));        
      }
  | _RETURN _SEMICOLON
	  {
		has_return = true;
		if(fun_ret_type != VOID)
		  warn("function expected to return a value");
	  }
  ;

para_statement
  : _PARA _LPAREN _TYPE _ID 
	{   
		if(lookup_symbol($4, VAR|PAR|GVAR) == NO_INDEX){
           var_idx = insert_symbol($4, VAR, $3, ++var_num, PARA_ATR, 0);
		   para_iter_index = var_idx;

		}
        else 
           err("iterator '%s' is a global variable for para statement and cannot be reused", $4);

	}
	_ASSIGN literal 
	{
		gen_mov($7, var_idx);
		code("\n@para%d:", para_num);
		para_num++;
	}
	_SEMICOLON rel_exp 
	{
		code("\n\t\t%s\t@para_end%d", opp_jumps[$10], para_num-1);	
	}
	_SEMICOLON paso_part _RPAREN statement // izmena od KT1 - umesto cond_exp koristi se rel_exp
	{
		if(paso_current_type == -1){	// if there is no paso part
			if(get_type($7) != $3)
 	          err("incompatible types with paso statement literals");
		}
		else{	// if there is paso part
			if(get_type($7) != paso_current_type || get_type($7) != $3 || $3 != paso_current_type)
 	          err("incompatible types with paso statement literals");
		}
		paso_current_type = -1;

		if($13 == -1){
			code("\n\t\t%s\t", ar_instructions[($3 - 1) * AROP_NUMBER]);
			gen_sym_name(para_iter_index);
			code(",$1,");
			free_if_reg(para_iter_index);
			int free_reg = take_reg();
			gen_sym_name(free_reg);
			set_type(free_reg, $3);
			gen_mov(free_reg, para_iter_index);
		}	
		else {
			code("\n\t\t%s\t", ar_instructions[($3 - 1) * AROP_NUMBER]);
			gen_sym_name(para_iter_index);
			code(",");
			gen_sym_name($13);
			code(",");
			free_if_reg(para_iter_index);
			int free_reg = take_reg();
			gen_sym_name(free_reg);
			set_type(free_reg, paso_current_type);
			gen_mov(free_reg, para_iter_index);
		}

		gen_cmp($7, $7);
		code("\n\t\t%s\t@para%d", jumps[4], para_num-1);
		code("\n@para_end%d:", para_num-1);
	}
  ;

paso_part
  : /* empty */ 
  { 
		$$ = -1;
  }				
  | _PASO literal
	{
		paso_current_type = get_type($2);	// remembers type of literal
		$$ = $2;
	}
  ;


switch_statement 
  : _SWITCH _ID 
	{
		int idx = lookup_symbol($2, VAR|PAR|GVAR);
		if(idx == NO_INDEX)
           err("variable %s must be previously defined", $2);
           
        switch_id_index = idx;
        
		switch_id_type = get_type(idx);
		came_from_switch = true;
		
		code("\n@switch%d:", switch_num);
		switch_num++;
	}
	case_part default_part _END_SWITCH
	{
		switch_id_type = 0;
		
		code("\n@sw_end%d:", switch_num - 1);
	}
  ;

case_part
  : _CASE 
	{
		case_lit_counter++;
		came_from_case = true;
	}
	literal 
	{
		set_atr1($3, CASE_LIT_ATR);
		//$$ = $3;
		gen_cmp($3, switch_id_index);
		code("\n\t\t%s\t@sw%d", jumps[4], case_lit_counter - 1);
		code("\n@sw%d:", case_lit_counter - 1);
		
	}
	statement break_part
  | case_part _CASE 
	{
		case_lit_counter++;
		came_from_case = true;
	} 
	literal
	{
		set_atr1($4, CASE_LIT_ATR);
		//$$ = $4;
		gen_cmp($4, switch_id_index);
		code("\n\t\t%s\t@sw%d", jumps[4], case_lit_counter - 1);
		code("\n@sw%d:", case_lit_counter - 1);
	}
	statement break_part
  ;

break_part
  : /* empty */
  | _BREAK _SEMICOLON
  {
  	gen_cmp(switch_id_index, switch_id_index);
  	code("\n\t\t%s\t@sw_end%d", jumps[4], switch_num - 1);
  }
  ;

default_part
  : _DEFAULT statement
  ;

conditional_operator
  : _LPAREN rel_exp 
	{
		lab_num++;
        code("\n\t\t%s\t@false%d", opp_jumps[$2], lab_num);		
	}
	_RPAREN _QMARK num_exp _COLON num_exp %prec CONDITIONAL_OP
	{
		if(get_type($6) != get_type($8)){
			err("incompatible types in conditional operator");
		}

		$$ = take_reg();
		set_type($$, get_type($6));

        code("\n@true%d:", lab_num);

		gen_mov($6, $$);		
        code("\n\t\tJMP \t@exit%d", lab_num);
        code("\n@false%d:", lab_num);
		gen_mov($8, $$);
        code("\n@exit%d:", lab_num);
	}
  ;



%%

int yyerror(char *s) {
  fprintf(stderr, "\nline %d: ERROR: %s", yylineno, s);
  error_count++;
  return 0;
}

void warning(char *s) {
  fprintf(stderr, "\nline %d: WARNING: %s", yylineno, s);
  warning_count++;
}

int main() {
  int synerr;
  init_symtab();
  output = fopen("output.asm", "w+");

  synerr = yyparse();

  clear_symtab();
  fclose(output);
  
  if(warning_count)
    printf("\n%d warning(s).\n", warning_count);

  if(error_count) {
    remove("output.asm");
    printf("\n%d error(s).\n", error_count);
  }

  if(synerr)
    return -1;  //syntax error
  else if(error_count)
    return error_count & 127; //semantic errors
  else if(warning_count)
    return (warning_count & 127) + 127; //warnings
  else
    return 0; //OK
}

