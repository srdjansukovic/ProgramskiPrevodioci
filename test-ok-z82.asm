
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$12,%15
@main_body:
		MOV 	$2,-4(%14)
		MOV 	$4,-8(%14)
		MOV 	$6,-12(%14)
@if0:
		CMPS 	-4(%14),$2
		JEQ 	@false0
@true0:
		ADDS	$3,-4(%14),%0
		MOV 	%0,-8(%14)
		ADDS	-4(%14),$1,%0
		MOV 	%0,-4(%14)
		JMP 	@exit0
@false0:
		ADDS	-4(%14),$1,%0
		MOV 	%0,-4(%14)
		ADDS	-4(%14),$1,%0
		MOV 	%0,-4(%14)
@exit0:
		MOV 	-4(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET