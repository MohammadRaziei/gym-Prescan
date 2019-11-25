#ifndef __c5_Jan22_DLforACC_cs_h__
#define __c5_Jan22_DLforACC_cs_h__

/* Type Definitions */
#ifndef struct_PRESCAN_V2X_USER_BSM_size_tag
#define struct_PRESCAN_V2X_USER_BSM_size_tag

struct PRESCAN_V2X_USER_BSM_size_tag
{
  int32_T width;
  int32_T length;
};

#endif                                 /*struct_PRESCAN_V2X_USER_BSM_size_tag*/

#ifndef typedef_c5_PRESCAN_V2X_USER_BSM_size
#define typedef_c5_PRESCAN_V2X_USER_BSM_size

typedef struct PRESCAN_V2X_USER_BSM_size_tag c5_PRESCAN_V2X_USER_BSM_size;

#endif                                 /*typedef_c5_PRESCAN_V2X_USER_BSM_size*/

#ifndef struct_PRESCAN_V2X_USER_BSM_DATA_tag
#define struct_PRESCAN_V2X_USER_BSM_DATA_tag

struct PRESCAN_V2X_USER_BSM_DATA_tag
{
  int32_T msgID;
  int32_T msgCnt;
  int8_T id[4];
  int32_T secMark;
  int32_T latitude;
  int32_T longitude;
  int8_T elev[2];
  int8_T accuracy[4];
  int8_T speed[2];
  int32_T heading;
  int8_T angle;
  int8_T accelSet[7];
  int8_T brakes[2];
  c5_PRESCAN_V2X_USER_BSM_size size;
};

#endif                                 /*struct_PRESCAN_V2X_USER_BSM_DATA_tag*/

#ifndef typedef_c5_PRESCAN_V2X_USER_BSM_DATA
#define typedef_c5_PRESCAN_V2X_USER_BSM_DATA

typedef struct PRESCAN_V2X_USER_BSM_DATA_tag c5_PRESCAN_V2X_USER_BSM_DATA;

#endif                                 /*typedef_c5_PRESCAN_V2X_USER_BSM_DATA*/

#include "prescan_header_data.h"
#ifndef struct_PRESCAN_V2X_USER_BSM_MESSAGE_tag
#define struct_PRESCAN_V2X_USER_BSM_MESSAGE_tag

struct PRESCAN_V2X_USER_BSM_MESSAGE_tag
{
  PRESCAN_HEADER HEADER;
  c5_PRESCAN_V2X_USER_BSM_DATA DATA;
};

#endif                                 /*struct_PRESCAN_V2X_USER_BSM_MESSAGE_tag*/

#ifndef typedef_c5_PRESCAN_V2X_USER_BSM_MESSAGE
#define typedef_c5_PRESCAN_V2X_USER_BSM_MESSAGE

typedef struct PRESCAN_V2X_USER_BSM_MESSAGE_tag c5_PRESCAN_V2X_USER_BSM_MESSAGE;

#endif                                 /*typedef_c5_PRESCAN_V2X_USER_BSM_MESSAGE*/

#include "prescan_v2x_bsm_data.h"
#ifndef typedef_SFc5_Jan22_DLforACC_csInstanceStruct
#define typedef_SFc5_Jan22_DLforACC_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c5_sfEvent;
  boolean_T c5_doneDoubleBufferReInit;
  uint8_T c5_is_active_c5_Jan22_DLforACC_cs;
  void *c5_RuntimeVar;
  uint32_T c5_mlFcnLineNumber;
  void *c5_fEmlrtCtx;
  c5_PRESCAN_V2X_USER_BSM_MESSAGE *c5_u;
  PRESCAN_V2X_FIXED_BSM_MESSAGE *c5_y;
  PRESCAN_V2X_FIXED_BSM_MESSAGE *c5_z;
} SFc5_Jan22_DLforACC_csInstanceStruct;

#endif                                 /*typedef_SFc5_Jan22_DLforACC_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c5_Jan22_DLforACC_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c5_Jan22_DLforACC_cs_get_check_sum(mxArray *plhs[]);
extern void c5_Jan22_DLforACC_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
