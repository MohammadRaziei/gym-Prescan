/* Include files */

#include "Jan22_DLforACC_cs_sfun.h"
#include "c3_Jan22_DLforACC_cs.h"
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
static const char * c3_debug_family_names[5] = { "nargin", "nargout", "u", "z",
  "y" };

static const char * c3_b_debug_family_names[4] = { "nargin", "nargout", "u", "y"
};

static const char * c3_c_debug_family_names[4] = { "nargin", "nargout", "u", "y"
};

static const char * c3_d_debug_family_names[4] = { "nargin", "nargout", "u", "y"
};

static const char * c3_e_debug_family_names[4] = { "nargin", "nargout", "u", "y"
};

static const char * c3_f_debug_family_names[5] = { "nargin", "nargout", "y", "z",
  "u" };

static const char * c3_sv0[2] = { "HEADER", "DATA" };

static const char * c3_sv1[2] = { "width", "length" };

static const char * c3_sv2[10] = { "utcTime", "longitude", "latitude",
  "elevation", "heading", "speed", "posAccuracy", "timeConfidence",
  "posConfidence", "speedConfidence" };

static const char * c3_sv3[6] = { "year", "month", "day", "hour", "minute",
  "second" };

static const char * c3_sv4[2] = { "HEADER", "DATA" };

static const char * c3_sv5[2] = { "width", "length" };

static const char * c3_sv6[10] = { "utcTime", "longitude", "latitude",
  "elevation", "heading", "speed", "posAccuracy", "timeConfidence",
  "posConfidence", "speedConfidence" };

static const char * c3_sv7[6] = { "year", "month", "day", "hour", "minute",
  "second" };

/* Function Declarations */
static void initialize_c3_Jan22_DLforACC_cs(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance);
static void initialize_params_c3_Jan22_DLforACC_cs
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance);
static void enable_c3_Jan22_DLforACC_cs(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance);
static void disable_c3_Jan22_DLforACC_cs(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance);
static void c3_update_debugger_state_c3_Jan22_DLforACC_cs
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_Jan22_DLforACC_cs
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance);
static void set_sim_state_c3_Jan22_DLforACC_cs
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_st);
static void finalize_c3_Jan22_DLforACC_cs(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance);
static void sf_gateway_c3_Jan22_DLforACC_cs(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance);
static void mdl_start_c3_Jan22_DLforACC_cs(SFc3_Jan22_DLforACC_csInstanceStruct *
  chartInstance);
static void initSimStructsc3_Jan22_DLforACC_cs
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_emlrt_marshallOut(SFc3_Jan22_DLforACC_csInstanceStruct *
  chartInstance, const PRESCAN_V2X_FIXED_BSM_DATA *c3_b_u);
static const mxArray *c3_b_emlrt_marshallOut
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const int32_T c3_b_u);
static const mxArray *c3_c_emlrt_marshallOut
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const int8_T c3_b_u[2]);
static const mxArray *c3_d_emlrt_marshallOut
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const
   PRESCAN_V2X_FIXED_BSM_safetyExt *c3_b_u);
static const mxArray *c3_e_emlrt_marshallOut
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const
   PRESCAN_V2X_FIXED_BSM_utcTime c3_b_u);
static const mxArray *c3_f_emlrt_marshallOut
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const
   PRESCAN_V2X_FIXED_BSM_status *c3_b_u);
static const mxArray *c3_g_emlrt_marshallOut
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const
   PRESCAN_V2X_FIXED_BSM_wipers c3_b_u);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_h_emlrt_marshallOut
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const
   c3_PRESCAN_V2X_USER_BSM_DATA c3_b_u);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static c3_PRESCAN_V2X_USER_BSM_MESSAGE c3_b_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_y,
   const char_T *c3_identifier);
static c3_PRESCAN_V2X_USER_BSM_MESSAGE c3_c_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_u,
   const emlrtMsgIdentifier *c3_parentId);
static PRESCAN_HEADER c3_d_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId);
static boolean_T c3_e_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId);
static c3_PRESCAN_V2X_USER_BSM_DATA c3_f_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_u,
   const emlrtMsgIdentifier *c3_parentId);
static int32_T c3_g_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_h_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[4]);
static void c3_i_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[2]);
static int8_T c3_j_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_k_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[7]);
static c3_PRESCAN_V2X_USER_BSM_size c3_l_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_u,
   const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static PRESCAN_V2X_FIXED_BSM_size c3_m_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_u,
   const emlrtMsgIdentifier *c3_parentId);
static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_h_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_n_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  PRESCAN_V2X_FIXED_BSM_DATA *c3_b_y);
static void c3_o_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  PRESCAN_V2X_FIXED_BSM_safetyExt *c3_b_y);
static void c3_p_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  PRESCAN_V2X_FIXED_BSM_pathHistory *c3_b_y);
static PRESCAN_V2X_FIXED_BSM_initialPosition c3_q_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_u,
   const emlrtMsgIdentifier *c3_parentId);
static PRESCAN_V2X_FIXED_BSM_utcTime c3_r_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_u,
   const emlrtMsgIdentifier *c3_parentId);
static void c3_s_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  PRESCAN_V2X_FIXED_BSM_crumbData *c3_b_y);
static void c3_t_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 c3_b_y[23]);
static void c3_u_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[345]);
static void c3_v_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[276]);
static void c3_w_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[184]);
static void c3_x_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[230]);
static void c3_y_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[138]);
static void c3_ab_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[242]);
static void c3_bb_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[161]);
static void c3_cb_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[196]);
static void c3_db_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[104]);
static PRESCAN_V2X_FIXED_BSM_pathPrediction c3_eb_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_u,
   const emlrtMsgIdentifier *c3_parentId);
static void c3_fb_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  PRESCAN_V2X_FIXED_BSM_theRTCM *c3_b_y);
static PRESCAN_V2X_FIXED_BSM_anchorPoint c3_gb_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_u,
   const emlrtMsgIdentifier *c3_parentId);
static void c3_hb_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[5]);
static void c3_ib_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[124]);
static void c3_jb_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[156]);
static void c3_kb_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[210]);
static void c3_lb_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[258]);
static void c3_mb_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[19]);
static void c3_nb_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[21]);
static void c3_ob_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[36]);
static void c3_pb_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[68]);
static void c3_qb_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[136]);
static void c3_rb_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[166]);
static void c3_sb_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[222]);
static void c3_tb_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[268]);
static void c3_ub_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[27]);
static void c3_vb_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[15]);
static void c3_wb_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[69]);
static void c3_xb_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[81]);
static void c3_yb_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[115]);
static void c3_ac_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[62]);
static void c3_bc_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[45]);
static void c3_cc_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[75]);
static void c3_dc_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[73]);
static void c3_ec_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[74]);
static void c3_fc_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[25]);
static void c3_gc_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[30]);
static void c3_hc_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[33]);
static void c3_ic_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[105]);
static void c3_jc_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[107]);
static void c3_kc_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[20]);
static void c3_lc_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  PRESCAN_V2X_FIXED_BSM_status *c3_b_y);
static PRESCAN_V2X_FIXED_BSM_wipers c3_mc_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_u,
   const emlrtMsgIdentifier *c3_parentId);
static PRESCAN_V2X_FIXED_BSM_steering c3_nc_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_u,
   const emlrtMsgIdentifier *c3_parentId);
static PRESCAN_V2X_FIXED_BSM_accelSets c3_oc_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_u,
   const emlrtMsgIdentifier *c3_parentId);
static PRESCAN_V2X_FIXED_BSM_confidenceSet c3_pc_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_u,
   const emlrtMsgIdentifier *c3_parentId);
static PRESCAN_V2X_FIXED_BSM_accelConfidence c3_qc_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_u,
   const emlrtMsgIdentifier *c3_parentId);
static PRESCAN_V2X_FIXED_BSM_object c3_rc_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_u,
   const emlrtMsgIdentifier *c3_parentId);
static PRESCAN_V2X_FIXED_BSM_dateTime c3_sc_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_u,
   const emlrtMsgIdentifier *c3_parentId);
static PRESCAN_V2X_FIXED_BSM_fullPos c3_tc_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_u,
   const emlrtMsgIdentifier *c3_parentId);
static PRESCAN_V2X_FIXED_BSM_vehicleData c3_uc_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_u,
   const emlrtMsgIdentifier *c3_parentId);
static PRESCAN_V2X_FIXED_BSM_bumpers c3_vc_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_u,
   const emlrtMsgIdentifier *c3_parentId);
static void c3_wc_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  PRESCAN_V2X_FIXED_BSM_vehicleIdent *c3_b_y);
static void c3_xc_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[63]);
static void c3_yc_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[17]);
static void c3_ad_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[32]);
static PRESCAN_V2X_FIXED_BSM_vehicleClass c3_bd_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_u,
   const emlrtMsgIdentifier *c3_parentId);
static void c3_cd_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  PRESCAN_V2X_FIXED_BSM_j1939data *c3_b_y);
static void c3_dd_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  PRESCAN_V2X_FIXED_BSM_tires c3_b_y[16]);
static void c3_ed_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  PRESCAN_V2X_FIXED_BSM_axle c3_b_y[16]);
static PRESCAN_V2X_FIXED_BSM_weatherReport c3_fd_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_u,
   const emlrtMsgIdentifier *c3_parentId);
static void c3_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_gd_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  PRESCAN_V2X_FIXED_BSM_MESSAGE *c3_b_y);
static void c3_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_i_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_u_bus_io(void *chartInstanceVoid, void *c3_pData);
static const mxArray *c3_y_bus_io(void *chartInstanceVoid, void *c3_pData);
static uint8_T c3_hd_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_Jan22_DLforACC_cs, const
  char_T *c3_identifier);
static uint8_T c3_id_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_Jan22_DLforACC_cs(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc3_Jan22_DLforACC_cs(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  sim_mode_is_external(chartInstance->S);
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_is_active_c3_Jan22_DLforACC_cs = 0U;
  setLegacyDebuggerFlagForRuntime(chartInstance->S, true);
}

static void initialize_params_c3_Jan22_DLforACC_cs
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_Jan22_DLforACC_cs(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_Jan22_DLforACC_cs(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c3_update_debugger_state_c3_Jan22_DLforACC_cs
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c3_Jan22_DLforACC_cs
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_b_y = NULL;
  const mxArray *c3_c_y = NULL;
  PRESCAN_HEADER c3_b_u;
  const mxArray *c3_d_y = NULL;
  static const char * c3_sv8[1] = { "valid" };

  boolean_T c3_c_u;
  const mxArray *c3_e_y = NULL;
  c3_PRESCAN_V2X_USER_BSM_DATA c3_r0;
  int32_T c3_i0;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_i4;
  int32_T c3_i5;
  uint8_T c3_hoistedGlobal;
  const mxArray *c3_f_y = NULL;
  c3_st = NULL;
  c3_st = NULL;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_createcellmatrix(2, 1), false);
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_createstruct("structure", 2, c3_sv0, 2, 1, 1),
                false);
  c3_b_u.valid = *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)
    chartInstance->c3_y)[0])[0];
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_createstruct("structure", 1, c3_sv8, 2, 1, 1),
                false);
  c3_c_u = c3_b_u.valid;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_c_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_d_y, 0, "valid", c3_e_y, 0);
  sf_mex_setfieldbynum(c3_c_y, 0, "HEADER", c3_d_y, 0);
  c3_r0.msgID = *(int32_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)chartInstance->c3_y)[8])[0];
  c3_r0.msgCnt = *(int32_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)chartInstance->c3_y)[8])[4];
  for (c3_i0 = 0; c3_i0 < 4; c3_i0++) {
    c3_r0.id[c3_i0] = ((int8_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)
      &((char_T *)chartInstance->c3_y)[8])[8])[c3_i0];
  }

  c3_r0.secMark = *(int32_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)chartInstance->c3_y)[8])[12];
  c3_r0.latitude = *(int32_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)chartInstance->c3_y)[8])[16];
  c3_r0.longitude = *(int32_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)chartInstance->c3_y)[8])[20];
  for (c3_i1 = 0; c3_i1 < 2; c3_i1++) {
    c3_r0.elev[c3_i1] = ((int8_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)
      &((char_T *)chartInstance->c3_y)[8])[24])[c3_i1];
  }

  for (c3_i2 = 0; c3_i2 < 4; c3_i2++) {
    c3_r0.accuracy[c3_i2] = ((int8_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA
      *)&((char_T *)chartInstance->c3_y)[8])[26])[c3_i2];
  }

  for (c3_i3 = 0; c3_i3 < 2; c3_i3++) {
    c3_r0.speed[c3_i3] = ((int8_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)
      &((char_T *)chartInstance->c3_y)[8])[30])[c3_i3];
  }

  c3_r0.heading = *(int32_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)chartInstance->c3_y)[8])[32];
  c3_r0.angle = *(int8_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T
    *)chartInstance->c3_y)[8])[36];
  for (c3_i4 = 0; c3_i4 < 7; c3_i4++) {
    c3_r0.accelSet[c3_i4] = ((int8_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA
      *)&((char_T *)chartInstance->c3_y)[8])[37])[c3_i4];
  }

  for (c3_i5 = 0; c3_i5 < 2; c3_i5++) {
    c3_r0.brakes[c3_i5] = ((int8_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)
      &((char_T *)chartInstance->c3_y)[8])[44])[c3_i5];
  }

  c3_r0.size.width = *(int32_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_size *)
    &((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)chartInstance->c3_y)
      [8])[48])[0];
  c3_r0.size.length = *(int32_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_size *)
    &((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)chartInstance->c3_y)
      [8])[48])[4];
  sf_mex_setfieldbynum(c3_c_y, 0, "DATA", c3_h_emlrt_marshallOut(chartInstance,
    c3_r0), 1);
  sf_mex_setcell(c3_b_y, 0, c3_c_y);
  c3_hoistedGlobal = chartInstance->c3_is_active_c3_Jan22_DLforACC_cs;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_hoistedGlobal, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c3_b_y, 1, c3_f_y);
  sf_mex_assign(&c3_st, c3_b_y, false);
  return c3_st;
}

static void set_sim_state_c3_Jan22_DLforACC_cs
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_b_u;
  c3_PRESCAN_V2X_USER_BSM_MESSAGE c3_r1;
  int32_T c3_i6;
  int32_T c3_i7;
  int32_T c3_i8;
  int32_T c3_i9;
  int32_T c3_i10;
  int32_T c3_i11;
  chartInstance->c3_doneDoubleBufferReInit = true;
  c3_b_u = sf_mex_dup(c3_st);
  c3_r1 = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_b_u,
    0)), "y");
  *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)chartInstance->c3_y)[0])
    [0] = c3_r1.HEADER.valid;
  *(int32_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
    chartInstance->c3_y)[8])[0] = c3_r1.DATA.msgID;
  *(int32_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
    chartInstance->c3_y)[8])[4] = c3_r1.DATA.msgCnt;
  for (c3_i6 = 0; c3_i6 < 4; c3_i6++) {
    ((int8_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
       chartInstance->c3_y)[8])[8])[c3_i6] = c3_r1.DATA.id[c3_i6];
  }

  *(int32_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
    chartInstance->c3_y)[8])[12] = c3_r1.DATA.secMark;
  *(int32_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
    chartInstance->c3_y)[8])[16] = c3_r1.DATA.latitude;
  *(int32_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
    chartInstance->c3_y)[8])[20] = c3_r1.DATA.longitude;
  for (c3_i7 = 0; c3_i7 < 2; c3_i7++) {
    ((int8_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
       chartInstance->c3_y)[8])[24])[c3_i7] = c3_r1.DATA.elev[c3_i7];
  }

  for (c3_i8 = 0; c3_i8 < 4; c3_i8++) {
    ((int8_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
       chartInstance->c3_y)[8])[26])[c3_i8] = c3_r1.DATA.accuracy[c3_i8];
  }

  for (c3_i9 = 0; c3_i9 < 2; c3_i9++) {
    ((int8_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
       chartInstance->c3_y)[8])[30])[c3_i9] = c3_r1.DATA.speed[c3_i9];
  }

  *(int32_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
    chartInstance->c3_y)[8])[32] = c3_r1.DATA.heading;
  *(int8_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
    chartInstance->c3_y)[8])[36] = c3_r1.DATA.angle;
  for (c3_i10 = 0; c3_i10 < 7; c3_i10++) {
    ((int8_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
       chartInstance->c3_y)[8])[37])[c3_i10] = c3_r1.DATA.accelSet[c3_i10];
  }

  for (c3_i11 = 0; c3_i11 < 2; c3_i11++) {
    ((int8_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
       chartInstance->c3_y)[8])[44])[c3_i11] = c3_r1.DATA.brakes[c3_i11];
  }

  *(int32_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_size *)&((char_T *)
    (c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)chartInstance->c3_y)[8])[48])[0]
    = c3_r1.DATA.size.width;
  *(int32_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_size *)&((char_T *)
    (c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)chartInstance->c3_y)[8])[48])[4]
    = c3_r1.DATA.size.length;
  chartInstance->c3_is_active_c3_Jan22_DLforACC_cs = c3_hd_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_b_u, 1)),
     "is_active_c3_Jan22_DLforACC_cs");
  sf_mex_destroy(&c3_b_u);
  c3_update_debugger_state_c3_Jan22_DLforACC_cs(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_Jan22_DLforACC_cs(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c3_RuntimeVar);
}

static void sf_gateway_c3_Jan22_DLforACC_cs(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance)
{
  PRESCAN_V2X_FIXED_BSM_MESSAGE c3_b_u;
  int32_T c3_i12;
  int32_T c3_i13;
  int32_T c3_i14;
  int32_T c3_i15;
  int32_T c3_i16;
  int32_T c3_i17;
  int32_T c3_i18;
  int32_T c3_i19;
  int32_T c3_i20;
  int32_T c3_i21;
  int32_T c3_i22;
  int32_T c3_i23;
  int32_T c3_i24;
  int32_T c3_i25;
  int32_T c3_i26;
  int32_T c3_i27;
  int32_T c3_i28;
  int32_T c3_i29;
  int32_T c3_i30;
  int32_T c3_i31;
  int32_T c3_i32;
  int32_T c3_i33;
  int32_T c3_i34;
  int32_T c3_i35;
  int32_T c3_i36;
  int32_T c3_i37;
  int32_T c3_i38;
  int32_T c3_i39;
  int32_T c3_i40;
  int32_T c3_i41;
  int32_T c3_i42;
  int32_T c3_i43;
  int32_T c3_i44;
  int32_T c3_i45;
  int32_T c3_i46;
  int32_T c3_i47;
  int32_T c3_i48;
  int32_T c3_i49;
  int32_T c3_i50;
  int32_T c3_i51;
  int32_T c3_i52;
  int32_T c3_i53;
  int32_T c3_i54;
  int32_T c3_i55;
  int32_T c3_i56;
  int32_T c3_i57;
  int32_T c3_i58;
  int32_T c3_i59;
  int32_T c3_i60;
  int32_T c3_i61;
  int32_T c3_i62;
  int32_T c3_i63;
  int32_T c3_i64;
  int32_T c3_i65;
  int32_T c3_i66;
  int32_T c3_i67;
  int32_T c3_i68;
  int32_T c3_i69;
  int32_T c3_i70;
  int32_T c3_i71;
  int32_T c3_i72;
  int32_T c3_i73;
  int32_T c3_i74;
  int32_T c3_i75;
  int32_T c3_i76;
  int32_T c3_i77;
  c3_PRESCAN_V2X_USER_BSM_MESSAGE c3_b_z;
  int32_T c3_i78;
  int32_T c3_i79;
  int32_T c3_i80;
  int32_T c3_i81;
  int32_T c3_i82;
  int32_T c3_i83;
  uint32_T c3_debug_family_var_map[5];
  real_T c3_nargin = 2.0;
  real_T c3_nargout = 1.0;
  c3_PRESCAN_V2X_USER_BSM_MESSAGE c3_b_y;
  PRESCAN_V2X_FIXED_BSM_MESSAGE c3_c_y;
  c3_PRESCAN_V2X_USER_BSM_MESSAGE c3_c_z;
  uint32_T c3_b_debug_family_var_map[5];
  real_T c3_b_nargin = 2.0;
  real_T c3_b_nargout = 1.0;
  c3_PRESCAN_V2X_USER_BSM_MESSAGE c3_c_u;
  PRESCAN_V2X_FIXED_BSM_MESSAGE c3_d_y;
  uint32_T c3_c_debug_family_var_map[4];
  real_T c3_c_nargin = 2.0;
  real_T c3_c_nargout = 1.0;
  PRESCAN_HEADER c3_d_u;
  PRESCAN_HEADER c3_e_y;
  uint32_T c3_d_debug_family_var_map[4];
  real_T c3_d_nargin = 2.0;
  real_T c3_d_nargout = 1.0;
  c3_PRESCAN_V2X_USER_BSM_DATA c3_e_u;
  PRESCAN_V2X_FIXED_BSM_DATA c3_f_y;
  uint32_T c3_e_debug_family_var_map[4];
  real_T c3_e_nargin = 2.0;
  real_T c3_e_nargout = 1.0;
  int32_T c3_i84;
  int32_T c3_i85;
  int32_T c3_i86;
  int32_T c3_i87;
  int32_T c3_i88;
  int32_T c3_i89;
  c3_PRESCAN_V2X_USER_BSM_size c3_f_u;
  PRESCAN_V2X_FIXED_BSM_size c3_g_y;
  uint32_T c3_f_debug_family_var_map[4];
  real_T c3_f_nargin = 2.0;
  real_T c3_f_nargout = 1.0;
  int32_T c3_i90;
  int32_T c3_i91;
  int32_T c3_i92;
  int32_T c3_i93;
  int32_T c3_i94;
  int32_T c3_i95;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1, chartInstance->c3_sfEvent);
  chartInstance->c3_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  c3_b_u.HEADER.valid = *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)
    chartInstance->c3_u)[0])[0];
  c3_b_u.DATA.msgID = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[0];
  c3_b_u.DATA.msgCnt = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[4];
  for (c3_i12 = 0; c3_i12 < 4; c3_i12++) {
    c3_b_u.DATA.id[c3_i12] = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c3_u)[8])[8])[c3_i12];
  }

  c3_b_u.DATA.secMark = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[12];
  c3_b_u.DATA.latitude = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[16];
  c3_b_u.DATA.longitude = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[20];
  for (c3_i13 = 0; c3_i13 < 2; c3_i13++) {
    c3_b_u.DATA.elev[c3_i13] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[24])
      [c3_i13];
  }

  for (c3_i14 = 0; c3_i14 < 4; c3_i14++) {
    c3_b_u.DATA.accuracy[c3_i14] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[26])
      [c3_i14];
  }

  for (c3_i15 = 0; c3_i15 < 2; c3_i15++) {
    c3_b_u.DATA.speed[c3_i15] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[30])
      [c3_i15];
  }

  c3_b_u.DATA.heading = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[32];
  c3_b_u.DATA.angle = *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[36];
  for (c3_i16 = 0; c3_i16 < 7; c3_i16++) {
    c3_b_u.DATA.accelSet[c3_i16] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[37])
      [c3_i16];
  }

  for (c3_i17 = 0; c3_i17 < 2; c3_i17++) {
    c3_b_u.DATA.brakes[c3_i17] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[44])
      [c3_i17];
  }

  c3_b_u.DATA.size.width = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_size *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])
    [48])[0];
  c3_b_u.DATA.size.length = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_size *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])
    [48])[4];
  c3_b_u.DATA.safetyExt.events = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[56])[0];
  c3_b_u.DATA.safetyExt.pathHistory.initialPosition.utcTime.year = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[56])
        [8])[0])[0])[0];
  c3_b_u.DATA.safetyExt.pathHistory.initialPosition.utcTime.month = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[56])
        [8])[0])[0])[4];
  c3_b_u.DATA.safetyExt.pathHistory.initialPosition.utcTime.day = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[56])
        [8])[0])[0])[8];
  c3_b_u.DATA.safetyExt.pathHistory.initialPosition.utcTime.hour = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[56])
        [8])[0])[0])[12];
  c3_b_u.DATA.safetyExt.pathHistory.initialPosition.utcTime.minute = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[56])
        [8])[0])[0])[16];
  c3_b_u.DATA.safetyExt.pathHistory.initialPosition.utcTime.second = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[56])
        [8])[0])[0])[20];
  c3_b_u.DATA.safetyExt.pathHistory.initialPosition.longitude = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[56])
       [8])[0])[24];
  c3_b_u.DATA.safetyExt.pathHistory.initialPosition.latitude = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[56])
       [8])[0])[28];
  for (c3_i18 = 0; c3_i18 < 2; c3_i18++) {
    c3_b_u.DATA.safetyExt.pathHistory.initialPosition.elevation[c3_i18] =
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[56])
         [8])[0])[32])[c3_i18];
  }

  c3_b_u.DATA.safetyExt.pathHistory.initialPosition.heading = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[56])
       [8])[0])[36];
  for (c3_i19 = 0; c3_i19 < 2; c3_i19++) {
    c3_b_u.DATA.safetyExt.pathHistory.initialPosition.speed[c3_i19] = ((int8_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c3_u)[8])[56])[8])[0])[40])[c3_i19];
  }

  for (c3_i20 = 0; c3_i20 < 4; c3_i20++) {
    c3_b_u.DATA.safetyExt.pathHistory.initialPosition.posAccuracy[c3_i20] =
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[56])
         [8])[0])[42])[c3_i20];
  }

  c3_b_u.DATA.safetyExt.pathHistory.initialPosition.timeConfidence = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[56])
       [8])[0])[48];
  c3_b_u.DATA.safetyExt.pathHistory.initialPosition.posConfidence = *(int8_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[56])
       [8])[0])[52];
  c3_b_u.DATA.safetyExt.pathHistory.initialPosition.speedConfidence = *(int8_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[56])
       [8])[0])[53];
  c3_b_u.DATA.safetyExt.pathHistory.currGPSstatus = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[56])[8])[56];
  c3_b_u.DATA.safetyExt.pathHistory.itemCnt = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[56])[8])[60];
  for (c3_i21 = 0; c3_i21 < 23; c3_i21++) {
    c3_b_u.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c3_i21].
      latOffset = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c3_u)[8])[56])[8])[64])[0])[32 * (int32_T)
      c3_i21])[0];
    c3_b_u.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c3_i21].
      longOffset = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c3_u)[8])[56])[8])[64])[0])[32 * (int32_T)
      c3_i21])[4];
    c3_b_u.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c3_i21].
      elevationOffset = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c3_u)[8])[56])[8])[64])[0])[32 * (int32_T)
      c3_i21])[8];
    c3_b_u.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c3_i21].
      timeOffset = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c3_u)[8])[56])[8])[64])[0])[32 * (int32_T)
      c3_i21])[12];
    for (c3_i24 = 0; c3_i24 < 4; c3_i24++) {
      c3_b_u.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c3_i21]
        .posAccuracy[c3_i24] = ((int8_T *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[56])
        [8])[64])[0])[32 * (int32_T)c3_i21])[16])[c3_i24];
    }

    c3_b_u.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c3_i21].
      heading = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c3_u)[8])[56])[8])[64])[0])[32 * (int32_T)
      c3_i21])[20];
    for (c3_i26 = 0; c3_i26 < 2; c3_i26++) {
      c3_b_u.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c3_i21]
        .speed[c3_i26] = ((int8_T *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[56])
        [8])[64])[0])[32 * (int32_T)c3_i21])[24])[c3_i26];
    }
  }

  for (c3_i22 = 0; c3_i22 < 345; c3_i22++) {
    c3_b_u.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_02[c3_i22] =
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[56])
         [8])[64])[736])[c3_i22];
  }

  for (c3_i23 = 0; c3_i23 < 276; c3_i23++) {
    c3_b_u.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_03[c3_i23] =
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[56])
         [8])[64])[1081])[c3_i23];
  }

  for (c3_i25 = 0; c3_i25 < 184; c3_i25++) {
    c3_b_u.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_04[c3_i25] =
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[56])
         [8])[64])[1357])[c3_i25];
  }

  for (c3_i27 = 0; c3_i27 < 230; c3_i27++) {
    c3_b_u.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_05[c3_i27] =
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[56])
         [8])[64])[1541])[c3_i27];
  }

  for (c3_i28 = 0; c3_i28 < 138; c3_i28++) {
    c3_b_u.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_06[c3_i28] =
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[56])
         [8])[64])[1771])[c3_i28];
  }

  for (c3_i29 = 0; c3_i29 < 242; c3_i29++) {
    c3_b_u.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_07[c3_i29] =
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[56])
         [8])[64])[1909])[c3_i29];
  }

  for (c3_i30 = 0; c3_i30 < 161; c3_i30++) {
    c3_b_u.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_08[c3_i30] =
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[56])
         [8])[64])[2151])[c3_i30];
  }

  for (c3_i31 = 0; c3_i31 < 196; c3_i31++) {
    c3_b_u.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_09[c3_i31] =
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[56])
         [8])[64])[2312])[c3_i31];
  }

  for (c3_i32 = 0; c3_i32 < 104; c3_i32++) {
    c3_b_u.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_10[c3_i32] =
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[56])
         [8])[64])[2508])[c3_i32];
  }

  c3_b_u.DATA.safetyExt.pathPrediction.radiusOfCurve = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathPrediction *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[56])[2688])[0];
  c3_b_u.DATA.safetyExt.pathPrediction.confidence = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathPrediction *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[56])[2688])[4];
  c3_b_u.DATA.safetyExt.theRTCM.anchorPoint.utcTime.year = *(int32_T *)&((char_T
    *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[56])[2696])[0])[0])[0];
  c3_b_u.DATA.safetyExt.theRTCM.anchorPoint.utcTime.month = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[56])
        [2696])[0])[0])[4];
  c3_b_u.DATA.safetyExt.theRTCM.anchorPoint.utcTime.day = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[56])[2696])[0])[0])[8];
  c3_b_u.DATA.safetyExt.theRTCM.anchorPoint.utcTime.hour = *(int32_T *)&((char_T
    *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[56])[2696])[0])[0])[12];
  c3_b_u.DATA.safetyExt.theRTCM.anchorPoint.utcTime.minute = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[56])
        [2696])[0])[0])[16];
  c3_b_u.DATA.safetyExt.theRTCM.anchorPoint.utcTime.second = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[56])
        [2696])[0])[0])[20];
  c3_b_u.DATA.safetyExt.theRTCM.anchorPoint.longitude = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[56])[2696])[0])[24];
  c3_b_u.DATA.safetyExt.theRTCM.anchorPoint.latitude = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[56])[2696])[0])[28];
  for (c3_i33 = 0; c3_i33 < 2; c3_i33++) {
    c3_b_u.DATA.safetyExt.theRTCM.anchorPoint.elevation[c3_i33] = ((int8_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c3_u)[8])[56])[2696])[0])[32])[c3_i33];
  }

  c3_b_u.DATA.safetyExt.theRTCM.anchorPoint.heading = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[56])[2696])[0])[36];
  for (c3_i34 = 0; c3_i34 < 2; c3_i34++) {
    c3_b_u.DATA.safetyExt.theRTCM.anchorPoint.speed[c3_i34] = ((int8_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c3_u)[8])[56])[2696])[0])[40])[c3_i34];
  }

  for (c3_i35 = 0; c3_i35 < 4; c3_i35++) {
    c3_b_u.DATA.safetyExt.theRTCM.anchorPoint.posAccuracy[c3_i35] = ((int8_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c3_u)[8])[56])[2696])[0])[42])[c3_i35];
  }

  c3_b_u.DATA.safetyExt.theRTCM.anchorPoint.timeConfidence = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[56])
       [2696])[0])[48];
  c3_b_u.DATA.safetyExt.theRTCM.anchorPoint.posConfidence = *(int8_T *)&((char_T
    *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[56])[2696])[0])[52];
  c3_b_u.DATA.safetyExt.theRTCM.anchorPoint.speedConfidence = *(int8_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[56])
       [2696])[0])[53];
  for (c3_i36 = 0; c3_i36 < 5; c3_i36++) {
    c3_b_u.DATA.safetyExt.theRTCM.rtcmHeader[c3_i36] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c3_u)[8])[56])[2696])[56])[c3_i36];
  }

  for (c3_i37 = 0; c3_i37 < 124; c3_i37++) {
    c3_b_u.DATA.safetyExt.theRTCM.msg1001[c3_i37] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c3_u)[8])[56])[2696])[61])[c3_i37];
  }

  for (c3_i38 = 0; c3_i38 < 156; c3_i38++) {
    c3_b_u.DATA.safetyExt.theRTCM.msg1002[c3_i38] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c3_u)[8])[56])[2696])[185])[c3_i38];
  }

  for (c3_i39 = 0; c3_i39 < 210; c3_i39++) {
    c3_b_u.DATA.safetyExt.theRTCM.msg1003[c3_i39] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c3_u)[8])[56])[2696])[341])[c3_i39];
  }

  for (c3_i40 = 0; c3_i40 < 258; c3_i40++) {
    c3_b_u.DATA.safetyExt.theRTCM.msg1004[c3_i40] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c3_u)[8])[56])[2696])[551])[c3_i40];
  }

  for (c3_i41 = 0; c3_i41 < 19; c3_i41++) {
    c3_b_u.DATA.safetyExt.theRTCM.msg1005[c3_i41] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c3_u)[8])[56])[2696])[809])[c3_i41];
  }

  for (c3_i42 = 0; c3_i42 < 21; c3_i42++) {
    c3_b_u.DATA.safetyExt.theRTCM.msg1006[c3_i42] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c3_u)[8])[56])[2696])[828])[c3_i42];
  }

  for (c3_i43 = 0; c3_i43 < 36; c3_i43++) {
    c3_b_u.DATA.safetyExt.theRTCM.msg1007[c3_i43] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c3_u)[8])[56])[2696])[849])[c3_i43];
  }

  for (c3_i44 = 0; c3_i44 < 68; c3_i44++) {
    c3_b_u.DATA.safetyExt.theRTCM.msg1008[c3_i44] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c3_u)[8])[56])[2696])[885])[c3_i44];
  }

  for (c3_i45 = 0; c3_i45 < 136; c3_i45++) {
    c3_b_u.DATA.safetyExt.theRTCM.msg1009[c3_i45] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c3_u)[8])[56])[2696])[953])[c3_i45];
  }

  for (c3_i46 = 0; c3_i46 < 166; c3_i46++) {
    c3_b_u.DATA.safetyExt.theRTCM.msg1010[c3_i46] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c3_u)[8])[56])[2696])[1089])[c3_i46];
  }

  for (c3_i47 = 0; c3_i47 < 222; c3_i47++) {
    c3_b_u.DATA.safetyExt.theRTCM.msg1011[c3_i47] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c3_u)[8])[56])[2696])[1255])[c3_i47];
  }

  for (c3_i48 = 0; c3_i48 < 268; c3_i48++) {
    c3_b_u.DATA.safetyExt.theRTCM.msg1012[c3_i48] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c3_u)[8])[56])[2696])[1477])[c3_i48];
  }

  for (c3_i49 = 0; c3_i49 < 27; c3_i49++) {
    c3_b_u.DATA.safetyExt.theRTCM.msg1013[c3_i49] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c3_u)[8])[56])[2696])[1745])[c3_i49];
  }

  for (c3_i50 = 0; c3_i50 < 15; c3_i50++) {
    c3_b_u.DATA.safetyExt.theRTCM.msg1014[c3_i50] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c3_u)[8])[56])[2696])[1772])[c3_i50];
  }

  for (c3_i51 = 0; c3_i51 < 69; c3_i51++) {
    c3_b_u.DATA.safetyExt.theRTCM.msg1015[c3_i51] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c3_u)[8])[56])[2696])[1787])[c3_i51];
  }

  for (c3_i52 = 0; c3_i52 < 81; c3_i52++) {
    c3_b_u.DATA.safetyExt.theRTCM.msg1016[c3_i52] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c3_u)[8])[56])[2696])[1856])[c3_i52];
  }

  for (c3_i53 = 0; c3_i53 < 115; c3_i53++) {
    c3_b_u.DATA.safetyExt.theRTCM.msg1017[c3_i53] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c3_u)[8])[56])[2696])[1937])[c3_i53];
  }

  for (c3_i54 = 0; c3_i54 < 62; c3_i54++) {
    c3_b_u.DATA.safetyExt.theRTCM.msg1019[c3_i54] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c3_u)[8])[56])[2696])[2052])[c3_i54];
  }

  for (c3_i55 = 0; c3_i55 < 45; c3_i55++) {
    c3_b_u.DATA.safetyExt.theRTCM.msg1020[c3_i55] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c3_u)[8])[56])[2696])[2114])[c3_i55];
  }

  for (c3_i56 = 0; c3_i56 < 62; c3_i56++) {
    c3_b_u.DATA.safetyExt.theRTCM.msg1021[c3_i56] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c3_u)[8])[56])[2696])[2159])[c3_i56];
  }

  for (c3_i57 = 0; c3_i57 < 75; c3_i57++) {
    c3_b_u.DATA.safetyExt.theRTCM.msg1022[c3_i57] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c3_u)[8])[56])[2696])[2221])[c3_i57];
  }

  for (c3_i58 = 0; c3_i58 < 73; c3_i58++) {
    c3_b_u.DATA.safetyExt.theRTCM.msg1023[c3_i58] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c3_u)[8])[56])[2696])[2296])[c3_i58];
  }

  for (c3_i59 = 0; c3_i59 < 74; c3_i59++) {
    c3_b_u.DATA.safetyExt.theRTCM.msg1024[c3_i59] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c3_u)[8])[56])[2696])[2369])[c3_i59];
  }

  for (c3_i60 = 0; c3_i60 < 25; c3_i60++) {
    c3_b_u.DATA.safetyExt.theRTCM.msg1025[c3_i60] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c3_u)[8])[56])[2696])[2443])[c3_i60];
  }

  for (c3_i61 = 0; c3_i61 < 30; c3_i61++) {
    c3_b_u.DATA.safetyExt.theRTCM.msg1026[c3_i61] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c3_u)[8])[56])[2696])[2468])[c3_i61];
  }

  for (c3_i62 = 0; c3_i62 < 33; c3_i62++) {
    c3_b_u.DATA.safetyExt.theRTCM.msg1027[c3_i62] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c3_u)[8])[56])[2696])[2498])[c3_i62];
  }

  for (c3_i63 = 0; c3_i63 < 69; c3_i63++) {
    c3_b_u.DATA.safetyExt.theRTCM.msg1029[c3_i63] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c3_u)[8])[56])[2696])[2531])[c3_i63];
  }

  for (c3_i64 = 0; c3_i64 < 105; c3_i64++) {
    c3_b_u.DATA.safetyExt.theRTCM.msg1030[c3_i64] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c3_u)[8])[56])[2696])[2600])[c3_i64];
  }

  for (c3_i65 = 0; c3_i65 < 107; c3_i65++) {
    c3_b_u.DATA.safetyExt.theRTCM.msg1031[c3_i65] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c3_u)[8])[56])[2696])[2705])[c3_i65];
  }

  for (c3_i66 = 0; c3_i66 < 20; c3_i66++) {
    c3_b_u.DATA.safetyExt.theRTCM.msg1032[c3_i66] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c3_u)[8])[56])[2696])[2812])[c3_i66];
  }

  c3_b_u.DATA.status.lights = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[5584])[0];
  c3_b_u.DATA.status.lightBar = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[5584])[4];
  c3_b_u.DATA.status.wipers.statusFront = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])
    [5584])[8])[0];
  c3_b_u.DATA.status.wipers.rateFront = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])
    [5584])[8])[4];
  c3_b_u.DATA.status.wipers.statusRear = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])
    [5584])[8])[8];
  c3_b_u.DATA.status.wipers.rateRear = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])
    [5584])[8])[12];
  for (c3_i67 = 0; c3_i67 < 2; c3_i67++) {
    c3_b_u.DATA.status.brakeStatus[c3_i67] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c3_u)[8])[5584])[24])[c3_i67];
  }

  c3_b_u.DATA.status.brakePressure = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[5584])[28];
  c3_b_u.DATA.status.roadFriction = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[5584])[32];
  c3_b_u.DATA.status.sunData = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[5584])[36];
  c3_b_u.DATA.status.rainData = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[5584])[40];
  c3_b_u.DATA.status.airTemp = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[5584])[44];
  c3_b_u.DATA.status.airPres = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[5584])[48];
  c3_b_u.DATA.status.steering.angle = *(int8_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])
    [5584])[56])[0];
  c3_b_u.DATA.status.steering.confidence = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])
    [5584])[56])[4];
  c3_b_u.DATA.status.steering.rate = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])
    [5584])[56])[8];
  c3_b_u.DATA.status.steering.wheels = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])
    [5584])[56])[12];
  for (c3_i68 = 0; c3_i68 < 7; c3_i68++) {
    c3_b_u.DATA.status.accelSets.accel4way[c3_i68] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c3_u)[8])[5584])[72])[0])[c3_i68];
  }

  c3_b_u.DATA.status.accelSets.vertAccelThres = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)
        [8])[5584])[72])[8];
  c3_b_u.DATA.status.accelSets.yawRateCon = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)
        [8])[5584])[72])[12];
  c3_b_u.DATA.status.accelSets.hozAccelCon = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)
        [8])[5584])[72])[16];
  c3_b_u.DATA.status.accelSets.confidenceSet.accelConfidence.yawRate = *(int32_T
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelConfidence *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])
           [5584])[72])[24])[0])[0];
  c3_b_u.DATA.status.accelSets.confidenceSet.accelConfidence.acceleration =
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelConfidence *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)
        [8])[5584])[72])[24])[0])[4];
  c3_b_u.DATA.status.accelSets.confidenceSet.accelConfidence.steeringWheelAngle =
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelConfidence *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)
        [8])[5584])[72])[24])[0])[8];
  c3_b_u.DATA.status.accelSets.confidenceSet.speedConfidence = *(int8_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
         &((char_T *)chartInstance->c3_u)[8])[5584])[72])[24])[16];
  c3_b_u.DATA.status.accelSets.confidenceSet.timeConfidence = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
         &((char_T *)chartInstance->c3_u)[8])[5584])[72])[24])[20];
  c3_b_u.DATA.status.accelSets.confidenceSet.posConfidence = *(int8_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
         &((char_T *)chartInstance->c3_u)[8])[5584])[72])[24])[24];
  c3_b_u.DATA.status.accelSets.confidenceSet.steerConfidence = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
         &((char_T *)chartInstance->c3_u)[8])[5584])[72])[24])[28];
  c3_b_u.DATA.status.accelSets.confidenceSet.throttleConfidence = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
         &((char_T *)chartInstance->c3_u)[8])[5584])[72])[24])[32];
  c3_b_u.DATA.status.object.obDist = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])
    [5584])[136])[0];
  c3_b_u.DATA.status.object.obDirect = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])
    [5584])[136])[4];
  c3_b_u.DATA.status.object.dateTime.year = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[5584])
    [136])[8])[0];
  c3_b_u.DATA.status.object.dateTime.month = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[5584])
    [136])[8])[4];
  c3_b_u.DATA.status.object.dateTime.day = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[5584])
    [136])[8])[8];
  c3_b_u.DATA.status.object.dateTime.hour = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[5584])
    [136])[8])[12];
  c3_b_u.DATA.status.object.dateTime.minute = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[5584])
    [136])[8])[16];
  c3_b_u.DATA.status.object.dateTime.second = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[5584])
    [136])[8])[20];
  c3_b_u.DATA.status.fullPos.utcTime.year = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[5584])
    [168])[0])[0];
  c3_b_u.DATA.status.fullPos.utcTime.month = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[5584])
    [168])[0])[4];
  c3_b_u.DATA.status.fullPos.utcTime.day = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[5584])
    [168])[0])[8];
  c3_b_u.DATA.status.fullPos.utcTime.hour = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[5584])
    [168])[0])[12];
  c3_b_u.DATA.status.fullPos.utcTime.minute = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[5584])
    [168])[0])[16];
  c3_b_u.DATA.status.fullPos.utcTime.second = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])[5584])
    [168])[0])[20];
  c3_b_u.DATA.status.fullPos.longitude = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])
    [5584])[168])[24];
  c3_b_u.DATA.status.fullPos.latitude = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])
    [5584])[168])[28];
  for (c3_i69 = 0; c3_i69 < 2; c3_i69++) {
    c3_b_u.DATA.status.fullPos.elevation[c3_i69] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
      chartInstance->c3_u)[8])[5584])[168])[32])[c3_i69];
  }

  c3_b_u.DATA.status.fullPos.heading = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])
    [5584])[168])[36];
  for (c3_i70 = 0; c3_i70 < 2; c3_i70++) {
    c3_b_u.DATA.status.fullPos.speed[c3_i70] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
      chartInstance->c3_u)[8])[5584])[168])[40])[c3_i70];
  }

  for (c3_i71 = 0; c3_i71 < 4; c3_i71++) {
    c3_b_u.DATA.status.fullPos.posAccuracy[c3_i71] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
      chartInstance->c3_u)[8])[5584])[168])[42])[c3_i71];
  }

  c3_b_u.DATA.status.fullPos.timeConfidence = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])
    [5584])[168])[48];
  c3_b_u.DATA.status.fullPos.posConfidence = *(int8_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])
    [5584])[168])[52];
  c3_b_u.DATA.status.fullPos.speedConfidence = *(int8_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])
    [5584])[168])[53];
  c3_b_u.DATA.status.throttlePos = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[5584])[224];
  c3_b_u.DATA.status.speedHeadC = *(int8_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[5584])[228];
  c3_b_u.DATA.status.speedC = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[5584])[232];
  c3_b_u.DATA.status.vehicleData.height = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[5584])[240])[0];
  c3_b_u.DATA.status.vehicleData.bumpers.frnt = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_bumpers *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[5584])[240])[8])[0];
  c3_b_u.DATA.status.vehicleData.bumpers.rear = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_bumpers *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[5584])[240])[8])[4];
  c3_b_u.DATA.status.vehicleData.mass = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[5584])[240])[16];
  c3_b_u.DATA.status.vehicleData.trailerWeight = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[5584])[240])[20];
  c3_b_u.DATA.status.vehicleData.type = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[5584])[240])[24];
  for (c3_i72 = 0; c3_i72 < 63; c3_i72++) {
    c3_b_u.DATA.status.vehicleIdent.name[c3_i72] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c3_u)[8])[5584])[272])[0])[c3_i72];
  }

  for (c3_i73 = 0; c3_i73 < 17; c3_i73++) {
    c3_b_u.DATA.status.vehicleIdent.vin[c3_i73] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c3_u)[8])[5584])[272])[63])[c3_i73];
  }

  for (c3_i74 = 0; c3_i74 < 32; c3_i74++) {
    c3_b_u.DATA.status.vehicleIdent.ownerCode[c3_i74] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c3_u)[8])[5584])[272])[80])[c3_i74];
  }

  for (c3_i75 = 0; c3_i75 < 4; c3_i75++) {
    c3_b_u.DATA.status.vehicleIdent.id[c3_i75] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c3_u)[8])[5584])[272])[112])[c3_i75];
  }

  c3_b_u.DATA.status.vehicleIdent.vehicleType = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[5584])[272])[116];
  c3_b_u.DATA.status.vehicleIdent.vehicleClass.vGroup = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleClass *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[5584])[272])[120])[0];
  c3_b_u.DATA.status.vehicleIdent.vehicleClass.rGroup = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleClass *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[5584])[272])[120])[4];
  c3_b_u.DATA.status.vehicleIdent.vehicleClass.rEquip = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleClass *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[5584])[272])[120])[8];
  for (c3_i76 = 0; c3_i76 < 16; c3_i76++) {
    c3_b_u.DATA.status.j1939data.tires[c3_i76].location = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c3_u)[8])[5584])[408])[0])[32 * (int32_T)c3_i76])
      [0];
    c3_b_u.DATA.status.j1939data.tires[c3_i76].pressure = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c3_u)[8])[5584])[408])[0])[32 * (int32_T)c3_i76])
      [4];
    c3_b_u.DATA.status.j1939data.tires[c3_i76].temp = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c3_u)[8])[5584])[408])[0])[32 * (int32_T)c3_i76])
      [8];
    c3_b_u.DATA.status.j1939data.tires[c3_i76].wheelSensorStatus = *(int32_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])
           [5584])[408])[0])[32 * (int32_T)c3_i76])[12];
    c3_b_u.DATA.status.j1939data.tires[c3_i76].wheelEndElectFault = *(int32_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])
           [5584])[408])[0])[32 * (int32_T)c3_i76])[16];
    c3_b_u.DATA.status.j1939data.tires[c3_i76].leakageRate = *(int32_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)[8])
           [5584])[408])[0])[32 * (int32_T)c3_i76])[20];
    c3_b_u.DATA.status.j1939data.tires[c3_i76].detection = *(int32_T *)&((char_T
      *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c3_u)[8])[5584])[408])[0])[32 * (int32_T)c3_i76])
      [24];
  }

  for (c3_i77 = 0; c3_i77 < 16; c3_i77++) {
    c3_b_u.DATA.status.j1939data.axle[c3_i77].location = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_axle *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_axle *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c3_u)[8])[5584])[408])[512])[8 * (int32_T)
      c3_i77])[0];
    c3_b_u.DATA.status.j1939data.axle[c3_i77].weight = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_axle *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_axle *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c3_u)[8])[5584])[408])[512])[8 * (int32_T)
      c3_i77])[4];
  }

  c3_b_u.DATA.status.j1939data.trailerWeight = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)
        [8])[5584])[408])[640];
  c3_b_u.DATA.status.j1939data.cargoWeight = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)
        [8])[5584])[408])[644];
  c3_b_u.DATA.status.j1939data.steeringAxleTemperature = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)
        [8])[5584])[408])[648];
  c3_b_u.DATA.status.j1939data.driveAxleLocation = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)
        [8])[5584])[408])[652];
  c3_b_u.DATA.status.j1939data.driveAxleLiftAirPressure = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)
        [8])[5584])[408])[656];
  c3_b_u.DATA.status.j1939data.driveAxleTemperature = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)
        [8])[5584])[408])[660];
  c3_b_u.DATA.status.j1939data.driveAxleLubePressure = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)
        [8])[5584])[408])[664];
  c3_b_u.DATA.status.j1939data.steeringAxleLubePressure = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c3_u)
        [8])[5584])[408])[668];
  c3_b_u.DATA.status.weatherReport.isRaining = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[5584])[1080])[0];
  c3_b_u.DATA.status.weatherReport.rainRate = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[5584])[1080])[4];
  c3_b_u.DATA.status.weatherReport.precipSituation = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[5584])[1080])[8];
  c3_b_u.DATA.status.weatherReport.solarRadiation = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[5584])[1080])[12];
  c3_b_u.DATA.status.weatherReport.friction = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[5584])[1080])[16];
  c3_b_u.DATA.status.gpsStatus = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c3_u)[8])[5584])[1104];
  c3_b_z.HEADER.valid = *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)
    chartInstance->c3_z)[0])[0];
  c3_b_z.DATA.msgID = *(int32_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)chartInstance->c3_z)[8])[0];
  c3_b_z.DATA.msgCnt = *(int32_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)chartInstance->c3_z)[8])[4];
  for (c3_i78 = 0; c3_i78 < 4; c3_i78++) {
    c3_b_z.DATA.id[c3_i78] = ((int8_T *)&((char_T *)
      (c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)chartInstance->c3_z)[8])[8])
      [c3_i78];
  }

  c3_b_z.DATA.secMark = *(int32_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)chartInstance->c3_z)[8])[12];
  c3_b_z.DATA.latitude = *(int32_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)chartInstance->c3_z)[8])[16];
  c3_b_z.DATA.longitude = *(int32_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)chartInstance->c3_z)[8])[20];
  for (c3_i79 = 0; c3_i79 < 2; c3_i79++) {
    c3_b_z.DATA.elev[c3_i79] = ((int8_T *)&((char_T *)
      (c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)chartInstance->c3_z)[8])[24])
      [c3_i79];
  }

  for (c3_i80 = 0; c3_i80 < 4; c3_i80++) {
    c3_b_z.DATA.accuracy[c3_i80] = ((int8_T *)&((char_T *)
      (c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)chartInstance->c3_z)[8])[26])
      [c3_i80];
  }

  for (c3_i81 = 0; c3_i81 < 2; c3_i81++) {
    c3_b_z.DATA.speed[c3_i81] = ((int8_T *)&((char_T *)
      (c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)chartInstance->c3_z)[8])[30])
      [c3_i81];
  }

  c3_b_z.DATA.heading = *(int32_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)chartInstance->c3_z)[8])[32];
  c3_b_z.DATA.angle = *(int8_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)chartInstance->c3_z)[8])[36];
  for (c3_i82 = 0; c3_i82 < 7; c3_i82++) {
    c3_b_z.DATA.accelSet[c3_i82] = ((int8_T *)&((char_T *)
      (c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)chartInstance->c3_z)[8])[37])
      [c3_i82];
  }

  for (c3_i83 = 0; c3_i83 < 2; c3_i83++) {
    c3_b_z.DATA.brakes[c3_i83] = ((int8_T *)&((char_T *)
      (c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)chartInstance->c3_z)[8])[44])
      [c3_i83];
  }

  c3_b_z.DATA.size.width = *(int32_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_size
    *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
    chartInstance->c3_z)[8])[48])[0];
  c3_b_z.DATA.size.length = *(int32_T *)&((char_T *)
    (c3_PRESCAN_V2X_USER_BSM_size *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)chartInstance->c3_z)[8])[48])[4];
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_b_u, 2U, c3_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_b_z, 3U, c3_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_y, 4U, c3_c_sf_marshallOut,
    c3_b_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_c_y = c3_b_u;
  c3_c_z = c3_b_z;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c3_f_debug_family_names,
    c3_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_y, 2U, c3_b_sf_marshallOut,
    c3_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_z, 3U, c3_c_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_y, 4U, c3_c_sf_marshallOut,
    c3_b_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 3);
  c3_b_y = c3_c_z;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_c_u = c3_b_y;
  c3_d_y = c3_c_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 5U, c3_e_debug_family_names,
    c3_c_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_u, 2U, c3_c_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_y, 3U, c3_b_sf_marshallOut,
    c3_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_y, MAX_uint32_T,
    c3_c_sf_marshallOut, c3_b_sf_marshallIn);
  c3_b_y = c3_c_u;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  CV_SCRIPT_FCN(0, 1);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_d_u = c3_b_y.HEADER;
  c3_e_y = c3_d_y.HEADER;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 5U, c3_b_debug_family_names,
    c3_d_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_u, 2U, c3_d_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_y, 3U, c3_d_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_y.HEADER, MAX_uint32_T,
    c3_d_sf_marshallOut, c3_c_sf_marshallIn);
  c3_b_y.HEADER = c3_d_u;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  CV_SCRIPT_FCN(0, 2);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 13);
  c3_b_y.HEADER.valid = c3_e_y.valid;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -13);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 9);
  c3_e_u = c3_b_y.DATA;
  c3_f_y = c3_d_y.DATA;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 5U, c3_d_debug_family_names,
    c3_e_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_u, 2U, c3_g_sf_marshallOut,
    c3_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_y, 3U, c3_h_sf_marshallOut,
    c3_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_y.DATA, MAX_uint32_T,
    c3_g_sf_marshallOut, c3_f_sf_marshallIn);
  c3_b_y.DATA = c3_e_u;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  CV_SCRIPT_FCN(0, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 17);
  c3_b_y.DATA.msgID = c3_f_y.msgID;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 18);
  c3_b_y.DATA.msgCnt = c3_f_y.msgCnt;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 19);
  for (c3_i84 = 0; c3_i84 < 4; c3_i84++) {
    c3_b_y.DATA.id[c3_i84] = c3_f_y.id[c3_i84];
  }

  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 20);
  c3_b_y.DATA.secMark = c3_f_y.secMark;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 21);
  c3_b_y.DATA.latitude = c3_f_y.latitude;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 22);
  c3_b_y.DATA.longitude = c3_f_y.longitude;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 23);
  for (c3_i85 = 0; c3_i85 < 2; c3_i85++) {
    c3_b_y.DATA.elev[c3_i85] = c3_f_y.elev[c3_i85];
  }

  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 24);
  for (c3_i86 = 0; c3_i86 < 4; c3_i86++) {
    c3_b_y.DATA.accuracy[c3_i86] = c3_f_y.accuracy[c3_i86];
  }

  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 25);
  for (c3_i87 = 0; c3_i87 < 2; c3_i87++) {
    c3_b_y.DATA.speed[c3_i87] = c3_f_y.speed[c3_i87];
  }

  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 26);
  c3_b_y.DATA.heading = c3_f_y.heading;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 27);
  c3_b_y.DATA.angle = c3_f_y.angle;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 28);
  for (c3_i88 = 0; c3_i88 < 7; c3_i88++) {
    c3_b_y.DATA.accelSet[c3_i88] = c3_f_y.accelSet[c3_i88];
  }

  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 29);
  for (c3_i89 = 0; c3_i89 < 2; c3_i89++) {
    c3_b_y.DATA.brakes[c3_i89] = c3_f_y.brakes[c3_i89];
  }

  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 30);
  c3_f_u = c3_b_y.DATA.size;
  c3_g_y = c3_f_y.size;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 5U, c3_c_debug_family_names,
    c3_f_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_u, 2U, c3_e_sf_marshallOut,
    c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_y, 3U, c3_f_sf_marshallOut,
    c3_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_y.DATA.size, MAX_uint32_T,
    c3_e_sf_marshallOut, c3_d_sf_marshallIn);
  c3_b_y.DATA.size = c3_f_u;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  CV_SCRIPT_FCN(0, 4);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 34);
  c3_b_y.DATA.size.width = c3_g_y.width;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 35);
  c3_b_y.DATA.size.length = c3_g_y.length;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -35);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -30);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -9);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -4);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -4);
  _SFD_SYMBOL_SCOPE_POP();
  *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)chartInstance->c3_y)[0])
    [0] = c3_b_y.HEADER.valid;
  *(int32_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
    chartInstance->c3_y)[8])[0] = c3_b_y.DATA.msgID;
  *(int32_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
    chartInstance->c3_y)[8])[4] = c3_b_y.DATA.msgCnt;
  for (c3_i90 = 0; c3_i90 < 4; c3_i90++) {
    ((int8_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
       chartInstance->c3_y)[8])[8])[c3_i90] = c3_b_y.DATA.id[c3_i90];
  }

  *(int32_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
    chartInstance->c3_y)[8])[12] = c3_b_y.DATA.secMark;
  *(int32_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
    chartInstance->c3_y)[8])[16] = c3_b_y.DATA.latitude;
  *(int32_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
    chartInstance->c3_y)[8])[20] = c3_b_y.DATA.longitude;
  for (c3_i91 = 0; c3_i91 < 2; c3_i91++) {
    ((int8_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
       chartInstance->c3_y)[8])[24])[c3_i91] = c3_b_y.DATA.elev[c3_i91];
  }

  for (c3_i92 = 0; c3_i92 < 4; c3_i92++) {
    ((int8_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
       chartInstance->c3_y)[8])[26])[c3_i92] = c3_b_y.DATA.accuracy[c3_i92];
  }

  for (c3_i93 = 0; c3_i93 < 2; c3_i93++) {
    ((int8_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
       chartInstance->c3_y)[8])[30])[c3_i93] = c3_b_y.DATA.speed[c3_i93];
  }

  *(int32_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
    chartInstance->c3_y)[8])[32] = c3_b_y.DATA.heading;
  *(int8_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
    chartInstance->c3_y)[8])[36] = c3_b_y.DATA.angle;
  for (c3_i94 = 0; c3_i94 < 7; c3_i94++) {
    ((int8_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
       chartInstance->c3_y)[8])[37])[c3_i94] = c3_b_y.DATA.accelSet[c3_i94];
  }

  for (c3_i95 = 0; c3_i95 < 2; c3_i95++) {
    ((int8_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
       chartInstance->c3_y)[8])[44])[c3_i95] = c3_b_y.DATA.brakes[c3_i95];
  }

  *(int32_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_size *)&((char_T *)
    (c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)chartInstance->c3_y)[8])[48])[0]
    = c3_b_y.DATA.size.width;
  *(int32_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_size *)&((char_T *)
    (c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)chartInstance->c3_y)[8])[48])[4]
    = c3_b_y.DATA.size.length;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
}

static void mdl_start_c3_Jan22_DLforACC_cs(SFc3_Jan22_DLforACC_csInstanceStruct *
  chartInstance)
{
  chartInstance->c3_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sim_mode_is_external(chartInstance->S);
}

static void initSimStructsc3_Jan22_DLforACC_cs
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber)
{
  (void)(c3_machineNumber);
  (void)(c3_chartNumber);
  (void)(c3_instanceNumber);
  _SFD_SCRIPT_TRANSLATION(c3_chartNumber, c3_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\s2lohras\\PreScan_Experiments\\Jan22_DLforACC\\V2X_BSM_filter.m"));
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  real_T c3_b_u;
  const mxArray *c3_b_y = NULL;
  SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc3_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_b_u = *(real_T *)c3_inData;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_b_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_b_y;
  real_T c3_d0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_b_y = c3_d0;
  sf_mex_destroy(&c3_b_u);
  return c3_b_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_nargin;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_b_y;
  SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc3_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c3_nargin = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_y = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargin), &c3_thisId);
  sf_mex_destroy(&c3_nargin);
  *(real_T *)c3_outData = c3_b_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_emlrt_marshallOut(SFc3_Jan22_DLforACC_csInstanceStruct *
  chartInstance, const PRESCAN_V2X_FIXED_BSM_DATA *c3_b_u)
{
  const mxArray *c3_b_y;
  static const char * c3_sv9[16] = { "msgID", "msgCnt", "id", "secMark",
    "latitude", "longitude", "elev", "accuracy", "speed", "heading", "angle",
    "accelSet", "brakes", "size", "safetyExt", "status" };

  int32_T c3_c_u;
  const mxArray *c3_c_y = NULL;
  int32_T c3_d_u;
  const mxArray *c3_d_y = NULL;
  int32_T c3_i96;
  const mxArray *c3_e_y = NULL;
  int8_T c3_e_u[4];
  int32_T c3_f_u;
  const mxArray *c3_f_y = NULL;
  int32_T c3_g_u;
  const mxArray *c3_g_y = NULL;
  int32_T c3_h_u;
  const mxArray *c3_h_y = NULL;
  int32_T c3_i97;
  const mxArray *c3_i_y = NULL;
  int8_T c3_i_u[2];
  int32_T c3_i98;
  const mxArray *c3_j_y = NULL;
  int32_T c3_i99;
  const mxArray *c3_k_y = NULL;
  int32_T c3_j_u;
  const mxArray *c3_l_y = NULL;
  int8_T c3_k_u;
  const mxArray *c3_m_y = NULL;
  int32_T c3_i100;
  const mxArray *c3_n_y = NULL;
  int8_T c3_l_u[7];
  int32_T c3_i101;
  const mxArray *c3_o_y = NULL;
  PRESCAN_V2X_FIXED_BSM_size c3_m_u;
  const mxArray *c3_p_y = NULL;
  int32_T c3_n_u;
  const mxArray *c3_q_y = NULL;
  int32_T c3_o_u;
  const mxArray *c3_r_y = NULL;
  c3_b_y = NULL;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_createstruct("structure", 16, c3_sv9, 2, 1, 1),
                false);
  c3_c_u = c3_b_u->msgID;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_c_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "msgID", c3_c_y, 0);
  c3_d_u = c3_b_u->msgCnt;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_d_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "msgCnt", c3_d_y, 1);
  for (c3_i96 = 0; c3_i96 < 4; c3_i96++) {
    c3_e_u[c3_i96] = c3_b_u->id[c3_i96];
  }

  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", c3_e_u, 2, 0U, 1U, 0U, 1, 4), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "id", c3_e_y, 2);
  c3_f_u = c3_b_u->secMark;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_f_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "secMark", c3_f_y, 3);
  c3_g_u = c3_b_u->latitude;
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_g_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "latitude", c3_g_y, 4);
  c3_h_u = c3_b_u->longitude;
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", &c3_h_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "longitude", c3_h_y, 5);
  for (c3_i97 = 0; c3_i97 < 2; c3_i97++) {
    c3_i_u[c3_i97] = c3_b_u->elev[c3_i97];
  }

  c3_i_y = NULL;
  sf_mex_assign(&c3_i_y, sf_mex_create("y", c3_i_u, 2, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "elev", c3_i_y, 6);
  for (c3_i98 = 0; c3_i98 < 4; c3_i98++) {
    c3_e_u[c3_i98] = c3_b_u->accuracy[c3_i98];
  }

  c3_j_y = NULL;
  sf_mex_assign(&c3_j_y, sf_mex_create("y", c3_e_u, 2, 0U, 1U, 0U, 1, 4), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "accuracy", c3_j_y, 7);
  for (c3_i99 = 0; c3_i99 < 2; c3_i99++) {
    c3_i_u[c3_i99] = c3_b_u->speed[c3_i99];
  }

  c3_k_y = NULL;
  sf_mex_assign(&c3_k_y, sf_mex_create("y", c3_i_u, 2, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "speed", c3_k_y, 8);
  c3_j_u = c3_b_u->heading;
  c3_l_y = NULL;
  sf_mex_assign(&c3_l_y, sf_mex_create("y", &c3_j_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "heading", c3_l_y, 9);
  c3_k_u = c3_b_u->angle;
  c3_m_y = NULL;
  sf_mex_assign(&c3_m_y, sf_mex_create("y", &c3_k_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "angle", c3_m_y, 10);
  for (c3_i100 = 0; c3_i100 < 7; c3_i100++) {
    c3_l_u[c3_i100] = c3_b_u->accelSet[c3_i100];
  }

  c3_n_y = NULL;
  sf_mex_assign(&c3_n_y, sf_mex_create("y", c3_l_u, 2, 0U, 1U, 0U, 1, 7), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "accelSet", c3_n_y, 11);
  for (c3_i101 = 0; c3_i101 < 2; c3_i101++) {
    c3_i_u[c3_i101] = c3_b_u->brakes[c3_i101];
  }

  c3_o_y = NULL;
  sf_mex_assign(&c3_o_y, sf_mex_create("y", c3_i_u, 2, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "brakes", c3_o_y, 12);
  c3_m_u = c3_b_u->size;
  c3_p_y = NULL;
  sf_mex_assign(&c3_p_y, sf_mex_createstruct("structure", 2, c3_sv1, 2, 1, 1),
                false);
  c3_n_u = c3_m_u.width;
  c3_q_y = NULL;
  sf_mex_assign(&c3_q_y, sf_mex_create("y", &c3_n_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_p_y, 0, "width", c3_q_y, 0);
  c3_o_u = c3_m_u.length;
  c3_r_y = NULL;
  sf_mex_assign(&c3_r_y, sf_mex_create("y", &c3_o_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_p_y, 0, "length", c3_r_y, 1);
  sf_mex_setfieldbynum(c3_b_y, 0, "size", c3_p_y, 13);
  sf_mex_setfieldbynum(c3_b_y, 0, "safetyExt", c3_d_emlrt_marshallOut
                       (chartInstance, &c3_b_u->safetyExt), 14);
  sf_mex_setfieldbynum(c3_b_y, 0, "status", c3_f_emlrt_marshallOut(chartInstance,
    &c3_b_u->status), 15);
  return c3_b_y;
}

static const mxArray *c3_b_emlrt_marshallOut
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const int32_T c3_b_u)
{
  const mxArray *c3_b_y = NULL;
  (void)chartInstance;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 6, 0U, 0U, 0U, 0), false);
  return c3_b_y;
}

static const mxArray *c3_c_emlrt_marshallOut
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const int8_T c3_b_u[2])
{
  const mxArray *c3_b_y = NULL;
  (void)chartInstance;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_b_u, 2, 0U, 1U, 0U, 1, 2), false);
  return c3_b_y;
}

static const mxArray *c3_d_emlrt_marshallOut
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const
   PRESCAN_V2X_FIXED_BSM_safetyExt *c3_b_u)
{
  const mxArray *c3_b_y;
  static const char * c3_sv10[4] = { "events", "pathHistory", "pathPrediction",
    "theRTCM" };

  int32_T c3_c_u;
  const mxArray *c3_c_y = NULL;
  PRESCAN_V2X_FIXED_BSM_pathHistory c3_d_u;
  const mxArray *c3_d_y = NULL;
  static const char * c3_sv11[4] = { "initialPosition", "currGPSstatus",
    "itemCnt", "crumbData" };

  PRESCAN_V2X_FIXED_BSM_initialPosition c3_e_u;
  const mxArray *c3_e_y = NULL;
  int32_T c3_f_u;
  const mxArray *c3_f_y = NULL;
  int32_T c3_g_u;
  const mxArray *c3_g_y = NULL;
  int32_T c3_i102;
  const mxArray *c3_h_y = NULL;
  int8_T c3_h_u[2];
  int32_T c3_i_u;
  const mxArray *c3_i_y = NULL;
  int32_T c3_i103;
  const mxArray *c3_j_y = NULL;
  int32_T c3_i104;
  const mxArray *c3_k_y = NULL;
  int8_T c3_j_u[4];
  int32_T c3_k_u;
  const mxArray *c3_l_y = NULL;
  int8_T c3_l_u;
  const mxArray *c3_m_y = NULL;
  int8_T c3_m_u;
  const mxArray *c3_n_y = NULL;
  int32_T c3_n_u;
  const mxArray *c3_o_y = NULL;
  int32_T c3_o_u;
  const mxArray *c3_p_y = NULL;
  PRESCAN_V2X_FIXED_BSM_crumbData c3_p_u;
  const mxArray *c3_q_y = NULL;
  static const char * c3_sv12[10] = { "pathHistoryPointSets_01",
    "pathHistoryPointSets_02", "pathHistoryPointSets_03",
    "pathHistoryPointSets_04", "pathHistoryPointSets_05",
    "pathHistoryPointSets_06", "pathHistoryPointSets_07",
    "pathHistoryPointSets_08", "pathHistoryPointSets_09",
    "pathHistoryPointSets_10" };

  int32_T c3_i105;
  const mxArray *c3_r_y = NULL;
  PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 c3_q_u[23];
  int32_T c3_iv0[1];
  static const char * c3_sv13[7] = { "latOffset", "longOffset",
    "elevationOffset", "timeOffset", "posAccuracy", "heading", "speed" };

  int32_T c3_i106;
  const PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *c3_r2;
  int32_T c3_i107;
  int32_T c3_r_u;
  const mxArray *c3_s_y = NULL;
  const mxArray *c3_t_y = NULL;
  int8_T c3_s_u[345];
  int32_T c3_t_u;
  const mxArray *c3_u_y = NULL;
  int32_T c3_i108;
  int32_T c3_u_u;
  const mxArray *c3_v_y = NULL;
  int8_T c3_v_u[276];
  const mxArray *c3_w_y = NULL;
  int32_T c3_i109;
  int32_T c3_w_u;
  const mxArray *c3_x_y = NULL;
  const mxArray *c3_y_y = NULL;
  int8_T c3_x_u[184];
  int32_T c3_i110;
  int32_T c3_i111;
  const mxArray *c3_ab_y = NULL;
  const mxArray *c3_bb_y = NULL;
  int8_T c3_y_u[230];
  int32_T c3_ab_u;
  const mxArray *c3_cb_y = NULL;
  int32_T c3_i112;
  int32_T c3_i113;
  const mxArray *c3_db_y = NULL;
  int8_T c3_bb_u[138];
  const mxArray *c3_eb_y = NULL;
  int32_T c3_i114;
  const mxArray *c3_fb_y = NULL;
  int8_T c3_cb_u[242];
  int32_T c3_i115;
  const mxArray *c3_gb_y = NULL;
  int8_T c3_db_u[161];
  int32_T c3_i116;
  const mxArray *c3_hb_y = NULL;
  int8_T c3_eb_u[196];
  int32_T c3_i117;
  const mxArray *c3_ib_y = NULL;
  int8_T c3_fb_u[104];
  PRESCAN_V2X_FIXED_BSM_pathPrediction c3_gb_u;
  const mxArray *c3_jb_y = NULL;
  static const char * c3_sv14[2] = { "radiusOfCurve", "confidence" };

  int32_T c3_hb_u;
  const mxArray *c3_kb_y = NULL;
  int32_T c3_ib_u;
  const mxArray *c3_lb_y = NULL;
  PRESCAN_V2X_FIXED_BSM_theRTCM c3_jb_u;
  const mxArray *c3_mb_y = NULL;
  static const char * c3_sv15[32] = { "anchorPoint", "rtcmHeader", "msg1001",
    "msg1002", "msg1003", "msg1004", "msg1005", "msg1006", "msg1007", "msg1008",
    "msg1009", "msg1010", "msg1011", "msg1012", "msg1013", "msg1014", "msg1015",
    "msg1016", "msg1017", "msg1019", "msg1020", "msg1021", "msg1022", "msg1023",
    "msg1024", "msg1025", "msg1026", "msg1027", "msg1029", "msg1030", "msg1031",
    "msg1032" };

  PRESCAN_V2X_FIXED_BSM_anchorPoint c3_kb_u;
  const mxArray *c3_nb_y = NULL;
  int32_T c3_lb_u;
  const mxArray *c3_ob_y = NULL;
  int32_T c3_mb_u;
  const mxArray *c3_pb_y = NULL;
  int32_T c3_i118;
  const mxArray *c3_qb_y = NULL;
  int32_T c3_nb_u;
  const mxArray *c3_rb_y = NULL;
  int32_T c3_i119;
  const mxArray *c3_sb_y = NULL;
  int32_T c3_i120;
  const mxArray *c3_tb_y = NULL;
  int32_T c3_ob_u;
  const mxArray *c3_ub_y = NULL;
  int8_T c3_pb_u;
  const mxArray *c3_vb_y = NULL;
  int8_T c3_qb_u;
  const mxArray *c3_wb_y = NULL;
  int32_T c3_i121;
  const mxArray *c3_xb_y = NULL;
  int8_T c3_rb_u[5];
  int32_T c3_i122;
  const mxArray *c3_yb_y = NULL;
  int8_T c3_sb_u[124];
  int32_T c3_i123;
  const mxArray *c3_ac_y = NULL;
  int8_T c3_tb_u[156];
  int32_T c3_i124;
  const mxArray *c3_bc_y = NULL;
  int8_T c3_ub_u[210];
  int32_T c3_i125;
  const mxArray *c3_cc_y = NULL;
  int8_T c3_vb_u[258];
  int32_T c3_i126;
  const mxArray *c3_dc_y = NULL;
  int8_T c3_wb_u[19];
  int32_T c3_i127;
  const mxArray *c3_ec_y = NULL;
  int8_T c3_xb_u[21];
  int32_T c3_i128;
  const mxArray *c3_fc_y = NULL;
  int8_T c3_yb_u[36];
  int32_T c3_i129;
  const mxArray *c3_gc_y = NULL;
  int8_T c3_ac_u[68];
  int32_T c3_i130;
  const mxArray *c3_hc_y = NULL;
  int8_T c3_bc_u[136];
  int32_T c3_i131;
  const mxArray *c3_ic_y = NULL;
  int8_T c3_cc_u[166];
  int32_T c3_i132;
  const mxArray *c3_jc_y = NULL;
  int8_T c3_dc_u[222];
  int32_T c3_i133;
  const mxArray *c3_kc_y = NULL;
  int8_T c3_ec_u[268];
  int32_T c3_i134;
  const mxArray *c3_lc_y = NULL;
  int8_T c3_fc_u[27];
  int32_T c3_i135;
  const mxArray *c3_mc_y = NULL;
  int8_T c3_gc_u[15];
  int32_T c3_i136;
  const mxArray *c3_nc_y = NULL;
  int8_T c3_hc_u[69];
  int32_T c3_i137;
  const mxArray *c3_oc_y = NULL;
  int8_T c3_ic_u[81];
  int32_T c3_i138;
  const mxArray *c3_pc_y = NULL;
  int8_T c3_jc_u[115];
  int32_T c3_i139;
  const mxArray *c3_qc_y = NULL;
  int8_T c3_kc_u[62];
  int32_T c3_i140;
  const mxArray *c3_rc_y = NULL;
  int8_T c3_lc_u[45];
  int32_T c3_i141;
  const mxArray *c3_sc_y = NULL;
  int32_T c3_i142;
  const mxArray *c3_tc_y = NULL;
  int8_T c3_mc_u[75];
  int32_T c3_i143;
  const mxArray *c3_uc_y = NULL;
  int8_T c3_nc_u[73];
  int32_T c3_i144;
  const mxArray *c3_vc_y = NULL;
  int8_T c3_oc_u[74];
  int32_T c3_i145;
  const mxArray *c3_wc_y = NULL;
  int8_T c3_pc_u[25];
  int32_T c3_i146;
  const mxArray *c3_xc_y = NULL;
  int8_T c3_qc_u[30];
  int32_T c3_i147;
  const mxArray *c3_yc_y = NULL;
  int8_T c3_rc_u[33];
  int32_T c3_i148;
  const mxArray *c3_ad_y = NULL;
  int32_T c3_i149;
  const mxArray *c3_bd_y = NULL;
  int8_T c3_sc_u[105];
  int32_T c3_i150;
  const mxArray *c3_cd_y = NULL;
  int8_T c3_tc_u[107];
  int32_T c3_i151;
  const mxArray *c3_dd_y = NULL;
  int8_T c3_uc_u[20];
  c3_b_y = NULL;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_createstruct("structure", 4, c3_sv10, 2, 1, 1),
                false);
  c3_c_u = c3_b_u->events;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_c_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "events", c3_c_y, 0);
  c3_d_u = c3_b_u->pathHistory;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_createstruct("structure", 4, c3_sv11, 2, 1, 1),
                false);
  c3_e_u = c3_d_u.initialPosition;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_createstruct("structure", 10, c3_sv2, 2, 1, 1),
                false);
  sf_mex_setfieldbynum(c3_e_y, 0, "utcTime", c3_e_emlrt_marshallOut
                       (chartInstance, c3_e_u.utcTime), 0);
  c3_f_u = c3_e_u.longitude;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_f_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_e_y, 0, "longitude", c3_f_y, 1);
  c3_g_u = c3_e_u.latitude;
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_g_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_e_y, 0, "latitude", c3_g_y, 2);
  for (c3_i102 = 0; c3_i102 < 2; c3_i102++) {
    c3_h_u[c3_i102] = c3_e_u.elevation[c3_i102];
  }

  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", c3_h_u, 2, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setfieldbynum(c3_e_y, 0, "elevation", c3_h_y, 3);
  c3_i_u = c3_e_u.heading;
  c3_i_y = NULL;
  sf_mex_assign(&c3_i_y, sf_mex_create("y", &c3_i_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_e_y, 0, "heading", c3_i_y, 4);
  for (c3_i103 = 0; c3_i103 < 2; c3_i103++) {
    c3_h_u[c3_i103] = c3_e_u.speed[c3_i103];
  }

  c3_j_y = NULL;
  sf_mex_assign(&c3_j_y, sf_mex_create("y", c3_h_u, 2, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setfieldbynum(c3_e_y, 0, "speed", c3_j_y, 5);
  for (c3_i104 = 0; c3_i104 < 4; c3_i104++) {
    c3_j_u[c3_i104] = c3_e_u.posAccuracy[c3_i104];
  }

  c3_k_y = NULL;
  sf_mex_assign(&c3_k_y, sf_mex_create("y", c3_j_u, 2, 0U, 1U, 0U, 1, 4), false);
  sf_mex_setfieldbynum(c3_e_y, 0, "posAccuracy", c3_k_y, 6);
  c3_k_u = c3_e_u.timeConfidence;
  c3_l_y = NULL;
  sf_mex_assign(&c3_l_y, sf_mex_create("y", &c3_k_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_e_y, 0, "timeConfidence", c3_l_y, 7);
  c3_l_u = c3_e_u.posConfidence;
  c3_m_y = NULL;
  sf_mex_assign(&c3_m_y, sf_mex_create("y", &c3_l_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_e_y, 0, "posConfidence", c3_m_y, 8);
  c3_m_u = c3_e_u.speedConfidence;
  c3_n_y = NULL;
  sf_mex_assign(&c3_n_y, sf_mex_create("y", &c3_m_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_e_y, 0, "speedConfidence", c3_n_y, 9);
  sf_mex_setfieldbynum(c3_d_y, 0, "initialPosition", c3_e_y, 0);
  c3_n_u = c3_d_u.currGPSstatus;
  c3_o_y = NULL;
  sf_mex_assign(&c3_o_y, sf_mex_create("y", &c3_n_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_d_y, 0, "currGPSstatus", c3_o_y, 1);
  c3_o_u = c3_d_u.itemCnt;
  c3_p_y = NULL;
  sf_mex_assign(&c3_p_y, sf_mex_create("y", &c3_o_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_d_y, 0, "itemCnt", c3_p_y, 2);
  c3_p_u = c3_d_u.crumbData;
  c3_q_y = NULL;
  sf_mex_assign(&c3_q_y, sf_mex_createstruct("structure", 10, c3_sv12, 2, 1, 1),
                false);
  for (c3_i105 = 0; c3_i105 < 23; c3_i105++) {
    c3_q_u[c3_i105] = c3_p_u.pathHistoryPointSets_01[c3_i105];
  }

  c3_r_y = NULL;
  c3_iv0[0] = 23;
  sf_mex_assign(&c3_r_y, sf_mex_createstructarray("structure", 1, c3_iv0, 7,
    c3_sv13), false);
  for (c3_i106 = 0; c3_i106 < 23; c3_i106++) {
    c3_r2 = &c3_q_u[c3_i106];
    c3_r_u = c3_r2->latOffset;
    c3_s_y = NULL;
    sf_mex_assign(&c3_s_y, sf_mex_create("y", &c3_r_u, 6, 0U, 0U, 0U, 0), false);
    sf_mex_setfieldbynum(c3_r_y, c3_i106, "latOffset", c3_s_y, 0);
    c3_t_u = c3_r2->longOffset;
    c3_u_y = NULL;
    sf_mex_assign(&c3_u_y, sf_mex_create("y", &c3_t_u, 6, 0U, 0U, 0U, 0), false);
    sf_mex_setfieldbynum(c3_r_y, c3_i106, "longOffset", c3_u_y, 1);
    c3_u_u = c3_r2->elevationOffset;
    c3_w_y = NULL;
    sf_mex_assign(&c3_w_y, sf_mex_create("y", &c3_u_u, 6, 0U, 0U, 0U, 0), false);
    sf_mex_setfieldbynum(c3_r_y, c3_i106, "elevationOffset", c3_w_y, 2);
    c3_w_u = c3_r2->timeOffset;
    c3_x_y = NULL;
    sf_mex_assign(&c3_x_y, sf_mex_create("y", &c3_w_u, 6, 0U, 0U, 0U, 0), false);
    sf_mex_setfieldbynum(c3_r_y, c3_i106, "timeOffset", c3_x_y, 3);
    for (c3_i110 = 0; c3_i110 < 4; c3_i110++) {
      c3_j_u[c3_i110] = c3_r2->posAccuracy[c3_i110];
    }

    c3_ab_y = NULL;
    sf_mex_assign(&c3_ab_y, sf_mex_create("y", c3_j_u, 2, 0U, 1U, 0U, 1, 4),
                  false);
    sf_mex_setfieldbynum(c3_r_y, c3_i106, "posAccuracy", c3_ab_y, 4);
    c3_ab_u = c3_r2->heading;
    c3_cb_y = NULL;
    sf_mex_assign(&c3_cb_y, sf_mex_create("y", &c3_ab_u, 6, 0U, 0U, 0U, 0),
                  false);
    sf_mex_setfieldbynum(c3_r_y, c3_i106, "heading", c3_cb_y, 5);
    for (c3_i113 = 0; c3_i113 < 2; c3_i113++) {
      c3_h_u[c3_i113] = c3_r2->speed[c3_i113];
    }

    c3_eb_y = NULL;
    sf_mex_assign(&c3_eb_y, sf_mex_create("y", c3_h_u, 2, 0U, 1U, 0U, 1, 2),
                  false);
    sf_mex_setfieldbynum(c3_r_y, c3_i106, "speed", c3_eb_y, 6);
  }

  sf_mex_setfieldbynum(c3_q_y, 0, "pathHistoryPointSets_01", c3_r_y, 0);
  for (c3_i107 = 0; c3_i107 < 345; c3_i107++) {
    c3_s_u[c3_i107] = c3_p_u.pathHistoryPointSets_02[c3_i107];
  }

  c3_t_y = NULL;
  sf_mex_assign(&c3_t_y, sf_mex_create("y", c3_s_u, 2, 0U, 1U, 0U, 1, 345),
                false);
  sf_mex_setfieldbynum(c3_q_y, 0, "pathHistoryPointSets_02", c3_t_y, 1);
  for (c3_i108 = 0; c3_i108 < 276; c3_i108++) {
    c3_v_u[c3_i108] = c3_p_u.pathHistoryPointSets_03[c3_i108];
  }

  c3_v_y = NULL;
  sf_mex_assign(&c3_v_y, sf_mex_create("y", c3_v_u, 2, 0U, 1U, 0U, 1, 276),
                false);
  sf_mex_setfieldbynum(c3_q_y, 0, "pathHistoryPointSets_03", c3_v_y, 2);
  for (c3_i109 = 0; c3_i109 < 184; c3_i109++) {
    c3_x_u[c3_i109] = c3_p_u.pathHistoryPointSets_04[c3_i109];
  }

  c3_y_y = NULL;
  sf_mex_assign(&c3_y_y, sf_mex_create("y", c3_x_u, 2, 0U, 1U, 0U, 1, 184),
                false);
  sf_mex_setfieldbynum(c3_q_y, 0, "pathHistoryPointSets_04", c3_y_y, 3);
  for (c3_i111 = 0; c3_i111 < 230; c3_i111++) {
    c3_y_u[c3_i111] = c3_p_u.pathHistoryPointSets_05[c3_i111];
  }

  c3_bb_y = NULL;
  sf_mex_assign(&c3_bb_y, sf_mex_create("y", c3_y_u, 2, 0U, 1U, 0U, 1, 230),
                false);
  sf_mex_setfieldbynum(c3_q_y, 0, "pathHistoryPointSets_05", c3_bb_y, 4);
  for (c3_i112 = 0; c3_i112 < 138; c3_i112++) {
    c3_bb_u[c3_i112] = c3_p_u.pathHistoryPointSets_06[c3_i112];
  }

  c3_db_y = NULL;
  sf_mex_assign(&c3_db_y, sf_mex_create("y", c3_bb_u, 2, 0U, 1U, 0U, 1, 138),
                false);
  sf_mex_setfieldbynum(c3_q_y, 0, "pathHistoryPointSets_06", c3_db_y, 5);
  for (c3_i114 = 0; c3_i114 < 242; c3_i114++) {
    c3_cb_u[c3_i114] = c3_p_u.pathHistoryPointSets_07[c3_i114];
  }

  c3_fb_y = NULL;
  sf_mex_assign(&c3_fb_y, sf_mex_create("y", c3_cb_u, 2, 0U, 1U, 0U, 1, 242),
                false);
  sf_mex_setfieldbynum(c3_q_y, 0, "pathHistoryPointSets_07", c3_fb_y, 6);
  for (c3_i115 = 0; c3_i115 < 161; c3_i115++) {
    c3_db_u[c3_i115] = c3_p_u.pathHistoryPointSets_08[c3_i115];
  }

  c3_gb_y = NULL;
  sf_mex_assign(&c3_gb_y, sf_mex_create("y", c3_db_u, 2, 0U, 1U, 0U, 1, 161),
                false);
  sf_mex_setfieldbynum(c3_q_y, 0, "pathHistoryPointSets_08", c3_gb_y, 7);
  for (c3_i116 = 0; c3_i116 < 196; c3_i116++) {
    c3_eb_u[c3_i116] = c3_p_u.pathHistoryPointSets_09[c3_i116];
  }

  c3_hb_y = NULL;
  sf_mex_assign(&c3_hb_y, sf_mex_create("y", c3_eb_u, 2, 0U, 1U, 0U, 1, 196),
                false);
  sf_mex_setfieldbynum(c3_q_y, 0, "pathHistoryPointSets_09", c3_hb_y, 8);
  for (c3_i117 = 0; c3_i117 < 104; c3_i117++) {
    c3_fb_u[c3_i117] = c3_p_u.pathHistoryPointSets_10[c3_i117];
  }

  c3_ib_y = NULL;
  sf_mex_assign(&c3_ib_y, sf_mex_create("y", c3_fb_u, 2, 0U, 1U, 0U, 1, 104),
                false);
  sf_mex_setfieldbynum(c3_q_y, 0, "pathHistoryPointSets_10", c3_ib_y, 9);
  sf_mex_setfieldbynum(c3_d_y, 0, "crumbData", c3_q_y, 3);
  sf_mex_setfieldbynum(c3_b_y, 0, "pathHistory", c3_d_y, 1);
  c3_gb_u = c3_b_u->pathPrediction;
  c3_jb_y = NULL;
  sf_mex_assign(&c3_jb_y, sf_mex_createstruct("structure", 2, c3_sv14, 2, 1, 1),
                false);
  c3_hb_u = c3_gb_u.radiusOfCurve;
  c3_kb_y = NULL;
  sf_mex_assign(&c3_kb_y, sf_mex_create("y", &c3_hb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_jb_y, 0, "radiusOfCurve", c3_kb_y, 0);
  c3_ib_u = c3_gb_u.confidence;
  c3_lb_y = NULL;
  sf_mex_assign(&c3_lb_y, sf_mex_create("y", &c3_ib_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_jb_y, 0, "confidence", c3_lb_y, 1);
  sf_mex_setfieldbynum(c3_b_y, 0, "pathPrediction", c3_jb_y, 2);
  c3_jb_u = c3_b_u->theRTCM;
  c3_mb_y = NULL;
  sf_mex_assign(&c3_mb_y, sf_mex_createstruct("structure", 32, c3_sv15, 2, 1, 1),
                false);
  c3_kb_u = c3_jb_u.anchorPoint;
  c3_nb_y = NULL;
  sf_mex_assign(&c3_nb_y, sf_mex_createstruct("structure", 10, c3_sv2, 2, 1, 1),
                false);
  sf_mex_setfieldbynum(c3_nb_y, 0, "utcTime", c3_e_emlrt_marshallOut
                       (chartInstance, c3_kb_u.utcTime), 0);
  c3_lb_u = c3_kb_u.longitude;
  c3_ob_y = NULL;
  sf_mex_assign(&c3_ob_y, sf_mex_create("y", &c3_lb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_nb_y, 0, "longitude", c3_ob_y, 1);
  c3_mb_u = c3_kb_u.latitude;
  c3_pb_y = NULL;
  sf_mex_assign(&c3_pb_y, sf_mex_create("y", &c3_mb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_nb_y, 0, "latitude", c3_pb_y, 2);
  for (c3_i118 = 0; c3_i118 < 2; c3_i118++) {
    c3_h_u[c3_i118] = c3_kb_u.elevation[c3_i118];
  }

  c3_qb_y = NULL;
  sf_mex_assign(&c3_qb_y, sf_mex_create("y", c3_h_u, 2, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setfieldbynum(c3_nb_y, 0, "elevation", c3_qb_y, 3);
  c3_nb_u = c3_kb_u.heading;
  c3_rb_y = NULL;
  sf_mex_assign(&c3_rb_y, sf_mex_create("y", &c3_nb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_nb_y, 0, "heading", c3_rb_y, 4);
  for (c3_i119 = 0; c3_i119 < 2; c3_i119++) {
    c3_h_u[c3_i119] = c3_kb_u.speed[c3_i119];
  }

  c3_sb_y = NULL;
  sf_mex_assign(&c3_sb_y, sf_mex_create("y", c3_h_u, 2, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setfieldbynum(c3_nb_y, 0, "speed", c3_sb_y, 5);
  for (c3_i120 = 0; c3_i120 < 4; c3_i120++) {
    c3_j_u[c3_i120] = c3_kb_u.posAccuracy[c3_i120];
  }

  c3_tb_y = NULL;
  sf_mex_assign(&c3_tb_y, sf_mex_create("y", c3_j_u, 2, 0U, 1U, 0U, 1, 4), false);
  sf_mex_setfieldbynum(c3_nb_y, 0, "posAccuracy", c3_tb_y, 6);
  c3_ob_u = c3_kb_u.timeConfidence;
  c3_ub_y = NULL;
  sf_mex_assign(&c3_ub_y, sf_mex_create("y", &c3_ob_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_nb_y, 0, "timeConfidence", c3_ub_y, 7);
  c3_pb_u = c3_kb_u.posConfidence;
  c3_vb_y = NULL;
  sf_mex_assign(&c3_vb_y, sf_mex_create("y", &c3_pb_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_nb_y, 0, "posConfidence", c3_vb_y, 8);
  c3_qb_u = c3_kb_u.speedConfidence;
  c3_wb_y = NULL;
  sf_mex_assign(&c3_wb_y, sf_mex_create("y", &c3_qb_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_nb_y, 0, "speedConfidence", c3_wb_y, 9);
  sf_mex_setfieldbynum(c3_mb_y, 0, "anchorPoint", c3_nb_y, 0);
  for (c3_i121 = 0; c3_i121 < 5; c3_i121++) {
    c3_rb_u[c3_i121] = c3_jb_u.rtcmHeader[c3_i121];
  }

  c3_xb_y = NULL;
  sf_mex_assign(&c3_xb_y, sf_mex_create("y", c3_rb_u, 2, 0U, 1U, 0U, 1, 5),
                false);
  sf_mex_setfieldbynum(c3_mb_y, 0, "rtcmHeader", c3_xb_y, 1);
  for (c3_i122 = 0; c3_i122 < 124; c3_i122++) {
    c3_sb_u[c3_i122] = c3_jb_u.msg1001[c3_i122];
  }

  c3_yb_y = NULL;
  sf_mex_assign(&c3_yb_y, sf_mex_create("y", c3_sb_u, 2, 0U, 1U, 0U, 1, 124),
                false);
  sf_mex_setfieldbynum(c3_mb_y, 0, "msg1001", c3_yb_y, 2);
  for (c3_i123 = 0; c3_i123 < 156; c3_i123++) {
    c3_tb_u[c3_i123] = c3_jb_u.msg1002[c3_i123];
  }

  c3_ac_y = NULL;
  sf_mex_assign(&c3_ac_y, sf_mex_create("y", c3_tb_u, 2, 0U, 1U, 0U, 1, 156),
                false);
  sf_mex_setfieldbynum(c3_mb_y, 0, "msg1002", c3_ac_y, 3);
  for (c3_i124 = 0; c3_i124 < 210; c3_i124++) {
    c3_ub_u[c3_i124] = c3_jb_u.msg1003[c3_i124];
  }

  c3_bc_y = NULL;
  sf_mex_assign(&c3_bc_y, sf_mex_create("y", c3_ub_u, 2, 0U, 1U, 0U, 1, 210),
                false);
  sf_mex_setfieldbynum(c3_mb_y, 0, "msg1003", c3_bc_y, 4);
  for (c3_i125 = 0; c3_i125 < 258; c3_i125++) {
    c3_vb_u[c3_i125] = c3_jb_u.msg1004[c3_i125];
  }

  c3_cc_y = NULL;
  sf_mex_assign(&c3_cc_y, sf_mex_create("y", c3_vb_u, 2, 0U, 1U, 0U, 1, 258),
                false);
  sf_mex_setfieldbynum(c3_mb_y, 0, "msg1004", c3_cc_y, 5);
  for (c3_i126 = 0; c3_i126 < 19; c3_i126++) {
    c3_wb_u[c3_i126] = c3_jb_u.msg1005[c3_i126];
  }

  c3_dc_y = NULL;
  sf_mex_assign(&c3_dc_y, sf_mex_create("y", c3_wb_u, 2, 0U, 1U, 0U, 1, 19),
                false);
  sf_mex_setfieldbynum(c3_mb_y, 0, "msg1005", c3_dc_y, 6);
  for (c3_i127 = 0; c3_i127 < 21; c3_i127++) {
    c3_xb_u[c3_i127] = c3_jb_u.msg1006[c3_i127];
  }

  c3_ec_y = NULL;
  sf_mex_assign(&c3_ec_y, sf_mex_create("y", c3_xb_u, 2, 0U, 1U, 0U, 1, 21),
                false);
  sf_mex_setfieldbynum(c3_mb_y, 0, "msg1006", c3_ec_y, 7);
  for (c3_i128 = 0; c3_i128 < 36; c3_i128++) {
    c3_yb_u[c3_i128] = c3_jb_u.msg1007[c3_i128];
  }

  c3_fc_y = NULL;
  sf_mex_assign(&c3_fc_y, sf_mex_create("y", c3_yb_u, 2, 0U, 1U, 0U, 1, 36),
                false);
  sf_mex_setfieldbynum(c3_mb_y, 0, "msg1007", c3_fc_y, 8);
  for (c3_i129 = 0; c3_i129 < 68; c3_i129++) {
    c3_ac_u[c3_i129] = c3_jb_u.msg1008[c3_i129];
  }

  c3_gc_y = NULL;
  sf_mex_assign(&c3_gc_y, sf_mex_create("y", c3_ac_u, 2, 0U, 1U, 0U, 1, 68),
                false);
  sf_mex_setfieldbynum(c3_mb_y, 0, "msg1008", c3_gc_y, 9);
  for (c3_i130 = 0; c3_i130 < 136; c3_i130++) {
    c3_bc_u[c3_i130] = c3_jb_u.msg1009[c3_i130];
  }

  c3_hc_y = NULL;
  sf_mex_assign(&c3_hc_y, sf_mex_create("y", c3_bc_u, 2, 0U, 1U, 0U, 1, 136),
                false);
  sf_mex_setfieldbynum(c3_mb_y, 0, "msg1009", c3_hc_y, 10);
  for (c3_i131 = 0; c3_i131 < 166; c3_i131++) {
    c3_cc_u[c3_i131] = c3_jb_u.msg1010[c3_i131];
  }

  c3_ic_y = NULL;
  sf_mex_assign(&c3_ic_y, sf_mex_create("y", c3_cc_u, 2, 0U, 1U, 0U, 1, 166),
                false);
  sf_mex_setfieldbynum(c3_mb_y, 0, "msg1010", c3_ic_y, 11);
  for (c3_i132 = 0; c3_i132 < 222; c3_i132++) {
    c3_dc_u[c3_i132] = c3_jb_u.msg1011[c3_i132];
  }

  c3_jc_y = NULL;
  sf_mex_assign(&c3_jc_y, sf_mex_create("y", c3_dc_u, 2, 0U, 1U, 0U, 1, 222),
                false);
  sf_mex_setfieldbynum(c3_mb_y, 0, "msg1011", c3_jc_y, 12);
  for (c3_i133 = 0; c3_i133 < 268; c3_i133++) {
    c3_ec_u[c3_i133] = c3_jb_u.msg1012[c3_i133];
  }

  c3_kc_y = NULL;
  sf_mex_assign(&c3_kc_y, sf_mex_create("y", c3_ec_u, 2, 0U, 1U, 0U, 1, 268),
                false);
  sf_mex_setfieldbynum(c3_mb_y, 0, "msg1012", c3_kc_y, 13);
  for (c3_i134 = 0; c3_i134 < 27; c3_i134++) {
    c3_fc_u[c3_i134] = c3_jb_u.msg1013[c3_i134];
  }

  c3_lc_y = NULL;
  sf_mex_assign(&c3_lc_y, sf_mex_create("y", c3_fc_u, 2, 0U, 1U, 0U, 1, 27),
                false);
  sf_mex_setfieldbynum(c3_mb_y, 0, "msg1013", c3_lc_y, 14);
  for (c3_i135 = 0; c3_i135 < 15; c3_i135++) {
    c3_gc_u[c3_i135] = c3_jb_u.msg1014[c3_i135];
  }

  c3_mc_y = NULL;
  sf_mex_assign(&c3_mc_y, sf_mex_create("y", c3_gc_u, 2, 0U, 1U, 0U, 1, 15),
                false);
  sf_mex_setfieldbynum(c3_mb_y, 0, "msg1014", c3_mc_y, 15);
  for (c3_i136 = 0; c3_i136 < 69; c3_i136++) {
    c3_hc_u[c3_i136] = c3_jb_u.msg1015[c3_i136];
  }

  c3_nc_y = NULL;
  sf_mex_assign(&c3_nc_y, sf_mex_create("y", c3_hc_u, 2, 0U, 1U, 0U, 1, 69),
                false);
  sf_mex_setfieldbynum(c3_mb_y, 0, "msg1015", c3_nc_y, 16);
  for (c3_i137 = 0; c3_i137 < 81; c3_i137++) {
    c3_ic_u[c3_i137] = c3_jb_u.msg1016[c3_i137];
  }

  c3_oc_y = NULL;
  sf_mex_assign(&c3_oc_y, sf_mex_create("y", c3_ic_u, 2, 0U, 1U, 0U, 1, 81),
                false);
  sf_mex_setfieldbynum(c3_mb_y, 0, "msg1016", c3_oc_y, 17);
  for (c3_i138 = 0; c3_i138 < 115; c3_i138++) {
    c3_jc_u[c3_i138] = c3_jb_u.msg1017[c3_i138];
  }

  c3_pc_y = NULL;
  sf_mex_assign(&c3_pc_y, sf_mex_create("y", c3_jc_u, 2, 0U, 1U, 0U, 1, 115),
                false);
  sf_mex_setfieldbynum(c3_mb_y, 0, "msg1017", c3_pc_y, 18);
  for (c3_i139 = 0; c3_i139 < 62; c3_i139++) {
    c3_kc_u[c3_i139] = c3_jb_u.msg1019[c3_i139];
  }

  c3_qc_y = NULL;
  sf_mex_assign(&c3_qc_y, sf_mex_create("y", c3_kc_u, 2, 0U, 1U, 0U, 1, 62),
                false);
  sf_mex_setfieldbynum(c3_mb_y, 0, "msg1019", c3_qc_y, 19);
  for (c3_i140 = 0; c3_i140 < 45; c3_i140++) {
    c3_lc_u[c3_i140] = c3_jb_u.msg1020[c3_i140];
  }

  c3_rc_y = NULL;
  sf_mex_assign(&c3_rc_y, sf_mex_create("y", c3_lc_u, 2, 0U, 1U, 0U, 1, 45),
                false);
  sf_mex_setfieldbynum(c3_mb_y, 0, "msg1020", c3_rc_y, 20);
  for (c3_i141 = 0; c3_i141 < 62; c3_i141++) {
    c3_kc_u[c3_i141] = c3_jb_u.msg1021[c3_i141];
  }

  c3_sc_y = NULL;
  sf_mex_assign(&c3_sc_y, sf_mex_create("y", c3_kc_u, 2, 0U, 1U, 0U, 1, 62),
                false);
  sf_mex_setfieldbynum(c3_mb_y, 0, "msg1021", c3_sc_y, 21);
  for (c3_i142 = 0; c3_i142 < 75; c3_i142++) {
    c3_mc_u[c3_i142] = c3_jb_u.msg1022[c3_i142];
  }

  c3_tc_y = NULL;
  sf_mex_assign(&c3_tc_y, sf_mex_create("y", c3_mc_u, 2, 0U, 1U, 0U, 1, 75),
                false);
  sf_mex_setfieldbynum(c3_mb_y, 0, "msg1022", c3_tc_y, 22);
  for (c3_i143 = 0; c3_i143 < 73; c3_i143++) {
    c3_nc_u[c3_i143] = c3_jb_u.msg1023[c3_i143];
  }

  c3_uc_y = NULL;
  sf_mex_assign(&c3_uc_y, sf_mex_create("y", c3_nc_u, 2, 0U, 1U, 0U, 1, 73),
                false);
  sf_mex_setfieldbynum(c3_mb_y, 0, "msg1023", c3_uc_y, 23);
  for (c3_i144 = 0; c3_i144 < 74; c3_i144++) {
    c3_oc_u[c3_i144] = c3_jb_u.msg1024[c3_i144];
  }

  c3_vc_y = NULL;
  sf_mex_assign(&c3_vc_y, sf_mex_create("y", c3_oc_u, 2, 0U, 1U, 0U, 1, 74),
                false);
  sf_mex_setfieldbynum(c3_mb_y, 0, "msg1024", c3_vc_y, 24);
  for (c3_i145 = 0; c3_i145 < 25; c3_i145++) {
    c3_pc_u[c3_i145] = c3_jb_u.msg1025[c3_i145];
  }

  c3_wc_y = NULL;
  sf_mex_assign(&c3_wc_y, sf_mex_create("y", c3_pc_u, 2, 0U, 1U, 0U, 1, 25),
                false);
  sf_mex_setfieldbynum(c3_mb_y, 0, "msg1025", c3_wc_y, 25);
  for (c3_i146 = 0; c3_i146 < 30; c3_i146++) {
    c3_qc_u[c3_i146] = c3_jb_u.msg1026[c3_i146];
  }

  c3_xc_y = NULL;
  sf_mex_assign(&c3_xc_y, sf_mex_create("y", c3_qc_u, 2, 0U, 1U, 0U, 1, 30),
                false);
  sf_mex_setfieldbynum(c3_mb_y, 0, "msg1026", c3_xc_y, 26);
  for (c3_i147 = 0; c3_i147 < 33; c3_i147++) {
    c3_rc_u[c3_i147] = c3_jb_u.msg1027[c3_i147];
  }

  c3_yc_y = NULL;
  sf_mex_assign(&c3_yc_y, sf_mex_create("y", c3_rc_u, 2, 0U, 1U, 0U, 1, 33),
                false);
  sf_mex_setfieldbynum(c3_mb_y, 0, "msg1027", c3_yc_y, 27);
  for (c3_i148 = 0; c3_i148 < 69; c3_i148++) {
    c3_hc_u[c3_i148] = c3_jb_u.msg1029[c3_i148];
  }

  c3_ad_y = NULL;
  sf_mex_assign(&c3_ad_y, sf_mex_create("y", c3_hc_u, 2, 0U, 1U, 0U, 1, 69),
                false);
  sf_mex_setfieldbynum(c3_mb_y, 0, "msg1029", c3_ad_y, 28);
  for (c3_i149 = 0; c3_i149 < 105; c3_i149++) {
    c3_sc_u[c3_i149] = c3_jb_u.msg1030[c3_i149];
  }

  c3_bd_y = NULL;
  sf_mex_assign(&c3_bd_y, sf_mex_create("y", c3_sc_u, 2, 0U, 1U, 0U, 1, 105),
                false);
  sf_mex_setfieldbynum(c3_mb_y, 0, "msg1030", c3_bd_y, 29);
  for (c3_i150 = 0; c3_i150 < 107; c3_i150++) {
    c3_tc_u[c3_i150] = c3_jb_u.msg1031[c3_i150];
  }

  c3_cd_y = NULL;
  sf_mex_assign(&c3_cd_y, sf_mex_create("y", c3_tc_u, 2, 0U, 1U, 0U, 1, 107),
                false);
  sf_mex_setfieldbynum(c3_mb_y, 0, "msg1031", c3_cd_y, 30);
  for (c3_i151 = 0; c3_i151 < 20; c3_i151++) {
    c3_uc_u[c3_i151] = c3_jb_u.msg1032[c3_i151];
  }

  c3_dd_y = NULL;
  sf_mex_assign(&c3_dd_y, sf_mex_create("y", c3_uc_u, 2, 0U, 1U, 0U, 1, 20),
                false);
  sf_mex_setfieldbynum(c3_mb_y, 0, "msg1032", c3_dd_y, 31);
  sf_mex_setfieldbynum(c3_b_y, 0, "theRTCM", c3_mb_y, 3);
  return c3_b_y;
}

static const mxArray *c3_e_emlrt_marshallOut
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const
   PRESCAN_V2X_FIXED_BSM_utcTime c3_b_u)
{
  const mxArray *c3_b_y;
  int32_T c3_c_u;
  const mxArray *c3_c_y = NULL;
  int32_T c3_d_u;
  const mxArray *c3_d_y = NULL;
  int32_T c3_e_u;
  const mxArray *c3_e_y = NULL;
  int32_T c3_f_u;
  const mxArray *c3_f_y = NULL;
  int32_T c3_g_u;
  const mxArray *c3_g_y = NULL;
  int32_T c3_h_u;
  const mxArray *c3_h_y = NULL;
  (void)chartInstance;
  c3_b_y = NULL;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_createstruct("structure", 6, c3_sv3, 2, 1, 1),
                false);
  c3_c_u = c3_b_u.year;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_c_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "year", c3_c_y, 0);
  c3_d_u = c3_b_u.month;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_d_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "month", c3_d_y, 1);
  c3_e_u = c3_b_u.day;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_e_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "day", c3_e_y, 2);
  c3_f_u = c3_b_u.hour;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_f_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "hour", c3_f_y, 3);
  c3_g_u = c3_b_u.minute;
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_g_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "minute", c3_g_y, 4);
  c3_h_u = c3_b_u.second;
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", &c3_h_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "second", c3_h_y, 5);
  return c3_b_y;
}

static const mxArray *c3_f_emlrt_marshallOut
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const
   PRESCAN_V2X_FIXED_BSM_status *c3_b_u)
{
  const mxArray *c3_b_y;
  static const char * c3_sv16[22] = { "lights", "lightBar", "wipers",
    "brakeStatus", "brakePressure", "roadFriction", "sunData", "rainData",
    "airTemp", "airPres", "steering", "accelSets", "object", "fullPos",
    "throttlePos", "speedHeadC", "speedC", "vehicleData", "vehicleIdent",
    "j1939data", "weatherReport", "gpsStatus" };

  int32_T c3_c_u;
  const mxArray *c3_c_y = NULL;
  int32_T c3_d_u;
  const mxArray *c3_d_y = NULL;
  int32_T c3_e_u;
  const mxArray *c3_e_y = NULL;
  PRESCAN_V2X_FIXED_BSM_steering c3_f_u;
  const mxArray *c3_f_y = NULL;
  static const char * c3_sv17[4] = { "angle", "confidence", "rate", "wheels" };

  int8_T c3_g_u;
  const mxArray *c3_g_y = NULL;
  int32_T c3_h_u;
  const mxArray *c3_h_y = NULL;
  int32_T c3_i_u;
  const mxArray *c3_i_y = NULL;
  int32_T c3_j_u;
  const mxArray *c3_j_y = NULL;
  PRESCAN_V2X_FIXED_BSM_accelSets c3_k_u;
  const mxArray *c3_k_y = NULL;
  static const char * c3_sv18[5] = { "accel4way", "vertAccelThres", "yawRateCon",
    "hozAccelCon", "confidenceSet" };

  int32_T c3_i152;
  const mxArray *c3_l_y = NULL;
  int8_T c3_l_u[7];
  int32_T c3_m_u;
  const mxArray *c3_m_y = NULL;
  int32_T c3_n_u;
  const mxArray *c3_n_y = NULL;
  int32_T c3_o_u;
  const mxArray *c3_o_y = NULL;
  PRESCAN_V2X_FIXED_BSM_confidenceSet c3_p_u;
  const mxArray *c3_p_y = NULL;
  static const char * c3_sv19[6] = { "accelConfidence", "speedConfidence",
    "timeConfidence", "posConfidence", "steerConfidence", "throttleConfidence" };

  PRESCAN_V2X_FIXED_BSM_accelConfidence c3_q_u;
  const mxArray *c3_q_y = NULL;
  static const char * c3_sv20[3] = { "yawRate", "acceleration",
    "steeringWheelAngle" };

  int32_T c3_r_u;
  const mxArray *c3_r_y = NULL;
  int32_T c3_s_u;
  const mxArray *c3_s_y = NULL;
  int32_T c3_t_u;
  const mxArray *c3_t_y = NULL;
  int8_T c3_u_u;
  const mxArray *c3_u_y = NULL;
  int32_T c3_v_u;
  const mxArray *c3_v_y = NULL;
  int8_T c3_w_u;
  const mxArray *c3_w_y = NULL;
  int32_T c3_x_u;
  const mxArray *c3_x_y = NULL;
  int32_T c3_y_u;
  const mxArray *c3_y_y = NULL;
  PRESCAN_V2X_FIXED_BSM_object c3_ab_u;
  const mxArray *c3_ab_y = NULL;
  static const char * c3_sv21[3] = { "obDist", "obDirect", "dateTime" };

  int32_T c3_bb_u;
  const mxArray *c3_bb_y = NULL;
  int32_T c3_cb_u;
  const mxArray *c3_cb_y = NULL;
  PRESCAN_V2X_FIXED_BSM_dateTime c3_db_u;
  const mxArray *c3_db_y = NULL;
  int32_T c3_eb_u;
  const mxArray *c3_eb_y = NULL;
  int32_T c3_fb_u;
  const mxArray *c3_fb_y = NULL;
  int32_T c3_gb_u;
  const mxArray *c3_gb_y = NULL;
  int32_T c3_hb_u;
  const mxArray *c3_hb_y = NULL;
  int32_T c3_ib_u;
  const mxArray *c3_ib_y = NULL;
  int32_T c3_jb_u;
  const mxArray *c3_jb_y = NULL;
  PRESCAN_V2X_FIXED_BSM_fullPos c3_kb_u;
  const mxArray *c3_kb_y = NULL;
  int32_T c3_lb_u;
  const mxArray *c3_lb_y = NULL;
  int32_T c3_mb_u;
  const mxArray *c3_mb_y = NULL;
  int32_T c3_i153;
  const mxArray *c3_nb_y = NULL;
  int8_T c3_nb_u[2];
  int32_T c3_ob_u;
  const mxArray *c3_ob_y = NULL;
  int32_T c3_i154;
  const mxArray *c3_pb_y = NULL;
  int32_T c3_i155;
  const mxArray *c3_qb_y = NULL;
  int8_T c3_pb_u[4];
  int32_T c3_qb_u;
  const mxArray *c3_rb_y = NULL;
  int8_T c3_rb_u;
  const mxArray *c3_sb_y = NULL;
  int8_T c3_sb_u;
  const mxArray *c3_tb_y = NULL;
  int32_T c3_tb_u;
  const mxArray *c3_ub_y = NULL;
  int8_T c3_ub_u;
  const mxArray *c3_vb_y = NULL;
  int32_T c3_vb_u;
  const mxArray *c3_wb_y = NULL;
  PRESCAN_V2X_FIXED_BSM_vehicleData c3_wb_u;
  const mxArray *c3_xb_y = NULL;
  static const char * c3_sv22[5] = { "height", "bumpers", "mass",
    "trailerWeight", "type" };

  int32_T c3_xb_u;
  const mxArray *c3_yb_y = NULL;
  PRESCAN_V2X_FIXED_BSM_bumpers c3_yb_u;
  const mxArray *c3_ac_y = NULL;
  static const char * c3_sv23[2] = { "frnt", "rear" };

  int32_T c3_ac_u;
  const mxArray *c3_bc_y = NULL;
  int32_T c3_bc_u;
  const mxArray *c3_cc_y = NULL;
  int32_T c3_cc_u;
  const mxArray *c3_dc_y = NULL;
  int32_T c3_dc_u;
  const mxArray *c3_ec_y = NULL;
  int32_T c3_ec_u;
  const mxArray *c3_fc_y = NULL;
  PRESCAN_V2X_FIXED_BSM_vehicleIdent c3_fc_u;
  const mxArray *c3_gc_y = NULL;
  static const char * c3_sv24[6] = { "name", "vin", "ownerCode", "id",
    "vehicleType", "vehicleClass" };

  int32_T c3_i156;
  const mxArray *c3_hc_y = NULL;
  int8_T c3_gc_u[63];
  int32_T c3_i157;
  const mxArray *c3_ic_y = NULL;
  int8_T c3_hc_u[17];
  int32_T c3_i158;
  const mxArray *c3_jc_y = NULL;
  int8_T c3_ic_u[32];
  int32_T c3_i159;
  const mxArray *c3_kc_y = NULL;
  int32_T c3_jc_u;
  const mxArray *c3_lc_y = NULL;
  PRESCAN_V2X_FIXED_BSM_vehicleClass c3_kc_u;
  const mxArray *c3_mc_y = NULL;
  static const char * c3_sv25[3] = { "vGroup", "rGroup", "rEquip" };

  int32_T c3_lc_u;
  const mxArray *c3_nc_y = NULL;
  int32_T c3_mc_u;
  const mxArray *c3_oc_y = NULL;
  int32_T c3_nc_u;
  const mxArray *c3_pc_y = NULL;
  PRESCAN_V2X_FIXED_BSM_j1939data c3_oc_u;
  const mxArray *c3_qc_y = NULL;
  static const char * c3_sv26[10] = { "tires", "axle", "trailerWeight",
    "cargoWeight", "steeringAxleTemperature", "driveAxleLocation",
    "driveAxleLiftAirPressure", "driveAxleTemperature", "driveAxleLubePressure",
    "steeringAxleLubePressure" };

  int32_T c3_i160;
  const mxArray *c3_rc_y = NULL;
  PRESCAN_V2X_FIXED_BSM_tires c3_pc_u[16];
  int32_T c3_iv1[1];
  static const char * c3_sv27[7] = { "location", "pressure", "temp",
    "wheelSensorStatus", "wheelEndElectFault", "leakageRate", "detection" };

  int32_T c3_i161;
  const PRESCAN_V2X_FIXED_BSM_tires *c3_r3;
  int32_T c3_i162;
  int32_T c3_qc_u;
  const mxArray *c3_sc_y = NULL;
  const mxArray *c3_tc_y = NULL;
  PRESCAN_V2X_FIXED_BSM_axle c3_rc_u[16];
  int32_T c3_iv2[1];
  int32_T c3_sc_u;
  static const char * c3_sv28[2] = { "location", "weight" };

  const mxArray *c3_uc_y = NULL;
  int32_T c3_i163;
  int32_T c3_tc_u;
  const PRESCAN_V2X_FIXED_BSM_axle *c3_r4;
  const mxArray *c3_vc_y = NULL;
  int32_T c3_uc_u;
  int32_T c3_vc_u;
  const mxArray *c3_wc_y = NULL;
  const mxArray *c3_xc_y = NULL;
  int32_T c3_wc_u;
  const mxArray *c3_yc_y = NULL;
  int32_T c3_xc_u;
  int32_T c3_yc_u;
  const mxArray *c3_ad_y = NULL;
  const mxArray *c3_bd_y = NULL;
  int32_T c3_ad_u;
  const mxArray *c3_cd_y = NULL;
  int32_T c3_bd_u;
  const mxArray *c3_dd_y = NULL;
  int32_T c3_cd_u;
  const mxArray *c3_ed_y = NULL;
  int32_T c3_dd_u;
  const mxArray *c3_fd_y = NULL;
  int32_T c3_ed_u;
  const mxArray *c3_gd_y = NULL;
  int32_T c3_fd_u;
  const mxArray *c3_hd_y = NULL;
  int32_T c3_gd_u;
  const mxArray *c3_id_y = NULL;
  int32_T c3_hd_u;
  const mxArray *c3_jd_y = NULL;
  int32_T c3_id_u;
  const mxArray *c3_kd_y = NULL;
  PRESCAN_V2X_FIXED_BSM_weatherReport c3_jd_u;
  const mxArray *c3_ld_y = NULL;
  static const char * c3_sv29[5] = { "isRaining", "rainRate", "precipSituation",
    "solarRadiation", "friction" };

  int32_T c3_kd_u;
  const mxArray *c3_md_y = NULL;
  int32_T c3_ld_u;
  const mxArray *c3_nd_y = NULL;
  int32_T c3_md_u;
  const mxArray *c3_od_y = NULL;
  int32_T c3_nd_u;
  const mxArray *c3_pd_y = NULL;
  int32_T c3_od_u;
  const mxArray *c3_qd_y = NULL;
  int32_T c3_pd_u;
  const mxArray *c3_rd_y = NULL;
  c3_b_y = NULL;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_createstruct("structure", 22, c3_sv16, 2, 1, 1),
                false);
  sf_mex_setfieldbynum(c3_b_y, 0, "lights", c3_b_emlrt_marshallOut(chartInstance,
    c3_b_u->lights), 0);
  sf_mex_setfieldbynum(c3_b_y, 0, "lightBar", c3_b_emlrt_marshallOut
                       (chartInstance, c3_b_u->lightBar), 1);
  sf_mex_setfieldbynum(c3_b_y, 0, "wipers", c3_g_emlrt_marshallOut(chartInstance,
    c3_b_u->wipers), 2);
  sf_mex_setfieldbynum(c3_b_y, 0, "brakeStatus", c3_c_emlrt_marshallOut
                       (chartInstance, c3_b_u->brakeStatus), 3);
  sf_mex_setfieldbynum(c3_b_y, 0, "brakePressure", c3_b_emlrt_marshallOut
                       (chartInstance, c3_b_u->brakePressure), 4);
  sf_mex_setfieldbynum(c3_b_y, 0, "roadFriction", c3_b_emlrt_marshallOut
                       (chartInstance, c3_b_u->roadFriction), 5);
  sf_mex_setfieldbynum(c3_b_y, 0, "sunData", c3_b_emlrt_marshallOut
                       (chartInstance, c3_b_u->sunData), 6);
  c3_c_u = c3_b_u->rainData;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_c_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "rainData", c3_c_y, 7);
  c3_d_u = c3_b_u->airTemp;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_d_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "airTemp", c3_d_y, 8);
  c3_e_u = c3_b_u->airPres;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_e_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "airPres", c3_e_y, 9);
  c3_f_u = c3_b_u->steering;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_createstruct("structure", 4, c3_sv17, 2, 1, 1),
                false);
  c3_g_u = c3_f_u.angle;
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_g_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_f_y, 0, "angle", c3_g_y, 0);
  c3_h_u = c3_f_u.confidence;
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", &c3_h_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_f_y, 0, "confidence", c3_h_y, 1);
  c3_i_u = c3_f_u.rate;
  c3_i_y = NULL;
  sf_mex_assign(&c3_i_y, sf_mex_create("y", &c3_i_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_f_y, 0, "rate", c3_i_y, 2);
  c3_j_u = c3_f_u.wheels;
  c3_j_y = NULL;
  sf_mex_assign(&c3_j_y, sf_mex_create("y", &c3_j_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_f_y, 0, "wheels", c3_j_y, 3);
  sf_mex_setfieldbynum(c3_b_y, 0, "steering", c3_f_y, 10);
  c3_k_u = c3_b_u->accelSets;
  c3_k_y = NULL;
  sf_mex_assign(&c3_k_y, sf_mex_createstruct("structure", 5, c3_sv18, 2, 1, 1),
                false);
  for (c3_i152 = 0; c3_i152 < 7; c3_i152++) {
    c3_l_u[c3_i152] = c3_k_u.accel4way[c3_i152];
  }

  c3_l_y = NULL;
  sf_mex_assign(&c3_l_y, sf_mex_create("y", c3_l_u, 2, 0U, 1U, 0U, 1, 7), false);
  sf_mex_setfieldbynum(c3_k_y, 0, "accel4way", c3_l_y, 0);
  c3_m_u = c3_k_u.vertAccelThres;
  c3_m_y = NULL;
  sf_mex_assign(&c3_m_y, sf_mex_create("y", &c3_m_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_k_y, 0, "vertAccelThres", c3_m_y, 1);
  c3_n_u = c3_k_u.yawRateCon;
  c3_n_y = NULL;
  sf_mex_assign(&c3_n_y, sf_mex_create("y", &c3_n_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_k_y, 0, "yawRateCon", c3_n_y, 2);
  c3_o_u = c3_k_u.hozAccelCon;
  c3_o_y = NULL;
  sf_mex_assign(&c3_o_y, sf_mex_create("y", &c3_o_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_k_y, 0, "hozAccelCon", c3_o_y, 3);
  c3_p_u = c3_k_u.confidenceSet;
  c3_p_y = NULL;
  sf_mex_assign(&c3_p_y, sf_mex_createstruct("structure", 6, c3_sv19, 2, 1, 1),
                false);
  c3_q_u = c3_p_u.accelConfidence;
  c3_q_y = NULL;
  sf_mex_assign(&c3_q_y, sf_mex_createstruct("structure", 3, c3_sv20, 2, 1, 1),
                false);
  c3_r_u = c3_q_u.yawRate;
  c3_r_y = NULL;
  sf_mex_assign(&c3_r_y, sf_mex_create("y", &c3_r_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_q_y, 0, "yawRate", c3_r_y, 0);
  c3_s_u = c3_q_u.acceleration;
  c3_s_y = NULL;
  sf_mex_assign(&c3_s_y, sf_mex_create("y", &c3_s_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_q_y, 0, "acceleration", c3_s_y, 1);
  c3_t_u = c3_q_u.steeringWheelAngle;
  c3_t_y = NULL;
  sf_mex_assign(&c3_t_y, sf_mex_create("y", &c3_t_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_q_y, 0, "steeringWheelAngle", c3_t_y, 2);
  sf_mex_setfieldbynum(c3_p_y, 0, "accelConfidence", c3_q_y, 0);
  c3_u_u = c3_p_u.speedConfidence;
  c3_u_y = NULL;
  sf_mex_assign(&c3_u_y, sf_mex_create("y", &c3_u_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_p_y, 0, "speedConfidence", c3_u_y, 1);
  c3_v_u = c3_p_u.timeConfidence;
  c3_v_y = NULL;
  sf_mex_assign(&c3_v_y, sf_mex_create("y", &c3_v_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_p_y, 0, "timeConfidence", c3_v_y, 2);
  c3_w_u = c3_p_u.posConfidence;
  c3_w_y = NULL;
  sf_mex_assign(&c3_w_y, sf_mex_create("y", &c3_w_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_p_y, 0, "posConfidence", c3_w_y, 3);
  c3_x_u = c3_p_u.steerConfidence;
  c3_x_y = NULL;
  sf_mex_assign(&c3_x_y, sf_mex_create("y", &c3_x_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_p_y, 0, "steerConfidence", c3_x_y, 4);
  c3_y_u = c3_p_u.throttleConfidence;
  c3_y_y = NULL;
  sf_mex_assign(&c3_y_y, sf_mex_create("y", &c3_y_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_p_y, 0, "throttleConfidence", c3_y_y, 5);
  sf_mex_setfieldbynum(c3_k_y, 0, "confidenceSet", c3_p_y, 4);
  sf_mex_setfieldbynum(c3_b_y, 0, "accelSets", c3_k_y, 11);
  c3_ab_u = c3_b_u->object;
  c3_ab_y = NULL;
  sf_mex_assign(&c3_ab_y, sf_mex_createstruct("structure", 3, c3_sv21, 2, 1, 1),
                false);
  c3_bb_u = c3_ab_u.obDist;
  c3_bb_y = NULL;
  sf_mex_assign(&c3_bb_y, sf_mex_create("y", &c3_bb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_ab_y, 0, "obDist", c3_bb_y, 0);
  c3_cb_u = c3_ab_u.obDirect;
  c3_cb_y = NULL;
  sf_mex_assign(&c3_cb_y, sf_mex_create("y", &c3_cb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_ab_y, 0, "obDirect", c3_cb_y, 1);
  c3_db_u = c3_ab_u.dateTime;
  c3_db_y = NULL;
  sf_mex_assign(&c3_db_y, sf_mex_createstruct("structure", 6, c3_sv3, 2, 1, 1),
                false);
  c3_eb_u = c3_db_u.year;
  c3_eb_y = NULL;
  sf_mex_assign(&c3_eb_y, sf_mex_create("y", &c3_eb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_db_y, 0, "year", c3_eb_y, 0);
  c3_fb_u = c3_db_u.month;
  c3_fb_y = NULL;
  sf_mex_assign(&c3_fb_y, sf_mex_create("y", &c3_fb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_db_y, 0, "month", c3_fb_y, 1);
  c3_gb_u = c3_db_u.day;
  c3_gb_y = NULL;
  sf_mex_assign(&c3_gb_y, sf_mex_create("y", &c3_gb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_db_y, 0, "day", c3_gb_y, 2);
  c3_hb_u = c3_db_u.hour;
  c3_hb_y = NULL;
  sf_mex_assign(&c3_hb_y, sf_mex_create("y", &c3_hb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_db_y, 0, "hour", c3_hb_y, 3);
  c3_ib_u = c3_db_u.minute;
  c3_ib_y = NULL;
  sf_mex_assign(&c3_ib_y, sf_mex_create("y", &c3_ib_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_db_y, 0, "minute", c3_ib_y, 4);
  c3_jb_u = c3_db_u.second;
  c3_jb_y = NULL;
  sf_mex_assign(&c3_jb_y, sf_mex_create("y", &c3_jb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_db_y, 0, "second", c3_jb_y, 5);
  sf_mex_setfieldbynum(c3_ab_y, 0, "dateTime", c3_db_y, 2);
  sf_mex_setfieldbynum(c3_b_y, 0, "object", c3_ab_y, 12);
  c3_kb_u = c3_b_u->fullPos;
  c3_kb_y = NULL;
  sf_mex_assign(&c3_kb_y, sf_mex_createstruct("structure", 10, c3_sv2, 2, 1, 1),
                false);
  sf_mex_setfieldbynum(c3_kb_y, 0, "utcTime", c3_e_emlrt_marshallOut
                       (chartInstance, c3_kb_u.utcTime), 0);
  c3_lb_u = c3_kb_u.longitude;
  c3_lb_y = NULL;
  sf_mex_assign(&c3_lb_y, sf_mex_create("y", &c3_lb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_kb_y, 0, "longitude", c3_lb_y, 1);
  c3_mb_u = c3_kb_u.latitude;
  c3_mb_y = NULL;
  sf_mex_assign(&c3_mb_y, sf_mex_create("y", &c3_mb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_kb_y, 0, "latitude", c3_mb_y, 2);
  for (c3_i153 = 0; c3_i153 < 2; c3_i153++) {
    c3_nb_u[c3_i153] = c3_kb_u.elevation[c3_i153];
  }

  c3_nb_y = NULL;
  sf_mex_assign(&c3_nb_y, sf_mex_create("y", c3_nb_u, 2, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_setfieldbynum(c3_kb_y, 0, "elevation", c3_nb_y, 3);
  c3_ob_u = c3_kb_u.heading;
  c3_ob_y = NULL;
  sf_mex_assign(&c3_ob_y, sf_mex_create("y", &c3_ob_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_kb_y, 0, "heading", c3_ob_y, 4);
  for (c3_i154 = 0; c3_i154 < 2; c3_i154++) {
    c3_nb_u[c3_i154] = c3_kb_u.speed[c3_i154];
  }

  c3_pb_y = NULL;
  sf_mex_assign(&c3_pb_y, sf_mex_create("y", c3_nb_u, 2, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_setfieldbynum(c3_kb_y, 0, "speed", c3_pb_y, 5);
  for (c3_i155 = 0; c3_i155 < 4; c3_i155++) {
    c3_pb_u[c3_i155] = c3_kb_u.posAccuracy[c3_i155];
  }

  c3_qb_y = NULL;
  sf_mex_assign(&c3_qb_y, sf_mex_create("y", c3_pb_u, 2, 0U, 1U, 0U, 1, 4),
                false);
  sf_mex_setfieldbynum(c3_kb_y, 0, "posAccuracy", c3_qb_y, 6);
  c3_qb_u = c3_kb_u.timeConfidence;
  c3_rb_y = NULL;
  sf_mex_assign(&c3_rb_y, sf_mex_create("y", &c3_qb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_kb_y, 0, "timeConfidence", c3_rb_y, 7);
  c3_rb_u = c3_kb_u.posConfidence;
  c3_sb_y = NULL;
  sf_mex_assign(&c3_sb_y, sf_mex_create("y", &c3_rb_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_kb_y, 0, "posConfidence", c3_sb_y, 8);
  c3_sb_u = c3_kb_u.speedConfidence;
  c3_tb_y = NULL;
  sf_mex_assign(&c3_tb_y, sf_mex_create("y", &c3_sb_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_kb_y, 0, "speedConfidence", c3_tb_y, 9);
  sf_mex_setfieldbynum(c3_b_y, 0, "fullPos", c3_kb_y, 13);
  c3_tb_u = c3_b_u->throttlePos;
  c3_ub_y = NULL;
  sf_mex_assign(&c3_ub_y, sf_mex_create("y", &c3_tb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "throttlePos", c3_ub_y, 14);
  c3_ub_u = c3_b_u->speedHeadC;
  c3_vb_y = NULL;
  sf_mex_assign(&c3_vb_y, sf_mex_create("y", &c3_ub_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "speedHeadC", c3_vb_y, 15);
  c3_vb_u = c3_b_u->speedC;
  c3_wb_y = NULL;
  sf_mex_assign(&c3_wb_y, sf_mex_create("y", &c3_vb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "speedC", c3_wb_y, 16);
  c3_wb_u = c3_b_u->vehicleData;
  c3_xb_y = NULL;
  sf_mex_assign(&c3_xb_y, sf_mex_createstruct("structure", 5, c3_sv22, 2, 1, 1),
                false);
  c3_xb_u = c3_wb_u.height;
  c3_yb_y = NULL;
  sf_mex_assign(&c3_yb_y, sf_mex_create("y", &c3_xb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_xb_y, 0, "height", c3_yb_y, 0);
  c3_yb_u = c3_wb_u.bumpers;
  c3_ac_y = NULL;
  sf_mex_assign(&c3_ac_y, sf_mex_createstruct("structure", 2, c3_sv23, 2, 1, 1),
                false);
  c3_ac_u = c3_yb_u.frnt;
  c3_bc_y = NULL;
  sf_mex_assign(&c3_bc_y, sf_mex_create("y", &c3_ac_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_ac_y, 0, "frnt", c3_bc_y, 0);
  c3_bc_u = c3_yb_u.rear;
  c3_cc_y = NULL;
  sf_mex_assign(&c3_cc_y, sf_mex_create("y", &c3_bc_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_ac_y, 0, "rear", c3_cc_y, 1);
  sf_mex_setfieldbynum(c3_xb_y, 0, "bumpers", c3_ac_y, 1);
  c3_cc_u = c3_wb_u.mass;
  c3_dc_y = NULL;
  sf_mex_assign(&c3_dc_y, sf_mex_create("y", &c3_cc_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_xb_y, 0, "mass", c3_dc_y, 2);
  c3_dc_u = c3_wb_u.trailerWeight;
  c3_ec_y = NULL;
  sf_mex_assign(&c3_ec_y, sf_mex_create("y", &c3_dc_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_xb_y, 0, "trailerWeight", c3_ec_y, 3);
  c3_ec_u = c3_wb_u.type;
  c3_fc_y = NULL;
  sf_mex_assign(&c3_fc_y, sf_mex_create("y", &c3_ec_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_xb_y, 0, "type", c3_fc_y, 4);
  sf_mex_setfieldbynum(c3_b_y, 0, "vehicleData", c3_xb_y, 17);
  c3_fc_u = c3_b_u->vehicleIdent;
  c3_gc_y = NULL;
  sf_mex_assign(&c3_gc_y, sf_mex_createstruct("structure", 6, c3_sv24, 2, 1, 1),
                false);
  for (c3_i156 = 0; c3_i156 < 63; c3_i156++) {
    c3_gc_u[c3_i156] = c3_fc_u.name[c3_i156];
  }

  c3_hc_y = NULL;
  sf_mex_assign(&c3_hc_y, sf_mex_create("y", c3_gc_u, 2, 0U, 1U, 0U, 1, 63),
                false);
  sf_mex_setfieldbynum(c3_gc_y, 0, "name", c3_hc_y, 0);
  for (c3_i157 = 0; c3_i157 < 17; c3_i157++) {
    c3_hc_u[c3_i157] = c3_fc_u.vin[c3_i157];
  }

  c3_ic_y = NULL;
  sf_mex_assign(&c3_ic_y, sf_mex_create("y", c3_hc_u, 2, 0U, 1U, 0U, 1, 17),
                false);
  sf_mex_setfieldbynum(c3_gc_y, 0, "vin", c3_ic_y, 1);
  for (c3_i158 = 0; c3_i158 < 32; c3_i158++) {
    c3_ic_u[c3_i158] = c3_fc_u.ownerCode[c3_i158];
  }

  c3_jc_y = NULL;
  sf_mex_assign(&c3_jc_y, sf_mex_create("y", c3_ic_u, 2, 0U, 1U, 0U, 1, 32),
                false);
  sf_mex_setfieldbynum(c3_gc_y, 0, "ownerCode", c3_jc_y, 2);
  for (c3_i159 = 0; c3_i159 < 4; c3_i159++) {
    c3_pb_u[c3_i159] = c3_fc_u.id[c3_i159];
  }

  c3_kc_y = NULL;
  sf_mex_assign(&c3_kc_y, sf_mex_create("y", c3_pb_u, 2, 0U, 1U, 0U, 1, 4),
                false);
  sf_mex_setfieldbynum(c3_gc_y, 0, "id", c3_kc_y, 3);
  c3_jc_u = c3_fc_u.vehicleType;
  c3_lc_y = NULL;
  sf_mex_assign(&c3_lc_y, sf_mex_create("y", &c3_jc_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_gc_y, 0, "vehicleType", c3_lc_y, 4);
  c3_kc_u = c3_fc_u.vehicleClass;
  c3_mc_y = NULL;
  sf_mex_assign(&c3_mc_y, sf_mex_createstruct("structure", 3, c3_sv25, 2, 1, 1),
                false);
  c3_lc_u = c3_kc_u.vGroup;
  c3_nc_y = NULL;
  sf_mex_assign(&c3_nc_y, sf_mex_create("y", &c3_lc_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_mc_y, 0, "vGroup", c3_nc_y, 0);
  c3_mc_u = c3_kc_u.rGroup;
  c3_oc_y = NULL;
  sf_mex_assign(&c3_oc_y, sf_mex_create("y", &c3_mc_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_mc_y, 0, "rGroup", c3_oc_y, 1);
  c3_nc_u = c3_kc_u.rEquip;
  c3_pc_y = NULL;
  sf_mex_assign(&c3_pc_y, sf_mex_create("y", &c3_nc_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_mc_y, 0, "rEquip", c3_pc_y, 2);
  sf_mex_setfieldbynum(c3_gc_y, 0, "vehicleClass", c3_mc_y, 5);
  sf_mex_setfieldbynum(c3_b_y, 0, "vehicleIdent", c3_gc_y, 18);
  c3_oc_u = c3_b_u->j1939data;
  c3_qc_y = NULL;
  sf_mex_assign(&c3_qc_y, sf_mex_createstruct("structure", 10, c3_sv26, 2, 1, 1),
                false);
  for (c3_i160 = 0; c3_i160 < 16; c3_i160++) {
    c3_pc_u[c3_i160] = c3_oc_u.tires[c3_i160];
  }

  c3_rc_y = NULL;
  c3_iv1[0] = 16;
  sf_mex_assign(&c3_rc_y, sf_mex_createstructarray("structure", 1, c3_iv1, 7,
    c3_sv27), false);
  for (c3_i161 = 0; c3_i161 < 16; c3_i161++) {
    c3_r3 = &c3_pc_u[c3_i161];
    c3_qc_u = c3_r3->location;
    c3_sc_y = NULL;
    sf_mex_assign(&c3_sc_y, sf_mex_create("y", &c3_qc_u, 6, 0U, 0U, 0U, 0),
                  false);
    sf_mex_setfieldbynum(c3_rc_y, c3_i161, "location", c3_sc_y, 0);
    c3_sc_u = c3_r3->pressure;
    c3_uc_y = NULL;
    sf_mex_assign(&c3_uc_y, sf_mex_create("y", &c3_sc_u, 6, 0U, 0U, 0U, 0),
                  false);
    sf_mex_setfieldbynum(c3_rc_y, c3_i161, "pressure", c3_uc_y, 1);
    c3_tc_u = c3_r3->temp;
    c3_vc_y = NULL;
    sf_mex_assign(&c3_vc_y, sf_mex_create("y", &c3_tc_u, 6, 0U, 0U, 0U, 0),
                  false);
    sf_mex_setfieldbynum(c3_rc_y, c3_i161, "temp", c3_vc_y, 2);
    c3_wc_u = c3_r3->wheelSensorStatus;
    c3_yc_y = NULL;
    sf_mex_assign(&c3_yc_y, sf_mex_create("y", &c3_wc_u, 6, 0U, 0U, 0U, 0),
                  false);
    sf_mex_setfieldbynum(c3_rc_y, c3_i161, "wheelSensorStatus", c3_yc_y, 3);
    c3_ad_u = c3_r3->wheelEndElectFault;
    c3_cd_y = NULL;
    sf_mex_assign(&c3_cd_y, sf_mex_create("y", &c3_ad_u, 6, 0U, 0U, 0U, 0),
                  false);
    sf_mex_setfieldbynum(c3_rc_y, c3_i161, "wheelEndElectFault", c3_cd_y, 4);
    c3_cd_u = c3_r3->leakageRate;
    c3_ed_y = NULL;
    sf_mex_assign(&c3_ed_y, sf_mex_create("y", &c3_cd_u, 6, 0U, 0U, 0U, 0),
                  false);
    sf_mex_setfieldbynum(c3_rc_y, c3_i161, "leakageRate", c3_ed_y, 5);
    c3_ed_u = c3_r3->detection;
    c3_gd_y = NULL;
    sf_mex_assign(&c3_gd_y, sf_mex_create("y", &c3_ed_u, 6, 0U, 0U, 0U, 0),
                  false);
    sf_mex_setfieldbynum(c3_rc_y, c3_i161, "detection", c3_gd_y, 6);
  }

  sf_mex_setfieldbynum(c3_qc_y, 0, "tires", c3_rc_y, 0);
  for (c3_i162 = 0; c3_i162 < 16; c3_i162++) {
    c3_rc_u[c3_i162] = c3_oc_u.axle[c3_i162];
  }

  c3_tc_y = NULL;
  c3_iv2[0] = 16;
  sf_mex_assign(&c3_tc_y, sf_mex_createstructarray("structure", 1, c3_iv2, 2,
    c3_sv28), false);
  for (c3_i163 = 0; c3_i163 < 16; c3_i163++) {
    c3_r4 = &c3_rc_u[c3_i163];
    c3_vc_u = c3_r4->location;
    c3_xc_y = NULL;
    sf_mex_assign(&c3_xc_y, sf_mex_create("y", &c3_vc_u, 6, 0U, 0U, 0U, 0),
                  false);
    sf_mex_setfieldbynum(c3_tc_y, c3_i163, "location", c3_xc_y, 0);
    c3_yc_u = c3_r4->weight;
    c3_bd_y = NULL;
    sf_mex_assign(&c3_bd_y, sf_mex_create("y", &c3_yc_u, 6, 0U, 0U, 0U, 0),
                  false);
    sf_mex_setfieldbynum(c3_tc_y, c3_i163, "weight", c3_bd_y, 1);
  }

  sf_mex_setfieldbynum(c3_qc_y, 0, "axle", c3_tc_y, 1);
  c3_uc_u = c3_oc_u.trailerWeight;
  c3_wc_y = NULL;
  sf_mex_assign(&c3_wc_y, sf_mex_create("y", &c3_uc_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_qc_y, 0, "trailerWeight", c3_wc_y, 2);
  c3_xc_u = c3_oc_u.cargoWeight;
  c3_ad_y = NULL;
  sf_mex_assign(&c3_ad_y, sf_mex_create("y", &c3_xc_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_qc_y, 0, "cargoWeight", c3_ad_y, 3);
  c3_bd_u = c3_oc_u.steeringAxleTemperature;
  c3_dd_y = NULL;
  sf_mex_assign(&c3_dd_y, sf_mex_create("y", &c3_bd_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_qc_y, 0, "steeringAxleTemperature", c3_dd_y, 4);
  c3_dd_u = c3_oc_u.driveAxleLocation;
  c3_fd_y = NULL;
  sf_mex_assign(&c3_fd_y, sf_mex_create("y", &c3_dd_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_qc_y, 0, "driveAxleLocation", c3_fd_y, 5);
  c3_fd_u = c3_oc_u.driveAxleLiftAirPressure;
  c3_hd_y = NULL;
  sf_mex_assign(&c3_hd_y, sf_mex_create("y", &c3_fd_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_qc_y, 0, "driveAxleLiftAirPressure", c3_hd_y, 6);
  c3_gd_u = c3_oc_u.driveAxleTemperature;
  c3_id_y = NULL;
  sf_mex_assign(&c3_id_y, sf_mex_create("y", &c3_gd_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_qc_y, 0, "driveAxleTemperature", c3_id_y, 7);
  c3_hd_u = c3_oc_u.driveAxleLubePressure;
  c3_jd_y = NULL;
  sf_mex_assign(&c3_jd_y, sf_mex_create("y", &c3_hd_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_qc_y, 0, "driveAxleLubePressure", c3_jd_y, 8);
  c3_id_u = c3_oc_u.steeringAxleLubePressure;
  c3_kd_y = NULL;
  sf_mex_assign(&c3_kd_y, sf_mex_create("y", &c3_id_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_qc_y, 0, "steeringAxleLubePressure", c3_kd_y, 9);
  sf_mex_setfieldbynum(c3_b_y, 0, "j1939data", c3_qc_y, 19);
  c3_jd_u = c3_b_u->weatherReport;
  c3_ld_y = NULL;
  sf_mex_assign(&c3_ld_y, sf_mex_createstruct("structure", 5, c3_sv29, 2, 1, 1),
                false);
  c3_kd_u = c3_jd_u.isRaining;
  c3_md_y = NULL;
  sf_mex_assign(&c3_md_y, sf_mex_create("y", &c3_kd_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_ld_y, 0, "isRaining", c3_md_y, 0);
  c3_ld_u = c3_jd_u.rainRate;
  c3_nd_y = NULL;
  sf_mex_assign(&c3_nd_y, sf_mex_create("y", &c3_ld_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_ld_y, 0, "rainRate", c3_nd_y, 1);
  c3_md_u = c3_jd_u.precipSituation;
  c3_od_y = NULL;
  sf_mex_assign(&c3_od_y, sf_mex_create("y", &c3_md_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_ld_y, 0, "precipSituation", c3_od_y, 2);
  c3_nd_u = c3_jd_u.solarRadiation;
  c3_pd_y = NULL;
  sf_mex_assign(&c3_pd_y, sf_mex_create("y", &c3_nd_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_ld_y, 0, "solarRadiation", c3_pd_y, 3);
  c3_od_u = c3_jd_u.friction;
  c3_qd_y = NULL;
  sf_mex_assign(&c3_qd_y, sf_mex_create("y", &c3_od_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_ld_y, 0, "friction", c3_qd_y, 4);
  sf_mex_setfieldbynum(c3_b_y, 0, "weatherReport", c3_ld_y, 20);
  c3_pd_u = c3_b_u->gpsStatus;
  c3_rd_y = NULL;
  sf_mex_assign(&c3_rd_y, sf_mex_create("y", &c3_pd_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "gpsStatus", c3_rd_y, 21);
  return c3_b_y;
}

static const mxArray *c3_g_emlrt_marshallOut
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const
   PRESCAN_V2X_FIXED_BSM_wipers c3_b_u)
{
  const mxArray *c3_b_y;
  static const char * c3_sv30[4] = { "statusFront", "rateFront", "statusRear",
    "rateRear" };

  int32_T c3_c_u;
  const mxArray *c3_c_y = NULL;
  int32_T c3_d_u;
  const mxArray *c3_d_y = NULL;
  int32_T c3_e_u;
  const mxArray *c3_e_y = NULL;
  int32_T c3_f_u;
  const mxArray *c3_f_y = NULL;
  (void)chartInstance;
  c3_b_y = NULL;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_createstruct("structure", 4, c3_sv30, 2, 1, 1),
                false);
  c3_c_u = c3_b_u.statusFront;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_c_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "statusFront", c3_c_y, 0);
  c3_d_u = c3_b_u.rateFront;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_d_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "rateFront", c3_d_y, 1);
  c3_e_u = c3_b_u.statusRear;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_e_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "statusRear", c3_e_y, 2);
  c3_f_u = c3_b_u.rateRear;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_f_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "rateRear", c3_f_y, 3);
  return c3_b_y;
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  PRESCAN_V2X_FIXED_BSM_MESSAGE c3_b_u;
  const mxArray *c3_b_y = NULL;
  PRESCAN_HEADER c3_c_u;
  const mxArray *c3_c_y = NULL;
  static const char * c3_sv31[1] = { "valid" };

  boolean_T c3_d_u;
  const mxArray *c3_d_y = NULL;
  SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc3_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_b_u = *(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_inData;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_createstruct("structure", 2, c3_sv0, 2, 1, 1),
                false);
  c3_c_u = c3_b_u.HEADER;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_createstruct("structure", 1, c3_sv31, 2, 1, 1),
                false);
  c3_d_u = c3_c_u.valid;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_d_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_c_y, 0, "valid", c3_d_y, 0);
  sf_mex_setfieldbynum(c3_b_y, 0, "HEADER", c3_c_y, 0);
  sf_mex_setfieldbynum(c3_b_y, 0, "DATA", c3_emlrt_marshallOut(chartInstance,
    &c3_b_u.DATA), 1);
  sf_mex_assign(&c3_mxArrayOutData, c3_b_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_h_emlrt_marshallOut
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const
   c3_PRESCAN_V2X_USER_BSM_DATA c3_b_u)
{
  const mxArray *c3_b_y;
  static const char * c3_sv32[14] = { "msgID", "msgCnt", "id", "secMark",
    "latitude", "longitude", "elev", "accuracy", "speed", "heading", "angle",
    "accelSet", "brakes", "size" };

  int32_T c3_c_u;
  const mxArray *c3_c_y = NULL;
  int32_T c3_d_u;
  const mxArray *c3_d_y = NULL;
  int32_T c3_i164;
  const mxArray *c3_e_y = NULL;
  int8_T c3_e_u[4];
  int32_T c3_f_u;
  const mxArray *c3_f_y = NULL;
  int32_T c3_g_u;
  const mxArray *c3_g_y = NULL;
  int32_T c3_h_u;
  const mxArray *c3_h_y = NULL;
  int32_T c3_i165;
  const mxArray *c3_i_y = NULL;
  int8_T c3_i_u[2];
  int32_T c3_i166;
  const mxArray *c3_j_y = NULL;
  int32_T c3_i167;
  const mxArray *c3_k_y = NULL;
  int32_T c3_j_u;
  const mxArray *c3_l_y = NULL;
  int8_T c3_k_u;
  const mxArray *c3_m_y = NULL;
  int32_T c3_i168;
  const mxArray *c3_n_y = NULL;
  int8_T c3_l_u[7];
  int32_T c3_i169;
  const mxArray *c3_o_y = NULL;
  c3_PRESCAN_V2X_USER_BSM_size c3_m_u;
  const mxArray *c3_p_y = NULL;
  int32_T c3_n_u;
  const mxArray *c3_q_y = NULL;
  int32_T c3_o_u;
  const mxArray *c3_r_y = NULL;
  (void)chartInstance;
  c3_b_y = NULL;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_createstruct("structure", 14, c3_sv32, 2, 1, 1),
                false);
  c3_c_u = c3_b_u.msgID;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_c_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "msgID", c3_c_y, 0);
  c3_d_u = c3_b_u.msgCnt;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_d_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "msgCnt", c3_d_y, 1);
  for (c3_i164 = 0; c3_i164 < 4; c3_i164++) {
    c3_e_u[c3_i164] = c3_b_u.id[c3_i164];
  }

  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", c3_e_u, 2, 0U, 1U, 0U, 1, 4), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "id", c3_e_y, 2);
  c3_f_u = c3_b_u.secMark;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_f_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "secMark", c3_f_y, 3);
  c3_g_u = c3_b_u.latitude;
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_g_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "latitude", c3_g_y, 4);
  c3_h_u = c3_b_u.longitude;
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", &c3_h_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "longitude", c3_h_y, 5);
  for (c3_i165 = 0; c3_i165 < 2; c3_i165++) {
    c3_i_u[c3_i165] = c3_b_u.elev[c3_i165];
  }

  c3_i_y = NULL;
  sf_mex_assign(&c3_i_y, sf_mex_create("y", c3_i_u, 2, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "elev", c3_i_y, 6);
  for (c3_i166 = 0; c3_i166 < 4; c3_i166++) {
    c3_e_u[c3_i166] = c3_b_u.accuracy[c3_i166];
  }

  c3_j_y = NULL;
  sf_mex_assign(&c3_j_y, sf_mex_create("y", c3_e_u, 2, 0U, 1U, 0U, 1, 4), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "accuracy", c3_j_y, 7);
  for (c3_i167 = 0; c3_i167 < 2; c3_i167++) {
    c3_i_u[c3_i167] = c3_b_u.speed[c3_i167];
  }

  c3_k_y = NULL;
  sf_mex_assign(&c3_k_y, sf_mex_create("y", c3_i_u, 2, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "speed", c3_k_y, 8);
  c3_j_u = c3_b_u.heading;
  c3_l_y = NULL;
  sf_mex_assign(&c3_l_y, sf_mex_create("y", &c3_j_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "heading", c3_l_y, 9);
  c3_k_u = c3_b_u.angle;
  c3_m_y = NULL;
  sf_mex_assign(&c3_m_y, sf_mex_create("y", &c3_k_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "angle", c3_m_y, 10);
  for (c3_i168 = 0; c3_i168 < 7; c3_i168++) {
    c3_l_u[c3_i168] = c3_b_u.accelSet[c3_i168];
  }

  c3_n_y = NULL;
  sf_mex_assign(&c3_n_y, sf_mex_create("y", c3_l_u, 2, 0U, 1U, 0U, 1, 7), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "accelSet", c3_n_y, 11);
  for (c3_i169 = 0; c3_i169 < 2; c3_i169++) {
    c3_i_u[c3_i169] = c3_b_u.brakes[c3_i169];
  }

  c3_o_y = NULL;
  sf_mex_assign(&c3_o_y, sf_mex_create("y", c3_i_u, 2, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "brakes", c3_o_y, 12);
  c3_m_u = c3_b_u.size;
  c3_p_y = NULL;
  sf_mex_assign(&c3_p_y, sf_mex_createstruct("structure", 2, c3_sv1, 2, 1, 1),
                false);
  c3_n_u = c3_m_u.width;
  c3_q_y = NULL;
  sf_mex_assign(&c3_q_y, sf_mex_create("y", &c3_n_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_p_y, 0, "width", c3_q_y, 0);
  c3_o_u = c3_m_u.length;
  c3_r_y = NULL;
  sf_mex_assign(&c3_r_y, sf_mex_create("y", &c3_o_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_p_y, 0, "length", c3_r_y, 1);
  sf_mex_setfieldbynum(c3_b_y, 0, "size", c3_p_y, 13);
  return c3_b_y;
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  c3_PRESCAN_V2X_USER_BSM_MESSAGE c3_b_u;
  const mxArray *c3_b_y = NULL;
  PRESCAN_HEADER c3_c_u;
  const mxArray *c3_c_y = NULL;
  static const char * c3_sv33[1] = { "valid" };

  boolean_T c3_d_u;
  const mxArray *c3_d_y = NULL;
  SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc3_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_b_u = *(c3_PRESCAN_V2X_USER_BSM_MESSAGE *)c3_inData;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_createstruct("structure", 2, c3_sv0, 2, 1, 1),
                false);
  c3_c_u = c3_b_u.HEADER;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_createstruct("structure", 1, c3_sv33, 2, 1, 1),
                false);
  c3_d_u = c3_c_u.valid;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_d_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_c_y, 0, "valid", c3_d_y, 0);
  sf_mex_setfieldbynum(c3_b_y, 0, "HEADER", c3_c_y, 0);
  sf_mex_setfieldbynum(c3_b_y, 0, "DATA", c3_h_emlrt_marshallOut(chartInstance,
    c3_b_u.DATA), 1);
  sf_mex_assign(&c3_mxArrayOutData, c3_b_y, false);
  return c3_mxArrayOutData;
}

static c3_PRESCAN_V2X_USER_BSM_MESSAGE c3_b_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_y,
   const char_T *c3_identifier)
{
  c3_PRESCAN_V2X_USER_BSM_MESSAGE c3_c_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_c_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_y), &c3_thisId);
  sf_mex_destroy(&c3_b_y);
  return c3_c_y;
}

static c3_PRESCAN_V2X_USER_BSM_MESSAGE c3_c_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_u,
   const emlrtMsgIdentifier *c3_parentId)
{
  c3_PRESCAN_V2X_USER_BSM_MESSAGE c3_b_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fParent = c3_parentId;
  c3_thisId.bParentIsCell = false;
  sf_mex_check_struct(c3_parentId, c3_b_u, 2, c3_sv4, 0U, NULL);
  c3_thisId.fIdentifier = "HEADER";
  c3_b_y.HEADER = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "HEADER", "HEADER", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "DATA";
  c3_b_y.DATA = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_b_u, "DATA", "DATA", 0)), &c3_thisId);
  sf_mex_destroy(&c3_b_u);
  return c3_b_y;
}

static PRESCAN_HEADER c3_d_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId)
{
  PRESCAN_HEADER c3_b_y;
  emlrtMsgIdentifier c3_thisId;
  static const char * c3_fieldNames[1] = { "valid" };

  c3_thisId.fParent = c3_parentId;
  c3_thisId.bParentIsCell = false;
  sf_mex_check_struct(c3_parentId, c3_b_u, 1, c3_fieldNames, 0U, NULL);
  c3_thisId.fIdentifier = "valid";
  c3_b_y.valid = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_b_u, "valid", "valid", 0)), &c3_thisId);
  sf_mex_destroy(&c3_b_u);
  return c3_b_y;
}

static boolean_T c3_e_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId)
{
  boolean_T c3_b_y;
  boolean_T c3_b0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), &c3_b0, 1, 11, 0U, 0, 0U, 0);
  c3_b_y = c3_b0;
  sf_mex_destroy(&c3_b_u);
  return c3_b_y;
}

static c3_PRESCAN_V2X_USER_BSM_DATA c3_f_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_u,
   const emlrtMsgIdentifier *c3_parentId)
{
  c3_PRESCAN_V2X_USER_BSM_DATA c3_b_y;
  emlrtMsgIdentifier c3_thisId;
  static const char * c3_fieldNames[14] = { "msgID", "msgCnt", "id", "secMark",
    "latitude", "longitude", "elev", "accuracy", "speed", "heading", "angle",
    "accelSet", "brakes", "size" };

  c3_thisId.fParent = c3_parentId;
  c3_thisId.bParentIsCell = false;
  sf_mex_check_struct(c3_parentId, c3_b_u, 14, c3_fieldNames, 0U, NULL);
  c3_thisId.fIdentifier = "msgID";
  c3_b_y.msgID = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_b_u, "msgID", "msgID", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "msgCnt";
  c3_b_y.msgCnt = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "msgCnt", "msgCnt", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "id";
  c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u, "id",
    "id", 0)), &c3_thisId, c3_b_y.id);
  c3_thisId.fIdentifier = "secMark";
  c3_b_y.secMark = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "secMark", "secMark", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "latitude";
  c3_b_y.latitude = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "latitude", "latitude", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "longitude";
  c3_b_y.longitude = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "longitude", "longitude", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "elev";
  c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u, "elev",
    "elev", 0)), &c3_thisId, c3_b_y.elev);
  c3_thisId.fIdentifier = "accuracy";
  c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "accuracy", "accuracy", 0)), &c3_thisId, c3_b_y.accuracy);
  c3_thisId.fIdentifier = "speed";
  c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "speed", "speed", 0)), &c3_thisId, c3_b_y.speed);
  c3_thisId.fIdentifier = "heading";
  c3_b_y.heading = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "heading", "heading", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "angle";
  c3_b_y.angle = c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_b_u, "angle", "angle", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "accelSet";
  c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "accelSet", "accelSet", 0)), &c3_thisId, c3_b_y.accelSet);
  c3_thisId.fIdentifier = "brakes";
  c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "brakes", "brakes", 0)), &c3_thisId, c3_b_y.brakes);
  c3_thisId.fIdentifier = "size";
  c3_b_y.size = c3_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_b_u, "size", "size", 0)), &c3_thisId);
  sf_mex_destroy(&c3_b_u);
  return c3_b_y;
}

static int32_T c3_g_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_b_y;
  int32_T c3_i170;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), &c3_i170, 1, 6, 0U, 0, 0U, 0);
  c3_b_y = c3_i170;
  sf_mex_destroy(&c3_b_u);
  return c3_b_y;
}

static void c3_h_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[4])
{
  int8_T c3_iv3[4];
  int32_T c3_i171;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv3, 1, 2, 0U, 1, 0U, 1, 4);
  for (c3_i171 = 0; c3_i171 < 4; c3_i171++) {
    c3_b_y[c3_i171] = c3_iv3[c3_i171];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_i_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[2])
{
  int8_T c3_iv4[2];
  int32_T c3_i172;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv4, 1, 2, 0U, 1, 0U, 1, 2);
  for (c3_i172 = 0; c3_i172 < 2; c3_i172++) {
    c3_b_y[c3_i172] = c3_iv4[c3_i172];
  }

  sf_mex_destroy(&c3_b_u);
}

static int8_T c3_j_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId)
{
  int8_T c3_b_y;
  int8_T c3_i173;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), &c3_i173, 1, 2, 0U, 0, 0U, 0);
  c3_b_y = c3_i173;
  sf_mex_destroy(&c3_b_u);
  return c3_b_y;
}

static void c3_k_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[7])
{
  int8_T c3_iv5[7];
  int32_T c3_i174;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv5, 1, 2, 0U, 1, 0U, 1, 7);
  for (c3_i174 = 0; c3_i174 < 7; c3_i174++) {
    c3_b_y[c3_i174] = c3_iv5[c3_i174];
  }

  sf_mex_destroy(&c3_b_u);
}

static c3_PRESCAN_V2X_USER_BSM_size c3_l_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_u,
   const emlrtMsgIdentifier *c3_parentId)
{
  c3_PRESCAN_V2X_USER_BSM_size c3_b_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fParent = c3_parentId;
  c3_thisId.bParentIsCell = false;
  sf_mex_check_struct(c3_parentId, c3_b_u, 2, c3_sv5, 0U, NULL);
  c3_thisId.fIdentifier = "width";
  c3_b_y.width = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_b_u, "width", "width", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "length";
  c3_b_y.length = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "length", "length", 0)), &c3_thisId);
  sf_mex_destroy(&c3_b_u);
  return c3_b_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_y;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  c3_PRESCAN_V2X_USER_BSM_MESSAGE c3_c_y;
  SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc3_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c3_b_y = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_c_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_y), &c3_thisId);
  sf_mex_destroy(&c3_b_y);
  *(c3_PRESCAN_V2X_USER_BSM_MESSAGE *)c3_outData = c3_c_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  PRESCAN_HEADER c3_b_u;
  const mxArray *c3_b_y = NULL;
  static const char * c3_sv34[1] = { "valid" };

  boolean_T c3_c_u;
  const mxArray *c3_c_y = NULL;
  SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc3_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_b_u = *(PRESCAN_HEADER *)c3_inData;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_createstruct("structure", 1, c3_sv34, 2, 1, 1),
                false);
  c3_c_u = c3_b_u.valid;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_c_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "valid", c3_c_y, 0);
  sf_mex_assign(&c3_mxArrayOutData, c3_b_y, false);
  return c3_mxArrayOutData;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_u;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  PRESCAN_HEADER c3_b_y;
  SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc3_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c3_b_u = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_u), &c3_thisId);
  sf_mex_destroy(&c3_b_u);
  *(PRESCAN_HEADER *)c3_outData = c3_b_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  c3_PRESCAN_V2X_USER_BSM_size c3_b_u;
  const mxArray *c3_b_y = NULL;
  int32_T c3_c_u;
  const mxArray *c3_c_y = NULL;
  int32_T c3_d_u;
  const mxArray *c3_d_y = NULL;
  SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc3_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_b_u = *(c3_PRESCAN_V2X_USER_BSM_size *)c3_inData;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_createstruct("structure", 2, c3_sv1, 2, 1, 1),
                false);
  c3_c_u = c3_b_u.width;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_c_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "width", c3_c_y, 0);
  c3_d_u = c3_b_u.length;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_d_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "length", c3_d_y, 1);
  sf_mex_assign(&c3_mxArrayOutData, c3_b_y, false);
  return c3_mxArrayOutData;
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_u;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  c3_PRESCAN_V2X_USER_BSM_size c3_b_y;
  SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc3_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c3_b_u = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_y = c3_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_u), &c3_thisId);
  sf_mex_destroy(&c3_b_u);
  *(c3_PRESCAN_V2X_USER_BSM_size *)c3_outData = c3_b_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  PRESCAN_V2X_FIXED_BSM_size c3_b_u;
  const mxArray *c3_b_y = NULL;
  int32_T c3_c_u;
  const mxArray *c3_c_y = NULL;
  int32_T c3_d_u;
  const mxArray *c3_d_y = NULL;
  SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc3_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_b_u = *(PRESCAN_V2X_FIXED_BSM_size *)c3_inData;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_createstruct("structure", 2, c3_sv1, 2, 1, 1),
                false);
  c3_c_u = c3_b_u.width;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_c_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "width", c3_c_y, 0);
  c3_d_u = c3_b_u.length;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_d_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c3_b_y, 0, "length", c3_d_y, 1);
  sf_mex_assign(&c3_mxArrayOutData, c3_b_y, false);
  return c3_mxArrayOutData;
}

static PRESCAN_V2X_FIXED_BSM_size c3_m_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_u,
   const emlrtMsgIdentifier *c3_parentId)
{
  PRESCAN_V2X_FIXED_BSM_size c3_b_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fParent = c3_parentId;
  c3_thisId.bParentIsCell = false;
  sf_mex_check_struct(c3_parentId, c3_b_u, 2, c3_sv5, 0U, NULL);
  c3_thisId.fIdentifier = "width";
  c3_b_y.width = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_b_u, "width", "width", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "length";
  c3_b_y.length = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "length", "length", 0)), &c3_thisId);
  sf_mex_destroy(&c3_b_u);
  return c3_b_y;
}

static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_y;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  PRESCAN_V2X_FIXED_BSM_size c3_c_y;
  SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc3_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c3_b_y = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_c_y = c3_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_y), &c3_thisId);
  sf_mex_destroy(&c3_b_y);
  *(PRESCAN_V2X_FIXED_BSM_size *)c3_outData = c3_c_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc3_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  sf_mex_assign(&c3_mxArrayOutData, c3_h_emlrt_marshallOut(chartInstance,
    *(c3_PRESCAN_V2X_USER_BSM_DATA *)c3_inData), false);
  return c3_mxArrayOutData;
}

static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_u;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  c3_PRESCAN_V2X_USER_BSM_DATA c3_b_y;
  SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc3_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c3_b_u = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_u), &c3_thisId);
  sf_mex_destroy(&c3_b_u);
  *(c3_PRESCAN_V2X_USER_BSM_DATA *)c3_outData = c3_b_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_h_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc3_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  sf_mex_assign(&c3_mxArrayOutData, c3_emlrt_marshallOut(chartInstance,
    (PRESCAN_V2X_FIXED_BSM_DATA *)c3_inData), false);
  return c3_mxArrayOutData;
}

static void c3_n_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  PRESCAN_V2X_FIXED_BSM_DATA *c3_b_y)
{
  emlrtMsgIdentifier c3_thisId;
  static const char * c3_fieldNames[16] = { "msgID", "msgCnt", "id", "secMark",
    "latitude", "longitude", "elev", "accuracy", "speed", "heading", "angle",
    "accelSet", "brakes", "size", "safetyExt", "status" };

  c3_thisId.fParent = c3_parentId;
  c3_thisId.bParentIsCell = false;
  sf_mex_check_struct(c3_parentId, c3_b_u, 16, c3_fieldNames, 0U, NULL);
  c3_thisId.fIdentifier = "msgID";
  c3_b_y->msgID = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "msgID", "msgID", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "msgCnt";
  c3_b_y->msgCnt = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "msgCnt", "msgCnt", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "id";
  c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u, "id",
    "id", 0)), &c3_thisId, c3_b_y->id);
  c3_thisId.fIdentifier = "secMark";
  c3_b_y->secMark = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "secMark", "secMark", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "latitude";
  c3_b_y->latitude = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "latitude", "latitude", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "longitude";
  c3_b_y->longitude = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "longitude", "longitude", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "elev";
  c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u, "elev",
    "elev", 0)), &c3_thisId, c3_b_y->elev);
  c3_thisId.fIdentifier = "accuracy";
  c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "accuracy", "accuracy", 0)), &c3_thisId, c3_b_y->accuracy);
  c3_thisId.fIdentifier = "speed";
  c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "speed", "speed", 0)), &c3_thisId, c3_b_y->speed);
  c3_thisId.fIdentifier = "heading";
  c3_b_y->heading = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "heading", "heading", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "angle";
  c3_b_y->angle = c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "angle", "angle", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "accelSet";
  c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "accelSet", "accelSet", 0)), &c3_thisId, c3_b_y->accelSet);
  c3_thisId.fIdentifier = "brakes";
  c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "brakes", "brakes", 0)), &c3_thisId, c3_b_y->brakes);
  c3_thisId.fIdentifier = "size";
  c3_b_y->size = c3_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_b_u, "size", "size", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "safetyExt";
  c3_o_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "safetyExt", "safetyExt", 0)), &c3_thisId, &c3_b_y->safetyExt);
  c3_thisId.fIdentifier = "status";
  c3_lc_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "status", "status", 0)), &c3_thisId, &c3_b_y->status);
  sf_mex_destroy(&c3_b_u);
}

static void c3_o_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  PRESCAN_V2X_FIXED_BSM_safetyExt *c3_b_y)
{
  emlrtMsgIdentifier c3_thisId;
  static const char * c3_fieldNames[4] = { "events", "pathHistory",
    "pathPrediction", "theRTCM" };

  c3_thisId.fParent = c3_parentId;
  c3_thisId.bParentIsCell = false;
  sf_mex_check_struct(c3_parentId, c3_b_u, 4, c3_fieldNames, 0U, NULL);
  c3_thisId.fIdentifier = "events";
  c3_b_y->events = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "events", "events", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "pathHistory";
  c3_p_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "pathHistory", "pathHistory", 0)), &c3_thisId, &c3_b_y->pathHistory);
  c3_thisId.fIdentifier = "pathPrediction";
  c3_b_y->pathPrediction = c3_eb_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "pathPrediction", "pathPrediction", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "theRTCM";
  c3_fb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "theRTCM", "theRTCM", 0)), &c3_thisId, &c3_b_y->theRTCM);
  sf_mex_destroy(&c3_b_u);
}

static void c3_p_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  PRESCAN_V2X_FIXED_BSM_pathHistory *c3_b_y)
{
  emlrtMsgIdentifier c3_thisId;
  static const char * c3_fieldNames[4] = { "initialPosition", "currGPSstatus",
    "itemCnt", "crumbData" };

  c3_thisId.fParent = c3_parentId;
  c3_thisId.bParentIsCell = false;
  sf_mex_check_struct(c3_parentId, c3_b_u, 4, c3_fieldNames, 0U, NULL);
  c3_thisId.fIdentifier = "initialPosition";
  c3_b_y->initialPosition = c3_q_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "initialPosition", "initialPosition", 0)),
    &c3_thisId);
  c3_thisId.fIdentifier = "currGPSstatus";
  c3_b_y->currGPSstatus = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "currGPSstatus", "currGPSstatus", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "itemCnt";
  c3_b_y->itemCnt = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "itemCnt", "itemCnt", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "crumbData";
  c3_s_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "crumbData", "crumbData", 0)), &c3_thisId, &c3_b_y->crumbData);
  sf_mex_destroy(&c3_b_u);
}

static PRESCAN_V2X_FIXED_BSM_initialPosition c3_q_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_u,
   const emlrtMsgIdentifier *c3_parentId)
{
  PRESCAN_V2X_FIXED_BSM_initialPosition c3_b_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fParent = c3_parentId;
  c3_thisId.bParentIsCell = false;
  sf_mex_check_struct(c3_parentId, c3_b_u, 10, c3_sv6, 0U, NULL);
  c3_thisId.fIdentifier = "utcTime";
  c3_b_y.utcTime = c3_r_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "utcTime", "utcTime", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "longitude";
  c3_b_y.longitude = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "longitude", "longitude", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "latitude";
  c3_b_y.latitude = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "latitude", "latitude", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "elevation";
  c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "elevation", "elevation", 0)), &c3_thisId, c3_b_y.elevation);
  c3_thisId.fIdentifier = "heading";
  c3_b_y.heading = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "heading", "heading", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "speed";
  c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "speed", "speed", 0)), &c3_thisId, c3_b_y.speed);
  c3_thisId.fIdentifier = "posAccuracy";
  c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "posAccuracy", "posAccuracy", 0)), &c3_thisId, c3_b_y.posAccuracy);
  c3_thisId.fIdentifier = "timeConfidence";
  c3_b_y.timeConfidence = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "timeConfidence", "timeConfidence", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "posConfidence";
  c3_b_y.posConfidence = c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "posConfidence", "posConfidence", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "speedConfidence";
  c3_b_y.speedConfidence = c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "speedConfidence", "speedConfidence", 0)),
    &c3_thisId);
  sf_mex_destroy(&c3_b_u);
  return c3_b_y;
}

static PRESCAN_V2X_FIXED_BSM_utcTime c3_r_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_u,
   const emlrtMsgIdentifier *c3_parentId)
{
  PRESCAN_V2X_FIXED_BSM_utcTime c3_b_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fParent = c3_parentId;
  c3_thisId.bParentIsCell = false;
  sf_mex_check_struct(c3_parentId, c3_b_u, 6, c3_sv7, 0U, NULL);
  c3_thisId.fIdentifier = "year";
  c3_b_y.year = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_b_u, "year", "year", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "month";
  c3_b_y.month = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_b_u, "month", "month", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "day";
  c3_b_y.day = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_b_u, "day", "day", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "hour";
  c3_b_y.hour = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_b_u, "hour", "hour", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "minute";
  c3_b_y.minute = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "minute", "minute", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "second";
  c3_b_y.second = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "second", "second", 0)), &c3_thisId);
  sf_mex_destroy(&c3_b_u);
  return c3_b_y;
}

static void c3_s_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  PRESCAN_V2X_FIXED_BSM_crumbData *c3_b_y)
{
  emlrtMsgIdentifier c3_thisId;
  static const char * c3_fieldNames[10] = { "pathHistoryPointSets_01",
    "pathHistoryPointSets_02", "pathHistoryPointSets_03",
    "pathHistoryPointSets_04", "pathHistoryPointSets_05",
    "pathHistoryPointSets_06", "pathHistoryPointSets_07",
    "pathHistoryPointSets_08", "pathHistoryPointSets_09",
    "pathHistoryPointSets_10" };

  c3_thisId.fParent = c3_parentId;
  c3_thisId.bParentIsCell = false;
  sf_mex_check_struct(c3_parentId, c3_b_u, 10, c3_fieldNames, 0U, NULL);
  c3_thisId.fIdentifier = "pathHistoryPointSets_01";
  c3_t_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "pathHistoryPointSets_01", "pathHistoryPointSets_01", 0)), &c3_thisId,
                        c3_b_y->pathHistoryPointSets_01);
  c3_thisId.fIdentifier = "pathHistoryPointSets_02";
  c3_u_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "pathHistoryPointSets_02", "pathHistoryPointSets_02", 0)), &c3_thisId,
                        c3_b_y->pathHistoryPointSets_02);
  c3_thisId.fIdentifier = "pathHistoryPointSets_03";
  c3_v_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "pathHistoryPointSets_03", "pathHistoryPointSets_03", 0)), &c3_thisId,
                        c3_b_y->pathHistoryPointSets_03);
  c3_thisId.fIdentifier = "pathHistoryPointSets_04";
  c3_w_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "pathHistoryPointSets_04", "pathHistoryPointSets_04", 0)), &c3_thisId,
                        c3_b_y->pathHistoryPointSets_04);
  c3_thisId.fIdentifier = "pathHistoryPointSets_05";
  c3_x_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "pathHistoryPointSets_05", "pathHistoryPointSets_05", 0)), &c3_thisId,
                        c3_b_y->pathHistoryPointSets_05);
  c3_thisId.fIdentifier = "pathHistoryPointSets_06";
  c3_y_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "pathHistoryPointSets_06", "pathHistoryPointSets_06", 0)), &c3_thisId,
                        c3_b_y->pathHistoryPointSets_06);
  c3_thisId.fIdentifier = "pathHistoryPointSets_07";
  c3_ab_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "pathHistoryPointSets_07", "pathHistoryPointSets_07", 0)), &c3_thisId,
    c3_b_y->pathHistoryPointSets_07);
  c3_thisId.fIdentifier = "pathHistoryPointSets_08";
  c3_bb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "pathHistoryPointSets_08", "pathHistoryPointSets_08", 0)), &c3_thisId,
    c3_b_y->pathHistoryPointSets_08);
  c3_thisId.fIdentifier = "pathHistoryPointSets_09";
  c3_cb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "pathHistoryPointSets_09", "pathHistoryPointSets_09", 0)), &c3_thisId,
    c3_b_y->pathHistoryPointSets_09);
  c3_thisId.fIdentifier = "pathHistoryPointSets_10";
  c3_db_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "pathHistoryPointSets_10", "pathHistoryPointSets_10", 0)), &c3_thisId,
    c3_b_y->pathHistoryPointSets_10);
  sf_mex_destroy(&c3_b_u);
}

static void c3_t_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 c3_b_y[23])
{
  uint32_T c3_uv0[1];
  emlrtMsgIdentifier c3_thisId;
  static const char * c3_fieldNames[7] = { "latOffset", "longOffset",
    "elevationOffset", "timeOffset", "posAccuracy", "heading", "speed" };

  int32_T c3_i175;
  c3_uv0[0] = 23U;
  c3_thisId.fParent = c3_parentId;
  c3_thisId.bParentIsCell = false;
  sf_mex_check_struct(c3_parentId, c3_b_u, 7, c3_fieldNames, 1U, c3_uv0);
  for (c3_i175 = 0; c3_i175 < 23; c3_i175++) {
    c3_thisId.fIdentifier = "latOffset";
    c3_b_y[c3_i175].latOffset = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c3_b_u, "latOffset", "latOffset", c3_i175)), &c3_thisId);
    c3_thisId.fIdentifier = "longOffset";
    c3_b_y[c3_i175].longOffset = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c3_b_u, "longOffset", "longOffset", c3_i175)), &c3_thisId);
    c3_thisId.fIdentifier = "elevationOffset";
    c3_b_y[c3_i175].elevationOffset = c3_g_emlrt_marshallIn(chartInstance,
      sf_mex_dup(sf_mex_getfield(c3_b_u, "elevationOffset", "elevationOffset",
      c3_i175)), &c3_thisId);
    c3_thisId.fIdentifier = "timeOffset";
    c3_b_y[c3_i175].timeOffset = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c3_b_u, "timeOffset", "timeOffset", c3_i175)), &c3_thisId);
    c3_thisId.fIdentifier = "posAccuracy";
    c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
      "posAccuracy", "posAccuracy", c3_i175)), &c3_thisId, c3_b_y[c3_i175].
                          posAccuracy);
    c3_thisId.fIdentifier = "heading";
    c3_b_y[c3_i175].heading = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c3_b_u, "heading", "heading", c3_i175)), &c3_thisId);
    c3_thisId.fIdentifier = "speed";
    c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
      "speed", "speed", c3_i175)), &c3_thisId, c3_b_y[c3_i175].speed);
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_u_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[345])
{
  int8_T c3_iv6[345];
  int32_T c3_i176;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv6, 1, 2, 0U, 1, 0U, 1, 345);
  for (c3_i176 = 0; c3_i176 < 345; c3_i176++) {
    c3_b_y[c3_i176] = c3_iv6[c3_i176];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_v_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[276])
{
  int8_T c3_iv7[276];
  int32_T c3_i177;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv7, 1, 2, 0U, 1, 0U, 1, 276);
  for (c3_i177 = 0; c3_i177 < 276; c3_i177++) {
    c3_b_y[c3_i177] = c3_iv7[c3_i177];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_w_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[184])
{
  int8_T c3_iv8[184];
  int32_T c3_i178;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv8, 1, 2, 0U, 1, 0U, 1, 184);
  for (c3_i178 = 0; c3_i178 < 184; c3_i178++) {
    c3_b_y[c3_i178] = c3_iv8[c3_i178];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_x_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[230])
{
  int8_T c3_iv9[230];
  int32_T c3_i179;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv9, 1, 2, 0U, 1, 0U, 1, 230);
  for (c3_i179 = 0; c3_i179 < 230; c3_i179++) {
    c3_b_y[c3_i179] = c3_iv9[c3_i179];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_y_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[138])
{
  int8_T c3_iv10[138];
  int32_T c3_i180;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv10, 1, 2, 0U, 1, 0U, 1,
                138);
  for (c3_i180 = 0; c3_i180 < 138; c3_i180++) {
    c3_b_y[c3_i180] = c3_iv10[c3_i180];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_ab_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[242])
{
  int8_T c3_iv11[242];
  int32_T c3_i181;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv11, 1, 2, 0U, 1, 0U, 1,
                242);
  for (c3_i181 = 0; c3_i181 < 242; c3_i181++) {
    c3_b_y[c3_i181] = c3_iv11[c3_i181];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_bb_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[161])
{
  int8_T c3_iv12[161];
  int32_T c3_i182;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv12, 1, 2, 0U, 1, 0U, 1,
                161);
  for (c3_i182 = 0; c3_i182 < 161; c3_i182++) {
    c3_b_y[c3_i182] = c3_iv12[c3_i182];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_cb_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[196])
{
  int8_T c3_iv13[196];
  int32_T c3_i183;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv13, 1, 2, 0U, 1, 0U, 1,
                196);
  for (c3_i183 = 0; c3_i183 < 196; c3_i183++) {
    c3_b_y[c3_i183] = c3_iv13[c3_i183];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_db_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[104])
{
  int8_T c3_iv14[104];
  int32_T c3_i184;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv14, 1, 2, 0U, 1, 0U, 1,
                104);
  for (c3_i184 = 0; c3_i184 < 104; c3_i184++) {
    c3_b_y[c3_i184] = c3_iv14[c3_i184];
  }

  sf_mex_destroy(&c3_b_u);
}

static PRESCAN_V2X_FIXED_BSM_pathPrediction c3_eb_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_u,
   const emlrtMsgIdentifier *c3_parentId)
{
  PRESCAN_V2X_FIXED_BSM_pathPrediction c3_b_y;
  emlrtMsgIdentifier c3_thisId;
  static const char * c3_fieldNames[2] = { "radiusOfCurve", "confidence" };

  c3_thisId.fParent = c3_parentId;
  c3_thisId.bParentIsCell = false;
  sf_mex_check_struct(c3_parentId, c3_b_u, 2, c3_fieldNames, 0U, NULL);
  c3_thisId.fIdentifier = "radiusOfCurve";
  c3_b_y.radiusOfCurve = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "radiusOfCurve", "radiusOfCurve", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "confidence";
  c3_b_y.confidence = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "confidence", "confidence", 0)), &c3_thisId);
  sf_mex_destroy(&c3_b_u);
  return c3_b_y;
}

static void c3_fb_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  PRESCAN_V2X_FIXED_BSM_theRTCM *c3_b_y)
{
  emlrtMsgIdentifier c3_thisId;
  static const char * c3_fieldNames[32] = { "anchorPoint", "rtcmHeader",
    "msg1001", "msg1002", "msg1003", "msg1004", "msg1005", "msg1006", "msg1007",
    "msg1008", "msg1009", "msg1010", "msg1011", "msg1012", "msg1013", "msg1014",
    "msg1015", "msg1016", "msg1017", "msg1019", "msg1020", "msg1021", "msg1022",
    "msg1023", "msg1024", "msg1025", "msg1026", "msg1027", "msg1029", "msg1030",
    "msg1031", "msg1032" };

  c3_thisId.fParent = c3_parentId;
  c3_thisId.bParentIsCell = false;
  sf_mex_check_struct(c3_parentId, c3_b_u, 32, c3_fieldNames, 0U, NULL);
  c3_thisId.fIdentifier = "anchorPoint";
  c3_b_y->anchorPoint = c3_gb_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "anchorPoint", "anchorPoint", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "rtcmHeader";
  c3_hb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "rtcmHeader", "rtcmHeader", 0)), &c3_thisId, c3_b_y->rtcmHeader);
  c3_thisId.fIdentifier = "msg1001";
  c3_ib_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "msg1001", "msg1001", 0)), &c3_thisId, c3_b_y->msg1001);
  c3_thisId.fIdentifier = "msg1002";
  c3_jb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "msg1002", "msg1002", 0)), &c3_thisId, c3_b_y->msg1002);
  c3_thisId.fIdentifier = "msg1003";
  c3_kb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "msg1003", "msg1003", 0)), &c3_thisId, c3_b_y->msg1003);
  c3_thisId.fIdentifier = "msg1004";
  c3_lb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "msg1004", "msg1004", 0)), &c3_thisId, c3_b_y->msg1004);
  c3_thisId.fIdentifier = "msg1005";
  c3_mb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "msg1005", "msg1005", 0)), &c3_thisId, c3_b_y->msg1005);
  c3_thisId.fIdentifier = "msg1006";
  c3_nb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "msg1006", "msg1006", 0)), &c3_thisId, c3_b_y->msg1006);
  c3_thisId.fIdentifier = "msg1007";
  c3_ob_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "msg1007", "msg1007", 0)), &c3_thisId, c3_b_y->msg1007);
  c3_thisId.fIdentifier = "msg1008";
  c3_pb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "msg1008", "msg1008", 0)), &c3_thisId, c3_b_y->msg1008);
  c3_thisId.fIdentifier = "msg1009";
  c3_qb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "msg1009", "msg1009", 0)), &c3_thisId, c3_b_y->msg1009);
  c3_thisId.fIdentifier = "msg1010";
  c3_rb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "msg1010", "msg1010", 0)), &c3_thisId, c3_b_y->msg1010);
  c3_thisId.fIdentifier = "msg1011";
  c3_sb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "msg1011", "msg1011", 0)), &c3_thisId, c3_b_y->msg1011);
  c3_thisId.fIdentifier = "msg1012";
  c3_tb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "msg1012", "msg1012", 0)), &c3_thisId, c3_b_y->msg1012);
  c3_thisId.fIdentifier = "msg1013";
  c3_ub_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "msg1013", "msg1013", 0)), &c3_thisId, c3_b_y->msg1013);
  c3_thisId.fIdentifier = "msg1014";
  c3_vb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "msg1014", "msg1014", 0)), &c3_thisId, c3_b_y->msg1014);
  c3_thisId.fIdentifier = "msg1015";
  c3_wb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "msg1015", "msg1015", 0)), &c3_thisId, c3_b_y->msg1015);
  c3_thisId.fIdentifier = "msg1016";
  c3_xb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "msg1016", "msg1016", 0)), &c3_thisId, c3_b_y->msg1016);
  c3_thisId.fIdentifier = "msg1017";
  c3_yb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "msg1017", "msg1017", 0)), &c3_thisId, c3_b_y->msg1017);
  c3_thisId.fIdentifier = "msg1019";
  c3_ac_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "msg1019", "msg1019", 0)), &c3_thisId, c3_b_y->msg1019);
  c3_thisId.fIdentifier = "msg1020";
  c3_bc_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "msg1020", "msg1020", 0)), &c3_thisId, c3_b_y->msg1020);
  c3_thisId.fIdentifier = "msg1021";
  c3_ac_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "msg1021", "msg1021", 0)), &c3_thisId, c3_b_y->msg1021);
  c3_thisId.fIdentifier = "msg1022";
  c3_cc_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "msg1022", "msg1022", 0)), &c3_thisId, c3_b_y->msg1022);
  c3_thisId.fIdentifier = "msg1023";
  c3_dc_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "msg1023", "msg1023", 0)), &c3_thisId, c3_b_y->msg1023);
  c3_thisId.fIdentifier = "msg1024";
  c3_ec_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "msg1024", "msg1024", 0)), &c3_thisId, c3_b_y->msg1024);
  c3_thisId.fIdentifier = "msg1025";
  c3_fc_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "msg1025", "msg1025", 0)), &c3_thisId, c3_b_y->msg1025);
  c3_thisId.fIdentifier = "msg1026";
  c3_gc_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "msg1026", "msg1026", 0)), &c3_thisId, c3_b_y->msg1026);
  c3_thisId.fIdentifier = "msg1027";
  c3_hc_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "msg1027", "msg1027", 0)), &c3_thisId, c3_b_y->msg1027);
  c3_thisId.fIdentifier = "msg1029";
  c3_wb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "msg1029", "msg1029", 0)), &c3_thisId, c3_b_y->msg1029);
  c3_thisId.fIdentifier = "msg1030";
  c3_ic_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "msg1030", "msg1030", 0)), &c3_thisId, c3_b_y->msg1030);
  c3_thisId.fIdentifier = "msg1031";
  c3_jc_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "msg1031", "msg1031", 0)), &c3_thisId, c3_b_y->msg1031);
  c3_thisId.fIdentifier = "msg1032";
  c3_kc_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "msg1032", "msg1032", 0)), &c3_thisId, c3_b_y->msg1032);
  sf_mex_destroy(&c3_b_u);
}

static PRESCAN_V2X_FIXED_BSM_anchorPoint c3_gb_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_u,
   const emlrtMsgIdentifier *c3_parentId)
{
  PRESCAN_V2X_FIXED_BSM_anchorPoint c3_b_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fParent = c3_parentId;
  c3_thisId.bParentIsCell = false;
  sf_mex_check_struct(c3_parentId, c3_b_u, 10, c3_sv6, 0U, NULL);
  c3_thisId.fIdentifier = "utcTime";
  c3_b_y.utcTime = c3_r_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "utcTime", "utcTime", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "longitude";
  c3_b_y.longitude = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "longitude", "longitude", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "latitude";
  c3_b_y.latitude = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "latitude", "latitude", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "elevation";
  c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "elevation", "elevation", 0)), &c3_thisId, c3_b_y.elevation);
  c3_thisId.fIdentifier = "heading";
  c3_b_y.heading = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "heading", "heading", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "speed";
  c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "speed", "speed", 0)), &c3_thisId, c3_b_y.speed);
  c3_thisId.fIdentifier = "posAccuracy";
  c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "posAccuracy", "posAccuracy", 0)), &c3_thisId, c3_b_y.posAccuracy);
  c3_thisId.fIdentifier = "timeConfidence";
  c3_b_y.timeConfidence = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "timeConfidence", "timeConfidence", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "posConfidence";
  c3_b_y.posConfidence = c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "posConfidence", "posConfidence", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "speedConfidence";
  c3_b_y.speedConfidence = c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "speedConfidence", "speedConfidence", 0)),
    &c3_thisId);
  sf_mex_destroy(&c3_b_u);
  return c3_b_y;
}

static void c3_hb_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[5])
{
  int8_T c3_iv15[5];
  int32_T c3_i185;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv15, 1, 2, 0U, 1, 0U, 1, 5);
  for (c3_i185 = 0; c3_i185 < 5; c3_i185++) {
    c3_b_y[c3_i185] = c3_iv15[c3_i185];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_ib_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[124])
{
  int8_T c3_iv16[124];
  int32_T c3_i186;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv16, 1, 2, 0U, 1, 0U, 1,
                124);
  for (c3_i186 = 0; c3_i186 < 124; c3_i186++) {
    c3_b_y[c3_i186] = c3_iv16[c3_i186];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_jb_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[156])
{
  int8_T c3_iv17[156];
  int32_T c3_i187;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv17, 1, 2, 0U, 1, 0U, 1,
                156);
  for (c3_i187 = 0; c3_i187 < 156; c3_i187++) {
    c3_b_y[c3_i187] = c3_iv17[c3_i187];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_kb_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[210])
{
  int8_T c3_iv18[210];
  int32_T c3_i188;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv18, 1, 2, 0U, 1, 0U, 1,
                210);
  for (c3_i188 = 0; c3_i188 < 210; c3_i188++) {
    c3_b_y[c3_i188] = c3_iv18[c3_i188];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_lb_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[258])
{
  int8_T c3_iv19[258];
  int32_T c3_i189;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv19, 1, 2, 0U, 1, 0U, 1,
                258);
  for (c3_i189 = 0; c3_i189 < 258; c3_i189++) {
    c3_b_y[c3_i189] = c3_iv19[c3_i189];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_mb_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[19])
{
  int8_T c3_iv20[19];
  int32_T c3_i190;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv20, 1, 2, 0U, 1, 0U, 1, 19);
  for (c3_i190 = 0; c3_i190 < 19; c3_i190++) {
    c3_b_y[c3_i190] = c3_iv20[c3_i190];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_nb_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[21])
{
  int8_T c3_iv21[21];
  int32_T c3_i191;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv21, 1, 2, 0U, 1, 0U, 1, 21);
  for (c3_i191 = 0; c3_i191 < 21; c3_i191++) {
    c3_b_y[c3_i191] = c3_iv21[c3_i191];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_ob_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[36])
{
  int8_T c3_iv22[36];
  int32_T c3_i192;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv22, 1, 2, 0U, 1, 0U, 1, 36);
  for (c3_i192 = 0; c3_i192 < 36; c3_i192++) {
    c3_b_y[c3_i192] = c3_iv22[c3_i192];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_pb_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[68])
{
  int8_T c3_iv23[68];
  int32_T c3_i193;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv23, 1, 2, 0U, 1, 0U, 1, 68);
  for (c3_i193 = 0; c3_i193 < 68; c3_i193++) {
    c3_b_y[c3_i193] = c3_iv23[c3_i193];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_qb_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[136])
{
  int8_T c3_iv24[136];
  int32_T c3_i194;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv24, 1, 2, 0U, 1, 0U, 1,
                136);
  for (c3_i194 = 0; c3_i194 < 136; c3_i194++) {
    c3_b_y[c3_i194] = c3_iv24[c3_i194];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_rb_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[166])
{
  int8_T c3_iv25[166];
  int32_T c3_i195;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv25, 1, 2, 0U, 1, 0U, 1,
                166);
  for (c3_i195 = 0; c3_i195 < 166; c3_i195++) {
    c3_b_y[c3_i195] = c3_iv25[c3_i195];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_sb_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[222])
{
  int8_T c3_iv26[222];
  int32_T c3_i196;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv26, 1, 2, 0U, 1, 0U, 1,
                222);
  for (c3_i196 = 0; c3_i196 < 222; c3_i196++) {
    c3_b_y[c3_i196] = c3_iv26[c3_i196];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_tb_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[268])
{
  int8_T c3_iv27[268];
  int32_T c3_i197;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv27, 1, 2, 0U, 1, 0U, 1,
                268);
  for (c3_i197 = 0; c3_i197 < 268; c3_i197++) {
    c3_b_y[c3_i197] = c3_iv27[c3_i197];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_ub_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[27])
{
  int8_T c3_iv28[27];
  int32_T c3_i198;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv28, 1, 2, 0U, 1, 0U, 1, 27);
  for (c3_i198 = 0; c3_i198 < 27; c3_i198++) {
    c3_b_y[c3_i198] = c3_iv28[c3_i198];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_vb_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[15])
{
  int8_T c3_iv29[15];
  int32_T c3_i199;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv29, 1, 2, 0U, 1, 0U, 1, 15);
  for (c3_i199 = 0; c3_i199 < 15; c3_i199++) {
    c3_b_y[c3_i199] = c3_iv29[c3_i199];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_wb_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[69])
{
  int8_T c3_iv30[69];
  int32_T c3_i200;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv30, 1, 2, 0U, 1, 0U, 1, 69);
  for (c3_i200 = 0; c3_i200 < 69; c3_i200++) {
    c3_b_y[c3_i200] = c3_iv30[c3_i200];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_xb_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[81])
{
  int8_T c3_iv31[81];
  int32_T c3_i201;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv31, 1, 2, 0U, 1, 0U, 1, 81);
  for (c3_i201 = 0; c3_i201 < 81; c3_i201++) {
    c3_b_y[c3_i201] = c3_iv31[c3_i201];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_yb_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[115])
{
  int8_T c3_iv32[115];
  int32_T c3_i202;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv32, 1, 2, 0U, 1, 0U, 1,
                115);
  for (c3_i202 = 0; c3_i202 < 115; c3_i202++) {
    c3_b_y[c3_i202] = c3_iv32[c3_i202];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_ac_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[62])
{
  int8_T c3_iv33[62];
  int32_T c3_i203;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv33, 1, 2, 0U, 1, 0U, 1, 62);
  for (c3_i203 = 0; c3_i203 < 62; c3_i203++) {
    c3_b_y[c3_i203] = c3_iv33[c3_i203];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_bc_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[45])
{
  int8_T c3_iv34[45];
  int32_T c3_i204;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv34, 1, 2, 0U, 1, 0U, 1, 45);
  for (c3_i204 = 0; c3_i204 < 45; c3_i204++) {
    c3_b_y[c3_i204] = c3_iv34[c3_i204];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_cc_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[75])
{
  int8_T c3_iv35[75];
  int32_T c3_i205;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv35, 1, 2, 0U, 1, 0U, 1, 75);
  for (c3_i205 = 0; c3_i205 < 75; c3_i205++) {
    c3_b_y[c3_i205] = c3_iv35[c3_i205];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_dc_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[73])
{
  int8_T c3_iv36[73];
  int32_T c3_i206;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv36, 1, 2, 0U, 1, 0U, 1, 73);
  for (c3_i206 = 0; c3_i206 < 73; c3_i206++) {
    c3_b_y[c3_i206] = c3_iv36[c3_i206];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_ec_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[74])
{
  int8_T c3_iv37[74];
  int32_T c3_i207;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv37, 1, 2, 0U, 1, 0U, 1, 74);
  for (c3_i207 = 0; c3_i207 < 74; c3_i207++) {
    c3_b_y[c3_i207] = c3_iv37[c3_i207];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_fc_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[25])
{
  int8_T c3_iv38[25];
  int32_T c3_i208;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv38, 1, 2, 0U, 1, 0U, 1, 25);
  for (c3_i208 = 0; c3_i208 < 25; c3_i208++) {
    c3_b_y[c3_i208] = c3_iv38[c3_i208];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_gc_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[30])
{
  int8_T c3_iv39[30];
  int32_T c3_i209;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv39, 1, 2, 0U, 1, 0U, 1, 30);
  for (c3_i209 = 0; c3_i209 < 30; c3_i209++) {
    c3_b_y[c3_i209] = c3_iv39[c3_i209];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_hc_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[33])
{
  int8_T c3_iv40[33];
  int32_T c3_i210;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv40, 1, 2, 0U, 1, 0U, 1, 33);
  for (c3_i210 = 0; c3_i210 < 33; c3_i210++) {
    c3_b_y[c3_i210] = c3_iv40[c3_i210];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_ic_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[105])
{
  int8_T c3_iv41[105];
  int32_T c3_i211;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv41, 1, 2, 0U, 1, 0U, 1,
                105);
  for (c3_i211 = 0; c3_i211 < 105; c3_i211++) {
    c3_b_y[c3_i211] = c3_iv41[c3_i211];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_jc_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[107])
{
  int8_T c3_iv42[107];
  int32_T c3_i212;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv42, 1, 2, 0U, 1, 0U, 1,
                107);
  for (c3_i212 = 0; c3_i212 < 107; c3_i212++) {
    c3_b_y[c3_i212] = c3_iv42[c3_i212];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_kc_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[20])
{
  int8_T c3_iv43[20];
  int32_T c3_i213;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv43, 1, 2, 0U, 1, 0U, 1, 20);
  for (c3_i213 = 0; c3_i213 < 20; c3_i213++) {
    c3_b_y[c3_i213] = c3_iv43[c3_i213];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_lc_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  PRESCAN_V2X_FIXED_BSM_status *c3_b_y)
{
  emlrtMsgIdentifier c3_thisId;
  static const char * c3_fieldNames[22] = { "lights", "lightBar", "wipers",
    "brakeStatus", "brakePressure", "roadFriction", "sunData", "rainData",
    "airTemp", "airPres", "steering", "accelSets", "object", "fullPos",
    "throttlePos", "speedHeadC", "speedC", "vehicleData", "vehicleIdent",
    "j1939data", "weatherReport", "gpsStatus" };

  c3_thisId.fParent = c3_parentId;
  c3_thisId.bParentIsCell = false;
  sf_mex_check_struct(c3_parentId, c3_b_u, 22, c3_fieldNames, 0U, NULL);
  c3_thisId.fIdentifier = "lights";
  c3_b_y->lights = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "lights", "lights", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "lightBar";
  c3_b_y->lightBar = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "lightBar", "lightBar", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "wipers";
  c3_b_y->wipers = c3_mc_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "wipers", "wipers", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "brakeStatus";
  c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "brakeStatus", "brakeStatus", 0)), &c3_thisId, c3_b_y->brakeStatus);
  c3_thisId.fIdentifier = "brakePressure";
  c3_b_y->brakePressure = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "brakePressure", "brakePressure", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "roadFriction";
  c3_b_y->roadFriction = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "roadFriction", "roadFriction", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "sunData";
  c3_b_y->sunData = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "sunData", "sunData", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "rainData";
  c3_b_y->rainData = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "rainData", "rainData", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "airTemp";
  c3_b_y->airTemp = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "airTemp", "airTemp", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "airPres";
  c3_b_y->airPres = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "airPres", "airPres", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "steering";
  c3_b_y->steering = c3_nc_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "steering", "steering", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "accelSets";
  c3_b_y->accelSets = c3_oc_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "accelSets", "accelSets", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "object";
  c3_b_y->object = c3_rc_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "object", "object", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "fullPos";
  c3_b_y->fullPos = c3_tc_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "fullPos", "fullPos", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "throttlePos";
  c3_b_y->throttlePos = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "throttlePos", "throttlePos", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "speedHeadC";
  c3_b_y->speedHeadC = c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "speedHeadC", "speedHeadC", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "speedC";
  c3_b_y->speedC = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "speedC", "speedC", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "vehicleData";
  c3_b_y->vehicleData = c3_uc_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "vehicleData", "vehicleData", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "vehicleIdent";
  c3_wc_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "vehicleIdent", "vehicleIdent", 0)), &c3_thisId, &c3_b_y->vehicleIdent);
  c3_thisId.fIdentifier = "j1939data";
  c3_cd_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "j1939data", "j1939data", 0)), &c3_thisId, &c3_b_y->j1939data);
  c3_thisId.fIdentifier = "weatherReport";
  c3_b_y->weatherReport = c3_fd_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "weatherReport", "weatherReport", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "gpsStatus";
  c3_b_y->gpsStatus = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "gpsStatus", "gpsStatus", 0)), &c3_thisId);
  sf_mex_destroy(&c3_b_u);
}

static PRESCAN_V2X_FIXED_BSM_wipers c3_mc_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_u,
   const emlrtMsgIdentifier *c3_parentId)
{
  PRESCAN_V2X_FIXED_BSM_wipers c3_b_y;
  emlrtMsgIdentifier c3_thisId;
  static const char * c3_fieldNames[4] = { "statusFront", "rateFront",
    "statusRear", "rateRear" };

  c3_thisId.fParent = c3_parentId;
  c3_thisId.bParentIsCell = false;
  sf_mex_check_struct(c3_parentId, c3_b_u, 4, c3_fieldNames, 0U, NULL);
  c3_thisId.fIdentifier = "statusFront";
  c3_b_y.statusFront = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "statusFront", "statusFront", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "rateFront";
  c3_b_y.rateFront = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "rateFront", "rateFront", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "statusRear";
  c3_b_y.statusRear = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "statusRear", "statusRear", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "rateRear";
  c3_b_y.rateRear = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "rateRear", "rateRear", 0)), &c3_thisId);
  sf_mex_destroy(&c3_b_u);
  return c3_b_y;
}

static PRESCAN_V2X_FIXED_BSM_steering c3_nc_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_u,
   const emlrtMsgIdentifier *c3_parentId)
{
  PRESCAN_V2X_FIXED_BSM_steering c3_b_y;
  emlrtMsgIdentifier c3_thisId;
  static const char * c3_fieldNames[4] = { "angle", "confidence", "rate",
    "wheels" };

  c3_thisId.fParent = c3_parentId;
  c3_thisId.bParentIsCell = false;
  sf_mex_check_struct(c3_parentId, c3_b_u, 4, c3_fieldNames, 0U, NULL);
  c3_thisId.fIdentifier = "angle";
  c3_b_y.angle = c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_b_u, "angle", "angle", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "confidence";
  c3_b_y.confidence = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "confidence", "confidence", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "rate";
  c3_b_y.rate = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_b_u, "rate", "rate", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "wheels";
  c3_b_y.wheels = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "wheels", "wheels", 0)), &c3_thisId);
  sf_mex_destroy(&c3_b_u);
  return c3_b_y;
}

static PRESCAN_V2X_FIXED_BSM_accelSets c3_oc_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_u,
   const emlrtMsgIdentifier *c3_parentId)
{
  PRESCAN_V2X_FIXED_BSM_accelSets c3_b_y;
  emlrtMsgIdentifier c3_thisId;
  static const char * c3_fieldNames[5] = { "accel4way", "vertAccelThres",
    "yawRateCon", "hozAccelCon", "confidenceSet" };

  c3_thisId.fParent = c3_parentId;
  c3_thisId.bParentIsCell = false;
  sf_mex_check_struct(c3_parentId, c3_b_u, 5, c3_fieldNames, 0U, NULL);
  c3_thisId.fIdentifier = "accel4way";
  c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "accel4way", "accel4way", 0)), &c3_thisId, c3_b_y.accel4way);
  c3_thisId.fIdentifier = "vertAccelThres";
  c3_b_y.vertAccelThres = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "vertAccelThres", "vertAccelThres", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "yawRateCon";
  c3_b_y.yawRateCon = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "yawRateCon", "yawRateCon", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "hozAccelCon";
  c3_b_y.hozAccelCon = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "hozAccelCon", "hozAccelCon", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "confidenceSet";
  c3_b_y.confidenceSet = c3_pc_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "confidenceSet", "confidenceSet", 0)), &c3_thisId);
  sf_mex_destroy(&c3_b_u);
  return c3_b_y;
}

static PRESCAN_V2X_FIXED_BSM_confidenceSet c3_pc_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_u,
   const emlrtMsgIdentifier *c3_parentId)
{
  PRESCAN_V2X_FIXED_BSM_confidenceSet c3_b_y;
  emlrtMsgIdentifier c3_thisId;
  static const char * c3_fieldNames[6] = { "accelConfidence", "speedConfidence",
    "timeConfidence", "posConfidence", "steerConfidence", "throttleConfidence" };

  c3_thisId.fParent = c3_parentId;
  c3_thisId.bParentIsCell = false;
  sf_mex_check_struct(c3_parentId, c3_b_u, 6, c3_fieldNames, 0U, NULL);
  c3_thisId.fIdentifier = "accelConfidence";
  c3_b_y.accelConfidence = c3_qc_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "accelConfidence", "accelConfidence", 0)),
    &c3_thisId);
  c3_thisId.fIdentifier = "speedConfidence";
  c3_b_y.speedConfidence = c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "speedConfidence", "speedConfidence", 0)),
    &c3_thisId);
  c3_thisId.fIdentifier = "timeConfidence";
  c3_b_y.timeConfidence = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "timeConfidence", "timeConfidence", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "posConfidence";
  c3_b_y.posConfidence = c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "posConfidence", "posConfidence", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "steerConfidence";
  c3_b_y.steerConfidence = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "steerConfidence", "steerConfidence", 0)),
    &c3_thisId);
  c3_thisId.fIdentifier = "throttleConfidence";
  c3_b_y.throttleConfidence = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "throttleConfidence", "throttleConfidence", 0)),
    &c3_thisId);
  sf_mex_destroy(&c3_b_u);
  return c3_b_y;
}

static PRESCAN_V2X_FIXED_BSM_accelConfidence c3_qc_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_u,
   const emlrtMsgIdentifier *c3_parentId)
{
  PRESCAN_V2X_FIXED_BSM_accelConfidence c3_b_y;
  emlrtMsgIdentifier c3_thisId;
  static const char * c3_fieldNames[3] = { "yawRate", "acceleration",
    "steeringWheelAngle" };

  c3_thisId.fParent = c3_parentId;
  c3_thisId.bParentIsCell = false;
  sf_mex_check_struct(c3_parentId, c3_b_u, 3, c3_fieldNames, 0U, NULL);
  c3_thisId.fIdentifier = "yawRate";
  c3_b_y.yawRate = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "yawRate", "yawRate", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "acceleration";
  c3_b_y.acceleration = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "acceleration", "acceleration", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "steeringWheelAngle";
  c3_b_y.steeringWheelAngle = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "steeringWheelAngle", "steeringWheelAngle", 0)),
    &c3_thisId);
  sf_mex_destroy(&c3_b_u);
  return c3_b_y;
}

static PRESCAN_V2X_FIXED_BSM_object c3_rc_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_u,
   const emlrtMsgIdentifier *c3_parentId)
{
  PRESCAN_V2X_FIXED_BSM_object c3_b_y;
  emlrtMsgIdentifier c3_thisId;
  static const char * c3_fieldNames[3] = { "obDist", "obDirect", "dateTime" };

  c3_thisId.fParent = c3_parentId;
  c3_thisId.bParentIsCell = false;
  sf_mex_check_struct(c3_parentId, c3_b_u, 3, c3_fieldNames, 0U, NULL);
  c3_thisId.fIdentifier = "obDist";
  c3_b_y.obDist = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "obDist", "obDist", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "obDirect";
  c3_b_y.obDirect = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "obDirect", "obDirect", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "dateTime";
  c3_b_y.dateTime = c3_sc_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "dateTime", "dateTime", 0)), &c3_thisId);
  sf_mex_destroy(&c3_b_u);
  return c3_b_y;
}

static PRESCAN_V2X_FIXED_BSM_dateTime c3_sc_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_u,
   const emlrtMsgIdentifier *c3_parentId)
{
  PRESCAN_V2X_FIXED_BSM_dateTime c3_b_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fParent = c3_parentId;
  c3_thisId.bParentIsCell = false;
  sf_mex_check_struct(c3_parentId, c3_b_u, 6, c3_sv7, 0U, NULL);
  c3_thisId.fIdentifier = "year";
  c3_b_y.year = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_b_u, "year", "year", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "month";
  c3_b_y.month = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_b_u, "month", "month", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "day";
  c3_b_y.day = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_b_u, "day", "day", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "hour";
  c3_b_y.hour = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_b_u, "hour", "hour", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "minute";
  c3_b_y.minute = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "minute", "minute", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "second";
  c3_b_y.second = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "second", "second", 0)), &c3_thisId);
  sf_mex_destroy(&c3_b_u);
  return c3_b_y;
}

static PRESCAN_V2X_FIXED_BSM_fullPos c3_tc_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_u,
   const emlrtMsgIdentifier *c3_parentId)
{
  PRESCAN_V2X_FIXED_BSM_fullPos c3_b_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fParent = c3_parentId;
  c3_thisId.bParentIsCell = false;
  sf_mex_check_struct(c3_parentId, c3_b_u, 10, c3_sv6, 0U, NULL);
  c3_thisId.fIdentifier = "utcTime";
  c3_b_y.utcTime = c3_r_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "utcTime", "utcTime", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "longitude";
  c3_b_y.longitude = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "longitude", "longitude", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "latitude";
  c3_b_y.latitude = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "latitude", "latitude", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "elevation";
  c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "elevation", "elevation", 0)), &c3_thisId, c3_b_y.elevation);
  c3_thisId.fIdentifier = "heading";
  c3_b_y.heading = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "heading", "heading", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "speed";
  c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "speed", "speed", 0)), &c3_thisId, c3_b_y.speed);
  c3_thisId.fIdentifier = "posAccuracy";
  c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "posAccuracy", "posAccuracy", 0)), &c3_thisId, c3_b_y.posAccuracy);
  c3_thisId.fIdentifier = "timeConfidence";
  c3_b_y.timeConfidence = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "timeConfidence", "timeConfidence", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "posConfidence";
  c3_b_y.posConfidence = c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "posConfidence", "posConfidence", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "speedConfidence";
  c3_b_y.speedConfidence = c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "speedConfidence", "speedConfidence", 0)),
    &c3_thisId);
  sf_mex_destroy(&c3_b_u);
  return c3_b_y;
}

static PRESCAN_V2X_FIXED_BSM_vehicleData c3_uc_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_u,
   const emlrtMsgIdentifier *c3_parentId)
{
  PRESCAN_V2X_FIXED_BSM_vehicleData c3_b_y;
  emlrtMsgIdentifier c3_thisId;
  static const char * c3_fieldNames[5] = { "height", "bumpers", "mass",
    "trailerWeight", "type" };

  c3_thisId.fParent = c3_parentId;
  c3_thisId.bParentIsCell = false;
  sf_mex_check_struct(c3_parentId, c3_b_u, 5, c3_fieldNames, 0U, NULL);
  c3_thisId.fIdentifier = "height";
  c3_b_y.height = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "height", "height", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "bumpers";
  c3_b_y.bumpers = c3_vc_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "bumpers", "bumpers", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "mass";
  c3_b_y.mass = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_b_u, "mass", "mass", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "trailerWeight";
  c3_b_y.trailerWeight = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "trailerWeight", "trailerWeight", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "type";
  c3_b_y.type = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_b_u, "type", "type", 0)), &c3_thisId);
  sf_mex_destroy(&c3_b_u);
  return c3_b_y;
}

static PRESCAN_V2X_FIXED_BSM_bumpers c3_vc_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_u,
   const emlrtMsgIdentifier *c3_parentId)
{
  PRESCAN_V2X_FIXED_BSM_bumpers c3_b_y;
  emlrtMsgIdentifier c3_thisId;
  static const char * c3_fieldNames[2] = { "frnt", "rear" };

  c3_thisId.fParent = c3_parentId;
  c3_thisId.bParentIsCell = false;
  sf_mex_check_struct(c3_parentId, c3_b_u, 2, c3_fieldNames, 0U, NULL);
  c3_thisId.fIdentifier = "frnt";
  c3_b_y.frnt = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_b_u, "frnt", "frnt", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "rear";
  c3_b_y.rear = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_b_u, "rear", "rear", 0)), &c3_thisId);
  sf_mex_destroy(&c3_b_u);
  return c3_b_y;
}

static void c3_wc_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  PRESCAN_V2X_FIXED_BSM_vehicleIdent *c3_b_y)
{
  emlrtMsgIdentifier c3_thisId;
  static const char * c3_fieldNames[6] = { "name", "vin", "ownerCode", "id",
    "vehicleType", "vehicleClass" };

  c3_thisId.fParent = c3_parentId;
  c3_thisId.bParentIsCell = false;
  sf_mex_check_struct(c3_parentId, c3_b_u, 6, c3_fieldNames, 0U, NULL);
  c3_thisId.fIdentifier = "name";
  c3_xc_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "name", "name", 0)), &c3_thisId, c3_b_y->name);
  c3_thisId.fIdentifier = "vin";
  c3_yc_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u, "vin",
    "vin", 0)), &c3_thisId, c3_b_y->vin);
  c3_thisId.fIdentifier = "ownerCode";
  c3_ad_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "ownerCode", "ownerCode", 0)), &c3_thisId, c3_b_y->ownerCode);
  c3_thisId.fIdentifier = "id";
  c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u, "id",
    "id", 0)), &c3_thisId, c3_b_y->id);
  c3_thisId.fIdentifier = "vehicleType";
  c3_b_y->vehicleType = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "vehicleType", "vehicleType", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "vehicleClass";
  c3_b_y->vehicleClass = c3_bd_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "vehicleClass", "vehicleClass", 0)), &c3_thisId);
  sf_mex_destroy(&c3_b_u);
}

static void c3_xc_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[63])
{
  int8_T c3_iv44[63];
  int32_T c3_i214;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv44, 1, 2, 0U, 1, 0U, 1, 63);
  for (c3_i214 = 0; c3_i214 < 63; c3_i214++) {
    c3_b_y[c3_i214] = c3_iv44[c3_i214];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_yc_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[17])
{
  int8_T c3_iv45[17];
  int32_T c3_i215;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv45, 1, 2, 0U, 1, 0U, 1, 17);
  for (c3_i215 = 0; c3_i215 < 17; c3_i215++) {
    c3_b_y[c3_i215] = c3_iv45[c3_i215];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_ad_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  int8_T c3_b_y[32])
{
  int8_T c3_iv46[32];
  int32_T c3_i216;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_iv46, 1, 2, 0U, 1, 0U, 1, 32);
  for (c3_i216 = 0; c3_i216 < 32; c3_i216++) {
    c3_b_y[c3_i216] = c3_iv46[c3_i216];
  }

  sf_mex_destroy(&c3_b_u);
}

static PRESCAN_V2X_FIXED_BSM_vehicleClass c3_bd_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_u,
   const emlrtMsgIdentifier *c3_parentId)
{
  PRESCAN_V2X_FIXED_BSM_vehicleClass c3_b_y;
  emlrtMsgIdentifier c3_thisId;
  static const char * c3_fieldNames[3] = { "vGroup", "rGroup", "rEquip" };

  c3_thisId.fParent = c3_parentId;
  c3_thisId.bParentIsCell = false;
  sf_mex_check_struct(c3_parentId, c3_b_u, 3, c3_fieldNames, 0U, NULL);
  c3_thisId.fIdentifier = "vGroup";
  c3_b_y.vGroup = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "vGroup", "vGroup", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "rGroup";
  c3_b_y.rGroup = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "rGroup", "rGroup", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "rEquip";
  c3_b_y.rEquip = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "rEquip", "rEquip", 0)), &c3_thisId);
  sf_mex_destroy(&c3_b_u);
  return c3_b_y;
}

static void c3_cd_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  PRESCAN_V2X_FIXED_BSM_j1939data *c3_b_y)
{
  emlrtMsgIdentifier c3_thisId;
  static const char * c3_fieldNames[10] = { "tires", "axle", "trailerWeight",
    "cargoWeight", "steeringAxleTemperature", "driveAxleLocation",
    "driveAxleLiftAirPressure", "driveAxleTemperature", "driveAxleLubePressure",
    "steeringAxleLubePressure" };

  c3_thisId.fParent = c3_parentId;
  c3_thisId.bParentIsCell = false;
  sf_mex_check_struct(c3_parentId, c3_b_u, 10, c3_fieldNames, 0U, NULL);
  c3_thisId.fIdentifier = "tires";
  c3_dd_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "tires", "tires", 0)), &c3_thisId, c3_b_y->tires);
  c3_thisId.fIdentifier = "axle";
  c3_ed_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u,
    "axle", "axle", 0)), &c3_thisId, c3_b_y->axle);
  c3_thisId.fIdentifier = "trailerWeight";
  c3_b_y->trailerWeight = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "trailerWeight", "trailerWeight", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "cargoWeight";
  c3_b_y->cargoWeight = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "cargoWeight", "cargoWeight", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "steeringAxleTemperature";
  c3_b_y->steeringAxleTemperature = c3_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c3_b_u, "steeringAxleTemperature",
    "steeringAxleTemperature", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "driveAxleLocation";
  c3_b_y->driveAxleLocation = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "driveAxleLocation", "driveAxleLocation", 0)),
    &c3_thisId);
  c3_thisId.fIdentifier = "driveAxleLiftAirPressure";
  c3_b_y->driveAxleLiftAirPressure = c3_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c3_b_u, "driveAxleLiftAirPressure",
    "driveAxleLiftAirPressure", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "driveAxleTemperature";
  c3_b_y->driveAxleTemperature = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "driveAxleTemperature", "driveAxleTemperature", 0)),
    &c3_thisId);
  c3_thisId.fIdentifier = "driveAxleLubePressure";
  c3_b_y->driveAxleLubePressure = c3_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c3_b_u, "driveAxleLubePressure",
    "driveAxleLubePressure", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "steeringAxleLubePressure";
  c3_b_y->steeringAxleLubePressure = c3_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c3_b_u, "steeringAxleLubePressure",
    "steeringAxleLubePressure", 0)), &c3_thisId);
  sf_mex_destroy(&c3_b_u);
}

static void c3_dd_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  PRESCAN_V2X_FIXED_BSM_tires c3_b_y[16])
{
  uint32_T c3_uv1[1];
  emlrtMsgIdentifier c3_thisId;
  static const char * c3_fieldNames[7] = { "location", "pressure", "temp",
    "wheelSensorStatus", "wheelEndElectFault", "leakageRate", "detection" };

  int32_T c3_i217;
  c3_uv1[0] = 16U;
  c3_thisId.fParent = c3_parentId;
  c3_thisId.bParentIsCell = false;
  sf_mex_check_struct(c3_parentId, c3_b_u, 7, c3_fieldNames, 1U, c3_uv1);
  for (c3_i217 = 0; c3_i217 < 16; c3_i217++) {
    c3_thisId.fIdentifier = "location";
    c3_b_y[c3_i217].location = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c3_b_u, "location", "location", c3_i217)), &c3_thisId);
    c3_thisId.fIdentifier = "pressure";
    c3_b_y[c3_i217].pressure = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c3_b_u, "pressure", "pressure", c3_i217)), &c3_thisId);
    c3_thisId.fIdentifier = "temp";
    c3_b_y[c3_i217].temp = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c3_b_u, "temp", "temp", c3_i217)), &c3_thisId);
    c3_thisId.fIdentifier = "wheelSensorStatus";
    c3_b_y[c3_i217].wheelSensorStatus = c3_g_emlrt_marshallIn(chartInstance,
      sf_mex_dup(sf_mex_getfield(c3_b_u, "wheelSensorStatus",
      "wheelSensorStatus", c3_i217)), &c3_thisId);
    c3_thisId.fIdentifier = "wheelEndElectFault";
    c3_b_y[c3_i217].wheelEndElectFault = c3_g_emlrt_marshallIn(chartInstance,
      sf_mex_dup(sf_mex_getfield(c3_b_u, "wheelEndElectFault",
      "wheelEndElectFault", c3_i217)), &c3_thisId);
    c3_thisId.fIdentifier = "leakageRate";
    c3_b_y[c3_i217].leakageRate = c3_g_emlrt_marshallIn(chartInstance,
      sf_mex_dup(sf_mex_getfield(c3_b_u, "leakageRate", "leakageRate", c3_i217)),
      &c3_thisId);
    c3_thisId.fIdentifier = "detection";
    c3_b_y[c3_i217].detection = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c3_b_u, "detection", "detection", c3_i217)), &c3_thisId);
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_ed_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  PRESCAN_V2X_FIXED_BSM_axle c3_b_y[16])
{
  uint32_T c3_uv2[1];
  emlrtMsgIdentifier c3_thisId;
  static const char * c3_fieldNames[2] = { "location", "weight" };

  int32_T c3_i218;
  c3_uv2[0] = 16U;
  c3_thisId.fParent = c3_parentId;
  c3_thisId.bParentIsCell = false;
  sf_mex_check_struct(c3_parentId, c3_b_u, 2, c3_fieldNames, 1U, c3_uv2);
  for (c3_i218 = 0; c3_i218 < 16; c3_i218++) {
    c3_thisId.fIdentifier = "location";
    c3_b_y[c3_i218].location = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c3_b_u, "location", "location", c3_i218)), &c3_thisId);
    c3_thisId.fIdentifier = "weight";
    c3_b_y[c3_i218].weight = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c3_b_u, "weight", "weight", c3_i218)), &c3_thisId);
  }

  sf_mex_destroy(&c3_b_u);
}

static PRESCAN_V2X_FIXED_BSM_weatherReport c3_fd_emlrt_marshallIn
  (SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c3_b_u,
   const emlrtMsgIdentifier *c3_parentId)
{
  PRESCAN_V2X_FIXED_BSM_weatherReport c3_b_y;
  emlrtMsgIdentifier c3_thisId;
  static const char * c3_fieldNames[5] = { "isRaining", "rainRate",
    "precipSituation", "solarRadiation", "friction" };

  c3_thisId.fParent = c3_parentId;
  c3_thisId.bParentIsCell = false;
  sf_mex_check_struct(c3_parentId, c3_b_u, 5, c3_fieldNames, 0U, NULL);
  c3_thisId.fIdentifier = "isRaining";
  c3_b_y.isRaining = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "isRaining", "isRaining", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "rainRate";
  c3_b_y.rainRate = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "rainRate", "rainRate", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "precipSituation";
  c3_b_y.precipSituation = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "precipSituation", "precipSituation", 0)),
    &c3_thisId);
  c3_thisId.fIdentifier = "solarRadiation";
  c3_b_y.solarRadiation = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "solarRadiation", "solarRadiation", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "friction";
  c3_b_y.friction = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "friction", "friction", 0)), &c3_thisId);
  sf_mex_destroy(&c3_b_u);
  return c3_b_y;
}

static void c3_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_y;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  PRESCAN_V2X_FIXED_BSM_DATA c3_c_y;
  SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc3_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c3_b_y = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_y), &c3_thisId, &c3_c_y);
  sf_mex_destroy(&c3_b_y);
  *(PRESCAN_V2X_FIXED_BSM_DATA *)c3_outData = c3_c_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static void c3_gd_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId,
  PRESCAN_V2X_FIXED_BSM_MESSAGE *c3_b_y)
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fParent = c3_parentId;
  c3_thisId.bParentIsCell = false;
  sf_mex_check_struct(c3_parentId, c3_b_u, 2, c3_sv4, 0U, NULL);
  c3_thisId.fIdentifier = "HEADER";
  c3_b_y->HEADER = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_b_u, "HEADER", "HEADER", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "DATA";
  c3_n_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_b_u, "DATA",
    "DATA", 0)), &c3_thisId, &c3_b_y->DATA);
  sf_mex_destroy(&c3_b_u);
}

static void c3_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_y;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  PRESCAN_V2X_FIXED_BSM_MESSAGE c3_c_y;
  SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc3_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c3_b_y = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_gd_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_y), &c3_thisId, &c3_c_y);
  sf_mex_destroy(&c3_b_y);
  *(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_outData = c3_c_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_Jan22_DLforACC_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  const char * c3_data[4] = {
    "789cc592cf4ac34010c627a5163db4f420fa0e1e0ce420e2c99a566b69a5d0560a2231a65312cc6ecaee56ab271fc48347dfc8d731fd9bed922505b10e2c938f"
    "2fcc6f6776c0b86e1900508a4f2e3e9f059845719ea0bcc839580fd5373479193b909fd5282afec7227b11153811731106146fc6e411592ca84b705566109180",
    "ba54745f47080c79143ee360e60c8310bb01c16624897a100b7229592b31b5a6dfb68fde53674c80f93cb96e280b90e6f3a0e93f9f311f35d4f9a8ffa5f10ce9"
    "bf420a4ff6b3de630f7665faf99237d2d44beb2f8d57d2f0ca8a7f6bf59d8b4ecb895f4a4c9f39abdf4df9054527fcb9c3051b7b22e17dfd9257cfe877e9dfd5",
    "eeed33b3c79171935b61e433979b6d861dcfa54e6d324216ef2415dc6cb8d4b29c6a7318b18a6d9beb733a26dbdb8bf7a3fdc3efca76f770db7bff7fbc89a6de"
    "a67b77a0e19515bf2a1adcb74eb1f6d6ecb3f6498f0e5f887d95dca39dc1c9ba0768f45fd7ff01fee45fcb",
    "" };

  c3_nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(c3_data, 1720U, &c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static const mxArray *c3_i_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  int32_T c3_b_u;
  const mxArray *c3_b_y = NULL;
  SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc3_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_b_u = *(int32_T *)c3_inData;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_b_y, false);
  return c3_mxArrayOutData;
}

static void c3_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_b_y;
  SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc3_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_y = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_b_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_u_bus_io(void *chartInstanceVoid, void *c3_pData)
{
  const mxArray *c3_mxVal = NULL;
  PRESCAN_V2X_FIXED_BSM_MESSAGE c3_tmp;
  int32_T c3_i219;
  int32_T c3_i220;
  int32_T c3_i221;
  int32_T c3_i222;
  int32_T c3_i223;
  int32_T c3_i224;
  int32_T c3_i225;
  int32_T c3_i226;
  int32_T c3_i227;
  int32_T c3_i228;
  int32_T c3_i229;
  int32_T c3_i230;
  int32_T c3_i231;
  int32_T c3_i232;
  int32_T c3_i233;
  int32_T c3_i234;
  int32_T c3_i235;
  int32_T c3_i236;
  int32_T c3_i237;
  int32_T c3_i238;
  int32_T c3_i239;
  int32_T c3_i240;
  int32_T c3_i241;
  int32_T c3_i242;
  int32_T c3_i243;
  int32_T c3_i244;
  int32_T c3_i245;
  int32_T c3_i246;
  int32_T c3_i247;
  int32_T c3_i248;
  int32_T c3_i249;
  int32_T c3_i250;
  int32_T c3_i251;
  int32_T c3_i252;
  int32_T c3_i253;
  int32_T c3_i254;
  int32_T c3_i255;
  int32_T c3_i256;
  int32_T c3_i257;
  int32_T c3_i258;
  int32_T c3_i259;
  int32_T c3_i260;
  int32_T c3_i261;
  int32_T c3_i262;
  int32_T c3_i263;
  int32_T c3_i264;
  int32_T c3_i265;
  int32_T c3_i266;
  int32_T c3_i267;
  int32_T c3_i268;
  int32_T c3_i269;
  int32_T c3_i270;
  int32_T c3_i271;
  int32_T c3_i272;
  int32_T c3_i273;
  int32_T c3_i274;
  int32_T c3_i275;
  int32_T c3_i276;
  int32_T c3_i277;
  int32_T c3_i278;
  int32_T c3_i279;
  int32_T c3_i280;
  int32_T c3_i281;
  int32_T c3_i282;
  int32_T c3_i283;
  int32_T c3_i284;
  SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc3_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c3_mxVal = NULL;
  c3_tmp.HEADER.valid = *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[0])[0];
  c3_tmp.DATA.msgID = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[0];
  c3_tmp.DATA.msgCnt = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[4];
  for (c3_i219 = 0; c3_i219 < 4; c3_i219++) {
    c3_tmp.DATA.id[c3_i219] = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[8])[c3_i219];
  }

  c3_tmp.DATA.secMark = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[12];
  c3_tmp.DATA.latitude = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[16];
  c3_tmp.DATA.longitude = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[20];
  for (c3_i220 = 0; c3_i220 < 2; c3_i220++) {
    c3_tmp.DATA.elev[c3_i220] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
      c3_pData)[8])[24])[c3_i220];
  }

  for (c3_i221 = 0; c3_i221 < 4; c3_i221++) {
    c3_tmp.DATA.accuracy[c3_i221] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
      c3_pData)[8])[26])[c3_i221];
  }

  for (c3_i222 = 0; c3_i222 < 2; c3_i222++) {
    c3_tmp.DATA.speed[c3_i222] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
      c3_pData)[8])[30])[c3_i222];
  }

  c3_tmp.DATA.heading = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[32];
  c3_tmp.DATA.angle = *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[36];
  for (c3_i223 = 0; c3_i223 < 7; c3_i223++) {
    c3_tmp.DATA.accelSet[c3_i223] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
      c3_pData)[8])[37])[c3_i223];
  }

  for (c3_i224 = 0; c3_i224 < 2; c3_i224++) {
    c3_tmp.DATA.brakes[c3_i224] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
      c3_pData)[8])[44])[c3_i224];
  }

  c3_tmp.DATA.size.width = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_size *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[48])[0];
  c3_tmp.DATA.size.length = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_size *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[48])[4];
  c3_tmp.DATA.safetyExt.events = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[0];
  c3_tmp.DATA.safetyExt.pathHistory.initialPosition.utcTime.year = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[8])[0])[0])[0];
  c3_tmp.DATA.safetyExt.pathHistory.initialPosition.utcTime.month = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[8])[0])[0])[4];
  c3_tmp.DATA.safetyExt.pathHistory.initialPosition.utcTime.day = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[8])[0])[0])[8];
  c3_tmp.DATA.safetyExt.pathHistory.initialPosition.utcTime.hour = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[8])[0])[0])[12];
  c3_tmp.DATA.safetyExt.pathHistory.initialPosition.utcTime.minute = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[8])[0])[0])[16];
  c3_tmp.DATA.safetyExt.pathHistory.initialPosition.utcTime.second = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[8])[0])[0])[20];
  c3_tmp.DATA.safetyExt.pathHistory.initialPosition.longitude = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[8])[0])[24];
  c3_tmp.DATA.safetyExt.pathHistory.initialPosition.latitude = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[8])[0])[28];
  for (c3_i225 = 0; c3_i225 < 2; c3_i225++) {
    c3_tmp.DATA.safetyExt.pathHistory.initialPosition.elevation[c3_i225] =
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[8])[0])[32])
      [c3_i225];
  }

  c3_tmp.DATA.safetyExt.pathHistory.initialPosition.heading = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[8])[0])[36];
  for (c3_i226 = 0; c3_i226 < 2; c3_i226++) {
    c3_tmp.DATA.safetyExt.pathHistory.initialPosition.speed[c3_i226] = ((int8_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[8])[0])
      [40])[c3_i226];
  }

  for (c3_i227 = 0; c3_i227 < 4; c3_i227++) {
    c3_tmp.DATA.safetyExt.pathHistory.initialPosition.posAccuracy[c3_i227] =
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[8])[0])[42])
      [c3_i227];
  }

  c3_tmp.DATA.safetyExt.pathHistory.initialPosition.timeConfidence = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[8])[0])[48];
  c3_tmp.DATA.safetyExt.pathHistory.initialPosition.posConfidence = *(int8_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[8])[0])[52];
  c3_tmp.DATA.safetyExt.pathHistory.initialPosition.speedConfidence = *(int8_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[8])[0])[53];
  c3_tmp.DATA.safetyExt.pathHistory.currGPSstatus = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[8])[56];
  c3_tmp.DATA.safetyExt.pathHistory.itemCnt = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[8])[60];
  for (c3_i228 = 0; c3_i228 < 23; c3_i228++) {
    c3_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c3_i228]
      .latOffset = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[8])[64])
      [0])[32 * (int32_T)c3_i228])[0];
    c3_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c3_i228]
      .longOffset = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[8])[64])
      [0])[32 * (int32_T)c3_i228])[4];
    c3_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c3_i228]
      .elevationOffset = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[8])[64])
      [0])[32 * (int32_T)c3_i228])[8];
    c3_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c3_i228]
      .timeOffset = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[8])[64])
      [0])[32 * (int32_T)c3_i228])[12];
    for (c3_i231 = 0; c3_i231 < 4; c3_i231++) {
      c3_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c3_i228]
        .posAccuracy[c3_i231] = ((int8_T *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE
        *)c3_pData)[8])[56])[8])[64])[0])[32 * (int32_T)c3_i228])[16])[c3_i231];
    }

    c3_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c3_i228]
      .heading = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[8])[64])
      [0])[32 * (int32_T)c3_i228])[20];
    for (c3_i233 = 0; c3_i233 < 2; c3_i233++) {
      c3_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c3_i228]
        .speed[c3_i233] = ((int8_T *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE
        *)c3_pData)[8])[56])[8])[64])[0])[32 * (int32_T)c3_i228])[24])[c3_i233];
    }
  }

  for (c3_i229 = 0; c3_i229 < 345; c3_i229++) {
    c3_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_02[c3_i229]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
              (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[8])[64])[736])
      [c3_i229];
  }

  for (c3_i230 = 0; c3_i230 < 276; c3_i230++) {
    c3_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_03[c3_i230]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
              (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[8])[64])[1081])
      [c3_i230];
  }

  for (c3_i232 = 0; c3_i232 < 184; c3_i232++) {
    c3_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_04[c3_i232]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
              (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[8])[64])[1357])
      [c3_i232];
  }

  for (c3_i234 = 0; c3_i234 < 230; c3_i234++) {
    c3_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_05[c3_i234]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
              (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[8])[64])[1541])
      [c3_i234];
  }

  for (c3_i235 = 0; c3_i235 < 138; c3_i235++) {
    c3_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_06[c3_i235]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
              (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[8])[64])[1771])
      [c3_i235];
  }

  for (c3_i236 = 0; c3_i236 < 242; c3_i236++) {
    c3_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_07[c3_i236]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
              (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[8])[64])[1909])
      [c3_i236];
  }

  for (c3_i237 = 0; c3_i237 < 161; c3_i237++) {
    c3_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_08[c3_i237]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
              (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[8])[64])[2151])
      [c3_i237];
  }

  for (c3_i238 = 0; c3_i238 < 196; c3_i238++) {
    c3_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_09[c3_i238]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
              (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[8])[64])[2312])
      [c3_i238];
  }

  for (c3_i239 = 0; c3_i239 < 104; c3_i239++) {
    c3_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_10[c3_i239]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
              (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[8])[64])[2508])
      [c3_i239];
  }

  c3_tmp.DATA.safetyExt.pathPrediction.radiusOfCurve = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathPrediction *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2688])[0];
  c3_tmp.DATA.safetyExt.pathPrediction.confidence = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathPrediction *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2688])[4];
  c3_tmp.DATA.safetyExt.theRTCM.anchorPoint.utcTime.year = *(int32_T *)&((char_T
    *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])[0])[0])
    [0];
  c3_tmp.DATA.safetyExt.theRTCM.anchorPoint.utcTime.month = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])[0])[0])[4];
  c3_tmp.DATA.safetyExt.theRTCM.anchorPoint.utcTime.day = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])[0])[0])
    [8];
  c3_tmp.DATA.safetyExt.theRTCM.anchorPoint.utcTime.hour = *(int32_T *)&((char_T
    *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])[0])[0])
    [12];
  c3_tmp.DATA.safetyExt.theRTCM.anchorPoint.utcTime.minute = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])[0])[0])[16];
  c3_tmp.DATA.safetyExt.theRTCM.anchorPoint.utcTime.second = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])[0])[0])[20];
  c3_tmp.DATA.safetyExt.theRTCM.anchorPoint.longitude = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])[0])
    [24];
  c3_tmp.DATA.safetyExt.theRTCM.anchorPoint.latitude = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])[0])
    [28];
  for (c3_i240 = 0; c3_i240 < 2; c3_i240++) {
    c3_tmp.DATA.safetyExt.theRTCM.anchorPoint.elevation[c3_i240] = ((int8_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])[0])
      [32])[c3_i240];
  }

  c3_tmp.DATA.safetyExt.theRTCM.anchorPoint.heading = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])[0])
    [36];
  for (c3_i241 = 0; c3_i241 < 2; c3_i241++) {
    c3_tmp.DATA.safetyExt.theRTCM.anchorPoint.speed[c3_i241] = ((int8_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])[0])
      [40])[c3_i241];
  }

  for (c3_i242 = 0; c3_i242 < 4; c3_i242++) {
    c3_tmp.DATA.safetyExt.theRTCM.anchorPoint.posAccuracy[c3_i242] = ((int8_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])[0])
      [42])[c3_i242];
  }

  c3_tmp.DATA.safetyExt.theRTCM.anchorPoint.timeConfidence = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])[0])[48];
  c3_tmp.DATA.safetyExt.theRTCM.anchorPoint.posConfidence = *(int8_T *)&((char_T
    *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])[0])
    [52];
  c3_tmp.DATA.safetyExt.theRTCM.anchorPoint.speedConfidence = *(int8_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])[0])[53];
  for (c3_i243 = 0; c3_i243 < 5; c3_i243++) {
    c3_tmp.DATA.safetyExt.theRTCM.rtcmHeader[c3_i243] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])
      [56])[c3_i243];
  }

  for (c3_i244 = 0; c3_i244 < 124; c3_i244++) {
    c3_tmp.DATA.safetyExt.theRTCM.msg1001[c3_i244] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])
      [61])[c3_i244];
  }

  for (c3_i245 = 0; c3_i245 < 156; c3_i245++) {
    c3_tmp.DATA.safetyExt.theRTCM.msg1002[c3_i245] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])
      [185])[c3_i245];
  }

  for (c3_i246 = 0; c3_i246 < 210; c3_i246++) {
    c3_tmp.DATA.safetyExt.theRTCM.msg1003[c3_i246] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])
      [341])[c3_i246];
  }

  for (c3_i247 = 0; c3_i247 < 258; c3_i247++) {
    c3_tmp.DATA.safetyExt.theRTCM.msg1004[c3_i247] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])
      [551])[c3_i247];
  }

  for (c3_i248 = 0; c3_i248 < 19; c3_i248++) {
    c3_tmp.DATA.safetyExt.theRTCM.msg1005[c3_i248] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])
      [809])[c3_i248];
  }

  for (c3_i249 = 0; c3_i249 < 21; c3_i249++) {
    c3_tmp.DATA.safetyExt.theRTCM.msg1006[c3_i249] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])
      [828])[c3_i249];
  }

  for (c3_i250 = 0; c3_i250 < 36; c3_i250++) {
    c3_tmp.DATA.safetyExt.theRTCM.msg1007[c3_i250] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])
      [849])[c3_i250];
  }

  for (c3_i251 = 0; c3_i251 < 68; c3_i251++) {
    c3_tmp.DATA.safetyExt.theRTCM.msg1008[c3_i251] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])
      [885])[c3_i251];
  }

  for (c3_i252 = 0; c3_i252 < 136; c3_i252++) {
    c3_tmp.DATA.safetyExt.theRTCM.msg1009[c3_i252] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])
      [953])[c3_i252];
  }

  for (c3_i253 = 0; c3_i253 < 166; c3_i253++) {
    c3_tmp.DATA.safetyExt.theRTCM.msg1010[c3_i253] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])
      [1089])[c3_i253];
  }

  for (c3_i254 = 0; c3_i254 < 222; c3_i254++) {
    c3_tmp.DATA.safetyExt.theRTCM.msg1011[c3_i254] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])
      [1255])[c3_i254];
  }

  for (c3_i255 = 0; c3_i255 < 268; c3_i255++) {
    c3_tmp.DATA.safetyExt.theRTCM.msg1012[c3_i255] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])
      [1477])[c3_i255];
  }

  for (c3_i256 = 0; c3_i256 < 27; c3_i256++) {
    c3_tmp.DATA.safetyExt.theRTCM.msg1013[c3_i256] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])
      [1745])[c3_i256];
  }

  for (c3_i257 = 0; c3_i257 < 15; c3_i257++) {
    c3_tmp.DATA.safetyExt.theRTCM.msg1014[c3_i257] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])
      [1772])[c3_i257];
  }

  for (c3_i258 = 0; c3_i258 < 69; c3_i258++) {
    c3_tmp.DATA.safetyExt.theRTCM.msg1015[c3_i258] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])
      [1787])[c3_i258];
  }

  for (c3_i259 = 0; c3_i259 < 81; c3_i259++) {
    c3_tmp.DATA.safetyExt.theRTCM.msg1016[c3_i259] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])
      [1856])[c3_i259];
  }

  for (c3_i260 = 0; c3_i260 < 115; c3_i260++) {
    c3_tmp.DATA.safetyExt.theRTCM.msg1017[c3_i260] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])
      [1937])[c3_i260];
  }

  for (c3_i261 = 0; c3_i261 < 62; c3_i261++) {
    c3_tmp.DATA.safetyExt.theRTCM.msg1019[c3_i261] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])
      [2052])[c3_i261];
  }

  for (c3_i262 = 0; c3_i262 < 45; c3_i262++) {
    c3_tmp.DATA.safetyExt.theRTCM.msg1020[c3_i262] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])
      [2114])[c3_i262];
  }

  for (c3_i263 = 0; c3_i263 < 62; c3_i263++) {
    c3_tmp.DATA.safetyExt.theRTCM.msg1021[c3_i263] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])
      [2159])[c3_i263];
  }

  for (c3_i264 = 0; c3_i264 < 75; c3_i264++) {
    c3_tmp.DATA.safetyExt.theRTCM.msg1022[c3_i264] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])
      [2221])[c3_i264];
  }

  for (c3_i265 = 0; c3_i265 < 73; c3_i265++) {
    c3_tmp.DATA.safetyExt.theRTCM.msg1023[c3_i265] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])
      [2296])[c3_i265];
  }

  for (c3_i266 = 0; c3_i266 < 74; c3_i266++) {
    c3_tmp.DATA.safetyExt.theRTCM.msg1024[c3_i266] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])
      [2369])[c3_i266];
  }

  for (c3_i267 = 0; c3_i267 < 25; c3_i267++) {
    c3_tmp.DATA.safetyExt.theRTCM.msg1025[c3_i267] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])
      [2443])[c3_i267];
  }

  for (c3_i268 = 0; c3_i268 < 30; c3_i268++) {
    c3_tmp.DATA.safetyExt.theRTCM.msg1026[c3_i268] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])
      [2468])[c3_i268];
  }

  for (c3_i269 = 0; c3_i269 < 33; c3_i269++) {
    c3_tmp.DATA.safetyExt.theRTCM.msg1027[c3_i269] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])
      [2498])[c3_i269];
  }

  for (c3_i270 = 0; c3_i270 < 69; c3_i270++) {
    c3_tmp.DATA.safetyExt.theRTCM.msg1029[c3_i270] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])
      [2531])[c3_i270];
  }

  for (c3_i271 = 0; c3_i271 < 105; c3_i271++) {
    c3_tmp.DATA.safetyExt.theRTCM.msg1030[c3_i271] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])
      [2600])[c3_i271];
  }

  for (c3_i272 = 0; c3_i272 < 107; c3_i272++) {
    c3_tmp.DATA.safetyExt.theRTCM.msg1031[c3_i272] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])
      [2705])[c3_i272];
  }

  for (c3_i273 = 0; c3_i273 < 20; c3_i273++) {
    c3_tmp.DATA.safetyExt.theRTCM.msg1032[c3_i273] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[56])[2696])
      [2812])[c3_i273];
  }

  c3_tmp.DATA.status.lights = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[0];
  c3_tmp.DATA.status.lightBar = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[4];
  c3_tmp.DATA.status.wipers.statusFront = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[8])[0];
  c3_tmp.DATA.status.wipers.rateFront = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[8])[4];
  c3_tmp.DATA.status.wipers.statusRear = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[8])[8];
  c3_tmp.DATA.status.wipers.rateRear = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[8])[12];
  for (c3_i274 = 0; c3_i274 < 2; c3_i274++) {
    c3_tmp.DATA.status.brakeStatus[c3_i274] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[24])
      [c3_i274];
  }

  c3_tmp.DATA.status.brakePressure = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[28];
  c3_tmp.DATA.status.roadFriction = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[32];
  c3_tmp.DATA.status.sunData = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[36];
  c3_tmp.DATA.status.rainData = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[40];
  c3_tmp.DATA.status.airTemp = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[44];
  c3_tmp.DATA.status.airPres = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[48];
  c3_tmp.DATA.status.steering.angle = *(int8_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[56])[0];
  c3_tmp.DATA.status.steering.confidence = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[56])[4];
  c3_tmp.DATA.status.steering.rate = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[56])[8];
  c3_tmp.DATA.status.steering.wheels = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[56])[12];
  for (c3_i275 = 0; c3_i275 < 7; c3_i275++) {
    c3_tmp.DATA.status.accelSets.accel4way[c3_i275] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[72])[0])
      [c3_i275];
  }

  c3_tmp.DATA.status.accelSets.vertAccelThres = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[72])[8];
  c3_tmp.DATA.status.accelSets.yawRateCon = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[72])[12];
  c3_tmp.DATA.status.accelSets.hozAccelCon = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[72])[16];
  c3_tmp.DATA.status.accelSets.confidenceSet.accelConfidence.yawRate = *(int32_T
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelConfidence *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[72])[24])[0])
    [0];
  c3_tmp.DATA.status.accelSets.confidenceSet.accelConfidence.acceleration =
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelConfidence *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[72])[24])[0])[4];
  c3_tmp.DATA.status.accelSets.confidenceSet.accelConfidence.steeringWheelAngle =
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelConfidence *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[72])[24])[0])[8];
  c3_tmp.DATA.status.accelSets.confidenceSet.speedConfidence = *(int8_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
         &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[72])
      [24])[16];
  c3_tmp.DATA.status.accelSets.confidenceSet.timeConfidence = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
         &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[72])
      [24])[20];
  c3_tmp.DATA.status.accelSets.confidenceSet.posConfidence = *(int8_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
         &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[72])
      [24])[24];
  c3_tmp.DATA.status.accelSets.confidenceSet.steerConfidence = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
         &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[72])
      [24])[28];
  c3_tmp.DATA.status.accelSets.confidenceSet.throttleConfidence = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
         &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[72])
      [24])[32];
  c3_tmp.DATA.status.object.obDist = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[136])[0];
  c3_tmp.DATA.status.object.obDirect = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[136])[4];
  c3_tmp.DATA.status.object.dateTime.year = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    c3_pData)[8])[5584])[136])[8])[0];
  c3_tmp.DATA.status.object.dateTime.month = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    c3_pData)[8])[5584])[136])[8])[4];
  c3_tmp.DATA.status.object.dateTime.day = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    c3_pData)[8])[5584])[136])[8])[8];
  c3_tmp.DATA.status.object.dateTime.hour = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    c3_pData)[8])[5584])[136])[8])[12];
  c3_tmp.DATA.status.object.dateTime.minute = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    c3_pData)[8])[5584])[136])[8])[16];
  c3_tmp.DATA.status.object.dateTime.second = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    c3_pData)[8])[5584])[136])[8])[20];
  c3_tmp.DATA.status.fullPos.utcTime.year = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    c3_pData)[8])[5584])[168])[0])[0];
  c3_tmp.DATA.status.fullPos.utcTime.month = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    c3_pData)[8])[5584])[168])[0])[4];
  c3_tmp.DATA.status.fullPos.utcTime.day = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    c3_pData)[8])[5584])[168])[0])[8];
  c3_tmp.DATA.status.fullPos.utcTime.hour = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    c3_pData)[8])[5584])[168])[0])[12];
  c3_tmp.DATA.status.fullPos.utcTime.minute = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    c3_pData)[8])[5584])[168])[0])[16];
  c3_tmp.DATA.status.fullPos.utcTime.second = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    c3_pData)[8])[5584])[168])[0])[20];
  c3_tmp.DATA.status.fullPos.longitude = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[168])[24];
  c3_tmp.DATA.status.fullPos.latitude = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[168])[28];
  for (c3_i276 = 0; c3_i276 < 2; c3_i276++) {
    c3_tmp.DATA.status.fullPos.elevation[c3_i276] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[168])[32])[c3_i276];
  }

  c3_tmp.DATA.status.fullPos.heading = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[168])[36];
  for (c3_i277 = 0; c3_i277 < 2; c3_i277++) {
    c3_tmp.DATA.status.fullPos.speed[c3_i277] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[168])[40])[c3_i277];
  }

  for (c3_i278 = 0; c3_i278 < 4; c3_i278++) {
    c3_tmp.DATA.status.fullPos.posAccuracy[c3_i278] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[168])[42])[c3_i278];
  }

  c3_tmp.DATA.status.fullPos.timeConfidence = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[168])[48];
  c3_tmp.DATA.status.fullPos.posConfidence = *(int8_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[168])[52];
  c3_tmp.DATA.status.fullPos.speedConfidence = *(int8_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[168])[53];
  c3_tmp.DATA.status.throttlePos = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[224];
  c3_tmp.DATA.status.speedHeadC = *(int8_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[228];
  c3_tmp.DATA.status.speedC = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[232];
  c3_tmp.DATA.status.vehicleData.height = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[240])[0];
  c3_tmp.DATA.status.vehicleData.bumpers.frnt = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_bumpers *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[240])[8])
    [0];
  c3_tmp.DATA.status.vehicleData.bumpers.rear = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_bumpers *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[240])[8])
    [4];
  c3_tmp.DATA.status.vehicleData.mass = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[240])[16];
  c3_tmp.DATA.status.vehicleData.trailerWeight = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[240])[20];
  c3_tmp.DATA.status.vehicleData.type = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[240])[24];
  for (c3_i279 = 0; c3_i279 < 63; c3_i279++) {
    c3_tmp.DATA.status.vehicleIdent.name[c3_i279] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[272])[0])
      [c3_i279];
  }

  for (c3_i280 = 0; c3_i280 < 17; c3_i280++) {
    c3_tmp.DATA.status.vehicleIdent.vin[c3_i280] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[272])[63])
      [c3_i280];
  }

  for (c3_i281 = 0; c3_i281 < 32; c3_i281++) {
    c3_tmp.DATA.status.vehicleIdent.ownerCode[c3_i281] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[272])[80])
      [c3_i281];
  }

  for (c3_i282 = 0; c3_i282 < 4; c3_i282++) {
    c3_tmp.DATA.status.vehicleIdent.id[c3_i282] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[272])
      [112])[c3_i282];
  }

  c3_tmp.DATA.status.vehicleIdent.vehicleType = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[272])[116];
  c3_tmp.DATA.status.vehicleIdent.vehicleClass.vGroup = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleClass *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[272])[120])
    [0];
  c3_tmp.DATA.status.vehicleIdent.vehicleClass.rGroup = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleClass *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[272])[120])
    [4];
  c3_tmp.DATA.status.vehicleIdent.vehicleClass.rEquip = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleClass *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[272])[120])
    [8];
  for (c3_i283 = 0; c3_i283 < 16; c3_i283++) {
    c3_tmp.DATA.status.j1939data.tires[c3_i283].location = *(int32_T *)&((char_T
      *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[408])[0])
      [32 * (int32_T)c3_i283])[0];
    c3_tmp.DATA.status.j1939data.tires[c3_i283].pressure = *(int32_T *)&((char_T
      *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[408])[0])
      [32 * (int32_T)c3_i283])[4];
    c3_tmp.DATA.status.j1939data.tires[c3_i283].temp = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[408])[0])
      [32 * (int32_T)c3_i283])[8];
    c3_tmp.DATA.status.j1939data.tires[c3_i283].wheelSensorStatus = *(int32_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[408])[0])[32 *
        (int32_T)c3_i283])[12];
    c3_tmp.DATA.status.j1939data.tires[c3_i283].wheelEndElectFault = *(int32_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[408])[0])[32 *
        (int32_T)c3_i283])[16];
    c3_tmp.DATA.status.j1939data.tires[c3_i283].leakageRate = *(int32_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[408])[0])[32 *
        (int32_T)c3_i283])[20];
    c3_tmp.DATA.status.j1939data.tires[c3_i283].detection = *(int32_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[408])[0])[32 *
        (int32_T)c3_i283])[24];
  }

  for (c3_i284 = 0; c3_i284 < 16; c3_i284++) {
    c3_tmp.DATA.status.j1939data.axle[c3_i284].location = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_axle *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_axle *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[408])
      [512])[8 * (int32_T)c3_i284])[0];
    c3_tmp.DATA.status.j1939data.axle[c3_i284].weight = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_axle *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_axle *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[408])
      [512])[8 * (int32_T)c3_i284])[4];
  }

  c3_tmp.DATA.status.j1939data.trailerWeight = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[408])[640];
  c3_tmp.DATA.status.j1939data.cargoWeight = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[408])[644];
  c3_tmp.DATA.status.j1939data.steeringAxleTemperature = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[408])[648];
  c3_tmp.DATA.status.j1939data.driveAxleLocation = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[408])[652];
  c3_tmp.DATA.status.j1939data.driveAxleLiftAirPressure = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[408])[656];
  c3_tmp.DATA.status.j1939data.driveAxleTemperature = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[408])[660];
  c3_tmp.DATA.status.j1939data.driveAxleLubePressure = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[408])[664];
  c3_tmp.DATA.status.j1939data.steeringAxleLubePressure = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[408])[668];
  c3_tmp.DATA.status.weatherReport.isRaining = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[1080])[0];
  c3_tmp.DATA.status.weatherReport.rainRate = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[1080])[4];
  c3_tmp.DATA.status.weatherReport.precipSituation = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[1080])[8];
  c3_tmp.DATA.status.weatherReport.solarRadiation = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[1080])[12];
  c3_tmp.DATA.status.weatherReport.friction = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[1080])[16];
  c3_tmp.DATA.status.gpsStatus = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c3_pData)[8])[5584])[1104];
  sf_mex_assign(&c3_mxVal, c3_b_sf_marshallOut(chartInstance, &c3_tmp), false);
  return c3_mxVal;
}

static const mxArray *c3_y_bus_io(void *chartInstanceVoid, void *c3_pData)
{
  const mxArray *c3_mxVal = NULL;
  c3_PRESCAN_V2X_USER_BSM_MESSAGE c3_tmp;
  int32_T c3_i285;
  int32_T c3_i286;
  int32_T c3_i287;
  int32_T c3_i288;
  int32_T c3_i289;
  int32_T c3_i290;
  SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc3_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c3_mxVal = NULL;
  c3_tmp.HEADER.valid = *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)
    (c3_PRESCAN_V2X_USER_BSM_MESSAGE *)c3_pData)[0])[0];
  c3_tmp.DATA.msgID = *(int32_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)(c3_PRESCAN_V2X_USER_BSM_MESSAGE *)c3_pData)[8])[0];
  c3_tmp.DATA.msgCnt = *(int32_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)(c3_PRESCAN_V2X_USER_BSM_MESSAGE *)c3_pData)[8])[4];
  for (c3_i285 = 0; c3_i285 < 4; c3_i285++) {
    c3_tmp.DATA.id[c3_i285] = ((int8_T *)&((char_T *)
      (c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
      (c3_PRESCAN_V2X_USER_BSM_MESSAGE *)c3_pData)[8])[8])[c3_i285];
  }

  c3_tmp.DATA.secMark = *(int32_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)(c3_PRESCAN_V2X_USER_BSM_MESSAGE *)c3_pData)[8])[12];
  c3_tmp.DATA.latitude = *(int32_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)(c3_PRESCAN_V2X_USER_BSM_MESSAGE *)c3_pData)[8])[16];
  c3_tmp.DATA.longitude = *(int32_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)(c3_PRESCAN_V2X_USER_BSM_MESSAGE *)c3_pData)[8])[20];
  for (c3_i286 = 0; c3_i286 < 2; c3_i286++) {
    c3_tmp.DATA.elev[c3_i286] = ((int8_T *)&((char_T *)
      (c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
      (c3_PRESCAN_V2X_USER_BSM_MESSAGE *)c3_pData)[8])[24])[c3_i286];
  }

  for (c3_i287 = 0; c3_i287 < 4; c3_i287++) {
    c3_tmp.DATA.accuracy[c3_i287] = ((int8_T *)&((char_T *)
      (c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
      (c3_PRESCAN_V2X_USER_BSM_MESSAGE *)c3_pData)[8])[26])[c3_i287];
  }

  for (c3_i288 = 0; c3_i288 < 2; c3_i288++) {
    c3_tmp.DATA.speed[c3_i288] = ((int8_T *)&((char_T *)
      (c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
      (c3_PRESCAN_V2X_USER_BSM_MESSAGE *)c3_pData)[8])[30])[c3_i288];
  }

  c3_tmp.DATA.heading = *(int32_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)(c3_PRESCAN_V2X_USER_BSM_MESSAGE *)c3_pData)[8])[32];
  c3_tmp.DATA.angle = *(int8_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)(c3_PRESCAN_V2X_USER_BSM_MESSAGE *)c3_pData)[8])[36];
  for (c3_i289 = 0; c3_i289 < 7; c3_i289++) {
    c3_tmp.DATA.accelSet[c3_i289] = ((int8_T *)&((char_T *)
      (c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
      (c3_PRESCAN_V2X_USER_BSM_MESSAGE *)c3_pData)[8])[37])[c3_i289];
  }

  for (c3_i290 = 0; c3_i290 < 2; c3_i290++) {
    c3_tmp.DATA.brakes[c3_i290] = ((int8_T *)&((char_T *)
      (c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
      (c3_PRESCAN_V2X_USER_BSM_MESSAGE *)c3_pData)[8])[44])[c3_i290];
  }

  c3_tmp.DATA.size.width = *(int32_T *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_size
    *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
    (c3_PRESCAN_V2X_USER_BSM_MESSAGE *)c3_pData)[8])[48])[0];
  c3_tmp.DATA.size.length = *(int32_T *)&((char_T *)
    (c3_PRESCAN_V2X_USER_BSM_size *)&((char_T *)(c3_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)(c3_PRESCAN_V2X_USER_BSM_MESSAGE *)c3_pData)[8])[48])[4];
  sf_mex_assign(&c3_mxVal, c3_c_sf_marshallOut(chartInstance, &c3_tmp), false);
  return c3_mxVal;
}

static uint8_T c3_hd_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_Jan22_DLforACC_cs, const
  char_T *c3_identifier)
{
  uint8_T c3_b_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_y = c3_id_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_Jan22_DLforACC_cs), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_Jan22_DLforACC_cs);
  return c3_b_y;
}

static uint8_T c3_id_emlrt_marshallIn(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_b_y;
  uint8_T c3_u0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_b_y = c3_u0;
  sf_mex_destroy(&c3_b_u);
  return c3_b_y;
}

static void init_dsm_address_info(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc3_Jan22_DLforACC_csInstanceStruct
  *chartInstance)
{
  chartInstance->c3_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c3_u = (PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c3_y = (c3_PRESCAN_V2X_USER_BSM_MESSAGE *)
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c3_z = (c3_PRESCAN_V2X_USER_BSM_MESSAGE *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 1);
}

/* SFunction Glue Code */
void sf_c3_Jan22_DLforACC_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1294956175U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1641568694U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2669433127U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(672617605U);
}

mxArray* sf_c3_Jan22_DLforACC_cs_get_post_codegen_info(void);
mxArray *sf_c3_Jan22_DLforACC_cs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("GhuJtjOgCN6otutIThDh3G");
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
    mxArray* mxPostCodegenInfo = sf_c3_Jan22_DLforACC_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_Jan22_DLforACC_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_Jan22_DLforACC_cs_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("early");
  mxArray *fallbackReason = mxCreateString("imported_bus");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("PRESCAN_V2X_FIXED_BSM_MESSAGE");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c3_Jan22_DLforACC_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c3_Jan22_DLforACC_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c3_Jan22_DLforACC_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c3_Jan22_DLforACC_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_Jan22_DLforACC_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance =
      (SFc3_Jan22_DLforACC_csInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Jan22_DLforACC_csMachineNumber_,
           3,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,55);
        _SFD_CV_INIT_SCRIPT(0,5,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"V2X_BSM_filter",0,-1,103);
        _SFD_CV_INIT_SCRIPT_FCN(0,1,"FILTER_PRESCAN_V2X_USER_BSM_MESSAGE",105,-1,
          282);
        _SFD_CV_INIT_SCRIPT_FCN(0,2,"FILTER_PRESCAN_HEADER",284,-1,351);
        _SFD_CV_INIT_SCRIPT_FCN(0,3,"FILTER_PRESCAN_V2X_USER_BSM_DATA",353,-1,
          774);
        _SFD_CV_INIT_SCRIPT_FCN(0,4,"FILTER_PRESCAN_V2X_USER_BSM_size",776,-1,
          877);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_u_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_y_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_y_bus_io,(MexInFcnForType)NULL);
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
    SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance =
      (SFc3_Jan22_DLforACC_csInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c3_u);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c3_y);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c3_z);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sS0b8s5iLYOi9XoaSidJtzB";
}

static void sf_opaque_initialize_c3_Jan22_DLforACC_cs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_Jan22_DLforACC_csInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_Jan22_DLforACC_cs((SFc3_Jan22_DLforACC_csInstanceStruct*)
    chartInstanceVar);
  initialize_c3_Jan22_DLforACC_cs((SFc3_Jan22_DLforACC_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_Jan22_DLforACC_cs(void *chartInstanceVar)
{
  enable_c3_Jan22_DLforACC_cs((SFc3_Jan22_DLforACC_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c3_Jan22_DLforACC_cs(void *chartInstanceVar)
{
  disable_c3_Jan22_DLforACC_cs((SFc3_Jan22_DLforACC_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c3_Jan22_DLforACC_cs(void *chartInstanceVar)
{
  sf_gateway_c3_Jan22_DLforACC_cs((SFc3_Jan22_DLforACC_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c3_Jan22_DLforACC_cs(SimStruct* S)
{
  return get_sim_state_c3_Jan22_DLforACC_cs
    ((SFc3_Jan22_DLforACC_csInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c3_Jan22_DLforACC_cs(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c3_Jan22_DLforACC_cs((SFc3_Jan22_DLforACC_csInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c3_Jan22_DLforACC_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_Jan22_DLforACC_csInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Jan22_DLforACC_cs_optimization_info();
    }

    finalize_c3_Jan22_DLforACC_cs((SFc3_Jan22_DLforACC_csInstanceStruct*)
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
  initSimStructsc3_Jan22_DLforACC_cs((SFc3_Jan22_DLforACC_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_Jan22_DLforACC_cs(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_Jan22_DLforACC_cs((SFc3_Jan22_DLforACC_csInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c3_Jan22_DLforACC_cs(SimStruct *S)
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
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetSupportedForRowMajorCodeGen(S, 1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,3,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 3);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3621739769U));
  ssSetChecksum1(S,(31975563U));
  ssSetChecksum2(S,(2245361424U));
  ssSetChecksum3(S,(948308730U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_Jan22_DLforACC_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_Jan22_DLforACC_cs(SimStruct *S)
{
  SFc3_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc3_Jan22_DLforACC_csInstanceStruct *)utMalloc(sizeof
    (SFc3_Jan22_DLforACC_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc3_Jan22_DLforACC_csInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_Jan22_DLforACC_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_Jan22_DLforACC_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_Jan22_DLforACC_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_Jan22_DLforACC_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_Jan22_DLforACC_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_Jan22_DLforACC_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_Jan22_DLforACC_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_Jan22_DLforACC_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_Jan22_DLforACC_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_Jan22_DLforACC_cs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_Jan22_DLforACC_cs;
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
  mdl_start_c3_Jan22_DLforACC_cs(chartInstance);
}

void c3_Jan22_DLforACC_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_Jan22_DLforACC_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_Jan22_DLforACC_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_Jan22_DLforACC_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_Jan22_DLforACC_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
