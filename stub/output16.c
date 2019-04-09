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
  /* Assume SP mode */
  arg1 = arg5;
  /* SP-pop mode */
  if (arg2 == 0)
    arg1 = iSP;
  /* Adjust SP if SP-pop mode */
  if (arg2 == 0)
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
  /* Get the lexical var number */
  t4 = t4 & 7;
  t1 = (u32)t1;
  /* TagType. */
  t3 = t2 & 63;
  t3 = t3 - Type_List;
  t3 = t3 & ~4L;
  /* Compute the address of the lexical variable. */
  t1 = t1 + t4;
  if (t3 != 0)
    goto pushlexvariop;
  arg5 = *(u64 *)&(processor->stackcachebasevma);
  /* Size of the stack cache (words) */
  arg6 = *(s32 *)&processor->scovlimit;
  /* Memory Read Internal */

g8428:
  t6 = t1 + ivory;
  t3 = (t6 * 4);
  t2 = LDQ_U(t6);
  /* Stack cache offset */
  t4 = t1 - arg5;
  t7 = *(u64 *)&(processor->dataread_mask);
  /* In range? */
  t5 = ((u64)t4 < (u64)arg6) ? 1 : 0;
  t3 = *(s32 *)t3;
  t2 = (u8)(t2 >> ((t6&7)*8));
  if (t5 != 0)
    goto g8430;

g8429:
  t6 = zero + 240;
  t7 = t7 >> (t2 & 63);
  t6 = t6 >> (t2 & 63);
  if (t7 & 1)
    goto g8432;

g8439:
  iPC = *(u64 *)&(((CACHELINEP)iCP)->nextpcdata);
  iCP = *(u64 *)&(((CACHELINEP)iCP)->nextcp);
  /* set CDR-NEXT */
  t4 = t2 & 63;
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

g8430:
  if (_trace) printf("g8430:\n");
  t5 = *(u64 *)&(processor->stackcachedata);
  /* reconstruct SCA */
  t4 = (t4 * 8) + t5;
  t3 = *(s32 *)t4;
  /* Read from stack cache */
  t2 = *(s32 *)(t4 + 4);
  goto g8429;

g8432:
  if (_trace) printf("g8432:\n");
  if ((t6 & 1) == 0)
    goto g8431;
  /* Do the indirect thing */
  t1 = (u32)t3;
  goto g8428;

g8431:
  if (_trace) printf("g8431:\n");
  /* Load the memory action table for cycle */
  t7 = *(u64 *)&(processor->dataread);
  /* TagType. */
  /* Discard the CDR code */
  t6 = t2 & 63;
  /* stash the VMA for the (likely) trap */
  *(u64 *)&processor->vma = t1;
  /* Adjust for a longword load */
  t6 = (t6 * 4) + t7;
  /* Get the memory action */
  t7 = *(s32 *)t6;

g8436:
  if (_trace) printf("g8436:\n");
  t6 = t7 & MemoryActionTransform;
  if (t6 == 0)
    goto g8435;
  t2 = t2 & ~63L;
  t2 = t2 | Type_ExternalValueCellPointer;
  goto g8439;
#ifndef MINIMA

g8435:
#endif
#ifdef MINIMA

g8435:
  if (_trace) printf("g8435:\n");
  t6 = t7 & MemoryActionBinding;
  t5 = *(u64 *)&(processor->dbcmask);
  if (t6 == 0)
    goto g8434;
  t4 = t1 << 1;
  t6 = *(u64 *)&(processor->dbcbase);
  /* Hash index */
  t4 = t4 & t5;
  t5 = 1;
  t5 = t5 << (ivorymemorydata & 63);
  t4 = (s32)t4 + (s32)t6;
  /* Clear sign-extension */
  t4 = (u32)t4;
  t5 = (t4 * 4) + t5;
  /* Fetch the key */
  t4 = *(s32 *)t5;
  /* Fetch value */
  t3 = *(s32 *)(t5 + 4);
  /* Compare */
  t6 = (s32)t1 - (s32)t4;
  /* Trap on miss */
  if (t6 != 0)
    goto g8438;
  /* Extract the pointer, and indirect */
  t1 = (u32)t3;
  goto g8428;

g8438:
  if (_trace) printf("g8438:\n");
  goto dbcachemisstrap;
#endif

g8434:
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
  /* Assume SP mode */
  arg1 = arg5;
  /* SP-pop mode */
  if (arg2 == 0)
    arg1 = iSP;
  /* Adjust SP if SP-pop mode */
  if (arg2 == 0)
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
  /* Get the lexical var number */
  t4 = t4 & 7;
  t1 = (u32)t1;
  /* TagType. */
  t3 = t2 & 63;
  t3 = t3 - Type_List;
  t3 = t3 & ~4L;
  /* Compute the address of the lexical variable. */
  t1 = t1 + t4;
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

g8440:
  t8 = t1 + ivory;
  t5 = (t8 * 4);
  t4 = LDQ_U(t8);
  /* Stack cache offset */
  t6 = t1 - arg5;
  t9 = *(u64 *)&(processor->datawrite_mask);
  /* In range? */
  t7 = ((u64)t6 < (u64)arg6) ? 1 : 0;
  t5 = *(s32 *)t5;
  t4 = (u8)(t4 >> ((t8&7)*8));
  if (t7 != 0)
    goto g8442;

g8441:
  t8 = zero + 240;
  t9 = t9 >> (t4 & 63);
  t8 = t8 >> (t4 & 63);
  if (t9 & 1)
    goto g8444;

g8450:
  /* Merge cdr-code */
  t5 = t2 & 63;
  t4 = t4 & 192;
  t4 = t4 | t5;
  t6 = t1 + ivory;
  t5 = (t6 * 4);
  t8 = LDQ_U(t6);
  /* Stack cache offset */
  t7 = t1 - arg5;
  /* In range? */
  t9 = ((u64)t7 < (u64)arg6) ? 1 : 0;
  t7 = (t4 & 0xff) << ((t6&7)*8);
  t8 = t8 & ~(0xffL << (t6&7)*8);

g8452:
  if (_trace) printf("g8452:\n");
  t8 = t8 | t7;
  STQ_U(t6, t8);
  *(u32 *)t5 = t3;
  /* J. if in cache */
  if (t9 != 0)
    goto g8451;
  goto NEXTINSTRUCTION;
  goto NEXTINSTRUCTION;

poplexvariop:
  if (_trace) printf("poplexvariop:\n");
  arg5 = 0;
  arg2 = 17;
  goto illegaloperand;

g8451:
  if (_trace) printf("g8451:\n");
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

g8442:
  if (_trace) printf("g8442:\n");
  t7 = *(u64 *)&(processor->stackcachedata);
  /* reconstruct SCA */
  t6 = (t6 * 8) + t7;
  t5 = *(s32 *)t6;
  /* Read from stack cache */
  t4 = *(s32 *)(t6 + 4);
  goto g8441;

g8444:
  if (_trace) printf("g8444:\n");
  if ((t8 & 1) == 0)
    goto g8443;
  /* Do the indirect thing */
  t1 = (u32)t5;
  goto g8440;

g8443:
  if (_trace) printf("g8443:\n");
  /* Load the memory action table for cycle */
  t9 = *(u64 *)&(processor->datawrite);
  /* TagType. */
  /* Discard the CDR code */
  t8 = t4 & 63;
  /* stash the VMA for the (likely) trap */
  *(u64 *)&processor->vma = t1;
  /* Adjust for a longword load */
  t8 = (t8 * 4) + t9;
  /* Get the memory action */
  t9 = *(s32 *)t8;
#ifndef MINIMA

g8447:
#endif
#ifdef MINIMA

g8447:
  if (_trace) printf("g8447:\n");
  t8 = t9 & MemoryActionBinding;
  t7 = *(u64 *)&(processor->dbcmask);
  if (t8 == 0)
    goto g8446;
  t6 = t1 << 1;
  t8 = *(u64 *)&(processor->dbcbase);
  /* Hash index */
  t6 = t6 & t7;
  t7 = 1;
  t7 = t7 << (ivorymemorydata & 63);
  t6 = (s32)t6 + (s32)t8;
  /* Clear sign-extension */
  t6 = (u32)t6;
  t7 = (t6 * 4) + t7;
  /* Fetch the key */
  t6 = *(s32 *)t7;
  /* Fetch value */
  t5 = *(s32 *)(t7 + 4);
  /* Compare */
  t8 = (s32)t1 - (s32)t6;
  /* Trap on miss */
  if (t8 != 0)
    goto g8449;
  /* Extract the pointer, and indirect */
  t1 = (u32)t5;
  goto g8440;

g8449:
  if (_trace) printf("g8449:\n");
  goto dbcachemisstrap;
#endif

g8446:
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
  /* Assume SP mode */
  arg1 = arg5;
  /* SP-pop mode */
  if (arg2 == 0)
    arg1 = iSP;
  /* Adjust SP if SP-pop mode */
  if (arg2 == 0)
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
  /* Get the lexical var number */
  t4 = t4 & 7;
  t1 = (u32)t1;
  /* TagType. */
  t3 = t2 & 63;
  t3 = t3 - Type_List;
  t3 = t3 & ~4L;
  /* Compute the address of the lexical variable. */
  t1 = t1 + t4;
  if (t3 != 0)
    goto movemlexvariop;
  t3 = *(s32 *)iSP;
  t2 = *(s32 *)(iSP + 4);
  t3 = (u32)t3;
  arg5 = *(u64 *)&(processor->stackcachebasevma);
  /* Size of the stack cache (words) */
  arg6 = *(s32 *)&processor->scovlimit;
  /* Memory Read Internal */

g8453:
  t8 = t1 + ivory;
  t5 = (t8 * 4);
  t4 = LDQ_U(t8);
  /* Stack cache offset */
  t6 = t1 - arg5;
  t9 = *(u64 *)&(processor->datawrite_mask);
  /* In range? */
  t7 = ((u64)t6 < (u64)arg6) ? 1 : 0;
  t5 = *(s32 *)t5;
  t4 = (u8)(t4 >> ((t8&7)*8));
  if (t7 != 0)
    goto g8455;

g8454:
  t8 = zero + 240;
  t9 = t9 >> (t4 & 63);
  t8 = t8 >> (t4 & 63);
  if (t9 & 1)
    goto g8457;

g8463:
  /* Merge cdr-code */
  t5 = t2 & 63;
  t4 = t4 & 192;
  t4 = t4 | t5;
  t6 = t1 + ivory;
  t5 = (t6 * 4);
  t8 = LDQ_U(t6);
  /* Stack cache offset */
  t7 = t1 - arg5;
  /* In range? */
  t9 = ((u64)t7 < (u64)arg6) ? 1 : 0;
  t7 = (t4 & 0xff) << ((t6&7)*8);
  t8 = t8 & ~(0xffL << (t6&7)*8);

g8465:
  if (_trace) printf("g8465:\n");
  t8 = t8 | t7;
  STQ_U(t6, t8);
  *(u32 *)t5 = t3;
  /* J. if in cache */
  if (t9 != 0)
    goto g8464;
  goto NEXTINSTRUCTION;
  goto NEXTINSTRUCTION;

movemlexvariop:
  if (_trace) printf("movemlexvariop:\n");
  arg5 = 0;
  arg2 = 17;
  goto illegaloperand;

g8464:
  if (_trace) printf("g8464:\n");
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

g8455:
  if (_trace) printf("g8455:\n");
  t7 = *(u64 *)&(processor->stackcachedata);
  /* reconstruct SCA */
  t6 = (t6 * 8) + t7;
  t5 = *(s32 *)t6;
  /* Read from stack cache */
  t4 = *(s32 *)(t6 + 4);
  goto g8454;

g8457:
  if (_trace) printf("g8457:\n");
  if ((t8 & 1) == 0)
    goto g8456;
  /* Do the indirect thing */
  t1 = (u32)t5;
  goto g8453;

g8456:
  if (_trace) printf("g8456:\n");
  /* Load the memory action table for cycle */
  t9 = *(u64 *)&(processor->datawrite);
  /* TagType. */
  /* Discard the CDR code */
  t8 = t4 & 63;
  /* stash the VMA for the (likely) trap */
  *(u64 *)&processor->vma = t1;
  /* Adjust for a longword load */
  t8 = (t8 * 4) + t9;
  /* Get the memory action */
  t9 = *(s32 *)t8;
#ifndef MINIMA

g8460:
#endif
#ifdef MINIMA

g8460:
  if (_trace) printf("g8460:\n");
  t8 = t9 & MemoryActionBinding;
  t7 = *(u64 *)&(processor->dbcmask);
  if (t8 == 0)
    goto g8459;
  t6 = t1 << 1;
  t8 = *(u64 *)&(processor->dbcbase);
  /* Hash index */
  t6 = t6 & t7;
  t7 = 1;
  t7 = t7 << (ivorymemorydata & 63);
  t6 = (s32)t6 + (s32)t8;
  /* Clear sign-extension */
  t6 = (u32)t6;
  t7 = (t6 * 4) + t7;
  /* Fetch the key */
  t6 = *(s32 *)t7;
  /* Fetch value */
  t5 = *(s32 *)(t7 + 4);
  /* Compare */
  t8 = (s32)t1 - (s32)t6;
  /* Trap on miss */
  if (t8 != 0)
    goto g8462;
  /* Extract the pointer, and indirect */
  t1 = (u32)t5;
  goto g8453;

g8462:
  if (_trace) printf("g8462:\n");
  goto dbcachemisstrap;
#endif

g8459:
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
