/************************************************************************
 * WARNING: DO NOT EDIT THIS FILE.  THIS FILE WAS AUTOMATICALLY GENERATED
 * ANY CHANGES MADE TO THIS FILE WILL BE LOST
 *
 * File translated:      ../alpha-emulator/ifunbits.as
 ************************************************************************/

  /* Bits. */
/* start DoLogand */

  /* Halfword operand from stack instruction - DoLogand */
  /* arg2 has the preloaded 8 bit operand. */

dologand:
  if (_trace) printf("dologand:\n");
#ifdef TRACING
#endif

DoLogandSP:
  if (_trace) printf("DoLogandSP:\n");
  arg1 = arg5;		// Assume SP mode 
  if (arg2 == 0)   		// SP-pop mode 
    arg1 = iSP;
  if (arg2 == 0)   		// Adjust SP if SP-pop mode 
    iSP = arg4;
#ifdef TRACING
  goto headdologand;   
#endif

DoLogandLP:
  if (_trace) printf("DoLogandLP:\n");
#ifdef TRACING
  goto headdologand;   
#endif

DoLogandFP:
  if (_trace) printf("DoLogandFP:\n");

headdologand:
  if (_trace) printf("headdologand:\n");
		/* Compute operand address */
  arg1 = (arg2 * 8) + arg1;
		/* Get the operand */
  arg1 = *(u64 *)arg1;

begindologand:
  if (_trace) printf("begindologand:\n");
  /* arg1 has the operand, not sign extended if immediate. */
		/* Get tag from ARG1 */
  t3 = *(s32 *)(iSP + 4);
		/* Grab data for ARG1 */
  t4 = *(s32 *)iSP;
  t1 = (u8)(arg1 >> ((4&7)*8));   		// Get tag from ARG2 
  t6 = t3 - Type_Fixnum;
  t6 = t6 & 63;		// Strip CDR code 
  if (t6 != 0)   
    goto g30135;
  t6 = t1 - Type_Fixnum;
  t6 = t6 & 63;		// Strip CDR code 
  if (t6 != 0)   
    goto g30136;
  /* Here we know that both args are fixnums! */
  t4 = t4 & arg1;		// Do the operation 
  iPC = *(u64 *)&(((CACHELINEP)iCP)->nextpcdata);
  iCP = *(u64 *)&(((CACHELINEP)iCP)->nextcp);
  r31 = r31 | r31;
  t4 = (u32)t4;   		// Strip high bits 
  t1 = Type_Fixnum;
		/* Push result */
  *(u32 *)iSP = t4;
		/* write the stack cache */
  *(u32 *)(iSP + 4) = t1;
  goto cachevalid;   

g30135:
  if (_trace) printf("g30135:\n");
  arg6 = t3;		// arg6 = tag to dispatch on 
  arg3 = 0;		// arg3 = stackp 
  arg1 = 2;		// arg1 = instruction arity 
  arg4 = 1;		// arg4 = arithmeticp 
  goto numericexception;

g30136:
  if (_trace) printf("g30136:\n");
  arg6 = t1;		// arg6 = tag to dispatch on 
  arg3 = 0;		// arg3 = stackp 
  arg1 = 2;		// arg1 = instruction arity 
  arg4 = 1;		// arg4 = arithmeticp 
  goto numericexception;
#ifdef TRACING
  goto DoLogandIM;   
#endif

DoLogandIM:
  if (_trace) printf("DoLogandIM:\n");
		/* Get tag from ARG1 */
  t3 = *(s32 *)(iSP + 4);
  arg2 = arg2 << 56;
		/* Grab data for ARG1 */
  t4 = *(s32 *)iSP;
  arg2 = (s64)arg2 >> 56;
  t6 = t3 - Type_Fixnum;
  t6 = t6 & 63;		// Strip CDR code 
  if (t6 != 0)   
    goto g30137;
  /* Here we know that both args are fixnums! */
  t4 = t4 & arg2;		// Do the operation 
  iPC = *(u64 *)&(((CACHELINEP)iCP)->nextpcdata);
  iCP = *(u64 *)&(((CACHELINEP)iCP)->nextcp);
  r31 = r31 | r31;
  t4 = (u32)t4;   		// Strip high bits 
  t1 = Type_Fixnum;
		/* Push result */
  *(u32 *)iSP = t4;
		/* write the stack cache */
  *(u32 *)(iSP + 4) = t1;
  goto cachevalid;   

g30137:
  if (_trace) printf("g30137:\n");
  arg1 = Type_Fixnum;
  arg2 = (u32)arg2;   
  /* SetTag. */
  t1 = arg1 << 32;
  t1 = arg2 | t1;
  arg6 = t3;		// arg6 = tag to dispatch on 
  arg3 = 0;		// arg3 = stackp 
  arg1 = 2;		// arg1 = instruction arity 
  arg4 = 1;		// arg4 = arithmeticp 
  goto numericexception;

/* end DoLogand */
  /* End of Halfword operand from stack instruction - DoLogand */
/* start DoLogior */

  /* Halfword operand from stack instruction - DoLogior */
  /* arg2 has the preloaded 8 bit operand. */

dologior:
  if (_trace) printf("dologior:\n");
#ifdef TRACING
#endif

DoLogiorSP:
  if (_trace) printf("DoLogiorSP:\n");
  arg1 = arg5;		// Assume SP mode 
  if (arg2 == 0)   		// SP-pop mode 
    arg1 = iSP;
  if (arg2 == 0)   		// Adjust SP if SP-pop mode 
    iSP = arg4;
#ifdef TRACING
  goto headdologior;   
#endif

DoLogiorLP:
  if (_trace) printf("DoLogiorLP:\n");
#ifdef TRACING
  goto headdologior;   
#endif

DoLogiorFP:
  if (_trace) printf("DoLogiorFP:\n");

headdologior:
  if (_trace) printf("headdologior:\n");
		/* Compute operand address */
  arg1 = (arg2 * 8) + arg1;
		/* Get the operand */
  arg1 = *(u64 *)arg1;

begindologior:
  if (_trace) printf("begindologior:\n");
  /* arg1 has the operand, not sign extended if immediate. */
		/* Get tag from ARG1 */
  t3 = *(s32 *)(iSP + 4);
		/* Grab data for ARG1 */
  t4 = *(s32 *)iSP;
  t1 = (u8)(arg1 >> ((4&7)*8));   		// Get tag from ARG2 
  t6 = t3 - Type_Fixnum;
  t6 = t6 & 63;		// Strip CDR code 
  if (t6 != 0)   
    goto g30138;
  t6 = t1 - Type_Fixnum;
  t6 = t6 & 63;		// Strip CDR code 
  if (t6 != 0)   
    goto g30139;
  /* Here we know that both args are fixnums! */
  t4 = t4 | arg1;		// Do the operation 
  iPC = *(u64 *)&(((CACHELINEP)iCP)->nextpcdata);
  iCP = *(u64 *)&(((CACHELINEP)iCP)->nextcp);
  r31 = r31 | r31;
  t4 = (u32)t4;   		// Strip high bits 
  t1 = Type_Fixnum;
		/* Push result */
  *(u32 *)iSP = t4;
		/* write the stack cache */
  *(u32 *)(iSP + 4) = t1;
  goto cachevalid;   

g30138:
  if (_trace) printf("g30138:\n");
  arg6 = t3;		// arg6 = tag to dispatch on 
  arg3 = 0;		// arg3 = stackp 
  arg1 = 2;		// arg1 = instruction arity 
  arg4 = 1;		// arg4 = arithmeticp 
  goto numericexception;

g30139:
  if (_trace) printf("g30139:\n");
  arg6 = t1;		// arg6 = tag to dispatch on 
  arg3 = 0;		// arg3 = stackp 
  arg1 = 2;		// arg1 = instruction arity 
  arg4 = 1;		// arg4 = arithmeticp 
  goto numericexception;
#ifdef TRACING
  goto DoLogiorIM;   
#endif

DoLogiorIM:
  if (_trace) printf("DoLogiorIM:\n");
		/* Get tag from ARG1 */
  t3 = *(s32 *)(iSP + 4);
  arg2 = arg2 << 56;
		/* Grab data for ARG1 */
  t4 = *(s32 *)iSP;
  arg2 = (s64)arg2 >> 56;
  t6 = t3 - Type_Fixnum;
  t6 = t6 & 63;		// Strip CDR code 
  if (t6 != 0)   
    goto g30140;
  /* Here we know that both args are fixnums! */
  t4 = t4 | arg2;		// Do the operation 
  iPC = *(u64 *)&(((CACHELINEP)iCP)->nextpcdata);
  iCP = *(u64 *)&(((CACHELINEP)iCP)->nextcp);
  r31 = r31 | r31;
  t4 = (u32)t4;   		// Strip high bits 
  t1 = Type_Fixnum;
		/* Push result */
  *(u32 *)iSP = t4;
		/* write the stack cache */
  *(u32 *)(iSP + 4) = t1;
  goto cachevalid;   

g30140:
  if (_trace) printf("g30140:\n");
  arg1 = Type_Fixnum;
  arg2 = (u32)arg2;   
  /* SetTag. */
  t1 = arg1 << 32;
  t1 = arg2 | t1;
  arg6 = t3;		// arg6 = tag to dispatch on 
  arg3 = 0;		// arg3 = stackp 
  arg1 = 2;		// arg1 = instruction arity 
  arg4 = 1;		// arg4 = arithmeticp 
  goto numericexception;

/* end DoLogior */
  /* End of Halfword operand from stack instruction - DoLogior */
/* start DoLogxor */

  /* Halfword operand from stack instruction - DoLogxor */
  /* arg2 has the preloaded 8 bit operand. */

dologxor:
  if (_trace) printf("dologxor:\n");
#ifdef TRACING
#endif

DoLogxorSP:
  if (_trace) printf("DoLogxorSP:\n");
  arg1 = arg5;		// Assume SP mode 
  if (arg2 == 0)   		// SP-pop mode 
    arg1 = iSP;
  if (arg2 == 0)   		// Adjust SP if SP-pop mode 
    iSP = arg4;
#ifdef TRACING
  goto headdologxor;   
#endif

DoLogxorLP:
  if (_trace) printf("DoLogxorLP:\n");
#ifdef TRACING
  goto headdologxor;   
#endif

DoLogxorFP:
  if (_trace) printf("DoLogxorFP:\n");

headdologxor:
  if (_trace) printf("headdologxor:\n");
		/* Compute operand address */
  arg1 = (arg2 * 8) + arg1;
		/* Get the operand */
  arg1 = *(u64 *)arg1;

begindologxor:
  if (_trace) printf("begindologxor:\n");
  /* arg1 has the operand, not sign extended if immediate. */
		/* Get tag from ARG1 */
  t3 = *(s32 *)(iSP + 4);
		/* Grab data for ARG1 */
  t4 = *(s32 *)iSP;
  t1 = (u8)(arg1 >> ((4&7)*8));   		// Get tag from ARG2 
  t6 = t3 - Type_Fixnum;
  t6 = t6 & 63;		// Strip CDR code 
  if (t6 != 0)   
    goto g30141;
  t6 = t1 - Type_Fixnum;
  t6 = t6 & 63;		// Strip CDR code 
  if (t6 != 0)   
    goto g30142;
  /* Here we know that both args are fixnums! */
  t4 = t4 ^ arg1;   		// Do the operation 
  iPC = *(u64 *)&(((CACHELINEP)iCP)->nextpcdata);
  iCP = *(u64 *)&(((CACHELINEP)iCP)->nextcp);
  r31 = r31 | r31;
  t4 = (u32)t4;   		// Strip high bits 
  t1 = Type_Fixnum;
		/* Push result */
  *(u32 *)iSP = t4;
		/* write the stack cache */
  *(u32 *)(iSP + 4) = t1;
  goto cachevalid;   

g30141:
  if (_trace) printf("g30141:\n");
  arg6 = t3;		// arg6 = tag to dispatch on 
  arg3 = 0;		// arg3 = stackp 
  arg1 = 2;		// arg1 = instruction arity 
  arg4 = 1;		// arg4 = arithmeticp 
  goto numericexception;

g30142:
  if (_trace) printf("g30142:\n");
  arg6 = t1;		// arg6 = tag to dispatch on 
  arg3 = 0;		// arg3 = stackp 
  arg1 = 2;		// arg1 = instruction arity 
  arg4 = 1;		// arg4 = arithmeticp 
  goto numericexception;
#ifdef TRACING
  goto DoLogxorIM;   
#endif

DoLogxorIM:
  if (_trace) printf("DoLogxorIM:\n");
		/* Get tag from ARG1 */
  t3 = *(s32 *)(iSP + 4);
  arg2 = arg2 << 56;
		/* Grab data for ARG1 */
  t4 = *(s32 *)iSP;
  arg2 = (s64)arg2 >> 56;
  t6 = t3 - Type_Fixnum;
  t6 = t6 & 63;		// Strip CDR code 
  if (t6 != 0)   
    goto g30143;
  /* Here we know that both args are fixnums! */
  t4 = t4 ^ arg2;   		// Do the operation 
  iPC = *(u64 *)&(((CACHELINEP)iCP)->nextpcdata);
  iCP = *(u64 *)&(((CACHELINEP)iCP)->nextcp);
  r31 = r31 | r31;
  t4 = (u32)t4;   		// Strip high bits 
  t1 = Type_Fixnum;
		/* Push result */
  *(u32 *)iSP = t4;
		/* write the stack cache */
  *(u32 *)(iSP + 4) = t1;
  goto cachevalid;   

g30143:
  if (_trace) printf("g30143:\n");
  arg1 = Type_Fixnum;
  arg2 = (u32)arg2;   
  /* SetTag. */
  t1 = arg1 << 32;
  t1 = arg2 | t1;
  arg6 = t3;		// arg6 = tag to dispatch on 
  arg3 = 0;		// arg3 = stackp 
  arg1 = 2;		// arg1 = instruction arity 
  arg4 = 1;		// arg4 = arithmeticp 
  goto numericexception;

/* end DoLogxor */
  /* End of Halfword operand from stack instruction - DoLogxor */
/* start DoAsh */

  /* Halfword operand from stack instruction - DoAsh */

doash:
  if (_trace) printf("doash:\n");
  /* arg2 has the preloaded 8 bit operand. */
#ifdef TRACING
#endif

DoAshIM:
  if (_trace) printf("DoAshIM:\n");
  /* This sequence only sucks a moderate amount */
		/* sign extend the byte argument. */
  arg2 = arg2 << 56;

g30157:
  if (_trace) printf("g30157:\n");
		/* Rest of sign extension */
  arg2 = (s64)arg2 >> 56;
  *(u32 *)&processor->immediate_arg = arg2;
  arg1 = *(u64 *)&(processor->immediate_arg);
  goto begindoash;   
#ifdef TRACING
#endif

DoAshSP:
  if (_trace) printf("DoAshSP:\n");
  arg1 = arg5;		// Assume SP mode 
  if (arg2 == 0)   		// SP-pop mode 
    arg1 = iSP;
  if (arg2 == 0)   		// Adjust SP if SP-pop mode 
    iSP = arg4;
#ifdef TRACING
  goto headdoash;   
#endif

DoAshLP:
  if (_trace) printf("DoAshLP:\n");
#ifdef TRACING
  goto headdoash;   
#endif

DoAshFP:
  if (_trace) printf("DoAshFP:\n");

headdoash:
  if (_trace) printf("headdoash:\n");
		/* Compute operand address */
  arg1 = (arg2 * 8) + arg1;
		/* Get the operand */
  arg1 = *(u64 *)arg1;

begindoash:
  if (_trace) printf("begindoash:\n");
  /* arg1 has the operand, sign extended if immediate. */
		/* Get ARG1. */
  arg4 = *(s32 *)iSP;
  arg3 = *(s32 *)(iSP + 4);
  arg4 = (u32)arg4;   
		/* Get ARG2's tag. */
  arg2 = arg1 >> 32;
  arg1 = (s32)arg1;		// Sign extended the rotation amount. 
  t1 = arg2 & 63;		// Strip off any CDR code bits. 
  t3 = arg3 & 63;		// Strip off any CDR code bits. 
  t2 = (t1 == Type_Fixnum) ? 1 : 0;   

g30156:
  if (_trace) printf("g30156:\n");
  if (t2 == 0) 
    goto g30149;
  /* Here if argument TypeFixnum */
  t4 = (t3 == Type_Fixnum) ? 1 : 0;   

g30153:
  if (_trace) printf("g30153:\n");
  if (t4 == 0) 
    goto g30146;
  /* Here if argument TypeFixnum */
  if (arg4 == 0) 		// B. if ash of zero -- trivial case 
    goto zerash;
  if ((s64)arg1 <= 0)  		// B. if negative ash. 
    goto negash;
  arg4 = (s32)arg4;		// Sign extend ARG1 before shifting. 
  arg5 = arg1 - 32;
  if ((s64)arg5 > 0)   
    goto ashovexc;
		/* Shift Left */
  arg5 = arg4 << (arg1 & 63);
  arg6 = arg4 ^ arg5;   
		/* arg6<0>=1 if overflow, 0 otherwise */
  arg6 = arg6 >> 31;
  /* TagType. */
  arg2 = arg2 & 63;
  if (arg6 != 0)   		// J. if overflow 
    goto ashovexc;
  *(u32 *)iSP = arg5;
		/* write the stack cache */
  *(u32 *)(iSP + 4) = arg2;
  goto NEXTINSTRUCTION;   

negash:
  if (_trace) printf("negash:\n");
  arg1 = zero - arg1;
  arg4 = (s32)arg4;		// Sign extend ARG1 before shifting. 
		/* Shift Right */
  arg5 = (s64)arg4 >> $27(arg1 & 63);
  /* TagType. */
  arg2 = arg2 & 63;
  *(u32 *)iSP = arg5;
		/* write the stack cache */
  *(u32 *)(iSP + 4) = arg2;
  goto NEXTINSTRUCTION;   

zerash:
  if (_trace) printf("zerash:\n");
  arg5 = Type_Fixnum;
  *(u32 *)iSP = arg4;
		/* write the stack cache */
  *(u32 *)(iSP + 4) = arg5;
  goto NEXTINSTRUCTION;   

g30150:
  if (_trace) printf("g30150:\n");

g30149:
  if (_trace) printf("g30149:\n");
  /* Here for all other cases */

g30145:
  if (_trace) printf("g30145:\n");
  arg1 = (u32)arg1;   
  /* SetTag. */
  t2 = arg2 << 32;
  t2 = arg1 | t2;
  arg6 = arg2;		// arg6 = tag to dispatch on 
  arg3 = 0;		// arg3 = stackp 
  arg1 = 2;		// arg1 = instruction arity 
  arg4 = 1;		// arg4 = arithmeticp 
  goto numericexception;
  goto g30147;   

g30146:
  if (_trace) printf("g30146:\n");
  arg1 = (u32)arg1;   
  /* SetTag. */
  t2 = arg2 << 32;
  t2 = arg1 | t2;
  arg6 = arg3;		// arg6 = tag to dispatch on 
  arg3 = 0;		// arg3 = stackp 
  arg1 = 2;		// arg1 = instruction arity 
  arg4 = 1;		// arg4 = arithmeticp 
  goto numericexception;

g30147:
  if (_trace) printf("g30147:\n");

g30148:
  if (_trace) printf("g30148:\n");

ashovexc:
  if (_trace) printf("ashovexc:\n");
  arg1 = (u32)arg1;   
  /* SetTag. */
  t1 = arg2 << 32;
  t1 = arg1 | t1;
  arg6 = arg2;		// arg6 = tag to dispatch on 
  arg3 = 0;		// arg3 = stackp 
  arg1 = 2;		// arg1 = instruction arity 
  arg4 = 1;		// arg4 = arithmeticp 
  goto exception;

/* end DoAsh */
  /* End of Halfword operand from stack instruction - DoAsh */
/* start DoRot */

  /* Halfword operand from stack instruction - DoRot */
  /* arg2 has the preloaded 8 bit operand. */

dorot:
  if (_trace) printf("dorot:\n");
#ifdef TRACING
#endif

DoRotSP:
  if (_trace) printf("DoRotSP:\n");
  arg1 = arg5;		// Assume SP mode 
  if (arg2 != 0)   
    goto begindorot;
		/* SP-pop, Reload TOS */
  arg6 = *(u64 *)arg4;
  arg1 = iSP;		// SP-pop mode 
  iSP = arg4;		// Adjust SP 
#ifdef TRACING
  goto begindorot;   
#endif

DoRotLP:
  if (_trace) printf("DoRotLP:\n");
#ifdef TRACING
  goto begindorot;   
#endif

DoRotFP:
  if (_trace) printf("DoRotFP:\n");

begindorot:
  if (_trace) printf("begindorot:\n");
  /* arg1 has the operand address. */
		/* Compute operand address */
  arg1 = (arg2 * 8) + arg1;

g30159:
  if (_trace) printf("g30159:\n");
  t4 = (u32)(arg6 >> ((4&7)*8));   		// Arg1 on the stack 
  t7 = *(u64 *)&(((CACHELINEP)iCP)->nextpcdata);
  t1 = (u32)arg6;   		// Arg1 on the stack 
		/* Arg2 from operand */
  t5 = *(s32 *)(arg1 + 4);
  t4 = t4 & 63;		// Strip CDR code if any. 
		/* Arg2 from operand */
  t2 = *(s32 *)arg1;
  t4 = t4 - Type_Fixnum;
  t8 = *(u64 *)&(((CACHELINEP)iCP)->nextcp);
  t5 = t5 & 63;		// Strip CDR code if any. 
  if (t4 != 0)   
    goto g30158;
  t2 = (u32)t2;   
  t5 = t5 - Type_Fixnum;

g30160:
  if (_trace) printf("g30160:\n");
  if (t5 != 0)   
    goto g30158;
  t2 = t2 & 31;		// Get low 5 bits of the rotation 
		/* Shift left to get new high bits */
  t3 = t1 << (t2 & 63);
  t6 = (u32)(t3 >> ((4&7)*8));   		// Get new low bits 
  t3 = t3 | t6;		// Glue two parts of shifted operand together 

g30161:
  if (_trace) printf("g30161:\n");
  iPC = t7;
		/* Put the result back on the stack */
  *(u32 *)iSP = t3;
  iCP = t8;
  goto cachevalid;   
#ifdef TRACING
  goto DoRotIM;   
#endif

DoRotIM:
  if (_trace) printf("DoRotIM:\n");
  *(u32 *)&processor->immediate_arg = arg2;
  arg1 = (u64)&processor->immediate_arg;   
  goto g30159;   

g30158:
  if (_trace) printf("g30158:\n");
  arg5 = 0;
  arg2 = 80;
  goto illegaloperand;

/* end DoRot */
  /* End of Halfword operand from stack instruction - DoRot */
/* start DoLsh */

  /* Halfword operand from stack instruction - DoLsh */
  /* arg2 has the preloaded 8 bit operand. */

dolsh:
  if (_trace) printf("dolsh:\n");
#ifdef TRACING
#endif

DoLshSP:
  if (_trace) printf("DoLshSP:\n");
  arg1 = arg5;		// Assume SP mode 
  if (arg2 != 0)   
    goto begindolsh;
		/* SP-pop, Reload TOS */
  arg6 = *(u64 *)arg4;
  arg1 = iSP;		// SP-pop mode 
  iSP = arg4;		// Adjust SP 
#ifdef TRACING
  goto begindolsh;   
#endif

DoLshLP:
  if (_trace) printf("DoLshLP:\n");
#ifdef TRACING
  goto begindolsh;   
#endif

DoLshFP:
  if (_trace) printf("DoLshFP:\n");

begindolsh:
  if (_trace) printf("begindolsh:\n");
  /* arg1 has the operand address. */
		/* Compute operand address */
  arg1 = (arg2 * 8) + arg1;

g30163:
  if (_trace) printf("g30163:\n");
  t4 = (u32)(arg6 >> ((4&7)*8));   		// Arg1 on the stack 
  t7 = *(u64 *)&(((CACHELINEP)iCP)->nextpcdata);
  t1 = (u32)arg6;   		// Arg1 on the stack 
		/* Arg2 from operand */
  t5 = *(s32 *)(arg1 + 4);
  t4 = t4 & 63;		// Strip CDR code if any. 
		/* Arg2 from operand */
  t2 = *(s32 *)arg1;
  t4 = t4 - Type_Fixnum;
  t8 = *(u64 *)&(((CACHELINEP)iCP)->nextcp);
  t5 = t5 & 63;		// Strip CDR code if any. 
  if (t4 != 0)   
    goto g30162;
  t5 = t5 - Type_Fixnum;

g30164:
  if (_trace) printf("g30164:\n");
  if (t5 != 0)   
    goto g30162;
  if ((s64)t2 < 0)   		// B. if negative lsh. 
    goto neglsh;
  t3 = t2 - 32;
  if ((s64)t3 >= 0)   
    goto returnzero;
		/* Shift Left */
  t3 = t1 << (t2 & 63);
  goto lshdone;   

neglsh:
  if (_trace) printf("neglsh:\n");
  t2 = zero - t2;
  t3 = t2 - 32;
  if ((s64)t3 >= 0)   
    goto returnzero;
		/* Shift Right */
  t3 = t1 >> (t2 & 63);
  goto lshdone;   

returnzero:
  if (_trace) printf("returnzero:\n");
  t3 = t3 & ~t3;

lshdone:
  if (_trace) printf("lshdone:\n");

g30165:
  if (_trace) printf("g30165:\n");
  iPC = t7;
		/* Put the result back on the stack */
  *(u32 *)iSP = t3;
  iCP = t8;
  goto cachevalid;   
#ifdef TRACING
  goto DoLshIM;   
#endif

DoLshIM:
  if (_trace) printf("DoLshIM:\n");
		/* sign extend the byte argument. */
  arg2 = arg2 << 56;

g30166:
  if (_trace) printf("g30166:\n");
		/* Rest of sign extension */
  arg2 = (s64)arg2 >> 56;
  *(u32 *)&processor->immediate_arg = arg2;
  arg1 = (u64)&processor->immediate_arg;   
  goto g30163;   

g30162:
  if (_trace) printf("g30162:\n");
  arg5 = 0;
  arg2 = 80;
  goto illegaloperand;

/* end DoLsh */
  /* End of Halfword operand from stack instruction - DoLsh */
/* start Do32BitPlus */

  /* Halfword operand from stack instruction - Do32BitPlus */
  /* arg2 has the preloaded 8 bit operand. */

do32bitplus:
  if (_trace) printf("do32bitplus:\n");
#ifdef TRACING
#endif

Do32BitPlusSP:
  if (_trace) printf("Do32BitPlusSP:\n");
  arg1 = arg5;		// Assume SP mode 
  if (arg2 != 0)   
    goto begindo32bitplus;
		/* SP-pop, Reload TOS */
  arg6 = *(u64 *)arg4;
  arg1 = iSP;		// SP-pop mode 
  iSP = arg4;		// Adjust SP 
#ifdef TRACING
  goto begindo32bitplus;   
#endif

Do32BitPlusLP:
  if (_trace) printf("Do32BitPlusLP:\n");
#ifdef TRACING
  goto begindo32bitplus;   
#endif

Do32BitPlusFP:
  if (_trace) printf("Do32BitPlusFP:\n");

begindo32bitplus:
  if (_trace) printf("begindo32bitplus:\n");
  /* arg1 has the operand address. */
		/* Compute operand address */
  arg1 = (arg2 * 8) + arg1;

g30168:
  if (_trace) printf("g30168:\n");
  t4 = (u32)(arg6 >> ((4&7)*8));   		// Arg1 on the stack 
  t7 = *(u64 *)&(((CACHELINEP)iCP)->nextpcdata);
  t1 = (u32)arg6;   		// Arg1 on the stack 
		/* Arg2 from operand */
  t5 = *(s32 *)(arg1 + 4);
  t4 = t4 & 63;		// Strip CDR code if any. 
		/* Arg2 from operand */
  t2 = *(s32 *)arg1;
  t4 = t4 - Type_Fixnum;
  t8 = *(u64 *)&(((CACHELINEP)iCP)->nextcp);
  t5 = t5 & 63;		// Strip CDR code if any. 
  if (t4 != 0)   
    goto g30167;
  t2 = (u32)t2;   
  t5 = t5 - Type_Fixnum;

g30169:
  if (_trace) printf("g30169:\n");
  if (t5 != 0)   
    goto g30167;
  t3 = t1 + t2;		// Perform the 32 bit Add. 

g30170:
  if (_trace) printf("g30170:\n");
  iPC = t7;
		/* Put the result back on the stack */
  *(u32 *)iSP = t3;
  iCP = t8;
  goto cachevalid;   
#ifdef TRACING
  goto Do32BitPlusIM;   
#endif

Do32BitPlusIM:
  if (_trace) printf("Do32BitPlusIM:\n");
  *(u32 *)&processor->immediate_arg = arg2;
  arg1 = (u64)&processor->immediate_arg;   
  goto g30168;   

g30167:
  if (_trace) printf("g30167:\n");
  arg5 = 0;
  arg2 = 80;
  goto illegaloperand;

/* end Do32BitPlus */
  /* End of Halfword operand from stack instruction - Do32BitPlus */
/* start Do32BitDifference */

  /* Halfword operand from stack instruction - Do32BitDifference */
  /* arg2 has the preloaded 8 bit operand. */

do32bitdifference:
  if (_trace) printf("do32bitdifference:\n");
#ifdef TRACING
#endif

Do32BitDifferenceSP:
  if (_trace) printf("Do32BitDifferenceSP:\n");
  arg1 = arg5;		// Assume SP mode 
  if (arg2 != 0)   
    goto begindo32bitdifference;
		/* SP-pop, Reload TOS */
  arg6 = *(u64 *)arg4;
  arg1 = iSP;		// SP-pop mode 
  iSP = arg4;		// Adjust SP 
#ifdef TRACING
  goto begindo32bitdifference;   
#endif

Do32BitDifferenceLP:
  if (_trace) printf("Do32BitDifferenceLP:\n");
#ifdef TRACING
  goto begindo32bitdifference;   
#endif

Do32BitDifferenceFP:
  if (_trace) printf("Do32BitDifferenceFP:\n");

begindo32bitdifference:
  if (_trace) printf("begindo32bitdifference:\n");
  /* arg1 has the operand address. */
		/* Compute operand address */
  arg1 = (arg2 * 8) + arg1;

g30172:
  if (_trace) printf("g30172:\n");
  t4 = (u32)(arg6 >> ((4&7)*8));   		// Arg1 on the stack 
  t7 = *(u64 *)&(((CACHELINEP)iCP)->nextpcdata);
  t1 = (u32)arg6;   		// Arg1 on the stack 
		/* Arg2 from operand */
  t5 = *(s32 *)(arg1 + 4);
  t4 = t4 & 63;		// Strip CDR code if any. 
		/* Arg2 from operand */
  t2 = *(s32 *)arg1;
  t4 = t4 - Type_Fixnum;
  t8 = *(u64 *)&(((CACHELINEP)iCP)->nextcp);
  t5 = t5 & 63;		// Strip CDR code if any. 
  if (t4 != 0)   
    goto g30171;
  t2 = (u32)t2;   
  t5 = t5 - Type_Fixnum;

g30173:
  if (_trace) printf("g30173:\n");
  if (t5 != 0)   
    goto g30171;
		/* Perform the 32 bit Difference. */
  t3 = t1 - t2;

g30174:
  if (_trace) printf("g30174:\n");
  iPC = t7;
		/* Put the result back on the stack */
  *(u32 *)iSP = t3;
  iCP = t8;
  goto cachevalid;   
#ifdef TRACING
  goto Do32BitDifferenceIM;   
#endif

Do32BitDifferenceIM:
  if (_trace) printf("Do32BitDifferenceIM:\n");
  *(u32 *)&processor->immediate_arg = arg2;
  arg1 = (u64)&processor->immediate_arg;   
  goto g30172;   

g30171:
  if (_trace) printf("g30171:\n");
  arg5 = 0;
  arg2 = 80;
  goto illegaloperand;

/* end Do32BitDifference */
  /* End of Halfword operand from stack instruction - Do32BitDifference */
  /* Fin. */



/* End of file automatically generated from ../alpha-emulator/ifunbits.as */
