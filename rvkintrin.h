//	rvkintrin.h
//	2021-11-08	Markku-Juhani O. Saarinen <mjos@pqshield.com>
//	Copyright (c) 2021, PQShield Ltd. All rights reserved.

/*
 *	_rv_*(...)
 *	  RV32/64 intrinsics that operate on the "long" data type
 *
 *	_rv32_*(...)
 *	  RV32/64 intrinsics that operate on the "int32_t" data type
 *
 *	_rv64_*(...)
 *	  RV64-only intrinsics that operate on the "int64_t" data type
 *
 */

#ifndef _RVKINTRIN
#define _RVKINTRIN

#if !defined(__riscv_xlen) && !defined(RVINTRIN_EMULATE)
#warning "Target is not RISC-V. Enabling <rvk_emu.h> insecure emulation."
#define RVINTRIN_EMULATE 1
#endif

#if defined(RVINTRIN_EMULATE)
//	intrinsics via emulation (insecure)
#include "rvk_emu.h"

#elif defined(RVKINTRIN_INLINE)
//	intrinsics via inline assembler
#include "rvk_inline.h"
#else

//	Mappings to builtins

//	Zbkb (Zk, Zkn, Zks): Bitmanipulation instructions for Cryptography

//  Zk, Zkn, Zks, Zbkb on RV32
int32_t __builtin_riscv_ror_32(int32_t rs1, int32_t rs2);       //  ROR or RORI
int32_t __builtin_riscv_rol_32(int32_t rs1, int32_t rs2);       //  ROL or RORI

//  Zk, Zkn, Zks, Zbkb on RV64
int32_t __builtin_riscv_ror_32(int32_t rs1, int32_t rs2);       //  RORW or RORIW
int32_t __builtin_riscv_rol_32(int32_t rs1, int32_t rs2);       //  ROLW or RORIW
int64_t __builtin_riscv_ror_64(int64_t rs1, int64_t rs2);       //  ROR or RORI
int64_t __builtin_riscv_rol_64(int64_t rs1, int64_t rs2);       //  ROL or RORI

//  Zk, Zkn, Zks, Zbkb on RV32,RV64
long __builtin_riscv_andn(long rs1, long rs2);                  //  ANDN
long __builtin_riscv_orn(long rs1, long rs2);                   //  ORN
long __builtin_riscv_xnor(long rs1, long rs2);                  //  XNOR

//  Zk, Zkn, Zks, Zbkb on RV32
int32_t __builtin_riscv_pack_32(int32_t rs1, int32_t rs2);      //  PACK
int32_t __builtin_riscv_packh_32(int32_t rs1, int32_t rs2);     //  PACKH

//  Zk, Zkn, Zks, Zbkb on RV64
int64_t __builtin_riscv_pack_64(int64_t rs1, int64_t rs2);      //  PACK
int64_t __builtin_riscv_packh_64(int64_t rs1, int64_t rs2);     //  PACKH
int32_t __builtin_riscv_pack_32(int32_t rs1, int32_t rs2);      //  PACKW

//  Zk, Zkn, Zks, Zbkb on RV32
int32_t __builtin_riscv_brev8_32(int32_t rs1);                  //  BREV8 (GREVI)
int32_t __builtin_riscv_rev8_32(int32_t rs1);                   //  REV8 (GREVI)

//  Zk, Zkn, Zks, Zbkb on RV64
int64_t __builtin_riscv_brev8_64(int64_t rs1);                  //  BREV8 (GREVI)
int64_t __builtin_riscv_rev8_64(int64_t rs1);                   //  REV8 (GREVI)

//  Zk, Zkn, Zks, Zbkb on RV32
int32_t __builtin_riscv_zip_32(int32_t rs1);                    //  ZIP (SHFLI)
int32_t __builtin_riscv_unzip_32(int32_t rs1);                  //  UNZIP (UNSHFLI)

//  Zk, Zkn, Zks, Zbkb implementation of a generic builtin on RV32 
uint32_t __builtin_bswap32(uint32_t x);                         //  REV8 (GREVI)

//  Zk, Zkn, Zks, Zbkb implementation of generic builtins on RV64
uint64_t __builtin_bswap64(uint64_t x);                         //  REV8 (GREVI)
uint32_t __builtin_bswap32(uint32_t x);                         //  REV8 + SRAI

Zbkc (Zk, Zkn, Zks): Carry-less multiply instructions

//  Zk, Zkn, Zks, Zbkc on RV32
int32_t __builtin_riscv_clmul_32(int32_t rs1, int32_t rs2);     //  CLMUL
int32_t __builtin_riscv_clmulh_32(int32_t rs1, int32_t rs2);    //  CLMULH

//  Zk, Zkn, Zks, Zbkc on RV64
int64_t __builtin_riscv_clmul_64(int64_t rs1, int64_t rs2);     //  CLMUL
int64_t __builtin_riscv_clmulh_64(int64_t rs1, int64_t rs2);    //  CLMULH

Zbkx (Zk, Zkn, Zks): Crossbar permutation instructions

//  Zk, Zkn, Zks, Zbkx on RV32
int32_t __builtin_riscv_xperm4_32(int32_t rs1, int32_t rs2);    //  XPERM4
int32_t __builtin_riscv_xperm8_32(int32_t rs1, int32_t rs2);    //  XPERM8

//  Zk, Zkn, Zks, Zbkx on RV64
int64_t __builtin_riscv_xperm4_64(int64_t rs1, int64_t rs2);    //  XPERM4
int64_t __builtin_riscv_xperm8_64(int64_t rs1, int64_t rs2);    //  XPERM8

Zknd (Zk, Zkn): NIST Suite: AES Decryption

//  Zk, Zkn, Zknd on RV32
int32_t __builtin_riscv_aes32dsi(int32_t rs1, int32_t rs2, int bs);     //  AES32DSI
int32_t __builtin_riscv_aes32dsmi(int32_t rs1, int32_t rs2, int bs);    //  AES32DSMI

//  Zk, Zkn, Zknd on RV64
int64_t __builtin_riscv_aes64ds(int64_t rs1, int64_t rs2);      //  AES64DS
int64_t __builtin_riscv_aes64dsm(int64_t rs1, int64_t rs2);     //  AES64DSM
int64_t __builtin_riscv_aes64im(int64_t rs1);                   //  AES64IM

Zkne (Zk, Zkn): NIST Suite: AES Encryption

//  Zk, Zkn, Zkne on RV32
int32_t __builtin_riscv_aes32esi(int32_t rs1, int32_t rs2, int bs);     //  AES32ESI
int32_t __builtin_riscv_aes32esmi(int32_t rs1, int32_t rs2, int bs);    //  AES32ESMI

//  Zk, Zkn, Zkne or RV64
int64_t __builtin_riscv_aes64es(int64_t rs1, int64_t rs2);      //  AES64ES
int64_t __builtin_riscv_aes64esm(int64_t rs1, int64_t rs2);     //  AES64ESM

Zknd and Zkne (Zk, Zkn): NIST Suite: AES Key Schedule (Encrypt & Decrypt)

//  Zk, Zkn, Zkne, Zknd on RV64
int64_t __builtin_riscv_aes64ks1i(int64_t rs1, int rnum);       //  AES64KS1I
int64_t __builtin_riscv_aes64ks2(int64_t rs1, int64_t rs2);     //  AES64KS2

Zknh (Zk, Zkn): NIST Suite: Hash Function Instructions

//  Zk, Zkn, Zknh on RV32, RV64
long __builtin_riscv_sha256sig0(long rs1);                      //  SHA256SIG0
long __builtin_riscv_sha256sig1(long rs1);                      //  SHA256SIG1
long __builtin_riscv_sha256sum0(long rs1);                      //  SHA256SUM0
long __builtin_riscv_sha256sum1(long rs1);                      //  SHA256SUM1

//  Zk, Zkn, Zknh on RV32
int32_t __builtin_riscv_sha512sig0h(int32_t rs1, int32_t rs2);  //  SHA512SIG0H
int32_t __builtin_riscv_sha512sig0l(int32_t rs1, int32_t rs2);  //  SHA512SIG0L
int32_t __builtin_riscv_sha512sig1h(int32_t rs1, int32_t rs2);  //  SHA512SIG1H
int32_t __builtin_riscv_sha512sig1l(int32_t rs1, int32_t rs2);  //  SHA512SIG1L
int32_t __builtin_riscv_sha512sum0r(int32_t rs1, int32_t rs2);  //  SHA512SUM0R
int32_t __builtin_riscv_sha512sum1r(int32_t rs1, int32_t rs2);  //  SHA512SUM1R

//  Zk, Zkn, Zknh on RV64
int64_t __builtin_riscv_sha512sig0(int64_t rs1);                //  SHA512SIG0
int64_t __builtin_riscv_sha512sig1(int64_t rs1);                //  SHA512SIG1
int64_t __builtin_riscv_sha512sum0(int64_t rs1);                //  SHA512SUM0
int64_t __builtin_riscv_sha512sum1(int64_t rs1);                //  SHA512SUM1

Zksed (Zks): ShangMi Suite: SM4 Block Cipher Instructions

//  Zks, Zksed on RV32, RV64
long __builtin_riscv_sm4ks(int32_t rs1, int32_t rs2, int bs);   //  SM4KS
long __builtin_riscv_sm4ed(int32_t rs1, int32_t rs2, int bs);   //  SM4ED

Zksh (Zks): ShangMi Suite: SM3 Hash Function Instructions

//  Zks, Zksh on RV32, RV64
long __builtin_riscv_sm3p0(long rs1);                           //  SM3P0
long __builtin_riscv_sm3p1(long rs1);                           //  SM3P1


/endif
