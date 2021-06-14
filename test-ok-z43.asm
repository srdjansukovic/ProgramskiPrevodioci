
y:
		WORD	1
main:
		PUSH	%14
		MOV 	%15,%14
@main_body:
		MOV 	$4,y
		CMPS 	y,$5
		JLES	@false0
@true0:
		MOV 	$2,%0
		JMP 	@exit0
@false0:
		MOV 	$3,%0
@exit0:
		MOV 	%0,%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET