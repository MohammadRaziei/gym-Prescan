#ifndef __c8_Feb16_DLforMLACC_cs_h__
#define __c8_Feb16_DLforMLACC_cs_h__

/* Type Definitions */
#ifndef struct_PRESCAN_V2X_USER_GENERIC_DATA_tag
#define struct_PRESCAN_V2X_USER_GENERIC_DATA_tag

struct PRESCAN_V2X_USER_GENERIC_DATA_tag
{
  int32_T messageID;
  int32_T senderID;
  real_T signal_1;
  real_T signal_4;
  real_T signal_5;
  int32_T discrete_signal_3;
};

#endif                                 /*struct_PRESCAN_V2X_USER_GENERIC_DATA_tag*/

#ifndef typedef_c8_PRESCAN_V2X_USER_GENERIC_DATA
#define typedef_c8_PRESCAN_V2X_USER_GENERIC_DATA

typedef struct PRESCAN_V2X_USER_GENERIC_DATA_tag
  c8_PRESCAN_V2X_USER_GENERIC_DATA;

#endif                                 /*typedef_c8_PRESCAN_V2X_USER_GENERIC_DATA*/

#include "prescan_header_data.h"
#ifndef struct_PRESCAN_V2X_USER_GENERIC_MESSAGE_tag
#define struct_PRESCAN_V2X_USER_GENERIC_MESSAGE_tag

struct PRESCAN_V2X_USER_GENERIC_MESSAGE_tag
{
  PRESCAN_HEADER HEADER;
  c8_PRESCAN_V2X_USER_GENERIC_DATA DATA;
};

#endif                                 /*struct_PRESCAN_V2X_USER_GENERIC_MESSAGE_tag*/

#ifndef typedef_c8_PRESCAN_V2X_USER_GENERIC_MESSAGE
#define typedef_c8_PRESCAN_V2X_USER_GENERIC_MESSAGE

typedef struct PRESCAN_V2X_USER_GENERIC_MESSAGE_tag
  c8_PRESCAN_V2X_USER_GENERIC_MESSAGE;

#endif                                 /*typedef_c8_PRESCAN_V2X_USER_GENERIC_MESSAGE*/

#include "prescan_v2x_generic_data.h"
#ifndef typedef_SFc8_Feb16_DLforMLACC_csInstanceStruct
#define typedef_SFc8_Feb16_DLforMLACC_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c8_sfEvent;
  boolean_T c8_doneDoubleBufferReInit;
  uint8_T c8_is_active_c8_Feb16_DLforMLACC_cs;
  void *c8_RuntimeVar;
  uint32_T c8_mlFcnLineNumber;
  void *c8_fEmlrtCtx;
  c8_PRESCAN_V2X_USER_GENERIC_MESSAGE *c8_u;
  PRESCAN_V2X_FIXED_GENERIC_MESSAGE *c8_y;
  PRESCAN_V2X_FIXED_GENERIC_MESSAGE *c8_z;
} SFc8_Feb16_DLforMLACC_csInstanceStruct;

#endif                                 /*typedef_SFc8_Feb16_DLforMLACC_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c8_Feb16_DLforMLACC_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c8_Feb16_DLforMLACC_cs_get_check_sum(mxArray *plhs[]);
extern void c8_Feb16_DLforMLACC_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
