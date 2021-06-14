
y:
		WORD	1
main:
		PUSH	%14
		MOV 	%15,%14
@main_body:
		MOV 	$1,y
@if0:
		CMPU 	y,$2
		JLEU	@false0
@true0:
		MOV 	$2,y
		JMP 	@exit0
@false0:
		MOV 	$3,y
@exit0:
		MOV 	y,%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET