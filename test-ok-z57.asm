
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
		ADDS	$2,$3,%0
		SUBS	%0,$2,%0
		MULS	%0,$2,%0
		ADDS	%0,$2,%0
			PUSH	%0
			CALL	f
			ADDS	%15,$4,%15
		MOV 	%13,%0
		MOV 	%0,-8(%14)
		MOV 	-8(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET