
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$8,%15
@main_body:
		MOV 	$5,-8(%14)
		MOV 	$3,-4(%14)
		ADDS	$1,$1,%0
		SUBS	%0,$1,%0
		MULS	%0,$2,%0
		ADDS	%0,$1,%0
		SUBS	%0,$1,%0
		MULS	%0,$2,%0
		ADDS	%0,$1,%0
		SUBS	%0,$1,%0
		MULS	%0,-8(%14),%0
		ADDS	%0,$1,%0
		SUBS	%0,$1,%1
		SUBS	%1,%0,%1
		MULS	%1,-4(%14),%1
		ADDS	%1,%0,%1
		ADDS	%1,$4,%2
		SUBS	%2,%1,%2
		DIVS	%2,$2,%2
		ADDS	%2,%1,%2
		SUBS	%2,%1,%2
		MULS	%2,$2,%2
		ADDS	%2,%1,%2
		ADDS	%2,$1,%3
		MOV 	%3,-4(%14)
		MOV 	-4(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET