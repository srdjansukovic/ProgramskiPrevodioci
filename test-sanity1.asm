
f:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$4,%15
@f_body:
		ADDS	8(%14),$2,%0
		SUBS	%0,-4(%14),%1
		MOV 	%1,%13
		JMP 	@f_exit
@f_exit:
		MOV 	%14,%15
		POP 	%14
		RET
f2:
		PUSH	%14
		MOV 	%15,%14
@f2_body:
		MOV 	$2,%13
		JMP 	@f2_exit
@f2_exit:
		MOV 	%14,%15
		POP 	%14
		RET
ff:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$4,%15
@ff_body:
			CALL	f2
		MOV 	%13,%1
		ADDU	8(%14),%1,%1
		SUBU	%1,-4(%14),%2
		MOV 	%2,%13
		JMP 	@ff_exit
@ff_exit:
		MOV 	%14,%15
		POP 	%14
		RET
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$52,%15
@main_body:
			PUSH	$3
			CALL	f
			ADDS	%15,$4,%15
		MOV 	%13,%2
		MOV 	%2,-4(%14)
@if0:
		CMPS 	-4(%14),-8(%14)
		JGES	@false0
@true0:
		MOV 	$1,-4(%14)
		JMP 	@exit0
@false0:
		MOV 	$-2,-4(%14)
@exit0:
@if1:
		ADDS	-4(%14),-20(%14),%2
		ADDS	-8(%14),-36(%14),%3
		SUBS	%3,$4,%4
		CMPS 	%2,%4
		JNE 	@false1
@true1:
		MOV 	$1,-4(%14)
		JMP 	@exit1
@false1:
		MOV 	$2,-4(%14)
@exit1:
@if2:
		CMPU 	-40(%14),-44(%14)
		JNE 	@false2
@true2:
			PUSH	$1
			CALL	ff
			ADDS	%15,$4,%15
		MOV 	%13,%3
		MOV 	%3,-40(%14)
			PUSH	$11
			CALL	f
			ADDS	%15,$4,%15
		MOV 	%13,%3
		MOV 	%3,-4(%14)
		JMP 	@exit2
@false2:
		MOV 	$2,-44(%14)
@exit2:
@if3:
		ADDS	-4(%14),-20(%14),%3
		SUBS	-8(%14),-36(%14),%4
		SUBS	%4,$-4,%5
		CMPS 	%3,%5
		JNE 	@false3
@true3:
		MOV 	$1,-4(%14)
		JMP 	@exit3
@false3:
		MOV 	$2,-4(%14)
@exit3:
			PUSH	$42
			CALL	f
			ADDS	%15,$4,%15
		MOV 	%13,%4
		MOV 	%4,-4(%14)
@if4:
		SUBS	-12(%14),-20(%14),%4
		ADDS	-4(%14),%4,%4
		SUBS	%4,-36(%14),%5
		SUBS	-16(%14),-4(%14),%6
		ADDS	-8(%14),%6,%6
		CMPS 	%5,%6
		JGES	@false4
@true4:
		SUBU	-44(%14),-40(%14),%5
		ADDU	%5,-48(%14),%6
		MOV 	%6,-48(%14)
		JMP 	@exit4
@false4:
		ADDS	-12(%14),-16(%14),%6
		SUBS	%6,-20(%14),%7
		MOV 	%7,-36(%14)
@exit4:
@if5:
		CMPS 	-4(%14),-8(%14)
		JGES	@false5
@true5:
		MOV 	$1,-4(%14)
		JMP 	@exit5
@false5:
@exit5:
@if6:
		ADDS	-4(%14),-20(%14),%7
		SUBS	-8(%14),$+4,%8
		CMPS 	%7,%8
		JNE 	@false6
@true6:
		MOV 	$1,-4(%14)
		JMP 	@exit6
@false6:
@exit6:
@switch0:
		CMPS 	$1,-4(%14)
		JEQ 	@sw0
@sw0:
		ADDS	-4(%14),$5,%7
		MOV 	%7,-4(%14)
		CMPS 	-4(%14),-4(%14)
		JEQ 	@sw_end0
		CMPS 	$2,-4(%14)
		JEQ 	@sw1
@sw1:
		SUBS	-4(%14),-4(%14),-4(%14)
		DIVS	-4(%14),$2,%7
		ADDS	%7,-4(%14),%7
		MOV 	%7,-4(%14)
		CMPS 	$3,-4(%14)
		JEQ 	@sw2
@sw2:
		SUBS	-4(%14),-4(%14),-4(%14)
		MULS	-4(%14),$8,%7
		ADDS	%7,-4(%14),%7
		MOV 	%7,-4(%14)
		SUBS	-4(%14),$1,%7
		MOV 	%7,-4(%14)
@sw_end0:
		MOV 	$3,-56(%14)
@para0:
		CMPS 	-56(%14),$4
		JGES	@para_end0
		ADDS	-4(%14),-56(%14),%7
		MOV 	%7,-4(%14)
		ADDS	-56(%14),$1,%7
		MOV 	%7,-56(%14)
		CMPS 	$3,$3
		JEQ 	@para0
@para_end0:
		MOV 	$0,%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET