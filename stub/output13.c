/************************************************************************
 * WARNING: DO NOT EDIT THIS FILE.  THIS FILE WAS AUTOMATICALLY GENERATED
 * ANY CHANGES MADE TO THIS FILE WILL BE LOST
 *
 * File translated:      ../alpha-emulator/ifunpred.as
 ************************************************************************/

  /* Predicates. */
/* start DoEql */

  /* Halfword operand from stack instruction - DoEql */
  /* arg2 has the preloaded 8 bit operand. */

doeql:
  if (_trace) printf("doeql:\n");
#ifdef TRACING
#endif

DoEqlSP:
  if (_trace) printf("DoEqlSP:\n");
  /* Assume SP mode */
  arg1 = arg5;
  /* SP-pop mode */
  if (arg2 == 0)
    arg1 = iSP;
  /* Adjust SP if SP-pop mode */
  if (arg2 == 0)
    iSP = arg4;
#ifdef TRACING
  goto headdoeql;
#endif

DoEqlLP:
  if (_trace) printf("DoEqlLP:\n");
#ifdef TRACING
  goto headdoeql;
#endif

DoEqlFP:
  if (_trace) printf("DoEqlFP:\n");

headdoeql:
  if (_trace) printf("headdoeql:\n");
  /* Compute operand address */
  arg1 = (arg2 * 8) + arg1;
  /* Get the operand */
  arg1 = *(u64 *)arg1;

begindoeql:
  if (_trace) printf("begindoeql:\n");
  /* arg1 has the operand, not sign extended if immediate. */
  arg6 = arg3 >> 12;
  /* Load arg1 into t3 */
  t3 = *(u64 *)iSP;
  /* Low part of EQ-NOT-EQL mask */
  t4 = zero + -2048;
  t11 = *(u64 *)&(processor->niladdress);
  /* High part of EQ-NOT-EQL mask */
  t4 = t4 + ((1) << 16);
  /* Assume result will be T */
  t12 = *(u64 *)&(processor->taddress);
  t5 = arg1 ^ t3;
  /* Shift left to lose CDRCODE. */
  t5 = t5 << 26;
  /* 1 if no-pop, 0 if pop */
  arg6 = arg6 & 1;
  if (t5 == 0)
    goto eqldone;
  /* They are not EQ, if types different or not numeric return nil */
  /* Get the tag alone */
  t5 = t5 >> 58;
  /* Now assume result will be NIL */
  t12 = t11;
  /* Return NIL if tags different */
  if (t5 != 0)
    goto eqldone;
  /* Get tag, check for numeric */
  t3 = t3 >> 32;
  /* TagType. */
  t3 = t3 & 63;
  /* Type is now a bit mask */
  t4 = t4 >> (t3 & 63);
  /* If funny numeric type, exception */
  if (t4 & 1)
    goto eqlexc;

eqldone:
  if (_trace) printf("eqldone:\n");
  /* Either a stack-push or a stack-write */
  iSP = (arg6 * 8) + iSP;
  iPC = *(u64 *)&(((CACHELINEP)iCP)->nextpcdata);
  iCP = *(u64 *)&(((CACHELINEP)iCP)->nextcp);
  *(u64 *)iSP = t12;
  goto cachevalid;
#ifdef TRACING
  goto DoEqlIM;
#endif

DoEqlIM:
  if (_trace) printf("DoEqlIM:\n");
  arg2 = arg2 << 56;
  /* t4=tag t3=data */
  t4 = *(s32 *)(iSP + 4);
  t3 = *(s32 *)iSP;
  arg6 = arg3 >> 12;
  /* Sign extension of arg2 is complete */
  arg2 = (s64)arg2 >> 56;
  t3 = (u32)t3;
  t11 = *(u64 *)&(processor->niladdress);
  /* TagType. */
  t4 = t4 & 63;
  t12 = *(u64 *)&(processor->taddress);
  arg2 = (s32)t3 - (s32)arg2;
  t4 = t4 ^ Type_Fixnum;
  /* 1 if no-pop, 0 if pop */
  arg6 = arg6 & 1;
  t4 = arg2 | t4;
  /* Either a stack-push or a stack-write */
  iSP = (arg6 * 8) + iSP;
  iPC = *(u64 *)&(((CACHELINEP)iCP)->nextpcdata);
  iCP = *(u64 *)&(((CACHELINEP)iCP)->nextcp);
  if (t4 == 0)
    t11 = t12;
  /* Yes Virginia, this does dual issue with above */
  *(u64 *)iSP = t11;
  goto cachevalid;

eqlexc:
  if (_trace) printf("eqlexc:\n");
  /* arg3 = stackp */
  arg3 = 0;
  /* arg1 = instruction arity */
  arg1 = 2;
  /* arg4 = arithmeticp */
  arg4 = 1;
  goto exception;

/* end DoEql */
  /* End of Halfword operand from stack instruction - DoEql */
/* start DoGreaterp */

  /* Halfword operand from stack instruction - DoGreaterp */
  /* arg2 has the preloaded 8 bit operand. */

dogreaterp:
  if (_trace) printf("dogreaterp:\n");
#ifdef TRACING
#endif

DoGreaterpSP:
  if (_trace) printf("DoGreaterpSP:\n");
  /* Assume SP mode */
  arg1 = arg5;
  if (arg2 != 0)
    goto begindogreaterp;
  /* SP-pop, Reload TOS */
  arg6 = *(u64 *)arg4;
  /* SP-pop mode */
  arg1 = iSP;
  /* Adjust SP */
  iSP = arg4;
#ifdef TRACING
  goto begindogreaterp;
#endif

DoGreaterpLP:
  if (_trace) printf("DoGreaterpLP:\n");
#ifdef TRACING
  goto begindogreaterp;
#endif

DoGreaterpFP:
  if (_trace) printf("DoGreaterpFP:\n");

begindogreaterp:
  if (_trace) printf("begindogreaterp:\n");
  /* arg1 has the operand address. */
  /* Compute operand address */
  arg1 = (arg2 * 8) + arg1;
  t11 = *(u64 *)&(processor->niladdress);
  t7 = arg3 >> 12;
  t12 = *(u64 *)&(processor->taddress);
  /* Get ARG1 tag */
  arg3 = (u32)(arg6 >> ((4&7)*8));
  /* t1 is tag of arg2 */
  t1 = *(s32 *)(arg1 + 4);
  LDS(1, f1, *(u32 *)iSP );
  t7 = t7 & 1;
  arg2 = *(s32 *)arg1;
  arg4 = (s32)arg6;
  LDS(2, f2, *(u32 *)arg1 );
  /* Strip off any CDR code bits. */
  t5 = arg3 & 63;
  /* Strip off any CDR code bits. */
  t4 = t1 & 63;
  t6 = (t5 == Type_Fixnum) ? 1 : 0;

g8151:
  if (_trace) printf("g8151:\n");
  if (t6 == 0)
    goto g8139;
  /* Here if argument TypeFixnum */
  t3 = (t4 == Type_Fixnum) ? 1 : 0;

g8143:
  if (_trace) printf("g8143:\n");
  if (t3 == 0)
    goto g8134;
  /* Here if argument TypeFixnum */
  t2 = arg4 - arg2;
  iPC = *(u64 *)&(((CACHELINEP)iCP)->nextpcdata);
  /* Pop/No-pop */
  iSP = (t7 * 8) + iSP;
  iCP = *(u64 *)&(((CACHELINEP)iCP)->nextcp);
  /* T if the test succeeds */
  if ((s64)t2 > 0)
    t11 = t12;
  *(u64 *)iSP = t11;
  goto cachevalid;

g8140:
  if (_trace) printf("g8140:\n");

g8139:
  if (_trace) printf("g8139:\n");
  t6 = (t5 == Type_SingleFloat) ? 1 : 0;

g8152:
  if (_trace) printf("g8152:\n");
  if (t6 == 0)
    goto g8144;
  /* Here if argument TypeSingleFloat */
  t3 = (t4 == Type_SingleFloat) ? 1 : 0;

g8148:
  if (_trace) printf("g8148:\n");
  if (t3 == 0)
    goto g8134;
  /* Here if argument TypeSingleFloat */

greaterpmmexcfltflt:
  if (_trace) printf("greaterpmmexcfltflt:\n");
  SETFLTT(3,f3, FLTU64(1,f1) <= FLTU64(2,f2) ? 2.0:0);
  /* Force the trap to occur here */
  /* trapb force the trap to occur here */
  iPC = *(u64 *)&(((CACHELINEP)iCP)->nextpcdata);
  iSP = (t7 * 8) + iSP;
  iCP = *(u64 *)&(((CACHELINEP)iCP)->nextcp);
  *(u64 *)iSP = t12;
  if (FLTU64(3, f3) == 0.0)
    goto cachevalid;
  /* Didn't branch, answer is NIL */
  *(u64 *)iSP = t11;
  goto cachevalid;

g8145:
  if (_trace) printf("g8145:\n");

g8144:
  if (_trace) printf("g8144:\n");
  /* Here for all other cases */

g8134:
  if (_trace) printf("g8134:\n");
  goto greaterpmmexc;

g8138:
  if (_trace) printf("g8138:\n");
#ifdef TRACING
  goto DoGreaterpIM;
#endif

DoGreaterpIM:
  if (_trace) printf("DoGreaterpIM:\n");
  t11 = *(u64 *)&(processor->niladdress);
  /* First half of sign extension */
  arg2 = arg2 << 56;
  t12 = *(u64 *)&(processor->taddress);
  t7 = arg3 >> 12;
  arg3 = (u32)(arg6 >> ((4&7)*8));
  arg4 = (s32)arg6;
  /* Second half of sign extension */
  arg2 = (s64)arg2 >> 56;
  t7 = t7 & 1;
  /* Strip off any CDR code bits. */
  t3 = arg3 & 63;
  t4 = (t3 == Type_Fixnum) ? 1 : 0;

g8157:
  if (_trace) printf("g8157:\n");
  if (t4 == 0)
    goto g8154;
  /* Here if argument TypeFixnum */
  t2 = arg4 - arg2;
  iPC = *(u64 *)&(((CACHELINEP)iCP)->nextpcdata);
  iSP = (t7 * 8) + iSP;
  iCP = *(u64 *)&(((CACHELINEP)iCP)->nextcp);
  /* T if the test succeeds */
  if ((s64)t2 > 0)
    t11 = t12;
  *(u64 *)iSP = t11;
  goto cachevalid;

g8154:
  if (_trace) printf("g8154:\n");
  /* Here for all other cases */
  /* arg6 = tag to dispatch on */
  arg6 = arg3;
  /* arg3 = stackp */
  arg3 = 0;
  /* arg1 = instruction arity */
  arg1 = 2;
  /* arg4 = arithmeticp */
  arg4 = 1;
  goto numericexception;

g8153:
  if (_trace) printf("g8153:\n");

/* end DoGreaterp */
  /* End of Halfword operand from stack instruction - DoGreaterp */
/* start DoLogtest */

  /* Halfword operand from stack instruction - DoLogtest */
  /* arg2 has the preloaded 8 bit operand. */

dologtest:
  if (_trace) printf("dologtest:\n");
#ifdef TRACING
#endif

DoLogtestSP:
  if (_trace) printf("DoLogtestSP:\n");
  /* Assume SP mode */
  arg1 = arg5;
  if (arg2 != 0)
    goto begindologtest;
  /* SP-pop, Reload TOS */
  arg6 = *(u64 *)arg4;
  /* SP-pop mode */
  arg1 = iSP;
  /* Adjust SP */
  iSP = arg4;
#ifdef TRACING
  goto begindologtest;
#endif

DoLogtestLP:
  if (_trace) printf("DoLogtestLP:\n");
#ifdef TRACING
  goto begindologtest;
#endif

DoLogtestFP:
  if (_trace) printf("DoLogtestFP:\n");

begindologtest:
  if (_trace) printf("begindologtest:\n");
  /* arg1 has the operand address. */
  /* Compute operand address */
  arg1 = (arg2 * 8) + arg1;
  t11 = *(u64 *)&(processor->niladdress);
  t7 = arg3 >> 12;
  t12 = *(u64 *)&(processor->taddress);
  /* Get ARG1 tag */
  arg3 = (u32)(arg6 >> ((4&7)*8));
  arg2 = *(s32 *)arg1;
  LDS(1, f1, *(u32 *)iSP );
  t7 = t7 & 1;
  /* t1 is tag of arg2 */
  t1 = *(s32 *)(arg1 + 4);
  arg4 = (u32)arg6;
  arg2 = (u32)arg2;
  LDS(2, f2, *(u32 *)arg1 );
  /* Strip off any CDR code bits. */
  t5 = arg3 & 63;
  /* Strip off any CDR code bits. */
  t4 = t1 & 63;
  t6 = (t5 == Type_Fixnum) ? 1 : 0;

g8170:
  if (_trace) printf("g8170:\n");
  if (t6 == 0)
    goto g8163;
  /* Here if argument TypeFixnum */
  t3 = (t4 == Type_Fixnum) ? 1 : 0;

g8167:
  if (_trace) printf("g8167:\n");
  if (t3 == 0)
    goto g8160;
  /* Here if argument TypeFixnum */
  t2 = arg4 & arg2;
  iPC = *(u64 *)&(((CACHELINEP)iCP)->nextpcdata);
  /* Pop/No-pop */
  iSP = (t7 * 8) + iSP;
  iCP = *(u64 *)&(((CACHELINEP)iCP)->nextcp);
  /* T if the test succeeds */
  if (t2)
    t11 = t12;
  *(u64 *)iSP = t11;
  goto cachevalid;

g8164:
  if (_trace) printf("g8164:\n");

g8163:
  if (_trace) printf("g8163:\n");
  /* Here for all other cases */

g8159:
  if (_trace) printf("g8159:\n");
  /* arg6 = tag to dispatch on */
  arg6 = arg3;
  /* arg3 = stackp */
  arg3 = 0;
  /* arg1 = instruction arity */
  arg1 = 2;
  /* arg4 = arithmeticp */
  arg4 = 1;
  goto numericexception;
  goto g8161;

g8160:
  if (_trace) printf("g8160:\n");
  /* arg6 = tag to dispatch on */
  arg6 = t1;
  /* arg3 = stackp */
  arg3 = 0;
  /* arg1 = instruction arity */
  arg1 = 2;
  /* arg4 = arithmeticp */
  arg4 = 1;
  goto numericexception;

g8161:
  if (_trace) printf("g8161:\n");

g8162:
  if (_trace) printf("g8162:\n");
#ifdef TRACING
  goto DoLogtestIM;
#endif

DoLogtestIM:
  if (_trace) printf("DoLogtestIM:\n");
  t11 = *(u64 *)&(processor->niladdress);
  /* First half of sign extension */
  arg2 = arg2 << 56;
  t12 = *(u64 *)&(processor->taddress);
  t7 = arg3 >> 12;
  arg3 = (u32)(arg6 >> ((4&7)*8));
  arg4 = (s32)arg6;
  /* Second half of sign extension */
  arg2 = (s64)arg2 >> 56;
  t7 = t7 & 1;
  /* Strip off any CDR code bits. */
  t3 = arg3 & 63;
  t4 = (t3 == Type_Fixnum) ? 1 : 0;

g8175:
  if (_trace) printf("g8175:\n");
  if (t4 == 0)
    goto g8172;
  /* Here if argument TypeFixnum */
  t2 = arg4 & arg2;
  iPC = *(u64 *)&(((CACHELINEP)iCP)->nextpcdata);
  iSP = (t7 * 8) + iSP;
  iCP = *(u64 *)&(((CACHELINEP)iCP)->nextcp);
  /* T if the test succeeds */
  if (t2)
    t11 = t12;
  *(u64 *)iSP = t11;
  goto cachevalid;

g8172:
  if (_trace) printf("g8172:\n");
  /* Here for all other cases */
  /* arg6 = tag to dispatch on */
  arg6 = arg3;
  /* arg3 = stackp */
  arg3 = 0;
  /* arg1 = instruction arity */
  arg1 = 2;
  /* arg4 = arithmeticp */
  arg4 = 1;
  goto numericexception;

g8171:
  if (_trace) printf("g8171:\n");

/* end DoLogtest */
  /* End of Halfword operand from stack instruction - DoLogtest */
/* start EqualNumberMMExc */


equalnumbermmexc:
  if (_trace) printf("equalnumbermmexc:\n");
  /* Strip off any CDR code bits. */
  t5 = arg3 & 63;
  /* Strip off any CDR code bits. */
  t4 = t1 & 63;
  t6 = (t5 == Type_Fixnum) ? 1 : 0;

g8193:
  if (_trace) printf("g8193:\n");
  if (t6 == 0)
    goto g8181;
  /* Here if argument TypeFixnum */
  t3 = (t4 == Type_SingleFloat) ? 1 : 0;

g8185:
  if (_trace) printf("g8185:\n");
  if (t3 == 0)
    goto g8178;
  /* Here if argument TypeSingleFloat */
  CVTLQ(1, f1, f31, 1, f1);
  CVTQS(1, f1, f31, 1, f1);
  goto equalnumbermmexcfltflt;

g8182:
  if (_trace) printf("g8182:\n");

g8181:
  if (_trace) printf("g8181:\n");
  t6 = (t5 == Type_SingleFloat) ? 1 : 0;

g8194:
  if (_trace) printf("g8194:\n");
  if (t6 == 0)
    goto g8186;
  /* Here if argument TypeSingleFloat */
  t3 = (t4 == Type_Fixnum) ? 1 : 0;

g8190:
  if (_trace) printf("g8190:\n");
  if (t3 == 0)
    goto g8178;
  /* Here if argument TypeFixnum */
  CVTLQ(2, f2, f31, 2, f2);
  CVTQS(2, f2, f31, 2, f2);
  goto equalnumbermmexcfltflt;

g8187:
  if (_trace) printf("g8187:\n");

g8186:
  if (_trace) printf("g8186:\n");
  /* Here for all other cases */

g8177:
  if (_trace) printf("g8177:\n");
  /* arg6 = tag to dispatch on */
  arg6 = arg3;
  /* arg3 = stackp */
  arg3 = 0;
  /* arg1 = instruction arity */
  arg1 = 2;
  /* arg4 = arithmeticp */
  arg4 = 1;
  goto numericexception;
  goto g8179;

g8178:
  if (_trace) printf("g8178:\n");
  /* arg6 = tag to dispatch on */
  arg6 = t1;
  /* arg3 = stackp */
  arg3 = 0;
  /* arg1 = instruction arity */
  arg1 = 2;
  /* arg4 = arithmeticp */
  arg4 = 1;
  goto numericexception;

g8179:
  if (_trace) printf("g8179:\n");

g8180:
  if (_trace) printf("g8180:\n");

/* end EqualNumberMMExc */
/* start LesspMMExc */


lesspmmexc:
  if (_trace) printf("lesspmmexc:\n");
  /* Strip off any CDR code bits. */
  t5 = arg3 & 63;
  /* Strip off any CDR code bits. */
  t4 = t1 & 63;
  t6 = (t5 == Type_Fixnum) ? 1 : 0;

g8212:
  if (_trace) printf("g8212:\n");
  if (t6 == 0)
    goto g8200;
  /* Here if argument TypeFixnum */
  t3 = (t4 == Type_SingleFloat) ? 1 : 0;

g8204:
  if (_trace) printf("g8204:\n");
  if (t3 == 0)
    goto g8197;
  /* Here if argument TypeSingleFloat */
  CVTLQ(1, f1, f31, 1, f1);
  CVTQS(1, f1, f31, 1, f1);
  goto lesspmmexcfltflt;

g8201:
  if (_trace) printf("g8201:\n");

g8200:
  if (_trace) printf("g8200:\n");
  t6 = (t5 == Type_SingleFloat) ? 1 : 0;

g8213:
  if (_trace) printf("g8213:\n");
  if (t6 == 0)
    goto g8205;
  /* Here if argument TypeSingleFloat */
  t3 = (t4 == Type_Fixnum) ? 1 : 0;

g8209:
  if (_trace) printf("g8209:\n");
  if (t3 == 0)
    goto g8197;
  /* Here if argument TypeFixnum */
  CVTLQ(2, f2, f31, 2, f2);
  CVTQS(2, f2, f31, 2, f2);
  goto lesspmmexcfltflt;

g8206:
  if (_trace) printf("g8206:\n");

g8205:
  if (_trace) printf("g8205:\n");
  /* Here for all other cases */

g8196:
  if (_trace) printf("g8196:\n");
  /* arg6 = tag to dispatch on */
  arg6 = arg3;
  /* arg3 = stackp */
  arg3 = 0;
  /* arg1 = instruction arity */
  arg1 = 2;
  /* arg4 = arithmeticp */
  arg4 = 1;
  goto numericexception;
  goto g8198;

g8197:
  if (_trace) printf("g8197:\n");
  /* arg6 = tag to dispatch on */
  arg6 = t1;
  /* arg3 = stackp */
  arg3 = 0;
  /* arg1 = instruction arity */
  arg1 = 2;
  /* arg4 = arithmeticp */
  arg4 = 1;
  goto numericexception;

g8198:
  if (_trace) printf("g8198:\n");

g8199:
  if (_trace) printf("g8199:\n");

/* end LesspMMExc */
/* start GreaterpMMExc */


greaterpmmexc:
  if (_trace) printf("greaterpmmexc:\n");
  /* Strip off any CDR code bits. */
  t5 = arg3 & 63;
  /* Strip off any CDR code bits. */
  t4 = t1 & 63;
  t6 = (t5 == Type_Fixnum) ? 1 : 0;

g8231:
  if (_trace) printf("g8231:\n");
  if (t6 == 0)
    goto g8219;
  /* Here if argument TypeFixnum */
  t3 = (t4 == Type_SingleFloat) ? 1 : 0;

g8223:
  if (_trace) printf("g8223:\n");
  if (t3 == 0)
    goto g8216;
  /* Here if argument TypeSingleFloat */
  CVTLQ(1, f1, f31, 1, f1);
  CVTQS(1, f1, f31, 1, f1);
  goto greaterpmmexcfltflt;

g8220:
  if (_trace) printf("g8220:\n");

g8219:
  if (_trace) printf("g8219:\n");
  t6 = (t5 == Type_SingleFloat) ? 1 : 0;

g8232:
  if (_trace) printf("g8232:\n");
  if (t6 == 0)
    goto g8224;
  /* Here if argument TypeSingleFloat */
  t3 = (t4 == Type_Fixnum) ? 1 : 0;

g8228:
  if (_trace) printf("g8228:\n");
  if (t3 == 0)
    goto g8216;
  /* Here if argument TypeFixnum */
  CVTLQ(2, f2, f31, 2, f2);
  CVTQS(2, f2, f31, 2, f2);
  goto greaterpmmexcfltflt;

g8225:
  if (_trace) printf("g8225:\n");

g8224:
  if (_trace) printf("g8224:\n");
  /* Here for all other cases */

g8215:
  if (_trace) printf("g8215:\n");
  /* arg6 = tag to dispatch on */
  arg6 = arg3;
  /* arg3 = stackp */
  arg3 = 0;
  /* arg1 = instruction arity */
  arg1 = 2;
  /* arg4 = arithmeticp */
  arg4 = 1;
  goto numericexception;
  goto g8217;

g8216:
  if (_trace) printf("g8216:\n");
  /* arg6 = tag to dispatch on */
  arg6 = t1;
  /* arg3 = stackp */
  arg3 = 0;
  /* arg1 = instruction arity */
  arg1 = 2;
  /* arg4 = arithmeticp */
  arg4 = 1;
  goto numericexception;

g8217:
  if (_trace) printf("g8217:\n");

g8218:
  if (_trace) printf("g8218:\n");

/* end GreaterpMMExc */
  /* Fin. */



/* End of file automatically generated from ../alpha-emulator/ifunpred.as */
