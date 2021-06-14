
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$8,%15
@main_body:
		MOV 	$5,-8(%14)
		MOV 	$3,-4(%14)
		ADDS	$2,$2,%0
		ADDS	%0,-8(%14),%1
		SUBS	%1,%0,%1
		MULS	%1,$2,%1
		ADDS	%1,%0,%1
		MOV 	%1,-4(%14)
		MOV 	-4(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET