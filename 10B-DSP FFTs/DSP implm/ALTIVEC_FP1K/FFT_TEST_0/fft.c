#include <math.h>
#include "inline.h"

#define cplx __complex__ float

int sc_fft_dif(__complex__ short int *pfs, __complex__ short int *pfw, unsigned int n, unsigned int log_n )
{
	unsigned int stage, blk, j, iw=0;
	unsigned int pa, pb, qa, qb;
	unsigned int stride, edirts;
//	cplx ft1a, ft1b, ft2a,ft2b ,ft3a, ft3b;
	__complex__ short int ft1a, ft1b, ft2a,ft2b ,ft3a, ft3b;
	int tmpMult;
//INIT
	stride = n/2;
	edirts = 1;
//DIF FFT
	for( stage=0; stage<log_n-2; stage++ )
	{
		for( blk=0; blk<n; blk+=stride*2 )
		{
			pa = blk;
			pb = blk + stride/2;
			qa = blk + stride;
			qb = blk + stride/2 + stride;
			iw = 0;
			for( j=0; j<stride/2; j++ )
			{//2bufflies/loop
//Scale inputs
				__real__ pfs[pa+j] = __real__ pfs[pa+j] >> 1;
				__imag__ pfs[pa+j] = __imag__ pfs[pa+j] >> 1;
				__real__ pfs[qa+j] = __real__ pfs[qa+j] >> 1;
				__imag__ pfs[qa+j] = __imag__ pfs[qa+j] >> 1;
				__real__ pfs[pb+j] = __real__ pfs[pb+j] >> 1;
				__imag__ pfs[pb+j] = __imag__ pfs[pb+j] >> 1;
				__real__ pfs[qb+j] = __real__ pfs[qb+j] >> 1;
				__imag__ pfs[qb+j] = __imag__ pfs[qb+j] >> 1;
//add
				__real__ ft1a = __real__ pfs[pa+j] + __real__ pfs[qa+j];
				__imag__ ft1a = __imag__ pfs[pa+j] + __imag__ pfs[qa+j];
				__real__ ft1b = __real__ pfs[pb+j] + __real__ pfs[qb+j];
				__imag__ ft1b = __imag__ pfs[pb+j] + __imag__ pfs[qb+j];
//sub
				__real__ ft2a = __real__ pfs[pa+j] - __real__ pfs[qa+j];
				__imag__ ft2a = __imag__ pfs[pa+j] - __imag__ pfs[qa+j];
				__real__ ft2b = __real__ pfs[pb+j] - __real__ pfs[qb+j];
				__imag__ ft2b = __imag__ pfs[pb+j] - __imag__ pfs[qb+j];
				pfs[pa+j] = ft1a;//sto__real__ adds
				pfs[pb+j] = ft1b;
//cmul
				tmpMult = ((int) __real__ ft2a * (int) __real__ pfw[iw]);
				tmpMult = tmpMult - ((int) __imag__ ft2a * (int) __imag__ pfw[iw]);
				tmpMult = tmpMult >> 15;
				__real__ pfs[qa+j] = (signed short) tmpMult;
				tmpMult = ((int) __real__ ft2a * (int) __imag__ pfw[iw]);
				tmpMult = tmpMult + ((int) __imag__ ft2a * (int) __real__ pfw[iw]);
				tmpMult = tmpMult >> 15;
				__imag__ pfs[qa+j] = (signed short) tmpMult;
//twiddled cmul
				tmpMult = ((int) __real__ ft2b * (int) __imag__ pfw[iw]);
				tmpMult = tmpMult + ((int) __imag__ ft2b * (int) __real__ pfw[iw]);
				tmpMult = tmpMult >> 15;
				__real__ pfs[qb+j] = (signed short) tmpMult;
				tmpMult = ((int) __real__ -ft2b * (int) __real__ pfw[iw]);
				tmpMult = tmpMult + ((int) __imag__ ft2b * (int) __imag__ pfw[iw]);
				tmpMult = tmpMult >> 15;
				__imag__ pfs[qb+j] = (signed short) tmpMult;
				iw += edirts;
			} // for( j=0; j<stride/2; j++ )
		} // for( blk=0; blk<n; blk+=stride*2 )
	} // for( stage=0; stage<log_n-2; stage++ )
	stride = stride>>1;
	edirts = edirts<<1;
// } ?????????????????????????????????????
//last two stages
	for( j=0; j<n; j+=4 )
	{
//Scaling
		__real__ pfs[j] = __real__ pfs[j] >> 1;
		__imag__ pfs[j] = __imag__ pfs[j] >> 1;
		__real__ pfs[j+1] = __real__ pfs[j+1] >> 1;
		__imag__ pfs[j+1] = __imag__ pfs[j+1] >> 1;
		__real__ pfs[j+2] = __real__ pfs[j+2] >> 1;
		__imag__ pfs[j+2] = __imag__ pfs[j+2] >> 1;
		__real__ pfs[j+3] = __real__ pfs[j+3] >> 1;
		__imag__ pfs[j+3] = __imag__ pfs[j+3] >> 1;
//upper two
		__real__ ft1a = __real__ pfs[j ]  + __real__ pfs[j+2];
		__imag__ ft1a = __imag__ pfs[j ]  + __imag__ pfs[j+2];
		__real__ ft1b = __real__ pfs[j+1] + __real__ pfs[j+3];
		__imag__ ft1b = __imag__ pfs[j+1] + __imag__ pfs[j+3];
		__real__ ft2a = __real__ ft1a + __real__ ft1b;
		__imag__ ft2a = __imag__ ft1a + __imag__ ft1b;
		__real__ ft2b = __real__ ft1a - __real__ ft1b;
		__imag__ ft2b = __imag__ ft1a - __imag__ ft1b;
//lower two
//notwiddle
		__real__ ft3a = __real__ pfs[j] - __real__ pfs[j+2];
		__imag__ ft3a = __imag__ pfs[j] - __imag__ pfs[j+2];
//twiddle
		__real__ ft3b = __imag__ pfs[j+1]  - __imag__ pfs[j+3];
		__imag__ ft3b = __real__ -pfs[j+1] + __real__ pfs[j+3];
//sto__real__
		pfs[j ] = ft2a;
		pfs[j+1] = ft2b;
		__real__ pfs[j+2] = __real__ ft3a + __real__ ft3b;
		__imag__ pfs[j+2] = __imag__ ft3a + __imag__ ft3b;
		__real__ pfs[j+3] = __real__ ft3a - __real__ ft3b;
		__imag__ pfs[j+3] = __imag__ ft3a - __imag__ ft3b;
	}
	return 0;
}

#define VSH vector signed short
#define VUC vector unsigned char
#define VUH vector unsigned short

int av_dif(int numStages, VSH *data, VSH *w)
{
//VARIABLES
	int numBlks; 				//num blocks in cur__real__nt stage
	int stride; 				//dist between even and odd pts in butterfly
	int stage; 					//the cur__real__nt stage
	int block; 					//the cur__real__nt block
	int nBlk; 					//offset of cur__real__nt block
	int n; 						//offset of cur__real__nt butterfly from nBlk
	int nw; 					//twiddle block index
	int lastStages; 			//Number of t__imag__es to iterate through last 2 stages code
	VSH ve; 					//vector of even (upper) butterfly data
	VSH vo; 					//vector of odd (lower) butterfly data
	VSH vw; 					//vector of twiddles
	VSH vep; 					//__real__sult of even add
	VSH vop; 					//__real__sult of odd subtract
	VSH vopt; 					//vop with twiddles applied
	VSH vn, vs; 				//intermediate __real__sults
	VSH vm1,vm2,vpt; 		//intermediate __real__sults
	VSH v,vp,vpp; 			//src vec, intermediate and final __real__sults
	VSH vMultiply; 			//Intermediate for vec_madds __real__sults
	VSH vSwap; 				//Swapped values for adding
	VSH vReal, vImag; 		//Real and __imag__ag. int. __real__sults
//CONSTANTS
	const VSH vk0s = (VSH)( 0, 0, 0, 0, 0, 0, 0, 0 );
	const VUC vkm1 = (VUC)( 2, 3, 0, 1, 6, 7, 4, 5, //[15]
			10, 11, 8, 9, 14, 15, 12, 13 );
	const VUC vkm2 = (VUC)( 0, 1, 16, 17, 4, 5, 20, //[18]
		21, 8, 9, 24, 25, 12, 13, 28, 29 );
	const VUC vkm3 = (VUC)( 8, 9, 10, 11, 12, 13, 14, 15, //[24]
		0, 1, 2, 3, 4, 5, 6, 7 );
	const VUC vkm4 = (VUC)( 0, 1, 2, 3, 4, 5, 6, 7, //[30]
		8, 9, 10, 11, 14, 15, 12, 13 );
	const VUC vkm5 = (VUC)( 4, 5, 6, 7, 0, 1, 2, 3, //[34]
		12, 13, 14, 15, 8, 9, 10, 11 );
	const VSH vFixKn2 = (VSH)(32767, 32767, 32767, 32767, -32767, -32767,
		-32767, -32767);
	const VSH vFixNegate7 = (VSH) (32767, 32767, 32767, 32767, 32767, 32767,
		32767, -32767);
	const VSH vFixKn3 = (VSH) (32767, 32767, -32767, -32767, 32767, 32767,
		-32767, -32767);
	const VSH vFixKn1 = (VSH) (32767, -32767, 32767, -32767, 32767, -32767,
		32767, -32767);
	const VUH vScaleInput = (VUH) (1, 1, 1, 1, 1, 1, 1, 1);
// my
/////// SPV ?????????
	int SPV = 1; // myyyyyyyyy
// end of my
//INIT
	numBlks = 1; //stage 0 has 1 block
	nw = 0; 		//twiddle block index

	stride = (int)(1 << numStages) / SPV; //dist b/n even & odd vecs
//FFT : iterate over all (but last 2) stages
	for( stage=0; stage<(numStages-2); stage++ )
	{
//start at the top of the lattice
		nBlk = 0;
//iterate over all blocks in this stage
		for(block=0; block<numBlks; block++)
		{
//iterate over all butterflies in this block
			for(n=0; n<stride; n++)
			{
//load the vectors
				ve = data[ nBlk + n ]; //[5]
				vo = data[ nBlk + stride + n ]; //[6]
				vw = vec_ld( (nw*4)+ (n*16), w); //nw = num of twiddles values to skip.
//4 bytes/(twiddle value)
//scaling input
				ve = vec_sra(ve, vScaleInput);
				vo = vec_sra(vo, vScaleInput);
//do the __real__gular math
				vep = vec_adds( ve, vo ); //[7]
				vop = vec_subs( ve, vo ); //[8]
				vn = vec_madds(vw, vFixKn1, vk0s);
				vMultiply = vec_madds(vop, vn, vk0s);
				vSwap = (VSH) vec_perm(vMultiply, vMultiply, vkm1);
				vReal = vec_adds(vMultiply, vSwap);
				vs = (VSH) vec_perm(vw, vw, vkm1);
				vMultiply = vec_madds(vop, vs, vk0s);
				vSwap = (VSH) vec_perm(vMultiply, vMultiply, vkm1);
				vImag = vec_adds(vMultiply, vSwap);
				vopt= (VSH)vec_perm( vReal, vImag, vkm2 ); //[17]
//sto__real__ the vectors
				data[ nBlk + n ] = vep; //[19]
				data[ nBlk + stride + n ] = vopt; //[20]
			} // for(n=0; n<stride; n++)
//offset to next block is 2 strides away
			nBlk = nBlk + 2 * stride;
		} // for( block=0; block<numBlks; block++)
//twice as many blocks in next stage
		numBlks = numBlks * 2;
//next twiddle block is 4 strides away
		nw = nw + 4 * stride;
//stride is half in next stage
		stride = stride / 2;
	} // for( stage=0; stage<(numStages-2); stage++ )
// SPECIAL CASE: last 2 stages combined into one. [38]
//iterate over all vectors in dataset
	lastStages = ((1<<(numStages+1))/SPV);
	for( n=0; n<lastStages; n++)
	{
		v = data[n];
		v = vec_sra(v, vScaleInput);
		vm1 = (VSH)vec_perm( v, v, vkm3 ); //[25]
		vp = vec_madds(v, vFixKn2, vm1); //[28]
		vpt = (VSH)vec_perm( vp, vp, vkm4 ); //[31]
		vpt = vec_madds (vpt, vFixNegate7, vk0s);
		vm2 = (VSH)vec_perm( vpt, vpt, vkm5 ); //[35]
		vpp = vec_madds( vpt, vFixKn3, vm2 ); //[37]
		data[n] = vpp;
	} // for( n=0; n<lastStages; n++)
	return 0;
}

// complex
int sc_fft_dif_cmpx( cplx *pfs, cplx *pfw, unsigned int n, unsigned int log_n )
{
	unsigned int stage, block, j, iw=0;
	unsigned int pa, pb, qa, qb;
	unsigned int stride, edirts;
	cplx ft1a, ft1b, ft2a, ft2b, ft3a, ft3b;
//INIT
	stride = n/2;
	edirts = 1;
//DIF FFT
	for( stage=0; stage<log_n-2; stage++ )
	{
		for( block=0; block<n; block+=stride*2 )
		{
			pa = block;
			pb = block + stride/2;
			qa = block + stride;
			qb = block + stride/2 + stride;
			iw = 0;
			for( j=0; j<stride/2; j++ )
			{ //2bufflies/loop
//add
				__real__ ft1a = __real__ pfs[pa+j] + __real__ pfs[qa+j];
				__imag__ ft1a = __imag__ pfs[pa+j] + __imag__ pfs[qa+j];
				__real__ ft1b = __real__ pfs[pb+j] + __real__ pfs[qb+j];
				__imag__ ft1b = __imag__ pfs[pb+j] + __imag__ pfs[qb+j];
//sub
				__real__ ft2a = __real__ pfs[pa+j] - __real__ pfs[qa+j];
				__imag__ ft2a = __imag__ pfs[pa+j] - __imag__ pfs[qa+j];

				__real__ ft2b = __real__ pfs[pb+j] - __real__ pfs[qb+j];
				__imag__ ft2b = __imag__ pfs[pb+j] - __imag__ pfs[qb+j];
				pfs[pa+j] = ft1a; //store adds
				pfs[pb+j] = ft1b;
//cmul
				__real__ pfs[qa+j] = __real__ ft2a * __real__ pfw[iw] - __imag__ ft2a * __imag__ pfw[iw];
				__imag__ pfs[qa+j] = __real__ ft2a * __imag__ pfw[iw] + __imag__ ft2a * __real__ pfw[iw];
//twiddled cmul
				__real__ pfs[qb+j] = __real__ ft2b * __imag__ pfw[iw] +  __imag__ ft2b * __real__ pfw[iw];
				pfs[qb+j] = -__real__ ft2b * __real__ pfw[iw] + __imag__ ft2b * __imag__ pfw[iw];
				iw += edirts;
			} // for( j=0; j<stride/2; j++ )
		}// for( block=0; block<n; block+=stride*2 )
		stride = stride>>1;
		edirts = edirts<<1;
	} //for( stage=0; stage<log_n-2; stage++ )
//last two stages
	for( j=0; j<n; j+=4 )
	{
//upper two
		__real__ ft1a = __real__ pfs[j ] + __real__ pfs[j+2];
		__imag__ ft1a = __imag__ pfs[j ] + __imag__ pfs[j+2];
		__real__ ft1b = __real__ pfs[j+1] + __real__ pfs[j+3];
		__imag__ ft1b = __imag__ pfs[j+1] + __imag__ pfs[j+3];
		__real__ ft2a = __real__ ft1a + __real__ ft1b;
		__imag__ ft2a = __imag__ ft1a + __imag__ ft1b;
		__real__ ft2b = __real__ ft1a - __real__ ft1b;
		__imag__ ft2b = __imag__ ft1a - __imag__ ft1b;
//lower two
//notwiddle
		__real__ ft3a = __real__ pfs[j] - __real__ pfs[j+2];
		__imag__ ft3a = __imag__ pfs[j] - __imag__ pfs[j+2];
//twiddle
		__real__ ft3b = __imag__ pfs[j+1] - __imag__ pfs[j+3];
		__imag__ ft3b = -__real__ pfs[j+1] + __real__ pfs[j+3];
//store
		pfs[j ] = ft2a;
		pfs[j+1] = ft2b;
		__real__ pfs[j+2] = __real__ ft3a + __real__ ft3b;
		__imag__ pfs[j+2] = __imag__ ft3a + __imag__ ft3b;
		__real__ pfs[j+3] = __real__ ft3a - __real__ ft3b;
		__imag__ pfs[j+3] = __imag__ ft3a - __imag__ ft3b;
	} // 	for( j=0; j<n; j+=4 )
return 0;
}


int av_fft_dif_cmpx( vector float *pvf, vector float *pw, unsigned int n, unsigned int log_n )
{
//local constants
	const vector float vcfzero = (vector float)( 0., 0., 0., 0.);
	const vector float vcfnegeven = (vector float)(-0., 0.,-0., 0.);
	const vector float vcfnegodd = (vector float)( 0.,-0., 0.,-0.);
	const vector float vcppnn = (vector float)( 1., 1.,-1.,-1.);
	const vector float vcpnnp = (vector float)( 1.,-1.,-1., 1.);
//SINGLE VECTOR PERM FORMS (V=[0,1,2,3])
	const vector unsigned char vcprm1032 =
		(vector unsigned char)( 4,5,6,7, 0,1,2,3, 12,13,14,15, 8,9,10,11 );
	const vector unsigned char vcprm0022 =
		(vector unsigned char)( 0,1,2,3, 0,1,2,3, 8,9,10,11, 8,9,10,11 );
	const vector unsigned char vcprm1133 =
		(vector unsigned char)( 4,5,6,7, 4,5,6,7, 12,13,14,15, 12,13,14,15 );
	const vector unsigned char vcprm2301 =
		(vector unsigned char)( 8,9,10,11,12,13,14,15, 0,1,2,3,4,5,6,7 );
	const vector unsigned char vcprm0101 =
		(vector unsigned char)( 0,1,2,3,4,5,6,7, 0,1,2,3,4,5,6,7 );
	const vector unsigned char vcprm3232 =
		(vector unsigned char)( 12,13,14,15,8,9,10,11, 12,13,14,15,8,9,10,11 );
//DOUBLE VECTOR PERM FORMS (V1,V2=[ar,ai,x,x],[br,bi,x,x] x=dontcare)
	const vector unsigned char vcaiarbibr =
		(vector unsigned char)( 4,5,6,7, 0,1,2,3, 20,21,22,23, 16,17,18,19 );
	const vector unsigned char vcaraibrbi =
		(vector unsigned char)( 0,1,2,3,4,5,6,7, 16,17,18,19,20,21,22,23 );
//VECTOR LOCALS
	vector float vtf10, vtf11, vtf12, vtf13, vtf14, vtf15, vtf20, vtf21, vtf22, vtf23, vtf24,
	                  vtf25, vtf31, vtf32, vtf33, vtf34, vtf35, vtf41, vtf42, vtf43, vtf44, vtf45,
	                  vtfw0, vtfw1, vtfw2, vtfw3;
//ITERATORS&INDICES
	unsigned int pa,pb,qa,qb,stride,edirts,iw;//indices
	unsigned int stage,block,j;//iterators
//BEGIN DIF FFT
//FIRST STAGE
	stride = n/2; // in stage 0 stride = n/2
//special case since twiddles are (w1r,w1i,w2r,w2i) in same vec
//and only one block

	for( j=0; j<stride/4; j++ )
	{
//PREP THE TWIDDLES
		vtfw1 = vec_perm( pw[j], pw[j], vcprm1032 );
		vtfw2 = vec_xor( vtfw1, vcfnegeven );//(-i, r)
		vtfw3 = vec_xor( vtfw1, vcfnegodd );//( i,-r)
//BUTTERFLIES
//upper two
		vtf10 = vec_add( pvf[j], pvf[n/4+j] );//PA+QA
		vtf11 = vec_sub( pvf[j], pvf[n/4+j] );//PA-QA
		pvf[j] = vtf10;
		vtf20 = vec_add( pvf[n/8+j], pvf[n/8+n/4+j] );//PB+QB
		vtf21 = vec_sub( pvf[n/8+j], pvf[n/8+n/4+j] );//PB-QB
		pvf[n/8+j] = vtf20;
//lower two (apply twiddle)
		vtf12 = vec_perm( vtf11, vtf11, vcprm0022 );
		vtf12 = vec_madd( vtf12, pw[j], vcfzero );
		vtf13 = vec_perm( vtf11, vtf11, vcprm1133 );
		pvf[n/4+j] = vec_madd( vtfw2, vtf13, vtf12 );
		vtf22 = vec_perm( vtf21, vtf21, vcprm1133 ); //imag
		vtf22 = vec_madd( vtf22, pw[j], vcfzero ); //w.imag
		vtf23 = vec_perm( vtf21, vtf21, vcprm0022 ); //real
		pvf[n/4+n/8+j] = vec_madd( vtfw3, vtf23, vtf22 );//w.real
	} // 	for( j=0; j<stride/4; j++ )

//END FIRST STAGE
	stride = n/4; // in stage 1 stride = n/4
//STAGES iterate over remaining, less the last two
	edirts = 1;

	for( stage=1; stage<log_n-2; stage++ )
	{
//BLOCKS iterate for the number of blocks
		for( block=0; block<n/2; block+=stride )
		{
			pa = block;
			pb = block + stride/4;
			qa = block + stride/2;
			qb = block + stride/4 + stride/2;
			iw = 0;
//itr(stride) of the block, /4 since 2 bufflies/vec and 2vecs/loop
			for( j=0; j<stride/4; j++ )
			{
//PREP THE TWIDDLES
				vtfw0 = vec_perm( pw[j*2*edirts], pw[j*2*edirts+edirts], vcaraibrbi );
				vtfw1 = vec_perm( pw[j*2*edirts], pw[j*2*edirts+edirts], vcaiarbibr );//swap r,i
				vtfw2 = vec_xor( vtfw1, vcfnegeven );//(-i, r)
				vtfw3 = vec_xor( vtfw1, vcfnegodd );//( i,-r)
//BUTTERFLIES
//upper two
				vtf10 = vec_add( pvf[pa+j], pvf[qa+j] );//PA+QA
				vtf11 = vec_sub( pvf[pa+j], pvf[qa+j] );//PA-QA
				pvf[pa+j] = vtf10;
				vtf20 = vec_add( pvf[pb+j], pvf[qb+j] );//PB+QB
				vtf21 = vec_sub( pvf[pb+j], pvf[qb+j] );//PB-QB
				pvf[pb+j] = vtf20;
//lower two (apply twiddle)
				vtf12 = vec_perm( vtf11, vtf11, vcprm0022 );
				vtf12 = vec_madd( vtf12, vtfw0, vcfzero );
				vtf13 = vec_perm( vtf11, vtf11, vcprm1133 );
				pvf[qa+j] = vec_madd( vtfw2, vtf13, vtf12 );
				vtf22 = vec_perm( vtf21, vtf21, vcprm1133 );//imag
				vtf22 = vec_madd( vtf22, vtfw0, vcfzero ); //w.imag
				vtf23 = vec_perm( vtf21, vtf21, vcprm0022 ); //real
				pvf[qb+j] = vec_madd( vtfw3, vtf23, vtf22 ); //w.real
			} // for( j=0; j<stride/4; j++ )
//end BUTTERFLIES
		} // for( block=0; block<n/2; block+=stride )
//stride halves, block count (twiddle separation) doubles
		stride = stride >> 1;
		edirts = edirts << 1;
	} // for( stage=1; stage<log_n-2; stage++ )
//end STAGES (third-to-last stage, actually)
//Last two stages (quad unrolled; forces n>=16)

	for( block=0; block<n/2; block+=8 )
	{ //(n/2 since 1Vec=2pts)
		vtf13 = vec_sub( pvf[block ], pvf[block+1] );//PB1
		vtf11 = vec_add( pvf[block ], pvf[block+1] );//PA1
		vtf23 = vec_sub( pvf[block+2], pvf[block+3] );//QB1
		vtf21 = vec_add( pvf[block+2], pvf[block+3] );//QA1
		vtf33 = vec_sub( pvf[block+4], pvf[block+5] );//PB1
		vtf31 = vec_add( pvf[block+4], pvf[block+5] );//PA1
		vtf43 = vec_sub( pvf[block+6], pvf[block+7] );//QB1
		vtf41 = vec_add( pvf[block+6], pvf[block+7] );//QA1
		vtf15 = vec_perm( vtf13, vtf13, vcprm3232 );//PB2b
		vtf14 = vec_perm( vtf13, vtf13, vcprm0101 );//PB2a
		vtf12 = vec_perm( vtf11, vtf11, vcprm2301 );//PA2
		vtf25 = vec_perm( vtf23, vtf23, vcprm3232 );//QB2b
		vtf24 = vec_perm( vtf23, vtf23, vcprm0101 );//QB2a
		vtf22 = vec_perm( vtf21, vtf21, vcprm2301 );//QA2
		vtf35 = vec_perm( vtf33, vtf33, vcprm3232 );//PB2b
		vtf34 = vec_perm( vtf33, vtf33, vcprm0101 );//PB2a
		vtf32 = vec_perm( vtf31, vtf31, vcprm2301 );//PA2
		vtf45 = vec_perm( vtf43, vtf43, vcprm3232 );//QB2b
		vtf44 = vec_perm( vtf43, vtf43, vcprm0101 );//QB2a
		vtf42 = vec_perm( vtf41, vtf41, vcprm2301 );//QA2
		pvf[block] = vec_madd( vtf11, vcppnn, vtf12 );//PA3
		pvf[block+1] = vec_madd( vtf15, vcpnnp, vtf14 );//PB3
		pvf[block+2] = vec_madd( vtf21, vcppnn, vtf22 );//QA3
		pvf[block+3] = vec_madd( vtf25, vcpnnp, vtf24 );//QB3
		pvf[block+4] = vec_madd( vtf31, vcppnn, vtf32 );//PA3
		pvf[block+5] = vec_madd( vtf35, vcpnnp, vtf34 );//PB3
		pvf[block+6] = vec_madd( vtf41, vcppnn, vtf42 );//QA3
		pvf[block+7] = vec_madd( vtf45, vcpnnp, vtf44 );//QB3
	} // for( block=0; block<n/2; block+=8 )
//end last stage
//END DIF FFT
	return 0;
}
