/* Include files */

#include "Jan22_DLforACC_cs_sfun.h"
#include "c8_Jan22_DLforACC_cs.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Jan22_DLforACC_cs_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c8_debug_family_names[5] = { "nargin", "nargout", "u", "z",
  "y" };

static const char * c8_b_debug_family_names[4] = { "nargin", "nargout", "u", "y"
};

static const char * c8_c_debug_family_names[4] = { "nargin", "nargout", "u", "y"
};

static const char * c8_d_debug_family_names[4] = { "nargin", "nargout", "u", "y"
};

static const char * c8_e_debug_family_names[5] = { "nargin", "nargout", "y", "z",
  "u" };

static const char * c8_sv0[2] = { "HEADER", "DATA" };

static const char * c8_sv1[2] = { "HEADER", "DATA" };

/* Function Declarations */
static void initialize_c8_Jan22_DLforACC_cs(SFc8_Jan22_DLforACC_csInstanceStruct
  *chartInstance);
static void initialize_params_c8_Jan22_DLforACC_cs
  (SFc8_Jan22_DLforACC_csInstanceStruct *chartInstance);
static void enable_c8_Jan22_DLforACC_cs(SFc8_Jan22_DLforACC_csInstanceStruct
  *chartInstance);
static void disable_c8_Jan22_DLforACC_cs(SFc8_Jan22_DLforACC_csInstanceStruct
  *chartInstance);
static void c8_update_debugger_state_c8_Jan22_DLforACC_cs
  (SFc8_Jan22_DLforACC_csInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c8_Jan22_DLforACC_cs
  (SFc8_Jan22_DLforACC_csInstanceStruct *chartInstance);
static void set_sim_state_c8_Jan22_DLforACC_cs
  (SFc8_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c8_st);
static void finalize_c8_Jan22_DLforACC_cs(SFc8_Jan22_DLforACC_csInstanceStruct
  *chartInstance);
static void sf_gateway_c8_Jan22_DLforACC_cs(SFc8_Jan22_DLforACC_csInstanceStruct
  *chartInstance);
static void mdl_start_c8_Jan22_DLforACC_cs(SFc8_Jan22_DLforACC_csInstanceStruct *
  chartInstance);
static void initSimStructsc8_Jan22_DLforACC_cs
  (SFc8_Jan22_DLforACC_csInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber, uint32_T c8_instanceNumber);
static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData);
static real_T c8_emlrt_marshallIn(SFc8_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c8_b_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_emlrt_marshallOut(SFc8_Jan22_DLforACC_csInstanceStruct *
  chartInstance, const c8_PRESCAN_V2X_USER_GENERIC_DATA c8_b_u);
static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_b_emlrt_marshallOut
  (SFc8_Jan22_DLforACC_csInstanceStruct *chartInstance, const
   PRESCAN_V2X_FIXED_GENERIC_DATA *c8_b_u);
static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static void c8_b_emlrt_marshallIn(SFc8_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c8_b_y, const char_T *c8_identifier,
  PRESCAN_V2X_FIXED_GENERIC_MESSAGE *c8_c_y);
static void c8_c_emlrt_marshallIn(SFc8_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c8_b_u, const emlrtMsgIdentifier *c8_parentId,
  PRESCAN_V2X_FIXED_GENERIC_MESSAGE *c8_b_y);
static PRESCAN_HEADER c8_d_emlrt_marshallIn(SFc8_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c8_b_u, const emlrtMsgIdentifier *c8_parentId);
static boolean_T c8_e_emlrt_marshallIn(SFc8_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c8_b_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_f_emlrt_marshallIn(SFc8_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c8_b_u, const emlrtMsgIdentifier *c8_parentId,
  PRESCAN_V2X_FIXED_GENERIC_DATA *c8_b_y);
static int32_T c8_g_emlrt_marshallIn(SFc8_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c8_b_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_d_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_e_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static void c8_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_f_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static c8_PRESCAN_V2X_USER_GENERIC_DATA c8_h_emlrt_marshallIn
  (SFc8_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c8_b_u,
   const emlrtMsgIdentifier *c8_parentId);
static void c8_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static c8_PRESCAN_V2X_USER_GENERIC_MESSAGE c8_i_emlrt_marshallIn
  (SFc8_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c8_b_u,
   const emlrtMsgIdentifier *c8_parentId);
static void c8_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_g_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static void c8_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_u_bus_io(void *chartInstanceVoid, void *c8_pData);
static const mxArray *c8_y_bus_io(void *chartInstanceVoid, void *c8_pData);
static uint8_T c8_j_emlrt_marshallIn(SFc8_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c8_b_is_active_c8_Jan22_DLforACC_cs, const
  char_T *c8_identifier);
static uint8_T c8_k_emlrt_marshallIn(SFc8_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c8_b_u, const emlrtMsgIdentifier *c8_parentId);
static void init_dsm_address_info(SFc8_Jan22_DLforACC_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc8_Jan22_DLforACC_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c8_Jan22_DLforACC_cs(SFc8_Jan22_DLforACC_csInstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc8_Jan22_DLforACC_cs(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  sim_mode_is_external(chartInstance->S);
  chartInstance->c8_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c8_is_active_c8_Jan22_DLforACC_cs = 0U;
  setLegacyDebuggerFlagForRuntime(chartInstance->S, true);
}

static void initialize_params_c8_Jan22_DLforACC_cs
  (SFc8_Jan22_DLforACC_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c8_Jan22_DLforACC_cs(SFc8_Jan22_DLforACC_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c8_Jan22_DLforACC_cs(SFc8_Jan22_DLforACC_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c8_update_debugger_state_c8_Jan22_DLforACC_cs
  (SFc8_Jan22_DLforACC_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c8_Jan22_DLforACC_cs
  (SFc8_Jan22_DLforACC_csInstanceStruct *chartInstance)
{
  const mxArray *c8_st;
  const mxArray *c8_b_y = NULL;
  const mxArray *c8_c_y = NULL;
  PRESCAN_HEADER c8_b_u;
  const mxArray *c8_d_y = NULL;
  static const char * c8_sv2[1] = { "valid" };

  boolean_T c8_c_u;
  const mxArray *c8_e_y = NULL;
  PRESCAN_V2X_FIXED_GENERIC_DATA c8_r0;
  uint8_T c8_hoistedGlobal;
  const mxArray *c8_f_y = NULL;
  c8_st = NULL;
  c8_st = NULL;
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_createcellmatrix(2, 1), false);
  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_createstruct("structure", 2, c8_sv0, 2, 1, 1),
                false);
  c8_b_u.valid = *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)
    chartInstance->c8_y)[0])[0];
  c8_d_y = NULL;
  sf_mex_assign(&c8_d_y, sf_mex_createstruct("structure", 1, c8_sv2, 2, 1, 1),
                false);
  c8_c_u = c8_b_u.valid;
  c8_e_y = NULL;
  sf_mex_assign(&c8_e_y, sf_mex_create("y", &c8_c_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c8_d_y, 0, "valid", c8_e_y, 0);
  sf_mex_setfieldbynum(c8_c_y, 0, "HEADER", c8_d_y, 0);
  c8_r0.messageID = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c8_y)[8])[0];
  c8_r0.senderID = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c8_y)[8])[4];
  c8_r0.signal_1 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c8_y)[8])[8];
  c8_r0.signal_2 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c8_y)[8])[16];
  c8_r0.signal_3 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c8_y)[8])[24];
  c8_r0.signal_4 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c8_y)[8])[32];
  c8_r0.signal_5 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c8_y)[8])[40];
  c8_r0.signal_6 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c8_y)[8])[48];
  c8_r0.signal_7 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c8_y)[8])[56];
  c8_r0.signal_8 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c8_y)[8])[64];
  c8_r0.signal_9 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c8_y)[8])[72];
  c8_r0.signal_10 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c8_y)[8])[80];
  c8_r0.discrete_signal_1 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c8_y)[8])[88];
  c8_r0.discrete_signal_2 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c8_y)[8])[92];
  c8_r0.discrete_signal_3 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c8_y)[8])[96];
  c8_r0.discrete_signal_4 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c8_y)[8])[100];
  c8_r0.discrete_signal_5 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c8_y)[8])[104];
  c8_r0.discrete_signal_6 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c8_y)[8])[108];
  c8_r0.discrete_signal_7 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c8_y)[8])[112];
  c8_r0.discrete_signal_8 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c8_y)[8])[116];
  c8_r0.discrete_signal_9 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c8_y)[8])[120];
  c8_r0.discrete_signal_10 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c8_y)[8])[124];
  sf_mex_setfieldbynum(c8_c_y, 0, "DATA", c8_b_emlrt_marshallOut(chartInstance,
    &c8_r0), 1);
  sf_mex_setcell(c8_b_y, 0, c8_c_y);
  c8_hoistedGlobal = chartInstance->c8_is_active_c8_Jan22_DLforACC_cs;
  c8_f_y = NULL;
  sf_mex_assign(&c8_f_y, sf_mex_create("y", &c8_hoistedGlobal, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c8_b_y, 1, c8_f_y);
  sf_mex_assign(&c8_st, c8_b_y, false);
  return c8_st;
}

static void set_sim_state_c8_Jan22_DLforACC_cs
  (SFc8_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c8_st)
{
  const mxArray *c8_b_u;
  PRESCAN_V2X_FIXED_GENERIC_MESSAGE c8_r1;
  chartInstance->c8_doneDoubleBufferReInit = true;
  c8_b_u = sf_mex_dup(c8_st);
  c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_b_u, 0)),
                        "y", &c8_r1);
  *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)chartInstance->c8_y)[0])
    [0] = c8_r1.HEADER.valid;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[0] = c8_r1.DATA.messageID;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[4] = c8_r1.DATA.senderID;
  *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[8] = c8_r1.DATA.signal_1;
  *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[16] = c8_r1.DATA.signal_2;
  *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[24] = c8_r1.DATA.signal_3;
  *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[32] = c8_r1.DATA.signal_4;
  *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[40] = c8_r1.DATA.signal_5;
  *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[48] = c8_r1.DATA.signal_6;
  *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[56] = c8_r1.DATA.signal_7;
  *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[64] = c8_r1.DATA.signal_8;
  *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[72] = c8_r1.DATA.signal_9;
  *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[80] = c8_r1.DATA.signal_10;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[88] = c8_r1.DATA.discrete_signal_1;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[92] = c8_r1.DATA.discrete_signal_2;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[96] = c8_r1.DATA.discrete_signal_3;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[100] = c8_r1.DATA.discrete_signal_4;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[104] = c8_r1.DATA.discrete_signal_5;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[108] = c8_r1.DATA.discrete_signal_6;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[112] = c8_r1.DATA.discrete_signal_7;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[116] = c8_r1.DATA.discrete_signal_8;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[120] = c8_r1.DATA.discrete_signal_9;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[124] = c8_r1.DATA.discrete_signal_10;
  chartInstance->c8_is_active_c8_Jan22_DLforACC_cs = c8_j_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c8_b_u, 1)),
     "is_active_c8_Jan22_DLforACC_cs");
  sf_mex_destroy(&c8_b_u);
  c8_update_debugger_state_c8_Jan22_DLforACC_cs(chartInstance);
  sf_mex_destroy(&c8_st);
}

static void finalize_c8_Jan22_DLforACC_cs(SFc8_Jan22_DLforACC_csInstanceStruct
  *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c8_RuntimeVar);
}

static void sf_gateway_c8_Jan22_DLforACC_cs(SFc8_Jan22_DLforACC_csInstanceStruct
  *chartInstance)
{
  c8_PRESCAN_V2X_USER_GENERIC_MESSAGE c8_b_u;
  PRESCAN_V2X_FIXED_GENERIC_MESSAGE c8_b_z;
  uint32_T c8_debug_family_var_map[5];
  real_T c8_nargin = 2.0;
  real_T c8_nargout = 1.0;
  PRESCAN_V2X_FIXED_GENERIC_MESSAGE c8_b_y;
  c8_PRESCAN_V2X_USER_GENERIC_MESSAGE c8_c_y;
  PRESCAN_V2X_FIXED_GENERIC_MESSAGE c8_c_z;
  uint32_T c8_b_debug_family_var_map[5];
  real_T c8_b_nargin = 2.0;
  real_T c8_b_nargout = 1.0;
  PRESCAN_V2X_FIXED_GENERIC_MESSAGE c8_c_u;
  c8_PRESCAN_V2X_USER_GENERIC_MESSAGE c8_d_y;
  uint32_T c8_c_debug_family_var_map[4];
  real_T c8_c_nargin = 2.0;
  real_T c8_c_nargout = 1.0;
  PRESCAN_HEADER c8_d_u;
  PRESCAN_HEADER c8_e_y;
  uint32_T c8_d_debug_family_var_map[4];
  real_T c8_d_nargin = 2.0;
  real_T c8_d_nargout = 1.0;
  PRESCAN_V2X_FIXED_GENERIC_DATA c8_e_u;
  c8_PRESCAN_V2X_USER_GENERIC_DATA c8_f_y;
  uint32_T c8_e_debug_family_var_map[4];
  real_T c8_e_nargin = 2.0;
  real_T c8_e_nargout = 1.0;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5, chartInstance->c8_sfEvent);
  chartInstance->c8_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c8_sfEvent);
  c8_b_u.HEADER.valid = *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)
    chartInstance->c8_u)[0])[0];
  c8_b_u.DATA.messageID = *(int32_T *)&((char_T *)
    (c8_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)chartInstance->c8_u)[8])[0];
  c8_b_u.DATA.senderID = *(int32_T *)&((char_T *)
    (c8_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)chartInstance->c8_u)[8])[4];
  c8_b_u.DATA.signal_1 = *(real_T *)&((char_T *)
    (c8_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)chartInstance->c8_u)[8])[8];
  c8_b_u.DATA.signal_4 = *(real_T *)&((char_T *)
    (c8_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)chartInstance->c8_u)[8])[16];
  c8_b_u.DATA.signal_5 = *(real_T *)&((char_T *)
    (c8_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)chartInstance->c8_u)[8])[24];
  c8_b_u.DATA.discrete_signal_3 = *(int32_T *)&((char_T *)
    (c8_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)chartInstance->c8_u)[8])[32];
  c8_b_z.HEADER.valid = *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)
    chartInstance->c8_z)[0])[0];
  c8_b_z.DATA.messageID = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c8_z)[8])[0];
  c8_b_z.DATA.senderID = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA
    *)&((char_T *)chartInstance->c8_z)[8])[4];
  c8_b_z.DATA.signal_1 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c8_z)[8])[8];
  c8_b_z.DATA.signal_2 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c8_z)[8])[16];
  c8_b_z.DATA.signal_3 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c8_z)[8])[24];
  c8_b_z.DATA.signal_4 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c8_z)[8])[32];
  c8_b_z.DATA.signal_5 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c8_z)[8])[40];
  c8_b_z.DATA.signal_6 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c8_z)[8])[48];
  c8_b_z.DATA.signal_7 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c8_z)[8])[56];
  c8_b_z.DATA.signal_8 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c8_z)[8])[64];
  c8_b_z.DATA.signal_9 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)chartInstance->c8_z)[8])[72];
  c8_b_z.DATA.signal_10 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA
    *)&((char_T *)chartInstance->c8_z)[8])[80];
  c8_b_z.DATA.discrete_signal_1 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c8_z)[8])[88];
  c8_b_z.DATA.discrete_signal_2 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c8_z)[8])[92];
  c8_b_z.DATA.discrete_signal_3 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c8_z)[8])[96];
  c8_b_z.DATA.discrete_signal_4 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c8_z)[8])[100];
  c8_b_z.DATA.discrete_signal_5 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c8_z)[8])[104];
  c8_b_z.DATA.discrete_signal_6 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c8_z)[8])[108];
  c8_b_z.DATA.discrete_signal_7 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c8_z)[8])[112];
  c8_b_z.DATA.discrete_signal_8 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c8_z)[8])[116];
  c8_b_z.DATA.discrete_signal_9 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c8_z)[8])[120];
  c8_b_z.DATA.discrete_signal_10 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)chartInstance->c8_z)[8])[124];
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c8_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_b_u, 2U, c8_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_b_z, 3U, c8_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_y, 4U, c8_c_sf_marshallOut,
    c8_b_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_c_y = c8_b_u;
  c8_c_z = c8_b_z;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c8_e_debug_family_names,
    c8_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargin, 0U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargout, 1U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_y, 2U, c8_b_sf_marshallOut,
    c8_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_z, 3U, c8_c_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_y, 4U, c8_c_sf_marshallOut,
    c8_b_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 3);
  c8_b_y = c8_c_z;
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 4);
  c8_c_u = c8_b_y;
  c8_d_y = c8_c_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 5U, c8_d_debug_family_names,
    c8_c_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_nargin, 0U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_nargout, 1U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_u, 2U, c8_c_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_y, 3U, c8_b_sf_marshallOut,
    c8_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_y, MAX_uint32_T,
    c8_c_sf_marshallOut, c8_b_sf_marshallIn);
  c8_b_y = c8_c_u;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  CV_SCRIPT_FCN(0, 1);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_d_u = c8_b_y.HEADER;
  c8_e_y = c8_d_y.HEADER;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 5U, c8_b_debug_family_names,
    c8_d_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_nargin, 0U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_nargout, 1U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_d_u, 2U, c8_d_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_e_y, 3U, c8_d_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_y.HEADER, MAX_uint32_T,
    c8_d_sf_marshallOut, c8_c_sf_marshallIn);
  c8_b_y.HEADER = c8_d_u;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  CV_SCRIPT_FCN(0, 2);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 13);
  c8_b_y.HEADER.valid = c8_e_y.valid;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -13);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 9);
  c8_e_u = c8_b_y.DATA;
  c8_f_y = c8_d_y.DATA;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 5U, c8_c_debug_family_names,
    c8_e_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_e_nargin, 0U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_e_nargout, 1U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_e_u, 2U, c8_e_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_f_y, 3U, c8_f_sf_marshallOut,
    c8_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_y.DATA, MAX_uint32_T,
    c8_e_sf_marshallOut, c8_d_sf_marshallIn);
  c8_b_y.DATA = c8_e_u;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  CV_SCRIPT_FCN(0, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 17);
  c8_b_y.DATA.messageID = c8_f_y.messageID;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 18);
  c8_b_y.DATA.senderID = c8_f_y.senderID;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 19);
  c8_b_y.DATA.signal_1 = c8_f_y.signal_1;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 20);
  c8_b_y.DATA.signal_4 = c8_f_y.signal_4;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 21);
  c8_b_y.DATA.signal_5 = c8_f_y.signal_5;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, 22);
  c8_b_y.DATA.discrete_signal_3 = c8_f_y.discrete_signal_3;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -22);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -9);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SCRIPT_CALL(0U, chartInstance->c8_sfEvent, -4);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, -4);
  _SFD_SYMBOL_SCOPE_POP();
  *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)chartInstance->c8_y)[0])
    [0] = c8_b_y.HEADER.valid;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[0] = c8_b_y.DATA.messageID;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[4] = c8_b_y.DATA.senderID;
  *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[8] = c8_b_y.DATA.signal_1;
  *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[16] = c8_b_y.DATA.signal_2;
  *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[24] = c8_b_y.DATA.signal_3;
  *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[32] = c8_b_y.DATA.signal_4;
  *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[40] = c8_b_y.DATA.signal_5;
  *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[48] = c8_b_y.DATA.signal_6;
  *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[56] = c8_b_y.DATA.signal_7;
  *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[64] = c8_b_y.DATA.signal_8;
  *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[72] = c8_b_y.DATA.signal_9;
  *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[80] = c8_b_y.DATA.signal_10;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[88] = c8_b_y.DATA.discrete_signal_1;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[92] = c8_b_y.DATA.discrete_signal_2;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[96] = c8_b_y.DATA.discrete_signal_3;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[100] = c8_b_y.DATA.discrete_signal_4;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[104] = c8_b_y.DATA.discrete_signal_5;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[108] = c8_b_y.DATA.discrete_signal_6;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[112] = c8_b_y.DATA.discrete_signal_7;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[116] = c8_b_y.DATA.discrete_signal_8;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[120] = c8_b_y.DATA.discrete_signal_9;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    chartInstance->c8_y)[8])[124] = c8_b_y.DATA.discrete_signal_10;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c8_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
}

static void mdl_start_c8_Jan22_DLforACC_cs(SFc8_Jan22_DLforACC_csInstanceStruct *
  chartInstance)
{
  chartInstance->c8_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sim_mode_is_external(chartInstance->S);
}

static void initSimStructsc8_Jan22_DLforACC_cs
  (SFc8_Jan22_DLforACC_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber, uint32_T c8_instanceNumber)
{
  (void)(c8_machineNumber);
  (void)(c8_chartNumber);
  (void)(c8_instanceNumber);
  _SFD_SCRIPT_TRANSLATION(c8_chartNumber, c8_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\s2lohras\\PreScan_Experiments\\Jan22_DLforACC\\V2X_GENERIC_expander.m"));
}

static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData)
{
  const mxArray *c8_mxArrayOutData;
  real_T c8_b_u;
  const mxArray *c8_b_y = NULL;
  SFc8_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc8_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_mxArrayOutData = NULL;
  c8_b_u = *(real_T *)c8_inData;
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_b_y, false);
  return c8_mxArrayOutData;
}

static real_T c8_emlrt_marshallIn(SFc8_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c8_b_u, const emlrtMsgIdentifier *c8_parentId)
{
  real_T c8_b_y;
  real_T c8_d0;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_b_u), &c8_d0, 1, 0, 0U, 0, 0U, 0);
  c8_b_y = c8_d0;
  sf_mex_destroy(&c8_b_u);
  return c8_b_y;
}

static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_nargin;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_b_y;
  SFc8_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc8_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c8_nargin = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = (const char *)c8_identifier;
  c8_thisId.fParent = NULL;
  c8_thisId.bParentIsCell = false;
  c8_b_y = c8_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_nargin), &c8_thisId);
  sf_mex_destroy(&c8_nargin);
  *(real_T *)c8_outData = c8_b_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_emlrt_marshallOut(SFc8_Jan22_DLforACC_csInstanceStruct *
  chartInstance, const c8_PRESCAN_V2X_USER_GENERIC_DATA c8_b_u)
{
  const mxArray *c8_b_y;
  static const char * c8_sv3[6] = { "messageID", "senderID", "signal_1",
    "signal_4", "signal_5", "discrete_signal_3" };

  int32_T c8_c_u;
  const mxArray *c8_c_y = NULL;
  int32_T c8_d_u;
  const mxArray *c8_d_y = NULL;
  real_T c8_e_u;
  const mxArray *c8_e_y = NULL;
  real_T c8_f_u;
  const mxArray *c8_f_y = NULL;
  real_T c8_g_u;
  const mxArray *c8_g_y = NULL;
  int32_T c8_h_u;
  const mxArray *c8_h_y = NULL;
  (void)chartInstance;
  c8_b_y = NULL;
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_createstruct("structure", 6, c8_sv3, 2, 1, 1),
                false);
  c8_c_u = c8_b_u.messageID;
  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y", &c8_c_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c8_b_y, 0, "messageID", c8_c_y, 0);
  c8_d_u = c8_b_u.senderID;
  c8_d_y = NULL;
  sf_mex_assign(&c8_d_y, sf_mex_create("y", &c8_d_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c8_b_y, 0, "senderID", c8_d_y, 1);
  c8_e_u = c8_b_u.signal_1;
  c8_e_y = NULL;
  sf_mex_assign(&c8_e_y, sf_mex_create("y", &c8_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c8_b_y, 0, "signal_1", c8_e_y, 2);
  c8_f_u = c8_b_u.signal_4;
  c8_f_y = NULL;
  sf_mex_assign(&c8_f_y, sf_mex_create("y", &c8_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c8_b_y, 0, "signal_4", c8_f_y, 3);
  c8_g_u = c8_b_u.signal_5;
  c8_g_y = NULL;
  sf_mex_assign(&c8_g_y, sf_mex_create("y", &c8_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c8_b_y, 0, "signal_5", c8_g_y, 4);
  c8_h_u = c8_b_u.discrete_signal_3;
  c8_h_y = NULL;
  sf_mex_assign(&c8_h_y, sf_mex_create("y", &c8_h_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c8_b_y, 0, "discrete_signal_3", c8_h_y, 5);
  return c8_b_y;
}

static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData;
  c8_PRESCAN_V2X_USER_GENERIC_MESSAGE c8_b_u;
  const mxArray *c8_b_y = NULL;
  PRESCAN_HEADER c8_c_u;
  const mxArray *c8_c_y = NULL;
  static const char * c8_sv4[1] = { "valid" };

  boolean_T c8_d_u;
  const mxArray *c8_d_y = NULL;
  SFc8_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc8_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_mxArrayOutData = NULL;
  c8_b_u = *(c8_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c8_inData;
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_createstruct("structure", 2, c8_sv0, 2, 1, 1),
                false);
  c8_c_u = c8_b_u.HEADER;
  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_createstruct("structure", 1, c8_sv4, 2, 1, 1),
                false);
  c8_d_u = c8_c_u.valid;
  c8_d_y = NULL;
  sf_mex_assign(&c8_d_y, sf_mex_create("y", &c8_d_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c8_c_y, 0, "valid", c8_d_y, 0);
  sf_mex_setfieldbynum(c8_b_y, 0, "HEADER", c8_c_y, 0);
  sf_mex_setfieldbynum(c8_b_y, 0, "DATA", c8_emlrt_marshallOut(chartInstance,
    c8_b_u.DATA), 1);
  sf_mex_assign(&c8_mxArrayOutData, c8_b_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_b_emlrt_marshallOut
  (SFc8_Jan22_DLforACC_csInstanceStruct *chartInstance, const
   PRESCAN_V2X_FIXED_GENERIC_DATA *c8_b_u)
{
  const mxArray *c8_b_y;
  static const char * c8_sv5[22] = { "messageID", "senderID", "signal_1",
    "signal_2", "signal_3", "signal_4", "signal_5", "signal_6", "signal_7",
    "signal_8", "signal_9", "signal_10", "discrete_signal_1",
    "discrete_signal_2", "discrete_signal_3", "discrete_signal_4",
    "discrete_signal_5", "discrete_signal_6", "discrete_signal_7",
    "discrete_signal_8", "discrete_signal_9", "discrete_signal_10" };

  int32_T c8_c_u;
  const mxArray *c8_c_y = NULL;
  int32_T c8_d_u;
  const mxArray *c8_d_y = NULL;
  real_T c8_e_u;
  const mxArray *c8_e_y = NULL;
  real_T c8_f_u;
  const mxArray *c8_f_y = NULL;
  real_T c8_g_u;
  const mxArray *c8_g_y = NULL;
  real_T c8_h_u;
  const mxArray *c8_h_y = NULL;
  real_T c8_i_u;
  const mxArray *c8_i_y = NULL;
  real_T c8_j_u;
  const mxArray *c8_j_y = NULL;
  real_T c8_k_u;
  const mxArray *c8_k_y = NULL;
  real_T c8_l_u;
  const mxArray *c8_l_y = NULL;
  real_T c8_m_u;
  const mxArray *c8_m_y = NULL;
  real_T c8_n_u;
  const mxArray *c8_n_y = NULL;
  int32_T c8_o_u;
  const mxArray *c8_o_y = NULL;
  int32_T c8_p_u;
  const mxArray *c8_p_y = NULL;
  int32_T c8_q_u;
  const mxArray *c8_q_y = NULL;
  int32_T c8_r_u;
  const mxArray *c8_r_y = NULL;
  int32_T c8_s_u;
  const mxArray *c8_s_y = NULL;
  int32_T c8_t_u;
  const mxArray *c8_t_y = NULL;
  int32_T c8_u_u;
  const mxArray *c8_u_y = NULL;
  int32_T c8_v_u;
  const mxArray *c8_v_y = NULL;
  int32_T c8_w_u;
  const mxArray *c8_w_y = NULL;
  int32_T c8_x_u;
  const mxArray *c8_x_y = NULL;
  (void)chartInstance;
  c8_b_y = NULL;
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_createstruct("structure", 22, c8_sv5, 2, 1, 1),
                false);
  c8_c_u = c8_b_u->messageID;
  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y", &c8_c_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c8_b_y, 0, "messageID", c8_c_y, 0);
  c8_d_u = c8_b_u->senderID;
  c8_d_y = NULL;
  sf_mex_assign(&c8_d_y, sf_mex_create("y", &c8_d_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c8_b_y, 0, "senderID", c8_d_y, 1);
  c8_e_u = c8_b_u->signal_1;
  c8_e_y = NULL;
  sf_mex_assign(&c8_e_y, sf_mex_create("y", &c8_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c8_b_y, 0, "signal_1", c8_e_y, 2);
  c8_f_u = c8_b_u->signal_2;
  c8_f_y = NULL;
  sf_mex_assign(&c8_f_y, sf_mex_create("y", &c8_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c8_b_y, 0, "signal_2", c8_f_y, 3);
  c8_g_u = c8_b_u->signal_3;
  c8_g_y = NULL;
  sf_mex_assign(&c8_g_y, sf_mex_create("y", &c8_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c8_b_y, 0, "signal_3", c8_g_y, 4);
  c8_h_u = c8_b_u->signal_4;
  c8_h_y = NULL;
  sf_mex_assign(&c8_h_y, sf_mex_create("y", &c8_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c8_b_y, 0, "signal_4", c8_h_y, 5);
  c8_i_u = c8_b_u->signal_5;
  c8_i_y = NULL;
  sf_mex_assign(&c8_i_y, sf_mex_create("y", &c8_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c8_b_y, 0, "signal_5", c8_i_y, 6);
  c8_j_u = c8_b_u->signal_6;
  c8_j_y = NULL;
  sf_mex_assign(&c8_j_y, sf_mex_create("y", &c8_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c8_b_y, 0, "signal_6", c8_j_y, 7);
  c8_k_u = c8_b_u->signal_7;
  c8_k_y = NULL;
  sf_mex_assign(&c8_k_y, sf_mex_create("y", &c8_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c8_b_y, 0, "signal_7", c8_k_y, 8);
  c8_l_u = c8_b_u->signal_8;
  c8_l_y = NULL;
  sf_mex_assign(&c8_l_y, sf_mex_create("y", &c8_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c8_b_y, 0, "signal_8", c8_l_y, 9);
  c8_m_u = c8_b_u->signal_9;
  c8_m_y = NULL;
  sf_mex_assign(&c8_m_y, sf_mex_create("y", &c8_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c8_b_y, 0, "signal_9", c8_m_y, 10);
  c8_n_u = c8_b_u->signal_10;
  c8_n_y = NULL;
  sf_mex_assign(&c8_n_y, sf_mex_create("y", &c8_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c8_b_y, 0, "signal_10", c8_n_y, 11);
  c8_o_u = c8_b_u->discrete_signal_1;
  c8_o_y = NULL;
  sf_mex_assign(&c8_o_y, sf_mex_create("y", &c8_o_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c8_b_y, 0, "discrete_signal_1", c8_o_y, 12);
  c8_p_u = c8_b_u->discrete_signal_2;
  c8_p_y = NULL;
  sf_mex_assign(&c8_p_y, sf_mex_create("y", &c8_p_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c8_b_y, 0, "discrete_signal_2", c8_p_y, 13);
  c8_q_u = c8_b_u->discrete_signal_3;
  c8_q_y = NULL;
  sf_mex_assign(&c8_q_y, sf_mex_create("y", &c8_q_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c8_b_y, 0, "discrete_signal_3", c8_q_y, 14);
  c8_r_u = c8_b_u->discrete_signal_4;
  c8_r_y = NULL;
  sf_mex_assign(&c8_r_y, sf_mex_create("y", &c8_r_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c8_b_y, 0, "discrete_signal_4", c8_r_y, 15);
  c8_s_u = c8_b_u->discrete_signal_5;
  c8_s_y = NULL;
  sf_mex_assign(&c8_s_y, sf_mex_create("y", &c8_s_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c8_b_y, 0, "discrete_signal_5", c8_s_y, 16);
  c8_t_u = c8_b_u->discrete_signal_6;
  c8_t_y = NULL;
  sf_mex_assign(&c8_t_y, sf_mex_create("y", &c8_t_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c8_b_y, 0, "discrete_signal_6", c8_t_y, 17);
  c8_u_u = c8_b_u->discrete_signal_7;
  c8_u_y = NULL;
  sf_mex_assign(&c8_u_y, sf_mex_create("y", &c8_u_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c8_b_y, 0, "discrete_signal_7", c8_u_y, 18);
  c8_v_u = c8_b_u->discrete_signal_8;
  c8_v_y = NULL;
  sf_mex_assign(&c8_v_y, sf_mex_create("y", &c8_v_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c8_b_y, 0, "discrete_signal_8", c8_v_y, 19);
  c8_w_u = c8_b_u->discrete_signal_9;
  c8_w_y = NULL;
  sf_mex_assign(&c8_w_y, sf_mex_create("y", &c8_w_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c8_b_y, 0, "discrete_signal_9", c8_w_y, 20);
  c8_x_u = c8_b_u->discrete_signal_10;
  c8_x_y = NULL;
  sf_mex_assign(&c8_x_y, sf_mex_create("y", &c8_x_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c8_b_y, 0, "discrete_signal_10", c8_x_y, 21);
  return c8_b_y;
}

static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData;
  PRESCAN_V2X_FIXED_GENERIC_MESSAGE c8_b_u;
  const mxArray *c8_b_y = NULL;
  PRESCAN_HEADER c8_c_u;
  const mxArray *c8_c_y = NULL;
  static const char * c8_sv6[1] = { "valid" };

  boolean_T c8_d_u;
  const mxArray *c8_d_y = NULL;
  SFc8_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc8_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_mxArrayOutData = NULL;
  c8_b_u = *(PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c8_inData;
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_createstruct("structure", 2, c8_sv0, 2, 1, 1),
                false);
  c8_c_u = c8_b_u.HEADER;
  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_createstruct("structure", 1, c8_sv6, 2, 1, 1),
                false);
  c8_d_u = c8_c_u.valid;
  c8_d_y = NULL;
  sf_mex_assign(&c8_d_y, sf_mex_create("y", &c8_d_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c8_c_y, 0, "valid", c8_d_y, 0);
  sf_mex_setfieldbynum(c8_b_y, 0, "HEADER", c8_c_y, 0);
  sf_mex_setfieldbynum(c8_b_y, 0, "DATA", c8_b_emlrt_marshallOut(chartInstance,
    &c8_b_u.DATA), 1);
  sf_mex_assign(&c8_mxArrayOutData, c8_b_y, false);
  return c8_mxArrayOutData;
}

static void c8_b_emlrt_marshallIn(SFc8_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c8_b_y, const char_T *c8_identifier,
  PRESCAN_V2X_FIXED_GENERIC_MESSAGE *c8_c_y)
{
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = (const char *)c8_identifier;
  c8_thisId.fParent = NULL;
  c8_thisId.bParentIsCell = false;
  c8_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_y), &c8_thisId, c8_c_y);
  sf_mex_destroy(&c8_b_y);
}

static void c8_c_emlrt_marshallIn(SFc8_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c8_b_u, const emlrtMsgIdentifier *c8_parentId,
  PRESCAN_V2X_FIXED_GENERIC_MESSAGE *c8_b_y)
{
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fParent = c8_parentId;
  c8_thisId.bParentIsCell = false;
  sf_mex_check_struct(c8_parentId, c8_b_u, 2, c8_sv1, 0U, NULL);
  c8_thisId.fIdentifier = "HEADER";
  c8_b_y->HEADER = c8_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_b_u, "HEADER", "HEADER", 0)), &c8_thisId);
  c8_thisId.fIdentifier = "DATA";
  c8_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c8_b_u, "DATA",
    "DATA", 0)), &c8_thisId, &c8_b_y->DATA);
  sf_mex_destroy(&c8_b_u);
}

static PRESCAN_HEADER c8_d_emlrt_marshallIn(SFc8_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c8_b_u, const emlrtMsgIdentifier *c8_parentId)
{
  PRESCAN_HEADER c8_b_y;
  emlrtMsgIdentifier c8_thisId;
  static const char * c8_fieldNames[1] = { "valid" };

  c8_thisId.fParent = c8_parentId;
  c8_thisId.bParentIsCell = false;
  sf_mex_check_struct(c8_parentId, c8_b_u, 1, c8_fieldNames, 0U, NULL);
  c8_thisId.fIdentifier = "valid";
  c8_b_y.valid = c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c8_b_u, "valid", "valid", 0)), &c8_thisId);
  sf_mex_destroy(&c8_b_u);
  return c8_b_y;
}

static boolean_T c8_e_emlrt_marshallIn(SFc8_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c8_b_u, const emlrtMsgIdentifier *c8_parentId)
{
  boolean_T c8_b_y;
  boolean_T c8_b0;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_b_u), &c8_b0, 1, 11, 0U, 0, 0U, 0);
  c8_b_y = c8_b0;
  sf_mex_destroy(&c8_b_u);
  return c8_b_y;
}

static void c8_f_emlrt_marshallIn(SFc8_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c8_b_u, const emlrtMsgIdentifier *c8_parentId,
  PRESCAN_V2X_FIXED_GENERIC_DATA *c8_b_y)
{
  emlrtMsgIdentifier c8_thisId;
  static const char * c8_fieldNames[22] = { "messageID", "senderID", "signal_1",
    "signal_2", "signal_3", "signal_4", "signal_5", "signal_6", "signal_7",
    "signal_8", "signal_9", "signal_10", "discrete_signal_1",
    "discrete_signal_2", "discrete_signal_3", "discrete_signal_4",
    "discrete_signal_5", "discrete_signal_6", "discrete_signal_7",
    "discrete_signal_8", "discrete_signal_9", "discrete_signal_10" };

  c8_thisId.fParent = c8_parentId;
  c8_thisId.bParentIsCell = false;
  sf_mex_check_struct(c8_parentId, c8_b_u, 22, c8_fieldNames, 0U, NULL);
  c8_thisId.fIdentifier = "messageID";
  c8_b_y->messageID = c8_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_b_u, "messageID", "messageID", 0)), &c8_thisId);
  c8_thisId.fIdentifier = "senderID";
  c8_b_y->senderID = c8_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_b_u, "senderID", "senderID", 0)), &c8_thisId);
  c8_thisId.fIdentifier = "signal_1";
  c8_b_y->signal_1 = c8_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_b_u, "signal_1", "signal_1", 0)), &c8_thisId);
  c8_thisId.fIdentifier = "signal_2";
  c8_b_y->signal_2 = c8_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_b_u, "signal_2", "signal_2", 0)), &c8_thisId);
  c8_thisId.fIdentifier = "signal_3";
  c8_b_y->signal_3 = c8_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_b_u, "signal_3", "signal_3", 0)), &c8_thisId);
  c8_thisId.fIdentifier = "signal_4";
  c8_b_y->signal_4 = c8_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_b_u, "signal_4", "signal_4", 0)), &c8_thisId);
  c8_thisId.fIdentifier = "signal_5";
  c8_b_y->signal_5 = c8_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_b_u, "signal_5", "signal_5", 0)), &c8_thisId);
  c8_thisId.fIdentifier = "signal_6";
  c8_b_y->signal_6 = c8_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_b_u, "signal_6", "signal_6", 0)), &c8_thisId);
  c8_thisId.fIdentifier = "signal_7";
  c8_b_y->signal_7 = c8_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_b_u, "signal_7", "signal_7", 0)), &c8_thisId);
  c8_thisId.fIdentifier = "signal_8";
  c8_b_y->signal_8 = c8_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_b_u, "signal_8", "signal_8", 0)), &c8_thisId);
  c8_thisId.fIdentifier = "signal_9";
  c8_b_y->signal_9 = c8_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_b_u, "signal_9", "signal_9", 0)), &c8_thisId);
  c8_thisId.fIdentifier = "signal_10";
  c8_b_y->signal_10 = c8_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_b_u, "signal_10", "signal_10", 0)), &c8_thisId);
  c8_thisId.fIdentifier = "discrete_signal_1";
  c8_b_y->discrete_signal_1 = c8_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_b_u, "discrete_signal_1", "discrete_signal_1", 0)),
    &c8_thisId);
  c8_thisId.fIdentifier = "discrete_signal_2";
  c8_b_y->discrete_signal_2 = c8_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_b_u, "discrete_signal_2", "discrete_signal_2", 0)),
    &c8_thisId);
  c8_thisId.fIdentifier = "discrete_signal_3";
  c8_b_y->discrete_signal_3 = c8_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_b_u, "discrete_signal_3", "discrete_signal_3", 0)),
    &c8_thisId);
  c8_thisId.fIdentifier = "discrete_signal_4";
  c8_b_y->discrete_signal_4 = c8_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_b_u, "discrete_signal_4", "discrete_signal_4", 0)),
    &c8_thisId);
  c8_thisId.fIdentifier = "discrete_signal_5";
  c8_b_y->discrete_signal_5 = c8_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_b_u, "discrete_signal_5", "discrete_signal_5", 0)),
    &c8_thisId);
  c8_thisId.fIdentifier = "discrete_signal_6";
  c8_b_y->discrete_signal_6 = c8_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_b_u, "discrete_signal_6", "discrete_signal_6", 0)),
    &c8_thisId);
  c8_thisId.fIdentifier = "discrete_signal_7";
  c8_b_y->discrete_signal_7 = c8_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_b_u, "discrete_signal_7", "discrete_signal_7", 0)),
    &c8_thisId);
  c8_thisId.fIdentifier = "discrete_signal_8";
  c8_b_y->discrete_signal_8 = c8_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_b_u, "discrete_signal_8", "discrete_signal_8", 0)),
    &c8_thisId);
  c8_thisId.fIdentifier = "discrete_signal_9";
  c8_b_y->discrete_signal_9 = c8_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_b_u, "discrete_signal_9", "discrete_signal_9", 0)),
    &c8_thisId);
  c8_thisId.fIdentifier = "discrete_signal_10";
  c8_b_y->discrete_signal_10 = c8_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_b_u, "discrete_signal_10", "discrete_signal_10", 0)),
    &c8_thisId);
  sf_mex_destroy(&c8_b_u);
}

static int32_T c8_g_emlrt_marshallIn(SFc8_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c8_b_u, const emlrtMsgIdentifier *c8_parentId)
{
  int32_T c8_b_y;
  int32_T c8_i0;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_b_u), &c8_i0, 1, 6, 0U, 0, 0U, 0);
  c8_b_y = c8_i0;
  sf_mex_destroy(&c8_b_u);
  return c8_b_y;
}

static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_y;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  PRESCAN_V2X_FIXED_GENERIC_MESSAGE c8_c_y;
  SFc8_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc8_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c8_b_y = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = (const char *)c8_identifier;
  c8_thisId.fParent = NULL;
  c8_thisId.bParentIsCell = false;
  c8_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_y), &c8_thisId, &c8_c_y);
  sf_mex_destroy(&c8_b_y);
  *(PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c8_outData = c8_c_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_d_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData;
  PRESCAN_HEADER c8_b_u;
  const mxArray *c8_b_y = NULL;
  static const char * c8_sv7[1] = { "valid" };

  boolean_T c8_c_u;
  const mxArray *c8_c_y = NULL;
  SFc8_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc8_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_mxArrayOutData = NULL;
  c8_b_u = *(PRESCAN_HEADER *)c8_inData;
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_createstruct("structure", 1, c8_sv7, 2, 1, 1),
                false);
  c8_c_u = c8_b_u.valid;
  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y", &c8_c_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c8_b_y, 0, "valid", c8_c_y, 0);
  sf_mex_assign(&c8_mxArrayOutData, c8_b_y, false);
  return c8_mxArrayOutData;
}

static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_u;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  PRESCAN_HEADER c8_b_y;
  SFc8_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc8_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c8_b_u = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = (const char *)c8_identifier;
  c8_thisId.fParent = NULL;
  c8_thisId.bParentIsCell = false;
  c8_b_y = c8_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_u), &c8_thisId);
  sf_mex_destroy(&c8_b_u);
  *(PRESCAN_HEADER *)c8_outData = c8_b_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_e_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  SFc8_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc8_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  sf_mex_assign(&c8_mxArrayOutData, c8_b_emlrt_marshallOut(chartInstance,
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)c8_inData), false);
  return c8_mxArrayOutData;
}

static void c8_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_u;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  PRESCAN_V2X_FIXED_GENERIC_DATA c8_b_y;
  SFc8_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc8_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c8_b_u = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = (const char *)c8_identifier;
  c8_thisId.fParent = NULL;
  c8_thisId.bParentIsCell = false;
  c8_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_u), &c8_thisId, &c8_b_y);
  sf_mex_destroy(&c8_b_u);
  *(PRESCAN_V2X_FIXED_GENERIC_DATA *)c8_outData = c8_b_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_f_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  SFc8_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc8_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  sf_mex_assign(&c8_mxArrayOutData, c8_emlrt_marshallOut(chartInstance,
    *(c8_PRESCAN_V2X_USER_GENERIC_DATA *)c8_inData), false);
  return c8_mxArrayOutData;
}

static c8_PRESCAN_V2X_USER_GENERIC_DATA c8_h_emlrt_marshallIn
  (SFc8_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c8_b_u,
   const emlrtMsgIdentifier *c8_parentId)
{
  c8_PRESCAN_V2X_USER_GENERIC_DATA c8_b_y;
  emlrtMsgIdentifier c8_thisId;
  static const char * c8_fieldNames[6] = { "messageID", "senderID", "signal_1",
    "signal_4", "signal_5", "discrete_signal_3" };

  c8_thisId.fParent = c8_parentId;
  c8_thisId.bParentIsCell = false;
  sf_mex_check_struct(c8_parentId, c8_b_u, 6, c8_fieldNames, 0U, NULL);
  c8_thisId.fIdentifier = "messageID";
  c8_b_y.messageID = c8_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_b_u, "messageID", "messageID", 0)), &c8_thisId);
  c8_thisId.fIdentifier = "senderID";
  c8_b_y.senderID = c8_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_b_u, "senderID", "senderID", 0)), &c8_thisId);
  c8_thisId.fIdentifier = "signal_1";
  c8_b_y.signal_1 = c8_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_b_u, "signal_1", "signal_1", 0)), &c8_thisId);
  c8_thisId.fIdentifier = "signal_4";
  c8_b_y.signal_4 = c8_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_b_u, "signal_4", "signal_4", 0)), &c8_thisId);
  c8_thisId.fIdentifier = "signal_5";
  c8_b_y.signal_5 = c8_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_b_u, "signal_5", "signal_5", 0)), &c8_thisId);
  c8_thisId.fIdentifier = "discrete_signal_3";
  c8_b_y.discrete_signal_3 = c8_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_b_u, "discrete_signal_3", "discrete_signal_3", 0)),
    &c8_thisId);
  sf_mex_destroy(&c8_b_u);
  return c8_b_y;
}

static void c8_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_y;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  c8_PRESCAN_V2X_USER_GENERIC_DATA c8_c_y;
  SFc8_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc8_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c8_b_y = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = (const char *)c8_identifier;
  c8_thisId.fParent = NULL;
  c8_thisId.bParentIsCell = false;
  c8_c_y = c8_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_y), &c8_thisId);
  sf_mex_destroy(&c8_b_y);
  *(c8_PRESCAN_V2X_USER_GENERIC_DATA *)c8_outData = c8_c_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static c8_PRESCAN_V2X_USER_GENERIC_MESSAGE c8_i_emlrt_marshallIn
  (SFc8_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c8_b_u,
   const emlrtMsgIdentifier *c8_parentId)
{
  c8_PRESCAN_V2X_USER_GENERIC_MESSAGE c8_b_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fParent = c8_parentId;
  c8_thisId.bParentIsCell = false;
  sf_mex_check_struct(c8_parentId, c8_b_u, 2, c8_sv1, 0U, NULL);
  c8_thisId.fIdentifier = "HEADER";
  c8_b_y.HEADER = c8_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c8_b_u, "HEADER", "HEADER", 0)), &c8_thisId);
  c8_thisId.fIdentifier = "DATA";
  c8_b_y.DATA = c8_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c8_b_u, "DATA", "DATA", 0)), &c8_thisId);
  sf_mex_destroy(&c8_b_u);
  return c8_b_y;
}

static void c8_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_y;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  c8_PRESCAN_V2X_USER_GENERIC_MESSAGE c8_c_y;
  SFc8_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc8_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c8_b_y = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = (const char *)c8_identifier;
  c8_thisId.fParent = NULL;
  c8_thisId.bParentIsCell = false;
  c8_c_y = c8_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_y), &c8_thisId);
  sf_mex_destroy(&c8_b_y);
  *(c8_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c8_outData = c8_c_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

const mxArray *sf_c8_Jan22_DLforACC_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c8_nameCaptureInfo = NULL;
  const char * c8_data[4] = {
    "789c6360f4f465646060e003626620dec0c60006bc108a41004a3331a0027479461c340cb032b0a0e883c9cf81d2c9f97925a91525104e4e665eaa5f696e526a"
    "11909397989b0a3726253f37332f31af24a4b22095a128b5383fa72c35052c939699931a92999bea938fc4f1c8047272dd90a4e01c901488ed9c919a9c1d5c9a",
    "cb5094518c706e0e328701297c1270f89f8540f8a003f4f0415747c83e3602f6118a0f4e060e64db1d60f655e0308f90ff60e68be0b04f004d3ecc2822deddd5"
    "cf35c8d3393eb5a220312f051cd9148733cc5e36343ec21d1099e292a2d2e412a4744fa17d7e38ed43958f768d75b6d20f2d4e2d2ad62f36cac9cf284a2cd60f",
    "284a0d4e4ecc8b77ad28482d02a6cdbc92627dafc43c23a378179fb4fc224767677d6ce1a5974bcf74d2c07f5ee2ba237dd325bdf3c1c0d94769be13c3619f00"
    "9a7c549447807968794872b1b1bf936151b877557a50b813c21d0104ec21e40e061c7c5a9b0f00709d6421",
    "" };

  c8_nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(c8_data, 1736U, &c8_nameCaptureInfo);
  return c8_nameCaptureInfo;
}

static const mxArray *c8_g_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData;
  int32_T c8_b_u;
  const mxArray *c8_b_y = NULL;
  SFc8_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc8_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_mxArrayOutData = NULL;
  c8_b_u = *(int32_T *)c8_inData;
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_b_y, false);
  return c8_mxArrayOutData;
}

static void c8_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_sfEvent;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  int32_T c8_b_y;
  SFc8_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc8_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c8_b_sfEvent = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = (const char *)c8_identifier;
  c8_thisId.fParent = NULL;
  c8_thisId.bParentIsCell = false;
  c8_b_y = c8_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_sfEvent),
    &c8_thisId);
  sf_mex_destroy(&c8_b_sfEvent);
  *(int32_T *)c8_outData = c8_b_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_u_bus_io(void *chartInstanceVoid, void *c8_pData)
{
  const mxArray *c8_mxVal = NULL;
  c8_PRESCAN_V2X_USER_GENERIC_MESSAGE c8_tmp;
  SFc8_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc8_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c8_mxVal = NULL;
  c8_tmp.HEADER.valid = *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)
    (c8_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c8_pData)[0])[0];
  c8_tmp.DATA.messageID = *(int32_T *)&((char_T *)
    (c8_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    (c8_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c8_pData)[8])[0];
  c8_tmp.DATA.senderID = *(int32_T *)&((char_T *)
    (c8_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    (c8_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c8_pData)[8])[4];
  c8_tmp.DATA.signal_1 = *(real_T *)&((char_T *)
    (c8_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    (c8_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c8_pData)[8])[8];
  c8_tmp.DATA.signal_4 = *(real_T *)&((char_T *)
    (c8_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    (c8_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c8_pData)[8])[16];
  c8_tmp.DATA.signal_5 = *(real_T *)&((char_T *)
    (c8_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    (c8_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c8_pData)[8])[24];
  c8_tmp.DATA.discrete_signal_3 = *(int32_T *)&((char_T *)
    (c8_PRESCAN_V2X_USER_GENERIC_DATA *)&((char_T *)
    (c8_PRESCAN_V2X_USER_GENERIC_MESSAGE *)c8_pData)[8])[32];
  sf_mex_assign(&c8_mxVal, c8_b_sf_marshallOut(chartInstance, &c8_tmp), false);
  return c8_mxVal;
}

static const mxArray *c8_y_bus_io(void *chartInstanceVoid, void *c8_pData)
{
  const mxArray *c8_mxVal = NULL;
  PRESCAN_V2X_FIXED_GENERIC_MESSAGE c8_tmp;
  SFc8_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc8_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c8_mxVal = NULL;
  c8_tmp.HEADER.valid = *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c8_pData)[0])[0];
  c8_tmp.DATA.messageID = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c8_pData)[8])[0];
  c8_tmp.DATA.senderID = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA
    *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c8_pData)[8])[4];
  c8_tmp.DATA.signal_1 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c8_pData)[8])[8];
  c8_tmp.DATA.signal_2 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c8_pData)[8])[16];
  c8_tmp.DATA.signal_3 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c8_pData)[8])[24];
  c8_tmp.DATA.signal_4 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c8_pData)[8])[32];
  c8_tmp.DATA.signal_5 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c8_pData)[8])[40];
  c8_tmp.DATA.signal_6 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c8_pData)[8])[48];
  c8_tmp.DATA.signal_7 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c8_pData)[8])[56];
  c8_tmp.DATA.signal_8 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c8_pData)[8])[64];
  c8_tmp.DATA.signal_9 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c8_pData)[8])[72];
  c8_tmp.DATA.signal_10 = *(real_T *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_DATA
    *)&((char_T *)(PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c8_pData)[8])[80];
  c8_tmp.DATA.discrete_signal_1 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c8_pData)[8])[88];
  c8_tmp.DATA.discrete_signal_2 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c8_pData)[8])[92];
  c8_tmp.DATA.discrete_signal_3 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c8_pData)[8])[96];
  c8_tmp.DATA.discrete_signal_4 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c8_pData)[8])[100];
  c8_tmp.DATA.discrete_signal_5 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c8_pData)[8])[104];
  c8_tmp.DATA.discrete_signal_6 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c8_pData)[8])[108];
  c8_tmp.DATA.discrete_signal_7 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c8_pData)[8])[112];
  c8_tmp.DATA.discrete_signal_8 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c8_pData)[8])[116];
  c8_tmp.DATA.discrete_signal_9 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c8_pData)[8])[120];
  c8_tmp.DATA.discrete_signal_10 = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)c8_pData)[8])[124];
  sf_mex_assign(&c8_mxVal, c8_c_sf_marshallOut(chartInstance, &c8_tmp), false);
  return c8_mxVal;
}

static uint8_T c8_j_emlrt_marshallIn(SFc8_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c8_b_is_active_c8_Jan22_DLforACC_cs, const
  char_T *c8_identifier)
{
  uint8_T c8_b_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = (const char *)c8_identifier;
  c8_thisId.fParent = NULL;
  c8_thisId.bParentIsCell = false;
  c8_b_y = c8_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_b_is_active_c8_Jan22_DLforACC_cs), &c8_thisId);
  sf_mex_destroy(&c8_b_is_active_c8_Jan22_DLforACC_cs);
  return c8_b_y;
}

static uint8_T c8_k_emlrt_marshallIn(SFc8_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c8_b_u, const emlrtMsgIdentifier *c8_parentId)
{
  uint8_T c8_b_y;
  uint8_T c8_u0;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_b_u), &c8_u0, 1, 3, 0U, 0, 0U, 0);
  c8_b_y = c8_u0;
  sf_mex_destroy(&c8_b_u);
  return c8_b_y;
}

static void init_dsm_address_info(SFc8_Jan22_DLforACC_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc8_Jan22_DLforACC_csInstanceStruct
  *chartInstance)
{
  chartInstance->c8_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c8_u = (c8_PRESCAN_V2X_USER_GENERIC_MESSAGE *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c8_y = (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c8_z = (PRESCAN_V2X_FIXED_GENERIC_MESSAGE *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 1);
}

/* SFunction Glue Code */
void sf_c8_Jan22_DLforACC_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3513950640U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(249107576U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(738272558U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(724438600U);
}

mxArray* sf_c8_Jan22_DLforACC_cs_get_post_codegen_info(void);
mxArray *sf_c8_Jan22_DLforACC_cs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("noe0rQRqeJv7Bov2wfnCLH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c8_Jan22_DLforACC_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c8_Jan22_DLforACC_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c8_Jan22_DLforACC_cs_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("early");
  mxArray *fallbackReason = mxCreateString("imported_bus");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString(
    "PRESCAN_V2X_USER_GENERIC_MESSAGE");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c8_Jan22_DLforACC_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c8_Jan22_DLforACC_cs_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c8_Jan22_DLforACC_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c8_Jan22_DLforACC_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_Jan22_DLforACC_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc8_Jan22_DLforACC_csInstanceStruct *chartInstance =
      (SFc8_Jan22_DLforACC_csInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Jan22_DLforACC_csMachineNumber_,
           8,
           1,
           1,
           0,
           3,
           0,
           0,
           0,
           0,
           1,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_Jan22_DLforACC_csMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Jan22_DLforACC_csMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Jan22_DLforACC_csMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,1,1,0,"z");
          _SFD_SET_DATA_PROPS(2,2,0,1,"y");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,61);
        _SFD_CV_INIT_SCRIPT(0,4,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"V2X_GENERIC_expander",0,-1,114);
        _SFD_CV_INIT_SCRIPT_FCN(0,1,"FILTER_PRESCAN_V2X_FIXED_GENERIC_MESSAGE",
          116,-1,303);
        _SFD_CV_INIT_SCRIPT_FCN(0,2,"FILTER_PRESCAN_HEADER",305,-1,372);
        _SFD_CV_INIT_SCRIPT_FCN(0,3,"FILTER_PRESCAN_V2X_FIXED_GENERIC_DATA",374,
          -1,618);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_u_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_y_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_y_bus_io,(MexInFcnForType)NULL);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Jan22_DLforACC_csMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc8_Jan22_DLforACC_csInstanceStruct *chartInstance =
      (SFc8_Jan22_DLforACC_csInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c8_u);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c8_y);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c8_z);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "s65jrMyBLFbEl8YgFfcUunD";
}

static void sf_opaque_initialize_c8_Jan22_DLforACC_cs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc8_Jan22_DLforACC_csInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c8_Jan22_DLforACC_cs((SFc8_Jan22_DLforACC_csInstanceStruct*)
    chartInstanceVar);
  initialize_c8_Jan22_DLforACC_cs((SFc8_Jan22_DLforACC_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c8_Jan22_DLforACC_cs(void *chartInstanceVar)
{
  enable_c8_Jan22_DLforACC_cs((SFc8_Jan22_DLforACC_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c8_Jan22_DLforACC_cs(void *chartInstanceVar)
{
  disable_c8_Jan22_DLforACC_cs((SFc8_Jan22_DLforACC_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c8_Jan22_DLforACC_cs(void *chartInstanceVar)
{
  sf_gateway_c8_Jan22_DLforACC_cs((SFc8_Jan22_DLforACC_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c8_Jan22_DLforACC_cs(SimStruct* S)
{
  return get_sim_state_c8_Jan22_DLforACC_cs
    ((SFc8_Jan22_DLforACC_csInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c8_Jan22_DLforACC_cs(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c8_Jan22_DLforACC_cs((SFc8_Jan22_DLforACC_csInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c8_Jan22_DLforACC_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc8_Jan22_DLforACC_csInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Jan22_DLforACC_cs_optimization_info();
    }

    finalize_c8_Jan22_DLforACC_cs((SFc8_Jan22_DLforACC_csInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc8_Jan22_DLforACC_cs((SFc8_Jan22_DLforACC_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c8_Jan22_DLforACC_cs(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c8_Jan22_DLforACC_cs((SFc8_Jan22_DLforACC_csInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c8_Jan22_DLforACC_cs(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssSetInputPortDirectFeedThrough(S, 0, 1);
  ssSetInputPortDirectFeedThrough(S, 1, 1);
  ssSetStatesModifiedOnlyInUpdate(S, 1);
  ssSetBlockIsPurelyCombinatorial_wrapper(S, 1);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Jan22_DLforACC_cs_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,8);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetSupportedForRowMajorCodeGen(S, 1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,8,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 8);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,8);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,8,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,8,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,8);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(950422726U));
  ssSetChecksum1(S,(404259738U));
  ssSetChecksum2(S,(206813336U));
  ssSetChecksum3(S,(3144167913U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c8_Jan22_DLforACC_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c8_Jan22_DLforACC_cs(SimStruct *S)
{
  SFc8_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc8_Jan22_DLforACC_csInstanceStruct *)utMalloc(sizeof
    (SFc8_Jan22_DLforACC_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc8_Jan22_DLforACC_csInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c8_Jan22_DLforACC_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c8_Jan22_DLforACC_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c8_Jan22_DLforACC_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c8_Jan22_DLforACC_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c8_Jan22_DLforACC_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c8_Jan22_DLforACC_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c8_Jan22_DLforACC_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c8_Jan22_DLforACC_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c8_Jan22_DLforACC_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c8_Jan22_DLforACC_cs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c8_Jan22_DLforACC_cs;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0, NULL, NULL);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c8_Jan22_DLforACC_cs(chartInstance);
}

void c8_Jan22_DLforACC_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_Jan22_DLforACC_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_Jan22_DLforACC_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_Jan22_DLforACC_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_Jan22_DLforACC_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
