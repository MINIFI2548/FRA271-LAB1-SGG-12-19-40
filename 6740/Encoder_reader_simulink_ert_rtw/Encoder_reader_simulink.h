/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Encoder_reader_simulink.h
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

#ifndef Encoder_reader_simulink_h_
#define Encoder_reader_simulink_h_
#ifndef Encoder_reader_simulink_COMMON_INCLUDES_
#define Encoder_reader_simulink_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_nonfinite.h"
#include "math.h"
#include "ext_mode.h"
#include "main.h"
#include "mw_stm32_utils.h"
#endif                            /* Encoder_reader_simulink_COMMON_INCLUDES_ */

#include "Encoder_reader_simulink_types.h"
#include "rtGetInf.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block states (default storage) for system '<Root>/WrapAround X1' */
typedef struct {
  real_T carry;                        /* '<Root>/WrapAround X1' */
  real_T preV;                         /* '<Root>/WrapAround X1' */
  real_T offset;                       /* '<Root>/WrapAround X1' */
  int32_T sfEvent;                     /* '<Root>/WrapAround X1' */
  boolean_T doneDoubleBufferReInit;    /* '<Root>/WrapAround X1' */
  boolean_T carry_not_empty;           /* '<Root>/WrapAround X1' */
  boolean_T preV_not_empty;            /* '<Root>/WrapAround X1' */
  boolean_T offset_not_empty;          /* '<Root>/WrapAround X1' */
} DW_WrapAroundX1_Encoder_reade_T;

/* Block signals (default storage) */
typedef struct {
  real_T X4Revolution2Rad;             /* '<Root>/X4Revolution2Rad' */
  real_T X4VRad;                       /* '<Root>/X4 V Rad' */
  real_T out;                          /* '<Root>/WrapAround X4' */
} B_Encoder_reader_simulink_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_DigitalPortR_T obj; /* '<S12>/Digital Port Read' */
  stm32cube_blocks_DigitalPortR_T obj_b;/* '<S10>/Digital Port Read' */
  stm32cube_blocks_DigitalPortR_T obj_n;/* '<S8>/Digital Port Read' */
  stm32cube_blocks_EncoderBlock_T obj_ni;/* '<Root>/TIM4_Encoder_X4' */
  stm32cube_blocks_EncoderBlock_T obj_p;/* '<Root>/TIM3_Encoder_X2' */
  stm32cube_blocks_EncoderBlock_T obj_l;/* '<Root>/TIM1_Encoder_X1' */
  real_T TimeStampA;                   /* '<Root>/X4 V Rad' */
  real_T LastUAtTimeA;                 /* '<Root>/X4 V Rad' */
  real_T TimeStampB;                   /* '<Root>/X4 V Rad' */
  real_T LastUAtTimeB;                 /* '<Root>/X4 V Rad' */
  real_T carry;                        /* '<Root>/WrapAround X4' */
  real_T preV;                         /* '<Root>/WrapAround X4' */
  real_T offset;                       /* '<Root>/WrapAround X4' */
  boolean_T doneDoubleBufferReInit;    /* '<Root>/WrapAround X4' */
  DW_WrapAroundX1_Encoder_reade_T sf_WrapAroundX2;/* '<Root>/WrapAround X2' */
  DW_WrapAroundX1_Encoder_reade_T sf_WrapAroundX1;/* '<Root>/WrapAround X1' */
} DW_Encoder_reader_simulink_T;

/* Real-time Model Data Structure */
struct tag_RTM_Encoder_reader_simuli_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block signals (default storage) */
extern B_Encoder_reader_simulink_T Encoder_reader_simulink_B;

/* Block states (default storage) */
extern DW_Encoder_reader_simulink_T Encoder_reader_simulink_DW;

/* Model entry point functions */
extern void Encoder_reader_simulink_initialize(void);
extern void Encoder_reader_simulink_step(void);
extern void Encoder_reader_simulink_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Encoder_reader_simul_T *const Encoder_reader_simulink_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Gain' : Unused code path elimination
 * Block '<Root>/X1 A Deg' : Unused code path elimination
 * Block '<Root>/X1 A Rad' : Unused code path elimination
 * Block '<Root>/X1 Revolution' : Unused code path elimination
 * Block '<Root>/X1 V Deg' : Unused code path elimination
 * Block '<Root>/X1 V Rad' : Unused code path elimination
 * Block '<Root>/X1Revolution2Deg' : Unused code path elimination
 * Block '<Root>/X1Revolution2Rad' : Unused code path elimination
 * Block '<Root>/X2 A Deg' : Unused code path elimination
 * Block '<Root>/X2 A Rad' : Unused code path elimination
 * Block '<Root>/X2 Revolution' : Unused code path elimination
 * Block '<Root>/X2 V Deg' : Unused code path elimination
 * Block '<Root>/X2 V Rad' : Unused code path elimination
 * Block '<Root>/X2Revolution2Deg' : Unused code path elimination
 * Block '<Root>/X2Revolution2Rad' : Unused code path elimination
 * Block '<Root>/X4 A Deg' : Unused code path elimination
 * Block '<Root>/X4 A Rad' : Unused code path elimination
 * Block '<Root>/X4 V Deg' : Unused code path elimination
 * Block '<Root>/X4Revolution2Deg' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Encoder_reader_simulink'
 * '<S1>'   : 'Encoder_reader_simulink/ENCODER  A'
 * '<S2>'   : 'Encoder_reader_simulink/ENCODER  B'
 * '<S3>'   : 'Encoder_reader_simulink/Homing Switch'
 * '<S4>'   : 'Encoder_reader_simulink/WrapAround X1'
 * '<S5>'   : 'Encoder_reader_simulink/WrapAround X2'
 * '<S6>'   : 'Encoder_reader_simulink/WrapAround X4'
 * '<S7>'   : 'Encoder_reader_simulink/ENCODER  A/ECSoC'
 * '<S8>'   : 'Encoder_reader_simulink/ENCODER  A/ECSoC/ECSimCodegen'
 * '<S9>'   : 'Encoder_reader_simulink/ENCODER  B/ECSoC'
 * '<S10>'  : 'Encoder_reader_simulink/ENCODER  B/ECSoC/ECSimCodegen'
 * '<S11>'  : 'Encoder_reader_simulink/Homing Switch/ECSoC'
 * '<S12>'  : 'Encoder_reader_simulink/Homing Switch/ECSoC/ECSimCodegen'
 */
#endif                                 /* Encoder_reader_simulink_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
