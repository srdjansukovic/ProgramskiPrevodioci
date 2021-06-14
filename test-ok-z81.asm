
f:
		PUSH	%14
		MOV 	%15,%14
@f_body:
		ADDS	8(%14),12(%14),%0
		ADDS	%0,16(%14),%1
		MOV 	%1,%13
		JMP 	@f_exit
@f_exit:
		MOV 	%14,%15
		POP 	%14
		RET
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$12,%15
@main_body:
		MOV 	$2,-4(%14)
		MOV 	$4,-8(%14)
		MOV 	$6,-12(%14)
			PUSH	-12(%14)
			PUSH	-8(%14)
			PUSH	-4(%14)
			CALL	f
			ADDS	%15,$12,%15
		MOV 	%13,%1
		MOV 	%1,-4(%14)
		ADDS	-4(%14),-8(%14),%1
		MOV 	%1,%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET