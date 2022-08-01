/*
 * solar_panel_tracking_sun_model_simulink.c
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

#include <math.h>
#include "solar_panel_tracking_sun_model_simulink.h"
#include "solar_panel_tracking_sun_model_simulink_private.h"
#include "solar_panel_tracking_sun_model_simulink_dt.h"

/* user code (top of parameter file) */
const int_T gblNumToFiles = 0;
const int_T gblNumFrFiles = 0;
const int_T gblNumFrWksBlocks = 0;
const char *gblSlvrJacPatternFileName =
  "solar_panel_tracking_sun_model_simulink_rsim_rtw\\solar_panel_tracking_sun_model_simulink_Jpattern.mat";

/* Root inports information  */
const int_T gblNumRootInportBlks = 2;
const int_T gblNumModelInputs = 2;
extern rtInportTUtable *gblInportTUtables;
extern const char *gblInportFileName;
const int_T gblInportDataTypeIdx[] = { 0, 0 };

const int_T gblInportDims[] = { 1, 1, 1, 1 } ;

const int_T gblInportComplex[] = { 0, 0 };

const int_T gblInportInterpoFlag[] = { 1, 1 };

const int_T gblInportContinuous[] = { 1, 1 };

#include "simstruc.h"
#include "fixedpoint.h"

/* Block signals (auto storage) */
B rtB;

/* Continuous states */
X rtX;

/* Block states (auto storage) */
DW rtDW;

/* External inputs (root inport signals with auto storage) */
ExtU rtU;

/* Parent Simstruct */
static SimStruct model_S;
SimStruct *const rtS = &model_S;
real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* System initialize for root system: '<Root>' */
void MdlInitialize(void)
{
  /* InitializeConditions for Integrator: '<S4>/Integrator1' */
  rtX.Integrator1_CSTATE = rtP.Integrator1_IC;

  /* InitializeConditions for Integrator: '<S4>/Integrator' */
  rtX.Integrator_CSTATE = rtP.Integrator_IC;

  /* InitializeConditions for Integrator: '<S2>/Integrator' */
  rtX.Integrator_CSTATE_k = rtP.Integrator_IC_p;

  /* InitializeConditions for Integrator: '<S3>/Integrator' */
  rtX.Integrator_CSTATE_m = rtP.Integrator_IC_g;
}

/* Start for root system: '<Root>' */
void MdlStart(void)
{
  MdlInitialize();
}

/* Outputs for root system: '<Root>' */
void MdlOutputs(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_powerOutput;

  /* Read data from the mat file of inport block */
  if (gblInportFileName != (NULL)) {
    real_T time = ssGetT(rtS);
    int_T currTimeIdx;
    int_T i;

    /*
     *  Read in data from mat file for root inport SunPosition
     */
    if (gblInportTUtables[0].nTimePoints > 0) {
      {
        {
          int k = 1;
          if (gblInportTUtables[0].nTimePoints == 1) {
            k = 0;
          }

          currTimeIdx = rt_getTimeIdx(gblInportTUtables[0].time, time,
            gblInportTUtables[0].nTimePoints,
            gblInportTUtables[0].currTimeIdx,
            1,
            0);
          gblInportTUtables[0].currTimeIdx = currTimeIdx;
          for (i = 0; i < 1; i++) {
            real_T* realPtr1 = (real_T*)gblInportTUtables[0].ur +
              i*gblInportTUtables[0].nTimePoints +currTimeIdx;
            real_T* realPtr2 = realPtr1 + 1*k;
            (void)rt_Interpolate_Datatype(
              realPtr1,
              realPtr2,
              &rtU.SunPosition,
              time,
              gblInportTUtables[0].time[currTimeIdx],
              gblInportTUtables[0].time[currTimeIdx + k],
              gblInportTUtables[0].uDataType);
          }
        }
      }
    }

    /*
     *  Read in data from mat file for root inport SunElevation
     */
    if (gblInportTUtables[1].nTimePoints > 0) {
      {
        {
          int k = 1;
          if (gblInportTUtables[1].nTimePoints == 1) {
            k = 0;
          }

          currTimeIdx = rt_getTimeIdx(gblInportTUtables[1].time, time,
            gblInportTUtables[1].nTimePoints,
            gblInportTUtables[1].currTimeIdx,
            1,
            0);
          gblInportTUtables[1].currTimeIdx = currTimeIdx;
          for (i = 0; i < 1; i++) {
            real_T* realPtr1 = (real_T*)gblInportTUtables[1].ur +
              i*gblInportTUtables[1].nTimePoints +currTimeIdx;
            real_T* realPtr2 = realPtr1 + 1*k;
            (void)rt_Interpolate_Datatype(
              realPtr1,
              realPtr2,
              &rtU.SunElevation,
              time,
              gblInportTUtables[1].time[currTimeIdx],
              gblInportTUtables[1].time[currTimeIdx + k],
              gblInportTUtables[1].uDataType);
          }
        }
      }
    }
  }

  /* end read inport data from file */

  /* Integrator: '<S4>/Integrator1' */
  rtB.theta = rtX.Integrator1_CSTATE;

  /* Integrator: '<S4>/Integrator' */
  rtB.theta_dot = rtX.Integrator_CSTATE;

  /* Integrator: '<S2>/Integrator' */
  rtB.Intensity = rtX.Integrator_CSTATE_k;

  /* Gain: '<S2>/Gain1' */
  rtB.Gain1 = rtP.Kg * rtB.Intensity;

  /* Gain: '<S2>/Gain2' */
  rtB.Gain2 = rtP.Kt * rtB.Gain1;

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/Sun Elevation'
   */
  rtb_powerOutput = (sin(1.5707963267948966 - rtU.SunElevation) *
                     0.90929742682568171 * cos(rtB.theta - rtU.SunPosition) +
                     cos(1.5707963267948966 - rtU.SunElevation) *
                     -0.41614683654714241) * (1.353 * rt_powd_snf(0.7,
    rt_powd_snf(sin(rtU.SunElevation), -0.678))) * 4.0 * 0.195 * 1000.0;
  rtb_powerOutput = fmax(rtb_powerOutput, 0.0);

  /* Sum: '<Root>/Sum' incorporates:
   *  Inport: '<Root>/In1'
   */
  rtB.Sum = rtU.SunPosition - rtB.theta;

  /* Gain: '<S3>/Proportional Gain' */
  rtB.ProportionalGain = rtP.PIDController_P * rtB.Sum;

  /* Integrator: '<S3>/Integrator' */
  rtB.Integrator = rtX.Integrator_CSTATE_m;

  /* Sum: '<S3>/Sum' */
  rtB.Sum_c = rtB.ProportionalGain + rtB.Integrator;

  /* Gain: '<S2>/Gain4' */
  rtB.Gain4 = rtP.Kf * rtB.theta_dot;

  /* Gain: '<S2>/Gain3' */
  rtB.Gain3 = rtP.Kg * rtB.Gain4;

  /* Gain: '<S2>/Resistance' */
  rtB.Resistance = rtP.Res * rtB.Intensity;

  /* Sum: '<S2>/Subtract' */
  rtB.Subtract = (rtB.Sum_c - rtB.Gain3) - rtB.Resistance;

  /* Gain: '<S2>/Gain' */
  rtB.intensity_dot = 1.0 / rtP.L * rtB.Subtract;

  /* Gain: '<S3>/Integral Gain' */
  rtB.IntegralGain = rtP.PIDController_I * rtB.Sum;

  /* Gain: '<S4>/Gain1' */
  rtB.Gain1_l = rtP.Kd * rtB.theta_dot;

  /* Sum: '<S4>/Subtract' */
  rtB.theta_dot_dot = rtB.Gain2 - rtB.Gain1_l;

  /* Gain: '<S4>/Gain' */
  rtB.Gain = 1.0 / rtP.J * rtB.theta_dot_dot;
  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
void MdlUpdate(int_T tid)
{
  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
void MdlDerivatives(void)
{
  XDot *_rtXdot;
  _rtXdot = ((XDot *) ssGetdX(rtS));

  /* Derivatives for Integrator: '<S4>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = rtB.theta_dot;

  /* Derivatives for Integrator: '<S4>/Integrator' */
  _rtXdot->Integrator_CSTATE = rtB.Gain;

  /* Derivatives for Integrator: '<S2>/Integrator' */
  _rtXdot->Integrator_CSTATE_k = rtB.intensity_dot;

  /* Derivatives for Integrator: '<S3>/Integrator' */
  _rtXdot->Integrator_CSTATE_m = rtB.IntegralGain;
}

/* Projection for root system: '<Root>' */
void MdlProjection(void)
{
}

/* Termination for root system: '<Root>' */
void MdlTerminate(void)
{
}

/* Function to initialize sizes */
void MdlInitializeSizes(void)
{
  ssSetNumContStates(rtS, 4);          /* Number of continuous states */
  ssSetNumPeriodicContStates(rtS, 0);  /* Number of periodic continuous states */
  ssSetNumY(rtS, 0);                   /* Number of model outputs */
  ssSetNumU(rtS, 2);                   /* Number of model inputs */
  ssSetDirectFeedThrough(rtS, 1);      /* The model is direct feedthrough */
  ssSetNumSampleTimes(rtS, 1);         /* Number of sample times */
  ssSetNumBlocks(rtS, 24);             /* Number of blocks */
  ssSetNumBlockIO(rtS, 18);            /* Number of block outputs */
  ssSetNumBlockParams(rtS, 13);        /* Sum of parameter "widths" */
}

/* Function to initialize sample times. */
void MdlInitializeSampleTimes(void)
{
  /* task periods */
  ssSetSampleTime(rtS, 0, 0.0);

  /* task offsets */
  ssSetOffsetTime(rtS, 0, 0.0);
}

/* Function to register the model */
/* Turns off all optimizations on Windows because of issues with VC 2015 compiler.
   This function is not performance-critical, hence this is not a problem.
 */
#if defined(_MSC_VER)

#pragma optimize( "", off )

#endif

SimStruct * solar_panel_tracking_sun_model_simulink(void)
{
  static struct _ssMdlInfo mdlInfo;
  (void) memset((char *)rtS, 0,
                sizeof(SimStruct));
  (void) memset((char *)&mdlInfo, 0,
                sizeof(struct _ssMdlInfo));
  ssSetMdlInfoPtr(rtS, &mdlInfo);

  /* timing info */
  {
    static time_T mdlPeriod[NSAMPLE_TIMES];
    static time_T mdlOffset[NSAMPLE_TIMES];
    static time_T mdlTaskTimes[NSAMPLE_TIMES];
    static int_T mdlTsMap[NSAMPLE_TIMES];
    static int_T mdlSampleHits[NSAMPLE_TIMES];
    static boolean_T mdlTNextWasAdjustedPtr[NSAMPLE_TIMES];
    static int_T mdlPerTaskSampleHits[NSAMPLE_TIMES * NSAMPLE_TIMES];
    static time_T mdlTimeOfNextSampleHit[NSAMPLE_TIMES];

    {
      int_T i;
      for (i = 0; i < NSAMPLE_TIMES; i++) {
        mdlPeriod[i] = 0.0;
        mdlOffset[i] = 0.0;
        mdlTaskTimes[i] = 0.0;
        mdlTsMap[i] = i;
        mdlSampleHits[i] = 1;
      }
    }

    ssSetSampleTimePtr(rtS, &mdlPeriod[0]);
    ssSetOffsetTimePtr(rtS, &mdlOffset[0]);
    ssSetSampleTimeTaskIDPtr(rtS, &mdlTsMap[0]);
    ssSetTPtr(rtS, &mdlTaskTimes[0]);
    ssSetSampleHitPtr(rtS, &mdlSampleHits[0]);
    ssSetTNextWasAdjustedPtr(rtS, &mdlTNextWasAdjustedPtr[0]);
    ssSetPerTaskSampleHitsPtr(rtS, &mdlPerTaskSampleHits[0]);
    ssSetTimeOfNextSampleHitPtr(rtS, &mdlTimeOfNextSampleHit[0]);
  }

  ssSetSolverMode(rtS, SOLVER_MODE_SINGLETASKING);

  /*
   * initialize model vectors and cache them in SimStruct
   */

  /* block I/O */
  {
    ssSetBlockIO(rtS, ((void *) &rtB));
    (void) memset(((void *) &rtB), 0,
                  sizeof(B));
  }

  /* external inputs */
  {
    ssSetU(rtS, ((void*) &rtU));
    (void)memset((void *)&rtU, 0, sizeof(ExtU));
  }

  /* parameters */
  ssSetDefaultParam(rtS, (real_T *) &rtP);

  /* states (continuous)*/
  {
    real_T *x = (real_T *) &rtX;
    ssSetContStates(rtS, x);
    (void) memset((void *)x, 0,
                  sizeof(X));
  }

  /* states (dwork) */
  {
    void *dwork = (void *) &rtDW;
    ssSetRootDWork(rtS, dwork);
    (void) memset(dwork, 0,
                  sizeof(DW));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    ssSetModelMappingInfo(rtS, &dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Model specific registration */
  ssSetRootSS(rtS, rtS);
  ssSetVersion(rtS, SIMSTRUCT_VERSION_LEVEL2);
  ssSetModelName(rtS, "solar_panel_tracking_sun_model_simulink");
  ssSetPath(rtS, "solar_panel_tracking_sun_model_simulink");
  ssSetTStart(rtS, 0.0);
  ssSetTFinal(rtS, 50400.0);

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    ssSetRTWLogInfo(rtS, &rt_DataLoggingInfo);
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ssGetRTWLogInfo(rtS), (NULL));
    rtliSetLogXSignalPtrs(ssGetRTWLogInfo(rtS), (NULL));
    rtliSetLogT(ssGetRTWLogInfo(rtS), "tout");
    rtliSetLogX(ssGetRTWLogInfo(rtS), "");
    rtliSetLogXFinal(ssGetRTWLogInfo(rtS), "");
    rtliSetLogVarNameModifier(ssGetRTWLogInfo(rtS), "rt_");
    rtliSetLogFormat(ssGetRTWLogInfo(rtS), 4);
    rtliSetLogMaxRows(ssGetRTWLogInfo(rtS), 0);
    rtliSetLogDecimation(ssGetRTWLogInfo(rtS), 1);
    rtliSetLogY(ssGetRTWLogInfo(rtS), "");
    rtliSetLogYSignalInfo(ssGetRTWLogInfo(rtS), (NULL));
    rtliSetLogYSignalPtrs(ssGetRTWLogInfo(rtS), (NULL));
  }

  {
    static struct _ssStatesInfo2 statesInfo2;
    ssSetStatesInfo2(rtS, &statesInfo2);
  }

  {
    static ssPeriodicStatesInfo periodicStatesInfo;
    ssSetPeriodicStatesInfo(rtS, &periodicStatesInfo);
  }

  {
    static ssSolverInfo slvrInfo;
    static boolean_T contStatesDisabled[4];
    static real_T absTol[4] = { 1.0E-6, 1.0E-6, 1.0E-6, 1.0E-6 };

    static uint8_T absTolControl[4] = { 0U, 0U, 0U, 0U };

    ssSetSolverRelTol(rtS, 0.001);
    ssSetStepSize(rtS, 0.0);
    ssSetMinStepSize(rtS, 0.0);
    ssSetMaxNumMinSteps(rtS, -1);
    ssSetMinStepViolatedError(rtS, 0);
    ssSetMaxStepSize(rtS, 1008.0);
    ssSetSolverMaxOrder(rtS, 5);
    ssSetSolverRefineFactor(rtS, 1);
    ssSetOutputTimes(rtS, (NULL));
    ssSetNumOutputTimes(rtS, 0);
    ssSetOutputTimesOnly(rtS, 0);
    ssSetOutputTimesIndex(rtS, 0);
    ssSetZCCacheNeedsReset(rtS, 0);
    ssSetDerivCacheNeedsReset(rtS, 0);
    ssSetNumNonContDerivSigInfos(rtS, 0);
    ssSetNonContDerivSigInfos(rtS, (NULL));
    ssSetSolverInfo(rtS, &slvrInfo);
    ssSetSolverName(rtS, "ode15s");
    ssSetVariableStepSolver(rtS, 1);
    ssSetSolverConsistencyChecking(rtS, 0);
    ssSetSolverAdaptiveZcDetection(rtS, 0);
    ssSetSolverRobustResetMethod(rtS, 0);
    ssSetAbsTolVector(rtS, absTol);
    ssSetAbsTolControlVector(rtS, absTolControl);
    ssSetSolverAbsTol_Obsolete(rtS, absTol);
    ssSetSolverAbsTolControl_Obsolete(rtS, absTolControl);
    ssSetSolverStateProjection(rtS, 0);
    ssSetSolverMassMatrixType(rtS, (ssMatrixType)0);
    ssSetSolverMassMatrixNzMax(rtS, 0);
    ssSetModelOutputs(rtS, MdlOutputs);
    ssSetModelLogData(rtS, rt_UpdateTXYLogVars);
    ssSetModelLogDataIfInInterval(rtS, rt_UpdateTXXFYLogVars);
    ssSetModelUpdate(rtS, MdlUpdate);
    ssSetModelDerivatives(rtS, MdlDerivatives);
    ssSetSolverMaxConsecutiveMinStep(rtS, 1);
    ssSetSolverShapePreserveControl(rtS, 2);
    ssSetTNextTid(rtS, INT_MIN);
    ssSetTNext(rtS, rtMinusInf);
    ssSetSolverNeedsReset(rtS);
    ssSetNumNonsampledZCs(rtS, 0);
    ssSetContStateDisabled(rtS, contStatesDisabled);
    ssSetSolverMaxConsecutiveMinStep(rtS, 1);
  }

  ssSetChecksumVal(rtS, 0, 2664383849U);
  ssSetChecksumVal(rtS, 1, 1375488786U);
  ssSetChecksumVal(rtS, 2, 2019446928U);
  ssSetChecksumVal(rtS, 3, 2501266434U);
  return rtS;
}

/* When you use the on parameter, it resets the optimizations to those that you
   specified with the /O compiler option. */
#if defined(_MSC_VER)

#pragma optimize( "", on )

#endif
