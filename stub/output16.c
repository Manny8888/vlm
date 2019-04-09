/************************************************************************
 * WARNING: DO NOT EDIT THIS FILE.  THIS FILE WAS AUTOMATICALLY GENERATED
 * ANY CHANGES MADE TO THIS FILE WILL BE LOST
 *
 * File translated:      ../alpha-emulator/ifunlexi.as
 ************************************************************************/

  /* Lexical variable accessors. */
/* start DoPushLexicalVarN */

  /* Halfword operand from stack instruction - DoPushLexicalVarN */
  /* arg2 has the preloaded 8 bit operand. */

dopushlexicalvarn:
  if (_trace) printf("dopushlexicalvarn:\n");
#ifdef TRACING
#endif

DoPushLexicalVarNSP:
  if (_trace) printf("DoPushLexicalVarNSP:\n");
  arg1 = arg5;		// Assume SP mode 
  if (arg2 == 0)   		// SP-pop mode 
    arg1 = iSP;
  if (arg2 == 0)   		// Adjust SP if SP-pop mode 
    iSP = arg4;
#ifdef TRACING
  goto begindopushlexicalvarn;   
#endif

DoPushLexicalVarNLP:
  if (_trace) printf("DoPushLexicalVarNLP:\n");
#ifdef TRACING
  goto begindopushlexicalvarn;   
#endif

DoPushLexicalVarNFP:
  if (_trace) printf("DoPushLexicalVarNFP:\n");

begindopushlexicalvarn:
  if (_trace) printf("begindopushlexicalvarn:\n");
  /* arg1 has the operand address. */
		/* Compute operand address */
  arg1 = (arg2 * 8) + arg1;
		/* Position the opcode */
  t4 = arg3 >> 10;
  t1 = *(s32 *)arg1;
  t2 = *(s32 *)(arg1 + 4);
  t4 = t4 & 7;		// Get the lexical var number 
  t1 = (u32)t1;   
  /* TagType. */
  t3 = t2 & 63;
  t3 = t3 - Type_List;
  t3 = t3 & ~4L;
  t1 = t1 + t4;		// Compute the address of the lexical variable. 
  if (t3 != 0)   
    goto pushlexvariop;
  arg5 = *(u64 *)&(processor->stackcachebasevma);
		/* Size of the stack cache (words) */
  arg6 = *(s32 *)&processor->scovlimit;
  /* Memory Read Internal */

g30097:
  t6 = t1 + ivory;
  t3 = (t6 * 4);   
  t2 = LDQ_U(t6);   
		/* Stack cache offset */
  t4 = t1 - arg5;
  t7 = *(u64 *)&(processor->dataread_mask);
  t5 = ((u64)t4 < (u64)arg6) ? 1 : 0;   		// In range? 
  t3 = *(s32 *)t3;
  t2 = (u8)(t2 >> ((t6&7)*8));   
  if (t5 != 0)   
    goto g30099;

g30098:
  t6 = zero + 240;   
  t7 = t7 >> (t2 & 63);
  t6 = t6 >> (t2 & 63);
  if (t7 & 1)   
    goto g30101;

g30108:
  iPC = *(u64 *)&(((CACHELINEP)iCP)->nextpcdata);
  iCP = *(u64 *)&(((CACHELINEP)iCP)->nextcp);
  t4 = t2 & 63;		// set CDR-NEXT 
  *(u32 *)(iSP + 8) = t3;
		/* write the stack cache */
  *(u32 *)(iSP + 12) = t4;
  iSP = iSP + 8;
  goto cachevalid;   

pushlexvariop:
  if (_trace) printf("pushlexvariop:\n");
  arg5 = 0;
  arg2 = 82;
  goto illegaloperand;

g30099:
  if (_trace) printf("g30099:\n");
  t5 = *(u64 *)&(processor->stackcachedata);
		/* reconstruct SCA */
  t4 = (t4 * 8) + t5;
  t3 = *(s32 *)t4;
		/* Read from stack cache */
  t2 = *(s32 *)(t4 + 4);
  goto g30098;   

g30101:
  if (_trace) printf("g30101:\n");
  if ((t6 & 1) == 0)   
    goto g30100;
  t1 = (u32)t3;   		// Do the indirect thing 
  goto g30097;   

g30100:
  if (_trace) printf("g30100:\n");
		/* Load the memory action table for cycle */
  t7 = *(u64 *)&(processor->dataread);
  /* TagType. */
  t6 = t2 & 63;		// Discard the CDR code 
		/* stash the VMA for the (likely) trap */
  *(u64 *)&processor->vma = t1;
  t6 = (t6 * 4) + t7;   		// Adjust for a longword load 
		/* Get the memory action */
  t7 = *(s32 *)t6;

g30105:
  if (_trace) printf("g30105:\n");
  t6 = t7 & MemoryActionTransform;
  if (t6 == 0) 
    goto g30104;
  t2 = t2 & ~63L;
  t2 = t2 | Type_ExternalValueCellPointer;
  goto g30108;   
#ifndef MINIMA

g30104:
#endif
#ifdef MINIMA

g30104:
  if (_trace) printf("g30104:\n");
  t6 = t7 & MemoryActionBinding;
  t5 = *(u64 *)&(processor->dbcmask);
  if (t6 == 0) 
    goto g30103;
  t4 = t1 << 1;
  t6 = *(u64 *)&(processor->dbcbase);
  t4 = t4 & t5;		// Hash index 
  t5 = 1;
  t5 = t5 << (ivorymemorydata & 63);
  t4 = (s32)t4 + (s32)t6;
  t4 = (u32)t4;   		// Clear sign-extension 
  t5 = (t4 * 4) + t5;   
		/* Fetch the key */
  t4 = *(s32 *)t5;
		/* Fetch value */
  t3 = *(s32 *)(t5 + 4);
		/* Compare */
  t6 = (s32)t1 - (s32)t4;
  if (t6 != 0)   		// Trap on miss 
    goto g30107;
  t1 = (u32)t3;   		// Extract the pointer, and indirect 
  goto g30097;   		// This is another memory read tailcall. 

g30107:
  if (_trace) printf("g30107:\n");
  goto dbcachemisstrap;
#endif

g30103:
  /* Perform memory action */
  arg1 = t7;
  arg2 = 0;
  goto performmemoryaction;
#ifdef TRACING
#endif

DoPushLexicalVarNIM:
  goto doistageerror;

/* end DoPushLexicalVarN */
  /* End of Halfword operand from stack instruction - DoPushLexicalVarN */
/* start DoPopLexicalVarN */

  /* Halfword operand from stack instruction - DoPopLexicalVarN */
  /* arg2 has the preloaded 8 bit operand. */

dopoplexicalvarn:
  if (_trace) printf("dopoplexicalvarn:\n");
#ifdef TRACING
#endif

DoPopLexicalVarNSP:
  if (_trace) printf("DoPopLexicalVarNSP:\n");
  arg1 = arg5;		// Assume SP mode 
  if (arg2 == 0)   		// SP-pop mode 
    arg1 = iSP;
  if (arg2 == 0)   		// Adjust SP if SP-pop mode 
    iSP = arg4;
#ifdef TRACING
  goto begindopoplexicalvarn;   
#endif

DoPopLexicalVarNLP:
  if (_trace) printf("DoPopLexicalVarNLP:\n");
#ifdef TRACING
  goto begindopoplexicalvarn;   
#endif

DoPopLexicalVarNFP:
  if (_trace) printf("DoPopLexicalVarNFP:\n");

begindopoplexicalvarn:
  if (_trace) printf("begindopoplexicalvarn:\n");
  /* arg1 has the operand address. */
		/* Compute operand address */
  arg1 = (arg2 * 8) + arg1;
		/* Position the opcode */
  t4 = arg3 >> 10;
  t1 = *(s32 *)arg1;
  t2 = *(s32 *)(arg1 + 4);
  t4 = t4 & 7;		// Get the lexical var number 
  t1 = (u32)t1;   
  /* TagType. */
  t3 = t2 & 63;
  t3 = t3 - Type_List;
  t3 = t3 & ~4L;
  t1 = t1 + t4;		// Compute the address of the lexical variable. 
  if (t3 != 0)   
    goto poplexvariop;
  t3 = *(s32 *)iSP;
  t2 = *(s32 *)(iSP + 4);
		/* Pop Stack. */
  iSP = iSP - 8;
  t3 = (u32)t3;   
  arg5 = *(u64 *)&(processor->stackcachebasevma);
		/* Size of the stack cache (words) */
  arg6 = *(s32 *)&processor->scovlimit;
  /* Memory Read Internal */

g30109:
  t8 = t1 + ivory;
  t5 = (t8 * 4);   
  t4 = LDQ_U(t8);   
		/* Stack cache offset */
  t6 = t1 - arg5;
  t9 = *(u64 *)&(processor->datawrite_mask);
  t7 = ((u64)t6 < (u64)arg6) ? 1 : 0;   		// In range? 
  t5 = *(s32 *)t5;
  t4 = (u8)(t4 >> ((t8&7)*8));   
  if (t7 != 0)   
    goto g30111;

g30110:
  t8 = zero + 240;   
  t9 = t9 >> (t4 & 63);
  t8 = t8 >> (t4 & 63);
  if (t9 & 1)   
    goto g30113;

g30119:
  /* Merge cdr-code */
  t5 = t2 & 63;
  t4 = t4 & 192;
  t4 = t4 | t5;
  t6 = t1 + ivory;
  t5 = (t6 * 4);   
  t8 = LDQ_U(t6);   
		/* Stack cache offset */
  t7 = t1 - arg5;
  t9 = ((u64)t7 < (u64)arg6) ? 1 : 0;   		// In range? 
  t7 = (t4 & 0xff) << ((t6&7)*8);   
  t8 = t8 & ~(0xffL << (t6&7)*8);

g30121:
  if (_trace) printf("g30121:\n");
  t8 = t8 | t7;
  STQ_U(t6, t8);   
  *(u32 *)t5 = t3;
  if (t9 != 0)   		// J. if in cache 
    goto g30120;
  goto NEXTINSTRUCTION;   
  goto NEXTINSTRUCTION;   

poplexvariop:
  if (_trace) printf("poplexvariop:\n");
  arg5 = 0;
  arg2 = 17;
  goto illegaloperand;

g30120:
  if (_trace) printf("g30120:\n");
  t6 = *(u64 *)&(processor->stackcachedata);
		/* Stack cache offset */
  t7 = t1 - arg5;
		/* reconstruct SCA */
  t6 = (t7 * 8) + t6;
		/* Store in stack */
  *(u32 *)t6 = t3;
		/* write the stack cache */
  *(u32 *)(t6 + 4) = t4;
  goto NEXTINSTRUCTION;   

g30111:
  if (_trace) printf("g30111:\n");
  t7 = *(u64 *)&(processor->stackcachedata);
		/* reconstruct SCA */
  t6 = (t6 * 8) + t7;
  t5 = *(s32 *)t6;
		/* Read from stack cache */
  t4 = *(s32 *)(t6 + 4);
  goto g30110;   

g30113:
  if (_trace) printf("g30113:\n");
  if ((t8 & 1) == 0)   
    goto g30112;
  t1 = (u32)t5;   		// Do the indirect thing 
  goto g30109;   

g30112:
  if (_trace) printf("g30112:\n");
		/* Load the memory action table for cycle */
  t9 = *(u64 *)&(processor->datawrite);
  /* TagType. */
  t8 = t4 & 63;		// Discard the CDR code 
		/* stash the VMA for the (likely) trap */
  *(u64 *)&processor->vma = t1;
  t8 = (t8 * 4) + t9;   		// Adjust for a longword load 
		/* Get the memory action */
  t9 = *(s32 *)t8;
#ifndef MINIMA

g30116:
#endif
#ifdef MINIMA

g30116:
  if (_trace) printf("g30116:\n");
  t8 = t9 & MemoryActionBinding;
  t7 = *(u64 *)&(processor->dbcmask);
  if (t8 == 0) 
    goto g30115;
  t6 = t1 << 1;
  t8 = *(u64 *)&(processor->dbcbase);
  t6 = t6 & t7;		// Hash index 
  t7 = 1;
  t7 = t7 << (ivorymemorydata & 63);
  t6 = (s32)t6 + (s32)t8;
  t6 = (u32)t6;   		// Clear sign-extension 
  t7 = (t6 * 4) + t7;   
		/* Fetch the key */
  t6 = *(s32 *)t7;
		/* Fetch value */
  t5 = *(s32 *)(t7 + 4);
		/* Compare */
  t8 = (s32)t1 - (s32)t6;
  if (t8 != 0)   		// Trap on miss 
    goto g30118;
  t1 = (u32)t5;   		// Extract the pointer, and indirect 
  goto g30109;   		// This is another memory read tailcall. 

g30118:
  if (_trace) printf("g30118:\n");
  goto dbcachemisstrap;
#endif

g30115:
  /* Perform memory action */
  arg1 = t9;
  arg2 = 1;
  goto performmemoryaction;
#ifdef TRACING
#endif

DoPopLexicalVarNIM:
  goto doistageerror;

/* end DoPopLexicalVarN */
  /* End of Halfword operand from stack instruction - DoPopLexicalVarN */
/* start DoMovemLexicalVarN */

  /* Halfword operand from stack instruction - DoMovemLexicalVarN */
  /* arg2 has the preloaded 8 bit operand. */

domovemlexicalvarn:
  if (_trace) printf("domovemlexicalvarn:\n");
#ifdef TRACING
#endif

DoMovemLexicalVarNSP:
  if (_trace) printf("DoMovemLexicalVarNSP:\n");
  arg1 = arg5;		// Assume SP mode 
  if (arg2 == 0)   		// SP-pop mode 
    arg1 = iSP;
  if (arg2 == 0)   		// Adjust SP if SP-pop mode 
    iSP = arg4;
#ifdef TRACING
  goto begindomovemlexicalvarn;   
#endif

DoMovemLexicalVarNLP:
  if (_trace) printf("DoMovemLexicalVarNLP:\n");
#ifdef TRACING
  goto begindomovemlexicalvarn;   
#endif

DoMovemLexicalVarNFP:
  if (_trace) printf("DoMovemLexicalVarNFP:\n");

begindomovemlexicalvarn:
  if (_trace) printf("begindomovemlexicalvarn:\n");
  /* arg1 has the operand address. */
		/* Compute operand address */
  arg1 = (arg2 * 8) + arg1;
		/* Position the opcode */
  t4 = arg3 >> 10;
  t1 = *(s32 *)arg1;
  t2 = *(s32 *)(arg1 + 4);
  t4 = t4 & 7;		// Get the lexical var number 
  t1 = (u32)t1;   
  /* TagType. */
  t3 = t2 & 63;
  t3 = t3 - Type_List;
  t3 = t3 & ~4L;
  t1 = t1 + t4;		// Compute the address of the lexical variable. 
  if (t3 != 0)   
    goto movemlexvariop;
  t3 = *(s32 *)iSP;
  t2 = *(s32 *)(iSP + 4);
  t3 = (u32)t3;   
  arg5 = *(u64 *)&(processor->stackcachebasevma);
		/* Size of the stack cache (words) */
  arg6 = *(s32 *)&processor->scovlimit;
  /* Memory Read Internal */

g30122:
  t8 = t1 + ivory;
  t5 = (t8 * 4);   
  t4 = LDQ_U(t8);   
		/* Stack cache offset */
  t6 = t1 - arg5;
  t9 = *(u64 *)&(processor->datawrite_mask);
  t7 = ((u64)t6 < (u64)arg6) ? 1 : 0;   		// In range? 
  t5 = *(s32 *)t5;
  t4 = (u8)(t4 >> ((t8&7)*8));   
  if (t7 != 0)   
    goto g30124;

g30123:
  t8 = zero + 240;   
  t9 = t9 >> (t4 & 63);
  t8 = t8 >> (t4 & 63);
  if (t9 & 1)   
    goto g30126;

g30132:
  /* Merge cdr-code */
  t5 = t2 & 63;
  t4 = t4 & 192;
  t4 = t4 | t5;
  t6 = t1 + ivory;
  t5 = (t6 * 4);   
  t8 = LDQ_U(t6);   
		/* Stack cache offset */
  t7 = t1 - arg5;
  t9 = ((u64)t7 < (u64)arg6) ? 1 : 0;   		// In range? 
  t7 = (t4 & 0xff) << ((t6&7)*8);   
  t8 = t8 & ~(0xffL << (t6&7)*8);

g30134:
  if (_trace) printf("g30134:\n");
  t8 = t8 | t7;
  STQ_U(t6, t8);   
  *(u32 *)t5 = t3;
  if (t9 != 0)   		// J. if in cache 
    goto g30133;
  goto NEXTINSTRUCTION;   
  goto NEXTINSTRUCTION;   

movemlexvariop:
  if (_trace) printf("movemlexvariop:\n");
  arg5 = 0;
  arg2 = 17;
  goto illegaloperand;

g30133:
  if (_trace) printf("g30133:\n");
  t6 = *(u64 *)&(processor->stackcachedata);
		/* Stack cache offset */
  t7 = t1 - arg5;
		/* reconstruct SCA */
  t6 = (t7 * 8) + t6;
		/* Store in stack */
  *(u32 *)t6 = t3;
		/* write the stack cache */
  *(u32 *)(t6 + 4) = t4;
  goto NEXTINSTRUCTION;   

g30124:
  if (_trace) printf("g30124:\n");
  t7 = *(u64 *)&(processor->stackcachedata);
		/* reconstruct SCA */
  t6 = (t6 * 8) + t7;
  t5 = *(s32 *)t6;
		/* Read from stack cache */
  t4 = *(s32 *)(t6 + 4);
  goto g30123;   

g30126:
  if (_trace) printf("g30126:\n");
  if ((t8 & 1) == 0)   
    goto g30125;
  t1 = (u32)t5;   		// Do the indirect thing 
  goto g30122;   

g30125:
  if (_trace) printf("g30125:\n");
		/* Load the memory action table for cycle */
  t9 = *(u64 *)&(processor->datawrite);
  /* TagType. */
  t8 = t4 & 63;		// Discard the CDR code 
		/* stash the VMA for the (likely) trap */
  *(u64 *)&processor->vma = t1;
  t8 = (t8 * 4) + t9;   		// Adjust for a longword load 
		/* Get the memory action */
  t9 = *(s32 *)t8;
#ifndef MINIMA

g30129:
#endif
#ifdef MINIMA

g30129:
  if (_trace) printf("g30129:\n");
  t8 = t9 & MemoryActionBinding;
  t7 = *(u64 *)&(processor->dbcmask);
  if (t8 == 0) 
    goto g30128;
  t6 = t1 << 1;
  t8 = *(u64 *)&(processor->dbcbase);
  t6 = t6 & t7;		// Hash index 
  t7 = 1;
  t7 = t7 << (ivorymemorydata & 63);
  t6 = (s32)t6 + (s32)t8;
  t6 = (u32)t6;   		// Clear sign-extension 
  t7 = (t6 * 4) + t7;   
		/* Fetch the key */
  t6 = *(s32 *)t7;
		/* Fetch value */
  t5 = *(s32 *)(t7 + 4);
		/* Compare */
  t8 = (s32)t1 - (s32)t6;
  if (t8 != 0)   		// Trap on miss 
    goto g30131;
  t1 = (u32)t5;   		// Extract the pointer, and indirect 
  goto g30122;   		// This is another memory read tailcall. 

g30131:
  if (_trace) printf("g30131:\n");
  goto dbcachemisstrap;
#endif

g30128:
  /* Perform memory action */
  arg1 = t9;
  arg2 = 1;
  goto performmemoryaction;
#ifdef TRACING
#endif

DoMovemLexicalVarNIM:
  goto doistageerror;

/* end DoMovemLexicalVarN */
  /* End of Halfword operand from stack instruction - DoMovemLexicalVarN */
  /* Fin. */



/* End of file automatically generated from ../alpha-emulator/ifunlexi.as */
