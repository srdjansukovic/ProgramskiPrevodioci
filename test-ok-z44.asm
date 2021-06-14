
f:
		PUSH	%14
		MOV 	%15,%14
@f_body:
		MOV 	8(%14),%13
		JMP 	@f_exit
@f_exit:
		MOV 	%14,%15
		POP 	%14
		RET
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$8,%15
@main_body:
		MOV 	$5,-8(%14)
		MOV 	$3,-4(%14)
		CMPS 	-4(%14),$5
		JLES	@false0
@true0:
		MOV 	$2,%0
		JMP 	@exit0
@false0:
		MOV 	-8(%14),%0
@exit0:
		ADDS	%0,$3,%1
			PUSH	%1
			CALL	f
			ADDS	%15,$4,%15
		MOV 	%13,%1
		MOV 	%1,%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET