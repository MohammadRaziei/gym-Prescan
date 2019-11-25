/* Include files */

#include "Jan22_DLforACC_cs_sfun.h"
#include "c5_Jan22_DLforACC_cs.h"
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
static const char * c5_debug_family_names[5] = { "nargin", "nargout", "u", "z",
  "y" };

static const char * c5_b_debug_family_names[4] = { "nargin", "nargout", "u", "y"
};

static const char * c5_c_debug_family_names[4] = { "nargin", "nargout", "u", "y"
};

static const char * c5_d_debug_family_names[4] = { "nargin", "nargout", "u", "y"
};

static const char * c5_e_debug_family_names[4] = { "nargin", "nargout", "u", "y"
};

static const char * c5_f_debug_family_names[5] = { "nargin", "nargout", "y", "z",
  "u" };

static const char * c5_sv0[2] = { "HEADER", "DATA" };

static const char * c5_sv1[2] = { "width", "length" };

static const char * c5_sv2[10] = { "utcTime", "longitude", "latitude",
  "elevation", "heading", "speed", "posAccuracy", "timeConfidence",
  "posConfidence", "speedConfidence" };

static const char * c5_sv3[6] = { "year", "month", "day", "hour", "minute",
  "second" };

static const char * c5_sv4[2] = { "HEADER", "DATA" };

static const char * c5_sv5[2] = { "width", "length" };

static const char * c5_sv6[10] = { "utcTime", "longitude", "latitude",
  "elevation", "heading", "speed", "posAccuracy", "timeConfidence",
  "posConfidence", "speedConfidence" };

static const char * c5_sv7[6] = { "year", "month", "day", "hour", "minute",
  "second" };

/* Function Declarations */
static void initialize_c5_Jan22_DLforACC_cs(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance);
static void initialize_params_c5_Jan22_DLforACC_cs
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance);
static void enable_c5_Jan22_DLforACC_cs(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance);
static void disable_c5_Jan22_DLforACC_cs(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance);
static void c5_update_debugger_state_c5_Jan22_DLforACC_cs
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_Jan22_DLforACC_cs
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance);
static void set_sim_state_c5_Jan22_DLforACC_cs
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_st);
static void finalize_c5_Jan22_DLforACC_cs(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance);
static void sf_gateway_c5_Jan22_DLforACC_cs(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance);
static void mdl_start_c5_Jan22_DLforACC_cs(SFc5_Jan22_DLforACC_csInstanceStruct *
  chartInstance);
static void initSimStructsc5_Jan22_DLforACC_cs
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static real_T c5_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_emlrt_marshallOut(SFc5_Jan22_DLforACC_csInstanceStruct *
  chartInstance, const c5_PRESCAN_V2X_USER_BSM_DATA c5_b_u);
static const mxArray *c5_b_emlrt_marshallOut
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const int32_T c5_b_u);
static const mxArray *c5_c_emlrt_marshallOut
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const int8_T c5_b_u[2]);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_d_emlrt_marshallOut
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const
   PRESCAN_V2X_FIXED_BSM_DATA *c5_b_u);
static const mxArray *c5_e_emlrt_marshallOut
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const
   PRESCAN_V2X_FIXED_BSM_safetyExt *c5_b_u);
static const mxArray *c5_f_emlrt_marshallOut
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const
   PRESCAN_V2X_FIXED_BSM_utcTime c5_b_u);
static const mxArray *c5_g_emlrt_marshallOut
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const
   PRESCAN_V2X_FIXED_BSM_status *c5_b_u);
static const mxArray *c5_h_emlrt_marshallOut
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const
   PRESCAN_V2X_FIXED_BSM_wipers c5_b_u);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_b_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_y, const char_T *c5_identifier,
  PRESCAN_V2X_FIXED_BSM_MESSAGE *c5_c_y);
static void c5_c_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  PRESCAN_V2X_FIXED_BSM_MESSAGE *c5_b_y);
static PRESCAN_HEADER c5_d_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId);
static boolean_T c5_e_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_f_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  PRESCAN_V2X_FIXED_BSM_DATA *c5_b_y);
static int32_T c5_g_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_h_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[4]);
static void c5_i_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[2]);
static int8_T c5_j_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_k_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[7]);
static PRESCAN_V2X_FIXED_BSM_size c5_l_emlrt_marshallIn
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_b_u,
   const emlrtMsgIdentifier *c5_parentId);
static void c5_m_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  PRESCAN_V2X_FIXED_BSM_safetyExt *c5_b_y);
static void c5_n_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  PRESCAN_V2X_FIXED_BSM_pathHistory *c5_b_y);
static PRESCAN_V2X_FIXED_BSM_initialPosition c5_o_emlrt_marshallIn
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_b_u,
   const emlrtMsgIdentifier *c5_parentId);
static PRESCAN_V2X_FIXED_BSM_utcTime c5_p_emlrt_marshallIn
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_b_u,
   const emlrtMsgIdentifier *c5_parentId);
static void c5_q_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  PRESCAN_V2X_FIXED_BSM_crumbData *c5_b_y);
static void c5_r_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 c5_b_y[23]);
static void c5_s_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[345]);
static void c5_t_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[276]);
static void c5_u_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[184]);
static void c5_v_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[230]);
static void c5_w_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[138]);
static void c5_x_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[242]);
static void c5_y_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[161]);
static void c5_ab_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[196]);
static void c5_bb_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[104]);
static PRESCAN_V2X_FIXED_BSM_pathPrediction c5_cb_emlrt_marshallIn
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_b_u,
   const emlrtMsgIdentifier *c5_parentId);
static void c5_db_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  PRESCAN_V2X_FIXED_BSM_theRTCM *c5_b_y);
static PRESCAN_V2X_FIXED_BSM_anchorPoint c5_eb_emlrt_marshallIn
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_b_u,
   const emlrtMsgIdentifier *c5_parentId);
static void c5_fb_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[5]);
static void c5_gb_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[124]);
static void c5_hb_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[156]);
static void c5_ib_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[210]);
static void c5_jb_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[258]);
static void c5_kb_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[19]);
static void c5_lb_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[21]);
static void c5_mb_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[36]);
static void c5_nb_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[68]);
static void c5_ob_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[136]);
static void c5_pb_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[166]);
static void c5_qb_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[222]);
static void c5_rb_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[268]);
static void c5_sb_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[27]);
static void c5_tb_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[15]);
static void c5_ub_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[69]);
static void c5_vb_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[81]);
static void c5_wb_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[115]);
static void c5_xb_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[62]);
static void c5_yb_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[45]);
static void c5_ac_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[75]);
static void c5_bc_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[73]);
static void c5_cc_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[74]);
static void c5_dc_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[25]);
static void c5_ec_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[30]);
static void c5_fc_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[33]);
static void c5_gc_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[105]);
static void c5_hc_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[107]);
static void c5_ic_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[20]);
static void c5_jc_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  PRESCAN_V2X_FIXED_BSM_status *c5_b_y);
static PRESCAN_V2X_FIXED_BSM_wipers c5_kc_emlrt_marshallIn
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_b_u,
   const emlrtMsgIdentifier *c5_parentId);
static PRESCAN_V2X_FIXED_BSM_steering c5_lc_emlrt_marshallIn
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_b_u,
   const emlrtMsgIdentifier *c5_parentId);
static PRESCAN_V2X_FIXED_BSM_accelSets c5_mc_emlrt_marshallIn
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_b_u,
   const emlrtMsgIdentifier *c5_parentId);
static PRESCAN_V2X_FIXED_BSM_confidenceSet c5_nc_emlrt_marshallIn
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_b_u,
   const emlrtMsgIdentifier *c5_parentId);
static PRESCAN_V2X_FIXED_BSM_accelConfidence c5_oc_emlrt_marshallIn
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_b_u,
   const emlrtMsgIdentifier *c5_parentId);
static PRESCAN_V2X_FIXED_BSM_object c5_pc_emlrt_marshallIn
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_b_u,
   const emlrtMsgIdentifier *c5_parentId);
static PRESCAN_V2X_FIXED_BSM_dateTime c5_qc_emlrt_marshallIn
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_b_u,
   const emlrtMsgIdentifier *c5_parentId);
static PRESCAN_V2X_FIXED_BSM_fullPos c5_rc_emlrt_marshallIn
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_b_u,
   const emlrtMsgIdentifier *c5_parentId);
static PRESCAN_V2X_FIXED_BSM_vehicleData c5_sc_emlrt_marshallIn
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_b_u,
   const emlrtMsgIdentifier *c5_parentId);
static PRESCAN_V2X_FIXED_BSM_bumpers c5_tc_emlrt_marshallIn
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_b_u,
   const emlrtMsgIdentifier *c5_parentId);
static void c5_uc_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  PRESCAN_V2X_FIXED_BSM_vehicleIdent *c5_b_y);
static void c5_vc_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[63]);
static void c5_wc_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[17]);
static void c5_xc_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[32]);
static PRESCAN_V2X_FIXED_BSM_vehicleClass c5_yc_emlrt_marshallIn
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_b_u,
   const emlrtMsgIdentifier *c5_parentId);
static void c5_ad_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  PRESCAN_V2X_FIXED_BSM_j1939data *c5_b_y);
static void c5_bd_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  PRESCAN_V2X_FIXED_BSM_tires c5_b_y[16]);
static void c5_cd_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  PRESCAN_V2X_FIXED_BSM_axle c5_b_y[16]);
static PRESCAN_V2X_FIXED_BSM_weatherReport c5_dd_emlrt_marshallIn
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_b_u,
   const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_e_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_f_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static c5_PRESCAN_V2X_USER_BSM_size c5_ed_emlrt_marshallIn
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_b_u,
   const emlrtMsgIdentifier *c5_parentId);
static void c5_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_g_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_h_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static c5_PRESCAN_V2X_USER_BSM_DATA c5_fd_emlrt_marshallIn
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_b_u,
   const emlrtMsgIdentifier *c5_parentId);
static void c5_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static c5_PRESCAN_V2X_USER_BSM_MESSAGE c5_gd_emlrt_marshallIn
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_b_u,
   const emlrtMsgIdentifier *c5_parentId);
static void c5_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_i_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_u_bus_io(void *chartInstanceVoid, void *c5_pData);
static const mxArray *c5_y_bus_io(void *chartInstanceVoid, void *c5_pData);
static uint8_T c5_hd_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_Jan22_DLforACC_cs, const
  char_T *c5_identifier);
static uint8_T c5_id_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId);
static void init_dsm_address_info(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c5_Jan22_DLforACC_cs(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc5_Jan22_DLforACC_cs(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  sim_mode_is_external(chartInstance->S);
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c5_is_active_c5_Jan22_DLforACC_cs = 0U;
  setLegacyDebuggerFlagForRuntime(chartInstance->S, true);
}

static void initialize_params_c5_Jan22_DLforACC_cs
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c5_Jan22_DLforACC_cs(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c5_Jan22_DLforACC_cs(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c5_update_debugger_state_c5_Jan22_DLforACC_cs
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c5_Jan22_DLforACC_cs
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_b_y = NULL;
  const mxArray *c5_c_y = NULL;
  PRESCAN_HEADER c5_b_u;
  const mxArray *c5_d_y = NULL;
  static const char * c5_sv8[1] = { "valid" };

  boolean_T c5_c_u;
  const mxArray *c5_e_y = NULL;
  PRESCAN_V2X_FIXED_BSM_DATA c5_r0;
  int32_T c5_i0;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i16;
  int32_T c5_i17;
  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i22;
  int32_T c5_i23;
  int32_T c5_i24;
  int32_T c5_i25;
  int32_T c5_i26;
  int32_T c5_i27;
  int32_T c5_i28;
  int32_T c5_i29;
  int32_T c5_i30;
  int32_T c5_i31;
  int32_T c5_i32;
  int32_T c5_i33;
  int32_T c5_i34;
  int32_T c5_i35;
  int32_T c5_i36;
  int32_T c5_i37;
  int32_T c5_i38;
  int32_T c5_i39;
  int32_T c5_i40;
  int32_T c5_i41;
  int32_T c5_i42;
  int32_T c5_i43;
  int32_T c5_i44;
  int32_T c5_i45;
  int32_T c5_i46;
  int32_T c5_i47;
  int32_T c5_i48;
  int32_T c5_i49;
  int32_T c5_i50;
  int32_T c5_i51;
  int32_T c5_i52;
  int32_T c5_i53;
  int32_T c5_i54;
  int32_T c5_i55;
  int32_T c5_i56;
  int32_T c5_i57;
  int32_T c5_i58;
  int32_T c5_i59;
  int32_T c5_i60;
  int32_T c5_i61;
  int32_T c5_i62;
  int32_T c5_i63;
  int32_T c5_i64;
  int32_T c5_i65;
  uint8_T c5_hoistedGlobal;
  const mxArray *c5_f_y = NULL;
  c5_st = NULL;
  c5_st = NULL;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_createcellmatrix(2, 1), false);
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_createstruct("structure", 2, c5_sv0, 2, 1, 1),
                false);
  c5_b_u.valid = *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)
    chartInstance->c5_y)[0])[0];
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_createstruct("structure", 1, c5_sv8, 2, 1, 1),
                false);
  c5_c_u = c5_b_u.valid;
  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", &c5_c_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_d_y, 0, "valid", c5_e_y, 0);
  sf_mex_setfieldbynum(c5_c_y, 0, "HEADER", c5_d_y, 0);
  c5_r0.msgID = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    chartInstance->c5_y)[8])[0];
  c5_r0.msgCnt = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T
    *)chartInstance->c5_y)[8])[4];
  for (c5_i0 = 0; c5_i0 < 4; c5_i0++) {
    c5_r0.id[c5_i0] = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_y)[8])[8])[c5_i0];
  }

  c5_r0.secMark = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[12];
  c5_r0.latitude = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[16];
  c5_r0.longitude = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[20];
  for (c5_i1 = 0; c5_i1 < 2; c5_i1++) {
    c5_r0.elev[c5_i1] = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_y)[8])[24])[c5_i1];
  }

  for (c5_i2 = 0; c5_i2 < 4; c5_i2++) {
    c5_r0.accuracy[c5_i2] = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_y)[8])[26])[c5_i2];
  }

  for (c5_i3 = 0; c5_i3 < 2; c5_i3++) {
    c5_r0.speed[c5_i3] = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_y)[8])[30])[c5_i3];
  }

  c5_r0.heading = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[32];
  c5_r0.angle = *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    chartInstance->c5_y)[8])[36];
  for (c5_i4 = 0; c5_i4 < 7; c5_i4++) {
    c5_r0.accelSet[c5_i4] = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_y)[8])[37])[c5_i4];
  }

  for (c5_i5 = 0; c5_i5 < 2; c5_i5++) {
    c5_r0.brakes[c5_i5] = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_y)[8])[44])[c5_i5];
  }

  c5_r0.size.width = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_size *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [48])[0];
  c5_r0.size.length = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_size *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [48])[4];
  c5_r0.safetyExt.events = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[0];
  c5_r0.safetyExt.pathHistory.initialPosition.utcTime.year = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
        [8])[0])[0])[0];
  c5_r0.safetyExt.pathHistory.initialPosition.utcTime.month = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
        [8])[0])[0])[4];
  c5_r0.safetyExt.pathHistory.initialPosition.utcTime.day = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
        [8])[0])[0])[8];
  c5_r0.safetyExt.pathHistory.initialPosition.utcTime.hour = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
        [8])[0])[0])[12];
  c5_r0.safetyExt.pathHistory.initialPosition.utcTime.minute = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
        [8])[0])[0])[16];
  c5_r0.safetyExt.pathHistory.initialPosition.utcTime.second = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
        [8])[0])[0])[20];
  c5_r0.safetyExt.pathHistory.initialPosition.longitude = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[8])[0])[24];
  c5_r0.safetyExt.pathHistory.initialPosition.latitude = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[8])[0])[28];
  for (c5_i6 = 0; c5_i6 < 2; c5_i6++) {
    c5_r0.safetyExt.pathHistory.initialPosition.elevation[c5_i6] = ((int8_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[8])[0])[32])[c5_i6];
  }

  c5_r0.safetyExt.pathHistory.initialPosition.heading = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[8])[0])[36];
  for (c5_i7 = 0; c5_i7 < 2; c5_i7++) {
    c5_r0.safetyExt.pathHistory.initialPosition.speed[c5_i7] = ((int8_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[8])[0])[40])[c5_i7];
  }

  for (c5_i8 = 0; c5_i8 < 4; c5_i8++) {
    c5_r0.safetyExt.pathHistory.initialPosition.posAccuracy[c5_i8] = ((int8_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[8])[0])[42])[c5_i8];
  }

  c5_r0.safetyExt.pathHistory.initialPosition.timeConfidence = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
       [8])[0])[48];
  c5_r0.safetyExt.pathHistory.initialPosition.posConfidence = *(int8_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
       [8])[0])[52];
  c5_r0.safetyExt.pathHistory.initialPosition.speedConfidence = *(int8_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
       [8])[0])[53];
  c5_r0.safetyExt.pathHistory.currGPSstatus = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[8])[56];
  c5_r0.safetyExt.pathHistory.itemCnt = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[8])[60];
  for (c5_i9 = 0; c5_i9 < 23; c5_i9++) {
    c5_r0.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c5_i9].
      latOffset = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[8])[64])[0])[32 * (int32_T)
      c5_i9])[0];
    c5_r0.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c5_i9].
      longOffset = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[8])[64])[0])[32 * (int32_T)
      c5_i9])[4];
    c5_r0.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c5_i9].
      elevationOffset = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[8])[64])[0])[32 * (int32_T)
      c5_i9])[8];
    c5_r0.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c5_i9].
      timeOffset = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[8])[64])[0])[32 * (int32_T)
      c5_i9])[12];
    for (c5_i12 = 0; c5_i12 < 4; c5_i12++) {
      c5_r0.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c5_i9].
        posAccuracy[c5_i12] = ((int8_T *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
        [8])[64])[0])[32 * (int32_T)c5_i9])[16])[c5_i12];
    }

    c5_r0.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c5_i9].heading
      = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                      &((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[8])[64])[0])[32 * (int32_T)
                      c5_i9])[20];
    for (c5_i14 = 0; c5_i14 < 2; c5_i14++) {
      c5_r0.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c5_i9]
        .speed[c5_i14] = ((int8_T *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
        [8])[64])[0])[32 * (int32_T)c5_i9])[24])[c5_i14];
    }
  }

  for (c5_i10 = 0; c5_i10 < 345; c5_i10++) {
    c5_r0.safetyExt.pathHistory.crumbData.pathHistoryPointSets_02[c5_i10] =
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
         [8])[64])[736])[c5_i10];
  }

  for (c5_i11 = 0; c5_i11 < 276; c5_i11++) {
    c5_r0.safetyExt.pathHistory.crumbData.pathHistoryPointSets_03[c5_i11] =
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
         [8])[64])[1081])[c5_i11];
  }

  for (c5_i13 = 0; c5_i13 < 184; c5_i13++) {
    c5_r0.safetyExt.pathHistory.crumbData.pathHistoryPointSets_04[c5_i13] =
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
         [8])[64])[1357])[c5_i13];
  }

  for (c5_i15 = 0; c5_i15 < 230; c5_i15++) {
    c5_r0.safetyExt.pathHistory.crumbData.pathHistoryPointSets_05[c5_i15] =
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
         [8])[64])[1541])[c5_i15];
  }

  for (c5_i16 = 0; c5_i16 < 138; c5_i16++) {
    c5_r0.safetyExt.pathHistory.crumbData.pathHistoryPointSets_06[c5_i16] =
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
         [8])[64])[1771])[c5_i16];
  }

  for (c5_i17 = 0; c5_i17 < 242; c5_i17++) {
    c5_r0.safetyExt.pathHistory.crumbData.pathHistoryPointSets_07[c5_i17] =
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
         [8])[64])[1909])[c5_i17];
  }

  for (c5_i18 = 0; c5_i18 < 161; c5_i18++) {
    c5_r0.safetyExt.pathHistory.crumbData.pathHistoryPointSets_08[c5_i18] =
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
         [8])[64])[2151])[c5_i18];
  }

  for (c5_i19 = 0; c5_i19 < 196; c5_i19++) {
    c5_r0.safetyExt.pathHistory.crumbData.pathHistoryPointSets_09[c5_i19] =
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
         [8])[64])[2312])[c5_i19];
  }

  for (c5_i20 = 0; c5_i20 < 104; c5_i20++) {
    c5_r0.safetyExt.pathHistory.crumbData.pathHistoryPointSets_10[c5_i20] =
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
         [8])[64])[2508])[c5_i20];
  }

  c5_r0.safetyExt.pathPrediction.radiusOfCurve = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathPrediction *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2688])[0];
  c5_r0.safetyExt.pathPrediction.confidence = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathPrediction *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2688])[4];
  c5_r0.safetyExt.theRTCM.anchorPoint.utcTime.year = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2696])[0])[0])[0];
  c5_r0.safetyExt.theRTCM.anchorPoint.utcTime.month = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2696])[0])[0])[4];
  c5_r0.safetyExt.theRTCM.anchorPoint.utcTime.day = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2696])[0])[0])[8];
  c5_r0.safetyExt.theRTCM.anchorPoint.utcTime.hour = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2696])[0])[0])[12];
  c5_r0.safetyExt.theRTCM.anchorPoint.utcTime.minute = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2696])[0])[0])[16];
  c5_r0.safetyExt.theRTCM.anchorPoint.utcTime.second = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2696])[0])[0])[20];
  c5_r0.safetyExt.theRTCM.anchorPoint.longitude = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2696])[0])[24];
  c5_r0.safetyExt.theRTCM.anchorPoint.latitude = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2696])[0])[28];
  for (c5_i21 = 0; c5_i21 < 2; c5_i21++) {
    c5_r0.safetyExt.theRTCM.anchorPoint.elevation[c5_i21] = ((int8_T *)&((char_T
      *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[2696])[0])[32])[c5_i21];
  }

  c5_r0.safetyExt.theRTCM.anchorPoint.heading = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2696])[0])[36];
  for (c5_i22 = 0; c5_i22 < 2; c5_i22++) {
    c5_r0.safetyExt.theRTCM.anchorPoint.speed[c5_i22] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[2696])[0])[40])[c5_i22];
  }

  for (c5_i23 = 0; c5_i23 < 4; c5_i23++) {
    c5_r0.safetyExt.theRTCM.anchorPoint.posAccuracy[c5_i23] = ((int8_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[2696])[0])[42])[c5_i23];
  }

  c5_r0.safetyExt.theRTCM.anchorPoint.timeConfidence = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2696])[0])[48];
  c5_r0.safetyExt.theRTCM.anchorPoint.posConfidence = *(int8_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2696])[0])[52];
  c5_r0.safetyExt.theRTCM.anchorPoint.speedConfidence = *(int8_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2696])[0])[53];
  for (c5_i24 = 0; c5_i24 < 5; c5_i24++) {
    c5_r0.safetyExt.theRTCM.rtcmHeader[c5_i24] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[2696])[56])[c5_i24];
  }

  for (c5_i25 = 0; c5_i25 < 124; c5_i25++) {
    c5_r0.safetyExt.theRTCM.msg1001[c5_i25] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[2696])[61])[c5_i25];
  }

  for (c5_i26 = 0; c5_i26 < 156; c5_i26++) {
    c5_r0.safetyExt.theRTCM.msg1002[c5_i26] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[2696])[185])[c5_i26];
  }

  for (c5_i27 = 0; c5_i27 < 210; c5_i27++) {
    c5_r0.safetyExt.theRTCM.msg1003[c5_i27] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[2696])[341])[c5_i27];
  }

  for (c5_i28 = 0; c5_i28 < 258; c5_i28++) {
    c5_r0.safetyExt.theRTCM.msg1004[c5_i28] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[2696])[551])[c5_i28];
  }

  for (c5_i29 = 0; c5_i29 < 19; c5_i29++) {
    c5_r0.safetyExt.theRTCM.msg1005[c5_i29] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[2696])[809])[c5_i29];
  }

  for (c5_i30 = 0; c5_i30 < 21; c5_i30++) {
    c5_r0.safetyExt.theRTCM.msg1006[c5_i30] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[2696])[828])[c5_i30];
  }

  for (c5_i31 = 0; c5_i31 < 36; c5_i31++) {
    c5_r0.safetyExt.theRTCM.msg1007[c5_i31] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[2696])[849])[c5_i31];
  }

  for (c5_i32 = 0; c5_i32 < 68; c5_i32++) {
    c5_r0.safetyExt.theRTCM.msg1008[c5_i32] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[2696])[885])[c5_i32];
  }

  for (c5_i33 = 0; c5_i33 < 136; c5_i33++) {
    c5_r0.safetyExt.theRTCM.msg1009[c5_i33] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[2696])[953])[c5_i33];
  }

  for (c5_i34 = 0; c5_i34 < 166; c5_i34++) {
    c5_r0.safetyExt.theRTCM.msg1010[c5_i34] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[2696])[1089])[c5_i34];
  }

  for (c5_i35 = 0; c5_i35 < 222; c5_i35++) {
    c5_r0.safetyExt.theRTCM.msg1011[c5_i35] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[2696])[1255])[c5_i35];
  }

  for (c5_i36 = 0; c5_i36 < 268; c5_i36++) {
    c5_r0.safetyExt.theRTCM.msg1012[c5_i36] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[2696])[1477])[c5_i36];
  }

  for (c5_i37 = 0; c5_i37 < 27; c5_i37++) {
    c5_r0.safetyExt.theRTCM.msg1013[c5_i37] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[2696])[1745])[c5_i37];
  }

  for (c5_i38 = 0; c5_i38 < 15; c5_i38++) {
    c5_r0.safetyExt.theRTCM.msg1014[c5_i38] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[2696])[1772])[c5_i38];
  }

  for (c5_i39 = 0; c5_i39 < 69; c5_i39++) {
    c5_r0.safetyExt.theRTCM.msg1015[c5_i39] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[2696])[1787])[c5_i39];
  }

  for (c5_i40 = 0; c5_i40 < 81; c5_i40++) {
    c5_r0.safetyExt.theRTCM.msg1016[c5_i40] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[2696])[1856])[c5_i40];
  }

  for (c5_i41 = 0; c5_i41 < 115; c5_i41++) {
    c5_r0.safetyExt.theRTCM.msg1017[c5_i41] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[2696])[1937])[c5_i41];
  }

  for (c5_i42 = 0; c5_i42 < 62; c5_i42++) {
    c5_r0.safetyExt.theRTCM.msg1019[c5_i42] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[2696])[2052])[c5_i42];
  }

  for (c5_i43 = 0; c5_i43 < 45; c5_i43++) {
    c5_r0.safetyExt.theRTCM.msg1020[c5_i43] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[2696])[2114])[c5_i43];
  }

  for (c5_i44 = 0; c5_i44 < 62; c5_i44++) {
    c5_r0.safetyExt.theRTCM.msg1021[c5_i44] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[2696])[2159])[c5_i44];
  }

  for (c5_i45 = 0; c5_i45 < 75; c5_i45++) {
    c5_r0.safetyExt.theRTCM.msg1022[c5_i45] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[2696])[2221])[c5_i45];
  }

  for (c5_i46 = 0; c5_i46 < 73; c5_i46++) {
    c5_r0.safetyExt.theRTCM.msg1023[c5_i46] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[2696])[2296])[c5_i46];
  }

  for (c5_i47 = 0; c5_i47 < 74; c5_i47++) {
    c5_r0.safetyExt.theRTCM.msg1024[c5_i47] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[2696])[2369])[c5_i47];
  }

  for (c5_i48 = 0; c5_i48 < 25; c5_i48++) {
    c5_r0.safetyExt.theRTCM.msg1025[c5_i48] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[2696])[2443])[c5_i48];
  }

  for (c5_i49 = 0; c5_i49 < 30; c5_i49++) {
    c5_r0.safetyExt.theRTCM.msg1026[c5_i49] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[2696])[2468])[c5_i49];
  }

  for (c5_i50 = 0; c5_i50 < 33; c5_i50++) {
    c5_r0.safetyExt.theRTCM.msg1027[c5_i50] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[2696])[2498])[c5_i50];
  }

  for (c5_i51 = 0; c5_i51 < 69; c5_i51++) {
    c5_r0.safetyExt.theRTCM.msg1029[c5_i51] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[2696])[2531])[c5_i51];
  }

  for (c5_i52 = 0; c5_i52 < 105; c5_i52++) {
    c5_r0.safetyExt.theRTCM.msg1030[c5_i52] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[2696])[2600])[c5_i52];
  }

  for (c5_i53 = 0; c5_i53 < 107; c5_i53++) {
    c5_r0.safetyExt.theRTCM.msg1031[c5_i53] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[2696])[2705])[c5_i53];
  }

  for (c5_i54 = 0; c5_i54 < 20; c5_i54++) {
    c5_r0.safetyExt.theRTCM.msg1032[c5_i54] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[2696])[2812])[c5_i54];
  }

  c5_r0.status.lights = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[0];
  c5_r0.status.lightBar = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[4];
  c5_r0.status.wipers.statusFront = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[8])[0];
  c5_r0.status.wipers.rateFront = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[8])[4];
  c5_r0.status.wipers.statusRear = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[8])[8];
  c5_r0.status.wipers.rateRear = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[8])[12];
  for (c5_i55 = 0; c5_i55 < 2; c5_i55++) {
    c5_r0.status.brakeStatus[c5_i55] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_y)[8])[5584])[24])[c5_i55];
  }

  c5_r0.status.brakePressure = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[28];
  c5_r0.status.roadFriction = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[32];
  c5_r0.status.sunData = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[36];
  c5_r0.status.rainData = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[40];
  c5_r0.status.airTemp = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[44];
  c5_r0.status.airPres = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[48];
  c5_r0.status.steering.angle = *(int8_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[56])[0];
  c5_r0.status.steering.confidence = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[56])[4];
  c5_r0.status.steering.rate = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[56])[8];
  c5_r0.status.steering.wheels = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[56])[12];
  for (c5_i56 = 0; c5_i56 < 7; c5_i56++) {
    c5_r0.status.accelSets.accel4way[c5_i56] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_y)[8])[5584])[72])[0])[c5_i56];
  }

  c5_r0.status.accelSets.vertAccelThres = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)
        [8])[5584])[72])[8];
  c5_r0.status.accelSets.yawRateCon = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)
        [8])[5584])[72])[12];
  c5_r0.status.accelSets.hozAccelCon = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)
        [8])[5584])[72])[16];
  c5_r0.status.accelSets.confidenceSet.accelConfidence.yawRate = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_accelConfidence *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
           *)&((char_T *)chartInstance->c5_y)[8])[5584])[72])[24])[0])[0];
  c5_r0.status.accelSets.confidenceSet.accelConfidence.acceleration = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_accelConfidence *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
           *)&((char_T *)chartInstance->c5_y)[8])[5584])[72])[24])[0])[4];
  c5_r0.status.accelSets.confidenceSet.accelConfidence.steeringWheelAngle =
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelConfidence *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)
        [8])[5584])[72])[24])[0])[8];
  c5_r0.status.accelSets.confidenceSet.speedConfidence = *(int8_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)
        [8])[5584])[72])[24])[16];
  c5_r0.status.accelSets.confidenceSet.timeConfidence = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)
        [8])[5584])[72])[24])[20];
  c5_r0.status.accelSets.confidenceSet.posConfidence = *(int8_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)
        [8])[5584])[72])[24])[24];
  c5_r0.status.accelSets.confidenceSet.steerConfidence = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)
        [8])[5584])[72])[24])[28];
  c5_r0.status.accelSets.confidenceSet.throttleConfidence = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
         &((char_T *)chartInstance->c5_y)[8])[5584])[72])[24])[32];
  c5_r0.status.object.obDist = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[136])[0];
  c5_r0.status.object.obDirect = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[136])[4];
  c5_r0.status.object.dateTime.year = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])
    [136])[8])[0];
  c5_r0.status.object.dateTime.month = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])
    [136])[8])[4];
  c5_r0.status.object.dateTime.day = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])
    [136])[8])[8];
  c5_r0.status.object.dateTime.hour = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])
    [136])[8])[12];
  c5_r0.status.object.dateTime.minute = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])
    [136])[8])[16];
  c5_r0.status.object.dateTime.second = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])
    [136])[8])[20];
  c5_r0.status.fullPos.utcTime.year = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])
    [168])[0])[0];
  c5_r0.status.fullPos.utcTime.month = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])
    [168])[0])[4];
  c5_r0.status.fullPos.utcTime.day = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])
    [168])[0])[8];
  c5_r0.status.fullPos.utcTime.hour = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])
    [168])[0])[12];
  c5_r0.status.fullPos.utcTime.minute = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])
    [168])[0])[16];
  c5_r0.status.fullPos.utcTime.second = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])
    [168])[0])[20];
  c5_r0.status.fullPos.longitude = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[168])[24];
  c5_r0.status.fullPos.latitude = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[168])[28];
  for (c5_i57 = 0; c5_i57 < 2; c5_i57++) {
    c5_r0.status.fullPos.elevation[c5_i57] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
      chartInstance->c5_y)[8])[5584])[168])[32])[c5_i57];
  }

  c5_r0.status.fullPos.heading = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[168])[36];
  for (c5_i58 = 0; c5_i58 < 2; c5_i58++) {
    c5_r0.status.fullPos.speed[c5_i58] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
      chartInstance->c5_y)[8])[5584])[168])[40])[c5_i58];
  }

  for (c5_i59 = 0; c5_i59 < 4; c5_i59++) {
    c5_r0.status.fullPos.posAccuracy[c5_i59] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
      chartInstance->c5_y)[8])[5584])[168])[42])[c5_i59];
  }

  c5_r0.status.fullPos.timeConfidence = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[168])[48];
  c5_r0.status.fullPos.posConfidence = *(int8_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[168])[52];
  c5_r0.status.fullPos.speedConfidence = *(int8_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[168])[53];
  c5_r0.status.throttlePos = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[224];
  c5_r0.status.speedHeadC = *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)
        [8])[5584])[228];
  c5_r0.status.speedC = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[232];
  c5_r0.status.vehicleData.height = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[240])[0];
  c5_r0.status.vehicleData.bumpers.frnt = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_bumpers *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[240])[8])[0];
  c5_r0.status.vehicleData.bumpers.rear = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_bumpers *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[240])[8])[4];
  c5_r0.status.vehicleData.mass = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[240])[16];
  c5_r0.status.vehicleData.trailerWeight = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[240])[20];
  c5_r0.status.vehicleData.type = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[240])[24];
  for (c5_i60 = 0; c5_i60 < 63; c5_i60++) {
    c5_r0.status.vehicleIdent.name[c5_i60] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_y)[8])[5584])[272])[0])[c5_i60];
  }

  for (c5_i61 = 0; c5_i61 < 17; c5_i61++) {
    c5_r0.status.vehicleIdent.vin[c5_i61] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_y)[8])[5584])[272])[63])[c5_i61];
  }

  for (c5_i62 = 0; c5_i62 < 32; c5_i62++) {
    c5_r0.status.vehicleIdent.ownerCode[c5_i62] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_y)[8])[5584])[272])[80])[c5_i62];
  }

  for (c5_i63 = 0; c5_i63 < 4; c5_i63++) {
    c5_r0.status.vehicleIdent.id[c5_i63] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_y)[8])[5584])[272])[112])[c5_i63];
  }

  c5_r0.status.vehicleIdent.vehicleType = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[272])[116];
  c5_r0.status.vehicleIdent.vehicleClass.vGroup = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleClass *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[272])[120])[0];
  c5_r0.status.vehicleIdent.vehicleClass.rGroup = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleClass *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[272])[120])[4];
  c5_r0.status.vehicleIdent.vehicleClass.rEquip = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleClass *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[272])[120])[8];
  for (c5_i64 = 0; c5_i64 < 16; c5_i64++) {
    c5_r0.status.j1939data.tires[c5_i64].location = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_y)[8])[5584])[408])[0])[32 * (int32_T)c5_i64])
      [0];
    c5_r0.status.j1939data.tires[c5_i64].pressure = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_y)[8])[5584])[408])[0])[32 * (int32_T)c5_i64])
      [4];
    c5_r0.status.j1939data.tires[c5_i64].temp = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_y)[8])[5584])[408])[0])[32 * (int32_T)c5_i64])
      [8];
    c5_r0.status.j1939data.tires[c5_i64].wheelSensorStatus = *(int32_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
           [5584])[408])[0])[32 * (int32_T)c5_i64])[12];
    c5_r0.status.j1939data.tires[c5_i64].wheelEndElectFault = *(int32_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
           [5584])[408])[0])[32 * (int32_T)c5_i64])[16];
    c5_r0.status.j1939data.tires[c5_i64].leakageRate = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_y)[8])[5584])[408])[0])[32 * (int32_T)c5_i64])
      [20];
    c5_r0.status.j1939data.tires[c5_i64].detection = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_y)[8])[5584])[408])[0])[32 * (int32_T)c5_i64])
      [24];
  }

  for (c5_i65 = 0; c5_i65 < 16; c5_i65++) {
    c5_r0.status.j1939data.axle[c5_i65].location = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_axle *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_axle *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_y)[8])[5584])[408])[512])[8 * (int32_T)
      c5_i65])[0];
    c5_r0.status.j1939data.axle[c5_i65].weight = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_axle *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_axle *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_y)[8])[5584])[408])[512])[8 * (int32_T)
      c5_i65])[4];
  }

  c5_r0.status.j1939data.trailerWeight = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)
        [8])[5584])[408])[640];
  c5_r0.status.j1939data.cargoWeight = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)
        [8])[5584])[408])[644];
  c5_r0.status.j1939data.steeringAxleTemperature = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)
        [8])[5584])[408])[648];
  c5_r0.status.j1939data.driveAxleLocation = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)
        [8])[5584])[408])[652];
  c5_r0.status.j1939data.driveAxleLiftAirPressure = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)
        [8])[5584])[408])[656];
  c5_r0.status.j1939data.driveAxleTemperature = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)
        [8])[5584])[408])[660];
  c5_r0.status.j1939data.driveAxleLubePressure = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)
        [8])[5584])[408])[664];
  c5_r0.status.j1939data.steeringAxleLubePressure = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)
        [8])[5584])[408])[668];
  c5_r0.status.weatherReport.isRaining = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[1080])[0];
  c5_r0.status.weatherReport.rainRate = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[1080])[4];
  c5_r0.status.weatherReport.precipSituation = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[1080])[8];
  c5_r0.status.weatherReport.solarRadiation = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[1080])[12];
  c5_r0.status.weatherReport.friction = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[1080])[16];
  c5_r0.status.gpsStatus = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)
        [8])[5584])[1104];
  sf_mex_setfieldbynum(c5_c_y, 0, "DATA", c5_d_emlrt_marshallOut(chartInstance,
    &c5_r0), 1);
  sf_mex_setcell(c5_b_y, 0, c5_c_y);
  c5_hoistedGlobal = chartInstance->c5_is_active_c5_Jan22_DLforACC_cs;
  c5_f_y = NULL;
  sf_mex_assign(&c5_f_y, sf_mex_create("y", &c5_hoistedGlobal, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c5_b_y, 1, c5_f_y);
  sf_mex_assign(&c5_st, c5_b_y, false);
  return c5_st;
}

static void set_sim_state_c5_Jan22_DLforACC_cs
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_st)
{
  const mxArray *c5_b_u;
  PRESCAN_V2X_FIXED_BSM_MESSAGE c5_r1;
  int32_T c5_i66;
  int32_T c5_i67;
  int32_T c5_i68;
  int32_T c5_i69;
  int32_T c5_i70;
  int32_T c5_i71;
  int32_T c5_i72;
  int32_T c5_i73;
  int32_T c5_i74;
  int32_T c5_i75;
  int32_T c5_i76;
  int32_T c5_i77;
  int32_T c5_i78;
  int32_T c5_i79;
  int32_T c5_i80;
  int32_T c5_i81;
  int32_T c5_i82;
  int32_T c5_i83;
  int32_T c5_i84;
  int32_T c5_i85;
  int32_T c5_i86;
  int32_T c5_i87;
  int32_T c5_i88;
  int32_T c5_i89;
  int32_T c5_i90;
  int32_T c5_i91;
  int32_T c5_i92;
  int32_T c5_i93;
  int32_T c5_i94;
  int32_T c5_i95;
  int32_T c5_i96;
  int32_T c5_i97;
  int32_T c5_i98;
  int32_T c5_i99;
  int32_T c5_i100;
  int32_T c5_i101;
  int32_T c5_i102;
  int32_T c5_i103;
  int32_T c5_i104;
  int32_T c5_i105;
  int32_T c5_i106;
  int32_T c5_i107;
  int32_T c5_i108;
  int32_T c5_i109;
  int32_T c5_i110;
  int32_T c5_i111;
  int32_T c5_i112;
  int32_T c5_i113;
  int32_T c5_i114;
  int32_T c5_i115;
  int32_T c5_i116;
  int32_T c5_i117;
  int32_T c5_i118;
  int32_T c5_i119;
  int32_T c5_i120;
  int32_T c5_i121;
  int32_T c5_i122;
  int32_T c5_i123;
  int32_T c5_i124;
  int32_T c5_i125;
  int32_T c5_i126;
  int32_T c5_i127;
  int32_T c5_i128;
  int32_T c5_i129;
  int32_T c5_i130;
  int32_T c5_i131;
  chartInstance->c5_doneDoubleBufferReInit = true;
  c5_b_u = sf_mex_dup(c5_st);
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_b_u, 0)),
                        "y", &c5_r1);
  *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)chartInstance->c5_y)[0])
    [0] = c5_r1.HEADER.valid;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    chartInstance->c5_y)[8])[0] = c5_r1.DATA.msgID;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    chartInstance->c5_y)[8])[4] = c5_r1.DATA.msgCnt;
  for (c5_i66 = 0; c5_i66 < 4; c5_i66++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
       chartInstance->c5_y)[8])[8])[c5_i66] = c5_r1.DATA.id[c5_i66];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    chartInstance->c5_y)[8])[12] = c5_r1.DATA.secMark;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    chartInstance->c5_y)[8])[16] = c5_r1.DATA.latitude;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    chartInstance->c5_y)[8])[20] = c5_r1.DATA.longitude;
  for (c5_i67 = 0; c5_i67 < 2; c5_i67++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
       chartInstance->c5_y)[8])[24])[c5_i67] = c5_r1.DATA.elev[c5_i67];
  }

  for (c5_i68 = 0; c5_i68 < 4; c5_i68++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
       chartInstance->c5_y)[8])[26])[c5_i68] = c5_r1.DATA.accuracy[c5_i68];
  }

  for (c5_i69 = 0; c5_i69 < 2; c5_i69++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
       chartInstance->c5_y)[8])[30])[c5_i69] = c5_r1.DATA.speed[c5_i69];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    chartInstance->c5_y)[8])[32] = c5_r1.DATA.heading;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    chartInstance->c5_y)[8])[36] = c5_r1.DATA.angle;
  for (c5_i70 = 0; c5_i70 < 7; c5_i70++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
       chartInstance->c5_y)[8])[37])[c5_i70] = c5_r1.DATA.accelSet[c5_i70];
  }

  for (c5_i71 = 0; c5_i71 < 2; c5_i71++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
       chartInstance->c5_y)[8])[44])[c5_i71] = c5_r1.DATA.brakes[c5_i71];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_size *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[48])[0] =
    c5_r1.DATA.size.width;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_size *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[48])[4] =
    c5_r1.DATA.size.length;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])[0] =
    c5_r1.DATA.safetyExt.events;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[8])[0])[0])[0] =
    c5_r1.DATA.safetyExt.pathHistory.initialPosition.utcTime.year;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[8])[0])[0])[4] =
    c5_r1.DATA.safetyExt.pathHistory.initialPosition.utcTime.month;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[8])[0])[0])[8] =
    c5_r1.DATA.safetyExt.pathHistory.initialPosition.utcTime.day;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[8])[0])[0])[12] =
    c5_r1.DATA.safetyExt.pathHistory.initialPosition.utcTime.hour;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[8])[0])[0])[16] =
    c5_r1.DATA.safetyExt.pathHistory.initialPosition.utcTime.minute;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[8])[0])[0])[20] =
    c5_r1.DATA.safetyExt.pathHistory.initialPosition.utcTime.second;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[8])[0])[24] =
    c5_r1.DATA.safetyExt.pathHistory.initialPosition.longitude;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[8])[0])[28] =
    c5_r1.DATA.safetyExt.pathHistory.initialPosition.latitude;
  for (c5_i72 = 0; c5_i72 < 2; c5_i72++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
       [8])[0])[32])[c5_i72] =
      c5_r1.DATA.safetyExt.pathHistory.initialPosition.elevation[c5_i72];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[8])[0])[36] =
    c5_r1.DATA.safetyExt.pathHistory.initialPosition.heading;
  for (c5_i73 = 0; c5_i73 < 2; c5_i73++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
       [8])[0])[40])[c5_i73] =
      c5_r1.DATA.safetyExt.pathHistory.initialPosition.speed[c5_i73];
  }

  for (c5_i74 = 0; c5_i74 < 4; c5_i74++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
       [8])[0])[42])[c5_i74] =
      c5_r1.DATA.safetyExt.pathHistory.initialPosition.posAccuracy[c5_i74];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[8])[0])[48] =
    c5_r1.DATA.safetyExt.pathHistory.initialPosition.timeConfidence;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[8])[0])[52] =
    c5_r1.DATA.safetyExt.pathHistory.initialPosition.posConfidence;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[8])[0])[53] =
    c5_r1.DATA.safetyExt.pathHistory.initialPosition.speedConfidence;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[8])[56] =
    c5_r1.DATA.safetyExt.pathHistory.currGPSstatus;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[8])[60] =
    c5_r1.DATA.safetyExt.pathHistory.itemCnt;
  for (c5_i75 = 0; c5_i75 < 23; c5_i75++) {
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                  &((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                    &((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[8])[64])[0])[32 * (int32_T)
                  c5_i75])[0] =
      c5_r1.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c5_i75]
      .latOffset;
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                  &((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                    &((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[8])[64])[0])[32 * (int32_T)
                  c5_i75])[4] =
      c5_r1.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c5_i75]
      .longOffset;
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                  &((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                    &((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[8])[64])[0])[32 * (int32_T)
                  c5_i75])[8] =
      c5_r1.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c5_i75]
      .elevationOffset;
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                  &((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                    &((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[8])[64])[0])[32 * (int32_T)
                  c5_i75])[12] =
      c5_r1.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c5_i75]
      .timeOffset;
    for (c5_i78 = 0; c5_i78 < 4; c5_i78++) {
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                   &((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                     &((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
            [56])[8])[64])[0])[32 * (int32_T)c5_i75])[16])[c5_i78] =
        c5_r1.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c5_i75]
        .posAccuracy[c5_i78];
    }

    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                  &((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                    &((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[8])[64])[0])[32 * (int32_T)
                  c5_i75])[20] =
      c5_r1.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c5_i75]
      .heading;
    for (c5_i80 = 0; c5_i80 < 2; c5_i80++) {
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                   &((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                     &((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
            [56])[8])[64])[0])[32 * (int32_T)c5_i75])[24])[c5_i80] =
        c5_r1.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c5_i75]
        .speed[c5_i80];
    }
  }

  for (c5_i76 = 0; c5_i76 < 345; c5_i76++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
       [8])[64])[736])[c5_i76] =
      c5_r1.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_02[c5_i76];
  }

  for (c5_i77 = 0; c5_i77 < 276; c5_i77++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
       [8])[64])[1081])[c5_i77] =
      c5_r1.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_03[c5_i77];
  }

  for (c5_i79 = 0; c5_i79 < 184; c5_i79++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
       [8])[64])[1357])[c5_i79] =
      c5_r1.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_04[c5_i79];
  }

  for (c5_i81 = 0; c5_i81 < 230; c5_i81++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
       [8])[64])[1541])[c5_i81] =
      c5_r1.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_05[c5_i81];
  }

  for (c5_i82 = 0; c5_i82 < 138; c5_i82++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
       [8])[64])[1771])[c5_i82] =
      c5_r1.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_06[c5_i82];
  }

  for (c5_i83 = 0; c5_i83 < 242; c5_i83++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
       [8])[64])[1909])[c5_i83] =
      c5_r1.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_07[c5_i83];
  }

  for (c5_i84 = 0; c5_i84 < 161; c5_i84++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
       [8])[64])[2151])[c5_i84] =
      c5_r1.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_08[c5_i84];
  }

  for (c5_i85 = 0; c5_i85 < 196; c5_i85++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
       [8])[64])[2312])[c5_i85] =
      c5_r1.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_09[c5_i85];
  }

  for (c5_i86 = 0; c5_i86 < 104; c5_i86++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
       [8])[64])[2508])[c5_i86] =
      c5_r1.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_10[c5_i86];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathPrediction *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2688])[0] =
    c5_r1.DATA.safetyExt.pathPrediction.radiusOfCurve;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathPrediction *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2688])[4] =
    c5_r1.DATA.safetyExt.pathPrediction.confidence;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2696])[0])[0])[0] =
    c5_r1.DATA.safetyExt.theRTCM.anchorPoint.utcTime.year;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2696])[0])[0])[4] =
    c5_r1.DATA.safetyExt.theRTCM.anchorPoint.utcTime.month;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2696])[0])[0])[8] =
    c5_r1.DATA.safetyExt.theRTCM.anchorPoint.utcTime.day;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2696])[0])[0])[12] =
    c5_r1.DATA.safetyExt.theRTCM.anchorPoint.utcTime.hour;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2696])[0])[0])[16] =
    c5_r1.DATA.safetyExt.theRTCM.anchorPoint.utcTime.minute;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2696])[0])[0])[20] =
    c5_r1.DATA.safetyExt.theRTCM.anchorPoint.utcTime.second;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2696])[0])[24] =
    c5_r1.DATA.safetyExt.theRTCM.anchorPoint.longitude;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2696])[0])[28] =
    c5_r1.DATA.safetyExt.theRTCM.anchorPoint.latitude;
  for (c5_i87 = 0; c5_i87 < 2; c5_i87++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
       [2696])[0])[32])[c5_i87] =
      c5_r1.DATA.safetyExt.theRTCM.anchorPoint.elevation[c5_i87];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2696])[0])[36] =
    c5_r1.DATA.safetyExt.theRTCM.anchorPoint.heading;
  for (c5_i88 = 0; c5_i88 < 2; c5_i88++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
       [2696])[0])[40])[c5_i88] =
      c5_r1.DATA.safetyExt.theRTCM.anchorPoint.speed[c5_i88];
  }

  for (c5_i89 = 0; c5_i89 < 4; c5_i89++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
       [2696])[0])[42])[c5_i89] =
      c5_r1.DATA.safetyExt.theRTCM.anchorPoint.posAccuracy[c5_i89];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2696])[0])[48] =
    c5_r1.DATA.safetyExt.theRTCM.anchorPoint.timeConfidence;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2696])[0])[52] =
    c5_r1.DATA.safetyExt.theRTCM.anchorPoint.posConfidence;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2696])[0])[53] =
    c5_r1.DATA.safetyExt.theRTCM.anchorPoint.speedConfidence;
  for (c5_i90 = 0; c5_i90 < 5; c5_i90++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[56])[c5_i90] =
      c5_r1.DATA.safetyExt.theRTCM.rtcmHeader[c5_i90];
  }

  for (c5_i91 = 0; c5_i91 < 124; c5_i91++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[61])[c5_i91] =
      c5_r1.DATA.safetyExt.theRTCM.msg1001[c5_i91];
  }

  for (c5_i92 = 0; c5_i92 < 156; c5_i92++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[185])[c5_i92] =
      c5_r1.DATA.safetyExt.theRTCM.msg1002[c5_i92];
  }

  for (c5_i93 = 0; c5_i93 < 210; c5_i93++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[341])[c5_i93] =
      c5_r1.DATA.safetyExt.theRTCM.msg1003[c5_i93];
  }

  for (c5_i94 = 0; c5_i94 < 258; c5_i94++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[551])[c5_i94] =
      c5_r1.DATA.safetyExt.theRTCM.msg1004[c5_i94];
  }

  for (c5_i95 = 0; c5_i95 < 19; c5_i95++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[809])[c5_i95] =
      c5_r1.DATA.safetyExt.theRTCM.msg1005[c5_i95];
  }

  for (c5_i96 = 0; c5_i96 < 21; c5_i96++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[828])[c5_i96] =
      c5_r1.DATA.safetyExt.theRTCM.msg1006[c5_i96];
  }

  for (c5_i97 = 0; c5_i97 < 36; c5_i97++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[849])[c5_i97] =
      c5_r1.DATA.safetyExt.theRTCM.msg1007[c5_i97];
  }

  for (c5_i98 = 0; c5_i98 < 68; c5_i98++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[885])[c5_i98] =
      c5_r1.DATA.safetyExt.theRTCM.msg1008[c5_i98];
  }

  for (c5_i99 = 0; c5_i99 < 136; c5_i99++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[953])[c5_i99] =
      c5_r1.DATA.safetyExt.theRTCM.msg1009[c5_i99];
  }

  for (c5_i100 = 0; c5_i100 < 166; c5_i100++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[1089])[c5_i100] =
      c5_r1.DATA.safetyExt.theRTCM.msg1010[c5_i100];
  }

  for (c5_i101 = 0; c5_i101 < 222; c5_i101++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[1255])[c5_i101] =
      c5_r1.DATA.safetyExt.theRTCM.msg1011[c5_i101];
  }

  for (c5_i102 = 0; c5_i102 < 268; c5_i102++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[1477])[c5_i102] =
      c5_r1.DATA.safetyExt.theRTCM.msg1012[c5_i102];
  }

  for (c5_i103 = 0; c5_i103 < 27; c5_i103++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[1745])[c5_i103] =
      c5_r1.DATA.safetyExt.theRTCM.msg1013[c5_i103];
  }

  for (c5_i104 = 0; c5_i104 < 15; c5_i104++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[1772])[c5_i104] =
      c5_r1.DATA.safetyExt.theRTCM.msg1014[c5_i104];
  }

  for (c5_i105 = 0; c5_i105 < 69; c5_i105++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[1787])[c5_i105] =
      c5_r1.DATA.safetyExt.theRTCM.msg1015[c5_i105];
  }

  for (c5_i106 = 0; c5_i106 < 81; c5_i106++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[1856])[c5_i106] =
      c5_r1.DATA.safetyExt.theRTCM.msg1016[c5_i106];
  }

  for (c5_i107 = 0; c5_i107 < 115; c5_i107++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[1937])[c5_i107] =
      c5_r1.DATA.safetyExt.theRTCM.msg1017[c5_i107];
  }

  for (c5_i108 = 0; c5_i108 < 62; c5_i108++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[2052])[c5_i108] =
      c5_r1.DATA.safetyExt.theRTCM.msg1019[c5_i108];
  }

  for (c5_i109 = 0; c5_i109 < 45; c5_i109++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[2114])[c5_i109] =
      c5_r1.DATA.safetyExt.theRTCM.msg1020[c5_i109];
  }

  for (c5_i110 = 0; c5_i110 < 62; c5_i110++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[2159])[c5_i110] =
      c5_r1.DATA.safetyExt.theRTCM.msg1021[c5_i110];
  }

  for (c5_i111 = 0; c5_i111 < 75; c5_i111++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[2221])[c5_i111] =
      c5_r1.DATA.safetyExt.theRTCM.msg1022[c5_i111];
  }

  for (c5_i112 = 0; c5_i112 < 73; c5_i112++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[2296])[c5_i112] =
      c5_r1.DATA.safetyExt.theRTCM.msg1023[c5_i112];
  }

  for (c5_i113 = 0; c5_i113 < 74; c5_i113++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[2369])[c5_i113] =
      c5_r1.DATA.safetyExt.theRTCM.msg1024[c5_i113];
  }

  for (c5_i114 = 0; c5_i114 < 25; c5_i114++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[2443])[c5_i114] =
      c5_r1.DATA.safetyExt.theRTCM.msg1025[c5_i114];
  }

  for (c5_i115 = 0; c5_i115 < 30; c5_i115++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[2468])[c5_i115] =
      c5_r1.DATA.safetyExt.theRTCM.msg1026[c5_i115];
  }

  for (c5_i116 = 0; c5_i116 < 33; c5_i116++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[2498])[c5_i116] =
      c5_r1.DATA.safetyExt.theRTCM.msg1027[c5_i116];
  }

  for (c5_i117 = 0; c5_i117 < 69; c5_i117++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[2531])[c5_i117] =
      c5_r1.DATA.safetyExt.theRTCM.msg1029[c5_i117];
  }

  for (c5_i118 = 0; c5_i118 < 105; c5_i118++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[2600])[c5_i118] =
      c5_r1.DATA.safetyExt.theRTCM.msg1030[c5_i118];
  }

  for (c5_i119 = 0; c5_i119 < 107; c5_i119++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[2705])[c5_i119] =
      c5_r1.DATA.safetyExt.theRTCM.msg1031[c5_i119];
  }

  for (c5_i120 = 0; c5_i120 < 20; c5_i120++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[2812])[c5_i120] =
      c5_r1.DATA.safetyExt.theRTCM.msg1032[c5_i120];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])[0]
    = c5_r1.DATA.status.lights;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])[4]
    = c5_r1.DATA.status.lightBar;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[8])[0] =
    c5_r1.DATA.status.wipers.statusFront;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[8])[4] =
    c5_r1.DATA.status.wipers.rateFront;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[8])[8] =
    c5_r1.DATA.status.wipers.statusRear;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[8])[12] =
    c5_r1.DATA.status.wipers.rateRear;
  for (c5_i121 = 0; c5_i121 < 2; c5_i121++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])
      [24])[c5_i121] = c5_r1.DATA.status.brakeStatus[c5_i121];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])[28]
    = c5_r1.DATA.status.brakePressure;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])[32]
    = c5_r1.DATA.status.roadFriction;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])[36]
    = c5_r1.DATA.status.sunData;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])[40]
    = c5_r1.DATA.status.rainData;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])[44]
    = c5_r1.DATA.status.airTemp;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])[48]
    = c5_r1.DATA.status.airPres;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[56])[0] =
    c5_r1.DATA.status.steering.angle;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[56])[4] =
    c5_r1.DATA.status.steering.confidence;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[56])[8] =
    c5_r1.DATA.status.steering.rate;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[56])[12] =
    c5_r1.DATA.status.steering.wheels;
  for (c5_i122 = 0; c5_i122 < 7; c5_i122++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
        &((char_T *)chartInstance->c5_y)[8])[5584])[72])[0])[c5_i122] =
      c5_r1.DATA.status.accelSets.accel4way[c5_i122];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[72])[8] =
    c5_r1.DATA.status.accelSets.vertAccelThres;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[72])[12] =
    c5_r1.DATA.status.accelSets.yawRateCon;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[72])[16] =
    c5_r1.DATA.status.accelSets.hozAccelCon;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelConfidence *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)
        [8])[5584])[72])[24])[0])[0] =
    c5_r1.DATA.status.accelSets.confidenceSet.accelConfidence.yawRate;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelConfidence *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)
        [8])[5584])[72])[24])[0])[4] =
    c5_r1.DATA.status.accelSets.confidenceSet.accelConfidence.acceleration;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelConfidence *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)
        [8])[5584])[72])[24])[0])[8] =
    c5_r1.DATA.status.accelSets.confidenceSet.accelConfidence.steeringWheelAngle;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)
        [8])[5584])[72])[24])[16] =
    c5_r1.DATA.status.accelSets.confidenceSet.speedConfidence;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)
        [8])[5584])[72])[24])[20] =
    c5_r1.DATA.status.accelSets.confidenceSet.timeConfidence;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)
        [8])[5584])[72])[24])[24] =
    c5_r1.DATA.status.accelSets.confidenceSet.posConfidence;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)
        [8])[5584])[72])[24])[28] =
    c5_r1.DATA.status.accelSets.confidenceSet.steerConfidence;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)
        [8])[5584])[72])[24])[32] =
    c5_r1.DATA.status.accelSets.confidenceSet.throttleConfidence;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[136])[0] =
    c5_r1.DATA.status.object.obDist;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[136])[4] =
    c5_r1.DATA.status.object.obDirect;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[136])[8])[0] = c5_r1.DATA.status.object.dateTime.year;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[136])[8])[4] = c5_r1.DATA.status.object.dateTime.month;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[136])[8])[8] = c5_r1.DATA.status.object.dateTime.day;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[136])[8])[12] = c5_r1.DATA.status.object.dateTime.hour;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[136])[8])[16] = c5_r1.DATA.status.object.dateTime.minute;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[136])[8])[20] = c5_r1.DATA.status.object.dateTime.second;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[168])[0])[0] = c5_r1.DATA.status.fullPos.utcTime.year;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[168])[0])[4] = c5_r1.DATA.status.fullPos.utcTime.month;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[168])[0])[8] = c5_r1.DATA.status.fullPos.utcTime.day;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[168])[0])[12] = c5_r1.DATA.status.fullPos.utcTime.hour;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[168])[0])[16] = c5_r1.DATA.status.fullPos.utcTime.minute;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[168])[0])[20] = c5_r1.DATA.status.fullPos.utcTime.second;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[168])[24] =
    c5_r1.DATA.status.fullPos.longitude;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[168])[28] =
    c5_r1.DATA.status.fullPos.latitude;
  for (c5_i123 = 0; c5_i123 < 2; c5_i123++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
        &((char_T *)chartInstance->c5_y)[8])[5584])[168])[32])[c5_i123] =
      c5_r1.DATA.status.fullPos.elevation[c5_i123];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[168])[36] =
    c5_r1.DATA.status.fullPos.heading;
  for (c5_i124 = 0; c5_i124 < 2; c5_i124++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
        &((char_T *)chartInstance->c5_y)[8])[5584])[168])[40])[c5_i124] =
      c5_r1.DATA.status.fullPos.speed[c5_i124];
  }

  for (c5_i125 = 0; c5_i125 < 4; c5_i125++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
        &((char_T *)chartInstance->c5_y)[8])[5584])[168])[42])[c5_i125] =
      c5_r1.DATA.status.fullPos.posAccuracy[c5_i125];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[168])[48] =
    c5_r1.DATA.status.fullPos.timeConfidence;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[168])[52] =
    c5_r1.DATA.status.fullPos.posConfidence;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[168])[53] =
    c5_r1.DATA.status.fullPos.speedConfidence;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])
    [224] = c5_r1.DATA.status.throttlePos;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])
    [228] = c5_r1.DATA.status.speedHeadC;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])
    [232] = c5_r1.DATA.status.speedC;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[240])[0] =
    c5_r1.DATA.status.vehicleData.height;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_bumpers *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[240])[8])[0] =
    c5_r1.DATA.status.vehicleData.bumpers.frnt;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_bumpers *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[240])[8])[4] =
    c5_r1.DATA.status.vehicleData.bumpers.rear;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[240])[16] =
    c5_r1.DATA.status.vehicleData.mass;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[240])[20] =
    c5_r1.DATA.status.vehicleData.trailerWeight;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[240])[24] =
    c5_r1.DATA.status.vehicleData.type;
  for (c5_i126 = 0; c5_i126 < 63; c5_i126++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
        &((char_T *)chartInstance->c5_y)[8])[5584])[272])[0])[c5_i126] =
      c5_r1.DATA.status.vehicleIdent.name[c5_i126];
  }

  for (c5_i127 = 0; c5_i127 < 17; c5_i127++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
        &((char_T *)chartInstance->c5_y)[8])[5584])[272])[63])[c5_i127] =
      c5_r1.DATA.status.vehicleIdent.vin[c5_i127];
  }

  for (c5_i128 = 0; c5_i128 < 32; c5_i128++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
        &((char_T *)chartInstance->c5_y)[8])[5584])[272])[80])[c5_i128] =
      c5_r1.DATA.status.vehicleIdent.ownerCode[c5_i128];
  }

  for (c5_i129 = 0; c5_i129 < 4; c5_i129++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
        &((char_T *)chartInstance->c5_y)[8])[5584])[272])[112])[c5_i129] =
      c5_r1.DATA.status.vehicleIdent.id[c5_i129];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[272])[116] =
    c5_r1.DATA.status.vehicleIdent.vehicleType;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleClass *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[272])[120])[0] =
    c5_r1.DATA.status.vehicleIdent.vehicleClass.vGroup;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleClass *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[272])[120])[4] =
    c5_r1.DATA.status.vehicleIdent.vehicleClass.rGroup;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleClass *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[272])[120])[8] =
    c5_r1.DATA.status.vehicleIdent.vehicleClass.rEquip;
  for (c5_i130 = 0; c5_i130 < 16; c5_i130++) {
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_y)[8])[5584])[408])[0])[32 * (int32_T)
                  c5_i130])[0] = c5_r1.DATA.status.j1939data.tires[c5_i130].
      location;
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_y)[8])[5584])[408])[0])[32 * (int32_T)
                  c5_i130])[4] = c5_r1.DATA.status.j1939data.tires[c5_i130].
      pressure;
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_y)[8])[5584])[408])[0])[32 * (int32_T)
                  c5_i130])[8] = c5_r1.DATA.status.j1939data.tires[c5_i130].temp;
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_y)[8])[5584])[408])[0])[32 * (int32_T)
                  c5_i130])[12] = c5_r1.DATA.status.j1939data.tires[c5_i130].
      wheelSensorStatus;
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_y)[8])[5584])[408])[0])[32 * (int32_T)
                  c5_i130])[16] = c5_r1.DATA.status.j1939data.tires[c5_i130].
      wheelEndElectFault;
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_y)[8])[5584])[408])[0])[32 * (int32_T)
                  c5_i130])[20] = c5_r1.DATA.status.j1939data.tires[c5_i130].
      leakageRate;
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_y)[8])[5584])[408])[0])[32 * (int32_T)
                  c5_i130])[24] = c5_r1.DATA.status.j1939data.tires[c5_i130].
      detection;
  }

  for (c5_i131 = 0; c5_i131 < 16; c5_i131++) {
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_axle *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_axle *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])
      [408])[512])[8 * (int32_T)c5_i131])[0] =
      c5_r1.DATA.status.j1939data.axle[c5_i131].location;
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_axle *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_axle *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])
      [408])[512])[8 * (int32_T)c5_i131])[4] =
      c5_r1.DATA.status.j1939data.axle[c5_i131].weight;
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[408])[640] =
    c5_r1.DATA.status.j1939data.trailerWeight;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[408])[644] =
    c5_r1.DATA.status.j1939data.cargoWeight;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[408])[648] =
    c5_r1.DATA.status.j1939data.steeringAxleTemperature;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[408])[652] =
    c5_r1.DATA.status.j1939data.driveAxleLocation;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[408])[656] =
    c5_r1.DATA.status.j1939data.driveAxleLiftAirPressure;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[408])[660] =
    c5_r1.DATA.status.j1939data.driveAxleTemperature;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[408])[664] =
    c5_r1.DATA.status.j1939data.driveAxleLubePressure;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[408])[668] =
    c5_r1.DATA.status.j1939data.steeringAxleLubePressure;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[1080])[0] =
    c5_r1.DATA.status.weatherReport.isRaining;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[1080])[4] =
    c5_r1.DATA.status.weatherReport.rainRate;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[1080])[8] =
    c5_r1.DATA.status.weatherReport.precipSituation;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[1080])[12] =
    c5_r1.DATA.status.weatherReport.solarRadiation;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[1080])[16] =
    c5_r1.DATA.status.weatherReport.friction;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])
    [1104] = c5_r1.DATA.status.gpsStatus;
  chartInstance->c5_is_active_c5_Jan22_DLforACC_cs = c5_hd_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c5_b_u, 1)),
     "is_active_c5_Jan22_DLforACC_cs");
  sf_mex_destroy(&c5_b_u);
  c5_update_debugger_state_c5_Jan22_DLforACC_cs(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_Jan22_DLforACC_cs(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c5_RuntimeVar);
}

static void sf_gateway_c5_Jan22_DLforACC_cs(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance)
{
  c5_PRESCAN_V2X_USER_BSM_MESSAGE c5_b_u;
  int32_T c5_i132;
  int32_T c5_i133;
  int32_T c5_i134;
  int32_T c5_i135;
  int32_T c5_i136;
  int32_T c5_i137;
  PRESCAN_V2X_FIXED_BSM_MESSAGE c5_b_z;
  int32_T c5_i138;
  int32_T c5_i139;
  int32_T c5_i140;
  int32_T c5_i141;
  int32_T c5_i142;
  int32_T c5_i143;
  int32_T c5_i144;
  int32_T c5_i145;
  int32_T c5_i146;
  int32_T c5_i147;
  int32_T c5_i148;
  int32_T c5_i149;
  int32_T c5_i150;
  int32_T c5_i151;
  int32_T c5_i152;
  int32_T c5_i153;
  int32_T c5_i154;
  int32_T c5_i155;
  int32_T c5_i156;
  int32_T c5_i157;
  int32_T c5_i158;
  int32_T c5_i159;
  int32_T c5_i160;
  int32_T c5_i161;
  int32_T c5_i162;
  int32_T c5_i163;
  int32_T c5_i164;
  int32_T c5_i165;
  int32_T c5_i166;
  int32_T c5_i167;
  int32_T c5_i168;
  int32_T c5_i169;
  int32_T c5_i170;
  int32_T c5_i171;
  int32_T c5_i172;
  int32_T c5_i173;
  int32_T c5_i174;
  int32_T c5_i175;
  int32_T c5_i176;
  int32_T c5_i177;
  int32_T c5_i178;
  int32_T c5_i179;
  int32_T c5_i180;
  int32_T c5_i181;
  int32_T c5_i182;
  int32_T c5_i183;
  int32_T c5_i184;
  int32_T c5_i185;
  int32_T c5_i186;
  int32_T c5_i187;
  int32_T c5_i188;
  int32_T c5_i189;
  int32_T c5_i190;
  int32_T c5_i191;
  int32_T c5_i192;
  int32_T c5_i193;
  int32_T c5_i194;
  int32_T c5_i195;
  int32_T c5_i196;
  int32_T c5_i197;
  int32_T c5_i198;
  int32_T c5_i199;
  int32_T c5_i200;
  int32_T c5_i201;
  int32_T c5_i202;
  int32_T c5_i203;
  uint32_T c5_debug_family_var_map[5];
  real_T c5_nargin = 2.0;
  real_T c5_nargout = 1.0;
  PRESCAN_V2X_FIXED_BSM_MESSAGE c5_b_y;
  c5_PRESCAN_V2X_USER_BSM_MESSAGE c5_c_y;
  PRESCAN_V2X_FIXED_BSM_MESSAGE c5_c_z;
  uint32_T c5_b_debug_family_var_map[5];
  real_T c5_b_nargin = 2.0;
  real_T c5_b_nargout = 1.0;
  PRESCAN_V2X_FIXED_BSM_MESSAGE c5_c_u;
  c5_PRESCAN_V2X_USER_BSM_MESSAGE c5_d_y;
  uint32_T c5_c_debug_family_var_map[4];
  real_T c5_c_nargin = 2.0;
  real_T c5_c_nargout = 1.0;
  PRESCAN_HEADER c5_d_u;
  PRESCAN_HEADER c5_e_y;
  uint32_T c5_d_debug_family_var_map[4];
  real_T c5_d_nargin = 2.0;
  real_T c5_d_nargout = 1.0;
  PRESCAN_V2X_FIXED_BSM_DATA c5_e_u;
  c5_PRESCAN_V2X_USER_BSM_DATA c5_f_y;
  uint32_T c5_e_debug_family_var_map[4];
  real_T c5_e_nargin = 2.0;
  real_T c5_e_nargout = 1.0;
  int32_T c5_i204;
  int32_T c5_i205;
  int32_T c5_i206;
  int32_T c5_i207;
  int32_T c5_i208;
  int32_T c5_i209;
  PRESCAN_V2X_FIXED_BSM_size c5_f_u;
  c5_PRESCAN_V2X_USER_BSM_size c5_g_y;
  uint32_T c5_f_debug_family_var_map[4];
  real_T c5_f_nargin = 2.0;
  real_T c5_f_nargout = 1.0;
  int32_T c5_i210;
  int32_T c5_i211;
  int32_T c5_i212;
  int32_T c5_i213;
  int32_T c5_i214;
  int32_T c5_i215;
  int32_T c5_i216;
  int32_T c5_i217;
  int32_T c5_i218;
  int32_T c5_i219;
  int32_T c5_i220;
  int32_T c5_i221;
  int32_T c5_i222;
  int32_T c5_i223;
  int32_T c5_i224;
  int32_T c5_i225;
  int32_T c5_i226;
  int32_T c5_i227;
  int32_T c5_i228;
  int32_T c5_i229;
  int32_T c5_i230;
  int32_T c5_i231;
  int32_T c5_i232;
  int32_T c5_i233;
  int32_T c5_i234;
  int32_T c5_i235;
  int32_T c5_i236;
  int32_T c5_i237;
  int32_T c5_i238;
  int32_T c5_i239;
  int32_T c5_i240;
  int32_T c5_i241;
  int32_T c5_i242;
  int32_T c5_i243;
  int32_T c5_i244;
  int32_T c5_i245;
  int32_T c5_i246;
  int32_T c5_i247;
  int32_T c5_i248;
  int32_T c5_i249;
  int32_T c5_i250;
  int32_T c5_i251;
  int32_T c5_i252;
  int32_T c5_i253;
  int32_T c5_i254;
  int32_T c5_i255;
  int32_T c5_i256;
  int32_T c5_i257;
  int32_T c5_i258;
  int32_T c5_i259;
  int32_T c5_i260;
  int32_T c5_i261;
  int32_T c5_i262;
  int32_T c5_i263;
  int32_T c5_i264;
  int32_T c5_i265;
  int32_T c5_i266;
  int32_T c5_i267;
  int32_T c5_i268;
  int32_T c5_i269;
  int32_T c5_i270;
  int32_T c5_i271;
  int32_T c5_i272;
  int32_T c5_i273;
  int32_T c5_i274;
  int32_T c5_i275;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3, chartInstance->c5_sfEvent);
  chartInstance->c5_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c5_sfEvent);
  c5_b_u.HEADER.valid = *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)
    chartInstance->c5_u)[0])[0];
  c5_b_u.DATA.msgID = *(int32_T *)&((char_T *)(c5_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)chartInstance->c5_u)[8])[0];
  c5_b_u.DATA.msgCnt = *(int32_T *)&((char_T *)(c5_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)chartInstance->c5_u)[8])[4];
  for (c5_i132 = 0; c5_i132 < 4; c5_i132++) {
    c5_b_u.DATA.id[c5_i132] = ((int8_T *)&((char_T *)
      (c5_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)chartInstance->c5_u)[8])[8])
      [c5_i132];
  }

  c5_b_u.DATA.secMark = *(int32_T *)&((char_T *)(c5_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)chartInstance->c5_u)[8])[12];
  c5_b_u.DATA.latitude = *(int32_T *)&((char_T *)(c5_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)chartInstance->c5_u)[8])[16];
  c5_b_u.DATA.longitude = *(int32_T *)&((char_T *)(c5_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)chartInstance->c5_u)[8])[20];
  for (c5_i133 = 0; c5_i133 < 2; c5_i133++) {
    c5_b_u.DATA.elev[c5_i133] = ((int8_T *)&((char_T *)
      (c5_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)chartInstance->c5_u)[8])[24])
      [c5_i133];
  }

  for (c5_i134 = 0; c5_i134 < 4; c5_i134++) {
    c5_b_u.DATA.accuracy[c5_i134] = ((int8_T *)&((char_T *)
      (c5_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)chartInstance->c5_u)[8])[26])
      [c5_i134];
  }

  for (c5_i135 = 0; c5_i135 < 2; c5_i135++) {
    c5_b_u.DATA.speed[c5_i135] = ((int8_T *)&((char_T *)
      (c5_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)chartInstance->c5_u)[8])[30])
      [c5_i135];
  }

  c5_b_u.DATA.heading = *(int32_T *)&((char_T *)(c5_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)chartInstance->c5_u)[8])[32];
  c5_b_u.DATA.angle = *(int8_T *)&((char_T *)(c5_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)chartInstance->c5_u)[8])[36];
  for (c5_i136 = 0; c5_i136 < 7; c5_i136++) {
    c5_b_u.DATA.accelSet[c5_i136] = ((int8_T *)&((char_T *)
      (c5_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)chartInstance->c5_u)[8])[37])
      [c5_i136];
  }

  for (c5_i137 = 0; c5_i137 < 2; c5_i137++) {
    c5_b_u.DATA.brakes[c5_i137] = ((int8_T *)&((char_T *)
      (c5_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)chartInstance->c5_u)[8])[44])
      [c5_i137];
  }

  c5_b_u.DATA.size.width = *(int32_T *)&((char_T *)(c5_PRESCAN_V2X_USER_BSM_size
    *)&((char_T *)(c5_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
    chartInstance->c5_u)[8])[48])[0];
  c5_b_u.DATA.size.length = *(int32_T *)&((char_T *)
    (c5_PRESCAN_V2X_USER_BSM_size *)&((char_T *)(c5_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)chartInstance->c5_u)[8])[48])[4];
  c5_b_z.HEADER.valid = *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)
    chartInstance->c5_z)[0])[0];
  c5_b_z.DATA.msgID = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[0];
  c5_b_z.DATA.msgCnt = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[4];
  for (c5_i138 = 0; c5_i138 < 4; c5_i138++) {
    c5_b_z.DATA.id[c5_i138] = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[8])[c5_i138];
  }

  c5_b_z.DATA.secMark = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[12];
  c5_b_z.DATA.latitude = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[16];
  c5_b_z.DATA.longitude = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[20];
  for (c5_i139 = 0; c5_i139 < 2; c5_i139++) {
    c5_b_z.DATA.elev[c5_i139] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])[24])
      [c5_i139];
  }

  for (c5_i140 = 0; c5_i140 < 4; c5_i140++) {
    c5_b_z.DATA.accuracy[c5_i140] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])[26])
      [c5_i140];
  }

  for (c5_i141 = 0; c5_i141 < 2; c5_i141++) {
    c5_b_z.DATA.speed[c5_i141] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])[30])
      [c5_i141];
  }

  c5_b_z.DATA.heading = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[32];
  c5_b_z.DATA.angle = *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[36];
  for (c5_i142 = 0; c5_i142 < 7; c5_i142++) {
    c5_b_z.DATA.accelSet[c5_i142] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])[37])
      [c5_i142];
  }

  for (c5_i143 = 0; c5_i143 < 2; c5_i143++) {
    c5_b_z.DATA.brakes[c5_i143] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])[44])
      [c5_i143];
  }

  c5_b_z.DATA.size.width = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_size *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])
    [48])[0];
  c5_b_z.DATA.size.length = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_size *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])
    [48])[4];
  c5_b_z.DATA.safetyExt.events = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[56])[0];
  c5_b_z.DATA.safetyExt.pathHistory.initialPosition.utcTime.year = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])[56])
        [8])[0])[0])[0];
  c5_b_z.DATA.safetyExt.pathHistory.initialPosition.utcTime.month = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])[56])
        [8])[0])[0])[4];
  c5_b_z.DATA.safetyExt.pathHistory.initialPosition.utcTime.day = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])[56])
        [8])[0])[0])[8];
  c5_b_z.DATA.safetyExt.pathHistory.initialPosition.utcTime.hour = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])[56])
        [8])[0])[0])[12];
  c5_b_z.DATA.safetyExt.pathHistory.initialPosition.utcTime.minute = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])[56])
        [8])[0])[0])[16];
  c5_b_z.DATA.safetyExt.pathHistory.initialPosition.utcTime.second = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])[56])
        [8])[0])[0])[20];
  c5_b_z.DATA.safetyExt.pathHistory.initialPosition.longitude = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])[56])
       [8])[0])[24];
  c5_b_z.DATA.safetyExt.pathHistory.initialPosition.latitude = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])[56])
       [8])[0])[28];
  for (c5_i144 = 0; c5_i144 < 2; c5_i144++) {
    c5_b_z.DATA.safetyExt.pathHistory.initialPosition.elevation[c5_i144] =
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])[56])
         [8])[0])[32])[c5_i144];
  }

  c5_b_z.DATA.safetyExt.pathHistory.initialPosition.heading = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])[56])
       [8])[0])[36];
  for (c5_i145 = 0; c5_i145 < 2; c5_i145++) {
    c5_b_z.DATA.safetyExt.pathHistory.initialPosition.speed[c5_i145] = ((int8_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[56])[8])[0])[40])[c5_i145];
  }

  for (c5_i146 = 0; c5_i146 < 4; c5_i146++) {
    c5_b_z.DATA.safetyExt.pathHistory.initialPosition.posAccuracy[c5_i146] =
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])[56])
         [8])[0])[42])[c5_i146];
  }

  c5_b_z.DATA.safetyExt.pathHistory.initialPosition.timeConfidence = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])[56])
       [8])[0])[48];
  c5_b_z.DATA.safetyExt.pathHistory.initialPosition.posConfidence = *(int8_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])[56])
       [8])[0])[52];
  c5_b_z.DATA.safetyExt.pathHistory.initialPosition.speedConfidence = *(int8_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])[56])
       [8])[0])[53];
  c5_b_z.DATA.safetyExt.pathHistory.currGPSstatus = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[56])[8])[56];
  c5_b_z.DATA.safetyExt.pathHistory.itemCnt = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[56])[8])[60];
  for (c5_i147 = 0; c5_i147 < 23; c5_i147++) {
    c5_b_z.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c5_i147]
      .latOffset = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[56])[8])[64])[0])[32 * (int32_T)
      c5_i147])[0];
    c5_b_z.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c5_i147]
      .longOffset = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[56])[8])[64])[0])[32 * (int32_T)
      c5_i147])[4];
    c5_b_z.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c5_i147]
      .elevationOffset = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[56])[8])[64])[0])[32 * (int32_T)
      c5_i147])[8];
    c5_b_z.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c5_i147]
      .timeOffset = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[56])[8])[64])[0])[32 * (int32_T)
      c5_i147])[12];
    for (c5_i150 = 0; c5_i150 < 4; c5_i150++) {
      c5_b_z.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c5_i147]
        .posAccuracy[c5_i150] = ((int8_T *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])[56])
        [8])[64])[0])[32 * (int32_T)c5_i147])[16])[c5_i150];
    }

    c5_b_z.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c5_i147]
      .heading = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[56])[8])[64])[0])[32 * (int32_T)
      c5_i147])[20];
    for (c5_i152 = 0; c5_i152 < 2; c5_i152++) {
      c5_b_z.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c5_i147]
        .speed[c5_i152] = ((int8_T *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])[56])
        [8])[64])[0])[32 * (int32_T)c5_i147])[24])[c5_i152];
    }
  }

  for (c5_i148 = 0; c5_i148 < 345; c5_i148++) {
    c5_b_z.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_02[c5_i148]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])
            [56])[8])[64])[736])[c5_i148];
  }

  for (c5_i149 = 0; c5_i149 < 276; c5_i149++) {
    c5_b_z.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_03[c5_i149]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])
            [56])[8])[64])[1081])[c5_i149];
  }

  for (c5_i151 = 0; c5_i151 < 184; c5_i151++) {
    c5_b_z.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_04[c5_i151]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])
            [56])[8])[64])[1357])[c5_i151];
  }

  for (c5_i153 = 0; c5_i153 < 230; c5_i153++) {
    c5_b_z.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_05[c5_i153]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])
            [56])[8])[64])[1541])[c5_i153];
  }

  for (c5_i154 = 0; c5_i154 < 138; c5_i154++) {
    c5_b_z.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_06[c5_i154]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])
            [56])[8])[64])[1771])[c5_i154];
  }

  for (c5_i155 = 0; c5_i155 < 242; c5_i155++) {
    c5_b_z.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_07[c5_i155]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])
            [56])[8])[64])[1909])[c5_i155];
  }

  for (c5_i156 = 0; c5_i156 < 161; c5_i156++) {
    c5_b_z.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_08[c5_i156]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])
            [56])[8])[64])[2151])[c5_i156];
  }

  for (c5_i157 = 0; c5_i157 < 196; c5_i157++) {
    c5_b_z.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_09[c5_i157]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])
            [56])[8])[64])[2312])[c5_i157];
  }

  for (c5_i158 = 0; c5_i158 < 104; c5_i158++) {
    c5_b_z.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_10[c5_i158]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])
            [56])[8])[64])[2508])[c5_i158];
  }

  c5_b_z.DATA.safetyExt.pathPrediction.radiusOfCurve = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathPrediction *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[56])[2688])[0];
  c5_b_z.DATA.safetyExt.pathPrediction.confidence = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathPrediction *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[56])[2688])[4];
  c5_b_z.DATA.safetyExt.theRTCM.anchorPoint.utcTime.year = *(int32_T *)&((char_T
    *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[56])[2696])[0])[0])[0];
  c5_b_z.DATA.safetyExt.theRTCM.anchorPoint.utcTime.month = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])[56])
        [2696])[0])[0])[4];
  c5_b_z.DATA.safetyExt.theRTCM.anchorPoint.utcTime.day = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[56])[2696])[0])[0])[8];
  c5_b_z.DATA.safetyExt.theRTCM.anchorPoint.utcTime.hour = *(int32_T *)&((char_T
    *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[56])[2696])[0])[0])[12];
  c5_b_z.DATA.safetyExt.theRTCM.anchorPoint.utcTime.minute = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])[56])
        [2696])[0])[0])[16];
  c5_b_z.DATA.safetyExt.theRTCM.anchorPoint.utcTime.second = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])[56])
        [2696])[0])[0])[20];
  c5_b_z.DATA.safetyExt.theRTCM.anchorPoint.longitude = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[56])[2696])[0])[24];
  c5_b_z.DATA.safetyExt.theRTCM.anchorPoint.latitude = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[56])[2696])[0])[28];
  for (c5_i159 = 0; c5_i159 < 2; c5_i159++) {
    c5_b_z.DATA.safetyExt.theRTCM.anchorPoint.elevation[c5_i159] = ((int8_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[56])[2696])[0])[32])[c5_i159];
  }

  c5_b_z.DATA.safetyExt.theRTCM.anchorPoint.heading = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[56])[2696])[0])[36];
  for (c5_i160 = 0; c5_i160 < 2; c5_i160++) {
    c5_b_z.DATA.safetyExt.theRTCM.anchorPoint.speed[c5_i160] = ((int8_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[56])[2696])[0])[40])[c5_i160];
  }

  for (c5_i161 = 0; c5_i161 < 4; c5_i161++) {
    c5_b_z.DATA.safetyExt.theRTCM.anchorPoint.posAccuracy[c5_i161] = ((int8_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[56])[2696])[0])[42])[c5_i161];
  }

  c5_b_z.DATA.safetyExt.theRTCM.anchorPoint.timeConfidence = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])[56])
       [2696])[0])[48];
  c5_b_z.DATA.safetyExt.theRTCM.anchorPoint.posConfidence = *(int8_T *)&((char_T
    *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[56])[2696])[0])[52];
  c5_b_z.DATA.safetyExt.theRTCM.anchorPoint.speedConfidence = *(int8_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])[56])
       [2696])[0])[53];
  for (c5_i162 = 0; c5_i162 < 5; c5_i162++) {
    c5_b_z.DATA.safetyExt.theRTCM.rtcmHeader[c5_i162] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[56])[2696])[56])[c5_i162];
  }

  for (c5_i163 = 0; c5_i163 < 124; c5_i163++) {
    c5_b_z.DATA.safetyExt.theRTCM.msg1001[c5_i163] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[56])[2696])[61])[c5_i163];
  }

  for (c5_i164 = 0; c5_i164 < 156; c5_i164++) {
    c5_b_z.DATA.safetyExt.theRTCM.msg1002[c5_i164] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[56])[2696])[185])[c5_i164];
  }

  for (c5_i165 = 0; c5_i165 < 210; c5_i165++) {
    c5_b_z.DATA.safetyExt.theRTCM.msg1003[c5_i165] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[56])[2696])[341])[c5_i165];
  }

  for (c5_i166 = 0; c5_i166 < 258; c5_i166++) {
    c5_b_z.DATA.safetyExt.theRTCM.msg1004[c5_i166] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[56])[2696])[551])[c5_i166];
  }

  for (c5_i167 = 0; c5_i167 < 19; c5_i167++) {
    c5_b_z.DATA.safetyExt.theRTCM.msg1005[c5_i167] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[56])[2696])[809])[c5_i167];
  }

  for (c5_i168 = 0; c5_i168 < 21; c5_i168++) {
    c5_b_z.DATA.safetyExt.theRTCM.msg1006[c5_i168] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[56])[2696])[828])[c5_i168];
  }

  for (c5_i169 = 0; c5_i169 < 36; c5_i169++) {
    c5_b_z.DATA.safetyExt.theRTCM.msg1007[c5_i169] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[56])[2696])[849])[c5_i169];
  }

  for (c5_i170 = 0; c5_i170 < 68; c5_i170++) {
    c5_b_z.DATA.safetyExt.theRTCM.msg1008[c5_i170] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[56])[2696])[885])[c5_i170];
  }

  for (c5_i171 = 0; c5_i171 < 136; c5_i171++) {
    c5_b_z.DATA.safetyExt.theRTCM.msg1009[c5_i171] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[56])[2696])[953])[c5_i171];
  }

  for (c5_i172 = 0; c5_i172 < 166; c5_i172++) {
    c5_b_z.DATA.safetyExt.theRTCM.msg1010[c5_i172] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[56])[2696])[1089])[c5_i172];
  }

  for (c5_i173 = 0; c5_i173 < 222; c5_i173++) {
    c5_b_z.DATA.safetyExt.theRTCM.msg1011[c5_i173] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[56])[2696])[1255])[c5_i173];
  }

  for (c5_i174 = 0; c5_i174 < 268; c5_i174++) {
    c5_b_z.DATA.safetyExt.theRTCM.msg1012[c5_i174] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[56])[2696])[1477])[c5_i174];
  }

  for (c5_i175 = 0; c5_i175 < 27; c5_i175++) {
    c5_b_z.DATA.safetyExt.theRTCM.msg1013[c5_i175] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[56])[2696])[1745])[c5_i175];
  }

  for (c5_i176 = 0; c5_i176 < 15; c5_i176++) {
    c5_b_z.DATA.safetyExt.theRTCM.msg1014[c5_i176] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[56])[2696])[1772])[c5_i176];
  }

  for (c5_i177 = 0; c5_i177 < 69; c5_i177++) {
    c5_b_z.DATA.safetyExt.theRTCM.msg1015[c5_i177] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[56])[2696])[1787])[c5_i177];
  }

  for (c5_i178 = 0; c5_i178 < 81; c5_i178++) {
    c5_b_z.DATA.safetyExt.theRTCM.msg1016[c5_i178] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[56])[2696])[1856])[c5_i178];
  }

  for (c5_i179 = 0; c5_i179 < 115; c5_i179++) {
    c5_b_z.DATA.safetyExt.theRTCM.msg1017[c5_i179] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[56])[2696])[1937])[c5_i179];
  }

  for (c5_i180 = 0; c5_i180 < 62; c5_i180++) {
    c5_b_z.DATA.safetyExt.theRTCM.msg1019[c5_i180] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[56])[2696])[2052])[c5_i180];
  }

  for (c5_i181 = 0; c5_i181 < 45; c5_i181++) {
    c5_b_z.DATA.safetyExt.theRTCM.msg1020[c5_i181] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[56])[2696])[2114])[c5_i181];
  }

  for (c5_i182 = 0; c5_i182 < 62; c5_i182++) {
    c5_b_z.DATA.safetyExt.theRTCM.msg1021[c5_i182] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[56])[2696])[2159])[c5_i182];
  }

  for (c5_i183 = 0; c5_i183 < 75; c5_i183++) {
    c5_b_z.DATA.safetyExt.theRTCM.msg1022[c5_i183] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[56])[2696])[2221])[c5_i183];
  }

  for (c5_i184 = 0; c5_i184 < 73; c5_i184++) {
    c5_b_z.DATA.safetyExt.theRTCM.msg1023[c5_i184] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[56])[2696])[2296])[c5_i184];
  }

  for (c5_i185 = 0; c5_i185 < 74; c5_i185++) {
    c5_b_z.DATA.safetyExt.theRTCM.msg1024[c5_i185] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[56])[2696])[2369])[c5_i185];
  }

  for (c5_i186 = 0; c5_i186 < 25; c5_i186++) {
    c5_b_z.DATA.safetyExt.theRTCM.msg1025[c5_i186] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[56])[2696])[2443])[c5_i186];
  }

  for (c5_i187 = 0; c5_i187 < 30; c5_i187++) {
    c5_b_z.DATA.safetyExt.theRTCM.msg1026[c5_i187] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[56])[2696])[2468])[c5_i187];
  }

  for (c5_i188 = 0; c5_i188 < 33; c5_i188++) {
    c5_b_z.DATA.safetyExt.theRTCM.msg1027[c5_i188] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[56])[2696])[2498])[c5_i188];
  }

  for (c5_i189 = 0; c5_i189 < 69; c5_i189++) {
    c5_b_z.DATA.safetyExt.theRTCM.msg1029[c5_i189] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[56])[2696])[2531])[c5_i189];
  }

  for (c5_i190 = 0; c5_i190 < 105; c5_i190++) {
    c5_b_z.DATA.safetyExt.theRTCM.msg1030[c5_i190] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[56])[2696])[2600])[c5_i190];
  }

  for (c5_i191 = 0; c5_i191 < 107; c5_i191++) {
    c5_b_z.DATA.safetyExt.theRTCM.msg1031[c5_i191] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[56])[2696])[2705])[c5_i191];
  }

  for (c5_i192 = 0; c5_i192 < 20; c5_i192++) {
    c5_b_z.DATA.safetyExt.theRTCM.msg1032[c5_i192] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_z)[8])[56])[2696])[2812])[c5_i192];
  }

  c5_b_z.DATA.status.lights = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[5584])[0];
  c5_b_z.DATA.status.lightBar = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[5584])[4];
  c5_b_z.DATA.status.wipers.statusFront = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])
    [5584])[8])[0];
  c5_b_z.DATA.status.wipers.rateFront = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])
    [5584])[8])[4];
  c5_b_z.DATA.status.wipers.statusRear = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])
    [5584])[8])[8];
  c5_b_z.DATA.status.wipers.rateRear = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])
    [5584])[8])[12];
  for (c5_i193 = 0; c5_i193 < 2; c5_i193++) {
    c5_b_z.DATA.status.brakeStatus[c5_i193] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_z)[8])[5584])[24])[c5_i193];
  }

  c5_b_z.DATA.status.brakePressure = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[5584])[28];
  c5_b_z.DATA.status.roadFriction = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[5584])[32];
  c5_b_z.DATA.status.sunData = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[5584])[36];
  c5_b_z.DATA.status.rainData = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[5584])[40];
  c5_b_z.DATA.status.airTemp = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[5584])[44];
  c5_b_z.DATA.status.airPres = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[5584])[48];
  c5_b_z.DATA.status.steering.angle = *(int8_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])
    [5584])[56])[0];
  c5_b_z.DATA.status.steering.confidence = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])
    [5584])[56])[4];
  c5_b_z.DATA.status.steering.rate = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])
    [5584])[56])[8];
  c5_b_z.DATA.status.steering.wheels = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])
    [5584])[56])[12];
  for (c5_i194 = 0; c5_i194 < 7; c5_i194++) {
    c5_b_z.DATA.status.accelSets.accel4way[c5_i194] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_z)[8])[5584])[72])[0])[c5_i194];
  }

  c5_b_z.DATA.status.accelSets.vertAccelThres = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)
        [8])[5584])[72])[8];
  c5_b_z.DATA.status.accelSets.yawRateCon = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)
        [8])[5584])[72])[12];
  c5_b_z.DATA.status.accelSets.hozAccelCon = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)
        [8])[5584])[72])[16];
  c5_b_z.DATA.status.accelSets.confidenceSet.accelConfidence.yawRate = *(int32_T
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelConfidence *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])
           [5584])[72])[24])[0])[0];
  c5_b_z.DATA.status.accelSets.confidenceSet.accelConfidence.acceleration =
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelConfidence *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)
        [8])[5584])[72])[24])[0])[4];
  c5_b_z.DATA.status.accelSets.confidenceSet.accelConfidence.steeringWheelAngle =
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelConfidence *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)
        [8])[5584])[72])[24])[0])[8];
  c5_b_z.DATA.status.accelSets.confidenceSet.speedConfidence = *(int8_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
         &((char_T *)chartInstance->c5_z)[8])[5584])[72])[24])[16];
  c5_b_z.DATA.status.accelSets.confidenceSet.timeConfidence = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
         &((char_T *)chartInstance->c5_z)[8])[5584])[72])[24])[20];
  c5_b_z.DATA.status.accelSets.confidenceSet.posConfidence = *(int8_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
         &((char_T *)chartInstance->c5_z)[8])[5584])[72])[24])[24];
  c5_b_z.DATA.status.accelSets.confidenceSet.steerConfidence = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
         &((char_T *)chartInstance->c5_z)[8])[5584])[72])[24])[28];
  c5_b_z.DATA.status.accelSets.confidenceSet.throttleConfidence = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
         &((char_T *)chartInstance->c5_z)[8])[5584])[72])[24])[32];
  c5_b_z.DATA.status.object.obDist = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])
    [5584])[136])[0];
  c5_b_z.DATA.status.object.obDirect = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])
    [5584])[136])[4];
  c5_b_z.DATA.status.object.dateTime.year = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])[5584])
    [136])[8])[0];
  c5_b_z.DATA.status.object.dateTime.month = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])[5584])
    [136])[8])[4];
  c5_b_z.DATA.status.object.dateTime.day = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])[5584])
    [136])[8])[8];
  c5_b_z.DATA.status.object.dateTime.hour = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])[5584])
    [136])[8])[12];
  c5_b_z.DATA.status.object.dateTime.minute = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])[5584])
    [136])[8])[16];
  c5_b_z.DATA.status.object.dateTime.second = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])[5584])
    [136])[8])[20];
  c5_b_z.DATA.status.fullPos.utcTime.year = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])[5584])
    [168])[0])[0];
  c5_b_z.DATA.status.fullPos.utcTime.month = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])[5584])
    [168])[0])[4];
  c5_b_z.DATA.status.fullPos.utcTime.day = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])[5584])
    [168])[0])[8];
  c5_b_z.DATA.status.fullPos.utcTime.hour = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])[5584])
    [168])[0])[12];
  c5_b_z.DATA.status.fullPos.utcTime.minute = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])[5584])
    [168])[0])[16];
  c5_b_z.DATA.status.fullPos.utcTime.second = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])[5584])
    [168])[0])[20];
  c5_b_z.DATA.status.fullPos.longitude = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])
    [5584])[168])[24];
  c5_b_z.DATA.status.fullPos.latitude = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])
    [5584])[168])[28];
  for (c5_i195 = 0; c5_i195 < 2; c5_i195++) {
    c5_b_z.DATA.status.fullPos.elevation[c5_i195] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
      chartInstance->c5_z)[8])[5584])[168])[32])[c5_i195];
  }

  c5_b_z.DATA.status.fullPos.heading = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])
    [5584])[168])[36];
  for (c5_i196 = 0; c5_i196 < 2; c5_i196++) {
    c5_b_z.DATA.status.fullPos.speed[c5_i196] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
      chartInstance->c5_z)[8])[5584])[168])[40])[c5_i196];
  }

  for (c5_i197 = 0; c5_i197 < 4; c5_i197++) {
    c5_b_z.DATA.status.fullPos.posAccuracy[c5_i197] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
      chartInstance->c5_z)[8])[5584])[168])[42])[c5_i197];
  }

  c5_b_z.DATA.status.fullPos.timeConfidence = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])
    [5584])[168])[48];
  c5_b_z.DATA.status.fullPos.posConfidence = *(int8_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])
    [5584])[168])[52];
  c5_b_z.DATA.status.fullPos.speedConfidence = *(int8_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])
    [5584])[168])[53];
  c5_b_z.DATA.status.throttlePos = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[5584])[224];
  c5_b_z.DATA.status.speedHeadC = *(int8_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[5584])[228];
  c5_b_z.DATA.status.speedC = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[5584])[232];
  c5_b_z.DATA.status.vehicleData.height = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[5584])[240])[0];
  c5_b_z.DATA.status.vehicleData.bumpers.frnt = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_bumpers *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[5584])[240])[8])[0];
  c5_b_z.DATA.status.vehicleData.bumpers.rear = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_bumpers *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[5584])[240])[8])[4];
  c5_b_z.DATA.status.vehicleData.mass = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[5584])[240])[16];
  c5_b_z.DATA.status.vehicleData.trailerWeight = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[5584])[240])[20];
  c5_b_z.DATA.status.vehicleData.type = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[5584])[240])[24];
  for (c5_i198 = 0; c5_i198 < 63; c5_i198++) {
    c5_b_z.DATA.status.vehicleIdent.name[c5_i198] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_z)[8])[5584])[272])[0])[c5_i198];
  }

  for (c5_i199 = 0; c5_i199 < 17; c5_i199++) {
    c5_b_z.DATA.status.vehicleIdent.vin[c5_i199] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_z)[8])[5584])[272])[63])[c5_i199];
  }

  for (c5_i200 = 0; c5_i200 < 32; c5_i200++) {
    c5_b_z.DATA.status.vehicleIdent.ownerCode[c5_i200] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_z)[8])[5584])[272])[80])[c5_i200];
  }

  for (c5_i201 = 0; c5_i201 < 4; c5_i201++) {
    c5_b_z.DATA.status.vehicleIdent.id[c5_i201] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_z)[8])[5584])[272])[112])[c5_i201];
  }

  c5_b_z.DATA.status.vehicleIdent.vehicleType = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[5584])[272])[116];
  c5_b_z.DATA.status.vehicleIdent.vehicleClass.vGroup = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleClass *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[5584])[272])[120])[0];
  c5_b_z.DATA.status.vehicleIdent.vehicleClass.rGroup = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleClass *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[5584])[272])[120])[4];
  c5_b_z.DATA.status.vehicleIdent.vehicleClass.rEquip = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleClass *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[5584])[272])[120])[8];
  for (c5_i202 = 0; c5_i202 < 16; c5_i202++) {
    c5_b_z.DATA.status.j1939data.tires[c5_i202].location = *(int32_T *)&((char_T
      *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_z)[8])[5584])[408])[0])[32 * (int32_T)
      c5_i202])[0];
    c5_b_z.DATA.status.j1939data.tires[c5_i202].pressure = *(int32_T *)&((char_T
      *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_z)[8])[5584])[408])[0])[32 * (int32_T)
      c5_i202])[4];
    c5_b_z.DATA.status.j1939data.tires[c5_i202].temp = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_z)[8])[5584])[408])[0])[32 * (int32_T)
      c5_i202])[8];
    c5_b_z.DATA.status.j1939data.tires[c5_i202].wheelSensorStatus = *(int32_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])
           [5584])[408])[0])[32 * (int32_T)c5_i202])[12];
    c5_b_z.DATA.status.j1939data.tires[c5_i202].wheelEndElectFault = *(int32_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])
           [5584])[408])[0])[32 * (int32_T)c5_i202])[16];
    c5_b_z.DATA.status.j1939data.tires[c5_i202].leakageRate = *(int32_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])
           [5584])[408])[0])[32 * (int32_T)c5_i202])[20];
    c5_b_z.DATA.status.j1939data.tires[c5_i202].detection = *(int32_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)[8])
           [5584])[408])[0])[32 * (int32_T)c5_i202])[24];
  }

  for (c5_i203 = 0; c5_i203 < 16; c5_i203++) {
    c5_b_z.DATA.status.j1939data.axle[c5_i203].location = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_axle *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_axle *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_z)[8])[5584])[408])[512])[8 * (int32_T)
      c5_i203])[0];
    c5_b_z.DATA.status.j1939data.axle[c5_i203].weight = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_axle *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_axle *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_z)[8])[5584])[408])[512])[8 * (int32_T)
      c5_i203])[4];
  }

  c5_b_z.DATA.status.j1939data.trailerWeight = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)
        [8])[5584])[408])[640];
  c5_b_z.DATA.status.j1939data.cargoWeight = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)
        [8])[5584])[408])[644];
  c5_b_z.DATA.status.j1939data.steeringAxleTemperature = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)
        [8])[5584])[408])[648];
  c5_b_z.DATA.status.j1939data.driveAxleLocation = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)
        [8])[5584])[408])[652];
  c5_b_z.DATA.status.j1939data.driveAxleLiftAirPressure = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)
        [8])[5584])[408])[656];
  c5_b_z.DATA.status.j1939data.driveAxleTemperature = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)
        [8])[5584])[408])[660];
  c5_b_z.DATA.status.j1939data.driveAxleLubePressure = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)
        [8])[5584])[408])[664];
  c5_b_z.DATA.status.j1939data.steeringAxleLubePressure = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_z)
        [8])[5584])[408])[668];
  c5_b_z.DATA.status.weatherReport.isRaining = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[5584])[1080])[0];
  c5_b_z.DATA.status.weatherReport.rainRate = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[5584])[1080])[4];
  c5_b_z.DATA.status.weatherReport.precipSituation = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[5584])[1080])[8];
  c5_b_z.DATA.status.weatherReport.solarRadiation = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[5584])[1080])[12];
  c5_b_z.DATA.status.weatherReport.friction = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[5584])[1080])[16];
  c5_b_z.DATA.status.gpsStatus = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_z)[8])[5584])[1104];
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c5_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 0U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 1U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_b_u, 2U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_b_z, 3U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_y, 4U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_c_y = c5_b_u;
  c5_c_z = c5_b_z;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c5_f_debug_family_names,
    c5_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_nargin, 0U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_nargout, 1U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_c_y, 2U, c5_b_sf_marshallOut,
    c5_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_c_z, 3U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_y, 4U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 3);
  c5_b_y = c5_c_z;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_c_u = c5_b_y;
  c5_d_y = c5_c_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 5U, c5_e_debug_family_names,
    c5_c_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_c_nargin, 0U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_c_nargout, 1U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_c_u, 2U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_d_y, 3U, c5_b_sf_marshallOut,
    c5_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_y, MAX_uint32_T,
    c5_c_sf_marshallOut, c5_b_sf_marshallIn);
  c5_b_y = c5_c_u;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  CV_SCRIPT_FCN(0, 1);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_d_u = c5_b_y.HEADER;
  c5_e_y = c5_d_y.HEADER;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 5U, c5_b_debug_family_names,
    c5_d_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_d_nargin, 0U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_d_nargout, 1U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_d_u, 2U, c5_d_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_e_y, 3U, c5_d_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_y.HEADER, MAX_uint32_T,
    c5_d_sf_marshallOut, c5_c_sf_marshallIn);
  c5_b_y.HEADER = c5_d_u;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  CV_SCRIPT_FCN(0, 2);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 13);
  c5_b_y.HEADER.valid = c5_e_y.valid;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -13);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  c5_e_u = c5_b_y.DATA;
  c5_f_y = c5_d_y.DATA;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 5U, c5_d_debug_family_names,
    c5_e_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_e_nargin, 0U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_e_nargout, 1U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_e_u, 2U, c5_g_sf_marshallOut,
    c5_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_f_y, 3U, c5_h_sf_marshallOut,
    c5_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_y.DATA, MAX_uint32_T,
    c5_g_sf_marshallOut, c5_f_sf_marshallIn);
  c5_b_y.DATA = c5_e_u;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  CV_SCRIPT_FCN(0, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 17);
  c5_b_y.DATA.msgID = c5_f_y.msgID;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 18);
  c5_b_y.DATA.msgCnt = c5_f_y.msgCnt;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 19);
  for (c5_i204 = 0; c5_i204 < 4; c5_i204++) {
    c5_b_y.DATA.id[c5_i204] = c5_f_y.id[c5_i204];
  }

  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 20);
  c5_b_y.DATA.secMark = c5_f_y.secMark;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 21);
  c5_b_y.DATA.latitude = c5_f_y.latitude;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 22);
  c5_b_y.DATA.longitude = c5_f_y.longitude;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 23);
  for (c5_i205 = 0; c5_i205 < 2; c5_i205++) {
    c5_b_y.DATA.elev[c5_i205] = c5_f_y.elev[c5_i205];
  }

  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 24);
  for (c5_i206 = 0; c5_i206 < 4; c5_i206++) {
    c5_b_y.DATA.accuracy[c5_i206] = c5_f_y.accuracy[c5_i206];
  }

  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 25);
  for (c5_i207 = 0; c5_i207 < 2; c5_i207++) {
    c5_b_y.DATA.speed[c5_i207] = c5_f_y.speed[c5_i207];
  }

  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 26);
  c5_b_y.DATA.heading = c5_f_y.heading;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 27);
  c5_b_y.DATA.angle = c5_f_y.angle;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 28);
  for (c5_i208 = 0; c5_i208 < 7; c5_i208++) {
    c5_b_y.DATA.accelSet[c5_i208] = c5_f_y.accelSet[c5_i208];
  }

  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 29);
  for (c5_i209 = 0; c5_i209 < 2; c5_i209++) {
    c5_b_y.DATA.brakes[c5_i209] = c5_f_y.brakes[c5_i209];
  }

  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 30);
  c5_f_u = c5_b_y.DATA.size;
  c5_g_y = c5_f_y.size;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 5U, c5_c_debug_family_names,
    c5_f_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_f_nargin, 0U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_f_nargout, 1U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_f_u, 2U, c5_e_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_g_y, 3U, c5_f_sf_marshallOut,
    c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_y.DATA.size, MAX_uint32_T,
    c5_e_sf_marshallOut, c5_d_sf_marshallIn);
  c5_b_y.DATA.size = c5_f_u;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  CV_SCRIPT_FCN(0, 4);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 34);
  c5_b_y.DATA.size.width = c5_g_y.width;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 35);
  c5_b_y.DATA.size.length = c5_g_y.length;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -35);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -30);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -9);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -4);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -4);
  _SFD_SYMBOL_SCOPE_POP();
  *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)chartInstance->c5_y)[0])
    [0] = c5_b_y.HEADER.valid;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    chartInstance->c5_y)[8])[0] = c5_b_y.DATA.msgID;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    chartInstance->c5_y)[8])[4] = c5_b_y.DATA.msgCnt;
  for (c5_i210 = 0; c5_i210 < 4; c5_i210++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
       chartInstance->c5_y)[8])[8])[c5_i210] = c5_b_y.DATA.id[c5_i210];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    chartInstance->c5_y)[8])[12] = c5_b_y.DATA.secMark;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    chartInstance->c5_y)[8])[16] = c5_b_y.DATA.latitude;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    chartInstance->c5_y)[8])[20] = c5_b_y.DATA.longitude;
  for (c5_i211 = 0; c5_i211 < 2; c5_i211++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
       chartInstance->c5_y)[8])[24])[c5_i211] = c5_b_y.DATA.elev[c5_i211];
  }

  for (c5_i212 = 0; c5_i212 < 4; c5_i212++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
       chartInstance->c5_y)[8])[26])[c5_i212] = c5_b_y.DATA.accuracy[c5_i212];
  }

  for (c5_i213 = 0; c5_i213 < 2; c5_i213++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
       chartInstance->c5_y)[8])[30])[c5_i213] = c5_b_y.DATA.speed[c5_i213];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    chartInstance->c5_y)[8])[32] = c5_b_y.DATA.heading;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    chartInstance->c5_y)[8])[36] = c5_b_y.DATA.angle;
  for (c5_i214 = 0; c5_i214 < 7; c5_i214++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
       chartInstance->c5_y)[8])[37])[c5_i214] = c5_b_y.DATA.accelSet[c5_i214];
  }

  for (c5_i215 = 0; c5_i215 < 2; c5_i215++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
       chartInstance->c5_y)[8])[44])[c5_i215] = c5_b_y.DATA.brakes[c5_i215];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_size *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[48])[0] =
    c5_b_y.DATA.size.width;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_size *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[48])[4] =
    c5_b_y.DATA.size.length;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])[0] =
    c5_b_y.DATA.safetyExt.events;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[8])[0])[0])[0] =
    c5_b_y.DATA.safetyExt.pathHistory.initialPosition.utcTime.year;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[8])[0])[0])[4] =
    c5_b_y.DATA.safetyExt.pathHistory.initialPosition.utcTime.month;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[8])[0])[0])[8] =
    c5_b_y.DATA.safetyExt.pathHistory.initialPosition.utcTime.day;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[8])[0])[0])[12] =
    c5_b_y.DATA.safetyExt.pathHistory.initialPosition.utcTime.hour;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[8])[0])[0])[16] =
    c5_b_y.DATA.safetyExt.pathHistory.initialPosition.utcTime.minute;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[8])[0])[0])[20] =
    c5_b_y.DATA.safetyExt.pathHistory.initialPosition.utcTime.second;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[8])[0])[24] =
    c5_b_y.DATA.safetyExt.pathHistory.initialPosition.longitude;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[8])[0])[28] =
    c5_b_y.DATA.safetyExt.pathHistory.initialPosition.latitude;
  for (c5_i216 = 0; c5_i216 < 2; c5_i216++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
       [8])[0])[32])[c5_i216] =
      c5_b_y.DATA.safetyExt.pathHistory.initialPosition.elevation[c5_i216];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[8])[0])[36] =
    c5_b_y.DATA.safetyExt.pathHistory.initialPosition.heading;
  for (c5_i217 = 0; c5_i217 < 2; c5_i217++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
       [8])[0])[40])[c5_i217] =
      c5_b_y.DATA.safetyExt.pathHistory.initialPosition.speed[c5_i217];
  }

  for (c5_i218 = 0; c5_i218 < 4; c5_i218++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
       [8])[0])[42])[c5_i218] =
      c5_b_y.DATA.safetyExt.pathHistory.initialPosition.posAccuracy[c5_i218];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[8])[0])[48] =
    c5_b_y.DATA.safetyExt.pathHistory.initialPosition.timeConfidence;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[8])[0])[52] =
    c5_b_y.DATA.safetyExt.pathHistory.initialPosition.posConfidence;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[8])[0])[53] =
    c5_b_y.DATA.safetyExt.pathHistory.initialPosition.speedConfidence;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[8])[56] =
    c5_b_y.DATA.safetyExt.pathHistory.currGPSstatus;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[8])[60] =
    c5_b_y.DATA.safetyExt.pathHistory.itemCnt;
  for (c5_i219 = 0; c5_i219 < 23; c5_i219++) {
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                  &((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                    &((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[8])[64])[0])[32 * (int32_T)
                  c5_i219])[0] =
      c5_b_y.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c5_i219]
      .latOffset;
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                  &((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                    &((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[8])[64])[0])[32 * (int32_T)
                  c5_i219])[4] =
      c5_b_y.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c5_i219]
      .longOffset;
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                  &((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                    &((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[8])[64])[0])[32 * (int32_T)
                  c5_i219])[8] =
      c5_b_y.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c5_i219]
      .elevationOffset;
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                  &((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                    &((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[8])[64])[0])[32 * (int32_T)
                  c5_i219])[12] =
      c5_b_y.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c5_i219]
      .timeOffset;
    for (c5_i222 = 0; c5_i222 < 4; c5_i222++) {
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                   &((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                     &((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
            [56])[8])[64])[0])[32 * (int32_T)c5_i219])[16])[c5_i222] =
        c5_b_y.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c5_i219]
        .posAccuracy[c5_i222];
    }

    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                  &((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                    &((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c5_y)[8])[56])[8])[64])[0])[32 * (int32_T)
                  c5_i219])[20] =
      c5_b_y.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c5_i219]
      .heading;
    for (c5_i224 = 0; c5_i224 < 2; c5_i224++) {
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                   &((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                     &((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
            [56])[8])[64])[0])[32 * (int32_T)c5_i219])[24])[c5_i224] =
        c5_b_y.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c5_i219]
        .speed[c5_i224];
    }
  }

  for (c5_i220 = 0; c5_i220 < 345; c5_i220++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
       [8])[64])[736])[c5_i220] =
      c5_b_y.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_02[c5_i220];
  }

  for (c5_i221 = 0; c5_i221 < 276; c5_i221++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
       [8])[64])[1081])[c5_i221] =
      c5_b_y.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_03[c5_i221];
  }

  for (c5_i223 = 0; c5_i223 < 184; c5_i223++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
       [8])[64])[1357])[c5_i223] =
      c5_b_y.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_04[c5_i223];
  }

  for (c5_i225 = 0; c5_i225 < 230; c5_i225++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
       [8])[64])[1541])[c5_i225] =
      c5_b_y.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_05[c5_i225];
  }

  for (c5_i226 = 0; c5_i226 < 138; c5_i226++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
       [8])[64])[1771])[c5_i226] =
      c5_b_y.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_06[c5_i226];
  }

  for (c5_i227 = 0; c5_i227 < 242; c5_i227++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
       [8])[64])[1909])[c5_i227] =
      c5_b_y.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_07[c5_i227];
  }

  for (c5_i228 = 0; c5_i228 < 161; c5_i228++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
       [8])[64])[2151])[c5_i228] =
      c5_b_y.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_08[c5_i228];
  }

  for (c5_i229 = 0; c5_i229 < 196; c5_i229++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
       [8])[64])[2312])[c5_i229] =
      c5_b_y.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_09[c5_i229];
  }

  for (c5_i230 = 0; c5_i230 < 104; c5_i230++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
       [8])[64])[2508])[c5_i230] =
      c5_b_y.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_10[c5_i230];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathPrediction *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2688])[0] =
    c5_b_y.DATA.safetyExt.pathPrediction.radiusOfCurve;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathPrediction *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2688])[4] =
    c5_b_y.DATA.safetyExt.pathPrediction.confidence;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2696])[0])[0])[0] =
    c5_b_y.DATA.safetyExt.theRTCM.anchorPoint.utcTime.year;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2696])[0])[0])[4] =
    c5_b_y.DATA.safetyExt.theRTCM.anchorPoint.utcTime.month;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2696])[0])[0])[8] =
    c5_b_y.DATA.safetyExt.theRTCM.anchorPoint.utcTime.day;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2696])[0])[0])[12] =
    c5_b_y.DATA.safetyExt.theRTCM.anchorPoint.utcTime.hour;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2696])[0])[0])[16] =
    c5_b_y.DATA.safetyExt.theRTCM.anchorPoint.utcTime.minute;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2696])[0])[0])[20] =
    c5_b_y.DATA.safetyExt.theRTCM.anchorPoint.utcTime.second;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2696])[0])[24] =
    c5_b_y.DATA.safetyExt.theRTCM.anchorPoint.longitude;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2696])[0])[28] =
    c5_b_y.DATA.safetyExt.theRTCM.anchorPoint.latitude;
  for (c5_i231 = 0; c5_i231 < 2; c5_i231++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
       [2696])[0])[32])[c5_i231] =
      c5_b_y.DATA.safetyExt.theRTCM.anchorPoint.elevation[c5_i231];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2696])[0])[36] =
    c5_b_y.DATA.safetyExt.theRTCM.anchorPoint.heading;
  for (c5_i232 = 0; c5_i232 < 2; c5_i232++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
       [2696])[0])[40])[c5_i232] =
      c5_b_y.DATA.safetyExt.theRTCM.anchorPoint.speed[c5_i232];
  }

  for (c5_i233 = 0; c5_i233 < 4; c5_i233++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
       [2696])[0])[42])[c5_i233] =
      c5_b_y.DATA.safetyExt.theRTCM.anchorPoint.posAccuracy[c5_i233];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2696])[0])[48] =
    c5_b_y.DATA.safetyExt.theRTCM.anchorPoint.timeConfidence;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2696])[0])[52] =
    c5_b_y.DATA.safetyExt.theRTCM.anchorPoint.posConfidence;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[56])[2696])[0])[53] =
    c5_b_y.DATA.safetyExt.theRTCM.anchorPoint.speedConfidence;
  for (c5_i234 = 0; c5_i234 < 5; c5_i234++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[56])[c5_i234] =
      c5_b_y.DATA.safetyExt.theRTCM.rtcmHeader[c5_i234];
  }

  for (c5_i235 = 0; c5_i235 < 124; c5_i235++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[61])[c5_i235] =
      c5_b_y.DATA.safetyExt.theRTCM.msg1001[c5_i235];
  }

  for (c5_i236 = 0; c5_i236 < 156; c5_i236++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[185])[c5_i236] =
      c5_b_y.DATA.safetyExt.theRTCM.msg1002[c5_i236];
  }

  for (c5_i237 = 0; c5_i237 < 210; c5_i237++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[341])[c5_i237] =
      c5_b_y.DATA.safetyExt.theRTCM.msg1003[c5_i237];
  }

  for (c5_i238 = 0; c5_i238 < 258; c5_i238++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[551])[c5_i238] =
      c5_b_y.DATA.safetyExt.theRTCM.msg1004[c5_i238];
  }

  for (c5_i239 = 0; c5_i239 < 19; c5_i239++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[809])[c5_i239] =
      c5_b_y.DATA.safetyExt.theRTCM.msg1005[c5_i239];
  }

  for (c5_i240 = 0; c5_i240 < 21; c5_i240++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[828])[c5_i240] =
      c5_b_y.DATA.safetyExt.theRTCM.msg1006[c5_i240];
  }

  for (c5_i241 = 0; c5_i241 < 36; c5_i241++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[849])[c5_i241] =
      c5_b_y.DATA.safetyExt.theRTCM.msg1007[c5_i241];
  }

  for (c5_i242 = 0; c5_i242 < 68; c5_i242++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[885])[c5_i242] =
      c5_b_y.DATA.safetyExt.theRTCM.msg1008[c5_i242];
  }

  for (c5_i243 = 0; c5_i243 < 136; c5_i243++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[953])[c5_i243] =
      c5_b_y.DATA.safetyExt.theRTCM.msg1009[c5_i243];
  }

  for (c5_i244 = 0; c5_i244 < 166; c5_i244++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[1089])[c5_i244] =
      c5_b_y.DATA.safetyExt.theRTCM.msg1010[c5_i244];
  }

  for (c5_i245 = 0; c5_i245 < 222; c5_i245++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[1255])[c5_i245] =
      c5_b_y.DATA.safetyExt.theRTCM.msg1011[c5_i245];
  }

  for (c5_i246 = 0; c5_i246 < 268; c5_i246++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[1477])[c5_i246] =
      c5_b_y.DATA.safetyExt.theRTCM.msg1012[c5_i246];
  }

  for (c5_i247 = 0; c5_i247 < 27; c5_i247++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[1745])[c5_i247] =
      c5_b_y.DATA.safetyExt.theRTCM.msg1013[c5_i247];
  }

  for (c5_i248 = 0; c5_i248 < 15; c5_i248++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[1772])[c5_i248] =
      c5_b_y.DATA.safetyExt.theRTCM.msg1014[c5_i248];
  }

  for (c5_i249 = 0; c5_i249 < 69; c5_i249++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[1787])[c5_i249] =
      c5_b_y.DATA.safetyExt.theRTCM.msg1015[c5_i249];
  }

  for (c5_i250 = 0; c5_i250 < 81; c5_i250++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[1856])[c5_i250] =
      c5_b_y.DATA.safetyExt.theRTCM.msg1016[c5_i250];
  }

  for (c5_i251 = 0; c5_i251 < 115; c5_i251++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[1937])[c5_i251] =
      c5_b_y.DATA.safetyExt.theRTCM.msg1017[c5_i251];
  }

  for (c5_i252 = 0; c5_i252 < 62; c5_i252++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[2052])[c5_i252] =
      c5_b_y.DATA.safetyExt.theRTCM.msg1019[c5_i252];
  }

  for (c5_i253 = 0; c5_i253 < 45; c5_i253++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[2114])[c5_i253] =
      c5_b_y.DATA.safetyExt.theRTCM.msg1020[c5_i253];
  }

  for (c5_i254 = 0; c5_i254 < 62; c5_i254++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[2159])[c5_i254] =
      c5_b_y.DATA.safetyExt.theRTCM.msg1021[c5_i254];
  }

  for (c5_i255 = 0; c5_i255 < 75; c5_i255++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[2221])[c5_i255] =
      c5_b_y.DATA.safetyExt.theRTCM.msg1022[c5_i255];
  }

  for (c5_i256 = 0; c5_i256 < 73; c5_i256++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[2296])[c5_i256] =
      c5_b_y.DATA.safetyExt.theRTCM.msg1023[c5_i256];
  }

  for (c5_i257 = 0; c5_i257 < 74; c5_i257++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[2369])[c5_i257] =
      c5_b_y.DATA.safetyExt.theRTCM.msg1024[c5_i257];
  }

  for (c5_i258 = 0; c5_i258 < 25; c5_i258++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[2443])[c5_i258] =
      c5_b_y.DATA.safetyExt.theRTCM.msg1025[c5_i258];
  }

  for (c5_i259 = 0; c5_i259 < 30; c5_i259++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[2468])[c5_i259] =
      c5_b_y.DATA.safetyExt.theRTCM.msg1026[c5_i259];
  }

  for (c5_i260 = 0; c5_i260 < 33; c5_i260++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[2498])[c5_i260] =
      c5_b_y.DATA.safetyExt.theRTCM.msg1027[c5_i260];
  }

  for (c5_i261 = 0; c5_i261 < 69; c5_i261++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[2531])[c5_i261] =
      c5_b_y.DATA.safetyExt.theRTCM.msg1029[c5_i261];
  }

  for (c5_i262 = 0; c5_i262 < 105; c5_i262++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[2600])[c5_i262] =
      c5_b_y.DATA.safetyExt.theRTCM.msg1030[c5_i262];
  }

  for (c5_i263 = 0; c5_i263 < 107; c5_i263++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[2705])[c5_i263] =
      c5_b_y.DATA.safetyExt.theRTCM.msg1031[c5_i263];
  }

  for (c5_i264 = 0; c5_i264 < 20; c5_i264++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[56])
                 [2696])[2812])[c5_i264] =
      c5_b_y.DATA.safetyExt.theRTCM.msg1032[c5_i264];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])[0]
    = c5_b_y.DATA.status.lights;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])[4]
    = c5_b_y.DATA.status.lightBar;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[8])[0] =
    c5_b_y.DATA.status.wipers.statusFront;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[8])[4] =
    c5_b_y.DATA.status.wipers.rateFront;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[8])[8] =
    c5_b_y.DATA.status.wipers.statusRear;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[8])[12] =
    c5_b_y.DATA.status.wipers.rateRear;
  for (c5_i265 = 0; c5_i265 < 2; c5_i265++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])
      [24])[c5_i265] = c5_b_y.DATA.status.brakeStatus[c5_i265];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])[28]
    = c5_b_y.DATA.status.brakePressure;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])[32]
    = c5_b_y.DATA.status.roadFriction;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])[36]
    = c5_b_y.DATA.status.sunData;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])[40]
    = c5_b_y.DATA.status.rainData;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])[44]
    = c5_b_y.DATA.status.airTemp;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])[48]
    = c5_b_y.DATA.status.airPres;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[56])[0] =
    c5_b_y.DATA.status.steering.angle;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[56])[4] =
    c5_b_y.DATA.status.steering.confidence;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[56])[8] =
    c5_b_y.DATA.status.steering.rate;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[56])[12] =
    c5_b_y.DATA.status.steering.wheels;
  for (c5_i266 = 0; c5_i266 < 7; c5_i266++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
        &((char_T *)chartInstance->c5_y)[8])[5584])[72])[0])[c5_i266] =
      c5_b_y.DATA.status.accelSets.accel4way[c5_i266];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[72])[8] =
    c5_b_y.DATA.status.accelSets.vertAccelThres;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[72])[12] =
    c5_b_y.DATA.status.accelSets.yawRateCon;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[72])[16] =
    c5_b_y.DATA.status.accelSets.hozAccelCon;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelConfidence *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)
        [8])[5584])[72])[24])[0])[0] =
    c5_b_y.DATA.status.accelSets.confidenceSet.accelConfidence.yawRate;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelConfidence *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)
        [8])[5584])[72])[24])[0])[4] =
    c5_b_y.DATA.status.accelSets.confidenceSet.accelConfidence.acceleration;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelConfidence *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)
        [8])[5584])[72])[24])[0])[8] =
    c5_b_y.DATA.status.accelSets.confidenceSet.accelConfidence.steeringWheelAngle;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)
        [8])[5584])[72])[24])[16] =
    c5_b_y.DATA.status.accelSets.confidenceSet.speedConfidence;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)
        [8])[5584])[72])[24])[20] =
    c5_b_y.DATA.status.accelSets.confidenceSet.timeConfidence;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)
        [8])[5584])[72])[24])[24] =
    c5_b_y.DATA.status.accelSets.confidenceSet.posConfidence;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)
        [8])[5584])[72])[24])[28] =
    c5_b_y.DATA.status.accelSets.confidenceSet.steerConfidence;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)
        [8])[5584])[72])[24])[32] =
    c5_b_y.DATA.status.accelSets.confidenceSet.throttleConfidence;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[136])[0] =
    c5_b_y.DATA.status.object.obDist;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[136])[4] =
    c5_b_y.DATA.status.object.obDirect;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[136])[8])[0] = c5_b_y.DATA.status.object.dateTime.year;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[136])[8])[4] = c5_b_y.DATA.status.object.dateTime.month;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[136])[8])[8] = c5_b_y.DATA.status.object.dateTime.day;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[136])[8])[12] = c5_b_y.DATA.status.object.dateTime.hour;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[136])[8])[16] = c5_b_y.DATA.status.object.dateTime.minute;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[136])[8])[20] = c5_b_y.DATA.status.object.dateTime.second;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[168])[0])[0] = c5_b_y.DATA.status.fullPos.utcTime.year;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[168])[0])[4] = c5_b_y.DATA.status.fullPos.utcTime.month;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[168])[0])[8] = c5_b_y.DATA.status.fullPos.utcTime.day;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[168])[0])[12] = c5_b_y.DATA.status.fullPos.utcTime.hour;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[168])[0])[16] = c5_b_y.DATA.status.fullPos.utcTime.minute;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])
    [5584])[168])[0])[20] = c5_b_y.DATA.status.fullPos.utcTime.second;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[168])[24] =
    c5_b_y.DATA.status.fullPos.longitude;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[168])[28] =
    c5_b_y.DATA.status.fullPos.latitude;
  for (c5_i267 = 0; c5_i267 < 2; c5_i267++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
        &((char_T *)chartInstance->c5_y)[8])[5584])[168])[32])[c5_i267] =
      c5_b_y.DATA.status.fullPos.elevation[c5_i267];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[168])[36] =
    c5_b_y.DATA.status.fullPos.heading;
  for (c5_i268 = 0; c5_i268 < 2; c5_i268++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
        &((char_T *)chartInstance->c5_y)[8])[5584])[168])[40])[c5_i268] =
      c5_b_y.DATA.status.fullPos.speed[c5_i268];
  }

  for (c5_i269 = 0; c5_i269 < 4; c5_i269++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
        &((char_T *)chartInstance->c5_y)[8])[5584])[168])[42])[c5_i269] =
      c5_b_y.DATA.status.fullPos.posAccuracy[c5_i269];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[168])[48] =
    c5_b_y.DATA.status.fullPos.timeConfidence;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[168])[52] =
    c5_b_y.DATA.status.fullPos.posConfidence;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[168])[53] =
    c5_b_y.DATA.status.fullPos.speedConfidence;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])
    [224] = c5_b_y.DATA.status.throttlePos;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])
    [228] = c5_b_y.DATA.status.speedHeadC;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])
    [232] = c5_b_y.DATA.status.speedC;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[240])[0] =
    c5_b_y.DATA.status.vehicleData.height;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_bumpers *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[240])[8])[0] =
    c5_b_y.DATA.status.vehicleData.bumpers.frnt;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_bumpers *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[240])[8])[4] =
    c5_b_y.DATA.status.vehicleData.bumpers.rear;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[240])[16] =
    c5_b_y.DATA.status.vehicleData.mass;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[240])[20] =
    c5_b_y.DATA.status.vehicleData.trailerWeight;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[240])[24] =
    c5_b_y.DATA.status.vehicleData.type;
  for (c5_i270 = 0; c5_i270 < 63; c5_i270++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
        &((char_T *)chartInstance->c5_y)[8])[5584])[272])[0])[c5_i270] =
      c5_b_y.DATA.status.vehicleIdent.name[c5_i270];
  }

  for (c5_i271 = 0; c5_i271 < 17; c5_i271++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
        &((char_T *)chartInstance->c5_y)[8])[5584])[272])[63])[c5_i271] =
      c5_b_y.DATA.status.vehicleIdent.vin[c5_i271];
  }

  for (c5_i272 = 0; c5_i272 < 32; c5_i272++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
        &((char_T *)chartInstance->c5_y)[8])[5584])[272])[80])[c5_i272] =
      c5_b_y.DATA.status.vehicleIdent.ownerCode[c5_i272];
  }

  for (c5_i273 = 0; c5_i273 < 4; c5_i273++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
        &((char_T *)chartInstance->c5_y)[8])[5584])[272])[112])[c5_i273] =
      c5_b_y.DATA.status.vehicleIdent.id[c5_i273];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[272])[116] =
    c5_b_y.DATA.status.vehicleIdent.vehicleType;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleClass *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[272])[120])[0] =
    c5_b_y.DATA.status.vehicleIdent.vehicleClass.vGroup;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleClass *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[272])[120])[4] =
    c5_b_y.DATA.status.vehicleIdent.vehicleClass.rGroup;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleClass *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[272])[120])[8] =
    c5_b_y.DATA.status.vehicleIdent.vehicleClass.rEquip;
  for (c5_i274 = 0; c5_i274 < 16; c5_i274++) {
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_y)[8])[5584])[408])[0])[32 * (int32_T)
                  c5_i274])[0] = c5_b_y.DATA.status.j1939data.tires[c5_i274].
      location;
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_y)[8])[5584])[408])[0])[32 * (int32_T)
                  c5_i274])[4] = c5_b_y.DATA.status.j1939data.tires[c5_i274].
      pressure;
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_y)[8])[5584])[408])[0])[32 * (int32_T)
                  c5_i274])[8] = c5_b_y.DATA.status.j1939data.tires[c5_i274].
      temp;
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_y)[8])[5584])[408])[0])[32 * (int32_T)
                  c5_i274])[12] = c5_b_y.DATA.status.j1939data.tires[c5_i274].
      wheelSensorStatus;
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_y)[8])[5584])[408])[0])[32 * (int32_T)
                  c5_i274])[16] = c5_b_y.DATA.status.j1939data.tires[c5_i274].
      wheelEndElectFault;
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_y)[8])[5584])[408])[0])[32 * (int32_T)
                  c5_i274])[20] = c5_b_y.DATA.status.j1939data.tires[c5_i274].
      leakageRate;
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c5_y)[8])[5584])[408])[0])[32 * (int32_T)
                  c5_i274])[24] = c5_b_y.DATA.status.j1939data.tires[c5_i274].
      detection;
  }

  for (c5_i275 = 0; c5_i275 < 16; c5_i275++) {
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_axle *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_axle *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])
      [408])[512])[8 * (int32_T)c5_i275])[0] =
      c5_b_y.DATA.status.j1939data.axle[c5_i275].location;
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_axle *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_axle *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])
      [408])[512])[8 * (int32_T)c5_i275])[4] =
      c5_b_y.DATA.status.j1939data.axle[c5_i275].weight;
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[408])[640] =
    c5_b_y.DATA.status.j1939data.trailerWeight;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[408])[644] =
    c5_b_y.DATA.status.j1939data.cargoWeight;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[408])[648] =
    c5_b_y.DATA.status.j1939data.steeringAxleTemperature;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[408])[652] =
    c5_b_y.DATA.status.j1939data.driveAxleLocation;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[408])[656] =
    c5_b_y.DATA.status.j1939data.driveAxleLiftAirPressure;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[408])[660] =
    c5_b_y.DATA.status.j1939data.driveAxleTemperature;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[408])[664] =
    c5_b_y.DATA.status.j1939data.driveAxleLubePressure;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[408])[668] =
    c5_b_y.DATA.status.j1939data.steeringAxleLubePressure;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[1080])[0] =
    c5_b_y.DATA.status.weatherReport.isRaining;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[1080])[4] =
    c5_b_y.DATA.status.weatherReport.rainRate;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[1080])[8] =
    c5_b_y.DATA.status.weatherReport.precipSituation;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[1080])[12] =
    c5_b_y.DATA.status.weatherReport.solarRadiation;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c5_y)[8])[5584])[1080])[16] =
    c5_b_y.DATA.status.weatherReport.friction;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c5_y)[8])[5584])
    [1104] = c5_b_y.DATA.status.gpsStatus;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c5_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
}

static void mdl_start_c5_Jan22_DLforACC_cs(SFc5_Jan22_DLforACC_csInstanceStruct *
  chartInstance)
{
  chartInstance->c5_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sim_mode_is_external(chartInstance->S);
}

static void initSimStructsc5_Jan22_DLforACC_cs
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber)
{
  (void)(c5_machineNumber);
  (void)(c5_chartNumber);
  (void)(c5_instanceNumber);
  _SFD_SCRIPT_TRANSLATION(c5_chartNumber, c5_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\s2lohras\\PreScan_Experiments\\Jan22_DLforACC\\V2X_BSM_expander.m"));
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData;
  real_T c5_b_u;
  const mxArray *c5_b_y = NULL;
  SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc5_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_mxArrayOutData = NULL;
  c5_b_u = *(real_T *)c5_inData;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static real_T c5_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_b_y;
  real_T c5_d0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), &c5_d0, 1, 0, 0U, 0, 0U, 0);
  c5_b_y = c5_d0;
  sf_mex_destroy(&c5_b_u);
  return c5_b_y;
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_nargin;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_b_y;
  SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc5_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c5_nargin = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = (const char *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_b_y = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_nargin), &c5_thisId);
  sf_mex_destroy(&c5_nargin);
  *(real_T *)c5_outData = c5_b_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_emlrt_marshallOut(SFc5_Jan22_DLforACC_csInstanceStruct *
  chartInstance, const c5_PRESCAN_V2X_USER_BSM_DATA c5_b_u)
{
  const mxArray *c5_b_y;
  static const char * c5_sv9[14] = { "msgID", "msgCnt", "id", "secMark",
    "latitude", "longitude", "elev", "accuracy", "speed", "heading", "angle",
    "accelSet", "brakes", "size" };

  int32_T c5_c_u;
  const mxArray *c5_c_y = NULL;
  int32_T c5_d_u;
  const mxArray *c5_d_y = NULL;
  int32_T c5_i276;
  const mxArray *c5_e_y = NULL;
  int8_T c5_e_u[4];
  int32_T c5_f_u;
  const mxArray *c5_f_y = NULL;
  int32_T c5_g_u;
  const mxArray *c5_g_y = NULL;
  int32_T c5_h_u;
  const mxArray *c5_h_y = NULL;
  int32_T c5_i277;
  const mxArray *c5_i_y = NULL;
  int8_T c5_i_u[2];
  int32_T c5_i278;
  const mxArray *c5_j_y = NULL;
  int32_T c5_i279;
  const mxArray *c5_k_y = NULL;
  int32_T c5_j_u;
  const mxArray *c5_l_y = NULL;
  int8_T c5_k_u;
  const mxArray *c5_m_y = NULL;
  int32_T c5_i280;
  const mxArray *c5_n_y = NULL;
  int8_T c5_l_u[7];
  int32_T c5_i281;
  const mxArray *c5_o_y = NULL;
  c5_PRESCAN_V2X_USER_BSM_size c5_m_u;
  const mxArray *c5_p_y = NULL;
  int32_T c5_n_u;
  const mxArray *c5_q_y = NULL;
  int32_T c5_o_u;
  const mxArray *c5_r_y = NULL;
  (void)chartInstance;
  c5_b_y = NULL;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_createstruct("structure", 14, c5_sv9, 2, 1, 1),
                false);
  c5_c_u = c5_b_u.msgID;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_c_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "msgID", c5_c_y, 0);
  c5_d_u = c5_b_u.msgCnt;
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", &c5_d_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "msgCnt", c5_d_y, 1);
  for (c5_i276 = 0; c5_i276 < 4; c5_i276++) {
    c5_e_u[c5_i276] = c5_b_u.id[c5_i276];
  }

  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_e_u, 2, 0U, 1U, 0U, 1, 4), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "id", c5_e_y, 2);
  c5_f_u = c5_b_u.secMark;
  c5_f_y = NULL;
  sf_mex_assign(&c5_f_y, sf_mex_create("y", &c5_f_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "secMark", c5_f_y, 3);
  c5_g_u = c5_b_u.latitude;
  c5_g_y = NULL;
  sf_mex_assign(&c5_g_y, sf_mex_create("y", &c5_g_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "latitude", c5_g_y, 4);
  c5_h_u = c5_b_u.longitude;
  c5_h_y = NULL;
  sf_mex_assign(&c5_h_y, sf_mex_create("y", &c5_h_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "longitude", c5_h_y, 5);
  for (c5_i277 = 0; c5_i277 < 2; c5_i277++) {
    c5_i_u[c5_i277] = c5_b_u.elev[c5_i277];
  }

  c5_i_y = NULL;
  sf_mex_assign(&c5_i_y, sf_mex_create("y", c5_i_u, 2, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "elev", c5_i_y, 6);
  for (c5_i278 = 0; c5_i278 < 4; c5_i278++) {
    c5_e_u[c5_i278] = c5_b_u.accuracy[c5_i278];
  }

  c5_j_y = NULL;
  sf_mex_assign(&c5_j_y, sf_mex_create("y", c5_e_u, 2, 0U, 1U, 0U, 1, 4), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "accuracy", c5_j_y, 7);
  for (c5_i279 = 0; c5_i279 < 2; c5_i279++) {
    c5_i_u[c5_i279] = c5_b_u.speed[c5_i279];
  }

  c5_k_y = NULL;
  sf_mex_assign(&c5_k_y, sf_mex_create("y", c5_i_u, 2, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "speed", c5_k_y, 8);
  c5_j_u = c5_b_u.heading;
  c5_l_y = NULL;
  sf_mex_assign(&c5_l_y, sf_mex_create("y", &c5_j_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "heading", c5_l_y, 9);
  c5_k_u = c5_b_u.angle;
  c5_m_y = NULL;
  sf_mex_assign(&c5_m_y, sf_mex_create("y", &c5_k_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "angle", c5_m_y, 10);
  for (c5_i280 = 0; c5_i280 < 7; c5_i280++) {
    c5_l_u[c5_i280] = c5_b_u.accelSet[c5_i280];
  }

  c5_n_y = NULL;
  sf_mex_assign(&c5_n_y, sf_mex_create("y", c5_l_u, 2, 0U, 1U, 0U, 1, 7), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "accelSet", c5_n_y, 11);
  for (c5_i281 = 0; c5_i281 < 2; c5_i281++) {
    c5_i_u[c5_i281] = c5_b_u.brakes[c5_i281];
  }

  c5_o_y = NULL;
  sf_mex_assign(&c5_o_y, sf_mex_create("y", c5_i_u, 2, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "brakes", c5_o_y, 12);
  c5_m_u = c5_b_u.size;
  c5_p_y = NULL;
  sf_mex_assign(&c5_p_y, sf_mex_createstruct("structure", 2, c5_sv1, 2, 1, 1),
                false);
  c5_n_u = c5_m_u.width;
  c5_q_y = NULL;
  sf_mex_assign(&c5_q_y, sf_mex_create("y", &c5_n_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_p_y, 0, "width", c5_q_y, 0);
  c5_o_u = c5_m_u.length;
  c5_r_y = NULL;
  sf_mex_assign(&c5_r_y, sf_mex_create("y", &c5_o_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_p_y, 0, "length", c5_r_y, 1);
  sf_mex_setfieldbynum(c5_b_y, 0, "size", c5_p_y, 13);
  return c5_b_y;
}

static const mxArray *c5_b_emlrt_marshallOut
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const int32_T c5_b_u)
{
  const mxArray *c5_b_y = NULL;
  (void)chartInstance;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 6, 0U, 0U, 0U, 0), false);
  return c5_b_y;
}

static const mxArray *c5_c_emlrt_marshallOut
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const int8_T c5_b_u[2])
{
  const mxArray *c5_b_y = NULL;
  (void)chartInstance;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_u, 2, 0U, 1U, 0U, 1, 2), false);
  return c5_b_y;
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData;
  c5_PRESCAN_V2X_USER_BSM_MESSAGE c5_b_u;
  const mxArray *c5_b_y = NULL;
  PRESCAN_HEADER c5_c_u;
  const mxArray *c5_c_y = NULL;
  static const char * c5_sv10[1] = { "valid" };

  boolean_T c5_d_u;
  const mxArray *c5_d_y = NULL;
  SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc5_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_mxArrayOutData = NULL;
  c5_b_u = *(c5_PRESCAN_V2X_USER_BSM_MESSAGE *)c5_inData;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_createstruct("structure", 2, c5_sv0, 2, 1, 1),
                false);
  c5_c_u = c5_b_u.HEADER;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_createstruct("structure", 1, c5_sv10, 2, 1, 1),
                false);
  c5_d_u = c5_c_u.valid;
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", &c5_d_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_c_y, 0, "valid", c5_d_y, 0);
  sf_mex_setfieldbynum(c5_b_y, 0, "HEADER", c5_c_y, 0);
  sf_mex_setfieldbynum(c5_b_y, 0, "DATA", c5_emlrt_marshallOut(chartInstance,
    c5_b_u.DATA), 1);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_d_emlrt_marshallOut
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const
   PRESCAN_V2X_FIXED_BSM_DATA *c5_b_u)
{
  const mxArray *c5_b_y;
  static const char * c5_sv11[16] = { "msgID", "msgCnt", "id", "secMark",
    "latitude", "longitude", "elev", "accuracy", "speed", "heading", "angle",
    "accelSet", "brakes", "size", "safetyExt", "status" };

  int32_T c5_c_u;
  const mxArray *c5_c_y = NULL;
  int32_T c5_d_u;
  const mxArray *c5_d_y = NULL;
  int32_T c5_i282;
  const mxArray *c5_e_y = NULL;
  int8_T c5_e_u[4];
  int32_T c5_f_u;
  const mxArray *c5_f_y = NULL;
  int32_T c5_g_u;
  const mxArray *c5_g_y = NULL;
  int32_T c5_h_u;
  const mxArray *c5_h_y = NULL;
  int32_T c5_i283;
  const mxArray *c5_i_y = NULL;
  int8_T c5_i_u[2];
  int32_T c5_i284;
  const mxArray *c5_j_y = NULL;
  int32_T c5_i285;
  const mxArray *c5_k_y = NULL;
  int32_T c5_j_u;
  const mxArray *c5_l_y = NULL;
  int8_T c5_k_u;
  const mxArray *c5_m_y = NULL;
  int32_T c5_i286;
  const mxArray *c5_n_y = NULL;
  int8_T c5_l_u[7];
  int32_T c5_i287;
  const mxArray *c5_o_y = NULL;
  PRESCAN_V2X_FIXED_BSM_size c5_m_u;
  const mxArray *c5_p_y = NULL;
  int32_T c5_n_u;
  const mxArray *c5_q_y = NULL;
  int32_T c5_o_u;
  const mxArray *c5_r_y = NULL;
  c5_b_y = NULL;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_createstruct("structure", 16, c5_sv11, 2, 1, 1),
                false);
  c5_c_u = c5_b_u->msgID;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_c_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "msgID", c5_c_y, 0);
  c5_d_u = c5_b_u->msgCnt;
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", &c5_d_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "msgCnt", c5_d_y, 1);
  for (c5_i282 = 0; c5_i282 < 4; c5_i282++) {
    c5_e_u[c5_i282] = c5_b_u->id[c5_i282];
  }

  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_e_u, 2, 0U, 1U, 0U, 1, 4), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "id", c5_e_y, 2);
  c5_f_u = c5_b_u->secMark;
  c5_f_y = NULL;
  sf_mex_assign(&c5_f_y, sf_mex_create("y", &c5_f_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "secMark", c5_f_y, 3);
  c5_g_u = c5_b_u->latitude;
  c5_g_y = NULL;
  sf_mex_assign(&c5_g_y, sf_mex_create("y", &c5_g_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "latitude", c5_g_y, 4);
  c5_h_u = c5_b_u->longitude;
  c5_h_y = NULL;
  sf_mex_assign(&c5_h_y, sf_mex_create("y", &c5_h_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "longitude", c5_h_y, 5);
  for (c5_i283 = 0; c5_i283 < 2; c5_i283++) {
    c5_i_u[c5_i283] = c5_b_u->elev[c5_i283];
  }

  c5_i_y = NULL;
  sf_mex_assign(&c5_i_y, sf_mex_create("y", c5_i_u, 2, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "elev", c5_i_y, 6);
  for (c5_i284 = 0; c5_i284 < 4; c5_i284++) {
    c5_e_u[c5_i284] = c5_b_u->accuracy[c5_i284];
  }

  c5_j_y = NULL;
  sf_mex_assign(&c5_j_y, sf_mex_create("y", c5_e_u, 2, 0U, 1U, 0U, 1, 4), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "accuracy", c5_j_y, 7);
  for (c5_i285 = 0; c5_i285 < 2; c5_i285++) {
    c5_i_u[c5_i285] = c5_b_u->speed[c5_i285];
  }

  c5_k_y = NULL;
  sf_mex_assign(&c5_k_y, sf_mex_create("y", c5_i_u, 2, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "speed", c5_k_y, 8);
  c5_j_u = c5_b_u->heading;
  c5_l_y = NULL;
  sf_mex_assign(&c5_l_y, sf_mex_create("y", &c5_j_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "heading", c5_l_y, 9);
  c5_k_u = c5_b_u->angle;
  c5_m_y = NULL;
  sf_mex_assign(&c5_m_y, sf_mex_create("y", &c5_k_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "angle", c5_m_y, 10);
  for (c5_i286 = 0; c5_i286 < 7; c5_i286++) {
    c5_l_u[c5_i286] = c5_b_u->accelSet[c5_i286];
  }

  c5_n_y = NULL;
  sf_mex_assign(&c5_n_y, sf_mex_create("y", c5_l_u, 2, 0U, 1U, 0U, 1, 7), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "accelSet", c5_n_y, 11);
  for (c5_i287 = 0; c5_i287 < 2; c5_i287++) {
    c5_i_u[c5_i287] = c5_b_u->brakes[c5_i287];
  }

  c5_o_y = NULL;
  sf_mex_assign(&c5_o_y, sf_mex_create("y", c5_i_u, 2, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "brakes", c5_o_y, 12);
  c5_m_u = c5_b_u->size;
  c5_p_y = NULL;
  sf_mex_assign(&c5_p_y, sf_mex_createstruct("structure", 2, c5_sv1, 2, 1, 1),
                false);
  c5_n_u = c5_m_u.width;
  c5_q_y = NULL;
  sf_mex_assign(&c5_q_y, sf_mex_create("y", &c5_n_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_p_y, 0, "width", c5_q_y, 0);
  c5_o_u = c5_m_u.length;
  c5_r_y = NULL;
  sf_mex_assign(&c5_r_y, sf_mex_create("y", &c5_o_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_p_y, 0, "length", c5_r_y, 1);
  sf_mex_setfieldbynum(c5_b_y, 0, "size", c5_p_y, 13);
  sf_mex_setfieldbynum(c5_b_y, 0, "safetyExt", c5_e_emlrt_marshallOut
                       (chartInstance, &c5_b_u->safetyExt), 14);
  sf_mex_setfieldbynum(c5_b_y, 0, "status", c5_g_emlrt_marshallOut(chartInstance,
    &c5_b_u->status), 15);
  return c5_b_y;
}

static const mxArray *c5_e_emlrt_marshallOut
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const
   PRESCAN_V2X_FIXED_BSM_safetyExt *c5_b_u)
{
  const mxArray *c5_b_y;
  static const char * c5_sv12[4] = { "events", "pathHistory", "pathPrediction",
    "theRTCM" };

  int32_T c5_c_u;
  const mxArray *c5_c_y = NULL;
  PRESCAN_V2X_FIXED_BSM_pathHistory c5_d_u;
  const mxArray *c5_d_y = NULL;
  static const char * c5_sv13[4] = { "initialPosition", "currGPSstatus",
    "itemCnt", "crumbData" };

  PRESCAN_V2X_FIXED_BSM_initialPosition c5_e_u;
  const mxArray *c5_e_y = NULL;
  int32_T c5_f_u;
  const mxArray *c5_f_y = NULL;
  int32_T c5_g_u;
  const mxArray *c5_g_y = NULL;
  int32_T c5_i288;
  const mxArray *c5_h_y = NULL;
  int8_T c5_h_u[2];
  int32_T c5_i_u;
  const mxArray *c5_i_y = NULL;
  int32_T c5_i289;
  const mxArray *c5_j_y = NULL;
  int32_T c5_i290;
  const mxArray *c5_k_y = NULL;
  int8_T c5_j_u[4];
  int32_T c5_k_u;
  const mxArray *c5_l_y = NULL;
  int8_T c5_l_u;
  const mxArray *c5_m_y = NULL;
  int8_T c5_m_u;
  const mxArray *c5_n_y = NULL;
  int32_T c5_n_u;
  const mxArray *c5_o_y = NULL;
  int32_T c5_o_u;
  const mxArray *c5_p_y = NULL;
  PRESCAN_V2X_FIXED_BSM_crumbData c5_p_u;
  const mxArray *c5_q_y = NULL;
  static const char * c5_sv14[10] = { "pathHistoryPointSets_01",
    "pathHistoryPointSets_02", "pathHistoryPointSets_03",
    "pathHistoryPointSets_04", "pathHistoryPointSets_05",
    "pathHistoryPointSets_06", "pathHistoryPointSets_07",
    "pathHistoryPointSets_08", "pathHistoryPointSets_09",
    "pathHistoryPointSets_10" };

  int32_T c5_i291;
  const mxArray *c5_r_y = NULL;
  PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 c5_q_u[23];
  int32_T c5_iv0[1];
  static const char * c5_sv15[7] = { "latOffset", "longOffset",
    "elevationOffset", "timeOffset", "posAccuracy", "heading", "speed" };

  int32_T c5_i292;
  const PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *c5_r2;
  int32_T c5_i293;
  int32_T c5_r_u;
  const mxArray *c5_s_y = NULL;
  const mxArray *c5_t_y = NULL;
  int8_T c5_s_u[345];
  int32_T c5_t_u;
  const mxArray *c5_u_y = NULL;
  int32_T c5_i294;
  int32_T c5_u_u;
  const mxArray *c5_v_y = NULL;
  int8_T c5_v_u[276];
  const mxArray *c5_w_y = NULL;
  int32_T c5_i295;
  int32_T c5_w_u;
  const mxArray *c5_x_y = NULL;
  const mxArray *c5_y_y = NULL;
  int8_T c5_x_u[184];
  int32_T c5_i296;
  int32_T c5_i297;
  const mxArray *c5_ab_y = NULL;
  const mxArray *c5_bb_y = NULL;
  int8_T c5_y_u[230];
  int32_T c5_ab_u;
  const mxArray *c5_cb_y = NULL;
  int32_T c5_i298;
  int32_T c5_i299;
  const mxArray *c5_db_y = NULL;
  int8_T c5_bb_u[138];
  const mxArray *c5_eb_y = NULL;
  int32_T c5_i300;
  const mxArray *c5_fb_y = NULL;
  int8_T c5_cb_u[242];
  int32_T c5_i301;
  const mxArray *c5_gb_y = NULL;
  int8_T c5_db_u[161];
  int32_T c5_i302;
  const mxArray *c5_hb_y = NULL;
  int8_T c5_eb_u[196];
  int32_T c5_i303;
  const mxArray *c5_ib_y = NULL;
  int8_T c5_fb_u[104];
  PRESCAN_V2X_FIXED_BSM_pathPrediction c5_gb_u;
  const mxArray *c5_jb_y = NULL;
  static const char * c5_sv16[2] = { "radiusOfCurve", "confidence" };

  int32_T c5_hb_u;
  const mxArray *c5_kb_y = NULL;
  int32_T c5_ib_u;
  const mxArray *c5_lb_y = NULL;
  PRESCAN_V2X_FIXED_BSM_theRTCM c5_jb_u;
  const mxArray *c5_mb_y = NULL;
  static const char * c5_sv17[32] = { "anchorPoint", "rtcmHeader", "msg1001",
    "msg1002", "msg1003", "msg1004", "msg1005", "msg1006", "msg1007", "msg1008",
    "msg1009", "msg1010", "msg1011", "msg1012", "msg1013", "msg1014", "msg1015",
    "msg1016", "msg1017", "msg1019", "msg1020", "msg1021", "msg1022", "msg1023",
    "msg1024", "msg1025", "msg1026", "msg1027", "msg1029", "msg1030", "msg1031",
    "msg1032" };

  PRESCAN_V2X_FIXED_BSM_anchorPoint c5_kb_u;
  const mxArray *c5_nb_y = NULL;
  int32_T c5_lb_u;
  const mxArray *c5_ob_y = NULL;
  int32_T c5_mb_u;
  const mxArray *c5_pb_y = NULL;
  int32_T c5_i304;
  const mxArray *c5_qb_y = NULL;
  int32_T c5_nb_u;
  const mxArray *c5_rb_y = NULL;
  int32_T c5_i305;
  const mxArray *c5_sb_y = NULL;
  int32_T c5_i306;
  const mxArray *c5_tb_y = NULL;
  int32_T c5_ob_u;
  const mxArray *c5_ub_y = NULL;
  int8_T c5_pb_u;
  const mxArray *c5_vb_y = NULL;
  int8_T c5_qb_u;
  const mxArray *c5_wb_y = NULL;
  int32_T c5_i307;
  const mxArray *c5_xb_y = NULL;
  int8_T c5_rb_u[5];
  int32_T c5_i308;
  const mxArray *c5_yb_y = NULL;
  int8_T c5_sb_u[124];
  int32_T c5_i309;
  const mxArray *c5_ac_y = NULL;
  int8_T c5_tb_u[156];
  int32_T c5_i310;
  const mxArray *c5_bc_y = NULL;
  int8_T c5_ub_u[210];
  int32_T c5_i311;
  const mxArray *c5_cc_y = NULL;
  int8_T c5_vb_u[258];
  int32_T c5_i312;
  const mxArray *c5_dc_y = NULL;
  int8_T c5_wb_u[19];
  int32_T c5_i313;
  const mxArray *c5_ec_y = NULL;
  int8_T c5_xb_u[21];
  int32_T c5_i314;
  const mxArray *c5_fc_y = NULL;
  int8_T c5_yb_u[36];
  int32_T c5_i315;
  const mxArray *c5_gc_y = NULL;
  int8_T c5_ac_u[68];
  int32_T c5_i316;
  const mxArray *c5_hc_y = NULL;
  int8_T c5_bc_u[136];
  int32_T c5_i317;
  const mxArray *c5_ic_y = NULL;
  int8_T c5_cc_u[166];
  int32_T c5_i318;
  const mxArray *c5_jc_y = NULL;
  int8_T c5_dc_u[222];
  int32_T c5_i319;
  const mxArray *c5_kc_y = NULL;
  int8_T c5_ec_u[268];
  int32_T c5_i320;
  const mxArray *c5_lc_y = NULL;
  int8_T c5_fc_u[27];
  int32_T c5_i321;
  const mxArray *c5_mc_y = NULL;
  int8_T c5_gc_u[15];
  int32_T c5_i322;
  const mxArray *c5_nc_y = NULL;
  int8_T c5_hc_u[69];
  int32_T c5_i323;
  const mxArray *c5_oc_y = NULL;
  int8_T c5_ic_u[81];
  int32_T c5_i324;
  const mxArray *c5_pc_y = NULL;
  int8_T c5_jc_u[115];
  int32_T c5_i325;
  const mxArray *c5_qc_y = NULL;
  int8_T c5_kc_u[62];
  int32_T c5_i326;
  const mxArray *c5_rc_y = NULL;
  int8_T c5_lc_u[45];
  int32_T c5_i327;
  const mxArray *c5_sc_y = NULL;
  int32_T c5_i328;
  const mxArray *c5_tc_y = NULL;
  int8_T c5_mc_u[75];
  int32_T c5_i329;
  const mxArray *c5_uc_y = NULL;
  int8_T c5_nc_u[73];
  int32_T c5_i330;
  const mxArray *c5_vc_y = NULL;
  int8_T c5_oc_u[74];
  int32_T c5_i331;
  const mxArray *c5_wc_y = NULL;
  int8_T c5_pc_u[25];
  int32_T c5_i332;
  const mxArray *c5_xc_y = NULL;
  int8_T c5_qc_u[30];
  int32_T c5_i333;
  const mxArray *c5_yc_y = NULL;
  int8_T c5_rc_u[33];
  int32_T c5_i334;
  const mxArray *c5_ad_y = NULL;
  int32_T c5_i335;
  const mxArray *c5_bd_y = NULL;
  int8_T c5_sc_u[105];
  int32_T c5_i336;
  const mxArray *c5_cd_y = NULL;
  int8_T c5_tc_u[107];
  int32_T c5_i337;
  const mxArray *c5_dd_y = NULL;
  int8_T c5_uc_u[20];
  c5_b_y = NULL;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_createstruct("structure", 4, c5_sv12, 2, 1, 1),
                false);
  c5_c_u = c5_b_u->events;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_c_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "events", c5_c_y, 0);
  c5_d_u = c5_b_u->pathHistory;
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_createstruct("structure", 4, c5_sv13, 2, 1, 1),
                false);
  c5_e_u = c5_d_u.initialPosition;
  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_createstruct("structure", 10, c5_sv2, 2, 1, 1),
                false);
  sf_mex_setfieldbynum(c5_e_y, 0, "utcTime", c5_f_emlrt_marshallOut
                       (chartInstance, c5_e_u.utcTime), 0);
  c5_f_u = c5_e_u.longitude;
  c5_f_y = NULL;
  sf_mex_assign(&c5_f_y, sf_mex_create("y", &c5_f_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_e_y, 0, "longitude", c5_f_y, 1);
  c5_g_u = c5_e_u.latitude;
  c5_g_y = NULL;
  sf_mex_assign(&c5_g_y, sf_mex_create("y", &c5_g_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_e_y, 0, "latitude", c5_g_y, 2);
  for (c5_i288 = 0; c5_i288 < 2; c5_i288++) {
    c5_h_u[c5_i288] = c5_e_u.elevation[c5_i288];
  }

  c5_h_y = NULL;
  sf_mex_assign(&c5_h_y, sf_mex_create("y", c5_h_u, 2, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setfieldbynum(c5_e_y, 0, "elevation", c5_h_y, 3);
  c5_i_u = c5_e_u.heading;
  c5_i_y = NULL;
  sf_mex_assign(&c5_i_y, sf_mex_create("y", &c5_i_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_e_y, 0, "heading", c5_i_y, 4);
  for (c5_i289 = 0; c5_i289 < 2; c5_i289++) {
    c5_h_u[c5_i289] = c5_e_u.speed[c5_i289];
  }

  c5_j_y = NULL;
  sf_mex_assign(&c5_j_y, sf_mex_create("y", c5_h_u, 2, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setfieldbynum(c5_e_y, 0, "speed", c5_j_y, 5);
  for (c5_i290 = 0; c5_i290 < 4; c5_i290++) {
    c5_j_u[c5_i290] = c5_e_u.posAccuracy[c5_i290];
  }

  c5_k_y = NULL;
  sf_mex_assign(&c5_k_y, sf_mex_create("y", c5_j_u, 2, 0U, 1U, 0U, 1, 4), false);
  sf_mex_setfieldbynum(c5_e_y, 0, "posAccuracy", c5_k_y, 6);
  c5_k_u = c5_e_u.timeConfidence;
  c5_l_y = NULL;
  sf_mex_assign(&c5_l_y, sf_mex_create("y", &c5_k_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_e_y, 0, "timeConfidence", c5_l_y, 7);
  c5_l_u = c5_e_u.posConfidence;
  c5_m_y = NULL;
  sf_mex_assign(&c5_m_y, sf_mex_create("y", &c5_l_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_e_y, 0, "posConfidence", c5_m_y, 8);
  c5_m_u = c5_e_u.speedConfidence;
  c5_n_y = NULL;
  sf_mex_assign(&c5_n_y, sf_mex_create("y", &c5_m_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_e_y, 0, "speedConfidence", c5_n_y, 9);
  sf_mex_setfieldbynum(c5_d_y, 0, "initialPosition", c5_e_y, 0);
  c5_n_u = c5_d_u.currGPSstatus;
  c5_o_y = NULL;
  sf_mex_assign(&c5_o_y, sf_mex_create("y", &c5_n_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_d_y, 0, "currGPSstatus", c5_o_y, 1);
  c5_o_u = c5_d_u.itemCnt;
  c5_p_y = NULL;
  sf_mex_assign(&c5_p_y, sf_mex_create("y", &c5_o_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_d_y, 0, "itemCnt", c5_p_y, 2);
  c5_p_u = c5_d_u.crumbData;
  c5_q_y = NULL;
  sf_mex_assign(&c5_q_y, sf_mex_createstruct("structure", 10, c5_sv14, 2, 1, 1),
                false);
  for (c5_i291 = 0; c5_i291 < 23; c5_i291++) {
    c5_q_u[c5_i291] = c5_p_u.pathHistoryPointSets_01[c5_i291];
  }

  c5_r_y = NULL;
  c5_iv0[0] = 23;
  sf_mex_assign(&c5_r_y, sf_mex_createstructarray("structure", 1, c5_iv0, 7,
    c5_sv15), false);
  for (c5_i292 = 0; c5_i292 < 23; c5_i292++) {
    c5_r2 = &c5_q_u[c5_i292];
    c5_r_u = c5_r2->latOffset;
    c5_s_y = NULL;
    sf_mex_assign(&c5_s_y, sf_mex_create("y", &c5_r_u, 6, 0U, 0U, 0U, 0), false);
    sf_mex_setfieldbynum(c5_r_y, c5_i292, "latOffset", c5_s_y, 0);
    c5_t_u = c5_r2->longOffset;
    c5_u_y = NULL;
    sf_mex_assign(&c5_u_y, sf_mex_create("y", &c5_t_u, 6, 0U, 0U, 0U, 0), false);
    sf_mex_setfieldbynum(c5_r_y, c5_i292, "longOffset", c5_u_y, 1);
    c5_u_u = c5_r2->elevationOffset;
    c5_w_y = NULL;
    sf_mex_assign(&c5_w_y, sf_mex_create("y", &c5_u_u, 6, 0U, 0U, 0U, 0), false);
    sf_mex_setfieldbynum(c5_r_y, c5_i292, "elevationOffset", c5_w_y, 2);
    c5_w_u = c5_r2->timeOffset;
    c5_x_y = NULL;
    sf_mex_assign(&c5_x_y, sf_mex_create("y", &c5_w_u, 6, 0U, 0U, 0U, 0), false);
    sf_mex_setfieldbynum(c5_r_y, c5_i292, "timeOffset", c5_x_y, 3);
    for (c5_i296 = 0; c5_i296 < 4; c5_i296++) {
      c5_j_u[c5_i296] = c5_r2->posAccuracy[c5_i296];
    }

    c5_ab_y = NULL;
    sf_mex_assign(&c5_ab_y, sf_mex_create("y", c5_j_u, 2, 0U, 1U, 0U, 1, 4),
                  false);
    sf_mex_setfieldbynum(c5_r_y, c5_i292, "posAccuracy", c5_ab_y, 4);
    c5_ab_u = c5_r2->heading;
    c5_cb_y = NULL;
    sf_mex_assign(&c5_cb_y, sf_mex_create("y", &c5_ab_u, 6, 0U, 0U, 0U, 0),
                  false);
    sf_mex_setfieldbynum(c5_r_y, c5_i292, "heading", c5_cb_y, 5);
    for (c5_i299 = 0; c5_i299 < 2; c5_i299++) {
      c5_h_u[c5_i299] = c5_r2->speed[c5_i299];
    }

    c5_eb_y = NULL;
    sf_mex_assign(&c5_eb_y, sf_mex_create("y", c5_h_u, 2, 0U, 1U, 0U, 1, 2),
                  false);
    sf_mex_setfieldbynum(c5_r_y, c5_i292, "speed", c5_eb_y, 6);
  }

  sf_mex_setfieldbynum(c5_q_y, 0, "pathHistoryPointSets_01", c5_r_y, 0);
  for (c5_i293 = 0; c5_i293 < 345; c5_i293++) {
    c5_s_u[c5_i293] = c5_p_u.pathHistoryPointSets_02[c5_i293];
  }

  c5_t_y = NULL;
  sf_mex_assign(&c5_t_y, sf_mex_create("y", c5_s_u, 2, 0U, 1U, 0U, 1, 345),
                false);
  sf_mex_setfieldbynum(c5_q_y, 0, "pathHistoryPointSets_02", c5_t_y, 1);
  for (c5_i294 = 0; c5_i294 < 276; c5_i294++) {
    c5_v_u[c5_i294] = c5_p_u.pathHistoryPointSets_03[c5_i294];
  }

  c5_v_y = NULL;
  sf_mex_assign(&c5_v_y, sf_mex_create("y", c5_v_u, 2, 0U, 1U, 0U, 1, 276),
                false);
  sf_mex_setfieldbynum(c5_q_y, 0, "pathHistoryPointSets_03", c5_v_y, 2);
  for (c5_i295 = 0; c5_i295 < 184; c5_i295++) {
    c5_x_u[c5_i295] = c5_p_u.pathHistoryPointSets_04[c5_i295];
  }

  c5_y_y = NULL;
  sf_mex_assign(&c5_y_y, sf_mex_create("y", c5_x_u, 2, 0U, 1U, 0U, 1, 184),
                false);
  sf_mex_setfieldbynum(c5_q_y, 0, "pathHistoryPointSets_04", c5_y_y, 3);
  for (c5_i297 = 0; c5_i297 < 230; c5_i297++) {
    c5_y_u[c5_i297] = c5_p_u.pathHistoryPointSets_05[c5_i297];
  }

  c5_bb_y = NULL;
  sf_mex_assign(&c5_bb_y, sf_mex_create("y", c5_y_u, 2, 0U, 1U, 0U, 1, 230),
                false);
  sf_mex_setfieldbynum(c5_q_y, 0, "pathHistoryPointSets_05", c5_bb_y, 4);
  for (c5_i298 = 0; c5_i298 < 138; c5_i298++) {
    c5_bb_u[c5_i298] = c5_p_u.pathHistoryPointSets_06[c5_i298];
  }

  c5_db_y = NULL;
  sf_mex_assign(&c5_db_y, sf_mex_create("y", c5_bb_u, 2, 0U, 1U, 0U, 1, 138),
                false);
  sf_mex_setfieldbynum(c5_q_y, 0, "pathHistoryPointSets_06", c5_db_y, 5);
  for (c5_i300 = 0; c5_i300 < 242; c5_i300++) {
    c5_cb_u[c5_i300] = c5_p_u.pathHistoryPointSets_07[c5_i300];
  }

  c5_fb_y = NULL;
  sf_mex_assign(&c5_fb_y, sf_mex_create("y", c5_cb_u, 2, 0U, 1U, 0U, 1, 242),
                false);
  sf_mex_setfieldbynum(c5_q_y, 0, "pathHistoryPointSets_07", c5_fb_y, 6);
  for (c5_i301 = 0; c5_i301 < 161; c5_i301++) {
    c5_db_u[c5_i301] = c5_p_u.pathHistoryPointSets_08[c5_i301];
  }

  c5_gb_y = NULL;
  sf_mex_assign(&c5_gb_y, sf_mex_create("y", c5_db_u, 2, 0U, 1U, 0U, 1, 161),
                false);
  sf_mex_setfieldbynum(c5_q_y, 0, "pathHistoryPointSets_08", c5_gb_y, 7);
  for (c5_i302 = 0; c5_i302 < 196; c5_i302++) {
    c5_eb_u[c5_i302] = c5_p_u.pathHistoryPointSets_09[c5_i302];
  }

  c5_hb_y = NULL;
  sf_mex_assign(&c5_hb_y, sf_mex_create("y", c5_eb_u, 2, 0U, 1U, 0U, 1, 196),
                false);
  sf_mex_setfieldbynum(c5_q_y, 0, "pathHistoryPointSets_09", c5_hb_y, 8);
  for (c5_i303 = 0; c5_i303 < 104; c5_i303++) {
    c5_fb_u[c5_i303] = c5_p_u.pathHistoryPointSets_10[c5_i303];
  }

  c5_ib_y = NULL;
  sf_mex_assign(&c5_ib_y, sf_mex_create("y", c5_fb_u, 2, 0U, 1U, 0U, 1, 104),
                false);
  sf_mex_setfieldbynum(c5_q_y, 0, "pathHistoryPointSets_10", c5_ib_y, 9);
  sf_mex_setfieldbynum(c5_d_y, 0, "crumbData", c5_q_y, 3);
  sf_mex_setfieldbynum(c5_b_y, 0, "pathHistory", c5_d_y, 1);
  c5_gb_u = c5_b_u->pathPrediction;
  c5_jb_y = NULL;
  sf_mex_assign(&c5_jb_y, sf_mex_createstruct("structure", 2, c5_sv16, 2, 1, 1),
                false);
  c5_hb_u = c5_gb_u.radiusOfCurve;
  c5_kb_y = NULL;
  sf_mex_assign(&c5_kb_y, sf_mex_create("y", &c5_hb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_jb_y, 0, "radiusOfCurve", c5_kb_y, 0);
  c5_ib_u = c5_gb_u.confidence;
  c5_lb_y = NULL;
  sf_mex_assign(&c5_lb_y, sf_mex_create("y", &c5_ib_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_jb_y, 0, "confidence", c5_lb_y, 1);
  sf_mex_setfieldbynum(c5_b_y, 0, "pathPrediction", c5_jb_y, 2);
  c5_jb_u = c5_b_u->theRTCM;
  c5_mb_y = NULL;
  sf_mex_assign(&c5_mb_y, sf_mex_createstruct("structure", 32, c5_sv17, 2, 1, 1),
                false);
  c5_kb_u = c5_jb_u.anchorPoint;
  c5_nb_y = NULL;
  sf_mex_assign(&c5_nb_y, sf_mex_createstruct("structure", 10, c5_sv2, 2, 1, 1),
                false);
  sf_mex_setfieldbynum(c5_nb_y, 0, "utcTime", c5_f_emlrt_marshallOut
                       (chartInstance, c5_kb_u.utcTime), 0);
  c5_lb_u = c5_kb_u.longitude;
  c5_ob_y = NULL;
  sf_mex_assign(&c5_ob_y, sf_mex_create("y", &c5_lb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_nb_y, 0, "longitude", c5_ob_y, 1);
  c5_mb_u = c5_kb_u.latitude;
  c5_pb_y = NULL;
  sf_mex_assign(&c5_pb_y, sf_mex_create("y", &c5_mb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_nb_y, 0, "latitude", c5_pb_y, 2);
  for (c5_i304 = 0; c5_i304 < 2; c5_i304++) {
    c5_h_u[c5_i304] = c5_kb_u.elevation[c5_i304];
  }

  c5_qb_y = NULL;
  sf_mex_assign(&c5_qb_y, sf_mex_create("y", c5_h_u, 2, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setfieldbynum(c5_nb_y, 0, "elevation", c5_qb_y, 3);
  c5_nb_u = c5_kb_u.heading;
  c5_rb_y = NULL;
  sf_mex_assign(&c5_rb_y, sf_mex_create("y", &c5_nb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_nb_y, 0, "heading", c5_rb_y, 4);
  for (c5_i305 = 0; c5_i305 < 2; c5_i305++) {
    c5_h_u[c5_i305] = c5_kb_u.speed[c5_i305];
  }

  c5_sb_y = NULL;
  sf_mex_assign(&c5_sb_y, sf_mex_create("y", c5_h_u, 2, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setfieldbynum(c5_nb_y, 0, "speed", c5_sb_y, 5);
  for (c5_i306 = 0; c5_i306 < 4; c5_i306++) {
    c5_j_u[c5_i306] = c5_kb_u.posAccuracy[c5_i306];
  }

  c5_tb_y = NULL;
  sf_mex_assign(&c5_tb_y, sf_mex_create("y", c5_j_u, 2, 0U, 1U, 0U, 1, 4), false);
  sf_mex_setfieldbynum(c5_nb_y, 0, "posAccuracy", c5_tb_y, 6);
  c5_ob_u = c5_kb_u.timeConfidence;
  c5_ub_y = NULL;
  sf_mex_assign(&c5_ub_y, sf_mex_create("y", &c5_ob_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_nb_y, 0, "timeConfidence", c5_ub_y, 7);
  c5_pb_u = c5_kb_u.posConfidence;
  c5_vb_y = NULL;
  sf_mex_assign(&c5_vb_y, sf_mex_create("y", &c5_pb_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_nb_y, 0, "posConfidence", c5_vb_y, 8);
  c5_qb_u = c5_kb_u.speedConfidence;
  c5_wb_y = NULL;
  sf_mex_assign(&c5_wb_y, sf_mex_create("y", &c5_qb_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_nb_y, 0, "speedConfidence", c5_wb_y, 9);
  sf_mex_setfieldbynum(c5_mb_y, 0, "anchorPoint", c5_nb_y, 0);
  for (c5_i307 = 0; c5_i307 < 5; c5_i307++) {
    c5_rb_u[c5_i307] = c5_jb_u.rtcmHeader[c5_i307];
  }

  c5_xb_y = NULL;
  sf_mex_assign(&c5_xb_y, sf_mex_create("y", c5_rb_u, 2, 0U, 1U, 0U, 1, 5),
                false);
  sf_mex_setfieldbynum(c5_mb_y, 0, "rtcmHeader", c5_xb_y, 1);
  for (c5_i308 = 0; c5_i308 < 124; c5_i308++) {
    c5_sb_u[c5_i308] = c5_jb_u.msg1001[c5_i308];
  }

  c5_yb_y = NULL;
  sf_mex_assign(&c5_yb_y, sf_mex_create("y", c5_sb_u, 2, 0U, 1U, 0U, 1, 124),
                false);
  sf_mex_setfieldbynum(c5_mb_y, 0, "msg1001", c5_yb_y, 2);
  for (c5_i309 = 0; c5_i309 < 156; c5_i309++) {
    c5_tb_u[c5_i309] = c5_jb_u.msg1002[c5_i309];
  }

  c5_ac_y = NULL;
  sf_mex_assign(&c5_ac_y, sf_mex_create("y", c5_tb_u, 2, 0U, 1U, 0U, 1, 156),
                false);
  sf_mex_setfieldbynum(c5_mb_y, 0, "msg1002", c5_ac_y, 3);
  for (c5_i310 = 0; c5_i310 < 210; c5_i310++) {
    c5_ub_u[c5_i310] = c5_jb_u.msg1003[c5_i310];
  }

  c5_bc_y = NULL;
  sf_mex_assign(&c5_bc_y, sf_mex_create("y", c5_ub_u, 2, 0U, 1U, 0U, 1, 210),
                false);
  sf_mex_setfieldbynum(c5_mb_y, 0, "msg1003", c5_bc_y, 4);
  for (c5_i311 = 0; c5_i311 < 258; c5_i311++) {
    c5_vb_u[c5_i311] = c5_jb_u.msg1004[c5_i311];
  }

  c5_cc_y = NULL;
  sf_mex_assign(&c5_cc_y, sf_mex_create("y", c5_vb_u, 2, 0U, 1U, 0U, 1, 258),
                false);
  sf_mex_setfieldbynum(c5_mb_y, 0, "msg1004", c5_cc_y, 5);
  for (c5_i312 = 0; c5_i312 < 19; c5_i312++) {
    c5_wb_u[c5_i312] = c5_jb_u.msg1005[c5_i312];
  }

  c5_dc_y = NULL;
  sf_mex_assign(&c5_dc_y, sf_mex_create("y", c5_wb_u, 2, 0U, 1U, 0U, 1, 19),
                false);
  sf_mex_setfieldbynum(c5_mb_y, 0, "msg1005", c5_dc_y, 6);
  for (c5_i313 = 0; c5_i313 < 21; c5_i313++) {
    c5_xb_u[c5_i313] = c5_jb_u.msg1006[c5_i313];
  }

  c5_ec_y = NULL;
  sf_mex_assign(&c5_ec_y, sf_mex_create("y", c5_xb_u, 2, 0U, 1U, 0U, 1, 21),
                false);
  sf_mex_setfieldbynum(c5_mb_y, 0, "msg1006", c5_ec_y, 7);
  for (c5_i314 = 0; c5_i314 < 36; c5_i314++) {
    c5_yb_u[c5_i314] = c5_jb_u.msg1007[c5_i314];
  }

  c5_fc_y = NULL;
  sf_mex_assign(&c5_fc_y, sf_mex_create("y", c5_yb_u, 2, 0U, 1U, 0U, 1, 36),
                false);
  sf_mex_setfieldbynum(c5_mb_y, 0, "msg1007", c5_fc_y, 8);
  for (c5_i315 = 0; c5_i315 < 68; c5_i315++) {
    c5_ac_u[c5_i315] = c5_jb_u.msg1008[c5_i315];
  }

  c5_gc_y = NULL;
  sf_mex_assign(&c5_gc_y, sf_mex_create("y", c5_ac_u, 2, 0U, 1U, 0U, 1, 68),
                false);
  sf_mex_setfieldbynum(c5_mb_y, 0, "msg1008", c5_gc_y, 9);
  for (c5_i316 = 0; c5_i316 < 136; c5_i316++) {
    c5_bc_u[c5_i316] = c5_jb_u.msg1009[c5_i316];
  }

  c5_hc_y = NULL;
  sf_mex_assign(&c5_hc_y, sf_mex_create("y", c5_bc_u, 2, 0U, 1U, 0U, 1, 136),
                false);
  sf_mex_setfieldbynum(c5_mb_y, 0, "msg1009", c5_hc_y, 10);
  for (c5_i317 = 0; c5_i317 < 166; c5_i317++) {
    c5_cc_u[c5_i317] = c5_jb_u.msg1010[c5_i317];
  }

  c5_ic_y = NULL;
  sf_mex_assign(&c5_ic_y, sf_mex_create("y", c5_cc_u, 2, 0U, 1U, 0U, 1, 166),
                false);
  sf_mex_setfieldbynum(c5_mb_y, 0, "msg1010", c5_ic_y, 11);
  for (c5_i318 = 0; c5_i318 < 222; c5_i318++) {
    c5_dc_u[c5_i318] = c5_jb_u.msg1011[c5_i318];
  }

  c5_jc_y = NULL;
  sf_mex_assign(&c5_jc_y, sf_mex_create("y", c5_dc_u, 2, 0U, 1U, 0U, 1, 222),
                false);
  sf_mex_setfieldbynum(c5_mb_y, 0, "msg1011", c5_jc_y, 12);
  for (c5_i319 = 0; c5_i319 < 268; c5_i319++) {
    c5_ec_u[c5_i319] = c5_jb_u.msg1012[c5_i319];
  }

  c5_kc_y = NULL;
  sf_mex_assign(&c5_kc_y, sf_mex_create("y", c5_ec_u, 2, 0U, 1U, 0U, 1, 268),
                false);
  sf_mex_setfieldbynum(c5_mb_y, 0, "msg1012", c5_kc_y, 13);
  for (c5_i320 = 0; c5_i320 < 27; c5_i320++) {
    c5_fc_u[c5_i320] = c5_jb_u.msg1013[c5_i320];
  }

  c5_lc_y = NULL;
  sf_mex_assign(&c5_lc_y, sf_mex_create("y", c5_fc_u, 2, 0U, 1U, 0U, 1, 27),
                false);
  sf_mex_setfieldbynum(c5_mb_y, 0, "msg1013", c5_lc_y, 14);
  for (c5_i321 = 0; c5_i321 < 15; c5_i321++) {
    c5_gc_u[c5_i321] = c5_jb_u.msg1014[c5_i321];
  }

  c5_mc_y = NULL;
  sf_mex_assign(&c5_mc_y, sf_mex_create("y", c5_gc_u, 2, 0U, 1U, 0U, 1, 15),
                false);
  sf_mex_setfieldbynum(c5_mb_y, 0, "msg1014", c5_mc_y, 15);
  for (c5_i322 = 0; c5_i322 < 69; c5_i322++) {
    c5_hc_u[c5_i322] = c5_jb_u.msg1015[c5_i322];
  }

  c5_nc_y = NULL;
  sf_mex_assign(&c5_nc_y, sf_mex_create("y", c5_hc_u, 2, 0U, 1U, 0U, 1, 69),
                false);
  sf_mex_setfieldbynum(c5_mb_y, 0, "msg1015", c5_nc_y, 16);
  for (c5_i323 = 0; c5_i323 < 81; c5_i323++) {
    c5_ic_u[c5_i323] = c5_jb_u.msg1016[c5_i323];
  }

  c5_oc_y = NULL;
  sf_mex_assign(&c5_oc_y, sf_mex_create("y", c5_ic_u, 2, 0U, 1U, 0U, 1, 81),
                false);
  sf_mex_setfieldbynum(c5_mb_y, 0, "msg1016", c5_oc_y, 17);
  for (c5_i324 = 0; c5_i324 < 115; c5_i324++) {
    c5_jc_u[c5_i324] = c5_jb_u.msg1017[c5_i324];
  }

  c5_pc_y = NULL;
  sf_mex_assign(&c5_pc_y, sf_mex_create("y", c5_jc_u, 2, 0U, 1U, 0U, 1, 115),
                false);
  sf_mex_setfieldbynum(c5_mb_y, 0, "msg1017", c5_pc_y, 18);
  for (c5_i325 = 0; c5_i325 < 62; c5_i325++) {
    c5_kc_u[c5_i325] = c5_jb_u.msg1019[c5_i325];
  }

  c5_qc_y = NULL;
  sf_mex_assign(&c5_qc_y, sf_mex_create("y", c5_kc_u, 2, 0U, 1U, 0U, 1, 62),
                false);
  sf_mex_setfieldbynum(c5_mb_y, 0, "msg1019", c5_qc_y, 19);
  for (c5_i326 = 0; c5_i326 < 45; c5_i326++) {
    c5_lc_u[c5_i326] = c5_jb_u.msg1020[c5_i326];
  }

  c5_rc_y = NULL;
  sf_mex_assign(&c5_rc_y, sf_mex_create("y", c5_lc_u, 2, 0U, 1U, 0U, 1, 45),
                false);
  sf_mex_setfieldbynum(c5_mb_y, 0, "msg1020", c5_rc_y, 20);
  for (c5_i327 = 0; c5_i327 < 62; c5_i327++) {
    c5_kc_u[c5_i327] = c5_jb_u.msg1021[c5_i327];
  }

  c5_sc_y = NULL;
  sf_mex_assign(&c5_sc_y, sf_mex_create("y", c5_kc_u, 2, 0U, 1U, 0U, 1, 62),
                false);
  sf_mex_setfieldbynum(c5_mb_y, 0, "msg1021", c5_sc_y, 21);
  for (c5_i328 = 0; c5_i328 < 75; c5_i328++) {
    c5_mc_u[c5_i328] = c5_jb_u.msg1022[c5_i328];
  }

  c5_tc_y = NULL;
  sf_mex_assign(&c5_tc_y, sf_mex_create("y", c5_mc_u, 2, 0U, 1U, 0U, 1, 75),
                false);
  sf_mex_setfieldbynum(c5_mb_y, 0, "msg1022", c5_tc_y, 22);
  for (c5_i329 = 0; c5_i329 < 73; c5_i329++) {
    c5_nc_u[c5_i329] = c5_jb_u.msg1023[c5_i329];
  }

  c5_uc_y = NULL;
  sf_mex_assign(&c5_uc_y, sf_mex_create("y", c5_nc_u, 2, 0U, 1U, 0U, 1, 73),
                false);
  sf_mex_setfieldbynum(c5_mb_y, 0, "msg1023", c5_uc_y, 23);
  for (c5_i330 = 0; c5_i330 < 74; c5_i330++) {
    c5_oc_u[c5_i330] = c5_jb_u.msg1024[c5_i330];
  }

  c5_vc_y = NULL;
  sf_mex_assign(&c5_vc_y, sf_mex_create("y", c5_oc_u, 2, 0U, 1U, 0U, 1, 74),
                false);
  sf_mex_setfieldbynum(c5_mb_y, 0, "msg1024", c5_vc_y, 24);
  for (c5_i331 = 0; c5_i331 < 25; c5_i331++) {
    c5_pc_u[c5_i331] = c5_jb_u.msg1025[c5_i331];
  }

  c5_wc_y = NULL;
  sf_mex_assign(&c5_wc_y, sf_mex_create("y", c5_pc_u, 2, 0U, 1U, 0U, 1, 25),
                false);
  sf_mex_setfieldbynum(c5_mb_y, 0, "msg1025", c5_wc_y, 25);
  for (c5_i332 = 0; c5_i332 < 30; c5_i332++) {
    c5_qc_u[c5_i332] = c5_jb_u.msg1026[c5_i332];
  }

  c5_xc_y = NULL;
  sf_mex_assign(&c5_xc_y, sf_mex_create("y", c5_qc_u, 2, 0U, 1U, 0U, 1, 30),
                false);
  sf_mex_setfieldbynum(c5_mb_y, 0, "msg1026", c5_xc_y, 26);
  for (c5_i333 = 0; c5_i333 < 33; c5_i333++) {
    c5_rc_u[c5_i333] = c5_jb_u.msg1027[c5_i333];
  }

  c5_yc_y = NULL;
  sf_mex_assign(&c5_yc_y, sf_mex_create("y", c5_rc_u, 2, 0U, 1U, 0U, 1, 33),
                false);
  sf_mex_setfieldbynum(c5_mb_y, 0, "msg1027", c5_yc_y, 27);
  for (c5_i334 = 0; c5_i334 < 69; c5_i334++) {
    c5_hc_u[c5_i334] = c5_jb_u.msg1029[c5_i334];
  }

  c5_ad_y = NULL;
  sf_mex_assign(&c5_ad_y, sf_mex_create("y", c5_hc_u, 2, 0U, 1U, 0U, 1, 69),
                false);
  sf_mex_setfieldbynum(c5_mb_y, 0, "msg1029", c5_ad_y, 28);
  for (c5_i335 = 0; c5_i335 < 105; c5_i335++) {
    c5_sc_u[c5_i335] = c5_jb_u.msg1030[c5_i335];
  }

  c5_bd_y = NULL;
  sf_mex_assign(&c5_bd_y, sf_mex_create("y", c5_sc_u, 2, 0U, 1U, 0U, 1, 105),
                false);
  sf_mex_setfieldbynum(c5_mb_y, 0, "msg1030", c5_bd_y, 29);
  for (c5_i336 = 0; c5_i336 < 107; c5_i336++) {
    c5_tc_u[c5_i336] = c5_jb_u.msg1031[c5_i336];
  }

  c5_cd_y = NULL;
  sf_mex_assign(&c5_cd_y, sf_mex_create("y", c5_tc_u, 2, 0U, 1U, 0U, 1, 107),
                false);
  sf_mex_setfieldbynum(c5_mb_y, 0, "msg1031", c5_cd_y, 30);
  for (c5_i337 = 0; c5_i337 < 20; c5_i337++) {
    c5_uc_u[c5_i337] = c5_jb_u.msg1032[c5_i337];
  }

  c5_dd_y = NULL;
  sf_mex_assign(&c5_dd_y, sf_mex_create("y", c5_uc_u, 2, 0U, 1U, 0U, 1, 20),
                false);
  sf_mex_setfieldbynum(c5_mb_y, 0, "msg1032", c5_dd_y, 31);
  sf_mex_setfieldbynum(c5_b_y, 0, "theRTCM", c5_mb_y, 3);
  return c5_b_y;
}

static const mxArray *c5_f_emlrt_marshallOut
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const
   PRESCAN_V2X_FIXED_BSM_utcTime c5_b_u)
{
  const mxArray *c5_b_y;
  int32_T c5_c_u;
  const mxArray *c5_c_y = NULL;
  int32_T c5_d_u;
  const mxArray *c5_d_y = NULL;
  int32_T c5_e_u;
  const mxArray *c5_e_y = NULL;
  int32_T c5_f_u;
  const mxArray *c5_f_y = NULL;
  int32_T c5_g_u;
  const mxArray *c5_g_y = NULL;
  int32_T c5_h_u;
  const mxArray *c5_h_y = NULL;
  (void)chartInstance;
  c5_b_y = NULL;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_createstruct("structure", 6, c5_sv3, 2, 1, 1),
                false);
  c5_c_u = c5_b_u.year;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_c_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "year", c5_c_y, 0);
  c5_d_u = c5_b_u.month;
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", &c5_d_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "month", c5_d_y, 1);
  c5_e_u = c5_b_u.day;
  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", &c5_e_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "day", c5_e_y, 2);
  c5_f_u = c5_b_u.hour;
  c5_f_y = NULL;
  sf_mex_assign(&c5_f_y, sf_mex_create("y", &c5_f_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "hour", c5_f_y, 3);
  c5_g_u = c5_b_u.minute;
  c5_g_y = NULL;
  sf_mex_assign(&c5_g_y, sf_mex_create("y", &c5_g_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "minute", c5_g_y, 4);
  c5_h_u = c5_b_u.second;
  c5_h_y = NULL;
  sf_mex_assign(&c5_h_y, sf_mex_create("y", &c5_h_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "second", c5_h_y, 5);
  return c5_b_y;
}

static const mxArray *c5_g_emlrt_marshallOut
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const
   PRESCAN_V2X_FIXED_BSM_status *c5_b_u)
{
  const mxArray *c5_b_y;
  static const char * c5_sv18[22] = { "lights", "lightBar", "wipers",
    "brakeStatus", "brakePressure", "roadFriction", "sunData", "rainData",
    "airTemp", "airPres", "steering", "accelSets", "object", "fullPos",
    "throttlePos", "speedHeadC", "speedC", "vehicleData", "vehicleIdent",
    "j1939data", "weatherReport", "gpsStatus" };

  int32_T c5_c_u;
  const mxArray *c5_c_y = NULL;
  int32_T c5_d_u;
  const mxArray *c5_d_y = NULL;
  int32_T c5_e_u;
  const mxArray *c5_e_y = NULL;
  PRESCAN_V2X_FIXED_BSM_steering c5_f_u;
  const mxArray *c5_f_y = NULL;
  static const char * c5_sv19[4] = { "angle", "confidence", "rate", "wheels" };

  int8_T c5_g_u;
  const mxArray *c5_g_y = NULL;
  int32_T c5_h_u;
  const mxArray *c5_h_y = NULL;
  int32_T c5_i_u;
  const mxArray *c5_i_y = NULL;
  int32_T c5_j_u;
  const mxArray *c5_j_y = NULL;
  PRESCAN_V2X_FIXED_BSM_accelSets c5_k_u;
  const mxArray *c5_k_y = NULL;
  static const char * c5_sv20[5] = { "accel4way", "vertAccelThres", "yawRateCon",
    "hozAccelCon", "confidenceSet" };

  int32_T c5_i338;
  const mxArray *c5_l_y = NULL;
  int8_T c5_l_u[7];
  int32_T c5_m_u;
  const mxArray *c5_m_y = NULL;
  int32_T c5_n_u;
  const mxArray *c5_n_y = NULL;
  int32_T c5_o_u;
  const mxArray *c5_o_y = NULL;
  PRESCAN_V2X_FIXED_BSM_confidenceSet c5_p_u;
  const mxArray *c5_p_y = NULL;
  static const char * c5_sv21[6] = { "accelConfidence", "speedConfidence",
    "timeConfidence", "posConfidence", "steerConfidence", "throttleConfidence" };

  PRESCAN_V2X_FIXED_BSM_accelConfidence c5_q_u;
  const mxArray *c5_q_y = NULL;
  static const char * c5_sv22[3] = { "yawRate", "acceleration",
    "steeringWheelAngle" };

  int32_T c5_r_u;
  const mxArray *c5_r_y = NULL;
  int32_T c5_s_u;
  const mxArray *c5_s_y = NULL;
  int32_T c5_t_u;
  const mxArray *c5_t_y = NULL;
  int8_T c5_u_u;
  const mxArray *c5_u_y = NULL;
  int32_T c5_v_u;
  const mxArray *c5_v_y = NULL;
  int8_T c5_w_u;
  const mxArray *c5_w_y = NULL;
  int32_T c5_x_u;
  const mxArray *c5_x_y = NULL;
  int32_T c5_y_u;
  const mxArray *c5_y_y = NULL;
  PRESCAN_V2X_FIXED_BSM_object c5_ab_u;
  const mxArray *c5_ab_y = NULL;
  static const char * c5_sv23[3] = { "obDist", "obDirect", "dateTime" };

  int32_T c5_bb_u;
  const mxArray *c5_bb_y = NULL;
  int32_T c5_cb_u;
  const mxArray *c5_cb_y = NULL;
  PRESCAN_V2X_FIXED_BSM_dateTime c5_db_u;
  const mxArray *c5_db_y = NULL;
  int32_T c5_eb_u;
  const mxArray *c5_eb_y = NULL;
  int32_T c5_fb_u;
  const mxArray *c5_fb_y = NULL;
  int32_T c5_gb_u;
  const mxArray *c5_gb_y = NULL;
  int32_T c5_hb_u;
  const mxArray *c5_hb_y = NULL;
  int32_T c5_ib_u;
  const mxArray *c5_ib_y = NULL;
  int32_T c5_jb_u;
  const mxArray *c5_jb_y = NULL;
  PRESCAN_V2X_FIXED_BSM_fullPos c5_kb_u;
  const mxArray *c5_kb_y = NULL;
  int32_T c5_lb_u;
  const mxArray *c5_lb_y = NULL;
  int32_T c5_mb_u;
  const mxArray *c5_mb_y = NULL;
  int32_T c5_i339;
  const mxArray *c5_nb_y = NULL;
  int8_T c5_nb_u[2];
  int32_T c5_ob_u;
  const mxArray *c5_ob_y = NULL;
  int32_T c5_i340;
  const mxArray *c5_pb_y = NULL;
  int32_T c5_i341;
  const mxArray *c5_qb_y = NULL;
  int8_T c5_pb_u[4];
  int32_T c5_qb_u;
  const mxArray *c5_rb_y = NULL;
  int8_T c5_rb_u;
  const mxArray *c5_sb_y = NULL;
  int8_T c5_sb_u;
  const mxArray *c5_tb_y = NULL;
  int32_T c5_tb_u;
  const mxArray *c5_ub_y = NULL;
  int8_T c5_ub_u;
  const mxArray *c5_vb_y = NULL;
  int32_T c5_vb_u;
  const mxArray *c5_wb_y = NULL;
  PRESCAN_V2X_FIXED_BSM_vehicleData c5_wb_u;
  const mxArray *c5_xb_y = NULL;
  static const char * c5_sv24[5] = { "height", "bumpers", "mass",
    "trailerWeight", "type" };

  int32_T c5_xb_u;
  const mxArray *c5_yb_y = NULL;
  PRESCAN_V2X_FIXED_BSM_bumpers c5_yb_u;
  const mxArray *c5_ac_y = NULL;
  static const char * c5_sv25[2] = { "frnt", "rear" };

  int32_T c5_ac_u;
  const mxArray *c5_bc_y = NULL;
  int32_T c5_bc_u;
  const mxArray *c5_cc_y = NULL;
  int32_T c5_cc_u;
  const mxArray *c5_dc_y = NULL;
  int32_T c5_dc_u;
  const mxArray *c5_ec_y = NULL;
  int32_T c5_ec_u;
  const mxArray *c5_fc_y = NULL;
  PRESCAN_V2X_FIXED_BSM_vehicleIdent c5_fc_u;
  const mxArray *c5_gc_y = NULL;
  static const char * c5_sv26[6] = { "name", "vin", "ownerCode", "id",
    "vehicleType", "vehicleClass" };

  int32_T c5_i342;
  const mxArray *c5_hc_y = NULL;
  int8_T c5_gc_u[63];
  int32_T c5_i343;
  const mxArray *c5_ic_y = NULL;
  int8_T c5_hc_u[17];
  int32_T c5_i344;
  const mxArray *c5_jc_y = NULL;
  int8_T c5_ic_u[32];
  int32_T c5_i345;
  const mxArray *c5_kc_y = NULL;
  int32_T c5_jc_u;
  const mxArray *c5_lc_y = NULL;
  PRESCAN_V2X_FIXED_BSM_vehicleClass c5_kc_u;
  const mxArray *c5_mc_y = NULL;
  static const char * c5_sv27[3] = { "vGroup", "rGroup", "rEquip" };

  int32_T c5_lc_u;
  const mxArray *c5_nc_y = NULL;
  int32_T c5_mc_u;
  const mxArray *c5_oc_y = NULL;
  int32_T c5_nc_u;
  const mxArray *c5_pc_y = NULL;
  PRESCAN_V2X_FIXED_BSM_j1939data c5_oc_u;
  const mxArray *c5_qc_y = NULL;
  static const char * c5_sv28[10] = { "tires", "axle", "trailerWeight",
    "cargoWeight", "steeringAxleTemperature", "driveAxleLocation",
    "driveAxleLiftAirPressure", "driveAxleTemperature", "driveAxleLubePressure",
    "steeringAxleLubePressure" };

  int32_T c5_i346;
  const mxArray *c5_rc_y = NULL;
  PRESCAN_V2X_FIXED_BSM_tires c5_pc_u[16];
  int32_T c5_iv1[1];
  static const char * c5_sv29[7] = { "location", "pressure", "temp",
    "wheelSensorStatus", "wheelEndElectFault", "leakageRate", "detection" };

  int32_T c5_i347;
  const PRESCAN_V2X_FIXED_BSM_tires *c5_r3;
  int32_T c5_i348;
  int32_T c5_qc_u;
  const mxArray *c5_sc_y = NULL;
  const mxArray *c5_tc_y = NULL;
  PRESCAN_V2X_FIXED_BSM_axle c5_rc_u[16];
  int32_T c5_iv2[1];
  int32_T c5_sc_u;
  static const char * c5_sv30[2] = { "location", "weight" };

  const mxArray *c5_uc_y = NULL;
  int32_T c5_i349;
  int32_T c5_tc_u;
  const PRESCAN_V2X_FIXED_BSM_axle *c5_r4;
  const mxArray *c5_vc_y = NULL;
  int32_T c5_uc_u;
  int32_T c5_vc_u;
  const mxArray *c5_wc_y = NULL;
  const mxArray *c5_xc_y = NULL;
  int32_T c5_wc_u;
  const mxArray *c5_yc_y = NULL;
  int32_T c5_xc_u;
  int32_T c5_yc_u;
  const mxArray *c5_ad_y = NULL;
  const mxArray *c5_bd_y = NULL;
  int32_T c5_ad_u;
  const mxArray *c5_cd_y = NULL;
  int32_T c5_bd_u;
  const mxArray *c5_dd_y = NULL;
  int32_T c5_cd_u;
  const mxArray *c5_ed_y = NULL;
  int32_T c5_dd_u;
  const mxArray *c5_fd_y = NULL;
  int32_T c5_ed_u;
  const mxArray *c5_gd_y = NULL;
  int32_T c5_fd_u;
  const mxArray *c5_hd_y = NULL;
  int32_T c5_gd_u;
  const mxArray *c5_id_y = NULL;
  int32_T c5_hd_u;
  const mxArray *c5_jd_y = NULL;
  int32_T c5_id_u;
  const mxArray *c5_kd_y = NULL;
  PRESCAN_V2X_FIXED_BSM_weatherReport c5_jd_u;
  const mxArray *c5_ld_y = NULL;
  static const char * c5_sv31[5] = { "isRaining", "rainRate", "precipSituation",
    "solarRadiation", "friction" };

  int32_T c5_kd_u;
  const mxArray *c5_md_y = NULL;
  int32_T c5_ld_u;
  const mxArray *c5_nd_y = NULL;
  int32_T c5_md_u;
  const mxArray *c5_od_y = NULL;
  int32_T c5_nd_u;
  const mxArray *c5_pd_y = NULL;
  int32_T c5_od_u;
  const mxArray *c5_qd_y = NULL;
  int32_T c5_pd_u;
  const mxArray *c5_rd_y = NULL;
  c5_b_y = NULL;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_createstruct("structure", 22, c5_sv18, 2, 1, 1),
                false);
  sf_mex_setfieldbynum(c5_b_y, 0, "lights", c5_b_emlrt_marshallOut(chartInstance,
    c5_b_u->lights), 0);
  sf_mex_setfieldbynum(c5_b_y, 0, "lightBar", c5_b_emlrt_marshallOut
                       (chartInstance, c5_b_u->lightBar), 1);
  sf_mex_setfieldbynum(c5_b_y, 0, "wipers", c5_h_emlrt_marshallOut(chartInstance,
    c5_b_u->wipers), 2);
  sf_mex_setfieldbynum(c5_b_y, 0, "brakeStatus", c5_c_emlrt_marshallOut
                       (chartInstance, c5_b_u->brakeStatus), 3);
  sf_mex_setfieldbynum(c5_b_y, 0, "brakePressure", c5_b_emlrt_marshallOut
                       (chartInstance, c5_b_u->brakePressure), 4);
  sf_mex_setfieldbynum(c5_b_y, 0, "roadFriction", c5_b_emlrt_marshallOut
                       (chartInstance, c5_b_u->roadFriction), 5);
  sf_mex_setfieldbynum(c5_b_y, 0, "sunData", c5_b_emlrt_marshallOut
                       (chartInstance, c5_b_u->sunData), 6);
  c5_c_u = c5_b_u->rainData;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_c_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "rainData", c5_c_y, 7);
  c5_d_u = c5_b_u->airTemp;
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", &c5_d_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "airTemp", c5_d_y, 8);
  c5_e_u = c5_b_u->airPres;
  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", &c5_e_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "airPres", c5_e_y, 9);
  c5_f_u = c5_b_u->steering;
  c5_f_y = NULL;
  sf_mex_assign(&c5_f_y, sf_mex_createstruct("structure", 4, c5_sv19, 2, 1, 1),
                false);
  c5_g_u = c5_f_u.angle;
  c5_g_y = NULL;
  sf_mex_assign(&c5_g_y, sf_mex_create("y", &c5_g_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_f_y, 0, "angle", c5_g_y, 0);
  c5_h_u = c5_f_u.confidence;
  c5_h_y = NULL;
  sf_mex_assign(&c5_h_y, sf_mex_create("y", &c5_h_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_f_y, 0, "confidence", c5_h_y, 1);
  c5_i_u = c5_f_u.rate;
  c5_i_y = NULL;
  sf_mex_assign(&c5_i_y, sf_mex_create("y", &c5_i_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_f_y, 0, "rate", c5_i_y, 2);
  c5_j_u = c5_f_u.wheels;
  c5_j_y = NULL;
  sf_mex_assign(&c5_j_y, sf_mex_create("y", &c5_j_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_f_y, 0, "wheels", c5_j_y, 3);
  sf_mex_setfieldbynum(c5_b_y, 0, "steering", c5_f_y, 10);
  c5_k_u = c5_b_u->accelSets;
  c5_k_y = NULL;
  sf_mex_assign(&c5_k_y, sf_mex_createstruct("structure", 5, c5_sv20, 2, 1, 1),
                false);
  for (c5_i338 = 0; c5_i338 < 7; c5_i338++) {
    c5_l_u[c5_i338] = c5_k_u.accel4way[c5_i338];
  }

  c5_l_y = NULL;
  sf_mex_assign(&c5_l_y, sf_mex_create("y", c5_l_u, 2, 0U, 1U, 0U, 1, 7), false);
  sf_mex_setfieldbynum(c5_k_y, 0, "accel4way", c5_l_y, 0);
  c5_m_u = c5_k_u.vertAccelThres;
  c5_m_y = NULL;
  sf_mex_assign(&c5_m_y, sf_mex_create("y", &c5_m_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_k_y, 0, "vertAccelThres", c5_m_y, 1);
  c5_n_u = c5_k_u.yawRateCon;
  c5_n_y = NULL;
  sf_mex_assign(&c5_n_y, sf_mex_create("y", &c5_n_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_k_y, 0, "yawRateCon", c5_n_y, 2);
  c5_o_u = c5_k_u.hozAccelCon;
  c5_o_y = NULL;
  sf_mex_assign(&c5_o_y, sf_mex_create("y", &c5_o_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_k_y, 0, "hozAccelCon", c5_o_y, 3);
  c5_p_u = c5_k_u.confidenceSet;
  c5_p_y = NULL;
  sf_mex_assign(&c5_p_y, sf_mex_createstruct("structure", 6, c5_sv21, 2, 1, 1),
                false);
  c5_q_u = c5_p_u.accelConfidence;
  c5_q_y = NULL;
  sf_mex_assign(&c5_q_y, sf_mex_createstruct("structure", 3, c5_sv22, 2, 1, 1),
                false);
  c5_r_u = c5_q_u.yawRate;
  c5_r_y = NULL;
  sf_mex_assign(&c5_r_y, sf_mex_create("y", &c5_r_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_q_y, 0, "yawRate", c5_r_y, 0);
  c5_s_u = c5_q_u.acceleration;
  c5_s_y = NULL;
  sf_mex_assign(&c5_s_y, sf_mex_create("y", &c5_s_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_q_y, 0, "acceleration", c5_s_y, 1);
  c5_t_u = c5_q_u.steeringWheelAngle;
  c5_t_y = NULL;
  sf_mex_assign(&c5_t_y, sf_mex_create("y", &c5_t_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_q_y, 0, "steeringWheelAngle", c5_t_y, 2);
  sf_mex_setfieldbynum(c5_p_y, 0, "accelConfidence", c5_q_y, 0);
  c5_u_u = c5_p_u.speedConfidence;
  c5_u_y = NULL;
  sf_mex_assign(&c5_u_y, sf_mex_create("y", &c5_u_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_p_y, 0, "speedConfidence", c5_u_y, 1);
  c5_v_u = c5_p_u.timeConfidence;
  c5_v_y = NULL;
  sf_mex_assign(&c5_v_y, sf_mex_create("y", &c5_v_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_p_y, 0, "timeConfidence", c5_v_y, 2);
  c5_w_u = c5_p_u.posConfidence;
  c5_w_y = NULL;
  sf_mex_assign(&c5_w_y, sf_mex_create("y", &c5_w_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_p_y, 0, "posConfidence", c5_w_y, 3);
  c5_x_u = c5_p_u.steerConfidence;
  c5_x_y = NULL;
  sf_mex_assign(&c5_x_y, sf_mex_create("y", &c5_x_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_p_y, 0, "steerConfidence", c5_x_y, 4);
  c5_y_u = c5_p_u.throttleConfidence;
  c5_y_y = NULL;
  sf_mex_assign(&c5_y_y, sf_mex_create("y", &c5_y_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_p_y, 0, "throttleConfidence", c5_y_y, 5);
  sf_mex_setfieldbynum(c5_k_y, 0, "confidenceSet", c5_p_y, 4);
  sf_mex_setfieldbynum(c5_b_y, 0, "accelSets", c5_k_y, 11);
  c5_ab_u = c5_b_u->object;
  c5_ab_y = NULL;
  sf_mex_assign(&c5_ab_y, sf_mex_createstruct("structure", 3, c5_sv23, 2, 1, 1),
                false);
  c5_bb_u = c5_ab_u.obDist;
  c5_bb_y = NULL;
  sf_mex_assign(&c5_bb_y, sf_mex_create("y", &c5_bb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_ab_y, 0, "obDist", c5_bb_y, 0);
  c5_cb_u = c5_ab_u.obDirect;
  c5_cb_y = NULL;
  sf_mex_assign(&c5_cb_y, sf_mex_create("y", &c5_cb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_ab_y, 0, "obDirect", c5_cb_y, 1);
  c5_db_u = c5_ab_u.dateTime;
  c5_db_y = NULL;
  sf_mex_assign(&c5_db_y, sf_mex_createstruct("structure", 6, c5_sv3, 2, 1, 1),
                false);
  c5_eb_u = c5_db_u.year;
  c5_eb_y = NULL;
  sf_mex_assign(&c5_eb_y, sf_mex_create("y", &c5_eb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_db_y, 0, "year", c5_eb_y, 0);
  c5_fb_u = c5_db_u.month;
  c5_fb_y = NULL;
  sf_mex_assign(&c5_fb_y, sf_mex_create("y", &c5_fb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_db_y, 0, "month", c5_fb_y, 1);
  c5_gb_u = c5_db_u.day;
  c5_gb_y = NULL;
  sf_mex_assign(&c5_gb_y, sf_mex_create("y", &c5_gb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_db_y, 0, "day", c5_gb_y, 2);
  c5_hb_u = c5_db_u.hour;
  c5_hb_y = NULL;
  sf_mex_assign(&c5_hb_y, sf_mex_create("y", &c5_hb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_db_y, 0, "hour", c5_hb_y, 3);
  c5_ib_u = c5_db_u.minute;
  c5_ib_y = NULL;
  sf_mex_assign(&c5_ib_y, sf_mex_create("y", &c5_ib_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_db_y, 0, "minute", c5_ib_y, 4);
  c5_jb_u = c5_db_u.second;
  c5_jb_y = NULL;
  sf_mex_assign(&c5_jb_y, sf_mex_create("y", &c5_jb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_db_y, 0, "second", c5_jb_y, 5);
  sf_mex_setfieldbynum(c5_ab_y, 0, "dateTime", c5_db_y, 2);
  sf_mex_setfieldbynum(c5_b_y, 0, "object", c5_ab_y, 12);
  c5_kb_u = c5_b_u->fullPos;
  c5_kb_y = NULL;
  sf_mex_assign(&c5_kb_y, sf_mex_createstruct("structure", 10, c5_sv2, 2, 1, 1),
                false);
  sf_mex_setfieldbynum(c5_kb_y, 0, "utcTime", c5_f_emlrt_marshallOut
                       (chartInstance, c5_kb_u.utcTime), 0);
  c5_lb_u = c5_kb_u.longitude;
  c5_lb_y = NULL;
  sf_mex_assign(&c5_lb_y, sf_mex_create("y", &c5_lb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_kb_y, 0, "longitude", c5_lb_y, 1);
  c5_mb_u = c5_kb_u.latitude;
  c5_mb_y = NULL;
  sf_mex_assign(&c5_mb_y, sf_mex_create("y", &c5_mb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_kb_y, 0, "latitude", c5_mb_y, 2);
  for (c5_i339 = 0; c5_i339 < 2; c5_i339++) {
    c5_nb_u[c5_i339] = c5_kb_u.elevation[c5_i339];
  }

  c5_nb_y = NULL;
  sf_mex_assign(&c5_nb_y, sf_mex_create("y", c5_nb_u, 2, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_setfieldbynum(c5_kb_y, 0, "elevation", c5_nb_y, 3);
  c5_ob_u = c5_kb_u.heading;
  c5_ob_y = NULL;
  sf_mex_assign(&c5_ob_y, sf_mex_create("y", &c5_ob_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_kb_y, 0, "heading", c5_ob_y, 4);
  for (c5_i340 = 0; c5_i340 < 2; c5_i340++) {
    c5_nb_u[c5_i340] = c5_kb_u.speed[c5_i340];
  }

  c5_pb_y = NULL;
  sf_mex_assign(&c5_pb_y, sf_mex_create("y", c5_nb_u, 2, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_setfieldbynum(c5_kb_y, 0, "speed", c5_pb_y, 5);
  for (c5_i341 = 0; c5_i341 < 4; c5_i341++) {
    c5_pb_u[c5_i341] = c5_kb_u.posAccuracy[c5_i341];
  }

  c5_qb_y = NULL;
  sf_mex_assign(&c5_qb_y, sf_mex_create("y", c5_pb_u, 2, 0U, 1U, 0U, 1, 4),
                false);
  sf_mex_setfieldbynum(c5_kb_y, 0, "posAccuracy", c5_qb_y, 6);
  c5_qb_u = c5_kb_u.timeConfidence;
  c5_rb_y = NULL;
  sf_mex_assign(&c5_rb_y, sf_mex_create("y", &c5_qb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_kb_y, 0, "timeConfidence", c5_rb_y, 7);
  c5_rb_u = c5_kb_u.posConfidence;
  c5_sb_y = NULL;
  sf_mex_assign(&c5_sb_y, sf_mex_create("y", &c5_rb_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_kb_y, 0, "posConfidence", c5_sb_y, 8);
  c5_sb_u = c5_kb_u.speedConfidence;
  c5_tb_y = NULL;
  sf_mex_assign(&c5_tb_y, sf_mex_create("y", &c5_sb_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_kb_y, 0, "speedConfidence", c5_tb_y, 9);
  sf_mex_setfieldbynum(c5_b_y, 0, "fullPos", c5_kb_y, 13);
  c5_tb_u = c5_b_u->throttlePos;
  c5_ub_y = NULL;
  sf_mex_assign(&c5_ub_y, sf_mex_create("y", &c5_tb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "throttlePos", c5_ub_y, 14);
  c5_ub_u = c5_b_u->speedHeadC;
  c5_vb_y = NULL;
  sf_mex_assign(&c5_vb_y, sf_mex_create("y", &c5_ub_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "speedHeadC", c5_vb_y, 15);
  c5_vb_u = c5_b_u->speedC;
  c5_wb_y = NULL;
  sf_mex_assign(&c5_wb_y, sf_mex_create("y", &c5_vb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "speedC", c5_wb_y, 16);
  c5_wb_u = c5_b_u->vehicleData;
  c5_xb_y = NULL;
  sf_mex_assign(&c5_xb_y, sf_mex_createstruct("structure", 5, c5_sv24, 2, 1, 1),
                false);
  c5_xb_u = c5_wb_u.height;
  c5_yb_y = NULL;
  sf_mex_assign(&c5_yb_y, sf_mex_create("y", &c5_xb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_xb_y, 0, "height", c5_yb_y, 0);
  c5_yb_u = c5_wb_u.bumpers;
  c5_ac_y = NULL;
  sf_mex_assign(&c5_ac_y, sf_mex_createstruct("structure", 2, c5_sv25, 2, 1, 1),
                false);
  c5_ac_u = c5_yb_u.frnt;
  c5_bc_y = NULL;
  sf_mex_assign(&c5_bc_y, sf_mex_create("y", &c5_ac_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_ac_y, 0, "frnt", c5_bc_y, 0);
  c5_bc_u = c5_yb_u.rear;
  c5_cc_y = NULL;
  sf_mex_assign(&c5_cc_y, sf_mex_create("y", &c5_bc_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_ac_y, 0, "rear", c5_cc_y, 1);
  sf_mex_setfieldbynum(c5_xb_y, 0, "bumpers", c5_ac_y, 1);
  c5_cc_u = c5_wb_u.mass;
  c5_dc_y = NULL;
  sf_mex_assign(&c5_dc_y, sf_mex_create("y", &c5_cc_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_xb_y, 0, "mass", c5_dc_y, 2);
  c5_dc_u = c5_wb_u.trailerWeight;
  c5_ec_y = NULL;
  sf_mex_assign(&c5_ec_y, sf_mex_create("y", &c5_dc_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_xb_y, 0, "trailerWeight", c5_ec_y, 3);
  c5_ec_u = c5_wb_u.type;
  c5_fc_y = NULL;
  sf_mex_assign(&c5_fc_y, sf_mex_create("y", &c5_ec_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_xb_y, 0, "type", c5_fc_y, 4);
  sf_mex_setfieldbynum(c5_b_y, 0, "vehicleData", c5_xb_y, 17);
  c5_fc_u = c5_b_u->vehicleIdent;
  c5_gc_y = NULL;
  sf_mex_assign(&c5_gc_y, sf_mex_createstruct("structure", 6, c5_sv26, 2, 1, 1),
                false);
  for (c5_i342 = 0; c5_i342 < 63; c5_i342++) {
    c5_gc_u[c5_i342] = c5_fc_u.name[c5_i342];
  }

  c5_hc_y = NULL;
  sf_mex_assign(&c5_hc_y, sf_mex_create("y", c5_gc_u, 2, 0U, 1U, 0U, 1, 63),
                false);
  sf_mex_setfieldbynum(c5_gc_y, 0, "name", c5_hc_y, 0);
  for (c5_i343 = 0; c5_i343 < 17; c5_i343++) {
    c5_hc_u[c5_i343] = c5_fc_u.vin[c5_i343];
  }

  c5_ic_y = NULL;
  sf_mex_assign(&c5_ic_y, sf_mex_create("y", c5_hc_u, 2, 0U, 1U, 0U, 1, 17),
                false);
  sf_mex_setfieldbynum(c5_gc_y, 0, "vin", c5_ic_y, 1);
  for (c5_i344 = 0; c5_i344 < 32; c5_i344++) {
    c5_ic_u[c5_i344] = c5_fc_u.ownerCode[c5_i344];
  }

  c5_jc_y = NULL;
  sf_mex_assign(&c5_jc_y, sf_mex_create("y", c5_ic_u, 2, 0U, 1U, 0U, 1, 32),
                false);
  sf_mex_setfieldbynum(c5_gc_y, 0, "ownerCode", c5_jc_y, 2);
  for (c5_i345 = 0; c5_i345 < 4; c5_i345++) {
    c5_pb_u[c5_i345] = c5_fc_u.id[c5_i345];
  }

  c5_kc_y = NULL;
  sf_mex_assign(&c5_kc_y, sf_mex_create("y", c5_pb_u, 2, 0U, 1U, 0U, 1, 4),
                false);
  sf_mex_setfieldbynum(c5_gc_y, 0, "id", c5_kc_y, 3);
  c5_jc_u = c5_fc_u.vehicleType;
  c5_lc_y = NULL;
  sf_mex_assign(&c5_lc_y, sf_mex_create("y", &c5_jc_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_gc_y, 0, "vehicleType", c5_lc_y, 4);
  c5_kc_u = c5_fc_u.vehicleClass;
  c5_mc_y = NULL;
  sf_mex_assign(&c5_mc_y, sf_mex_createstruct("structure", 3, c5_sv27, 2, 1, 1),
                false);
  c5_lc_u = c5_kc_u.vGroup;
  c5_nc_y = NULL;
  sf_mex_assign(&c5_nc_y, sf_mex_create("y", &c5_lc_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_mc_y, 0, "vGroup", c5_nc_y, 0);
  c5_mc_u = c5_kc_u.rGroup;
  c5_oc_y = NULL;
  sf_mex_assign(&c5_oc_y, sf_mex_create("y", &c5_mc_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_mc_y, 0, "rGroup", c5_oc_y, 1);
  c5_nc_u = c5_kc_u.rEquip;
  c5_pc_y = NULL;
  sf_mex_assign(&c5_pc_y, sf_mex_create("y", &c5_nc_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_mc_y, 0, "rEquip", c5_pc_y, 2);
  sf_mex_setfieldbynum(c5_gc_y, 0, "vehicleClass", c5_mc_y, 5);
  sf_mex_setfieldbynum(c5_b_y, 0, "vehicleIdent", c5_gc_y, 18);
  c5_oc_u = c5_b_u->j1939data;
  c5_qc_y = NULL;
  sf_mex_assign(&c5_qc_y, sf_mex_createstruct("structure", 10, c5_sv28, 2, 1, 1),
                false);
  for (c5_i346 = 0; c5_i346 < 16; c5_i346++) {
    c5_pc_u[c5_i346] = c5_oc_u.tires[c5_i346];
  }

  c5_rc_y = NULL;
  c5_iv1[0] = 16;
  sf_mex_assign(&c5_rc_y, sf_mex_createstructarray("structure", 1, c5_iv1, 7,
    c5_sv29), false);
  for (c5_i347 = 0; c5_i347 < 16; c5_i347++) {
    c5_r3 = &c5_pc_u[c5_i347];
    c5_qc_u = c5_r3->location;
    c5_sc_y = NULL;
    sf_mex_assign(&c5_sc_y, sf_mex_create("y", &c5_qc_u, 6, 0U, 0U, 0U, 0),
                  false);
    sf_mex_setfieldbynum(c5_rc_y, c5_i347, "location", c5_sc_y, 0);
    c5_sc_u = c5_r3->pressure;
    c5_uc_y = NULL;
    sf_mex_assign(&c5_uc_y, sf_mex_create("y", &c5_sc_u, 6, 0U, 0U, 0U, 0),
                  false);
    sf_mex_setfieldbynum(c5_rc_y, c5_i347, "pressure", c5_uc_y, 1);
    c5_tc_u = c5_r3->temp;
    c5_vc_y = NULL;
    sf_mex_assign(&c5_vc_y, sf_mex_create("y", &c5_tc_u, 6, 0U, 0U, 0U, 0),
                  false);
    sf_mex_setfieldbynum(c5_rc_y, c5_i347, "temp", c5_vc_y, 2);
    c5_wc_u = c5_r3->wheelSensorStatus;
    c5_yc_y = NULL;
    sf_mex_assign(&c5_yc_y, sf_mex_create("y", &c5_wc_u, 6, 0U, 0U, 0U, 0),
                  false);
    sf_mex_setfieldbynum(c5_rc_y, c5_i347, "wheelSensorStatus", c5_yc_y, 3);
    c5_ad_u = c5_r3->wheelEndElectFault;
    c5_cd_y = NULL;
    sf_mex_assign(&c5_cd_y, sf_mex_create("y", &c5_ad_u, 6, 0U, 0U, 0U, 0),
                  false);
    sf_mex_setfieldbynum(c5_rc_y, c5_i347, "wheelEndElectFault", c5_cd_y, 4);
    c5_cd_u = c5_r3->leakageRate;
    c5_ed_y = NULL;
    sf_mex_assign(&c5_ed_y, sf_mex_create("y", &c5_cd_u, 6, 0U, 0U, 0U, 0),
                  false);
    sf_mex_setfieldbynum(c5_rc_y, c5_i347, "leakageRate", c5_ed_y, 5);
    c5_ed_u = c5_r3->detection;
    c5_gd_y = NULL;
    sf_mex_assign(&c5_gd_y, sf_mex_create("y", &c5_ed_u, 6, 0U, 0U, 0U, 0),
                  false);
    sf_mex_setfieldbynum(c5_rc_y, c5_i347, "detection", c5_gd_y, 6);
  }

  sf_mex_setfieldbynum(c5_qc_y, 0, "tires", c5_rc_y, 0);
  for (c5_i348 = 0; c5_i348 < 16; c5_i348++) {
    c5_rc_u[c5_i348] = c5_oc_u.axle[c5_i348];
  }

  c5_tc_y = NULL;
  c5_iv2[0] = 16;
  sf_mex_assign(&c5_tc_y, sf_mex_createstructarray("structure", 1, c5_iv2, 2,
    c5_sv30), false);
  for (c5_i349 = 0; c5_i349 < 16; c5_i349++) {
    c5_r4 = &c5_rc_u[c5_i349];
    c5_vc_u = c5_r4->location;
    c5_xc_y = NULL;
    sf_mex_assign(&c5_xc_y, sf_mex_create("y", &c5_vc_u, 6, 0U, 0U, 0U, 0),
                  false);
    sf_mex_setfieldbynum(c5_tc_y, c5_i349, "location", c5_xc_y, 0);
    c5_yc_u = c5_r4->weight;
    c5_bd_y = NULL;
    sf_mex_assign(&c5_bd_y, sf_mex_create("y", &c5_yc_u, 6, 0U, 0U, 0U, 0),
                  false);
    sf_mex_setfieldbynum(c5_tc_y, c5_i349, "weight", c5_bd_y, 1);
  }

  sf_mex_setfieldbynum(c5_qc_y, 0, "axle", c5_tc_y, 1);
  c5_uc_u = c5_oc_u.trailerWeight;
  c5_wc_y = NULL;
  sf_mex_assign(&c5_wc_y, sf_mex_create("y", &c5_uc_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_qc_y, 0, "trailerWeight", c5_wc_y, 2);
  c5_xc_u = c5_oc_u.cargoWeight;
  c5_ad_y = NULL;
  sf_mex_assign(&c5_ad_y, sf_mex_create("y", &c5_xc_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_qc_y, 0, "cargoWeight", c5_ad_y, 3);
  c5_bd_u = c5_oc_u.steeringAxleTemperature;
  c5_dd_y = NULL;
  sf_mex_assign(&c5_dd_y, sf_mex_create("y", &c5_bd_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_qc_y, 0, "steeringAxleTemperature", c5_dd_y, 4);
  c5_dd_u = c5_oc_u.driveAxleLocation;
  c5_fd_y = NULL;
  sf_mex_assign(&c5_fd_y, sf_mex_create("y", &c5_dd_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_qc_y, 0, "driveAxleLocation", c5_fd_y, 5);
  c5_fd_u = c5_oc_u.driveAxleLiftAirPressure;
  c5_hd_y = NULL;
  sf_mex_assign(&c5_hd_y, sf_mex_create("y", &c5_fd_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_qc_y, 0, "driveAxleLiftAirPressure", c5_hd_y, 6);
  c5_gd_u = c5_oc_u.driveAxleTemperature;
  c5_id_y = NULL;
  sf_mex_assign(&c5_id_y, sf_mex_create("y", &c5_gd_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_qc_y, 0, "driveAxleTemperature", c5_id_y, 7);
  c5_hd_u = c5_oc_u.driveAxleLubePressure;
  c5_jd_y = NULL;
  sf_mex_assign(&c5_jd_y, sf_mex_create("y", &c5_hd_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_qc_y, 0, "driveAxleLubePressure", c5_jd_y, 8);
  c5_id_u = c5_oc_u.steeringAxleLubePressure;
  c5_kd_y = NULL;
  sf_mex_assign(&c5_kd_y, sf_mex_create("y", &c5_id_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_qc_y, 0, "steeringAxleLubePressure", c5_kd_y, 9);
  sf_mex_setfieldbynum(c5_b_y, 0, "j1939data", c5_qc_y, 19);
  c5_jd_u = c5_b_u->weatherReport;
  c5_ld_y = NULL;
  sf_mex_assign(&c5_ld_y, sf_mex_createstruct("structure", 5, c5_sv31, 2, 1, 1),
                false);
  c5_kd_u = c5_jd_u.isRaining;
  c5_md_y = NULL;
  sf_mex_assign(&c5_md_y, sf_mex_create("y", &c5_kd_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_ld_y, 0, "isRaining", c5_md_y, 0);
  c5_ld_u = c5_jd_u.rainRate;
  c5_nd_y = NULL;
  sf_mex_assign(&c5_nd_y, sf_mex_create("y", &c5_ld_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_ld_y, 0, "rainRate", c5_nd_y, 1);
  c5_md_u = c5_jd_u.precipSituation;
  c5_od_y = NULL;
  sf_mex_assign(&c5_od_y, sf_mex_create("y", &c5_md_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_ld_y, 0, "precipSituation", c5_od_y, 2);
  c5_nd_u = c5_jd_u.solarRadiation;
  c5_pd_y = NULL;
  sf_mex_assign(&c5_pd_y, sf_mex_create("y", &c5_nd_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_ld_y, 0, "solarRadiation", c5_pd_y, 3);
  c5_od_u = c5_jd_u.friction;
  c5_qd_y = NULL;
  sf_mex_assign(&c5_qd_y, sf_mex_create("y", &c5_od_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_ld_y, 0, "friction", c5_qd_y, 4);
  sf_mex_setfieldbynum(c5_b_y, 0, "weatherReport", c5_ld_y, 20);
  c5_pd_u = c5_b_u->gpsStatus;
  c5_rd_y = NULL;
  sf_mex_assign(&c5_rd_y, sf_mex_create("y", &c5_pd_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "gpsStatus", c5_rd_y, 21);
  return c5_b_y;
}

static const mxArray *c5_h_emlrt_marshallOut
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const
   PRESCAN_V2X_FIXED_BSM_wipers c5_b_u)
{
  const mxArray *c5_b_y;
  static const char * c5_sv32[4] = { "statusFront", "rateFront", "statusRear",
    "rateRear" };

  int32_T c5_c_u;
  const mxArray *c5_c_y = NULL;
  int32_T c5_d_u;
  const mxArray *c5_d_y = NULL;
  int32_T c5_e_u;
  const mxArray *c5_e_y = NULL;
  int32_T c5_f_u;
  const mxArray *c5_f_y = NULL;
  (void)chartInstance;
  c5_b_y = NULL;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_createstruct("structure", 4, c5_sv32, 2, 1, 1),
                false);
  c5_c_u = c5_b_u.statusFront;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_c_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "statusFront", c5_c_y, 0);
  c5_d_u = c5_b_u.rateFront;
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", &c5_d_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "rateFront", c5_d_y, 1);
  c5_e_u = c5_b_u.statusRear;
  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", &c5_e_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "statusRear", c5_e_y, 2);
  c5_f_u = c5_b_u.rateRear;
  c5_f_y = NULL;
  sf_mex_assign(&c5_f_y, sf_mex_create("y", &c5_f_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "rateRear", c5_f_y, 3);
  return c5_b_y;
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData;
  PRESCAN_V2X_FIXED_BSM_MESSAGE c5_b_u;
  const mxArray *c5_b_y = NULL;
  PRESCAN_HEADER c5_c_u;
  const mxArray *c5_c_y = NULL;
  static const char * c5_sv33[1] = { "valid" };

  boolean_T c5_d_u;
  const mxArray *c5_d_y = NULL;
  SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc5_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_mxArrayOutData = NULL;
  c5_b_u = *(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_inData;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_createstruct("structure", 2, c5_sv0, 2, 1, 1),
                false);
  c5_c_u = c5_b_u.HEADER;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_createstruct("structure", 1, c5_sv33, 2, 1, 1),
                false);
  c5_d_u = c5_c_u.valid;
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", &c5_d_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_c_y, 0, "valid", c5_d_y, 0);
  sf_mex_setfieldbynum(c5_b_y, 0, "HEADER", c5_c_y, 0);
  sf_mex_setfieldbynum(c5_b_y, 0, "DATA", c5_d_emlrt_marshallOut(chartInstance,
    &c5_b_u.DATA), 1);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static void c5_b_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_y, const char_T *c5_identifier,
  PRESCAN_V2X_FIXED_BSM_MESSAGE *c5_c_y)
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = (const char *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_y), &c5_thisId, c5_c_y);
  sf_mex_destroy(&c5_b_y);
}

static void c5_c_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  PRESCAN_V2X_FIXED_BSM_MESSAGE *c5_b_y)
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fParent = c5_parentId;
  c5_thisId.bParentIsCell = false;
  sf_mex_check_struct(c5_parentId, c5_b_u, 2, c5_sv4, 0U, NULL);
  c5_thisId.fIdentifier = "HEADER";
  c5_b_y->HEADER = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "HEADER", "HEADER", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "DATA";
  c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u, "DATA",
    "DATA", 0)), &c5_thisId, &c5_b_y->DATA);
  sf_mex_destroy(&c5_b_u);
}

static PRESCAN_HEADER c5_d_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId)
{
  PRESCAN_HEADER c5_b_y;
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[1] = { "valid" };

  c5_thisId.fParent = c5_parentId;
  c5_thisId.bParentIsCell = false;
  sf_mex_check_struct(c5_parentId, c5_b_u, 1, c5_fieldNames, 0U, NULL);
  c5_thisId.fIdentifier = "valid";
  c5_b_y.valid = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_b_u, "valid", "valid", 0)), &c5_thisId);
  sf_mex_destroy(&c5_b_u);
  return c5_b_y;
}

static boolean_T c5_e_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId)
{
  boolean_T c5_b_y;
  boolean_T c5_b0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), &c5_b0, 1, 11, 0U, 0, 0U, 0);
  c5_b_y = c5_b0;
  sf_mex_destroy(&c5_b_u);
  return c5_b_y;
}

static void c5_f_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  PRESCAN_V2X_FIXED_BSM_DATA *c5_b_y)
{
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[16] = { "msgID", "msgCnt", "id", "secMark",
    "latitude", "longitude", "elev", "accuracy", "speed", "heading", "angle",
    "accelSet", "brakes", "size", "safetyExt", "status" };

  c5_thisId.fParent = c5_parentId;
  c5_thisId.bParentIsCell = false;
  sf_mex_check_struct(c5_parentId, c5_b_u, 16, c5_fieldNames, 0U, NULL);
  c5_thisId.fIdentifier = "msgID";
  c5_b_y->msgID = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "msgID", "msgID", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "msgCnt";
  c5_b_y->msgCnt = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "msgCnt", "msgCnt", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "id";
  c5_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u, "id",
    "id", 0)), &c5_thisId, c5_b_y->id);
  c5_thisId.fIdentifier = "secMark";
  c5_b_y->secMark = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "secMark", "secMark", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "latitude";
  c5_b_y->latitude = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "latitude", "latitude", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "longitude";
  c5_b_y->longitude = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "longitude", "longitude", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "elev";
  c5_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u, "elev",
    "elev", 0)), &c5_thisId, c5_b_y->elev);
  c5_thisId.fIdentifier = "accuracy";
  c5_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "accuracy", "accuracy", 0)), &c5_thisId, c5_b_y->accuracy);
  c5_thisId.fIdentifier = "speed";
  c5_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "speed", "speed", 0)), &c5_thisId, c5_b_y->speed);
  c5_thisId.fIdentifier = "heading";
  c5_b_y->heading = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "heading", "heading", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "angle";
  c5_b_y->angle = c5_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "angle", "angle", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "accelSet";
  c5_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "accelSet", "accelSet", 0)), &c5_thisId, c5_b_y->accelSet);
  c5_thisId.fIdentifier = "brakes";
  c5_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "brakes", "brakes", 0)), &c5_thisId, c5_b_y->brakes);
  c5_thisId.fIdentifier = "size";
  c5_b_y->size = c5_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_b_u, "size", "size", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "safetyExt";
  c5_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "safetyExt", "safetyExt", 0)), &c5_thisId, &c5_b_y->safetyExt);
  c5_thisId.fIdentifier = "status";
  c5_jc_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "status", "status", 0)), &c5_thisId, &c5_b_y->status);
  sf_mex_destroy(&c5_b_u);
}

static int32_T c5_g_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_b_y;
  int32_T c5_i350;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), &c5_i350, 1, 6, 0U, 0, 0U, 0);
  c5_b_y = c5_i350;
  sf_mex_destroy(&c5_b_u);
  return c5_b_y;
}

static void c5_h_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[4])
{
  int8_T c5_iv3[4];
  int32_T c5_i351;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv3, 1, 2, 0U, 1, 0U, 1, 4);
  for (c5_i351 = 0; c5_i351 < 4; c5_i351++) {
    c5_b_y[c5_i351] = c5_iv3[c5_i351];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_i_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[2])
{
  int8_T c5_iv4[2];
  int32_T c5_i352;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv4, 1, 2, 0U, 1, 0U, 1, 2);
  for (c5_i352 = 0; c5_i352 < 2; c5_i352++) {
    c5_b_y[c5_i352] = c5_iv4[c5_i352];
  }

  sf_mex_destroy(&c5_b_u);
}

static int8_T c5_j_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId)
{
  int8_T c5_b_y;
  int8_T c5_i353;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), &c5_i353, 1, 2, 0U, 0, 0U, 0);
  c5_b_y = c5_i353;
  sf_mex_destroy(&c5_b_u);
  return c5_b_y;
}

static void c5_k_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[7])
{
  int8_T c5_iv5[7];
  int32_T c5_i354;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv5, 1, 2, 0U, 1, 0U, 1, 7);
  for (c5_i354 = 0; c5_i354 < 7; c5_i354++) {
    c5_b_y[c5_i354] = c5_iv5[c5_i354];
  }

  sf_mex_destroy(&c5_b_u);
}

static PRESCAN_V2X_FIXED_BSM_size c5_l_emlrt_marshallIn
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_b_u,
   const emlrtMsgIdentifier *c5_parentId)
{
  PRESCAN_V2X_FIXED_BSM_size c5_b_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fParent = c5_parentId;
  c5_thisId.bParentIsCell = false;
  sf_mex_check_struct(c5_parentId, c5_b_u, 2, c5_sv5, 0U, NULL);
  c5_thisId.fIdentifier = "width";
  c5_b_y.width = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_b_u, "width", "width", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "length";
  c5_b_y.length = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "length", "length", 0)), &c5_thisId);
  sf_mex_destroy(&c5_b_u);
  return c5_b_y;
}

static void c5_m_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  PRESCAN_V2X_FIXED_BSM_safetyExt *c5_b_y)
{
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[4] = { "events", "pathHistory",
    "pathPrediction", "theRTCM" };

  c5_thisId.fParent = c5_parentId;
  c5_thisId.bParentIsCell = false;
  sf_mex_check_struct(c5_parentId, c5_b_u, 4, c5_fieldNames, 0U, NULL);
  c5_thisId.fIdentifier = "events";
  c5_b_y->events = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "events", "events", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "pathHistory";
  c5_n_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "pathHistory", "pathHistory", 0)), &c5_thisId, &c5_b_y->pathHistory);
  c5_thisId.fIdentifier = "pathPrediction";
  c5_b_y->pathPrediction = c5_cb_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "pathPrediction", "pathPrediction", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "theRTCM";
  c5_db_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "theRTCM", "theRTCM", 0)), &c5_thisId, &c5_b_y->theRTCM);
  sf_mex_destroy(&c5_b_u);
}

static void c5_n_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  PRESCAN_V2X_FIXED_BSM_pathHistory *c5_b_y)
{
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[4] = { "initialPosition", "currGPSstatus",
    "itemCnt", "crumbData" };

  c5_thisId.fParent = c5_parentId;
  c5_thisId.bParentIsCell = false;
  sf_mex_check_struct(c5_parentId, c5_b_u, 4, c5_fieldNames, 0U, NULL);
  c5_thisId.fIdentifier = "initialPosition";
  c5_b_y->initialPosition = c5_o_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "initialPosition", "initialPosition", 0)),
    &c5_thisId);
  c5_thisId.fIdentifier = "currGPSstatus";
  c5_b_y->currGPSstatus = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "currGPSstatus", "currGPSstatus", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "itemCnt";
  c5_b_y->itemCnt = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "itemCnt", "itemCnt", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "crumbData";
  c5_q_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "crumbData", "crumbData", 0)), &c5_thisId, &c5_b_y->crumbData);
  sf_mex_destroy(&c5_b_u);
}

static PRESCAN_V2X_FIXED_BSM_initialPosition c5_o_emlrt_marshallIn
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_b_u,
   const emlrtMsgIdentifier *c5_parentId)
{
  PRESCAN_V2X_FIXED_BSM_initialPosition c5_b_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fParent = c5_parentId;
  c5_thisId.bParentIsCell = false;
  sf_mex_check_struct(c5_parentId, c5_b_u, 10, c5_sv6, 0U, NULL);
  c5_thisId.fIdentifier = "utcTime";
  c5_b_y.utcTime = c5_p_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "utcTime", "utcTime", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "longitude";
  c5_b_y.longitude = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "longitude", "longitude", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "latitude";
  c5_b_y.latitude = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "latitude", "latitude", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "elevation";
  c5_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "elevation", "elevation", 0)), &c5_thisId, c5_b_y.elevation);
  c5_thisId.fIdentifier = "heading";
  c5_b_y.heading = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "heading", "heading", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "speed";
  c5_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "speed", "speed", 0)), &c5_thisId, c5_b_y.speed);
  c5_thisId.fIdentifier = "posAccuracy";
  c5_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "posAccuracy", "posAccuracy", 0)), &c5_thisId, c5_b_y.posAccuracy);
  c5_thisId.fIdentifier = "timeConfidence";
  c5_b_y.timeConfidence = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "timeConfidence", "timeConfidence", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "posConfidence";
  c5_b_y.posConfidence = c5_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "posConfidence", "posConfidence", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "speedConfidence";
  c5_b_y.speedConfidence = c5_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "speedConfidence", "speedConfidence", 0)),
    &c5_thisId);
  sf_mex_destroy(&c5_b_u);
  return c5_b_y;
}

static PRESCAN_V2X_FIXED_BSM_utcTime c5_p_emlrt_marshallIn
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_b_u,
   const emlrtMsgIdentifier *c5_parentId)
{
  PRESCAN_V2X_FIXED_BSM_utcTime c5_b_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fParent = c5_parentId;
  c5_thisId.bParentIsCell = false;
  sf_mex_check_struct(c5_parentId, c5_b_u, 6, c5_sv7, 0U, NULL);
  c5_thisId.fIdentifier = "year";
  c5_b_y.year = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_b_u, "year", "year", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "month";
  c5_b_y.month = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_b_u, "month", "month", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "day";
  c5_b_y.day = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_b_u, "day", "day", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "hour";
  c5_b_y.hour = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_b_u, "hour", "hour", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "minute";
  c5_b_y.minute = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "minute", "minute", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "second";
  c5_b_y.second = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "second", "second", 0)), &c5_thisId);
  sf_mex_destroy(&c5_b_u);
  return c5_b_y;
}

static void c5_q_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  PRESCAN_V2X_FIXED_BSM_crumbData *c5_b_y)
{
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[10] = { "pathHistoryPointSets_01",
    "pathHistoryPointSets_02", "pathHistoryPointSets_03",
    "pathHistoryPointSets_04", "pathHistoryPointSets_05",
    "pathHistoryPointSets_06", "pathHistoryPointSets_07",
    "pathHistoryPointSets_08", "pathHistoryPointSets_09",
    "pathHistoryPointSets_10" };

  c5_thisId.fParent = c5_parentId;
  c5_thisId.bParentIsCell = false;
  sf_mex_check_struct(c5_parentId, c5_b_u, 10, c5_fieldNames, 0U, NULL);
  c5_thisId.fIdentifier = "pathHistoryPointSets_01";
  c5_r_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "pathHistoryPointSets_01", "pathHistoryPointSets_01", 0)), &c5_thisId,
                        c5_b_y->pathHistoryPointSets_01);
  c5_thisId.fIdentifier = "pathHistoryPointSets_02";
  c5_s_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "pathHistoryPointSets_02", "pathHistoryPointSets_02", 0)), &c5_thisId,
                        c5_b_y->pathHistoryPointSets_02);
  c5_thisId.fIdentifier = "pathHistoryPointSets_03";
  c5_t_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "pathHistoryPointSets_03", "pathHistoryPointSets_03", 0)), &c5_thisId,
                        c5_b_y->pathHistoryPointSets_03);
  c5_thisId.fIdentifier = "pathHistoryPointSets_04";
  c5_u_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "pathHistoryPointSets_04", "pathHistoryPointSets_04", 0)), &c5_thisId,
                        c5_b_y->pathHistoryPointSets_04);
  c5_thisId.fIdentifier = "pathHistoryPointSets_05";
  c5_v_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "pathHistoryPointSets_05", "pathHistoryPointSets_05", 0)), &c5_thisId,
                        c5_b_y->pathHistoryPointSets_05);
  c5_thisId.fIdentifier = "pathHistoryPointSets_06";
  c5_w_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "pathHistoryPointSets_06", "pathHistoryPointSets_06", 0)), &c5_thisId,
                        c5_b_y->pathHistoryPointSets_06);
  c5_thisId.fIdentifier = "pathHistoryPointSets_07";
  c5_x_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "pathHistoryPointSets_07", "pathHistoryPointSets_07", 0)), &c5_thisId,
                        c5_b_y->pathHistoryPointSets_07);
  c5_thisId.fIdentifier = "pathHistoryPointSets_08";
  c5_y_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "pathHistoryPointSets_08", "pathHistoryPointSets_08", 0)), &c5_thisId,
                        c5_b_y->pathHistoryPointSets_08);
  c5_thisId.fIdentifier = "pathHistoryPointSets_09";
  c5_ab_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "pathHistoryPointSets_09", "pathHistoryPointSets_09", 0)), &c5_thisId,
    c5_b_y->pathHistoryPointSets_09);
  c5_thisId.fIdentifier = "pathHistoryPointSets_10";
  c5_bb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "pathHistoryPointSets_10", "pathHistoryPointSets_10", 0)), &c5_thisId,
    c5_b_y->pathHistoryPointSets_10);
  sf_mex_destroy(&c5_b_u);
}

static void c5_r_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 c5_b_y[23])
{
  uint32_T c5_uv0[1];
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[7] = { "latOffset", "longOffset",
    "elevationOffset", "timeOffset", "posAccuracy", "heading", "speed" };

  int32_T c5_i355;
  c5_uv0[0] = 23U;
  c5_thisId.fParent = c5_parentId;
  c5_thisId.bParentIsCell = false;
  sf_mex_check_struct(c5_parentId, c5_b_u, 7, c5_fieldNames, 1U, c5_uv0);
  for (c5_i355 = 0; c5_i355 < 23; c5_i355++) {
    c5_thisId.fIdentifier = "latOffset";
    c5_b_y[c5_i355].latOffset = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c5_b_u, "latOffset", "latOffset", c5_i355)), &c5_thisId);
    c5_thisId.fIdentifier = "longOffset";
    c5_b_y[c5_i355].longOffset = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c5_b_u, "longOffset", "longOffset", c5_i355)), &c5_thisId);
    c5_thisId.fIdentifier = "elevationOffset";
    c5_b_y[c5_i355].elevationOffset = c5_g_emlrt_marshallIn(chartInstance,
      sf_mex_dup(sf_mex_getfield(c5_b_u, "elevationOffset", "elevationOffset",
      c5_i355)), &c5_thisId);
    c5_thisId.fIdentifier = "timeOffset";
    c5_b_y[c5_i355].timeOffset = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c5_b_u, "timeOffset", "timeOffset", c5_i355)), &c5_thisId);
    c5_thisId.fIdentifier = "posAccuracy";
    c5_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
      "posAccuracy", "posAccuracy", c5_i355)), &c5_thisId, c5_b_y[c5_i355].
                          posAccuracy);
    c5_thisId.fIdentifier = "heading";
    c5_b_y[c5_i355].heading = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c5_b_u, "heading", "heading", c5_i355)), &c5_thisId);
    c5_thisId.fIdentifier = "speed";
    c5_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
      "speed", "speed", c5_i355)), &c5_thisId, c5_b_y[c5_i355].speed);
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_s_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[345])
{
  int8_T c5_iv6[345];
  int32_T c5_i356;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv6, 1, 2, 0U, 1, 0U, 1, 345);
  for (c5_i356 = 0; c5_i356 < 345; c5_i356++) {
    c5_b_y[c5_i356] = c5_iv6[c5_i356];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_t_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[276])
{
  int8_T c5_iv7[276];
  int32_T c5_i357;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv7, 1, 2, 0U, 1, 0U, 1, 276);
  for (c5_i357 = 0; c5_i357 < 276; c5_i357++) {
    c5_b_y[c5_i357] = c5_iv7[c5_i357];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_u_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[184])
{
  int8_T c5_iv8[184];
  int32_T c5_i358;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv8, 1, 2, 0U, 1, 0U, 1, 184);
  for (c5_i358 = 0; c5_i358 < 184; c5_i358++) {
    c5_b_y[c5_i358] = c5_iv8[c5_i358];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_v_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[230])
{
  int8_T c5_iv9[230];
  int32_T c5_i359;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv9, 1, 2, 0U, 1, 0U, 1, 230);
  for (c5_i359 = 0; c5_i359 < 230; c5_i359++) {
    c5_b_y[c5_i359] = c5_iv9[c5_i359];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_w_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[138])
{
  int8_T c5_iv10[138];
  int32_T c5_i360;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv10, 1, 2, 0U, 1, 0U, 1,
                138);
  for (c5_i360 = 0; c5_i360 < 138; c5_i360++) {
    c5_b_y[c5_i360] = c5_iv10[c5_i360];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_x_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[242])
{
  int8_T c5_iv11[242];
  int32_T c5_i361;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv11, 1, 2, 0U, 1, 0U, 1,
                242);
  for (c5_i361 = 0; c5_i361 < 242; c5_i361++) {
    c5_b_y[c5_i361] = c5_iv11[c5_i361];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_y_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[161])
{
  int8_T c5_iv12[161];
  int32_T c5_i362;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv12, 1, 2, 0U, 1, 0U, 1,
                161);
  for (c5_i362 = 0; c5_i362 < 161; c5_i362++) {
    c5_b_y[c5_i362] = c5_iv12[c5_i362];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_ab_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[196])
{
  int8_T c5_iv13[196];
  int32_T c5_i363;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv13, 1, 2, 0U, 1, 0U, 1,
                196);
  for (c5_i363 = 0; c5_i363 < 196; c5_i363++) {
    c5_b_y[c5_i363] = c5_iv13[c5_i363];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_bb_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[104])
{
  int8_T c5_iv14[104];
  int32_T c5_i364;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv14, 1, 2, 0U, 1, 0U, 1,
                104);
  for (c5_i364 = 0; c5_i364 < 104; c5_i364++) {
    c5_b_y[c5_i364] = c5_iv14[c5_i364];
  }

  sf_mex_destroy(&c5_b_u);
}

static PRESCAN_V2X_FIXED_BSM_pathPrediction c5_cb_emlrt_marshallIn
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_b_u,
   const emlrtMsgIdentifier *c5_parentId)
{
  PRESCAN_V2X_FIXED_BSM_pathPrediction c5_b_y;
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[2] = { "radiusOfCurve", "confidence" };

  c5_thisId.fParent = c5_parentId;
  c5_thisId.bParentIsCell = false;
  sf_mex_check_struct(c5_parentId, c5_b_u, 2, c5_fieldNames, 0U, NULL);
  c5_thisId.fIdentifier = "radiusOfCurve";
  c5_b_y.radiusOfCurve = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "radiusOfCurve", "radiusOfCurve", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "confidence";
  c5_b_y.confidence = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "confidence", "confidence", 0)), &c5_thisId);
  sf_mex_destroy(&c5_b_u);
  return c5_b_y;
}

static void c5_db_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  PRESCAN_V2X_FIXED_BSM_theRTCM *c5_b_y)
{
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[32] = { "anchorPoint", "rtcmHeader",
    "msg1001", "msg1002", "msg1003", "msg1004", "msg1005", "msg1006", "msg1007",
    "msg1008", "msg1009", "msg1010", "msg1011", "msg1012", "msg1013", "msg1014",
    "msg1015", "msg1016", "msg1017", "msg1019", "msg1020", "msg1021", "msg1022",
    "msg1023", "msg1024", "msg1025", "msg1026", "msg1027", "msg1029", "msg1030",
    "msg1031", "msg1032" };

  c5_thisId.fParent = c5_parentId;
  c5_thisId.bParentIsCell = false;
  sf_mex_check_struct(c5_parentId, c5_b_u, 32, c5_fieldNames, 0U, NULL);
  c5_thisId.fIdentifier = "anchorPoint";
  c5_b_y->anchorPoint = c5_eb_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "anchorPoint", "anchorPoint", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "rtcmHeader";
  c5_fb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "rtcmHeader", "rtcmHeader", 0)), &c5_thisId, c5_b_y->rtcmHeader);
  c5_thisId.fIdentifier = "msg1001";
  c5_gb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "msg1001", "msg1001", 0)), &c5_thisId, c5_b_y->msg1001);
  c5_thisId.fIdentifier = "msg1002";
  c5_hb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "msg1002", "msg1002", 0)), &c5_thisId, c5_b_y->msg1002);
  c5_thisId.fIdentifier = "msg1003";
  c5_ib_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "msg1003", "msg1003", 0)), &c5_thisId, c5_b_y->msg1003);
  c5_thisId.fIdentifier = "msg1004";
  c5_jb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "msg1004", "msg1004", 0)), &c5_thisId, c5_b_y->msg1004);
  c5_thisId.fIdentifier = "msg1005";
  c5_kb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "msg1005", "msg1005", 0)), &c5_thisId, c5_b_y->msg1005);
  c5_thisId.fIdentifier = "msg1006";
  c5_lb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "msg1006", "msg1006", 0)), &c5_thisId, c5_b_y->msg1006);
  c5_thisId.fIdentifier = "msg1007";
  c5_mb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "msg1007", "msg1007", 0)), &c5_thisId, c5_b_y->msg1007);
  c5_thisId.fIdentifier = "msg1008";
  c5_nb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "msg1008", "msg1008", 0)), &c5_thisId, c5_b_y->msg1008);
  c5_thisId.fIdentifier = "msg1009";
  c5_ob_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "msg1009", "msg1009", 0)), &c5_thisId, c5_b_y->msg1009);
  c5_thisId.fIdentifier = "msg1010";
  c5_pb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "msg1010", "msg1010", 0)), &c5_thisId, c5_b_y->msg1010);
  c5_thisId.fIdentifier = "msg1011";
  c5_qb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "msg1011", "msg1011", 0)), &c5_thisId, c5_b_y->msg1011);
  c5_thisId.fIdentifier = "msg1012";
  c5_rb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "msg1012", "msg1012", 0)), &c5_thisId, c5_b_y->msg1012);
  c5_thisId.fIdentifier = "msg1013";
  c5_sb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "msg1013", "msg1013", 0)), &c5_thisId, c5_b_y->msg1013);
  c5_thisId.fIdentifier = "msg1014";
  c5_tb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "msg1014", "msg1014", 0)), &c5_thisId, c5_b_y->msg1014);
  c5_thisId.fIdentifier = "msg1015";
  c5_ub_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "msg1015", "msg1015", 0)), &c5_thisId, c5_b_y->msg1015);
  c5_thisId.fIdentifier = "msg1016";
  c5_vb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "msg1016", "msg1016", 0)), &c5_thisId, c5_b_y->msg1016);
  c5_thisId.fIdentifier = "msg1017";
  c5_wb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "msg1017", "msg1017", 0)), &c5_thisId, c5_b_y->msg1017);
  c5_thisId.fIdentifier = "msg1019";
  c5_xb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "msg1019", "msg1019", 0)), &c5_thisId, c5_b_y->msg1019);
  c5_thisId.fIdentifier = "msg1020";
  c5_yb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "msg1020", "msg1020", 0)), &c5_thisId, c5_b_y->msg1020);
  c5_thisId.fIdentifier = "msg1021";
  c5_xb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "msg1021", "msg1021", 0)), &c5_thisId, c5_b_y->msg1021);
  c5_thisId.fIdentifier = "msg1022";
  c5_ac_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "msg1022", "msg1022", 0)), &c5_thisId, c5_b_y->msg1022);
  c5_thisId.fIdentifier = "msg1023";
  c5_bc_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "msg1023", "msg1023", 0)), &c5_thisId, c5_b_y->msg1023);
  c5_thisId.fIdentifier = "msg1024";
  c5_cc_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "msg1024", "msg1024", 0)), &c5_thisId, c5_b_y->msg1024);
  c5_thisId.fIdentifier = "msg1025";
  c5_dc_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "msg1025", "msg1025", 0)), &c5_thisId, c5_b_y->msg1025);
  c5_thisId.fIdentifier = "msg1026";
  c5_ec_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "msg1026", "msg1026", 0)), &c5_thisId, c5_b_y->msg1026);
  c5_thisId.fIdentifier = "msg1027";
  c5_fc_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "msg1027", "msg1027", 0)), &c5_thisId, c5_b_y->msg1027);
  c5_thisId.fIdentifier = "msg1029";
  c5_ub_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "msg1029", "msg1029", 0)), &c5_thisId, c5_b_y->msg1029);
  c5_thisId.fIdentifier = "msg1030";
  c5_gc_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "msg1030", "msg1030", 0)), &c5_thisId, c5_b_y->msg1030);
  c5_thisId.fIdentifier = "msg1031";
  c5_hc_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "msg1031", "msg1031", 0)), &c5_thisId, c5_b_y->msg1031);
  c5_thisId.fIdentifier = "msg1032";
  c5_ic_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "msg1032", "msg1032", 0)), &c5_thisId, c5_b_y->msg1032);
  sf_mex_destroy(&c5_b_u);
}

static PRESCAN_V2X_FIXED_BSM_anchorPoint c5_eb_emlrt_marshallIn
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_b_u,
   const emlrtMsgIdentifier *c5_parentId)
{
  PRESCAN_V2X_FIXED_BSM_anchorPoint c5_b_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fParent = c5_parentId;
  c5_thisId.bParentIsCell = false;
  sf_mex_check_struct(c5_parentId, c5_b_u, 10, c5_sv6, 0U, NULL);
  c5_thisId.fIdentifier = "utcTime";
  c5_b_y.utcTime = c5_p_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "utcTime", "utcTime", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "longitude";
  c5_b_y.longitude = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "longitude", "longitude", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "latitude";
  c5_b_y.latitude = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "latitude", "latitude", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "elevation";
  c5_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "elevation", "elevation", 0)), &c5_thisId, c5_b_y.elevation);
  c5_thisId.fIdentifier = "heading";
  c5_b_y.heading = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "heading", "heading", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "speed";
  c5_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "speed", "speed", 0)), &c5_thisId, c5_b_y.speed);
  c5_thisId.fIdentifier = "posAccuracy";
  c5_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "posAccuracy", "posAccuracy", 0)), &c5_thisId, c5_b_y.posAccuracy);
  c5_thisId.fIdentifier = "timeConfidence";
  c5_b_y.timeConfidence = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "timeConfidence", "timeConfidence", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "posConfidence";
  c5_b_y.posConfidence = c5_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "posConfidence", "posConfidence", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "speedConfidence";
  c5_b_y.speedConfidence = c5_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "speedConfidence", "speedConfidence", 0)),
    &c5_thisId);
  sf_mex_destroy(&c5_b_u);
  return c5_b_y;
}

static void c5_fb_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[5])
{
  int8_T c5_iv15[5];
  int32_T c5_i365;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv15, 1, 2, 0U, 1, 0U, 1, 5);
  for (c5_i365 = 0; c5_i365 < 5; c5_i365++) {
    c5_b_y[c5_i365] = c5_iv15[c5_i365];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_gb_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[124])
{
  int8_T c5_iv16[124];
  int32_T c5_i366;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv16, 1, 2, 0U, 1, 0U, 1,
                124);
  for (c5_i366 = 0; c5_i366 < 124; c5_i366++) {
    c5_b_y[c5_i366] = c5_iv16[c5_i366];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_hb_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[156])
{
  int8_T c5_iv17[156];
  int32_T c5_i367;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv17, 1, 2, 0U, 1, 0U, 1,
                156);
  for (c5_i367 = 0; c5_i367 < 156; c5_i367++) {
    c5_b_y[c5_i367] = c5_iv17[c5_i367];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_ib_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[210])
{
  int8_T c5_iv18[210];
  int32_T c5_i368;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv18, 1, 2, 0U, 1, 0U, 1,
                210);
  for (c5_i368 = 0; c5_i368 < 210; c5_i368++) {
    c5_b_y[c5_i368] = c5_iv18[c5_i368];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_jb_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[258])
{
  int8_T c5_iv19[258];
  int32_T c5_i369;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv19, 1, 2, 0U, 1, 0U, 1,
                258);
  for (c5_i369 = 0; c5_i369 < 258; c5_i369++) {
    c5_b_y[c5_i369] = c5_iv19[c5_i369];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_kb_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[19])
{
  int8_T c5_iv20[19];
  int32_T c5_i370;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv20, 1, 2, 0U, 1, 0U, 1, 19);
  for (c5_i370 = 0; c5_i370 < 19; c5_i370++) {
    c5_b_y[c5_i370] = c5_iv20[c5_i370];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_lb_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[21])
{
  int8_T c5_iv21[21];
  int32_T c5_i371;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv21, 1, 2, 0U, 1, 0U, 1, 21);
  for (c5_i371 = 0; c5_i371 < 21; c5_i371++) {
    c5_b_y[c5_i371] = c5_iv21[c5_i371];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_mb_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[36])
{
  int8_T c5_iv22[36];
  int32_T c5_i372;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv22, 1, 2, 0U, 1, 0U, 1, 36);
  for (c5_i372 = 0; c5_i372 < 36; c5_i372++) {
    c5_b_y[c5_i372] = c5_iv22[c5_i372];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_nb_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[68])
{
  int8_T c5_iv23[68];
  int32_T c5_i373;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv23, 1, 2, 0U, 1, 0U, 1, 68);
  for (c5_i373 = 0; c5_i373 < 68; c5_i373++) {
    c5_b_y[c5_i373] = c5_iv23[c5_i373];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_ob_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[136])
{
  int8_T c5_iv24[136];
  int32_T c5_i374;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv24, 1, 2, 0U, 1, 0U, 1,
                136);
  for (c5_i374 = 0; c5_i374 < 136; c5_i374++) {
    c5_b_y[c5_i374] = c5_iv24[c5_i374];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_pb_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[166])
{
  int8_T c5_iv25[166];
  int32_T c5_i375;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv25, 1, 2, 0U, 1, 0U, 1,
                166);
  for (c5_i375 = 0; c5_i375 < 166; c5_i375++) {
    c5_b_y[c5_i375] = c5_iv25[c5_i375];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_qb_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[222])
{
  int8_T c5_iv26[222];
  int32_T c5_i376;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv26, 1, 2, 0U, 1, 0U, 1,
                222);
  for (c5_i376 = 0; c5_i376 < 222; c5_i376++) {
    c5_b_y[c5_i376] = c5_iv26[c5_i376];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_rb_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[268])
{
  int8_T c5_iv27[268];
  int32_T c5_i377;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv27, 1, 2, 0U, 1, 0U, 1,
                268);
  for (c5_i377 = 0; c5_i377 < 268; c5_i377++) {
    c5_b_y[c5_i377] = c5_iv27[c5_i377];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_sb_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[27])
{
  int8_T c5_iv28[27];
  int32_T c5_i378;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv28, 1, 2, 0U, 1, 0U, 1, 27);
  for (c5_i378 = 0; c5_i378 < 27; c5_i378++) {
    c5_b_y[c5_i378] = c5_iv28[c5_i378];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_tb_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[15])
{
  int8_T c5_iv29[15];
  int32_T c5_i379;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv29, 1, 2, 0U, 1, 0U, 1, 15);
  for (c5_i379 = 0; c5_i379 < 15; c5_i379++) {
    c5_b_y[c5_i379] = c5_iv29[c5_i379];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_ub_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[69])
{
  int8_T c5_iv30[69];
  int32_T c5_i380;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv30, 1, 2, 0U, 1, 0U, 1, 69);
  for (c5_i380 = 0; c5_i380 < 69; c5_i380++) {
    c5_b_y[c5_i380] = c5_iv30[c5_i380];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_vb_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[81])
{
  int8_T c5_iv31[81];
  int32_T c5_i381;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv31, 1, 2, 0U, 1, 0U, 1, 81);
  for (c5_i381 = 0; c5_i381 < 81; c5_i381++) {
    c5_b_y[c5_i381] = c5_iv31[c5_i381];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_wb_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[115])
{
  int8_T c5_iv32[115];
  int32_T c5_i382;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv32, 1, 2, 0U, 1, 0U, 1,
                115);
  for (c5_i382 = 0; c5_i382 < 115; c5_i382++) {
    c5_b_y[c5_i382] = c5_iv32[c5_i382];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_xb_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[62])
{
  int8_T c5_iv33[62];
  int32_T c5_i383;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv33, 1, 2, 0U, 1, 0U, 1, 62);
  for (c5_i383 = 0; c5_i383 < 62; c5_i383++) {
    c5_b_y[c5_i383] = c5_iv33[c5_i383];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_yb_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[45])
{
  int8_T c5_iv34[45];
  int32_T c5_i384;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv34, 1, 2, 0U, 1, 0U, 1, 45);
  for (c5_i384 = 0; c5_i384 < 45; c5_i384++) {
    c5_b_y[c5_i384] = c5_iv34[c5_i384];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_ac_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[75])
{
  int8_T c5_iv35[75];
  int32_T c5_i385;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv35, 1, 2, 0U, 1, 0U, 1, 75);
  for (c5_i385 = 0; c5_i385 < 75; c5_i385++) {
    c5_b_y[c5_i385] = c5_iv35[c5_i385];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_bc_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[73])
{
  int8_T c5_iv36[73];
  int32_T c5_i386;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv36, 1, 2, 0U, 1, 0U, 1, 73);
  for (c5_i386 = 0; c5_i386 < 73; c5_i386++) {
    c5_b_y[c5_i386] = c5_iv36[c5_i386];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_cc_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[74])
{
  int8_T c5_iv37[74];
  int32_T c5_i387;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv37, 1, 2, 0U, 1, 0U, 1, 74);
  for (c5_i387 = 0; c5_i387 < 74; c5_i387++) {
    c5_b_y[c5_i387] = c5_iv37[c5_i387];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_dc_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[25])
{
  int8_T c5_iv38[25];
  int32_T c5_i388;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv38, 1, 2, 0U, 1, 0U, 1, 25);
  for (c5_i388 = 0; c5_i388 < 25; c5_i388++) {
    c5_b_y[c5_i388] = c5_iv38[c5_i388];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_ec_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[30])
{
  int8_T c5_iv39[30];
  int32_T c5_i389;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv39, 1, 2, 0U, 1, 0U, 1, 30);
  for (c5_i389 = 0; c5_i389 < 30; c5_i389++) {
    c5_b_y[c5_i389] = c5_iv39[c5_i389];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_fc_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[33])
{
  int8_T c5_iv40[33];
  int32_T c5_i390;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv40, 1, 2, 0U, 1, 0U, 1, 33);
  for (c5_i390 = 0; c5_i390 < 33; c5_i390++) {
    c5_b_y[c5_i390] = c5_iv40[c5_i390];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_gc_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[105])
{
  int8_T c5_iv41[105];
  int32_T c5_i391;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv41, 1, 2, 0U, 1, 0U, 1,
                105);
  for (c5_i391 = 0; c5_i391 < 105; c5_i391++) {
    c5_b_y[c5_i391] = c5_iv41[c5_i391];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_hc_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[107])
{
  int8_T c5_iv42[107];
  int32_T c5_i392;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv42, 1, 2, 0U, 1, 0U, 1,
                107);
  for (c5_i392 = 0; c5_i392 < 107; c5_i392++) {
    c5_b_y[c5_i392] = c5_iv42[c5_i392];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_ic_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[20])
{
  int8_T c5_iv43[20];
  int32_T c5_i393;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv43, 1, 2, 0U, 1, 0U, 1, 20);
  for (c5_i393 = 0; c5_i393 < 20; c5_i393++) {
    c5_b_y[c5_i393] = c5_iv43[c5_i393];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_jc_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  PRESCAN_V2X_FIXED_BSM_status *c5_b_y)
{
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[22] = { "lights", "lightBar", "wipers",
    "brakeStatus", "brakePressure", "roadFriction", "sunData", "rainData",
    "airTemp", "airPres", "steering", "accelSets", "object", "fullPos",
    "throttlePos", "speedHeadC", "speedC", "vehicleData", "vehicleIdent",
    "j1939data", "weatherReport", "gpsStatus" };

  c5_thisId.fParent = c5_parentId;
  c5_thisId.bParentIsCell = false;
  sf_mex_check_struct(c5_parentId, c5_b_u, 22, c5_fieldNames, 0U, NULL);
  c5_thisId.fIdentifier = "lights";
  c5_b_y->lights = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "lights", "lights", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "lightBar";
  c5_b_y->lightBar = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "lightBar", "lightBar", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "wipers";
  c5_b_y->wipers = c5_kc_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "wipers", "wipers", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "brakeStatus";
  c5_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "brakeStatus", "brakeStatus", 0)), &c5_thisId, c5_b_y->brakeStatus);
  c5_thisId.fIdentifier = "brakePressure";
  c5_b_y->brakePressure = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "brakePressure", "brakePressure", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "roadFriction";
  c5_b_y->roadFriction = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "roadFriction", "roadFriction", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "sunData";
  c5_b_y->sunData = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "sunData", "sunData", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "rainData";
  c5_b_y->rainData = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "rainData", "rainData", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "airTemp";
  c5_b_y->airTemp = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "airTemp", "airTemp", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "airPres";
  c5_b_y->airPres = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "airPres", "airPres", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "steering";
  c5_b_y->steering = c5_lc_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "steering", "steering", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "accelSets";
  c5_b_y->accelSets = c5_mc_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "accelSets", "accelSets", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "object";
  c5_b_y->object = c5_pc_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "object", "object", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "fullPos";
  c5_b_y->fullPos = c5_rc_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "fullPos", "fullPos", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "throttlePos";
  c5_b_y->throttlePos = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "throttlePos", "throttlePos", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "speedHeadC";
  c5_b_y->speedHeadC = c5_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "speedHeadC", "speedHeadC", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "speedC";
  c5_b_y->speedC = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "speedC", "speedC", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "vehicleData";
  c5_b_y->vehicleData = c5_sc_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "vehicleData", "vehicleData", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "vehicleIdent";
  c5_uc_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "vehicleIdent", "vehicleIdent", 0)), &c5_thisId, &c5_b_y->vehicleIdent);
  c5_thisId.fIdentifier = "j1939data";
  c5_ad_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "j1939data", "j1939data", 0)), &c5_thisId, &c5_b_y->j1939data);
  c5_thisId.fIdentifier = "weatherReport";
  c5_b_y->weatherReport = c5_dd_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "weatherReport", "weatherReport", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "gpsStatus";
  c5_b_y->gpsStatus = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "gpsStatus", "gpsStatus", 0)), &c5_thisId);
  sf_mex_destroy(&c5_b_u);
}

static PRESCAN_V2X_FIXED_BSM_wipers c5_kc_emlrt_marshallIn
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_b_u,
   const emlrtMsgIdentifier *c5_parentId)
{
  PRESCAN_V2X_FIXED_BSM_wipers c5_b_y;
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[4] = { "statusFront", "rateFront",
    "statusRear", "rateRear" };

  c5_thisId.fParent = c5_parentId;
  c5_thisId.bParentIsCell = false;
  sf_mex_check_struct(c5_parentId, c5_b_u, 4, c5_fieldNames, 0U, NULL);
  c5_thisId.fIdentifier = "statusFront";
  c5_b_y.statusFront = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "statusFront", "statusFront", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "rateFront";
  c5_b_y.rateFront = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "rateFront", "rateFront", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "statusRear";
  c5_b_y.statusRear = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "statusRear", "statusRear", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "rateRear";
  c5_b_y.rateRear = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "rateRear", "rateRear", 0)), &c5_thisId);
  sf_mex_destroy(&c5_b_u);
  return c5_b_y;
}

static PRESCAN_V2X_FIXED_BSM_steering c5_lc_emlrt_marshallIn
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_b_u,
   const emlrtMsgIdentifier *c5_parentId)
{
  PRESCAN_V2X_FIXED_BSM_steering c5_b_y;
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[4] = { "angle", "confidence", "rate",
    "wheels" };

  c5_thisId.fParent = c5_parentId;
  c5_thisId.bParentIsCell = false;
  sf_mex_check_struct(c5_parentId, c5_b_u, 4, c5_fieldNames, 0U, NULL);
  c5_thisId.fIdentifier = "angle";
  c5_b_y.angle = c5_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_b_u, "angle", "angle", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "confidence";
  c5_b_y.confidence = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "confidence", "confidence", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "rate";
  c5_b_y.rate = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_b_u, "rate", "rate", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "wheels";
  c5_b_y.wheels = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "wheels", "wheels", 0)), &c5_thisId);
  sf_mex_destroy(&c5_b_u);
  return c5_b_y;
}

static PRESCAN_V2X_FIXED_BSM_accelSets c5_mc_emlrt_marshallIn
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_b_u,
   const emlrtMsgIdentifier *c5_parentId)
{
  PRESCAN_V2X_FIXED_BSM_accelSets c5_b_y;
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[5] = { "accel4way", "vertAccelThres",
    "yawRateCon", "hozAccelCon", "confidenceSet" };

  c5_thisId.fParent = c5_parentId;
  c5_thisId.bParentIsCell = false;
  sf_mex_check_struct(c5_parentId, c5_b_u, 5, c5_fieldNames, 0U, NULL);
  c5_thisId.fIdentifier = "accel4way";
  c5_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "accel4way", "accel4way", 0)), &c5_thisId, c5_b_y.accel4way);
  c5_thisId.fIdentifier = "vertAccelThres";
  c5_b_y.vertAccelThres = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "vertAccelThres", "vertAccelThres", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "yawRateCon";
  c5_b_y.yawRateCon = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "yawRateCon", "yawRateCon", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "hozAccelCon";
  c5_b_y.hozAccelCon = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "hozAccelCon", "hozAccelCon", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "confidenceSet";
  c5_b_y.confidenceSet = c5_nc_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "confidenceSet", "confidenceSet", 0)), &c5_thisId);
  sf_mex_destroy(&c5_b_u);
  return c5_b_y;
}

static PRESCAN_V2X_FIXED_BSM_confidenceSet c5_nc_emlrt_marshallIn
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_b_u,
   const emlrtMsgIdentifier *c5_parentId)
{
  PRESCAN_V2X_FIXED_BSM_confidenceSet c5_b_y;
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[6] = { "accelConfidence", "speedConfidence",
    "timeConfidence", "posConfidence", "steerConfidence", "throttleConfidence" };

  c5_thisId.fParent = c5_parentId;
  c5_thisId.bParentIsCell = false;
  sf_mex_check_struct(c5_parentId, c5_b_u, 6, c5_fieldNames, 0U, NULL);
  c5_thisId.fIdentifier = "accelConfidence";
  c5_b_y.accelConfidence = c5_oc_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "accelConfidence", "accelConfidence", 0)),
    &c5_thisId);
  c5_thisId.fIdentifier = "speedConfidence";
  c5_b_y.speedConfidence = c5_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "speedConfidence", "speedConfidence", 0)),
    &c5_thisId);
  c5_thisId.fIdentifier = "timeConfidence";
  c5_b_y.timeConfidence = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "timeConfidence", "timeConfidence", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "posConfidence";
  c5_b_y.posConfidence = c5_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "posConfidence", "posConfidence", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "steerConfidence";
  c5_b_y.steerConfidence = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "steerConfidence", "steerConfidence", 0)),
    &c5_thisId);
  c5_thisId.fIdentifier = "throttleConfidence";
  c5_b_y.throttleConfidence = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "throttleConfidence", "throttleConfidence", 0)),
    &c5_thisId);
  sf_mex_destroy(&c5_b_u);
  return c5_b_y;
}

static PRESCAN_V2X_FIXED_BSM_accelConfidence c5_oc_emlrt_marshallIn
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_b_u,
   const emlrtMsgIdentifier *c5_parentId)
{
  PRESCAN_V2X_FIXED_BSM_accelConfidence c5_b_y;
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[3] = { "yawRate", "acceleration",
    "steeringWheelAngle" };

  c5_thisId.fParent = c5_parentId;
  c5_thisId.bParentIsCell = false;
  sf_mex_check_struct(c5_parentId, c5_b_u, 3, c5_fieldNames, 0U, NULL);
  c5_thisId.fIdentifier = "yawRate";
  c5_b_y.yawRate = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "yawRate", "yawRate", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "acceleration";
  c5_b_y.acceleration = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "acceleration", "acceleration", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "steeringWheelAngle";
  c5_b_y.steeringWheelAngle = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "steeringWheelAngle", "steeringWheelAngle", 0)),
    &c5_thisId);
  sf_mex_destroy(&c5_b_u);
  return c5_b_y;
}

static PRESCAN_V2X_FIXED_BSM_object c5_pc_emlrt_marshallIn
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_b_u,
   const emlrtMsgIdentifier *c5_parentId)
{
  PRESCAN_V2X_FIXED_BSM_object c5_b_y;
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[3] = { "obDist", "obDirect", "dateTime" };

  c5_thisId.fParent = c5_parentId;
  c5_thisId.bParentIsCell = false;
  sf_mex_check_struct(c5_parentId, c5_b_u, 3, c5_fieldNames, 0U, NULL);
  c5_thisId.fIdentifier = "obDist";
  c5_b_y.obDist = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "obDist", "obDist", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "obDirect";
  c5_b_y.obDirect = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "obDirect", "obDirect", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "dateTime";
  c5_b_y.dateTime = c5_qc_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "dateTime", "dateTime", 0)), &c5_thisId);
  sf_mex_destroy(&c5_b_u);
  return c5_b_y;
}

static PRESCAN_V2X_FIXED_BSM_dateTime c5_qc_emlrt_marshallIn
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_b_u,
   const emlrtMsgIdentifier *c5_parentId)
{
  PRESCAN_V2X_FIXED_BSM_dateTime c5_b_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fParent = c5_parentId;
  c5_thisId.bParentIsCell = false;
  sf_mex_check_struct(c5_parentId, c5_b_u, 6, c5_sv7, 0U, NULL);
  c5_thisId.fIdentifier = "year";
  c5_b_y.year = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_b_u, "year", "year", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "month";
  c5_b_y.month = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_b_u, "month", "month", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "day";
  c5_b_y.day = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_b_u, "day", "day", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "hour";
  c5_b_y.hour = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_b_u, "hour", "hour", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "minute";
  c5_b_y.minute = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "minute", "minute", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "second";
  c5_b_y.second = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "second", "second", 0)), &c5_thisId);
  sf_mex_destroy(&c5_b_u);
  return c5_b_y;
}

static PRESCAN_V2X_FIXED_BSM_fullPos c5_rc_emlrt_marshallIn
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_b_u,
   const emlrtMsgIdentifier *c5_parentId)
{
  PRESCAN_V2X_FIXED_BSM_fullPos c5_b_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fParent = c5_parentId;
  c5_thisId.bParentIsCell = false;
  sf_mex_check_struct(c5_parentId, c5_b_u, 10, c5_sv6, 0U, NULL);
  c5_thisId.fIdentifier = "utcTime";
  c5_b_y.utcTime = c5_p_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "utcTime", "utcTime", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "longitude";
  c5_b_y.longitude = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "longitude", "longitude", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "latitude";
  c5_b_y.latitude = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "latitude", "latitude", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "elevation";
  c5_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "elevation", "elevation", 0)), &c5_thisId, c5_b_y.elevation);
  c5_thisId.fIdentifier = "heading";
  c5_b_y.heading = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "heading", "heading", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "speed";
  c5_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "speed", "speed", 0)), &c5_thisId, c5_b_y.speed);
  c5_thisId.fIdentifier = "posAccuracy";
  c5_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "posAccuracy", "posAccuracy", 0)), &c5_thisId, c5_b_y.posAccuracy);
  c5_thisId.fIdentifier = "timeConfidence";
  c5_b_y.timeConfidence = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "timeConfidence", "timeConfidence", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "posConfidence";
  c5_b_y.posConfidence = c5_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "posConfidence", "posConfidence", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "speedConfidence";
  c5_b_y.speedConfidence = c5_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "speedConfidence", "speedConfidence", 0)),
    &c5_thisId);
  sf_mex_destroy(&c5_b_u);
  return c5_b_y;
}

static PRESCAN_V2X_FIXED_BSM_vehicleData c5_sc_emlrt_marshallIn
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_b_u,
   const emlrtMsgIdentifier *c5_parentId)
{
  PRESCAN_V2X_FIXED_BSM_vehicleData c5_b_y;
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[5] = { "height", "bumpers", "mass",
    "trailerWeight", "type" };

  c5_thisId.fParent = c5_parentId;
  c5_thisId.bParentIsCell = false;
  sf_mex_check_struct(c5_parentId, c5_b_u, 5, c5_fieldNames, 0U, NULL);
  c5_thisId.fIdentifier = "height";
  c5_b_y.height = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "height", "height", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "bumpers";
  c5_b_y.bumpers = c5_tc_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "bumpers", "bumpers", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "mass";
  c5_b_y.mass = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_b_u, "mass", "mass", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "trailerWeight";
  c5_b_y.trailerWeight = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "trailerWeight", "trailerWeight", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "type";
  c5_b_y.type = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_b_u, "type", "type", 0)), &c5_thisId);
  sf_mex_destroy(&c5_b_u);
  return c5_b_y;
}

static PRESCAN_V2X_FIXED_BSM_bumpers c5_tc_emlrt_marshallIn
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_b_u,
   const emlrtMsgIdentifier *c5_parentId)
{
  PRESCAN_V2X_FIXED_BSM_bumpers c5_b_y;
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[2] = { "frnt", "rear" };

  c5_thisId.fParent = c5_parentId;
  c5_thisId.bParentIsCell = false;
  sf_mex_check_struct(c5_parentId, c5_b_u, 2, c5_fieldNames, 0U, NULL);
  c5_thisId.fIdentifier = "frnt";
  c5_b_y.frnt = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_b_u, "frnt", "frnt", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "rear";
  c5_b_y.rear = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_b_u, "rear", "rear", 0)), &c5_thisId);
  sf_mex_destroy(&c5_b_u);
  return c5_b_y;
}

static void c5_uc_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  PRESCAN_V2X_FIXED_BSM_vehicleIdent *c5_b_y)
{
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[6] = { "name", "vin", "ownerCode", "id",
    "vehicleType", "vehicleClass" };

  c5_thisId.fParent = c5_parentId;
  c5_thisId.bParentIsCell = false;
  sf_mex_check_struct(c5_parentId, c5_b_u, 6, c5_fieldNames, 0U, NULL);
  c5_thisId.fIdentifier = "name";
  c5_vc_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "name", "name", 0)), &c5_thisId, c5_b_y->name);
  c5_thisId.fIdentifier = "vin";
  c5_wc_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u, "vin",
    "vin", 0)), &c5_thisId, c5_b_y->vin);
  c5_thisId.fIdentifier = "ownerCode";
  c5_xc_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "ownerCode", "ownerCode", 0)), &c5_thisId, c5_b_y->ownerCode);
  c5_thisId.fIdentifier = "id";
  c5_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u, "id",
    "id", 0)), &c5_thisId, c5_b_y->id);
  c5_thisId.fIdentifier = "vehicleType";
  c5_b_y->vehicleType = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "vehicleType", "vehicleType", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "vehicleClass";
  c5_b_y->vehicleClass = c5_yc_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "vehicleClass", "vehicleClass", 0)), &c5_thisId);
  sf_mex_destroy(&c5_b_u);
}

static void c5_vc_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[63])
{
  int8_T c5_iv44[63];
  int32_T c5_i394;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv44, 1, 2, 0U, 1, 0U, 1, 63);
  for (c5_i394 = 0; c5_i394 < 63; c5_i394++) {
    c5_b_y[c5_i394] = c5_iv44[c5_i394];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_wc_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[17])
{
  int8_T c5_iv45[17];
  int32_T c5_i395;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv45, 1, 2, 0U, 1, 0U, 1, 17);
  for (c5_i395 = 0; c5_i395 < 17; c5_i395++) {
    c5_b_y[c5_i395] = c5_iv45[c5_i395];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_xc_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  int8_T c5_b_y[32])
{
  int8_T c5_iv46[32];
  int32_T c5_i396;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_iv46, 1, 2, 0U, 1, 0U, 1, 32);
  for (c5_i396 = 0; c5_i396 < 32; c5_i396++) {
    c5_b_y[c5_i396] = c5_iv46[c5_i396];
  }

  sf_mex_destroy(&c5_b_u);
}

static PRESCAN_V2X_FIXED_BSM_vehicleClass c5_yc_emlrt_marshallIn
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_b_u,
   const emlrtMsgIdentifier *c5_parentId)
{
  PRESCAN_V2X_FIXED_BSM_vehicleClass c5_b_y;
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[3] = { "vGroup", "rGroup", "rEquip" };

  c5_thisId.fParent = c5_parentId;
  c5_thisId.bParentIsCell = false;
  sf_mex_check_struct(c5_parentId, c5_b_u, 3, c5_fieldNames, 0U, NULL);
  c5_thisId.fIdentifier = "vGroup";
  c5_b_y.vGroup = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "vGroup", "vGroup", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "rGroup";
  c5_b_y.rGroup = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "rGroup", "rGroup", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "rEquip";
  c5_b_y.rEquip = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "rEquip", "rEquip", 0)), &c5_thisId);
  sf_mex_destroy(&c5_b_u);
  return c5_b_y;
}

static void c5_ad_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  PRESCAN_V2X_FIXED_BSM_j1939data *c5_b_y)
{
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[10] = { "tires", "axle", "trailerWeight",
    "cargoWeight", "steeringAxleTemperature", "driveAxleLocation",
    "driveAxleLiftAirPressure", "driveAxleTemperature", "driveAxleLubePressure",
    "steeringAxleLubePressure" };

  c5_thisId.fParent = c5_parentId;
  c5_thisId.bParentIsCell = false;
  sf_mex_check_struct(c5_parentId, c5_b_u, 10, c5_fieldNames, 0U, NULL);
  c5_thisId.fIdentifier = "tires";
  c5_bd_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "tires", "tires", 0)), &c5_thisId, c5_b_y->tires);
  c5_thisId.fIdentifier = "axle";
  c5_cd_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "axle", "axle", 0)), &c5_thisId, c5_b_y->axle);
  c5_thisId.fIdentifier = "trailerWeight";
  c5_b_y->trailerWeight = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "trailerWeight", "trailerWeight", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "cargoWeight";
  c5_b_y->cargoWeight = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "cargoWeight", "cargoWeight", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "steeringAxleTemperature";
  c5_b_y->steeringAxleTemperature = c5_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c5_b_u, "steeringAxleTemperature",
    "steeringAxleTemperature", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "driveAxleLocation";
  c5_b_y->driveAxleLocation = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "driveAxleLocation", "driveAxleLocation", 0)),
    &c5_thisId);
  c5_thisId.fIdentifier = "driveAxleLiftAirPressure";
  c5_b_y->driveAxleLiftAirPressure = c5_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c5_b_u, "driveAxleLiftAirPressure",
    "driveAxleLiftAirPressure", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "driveAxleTemperature";
  c5_b_y->driveAxleTemperature = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "driveAxleTemperature", "driveAxleTemperature", 0)),
    &c5_thisId);
  c5_thisId.fIdentifier = "driveAxleLubePressure";
  c5_b_y->driveAxleLubePressure = c5_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c5_b_u, "driveAxleLubePressure",
    "driveAxleLubePressure", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "steeringAxleLubePressure";
  c5_b_y->steeringAxleLubePressure = c5_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c5_b_u, "steeringAxleLubePressure",
    "steeringAxleLubePressure", 0)), &c5_thisId);
  sf_mex_destroy(&c5_b_u);
}

static void c5_bd_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  PRESCAN_V2X_FIXED_BSM_tires c5_b_y[16])
{
  uint32_T c5_uv1[1];
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[7] = { "location", "pressure", "temp",
    "wheelSensorStatus", "wheelEndElectFault", "leakageRate", "detection" };

  int32_T c5_i397;
  c5_uv1[0] = 16U;
  c5_thisId.fParent = c5_parentId;
  c5_thisId.bParentIsCell = false;
  sf_mex_check_struct(c5_parentId, c5_b_u, 7, c5_fieldNames, 1U, c5_uv1);
  for (c5_i397 = 0; c5_i397 < 16; c5_i397++) {
    c5_thisId.fIdentifier = "location";
    c5_b_y[c5_i397].location = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c5_b_u, "location", "location", c5_i397)), &c5_thisId);
    c5_thisId.fIdentifier = "pressure";
    c5_b_y[c5_i397].pressure = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c5_b_u, "pressure", "pressure", c5_i397)), &c5_thisId);
    c5_thisId.fIdentifier = "temp";
    c5_b_y[c5_i397].temp = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c5_b_u, "temp", "temp", c5_i397)), &c5_thisId);
    c5_thisId.fIdentifier = "wheelSensorStatus";
    c5_b_y[c5_i397].wheelSensorStatus = c5_g_emlrt_marshallIn(chartInstance,
      sf_mex_dup(sf_mex_getfield(c5_b_u, "wheelSensorStatus",
      "wheelSensorStatus", c5_i397)), &c5_thisId);
    c5_thisId.fIdentifier = "wheelEndElectFault";
    c5_b_y[c5_i397].wheelEndElectFault = c5_g_emlrt_marshallIn(chartInstance,
      sf_mex_dup(sf_mex_getfield(c5_b_u, "wheelEndElectFault",
      "wheelEndElectFault", c5_i397)), &c5_thisId);
    c5_thisId.fIdentifier = "leakageRate";
    c5_b_y[c5_i397].leakageRate = c5_g_emlrt_marshallIn(chartInstance,
      sf_mex_dup(sf_mex_getfield(c5_b_u, "leakageRate", "leakageRate", c5_i397)),
      &c5_thisId);
    c5_thisId.fIdentifier = "detection";
    c5_b_y[c5_i397].detection = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c5_b_u, "detection", "detection", c5_i397)), &c5_thisId);
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_cd_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  PRESCAN_V2X_FIXED_BSM_axle c5_b_y[16])
{
  uint32_T c5_uv2[1];
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[2] = { "location", "weight" };

  int32_T c5_i398;
  c5_uv2[0] = 16U;
  c5_thisId.fParent = c5_parentId;
  c5_thisId.bParentIsCell = false;
  sf_mex_check_struct(c5_parentId, c5_b_u, 2, c5_fieldNames, 1U, c5_uv2);
  for (c5_i398 = 0; c5_i398 < 16; c5_i398++) {
    c5_thisId.fIdentifier = "location";
    c5_b_y[c5_i398].location = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c5_b_u, "location", "location", c5_i398)), &c5_thisId);
    c5_thisId.fIdentifier = "weight";
    c5_b_y[c5_i398].weight = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c5_b_u, "weight", "weight", c5_i398)), &c5_thisId);
  }

  sf_mex_destroy(&c5_b_u);
}

static PRESCAN_V2X_FIXED_BSM_weatherReport c5_dd_emlrt_marshallIn
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_b_u,
   const emlrtMsgIdentifier *c5_parentId)
{
  PRESCAN_V2X_FIXED_BSM_weatherReport c5_b_y;
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[5] = { "isRaining", "rainRate",
    "precipSituation", "solarRadiation", "friction" };

  c5_thisId.fParent = c5_parentId;
  c5_thisId.bParentIsCell = false;
  sf_mex_check_struct(c5_parentId, c5_b_u, 5, c5_fieldNames, 0U, NULL);
  c5_thisId.fIdentifier = "isRaining";
  c5_b_y.isRaining = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "isRaining", "isRaining", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "rainRate";
  c5_b_y.rainRate = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "rainRate", "rainRate", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "precipSituation";
  c5_b_y.precipSituation = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "precipSituation", "precipSituation", 0)),
    &c5_thisId);
  c5_thisId.fIdentifier = "solarRadiation";
  c5_b_y.solarRadiation = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "solarRadiation", "solarRadiation", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "friction";
  c5_b_y.friction = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "friction", "friction", 0)), &c5_thisId);
  sf_mex_destroy(&c5_b_u);
  return c5_b_y;
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_y;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  PRESCAN_V2X_FIXED_BSM_MESSAGE c5_c_y;
  SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc5_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c5_b_y = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = (const char *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_y), &c5_thisId, &c5_c_y);
  sf_mex_destroy(&c5_b_y);
  *(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_outData = c5_c_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData;
  PRESCAN_HEADER c5_b_u;
  const mxArray *c5_b_y = NULL;
  static const char * c5_sv34[1] = { "valid" };

  boolean_T c5_c_u;
  const mxArray *c5_c_y = NULL;
  SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc5_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_mxArrayOutData = NULL;
  c5_b_u = *(PRESCAN_HEADER *)c5_inData;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_createstruct("structure", 1, c5_sv34, 2, 1, 1),
                false);
  c5_c_u = c5_b_u.valid;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_c_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "valid", c5_c_y, 0);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_u;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  PRESCAN_HEADER c5_b_y;
  SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc5_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c5_b_u = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = (const char *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_b_y = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_u), &c5_thisId);
  sf_mex_destroy(&c5_b_u);
  *(PRESCAN_HEADER *)c5_outData = c5_b_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_e_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData;
  PRESCAN_V2X_FIXED_BSM_size c5_b_u;
  const mxArray *c5_b_y = NULL;
  int32_T c5_c_u;
  const mxArray *c5_c_y = NULL;
  int32_T c5_d_u;
  const mxArray *c5_d_y = NULL;
  SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc5_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_mxArrayOutData = NULL;
  c5_b_u = *(PRESCAN_V2X_FIXED_BSM_size *)c5_inData;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_createstruct("structure", 2, c5_sv1, 2, 1, 1),
                false);
  c5_c_u = c5_b_u.width;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_c_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "width", c5_c_y, 0);
  c5_d_u = c5_b_u.length;
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", &c5_d_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "length", c5_d_y, 1);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_u;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  PRESCAN_V2X_FIXED_BSM_size c5_b_y;
  SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc5_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c5_b_u = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = (const char *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_b_y = c5_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_u), &c5_thisId);
  sf_mex_destroy(&c5_b_u);
  *(PRESCAN_V2X_FIXED_BSM_size *)c5_outData = c5_b_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_f_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData;
  c5_PRESCAN_V2X_USER_BSM_size c5_b_u;
  const mxArray *c5_b_y = NULL;
  int32_T c5_c_u;
  const mxArray *c5_c_y = NULL;
  int32_T c5_d_u;
  const mxArray *c5_d_y = NULL;
  SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc5_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_mxArrayOutData = NULL;
  c5_b_u = *(c5_PRESCAN_V2X_USER_BSM_size *)c5_inData;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_createstruct("structure", 2, c5_sv1, 2, 1, 1),
                false);
  c5_c_u = c5_b_u.width;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_c_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "width", c5_c_y, 0);
  c5_d_u = c5_b_u.length;
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", &c5_d_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c5_b_y, 0, "length", c5_d_y, 1);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static c5_PRESCAN_V2X_USER_BSM_size c5_ed_emlrt_marshallIn
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_b_u,
   const emlrtMsgIdentifier *c5_parentId)
{
  c5_PRESCAN_V2X_USER_BSM_size c5_b_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fParent = c5_parentId;
  c5_thisId.bParentIsCell = false;
  sf_mex_check_struct(c5_parentId, c5_b_u, 2, c5_sv5, 0U, NULL);
  c5_thisId.fIdentifier = "width";
  c5_b_y.width = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_b_u, "width", "width", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "length";
  c5_b_y.length = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "length", "length", 0)), &c5_thisId);
  sf_mex_destroy(&c5_b_u);
  return c5_b_y;
}

static void c5_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_y;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  c5_PRESCAN_V2X_USER_BSM_size c5_c_y;
  SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc5_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c5_b_y = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = (const char *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_c_y = c5_ed_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_y), &c5_thisId);
  sf_mex_destroy(&c5_b_y);
  *(c5_PRESCAN_V2X_USER_BSM_size *)c5_outData = c5_c_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_g_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc5_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  sf_mex_assign(&c5_mxArrayOutData, c5_d_emlrt_marshallOut(chartInstance,
    (PRESCAN_V2X_FIXED_BSM_DATA *)c5_inData), false);
  return c5_mxArrayOutData;
}

static void c5_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_u;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  PRESCAN_V2X_FIXED_BSM_DATA c5_b_y;
  SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc5_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c5_b_u = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = (const char *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_u), &c5_thisId, &c5_b_y);
  sf_mex_destroy(&c5_b_u);
  *(PRESCAN_V2X_FIXED_BSM_DATA *)c5_outData = c5_b_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_h_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc5_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  sf_mex_assign(&c5_mxArrayOutData, c5_emlrt_marshallOut(chartInstance,
    *(c5_PRESCAN_V2X_USER_BSM_DATA *)c5_inData), false);
  return c5_mxArrayOutData;
}

static c5_PRESCAN_V2X_USER_BSM_DATA c5_fd_emlrt_marshallIn
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_b_u,
   const emlrtMsgIdentifier *c5_parentId)
{
  c5_PRESCAN_V2X_USER_BSM_DATA c5_b_y;
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[14] = { "msgID", "msgCnt", "id", "secMark",
    "latitude", "longitude", "elev", "accuracy", "speed", "heading", "angle",
    "accelSet", "brakes", "size" };

  c5_thisId.fParent = c5_parentId;
  c5_thisId.bParentIsCell = false;
  sf_mex_check_struct(c5_parentId, c5_b_u, 14, c5_fieldNames, 0U, NULL);
  c5_thisId.fIdentifier = "msgID";
  c5_b_y.msgID = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_b_u, "msgID", "msgID", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "msgCnt";
  c5_b_y.msgCnt = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "msgCnt", "msgCnt", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "id";
  c5_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u, "id",
    "id", 0)), &c5_thisId, c5_b_y.id);
  c5_thisId.fIdentifier = "secMark";
  c5_b_y.secMark = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "secMark", "secMark", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "latitude";
  c5_b_y.latitude = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "latitude", "latitude", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "longitude";
  c5_b_y.longitude = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "longitude", "longitude", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "elev";
  c5_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u, "elev",
    "elev", 0)), &c5_thisId, c5_b_y.elev);
  c5_thisId.fIdentifier = "accuracy";
  c5_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "accuracy", "accuracy", 0)), &c5_thisId, c5_b_y.accuracy);
  c5_thisId.fIdentifier = "speed";
  c5_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "speed", "speed", 0)), &c5_thisId, c5_b_y.speed);
  c5_thisId.fIdentifier = "heading";
  c5_b_y.heading = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "heading", "heading", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "angle";
  c5_b_y.angle = c5_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_b_u, "angle", "angle", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "accelSet";
  c5_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "accelSet", "accelSet", 0)), &c5_thisId, c5_b_y.accelSet);
  c5_thisId.fIdentifier = "brakes";
  c5_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "brakes", "brakes", 0)), &c5_thisId, c5_b_y.brakes);
  c5_thisId.fIdentifier = "size";
  c5_b_y.size = c5_ed_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_b_u, "size", "size", 0)), &c5_thisId);
  sf_mex_destroy(&c5_b_u);
  return c5_b_y;
}

static void c5_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_y;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  c5_PRESCAN_V2X_USER_BSM_DATA c5_c_y;
  SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc5_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c5_b_y = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = (const char *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_c_y = c5_fd_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_y), &c5_thisId);
  sf_mex_destroy(&c5_b_y);
  *(c5_PRESCAN_V2X_USER_BSM_DATA *)c5_outData = c5_c_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static c5_PRESCAN_V2X_USER_BSM_MESSAGE c5_gd_emlrt_marshallIn
  (SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c5_b_u,
   const emlrtMsgIdentifier *c5_parentId)
{
  c5_PRESCAN_V2X_USER_BSM_MESSAGE c5_b_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fParent = c5_parentId;
  c5_thisId.bParentIsCell = false;
  sf_mex_check_struct(c5_parentId, c5_b_u, 2, c5_sv4, 0U, NULL);
  c5_thisId.fIdentifier = "HEADER";
  c5_b_y.HEADER = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "HEADER", "HEADER", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "DATA";
  c5_b_y.DATA = c5_fd_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_b_u, "DATA", "DATA", 0)), &c5_thisId);
  sf_mex_destroy(&c5_b_u);
  return c5_b_y;
}

static void c5_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_y;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  c5_PRESCAN_V2X_USER_BSM_MESSAGE c5_c_y;
  SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc5_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c5_b_y = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = (const char *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_c_y = c5_gd_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_y), &c5_thisId);
  sf_mex_destroy(&c5_b_y);
  *(c5_PRESCAN_V2X_USER_BSM_MESSAGE *)c5_outData = c5_c_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

const mxArray *sf_c5_Jan22_DLforACC_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  const char * c5_data[4] = {
    "789cc592cd4e834010c717531b3d687a30fa0e1e24c18b7ab2621bed87d650bf6370a5d394945dc82e18f4e483f8001e7d1b5fc7564ad96ed8d0c458e732fcf9"
    "2ff39b1d0669a76d0d21b48e92f82827796da22b93bc846643f635454e63199566be4bfdf749767c1a421c26c273299c45e409d848504c605aa6e71397621a76",
    "5f02400cb8ef3d43efc7e9bb1e745d022d5f1027ee4890ba604dc5d81a3f9b0370865644101bf0ac5d4f144898cfa3e2fea582f9c821cf473e97c7d38473e51c"
    "9ee817fd8f55b422d20f535ea0a89777bf3c9eac91f43ecd57c68d7d64b56d88034c7bc08aee3b2fbf2ce98c9f383c64911366f3fdfc25afa1e4cdfaf7b507f3",
    "40bfe4c0b8ce0dcf1f30ccf50e03cbc1d4aec501b0d14ed290eb0d4c0dc33e6ef57d56354d5d9ed30e49ea2d6e3fdeb637b6beaa8bddc745effffff16245bd79"
    "f76f53c1ab487eebe22e189e5fbf766f2dbaefe1ea5eb0eb34eb591f9d024e511f48a1ffbafe376fab6141",
    "" };

  c5_nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(c5_data, 1728U, &c5_nameCaptureInfo);
  return c5_nameCaptureInfo;
}

static const mxArray *c5_i_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData;
  int32_T c5_b_u;
  const mxArray *c5_b_y = NULL;
  SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc5_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_mxArrayOutData = NULL;
  c5_b_u = *(int32_T *)c5_inData;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static void c5_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_b_y;
  SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc5_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = (const char *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_b_y = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_b_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_u_bus_io(void *chartInstanceVoid, void *c5_pData)
{
  const mxArray *c5_mxVal = NULL;
  c5_PRESCAN_V2X_USER_BSM_MESSAGE c5_tmp;
  int32_T c5_i399;
  int32_T c5_i400;
  int32_T c5_i401;
  int32_T c5_i402;
  int32_T c5_i403;
  int32_T c5_i404;
  SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc5_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c5_mxVal = NULL;
  c5_tmp.HEADER.valid = *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)
    (c5_PRESCAN_V2X_USER_BSM_MESSAGE *)c5_pData)[0])[0];
  c5_tmp.DATA.msgID = *(int32_T *)&((char_T *)(c5_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)(c5_PRESCAN_V2X_USER_BSM_MESSAGE *)c5_pData)[8])[0];
  c5_tmp.DATA.msgCnt = *(int32_T *)&((char_T *)(c5_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)(c5_PRESCAN_V2X_USER_BSM_MESSAGE *)c5_pData)[8])[4];
  for (c5_i399 = 0; c5_i399 < 4; c5_i399++) {
    c5_tmp.DATA.id[c5_i399] = ((int8_T *)&((char_T *)
      (c5_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
      (c5_PRESCAN_V2X_USER_BSM_MESSAGE *)c5_pData)[8])[8])[c5_i399];
  }

  c5_tmp.DATA.secMark = *(int32_T *)&((char_T *)(c5_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)(c5_PRESCAN_V2X_USER_BSM_MESSAGE *)c5_pData)[8])[12];
  c5_tmp.DATA.latitude = *(int32_T *)&((char_T *)(c5_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)(c5_PRESCAN_V2X_USER_BSM_MESSAGE *)c5_pData)[8])[16];
  c5_tmp.DATA.longitude = *(int32_T *)&((char_T *)(c5_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)(c5_PRESCAN_V2X_USER_BSM_MESSAGE *)c5_pData)[8])[20];
  for (c5_i400 = 0; c5_i400 < 2; c5_i400++) {
    c5_tmp.DATA.elev[c5_i400] = ((int8_T *)&((char_T *)
      (c5_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
      (c5_PRESCAN_V2X_USER_BSM_MESSAGE *)c5_pData)[8])[24])[c5_i400];
  }

  for (c5_i401 = 0; c5_i401 < 4; c5_i401++) {
    c5_tmp.DATA.accuracy[c5_i401] = ((int8_T *)&((char_T *)
      (c5_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
      (c5_PRESCAN_V2X_USER_BSM_MESSAGE *)c5_pData)[8])[26])[c5_i401];
  }

  for (c5_i402 = 0; c5_i402 < 2; c5_i402++) {
    c5_tmp.DATA.speed[c5_i402] = ((int8_T *)&((char_T *)
      (c5_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
      (c5_PRESCAN_V2X_USER_BSM_MESSAGE *)c5_pData)[8])[30])[c5_i402];
  }

  c5_tmp.DATA.heading = *(int32_T *)&((char_T *)(c5_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)(c5_PRESCAN_V2X_USER_BSM_MESSAGE *)c5_pData)[8])[32];
  c5_tmp.DATA.angle = *(int8_T *)&((char_T *)(c5_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)(c5_PRESCAN_V2X_USER_BSM_MESSAGE *)c5_pData)[8])[36];
  for (c5_i403 = 0; c5_i403 < 7; c5_i403++) {
    c5_tmp.DATA.accelSet[c5_i403] = ((int8_T *)&((char_T *)
      (c5_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
      (c5_PRESCAN_V2X_USER_BSM_MESSAGE *)c5_pData)[8])[37])[c5_i403];
  }

  for (c5_i404 = 0; c5_i404 < 2; c5_i404++) {
    c5_tmp.DATA.brakes[c5_i404] = ((int8_T *)&((char_T *)
      (c5_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
      (c5_PRESCAN_V2X_USER_BSM_MESSAGE *)c5_pData)[8])[44])[c5_i404];
  }

  c5_tmp.DATA.size.width = *(int32_T *)&((char_T *)(c5_PRESCAN_V2X_USER_BSM_size
    *)&((char_T *)(c5_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
    (c5_PRESCAN_V2X_USER_BSM_MESSAGE *)c5_pData)[8])[48])[0];
  c5_tmp.DATA.size.length = *(int32_T *)&((char_T *)
    (c5_PRESCAN_V2X_USER_BSM_size *)&((char_T *)(c5_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)(c5_PRESCAN_V2X_USER_BSM_MESSAGE *)c5_pData)[8])[48])[4];
  sf_mex_assign(&c5_mxVal, c5_b_sf_marshallOut(chartInstance, &c5_tmp), false);
  return c5_mxVal;
}

static const mxArray *c5_y_bus_io(void *chartInstanceVoid, void *c5_pData)
{
  const mxArray *c5_mxVal = NULL;
  PRESCAN_V2X_FIXED_BSM_MESSAGE c5_tmp;
  int32_T c5_i405;
  int32_T c5_i406;
  int32_T c5_i407;
  int32_T c5_i408;
  int32_T c5_i409;
  int32_T c5_i410;
  int32_T c5_i411;
  int32_T c5_i412;
  int32_T c5_i413;
  int32_T c5_i414;
  int32_T c5_i415;
  int32_T c5_i416;
  int32_T c5_i417;
  int32_T c5_i418;
  int32_T c5_i419;
  int32_T c5_i420;
  int32_T c5_i421;
  int32_T c5_i422;
  int32_T c5_i423;
  int32_T c5_i424;
  int32_T c5_i425;
  int32_T c5_i426;
  int32_T c5_i427;
  int32_T c5_i428;
  int32_T c5_i429;
  int32_T c5_i430;
  int32_T c5_i431;
  int32_T c5_i432;
  int32_T c5_i433;
  int32_T c5_i434;
  int32_T c5_i435;
  int32_T c5_i436;
  int32_T c5_i437;
  int32_T c5_i438;
  int32_T c5_i439;
  int32_T c5_i440;
  int32_T c5_i441;
  int32_T c5_i442;
  int32_T c5_i443;
  int32_T c5_i444;
  int32_T c5_i445;
  int32_T c5_i446;
  int32_T c5_i447;
  int32_T c5_i448;
  int32_T c5_i449;
  int32_T c5_i450;
  int32_T c5_i451;
  int32_T c5_i452;
  int32_T c5_i453;
  int32_T c5_i454;
  int32_T c5_i455;
  int32_T c5_i456;
  int32_T c5_i457;
  int32_T c5_i458;
  int32_T c5_i459;
  int32_T c5_i460;
  int32_T c5_i461;
  int32_T c5_i462;
  int32_T c5_i463;
  int32_T c5_i464;
  int32_T c5_i465;
  int32_T c5_i466;
  int32_T c5_i467;
  int32_T c5_i468;
  int32_T c5_i469;
  int32_T c5_i470;
  SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc5_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c5_mxVal = NULL;
  c5_tmp.HEADER.valid = *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[0])[0];
  c5_tmp.DATA.msgID = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[0];
  c5_tmp.DATA.msgCnt = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[4];
  for (c5_i405 = 0; c5_i405 < 4; c5_i405++) {
    c5_tmp.DATA.id[c5_i405] = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[8])[c5_i405];
  }

  c5_tmp.DATA.secMark = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[12];
  c5_tmp.DATA.latitude = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[16];
  c5_tmp.DATA.longitude = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[20];
  for (c5_i406 = 0; c5_i406 < 2; c5_i406++) {
    c5_tmp.DATA.elev[c5_i406] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
      c5_pData)[8])[24])[c5_i406];
  }

  for (c5_i407 = 0; c5_i407 < 4; c5_i407++) {
    c5_tmp.DATA.accuracy[c5_i407] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
      c5_pData)[8])[26])[c5_i407];
  }

  for (c5_i408 = 0; c5_i408 < 2; c5_i408++) {
    c5_tmp.DATA.speed[c5_i408] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
      c5_pData)[8])[30])[c5_i408];
  }

  c5_tmp.DATA.heading = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[32];
  c5_tmp.DATA.angle = *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[36];
  for (c5_i409 = 0; c5_i409 < 7; c5_i409++) {
    c5_tmp.DATA.accelSet[c5_i409] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
      c5_pData)[8])[37])[c5_i409];
  }

  for (c5_i410 = 0; c5_i410 < 2; c5_i410++) {
    c5_tmp.DATA.brakes[c5_i410] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
      c5_pData)[8])[44])[c5_i410];
  }

  c5_tmp.DATA.size.width = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_size *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[48])[0];
  c5_tmp.DATA.size.length = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_size *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[48])[4];
  c5_tmp.DATA.safetyExt.events = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[0];
  c5_tmp.DATA.safetyExt.pathHistory.initialPosition.utcTime.year = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[8])[0])[0])[0];
  c5_tmp.DATA.safetyExt.pathHistory.initialPosition.utcTime.month = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[8])[0])[0])[4];
  c5_tmp.DATA.safetyExt.pathHistory.initialPosition.utcTime.day = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[8])[0])[0])[8];
  c5_tmp.DATA.safetyExt.pathHistory.initialPosition.utcTime.hour = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[8])[0])[0])[12];
  c5_tmp.DATA.safetyExt.pathHistory.initialPosition.utcTime.minute = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[8])[0])[0])[16];
  c5_tmp.DATA.safetyExt.pathHistory.initialPosition.utcTime.second = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[8])[0])[0])[20];
  c5_tmp.DATA.safetyExt.pathHistory.initialPosition.longitude = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[8])[0])[24];
  c5_tmp.DATA.safetyExt.pathHistory.initialPosition.latitude = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[8])[0])[28];
  for (c5_i411 = 0; c5_i411 < 2; c5_i411++) {
    c5_tmp.DATA.safetyExt.pathHistory.initialPosition.elevation[c5_i411] =
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[8])[0])[32])
      [c5_i411];
  }

  c5_tmp.DATA.safetyExt.pathHistory.initialPosition.heading = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[8])[0])[36];
  for (c5_i412 = 0; c5_i412 < 2; c5_i412++) {
    c5_tmp.DATA.safetyExt.pathHistory.initialPosition.speed[c5_i412] = ((int8_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[8])[0])
      [40])[c5_i412];
  }

  for (c5_i413 = 0; c5_i413 < 4; c5_i413++) {
    c5_tmp.DATA.safetyExt.pathHistory.initialPosition.posAccuracy[c5_i413] =
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[8])[0])[42])
      [c5_i413];
  }

  c5_tmp.DATA.safetyExt.pathHistory.initialPosition.timeConfidence = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[8])[0])[48];
  c5_tmp.DATA.safetyExt.pathHistory.initialPosition.posConfidence = *(int8_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[8])[0])[52];
  c5_tmp.DATA.safetyExt.pathHistory.initialPosition.speedConfidence = *(int8_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[8])[0])[53];
  c5_tmp.DATA.safetyExt.pathHistory.currGPSstatus = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[8])[56];
  c5_tmp.DATA.safetyExt.pathHistory.itemCnt = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[8])[60];
  for (c5_i414 = 0; c5_i414 < 23; c5_i414++) {
    c5_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c5_i414]
      .latOffset = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[8])[64])
      [0])[32 * (int32_T)c5_i414])[0];
    c5_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c5_i414]
      .longOffset = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[8])[64])
      [0])[32 * (int32_T)c5_i414])[4];
    c5_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c5_i414]
      .elevationOffset = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[8])[64])
      [0])[32 * (int32_T)c5_i414])[8];
    c5_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c5_i414]
      .timeOffset = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[8])[64])
      [0])[32 * (int32_T)c5_i414])[12];
    for (c5_i417 = 0; c5_i417 < 4; c5_i417++) {
      c5_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c5_i414]
        .posAccuracy[c5_i417] = ((int8_T *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE
        *)c5_pData)[8])[56])[8])[64])[0])[32 * (int32_T)c5_i414])[16])[c5_i417];
    }

    c5_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c5_i414]
      .heading = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[8])[64])
      [0])[32 * (int32_T)c5_i414])[20];
    for (c5_i419 = 0; c5_i419 < 2; c5_i419++) {
      c5_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c5_i414]
        .speed[c5_i419] = ((int8_T *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE
        *)c5_pData)[8])[56])[8])[64])[0])[32 * (int32_T)c5_i414])[24])[c5_i419];
    }
  }

  for (c5_i415 = 0; c5_i415 < 345; c5_i415++) {
    c5_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_02[c5_i415]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
              (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[8])[64])[736])
      [c5_i415];
  }

  for (c5_i416 = 0; c5_i416 < 276; c5_i416++) {
    c5_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_03[c5_i416]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
              (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[8])[64])[1081])
      [c5_i416];
  }

  for (c5_i418 = 0; c5_i418 < 184; c5_i418++) {
    c5_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_04[c5_i418]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
              (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[8])[64])[1357])
      [c5_i418];
  }

  for (c5_i420 = 0; c5_i420 < 230; c5_i420++) {
    c5_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_05[c5_i420]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
              (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[8])[64])[1541])
      [c5_i420];
  }

  for (c5_i421 = 0; c5_i421 < 138; c5_i421++) {
    c5_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_06[c5_i421]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
              (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[8])[64])[1771])
      [c5_i421];
  }

  for (c5_i422 = 0; c5_i422 < 242; c5_i422++) {
    c5_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_07[c5_i422]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
              (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[8])[64])[1909])
      [c5_i422];
  }

  for (c5_i423 = 0; c5_i423 < 161; c5_i423++) {
    c5_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_08[c5_i423]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
              (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[8])[64])[2151])
      [c5_i423];
  }

  for (c5_i424 = 0; c5_i424 < 196; c5_i424++) {
    c5_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_09[c5_i424]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
              (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[8])[64])[2312])
      [c5_i424];
  }

  for (c5_i425 = 0; c5_i425 < 104; c5_i425++) {
    c5_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_10[c5_i425]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
              (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[8])[64])[2508])
      [c5_i425];
  }

  c5_tmp.DATA.safetyExt.pathPrediction.radiusOfCurve = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathPrediction *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2688])[0];
  c5_tmp.DATA.safetyExt.pathPrediction.confidence = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathPrediction *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2688])[4];
  c5_tmp.DATA.safetyExt.theRTCM.anchorPoint.utcTime.year = *(int32_T *)&((char_T
    *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])[0])[0])
    [0];
  c5_tmp.DATA.safetyExt.theRTCM.anchorPoint.utcTime.month = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])[0])[0])[4];
  c5_tmp.DATA.safetyExt.theRTCM.anchorPoint.utcTime.day = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])[0])[0])
    [8];
  c5_tmp.DATA.safetyExt.theRTCM.anchorPoint.utcTime.hour = *(int32_T *)&((char_T
    *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])[0])[0])
    [12];
  c5_tmp.DATA.safetyExt.theRTCM.anchorPoint.utcTime.minute = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])[0])[0])[16];
  c5_tmp.DATA.safetyExt.theRTCM.anchorPoint.utcTime.second = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])[0])[0])[20];
  c5_tmp.DATA.safetyExt.theRTCM.anchorPoint.longitude = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])[0])
    [24];
  c5_tmp.DATA.safetyExt.theRTCM.anchorPoint.latitude = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])[0])
    [28];
  for (c5_i426 = 0; c5_i426 < 2; c5_i426++) {
    c5_tmp.DATA.safetyExt.theRTCM.anchorPoint.elevation[c5_i426] = ((int8_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])[0])
      [32])[c5_i426];
  }

  c5_tmp.DATA.safetyExt.theRTCM.anchorPoint.heading = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])[0])
    [36];
  for (c5_i427 = 0; c5_i427 < 2; c5_i427++) {
    c5_tmp.DATA.safetyExt.theRTCM.anchorPoint.speed[c5_i427] = ((int8_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])[0])
      [40])[c5_i427];
  }

  for (c5_i428 = 0; c5_i428 < 4; c5_i428++) {
    c5_tmp.DATA.safetyExt.theRTCM.anchorPoint.posAccuracy[c5_i428] = ((int8_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])[0])
      [42])[c5_i428];
  }

  c5_tmp.DATA.safetyExt.theRTCM.anchorPoint.timeConfidence = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])[0])[48];
  c5_tmp.DATA.safetyExt.theRTCM.anchorPoint.posConfidence = *(int8_T *)&((char_T
    *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])[0])
    [52];
  c5_tmp.DATA.safetyExt.theRTCM.anchorPoint.speedConfidence = *(int8_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])[0])[53];
  for (c5_i429 = 0; c5_i429 < 5; c5_i429++) {
    c5_tmp.DATA.safetyExt.theRTCM.rtcmHeader[c5_i429] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])
      [56])[c5_i429];
  }

  for (c5_i430 = 0; c5_i430 < 124; c5_i430++) {
    c5_tmp.DATA.safetyExt.theRTCM.msg1001[c5_i430] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])
      [61])[c5_i430];
  }

  for (c5_i431 = 0; c5_i431 < 156; c5_i431++) {
    c5_tmp.DATA.safetyExt.theRTCM.msg1002[c5_i431] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])
      [185])[c5_i431];
  }

  for (c5_i432 = 0; c5_i432 < 210; c5_i432++) {
    c5_tmp.DATA.safetyExt.theRTCM.msg1003[c5_i432] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])
      [341])[c5_i432];
  }

  for (c5_i433 = 0; c5_i433 < 258; c5_i433++) {
    c5_tmp.DATA.safetyExt.theRTCM.msg1004[c5_i433] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])
      [551])[c5_i433];
  }

  for (c5_i434 = 0; c5_i434 < 19; c5_i434++) {
    c5_tmp.DATA.safetyExt.theRTCM.msg1005[c5_i434] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])
      [809])[c5_i434];
  }

  for (c5_i435 = 0; c5_i435 < 21; c5_i435++) {
    c5_tmp.DATA.safetyExt.theRTCM.msg1006[c5_i435] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])
      [828])[c5_i435];
  }

  for (c5_i436 = 0; c5_i436 < 36; c5_i436++) {
    c5_tmp.DATA.safetyExt.theRTCM.msg1007[c5_i436] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])
      [849])[c5_i436];
  }

  for (c5_i437 = 0; c5_i437 < 68; c5_i437++) {
    c5_tmp.DATA.safetyExt.theRTCM.msg1008[c5_i437] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])
      [885])[c5_i437];
  }

  for (c5_i438 = 0; c5_i438 < 136; c5_i438++) {
    c5_tmp.DATA.safetyExt.theRTCM.msg1009[c5_i438] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])
      [953])[c5_i438];
  }

  for (c5_i439 = 0; c5_i439 < 166; c5_i439++) {
    c5_tmp.DATA.safetyExt.theRTCM.msg1010[c5_i439] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])
      [1089])[c5_i439];
  }

  for (c5_i440 = 0; c5_i440 < 222; c5_i440++) {
    c5_tmp.DATA.safetyExt.theRTCM.msg1011[c5_i440] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])
      [1255])[c5_i440];
  }

  for (c5_i441 = 0; c5_i441 < 268; c5_i441++) {
    c5_tmp.DATA.safetyExt.theRTCM.msg1012[c5_i441] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])
      [1477])[c5_i441];
  }

  for (c5_i442 = 0; c5_i442 < 27; c5_i442++) {
    c5_tmp.DATA.safetyExt.theRTCM.msg1013[c5_i442] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])
      [1745])[c5_i442];
  }

  for (c5_i443 = 0; c5_i443 < 15; c5_i443++) {
    c5_tmp.DATA.safetyExt.theRTCM.msg1014[c5_i443] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])
      [1772])[c5_i443];
  }

  for (c5_i444 = 0; c5_i444 < 69; c5_i444++) {
    c5_tmp.DATA.safetyExt.theRTCM.msg1015[c5_i444] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])
      [1787])[c5_i444];
  }

  for (c5_i445 = 0; c5_i445 < 81; c5_i445++) {
    c5_tmp.DATA.safetyExt.theRTCM.msg1016[c5_i445] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])
      [1856])[c5_i445];
  }

  for (c5_i446 = 0; c5_i446 < 115; c5_i446++) {
    c5_tmp.DATA.safetyExt.theRTCM.msg1017[c5_i446] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])
      [1937])[c5_i446];
  }

  for (c5_i447 = 0; c5_i447 < 62; c5_i447++) {
    c5_tmp.DATA.safetyExt.theRTCM.msg1019[c5_i447] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])
      [2052])[c5_i447];
  }

  for (c5_i448 = 0; c5_i448 < 45; c5_i448++) {
    c5_tmp.DATA.safetyExt.theRTCM.msg1020[c5_i448] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])
      [2114])[c5_i448];
  }

  for (c5_i449 = 0; c5_i449 < 62; c5_i449++) {
    c5_tmp.DATA.safetyExt.theRTCM.msg1021[c5_i449] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])
      [2159])[c5_i449];
  }

  for (c5_i450 = 0; c5_i450 < 75; c5_i450++) {
    c5_tmp.DATA.safetyExt.theRTCM.msg1022[c5_i450] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])
      [2221])[c5_i450];
  }

  for (c5_i451 = 0; c5_i451 < 73; c5_i451++) {
    c5_tmp.DATA.safetyExt.theRTCM.msg1023[c5_i451] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])
      [2296])[c5_i451];
  }

  for (c5_i452 = 0; c5_i452 < 74; c5_i452++) {
    c5_tmp.DATA.safetyExt.theRTCM.msg1024[c5_i452] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])
      [2369])[c5_i452];
  }

  for (c5_i453 = 0; c5_i453 < 25; c5_i453++) {
    c5_tmp.DATA.safetyExt.theRTCM.msg1025[c5_i453] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])
      [2443])[c5_i453];
  }

  for (c5_i454 = 0; c5_i454 < 30; c5_i454++) {
    c5_tmp.DATA.safetyExt.theRTCM.msg1026[c5_i454] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])
      [2468])[c5_i454];
  }

  for (c5_i455 = 0; c5_i455 < 33; c5_i455++) {
    c5_tmp.DATA.safetyExt.theRTCM.msg1027[c5_i455] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])
      [2498])[c5_i455];
  }

  for (c5_i456 = 0; c5_i456 < 69; c5_i456++) {
    c5_tmp.DATA.safetyExt.theRTCM.msg1029[c5_i456] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])
      [2531])[c5_i456];
  }

  for (c5_i457 = 0; c5_i457 < 105; c5_i457++) {
    c5_tmp.DATA.safetyExt.theRTCM.msg1030[c5_i457] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])
      [2600])[c5_i457];
  }

  for (c5_i458 = 0; c5_i458 < 107; c5_i458++) {
    c5_tmp.DATA.safetyExt.theRTCM.msg1031[c5_i458] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])
      [2705])[c5_i458];
  }

  for (c5_i459 = 0; c5_i459 < 20; c5_i459++) {
    c5_tmp.DATA.safetyExt.theRTCM.msg1032[c5_i459] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[56])[2696])
      [2812])[c5_i459];
  }

  c5_tmp.DATA.status.lights = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[0];
  c5_tmp.DATA.status.lightBar = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[4];
  c5_tmp.DATA.status.wipers.statusFront = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[8])[0];
  c5_tmp.DATA.status.wipers.rateFront = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[8])[4];
  c5_tmp.DATA.status.wipers.statusRear = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[8])[8];
  c5_tmp.DATA.status.wipers.rateRear = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[8])[12];
  for (c5_i460 = 0; c5_i460 < 2; c5_i460++) {
    c5_tmp.DATA.status.brakeStatus[c5_i460] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[24])
      [c5_i460];
  }

  c5_tmp.DATA.status.brakePressure = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[28];
  c5_tmp.DATA.status.roadFriction = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[32];
  c5_tmp.DATA.status.sunData = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[36];
  c5_tmp.DATA.status.rainData = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[40];
  c5_tmp.DATA.status.airTemp = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[44];
  c5_tmp.DATA.status.airPres = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[48];
  c5_tmp.DATA.status.steering.angle = *(int8_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[56])[0];
  c5_tmp.DATA.status.steering.confidence = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[56])[4];
  c5_tmp.DATA.status.steering.rate = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[56])[8];
  c5_tmp.DATA.status.steering.wheels = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[56])[12];
  for (c5_i461 = 0; c5_i461 < 7; c5_i461++) {
    c5_tmp.DATA.status.accelSets.accel4way[c5_i461] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[72])[0])
      [c5_i461];
  }

  c5_tmp.DATA.status.accelSets.vertAccelThres = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[72])[8];
  c5_tmp.DATA.status.accelSets.yawRateCon = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[72])[12];
  c5_tmp.DATA.status.accelSets.hozAccelCon = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[72])[16];
  c5_tmp.DATA.status.accelSets.confidenceSet.accelConfidence.yawRate = *(int32_T
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelConfidence *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[72])[24])[0])
    [0];
  c5_tmp.DATA.status.accelSets.confidenceSet.accelConfidence.acceleration =
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelConfidence *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[72])[24])[0])[4];
  c5_tmp.DATA.status.accelSets.confidenceSet.accelConfidence.steeringWheelAngle =
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelConfidence *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[72])[24])[0])[8];
  c5_tmp.DATA.status.accelSets.confidenceSet.speedConfidence = *(int8_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
         &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[72])
      [24])[16];
  c5_tmp.DATA.status.accelSets.confidenceSet.timeConfidence = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
         &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[72])
      [24])[20];
  c5_tmp.DATA.status.accelSets.confidenceSet.posConfidence = *(int8_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
         &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[72])
      [24])[24];
  c5_tmp.DATA.status.accelSets.confidenceSet.steerConfidence = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
         &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[72])
      [24])[28];
  c5_tmp.DATA.status.accelSets.confidenceSet.throttleConfidence = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
         &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[72])
      [24])[32];
  c5_tmp.DATA.status.object.obDist = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[136])[0];
  c5_tmp.DATA.status.object.obDirect = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[136])[4];
  c5_tmp.DATA.status.object.dateTime.year = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    c5_pData)[8])[5584])[136])[8])[0];
  c5_tmp.DATA.status.object.dateTime.month = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    c5_pData)[8])[5584])[136])[8])[4];
  c5_tmp.DATA.status.object.dateTime.day = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    c5_pData)[8])[5584])[136])[8])[8];
  c5_tmp.DATA.status.object.dateTime.hour = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    c5_pData)[8])[5584])[136])[8])[12];
  c5_tmp.DATA.status.object.dateTime.minute = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    c5_pData)[8])[5584])[136])[8])[16];
  c5_tmp.DATA.status.object.dateTime.second = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    c5_pData)[8])[5584])[136])[8])[20];
  c5_tmp.DATA.status.fullPos.utcTime.year = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    c5_pData)[8])[5584])[168])[0])[0];
  c5_tmp.DATA.status.fullPos.utcTime.month = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    c5_pData)[8])[5584])[168])[0])[4];
  c5_tmp.DATA.status.fullPos.utcTime.day = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    c5_pData)[8])[5584])[168])[0])[8];
  c5_tmp.DATA.status.fullPos.utcTime.hour = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    c5_pData)[8])[5584])[168])[0])[12];
  c5_tmp.DATA.status.fullPos.utcTime.minute = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    c5_pData)[8])[5584])[168])[0])[16];
  c5_tmp.DATA.status.fullPos.utcTime.second = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    c5_pData)[8])[5584])[168])[0])[20];
  c5_tmp.DATA.status.fullPos.longitude = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[168])[24];
  c5_tmp.DATA.status.fullPos.latitude = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[168])[28];
  for (c5_i462 = 0; c5_i462 < 2; c5_i462++) {
    c5_tmp.DATA.status.fullPos.elevation[c5_i462] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[168])[32])[c5_i462];
  }

  c5_tmp.DATA.status.fullPos.heading = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[168])[36];
  for (c5_i463 = 0; c5_i463 < 2; c5_i463++) {
    c5_tmp.DATA.status.fullPos.speed[c5_i463] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[168])[40])[c5_i463];
  }

  for (c5_i464 = 0; c5_i464 < 4; c5_i464++) {
    c5_tmp.DATA.status.fullPos.posAccuracy[c5_i464] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[168])[42])[c5_i464];
  }

  c5_tmp.DATA.status.fullPos.timeConfidence = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[168])[48];
  c5_tmp.DATA.status.fullPos.posConfidence = *(int8_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[168])[52];
  c5_tmp.DATA.status.fullPos.speedConfidence = *(int8_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[168])[53];
  c5_tmp.DATA.status.throttlePos = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[224];
  c5_tmp.DATA.status.speedHeadC = *(int8_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[228];
  c5_tmp.DATA.status.speedC = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[232];
  c5_tmp.DATA.status.vehicleData.height = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[240])[0];
  c5_tmp.DATA.status.vehicleData.bumpers.frnt = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_bumpers *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[240])[8])
    [0];
  c5_tmp.DATA.status.vehicleData.bumpers.rear = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_bumpers *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[240])[8])
    [4];
  c5_tmp.DATA.status.vehicleData.mass = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[240])[16];
  c5_tmp.DATA.status.vehicleData.trailerWeight = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[240])[20];
  c5_tmp.DATA.status.vehicleData.type = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[240])[24];
  for (c5_i465 = 0; c5_i465 < 63; c5_i465++) {
    c5_tmp.DATA.status.vehicleIdent.name[c5_i465] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[272])[0])
      [c5_i465];
  }

  for (c5_i466 = 0; c5_i466 < 17; c5_i466++) {
    c5_tmp.DATA.status.vehicleIdent.vin[c5_i466] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[272])[63])
      [c5_i466];
  }

  for (c5_i467 = 0; c5_i467 < 32; c5_i467++) {
    c5_tmp.DATA.status.vehicleIdent.ownerCode[c5_i467] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[272])[80])
      [c5_i467];
  }

  for (c5_i468 = 0; c5_i468 < 4; c5_i468++) {
    c5_tmp.DATA.status.vehicleIdent.id[c5_i468] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[272])
      [112])[c5_i468];
  }

  c5_tmp.DATA.status.vehicleIdent.vehicleType = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[272])[116];
  c5_tmp.DATA.status.vehicleIdent.vehicleClass.vGroup = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleClass *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[272])[120])
    [0];
  c5_tmp.DATA.status.vehicleIdent.vehicleClass.rGroup = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleClass *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[272])[120])
    [4];
  c5_tmp.DATA.status.vehicleIdent.vehicleClass.rEquip = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleClass *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[272])[120])
    [8];
  for (c5_i469 = 0; c5_i469 < 16; c5_i469++) {
    c5_tmp.DATA.status.j1939data.tires[c5_i469].location = *(int32_T *)&((char_T
      *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[408])[0])
      [32 * (int32_T)c5_i469])[0];
    c5_tmp.DATA.status.j1939data.tires[c5_i469].pressure = *(int32_T *)&((char_T
      *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[408])[0])
      [32 * (int32_T)c5_i469])[4];
    c5_tmp.DATA.status.j1939data.tires[c5_i469].temp = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[408])[0])
      [32 * (int32_T)c5_i469])[8];
    c5_tmp.DATA.status.j1939data.tires[c5_i469].wheelSensorStatus = *(int32_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[408])[0])[32 *
        (int32_T)c5_i469])[12];
    c5_tmp.DATA.status.j1939data.tires[c5_i469].wheelEndElectFault = *(int32_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[408])[0])[32 *
        (int32_T)c5_i469])[16];
    c5_tmp.DATA.status.j1939data.tires[c5_i469].leakageRate = *(int32_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[408])[0])[32 *
        (int32_T)c5_i469])[20];
    c5_tmp.DATA.status.j1939data.tires[c5_i469].detection = *(int32_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[408])[0])[32 *
        (int32_T)c5_i469])[24];
  }

  for (c5_i470 = 0; c5_i470 < 16; c5_i470++) {
    c5_tmp.DATA.status.j1939data.axle[c5_i470].location = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_axle *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_axle *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[408])
      [512])[8 * (int32_T)c5_i470])[0];
    c5_tmp.DATA.status.j1939data.axle[c5_i470].weight = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_axle *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_axle *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[408])
      [512])[8 * (int32_T)c5_i470])[4];
  }

  c5_tmp.DATA.status.j1939data.trailerWeight = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[408])[640];
  c5_tmp.DATA.status.j1939data.cargoWeight = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[408])[644];
  c5_tmp.DATA.status.j1939data.steeringAxleTemperature = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[408])[648];
  c5_tmp.DATA.status.j1939data.driveAxleLocation = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[408])[652];
  c5_tmp.DATA.status.j1939data.driveAxleLiftAirPressure = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[408])[656];
  c5_tmp.DATA.status.j1939data.driveAxleTemperature = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[408])[660];
  c5_tmp.DATA.status.j1939data.driveAxleLubePressure = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[408])[664];
  c5_tmp.DATA.status.j1939data.steeringAxleLubePressure = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[408])[668];
  c5_tmp.DATA.status.weatherReport.isRaining = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[1080])[0];
  c5_tmp.DATA.status.weatherReport.rainRate = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[1080])[4];
  c5_tmp.DATA.status.weatherReport.precipSituation = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[1080])[8];
  c5_tmp.DATA.status.weatherReport.solarRadiation = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[1080])[12];
  c5_tmp.DATA.status.weatherReport.friction = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[1080])[16];
  c5_tmp.DATA.status.gpsStatus = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c5_pData)[8])[5584])[1104];
  sf_mex_assign(&c5_mxVal, c5_c_sf_marshallOut(chartInstance, &c5_tmp), false);
  return c5_mxVal;
}

static uint8_T c5_hd_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_Jan22_DLforACC_cs, const
  char_T *c5_identifier)
{
  uint8_T c5_b_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = (const char *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_b_y = c5_id_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_is_active_c5_Jan22_DLforACC_cs), &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_Jan22_DLforACC_cs);
  return c5_b_y;
}

static uint8_T c5_id_emlrt_marshallIn(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_b_y;
  uint8_T c5_u0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_b_y = c5_u0;
  sf_mex_destroy(&c5_b_u);
  return c5_b_y;
}

static void init_dsm_address_info(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc5_Jan22_DLforACC_csInstanceStruct
  *chartInstance)
{
  chartInstance->c5_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c5_u = (c5_PRESCAN_V2X_USER_BSM_MESSAGE *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c5_y = (PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c5_z = (PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 1);
}

/* SFunction Glue Code */
void sf_c5_Jan22_DLforACC_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1327072647U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(726601269U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2467005579U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3278161143U);
}

mxArray* sf_c5_Jan22_DLforACC_cs_get_post_codegen_info(void);
mxArray *sf_c5_Jan22_DLforACC_cs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("PpJGbLtljwlaRPCL4dMceH");
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
    mxArray* mxPostCodegenInfo = sf_c5_Jan22_DLforACC_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c5_Jan22_DLforACC_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c5_Jan22_DLforACC_cs_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("early");
  mxArray *fallbackReason = mxCreateString("imported_bus");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("PRESCAN_V2X_USER_BSM_MESSAGE");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c5_Jan22_DLforACC_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c5_Jan22_DLforACC_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c5_Jan22_DLforACC_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c5_Jan22_DLforACC_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_Jan22_DLforACC_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance =
      (SFc5_Jan22_DLforACC_csInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Jan22_DLforACC_csMachineNumber_,
           5,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,57);
        _SFD_CV_INIT_SCRIPT(0,5,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"V2X_BSM_expander",0,-1,106);
        _SFD_CV_INIT_SCRIPT_FCN(0,1,"FILTER_PRESCAN_V2X_FIXED_BSM_MESSAGE",108,
          -1,287);
        _SFD_CV_INIT_SCRIPT_FCN(0,2,"FILTER_PRESCAN_HEADER",289,-1,356);
        _SFD_CV_INIT_SCRIPT_FCN(0,3,"FILTER_PRESCAN_V2X_FIXED_BSM_DATA",358,-1,
          781);
        _SFD_CV_INIT_SCRIPT_FCN(0,4,"FILTER_PRESCAN_V2X_FIXED_BSM_size",783,-1,
          885);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_u_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_y_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_y_bus_io,(MexInFcnForType)NULL);
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
    SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance =
      (SFc5_Jan22_DLforACC_csInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c5_u);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c5_y);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c5_z);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "s99X3kqVpXMuok8swRcg2o";
}

static void sf_opaque_initialize_c5_Jan22_DLforACC_cs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_Jan22_DLforACC_csInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c5_Jan22_DLforACC_cs((SFc5_Jan22_DLforACC_csInstanceStruct*)
    chartInstanceVar);
  initialize_c5_Jan22_DLforACC_cs((SFc5_Jan22_DLforACC_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c5_Jan22_DLforACC_cs(void *chartInstanceVar)
{
  enable_c5_Jan22_DLforACC_cs((SFc5_Jan22_DLforACC_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c5_Jan22_DLforACC_cs(void *chartInstanceVar)
{
  disable_c5_Jan22_DLforACC_cs((SFc5_Jan22_DLforACC_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c5_Jan22_DLforACC_cs(void *chartInstanceVar)
{
  sf_gateway_c5_Jan22_DLforACC_cs((SFc5_Jan22_DLforACC_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c5_Jan22_DLforACC_cs(SimStruct* S)
{
  return get_sim_state_c5_Jan22_DLforACC_cs
    ((SFc5_Jan22_DLforACC_csInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c5_Jan22_DLforACC_cs(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c5_Jan22_DLforACC_cs((SFc5_Jan22_DLforACC_csInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c5_Jan22_DLforACC_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_Jan22_DLforACC_csInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Jan22_DLforACC_cs_optimization_info();
    }

    finalize_c5_Jan22_DLforACC_cs((SFc5_Jan22_DLforACC_csInstanceStruct*)
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
  initSimStructsc5_Jan22_DLforACC_cs((SFc5_Jan22_DLforACC_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_Jan22_DLforACC_cs(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_Jan22_DLforACC_cs((SFc5_Jan22_DLforACC_csInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c5_Jan22_DLforACC_cs(SimStruct *S)
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
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetSupportedForRowMajorCodeGen(S, 1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,5,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 5);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,5);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,5,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,5,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,5);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1000668383U));
  ssSetChecksum1(S,(3068085634U));
  ssSetChecksum2(S,(3026433769U));
  ssSetChecksum3(S,(2945422396U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c5_Jan22_DLforACC_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_Jan22_DLforACC_cs(SimStruct *S)
{
  SFc5_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc5_Jan22_DLforACC_csInstanceStruct *)utMalloc(sizeof
    (SFc5_Jan22_DLforACC_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc5_Jan22_DLforACC_csInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c5_Jan22_DLforACC_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c5_Jan22_DLforACC_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c5_Jan22_DLforACC_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_Jan22_DLforACC_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c5_Jan22_DLforACC_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_Jan22_DLforACC_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_Jan22_DLforACC_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_Jan22_DLforACC_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_Jan22_DLforACC_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_Jan22_DLforACC_cs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c5_Jan22_DLforACC_cs;
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
  mdl_start_c5_Jan22_DLforACC_cs(chartInstance);
}

void c5_Jan22_DLforACC_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_Jan22_DLforACC_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_Jan22_DLforACC_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_Jan22_DLforACC_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_Jan22_DLforACC_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
