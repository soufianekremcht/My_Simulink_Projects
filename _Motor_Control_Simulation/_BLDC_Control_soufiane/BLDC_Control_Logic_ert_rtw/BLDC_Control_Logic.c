/*
 * File: BLDC_Control_Logic.c
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

#include "BLDC_Control_Logic.h"
#include "BLDC_Control_Logic_private.h"

/* Block states (auto storage) */
DW_BLDC_Control_Logic_T BLDC_Control_Logic_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_BLDC_Control_Logic_T BLDC_Control_Logic_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_BLDC_Control_Logic_T BLDC_Control_Logic_Y;

/* Real-time model */
RT_MODEL_BLDC_Control_Logic_T BLDC_Control_Logic_M_;
RT_MODEL_BLDC_Control_Logic_T *const BLDC_Control_Logic_M =
  &BLDC_Control_Logic_M_;

/* Model step function */
void BLDC_Control_Logic_step(void)
{
  real_T rtb_Sum2;
  real_T rtb_DataTypeConversion2;
  boolean_T rtb_Compare_d;
  real_T rtb_SwitchingPatterns[6];
  real_T Initial;
  int32_T i;

  /* Sum: '<Root>/Sum2' incorporates:
   *  Inport: '<Root>/Speed_'
   *  Inport: '<Root>/Speed_cmd'
   */
  rtb_Sum2 = BLDC_Control_Logic_U.Speed_cmd - BLDC_Control_Logic_U.Speed_;

  /* Sum: '<S16>/Sum' incorporates:
   *  DiscreteIntegrator: '<S16>/Integrator'
   *  Gain: '<S16>/Proportional Gain'
   */
  rtb_DataTypeConversion2 = 0.01 * rtb_Sum2 +
    BLDC_Control_Logic_DW.Integrator_DSTATE;

  /* RelationalOperator: '<S12>/Compare' incorporates:
   *  Constant: '<S12>/Constant'
   */
  rtb_Compare_d = (BLDC_Control_Logic_DW.Integrator_DSTATE_k >= 0.001);

  /* InitialCondition: '<S11>/Initial' incorporates:
   *  Bias: '<S11>/Bias1'
   */
  if (BLDC_Control_Logic_DW.Initial_FirstOutputTime) {
    BLDC_Control_Logic_DW.Initial_FirstOutputTime = false;
    Initial = 0.0;
  } else {
    Initial = BLDC_Control_Logic_DW.Integrator_DSTATE_k + -0.001;
  }

  /* End of InitialCondition: '<S11>/Initial' */

  /* DiscreteIntegrator: '<S11>/Integrator' */
  if (rtb_Compare_d && (BLDC_Control_Logic_DW.Integrator_PrevResetState <= 0)) {
    BLDC_Control_Logic_DW.Integrator_DSTATE_k = Initial;
  }

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S5>/Constant'
   *  DiscreteIntegrator: '<S11>/Integrator'
   *  Gain: '<S4>/Gain1'
   *  Gain: '<S4>/Gain2'
   *  Logic: '<S3>/Logical Operator'
   *  RelationalOperator: '<S3>/Relational Operator'
   *  RelationalOperator: '<S5>/Compare'
   */
  if ((rtb_DataTypeConversion2 != 0.0) && (rtb_DataTypeConversion2 >=
       1.0101010101010102 * BLDC_Control_Logic_DW.Integrator_DSTATE_k * 1000.0))
  {
    /* MultiPortSwitch: '<S1>/Multiport Switch' incorporates:
     *  Constant: '<S1>/Constant1'
     *  Constant: '<S1>/Constant3'
     *  Constant: '<S1>/Constant4'
     *  Constant: '<S1>/Constant5'
     *  Constant: '<S1>/Constant6'
     *  Constant: '<S1>/Constant7'
     *  Inport: '<Root>/Sector'
     */
    for (i = 0; i < 6; i++) {
      switch ((int32_T)BLDC_Control_Logic_U.Sector[i]) {
       case 0:
        rtb_SwitchingPatterns[i] = BLDC_Control_Logic_ConstP.pooled1[i];
        break;

       case 1:
        rtb_SwitchingPatterns[i] = BLDC_Control_Logic_ConstP.Constant3_Value[i];
        break;

       case 2:
        rtb_SwitchingPatterns[i] = BLDC_Control_Logic_ConstP.pooled2[i];
        break;

       case 3:
        rtb_SwitchingPatterns[i] = BLDC_Control_Logic_ConstP.pooled3[i];
        break;

       case 4:
        rtb_SwitchingPatterns[i] = BLDC_Control_Logic_ConstP.pooled4[i];
        break;

       default:
        rtb_SwitchingPatterns[i] = BLDC_Control_Logic_ConstP.pooled5[i];
        break;
      }
    }

    /* End of MultiPortSwitch: '<S1>/Multiport Switch' */
  } else {
    /* MultiPortSwitch: '<S1>/Multiport Switch1' incorporates:
     *  Constant: '<S1>/Constant10'
     *  Constant: '<S1>/Constant11'
     *  Constant: '<S1>/Constant12'
     *  Constant: '<S1>/Constant2'
     *  Constant: '<S1>/Constant8'
     *  Constant: '<S1>/Constant9'
     *  Inport: '<Root>/Sector'
     */
    for (i = 0; i < 6; i++) {
      switch ((int32_T)BLDC_Control_Logic_U.Sector[i]) {
       case 0:
        rtb_SwitchingPatterns[i] = BLDC_Control_Logic_ConstP.pooled3[i];
        break;

       case 1:
        rtb_SwitchingPatterns[i] = BLDC_Control_Logic_ConstP.pooled4[i];
        break;

       case 2:
        rtb_SwitchingPatterns[i] = BLDC_Control_Logic_ConstP.pooled5[i];
        break;

       case 3:
        rtb_SwitchingPatterns[i] = BLDC_Control_Logic_ConstP.pooled1[i];
        break;

       case 4:
        rtb_SwitchingPatterns[i] = BLDC_Control_Logic_ConstP.pooled1[i];
        break;

       default:
        rtb_SwitchingPatterns[i] = BLDC_Control_Logic_ConstP.pooled2[i];
        break;
      }
    }

    /* End of MultiPortSwitch: '<S1>/Multiport Switch1' */
  }

  /* End of Switch: '<S1>/Switch' */

  /* Outport: '<Root>/Switcing Patterns' */
  for (i = 0; i < 6; i++) {
    BLDC_Control_Logic_Y.SwitcingPatterns[i] = rtb_SwitchingPatterns[i];
  }

  /* End of Outport: '<Root>/Switcing Patterns' */

  /* Update for DiscreteIntegrator: '<S16>/Integrator' incorporates:
   *  Gain: '<S16>/Integral Gain'
   */
  BLDC_Control_Logic_DW.Integrator_DSTATE += 5.0 * rtb_Sum2 * 1.0E-5;

  /* Update for DiscreteIntegrator: '<S11>/Integrator' */
  BLDC_Control_Logic_DW.Integrator_DSTATE_k += 1.0E-5;
  BLDC_Control_Logic_DW.Integrator_PrevResetState = (int8_T)rtb_Compare_d;
}

/* Model initialize function */
void BLDC_Control_Logic_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(BLDC_Control_Logic_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&BLDC_Control_Logic_DW, 0,
                sizeof(DW_BLDC_Control_Logic_T));

  /* external inputs */
  (void)memset((void *)&BLDC_Control_Logic_U, 0, sizeof
               (ExtU_BLDC_Control_Logic_T));

  /* external outputs */
  (void) memset(&BLDC_Control_Logic_Y.SwitcingPatterns[0], 0,
                6U*sizeof(real_T));

  /* Start for InitialCondition: '<S11>/Initial' */
  BLDC_Control_Logic_DW.Initial_FirstOutputTime = true;

  /* InitializeConditions for DiscreteIntegrator: '<S11>/Integrator' */
  BLDC_Control_Logic_DW.Integrator_DSTATE_k = 0.0;
  BLDC_Control_Logic_DW.Integrator_PrevResetState = 2;
}

/* Model terminate function */
void BLDC_Control_Logic_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
