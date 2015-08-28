#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>

#include "inline.h"
//#include "atlas3g4_macro.h"
//#include "atlas3g4_crt0.h"

#include "spanregs.h"
#include "proregs.h"
#include "pro.h"
#include "span.h"
//#include "ppc_regs_c.h"

//#include "fpga_icu.h"
//#include "inline.h"


void ToConsole(const char *text, ...)
{
#define OUTBUF 0x00ff0000
//#define OUTBUF 0x0003000

volatile unsigned *pG4OutFlag = (unsigned *) (TUNDRA_SPAN_BASE + MBOX0);
volatile char *pG4OutBuf = (char*) (OUTBUF);

	int val;
	va_list argp;
	va_start(argp, text);

	while(*pG4OutFlag != 0) ;

	val = vsprintf(pG4OutBuf, text, argp);
	va_end(argp);

 	__FLUSH_CACHE((void *)pG4OutBuf, (val>>5) + 1);

 	*pG4OutFlag = 1;
 	__SYNC();

 	return;
}

unsigned Variable = 16;

void simpleDelayMS(unsigned ms)
{
//  1 ms = 25000 clocs
	unsigned value, beg, end;
	value = ms*25000;
	beg = __GET_TBL();
	end = beg+value;
	for(;;)
	{
		beg = __GET_TBL();
		if(beg > end) break;
		else continue;
	}
}

void simpleDelayMCS(unsigned mcs)
{
// 1 mcs = 25 clocs
	unsigned value, beg, end;
	value = mcs*25;
	beg = __GET_TBL();
	end = beg+value;
	for(;;)
	{
		beg = __GET_TBL();
		if(beg > end) break;
		else continue;
	}
}
//jklzhcg
void simpleDelay(long long mcs)
{
// 1 mcs = 25 clocs
	long long value, beg, end;
	value = mcs*25;
	beg = get_TB();
//	beg = __GET_TB();
	end = beg+value;
	for(;;)
	{
		beg = get_TB();
//		beg = __GET_TB();
		if(beg > end) break;
		else continue;
	}
}


#define PI	3.14159265358979323846

	__complex__ short int pfs_sc[1024];
	__complex__ short int pfw_sc[1024];

	__complex__ short int pfs_av[1024];
	__complex__ short int pfw_av[1024];


	__complex__ float pfs_c_sc[1024*1024];
	__complex__ float pfw_c_sc[1024*1024];


	__complex__ float pfs_c_av[1024*4] __attribute__ ((aligned (16))) ;
	__complex__ float pfw_c_av[1024*4] __attribute__ ((aligned (16))) ;


	__complex__ float pfs_cc[1024*1024];
	__complex__ float pfw_cc[1024*1024];

	__complex__ float pfs_tmp[1024];
	__complex__ float pfw_tmp[1024];


int main()
{
	int i,j;
	unsigned *p;
	unsigned start, end;
	unsigned clk_res[4];
	int pref_const = 0x10010100;

	ToConsole("\n\tEstimation test for FFT speed for Atlas3-G4(source code from Motorola)\n");
	ToConsole("\n\t== INTEGER\n");
	ToConsole("\t== This is a FFT test,  pfs_c_av = %08x, pfw_c_av =%08x \n", pfs_c_av, pfw_c_av);

	ToConsole("\n\t== No AltiVec\n");

	for(i = 0; i < 4; i++)
	{
	start = __GET_TBL();
		sc_fft_dif(pfs_sc, pfw_sc, 1024, 10);
	end =  __GET_TBL();
	clk_res[i] = end - start;
	}

	ToConsole("\t%d clk, %d clk, %d clk, %d clk or  %d ns, %d ns, %d ns, %d ns\n",
		clk_res[0], clk_res[1], clk_res[2], clk_res[3],
		clk_res[0]*40, clk_res[1]*40, clk_res[2]*40, clk_res[3]*40);


	ToConsole("\n\t== With AltiVec\n");

#define PREF_CONST 0x10010100

		for(i = 0; i < 4; i++)
		{
		start = __GET_TBL();
			av_dif(8, &pfs_av[0], &pfw_av[0]);
		end =  __GET_TBL();
		clk_res[i] = end - start;
		}
		vec_dss(0);

		ToConsole("\t%d clk, %d clk, %d clk, %d clk or  %d ns, %d ns, %d ns, %d ns\n",
			clk_res[0], clk_res[1], clk_res[2], clk_res[3],
		clk_res[0]*40, clk_res[1]*40, clk_res[2]*40, clk_res[3]*40);


	ToConsole("\n\t== COMPLEX\n");


	ToConsole("\n\t== No AltiVec\n");

	for(i = 0; i < 4; i++)
	{
	start = __GET_TBL();
		sc_fft_dif_cmpx(pfs_c_sc, pfw_c_sc, 1024, 10);
	end =  __GET_TBL();
	clk_res[i] = end - start;
	}

	ToConsole("\t%d clk, %d clk, %d clk, %d clk or  %d ns, %d ns, %d ns, %d ns\n",
		clk_res[0], clk_res[1], clk_res[2], clk_res[3],
		clk_res[0]*40, clk_res[1]*40, clk_res[2]*40, clk_res[3]*40);


	ToConsole("\n\t== With AltiVec\n");

	for(i = 0; i < 4; i++)
	{
	start = __GET_TBL();
		av_fft_dif_cmpx(&pfs_c_av[0], &pfw_c_av[0], 1024, 10);
	end =  __GET_TBL();
	clk_res[i] = end - start;
	}

	ToConsole("\t%d clk, %d clk, %d clk, %d clk or  %d ns, %d ns, %d ns, %d ns\n",
		clk_res[0], clk_res[1], clk_res[2], clk_res[3],
		clk_res[0]*40, clk_res[1]*40, clk_res[2]*40, clk_res[3]*40);

	start = __GET_TBL();

	for(i = 0;i < 1024; i++)
	{
		av_fft_dif_cmpx(&pfs_cc[i*1024], &pfw_cc[i*1024], 1024, 10);

		for(j = 0; j < 1024; j++)
		{
			pfs_tmp[j] = pfs_cc[j*1024 + i];
		}

		av_fft_dif_cmpx(&pfs_tmp[0], &pfw_tmp[0], 1024, 10);

		for(j = 0; j < 1024; j++)
		{
			 pfw_cc[j*1024 + i] = pfs_tmp[j];
		}

	}

	end =  __GET_TBL();

	ToConsole("\n\tDuration for this total stupid Altivec 2D FFT [1024 * 1024](64 MB) is %d mcs\n", (end - start)/25);

	start = __GET_TBL();

	for(i = 0;i < 32; i++)
	{
		av_fft_dif_cmpx(&pfs_cc[i*32], &pfw_cc[i*32], 32, 5);

		for(j = 0; j < 32; j++)
		{
			pfs_tmp[j] = pfs_cc[j*32 + i];
		}

		av_fft_dif_cmpx(&pfs_tmp[0], &pfw_tmp[0], 32, 5);

		for(j = 0; j < 32; j++)
		{
			 pfw_cc[j*32 + i] = pfs_tmp[j];
		}

	}

	end =  __GET_TBL();

	ToConsole("\n\tDuration for this total stupid Altivec 2D FFT[32 * 32] is %d mcs\n", (end - start)/25);

	ToConsole("\n\tComplex FFT with AltiVec\n");


	for(i = 0; i < 4; i++)
	{
	start = __GET_TBL();
		av_fft_dif_cmpx(&pfs_c_av[0], &pfw_c_av[0], 128, 7);
	end =  __GET_TBL();
	clk_res[i] = end - start;
	}


	ToConsole("\t 128: %d clk, %d clk, %d clk, %d clk or  %d ns, %d ns, %d ns, %d ns\n",
		clk_res[0], clk_res[1], clk_res[2], clk_res[3],
		clk_res[0]*40, clk_res[1]*40, clk_res[2]*40, clk_res[3]*40);


	for(i = 0; i < 4; i++)
	{
	start = __GET_TBL();
		av_fft_dif_cmpx(&pfs_c_av[0], &pfw_c_av[0], 256, 8);
	end =  __GET_TBL();
	clk_res[i] = end - start;
	}

	ToConsole("\t 256: %d clk, %d clk, %d clk, %d clk or  %d ns, %d ns, %d ns, %d ns\n",
		clk_res[0], clk_res[1], clk_res[2], clk_res[3],
		clk_res[0]*40, clk_res[1]*40, clk_res[2]*40, clk_res[3]*40);


	for(i = 0; i < 4; i++)
	{
	start = __GET_TBL();
		av_fft_dif_cmpx(&pfs_c_av[0], &pfw_c_av[0], 512, 9);
	end =  __GET_TBL();
	clk_res[i] = end - start;
	}


	ToConsole("\t 512: %d clk, %d clk, %d clk, %d clk or  %d ns, %d ns, %d ns, %d ns\n",
		clk_res[0], clk_res[1], clk_res[2], clk_res[3],
		clk_res[0]*40, clk_res[1]*40, clk_res[2]*40, clk_res[3]*40);


	for(i = 0; i < 4; i++)
	{
	start = __GET_TBL();
		av_fft_dif_cmpx(&pfs_c_av[0], &pfw_c_av[0], 1024, 10);
	end =  __GET_TBL();
	clk_res[i] = end - start;
	}


	ToConsole("\t1 K: %d clk, %d clk, %d clk, %d clk or  %d ns, %d ns, %d ns, %d ns\n",
		clk_res[0], clk_res[1], clk_res[2], clk_res[3],
		clk_res[0]*40, clk_res[1]*40, clk_res[2]*40, clk_res[3]*40);

	for(i = 0; i < 4; i++)
	{
	start = __GET_TBL();
		av_fft_dif_cmpx(&pfs_c_av[0], &pfw_c_av[0], 2048, 11);
	end =  __GET_TBL();
	clk_res[i] = end - start;
	}


	ToConsole("\t2 K: %d clk, %d clk, %d clk, %d clk or  %d ns, %d ns, %d ns, %d ns\n",
		clk_res[0], clk_res[1], clk_res[2], clk_res[3],
		clk_res[0]*40, clk_res[1]*40, clk_res[2]*40, clk_res[3]*40);

	for(i = 0; i < 4; i++)
	{
	start = __GET_TBL();
		av_fft_dif_cmpx(&pfs_c_av[0], &pfw_c_av[0], 4096, 12);
	end =  __GET_TBL();
	clk_res[i] = end - start;
	}

	ToConsole("\t4 K: %d clk, %d clk, %d clk, %d clk or  %d ns, %d ns, %d ns, %d ns\n",
		clk_res[0], clk_res[1], clk_res[2], clk_res[3],
		clk_res[0]*40, clk_res[1]*40, clk_res[2]*40, clk_res[3]*40);


	for(i = 0; i < 4; i++)
	{
	start = __GET_TBL();
		av_fft_dif_cmpx(&pfs_c_av[0], &pfw_c_av[0], 8192, 13);
	end =  __GET_TBL();
	clk_res[i] = end - start;
	}

	ToConsole("\t8 K: %d us, %d us, %d us, %d us\n",
				clk_res[0]/25, clk_res[1]/25, clk_res[2]/25, clk_res[3]/25);


	for(i = 0; i < 4; i++)
	{
	start = __GET_TBL();
		av_fft_dif_cmpx(&pfs_c_av[0], &pfw_c_av[0], 16*1024, 14);
	end =  __GET_TBL();
	clk_res[i] = end - start;
	}

	ToConsole("\t16 K: %d us, %d us, %d us, %d us\n",
				clk_res[0]/25, clk_res[1]/25, clk_res[2]/25, clk_res[3]/25);


	for(i = 0; i < 4; i++)
	{
	start = __GET_TBL();
		av_fft_dif_cmpx(&pfs_c_av[0], &pfw_c_av[0], 32*1024, 15);
	end =  __GET_TBL();
	clk_res[i] = end - start;
	}

	ToConsole("\t32 K: %d us, %d us, %d us, %d us\n",
				clk_res[0]/25, clk_res[1]/25, clk_res[2]/25, clk_res[3]/25);


	for(i = 0; i < 4; i++)
	{
	start = __GET_TBL();
		av_fft_dif_cmpx(&pfs_c_av[0], &pfw_c_av[0], 64*1024, 16);
	end =  __GET_TBL();
	clk_res[i] = end - start;
	}

	ToConsole("\t64 K: %d us, %d us, %d us, %d us\n",
				clk_res[0]/25, clk_res[1]/25, clk_res[2]/25, clk_res[3]/25);


	for(i = 0; i < 4; i++)
	{
	start = __GET_TBL();
		av_fft_dif_cmpx(&pfs_c_av[0], &pfw_c_av[0], 128*1024, 17);
	end =  __GET_TBL();
	clk_res[i] = end - start;
	}

	ToConsole("\t128 K: %d us, %d us, %d us, %d us\n",

		clk_res[0]/25, clk_res[1]/25, clk_res[2]/25, clk_res[3]/25);


	for(i = 0; i < 4; i++)
	{
	start = __GET_TBL();
		av_fft_dif_cmpx(&pfs_c_av[0], &pfw_c_av[0], 256*1024, 18);
	end =  __GET_TBL();
	clk_res[i] = end - start;
	}

	ToConsole("\t256 K: %d us, %d us, %d us, %d us\n",
				clk_res[0]/25, clk_res[1]/25, clk_res[2]/25, clk_res[3]/25);


	for(i = 0; i < 4; i++)
	{
	start = __GET_TBL();
		av_fft_dif_cmpx(&pfs_c_av[0], &pfw_c_av[0], 512*1024, 19);
	end =  __GET_TBL();
	clk_res[i] = end - start;
	}

	ToConsole("\t512 K: %d us, %d us, %d us, %d us\n",
			clk_res[0]/25, clk_res[1]/25, clk_res[2]/25, clk_res[3]/25);

	for(i = 0; i < 4; i++)
	{
	start = __GET_TBL();
		av_fft_dif_cmpx(&pfs_c_av[0], &pfw_c_av[0], 1024*1024, 20);
	end =  __GET_TBL();
	clk_res[i] = end - start;
	}

	ToConsole("\t1024 K:  %d us, %d us, %d us, %d us\n",
				clk_res[0]/25, clk_res[1]/25, clk_res[2]/25, clk_res[3]/25);


	ToConsole("2D FFT test");


	start = __GET_TBL();

	for(i = 0;i < 32; i++)
	{
		av_fft_dif_cmpx(&pfs_cc[i*32], &pfw_cc[i*32], 32, 5);

		for(j = 0; j < 32; j++)
		{
			pfs_tmp[j] = pfs_cc[j*32 + i];
		}

		av_fft_dif_cmpx(&pfs_tmp[0], &pfw_tmp[0], 32, 5);

		for(j = 0; j < 32; j++)
		{
			 pfw_cc[j*32 + i] = pfs_tmp[j];
		}

	}

	end =  __GET_TBL();

	ToConsole("\n\tDuration for this total stupid Altivec 2D FFT[32 * 32](64256 KB) is %d mcs\n", (end - start)/25);


	start = __GET_TBL();

	for(i = 0;i < 64; i++)
	{
		av_fft_dif_cmpx(&pfs_cc[i*64], &pfw_cc[i*64], 64, 6);

		for(j = 0; j < 64; j++)
		{
			pfs_tmp[j] = pfs_cc[j*64 + i];
		}

		av_fft_dif_cmpx(&pfs_tmp[0], &pfw_tmp[0], 64, 6);

		for(j = 0; j < 64; j++)
		{
			 pfw_cc[j*64 + i] = pfs_tmp[j];
		}

	}

	end =  __GET_TBL();

	ToConsole("\n\tDuration for this total stupid Altivec 2D FFT[64 * 64](256 KB) is %d mcs\n", (end - start)/25);


	start = __GET_TBL();

	for(i = 0;i < 128; i++)
	{
		av_fft_dif_cmpx(&pfs_cc[i*128], &pfw_cc[i*128], 128, 7);

		for(j = 0; j < 128; j++)
		{
			pfs_tmp[j] = pfs_cc[j*128 + i];
		}

		av_fft_dif_cmpx(&pfs_tmp[0], &pfw_tmp[0], 128, 7);

		for(j = 0; j < 128; j++)
		{
			 pfw_cc[j*128 + i] = pfs_tmp[j];
		}

	}

	end =  __GET_TBL();

	ToConsole("\n\tDuration for this total stupid Altivec 2D FFT[128 * 128](1024 KB) is %d mcs\n", (end - start)/25);

	start = __GET_TBL();

	for(i = 0;i < 256; i++)
	{
		av_fft_dif_cmpx(&pfs_cc[i*256], &pfw_cc[i*256], 256, 8);

		for(j = 0; j < 256; j++)
		{
			pfs_tmp[j] = pfs_cc[j*256 + i];
		}

		av_fft_dif_cmpx(&pfs_tmp[0], &pfw_tmp[0], 256, 8);

		for(j = 0; j < 256; j++)
		{
			 pfw_cc[j*256 + i] = pfs_tmp[j];
		}

	}

	end =  __GET_TBL();

	ToConsole("\n\tDuration for this total stupid Altivec 2D FFT[256 * 256](4096 KB) is %d mcs\n", (end - start)/25);

	start = __GET_TBL();

	for(i = 0;i < 512; i++)
	{
		av_fft_dif_cmpx(&pfs_cc[i*512], &pfw_cc[i*512], 512, 9);

		for(j = 0; j < 512; j++)
		{
			pfs_tmp[j] = pfs_cc[j*512 + i];
		}

		av_fft_dif_cmpx(&pfs_tmp[0], &pfw_tmp[0], 512, 9);

		for(j = 0; j < 512; j++)
		{
			 pfw_cc[j*512 + i] = pfs_tmp[j];
		}

	}

	end =  __GET_TBL();

	ToConsole("\n\tDuration for this total stupid Altivec 2D FFT[512 * 512](16 MB) is %d mcs\n", (end - start)/25);

start = __GET_TBL();

	for(i = 0;i < 1024; i++)
	{
		av_fft_dif_cmpx(&pfs_cc[i*1024], &pfw_cc[i*1024], 1024, 10);

		for(j = 0; j < 1024; j++)
		{
			pfs_tmp[j] = pfs_cc[j*1024 + i];
		}

		av_fft_dif_cmpx(&pfs_tmp[0], &pfw_tmp[0], 1024, 10);

		for(j = 0; j < 1024; j++)
		{
			 pfw_cc[j*1024 + i] = pfs_tmp[j];
		}

	}

	end =  __GET_TBL();

	ToConsole("\n\tDuration for this total stupid Altivec 2D FFT[1024 * 1024](64 MB) is %d mcs\n", (end - start)/25);
	ToConsole("\n\tTest is over\n");

	return 0;
}

