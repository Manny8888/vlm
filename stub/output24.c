/************************************************************************
 * WARNING: DO NOT EDIT THIS FILE.  THIS FILE WAS AUTOMATICALLY GENERATED
 * ANY CHANGES MADE TO THIS FILE WILL BE LOST
 *
 * File translated:      ../alpha-emulator/idouble.as
 ************************************************************************/

  /* Support for double precision floating point. */
/* start FetchDoubleFloat */


fetchdoublefloat:
  if (_trace) printf("fetchdoublefloat:\n");
  sp = sp + -8;   
  /* Memory Read Internal */

vma_memory_read30300:
  t7 = arg2 + ivory;
  arg6 = (t7 * 4);   
  arg5 = LDQ_U(t7);   
  t5 = arg2 - t11;   		// Stack cache offset 
  t8 = *(u64 *)&(processor->dataread_mask);   
  t6 = ((u64)t5 < (u64)t12) ? 1 : 0;   		// In range? 
  arg6 = *(s32 *)arg6;   
  arg5 = (u8)(arg5 >> ((t7&7)*8));   
  if (t6 != 0)   
    goto vma_memory_read30302;

vma_memory_read30301:
  t7 = zero + 240;   
  t8 = t8 >> (arg5 & 63);   
  t7 = t7 >> (arg5 & 63);   
  if (t8 & 1)   
    goto vma_memory_read30304;

vma_memory_read30311:
  t5 = arg5 - Type_Fixnum;   
  t5 = t5 & 63;		// Strip CDR code 
  if (t5 != 0)   
    goto fetch_double_float_internal30299;
  *((u32 *)(&processor->fp0)+1) = arg6;
  arg2 = arg2 + 1;
  /* Memory Read Internal */

vma_memory_read30312:
  t7 = arg2 + ivory;
  arg6 = (t7 * 4);   
  arg5 = LDQ_U(t7);   
  t5 = arg2 - t11;   		// Stack cache offset 
  t8 = *(u64 *)&(processor->dataread_mask);   
  t6 = ((u64)t5 < (u64)t12) ? 1 : 0;   		// In range? 
  arg6 = *(s32 *)arg6;   
  arg5 = (u8)(arg5 >> ((t7&7)*8));   
  if (t6 != 0)   
    goto vma_memory_read30314;

vma_memory_read30313:
  t7 = zero + 240;   
  t8 = t8 >> (arg5 & 63);   
  t7 = t7 >> (arg5 & 63);   
  if (t8 & 1)   
    goto vma_memory_read30316;

vma_memory_read30323:
  t5 = arg5 - Type_Fixnum;   
  t5 = t5 & 63;		// Strip CDR code 
  if (t5 != 0)   
    goto fetch_double_float_internal30299;
  *(u32 *)&processor->fp0 = arg6;
  sp = sp + 8;   
  goto *r0; /* ret */

vma_memory_read30316:
  if (_trace) printf("vma_memory_read30316:\n");
  if ((t7 & 1) == 0)   
    goto vma_memory_read30315;
  arg2 = (u32)arg6;   		// Do the indirect thing 
  goto vma_memory_read30312;   

vma_memory_read30315:
  if (_trace) printf("vma_memory_read30315:\n");

vma_memory_read30314:
  if (_trace) printf("vma_memory_read30314:\n");
  *(u64 *)sp = r0;   
  r0 = (u64)&&return0379;
  goto memoryreaddatadecode;
return0379:
  r0 = *(u64 *)sp;   
  goto vma_memory_read30323;   

vma_memory_read30304:
  if (_trace) printf("vma_memory_read30304:\n");
  if ((t7 & 1) == 0)   
    goto vma_memory_read30303;
  arg2 = (u32)arg6;   		// Do the indirect thing 
  goto vma_memory_read30300;   

vma_memory_read30303:
  if (_trace) printf("vma_memory_read30303:\n");

vma_memory_read30302:
  if (_trace) printf("vma_memory_read30302:\n");
  *(u64 *)sp = r0;   
  r0 = (u64)&&return0380;
  goto memoryreaddatadecode;
return0380:
  r0 = *(u64 *)sp;   
  goto vma_memory_read30311;   

fetch_double_float_internal30299:
  if (_trace) printf("fetch_double_float_internal30299:\n");
  arg6 = Type_DoubleFloat;		// arg6 = tag to dispatch on 
  arg3 = 0;		// arg3 = stackp 
  arg1 = 2;		// arg1 = instruction arity 
  arg4 = 1;		// arg4 = arithmeticp 
  goto numericexception;

/* end FetchDoubleFloat */
/* start ConsDoubleFloat */


consdoublefloat:
  if (_trace) printf("consdoublefloat:\n");
  sp = sp + -8;   
  arg6 = *(s32 *)&processor->fp0;   
  arg5 = *((s32 *)(&processor->fp0)+1);   
  t5 = *(u64 *)&(processor->lcarea);   
  t8 = *(u64 *)&(processor->niladdress);   
  t6 = *(s32 *)&processor->lclength;   
  arg2 = *(u64 *)&(processor->lcaddress);   		// Fetch address 
  t7 = (t5 == t8) ? 1 : 0;   
  if (t7 != 0)   		// Decached area 
    goto cons_double_float_internal30324;
  t7 = t6 - 2;   		// Effectively an unsigned 32-bit compare 
  if ((s64)t7 < 0)   		// Insufficient cache 
    goto cons_double_float_internal30324;
  /* trapb force the trap to occur here */   		// Force the trap to occur here 
		/* Store remaining length */
  *(u32 *)&processor->lclength = t7;
  t8 = (u32)arg2;   
  t8 = t8 + 2;		// Increment address 
		/* Store updated address */
  *(u32 *)&processor->lcaddress = t8;
  arg2 = (u32)arg2;   
  t9 = Type_Fixnum;
  t9 = t9 | 128;
  t5 = arg2 + ivory;
  t8 = (t5 * 4);   
  t7 = LDQ_U(t5);   
  t6 = (t9 & 0xff) << ((t5&7)*8);   
  t7 = t7 & ~(0xffL << (t5&7)*8);   

force_alignment30325:
  if (_trace) printf("force_alignment30325:\n");
  t7 = t7 | t6;
  STQ_U(t5, t7);   
  *(u32 *)t8 = arg5;
  t10 = arg2 + 1;
  t9 = Type_Fixnum;
  t9 = t9 | 64;
  t5 = t10 + ivory;
  t8 = (t5 * 4);   
  t7 = LDQ_U(t5);   
  t6 = (t9 & 0xff) << ((t5&7)*8);   
  t7 = t7 & ~(0xffL << (t5&7)*8);   

force_alignment30326:
  if (_trace) printf("force_alignment30326:\n");
  t7 = t7 | t6;
  STQ_U(t5, t7);   
  *(u32 *)t8 = arg6;
  sp = sp + 8;   
  goto *r0; /* ret */

cons_double_float_internal30324:
  if (_trace) printf("cons_double_float_internal30324:\n");
  arg6 = Type_DoubleFloat;		// arg6 = tag to dispatch on 
  arg3 = 0;		// arg3 = stackp 
  arg1 = 2;		// arg1 = instruction arity 
  arg4 = 1;		// arg4 = arithmeticp 
  goto numericexception;

/* end ConsDoubleFloat */
/* start DoDoubleFloatOp */

  /* Halfword operand from stack instruction - DoDoubleFloatOp */
  /* arg2 has the preloaded 8 bit operand. */

dodoublefloatop:
  if (_trace) printf("dodoublefloatop:\n");

DoDoubleFloatOpIM:
  if (_trace) printf("DoDoubleFloatOpIM:\n");
  /* This sequence is lukewarm */
  *(u32 *)&processor->immediate_arg = arg2;
  arg1 = *(u64 *)&(processor->immediate_arg);   
  goto begindodoublefloatop;   

DoDoubleFloatOpSP:
  if (_trace) printf("DoDoubleFloatOpSP:\n");
  arg1 = arg5;		// Assume SP mode 
  if (arg2 == 0)   		// SP-pop mode 
    arg1 = iSP;
  if (arg2 == 0)   		// Adjust SP if SP-pop mode 
    iSP = arg4;

DoDoubleFloatOpLP:
  if (_trace) printf("DoDoubleFloatOpLP:\n");

DoDoubleFloatOpFP:
  if (_trace) printf("DoDoubleFloatOpFP:\n");

headdodoublefloatop:
  if (_trace) printf("headdodoublefloatop:\n");
  arg1 = (arg2 * 8) + arg1;  		// Compute operand address 
  arg1 = *(u64 *)arg1;   		// Get the operand 

begindodoublefloatop:
  if (_trace) printf("begindodoublefloatop:\n");
  /* arg1 has the operand, not sign extended if immediate. */
  arg3 = *(s32 *)(iSP + -24);   		// X high 
  arg4 = *(s32 *)(iSP + -16);   		// X low 
  arg5 = *(s32 *)(iSP + -8);   		// Y high 
  arg6 = *(s32 *)iSP;   		// Y low 
  arg3 = arg3 << 32;   		// Get high part up top 
  arg4 = (u32)arg4;   
  arg5 = arg5 << 32;   		// Get high part up top 
  arg6 = (u32)arg6;   
  arg3 = arg3 | arg4;		// ARG3 is now X 
  arg5 = arg5 | arg6;		// ARG5 is now Y 
  *(u64 *)&processor->fp0 = arg3;   
  *(u64 *)&processor->fp1 = arg5;   
  t2 = arg1 >> 32;   		// Immediate tag 
  t1 = (u32)arg1;   		// Immediate data 
  t3 = t2 - Type_Fixnum;   
  t3 = t3 & 63;		// Strip CDR code 
  if (t3 != 0)   
    goto doublefloatiop;
  LDT(1, f1, processor->fp0);   
  LDT(2, f2, processor->fp1);   
  /* NIL */
  t3 = zero + DoubleFloatOp_Add;   
  t3 = t1 - t3;   
  if (t3 != 0)   
    goto mondo_dispatch30328;
  /* Here if argument DoubleFloatOpAdd */
  ADDT(1, f1, 1, f1, 2, f2); /* addt */   
  goto mondo_dispatch30327;   

mondo_dispatch30328:
  if (_trace) printf("mondo_dispatch30328:\n");
  t3 = zero + DoubleFloatOp_Sub;   
  t3 = t1 - t3;   
  if (t3 != 0)   
    goto mondo_dispatch30329;
  /* Here if argument DoubleFloatOpSub */
  SUBT(1, f1, 1, f1, 2, f2);   
  goto mondo_dispatch30327;   

mondo_dispatch30329:
  if (_trace) printf("mondo_dispatch30329:\n");
  t3 = zero + DoubleFloatOp_Multiply;   
  t3 = t1 - t3;   
  if (t3 != 0)   
    goto mondo_dispatch30330;
  /* Here if argument DoubleFloatOpMultiply */
  MULT(1, f1, 1, f1, 2, f2);   
  goto mondo_dispatch30327;   

mondo_dispatch30330:
  if (_trace) printf("mondo_dispatch30330:\n");
  t3 = zero + DoubleFloatOp_Divide;   
  t3 = t1 - t3;   
  if (t3 != 0)   
    goto mondo_dispatch30331;
  /* Here if argument DoubleFloatOpDivide */
  DIVT(1, f1, 1, f1, 2, f2);   
  goto mondo_dispatch30327;   

mondo_dispatch30331:
  if (_trace) printf("mondo_dispatch30331:\n");

mondo_dispatch30327:
  if (_trace) printf("mondo_dispatch30327:\n");
  /* trapb force the trap to occur here */   		// Force the trap to occur here 
  t3 = *(u64 *)&(processor->niladdress);   		// There was no FP exception 

doublefloatmerge:
  STT( (u64 *)&processor->fp0, 1, f1 );   
  t1 = *(s32 *)&processor->fp0;   
  t2 = *((s32 *)(&processor->fp0)+1);   
  iSP = iSP - 32;   		// Pop all the operands 
  t4 = Type_Fixnum;
		/* Push high result */
  *(u32 *)(iSP + 8) = t2;
		/* write the stack cache */
  *(u32 *)(iSP + 12) = t4;
  iSP = iSP + 8;
  t4 = Type_Fixnum;
		/* Push low result */
  *(u32 *)(iSP + 8) = t1;
		/* write the stack cache */
  *(u32 *)(iSP + 12) = t4;
  iSP = iSP + 8;
  iSP = iSP + 8;
  t4 = t3 << 26;   
  t4 = t4 >> 26;   
  *(u64 *)iSP = t4;   		// Push the exception predicate 
  goto NEXTINSTRUCTION;   

doublefloatexc:
  if (_trace) printf("doublefloatexc:\n");
  t3 = *(u64 *)&(processor->taddress);   		// Indicate an FP exception occurred 
  goto doublefloatmerge;   

doublefloatiop:
  if (_trace) printf("doublefloatiop:\n");
  arg5 = 0;
  arg2 = 85;
  goto illegaloperand;

/* end DoDoubleFloatOp */
  /* End of Halfword operand from stack instruction - DoDoubleFloatOp */
  /* Fin. */



/* End of file automatically generated from ../alpha-emulator/idouble.as */
