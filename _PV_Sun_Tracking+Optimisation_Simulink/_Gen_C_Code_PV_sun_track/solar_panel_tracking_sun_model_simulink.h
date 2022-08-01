/*
 * solar_panel_tracking_sun_model_simulink.h
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

#ifndef RTW_HEADER_solar_panel_tracking_sun_model_simulink_h_
#define RTW_HEADER_solar_panel_tracking_sun_model_simulink_h_
#include <stddef.h>
#include <math.h>
#include <string.h>
#ifndef solar_panel_tracking_sun_model_simulink_COMMON_INCLUDES_
# define solar_panel_tracking_sun_model_simulink_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rsim.h"
#include "rt_logging.h"
#include "dt_info.h"
#endif                                 /* solar_panel_tracking_sun_model_simulink_COMMON_INCLUDES_ */

#include "solar_panel_tracking_sun_model_simulink_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#define MODEL_NAME                     solar_panel_tracking_sun_model_simulink
#define NSAMPLE_TIMES                  (1)                       /* Number of sample times */
#define NINPUTS                        (2)                       /* Number of model inputs */
#define NOUTPUTS                       (0)                       /* Number of model outputs */
#define NBLOCKIO                       (18)                      /* Number of data output port signals */
#define NUM_ZC_EVENTS                  (0)                       /* Number of zero-crossing events */
#ifndef NCSTATES
# define NCSTATES                      (4)                       /* Number of continuous states */
#elif NCSTATES != 4
# error Invalid specification of NCSTATES defined in compiler command
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        (NULL)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T theta;                        /* '<S4>/Integrator1' */
  real_T theta_dot;                    /* '<S4>/Integrator' */
  real_T Intensity;                    /* '<S2>/Integrator' */
  real_T Gain1;                        /* '<S2>/Gain1' */
  real_T Gain2;                        /* '<S2>/Gain2' */
  real_T Sum;                          /* '<Root>/Sum' */
  real_T ProportionalGain;             /* '<S3>/Proportional Gain' */
  real_T Integrator;                   /* '<S3>/Integrator' */
  real_T Sum_c;                        /* '<S3>/Sum' */
  real_T Gain4;                        /* '<S2>/Gain4' */
  real_T Gain3;                        /* '<S2>/Gain3' */
  real_T Resistance;                   /* '<S2>/Resistance' */
  real_T Subtract;                     /* '<S2>/Subtract' */
  real_T intensity_dot;                /* '<S2>/Gain' */
  real_T IntegralGain;                 /* '<S3>/Integral Gain' */
  real_T Gain1_l;                      /* '<S4>/Gain1' */
  real_T theta_dot_dot;                /* '<S4>/Subtract' */
  real_T Gain;                         /* '<S4>/Gain' */
} B;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<Root>/Scope3' */
} DW;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S4>/Integrator1' */
  real_T Integrator_CSTATE;            /* '<S4>/Integrator' */
  real_T Integrator_CSTATE_k;          /* '<S2>/Integrator' */
  real_T Integrator_CSTATE_m;          /* '<S3>/Integrator' */
} X;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S4>/Integrator1' */
  real_T Integrator_CSTATE;            /* '<S4>/Integrator' */
  real_T Integrator_CSTATE_k;          /* '<S2>/Integrator' */
  real_T Integrator_CSTATE_m;          /* '<S3>/Integrator' */
} XDot;

/* State disabled  */
typedef struct {
  boolean_T Integrator1_CSTATE;        /* '<S4>/Integrator1' */
  boolean_T Integrator_CSTATE;         /* '<S4>/Integrator' */
  boolean_T Integrator_CSTATE_k;       /* '<S2>/Integrator' */
  boolean_T Integrator_CSTATE_m;       /* '<S3>/Integrator' */
} XDis;

/* Continuous State Absolute Tolerance  */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S4>/Integrator1' */
  real_T Integrator_CSTATE;            /* '<S4>/Integrator' */
  real_T Integrator_CSTATE_k;          /* '<S2>/Integrator' */
  real_T Integrator_CSTATE_m;          /* '<S3>/Integrator' */
} CStateAbsTol;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T SunPosition;                  /* '<Root>/In1' */
  real_T SunElevation;                 /* '<Root>/Sun Elevation' */
} ExtU;

/* Parameters (auto storage) */
struct P_ {
  real_T J;                            /* Variable: J
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T Kd;                           /* Variable: Kd
                                        * Referenced by: '<S4>/Gain1'
                                        */
  real_T Kf;                           /* Variable: Kf
                                        * Referenced by: '<S2>/Gain4'
                                        */
  real_T Kg;                           /* Variable: Kg
                                        * Referenced by:
                                        *   '<S2>/Gain1'
                                        *   '<S2>/Gain3'
                                        */
  real_T Kt;                           /* Variable: Kt
                                        * Referenced by: '<S2>/Gain2'
                                        */
  real_T L;                            /* Variable: L
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T Res;                          /* Variable: Res
                                        * Referenced by: '<S2>/Resistance'
                                        */
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S3>/Integral Gain'
                                        */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S3>/Proportional Gain'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S4>/Integrator1'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S4>/Integrator'
                                        */
  real_T Integrator_IC_p;              /* Expression: 0
                                        * Referenced by: '<S2>/Integrator'
                                        */
  real_T Integrator_IC_g;              /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S3>/Integrator'
                                        */
};

/* External data declarations for dependent source files */
extern const char *RT_MEMORY_ALLOCATION_ERROR;
extern B rtB;                          /* block i/o */
extern X rtX;                          /* states (continuous) */
extern DW rtDW;                        /* states (dwork) */
extern ExtU rtU;                       /* external inputs */
extern P rtP;                          /* parameters */

/* Simulation Structure */
extern SimStruct *const rtS;

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
 * '<Root>' : 'solar_panel_tracking_sun_model_simulink'
 * '<S1>'   : 'solar_panel_tracking_sun_model_simulink/MATLAB Function'
 * '<S2>'   : 'solar_panel_tracking_sun_model_simulink/Motor'
 * '<S3>'   : 'solar_panel_tracking_sun_model_simulink/PID Controller'
 * '<S4>'   : 'solar_panel_tracking_sun_model_simulink/Solar Panel'
 */

/* user code (bottom of header file) */
extern const int_T gblNumToFiles;
extern const int_T gblNumFrFiles;
extern const int_T gblNumFrWksBlocks;
extern rtInportTUtable *gblInportTUtables;
extern const char *gblInportFileName;
extern const int_T gblNumRootInportBlks;
extern const int_T gblNumModelInputs;
extern const int_T gblInportDataTypeIdx[];
extern const int_T gblInportDims[];
extern const int_T gblInportComplex[];
extern const int_T gblInportInterpoFlag[];
extern const int_T gblInportContinuous[];

#endif                                 /* RTW_HEADER_solar_panel_tracking_sun_model_simulink_h_ */
