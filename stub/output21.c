/************************************************************************
 * WARNING: DO NOT EDIT THIS FILE.  THIS FILE WAS AUTOMATICALLY GENERATED
 * ANY CHANGES MADE TO THIS FILE WILL BE LOST
 *
 * File translated:      ../alpha-emulator/ifunbnum.as
 ************************************************************************/

  /* Bignums. */
/* start DoAddBignumStep */

  /* Halfword operand from stack instruction - DoAddBignumStep */
  /* arg2 has the preloaded 8 bit operand. */

doaddbignumstep:
  if (_trace) printf("doaddbignumstep:\n");

DoAddBignumStepIM:
  if (_trace) printf("DoAddBignumStepIM:\n");
  /* This sequence is lukewarm */
  *(u32 *)&processor->immediate_arg = arg2;
  arg1 = *(u64 *)&(processor->immediate_arg);   
  goto begindoaddbignumstep;   

DoAddBignumStepSP:
  if (_trace) printf("DoAddBignumStepSP:\n");
  arg1 = arg5;		// Assume SP mode 
  if (arg2 == 0)   		// SP-pop mode 
    arg1 = iSP;
  if (arg2 == 0)   		// Adjust SP if SP-pop mode 
    iSP = arg4;

DoAddBignumStepLP:
  if (_trace) printf("DoAddBignumStepLP:\n");

DoAddBignumStepFP:
  if (_trace) printf("DoAddBignumStepFP:\n");

headdoaddbignumstep:
  if (_trace) printf("headdoaddbignumstep:\n");
  arg1 = (arg2 * 8) + arg1;  		// Compute operand address 
  arg1 = *(u64 *)arg1;   		// Get the operand 

begindoaddbignumstep:
  if (_trace) printf("begindoaddbignumstep:\n");
  /* arg1 has the operand, not sign extended if immediate. */
  arg2 = *(s32 *)iSP;   		// Get arg2 
  t2 = *(s32 *)(iSP + 4);   		// and its tag 
  t3 = arg1 >> 32;   
  arg1 = (u32)arg1;   		// Strip type from arg3 
  t4 = t3 - Type_Fixnum;   
  t4 = t4 & 63;		// Strip CDR code 
  if (t4 != 0)   
    goto addbignumsteplose;
  arg3 = *(s32 *)(iSP + -8);   		// Get arg1 
  t1 = *(s32 *)(iSP + -4);   		// and its tag 
  arg2 = (u32)arg2;   		// Clear sign extension from arg2 
  t4 = t2 - Type_Fixnum;   
  t4 = t4 & 63;		// Strip CDR code 
  if (t4 != 0)   
    goto addbignumsteplose;
  arg3 = (u32)arg3;   		// Clear sign extension 
  t4 = t1 - Type_Fixnum;   
  t4 = t4 & 63;		// Strip CDR code 
  if (t4 != 0)   
    goto addbignumsteplose;
  arg4 = arg1 + arg2;
  arg5 = arg3 + arg4;
  arg6 = arg5 >> 32;   		// Shift the carry into arg6 
  iPC = *(u64 *)&(((CACHELINEP)iCP)->nextpcdata);   
  iCP = *(u64 *)&(((CACHELINEP)iCP)->nextcp);   
		/* Store fixnum result */
  *(u32 *)(iSP + -8) = arg5;
		/* write the stack cache */
  *(u32 *)(iSP + -4) = t1;
		/* Store the carry if any */
  *(u32 *)iSP = arg6;
		/* write the stack cache */
  *(u32 *)(iSP + 4) = t1;
  goto cachevalid;   

addbignumsteplose:
  if (_trace) printf("addbignumsteplose:\n");
  arg5 = 0;
  arg2 = 76;
  goto illegaloperand;

/* end DoAddBignumStep */
  /* End of Halfword operand from stack instruction - DoAddBignumStep */
/* start DoSubBignumStep */

  /* Halfword operand from stack instruction - DoSubBignumStep */
  /* arg2 has the preloaded 8 bit operand. */

dosubbignumstep:
  if (_trace) printf("dosubbignumstep:\n");

DoSubBignumStepIM:
  if (_trace) printf("DoSubBignumStepIM:\n");
  /* This sequence is lukewarm */
  *(u32 *)&processor->immediate_arg = arg2;
  arg1 = *(u64 *)&(processor->immediate_arg);   
  goto begindosubbignumstep;   

DoSubBignumStepSP:
  if (_trace) printf("DoSubBignumStepSP:\n");
  arg1 = arg5;		// Assume SP mode 
  if (arg2 == 0)   		// SP-pop mode 
    arg1 = iSP;
  if (arg2 == 0)   		// Adjust SP if SP-pop mode 
    iSP = arg4;

DoSubBignumStepLP:
  if (_trace) printf("DoSubBignumStepLP:\n");

DoSubBignumStepFP:
  if (_trace) printf("DoSubBignumStepFP:\n");

headdosubbignumstep:
  if (_trace) printf("headdosubbignumstep:\n");
  arg1 = (arg2 * 8) + arg1;  		// Compute operand address 
  arg1 = *(u64 *)arg1;   		// Get the operand 

begindosubbignumstep:
  if (_trace) printf("begindosubbignumstep:\n");
  /* arg1 has the operand, not sign extended if immediate. */
  arg2 = *(s32 *)iSP;   		// Get arg2 
  t2 = *(s32 *)(iSP + 4);   		// and its tag 
  t3 = arg1 >> 32;   
  arg1 = (u32)arg1;   		// Strip type from arg3 
  t4 = t3 - Type_Fixnum;   
  t4 = t4 & 63;		// Strip CDR code 
  if (t4 != 0)   
    goto subbignumsteplose;
  arg3 = *(s32 *)(iSP + -8);   		// Get arg1 
  t1 = *(s32 *)(iSP + -4);   		// and its tag 
  arg2 = (u32)arg2;   		// Clear sign extension from arg2 
  t4 = t2 - Type_Fixnum;   
  t4 = t4 & 63;		// Strip CDR code 
  if (t4 != 0)   
    goto subbignumsteplose;
  arg3 = (u32)arg3;   		// Clear sign extension 
  t4 = t1 - Type_Fixnum;   
  t4 = t4 & 63;		// Strip CDR code 
  if (t4 != 0)   
    goto subbignumsteplose;
  arg4 = arg3 - arg2;   		// arg1-arg2 
  arg6 = ((s64)arg4 < (s64)zero) ? 1 : 0;   		// arg6=1 if we borrowed in 1st step 
  arg4 = (u32)arg4;   		// Truncate 1st step to 32-bits 
  arg5 = arg4 - arg1;   		// (arg1-arg2)-arg3 
  t6 = ((s64)arg5 < (s64)zero) ? 1 : 0;   		// t6=1 if we borrowed in 2nd step 
  iPC = *(u64 *)&(((CACHELINEP)iCP)->nextpcdata);   
  iCP = *(u64 *)&(((CACHELINEP)iCP)->nextcp);   
		/* Store fixnum result */
  *(u32 *)(iSP + -8) = arg5;
		/* write the stack cache */
  *(u32 *)(iSP + -4) = t1;
  arg6 = arg6 + t6;		// Compute borrow 
		/* Store the borrow if any */
  *(u32 *)iSP = arg6;
		/* write the stack cache */
  *(u32 *)(iSP + 4) = t1;
  goto cachevalid;   

subbignumsteplose:
  if (_trace) printf("subbignumsteplose:\n");
  arg5 = 0;
  arg2 = 76;
  goto illegaloperand;

/* end DoSubBignumStep */
  /* End of Halfword operand from stack instruction - DoSubBignumStep */
/* start DoMultiplyBignumStep */

  /* Halfword operand from stack instruction - DoMultiplyBignumStep */
  /* arg2 has the preloaded 8 bit operand. */

domultiplybignumstep:
  if (_trace) printf("domultiplybignumstep:\n");

DoMultiplyBignumStepIM:
  if (_trace) printf("DoMultiplyBignumStepIM:\n");
  /* This sequence is lukewarm */
  *(u32 *)&processor->immediate_arg = arg2;
  arg1 = *(u64 *)&(processor->immediate_arg);   
  goto begindomultiplybignumstep;   

DoMultiplyBignumStepSP:
  if (_trace) printf("DoMultiplyBignumStepSP:\n");
  arg1 = arg5;		// Assume SP mode 
  if (arg2 == 0)   		// SP-pop mode 
    arg1 = iSP;
  if (arg2 == 0)   		// Adjust SP if SP-pop mode 
    iSP = arg4;

DoMultiplyBignumStepLP:
  if (_trace) printf("DoMultiplyBignumStepLP:\n");

DoMultiplyBignumStepFP:
  if (_trace) printf("DoMultiplyBignumStepFP:\n");

headdomultiplybignumstep:
  if (_trace) printf("headdomultiplybignumstep:\n");
  arg1 = (arg2 * 8) + arg1;  		// Compute operand address 
  arg1 = *(u64 *)arg1;   		// Get the operand 

begindomultiplybignumstep:
  if (_trace) printf("begindomultiplybignumstep:\n");
  /* arg1 has the operand, not sign extended if immediate. */
  arg2 = *(s32 *)iSP;   		// Get arg1 
  t1 = *(s32 *)(iSP + 4);   
  t2 = arg1 >> 32;   
  arg1 = (u32)arg1;   		// Strip type from arg2 
  t4 = t2 - Type_Fixnum;   
  t4 = t4 & 63;		// Strip CDR code 
  if (t4 != 0)   
    goto multbignumsteplose;
  arg2 = (u32)arg2;   
  t4 = t1 - Type_Fixnum;   
  t4 = t4 & 63;		// Strip CDR code 
  if (t4 != 0)   
    goto multbignumsteplose;
  arg3 = arg2 * arg1;   		// arg1*arg2 
  arg6 = (u32)(arg3 >> ((4&7)*8));   		// arg6=high order word 
  iPC = *(u64 *)&(((CACHELINEP)iCP)->nextpcdata);   
  iCP = *(u64 *)&(((CACHELINEP)iCP)->nextcp);   
		/* Store fixnum result ls word */
  *(u32 *)iSP = arg3;
		/* write the stack cache */
  *(u32 *)(iSP + 4) = t1;
		/* Store ms word */
  *(u32 *)(iSP + 8) = arg6;
		/* write the stack cache */
  *(u32 *)(iSP + 12) = t1;
  iSP = iSP + 8;
  goto cachevalid;   

multbignumsteplose:
  if (_trace) printf("multbignumsteplose:\n");
  arg5 = 0;
  arg2 = 80;
  goto illegaloperand;

/* end DoMultiplyBignumStep */
  /* End of Halfword operand from stack instruction - DoMultiplyBignumStep */
/* start DoDivideBignumStep */

  /* Halfword operand from stack instruction - DoDivideBignumStep */
  /* arg2 has the preloaded 8 bit operand. */

dodividebignumstep:
  if (_trace) printf("dodividebignumstep:\n");

DoDivideBignumStepIM:
  if (_trace) printf("DoDivideBignumStepIM:\n");
  /* This sequence is lukewarm */
  *(u32 *)&processor->immediate_arg = arg2;
  arg1 = *(u64 *)&(processor->immediate_arg);   
  goto begindodividebignumstep;   

DoDivideBignumStepSP:
  if (_trace) printf("DoDivideBignumStepSP:\n");
  arg1 = arg5;		// Assume SP mode 
  if (arg2 == 0)   		// SP-pop mode 
    arg1 = iSP;
  if (arg2 == 0)   		// Adjust SP if SP-pop mode 
    iSP = arg4;

DoDivideBignumStepLP:
  if (_trace) printf("DoDivideBignumStepLP:\n");

DoDivideBignumStepFP:
  if (_trace) printf("DoDivideBignumStepFP:\n");

headdodividebignumstep:
  if (_trace) printf("headdodividebignumstep:\n");
  arg1 = (arg2 * 8) + arg1;  		// Compute operand address 
  arg1 = *(u64 *)arg1;   		// Get the operand 

begindodividebignumstep:
  if (_trace) printf("begindodividebignumstep:\n");
  /* arg1 has the operand, not sign extended if immediate. */
  arg2 = *(s32 *)iSP;   		// Get arg2 
  t1 = *(s32 *)(iSP + 4);   
  t2 = arg1 >> 32;   
  arg1 = (u32)arg1;   
  t4 = t2 - Type_Fixnum;   
  t4 = t4 & 63;		// Strip CDR code 
  if (t4 != 0)   
    goto divbignumsteplose1;
  if (arg1 == 0) 		// J. if division by zero 
    goto divbignumsteplose2;
  arg2 = (u32)arg2;   
  arg3 = *(s32 *)(iSP + -8);   		// Get arg1 
  t3 = *(s32 *)(iSP + -4);   
  t4 = t1 - Type_Fixnum;   
  t4 = t4 & 63;		// Strip CDR code 
  if (t4 != 0)   
    goto divbignumsteplose1;
  arg2 = arg2 << 32;   		// arg2=(ash arg2 32) 
  arg3 = (u32)arg3;   
  t4 = t3 - Type_Fixnum;   
  t4 = t4 & 63;		// Strip CDR code 
  if (t4 != 0)   
    goto divbignumsteplose1;
  arg4 = arg3 | arg2;		// arg1+(ash arg2 32) 
  t1 = arg4 / arg1;   		// t1 is now the quotient 
  t2 = t1 * arg1;   
  t2 = arg4 - t2;   		// t2 is now the remainder 
		/* store quotient (already fixnum) */
  *(u32 *)(iSP + -8) = t1;
		/* store remainder (already fixnum) */
  *(u32 *)iSP = t2;
  goto NEXTINSTRUCTION;   

divbignumsteplose1:
  if (_trace) printf("divbignumsteplose1:\n");
  arg5 = 0;
  arg2 = 76;
  goto illegaloperand;

divbignumsteplose2:
  if (_trace) printf("divbignumsteplose2:\n");
  arg5 = 0;
  arg2 = 2;
  goto illegaloperand;

/* end DoDivideBignumStep */
  /* End of Halfword operand from stack instruction - DoDivideBignumStep */
/* start DoLshcBignumStep */

  /* Halfword operand from stack instruction - DoLshcBignumStep */

dolshcbignumstep:
  if (_trace) printf("dolshcbignumstep:\n");
  /* arg2 has the preloaded 8 bit operand. */

DoLshcBignumStepIM:
  if (_trace) printf("DoLshcBignumStepIM:\n");
  /* This sequence only sucks a moderate amount */
  arg2 = arg2 << 56;   		// sign extend the byte argument. 

force-alignment16669:
  if (_trace) printf("force-alignment16669:\n");
  arg2 = (s64)arg2 >> 56;   		// Rest of sign extension 
  *(u32 *)&processor->immediate_arg = arg2;
  arg1 = *(u64 *)&(processor->immediate_arg);   
  goto begindolshcbignumstep;   

DoLshcBignumStepSP:
  if (_trace) printf("DoLshcBignumStepSP:\n");
  arg1 = arg5;		// Assume SP mode 
  if (arg2 == 0)   		// SP-pop mode 
    arg1 = iSP;
  if (arg2 == 0)   		// Adjust SP if SP-pop mode 
    iSP = arg4;

DoLshcBignumStepLP:
  if (_trace) printf("DoLshcBignumStepLP:\n");

DoLshcBignumStepFP:
  if (_trace) printf("DoLshcBignumStepFP:\n");

headdolshcbignumstep:
  if (_trace) printf("headdolshcbignumstep:\n");
  arg1 = (arg2 * 8) + arg1;  		// Compute operand address 
  arg1 = *(u64 *)arg1;   		// Get the operand 

begindolshcbignumstep:
  if (_trace) printf("begindolshcbignumstep:\n");
  /* arg1 has the operand, sign extended if immediate. */
  arg2 = *(s32 *)iSP;   		// Get arg2 
  t2 = *(s32 *)(iSP + 4);   
  iSP = iSP - 8;   		// Pop Stack 
  t3 = arg1 >> 32;   
  arg1 = (u32)arg1;   		// Strip type from arg3 
  t4 = t3 - Type_Fixnum;   
  t4 = t4 & 63;		// Strip CDR code 
  if (t4 != 0)   
    goto lshcbignumsteplose;
  arg2 = (u32)arg2;   
  arg3 = *(s32 *)iSP;   		// Get arg1 
  t1 = *(s32 *)(iSP + 4);   
  t4 = t2 - Type_Fixnum;   
  t4 = t4 & 63;		// Strip CDR code 
  if (t4 != 0)   
    goto lshcbignumsteplose;
  arg2 = arg2 << 32;   		// arg2=(ash arg2 32) 
  arg3 = (u32)arg3;   
  t4 = t1 - Type_Fixnum;   
  t4 = t4 & 63;		// Strip CDR code 
  if (t4 != 0)   
    goto lshcbignumsteplose;
  arg4 = arg3 | arg2;		// arg1+(ash arg2 32) 
  arg5 = arg4 << (arg1 & 63);   
  arg6 = (s64)arg5 >> 32;   		// Extract the result 
  iPC = *(u64 *)&(((CACHELINEP)iCP)->nextpcdata);   
  iCP = *(u64 *)&(((CACHELINEP)iCP)->nextcp);   
		/* Store the result as a fixnum */
  *(u32 *)iSP = arg6;
		/* write the stack cache */
  *(u32 *)(iSP + 4) = t1;
  goto cachevalid;   

lshcbignumsteplose:
  if (_trace) printf("lshcbignumsteplose:\n");
  arg5 = 0;
  arg2 = 76;
  goto illegaloperand;

/* end DoLshcBignumStep */
  /* End of Halfword operand from stack instruction - DoLshcBignumStep */
  /* Fin. */



/* End of file automatically generated from ../alpha-emulator/ifunbnum.as */
