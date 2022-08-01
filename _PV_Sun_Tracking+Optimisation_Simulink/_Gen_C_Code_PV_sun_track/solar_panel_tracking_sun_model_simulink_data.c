/*
 * solar_panel_tracking_sun_model_simulink_data.c
 *
 * Code generation for model "solar_panel_tracking_sun_model_simulink".
 *
 * Model version              : 1.45
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Tue Jan 11 19:32:14 2022
 *
 * Target selection: rsim.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "solar_panel_tracking_sun_model_simulink.h"
#include "solar_panel_tracking_sun_model_simulink_private.h"

/* Block parameters (auto storage) */
P rtP = {
  /* Variable: J
   * Referenced by: '<S4>/Gain'
   */
  8.6,

  /* Variable: Kd
   * Referenced by: '<S4>/Gain1'
   */
  5.0,

  /* Variable: Kf
   * Referenced by: '<S2>/Gain4'
   */
  0.07,

  /* Variable: Kg
   * Referenced by:
   *   '<S2>/Gain1'
   *   '<S2>/Gain3'
   */
  2000.0,

  /* Variable: Kt
   * Referenced by: '<S2>/Gain2'
   */
  0.07,

  /* Variable: L
   * Referenced by: '<S2>/Gain'
   */
  1.0E-5,

  /* Variable: Res
   * Referenced by: '<S2>/Resistance'
   */
  10.0,

  /* Mask Parameter: PIDController_I
   * Referenced by: '<S3>/Integral Gain'
   */
  180.0,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S3>/Proportional Gain'
   */
  240.0,

  /* Expression: 0
   * Referenced by: '<S4>/Integrator1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Integrator'
   */
  0.0,

  /* Expression: InitialConditionForIntegrator
   * Referenced by: '<S3>/Integrator'
   */
  0.0
};
