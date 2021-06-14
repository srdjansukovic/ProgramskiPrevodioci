
y:
		WORD	1
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$8,%15
@main_body:
		MOV 	$4,-8(%14)
		MOV 	$5,y
		CMPS 	y,$5
		JLES	@false0
		ADDS	-8(%14),$2,%0
@true0:
		MOV 	%0,%1
		JMP 	@exit0
@false0:
		MOV 	$3,%1
@exit0:
		ADDS	$10,%1,%0
		MOV 	%0,-4(%14)
		MOV 	-4(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET