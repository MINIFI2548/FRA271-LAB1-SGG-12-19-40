/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Encoder_reader_simulink.c
 *
 * Code generated for Simulink model 'Encoder_reader_simulink'.
 *
 * Model version                  : 3.15
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Thu Oct 30 00:58:50 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Encoder_reader_simulink.h"
#include "rtwtypes.h"
#include "Encoder_reader_simulink_types.h"
#include "Encoder_reader_simulink_private.h"
#include "stm_timer_ll.h"

/* Named constants for MATLAB Function: '<Root>/WrapAround X1' */
#define Encoder_reader_simul_CALL_EVENT (-1)

/* Block signals (default storage) */
B_Encoder_reader_simulink_T Encoder_reader_simulink_B;

/* Block states (default storage) */
DW_Encoder_reader_simulink_T Encoder_reader_simulink_DW;

/* Real-time model */
static RT_MODEL_Encoder_reader_simul_T Encoder_reader_simulink_M_;
RT_MODEL_Encoder_reader_simul_T *const Encoder_reader_simulink_M =
  &Encoder_reader_simulink_M_;

/* Forward declaration for local functions */
static void EncoderBlockForG4_setupImpl_j2(stm32cube_blocks_EncoderBlock_T *obj);
static void E_EncoderBlockForG4_setupImpl_j(stm32cube_blocks_EncoderBlock_T *obj);
static void Enc_EncoderBlockForG4_setupImpl(stm32cube_blocks_EncoderBlock_T *obj);

/*
 * System initialize for atomic system:
 *    '<Root>/WrapAround X1'
 *    '<Root>/WrapAround X2'
 */
void Encoder_reade_WrapAroundX1_Init(DW_WrapAroundX1_Encoder_reade_T *localDW)
{
  localDW->carry_not_empty = true;
  localDW->preV_not_empty = true;
  localDW->offset_not_empty = true;
  localDW->sfEvent = Encoder_reader_simul_CALL_EVENT;
}

/*
 * Output and update for atomic system:
 *    '<Root>/WrapAround X1'
 *    '<Root>/WrapAround X2'
 */
void Encoder_reader_sim_WrapAroundX1(real_T rtu_input, boolean_T rtu_reset,
  real_T *rty_out, DW_WrapAroundX1_Encoder_reade_T *localDW)
{
  real_T diff;
  localDW->sfEvent = Encoder_reader_simul_CALL_EVENT;
  diff = rtu_input - localDW->preV;
  if (diff > 30720.0) {
    localDW->carry--;
  } else if (diff < -30720.0) {
    localDW->carry++;
  }

  if (rtu_reset) {
    localDW->offset = localDW->carry * 61440.0 + rtu_input;
  }

  localDW->preV = rtu_input;
  *rty_out = (localDW->carry * 61440.0 + rtu_input) - localDW->offset;
}

static void EncoderBlockForG4_setupImpl_j2(stm32cube_blocks_EncoderBlock_T *obj)
{
  uint8_T ChannelInfo;
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/TIM4_Encoder_X4' */
  b.PeripheralPtr = TIM4;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/TIM4_Encoder_X4' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<Root>/TIM4_Encoder_X4' */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/TIM4_Encoder_X4' */
    enableCounter(obj->TimerHandle, false);
  }
}

static void E_EncoderBlockForG4_setupImpl_j(stm32cube_blocks_EncoderBlock_T *obj)
{
  uint8_T ChannelInfo;
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/TIM3_Encoder_X2' */
  b.PeripheralPtr = TIM3;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/TIM3_Encoder_X2' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<Root>/TIM3_Encoder_X2' */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/TIM3_Encoder_X2' */
    enableCounter(obj->TimerHandle, false);
  }
}

static void Enc_EncoderBlockForG4_setupImpl(stm32cube_blocks_EncoderBlock_T *obj)
{
  uint8_T ChannelInfo;
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/TIM1_Encoder_X1' */
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/TIM1_Encoder_X1' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<Root>/TIM1_Encoder_X1' */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/TIM1_Encoder_X1' */
    enableCounter(obj->TimerHandle, false);
  }
}

/* Model step function */
void Encoder_reader_simulink_step(void)
{
  {
    real_T diff;
    real_T lastTime;
    real_T *lastU;
    uint32_T pinReadLoc;
    boolean_T rtb_DigitalPortRead;

    /* MATLABSystem: '<S12>/Digital Port Read' */
    pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

    /* MATLABSystem: '<S12>/Digital Port Read' */
    rtb_DigitalPortRead = ((pinReadLoc & 8192U) != 0U);

    /* MATLABSystem: '<Root>/TIM4_Encoder_X4' */
    resetCounterAccToInput(Encoder_reader_simulink_DW.obj_ni.TimerHandle,
      rtb_DigitalPortRead);
    pinReadLoc = getTimerCounterValueForG4
      (Encoder_reader_simulink_DW.obj_ni.TimerHandle, false, NULL);

    /* MATLAB Function: '<Root>/WrapAround X4' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion2'
     *  MATLABSystem: '<Root>/TIM4_Encoder_X4'
     */
    diff = (real_T)pinReadLoc - Encoder_reader_simulink_DW.preV;
    if (diff > 30720.0) {
      Encoder_reader_simulink_DW.carry--;
    } else if (diff < -30720.0) {
      Encoder_reader_simulink_DW.carry++;
    }

    if (rtb_DigitalPortRead) {
      Encoder_reader_simulink_DW.offset = Encoder_reader_simulink_DW.carry *
        61440.0 + (real_T)pinReadLoc;
    }

    Encoder_reader_simulink_DW.preV = pinReadLoc;
    Encoder_reader_simulink_B.out = (Encoder_reader_simulink_DW.carry * 61440.0
      + (real_T)pinReadLoc) - Encoder_reader_simulink_DW.offset;

    /* End of MATLAB Function: '<Root>/WrapAround X4' */
    /* Gain: '<Root>/X4Revolution2Rad' incorporates:
     *  Gain: '<Root>/X4 Revolution'
     */
    Encoder_reader_simulink_B.X4Revolution2Rad = 0.0001220703125 *
      Encoder_reader_simulink_B.out * 6.2831853071795862;

    /* Derivative: '<Root>/X4 V Rad' */
    diff = Encoder_reader_simulink_M->Timing.t[0];
    if ((Encoder_reader_simulink_DW.TimeStampA >= diff) &&
        (Encoder_reader_simulink_DW.TimeStampB >= diff)) {
      /* Derivative: '<Root>/X4 V Rad' */
      Encoder_reader_simulink_B.X4VRad = 0.0;
    } else {
      lastTime = Encoder_reader_simulink_DW.TimeStampA;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA;
      if (Encoder_reader_simulink_DW.TimeStampA <
          Encoder_reader_simulink_DW.TimeStampB) {
        if (Encoder_reader_simulink_DW.TimeStampB < diff) {
          lastTime = Encoder_reader_simulink_DW.TimeStampB;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA >= diff) {
        lastTime = Encoder_reader_simulink_DW.TimeStampB;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB;
      }

      /* Derivative: '<Root>/X4 V Rad' */
      Encoder_reader_simulink_B.X4VRad =
        (Encoder_reader_simulink_B.X4Revolution2Rad - *lastU) / (diff - lastTime);
    }

    /* End of Derivative: '<Root>/X4 V Rad' */
    /* MATLABSystem: '<Root>/TIM3_Encoder_X2' */
    resetCounterAccToInput(Encoder_reader_simulink_DW.obj_p.TimerHandle,
      rtb_DigitalPortRead);
    pinReadLoc = getTimerCounterValueForG4
      (Encoder_reader_simulink_DW.obj_p.TimerHandle, false, NULL);

    /* MATLAB Function: '<Root>/WrapAround X2' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion1'
     *  MATLABSystem: '<Root>/TIM3_Encoder_X2'
     */
    Encoder_reader_sim_WrapAroundX1((real_T)pinReadLoc, rtb_DigitalPortRead,
      &diff, &Encoder_reader_simulink_DW.sf_WrapAroundX2);

    /* MATLABSystem: '<Root>/TIM1_Encoder_X1' */
    resetCounterAccToInput(Encoder_reader_simulink_DW.obj_l.TimerHandle,
      rtb_DigitalPortRead);
    pinReadLoc = getTimerCounterValueForG4
      (Encoder_reader_simulink_DW.obj_l.TimerHandle, false, NULL);

    /* MATLAB Function: '<Root>/WrapAround X1' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion3'
     *  MATLABSystem: '<Root>/TIM1_Encoder_X1'
     */
    Encoder_reader_sim_WrapAroundX1((real_T)pinReadLoc, rtb_DigitalPortRead,
      &diff, &Encoder_reader_simulink_DW.sf_WrapAroundX1);

    /* MATLABSystem: '<S8>/Digital Port Read' */
    LL_GPIO_ReadInputPort(GPIOA);

    /* MATLABSystem: '<S10>/Digital Port Read' */
    LL_GPIO_ReadInputPort(GPIOA);
  }

  {
    real_T *lastU;

    /* Update for Derivative: '<Root>/X4 V Rad' */
    if (Encoder_reader_simulink_DW.TimeStampA == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampA =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA;
    } else if (Encoder_reader_simulink_DW.TimeStampB == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampB =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB;
    } else if (Encoder_reader_simulink_DW.TimeStampA <
               Encoder_reader_simulink_DW.TimeStampB) {
      Encoder_reader_simulink_DW.TimeStampA =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA;
    } else {
      Encoder_reader_simulink_DW.TimeStampB =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB;
    }

    *lastU = Encoder_reader_simulink_B.X4Revolution2Rad;

    /* End of Update for Derivative: '<Root>/X4 V Rad' */
  }

  {                                    /* Sample time: [0.0001s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
      ((Encoder_reader_simulink_M->Timing.clockTick1) * 0.0001);

    /* Trigger External Mode event */
    errorCode = extmodeEvent(1, extmodeTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Encoder_reader_simulink_M->Timing.t[0] =
    ((time_T)(++Encoder_reader_simulink_M->Timing.clockTick0)) *
    Encoder_reader_simulink_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.0001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.0001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Encoder_reader_simulink_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Encoder_reader_simulink_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Encoder_reader_simulink_M->solverInfo,
                          &Encoder_reader_simulink_M->Timing.simTimeStep);
    rtsiSetTPtr(&Encoder_reader_simulink_M->solverInfo, &rtmGetTPtr
                (Encoder_reader_simulink_M));
    rtsiSetStepSizePtr(&Encoder_reader_simulink_M->solverInfo,
                       &Encoder_reader_simulink_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Encoder_reader_simulink_M->solverInfo,
                          (&rtmGetErrorStatus(Encoder_reader_simulink_M)));
    rtsiSetRTModelPtr(&Encoder_reader_simulink_M->solverInfo,
                      Encoder_reader_simulink_M);
  }

  rtsiSetSimTimeStep(&Encoder_reader_simulink_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&Encoder_reader_simulink_M->solverInfo,
    false);
  rtsiSetIsContModeFrozen(&Encoder_reader_simulink_M->solverInfo, false);
  rtsiSetSolverName(&Encoder_reader_simulink_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Encoder_reader_simulink_M,
             &Encoder_reader_simulink_M->Timing.tArray[0]);
  rtmSetTFinal(Encoder_reader_simulink_M, -1);
  Encoder_reader_simulink_M->Timing.stepSize0 = 0.0001;

  /* External mode info */
  Encoder_reader_simulink_M->Sizes.checksums[0] = (226468774U);
  Encoder_reader_simulink_M->Sizes.checksums[1] = (442291365U);
  Encoder_reader_simulink_M->Sizes.checksums[2] = (2974244235U);
  Encoder_reader_simulink_M->Sizes.checksums[3] = (4198045046U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[10];
    Encoder_reader_simulink_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Encoder_reader_simulink_M->extModeInfo,
      &Encoder_reader_simulink_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Encoder_reader_simulink_M->extModeInfo,
                        Encoder_reader_simulink_M->Sizes.checksums);
    rteiSetTPtr(Encoder_reader_simulink_M->extModeInfo, rtmGetTPtr
                (Encoder_reader_simulink_M));
  }

  /* InitializeConditions for Derivative: '<Root>/X4 V Rad' */
  Encoder_reader_simulink_DW.TimeStampA = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB = (rtInf);

  /* SystemInitialize for MATLAB Function: '<Root>/WrapAround X2' */
  Encoder_reade_WrapAroundX1_Init(&Encoder_reader_simulink_DW.sf_WrapAroundX2);

  /* SystemInitialize for MATLAB Function: '<Root>/WrapAround X1' */
  Encoder_reade_WrapAroundX1_Init(&Encoder_reader_simulink_DW.sf_WrapAroundX1);

  /* Start for MATLABSystem: '<S12>/Digital Port Read' */
  Encoder_reader_simulink_DW.obj.matlabCodegenIsDeleted = false;
  Encoder_reader_simulink_DW.obj.isInitialized = 1;
  Encoder_reader_simulink_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/TIM4_Encoder_X4' */
  Encoder_reader_simulink_DW.obj_ni.matlabCodegenIsDeleted = false;
  Encoder_reader_simulink_DW.obj_ni.isSetupComplete = false;
  Encoder_reader_simulink_DW.obj_ni.isInitialized = 1;
  EncoderBlockForG4_setupImpl_j2(&Encoder_reader_simulink_DW.obj_ni);
  Encoder_reader_simulink_DW.obj_ni.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/TIM3_Encoder_X2' */
  Encoder_reader_simulink_DW.obj_p.matlabCodegenIsDeleted = false;
  Encoder_reader_simulink_DW.obj_p.isSetupComplete = false;
  Encoder_reader_simulink_DW.obj_p.isInitialized = 1;
  E_EncoderBlockForG4_setupImpl_j(&Encoder_reader_simulink_DW.obj_p);
  Encoder_reader_simulink_DW.obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/TIM1_Encoder_X1' */
  Encoder_reader_simulink_DW.obj_l.matlabCodegenIsDeleted = false;
  Encoder_reader_simulink_DW.obj_l.isSetupComplete = false;
  Encoder_reader_simulink_DW.obj_l.isInitialized = 1;
  Enc_EncoderBlockForG4_setupImpl(&Encoder_reader_simulink_DW.obj_l);
  Encoder_reader_simulink_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<S8>/Digital Port Read' */
  Encoder_reader_simulink_DW.obj_n.matlabCodegenIsDeleted = false;
  Encoder_reader_simulink_DW.obj_n.isInitialized = 1;
  Encoder_reader_simulink_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<S10>/Digital Port Read' */
  Encoder_reader_simulink_DW.obj_b.matlabCodegenIsDeleted = false;
  Encoder_reader_simulink_DW.obj_b.isInitialized = 1;
  Encoder_reader_simulink_DW.obj_b.isSetupComplete = true;
}

/* Model terminate function */
void Encoder_reader_simulink_terminate(void)
{
  uint8_T ChannelInfo;

  /* Terminate for MATLABSystem: '<S12>/Digital Port Read' */
  if (!Encoder_reader_simulink_DW.obj.matlabCodegenIsDeleted) {
    Encoder_reader_simulink_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S12>/Digital Port Read' */

  /* Terminate for MATLABSystem: '<Root>/TIM4_Encoder_X4' */
  if (!Encoder_reader_simulink_DW.obj_ni.matlabCodegenIsDeleted) {
    Encoder_reader_simulink_DW.obj_ni.matlabCodegenIsDeleted = true;
    if ((Encoder_reader_simulink_DW.obj_ni.isInitialized == 1) &&
        Encoder_reader_simulink_DW.obj_ni.isSetupComplete) {
      disableCounter(Encoder_reader_simulink_DW.obj_ni.TimerHandle);
      disableTimerInterrupts(Encoder_reader_simulink_DW.obj_ni.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(Encoder_reader_simulink_DW.obj_ni.TimerHandle,
                           ChannelInfo);
      disableTimerChannel2(Encoder_reader_simulink_DW.obj_ni.TimerHandle,
                           ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/TIM4_Encoder_X4' */
  /* Terminate for MATLABSystem: '<Root>/TIM3_Encoder_X2' */
  if (!Encoder_reader_simulink_DW.obj_p.matlabCodegenIsDeleted) {
    Encoder_reader_simulink_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((Encoder_reader_simulink_DW.obj_p.isInitialized == 1) &&
        Encoder_reader_simulink_DW.obj_p.isSetupComplete) {
      disableCounter(Encoder_reader_simulink_DW.obj_p.TimerHandle);
      disableTimerInterrupts(Encoder_reader_simulink_DW.obj_p.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(Encoder_reader_simulink_DW.obj_p.TimerHandle,
                           ChannelInfo);
      disableTimerChannel2(Encoder_reader_simulink_DW.obj_p.TimerHandle,
                           ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/TIM3_Encoder_X2' */

  /* Terminate for MATLABSystem: '<Root>/TIM1_Encoder_X1' */
  if (!Encoder_reader_simulink_DW.obj_l.matlabCodegenIsDeleted) {
    Encoder_reader_simulink_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((Encoder_reader_simulink_DW.obj_l.isInitialized == 1) &&
        Encoder_reader_simulink_DW.obj_l.isSetupComplete) {
      disableCounter(Encoder_reader_simulink_DW.obj_l.TimerHandle);
      disableTimerInterrupts(Encoder_reader_simulink_DW.obj_l.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(Encoder_reader_simulink_DW.obj_l.TimerHandle,
                           ChannelInfo);
      disableTimerChannel2(Encoder_reader_simulink_DW.obj_l.TimerHandle,
                           ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/TIM1_Encoder_X1' */

  /* Terminate for MATLABSystem: '<S8>/Digital Port Read' */
  if (!Encoder_reader_simulink_DW.obj_n.matlabCodegenIsDeleted) {
    Encoder_reader_simulink_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S8>/Digital Port Read' */

  /* Terminate for MATLABSystem: '<S10>/Digital Port Read' */
  if (!Encoder_reader_simulink_DW.obj_b.matlabCodegenIsDeleted) {
    Encoder_reader_simulink_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S10>/Digital Port Read' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
