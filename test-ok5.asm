
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$12,%15
@main_body:
		MOV 	$2,-4(%14)
		MOV 	$3,-8(%14)
		MOV 	$2,-12(%14)
@switch0:
		CMPU 	$2,8(%14)
		JEQ 	@sw0
@sw0:
		MOV 	$5,-4(%14)
		CMPU 	8(%14),8(%14)
		JEQ 	@sw_end0
		CMPU 	$3,8(%14)
		JEQ 	@sw1
@sw1:
		MOV 	$47,-8(%14)
		CMPU 	8(%14),8(%14)
		JEQ 	@sw_end0
		CMPU 	$4,8(%14)
		JEQ 	@sw2
@sw2:
		MOV 	$47,-8(%14)
		CMPU 	$5,8(%14)
		JEQ 	@sw3
@sw3:
		MOV 	$47,-8(%14)
		MOV 	$3,-4(%14)
@sw_end0:
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET