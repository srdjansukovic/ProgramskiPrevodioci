
y:
		WORD	1
f:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$4,%15
@f_body:
		MOV 	$5,-4(%14)
@f_exit:
		MOV 	%14,%15
		POP 	%14
		RET
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$4,%15
@main_body:
		MOV 	$0,-4(%14)
			PUSH	-4(%14)
			CALL	f
			ADDS	%15,$4,%15
		ADDS	-4(%14),$1,%0
		MOV 	%0,-4(%14)
		MOV 	-4(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET