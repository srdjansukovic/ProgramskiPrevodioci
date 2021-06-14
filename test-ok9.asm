
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$8,%15
@main_body:
		MOV 	$0,-4(%14)
		MOV 	$3,-12(%14)
@para0:
		CMPS 	-12(%14),$4
		JGES	@para_end0
		ADDS	-4(%14),-12(%14),%0
		MOV 	%0,-4(%14)
		ADDS	-12(%14),$1,%0
		MOV 	%0,-12(%14)
		CMPS 	$3,$3
		JEQ 	@para0
@para_end0:
		MOV 	$3,-16(%14)
@para1:
		CMPS 	-16(%14),$4
		JGES	@para_end1
		ADDS	-8(%14),-16(%14),%0
		MOV 	%0,-8(%14)
		ADDS	-16(%14),$1,%0
		MOV 	%0,-16(%14)
		CMPS 	$3,$3
		JEQ 	@para1
@para_end1:
		MOV 	-4(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET