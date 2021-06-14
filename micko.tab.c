/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "micko.y" /* yacc.c:339  */

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


#line 123 "micko.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "micko.tab.h".  */
#ifndef YY_YY_MICKO_TAB_H_INCLUDED
# define YY_YY_MICKO_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    _TYPE = 258,
    _IF = 259,
    _ELSE = 260,
    _RETURN = 261,
    _ID = 262,
    _INT_NUMBER = 263,
    _UINT_NUMBER = 264,
    _LPAREN = 265,
    _RPAREN = 266,
    _LBRACKET = 267,
    _RBRACKET = 268,
    _ASSIGN = 269,
    _SEMICOLON = 270,
    _AROP = 271,
    _RELOP = 272,
    _COMMA = 273,
    _INC = 274,
    _PARA = 275,
    _PASO = 276,
    _SWITCH = 277,
    _CASE = 278,
    _BREAK = 279,
    _DEFAULT = 280,
    _END_SWITCH = 281,
    _QMARK = 282,
    _COLON = 283,
    ONLY_IF = 284,
    CONDITIONAL_OP = 285
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 58 "micko.y" /* yacc.c:355  */

  int i;
  char *s;

#line 199 "micko.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MICKO_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 216 "micko.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   123

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  141

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   102,   102,   109,   111,   116,   115,   129,   130,   135,
     134,   167,   169,   173,   182,   196,   195,   204,   206,   211,
     210,   221,   228,   237,   239,   243,   244,   245,   246,   247,
     248,   249,   250,   269,   289,   293,   323,   324,   400,   401,
     407,   420,   425,   427,   431,   451,   473,   472,   493,   494,
     505,   516,   530,   533,   539,   544,   538,   588,   601,   611,
     621,   632,   638,   620,   684,   687,   697,   696,   720,   725,
     719,   735,   740,   734,   750,   752,   760,   765,   764
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_TYPE", "_IF", "_ELSE", "_RETURN",
  "_ID", "_INT_NUMBER", "_UINT_NUMBER", "_LPAREN", "_RPAREN", "_LBRACKET",
  "_RBRACKET", "_ASSIGN", "_SEMICOLON", "_AROP", "_RELOP", "_COMMA",
  "_INC", "_PARA", "_PASO", "_SWITCH", "_CASE", "_BREAK", "_DEFAULT",
  "_END_SWITCH", "_QMARK", "_COLON", "ONLY_IF", "CONDITIONAL_OP",
  "$accept", "program", "global_var_list", "global_var", "$@1",
  "function_list", "function", "$@2", "parameter", "multiple_parameters",
  "body", "$@3", "variable_list", "variable", "$@4", "id_list",
  "statement_list", "statement", "post_increment_statement",
  "compound_statement", "assignment_statement", "num_exp", "exp",
  "literal", "function_call", "$@5", "argument", "multiple_arguments",
  "if_statement", "if_part", "@6", "$@7", "rel_exp", "return_statement",
  "para_statement", "$@8", "$@9", "$@10", "paso_part", "switch_statement",
  "$@11", "case_part", "$@12", "$@13", "$@14", "$@15", "break_part",
  "default_part", "conditional_operator", "$@16", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285
};
# endif

#define YYPACT_NINF -102

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-102)))

#define YYTABLE_NINF -47

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
    -102,    10,    51,  -102,    14,  -102,    58,  -102,    54,    60,
    -102,    53,    62,  -102,  -102,    67,    68,    63,    69,  -102,
      65,    83,  -102,  -102,    81,    87,  -102,  -102,  -102,  -102,
      84,     2,  -102,    27,    85,    23,     4,  -102,  -102,    86,
      90,  -102,  -102,  -102,  -102,    78,  -102,    93,  -102,  -102,
    -102,  -102,    92,  -102,    -7,  -102,  -102,    75,  -102,     1,
    -102,  -102,  -102,  -102,    75,    88,    91,    40,    97,  -102,
    -102,    59,  -102,    75,  -102,     9,  -102,  -102,    75,    13,
    -102,    75,  -102,    95,    82,  -102,    32,  -102,  -102,    75,
      96,  -102,  -102,    94,    98,    99,  -102,  -102,    18,   100,
      94,    77,  -102,    75,   101,    49,  -102,    59,    80,    59,
      75,    94,    49,  -102,    49,  -102,  -102,  -102,    -9,  -102,
      59,  -102,    75,   103,    89,    59,  -102,    75,   104,  -102,
      89,  -102,  -102,  -102,   105,   102,    49,   110,  -102,    59,
    -102
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     1,     0,     4,     2,     7,     5,     0,
       8,     0,     0,     9,     6,    11,     0,     0,    12,    13,
       0,     0,    17,    10,     0,    15,    14,    19,    23,    18,
       0,     0,    21,     0,     0,     0,    46,    23,    16,     0,
       0,    24,    29,    25,    26,     0,    27,    52,    28,    30,
      31,    20,     0,    54,    39,    44,    45,     0,    59,     0,
      36,    38,    41,    43,     0,     0,     0,     0,     0,    66,
      32,     0,    22,     0,    40,     0,    77,    58,     0,     0,
      33,    48,    34,     0,     0,    53,     0,    55,    42,     0,
       0,    37,    35,    50,     0,    49,    60,    68,     0,     0,
      57,     0,    47,     0,     0,     0,    71,     0,     0,     0,
       0,    51,     0,    69,     0,    76,    67,    56,     0,    61,
       0,    72,     0,     0,    74,     0,    78,     0,     0,    70,
      74,    62,    75,    73,     0,    64,     0,     0,    65,     0,
      63
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -102,  -102,  -102,  -102,  -102,  -102,   106,  -102,  -102,  -102,
    -102,  -102,  -102,  -102,  -102,  -102,    79,   -70,  -102,  -102,
    -102,   -30,    36,  -101,   -31,  -102,  -102,  -102,  -102,  -102,
    -102,  -102,   -71,  -102,  -102,  -102,  -102,  -102,  -102,  -102,
    -102,  -102,  -102,  -102,  -102,  -102,    -8,  -102,  -102,  -102
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     5,    11,     6,     7,    12,    17,    18,
      23,    28,    25,    29,    30,    33,    31,    41,    42,    43,
      44,    86,    60,    61,    62,    66,    94,    95,    46,    47,
      73,    99,    76,    48,    49,   104,   123,   134,   137,    50,
      84,    98,   105,   120,   114,   125,   129,   108,    63,    90
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    85,    87,   -46,   113,    59,    34,    78,    35,    36,
       3,   119,    74,   121,    37,    38,    77,    78,    64,   122,
      88,     8,    39,    65,    40,    78,    89,    75,    92,    78,
      54,    55,    56,    57,    79,   138,    45,   115,    58,   117,
      45,   106,    51,   107,    34,    52,    35,    36,    78,    89,
     124,    93,    37,    82,     4,   130,   131,    55,    56,   100,
      39,     9,    40,    34,    -9,    35,    36,    13,    14,   140,
      16,    37,    15,   111,    20,    19,    45,    22,    45,    39,
     118,    40,    54,    55,    56,    57,    24,    21,    26,    45,
      27,    32,   126,    70,    45,    53,    68,    69,    71,    72,
      83,    81,    96,    80,   110,    97,   116,   101,    45,   102,
      78,   109,    10,   128,    91,   112,    67,   103,   127,   132,
     135,   139,   133,   136
};

static const yytype_uint8 yycheck[] =
{
      31,    71,    73,    10,   105,    35,     4,    16,     6,     7,
       0,   112,    19,   114,    12,    13,    15,    16,    14,    28,
      11,     7,    20,    19,    22,    16,    17,    57,    15,    16,
       7,     8,     9,    10,    64,   136,    67,   107,    15,   109,
      71,    23,    15,    25,     4,    18,     6,     7,    16,    17,
     120,    81,    12,    13,     3,   125,   127,     8,     9,    89,
      20,     3,    22,     4,    10,     6,     7,     7,    15,   139,
       3,    12,    10,   103,    11,     7,   107,    12,   109,    20,
     110,    22,     7,     8,     9,    10,     3,    18,     7,   120,
       3,     7,   122,    15,   125,    10,    10,     7,     5,     7,
       3,    10,     7,    15,    27,    23,    26,    11,   139,    11,
      16,    11,     6,    24,    78,    14,    37,    18,    15,    15,
      15,    11,   130,    21
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    33,     0,     3,    34,    36,    37,     7,     3,
      37,    35,    38,     7,    15,    10,     3,    39,    40,     7,
      11,    18,    12,    41,     3,    43,     7,     3,    42,    44,
      45,    47,     7,    46,     4,     6,     7,    12,    13,    20,
      22,    48,    49,    50,    51,    55,    59,    60,    64,    65,
      70,    15,    18,    10,     7,     8,     9,    10,    15,    52,
      53,    54,    55,    79,    14,    19,    56,    47,    10,     7,
      15,     5,     7,    61,    19,    52,    63,    15,    16,    52,
      15,    10,    13,     3,    71,    48,    52,    63,    11,    17,
      80,    53,    15,    52,    57,    58,     7,    23,    72,    62,
      52,    11,    11,    18,    66,    73,    23,    25,    78,    11,
      27,    52,    14,    54,    75,    48,    26,    48,    52,    54,
      74,    54,    28,    67,    48,    76,    52,    15,    24,    77,
      48,    63,    15,    77,    68,    15,    21,    69,    54,    11,
      48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    31,    32,    33,    33,    35,    34,    36,    36,    38,
      37,    39,    39,    40,    40,    42,    41,    43,    43,    45,
      44,    46,    46,    47,    47,    48,    48,    48,    48,    48,
      48,    48,    48,    49,    50,    51,    52,    52,    53,    53,
      53,    53,    53,    53,    54,    54,    56,    55,    57,    57,
      58,    58,    59,    59,    61,    62,    60,    63,    64,    64,
      66,    67,    68,    65,    69,    69,    71,    70,    73,    74,
      72,    75,    76,    72,    77,    77,    78,    80,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     0,     4,     1,     2,     0,
       7,     0,     1,     2,     4,     0,     5,     0,     2,     0,
       4,     1,     3,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     3,     4,     1,     3,     1,     1,
       2,     1,     3,     1,     1,     1,     0,     5,     0,     1,
       1,     3,     1,     3,     0,     0,     7,     3,     3,     2,
       0,     0,     0,    15,     0,     2,     0,     6,     0,     0,
       6,     0,     0,     7,     0,     2,     2,     0,     8
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 103 "micko.y" /* yacc.c:1646  */
    {  
        if(lookup_symbol("main", FUN) == NO_INDEX)
          err("undefined reference to 'main'");
      }
#line 1398 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 116 "micko.y" /* yacc.c:1646  */
    {
        if(lookup_symbol((yyvsp[0].s), GVAR) == NO_INDEX){
           var_idx = insert_symbol((yyvsp[0].s), GVAR, (yyvsp[-1].i), NO_ATR, NO_ATR, 0);
		   code("\n%s:\n\t\tWORD\t1", (yyvsp[0].s));
		}
        else 
           err("redefinition of '%s'", (yyvsp[0].s));	  
	}
#line 1411 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 135 "micko.y" /* yacc.c:1646  */
    {
		fun_ret_type = (yyvsp[-1].i); // remembers function return type
        fun_idx = lookup_symbol((yyvsp[0].s), FUN);
        if(fun_idx == NO_INDEX)
          fun_idx = insert_symbol((yyvsp[0].s), FUN, (yyvsp[-1].i), NO_ATR, NO_ATR, 0);
        else 
          err("redefinition of function '%s'", (yyvsp[0].s));

        code("\n%s:", (yyvsp[0].s));
        code("\n\t\tPUSH\t%%14");
        code("\n\t\tMOV \t%%15,%%14");
      }
#line 1428 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 148 "micko.y" /* yacc.c:1646  */
    {
		if(has_return == false && (yyvsp[-6].i) != VOID)
			warn("function is expected to have a return statement");
		
		//print_symtab();/////////////////////////////////////////////////////////////////////////////////
        clear_symbols(fun_idx + 1);
        var_num = 0;
        param_num = 0;
		has_return = false;	// resets the value to false for future use

        code("\n@%s_exit:", (yyvsp[-5].s));
        code("\n\t\tMOV \t%%14,%%15");
        code("\n\t\tPOP \t%%14");
        code("\n\t\tRET");
      }
#line 1448 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 167 "micko.y" /* yacc.c:1646  */
    { set_atr1(fun_idx, 0); }
#line 1454 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 174 "micko.y" /* yacc.c:1646  */
    {
		if((yyvsp[-1].i) == VOID)		
			err("invalid type of data with parameter: void");	// forbids e.g. int fun(void a){}

        insert_symbol((yyvsp[0].s), PAR, (yyvsp[-1].i), ++param_num, NO_ATR, 0);
        set_atr1(fun_idx, param_num);
        set_atr2(fun_idx, (yyvsp[-1].i), param_num-1);
	}
#line 1467 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 183 "micko.y" /* yacc.c:1646  */
    {
		if((yyvsp[-1].i) == VOID)		
			err("invalid type of data with parameter: void");

		insert_symbol((yyvsp[0].s), PAR, (yyvsp[-1].i), ++param_num, NO_ATR, 0);
        set_atr1(fun_idx, param_num);
        set_atr2(fun_idx, (yyvsp[-1].i), param_num-1);
	}
#line 1480 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 196 "micko.y" /* yacc.c:1646  */
    {
        if(var_num)
          code("\n\t\tSUBS\t%%15,$%d,%%15", 4*var_num);
        code("\n@%s_body:", get_name(fun_idx));
      }
#line 1490 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 211 "micko.y" /* yacc.c:1646  */
    {	
		current_type = (yyvsp[0].i); // remembers type of variables
		if((yyvsp[0].i) == VOID)		
			err("invalid type of data with variable: void");	// forbids e.g. void c;
	  }
#line 1500 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 222 "micko.y" /* yacc.c:1646  */
    {
        if(lookup_symbol((yyvsp[0].s), VAR|PAR) == NO_INDEX)
           var_idx = insert_symbol((yyvsp[0].s), VAR, current_type, ++var_num, NO_ATR, 0);
        else 
           err("redefinition of '%s'", (yyvsp[0].s));
      }
#line 1511 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 229 "micko.y" /* yacc.c:1646  */
    {
        if(lookup_symbol((yyvsp[0].s), VAR|PAR) == NO_INDEX)
           var_idx = insert_symbol((yyvsp[0].s), VAR, current_type, ++var_num, NO_ATR, 0);
        else 
           err("redefinition of '%s'", (yyvsp[0].s));
      }
#line 1522 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 251 "micko.y" /* yacc.c:1646  */
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
#line 1542 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 270 "micko.y" /* yacc.c:1646  */
    {
		int idx = lookup_symbol((yyvsp[-2].s), VAR|PAR|GVAR);
		if(idx == NO_INDEX){
			err("invalid id %s with postincrement statement", (yyvsp[-2].s));		// if _ID is not variable or parameter
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
#line 1563 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 294 "micko.y" /* yacc.c:1646  */
    {
        int idx = lookup_symbol((yyvsp[-3].s), VAR|PAR|GVAR);
        if(idx == NO_INDEX)
          err("invalid lvalue '%s' in assignment", (yyvsp[-3].s));
        else
          if(get_type(idx) != get_type((yyvsp[-1].i)))
            err("incompatible types in assignment");
        gen_mov((yyvsp[-1].i), idx);
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
#line 1594 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 325 "micko.y" /* yacc.c:1646  */
    {	
    	if((yyvsp[-1].i) == DIV && atoi(get_name((yyvsp[0].i))) == 0){
    		err("cannot divide with zero");
    	}
    	
        if(get_type((yyvsp[-2].i)) != get_type((yyvsp[0].i))){
          err("invalid operands: arithmetic operation");	
		  mul_prec2 = 0;
		}

		if(mul_prec2 != 0){ // da ne bismo pristupali nedozvoljenoj memoriji

			if((yyvsp[-1].i) == ADD || (yyvsp[-1].i) == SUB){
				mul_prec1 = (yyvsp[-2].i);
			}
			int t1 = get_type((yyvsp[-2].i)); 
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			if(((yyvsp[-1].i) == MUL || (yyvsp[-1].i) == DIV) && mul_prec1 != -1) {

					//subs $1, mul_prec1, $1
					if(t1 == INT)
						code("\n\t\t%s\t", "SUBS");
					else if(t1 == UINT)
						code("\n\t\t%s\t", "SUBU");
					gen_sym_name((yyvsp[-2].i));
					code(",");
					gen_sym_name(mul_prec1);
					code(",");
					gen_sym_name((yyvsp[-2].i));
				   //muls
				code("\n\t\t%s\t", ar_instructions[(yyvsp[-1].i) + (t1 - 1) * AROP_NUMBER]);
				gen_sym_name((yyvsp[-2].i));
				code(",");
				gen_sym_name((yyvsp[0].i));
				code(",");
				free_if_reg((yyvsp[0].i));
				free_if_reg((yyvsp[-2].i)); /////////////////////////// probaj zakomentarisati
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
					(yyval.i) = free_reg;
					set_type((yyval.i), t1);
					//mul_prec1 = $1;
			}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			else{   
				code("\n\t\t%s\t", ar_instructions[(yyvsp[-1].i) + (t1 - 1) * AROP_NUMBER]);
				gen_sym_name((yyvsp[-2].i));
				code(",");
				gen_sym_name((yyvsp[0].i));
				code(",");
				free_if_reg((yyvsp[0].i));
				//free_if_reg($1);/////////////////////////////
				(yyval.i) = take_reg();
				gen_sym_name((yyval.i));
				set_type((yyval.i), t1);
				//mul_prec2 = $$; // used as a flag, anything except for 0 is acceptable
				//mul_prec1 = 0;
			}
		} // if(mul_prec2 != 0)

    }
#line 1671 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 402 "micko.y" /* yacc.c:1646  */
    {
        (yyval.i) = lookup_symbol((yyvsp[0].s), VAR|PAR|GVAR);
        if((yyval.i) == NO_INDEX)
          err("'%s' undeclared", (yyvsp[0].s));
      }
#line 1681 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 408 "micko.y" /* yacc.c:1646  */
    {
        int idx = lookup_symbol((yyvsp[-1].s), VAR|PAR|GVAR);
        (yyval.i) = idx;
        if((yyval.i) == NO_INDEX)
          err("'%s' undeclared", (yyvsp[-1].s));

		if(lookup_symbol((yyvsp[-1].s), VAR|PAR|GVAR) == NO_INDEX)
			err("invalid id %s with postincrement statement", (yyvsp[-1].s));			// if _ID is not variable or parameter	

		if((yyval.i) != NO_INDEX) 
			inc_exp_var_indexes[num_inc_exp_vars++] = lookup_symbol((yyvsp[-1].s), VAR|PAR|GVAR);
      }
#line 1698 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 421 "micko.y" /* yacc.c:1646  */
    {
        (yyval.i) = take_reg();
        gen_mov(FUN_REG, (yyval.i));
      }
#line 1707 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 426 "micko.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[-1].i); }
#line 1713 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 432 "micko.y" /* yacc.c:1646  */
    { 
		if(came_from_case){
			int i;
			case_literals[case_lit_counter - 1] = (yyvsp[0].s);
			for(i = 0; i < case_lit_counter-1; ++i){
				  if(strcmp(case_literals[i], (yyvsp[0].s)) == 0)
					err("constants in case expressions should be unique and the same type");	// throws error if either of the conditions
																								// is not met
			}

		}
		(yyval.i) = insert_literal((yyvsp[0].s), INT); 
		if(came_from_switch && switch_id_type != get_type((yyval.i)) && came_from_case){
			err("case constants must be the same type as switch variable");
			came_from_switch = false;	// used to remember variable right after 'switch'
		}
			came_from_case = false; // only important literal in the entire statement is the one after 'case'
   	  }
#line 1736 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 452 "micko.y" /* yacc.c:1646  */
    { 
		if(came_from_case){
			int i;
			case_literals[case_lit_counter - 1] = (yyvsp[0].s);
			for(i = 0; i < case_lit_counter - 1; ++i){
				if(strcmp(case_literals[i], (yyvsp[0].s)) == 0)
					err("constants in case expressions should be unique and the same type");
			}

		}
		(yyval.i) = insert_literal((yyvsp[0].s), UINT); 
		if(came_from_switch && switch_id_type != get_type((yyval.i)) && came_from_case){
			err("case constants must be the same type as switch variable");
			came_from_switch = false;	// used to remember variable right after 'switch'
		}
			came_from_case = false; // only important literal in the entire statement is the one after 'case' 
	  }
#line 1758 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 473 "micko.y" /* yacc.c:1646  */
    {
        fcall_idx = lookup_symbol((yyvsp[0].s), FUN);
        if(fcall_idx == NO_INDEX)
          err("'%s' is not a function", (yyvsp[0].s));
      }
#line 1768 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 479 "micko.y" /* yacc.c:1646  */
    {
        if(get_atr1(fcall_idx) != (yyvsp[-1].i))
          err("wrong number of arguments");
        code("\n\t\t\tCALL\t%s", get_name(fcall_idx));
        if((yyvsp[-1].i) > 0)
          code("\n\t\t\tADDS\t%%15,$%d,%%15", (yyvsp[-1].i) * 4);
        set_type(FUN_REG, get_type(fcall_idx));
        (yyval.i) = FUN_REG;
		arg_num = 0; // resets number of arguments to 0 for future use
      }
#line 1783 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 493 "micko.y" /* yacc.c:1646  */
    { (yyval.i) = 0; }
#line 1789 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 495 "micko.y" /* yacc.c:1646  */
    { // reverse stack pushing
  		int j;
  		for(j = arg_num-1; j >= 0; j--){
  			code("\n\t\t\tPUSH\t");
			gen_sym_name(reverse_stack_push[j]);
  		}
  	}
#line 1801 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 506 "micko.y" /* yacc.c:1646  */
    { 
      if(get_atr2(fcall_idx, arg_num++) != get_type((yyvsp[0].i))){		// atr2[arg_num] == type(num_exp) ?? 
        err("incompatible type for argument in '%s'", get_name(fcall_idx));
	  }
      free_if_reg((yyvsp[0].i));
      //code("\n\t\t\tPUSH\t");
      //gen_sym_name($1);
      reverse_stack_push[arg_num - 1] = (yyvsp[0].i);
      (yyval.i) = arg_num;
    }
#line 1816 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 517 "micko.y" /* yacc.c:1646  */
    {
      if(get_atr2(fcall_idx, arg_num++) != get_type((yyvsp[0].i)))
        err("incompatible type for argument in '%s'",
            get_name(fcall_idx));
      (yyval.i) = arg_num;
      reverse_stack_push[arg_num - 1] = (yyvsp[0].i);
      //code("\n\t\t\tPUSH\t");
      //gen_sym_name($3);

	}
#line 1831 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 531 "micko.y" /* yacc.c:1646  */
    { code("\n@exit%d:", (yyvsp[0].i)); }
#line 1837 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 534 "micko.y" /* yacc.c:1646  */
    { code("\n@exit%d:", (yyvsp[-2].i)); }
#line 1843 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 539 "micko.y" /* yacc.c:1646  */
    {
        (yyval.i) = ++lab_num;
        code("\n@if%d:", lab_num);
      }
#line 1852 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 544 "micko.y" /* yacc.c:1646  */
    {
        code("\n\t\t%s\t@false%d", opp_jumps[(yyvsp[0].i)], (yyvsp[-1].i)); 
        code("\n@true%d:", (yyvsp[-1].i));
        
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
#line 1876 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 564 "micko.y" /* yacc.c:1646  */
    {
        code("\n\t\tJMP \t@exit%d", (yyvsp[-4].i));
        code("\n@false%d:", (yyvsp[-4].i));
        
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
        
        (yyval.i) = (yyvsp[-4].i);
      }
#line 1902 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 589 "micko.y" /* yacc.c:1646  */
    {
        if(get_type((yyvsp[-2].i)) != get_type((yyvsp[0].i)))
          err("invalid operands: relational operator");
        (yyval.i) = (yyvsp[-1].i) + ((get_type((yyvsp[-2].i)) - 1) * RELOP_NUMBER);
        gen_cmp((yyvsp[-2].i), (yyvsp[0].i));

      }
#line 1914 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 602 "micko.y" /* yacc.c:1646  */
    {
		has_return = true;
        if(get_type(fun_idx) != get_type((yyvsp[-1].i)))
          err("incompatible types in return");
		if(fun_ret_type == VOID)
		  err("void type function should not return value");
        gen_mov((yyvsp[-1].i), FUN_REG);
        code("\n\t\tJMP \t@%s_exit", get_name(fun_idx));        
      }
#line 1928 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 612 "micko.y" /* yacc.c:1646  */
    {
		has_return = true;
		if(fun_ret_type != VOID)
		  warn("function expected to return a value");
	  }
#line 1938 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 621 "micko.y" /* yacc.c:1646  */
    {   
		if(lookup_symbol((yyvsp[0].s), VAR|PAR|GVAR) == NO_INDEX){
           var_idx = insert_symbol((yyvsp[0].s), VAR, (yyvsp[-1].i), ++var_num, PARA_ATR, 0);
		   para_iter_index = var_idx;

		}
        else 
           err("iterator '%s' is a global variable for para statement and cannot be reused", (yyvsp[0].s));

	}
#line 1953 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 632 "micko.y" /* yacc.c:1646  */
    {
		gen_mov((yyvsp[0].i), var_idx);
		code("\n@para%d:", para_num);
		para_num++;
	}
#line 1963 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 638 "micko.y" /* yacc.c:1646  */
    {
		code("\n\t\t%s\t@para_end%d", opp_jumps[(yyvsp[0].i)], para_num-1);	
	}
#line 1971 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 642 "micko.y" /* yacc.c:1646  */
    {
		if(paso_current_type == -1){	// if there is no paso part
			if(get_type((yyvsp[-8].i)) != (yyvsp[-12].i))
 	          err("incompatible types with paso statement literals");
		}
		else{	// if there is paso part
			if(get_type((yyvsp[-8].i)) != paso_current_type || get_type((yyvsp[-8].i)) != (yyvsp[-12].i) || (yyvsp[-12].i) != paso_current_type)
 	          err("incompatible types with paso statement literals");
		}
		paso_current_type = -1;

		if((yyvsp[-2].i) == -1){
			code("\n\t\t%s\t", ar_instructions[((yyvsp[-12].i) - 1) * AROP_NUMBER]);
			gen_sym_name(para_iter_index);
			code(",$1,");
			free_if_reg(para_iter_index);
			int free_reg = take_reg();
			gen_sym_name(free_reg);
			set_type(free_reg, (yyvsp[-12].i));
			gen_mov(free_reg, para_iter_index);
		}	
		else {
			code("\n\t\t%s\t", ar_instructions[((yyvsp[-12].i) - 1) * AROP_NUMBER]);
			gen_sym_name(para_iter_index);
			code(",");
			gen_sym_name((yyvsp[-2].i));
			code(",");
			free_if_reg(para_iter_index);
			int free_reg = take_reg();
			gen_sym_name(free_reg);
			set_type(free_reg, paso_current_type);
			gen_mov(free_reg, para_iter_index);
		}

		gen_cmp((yyvsp[-8].i), (yyvsp[-8].i));
		code("\n\t\t%s\t@para%d", jumps[4], para_num-1);
		code("\n@para_end%d:", para_num-1);
	}
#line 2014 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 684 "micko.y" /* yacc.c:1646  */
    { 
		(yyval.i) = -1;
  }
#line 2022 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 688 "micko.y" /* yacc.c:1646  */
    {
		paso_current_type = get_type((yyvsp[0].i));	// remembers type of literal
		(yyval.i) = (yyvsp[0].i);
	}
#line 2031 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 697 "micko.y" /* yacc.c:1646  */
    {
		int idx = lookup_symbol((yyvsp[0].s), VAR|PAR|GVAR);
		if(idx == NO_INDEX)
           err("variable %s must be previously defined", (yyvsp[0].s));
           
        switch_id_index = idx;
        
		switch_id_type = get_type(idx);
		came_from_switch = true;
		
		code("\n@switch%d:", switch_num);
		switch_num++;
	}
#line 2049 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 711 "micko.y" /* yacc.c:1646  */
    {
		switch_id_type = 0;
		
		code("\n@sw_end%d:", switch_num - 1);
	}
#line 2059 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 720 "micko.y" /* yacc.c:1646  */
    {
		case_lit_counter++;
		came_from_case = true;
	}
#line 2068 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 725 "micko.y" /* yacc.c:1646  */
    {
		set_atr1((yyvsp[0].i), CASE_LIT_ATR);
		//$$ = $3;
		gen_cmp((yyvsp[0].i), switch_id_index);
		code("\n\t\t%s\t@sw%d", jumps[4], case_lit_counter - 1);
		code("\n@sw%d:", case_lit_counter - 1);
		
	}
#line 2081 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 735 "micko.y" /* yacc.c:1646  */
    {
		case_lit_counter++;
		came_from_case = true;
	}
#line 2090 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 740 "micko.y" /* yacc.c:1646  */
    {
		set_atr1((yyvsp[0].i), CASE_LIT_ATR);
		//$$ = $4;
		gen_cmp((yyvsp[0].i), switch_id_index);
		code("\n\t\t%s\t@sw%d", jumps[4], case_lit_counter - 1);
		code("\n@sw%d:", case_lit_counter - 1);
	}
#line 2102 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 753 "micko.y" /* yacc.c:1646  */
    {
  	gen_cmp(switch_id_index, switch_id_index);
  	code("\n\t\t%s\t@sw_end%d", jumps[4], switch_num - 1);
  }
#line 2111 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 765 "micko.y" /* yacc.c:1646  */
    {
		lab_num++;
        code("\n\t\t%s\t@false%d", opp_jumps[(yyvsp[0].i)], lab_num);		
	}
#line 2120 "micko.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 770 "micko.y" /* yacc.c:1646  */
    {
		if(get_type((yyvsp[-2].i)) != get_type((yyvsp[0].i))){
			err("incompatible types in conditional operator");
		}

		(yyval.i) = take_reg();
		set_type((yyval.i), get_type((yyvsp[-2].i)));

        code("\n@true%d:", lab_num);

		gen_mov((yyvsp[-2].i), (yyval.i));		
        code("\n\t\tJMP \t@exit%d", lab_num);
        code("\n@false%d:", lab_num);
		gen_mov((yyvsp[0].i), (yyval.i));
        code("\n@exit%d:", lab_num);
	}
#line 2141 "micko.tab.c" /* yacc.c:1646  */
    break;


#line 2145 "micko.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 790 "micko.y" /* yacc.c:1906  */


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

