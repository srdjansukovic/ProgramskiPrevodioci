
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$4,%15
@main_body:
		MOV 	$2,-4(%14)
@switch0:
		CMPS 	$1,-4(%14)
		JEQ 	@sw0
@sw0:
		ADDS	-4(%14),$5,%0
		MOV 	%0,-4(%14)
		CMPS 	-4(%14),-4(%14)
		JEQ 	@sw_end0
		CMPS 	$2,-4(%14)
		JEQ 	@sw1
@sw1:
		SUBS	-4(%14),-4(%14),-4(%14)
		DIVS	-4(%14),$2,%0
		ADDS	%0,-4(%14),%0
		MOV 	%0,-4(%14)
		CMPS 	$3,-4(%14)
		JEQ 	@sw2
@sw2:
		SUBS	-4(%14),-4(%14),-4(%14)
		MULS	-4(%14),$8,%0
		ADDS	%0,-4(%14),%0
		MOV 	%0,-4(%14)
		SUBS	-4(%14),$1,%0
		MOV 	%0,-4(%14)
@sw_end0:
		MOV 	-4(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET