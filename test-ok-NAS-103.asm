
f:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$4,%15
@f_body:
		ADDS	8(%14),$1,%0
		MOV 	%0,-4(%14)
		ADDU	12(%14),16(%14),%0
		MOV 	%0,%13
		JMP 	@f_exit
@f_exit:
		MOV 	%14,%15
		POP 	%14
		RET
main:
		PUSH	%14
		MOV 	%15,%14
@main_body:
		MOV 	$0,%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET