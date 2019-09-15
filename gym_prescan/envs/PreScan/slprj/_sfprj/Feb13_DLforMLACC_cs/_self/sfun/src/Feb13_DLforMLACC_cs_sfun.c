/* Include files */

#define IN_SF_MACHINE_SOURCE           1
#include "Feb13_DLforMLACC_cs_sfun.h"
#include "Feb13_DLforMLACC_cs_sfun_debug_macros.h"
#include "c2_Feb13_DLforMLACC_cs.h"
#include "c8_Feb13_DLforMLACC_cs.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _Feb13_DLforMLACC_csMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void Feb13_DLforMLACC_cs_initializer(void)
{
}

void Feb13_DLforMLACC_cs_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_Feb13_DLforMLACC_cs_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==2) {
    c2_Feb13_DLforMLACC_cs_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_Feb13_DLforMLACC_cs_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_Feb13_DLforMLACC_cs_process_check_sum_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4188033116U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2482784291U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1644850984U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2914857338U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 2:
        {
          extern void sf_c2_Feb13_DLforMLACC_cs_get_check_sum(mxArray *plhs[]);
          sf_c2_Feb13_DLforMLACC_cs_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_Feb13_DLforMLACC_cs_get_check_sum(mxArray *plhs[]);
          sf_c8_Feb13_DLforMLACC_cs_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1126722536U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3211810005U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3934126720U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3824053538U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3196840830U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1306571977U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1652599121U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(58338819U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Feb13_DLforMLACC_cs_autoinheritance_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        if (strcmp(aiChksum, "8BIANqJbHnvsVAtRHd20nE") == 0) {
          extern mxArray *sf_c2_Feb13_DLforMLACC_cs_get_autoinheritance_info
            (void);
          plhs[0] = sf_c2_Feb13_DLforMLACC_cs_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "noe0rQRqeJv7Bov2wfnCLH") == 0) {
          extern mxArray *sf_c8_Feb13_DLforMLACC_cs_get_autoinheritance_info
            (void);
          plhs[0] = sf_c8_Feb13_DLforMLACC_cs_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Feb13_DLforMLACC_cs_get_eml_resolved_functions_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  char instanceChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    mxGetString(prhs[2], instanceChksum,sizeof(instanceChksum)/sizeof(char));
    instanceChksum[(sizeof(instanceChksum)/sizeof(char)-1)] = '\0';
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        if (strcmp(instanceChksum, "suMcrPkrw2BA9pimpFhtePG") == 0) {
          extern const mxArray
            *sf_c2_Feb13_DLforMLACC_cs_get_eml_resolved_functions_info(void);
          mxArray *persistentMxArray = (mxArray *)
            sf_c2_Feb13_DLforMLACC_cs_get_eml_resolved_functions_info();
          plhs[0] = mxDuplicateArray(persistentMxArray);
          mxDestroyArray(persistentMxArray);
          break;
        }
      }

     case 8:
      {
        if (strcmp(instanceChksum, "s65jrMyBLFbEl8YgFfcUunD") == 0) {
          extern const mxArray
            *sf_c8_Feb13_DLforMLACC_cs_get_eml_resolved_functions_info(void);
          mxArray *persistentMxArray = (mxArray *)
            sf_c8_Feb13_DLforMLACC_cs_get_eml_resolved_functions_info();
          plhs[0] = mxDuplicateArray(persistentMxArray);
          mxDestroyArray(persistentMxArray);
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Feb13_DLforMLACC_cs_third_party_uses_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        if (strcmp(tpChksum, "suMcrPkrw2BA9pimpFhtePG") == 0) {
          extern mxArray *sf_c2_Feb13_DLforMLACC_cs_third_party_uses_info(void);
          plhs[0] = sf_c2_Feb13_DLforMLACC_cs_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "s65jrMyBLFbEl8YgFfcUunD") == 0) {
          extern mxArray *sf_c8_Feb13_DLforMLACC_cs_third_party_uses_info(void);
          plhs[0] = sf_c8_Feb13_DLforMLACC_cs_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_Feb13_DLforMLACC_cs_jit_fallback_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the jit_fallback_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_jit_fallback_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        if (strcmp(tpChksum, "suMcrPkrw2BA9pimpFhtePG") == 0) {
          extern mxArray *sf_c2_Feb13_DLforMLACC_cs_jit_fallback_info(void);
          plhs[0] = sf_c2_Feb13_DLforMLACC_cs_jit_fallback_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "s65jrMyBLFbEl8YgFfcUunD") == 0) {
          extern mxArray *sf_c8_Feb13_DLforMLACC_cs_jit_fallback_info(void);
          plhs[0] = sf_c8_Feb13_DLforMLACC_cs_jit_fallback_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_Feb13_DLforMLACC_cs_updateBuildInfo_args_info( int nlhs, mxArray
  * plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        if (strcmp(tpChksum, "suMcrPkrw2BA9pimpFhtePG") == 0) {
          extern mxArray *sf_c2_Feb13_DLforMLACC_cs_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c2_Feb13_DLforMLACC_cs_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "s65jrMyBLFbEl8YgFfcUunD") == 0) {
          extern mxArray *sf_c8_Feb13_DLforMLACC_cs_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c8_Feb13_DLforMLACC_cs_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void Feb13_DLforMLACC_cs_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _Feb13_DLforMLACC_csMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "Feb13_DLforMLACC_cs","sfun",0,13,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _Feb13_DLforMLACC_csMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _Feb13_DLforMLACC_csMachineNumber_,0);
}

void Feb13_DLforMLACC_cs_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
typedef struct SfOptimizationInfoFlagsTag {
  boolean_T isRtwGen;
  boolean_T isModelRef;
  boolean_T isExternal;
} SfOptimizationInfoFlags;

static SfOptimizationInfoFlags sOptimizationInfoFlags;
void unload_Feb13_DLforMLACC_cs_optimization_info(void);
mxArray* load_Feb13_DLforMLACC_cs_optimization_info(boolean_T isRtwGen,
  boolean_T isModelRef, boolean_T isExternal)
{
  if (sOptimizationInfoFlags.isRtwGen != isRtwGen ||
      sOptimizationInfoFlags.isModelRef != isModelRef ||
      sOptimizationInfoFlags.isExternal != isExternal) {
    unload_Feb13_DLforMLACC_cs_optimization_info();
  }

  sOptimizationInfoFlags.isRtwGen = isRtwGen;
  sOptimizationInfoFlags.isModelRef = isModelRef;
  sOptimizationInfoFlags.isExternal = isExternal;
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "Feb13_DLforMLACC_cs", "Feb13_DLforMLACC_cs");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_Feb13_DLforMLACC_cs_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
