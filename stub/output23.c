/************************************************************************
 * WARNING: DO NOT EDIT THIS FILE.  THIS FILE WAS AUTOMATICALLY GENERATED
 * ANY CHANGES MADE TO THIS FILE WILL BE LOST
 *
 * File translated:      ../alpha-emulator/ihalt.as
 ************************************************************************/

  /* This file implements the out-of-line parts of the instruction dispatch loop. */
/* start iOutOfLine */


ioutofline:
  if (_trace) printf("ioutofline:\n");

traporsuspendmachine:
  if (_trace) printf("traporsuspendmachine:\n");
  t4 = *(s32 *)&processor->control;
  /* Be sure this is up-to-date */
  *(u64 *)&processor->restartsp = iSP;
  /* Has the spy asked us to stop or trap? */
  r0 = *(u64 *)&(processor->please_stop); /* lock */
  t5 = zero;
  *(u64 *)&processor->please_stop = t5; /* lock */
  t5 = 1;
  if (t5 == 0)
    goto collision;
  *(u64 *)&processor->stop_interpreter = zero;

collision:
  /* t3<0>=1 if we've been asked to stop */
  t3 = CMPBGE(r0, HaltReason_IllInstn);
  if (t3 & 1)
    goto SUSPENDMACHINE;
  /* Here when someone wants the emulator to trap. */
  /* Extract PROCESSORSTATE_PLEASE_TRAP (ivory) */
  r0 = (u32)(r0 >> ((4&7)*8));
  /* Isolate current trap mode */
  t4 = t4 >> 30;
  t3 = (r0 == TrapReason_HighPrioritySequenceBreak) ? 1 : 0;

g9018:
  if (_trace) printf("g9018:\n");
  if (t3 == 0)
    goto g9014;
  /* Here if argument TrapReasonHighPrioritySequenceBreak */
  /* Only interrupts EXTRA-STACK and EMULATOR */
  t4 = ((u64)t4 <= (u64)TrapMode_ExtraStack) ? 1 : 0;
  if (t4 == 0)
    goto continuecurrentinstruction;
  goto highprioritysequencebreak;

g9014:
  if (_trace) printf("g9014:\n");
  t3 = (r0 == TrapReason_LowPrioritySequenceBreak) ? 1 : 0;

g9019:
  if (_trace) printf("g9019:\n");
  if (t3 == 0)
    goto g9015;
  /* Here if argument TrapReasonLowPrioritySequenceBreak */
  /* Only interrupts EMULATOR */
  if (t4 != 0)
    goto continuecurrentinstruction;
  goto lowprioritysequencebreak;

g9015:
  if (_trace) printf("g9015:\n");
  /* Here for all other cases */
  /* Check for preempt-request trap */
  /* Get the preempt-pending bit */
  t5 = *(s32 *)&processor->interruptreg;
  /* Don't take preempt trap unless in emulator mode */
  if (t4 != 0)
    goto continuecurrentinstruction;
  /* Jump if preempt request not pending */
  if ((t5 & 1) == 0)
    goto continuecurrentinstruction;
  goto preemptrequesttrap;

g9013:
  if (_trace) printf("g9013:\n");

SUSPENDMACHINE:
  if (_trace) printf("SUSPENDMACHINE:\n");
  /* Get the reason */
  t1 = (u32)r0;
  goto stopinterp;

ILLEGALINSTRUCTION:
  if (_trace) printf("ILLEGALINSTRUCTION:\n");
  t1 = HaltReason_IllInstn;
  goto stopinterp;

haltmachine:
  if (_trace) printf("haltmachine:\n");
  t1 = HaltReason_Halted;
  goto stopinterp;

fatalstackoverflow:
  if (_trace) printf("fatalstackoverflow:\n");
  t1 = HaltReason_FatalStackOverflow;
  goto stopinterp;

illegaltrapvector:
  if (_trace) printf("illegaltrapvector:\n");
  t1 = HaltReason_IllegalTrapVector;
  goto stopinterp;

stopinterp:
  if (_trace) printf("stopinterp:\n");
  /* Return the halt reason */
  r0 = t1;
  /* Clear the request flag */
  *(u32 *)&processor->please_stop = zero;
  *(u64 *)&processor->cp = iCP;
  *(u64 *)&processor->epc = iPC;
  *(u64 *)&processor->sp = iSP;
  *(u64 *)&processor->fp = iFP;
  *(u64 *)&processor->lp = iLP;
  /* Stop the (emulated) chip */
  *(u64 *)&processor->runningp = zero;
  r9 = *(u64 *)&(processor->asrr9);
  r10 = *(u64 *)&(processor->asrr10);
  r11 = *(u64 *)&(processor->asrr11);
  r12 = *(u64 *)&(processor->asrr12);
  r13 = *(u64 *)&(processor->asrr13);
  r15 = *(u64 *)&(processor->asrr15);
  r26 = *(u64 *)&(processor->asrr26);
  r27 = *(u64 *)&(processor->asrr27);
  r29 = *(u64 *)&(processor->asrr29);
  r30 = *(u64 *)&(processor->asrr30);
  r14 = *(u64 *)&(processor->asrr14);
  goto *ra; /* ret */

/* end iOutOfLine */



/* End of file automatically generated from ../alpha-emulator/ihalt.as */
