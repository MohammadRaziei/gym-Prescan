#ifndef __c1_Jan22_DLforACC_cs_h__
#define __c1_Jan22_DLforACC_cs_h__

/* Type Definitions */
#ifndef struct_PRESCAN_V2X_USER_BSM_size_tag
#define struct_PRESCAN_V2X_USER_BSM_size_tag

struct PRESCAN_V2X_USER_BSM_size_tag
{
  int32_T width;
  int32_T length;
};

#endif                                 /*struct_PRESCAN_V2X_USER_BSM_size_tag*/

#ifndef typedef_c1_PRESCAN_V2X_USER_BSM_size
#define typedef_c1_PRESCAN_V2X_USER_BSM_size

typedef struct PRESCAN_V2X_USER_BSM_size_tag c1_PRESCAN_V2X_USER_BSM_size;

#endif                                 /*typedef_c1_PRESCAN_V2X_USER_BSM_size*/

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
  c1_PRESCAN_V2X_USER_BSM_size size;
};

#endif                                 /*struct_PRESCAN_V2X_USER_BSM_DATA_tag*/

#ifndef typedef_c1_PRESCAN_V2X_USER_BSM_DATA
#define typedef_c1_PRESCAN_V2X_USER_BSM_DATA

typedef struct PRESCAN_V2X_USER_BSM_DATA_tag c1_PRESCAN_V2X_USER_BSM_DATA;

#endif                                 /*typedef_c1_PRESCAN_V2X_USER_BSM_DATA*/

#include "prescan_header_data.h"
#ifndef struct_PRESCAN_V2X_USER_BSM_MESSAGE_tag
#define struct_PRESCAN_V2X_USER_BSM_MESSAGE_tag

struct PRESCAN_V2X_USER_BSM_MESSAGE_tag
{
  PRESCAN_HEADER HEADER;
  c1_PRESCAN_V2X_USER_BSM_DATA DATA;
};

#endif                                 /*struct_PRESCAN_V2X_USER_BSM_MESSAGE_tag*/

#ifndef typedef_c1_PRESCAN_V2X_USER_BSM_MESSAGE
#define typedef_c1_PRESCAN_V2X_USER_BSM_MESSAGE

typedef struct PRESCAN_V2X_USER_BSM_MESSAGE_tag c1_PRESCAN_V2X_USER_BSM_MESSAGE;

#endif                                 /*typedef_c1_PRESCAN_V2X_USER_BSM_MESSAGE*/

#include "prescan_v2x_bsm_data.h"
#ifndef typedef_SFc1_Jan22_DLforACC_csInstanceStruct
#define typedef_SFc1_Jan22_DLforACC_csInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  boolean_T c1_doneDoubleBufferReInit;
  uint8_T c1_is_active_c1_Jan22_DLforACC_cs;
  void *c1_RuntimeVar;
  uint32_T c1_mlFcnLineNumber;
  void *c1_fEmlrtCtx;
  c1_PRESCAN_V2X_USER_BSM_MESSAGE *c1_u;
  PRESCAN_V2X_FIXED_BSM_MESSAGE *c1_y;
  PRESCAN_V2X_FIXED_BSM_MESSAGE *c1_z;
} SFc1_Jan22_DLforACC_csInstanceStruct;

#endif                                 /*typedef_SFc1_Jan22_DLforACC_csInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_Jan22_DLforACC_cs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c1_Jan22_DLforACC_cs_get_check_sum(mxArray *plhs[]);
extern void c1_Jan22_DLforACC_cs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
