
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$8,%15
@main_body:
		MOV 	$7,-4(%14)
		MOV 	$3,-8(%14)
		MULS	-4(%14),-8(%14),%0
		DIVS	%0,$7,%1
		MOV 	%1,%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET