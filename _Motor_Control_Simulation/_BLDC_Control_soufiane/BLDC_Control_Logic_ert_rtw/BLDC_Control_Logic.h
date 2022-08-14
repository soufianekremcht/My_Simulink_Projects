/*
 * File: BLDC_Control_Logic.h
 *
 * Code generated for Simulink model 'BLDC_Control_Logic'.
 *
 * Model version                  : 1.21
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Mon Aug  1 21:51:04 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_BLDC_Control_Logic_h_
#define RTW_HEADER_BLDC_Control_Logic_h_
#include <string.h>
#include <stddef.h>
#ifndef BLDC_Control_Logic_COMMON_INCLUDES_
# define BLDC_Control_Logic_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* BLDC_Control_Logic_COMMON_INCLUDES_ */

#include "BLDC_Control_Logic_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S16>/Integrator' */
  real_T Integrator_DSTATE_k;          /* '<S11>/Integrator' */
  int8_T Integrator_PrevResetState;    /* '<S11>/Integrator' */
  boolean_T Initial_FirstOutputTime;   /* '<S11>/Initial' */
} DW_BLDC_Control_Logic_T;

/* Constant parameters (auto storage) */
typedef struct {
  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S1>/Constant1'
   *   '<S1>/Constant10'
   *   '<S1>/Constant11'
   */
  real_T pooled1[6];

  /* Expression: [0 0 1 0 0 1]
   * Referenced by: '<S1>/Constant3'
   */
  real_T Constant3_Value[6];

  /* Pooled Parameter (Expression: [0 1 1 0 0 0])
   * Referenced by:
   *   '<S1>/Constant12'
   *   '<S1>/Constant4'
   */
  real_T pooled2[6];

  /* Pooled Parameter (Expression: [0 1 0 0 1 0])
   * Referenced by:
   *   '<S1>/Constant2'
   *   '<S1>/Constant6'
   */
  real_T pooled3[6];

  /* Pooled Parameter (Expression: [0 0 0 1 1 0])
   * Referenced by:
   *   '<S1>/Constant5'
   *   '<S1>/Constant8'
   */
  real_T pooled4[6];

  /* Pooled Parameter (Expression: [1 0 0 1 0 0])
   * Referenced by:
   *   '<S1>/Constant7'
   *   '<S1>/Constant9'
   */
  real_T pooled5[6];
} ConstP_BLDC_Control_Logic_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T Speed_cmd;                    /* '<Root>/Speed_cmd' */
  real_T Sector[6];                    /* '<Root>/Sector' */
  real_T Speed_;                       /* '<Root>/Speed_' */
} ExtU_BLDC_Control_Logic_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T SwitcingPatterns[6];          /* '<Root>/Switcing Patterns' */
} ExtY_BLDC_Control_Logic_T;

/* Real-time Model Data Structure */
struct tag_RTM_BLDC_Control_Logic_T {
  const char_T * volatile errorStatus;
};

/* Block states (auto storage) */
extern DW_BLDC_Control_Logic_T BLDC_Control_Logic_DW;

/* External inputs (root inport signals with auto storage) */
extern ExtU_BLDC_Control_Logic_T BLDC_Control_Logic_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_BLDC_Control_Logic_T BLDC_Control_Logic_Y;

/* Constant parameters (auto storage) */
extern const ConstP_BLDC_Control_Logic_T BLDC_Control_Logic_ConstP;

/* Model entry point functions */
extern void BLDC_Control_Logic_initialize(void);
extern void BLDC_Control_Logic_step(void);
extern void BLDC_Control_Logic_terminate(void);

/* Real-time Model object */
extern RT_MODEL_BLDC_Control_Logic_T *const BLDC_Control_Logic_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Multiport Switch' : Eliminated due to constant selection input
 * Block '<S4>/Constant10' : Unused code path elimination
 * Block '<S4>/Constant2' : Unused code path elimination
 * Block '<S4>/Constant6' : Unused code path elimination
 * Block '<S14>/Bias1' : Unused code path elimination
 * Block '<S15>/Compare' : Unused code path elimination
 * Block '<S15>/Constant' : Unused code path elimination
 * Block '<S14>/Initial' : Unused code path elimination
 * Block '<S14>/Integrator' : Unused code path elimination
 * Block '<S8>/Constant2' : Unused code path elimination
 * Block '<S8>/Switch' : Unused code path elimination
 * Block '<S9>/Constant2' : Unused code path elimination
 * Block '<S9>/Switch' : Unused code path elimination
 * Block '<S4>/Saturation' : Unused code path elimination
 * Block '<S4>/Sum3' : Unused code path elimination
 * Block '<S4>/Sum4' : Unused code path elimination
 * Block '<S4>/Sum5' : Unused code path elimination
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
 * '<Root>' : 'BLDC_Control_Logic'
 * '<S1>'   : 'BLDC_Control_Logic/Commutation Logic_4'
 * '<S2>'   : 'BLDC_Control_Logic/Controller1'
 * '<S3>'   : 'BLDC_Control_Logic/Commutation Logic_4/PWM Generator'
 * '<S4>'   : 'BLDC_Control_Logic/Commutation Logic_4/PWM Generator/Carrier counter'
 * '<S5>'   : 'BLDC_Control_Logic/Commutation Logic_4/PWM Generator/Compare To Zero'
 * '<S6>'   : 'BLDC_Control_Logic/Commutation Logic_4/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)'
 * '<S7>'   : 'BLDC_Control_Logic/Commutation Logic_4/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1'
 * '<S8>'   : 'BLDC_Control_Logic/Commutation Logic_4/PWM Generator/Carrier counter/Limitation'
 * '<S9>'   : 'BLDC_Control_Logic/Commutation Logic_4/PWM Generator/Carrier counter/Limitation1'
 * '<S10>'  : 'BLDC_Control_Logic/Commutation Logic_4/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)/Continuous'
 * '<S11>'  : 'BLDC_Control_Logic/Commutation Logic_4/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)/Discrete'
 * '<S12>'  : 'BLDC_Control_Logic/Commutation Logic_4/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)/Discrete/Compare To Constant'
 * '<S13>'  : 'BLDC_Control_Logic/Commutation Logic_4/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1/Continuous'
 * '<S14>'  : 'BLDC_Control_Logic/Commutation Logic_4/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1/Discrete'
 * '<S15>'  : 'BLDC_Control_Logic/Commutation Logic_4/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1/Discrete/Compare To Constant'
 * '<S16>'  : 'BLDC_Control_Logic/Controller1/PID Controller1'
 */
#endif                                 /* RTW_HEADER_BLDC_Control_Logic_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
