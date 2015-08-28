                                ###############################################################################

                                #
                                # This program is available under a DISCLAIMER OF WARRANTY available
                                # from Motorola Imaging and Storage Division, 6501 William Cannon Drive,
                                # Austin, Texas 78735
                                #
                                # Radix-2, 128-pt In-Place, Decimation in Frequency FFT (smallest code size)
                                #
                                # Complex input and output data
                                #   Format of 32-bit operands: upper 16-bits real, lower 16-bits imaginary
                                #   Each operand is assumed to be in the form of S.FFF...FFF, where
                                #   S represents the sign and F represents the fractional part of the
                                #   operand.
                                #
                                # Normally ordered input data
                                # Bit-reversed output data
                                #
                                # Stack: %a7        LE
                                #        %a7+4      LE1
                                #        %a7+8      outerL
                                #        %a7+c      jlimit

                                    align   16
                                    space   64
                                stack:
                                    space   64

                                    align   0x1000
                                main:
02000: 4ff8 19a0                    lea     stack.w,%a7
02004: 203c 8100 0100               mov.l   &0x81000100,%d0
0200a: 4e7b 0002                    mov.l   %d0,%cacr
0200e: 41f8 3000                    lea     data.w,%a0
02012: 43f8 4000                    lea     coeff.w,%a1
02016: 7c01                         movq    &1,%d6
02018: 2f46 0008                    mov.l   %d6,(8,%a7)             #load outerL

                                l_loop:

0201c: 49f8 5000                    lea     init.w,%a4
02020: 4cd4 28ac                    movm.l  (%a4),&0x28ac           #load d2,d3,d5,d7,a3,a5
02024: 282f 0008                    mov.l   (8,%a7),%d4             #move outerL to d4
02028: 2c04                         mov.l   %d4,%d6                 #make a copy in d6
0202a: 5386                         subq.l  &1,%d6
0202c: eda7                         asl.l   %d6,%d7                 #2**(L-1)
0202e: 2447                         mov.l   %d7,%a2                 #holds increment value
02030: 9684                         sub.l   %d4,%d3
02032: e7a5                         asl.l   %d3,%d5                 #2**(M+1-L)
02034: 2e85                         mov.l   %d5,(%a7)               #load LE
02036: e285                         asr.l   &1,%d5                  #LE1=LE/2
02038: 2f45 0004                    mov.l   %d5,(4,%a7)             #store LE1
0203c: 5385                         subq.l  &1,%d5
0203e: 2f45 000c                    mov.l   %d5,(0xc,%a7)           #store jlimit

                                j_loop:

02042: 200b                         mov.l   %a3,%d0
02044: 99cc                         sub.l   %a4,%a4                 #clear out a4

                                i_loop:

02046: 2200                         mov.l   %d0,%d1
02048: d2af 0004                    add.l   (4,%a7),%d1

                                                                    #start of 2pt butterfly
0204c: 2630 0c00                    mov.l   (0,%a0,%d0.l*4),%d3     #AR+jAI
02050: 2830 1c00                    mov.l   (0,%a0,%d1.l*4),%d4     #BR+jBI

02054: 2a03                         mov.l   %d3,%d5
02056: 4245                         clr.w   %d5
02058: e285                         asr.l   &1,%d5                  #AR/2 -> d5
0205a: 4843                         swap    %d3
0205c: 4243                         clr.w   %d3
0205e: e283                         asr.l   &1,%d3                  #AI/2 -> d3
02060: 2c04                         mov.l   %d4,%d6
02062: 4246                         clr.w   %d6
02064: e286                         asr.l   &1,%d6                  #BR/2 -> d6
02066: 4844                         swap    %d4
02068: 4244                         clr.w   %d4
0206a: e284                         asr.l   &1,%d4                  #BI/2 -> d4

0206c: 2e06                         mov.l   %d6,%d7
0206e: dc85                         add.l   %d5,%d6                 #AR/2 + BR/2 -> d6
02070: 9a87                         sub.l   %d7,%d5                 #AR/2 - BR/2 -> d5
02072: 2e04                         mov.l   %d4,%d7
02074: d883                         add.l   %d3,%d4                 #AI/2 + BI/2 -> d4
02076: 9687                         sub.l   %d7,%d3                 #AI/2 - BI/2 -> d3

02078: 4846                         swap    %d6
0207a: 4844                         swap    %d4
0207c: 4df0 0c00                    lea     (0,%a0,%d0.l*4),%a6
02080: 3c86                         mov.w   %d6,(%a6)               #store off AR
02082: 3d44 0002                    mov.w   %d4,(2,%a6)             #store off AI

02086: 9dce                         sub.l   %a6,%a6                 #clear a6
02088: a10e                         mov.l   %a6,%acc                #start bottom of butterfly
0208a: 2c31 2c00                    mov.l   (0,%a1,%d2.l*4),%d6     #cosx+jsinx -> d6
0208e: ac05 02c0                    mac.w   %d6:u,%d5:u<<1          #cosx(AR-BR)/2
02092: ac03 0240                    mac.w   %d6:l,%d3:u<<1          #sinx(AI-BI)/2+cosx(AR-BR)/2
02096: a184                         mov.l   %acc,%d4
02098: 4844                         swap    %d4
0209a: 4df0 1c00                    lea     (0,%a0,%d1.l*4),%a6
0209e: 3c84                         mov.w   %d4,(%a6)               #store off BR
020a0: a10c                         mov.l   %a4,%acc                #clear accumulator
020a2: ac03 02c0                    mac.w   %d6:u,%d3:u<<1          #cosx(AI-BI)/2
020a6: ac05 0340                    msac.w  %d6:l,%d5:u<<1          #cosx(AI-BI)/2-sinx(AR-BR)/2
020aa: a184                         mov.l   %acc,%d4
020ac: 4844                         swap    %d4
020ae: 3d44 0002                    mov.w   %d4,(2,%a6)             #store off BI

020b2: d097                         add.l   (%a7),%d0
020b4: b08d                         cmp.l   %d0,%a5
020b6: 6f00 ff8e                    ble.w   i_loop

020ba: d48a                         add.l   %a2,%d2                 #increment coeff offset
020bc: 528b                         addq.l  &1,%a3                  #increment j
020be: b7ef 000c                    cmp.l   %a3,(0xc,%a7)           #end of loop?
020c2: 6f00 ff7e                    ble.w   j_loop
020c6: 52af 0008                    addq.l  &1,(8,%a7)
020ca: 282f 0008                    mov.l   (8,%a7),%d4
020ce: 0c84 0000 0007               cmpi.l  %d4,&7
020d4: 6f00 ff46                    ble.w   l_loop
020d8: 4ac8                         halt

                                    align   0x1000
                                #
                                # Sample data of two sinusoids with freq's of 120 and 170
                                #
                                data:
03000: 4ccc0000                     long    0x4ccc0000
03004: 124f0000                     long    0x124f0000
03008: c66e0000                     long    0xc66e0000
0300c: d26f0000                     long    0xd26f0000
03010: 09860000                     long    0x09860000
03014: 31870000                     long    0x31870000
03018: 2b480000                     long    0x2b480000
0301c: e3d90000                     long    0xe3d90000
03020: b5990000                     long    0xb5990000
03024: f85c0000                     long    0xf85c0000
03028: 44440000                     long    0x44440000
0302c: 27910000                     long    0x27910000
03030: e40a0000                     long    0xe40a0000
03034: ccb70000                     long    0xccb70000
03038: e5b00000                     long    0xe5b00000
0303c: 24c70000                     long    0x24c70000
03040: 43610000                     long    0x43610000
03044: fc940000                     long    0xfc940000
03048: b5510000                     long    0xb5510000
0304c: e0410000                     long    0xe0410000
03050: 2c9b0000                     long    0x2c9b0000
03054: 32c00000                     long    0x32c00000
03058: 07c30000                     long    0x07c30000
0305c: d42d0000                     long    0xd42d0000
03060: c7d00000                     long    0xc7d00000
03064: 0e730000                     long    0x0e730000
03068: 4c6f0000                     long    0x4c6f0000
0306c: 16670000                     long    0x16670000
03070: c59a0000                     long    0xc59a0000
03074: d0180000                     long    0xd0180000
03078: 0b2b0000                     long    0x0b2b0000
0307c: 30f90000                     long    0x30f90000
03080: 29920000                     long    0x29920000
03084: e7060000                     long    0xe7060000
03088: b6930000                     long    0xb6930000
0308c: f41d0000                     long    0xf41d0000
03090: 447b0000                     long    0x447b0000
03094: 2ad10000                     long    0x2ad10000
03098: e2b80000                     long    0xe2b80000
0309c: cc0a0000                     long    0xcc0a0000
030a0: e7830000                     long    0xe7830000
030a4: 228f0000                     long    0x228f0000
030a8: 41e50000                     long    0x41e50000
030ac: 009b0000                     long    0x009b0000
030b0: b5c30000                     long    0xb5c30000
030b4: dc600000                     long    0xdc600000
030b8: 2d6b0000                     long    0x2d6b0000
030bc: 34970000                     long    0x34970000
030c0: 060e0000                     long    0x060e0000
030c4: d5430000                     long    0xd5430000
030c8: c9a20000                     long    0xc9a20000
030cc: 0af90000                     long    0x0af90000
030d0: 4b5b0000                     long    0x4b5b0000
030d4: 1a930000                     long    0x1a930000
030d8: c56c0000                     long    0xc56c0000
030dc: cd420000                     long    0xcd420000
030e0: 0c8b0000                     long    0x0c8b0000
030e4: 311a0000                     long    0x311a0000
030e8: 27a10000                     long    0x27a10000
030ec: e9a70000                     long    0xe9a70000
030f0: b82e0000                     long    0xb82e0000
030f4: f0030000                     long    0xf0030000
030f8: 43f90000                     long    0x43f90000
030fc: 2e640000                     long    0x2e640000
03100: 00000000 00000000            long    0,0,0,0
03108: 00000000 00000000
03110: 00000000 00000000            long    0,0,0,0
03118: 00000000 00000000
03120: 00000000 00000000            long    0,0,0,0
03128: 00000000 00000000
03130: 00000000 00000000            long    0,0,0,0
03138: 00000000 00000000
03140: 00000000 00000000            long    0,0,0,0
03148: 00000000 00000000
03150: 00000000 00000000            long    0,0,0,0
03158: 00000000 00000000
03160: 00000000 00000000            long    0,0,0,0
03168: 00000000 00000000
03170: 00000000 00000000            long    0,0,0,0
03178: 00000000 00000000
03180: 00000000 00000000            long    0,0,0,0
03188: 00000000 00000000
03190: 00000000 00000000            long    0,0,0,0
03198: 00000000 00000000
031a0: 00000000 00000000            long    0,0,0,0
031a8: 00000000 00000000
031b0: 00000000 00000000            long    0,0,0,0
031b8: 00000000 00000000
031c0: 00000000 00000000            long    0,0,0,0
031c8: 00000000 00000000
031d0: 00000000 00000000            long    0,0,0,0
031d8: 00000000 00000000
031e0: 00000000 00000000            long    0,0,0,0
031e8: 00000000 00000000
031f0: 00000000 00000000            long    0,0,0,0
031f8: 00000000 00000000
03200: 00000000 00000000            long    0,0,0,0
03208: 00000000 00000000

                                    align   0x1000
                                coeff:
04000: 7fff0000                     long    0x7fff0000
04004: 7fd80647                     long    0x7fd80647
04008: 7f620c8b                     long    0x7f620c8b
0400c: 7e9d12c8                     long    0x7e9d12c8
04010: 7d8a18f8                     long    0x7d8a18f8
04014: 7c291f19                     long    0x7c291f19
04018: 7a7d2528                     long    0x7a7d2528
0401c: 78842b1f                     long    0x78842b1f
04020: 764130fb                     long    0x764130fb
04024: 73b536ba                     long    0x73b536ba
04028: 70e23c56                     long    0x70e23c56
0402c: 6dca41ce                     long    0x6dca41ce
04030: 6a6d471c                     long    0x6a6d471c
04034: 66cf4c3f                     long    0x66cf4c3f
04038: 62f25133                     long    0x62f25133
0403c: 5ed755f5                     long    0x5ed755f5
04040: 5a825a82                     long    0x5a825a82
04044: 55f55ed7                     long    0x55f55ed7
04048: 513362f2                     long    0x513362f2
0404c: 4c3f66cf                     long    0x4c3f66cf
04050: 471c6a6d                     long    0x471c6a6d
04054: 41ce6dca                     long    0x41ce6dca
04058: 3c5670e2                     long    0x3c5670e2
0405c: 36ba73b5                     long    0x36ba73b5
04060: 30fb7641                     long    0x30fb7641
04064: 2b1f7884                     long    0x2b1f7884
04068: 25287a7d                     long    0x25287a7d
0406c: 1f197c29                     long    0x1f197c29
04070: 18f87d8a                     long    0x18f87d8a
04074: 12c87e9d                     long    0x12c87e9d
04078: 0c8b7f62                     long    0x0c8b7f62
0407c: 06477fd8                     long    0x06477fd8
04080: 00007fff                     long    0x00007fff
04084: f9b97fd8                     long    0xf9b97fd8
04088: f3757f62                     long    0xf3757f62
0408c: ed387e9d                     long    0xed387e9d
04090: e7087d8a                     long    0xe7087d8a
04094: e0e77c29                     long    0xe0e77c29
04098: dad87a7d                     long    0xdad87a7d
0409c: d4e17884                     long    0xd4e17884
040a0: cf057641                     long    0xcf057641
040a4: c94673b5                     long    0xc94673b5
040a8: c3aa70e2                     long    0xc3aa70e2
040ac: be326dca                     long    0xbe326dca
040b0: b8e46a6d                     long    0xb8e46a6d
040b4: b3c166cf                     long    0xb3c166cf
040b8: aecd62f2                     long    0xaecd62f2
040bc: aa0b5ed7                     long    0xaa0b5ed7
040c0: a57e5a82                     long    0xa57e5a82
040c4: a12955f5                     long    0xa12955f5
040c8: 9d0e5133                     long    0x9d0e5133
040cc: 99314c3f                     long    0x99314c3f
040d0: 9593471c                     long    0x9593471c
040d4: 923641ce                     long    0x923641ce
040d8: 8f1e3c56                     long    0x8f1e3c56
040dc: 8c4b36ba                     long    0x8c4b36ba
040e0: 89bf30fb                     long    0x89bf30fb
040e4: 877c2b1f                     long    0x877c2b1f
040e8: 85832528                     long    0x85832528
040ec: 83d71f19                     long    0x83d71f19
040f0: 827618f8                     long    0x827618f8
040f4: 816312c8                     long    0x816312c8
040f8: 809e0c8b                     long    0x809e0c8b
040fc: 80280647                     long    0x80280647

                                    align   0x1000
                                init:
05000: 00000000                     long    0x00000000
05004: 00000008                     long    0x00000008
05008: 00000001                     long    0x00000001
0500c: 00000001                     long    0x00000001
05010: 00000000                     long    0x00000000
05014: 0000007f                     long    0x0000007f





