******************************************************************************/
*
*	TEXAS INSTRUMENTS INC.
*
*	COMPLEX FFT (Radix 2)
*
*	Revision Data: 04/14/97
*
*	USAGE This routine is C callable and can be called as
* 
*		void r2_fft(short xy[],short n,short w[])
*		
*		xy[] --- input and output sequences (dim-n) 	(input/output)
*		n    --- FFT size				(input)		
*		w[]  --- FFT coefficients (dim-n/2)		(input)
* 
*	      If the routine is not to be used as a C callable function,
*	      then all instructions relating to stack should be removed.
*	      Refer to comments of individual instructions. You will also
*	      need to initialize values for all the values passed as these
*	      are assumed to be in registers as defined by the calling
*	      convention of the compiler, (refer to the C compiler reference
*	      guide.)
*
*	C CODE
*
*	      This is the C equivalent of the Assembly Code without the 
*	      assumptions listed below. Note that the assembly code is hand
*             optimized and assumptions apply.
*
*		void r2_fft(short xy[],short n,short w[])
*		{
*		  short n1,n2,ie,ia,i,j,k,l;
*		  short xt,yt,c,s;
*	
*		  n2 = n;
*		  ie = 1;
*		  for (k=n; k > 1; k = (k >> 1) ) {
*		    n1 = n2;
*		    n2 = n2>>1;
*		    ia = 0;
*		    for (j=0; j < n2; j++) {
*		      c = w[2*ia];
*		      s = w[2*ia+1];
*		      ia = ia + ie;
*		      for (i=j; i < n; i += n1) {
*		        l = i + n2;
*		        xt		= xy[2*l] - xy[2*i];
*		        xy[2*i] 	= xy[2*i] + xy[2*l];
*		        yt 		= xy[2*l+1] - xy[2*i+1];
*		        xy[2*i+1]	= xy[2*i+1] + xy[2*l+1];
*		        xy[2*l]		= (c*xt + s*yt)>>15;
*		        xy[2*l+1]	= (c*yt - s*xt)>>15;
*		      }
*		    }
*		    ie = ie<<1;
*		  }
*	        }
*   
*	DESCRIPTION
*		This routine is used to compute FFT of a complex sequece
*		of size n, a power of 2, with "decimation-in-frequency
*		decomposition" method, ie, the output is in bit-reversed 
*		order. Each complex value is with interleaved 16-bit real
*	        and imaginary parts.
*
*	TECHNIQUES
*	     1. Loading input xy as well as coefficient w in word.
*	     2. Both loops j and i shown in the C code are placed in the
*	        INNERLOOP of the assembly code.
*
*
*	ASSUMPTIONS
*		8 <= n <= 32768
*		Both input xy and coefficient w should be aligned on word
*               boundary.
*		w coef stored ordered is k*(-cos[0*delta]), k*(-sin[0*delta]),  
*			k*(-cos[1*delta]), ...  where delta = 2*PI/N, k = 32767
*	
*	MEMORY NOTE
*		Align xy and w on different word boundaries to minimize
*	        memory bank hits.
*		
*	CYCLES		
*		Log(base 2)n * (4*n/2+7) + 9 + n/4 (memory bank hits)
*		(= 4225 for n = 256)	
*
********************************************************************


	.global _r2_fft
	.text

_r2_fft:

*** BEGIN Benchmark Timing ***
B_START:

	LMBD	.L2	1,B4,B8		; outer loop count calculation
||	SUB	.L1X	B15,4,A9	; copy stack pointer
||	STW	.D2	B3, *B15--[2]	; push return address on stack
||	MV	.S2	B4,B5		; XY index setup

	SHL	.S2	B4,2,B3		; calculating reset offset
||	MV	.L2X	A4,B9		; setup ptr for X[i] & Y[i]
||	STW	.D1	A10, *A9--[2]	; push A10 on stack
||	STW	.D2	B11, *B15--[2]	; push B11 on stack

	SHR	.S2	B4,1,B4		; used for inner loop count
||	SUB	.D2	B3,4,B3		; calculating reset offset
||	MV	.L1X	B4,A7		; XY index setup
||	MV	.L2X	A6,B6		; permanent ptr for W[0]
||	STW	.D1	A11, *A9--[3]	; push A11 on stack

	ADDAH	.D1	A4,A7,A3	; setup ptr for X[i+N2] & Y[i+N2]	
||	MVK	.S1	31,A1		; outer loop count calculation
||	STW	.D2	A13, *B15--	; push A13 on stack

	MV	.S2	B9,B8		; setup store ptr for X[i] & Y[i]
||	MV	.L2	B9,B11		; permanent ptr for X[0] & Y[0]
||	SUB	.L1X	A1,B8,A1	; outer loop counter
||	STW	.D1	A12, *A9--[2]	; push A12 on stack
||	STW	.D2	B12, *B15--[2]	; push B12 on stack
||	MVK	.S1	1,A2		; IE = 1

	LDW	.D2	*B9++[B5],B7	; X[i] & Y[i]
||	LDW	.D1	*A6++[A2],A5	; CS = W[IA] & W[IA+1]

  	SUB	.L2X	A2,1,B2		; decrement twiddle factor counter
||	LDW	.D1	*A3++[A7],A13	; X[i+N2] & Y[i+N2]
||	MV	.L1X	B3,A8		; move reset offset
||	SUB	.S2	B4,3,B4		; inner loop count

  [!B2] SUB		B9,B3,B9	; reset load X[i] & Y[i] ptrs
||	STW	.D2	B10, *B15--[2]	; push B10 on stack
||	STW	.D1	A14, *A9--	; push A14 on stack
||	SHL	.S1	A7,1,A0		; calculating reset offset

  [!B2] SUB		A3,A8,A3	; reset load X[i+N2] & Y[i+N2] ptrs
||	STW	.D1	A15, *A9	; push A15 on stack

OUTLOOP:
	LDW	.D2	*B9++[B5],B7	;* X[i] & Y[i]
||[!B2] MV	.L2X	A2,B2		;* reset twiddle factor counter
||[!B2] LDW	.D1	*A6++[A2],A5	;* CS = W[IA] & W[IA+1]
||	MPY	.M2	B2,1,B0		; move to next iteration

   [B2] SUB		B2,1,B2		;* decrement twiddle factor counter
||	LDW	.D1	*A3++[A7],A13	;* X[i+N2] & Y[i+N2]

	SUB2	.S1X	A13,B7,A4	; XYT = X[i]-X[i+N2] & Y[i]-Y[i+N2]
||	MV		A5,A10		; move to other file
||	ADD2	.S2X	B7,A13,B7	; X[i]+X[i+N2] & Y[i]+Y[i+N2]
||[!B2] SUB		B9,B3,B9	;* reset load X[i] & Y[i] ptrs

	MPYHL	.M1	A4,A5,A14	; (C)*(YT)
||	STW	.D2	B7,*B8++[B5]	; XY[i] = X[i]+X[i+N2] & Y[i]+Y[i+N2]
||[!B2] SUB		A3,A8,A3	;* reset load X[i+N2] & Y[i+N2] ptrs

	MPYLH	.M1	A4,A5,A15	; (S)*XT
||	LDW	.D2	*B9++[B5],B7	;** X[i] & Y[i]
||[!B2] MV	.L2X	A2,B2		;** reset twiddle factor counter
||[!B2] LDW	.D1	*A6++[A2],A5	;** CS = W[IA] & W[IA+1]
||	SUB	.L1X	B8,A0,A9	; set store X[i+N2] ptr
||	MPY	.M2	B2,1,B0		;* move to next iteration
||	MV	.S2	B4,B1		; set inner loop counter

	MPY	.M1	A4,A10,A13	; (C)*XT
||[!B0] SUB		B8,B3,B8	; reset store X[i] & Y[i] ptrs
||[B2]	SUB		B2,1,B2		;** decrement twiddle factor counter
||	LDW	.D1	*A3++[A7],A13	;** X[i+N2] & Y[i+N2]
||[B1]	B	.S1	INNERLOOP	; branch to the inner loop

	MPYH	.M1	A4,A10,A14	; (S)*(YT)
||	SUB2	.S1X	A13,B7,A4	;* XYT = X[i]-X[i+N2] & Y[i]-Y[i+N2]
||	MV	.L1	A5,A10		;* move to other file
||	ADD2	.S2X	B7,A13,B7	;* X[i]+X[i+N2] & Y[i]+Y[i+N2]
||[!B2] SUB	.D2	B9,B3,B9	;** reset load X[i] & Y[i] ptrs

INNERLOOP:
	SUB	.L1	A14,A15,A15	; Y[i+N2] = C*YT - S*XT
||	MPYHL	.M1	A4,A5,A14	;* (C)*(YT)
||	STW	.D2	B7,*B8++[B5]	;* XY[i] = X[i]+X[i+N2] & Y[i]+Y[i+N2]
||[!B2] SUB	.D1	A3,A8,A3	;** reset load X[i+N2] & Y[i+N2] ptrs
||	MV	.S1	A9,A12		; set store X[i+N2] ptr
||[!B2] MPY	.M2X	A2,1,B2		;*** reset twiddle factor counter

	SHR	.S1	A15,15,A11	; scale Y[i+N2]
||	ADD	.L1	A14,A13,A13	; X[i+N2] = C*XT + S*YT
||	MPYLH	.M1	A4,A5,A15	;* (S)*XT
||	LDW	.D2	*B9++[B5],B7	;*** X[i] & Y[i]
||[!B2] LDW	.D1	*A6++[A2],A5	;*** CS = W[IA] & W[IA+1]
||[B1]	SUB	.L2	B1,1,B1		; decrement inner loop counter
||	MPY	.M2	B2,1,B0		;** move to next iteration
||	ADD	.S2X	A12,2,B12	; set store Y[i+N2] ptr 

 [B1]	B	.S1	INNERLOOP	; for (i=j; i < N; i += N1)
||	SHR	.S2X	A13,15,B10	; scale X[i+N2]
||	SUB	.L1X	B8,A0,A9	;* set store X[i+N2] ptr
||	MPY	.M1	A4,A10,A13	;* (C)*XT
||[!B0] SUB	.L2	B8,B3,B8	;* reset store X[i] & Y[i] ptrs
||[B2]	SUB	.D2	B2,1,B2		;*** decrement twiddle factor counter
||	LDW	.D1	*A3++[A7],A13	;*** X[i+N2] & Y[i+N2]

	STH	.D1	B10,*A12	; X[i+N2] = C*YT + S*XT
||	STH	.D2	A11,*B12	; Y[i+N2] = C*YT - S*XT
||	MPYH	.M1	A4,A10,A14	;* (S)*(YT)
||	SUB2	.S1X	A13,B7,A4	;** XYT = X[i]-X[i+N2] & Y[i]-Y[i+N2]
||	ADD	.L1	0,A5,A10	;** move to other file
||	ADD2	.S2X	B7,A13,B7	;** X[i]+X[i+N2] & Y[i]+Y[i+N2]
||[!B2] SUB	.L2	B9,B3,B9	;*** reset load X[i] & Y[i] ptrs
					; INNERLOOP ENDS HERE

	SUB	.D1	A14,A15,A15	;* Y[i+N2] = C*YT - S*XT
||	MV	.L1	A9,A12		;* set store X[i+N2] ptr
||	MPYHL	.M1	A4,A5,A14	;** (C)*(YT)
||	STW	.D2	B7,*B8++[B5]	;** XY[i] = X[i]+X[i+N2] & Y[i]+Y[i+N2]
||	SHL	.S1	A2,1,A2		; IE << 1
||	MV	.L2	B11,B9		; set up load ptr to X[0] & Y[0]

	ADD	.D1	A14,A13,A13	;* X[i+N2] = C*XT + S*YT
||	MPYLH	.M1	A4,A5,A15	;** (S)*XT
||	SUB	.L1X	B8,A0,A9	;** set store X[i+N2] ptr
||	SHR	.S2X	A15,15,B10	;* scale Y[i+N2]
||	MV	.L2	B11,B8		; set up store ptr to X[0] & Y[0]
||[B1]	SUB	.D2	B1,1,B1		;** dec i lp cntr
||	SUB	.S1	A1,1,A1		; decrement outer loop counter

	SHR	.S1	A13,15,A11	;* scale X[i+N2]
||	ADD	.L2X	A12,2,B12	;* set store Y[i+N2] ptr	
||	MPY	.M1	A4,A10,A13	;** (C)*XT
|| [A1] B	.S2	OUTLOOP		; branch to next stage
||[!A1]	LDW	.D2	*+B15[9],B3	; pop B3 off stack
||	ADD	.L1X	A7,B9,A3	; set up load ptr to X[N2] & Y[N2]
||	MV	.D1	A7,A0		; calculating reset offset

	STH	.D1	A11,*A12	; X[i+N2] = C*YT + S*XT
||	STH	.D2	B10,*B12	; Y[i+N2] = C*YT - S*XT
||	MPYH	.M1	A4,A10,A10	;* (S)*(YT)
||	SHR	.S2	B5,1,B5		; load index >> 1
||	MV	.L1X	B6,A6		; reset W ptr
||	MV	.S1	A9,A12		;* set store X[i+N2] ptr
||	MV	.L2X	A2,B2		; reset twiddle factor counter

	LDW	.D2	*B9++[B5],B7	; X[i] & Y[i]
||	LDW	.D1	*A6++[A2],A5	; CS = W[IA] & W[IA+1]
||	SHR	.S1	A7,1,A7		; load index >> 1
||[!A1]	ADD	.L1X	B15,4,A4	; copy stack pointer

	ADD	.L1	A10,A13,A13	;* X[i+N2] = C*XT + S*YT
||	SUB	.S1	A14,A15,A15	;* Y[i+N2] = C*YT - S*XT
||[A1]	LDW	.D1	*A3++[A7],A13	; X[i+N2] & Y[i+N2]
||	ADD	.L2X	A12,2,B12	;* set store Y[i+N2] ptr	

	SHR	.S1	A13,15,A11	;* scale X[i+N2]
||	SHR	.S2X	A15,15,B10	;* scale Y[i+N2]
||[B2]	SUB	.L2	B2,1,B2		; decrement twiddle factor counter
||[!A1]	LDW	.D2	*B15++[2], A15	; pop A15 off stack

	STH	.D1	A11,*A12	; X[i+N2] = C*YT + S*XT
||	STH	.D2	B10,*B12	; Y[i+N2] = C*YT - S*XT
||[!B2] SUB	.L2	B9,B3,B9	; reset load X[i] & Y[i] ptrs
||[!B2] SUB	.S1	A3,A8,A3	; reset load X[i+N2] & Y[i+N2] ptrs
					; OUTLOOP ENDS HERE
B_END:
*** END Benchmark Timing ***

	LDW	.D2	*B15++[2], B10	; pop B10 off stack
||	LDW	.D1	*A4++[2], A14	; pop A14 off stack

	LDW	.D2	*B15++[3], B12	; pop B12 off stack
||	LDW	.D1	*A4++[2], A12	; pop A12 off stack

	LDW	.D1	*A4++, A13	; pop A13 off stack

	B	.S2	B3
||	LDW	.D2	*B15++[2], B11	; pop B11 off stack
||	LDW	.D1	*A4++[2], A11	; pop A11 off stack

	LDW	.D1	*A4, A10	; pop A10 off stack

	NOP		4

