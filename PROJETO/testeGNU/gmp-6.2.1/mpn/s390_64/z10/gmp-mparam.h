/* S/390-64 gmp-mparam.h -- Compiler/machine parameter header file.

Copyright 1991, 1993, 1994, 2000-2011, 2014, 2015 Free Software Foundation,
Inc.

This file is part of the GNU MP Library.

The GNU MP Library is free software; you can redistribute it and/or modify
it under the terms of either:

  * the GNU Lesser General Public License as published by the Free
    Software Foundation; either version 3 of the License, or (at your
    option) any later version.

or

  * the GNU General Public License as published by the Free Software
    Foundation; either version 2 of the License, or (at your option) any
    later version.

or both in parallel, as here.

The GNU MP Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received copies of the GNU General Public License and the
GNU Lesser General Public License along with the GNU MP Library.  If not,
see https://www.gnu.org/licenses/.  */

#define GMP_LIMB_BITS 64
#define GMP_LIMB_BYTES 8

/* 4400 MHz IBM z10 */
/* FFT tuning limit = 30 M */
/* Generated by tuneup.c, 2015-10-09, gcc 4.8 */

#define DIVREM_1_NORM_THRESHOLD              0  /* always */
#define DIVREM_1_UNNORM_THRESHOLD            3
#define MOD_1_1P_METHOD                      2
#define MOD_1_NORM_THRESHOLD                 0  /* always */
#define MOD_1_UNNORM_THRESHOLD               3
#define MOD_1N_TO_MOD_1_1_THRESHOLD          6
#define MOD_1U_TO_MOD_1_1_THRESHOLD          5
#define MOD_1_1_TO_MOD_1_2_THRESHOLD        15
#define MOD_1_2_TO_MOD_1_4_THRESHOLD        17
#define PREINV_MOD_1_TO_MOD_1_THRESHOLD     24
#define USE_PREINV_DIVREM_1                  1
#define DIV_QR_1N_PI1_METHOD                 1
#define DIV_QR_1_NORM_THRESHOLD              2
#define DIV_QR_1_UNNORM_THRESHOLD        MP_SIZE_T_MAX  /* never */
#define DIV_QR_2_PI2_THRESHOLD           MP_SIZE_T_MAX  /* never */
#define DIVEXACT_1_THRESHOLD                 0  /* always */
#define BMOD_1_TO_MOD_1_THRESHOLD           48

#define MUL_TOOM22_THRESHOLD                 9
#define MUL_TOOM33_THRESHOLD                65
#define MUL_TOOM44_THRESHOLD                94
#define MUL_TOOM6H_THRESHOLD               129
#define MUL_TOOM8H_THRESHOLD               187

#define MUL_TOOM32_TO_TOOM43_THRESHOLD      65
#define MUL_TOOM32_TO_TOOM53_THRESHOLD      61
#define MUL_TOOM42_TO_TOOM53_THRESHOLD      62
#define MUL_TOOM42_TO_TOOM63_THRESHOLD      64
#define MUL_TOOM43_TO_TOOM54_THRESHOLD      85

#define SQR_BASECASE_THRESHOLD               0  /* always (native) */
#define SQR_TOOM2_THRESHOLD                 11
#define SQR_TOOM3_THRESHOLD                 80
#define SQR_TOOM4_THRESHOLD                118
#define SQR_TOOM6_THRESHOLD                189
#define SQR_TOOM8_THRESHOLD                236

#define MULMID_TOOM42_THRESHOLD             24

#define MULMOD_BNM1_THRESHOLD                7
#define SQRMOD_BNM1_THRESHOLD                9

#define MUL_FFT_MODF_THRESHOLD             252  /* k = 5 */
#define MUL_FFT_TABLE3                                      \
  { {    252, 5}, {      9, 6}, {      5, 5}, {     11, 6}, \
    {      6, 5}, {     13, 6}, {      7, 5}, {     15, 6}, \
    {     13, 7}, {      7, 6}, {     15, 7}, {     13, 8}, \
    {      7, 7}, {     15, 8}, {      9, 7}, {     19, 8}, \
    {     11, 7}, {     23, 8}, {     13, 9}, {      7, 8}, \
    {     15, 7}, {     31, 8}, {     19, 9}, {     11, 8}, \
    {     27,10}, {      7, 9}, {     15, 8}, {     31, 9}, \
    {     19, 8}, {     41, 9}, {     27,10}, {     15, 9}, \
    {     39,10}, {     23, 9}, {     47,11}, {     15,10}, \
    {     31, 9}, {     67,10}, {     39, 9}, {     79,10}, \
    {     47,11}, {     31,10}, {     63, 9}, {    127, 8}, \
    {    255,10}, {     71, 9}, {    143, 8}, {    287, 7}, \
    {    575, 6}, {   1151,10}, {     79,11}, {     47,12}, \
    {     31,11}, {     63,10}, {    127, 9}, {    255, 8}, \
    {    511,10}, {    143,11}, {     79,10}, {    159, 9}, \
    {    319, 8}, {    639,10}, {    175, 8}, {    703,11}, \
    {     95,10}, {    191, 9}, {    383, 8}, {    767, 9}, \
    {    415, 8}, {    831, 7}, {   1663,10}, {    239, 9}, \
    {    479,12}, {     63,11}, {    127,10}, {    255, 9}, \
    {    511,11}, {    143,10}, {    287, 9}, {    575, 8}, \
    {   1151,10}, {    319, 9}, {    639,11}, {    175,10}, \
    {    351, 9}, {    703, 8}, {   1407, 7}, {   2815,11}, \
    {    191,10}, {    383, 9}, {    767,10}, {    415,11}, \
    {    223,10}, {    447, 9}, {    895,13}, {     63,11}, \
    {    255,10}, {    575, 9}, {   1151,12}, {    159,11}, \
    {    319,10}, {    639, 9}, {   1279,10}, {    703, 9}, \
    {   1407,12}, {    191,10}, {    767,11}, {    415,12}, \
    {    223,11}, {    447,10}, {    895,11}, {    479,13}, \
    {    127,12}, {    255,11}, {    511,12}, {    287,10}, \
    {   1151,12}, {    319,11}, {    703,10}, {   1407, 9}, \
    {   2815,12}, {    383,11}, {    767,12}, {    415,11}, \
    {    831,10}, {   1663,12}, {    447,11}, {    895,10}, \
    {   1791, 9}, {   3583,12}, {    479,11}, {    959,10}, \
    {   1919, 9}, {   3839,12}, {    511, 9}, {   4095, 6}, \
    {  32767, 8}, {   8447,11}, {   1151,13}, {    319,12}, \
    {    639,10}, {   2559,12}, {    703,10}, {   2815,12}, \
    {    831,11}, {   1663,12}, {    895,11}, {   1791,12}, \
    {    959,11}, {   1919,14}, {    255,13}, {    511,11}, \
    {   2047,12}, {   1215,10}, {   4863,11}, {   2559,14}, \
    {    383,12}, {   1535,13}, {    831,12}, {   1663,13}, \
    {    895,12}, {   1791,11}, {   3583,15}, {    255,14}, \
    {    511,13}, {   1151,14}, {    639,13}, {   1279,12}, \
    {   2559,13}, {   1407,12}, {   2815,14}, {    767,13}, \
    {   1663,10}, {  13311,14}, {    895,13}, {   1791,12}, \
    {   3583,13}, {   1919,12}, {   3839,10}, {  15359,14}, \
    {   1151,13}, {   2431,12}, {   4863,14}, {   1279,13}, \
    {   2559,14}, {   1407,13}, {   2815,15}, {    767,14}, \
    {   1791,13}, {   8192,14}, {  16384,15}, {  32768,16}, \
    {  65536,17}, { 131072,18}, { 262144,19}, { 524288,20}, \
    {1048576,21}, {2097152,22}, {4194304,23}, {8388608,24} }
#define MUL_FFT_TABLE3_SIZE 200
#define MUL_FFT_THRESHOLD                 1728

#define SQR_FFT_MODF_THRESHOLD             212  /* k = 5 */
#define SQR_FFT_TABLE3                                      \
  { {    212, 5}, {      7, 4}, {     15, 5}, {      9, 4}, \
    {     19, 6}, {      5, 5}, {     11, 6}, {      6, 5}, \
    {     13, 6}, {      7, 5}, {     15, 6}, {      9, 5}, \
    {     19, 6}, {     13, 7}, {      7, 6}, {     15, 7}, \
    {      9, 6}, {     19, 7}, {     13, 8}, {      7, 7}, \
    {     16, 8}, {      9, 7}, {     19, 8}, {     11, 7}, \
    {     23, 8}, {     13, 9}, {      7, 8}, {     19, 9}, \
    {     11, 8}, {     25,10}, {      7, 9}, {     15, 8}, \
    {     31, 9}, {     23,10}, {     15, 9}, {     39,10}, \
    {     23,11}, {     15,10}, {     31, 9}, {     63,10}, \
    {     47,11}, {     31,10}, {     63, 9}, {    127, 8}, \
    {    255,10}, {     71, 9}, {    143, 8}, {    287, 7}, \
    {    575,11}, {     47,12}, {     31,11}, {     63,10}, \
    {    127, 9}, {    255, 8}, {    511,10}, {    143, 9}, \
    {    287, 8}, {    575, 7}, {   1151,11}, {     79,10}, \
    {    159, 9}, {    319,10}, {    175, 9}, {    351, 8}, \
    {    703, 7}, {   1407,10}, {    191, 9}, {    383,10}, \
    {    207,11}, {    111,10}, {    223,12}, {     63,11}, \
    {    127,10}, {    255, 9}, {    511,11}, {    143,10}, \
    {    287, 9}, {    575, 8}, {   1151,11}, {    159,10}, \
    {    319, 9}, {    639,11}, {    175,10}, {    351, 9}, \
    {    703, 8}, {   1407,11}, {    191,10}, {    383,11}, \
    {    207,10}, {    415,11}, {    223,10}, {    447,13}, \
    {     63,12}, {    127,11}, {    255,10}, {    511,11}, \
    {    287,10}, {    575, 9}, {   1151,12}, {    159,11}, \
    {    319,10}, {    639,11}, {    351,10}, {    703, 9}, \
    {   1407,12}, {    191,11}, {    383,10}, {    767,11}, \
    {    415,12}, {    223,11}, {    447,10}, {    895, 9}, \
    {   1791,13}, {    127,12}, {    255,11}, {    511,12}, \
    {    287,11}, {    575,10}, {   1151,11}, {    607,12}, \
    {    319,11}, {    639,12}, {    351,11}, {    703,10}, \
    {   1407,13}, {    191,12}, {    383,11}, {    767,12}, \
    {    415,11}, {    831,10}, {   1663,12}, {    447,11}, \
    {    895,10}, {   1791,14}, {    127,13}, {    255,12}, \
    {    511,11}, {   1023,10}, {   2047,11}, {   1151,12}, \
    {    607,13}, {    319,11}, {   1279, 9}, {   5119, 8}, \
    {  10751, 4}, { 172031, 7}, {  22015,11}, {   1407,10}, \
    {   2943, 8}, {  11775, 9}, {   6143,12}, {    831, 8}, \
    {  13311,11}, {   1791,14}, {    255,11}, {   2047,13}, \
    {    575,12}, {   1151,13}, {    639,12}, {   1279,13}, \
    {    703,12}, {   1407,11}, {   2815,12}, {   1471, 9}, \
    {  11775,13}, {    767,12}, {   1535,13}, {    831,12}, \
    {   1663,13}, {    895,11}, {   3583,13}, {    959,12}, \
    {   1919,10}, {   7679, 9}, {  15359,11}, {   3967,14}, \
    {    511,13}, {   1151,12}, {   2303,13}, {   1215,14}, \
    {    639,13}, {   1279,12}, {   2559,14}, {    767,13}, \
    {   1663,14}, {    895,15}, {    511,13}, {   2047,14}, \
    {   1279,13}, {   2815,15}, {    767,14}, {   1791,13}, \
    {   3583,16}, {  65536,17}, { 131072,18}, { 262144,19}, \
    { 524288,20}, {1048576,21}, {2097152,22}, {4194304,23}, \
    {8388608,24} }
#define SQR_FFT_TABLE3_SIZE 201
#define SQR_FFT_THRESHOLD                 1344

#define MULLO_BASECASE_THRESHOLD             0  /* always */
#define MULLO_DC_THRESHOLD                  33
#define MULLO_MUL_N_THRESHOLD             2586
#define SQRLO_BASECASE_THRESHOLD             0  /* always */
#define SQRLO_DC_THRESHOLD                  63
#define SQRLO_SQR_THRESHOLD               2663

#define DC_DIV_QR_THRESHOLD                 37
#define DC_DIVAPPR_Q_THRESHOLD             143
#define DC_BDIV_QR_THRESHOLD                37
#define DC_BDIV_Q_THRESHOLD                 86

#define INV_MULMOD_BNM1_THRESHOLD           16
#define INV_NEWTON_THRESHOLD               147
#define INV_APPR_THRESHOLD                 141

#define BINV_NEWTON_THRESHOLD              141
#define REDC_1_TO_REDC_N_THRESHOLD          39

#define MU_DIV_QR_THRESHOLD                807
#define MU_DIVAPPR_Q_THRESHOLD             807
#define MUPI_DIV_QR_THRESHOLD               81
#define MU_BDIV_QR_THRESHOLD               654
#define MU_BDIV_Q_THRESHOLD                792

#define POWM_SEC_TABLE  1,28,163,1083,2111

#define GET_STR_DC_THRESHOLD                19
#define GET_STR_PRECOMPUTE_THRESHOLD        33
#define SET_STR_DC_THRESHOLD               898
#define SET_STR_PRECOMPUTE_THRESHOLD      2031

#define FAC_DSC_THRESHOLD                  372
#define FAC_ODD_THRESHOLD                   23

#define MATRIX22_STRASSEN_THRESHOLD         17
#define HGCD_THRESHOLD                     105
#define HGCD_APPR_THRESHOLD                111
#define HGCD_REDUCE_THRESHOLD             1137
#define GCD_DC_THRESHOLD                   285
#define GCDEXT_DC_THRESHOLD                210
#define JACOBI_BASE_METHOD                   4
