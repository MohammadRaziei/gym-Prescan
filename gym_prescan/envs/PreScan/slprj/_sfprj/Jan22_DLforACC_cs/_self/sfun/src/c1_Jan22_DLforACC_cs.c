/* Include files */

#include "Jan22_DLforACC_cs_sfun.h"
#include "c1_Jan22_DLforACC_cs.h"
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
static const char * c1_debug_family_names[5] = { "nargin", "nargout", "u", "z",
  "y" };

static const char * c1_b_debug_family_names[4] = { "nargin", "nargout", "u", "y"
};

static const char * c1_c_debug_family_names[4] = { "nargin", "nargout", "u", "y"
};

static const char * c1_d_debug_family_names[4] = { "nargin", "nargout", "u", "y"
};

static const char * c1_e_debug_family_names[4] = { "nargin", "nargout", "u", "y"
};

static const char * c1_f_debug_family_names[5] = { "nargin", "nargout", "y", "z",
  "u" };

static const char * c1_sv0[2] = { "HEADER", "DATA" };

static const char * c1_sv1[2] = { "width", "length" };

static const char * c1_sv2[10] = { "utcTime", "longitude", "latitude",
  "elevation", "heading", "speed", "posAccuracy", "timeConfidence",
  "posConfidence", "speedConfidence" };

static const char * c1_sv3[6] = { "year", "month", "day", "hour", "minute",
  "second" };

static const char * c1_sv4[2] = { "HEADER", "DATA" };

static const char * c1_sv5[2] = { "width", "length" };

static const char * c1_sv6[10] = { "utcTime", "longitude", "latitude",
  "elevation", "heading", "speed", "posAccuracy", "timeConfidence",
  "posConfidence", "speedConfidence" };

static const char * c1_sv7[6] = { "year", "month", "day", "hour", "minute",
  "second" };

/* Function Declarations */
static void initialize_c1_Jan22_DLforACC_cs(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance);
static void initialize_params_c1_Jan22_DLforACC_cs
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance);
static void enable_c1_Jan22_DLforACC_cs(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance);
static void disable_c1_Jan22_DLforACC_cs(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance);
static void c1_update_debugger_state_c1_Jan22_DLforACC_cs
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_Jan22_DLforACC_cs
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance);
static void set_sim_state_c1_Jan22_DLforACC_cs
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_st);
static void finalize_c1_Jan22_DLforACC_cs(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance);
static void sf_gateway_c1_Jan22_DLforACC_cs(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance);
static void mdl_start_c1_Jan22_DLforACC_cs(SFc1_Jan22_DLforACC_csInstanceStruct *
  chartInstance);
static void initSimStructsc1_Jan22_DLforACC_cs
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_emlrt_marshallOut(SFc1_Jan22_DLforACC_csInstanceStruct *
  chartInstance, const c1_PRESCAN_V2X_USER_BSM_DATA c1_b_u);
static const mxArray *c1_b_emlrt_marshallOut
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const int32_T c1_b_u);
static const mxArray *c1_c_emlrt_marshallOut
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const int8_T c1_b_u[2]);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_d_emlrt_marshallOut
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const
   PRESCAN_V2X_FIXED_BSM_DATA *c1_b_u);
static const mxArray *c1_e_emlrt_marshallOut
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const
   PRESCAN_V2X_FIXED_BSM_safetyExt *c1_b_u);
static const mxArray *c1_f_emlrt_marshallOut
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const
   PRESCAN_V2X_FIXED_BSM_utcTime c1_b_u);
static const mxArray *c1_g_emlrt_marshallOut
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const
   PRESCAN_V2X_FIXED_BSM_status *c1_b_u);
static const mxArray *c1_h_emlrt_marshallOut
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const
   PRESCAN_V2X_FIXED_BSM_wipers c1_b_u);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_b_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_y, const char_T *c1_identifier,
  PRESCAN_V2X_FIXED_BSM_MESSAGE *c1_c_y);
static void c1_c_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  PRESCAN_V2X_FIXED_BSM_MESSAGE *c1_b_y);
static PRESCAN_HEADER c1_d_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId);
static boolean_T c1_e_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_f_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  PRESCAN_V2X_FIXED_BSM_DATA *c1_b_y);
static int32_T c1_g_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_h_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[4]);
static void c1_i_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[2]);
static int8_T c1_j_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_k_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[7]);
static PRESCAN_V2X_FIXED_BSM_size c1_l_emlrt_marshallIn
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_b_u,
   const emlrtMsgIdentifier *c1_parentId);
static void c1_m_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  PRESCAN_V2X_FIXED_BSM_safetyExt *c1_b_y);
static void c1_n_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  PRESCAN_V2X_FIXED_BSM_pathHistory *c1_b_y);
static PRESCAN_V2X_FIXED_BSM_initialPosition c1_o_emlrt_marshallIn
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_b_u,
   const emlrtMsgIdentifier *c1_parentId);
static PRESCAN_V2X_FIXED_BSM_utcTime c1_p_emlrt_marshallIn
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_b_u,
   const emlrtMsgIdentifier *c1_parentId);
static void c1_q_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  PRESCAN_V2X_FIXED_BSM_crumbData *c1_b_y);
static void c1_r_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 c1_b_y[23]);
static void c1_s_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[345]);
static void c1_t_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[276]);
static void c1_u_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[184]);
static void c1_v_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[230]);
static void c1_w_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[138]);
static void c1_x_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[242]);
static void c1_y_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[161]);
static void c1_ab_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[196]);
static void c1_bb_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[104]);
static PRESCAN_V2X_FIXED_BSM_pathPrediction c1_cb_emlrt_marshallIn
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_b_u,
   const emlrtMsgIdentifier *c1_parentId);
static void c1_db_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  PRESCAN_V2X_FIXED_BSM_theRTCM *c1_b_y);
static PRESCAN_V2X_FIXED_BSM_anchorPoint c1_eb_emlrt_marshallIn
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_b_u,
   const emlrtMsgIdentifier *c1_parentId);
static void c1_fb_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[5]);
static void c1_gb_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[124]);
static void c1_hb_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[156]);
static void c1_ib_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[210]);
static void c1_jb_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[258]);
static void c1_kb_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[19]);
static void c1_lb_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[21]);
static void c1_mb_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[36]);
static void c1_nb_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[68]);
static void c1_ob_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[136]);
static void c1_pb_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[166]);
static void c1_qb_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[222]);
static void c1_rb_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[268]);
static void c1_sb_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[27]);
static void c1_tb_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[15]);
static void c1_ub_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[69]);
static void c1_vb_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[81]);
static void c1_wb_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[115]);
static void c1_xb_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[62]);
static void c1_yb_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[45]);
static void c1_ac_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[75]);
static void c1_bc_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[73]);
static void c1_cc_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[74]);
static void c1_dc_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[25]);
static void c1_ec_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[30]);
static void c1_fc_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[33]);
static void c1_gc_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[105]);
static void c1_hc_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[107]);
static void c1_ic_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[20]);
static void c1_jc_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  PRESCAN_V2X_FIXED_BSM_status *c1_b_y);
static PRESCAN_V2X_FIXED_BSM_wipers c1_kc_emlrt_marshallIn
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_b_u,
   const emlrtMsgIdentifier *c1_parentId);
static PRESCAN_V2X_FIXED_BSM_steering c1_lc_emlrt_marshallIn
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_b_u,
   const emlrtMsgIdentifier *c1_parentId);
static PRESCAN_V2X_FIXED_BSM_accelSets c1_mc_emlrt_marshallIn
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_b_u,
   const emlrtMsgIdentifier *c1_parentId);
static PRESCAN_V2X_FIXED_BSM_confidenceSet c1_nc_emlrt_marshallIn
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_b_u,
   const emlrtMsgIdentifier *c1_parentId);
static PRESCAN_V2X_FIXED_BSM_accelConfidence c1_oc_emlrt_marshallIn
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_b_u,
   const emlrtMsgIdentifier *c1_parentId);
static PRESCAN_V2X_FIXED_BSM_object c1_pc_emlrt_marshallIn
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_b_u,
   const emlrtMsgIdentifier *c1_parentId);
static PRESCAN_V2X_FIXED_BSM_dateTime c1_qc_emlrt_marshallIn
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_b_u,
   const emlrtMsgIdentifier *c1_parentId);
static PRESCAN_V2X_FIXED_BSM_fullPos c1_rc_emlrt_marshallIn
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_b_u,
   const emlrtMsgIdentifier *c1_parentId);
static PRESCAN_V2X_FIXED_BSM_vehicleData c1_sc_emlrt_marshallIn
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_b_u,
   const emlrtMsgIdentifier *c1_parentId);
static PRESCAN_V2X_FIXED_BSM_bumpers c1_tc_emlrt_marshallIn
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_b_u,
   const emlrtMsgIdentifier *c1_parentId);
static void c1_uc_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  PRESCAN_V2X_FIXED_BSM_vehicleIdent *c1_b_y);
static void c1_vc_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[63]);
static void c1_wc_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[17]);
static void c1_xc_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[32]);
static PRESCAN_V2X_FIXED_BSM_vehicleClass c1_yc_emlrt_marshallIn
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_b_u,
   const emlrtMsgIdentifier *c1_parentId);
static void c1_ad_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  PRESCAN_V2X_FIXED_BSM_j1939data *c1_b_y);
static void c1_bd_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  PRESCAN_V2X_FIXED_BSM_tires c1_b_y[16]);
static void c1_cd_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  PRESCAN_V2X_FIXED_BSM_axle c1_b_y[16]);
static PRESCAN_V2X_FIXED_BSM_weatherReport c1_dd_emlrt_marshallIn
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_b_u,
   const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static c1_PRESCAN_V2X_USER_BSM_size c1_ed_emlrt_marshallIn
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_b_u,
   const emlrtMsgIdentifier *c1_parentId);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static c1_PRESCAN_V2X_USER_BSM_DATA c1_fd_emlrt_marshallIn
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_b_u,
   const emlrtMsgIdentifier *c1_parentId);
static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static c1_PRESCAN_V2X_USER_BSM_MESSAGE c1_gd_emlrt_marshallIn
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_b_u,
   const emlrtMsgIdentifier *c1_parentId);
static void c1_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_u_bus_io(void *chartInstanceVoid, void *c1_pData);
static const mxArray *c1_y_bus_io(void *chartInstanceVoid, void *c1_pData);
static uint8_T c1_hd_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_Jan22_DLforACC_cs, const
  char_T *c1_identifier);
static uint8_T c1_id_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_Jan22_DLforACC_cs(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc1_Jan22_DLforACC_cs(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  sim_mode_is_external(chartInstance->S);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_is_active_c1_Jan22_DLforACC_cs = 0U;
  setLegacyDebuggerFlagForRuntime(chartInstance->S, true);
}

static void initialize_params_c1_Jan22_DLforACC_cs
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c1_Jan22_DLforACC_cs(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_Jan22_DLforACC_cs(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c1_update_debugger_state_c1_Jan22_DLforACC_cs
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c1_Jan22_DLforACC_cs
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  PRESCAN_HEADER c1_b_u;
  const mxArray *c1_d_y = NULL;
  static const char * c1_sv8[1] = { "valid" };

  boolean_T c1_c_u;
  const mxArray *c1_e_y = NULL;
  PRESCAN_V2X_FIXED_BSM_DATA c1_r0;
  int32_T c1_i0;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_i29;
  int32_T c1_i30;
  int32_T c1_i31;
  int32_T c1_i32;
  int32_T c1_i33;
  int32_T c1_i34;
  int32_T c1_i35;
  int32_T c1_i36;
  int32_T c1_i37;
  int32_T c1_i38;
  int32_T c1_i39;
  int32_T c1_i40;
  int32_T c1_i41;
  int32_T c1_i42;
  int32_T c1_i43;
  int32_T c1_i44;
  int32_T c1_i45;
  int32_T c1_i46;
  int32_T c1_i47;
  int32_T c1_i48;
  int32_T c1_i49;
  int32_T c1_i50;
  int32_T c1_i51;
  int32_T c1_i52;
  int32_T c1_i53;
  int32_T c1_i54;
  int32_T c1_i55;
  int32_T c1_i56;
  int32_T c1_i57;
  int32_T c1_i58;
  int32_T c1_i59;
  int32_T c1_i60;
  int32_T c1_i61;
  int32_T c1_i62;
  int32_T c1_i63;
  int32_T c1_i64;
  int32_T c1_i65;
  uint8_T c1_hoistedGlobal;
  const mxArray *c1_f_y = NULL;
  c1_st = NULL;
  c1_st = NULL;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_createcellmatrix(2, 1), false);
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_createstruct("structure", 2, c1_sv0, 2, 1, 1),
                false);
  c1_b_u.valid = *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)
    chartInstance->c1_y)[0])[0];
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_createstruct("structure", 1, c1_sv8, 2, 1, 1),
                false);
  c1_c_u = c1_b_u.valid;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_c_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_d_y, 0, "valid", c1_e_y, 0);
  sf_mex_setfieldbynum(c1_c_y, 0, "HEADER", c1_d_y, 0);
  c1_r0.msgID = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[0];
  c1_r0.msgCnt = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T
    *)chartInstance->c1_y)[8])[4];
  for (c1_i0 = 0; c1_i0 < 4; c1_i0++) {
    c1_r0.id[c1_i0] = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_y)[8])[8])[c1_i0];
  }

  c1_r0.secMark = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[12];
  c1_r0.latitude = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[16];
  c1_r0.longitude = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[20];
  for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
    c1_r0.elev[c1_i1] = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_y)[8])[24])[c1_i1];
  }

  for (c1_i2 = 0; c1_i2 < 4; c1_i2++) {
    c1_r0.accuracy[c1_i2] = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_y)[8])[26])[c1_i2];
  }

  for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
    c1_r0.speed[c1_i3] = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_y)[8])[30])[c1_i3];
  }

  c1_r0.heading = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[32];
  c1_r0.angle = *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[36];
  for (c1_i4 = 0; c1_i4 < 7; c1_i4++) {
    c1_r0.accelSet[c1_i4] = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_y)[8])[37])[c1_i4];
  }

  for (c1_i5 = 0; c1_i5 < 2; c1_i5++) {
    c1_r0.brakes[c1_i5] = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_y)[8])[44])[c1_i5];
  }

  c1_r0.size.width = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_size *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [48])[0];
  c1_r0.size.length = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_size *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [48])[4];
  c1_r0.safetyExt.events = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[0];
  c1_r0.safetyExt.pathHistory.initialPosition.utcTime.year = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
        [8])[0])[0])[0];
  c1_r0.safetyExt.pathHistory.initialPosition.utcTime.month = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
        [8])[0])[0])[4];
  c1_r0.safetyExt.pathHistory.initialPosition.utcTime.day = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
        [8])[0])[0])[8];
  c1_r0.safetyExt.pathHistory.initialPosition.utcTime.hour = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
        [8])[0])[0])[12];
  c1_r0.safetyExt.pathHistory.initialPosition.utcTime.minute = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
        [8])[0])[0])[16];
  c1_r0.safetyExt.pathHistory.initialPosition.utcTime.second = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
        [8])[0])[0])[20];
  c1_r0.safetyExt.pathHistory.initialPosition.longitude = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[8])[0])[24];
  c1_r0.safetyExt.pathHistory.initialPosition.latitude = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[8])[0])[28];
  for (c1_i6 = 0; c1_i6 < 2; c1_i6++) {
    c1_r0.safetyExt.pathHistory.initialPosition.elevation[c1_i6] = ((int8_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[8])[0])[32])[c1_i6];
  }

  c1_r0.safetyExt.pathHistory.initialPosition.heading = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[8])[0])[36];
  for (c1_i7 = 0; c1_i7 < 2; c1_i7++) {
    c1_r0.safetyExt.pathHistory.initialPosition.speed[c1_i7] = ((int8_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[8])[0])[40])[c1_i7];
  }

  for (c1_i8 = 0; c1_i8 < 4; c1_i8++) {
    c1_r0.safetyExt.pathHistory.initialPosition.posAccuracy[c1_i8] = ((int8_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[8])[0])[42])[c1_i8];
  }

  c1_r0.safetyExt.pathHistory.initialPosition.timeConfidence = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
       [8])[0])[48];
  c1_r0.safetyExt.pathHistory.initialPosition.posConfidence = *(int8_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
       [8])[0])[52];
  c1_r0.safetyExt.pathHistory.initialPosition.speedConfidence = *(int8_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
       [8])[0])[53];
  c1_r0.safetyExt.pathHistory.currGPSstatus = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[8])[56];
  c1_r0.safetyExt.pathHistory.itemCnt = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[8])[60];
  for (c1_i9 = 0; c1_i9 < 23; c1_i9++) {
    c1_r0.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c1_i9].
      latOffset = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[8])[64])[0])[32 * (int32_T)
      c1_i9])[0];
    c1_r0.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c1_i9].
      longOffset = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[8])[64])[0])[32 * (int32_T)
      c1_i9])[4];
    c1_r0.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c1_i9].
      elevationOffset = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[8])[64])[0])[32 * (int32_T)
      c1_i9])[8];
    c1_r0.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c1_i9].
      timeOffset = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[8])[64])[0])[32 * (int32_T)
      c1_i9])[12];
    for (c1_i12 = 0; c1_i12 < 4; c1_i12++) {
      c1_r0.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c1_i9].
        posAccuracy[c1_i12] = ((int8_T *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
        [8])[64])[0])[32 * (int32_T)c1_i9])[16])[c1_i12];
    }

    c1_r0.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c1_i9].heading
      = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                      &((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[8])[64])[0])[32 * (int32_T)
                      c1_i9])[20];
    for (c1_i14 = 0; c1_i14 < 2; c1_i14++) {
      c1_r0.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c1_i9]
        .speed[c1_i14] = ((int8_T *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
        [8])[64])[0])[32 * (int32_T)c1_i9])[24])[c1_i14];
    }
  }

  for (c1_i10 = 0; c1_i10 < 345; c1_i10++) {
    c1_r0.safetyExt.pathHistory.crumbData.pathHistoryPointSets_02[c1_i10] =
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
         [8])[64])[736])[c1_i10];
  }

  for (c1_i11 = 0; c1_i11 < 276; c1_i11++) {
    c1_r0.safetyExt.pathHistory.crumbData.pathHistoryPointSets_03[c1_i11] =
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
         [8])[64])[1081])[c1_i11];
  }

  for (c1_i13 = 0; c1_i13 < 184; c1_i13++) {
    c1_r0.safetyExt.pathHistory.crumbData.pathHistoryPointSets_04[c1_i13] =
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
         [8])[64])[1357])[c1_i13];
  }

  for (c1_i15 = 0; c1_i15 < 230; c1_i15++) {
    c1_r0.safetyExt.pathHistory.crumbData.pathHistoryPointSets_05[c1_i15] =
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
         [8])[64])[1541])[c1_i15];
  }

  for (c1_i16 = 0; c1_i16 < 138; c1_i16++) {
    c1_r0.safetyExt.pathHistory.crumbData.pathHistoryPointSets_06[c1_i16] =
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
         [8])[64])[1771])[c1_i16];
  }

  for (c1_i17 = 0; c1_i17 < 242; c1_i17++) {
    c1_r0.safetyExt.pathHistory.crumbData.pathHistoryPointSets_07[c1_i17] =
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
         [8])[64])[1909])[c1_i17];
  }

  for (c1_i18 = 0; c1_i18 < 161; c1_i18++) {
    c1_r0.safetyExt.pathHistory.crumbData.pathHistoryPointSets_08[c1_i18] =
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
         [8])[64])[2151])[c1_i18];
  }

  for (c1_i19 = 0; c1_i19 < 196; c1_i19++) {
    c1_r0.safetyExt.pathHistory.crumbData.pathHistoryPointSets_09[c1_i19] =
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
         [8])[64])[2312])[c1_i19];
  }

  for (c1_i20 = 0; c1_i20 < 104; c1_i20++) {
    c1_r0.safetyExt.pathHistory.crumbData.pathHistoryPointSets_10[c1_i20] =
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
         [8])[64])[2508])[c1_i20];
  }

  c1_r0.safetyExt.pathPrediction.radiusOfCurve = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathPrediction *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2688])[0];
  c1_r0.safetyExt.pathPrediction.confidence = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathPrediction *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2688])[4];
  c1_r0.safetyExt.theRTCM.anchorPoint.utcTime.year = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2696])[0])[0])[0];
  c1_r0.safetyExt.theRTCM.anchorPoint.utcTime.month = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2696])[0])[0])[4];
  c1_r0.safetyExt.theRTCM.anchorPoint.utcTime.day = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2696])[0])[0])[8];
  c1_r0.safetyExt.theRTCM.anchorPoint.utcTime.hour = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2696])[0])[0])[12];
  c1_r0.safetyExt.theRTCM.anchorPoint.utcTime.minute = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2696])[0])[0])[16];
  c1_r0.safetyExt.theRTCM.anchorPoint.utcTime.second = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2696])[0])[0])[20];
  c1_r0.safetyExt.theRTCM.anchorPoint.longitude = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2696])[0])[24];
  c1_r0.safetyExt.theRTCM.anchorPoint.latitude = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2696])[0])[28];
  for (c1_i21 = 0; c1_i21 < 2; c1_i21++) {
    c1_r0.safetyExt.theRTCM.anchorPoint.elevation[c1_i21] = ((int8_T *)&((char_T
      *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[2696])[0])[32])[c1_i21];
  }

  c1_r0.safetyExt.theRTCM.anchorPoint.heading = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2696])[0])[36];
  for (c1_i22 = 0; c1_i22 < 2; c1_i22++) {
    c1_r0.safetyExt.theRTCM.anchorPoint.speed[c1_i22] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[2696])[0])[40])[c1_i22];
  }

  for (c1_i23 = 0; c1_i23 < 4; c1_i23++) {
    c1_r0.safetyExt.theRTCM.anchorPoint.posAccuracy[c1_i23] = ((int8_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[2696])[0])[42])[c1_i23];
  }

  c1_r0.safetyExt.theRTCM.anchorPoint.timeConfidence = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2696])[0])[48];
  c1_r0.safetyExt.theRTCM.anchorPoint.posConfidence = *(int8_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2696])[0])[52];
  c1_r0.safetyExt.theRTCM.anchorPoint.speedConfidence = *(int8_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2696])[0])[53];
  for (c1_i24 = 0; c1_i24 < 5; c1_i24++) {
    c1_r0.safetyExt.theRTCM.rtcmHeader[c1_i24] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[2696])[56])[c1_i24];
  }

  for (c1_i25 = 0; c1_i25 < 124; c1_i25++) {
    c1_r0.safetyExt.theRTCM.msg1001[c1_i25] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[2696])[61])[c1_i25];
  }

  for (c1_i26 = 0; c1_i26 < 156; c1_i26++) {
    c1_r0.safetyExt.theRTCM.msg1002[c1_i26] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[2696])[185])[c1_i26];
  }

  for (c1_i27 = 0; c1_i27 < 210; c1_i27++) {
    c1_r0.safetyExt.theRTCM.msg1003[c1_i27] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[2696])[341])[c1_i27];
  }

  for (c1_i28 = 0; c1_i28 < 258; c1_i28++) {
    c1_r0.safetyExt.theRTCM.msg1004[c1_i28] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[2696])[551])[c1_i28];
  }

  for (c1_i29 = 0; c1_i29 < 19; c1_i29++) {
    c1_r0.safetyExt.theRTCM.msg1005[c1_i29] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[2696])[809])[c1_i29];
  }

  for (c1_i30 = 0; c1_i30 < 21; c1_i30++) {
    c1_r0.safetyExt.theRTCM.msg1006[c1_i30] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[2696])[828])[c1_i30];
  }

  for (c1_i31 = 0; c1_i31 < 36; c1_i31++) {
    c1_r0.safetyExt.theRTCM.msg1007[c1_i31] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[2696])[849])[c1_i31];
  }

  for (c1_i32 = 0; c1_i32 < 68; c1_i32++) {
    c1_r0.safetyExt.theRTCM.msg1008[c1_i32] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[2696])[885])[c1_i32];
  }

  for (c1_i33 = 0; c1_i33 < 136; c1_i33++) {
    c1_r0.safetyExt.theRTCM.msg1009[c1_i33] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[2696])[953])[c1_i33];
  }

  for (c1_i34 = 0; c1_i34 < 166; c1_i34++) {
    c1_r0.safetyExt.theRTCM.msg1010[c1_i34] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[2696])[1089])[c1_i34];
  }

  for (c1_i35 = 0; c1_i35 < 222; c1_i35++) {
    c1_r0.safetyExt.theRTCM.msg1011[c1_i35] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[2696])[1255])[c1_i35];
  }

  for (c1_i36 = 0; c1_i36 < 268; c1_i36++) {
    c1_r0.safetyExt.theRTCM.msg1012[c1_i36] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[2696])[1477])[c1_i36];
  }

  for (c1_i37 = 0; c1_i37 < 27; c1_i37++) {
    c1_r0.safetyExt.theRTCM.msg1013[c1_i37] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[2696])[1745])[c1_i37];
  }

  for (c1_i38 = 0; c1_i38 < 15; c1_i38++) {
    c1_r0.safetyExt.theRTCM.msg1014[c1_i38] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[2696])[1772])[c1_i38];
  }

  for (c1_i39 = 0; c1_i39 < 69; c1_i39++) {
    c1_r0.safetyExt.theRTCM.msg1015[c1_i39] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[2696])[1787])[c1_i39];
  }

  for (c1_i40 = 0; c1_i40 < 81; c1_i40++) {
    c1_r0.safetyExt.theRTCM.msg1016[c1_i40] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[2696])[1856])[c1_i40];
  }

  for (c1_i41 = 0; c1_i41 < 115; c1_i41++) {
    c1_r0.safetyExt.theRTCM.msg1017[c1_i41] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[2696])[1937])[c1_i41];
  }

  for (c1_i42 = 0; c1_i42 < 62; c1_i42++) {
    c1_r0.safetyExt.theRTCM.msg1019[c1_i42] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[2696])[2052])[c1_i42];
  }

  for (c1_i43 = 0; c1_i43 < 45; c1_i43++) {
    c1_r0.safetyExt.theRTCM.msg1020[c1_i43] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[2696])[2114])[c1_i43];
  }

  for (c1_i44 = 0; c1_i44 < 62; c1_i44++) {
    c1_r0.safetyExt.theRTCM.msg1021[c1_i44] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[2696])[2159])[c1_i44];
  }

  for (c1_i45 = 0; c1_i45 < 75; c1_i45++) {
    c1_r0.safetyExt.theRTCM.msg1022[c1_i45] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[2696])[2221])[c1_i45];
  }

  for (c1_i46 = 0; c1_i46 < 73; c1_i46++) {
    c1_r0.safetyExt.theRTCM.msg1023[c1_i46] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[2696])[2296])[c1_i46];
  }

  for (c1_i47 = 0; c1_i47 < 74; c1_i47++) {
    c1_r0.safetyExt.theRTCM.msg1024[c1_i47] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[2696])[2369])[c1_i47];
  }

  for (c1_i48 = 0; c1_i48 < 25; c1_i48++) {
    c1_r0.safetyExt.theRTCM.msg1025[c1_i48] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[2696])[2443])[c1_i48];
  }

  for (c1_i49 = 0; c1_i49 < 30; c1_i49++) {
    c1_r0.safetyExt.theRTCM.msg1026[c1_i49] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[2696])[2468])[c1_i49];
  }

  for (c1_i50 = 0; c1_i50 < 33; c1_i50++) {
    c1_r0.safetyExt.theRTCM.msg1027[c1_i50] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[2696])[2498])[c1_i50];
  }

  for (c1_i51 = 0; c1_i51 < 69; c1_i51++) {
    c1_r0.safetyExt.theRTCM.msg1029[c1_i51] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[2696])[2531])[c1_i51];
  }

  for (c1_i52 = 0; c1_i52 < 105; c1_i52++) {
    c1_r0.safetyExt.theRTCM.msg1030[c1_i52] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[2696])[2600])[c1_i52];
  }

  for (c1_i53 = 0; c1_i53 < 107; c1_i53++) {
    c1_r0.safetyExt.theRTCM.msg1031[c1_i53] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[2696])[2705])[c1_i53];
  }

  for (c1_i54 = 0; c1_i54 < 20; c1_i54++) {
    c1_r0.safetyExt.theRTCM.msg1032[c1_i54] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[2696])[2812])[c1_i54];
  }

  c1_r0.status.lights = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[0];
  c1_r0.status.lightBar = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[4];
  c1_r0.status.wipers.statusFront = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[8])[0];
  c1_r0.status.wipers.rateFront = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[8])[4];
  c1_r0.status.wipers.statusRear = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[8])[8];
  c1_r0.status.wipers.rateRear = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[8])[12];
  for (c1_i55 = 0; c1_i55 < 2; c1_i55++) {
    c1_r0.status.brakeStatus[c1_i55] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_y)[8])[5584])[24])[c1_i55];
  }

  c1_r0.status.brakePressure = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[28];
  c1_r0.status.roadFriction = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[32];
  c1_r0.status.sunData = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[36];
  c1_r0.status.rainData = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[40];
  c1_r0.status.airTemp = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[44];
  c1_r0.status.airPres = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[48];
  c1_r0.status.steering.angle = *(int8_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[56])[0];
  c1_r0.status.steering.confidence = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[56])[4];
  c1_r0.status.steering.rate = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[56])[8];
  c1_r0.status.steering.wheels = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[56])[12];
  for (c1_i56 = 0; c1_i56 < 7; c1_i56++) {
    c1_r0.status.accelSets.accel4way[c1_i56] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_y)[8])[5584])[72])[0])[c1_i56];
  }

  c1_r0.status.accelSets.vertAccelThres = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)
        [8])[5584])[72])[8];
  c1_r0.status.accelSets.yawRateCon = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)
        [8])[5584])[72])[12];
  c1_r0.status.accelSets.hozAccelCon = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)
        [8])[5584])[72])[16];
  c1_r0.status.accelSets.confidenceSet.accelConfidence.yawRate = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_accelConfidence *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
           *)&((char_T *)chartInstance->c1_y)[8])[5584])[72])[24])[0])[0];
  c1_r0.status.accelSets.confidenceSet.accelConfidence.acceleration = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_accelConfidence *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
           *)&((char_T *)chartInstance->c1_y)[8])[5584])[72])[24])[0])[4];
  c1_r0.status.accelSets.confidenceSet.accelConfidence.steeringWheelAngle =
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelConfidence *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)
        [8])[5584])[72])[24])[0])[8];
  c1_r0.status.accelSets.confidenceSet.speedConfidence = *(int8_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)
        [8])[5584])[72])[24])[16];
  c1_r0.status.accelSets.confidenceSet.timeConfidence = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)
        [8])[5584])[72])[24])[20];
  c1_r0.status.accelSets.confidenceSet.posConfidence = *(int8_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)
        [8])[5584])[72])[24])[24];
  c1_r0.status.accelSets.confidenceSet.steerConfidence = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)
        [8])[5584])[72])[24])[28];
  c1_r0.status.accelSets.confidenceSet.throttleConfidence = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
         &((char_T *)chartInstance->c1_y)[8])[5584])[72])[24])[32];
  c1_r0.status.object.obDist = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[136])[0];
  c1_r0.status.object.obDirect = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[136])[4];
  c1_r0.status.object.dateTime.year = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])
    [136])[8])[0];
  c1_r0.status.object.dateTime.month = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])
    [136])[8])[4];
  c1_r0.status.object.dateTime.day = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])
    [136])[8])[8];
  c1_r0.status.object.dateTime.hour = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])
    [136])[8])[12];
  c1_r0.status.object.dateTime.minute = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])
    [136])[8])[16];
  c1_r0.status.object.dateTime.second = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])
    [136])[8])[20];
  c1_r0.status.fullPos.utcTime.year = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])
    [168])[0])[0];
  c1_r0.status.fullPos.utcTime.month = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])
    [168])[0])[4];
  c1_r0.status.fullPos.utcTime.day = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])
    [168])[0])[8];
  c1_r0.status.fullPos.utcTime.hour = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])
    [168])[0])[12];
  c1_r0.status.fullPos.utcTime.minute = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])
    [168])[0])[16];
  c1_r0.status.fullPos.utcTime.second = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])
    [168])[0])[20];
  c1_r0.status.fullPos.longitude = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[168])[24];
  c1_r0.status.fullPos.latitude = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[168])[28];
  for (c1_i57 = 0; c1_i57 < 2; c1_i57++) {
    c1_r0.status.fullPos.elevation[c1_i57] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
      chartInstance->c1_y)[8])[5584])[168])[32])[c1_i57];
  }

  c1_r0.status.fullPos.heading = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[168])[36];
  for (c1_i58 = 0; c1_i58 < 2; c1_i58++) {
    c1_r0.status.fullPos.speed[c1_i58] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
      chartInstance->c1_y)[8])[5584])[168])[40])[c1_i58];
  }

  for (c1_i59 = 0; c1_i59 < 4; c1_i59++) {
    c1_r0.status.fullPos.posAccuracy[c1_i59] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
      chartInstance->c1_y)[8])[5584])[168])[42])[c1_i59];
  }

  c1_r0.status.fullPos.timeConfidence = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[168])[48];
  c1_r0.status.fullPos.posConfidence = *(int8_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[168])[52];
  c1_r0.status.fullPos.speedConfidence = *(int8_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[168])[53];
  c1_r0.status.throttlePos = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[224];
  c1_r0.status.speedHeadC = *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)
        [8])[5584])[228];
  c1_r0.status.speedC = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[232];
  c1_r0.status.vehicleData.height = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[240])[0];
  c1_r0.status.vehicleData.bumpers.frnt = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_bumpers *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[240])[8])[0];
  c1_r0.status.vehicleData.bumpers.rear = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_bumpers *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[240])[8])[4];
  c1_r0.status.vehicleData.mass = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[240])[16];
  c1_r0.status.vehicleData.trailerWeight = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[240])[20];
  c1_r0.status.vehicleData.type = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[240])[24];
  for (c1_i60 = 0; c1_i60 < 63; c1_i60++) {
    c1_r0.status.vehicleIdent.name[c1_i60] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_y)[8])[5584])[272])[0])[c1_i60];
  }

  for (c1_i61 = 0; c1_i61 < 17; c1_i61++) {
    c1_r0.status.vehicleIdent.vin[c1_i61] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_y)[8])[5584])[272])[63])[c1_i61];
  }

  for (c1_i62 = 0; c1_i62 < 32; c1_i62++) {
    c1_r0.status.vehicleIdent.ownerCode[c1_i62] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_y)[8])[5584])[272])[80])[c1_i62];
  }

  for (c1_i63 = 0; c1_i63 < 4; c1_i63++) {
    c1_r0.status.vehicleIdent.id[c1_i63] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_y)[8])[5584])[272])[112])[c1_i63];
  }

  c1_r0.status.vehicleIdent.vehicleType = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[272])[116];
  c1_r0.status.vehicleIdent.vehicleClass.vGroup = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleClass *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[272])[120])[0];
  c1_r0.status.vehicleIdent.vehicleClass.rGroup = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleClass *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[272])[120])[4];
  c1_r0.status.vehicleIdent.vehicleClass.rEquip = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleClass *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[272])[120])[8];
  for (c1_i64 = 0; c1_i64 < 16; c1_i64++) {
    c1_r0.status.j1939data.tires[c1_i64].location = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_y)[8])[5584])[408])[0])[32 * (int32_T)c1_i64])
      [0];
    c1_r0.status.j1939data.tires[c1_i64].pressure = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_y)[8])[5584])[408])[0])[32 * (int32_T)c1_i64])
      [4];
    c1_r0.status.j1939data.tires[c1_i64].temp = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_y)[8])[5584])[408])[0])[32 * (int32_T)c1_i64])
      [8];
    c1_r0.status.j1939data.tires[c1_i64].wheelSensorStatus = *(int32_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
           [5584])[408])[0])[32 * (int32_T)c1_i64])[12];
    c1_r0.status.j1939data.tires[c1_i64].wheelEndElectFault = *(int32_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
           [5584])[408])[0])[32 * (int32_T)c1_i64])[16];
    c1_r0.status.j1939data.tires[c1_i64].leakageRate = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_y)[8])[5584])[408])[0])[32 * (int32_T)c1_i64])
      [20];
    c1_r0.status.j1939data.tires[c1_i64].detection = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_y)[8])[5584])[408])[0])[32 * (int32_T)c1_i64])
      [24];
  }

  for (c1_i65 = 0; c1_i65 < 16; c1_i65++) {
    c1_r0.status.j1939data.axle[c1_i65].location = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_axle *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_axle *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_y)[8])[5584])[408])[512])[8 * (int32_T)
      c1_i65])[0];
    c1_r0.status.j1939data.axle[c1_i65].weight = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_axle *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_axle *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_y)[8])[5584])[408])[512])[8 * (int32_T)
      c1_i65])[4];
  }

  c1_r0.status.j1939data.trailerWeight = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)
        [8])[5584])[408])[640];
  c1_r0.status.j1939data.cargoWeight = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)
        [8])[5584])[408])[644];
  c1_r0.status.j1939data.steeringAxleTemperature = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)
        [8])[5584])[408])[648];
  c1_r0.status.j1939data.driveAxleLocation = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)
        [8])[5584])[408])[652];
  c1_r0.status.j1939data.driveAxleLiftAirPressure = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)
        [8])[5584])[408])[656];
  c1_r0.status.j1939data.driveAxleTemperature = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)
        [8])[5584])[408])[660];
  c1_r0.status.j1939data.driveAxleLubePressure = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)
        [8])[5584])[408])[664];
  c1_r0.status.j1939data.steeringAxleLubePressure = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)
        [8])[5584])[408])[668];
  c1_r0.status.weatherReport.isRaining = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[1080])[0];
  c1_r0.status.weatherReport.rainRate = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[1080])[4];
  c1_r0.status.weatherReport.precipSituation = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[1080])[8];
  c1_r0.status.weatherReport.solarRadiation = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[1080])[12];
  c1_r0.status.weatherReport.friction = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[1080])[16];
  c1_r0.status.gpsStatus = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)
        [8])[5584])[1104];
  sf_mex_setfieldbynum(c1_c_y, 0, "DATA", c1_d_emlrt_marshallOut(chartInstance,
    &c1_r0), 1);
  sf_mex_setcell(c1_b_y, 0, c1_c_y);
  c1_hoistedGlobal = chartInstance->c1_is_active_c1_Jan22_DLforACC_cs;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_hoistedGlobal, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c1_b_y, 1, c1_f_y);
  sf_mex_assign(&c1_st, c1_b_y, false);
  return c1_st;
}

static void set_sim_state_c1_Jan22_DLforACC_cs
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_b_u;
  PRESCAN_V2X_FIXED_BSM_MESSAGE c1_r1;
  int32_T c1_i66;
  int32_T c1_i67;
  int32_T c1_i68;
  int32_T c1_i69;
  int32_T c1_i70;
  int32_T c1_i71;
  int32_T c1_i72;
  int32_T c1_i73;
  int32_T c1_i74;
  int32_T c1_i75;
  int32_T c1_i76;
  int32_T c1_i77;
  int32_T c1_i78;
  int32_T c1_i79;
  int32_T c1_i80;
  int32_T c1_i81;
  int32_T c1_i82;
  int32_T c1_i83;
  int32_T c1_i84;
  int32_T c1_i85;
  int32_T c1_i86;
  int32_T c1_i87;
  int32_T c1_i88;
  int32_T c1_i89;
  int32_T c1_i90;
  int32_T c1_i91;
  int32_T c1_i92;
  int32_T c1_i93;
  int32_T c1_i94;
  int32_T c1_i95;
  int32_T c1_i96;
  int32_T c1_i97;
  int32_T c1_i98;
  int32_T c1_i99;
  int32_T c1_i100;
  int32_T c1_i101;
  int32_T c1_i102;
  int32_T c1_i103;
  int32_T c1_i104;
  int32_T c1_i105;
  int32_T c1_i106;
  int32_T c1_i107;
  int32_T c1_i108;
  int32_T c1_i109;
  int32_T c1_i110;
  int32_T c1_i111;
  int32_T c1_i112;
  int32_T c1_i113;
  int32_T c1_i114;
  int32_T c1_i115;
  int32_T c1_i116;
  int32_T c1_i117;
  int32_T c1_i118;
  int32_T c1_i119;
  int32_T c1_i120;
  int32_T c1_i121;
  int32_T c1_i122;
  int32_T c1_i123;
  int32_T c1_i124;
  int32_T c1_i125;
  int32_T c1_i126;
  int32_T c1_i127;
  int32_T c1_i128;
  int32_T c1_i129;
  int32_T c1_i130;
  int32_T c1_i131;
  chartInstance->c1_doneDoubleBufferReInit = true;
  c1_b_u = sf_mex_dup(c1_st);
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_b_u, 0)),
                        "y", &c1_r1);
  *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)chartInstance->c1_y)[0])
    [0] = c1_r1.HEADER.valid;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[0] = c1_r1.DATA.msgID;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[4] = c1_r1.DATA.msgCnt;
  for (c1_i66 = 0; c1_i66 < 4; c1_i66++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
       chartInstance->c1_y)[8])[8])[c1_i66] = c1_r1.DATA.id[c1_i66];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[12] = c1_r1.DATA.secMark;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[16] = c1_r1.DATA.latitude;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[20] = c1_r1.DATA.longitude;
  for (c1_i67 = 0; c1_i67 < 2; c1_i67++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
       chartInstance->c1_y)[8])[24])[c1_i67] = c1_r1.DATA.elev[c1_i67];
  }

  for (c1_i68 = 0; c1_i68 < 4; c1_i68++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
       chartInstance->c1_y)[8])[26])[c1_i68] = c1_r1.DATA.accuracy[c1_i68];
  }

  for (c1_i69 = 0; c1_i69 < 2; c1_i69++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
       chartInstance->c1_y)[8])[30])[c1_i69] = c1_r1.DATA.speed[c1_i69];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[32] = c1_r1.DATA.heading;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[36] = c1_r1.DATA.angle;
  for (c1_i70 = 0; c1_i70 < 7; c1_i70++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
       chartInstance->c1_y)[8])[37])[c1_i70] = c1_r1.DATA.accelSet[c1_i70];
  }

  for (c1_i71 = 0; c1_i71 < 2; c1_i71++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
       chartInstance->c1_y)[8])[44])[c1_i71] = c1_r1.DATA.brakes[c1_i71];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_size *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[48])[0] =
    c1_r1.DATA.size.width;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_size *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[48])[4] =
    c1_r1.DATA.size.length;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])[0] =
    c1_r1.DATA.safetyExt.events;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[8])[0])[0])[0] =
    c1_r1.DATA.safetyExt.pathHistory.initialPosition.utcTime.year;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[8])[0])[0])[4] =
    c1_r1.DATA.safetyExt.pathHistory.initialPosition.utcTime.month;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[8])[0])[0])[8] =
    c1_r1.DATA.safetyExt.pathHistory.initialPosition.utcTime.day;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[8])[0])[0])[12] =
    c1_r1.DATA.safetyExt.pathHistory.initialPosition.utcTime.hour;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[8])[0])[0])[16] =
    c1_r1.DATA.safetyExt.pathHistory.initialPosition.utcTime.minute;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[8])[0])[0])[20] =
    c1_r1.DATA.safetyExt.pathHistory.initialPosition.utcTime.second;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[8])[0])[24] =
    c1_r1.DATA.safetyExt.pathHistory.initialPosition.longitude;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[8])[0])[28] =
    c1_r1.DATA.safetyExt.pathHistory.initialPosition.latitude;
  for (c1_i72 = 0; c1_i72 < 2; c1_i72++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
       [8])[0])[32])[c1_i72] =
      c1_r1.DATA.safetyExt.pathHistory.initialPosition.elevation[c1_i72];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[8])[0])[36] =
    c1_r1.DATA.safetyExt.pathHistory.initialPosition.heading;
  for (c1_i73 = 0; c1_i73 < 2; c1_i73++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
       [8])[0])[40])[c1_i73] =
      c1_r1.DATA.safetyExt.pathHistory.initialPosition.speed[c1_i73];
  }

  for (c1_i74 = 0; c1_i74 < 4; c1_i74++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
       [8])[0])[42])[c1_i74] =
      c1_r1.DATA.safetyExt.pathHistory.initialPosition.posAccuracy[c1_i74];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[8])[0])[48] =
    c1_r1.DATA.safetyExt.pathHistory.initialPosition.timeConfidence;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[8])[0])[52] =
    c1_r1.DATA.safetyExt.pathHistory.initialPosition.posConfidence;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[8])[0])[53] =
    c1_r1.DATA.safetyExt.pathHistory.initialPosition.speedConfidence;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[8])[56] =
    c1_r1.DATA.safetyExt.pathHistory.currGPSstatus;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[8])[60] =
    c1_r1.DATA.safetyExt.pathHistory.itemCnt;
  for (c1_i75 = 0; c1_i75 < 23; c1_i75++) {
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                  &((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                    &((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[8])[64])[0])[32 * (int32_T)
                  c1_i75])[0] =
      c1_r1.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c1_i75]
      .latOffset;
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                  &((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                    &((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[8])[64])[0])[32 * (int32_T)
                  c1_i75])[4] =
      c1_r1.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c1_i75]
      .longOffset;
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                  &((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                    &((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[8])[64])[0])[32 * (int32_T)
                  c1_i75])[8] =
      c1_r1.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c1_i75]
      .elevationOffset;
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                  &((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                    &((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[8])[64])[0])[32 * (int32_T)
                  c1_i75])[12] =
      c1_r1.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c1_i75]
      .timeOffset;
    for (c1_i78 = 0; c1_i78 < 4; c1_i78++) {
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                   &((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                     &((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
            [56])[8])[64])[0])[32 * (int32_T)c1_i75])[16])[c1_i78] =
        c1_r1.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c1_i75]
        .posAccuracy[c1_i78];
    }

    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                  &((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                    &((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[8])[64])[0])[32 * (int32_T)
                  c1_i75])[20] =
      c1_r1.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c1_i75]
      .heading;
    for (c1_i80 = 0; c1_i80 < 2; c1_i80++) {
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                   &((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                     &((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
            [56])[8])[64])[0])[32 * (int32_T)c1_i75])[24])[c1_i80] =
        c1_r1.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c1_i75]
        .speed[c1_i80];
    }
  }

  for (c1_i76 = 0; c1_i76 < 345; c1_i76++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
       [8])[64])[736])[c1_i76] =
      c1_r1.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_02[c1_i76];
  }

  for (c1_i77 = 0; c1_i77 < 276; c1_i77++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
       [8])[64])[1081])[c1_i77] =
      c1_r1.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_03[c1_i77];
  }

  for (c1_i79 = 0; c1_i79 < 184; c1_i79++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
       [8])[64])[1357])[c1_i79] =
      c1_r1.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_04[c1_i79];
  }

  for (c1_i81 = 0; c1_i81 < 230; c1_i81++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
       [8])[64])[1541])[c1_i81] =
      c1_r1.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_05[c1_i81];
  }

  for (c1_i82 = 0; c1_i82 < 138; c1_i82++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
       [8])[64])[1771])[c1_i82] =
      c1_r1.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_06[c1_i82];
  }

  for (c1_i83 = 0; c1_i83 < 242; c1_i83++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
       [8])[64])[1909])[c1_i83] =
      c1_r1.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_07[c1_i83];
  }

  for (c1_i84 = 0; c1_i84 < 161; c1_i84++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
       [8])[64])[2151])[c1_i84] =
      c1_r1.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_08[c1_i84];
  }

  for (c1_i85 = 0; c1_i85 < 196; c1_i85++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
       [8])[64])[2312])[c1_i85] =
      c1_r1.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_09[c1_i85];
  }

  for (c1_i86 = 0; c1_i86 < 104; c1_i86++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
       [8])[64])[2508])[c1_i86] =
      c1_r1.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_10[c1_i86];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathPrediction *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2688])[0] =
    c1_r1.DATA.safetyExt.pathPrediction.radiusOfCurve;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathPrediction *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2688])[4] =
    c1_r1.DATA.safetyExt.pathPrediction.confidence;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2696])[0])[0])[0] =
    c1_r1.DATA.safetyExt.theRTCM.anchorPoint.utcTime.year;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2696])[0])[0])[4] =
    c1_r1.DATA.safetyExt.theRTCM.anchorPoint.utcTime.month;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2696])[0])[0])[8] =
    c1_r1.DATA.safetyExt.theRTCM.anchorPoint.utcTime.day;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2696])[0])[0])[12] =
    c1_r1.DATA.safetyExt.theRTCM.anchorPoint.utcTime.hour;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2696])[0])[0])[16] =
    c1_r1.DATA.safetyExt.theRTCM.anchorPoint.utcTime.minute;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2696])[0])[0])[20] =
    c1_r1.DATA.safetyExt.theRTCM.anchorPoint.utcTime.second;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2696])[0])[24] =
    c1_r1.DATA.safetyExt.theRTCM.anchorPoint.longitude;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2696])[0])[28] =
    c1_r1.DATA.safetyExt.theRTCM.anchorPoint.latitude;
  for (c1_i87 = 0; c1_i87 < 2; c1_i87++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
       [2696])[0])[32])[c1_i87] =
      c1_r1.DATA.safetyExt.theRTCM.anchorPoint.elevation[c1_i87];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2696])[0])[36] =
    c1_r1.DATA.safetyExt.theRTCM.anchorPoint.heading;
  for (c1_i88 = 0; c1_i88 < 2; c1_i88++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
       [2696])[0])[40])[c1_i88] =
      c1_r1.DATA.safetyExt.theRTCM.anchorPoint.speed[c1_i88];
  }

  for (c1_i89 = 0; c1_i89 < 4; c1_i89++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
       [2696])[0])[42])[c1_i89] =
      c1_r1.DATA.safetyExt.theRTCM.anchorPoint.posAccuracy[c1_i89];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2696])[0])[48] =
    c1_r1.DATA.safetyExt.theRTCM.anchorPoint.timeConfidence;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2696])[0])[52] =
    c1_r1.DATA.safetyExt.theRTCM.anchorPoint.posConfidence;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2696])[0])[53] =
    c1_r1.DATA.safetyExt.theRTCM.anchorPoint.speedConfidence;
  for (c1_i90 = 0; c1_i90 < 5; c1_i90++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[56])[c1_i90] =
      c1_r1.DATA.safetyExt.theRTCM.rtcmHeader[c1_i90];
  }

  for (c1_i91 = 0; c1_i91 < 124; c1_i91++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[61])[c1_i91] =
      c1_r1.DATA.safetyExt.theRTCM.msg1001[c1_i91];
  }

  for (c1_i92 = 0; c1_i92 < 156; c1_i92++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[185])[c1_i92] =
      c1_r1.DATA.safetyExt.theRTCM.msg1002[c1_i92];
  }

  for (c1_i93 = 0; c1_i93 < 210; c1_i93++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[341])[c1_i93] =
      c1_r1.DATA.safetyExt.theRTCM.msg1003[c1_i93];
  }

  for (c1_i94 = 0; c1_i94 < 258; c1_i94++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[551])[c1_i94] =
      c1_r1.DATA.safetyExt.theRTCM.msg1004[c1_i94];
  }

  for (c1_i95 = 0; c1_i95 < 19; c1_i95++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[809])[c1_i95] =
      c1_r1.DATA.safetyExt.theRTCM.msg1005[c1_i95];
  }

  for (c1_i96 = 0; c1_i96 < 21; c1_i96++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[828])[c1_i96] =
      c1_r1.DATA.safetyExt.theRTCM.msg1006[c1_i96];
  }

  for (c1_i97 = 0; c1_i97 < 36; c1_i97++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[849])[c1_i97] =
      c1_r1.DATA.safetyExt.theRTCM.msg1007[c1_i97];
  }

  for (c1_i98 = 0; c1_i98 < 68; c1_i98++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[885])[c1_i98] =
      c1_r1.DATA.safetyExt.theRTCM.msg1008[c1_i98];
  }

  for (c1_i99 = 0; c1_i99 < 136; c1_i99++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[953])[c1_i99] =
      c1_r1.DATA.safetyExt.theRTCM.msg1009[c1_i99];
  }

  for (c1_i100 = 0; c1_i100 < 166; c1_i100++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[1089])[c1_i100] =
      c1_r1.DATA.safetyExt.theRTCM.msg1010[c1_i100];
  }

  for (c1_i101 = 0; c1_i101 < 222; c1_i101++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[1255])[c1_i101] =
      c1_r1.DATA.safetyExt.theRTCM.msg1011[c1_i101];
  }

  for (c1_i102 = 0; c1_i102 < 268; c1_i102++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[1477])[c1_i102] =
      c1_r1.DATA.safetyExt.theRTCM.msg1012[c1_i102];
  }

  for (c1_i103 = 0; c1_i103 < 27; c1_i103++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[1745])[c1_i103] =
      c1_r1.DATA.safetyExt.theRTCM.msg1013[c1_i103];
  }

  for (c1_i104 = 0; c1_i104 < 15; c1_i104++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[1772])[c1_i104] =
      c1_r1.DATA.safetyExt.theRTCM.msg1014[c1_i104];
  }

  for (c1_i105 = 0; c1_i105 < 69; c1_i105++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[1787])[c1_i105] =
      c1_r1.DATA.safetyExt.theRTCM.msg1015[c1_i105];
  }

  for (c1_i106 = 0; c1_i106 < 81; c1_i106++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[1856])[c1_i106] =
      c1_r1.DATA.safetyExt.theRTCM.msg1016[c1_i106];
  }

  for (c1_i107 = 0; c1_i107 < 115; c1_i107++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[1937])[c1_i107] =
      c1_r1.DATA.safetyExt.theRTCM.msg1017[c1_i107];
  }

  for (c1_i108 = 0; c1_i108 < 62; c1_i108++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[2052])[c1_i108] =
      c1_r1.DATA.safetyExt.theRTCM.msg1019[c1_i108];
  }

  for (c1_i109 = 0; c1_i109 < 45; c1_i109++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[2114])[c1_i109] =
      c1_r1.DATA.safetyExt.theRTCM.msg1020[c1_i109];
  }

  for (c1_i110 = 0; c1_i110 < 62; c1_i110++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[2159])[c1_i110] =
      c1_r1.DATA.safetyExt.theRTCM.msg1021[c1_i110];
  }

  for (c1_i111 = 0; c1_i111 < 75; c1_i111++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[2221])[c1_i111] =
      c1_r1.DATA.safetyExt.theRTCM.msg1022[c1_i111];
  }

  for (c1_i112 = 0; c1_i112 < 73; c1_i112++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[2296])[c1_i112] =
      c1_r1.DATA.safetyExt.theRTCM.msg1023[c1_i112];
  }

  for (c1_i113 = 0; c1_i113 < 74; c1_i113++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[2369])[c1_i113] =
      c1_r1.DATA.safetyExt.theRTCM.msg1024[c1_i113];
  }

  for (c1_i114 = 0; c1_i114 < 25; c1_i114++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[2443])[c1_i114] =
      c1_r1.DATA.safetyExt.theRTCM.msg1025[c1_i114];
  }

  for (c1_i115 = 0; c1_i115 < 30; c1_i115++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[2468])[c1_i115] =
      c1_r1.DATA.safetyExt.theRTCM.msg1026[c1_i115];
  }

  for (c1_i116 = 0; c1_i116 < 33; c1_i116++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[2498])[c1_i116] =
      c1_r1.DATA.safetyExt.theRTCM.msg1027[c1_i116];
  }

  for (c1_i117 = 0; c1_i117 < 69; c1_i117++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[2531])[c1_i117] =
      c1_r1.DATA.safetyExt.theRTCM.msg1029[c1_i117];
  }

  for (c1_i118 = 0; c1_i118 < 105; c1_i118++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[2600])[c1_i118] =
      c1_r1.DATA.safetyExt.theRTCM.msg1030[c1_i118];
  }

  for (c1_i119 = 0; c1_i119 < 107; c1_i119++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[2705])[c1_i119] =
      c1_r1.DATA.safetyExt.theRTCM.msg1031[c1_i119];
  }

  for (c1_i120 = 0; c1_i120 < 20; c1_i120++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[2812])[c1_i120] =
      c1_r1.DATA.safetyExt.theRTCM.msg1032[c1_i120];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])[0]
    = c1_r1.DATA.status.lights;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])[4]
    = c1_r1.DATA.status.lightBar;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[8])[0] =
    c1_r1.DATA.status.wipers.statusFront;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[8])[4] =
    c1_r1.DATA.status.wipers.rateFront;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[8])[8] =
    c1_r1.DATA.status.wipers.statusRear;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[8])[12] =
    c1_r1.DATA.status.wipers.rateRear;
  for (c1_i121 = 0; c1_i121 < 2; c1_i121++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])
      [24])[c1_i121] = c1_r1.DATA.status.brakeStatus[c1_i121];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])[28]
    = c1_r1.DATA.status.brakePressure;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])[32]
    = c1_r1.DATA.status.roadFriction;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])[36]
    = c1_r1.DATA.status.sunData;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])[40]
    = c1_r1.DATA.status.rainData;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])[44]
    = c1_r1.DATA.status.airTemp;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])[48]
    = c1_r1.DATA.status.airPres;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[56])[0] =
    c1_r1.DATA.status.steering.angle;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[56])[4] =
    c1_r1.DATA.status.steering.confidence;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[56])[8] =
    c1_r1.DATA.status.steering.rate;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[56])[12] =
    c1_r1.DATA.status.steering.wheels;
  for (c1_i122 = 0; c1_i122 < 7; c1_i122++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
        &((char_T *)chartInstance->c1_y)[8])[5584])[72])[0])[c1_i122] =
      c1_r1.DATA.status.accelSets.accel4way[c1_i122];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[72])[8] =
    c1_r1.DATA.status.accelSets.vertAccelThres;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[72])[12] =
    c1_r1.DATA.status.accelSets.yawRateCon;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[72])[16] =
    c1_r1.DATA.status.accelSets.hozAccelCon;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelConfidence *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)
        [8])[5584])[72])[24])[0])[0] =
    c1_r1.DATA.status.accelSets.confidenceSet.accelConfidence.yawRate;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelConfidence *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)
        [8])[5584])[72])[24])[0])[4] =
    c1_r1.DATA.status.accelSets.confidenceSet.accelConfidence.acceleration;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelConfidence *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)
        [8])[5584])[72])[24])[0])[8] =
    c1_r1.DATA.status.accelSets.confidenceSet.accelConfidence.steeringWheelAngle;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)
        [8])[5584])[72])[24])[16] =
    c1_r1.DATA.status.accelSets.confidenceSet.speedConfidence;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)
        [8])[5584])[72])[24])[20] =
    c1_r1.DATA.status.accelSets.confidenceSet.timeConfidence;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)
        [8])[5584])[72])[24])[24] =
    c1_r1.DATA.status.accelSets.confidenceSet.posConfidence;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)
        [8])[5584])[72])[24])[28] =
    c1_r1.DATA.status.accelSets.confidenceSet.steerConfidence;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)
        [8])[5584])[72])[24])[32] =
    c1_r1.DATA.status.accelSets.confidenceSet.throttleConfidence;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[136])[0] =
    c1_r1.DATA.status.object.obDist;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[136])[4] =
    c1_r1.DATA.status.object.obDirect;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[136])[8])[0] = c1_r1.DATA.status.object.dateTime.year;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[136])[8])[4] = c1_r1.DATA.status.object.dateTime.month;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[136])[8])[8] = c1_r1.DATA.status.object.dateTime.day;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[136])[8])[12] = c1_r1.DATA.status.object.dateTime.hour;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[136])[8])[16] = c1_r1.DATA.status.object.dateTime.minute;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[136])[8])[20] = c1_r1.DATA.status.object.dateTime.second;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[168])[0])[0] = c1_r1.DATA.status.fullPos.utcTime.year;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[168])[0])[4] = c1_r1.DATA.status.fullPos.utcTime.month;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[168])[0])[8] = c1_r1.DATA.status.fullPos.utcTime.day;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[168])[0])[12] = c1_r1.DATA.status.fullPos.utcTime.hour;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[168])[0])[16] = c1_r1.DATA.status.fullPos.utcTime.minute;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[168])[0])[20] = c1_r1.DATA.status.fullPos.utcTime.second;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[168])[24] =
    c1_r1.DATA.status.fullPos.longitude;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[168])[28] =
    c1_r1.DATA.status.fullPos.latitude;
  for (c1_i123 = 0; c1_i123 < 2; c1_i123++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
        &((char_T *)chartInstance->c1_y)[8])[5584])[168])[32])[c1_i123] =
      c1_r1.DATA.status.fullPos.elevation[c1_i123];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[168])[36] =
    c1_r1.DATA.status.fullPos.heading;
  for (c1_i124 = 0; c1_i124 < 2; c1_i124++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
        &((char_T *)chartInstance->c1_y)[8])[5584])[168])[40])[c1_i124] =
      c1_r1.DATA.status.fullPos.speed[c1_i124];
  }

  for (c1_i125 = 0; c1_i125 < 4; c1_i125++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
        &((char_T *)chartInstance->c1_y)[8])[5584])[168])[42])[c1_i125] =
      c1_r1.DATA.status.fullPos.posAccuracy[c1_i125];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[168])[48] =
    c1_r1.DATA.status.fullPos.timeConfidence;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[168])[52] =
    c1_r1.DATA.status.fullPos.posConfidence;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[168])[53] =
    c1_r1.DATA.status.fullPos.speedConfidence;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])
    [224] = c1_r1.DATA.status.throttlePos;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])
    [228] = c1_r1.DATA.status.speedHeadC;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])
    [232] = c1_r1.DATA.status.speedC;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[240])[0] =
    c1_r1.DATA.status.vehicleData.height;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_bumpers *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[240])[8])[0] =
    c1_r1.DATA.status.vehicleData.bumpers.frnt;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_bumpers *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[240])[8])[4] =
    c1_r1.DATA.status.vehicleData.bumpers.rear;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[240])[16] =
    c1_r1.DATA.status.vehicleData.mass;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[240])[20] =
    c1_r1.DATA.status.vehicleData.trailerWeight;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[240])[24] =
    c1_r1.DATA.status.vehicleData.type;
  for (c1_i126 = 0; c1_i126 < 63; c1_i126++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
        &((char_T *)chartInstance->c1_y)[8])[5584])[272])[0])[c1_i126] =
      c1_r1.DATA.status.vehicleIdent.name[c1_i126];
  }

  for (c1_i127 = 0; c1_i127 < 17; c1_i127++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
        &((char_T *)chartInstance->c1_y)[8])[5584])[272])[63])[c1_i127] =
      c1_r1.DATA.status.vehicleIdent.vin[c1_i127];
  }

  for (c1_i128 = 0; c1_i128 < 32; c1_i128++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
        &((char_T *)chartInstance->c1_y)[8])[5584])[272])[80])[c1_i128] =
      c1_r1.DATA.status.vehicleIdent.ownerCode[c1_i128];
  }

  for (c1_i129 = 0; c1_i129 < 4; c1_i129++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
        &((char_T *)chartInstance->c1_y)[8])[5584])[272])[112])[c1_i129] =
      c1_r1.DATA.status.vehicleIdent.id[c1_i129];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[272])[116] =
    c1_r1.DATA.status.vehicleIdent.vehicleType;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleClass *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[272])[120])[0] =
    c1_r1.DATA.status.vehicleIdent.vehicleClass.vGroup;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleClass *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[272])[120])[4] =
    c1_r1.DATA.status.vehicleIdent.vehicleClass.rGroup;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleClass *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[272])[120])[8] =
    c1_r1.DATA.status.vehicleIdent.vehicleClass.rEquip;
  for (c1_i130 = 0; c1_i130 < 16; c1_i130++) {
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_y)[8])[5584])[408])[0])[32 * (int32_T)
                  c1_i130])[0] = c1_r1.DATA.status.j1939data.tires[c1_i130].
      location;
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_y)[8])[5584])[408])[0])[32 * (int32_T)
                  c1_i130])[4] = c1_r1.DATA.status.j1939data.tires[c1_i130].
      pressure;
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_y)[8])[5584])[408])[0])[32 * (int32_T)
                  c1_i130])[8] = c1_r1.DATA.status.j1939data.tires[c1_i130].temp;
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_y)[8])[5584])[408])[0])[32 * (int32_T)
                  c1_i130])[12] = c1_r1.DATA.status.j1939data.tires[c1_i130].
      wheelSensorStatus;
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_y)[8])[5584])[408])[0])[32 * (int32_T)
                  c1_i130])[16] = c1_r1.DATA.status.j1939data.tires[c1_i130].
      wheelEndElectFault;
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_y)[8])[5584])[408])[0])[32 * (int32_T)
                  c1_i130])[20] = c1_r1.DATA.status.j1939data.tires[c1_i130].
      leakageRate;
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_y)[8])[5584])[408])[0])[32 * (int32_T)
                  c1_i130])[24] = c1_r1.DATA.status.j1939data.tires[c1_i130].
      detection;
  }

  for (c1_i131 = 0; c1_i131 < 16; c1_i131++) {
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_axle *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_axle *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])
      [408])[512])[8 * (int32_T)c1_i131])[0] =
      c1_r1.DATA.status.j1939data.axle[c1_i131].location;
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_axle *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_axle *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])
      [408])[512])[8 * (int32_T)c1_i131])[4] =
      c1_r1.DATA.status.j1939data.axle[c1_i131].weight;
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[408])[640] =
    c1_r1.DATA.status.j1939data.trailerWeight;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[408])[644] =
    c1_r1.DATA.status.j1939data.cargoWeight;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[408])[648] =
    c1_r1.DATA.status.j1939data.steeringAxleTemperature;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[408])[652] =
    c1_r1.DATA.status.j1939data.driveAxleLocation;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[408])[656] =
    c1_r1.DATA.status.j1939data.driveAxleLiftAirPressure;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[408])[660] =
    c1_r1.DATA.status.j1939data.driveAxleTemperature;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[408])[664] =
    c1_r1.DATA.status.j1939data.driveAxleLubePressure;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[408])[668] =
    c1_r1.DATA.status.j1939data.steeringAxleLubePressure;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[1080])[0] =
    c1_r1.DATA.status.weatherReport.isRaining;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[1080])[4] =
    c1_r1.DATA.status.weatherReport.rainRate;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[1080])[8] =
    c1_r1.DATA.status.weatherReport.precipSituation;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[1080])[12] =
    c1_r1.DATA.status.weatherReport.solarRadiation;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[1080])[16] =
    c1_r1.DATA.status.weatherReport.friction;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])
    [1104] = c1_r1.DATA.status.gpsStatus;
  chartInstance->c1_is_active_c1_Jan22_DLforACC_cs = c1_hd_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_b_u, 1)),
     "is_active_c1_Jan22_DLforACC_cs");
  sf_mex_destroy(&c1_b_u);
  c1_update_debugger_state_c1_Jan22_DLforACC_cs(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_Jan22_DLforACC_cs(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c1_RuntimeVar);
}

static void sf_gateway_c1_Jan22_DLforACC_cs(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance)
{
  c1_PRESCAN_V2X_USER_BSM_MESSAGE c1_b_u;
  int32_T c1_i132;
  int32_T c1_i133;
  int32_T c1_i134;
  int32_T c1_i135;
  int32_T c1_i136;
  int32_T c1_i137;
  PRESCAN_V2X_FIXED_BSM_MESSAGE c1_b_z;
  int32_T c1_i138;
  int32_T c1_i139;
  int32_T c1_i140;
  int32_T c1_i141;
  int32_T c1_i142;
  int32_T c1_i143;
  int32_T c1_i144;
  int32_T c1_i145;
  int32_T c1_i146;
  int32_T c1_i147;
  int32_T c1_i148;
  int32_T c1_i149;
  int32_T c1_i150;
  int32_T c1_i151;
  int32_T c1_i152;
  int32_T c1_i153;
  int32_T c1_i154;
  int32_T c1_i155;
  int32_T c1_i156;
  int32_T c1_i157;
  int32_T c1_i158;
  int32_T c1_i159;
  int32_T c1_i160;
  int32_T c1_i161;
  int32_T c1_i162;
  int32_T c1_i163;
  int32_T c1_i164;
  int32_T c1_i165;
  int32_T c1_i166;
  int32_T c1_i167;
  int32_T c1_i168;
  int32_T c1_i169;
  int32_T c1_i170;
  int32_T c1_i171;
  int32_T c1_i172;
  int32_T c1_i173;
  int32_T c1_i174;
  int32_T c1_i175;
  int32_T c1_i176;
  int32_T c1_i177;
  int32_T c1_i178;
  int32_T c1_i179;
  int32_T c1_i180;
  int32_T c1_i181;
  int32_T c1_i182;
  int32_T c1_i183;
  int32_T c1_i184;
  int32_T c1_i185;
  int32_T c1_i186;
  int32_T c1_i187;
  int32_T c1_i188;
  int32_T c1_i189;
  int32_T c1_i190;
  int32_T c1_i191;
  int32_T c1_i192;
  int32_T c1_i193;
  int32_T c1_i194;
  int32_T c1_i195;
  int32_T c1_i196;
  int32_T c1_i197;
  int32_T c1_i198;
  int32_T c1_i199;
  int32_T c1_i200;
  int32_T c1_i201;
  int32_T c1_i202;
  int32_T c1_i203;
  uint32_T c1_debug_family_var_map[5];
  real_T c1_nargin = 2.0;
  real_T c1_nargout = 1.0;
  PRESCAN_V2X_FIXED_BSM_MESSAGE c1_b_y;
  c1_PRESCAN_V2X_USER_BSM_MESSAGE c1_c_y;
  PRESCAN_V2X_FIXED_BSM_MESSAGE c1_c_z;
  uint32_T c1_b_debug_family_var_map[5];
  real_T c1_b_nargin = 2.0;
  real_T c1_b_nargout = 1.0;
  PRESCAN_V2X_FIXED_BSM_MESSAGE c1_c_u;
  c1_PRESCAN_V2X_USER_BSM_MESSAGE c1_d_y;
  uint32_T c1_c_debug_family_var_map[4];
  real_T c1_c_nargin = 2.0;
  real_T c1_c_nargout = 1.0;
  PRESCAN_HEADER c1_d_u;
  PRESCAN_HEADER c1_e_y;
  uint32_T c1_d_debug_family_var_map[4];
  real_T c1_d_nargin = 2.0;
  real_T c1_d_nargout = 1.0;
  PRESCAN_V2X_FIXED_BSM_DATA c1_e_u;
  c1_PRESCAN_V2X_USER_BSM_DATA c1_f_y;
  uint32_T c1_e_debug_family_var_map[4];
  real_T c1_e_nargin = 2.0;
  real_T c1_e_nargout = 1.0;
  int32_T c1_i204;
  int32_T c1_i205;
  int32_T c1_i206;
  int32_T c1_i207;
  int32_T c1_i208;
  int32_T c1_i209;
  PRESCAN_V2X_FIXED_BSM_size c1_f_u;
  c1_PRESCAN_V2X_USER_BSM_size c1_g_y;
  uint32_T c1_f_debug_family_var_map[4];
  real_T c1_f_nargin = 2.0;
  real_T c1_f_nargout = 1.0;
  int32_T c1_i210;
  int32_T c1_i211;
  int32_T c1_i212;
  int32_T c1_i213;
  int32_T c1_i214;
  int32_T c1_i215;
  int32_T c1_i216;
  int32_T c1_i217;
  int32_T c1_i218;
  int32_T c1_i219;
  int32_T c1_i220;
  int32_T c1_i221;
  int32_T c1_i222;
  int32_T c1_i223;
  int32_T c1_i224;
  int32_T c1_i225;
  int32_T c1_i226;
  int32_T c1_i227;
  int32_T c1_i228;
  int32_T c1_i229;
  int32_T c1_i230;
  int32_T c1_i231;
  int32_T c1_i232;
  int32_T c1_i233;
  int32_T c1_i234;
  int32_T c1_i235;
  int32_T c1_i236;
  int32_T c1_i237;
  int32_T c1_i238;
  int32_T c1_i239;
  int32_T c1_i240;
  int32_T c1_i241;
  int32_T c1_i242;
  int32_T c1_i243;
  int32_T c1_i244;
  int32_T c1_i245;
  int32_T c1_i246;
  int32_T c1_i247;
  int32_T c1_i248;
  int32_T c1_i249;
  int32_T c1_i250;
  int32_T c1_i251;
  int32_T c1_i252;
  int32_T c1_i253;
  int32_T c1_i254;
  int32_T c1_i255;
  int32_T c1_i256;
  int32_T c1_i257;
  int32_T c1_i258;
  int32_T c1_i259;
  int32_T c1_i260;
  int32_T c1_i261;
  int32_T c1_i262;
  int32_T c1_i263;
  int32_T c1_i264;
  int32_T c1_i265;
  int32_T c1_i266;
  int32_T c1_i267;
  int32_T c1_i268;
  int32_T c1_i269;
  int32_T c1_i270;
  int32_T c1_i271;
  int32_T c1_i272;
  int32_T c1_i273;
  int32_T c1_i274;
  int32_T c1_i275;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0, chartInstance->c1_sfEvent);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_b_u.HEADER.valid = *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)
    chartInstance->c1_u)[0])[0];
  c1_b_u.DATA.msgID = *(int32_T *)&((char_T *)(c1_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)chartInstance->c1_u)[8])[0];
  c1_b_u.DATA.msgCnt = *(int32_T *)&((char_T *)(c1_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)chartInstance->c1_u)[8])[4];
  for (c1_i132 = 0; c1_i132 < 4; c1_i132++) {
    c1_b_u.DATA.id[c1_i132] = ((int8_T *)&((char_T *)
      (c1_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)chartInstance->c1_u)[8])[8])
      [c1_i132];
  }

  c1_b_u.DATA.secMark = *(int32_T *)&((char_T *)(c1_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)chartInstance->c1_u)[8])[12];
  c1_b_u.DATA.latitude = *(int32_T *)&((char_T *)(c1_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)chartInstance->c1_u)[8])[16];
  c1_b_u.DATA.longitude = *(int32_T *)&((char_T *)(c1_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)chartInstance->c1_u)[8])[20];
  for (c1_i133 = 0; c1_i133 < 2; c1_i133++) {
    c1_b_u.DATA.elev[c1_i133] = ((int8_T *)&((char_T *)
      (c1_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)chartInstance->c1_u)[8])[24])
      [c1_i133];
  }

  for (c1_i134 = 0; c1_i134 < 4; c1_i134++) {
    c1_b_u.DATA.accuracy[c1_i134] = ((int8_T *)&((char_T *)
      (c1_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)chartInstance->c1_u)[8])[26])
      [c1_i134];
  }

  for (c1_i135 = 0; c1_i135 < 2; c1_i135++) {
    c1_b_u.DATA.speed[c1_i135] = ((int8_T *)&((char_T *)
      (c1_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)chartInstance->c1_u)[8])[30])
      [c1_i135];
  }

  c1_b_u.DATA.heading = *(int32_T *)&((char_T *)(c1_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)chartInstance->c1_u)[8])[32];
  c1_b_u.DATA.angle = *(int8_T *)&((char_T *)(c1_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)chartInstance->c1_u)[8])[36];
  for (c1_i136 = 0; c1_i136 < 7; c1_i136++) {
    c1_b_u.DATA.accelSet[c1_i136] = ((int8_T *)&((char_T *)
      (c1_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)chartInstance->c1_u)[8])[37])
      [c1_i136];
  }

  for (c1_i137 = 0; c1_i137 < 2; c1_i137++) {
    c1_b_u.DATA.brakes[c1_i137] = ((int8_T *)&((char_T *)
      (c1_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)chartInstance->c1_u)[8])[44])
      [c1_i137];
  }

  c1_b_u.DATA.size.width = *(int32_T *)&((char_T *)(c1_PRESCAN_V2X_USER_BSM_size
    *)&((char_T *)(c1_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
    chartInstance->c1_u)[8])[48])[0];
  c1_b_u.DATA.size.length = *(int32_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_BSM_size *)&((char_T *)(c1_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)chartInstance->c1_u)[8])[48])[4];
  c1_b_z.HEADER.valid = *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)
    chartInstance->c1_z)[0])[0];
  c1_b_z.DATA.msgID = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[0];
  c1_b_z.DATA.msgCnt = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[4];
  for (c1_i138 = 0; c1_i138 < 4; c1_i138++) {
    c1_b_z.DATA.id[c1_i138] = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[8])[c1_i138];
  }

  c1_b_z.DATA.secMark = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[12];
  c1_b_z.DATA.latitude = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[16];
  c1_b_z.DATA.longitude = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[20];
  for (c1_i139 = 0; c1_i139 < 2; c1_i139++) {
    c1_b_z.DATA.elev[c1_i139] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])[24])
      [c1_i139];
  }

  for (c1_i140 = 0; c1_i140 < 4; c1_i140++) {
    c1_b_z.DATA.accuracy[c1_i140] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])[26])
      [c1_i140];
  }

  for (c1_i141 = 0; c1_i141 < 2; c1_i141++) {
    c1_b_z.DATA.speed[c1_i141] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])[30])
      [c1_i141];
  }

  c1_b_z.DATA.heading = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[32];
  c1_b_z.DATA.angle = *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[36];
  for (c1_i142 = 0; c1_i142 < 7; c1_i142++) {
    c1_b_z.DATA.accelSet[c1_i142] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])[37])
      [c1_i142];
  }

  for (c1_i143 = 0; c1_i143 < 2; c1_i143++) {
    c1_b_z.DATA.brakes[c1_i143] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])[44])
      [c1_i143];
  }

  c1_b_z.DATA.size.width = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_size *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])
    [48])[0];
  c1_b_z.DATA.size.length = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_size *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])
    [48])[4];
  c1_b_z.DATA.safetyExt.events = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[56])[0];
  c1_b_z.DATA.safetyExt.pathHistory.initialPosition.utcTime.year = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])[56])
        [8])[0])[0])[0];
  c1_b_z.DATA.safetyExt.pathHistory.initialPosition.utcTime.month = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])[56])
        [8])[0])[0])[4];
  c1_b_z.DATA.safetyExt.pathHistory.initialPosition.utcTime.day = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])[56])
        [8])[0])[0])[8];
  c1_b_z.DATA.safetyExt.pathHistory.initialPosition.utcTime.hour = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])[56])
        [8])[0])[0])[12];
  c1_b_z.DATA.safetyExt.pathHistory.initialPosition.utcTime.minute = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])[56])
        [8])[0])[0])[16];
  c1_b_z.DATA.safetyExt.pathHistory.initialPosition.utcTime.second = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])[56])
        [8])[0])[0])[20];
  c1_b_z.DATA.safetyExt.pathHistory.initialPosition.longitude = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])[56])
       [8])[0])[24];
  c1_b_z.DATA.safetyExt.pathHistory.initialPosition.latitude = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])[56])
       [8])[0])[28];
  for (c1_i144 = 0; c1_i144 < 2; c1_i144++) {
    c1_b_z.DATA.safetyExt.pathHistory.initialPosition.elevation[c1_i144] =
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])[56])
         [8])[0])[32])[c1_i144];
  }

  c1_b_z.DATA.safetyExt.pathHistory.initialPosition.heading = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])[56])
       [8])[0])[36];
  for (c1_i145 = 0; c1_i145 < 2; c1_i145++) {
    c1_b_z.DATA.safetyExt.pathHistory.initialPosition.speed[c1_i145] = ((int8_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[56])[8])[0])[40])[c1_i145];
  }

  for (c1_i146 = 0; c1_i146 < 4; c1_i146++) {
    c1_b_z.DATA.safetyExt.pathHistory.initialPosition.posAccuracy[c1_i146] =
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])[56])
         [8])[0])[42])[c1_i146];
  }

  c1_b_z.DATA.safetyExt.pathHistory.initialPosition.timeConfidence = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])[56])
       [8])[0])[48];
  c1_b_z.DATA.safetyExt.pathHistory.initialPosition.posConfidence = *(int8_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])[56])
       [8])[0])[52];
  c1_b_z.DATA.safetyExt.pathHistory.initialPosition.speedConfidence = *(int8_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])[56])
       [8])[0])[53];
  c1_b_z.DATA.safetyExt.pathHistory.currGPSstatus = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[56])[8])[56];
  c1_b_z.DATA.safetyExt.pathHistory.itemCnt = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[56])[8])[60];
  for (c1_i147 = 0; c1_i147 < 23; c1_i147++) {
    c1_b_z.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c1_i147]
      .latOffset = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[56])[8])[64])[0])[32 * (int32_T)
      c1_i147])[0];
    c1_b_z.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c1_i147]
      .longOffset = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[56])[8])[64])[0])[32 * (int32_T)
      c1_i147])[4];
    c1_b_z.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c1_i147]
      .elevationOffset = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[56])[8])[64])[0])[32 * (int32_T)
      c1_i147])[8];
    c1_b_z.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c1_i147]
      .timeOffset = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[56])[8])[64])[0])[32 * (int32_T)
      c1_i147])[12];
    for (c1_i150 = 0; c1_i150 < 4; c1_i150++) {
      c1_b_z.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c1_i147]
        .posAccuracy[c1_i150] = ((int8_T *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])[56])
        [8])[64])[0])[32 * (int32_T)c1_i147])[16])[c1_i150];
    }

    c1_b_z.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c1_i147]
      .heading = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[56])[8])[64])[0])[32 * (int32_T)
      c1_i147])[20];
    for (c1_i152 = 0; c1_i152 < 2; c1_i152++) {
      c1_b_z.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c1_i147]
        .speed[c1_i152] = ((int8_T *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])[56])
        [8])[64])[0])[32 * (int32_T)c1_i147])[24])[c1_i152];
    }
  }

  for (c1_i148 = 0; c1_i148 < 345; c1_i148++) {
    c1_b_z.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_02[c1_i148]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])
            [56])[8])[64])[736])[c1_i148];
  }

  for (c1_i149 = 0; c1_i149 < 276; c1_i149++) {
    c1_b_z.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_03[c1_i149]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])
            [56])[8])[64])[1081])[c1_i149];
  }

  for (c1_i151 = 0; c1_i151 < 184; c1_i151++) {
    c1_b_z.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_04[c1_i151]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])
            [56])[8])[64])[1357])[c1_i151];
  }

  for (c1_i153 = 0; c1_i153 < 230; c1_i153++) {
    c1_b_z.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_05[c1_i153]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])
            [56])[8])[64])[1541])[c1_i153];
  }

  for (c1_i154 = 0; c1_i154 < 138; c1_i154++) {
    c1_b_z.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_06[c1_i154]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])
            [56])[8])[64])[1771])[c1_i154];
  }

  for (c1_i155 = 0; c1_i155 < 242; c1_i155++) {
    c1_b_z.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_07[c1_i155]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])
            [56])[8])[64])[1909])[c1_i155];
  }

  for (c1_i156 = 0; c1_i156 < 161; c1_i156++) {
    c1_b_z.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_08[c1_i156]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])
            [56])[8])[64])[2151])[c1_i156];
  }

  for (c1_i157 = 0; c1_i157 < 196; c1_i157++) {
    c1_b_z.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_09[c1_i157]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])
            [56])[8])[64])[2312])[c1_i157];
  }

  for (c1_i158 = 0; c1_i158 < 104; c1_i158++) {
    c1_b_z.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_10[c1_i158]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])
            [56])[8])[64])[2508])[c1_i158];
  }

  c1_b_z.DATA.safetyExt.pathPrediction.radiusOfCurve = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathPrediction *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[56])[2688])[0];
  c1_b_z.DATA.safetyExt.pathPrediction.confidence = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathPrediction *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[56])[2688])[4];
  c1_b_z.DATA.safetyExt.theRTCM.anchorPoint.utcTime.year = *(int32_T *)&((char_T
    *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[56])[2696])[0])[0])[0];
  c1_b_z.DATA.safetyExt.theRTCM.anchorPoint.utcTime.month = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])[56])
        [2696])[0])[0])[4];
  c1_b_z.DATA.safetyExt.theRTCM.anchorPoint.utcTime.day = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[56])[2696])[0])[0])[8];
  c1_b_z.DATA.safetyExt.theRTCM.anchorPoint.utcTime.hour = *(int32_T *)&((char_T
    *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[56])[2696])[0])[0])[12];
  c1_b_z.DATA.safetyExt.theRTCM.anchorPoint.utcTime.minute = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])[56])
        [2696])[0])[0])[16];
  c1_b_z.DATA.safetyExt.theRTCM.anchorPoint.utcTime.second = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])[56])
        [2696])[0])[0])[20];
  c1_b_z.DATA.safetyExt.theRTCM.anchorPoint.longitude = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[56])[2696])[0])[24];
  c1_b_z.DATA.safetyExt.theRTCM.anchorPoint.latitude = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[56])[2696])[0])[28];
  for (c1_i159 = 0; c1_i159 < 2; c1_i159++) {
    c1_b_z.DATA.safetyExt.theRTCM.anchorPoint.elevation[c1_i159] = ((int8_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[56])[2696])[0])[32])[c1_i159];
  }

  c1_b_z.DATA.safetyExt.theRTCM.anchorPoint.heading = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[56])[2696])[0])[36];
  for (c1_i160 = 0; c1_i160 < 2; c1_i160++) {
    c1_b_z.DATA.safetyExt.theRTCM.anchorPoint.speed[c1_i160] = ((int8_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[56])[2696])[0])[40])[c1_i160];
  }

  for (c1_i161 = 0; c1_i161 < 4; c1_i161++) {
    c1_b_z.DATA.safetyExt.theRTCM.anchorPoint.posAccuracy[c1_i161] = ((int8_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[56])[2696])[0])[42])[c1_i161];
  }

  c1_b_z.DATA.safetyExt.theRTCM.anchorPoint.timeConfidence = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])[56])
       [2696])[0])[48];
  c1_b_z.DATA.safetyExt.theRTCM.anchorPoint.posConfidence = *(int8_T *)&((char_T
    *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[56])[2696])[0])[52];
  c1_b_z.DATA.safetyExt.theRTCM.anchorPoint.speedConfidence = *(int8_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])[56])
       [2696])[0])[53];
  for (c1_i162 = 0; c1_i162 < 5; c1_i162++) {
    c1_b_z.DATA.safetyExt.theRTCM.rtcmHeader[c1_i162] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[56])[2696])[56])[c1_i162];
  }

  for (c1_i163 = 0; c1_i163 < 124; c1_i163++) {
    c1_b_z.DATA.safetyExt.theRTCM.msg1001[c1_i163] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[56])[2696])[61])[c1_i163];
  }

  for (c1_i164 = 0; c1_i164 < 156; c1_i164++) {
    c1_b_z.DATA.safetyExt.theRTCM.msg1002[c1_i164] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[56])[2696])[185])[c1_i164];
  }

  for (c1_i165 = 0; c1_i165 < 210; c1_i165++) {
    c1_b_z.DATA.safetyExt.theRTCM.msg1003[c1_i165] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[56])[2696])[341])[c1_i165];
  }

  for (c1_i166 = 0; c1_i166 < 258; c1_i166++) {
    c1_b_z.DATA.safetyExt.theRTCM.msg1004[c1_i166] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[56])[2696])[551])[c1_i166];
  }

  for (c1_i167 = 0; c1_i167 < 19; c1_i167++) {
    c1_b_z.DATA.safetyExt.theRTCM.msg1005[c1_i167] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[56])[2696])[809])[c1_i167];
  }

  for (c1_i168 = 0; c1_i168 < 21; c1_i168++) {
    c1_b_z.DATA.safetyExt.theRTCM.msg1006[c1_i168] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[56])[2696])[828])[c1_i168];
  }

  for (c1_i169 = 0; c1_i169 < 36; c1_i169++) {
    c1_b_z.DATA.safetyExt.theRTCM.msg1007[c1_i169] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[56])[2696])[849])[c1_i169];
  }

  for (c1_i170 = 0; c1_i170 < 68; c1_i170++) {
    c1_b_z.DATA.safetyExt.theRTCM.msg1008[c1_i170] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[56])[2696])[885])[c1_i170];
  }

  for (c1_i171 = 0; c1_i171 < 136; c1_i171++) {
    c1_b_z.DATA.safetyExt.theRTCM.msg1009[c1_i171] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[56])[2696])[953])[c1_i171];
  }

  for (c1_i172 = 0; c1_i172 < 166; c1_i172++) {
    c1_b_z.DATA.safetyExt.theRTCM.msg1010[c1_i172] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[56])[2696])[1089])[c1_i172];
  }

  for (c1_i173 = 0; c1_i173 < 222; c1_i173++) {
    c1_b_z.DATA.safetyExt.theRTCM.msg1011[c1_i173] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[56])[2696])[1255])[c1_i173];
  }

  for (c1_i174 = 0; c1_i174 < 268; c1_i174++) {
    c1_b_z.DATA.safetyExt.theRTCM.msg1012[c1_i174] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[56])[2696])[1477])[c1_i174];
  }

  for (c1_i175 = 0; c1_i175 < 27; c1_i175++) {
    c1_b_z.DATA.safetyExt.theRTCM.msg1013[c1_i175] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[56])[2696])[1745])[c1_i175];
  }

  for (c1_i176 = 0; c1_i176 < 15; c1_i176++) {
    c1_b_z.DATA.safetyExt.theRTCM.msg1014[c1_i176] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[56])[2696])[1772])[c1_i176];
  }

  for (c1_i177 = 0; c1_i177 < 69; c1_i177++) {
    c1_b_z.DATA.safetyExt.theRTCM.msg1015[c1_i177] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[56])[2696])[1787])[c1_i177];
  }

  for (c1_i178 = 0; c1_i178 < 81; c1_i178++) {
    c1_b_z.DATA.safetyExt.theRTCM.msg1016[c1_i178] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[56])[2696])[1856])[c1_i178];
  }

  for (c1_i179 = 0; c1_i179 < 115; c1_i179++) {
    c1_b_z.DATA.safetyExt.theRTCM.msg1017[c1_i179] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[56])[2696])[1937])[c1_i179];
  }

  for (c1_i180 = 0; c1_i180 < 62; c1_i180++) {
    c1_b_z.DATA.safetyExt.theRTCM.msg1019[c1_i180] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[56])[2696])[2052])[c1_i180];
  }

  for (c1_i181 = 0; c1_i181 < 45; c1_i181++) {
    c1_b_z.DATA.safetyExt.theRTCM.msg1020[c1_i181] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[56])[2696])[2114])[c1_i181];
  }

  for (c1_i182 = 0; c1_i182 < 62; c1_i182++) {
    c1_b_z.DATA.safetyExt.theRTCM.msg1021[c1_i182] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[56])[2696])[2159])[c1_i182];
  }

  for (c1_i183 = 0; c1_i183 < 75; c1_i183++) {
    c1_b_z.DATA.safetyExt.theRTCM.msg1022[c1_i183] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[56])[2696])[2221])[c1_i183];
  }

  for (c1_i184 = 0; c1_i184 < 73; c1_i184++) {
    c1_b_z.DATA.safetyExt.theRTCM.msg1023[c1_i184] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[56])[2696])[2296])[c1_i184];
  }

  for (c1_i185 = 0; c1_i185 < 74; c1_i185++) {
    c1_b_z.DATA.safetyExt.theRTCM.msg1024[c1_i185] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[56])[2696])[2369])[c1_i185];
  }

  for (c1_i186 = 0; c1_i186 < 25; c1_i186++) {
    c1_b_z.DATA.safetyExt.theRTCM.msg1025[c1_i186] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[56])[2696])[2443])[c1_i186];
  }

  for (c1_i187 = 0; c1_i187 < 30; c1_i187++) {
    c1_b_z.DATA.safetyExt.theRTCM.msg1026[c1_i187] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[56])[2696])[2468])[c1_i187];
  }

  for (c1_i188 = 0; c1_i188 < 33; c1_i188++) {
    c1_b_z.DATA.safetyExt.theRTCM.msg1027[c1_i188] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[56])[2696])[2498])[c1_i188];
  }

  for (c1_i189 = 0; c1_i189 < 69; c1_i189++) {
    c1_b_z.DATA.safetyExt.theRTCM.msg1029[c1_i189] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[56])[2696])[2531])[c1_i189];
  }

  for (c1_i190 = 0; c1_i190 < 105; c1_i190++) {
    c1_b_z.DATA.safetyExt.theRTCM.msg1030[c1_i190] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[56])[2696])[2600])[c1_i190];
  }

  for (c1_i191 = 0; c1_i191 < 107; c1_i191++) {
    c1_b_z.DATA.safetyExt.theRTCM.msg1031[c1_i191] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[56])[2696])[2705])[c1_i191];
  }

  for (c1_i192 = 0; c1_i192 < 20; c1_i192++) {
    c1_b_z.DATA.safetyExt.theRTCM.msg1032[c1_i192] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_z)[8])[56])[2696])[2812])[c1_i192];
  }

  c1_b_z.DATA.status.lights = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[5584])[0];
  c1_b_z.DATA.status.lightBar = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[5584])[4];
  c1_b_z.DATA.status.wipers.statusFront = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])
    [5584])[8])[0];
  c1_b_z.DATA.status.wipers.rateFront = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])
    [5584])[8])[4];
  c1_b_z.DATA.status.wipers.statusRear = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])
    [5584])[8])[8];
  c1_b_z.DATA.status.wipers.rateRear = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])
    [5584])[8])[12];
  for (c1_i193 = 0; c1_i193 < 2; c1_i193++) {
    c1_b_z.DATA.status.brakeStatus[c1_i193] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_z)[8])[5584])[24])[c1_i193];
  }

  c1_b_z.DATA.status.brakePressure = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[5584])[28];
  c1_b_z.DATA.status.roadFriction = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[5584])[32];
  c1_b_z.DATA.status.sunData = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[5584])[36];
  c1_b_z.DATA.status.rainData = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[5584])[40];
  c1_b_z.DATA.status.airTemp = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[5584])[44];
  c1_b_z.DATA.status.airPres = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[5584])[48];
  c1_b_z.DATA.status.steering.angle = *(int8_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])
    [5584])[56])[0];
  c1_b_z.DATA.status.steering.confidence = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])
    [5584])[56])[4];
  c1_b_z.DATA.status.steering.rate = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])
    [5584])[56])[8];
  c1_b_z.DATA.status.steering.wheels = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])
    [5584])[56])[12];
  for (c1_i194 = 0; c1_i194 < 7; c1_i194++) {
    c1_b_z.DATA.status.accelSets.accel4way[c1_i194] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_z)[8])[5584])[72])[0])[c1_i194];
  }

  c1_b_z.DATA.status.accelSets.vertAccelThres = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)
        [8])[5584])[72])[8];
  c1_b_z.DATA.status.accelSets.yawRateCon = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)
        [8])[5584])[72])[12];
  c1_b_z.DATA.status.accelSets.hozAccelCon = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)
        [8])[5584])[72])[16];
  c1_b_z.DATA.status.accelSets.confidenceSet.accelConfidence.yawRate = *(int32_T
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelConfidence *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])
           [5584])[72])[24])[0])[0];
  c1_b_z.DATA.status.accelSets.confidenceSet.accelConfidence.acceleration =
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelConfidence *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)
        [8])[5584])[72])[24])[0])[4];
  c1_b_z.DATA.status.accelSets.confidenceSet.accelConfidence.steeringWheelAngle =
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelConfidence *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)
        [8])[5584])[72])[24])[0])[8];
  c1_b_z.DATA.status.accelSets.confidenceSet.speedConfidence = *(int8_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
         &((char_T *)chartInstance->c1_z)[8])[5584])[72])[24])[16];
  c1_b_z.DATA.status.accelSets.confidenceSet.timeConfidence = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
         &((char_T *)chartInstance->c1_z)[8])[5584])[72])[24])[20];
  c1_b_z.DATA.status.accelSets.confidenceSet.posConfidence = *(int8_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
         &((char_T *)chartInstance->c1_z)[8])[5584])[72])[24])[24];
  c1_b_z.DATA.status.accelSets.confidenceSet.steerConfidence = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
         &((char_T *)chartInstance->c1_z)[8])[5584])[72])[24])[28];
  c1_b_z.DATA.status.accelSets.confidenceSet.throttleConfidence = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
         &((char_T *)chartInstance->c1_z)[8])[5584])[72])[24])[32];
  c1_b_z.DATA.status.object.obDist = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])
    [5584])[136])[0];
  c1_b_z.DATA.status.object.obDirect = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])
    [5584])[136])[4];
  c1_b_z.DATA.status.object.dateTime.year = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])[5584])
    [136])[8])[0];
  c1_b_z.DATA.status.object.dateTime.month = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])[5584])
    [136])[8])[4];
  c1_b_z.DATA.status.object.dateTime.day = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])[5584])
    [136])[8])[8];
  c1_b_z.DATA.status.object.dateTime.hour = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])[5584])
    [136])[8])[12];
  c1_b_z.DATA.status.object.dateTime.minute = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])[5584])
    [136])[8])[16];
  c1_b_z.DATA.status.object.dateTime.second = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])[5584])
    [136])[8])[20];
  c1_b_z.DATA.status.fullPos.utcTime.year = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])[5584])
    [168])[0])[0];
  c1_b_z.DATA.status.fullPos.utcTime.month = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])[5584])
    [168])[0])[4];
  c1_b_z.DATA.status.fullPos.utcTime.day = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])[5584])
    [168])[0])[8];
  c1_b_z.DATA.status.fullPos.utcTime.hour = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])[5584])
    [168])[0])[12];
  c1_b_z.DATA.status.fullPos.utcTime.minute = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])[5584])
    [168])[0])[16];
  c1_b_z.DATA.status.fullPos.utcTime.second = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])[5584])
    [168])[0])[20];
  c1_b_z.DATA.status.fullPos.longitude = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])
    [5584])[168])[24];
  c1_b_z.DATA.status.fullPos.latitude = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])
    [5584])[168])[28];
  for (c1_i195 = 0; c1_i195 < 2; c1_i195++) {
    c1_b_z.DATA.status.fullPos.elevation[c1_i195] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
      chartInstance->c1_z)[8])[5584])[168])[32])[c1_i195];
  }

  c1_b_z.DATA.status.fullPos.heading = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])
    [5584])[168])[36];
  for (c1_i196 = 0; c1_i196 < 2; c1_i196++) {
    c1_b_z.DATA.status.fullPos.speed[c1_i196] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
      chartInstance->c1_z)[8])[5584])[168])[40])[c1_i196];
  }

  for (c1_i197 = 0; c1_i197 < 4; c1_i197++) {
    c1_b_z.DATA.status.fullPos.posAccuracy[c1_i197] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
      chartInstance->c1_z)[8])[5584])[168])[42])[c1_i197];
  }

  c1_b_z.DATA.status.fullPos.timeConfidence = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])
    [5584])[168])[48];
  c1_b_z.DATA.status.fullPos.posConfidence = *(int8_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])
    [5584])[168])[52];
  c1_b_z.DATA.status.fullPos.speedConfidence = *(int8_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])
    [5584])[168])[53];
  c1_b_z.DATA.status.throttlePos = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[5584])[224];
  c1_b_z.DATA.status.speedHeadC = *(int8_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[5584])[228];
  c1_b_z.DATA.status.speedC = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[5584])[232];
  c1_b_z.DATA.status.vehicleData.height = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[5584])[240])[0];
  c1_b_z.DATA.status.vehicleData.bumpers.frnt = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_bumpers *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[5584])[240])[8])[0];
  c1_b_z.DATA.status.vehicleData.bumpers.rear = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_bumpers *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[5584])[240])[8])[4];
  c1_b_z.DATA.status.vehicleData.mass = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[5584])[240])[16];
  c1_b_z.DATA.status.vehicleData.trailerWeight = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[5584])[240])[20];
  c1_b_z.DATA.status.vehicleData.type = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[5584])[240])[24];
  for (c1_i198 = 0; c1_i198 < 63; c1_i198++) {
    c1_b_z.DATA.status.vehicleIdent.name[c1_i198] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_z)[8])[5584])[272])[0])[c1_i198];
  }

  for (c1_i199 = 0; c1_i199 < 17; c1_i199++) {
    c1_b_z.DATA.status.vehicleIdent.vin[c1_i199] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_z)[8])[5584])[272])[63])[c1_i199];
  }

  for (c1_i200 = 0; c1_i200 < 32; c1_i200++) {
    c1_b_z.DATA.status.vehicleIdent.ownerCode[c1_i200] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_z)[8])[5584])[272])[80])[c1_i200];
  }

  for (c1_i201 = 0; c1_i201 < 4; c1_i201++) {
    c1_b_z.DATA.status.vehicleIdent.id[c1_i201] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_z)[8])[5584])[272])[112])[c1_i201];
  }

  c1_b_z.DATA.status.vehicleIdent.vehicleType = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[5584])[272])[116];
  c1_b_z.DATA.status.vehicleIdent.vehicleClass.vGroup = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleClass *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[5584])[272])[120])[0];
  c1_b_z.DATA.status.vehicleIdent.vehicleClass.rGroup = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleClass *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[5584])[272])[120])[4];
  c1_b_z.DATA.status.vehicleIdent.vehicleClass.rEquip = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleClass *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[5584])[272])[120])[8];
  for (c1_i202 = 0; c1_i202 < 16; c1_i202++) {
    c1_b_z.DATA.status.j1939data.tires[c1_i202].location = *(int32_T *)&((char_T
      *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_z)[8])[5584])[408])[0])[32 * (int32_T)
      c1_i202])[0];
    c1_b_z.DATA.status.j1939data.tires[c1_i202].pressure = *(int32_T *)&((char_T
      *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_z)[8])[5584])[408])[0])[32 * (int32_T)
      c1_i202])[4];
    c1_b_z.DATA.status.j1939data.tires[c1_i202].temp = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_z)[8])[5584])[408])[0])[32 * (int32_T)
      c1_i202])[8];
    c1_b_z.DATA.status.j1939data.tires[c1_i202].wheelSensorStatus = *(int32_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])
           [5584])[408])[0])[32 * (int32_T)c1_i202])[12];
    c1_b_z.DATA.status.j1939data.tires[c1_i202].wheelEndElectFault = *(int32_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])
           [5584])[408])[0])[32 * (int32_T)c1_i202])[16];
    c1_b_z.DATA.status.j1939data.tires[c1_i202].leakageRate = *(int32_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])
           [5584])[408])[0])[32 * (int32_T)c1_i202])[20];
    c1_b_z.DATA.status.j1939data.tires[c1_i202].detection = *(int32_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)[8])
           [5584])[408])[0])[32 * (int32_T)c1_i202])[24];
  }

  for (c1_i203 = 0; c1_i203 < 16; c1_i203++) {
    c1_b_z.DATA.status.j1939data.axle[c1_i203].location = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_axle *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_axle *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_z)[8])[5584])[408])[512])[8 * (int32_T)
      c1_i203])[0];
    c1_b_z.DATA.status.j1939data.axle[c1_i203].weight = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_axle *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_axle *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_z)[8])[5584])[408])[512])[8 * (int32_T)
      c1_i203])[4];
  }

  c1_b_z.DATA.status.j1939data.trailerWeight = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)
        [8])[5584])[408])[640];
  c1_b_z.DATA.status.j1939data.cargoWeight = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)
        [8])[5584])[408])[644];
  c1_b_z.DATA.status.j1939data.steeringAxleTemperature = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)
        [8])[5584])[408])[648];
  c1_b_z.DATA.status.j1939data.driveAxleLocation = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)
        [8])[5584])[408])[652];
  c1_b_z.DATA.status.j1939data.driveAxleLiftAirPressure = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)
        [8])[5584])[408])[656];
  c1_b_z.DATA.status.j1939data.driveAxleTemperature = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)
        [8])[5584])[408])[660];
  c1_b_z.DATA.status.j1939data.driveAxleLubePressure = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)
        [8])[5584])[408])[664];
  c1_b_z.DATA.status.j1939data.steeringAxleLubePressure = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_z)
        [8])[5584])[408])[668];
  c1_b_z.DATA.status.weatherReport.isRaining = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[5584])[1080])[0];
  c1_b_z.DATA.status.weatherReport.rainRate = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[5584])[1080])[4];
  c1_b_z.DATA.status.weatherReport.precipSituation = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[5584])[1080])[8];
  c1_b_z.DATA.status.weatherReport.solarRadiation = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[5584])[1080])[12];
  c1_b_z.DATA.status.weatherReport.friction = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[5584])[1080])[16];
  c1_b_z.DATA.status.gpsStatus = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_z)[8])[5584])[1104];
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_b_u, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_b_z, 3U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_y, 4U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_c_y = c1_b_u;
  c1_c_z = c1_b_z;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c1_f_debug_family_names,
    c1_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_y, 2U, c1_b_sf_marshallOut,
    c1_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_z, 3U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_y, 4U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  c1_b_y = c1_c_z;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_c_u = c1_b_y;
  c1_d_y = c1_c_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 5U, c1_e_debug_family_names,
    c1_c_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_u, 2U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_y, 3U, c1_b_sf_marshallOut,
    c1_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_y, MAX_uint32_T,
    c1_c_sf_marshallOut, c1_b_sf_marshallIn);
  c1_b_y = c1_c_u;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  CV_SCRIPT_FCN(0, 1);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_d_u = c1_b_y.HEADER;
  c1_e_y = c1_d_y.HEADER;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 5U, c1_b_debug_family_names,
    c1_d_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_u, 2U, c1_d_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_y, 3U, c1_d_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_y.HEADER, MAX_uint32_T,
    c1_d_sf_marshallOut, c1_c_sf_marshallIn);
  c1_b_y.HEADER = c1_d_u;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  CV_SCRIPT_FCN(0, 2);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 13);
  c1_b_y.HEADER.valid = c1_e_y.valid;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -13);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  c1_e_u = c1_b_y.DATA;
  c1_f_y = c1_d_y.DATA;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 5U, c1_d_debug_family_names,
    c1_e_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_u, 2U, c1_g_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_y, 3U, c1_h_sf_marshallOut,
    c1_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_y.DATA, MAX_uint32_T,
    c1_g_sf_marshallOut, c1_f_sf_marshallIn);
  c1_b_y.DATA = c1_e_u;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  CV_SCRIPT_FCN(0, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 17);
  c1_b_y.DATA.msgID = c1_f_y.msgID;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 18);
  c1_b_y.DATA.msgCnt = c1_f_y.msgCnt;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 19);
  for (c1_i204 = 0; c1_i204 < 4; c1_i204++) {
    c1_b_y.DATA.id[c1_i204] = c1_f_y.id[c1_i204];
  }

  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 20);
  c1_b_y.DATA.secMark = c1_f_y.secMark;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 21);
  c1_b_y.DATA.latitude = c1_f_y.latitude;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 22);
  c1_b_y.DATA.longitude = c1_f_y.longitude;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 23);
  for (c1_i205 = 0; c1_i205 < 2; c1_i205++) {
    c1_b_y.DATA.elev[c1_i205] = c1_f_y.elev[c1_i205];
  }

  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 24);
  for (c1_i206 = 0; c1_i206 < 4; c1_i206++) {
    c1_b_y.DATA.accuracy[c1_i206] = c1_f_y.accuracy[c1_i206];
  }

  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 25);
  for (c1_i207 = 0; c1_i207 < 2; c1_i207++) {
    c1_b_y.DATA.speed[c1_i207] = c1_f_y.speed[c1_i207];
  }

  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 26);
  c1_b_y.DATA.heading = c1_f_y.heading;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 27);
  c1_b_y.DATA.angle = c1_f_y.angle;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 28);
  for (c1_i208 = 0; c1_i208 < 7; c1_i208++) {
    c1_b_y.DATA.accelSet[c1_i208] = c1_f_y.accelSet[c1_i208];
  }

  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 29);
  for (c1_i209 = 0; c1_i209 < 2; c1_i209++) {
    c1_b_y.DATA.brakes[c1_i209] = c1_f_y.brakes[c1_i209];
  }

  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 30);
  c1_f_u = c1_b_y.DATA.size;
  c1_g_y = c1_f_y.size;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 5U, c1_c_debug_family_names,
    c1_f_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_u, 2U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_y, 3U, c1_f_sf_marshallOut,
    c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_y.DATA.size, MAX_uint32_T,
    c1_e_sf_marshallOut, c1_d_sf_marshallIn);
  c1_b_y.DATA.size = c1_f_u;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  CV_SCRIPT_FCN(0, 4);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 34);
  c1_b_y.DATA.size.width = c1_g_y.width;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 35);
  c1_b_y.DATA.size.length = c1_g_y.length;
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -35);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -30);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SWITCH(2U, 4U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -9);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -4);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -4);
  _SFD_SYMBOL_SCOPE_POP();
  *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)chartInstance->c1_y)[0])
    [0] = c1_b_y.HEADER.valid;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[0] = c1_b_y.DATA.msgID;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[4] = c1_b_y.DATA.msgCnt;
  for (c1_i210 = 0; c1_i210 < 4; c1_i210++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
       chartInstance->c1_y)[8])[8])[c1_i210] = c1_b_y.DATA.id[c1_i210];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[12] = c1_b_y.DATA.secMark;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[16] = c1_b_y.DATA.latitude;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[20] = c1_b_y.DATA.longitude;
  for (c1_i211 = 0; c1_i211 < 2; c1_i211++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
       chartInstance->c1_y)[8])[24])[c1_i211] = c1_b_y.DATA.elev[c1_i211];
  }

  for (c1_i212 = 0; c1_i212 < 4; c1_i212++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
       chartInstance->c1_y)[8])[26])[c1_i212] = c1_b_y.DATA.accuracy[c1_i212];
  }

  for (c1_i213 = 0; c1_i213 < 2; c1_i213++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
       chartInstance->c1_y)[8])[30])[c1_i213] = c1_b_y.DATA.speed[c1_i213];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[32] = c1_b_y.DATA.heading;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    chartInstance->c1_y)[8])[36] = c1_b_y.DATA.angle;
  for (c1_i214 = 0; c1_i214 < 7; c1_i214++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
       chartInstance->c1_y)[8])[37])[c1_i214] = c1_b_y.DATA.accelSet[c1_i214];
  }

  for (c1_i215 = 0; c1_i215 < 2; c1_i215++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
       chartInstance->c1_y)[8])[44])[c1_i215] = c1_b_y.DATA.brakes[c1_i215];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_size *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[48])[0] =
    c1_b_y.DATA.size.width;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_size *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[48])[4] =
    c1_b_y.DATA.size.length;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])[0] =
    c1_b_y.DATA.safetyExt.events;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[8])[0])[0])[0] =
    c1_b_y.DATA.safetyExt.pathHistory.initialPosition.utcTime.year;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[8])[0])[0])[4] =
    c1_b_y.DATA.safetyExt.pathHistory.initialPosition.utcTime.month;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[8])[0])[0])[8] =
    c1_b_y.DATA.safetyExt.pathHistory.initialPosition.utcTime.day;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[8])[0])[0])[12] =
    c1_b_y.DATA.safetyExt.pathHistory.initialPosition.utcTime.hour;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[8])[0])[0])[16] =
    c1_b_y.DATA.safetyExt.pathHistory.initialPosition.utcTime.minute;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[8])[0])[0])[20] =
    c1_b_y.DATA.safetyExt.pathHistory.initialPosition.utcTime.second;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[8])[0])[24] =
    c1_b_y.DATA.safetyExt.pathHistory.initialPosition.longitude;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[8])[0])[28] =
    c1_b_y.DATA.safetyExt.pathHistory.initialPosition.latitude;
  for (c1_i216 = 0; c1_i216 < 2; c1_i216++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
       [8])[0])[32])[c1_i216] =
      c1_b_y.DATA.safetyExt.pathHistory.initialPosition.elevation[c1_i216];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[8])[0])[36] =
    c1_b_y.DATA.safetyExt.pathHistory.initialPosition.heading;
  for (c1_i217 = 0; c1_i217 < 2; c1_i217++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
       [8])[0])[40])[c1_i217] =
      c1_b_y.DATA.safetyExt.pathHistory.initialPosition.speed[c1_i217];
  }

  for (c1_i218 = 0; c1_i218 < 4; c1_i218++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
       [8])[0])[42])[c1_i218] =
      c1_b_y.DATA.safetyExt.pathHistory.initialPosition.posAccuracy[c1_i218];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[8])[0])[48] =
    c1_b_y.DATA.safetyExt.pathHistory.initialPosition.timeConfidence;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[8])[0])[52] =
    c1_b_y.DATA.safetyExt.pathHistory.initialPosition.posConfidence;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[8])[0])[53] =
    c1_b_y.DATA.safetyExt.pathHistory.initialPosition.speedConfidence;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[8])[56] =
    c1_b_y.DATA.safetyExt.pathHistory.currGPSstatus;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[8])[60] =
    c1_b_y.DATA.safetyExt.pathHistory.itemCnt;
  for (c1_i219 = 0; c1_i219 < 23; c1_i219++) {
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                  &((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                    &((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[8])[64])[0])[32 * (int32_T)
                  c1_i219])[0] =
      c1_b_y.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c1_i219]
      .latOffset;
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                  &((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                    &((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[8])[64])[0])[32 * (int32_T)
                  c1_i219])[4] =
      c1_b_y.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c1_i219]
      .longOffset;
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                  &((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                    &((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[8])[64])[0])[32 * (int32_T)
                  c1_i219])[8] =
      c1_b_y.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c1_i219]
      .elevationOffset;
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                  &((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                    &((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[8])[64])[0])[32 * (int32_T)
                  c1_i219])[12] =
      c1_b_y.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c1_i219]
      .timeOffset;
    for (c1_i222 = 0; c1_i222 < 4; c1_i222++) {
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                   &((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                     &((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
            [56])[8])[64])[0])[32 * (int32_T)c1_i219])[16])[c1_i222] =
        c1_b_y.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c1_i219]
        .posAccuracy[c1_i222];
    }

    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                  &((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                    &((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)chartInstance->c1_y)[8])[56])[8])[64])[0])[32 * (int32_T)
                  c1_i219])[20] =
      c1_b_y.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c1_i219]
      .heading;
    for (c1_i224 = 0; c1_i224 < 2; c1_i224++) {
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                   &((char_T *)(PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)
                     &((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
            [56])[8])[64])[0])[32 * (int32_T)c1_i219])[24])[c1_i224] =
        c1_b_y.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c1_i219]
        .speed[c1_i224];
    }
  }

  for (c1_i220 = 0; c1_i220 < 345; c1_i220++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
       [8])[64])[736])[c1_i220] =
      c1_b_y.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_02[c1_i220];
  }

  for (c1_i221 = 0; c1_i221 < 276; c1_i221++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
       [8])[64])[1081])[c1_i221] =
      c1_b_y.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_03[c1_i221];
  }

  for (c1_i223 = 0; c1_i223 < 184; c1_i223++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
       [8])[64])[1357])[c1_i223] =
      c1_b_y.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_04[c1_i223];
  }

  for (c1_i225 = 0; c1_i225 < 230; c1_i225++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
       [8])[64])[1541])[c1_i225] =
      c1_b_y.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_05[c1_i225];
  }

  for (c1_i226 = 0; c1_i226 < 138; c1_i226++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
       [8])[64])[1771])[c1_i226] =
      c1_b_y.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_06[c1_i226];
  }

  for (c1_i227 = 0; c1_i227 < 242; c1_i227++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
       [8])[64])[1909])[c1_i227] =
      c1_b_y.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_07[c1_i227];
  }

  for (c1_i228 = 0; c1_i228 < 161; c1_i228++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
       [8])[64])[2151])[c1_i228] =
      c1_b_y.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_08[c1_i228];
  }

  for (c1_i229 = 0; c1_i229 < 196; c1_i229++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
       [8])[64])[2312])[c1_i229] =
      c1_b_y.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_09[c1_i229];
  }

  for (c1_i230 = 0; c1_i230 < 104; c1_i230++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
       [8])[64])[2508])[c1_i230] =
      c1_b_y.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_10[c1_i230];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathPrediction *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2688])[0] =
    c1_b_y.DATA.safetyExt.pathPrediction.radiusOfCurve;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_pathPrediction *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2688])[4] =
    c1_b_y.DATA.safetyExt.pathPrediction.confidence;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2696])[0])[0])[0] =
    c1_b_y.DATA.safetyExt.theRTCM.anchorPoint.utcTime.year;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2696])[0])[0])[4] =
    c1_b_y.DATA.safetyExt.theRTCM.anchorPoint.utcTime.month;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2696])[0])[0])[8] =
    c1_b_y.DATA.safetyExt.theRTCM.anchorPoint.utcTime.day;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2696])[0])[0])[12] =
    c1_b_y.DATA.safetyExt.theRTCM.anchorPoint.utcTime.hour;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2696])[0])[0])[16] =
    c1_b_y.DATA.safetyExt.theRTCM.anchorPoint.utcTime.minute;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2696])[0])[0])[20] =
    c1_b_y.DATA.safetyExt.theRTCM.anchorPoint.utcTime.second;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2696])[0])[24] =
    c1_b_y.DATA.safetyExt.theRTCM.anchorPoint.longitude;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2696])[0])[28] =
    c1_b_y.DATA.safetyExt.theRTCM.anchorPoint.latitude;
  for (c1_i231 = 0; c1_i231 < 2; c1_i231++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
       [2696])[0])[32])[c1_i231] =
      c1_b_y.DATA.safetyExt.theRTCM.anchorPoint.elevation[c1_i231];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2696])[0])[36] =
    c1_b_y.DATA.safetyExt.theRTCM.anchorPoint.heading;
  for (c1_i232 = 0; c1_i232 < 2; c1_i232++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
       [2696])[0])[40])[c1_i232] =
      c1_b_y.DATA.safetyExt.theRTCM.anchorPoint.speed[c1_i232];
  }

  for (c1_i233 = 0; c1_i233 < 4; c1_i233++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
       [2696])[0])[42])[c1_i233] =
      c1_b_y.DATA.safetyExt.theRTCM.anchorPoint.posAccuracy[c1_i233];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2696])[0])[48] =
    c1_b_y.DATA.safetyExt.theRTCM.anchorPoint.timeConfidence;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2696])[0])[52] =
    c1_b_y.DATA.safetyExt.theRTCM.anchorPoint.posConfidence;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[56])[2696])[0])[53] =
    c1_b_y.DATA.safetyExt.theRTCM.anchorPoint.speedConfidence;
  for (c1_i234 = 0; c1_i234 < 5; c1_i234++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[56])[c1_i234] =
      c1_b_y.DATA.safetyExt.theRTCM.rtcmHeader[c1_i234];
  }

  for (c1_i235 = 0; c1_i235 < 124; c1_i235++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[61])[c1_i235] =
      c1_b_y.DATA.safetyExt.theRTCM.msg1001[c1_i235];
  }

  for (c1_i236 = 0; c1_i236 < 156; c1_i236++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[185])[c1_i236] =
      c1_b_y.DATA.safetyExt.theRTCM.msg1002[c1_i236];
  }

  for (c1_i237 = 0; c1_i237 < 210; c1_i237++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[341])[c1_i237] =
      c1_b_y.DATA.safetyExt.theRTCM.msg1003[c1_i237];
  }

  for (c1_i238 = 0; c1_i238 < 258; c1_i238++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[551])[c1_i238] =
      c1_b_y.DATA.safetyExt.theRTCM.msg1004[c1_i238];
  }

  for (c1_i239 = 0; c1_i239 < 19; c1_i239++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[809])[c1_i239] =
      c1_b_y.DATA.safetyExt.theRTCM.msg1005[c1_i239];
  }

  for (c1_i240 = 0; c1_i240 < 21; c1_i240++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[828])[c1_i240] =
      c1_b_y.DATA.safetyExt.theRTCM.msg1006[c1_i240];
  }

  for (c1_i241 = 0; c1_i241 < 36; c1_i241++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[849])[c1_i241] =
      c1_b_y.DATA.safetyExt.theRTCM.msg1007[c1_i241];
  }

  for (c1_i242 = 0; c1_i242 < 68; c1_i242++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[885])[c1_i242] =
      c1_b_y.DATA.safetyExt.theRTCM.msg1008[c1_i242];
  }

  for (c1_i243 = 0; c1_i243 < 136; c1_i243++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[953])[c1_i243] =
      c1_b_y.DATA.safetyExt.theRTCM.msg1009[c1_i243];
  }

  for (c1_i244 = 0; c1_i244 < 166; c1_i244++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[1089])[c1_i244] =
      c1_b_y.DATA.safetyExt.theRTCM.msg1010[c1_i244];
  }

  for (c1_i245 = 0; c1_i245 < 222; c1_i245++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[1255])[c1_i245] =
      c1_b_y.DATA.safetyExt.theRTCM.msg1011[c1_i245];
  }

  for (c1_i246 = 0; c1_i246 < 268; c1_i246++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[1477])[c1_i246] =
      c1_b_y.DATA.safetyExt.theRTCM.msg1012[c1_i246];
  }

  for (c1_i247 = 0; c1_i247 < 27; c1_i247++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[1745])[c1_i247] =
      c1_b_y.DATA.safetyExt.theRTCM.msg1013[c1_i247];
  }

  for (c1_i248 = 0; c1_i248 < 15; c1_i248++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[1772])[c1_i248] =
      c1_b_y.DATA.safetyExt.theRTCM.msg1014[c1_i248];
  }

  for (c1_i249 = 0; c1_i249 < 69; c1_i249++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[1787])[c1_i249] =
      c1_b_y.DATA.safetyExt.theRTCM.msg1015[c1_i249];
  }

  for (c1_i250 = 0; c1_i250 < 81; c1_i250++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[1856])[c1_i250] =
      c1_b_y.DATA.safetyExt.theRTCM.msg1016[c1_i250];
  }

  for (c1_i251 = 0; c1_i251 < 115; c1_i251++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[1937])[c1_i251] =
      c1_b_y.DATA.safetyExt.theRTCM.msg1017[c1_i251];
  }

  for (c1_i252 = 0; c1_i252 < 62; c1_i252++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[2052])[c1_i252] =
      c1_b_y.DATA.safetyExt.theRTCM.msg1019[c1_i252];
  }

  for (c1_i253 = 0; c1_i253 < 45; c1_i253++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[2114])[c1_i253] =
      c1_b_y.DATA.safetyExt.theRTCM.msg1020[c1_i253];
  }

  for (c1_i254 = 0; c1_i254 < 62; c1_i254++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[2159])[c1_i254] =
      c1_b_y.DATA.safetyExt.theRTCM.msg1021[c1_i254];
  }

  for (c1_i255 = 0; c1_i255 < 75; c1_i255++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[2221])[c1_i255] =
      c1_b_y.DATA.safetyExt.theRTCM.msg1022[c1_i255];
  }

  for (c1_i256 = 0; c1_i256 < 73; c1_i256++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[2296])[c1_i256] =
      c1_b_y.DATA.safetyExt.theRTCM.msg1023[c1_i256];
  }

  for (c1_i257 = 0; c1_i257 < 74; c1_i257++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[2369])[c1_i257] =
      c1_b_y.DATA.safetyExt.theRTCM.msg1024[c1_i257];
  }

  for (c1_i258 = 0; c1_i258 < 25; c1_i258++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[2443])[c1_i258] =
      c1_b_y.DATA.safetyExt.theRTCM.msg1025[c1_i258];
  }

  for (c1_i259 = 0; c1_i259 < 30; c1_i259++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[2468])[c1_i259] =
      c1_b_y.DATA.safetyExt.theRTCM.msg1026[c1_i259];
  }

  for (c1_i260 = 0; c1_i260 < 33; c1_i260++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[2498])[c1_i260] =
      c1_b_y.DATA.safetyExt.theRTCM.msg1027[c1_i260];
  }

  for (c1_i261 = 0; c1_i261 < 69; c1_i261++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[2531])[c1_i261] =
      c1_b_y.DATA.safetyExt.theRTCM.msg1029[c1_i261];
  }

  for (c1_i262 = 0; c1_i262 < 105; c1_i262++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[2600])[c1_i262] =
      c1_b_y.DATA.safetyExt.theRTCM.msg1030[c1_i262];
  }

  for (c1_i263 = 0; c1_i263 < 107; c1_i263++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[2705])[c1_i263] =
      c1_b_y.DATA.safetyExt.theRTCM.msg1031[c1_i263];
  }

  for (c1_i264 = 0; c1_i264 < 20; c1_i264++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[56])
                 [2696])[2812])[c1_i264] =
      c1_b_y.DATA.safetyExt.theRTCM.msg1032[c1_i264];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])[0]
    = c1_b_y.DATA.status.lights;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])[4]
    = c1_b_y.DATA.status.lightBar;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[8])[0] =
    c1_b_y.DATA.status.wipers.statusFront;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[8])[4] =
    c1_b_y.DATA.status.wipers.rateFront;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[8])[8] =
    c1_b_y.DATA.status.wipers.statusRear;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[8])[12] =
    c1_b_y.DATA.status.wipers.rateRear;
  for (c1_i265 = 0; c1_i265 < 2; c1_i265++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])
      [24])[c1_i265] = c1_b_y.DATA.status.brakeStatus[c1_i265];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])[28]
    = c1_b_y.DATA.status.brakePressure;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])[32]
    = c1_b_y.DATA.status.roadFriction;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])[36]
    = c1_b_y.DATA.status.sunData;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])[40]
    = c1_b_y.DATA.status.rainData;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])[44]
    = c1_b_y.DATA.status.airTemp;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])[48]
    = c1_b_y.DATA.status.airPres;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[56])[0] =
    c1_b_y.DATA.status.steering.angle;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[56])[4] =
    c1_b_y.DATA.status.steering.confidence;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[56])[8] =
    c1_b_y.DATA.status.steering.rate;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[56])[12] =
    c1_b_y.DATA.status.steering.wheels;
  for (c1_i266 = 0; c1_i266 < 7; c1_i266++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
        &((char_T *)chartInstance->c1_y)[8])[5584])[72])[0])[c1_i266] =
      c1_b_y.DATA.status.accelSets.accel4way[c1_i266];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[72])[8] =
    c1_b_y.DATA.status.accelSets.vertAccelThres;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[72])[12] =
    c1_b_y.DATA.status.accelSets.yawRateCon;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[72])[16] =
    c1_b_y.DATA.status.accelSets.hozAccelCon;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelConfidence *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)
        [8])[5584])[72])[24])[0])[0] =
    c1_b_y.DATA.status.accelSets.confidenceSet.accelConfidence.yawRate;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelConfidence *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)
        [8])[5584])[72])[24])[0])[4] =
    c1_b_y.DATA.status.accelSets.confidenceSet.accelConfidence.acceleration;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelConfidence *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)
        [8])[5584])[72])[24])[0])[8] =
    c1_b_y.DATA.status.accelSets.confidenceSet.accelConfidence.steeringWheelAngle;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)
        [8])[5584])[72])[24])[16] =
    c1_b_y.DATA.status.accelSets.confidenceSet.speedConfidence;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)
        [8])[5584])[72])[24])[20] =
    c1_b_y.DATA.status.accelSets.confidenceSet.timeConfidence;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)
        [8])[5584])[72])[24])[24] =
    c1_b_y.DATA.status.accelSets.confidenceSet.posConfidence;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)
        [8])[5584])[72])[24])[28] =
    c1_b_y.DATA.status.accelSets.confidenceSet.steerConfidence;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)
        [8])[5584])[72])[24])[32] =
    c1_b_y.DATA.status.accelSets.confidenceSet.throttleConfidence;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[136])[0] =
    c1_b_y.DATA.status.object.obDist;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[136])[4] =
    c1_b_y.DATA.status.object.obDirect;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[136])[8])[0] = c1_b_y.DATA.status.object.dateTime.year;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[136])[8])[4] = c1_b_y.DATA.status.object.dateTime.month;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[136])[8])[8] = c1_b_y.DATA.status.object.dateTime.day;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[136])[8])[12] = c1_b_y.DATA.status.object.dateTime.hour;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[136])[8])[16] = c1_b_y.DATA.status.object.dateTime.minute;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[136])[8])[20] = c1_b_y.DATA.status.object.dateTime.second;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[168])[0])[0] = c1_b_y.DATA.status.fullPos.utcTime.year;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[168])[0])[4] = c1_b_y.DATA.status.fullPos.utcTime.month;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[168])[0])[8] = c1_b_y.DATA.status.fullPos.utcTime.day;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[168])[0])[12] = c1_b_y.DATA.status.fullPos.utcTime.hour;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[168])[0])[16] = c1_b_y.DATA.status.fullPos.utcTime.minute;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])
    [5584])[168])[0])[20] = c1_b_y.DATA.status.fullPos.utcTime.second;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[168])[24] =
    c1_b_y.DATA.status.fullPos.longitude;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[168])[28] =
    c1_b_y.DATA.status.fullPos.latitude;
  for (c1_i267 = 0; c1_i267 < 2; c1_i267++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
        &((char_T *)chartInstance->c1_y)[8])[5584])[168])[32])[c1_i267] =
      c1_b_y.DATA.status.fullPos.elevation[c1_i267];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[168])[36] =
    c1_b_y.DATA.status.fullPos.heading;
  for (c1_i268 = 0; c1_i268 < 2; c1_i268++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
        &((char_T *)chartInstance->c1_y)[8])[5584])[168])[40])[c1_i268] =
      c1_b_y.DATA.status.fullPos.speed[c1_i268];
  }

  for (c1_i269 = 0; c1_i269 < 4; c1_i269++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
        &((char_T *)chartInstance->c1_y)[8])[5584])[168])[42])[c1_i269] =
      c1_b_y.DATA.status.fullPos.posAccuracy[c1_i269];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[168])[48] =
    c1_b_y.DATA.status.fullPos.timeConfidence;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[168])[52] =
    c1_b_y.DATA.status.fullPos.posConfidence;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[168])[53] =
    c1_b_y.DATA.status.fullPos.speedConfidence;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])
    [224] = c1_b_y.DATA.status.throttlePos;
  *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])
    [228] = c1_b_y.DATA.status.speedHeadC;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])
    [232] = c1_b_y.DATA.status.speedC;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[240])[0] =
    c1_b_y.DATA.status.vehicleData.height;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_bumpers *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[240])[8])[0] =
    c1_b_y.DATA.status.vehicleData.bumpers.frnt;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_bumpers *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[240])[8])[4] =
    c1_b_y.DATA.status.vehicleData.bumpers.rear;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[240])[16] =
    c1_b_y.DATA.status.vehicleData.mass;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[240])[20] =
    c1_b_y.DATA.status.vehicleData.trailerWeight;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[240])[24] =
    c1_b_y.DATA.status.vehicleData.type;
  for (c1_i270 = 0; c1_i270 < 63; c1_i270++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
        &((char_T *)chartInstance->c1_y)[8])[5584])[272])[0])[c1_i270] =
      c1_b_y.DATA.status.vehicleIdent.name[c1_i270];
  }

  for (c1_i271 = 0; c1_i271 < 17; c1_i271++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
        &((char_T *)chartInstance->c1_y)[8])[5584])[272])[63])[c1_i271] =
      c1_b_y.DATA.status.vehicleIdent.vin[c1_i271];
  }

  for (c1_i272 = 0; c1_i272 < 32; c1_i272++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
        &((char_T *)chartInstance->c1_y)[8])[5584])[272])[80])[c1_i272] =
      c1_b_y.DATA.status.vehicleIdent.ownerCode[c1_i272];
  }

  for (c1_i273 = 0; c1_i273 < 4; c1_i273++) {
    ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
        &((char_T *)chartInstance->c1_y)[8])[5584])[272])[112])[c1_i273] =
      c1_b_y.DATA.status.vehicleIdent.id[c1_i273];
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[272])[116] =
    c1_b_y.DATA.status.vehicleIdent.vehicleType;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleClass *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[272])[120])[0] =
    c1_b_y.DATA.status.vehicleIdent.vehicleClass.vGroup;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleClass *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[272])[120])[4] =
    c1_b_y.DATA.status.vehicleIdent.vehicleClass.rGroup;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_vehicleClass *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[272])[120])[8] =
    c1_b_y.DATA.status.vehicleIdent.vehicleClass.rEquip;
  for (c1_i274 = 0; c1_i274 < 16; c1_i274++) {
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_y)[8])[5584])[408])[0])[32 * (int32_T)
                  c1_i274])[0] = c1_b_y.DATA.status.j1939data.tires[c1_i274].
      location;
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_y)[8])[5584])[408])[0])[32 * (int32_T)
                  c1_i274])[4] = c1_b_y.DATA.status.j1939data.tires[c1_i274].
      pressure;
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_y)[8])[5584])[408])[0])[32 * (int32_T)
                  c1_i274])[8] = c1_b_y.DATA.status.j1939data.tires[c1_i274].
      temp;
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_y)[8])[5584])[408])[0])[32 * (int32_T)
                  c1_i274])[12] = c1_b_y.DATA.status.j1939data.tires[c1_i274].
      wheelSensorStatus;
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_y)[8])[5584])[408])[0])[32 * (int32_T)
                  c1_i274])[16] = c1_b_y.DATA.status.j1939data.tires[c1_i274].
      wheelEndElectFault;
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_y)[8])[5584])[408])[0])[32 * (int32_T)
                  c1_i274])[20] = c1_b_y.DATA.status.j1939data.tires[c1_i274].
      leakageRate;
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)chartInstance->c1_y)[8])[5584])[408])[0])[32 * (int32_T)
                  c1_i274])[24] = c1_b_y.DATA.status.j1939data.tires[c1_i274].
      detection;
  }

  for (c1_i275 = 0; c1_i275 < 16; c1_i275++) {
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_axle *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_axle *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])
      [408])[512])[8 * (int32_T)c1_i275])[0] =
      c1_b_y.DATA.status.j1939data.axle[c1_i275].location;
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_axle *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_axle *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])
      [408])[512])[8 * (int32_T)c1_i275])[4] =
      c1_b_y.DATA.status.j1939data.axle[c1_i275].weight;
  }

  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[408])[640] =
    c1_b_y.DATA.status.j1939data.trailerWeight;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[408])[644] =
    c1_b_y.DATA.status.j1939data.cargoWeight;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[408])[648] =
    c1_b_y.DATA.status.j1939data.steeringAxleTemperature;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[408])[652] =
    c1_b_y.DATA.status.j1939data.driveAxleLocation;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[408])[656] =
    c1_b_y.DATA.status.j1939data.driveAxleLiftAirPressure;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[408])[660] =
    c1_b_y.DATA.status.j1939data.driveAxleTemperature;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[408])[664] =
    c1_b_y.DATA.status.j1939data.driveAxleLubePressure;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[408])[668] =
    c1_b_y.DATA.status.j1939data.steeringAxleLubePressure;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[1080])[0] =
    c1_b_y.DATA.status.weatherReport.isRaining;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[1080])[4] =
    c1_b_y.DATA.status.weatherReport.rainRate;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[1080])[8] =
    c1_b_y.DATA.status.weatherReport.precipSituation;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[1080])[12] =
    c1_b_y.DATA.status.weatherReport.solarRadiation;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)chartInstance->c1_y)[8])[5584])[1080])[16] =
    c1_b_y.DATA.status.weatherReport.friction;
  *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)chartInstance->c1_y)[8])[5584])
    [1104] = c1_b_y.DATA.status.gpsStatus;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
}

static void mdl_start_c1_Jan22_DLforACC_cs(SFc1_Jan22_DLforACC_csInstanceStruct *
  chartInstance)
{
  chartInstance->c1_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sim_mode_is_external(chartInstance->S);
}

static void initSimStructsc1_Jan22_DLforACC_cs
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber)
{
  (void)(c1_machineNumber);
  (void)(c1_chartNumber);
  (void)(c1_instanceNumber);
  _SFD_SCRIPT_TRANSLATION(c1_chartNumber, c1_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\s2lohras\\PreScan_Experiments\\Jan22_DLforACC\\V2X_BSM_expander.m"));
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc1_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_b_u = *(real_T *)c1_inData;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_b_y, false);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_b_y;
  real_T c1_d0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_b_y = c1_d0;
  sf_mex_destroy(&c1_b_u);
  return c1_b_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargin;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_b_y;
  SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc1_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c1_nargin = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_b_y = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargin), &c1_thisId);
  sf_mex_destroy(&c1_nargin);
  *(real_T *)c1_outData = c1_b_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_emlrt_marshallOut(SFc1_Jan22_DLforACC_csInstanceStruct *
  chartInstance, const c1_PRESCAN_V2X_USER_BSM_DATA c1_b_u)
{
  const mxArray *c1_b_y;
  static const char * c1_sv9[14] = { "msgID", "msgCnt", "id", "secMark",
    "latitude", "longitude", "elev", "accuracy", "speed", "heading", "angle",
    "accelSet", "brakes", "size" };

  int32_T c1_c_u;
  const mxArray *c1_c_y = NULL;
  int32_T c1_d_u;
  const mxArray *c1_d_y = NULL;
  int32_T c1_i276;
  const mxArray *c1_e_y = NULL;
  int8_T c1_e_u[4];
  int32_T c1_f_u;
  const mxArray *c1_f_y = NULL;
  int32_T c1_g_u;
  const mxArray *c1_g_y = NULL;
  int32_T c1_h_u;
  const mxArray *c1_h_y = NULL;
  int32_T c1_i277;
  const mxArray *c1_i_y = NULL;
  int8_T c1_i_u[2];
  int32_T c1_i278;
  const mxArray *c1_j_y = NULL;
  int32_T c1_i279;
  const mxArray *c1_k_y = NULL;
  int32_T c1_j_u;
  const mxArray *c1_l_y = NULL;
  int8_T c1_k_u;
  const mxArray *c1_m_y = NULL;
  int32_T c1_i280;
  const mxArray *c1_n_y = NULL;
  int8_T c1_l_u[7];
  int32_T c1_i281;
  const mxArray *c1_o_y = NULL;
  c1_PRESCAN_V2X_USER_BSM_size c1_m_u;
  const mxArray *c1_p_y = NULL;
  int32_T c1_n_u;
  const mxArray *c1_q_y = NULL;
  int32_T c1_o_u;
  const mxArray *c1_r_y = NULL;
  (void)chartInstance;
  c1_b_y = NULL;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_createstruct("structure", 14, c1_sv9, 2, 1, 1),
                false);
  c1_c_u = c1_b_u.msgID;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_c_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "msgID", c1_c_y, 0);
  c1_d_u = c1_b_u.msgCnt;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_d_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "msgCnt", c1_d_y, 1);
  for (c1_i276 = 0; c1_i276 < 4; c1_i276++) {
    c1_e_u[c1_i276] = c1_b_u.id[c1_i276];
  }

  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_e_u, 2, 0U, 1U, 0U, 1, 4), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "id", c1_e_y, 2);
  c1_f_u = c1_b_u.secMark;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_f_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "secMark", c1_f_y, 3);
  c1_g_u = c1_b_u.latitude;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_g_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "latitude", c1_g_y, 4);
  c1_h_u = c1_b_u.longitude;
  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_h_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "longitude", c1_h_y, 5);
  for (c1_i277 = 0; c1_i277 < 2; c1_i277++) {
    c1_i_u[c1_i277] = c1_b_u.elev[c1_i277];
  }

  c1_i_y = NULL;
  sf_mex_assign(&c1_i_y, sf_mex_create("y", c1_i_u, 2, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "elev", c1_i_y, 6);
  for (c1_i278 = 0; c1_i278 < 4; c1_i278++) {
    c1_e_u[c1_i278] = c1_b_u.accuracy[c1_i278];
  }

  c1_j_y = NULL;
  sf_mex_assign(&c1_j_y, sf_mex_create("y", c1_e_u, 2, 0U, 1U, 0U, 1, 4), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "accuracy", c1_j_y, 7);
  for (c1_i279 = 0; c1_i279 < 2; c1_i279++) {
    c1_i_u[c1_i279] = c1_b_u.speed[c1_i279];
  }

  c1_k_y = NULL;
  sf_mex_assign(&c1_k_y, sf_mex_create("y", c1_i_u, 2, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "speed", c1_k_y, 8);
  c1_j_u = c1_b_u.heading;
  c1_l_y = NULL;
  sf_mex_assign(&c1_l_y, sf_mex_create("y", &c1_j_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "heading", c1_l_y, 9);
  c1_k_u = c1_b_u.angle;
  c1_m_y = NULL;
  sf_mex_assign(&c1_m_y, sf_mex_create("y", &c1_k_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "angle", c1_m_y, 10);
  for (c1_i280 = 0; c1_i280 < 7; c1_i280++) {
    c1_l_u[c1_i280] = c1_b_u.accelSet[c1_i280];
  }

  c1_n_y = NULL;
  sf_mex_assign(&c1_n_y, sf_mex_create("y", c1_l_u, 2, 0U, 1U, 0U, 1, 7), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "accelSet", c1_n_y, 11);
  for (c1_i281 = 0; c1_i281 < 2; c1_i281++) {
    c1_i_u[c1_i281] = c1_b_u.brakes[c1_i281];
  }

  c1_o_y = NULL;
  sf_mex_assign(&c1_o_y, sf_mex_create("y", c1_i_u, 2, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "brakes", c1_o_y, 12);
  c1_m_u = c1_b_u.size;
  c1_p_y = NULL;
  sf_mex_assign(&c1_p_y, sf_mex_createstruct("structure", 2, c1_sv1, 2, 1, 1),
                false);
  c1_n_u = c1_m_u.width;
  c1_q_y = NULL;
  sf_mex_assign(&c1_q_y, sf_mex_create("y", &c1_n_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_p_y, 0, "width", c1_q_y, 0);
  c1_o_u = c1_m_u.length;
  c1_r_y = NULL;
  sf_mex_assign(&c1_r_y, sf_mex_create("y", &c1_o_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_p_y, 0, "length", c1_r_y, 1);
  sf_mex_setfieldbynum(c1_b_y, 0, "size", c1_p_y, 13);
  return c1_b_y;
}

static const mxArray *c1_b_emlrt_marshallOut
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const int32_T c1_b_u)
{
  const mxArray *c1_b_y = NULL;
  (void)chartInstance;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 6, 0U, 0U, 0U, 0), false);
  return c1_b_y;
}

static const mxArray *c1_c_emlrt_marshallOut
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const int8_T c1_b_u[2])
{
  const mxArray *c1_b_y = NULL;
  (void)chartInstance;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 2, 0U, 1U, 0U, 1, 2), false);
  return c1_b_y;
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  c1_PRESCAN_V2X_USER_BSM_MESSAGE c1_b_u;
  const mxArray *c1_b_y = NULL;
  PRESCAN_HEADER c1_c_u;
  const mxArray *c1_c_y = NULL;
  static const char * c1_sv10[1] = { "valid" };

  boolean_T c1_d_u;
  const mxArray *c1_d_y = NULL;
  SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc1_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_b_u = *(c1_PRESCAN_V2X_USER_BSM_MESSAGE *)c1_inData;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_createstruct("structure", 2, c1_sv0, 2, 1, 1),
                false);
  c1_c_u = c1_b_u.HEADER;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_createstruct("structure", 1, c1_sv10, 2, 1, 1),
                false);
  c1_d_u = c1_c_u.valid;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_d_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_c_y, 0, "valid", c1_d_y, 0);
  sf_mex_setfieldbynum(c1_b_y, 0, "HEADER", c1_c_y, 0);
  sf_mex_setfieldbynum(c1_b_y, 0, "DATA", c1_emlrt_marshallOut(chartInstance,
    c1_b_u.DATA), 1);
  sf_mex_assign(&c1_mxArrayOutData, c1_b_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_d_emlrt_marshallOut
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const
   PRESCAN_V2X_FIXED_BSM_DATA *c1_b_u)
{
  const mxArray *c1_b_y;
  static const char * c1_sv11[16] = { "msgID", "msgCnt", "id", "secMark",
    "latitude", "longitude", "elev", "accuracy", "speed", "heading", "angle",
    "accelSet", "brakes", "size", "safetyExt", "status" };

  int32_T c1_c_u;
  const mxArray *c1_c_y = NULL;
  int32_T c1_d_u;
  const mxArray *c1_d_y = NULL;
  int32_T c1_i282;
  const mxArray *c1_e_y = NULL;
  int8_T c1_e_u[4];
  int32_T c1_f_u;
  const mxArray *c1_f_y = NULL;
  int32_T c1_g_u;
  const mxArray *c1_g_y = NULL;
  int32_T c1_h_u;
  const mxArray *c1_h_y = NULL;
  int32_T c1_i283;
  const mxArray *c1_i_y = NULL;
  int8_T c1_i_u[2];
  int32_T c1_i284;
  const mxArray *c1_j_y = NULL;
  int32_T c1_i285;
  const mxArray *c1_k_y = NULL;
  int32_T c1_j_u;
  const mxArray *c1_l_y = NULL;
  int8_T c1_k_u;
  const mxArray *c1_m_y = NULL;
  int32_T c1_i286;
  const mxArray *c1_n_y = NULL;
  int8_T c1_l_u[7];
  int32_T c1_i287;
  const mxArray *c1_o_y = NULL;
  PRESCAN_V2X_FIXED_BSM_size c1_m_u;
  const mxArray *c1_p_y = NULL;
  int32_T c1_n_u;
  const mxArray *c1_q_y = NULL;
  int32_T c1_o_u;
  const mxArray *c1_r_y = NULL;
  c1_b_y = NULL;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_createstruct("structure", 16, c1_sv11, 2, 1, 1),
                false);
  c1_c_u = c1_b_u->msgID;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_c_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "msgID", c1_c_y, 0);
  c1_d_u = c1_b_u->msgCnt;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_d_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "msgCnt", c1_d_y, 1);
  for (c1_i282 = 0; c1_i282 < 4; c1_i282++) {
    c1_e_u[c1_i282] = c1_b_u->id[c1_i282];
  }

  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", c1_e_u, 2, 0U, 1U, 0U, 1, 4), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "id", c1_e_y, 2);
  c1_f_u = c1_b_u->secMark;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_f_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "secMark", c1_f_y, 3);
  c1_g_u = c1_b_u->latitude;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_g_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "latitude", c1_g_y, 4);
  c1_h_u = c1_b_u->longitude;
  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_h_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "longitude", c1_h_y, 5);
  for (c1_i283 = 0; c1_i283 < 2; c1_i283++) {
    c1_i_u[c1_i283] = c1_b_u->elev[c1_i283];
  }

  c1_i_y = NULL;
  sf_mex_assign(&c1_i_y, sf_mex_create("y", c1_i_u, 2, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "elev", c1_i_y, 6);
  for (c1_i284 = 0; c1_i284 < 4; c1_i284++) {
    c1_e_u[c1_i284] = c1_b_u->accuracy[c1_i284];
  }

  c1_j_y = NULL;
  sf_mex_assign(&c1_j_y, sf_mex_create("y", c1_e_u, 2, 0U, 1U, 0U, 1, 4), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "accuracy", c1_j_y, 7);
  for (c1_i285 = 0; c1_i285 < 2; c1_i285++) {
    c1_i_u[c1_i285] = c1_b_u->speed[c1_i285];
  }

  c1_k_y = NULL;
  sf_mex_assign(&c1_k_y, sf_mex_create("y", c1_i_u, 2, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "speed", c1_k_y, 8);
  c1_j_u = c1_b_u->heading;
  c1_l_y = NULL;
  sf_mex_assign(&c1_l_y, sf_mex_create("y", &c1_j_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "heading", c1_l_y, 9);
  c1_k_u = c1_b_u->angle;
  c1_m_y = NULL;
  sf_mex_assign(&c1_m_y, sf_mex_create("y", &c1_k_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "angle", c1_m_y, 10);
  for (c1_i286 = 0; c1_i286 < 7; c1_i286++) {
    c1_l_u[c1_i286] = c1_b_u->accelSet[c1_i286];
  }

  c1_n_y = NULL;
  sf_mex_assign(&c1_n_y, sf_mex_create("y", c1_l_u, 2, 0U, 1U, 0U, 1, 7), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "accelSet", c1_n_y, 11);
  for (c1_i287 = 0; c1_i287 < 2; c1_i287++) {
    c1_i_u[c1_i287] = c1_b_u->brakes[c1_i287];
  }

  c1_o_y = NULL;
  sf_mex_assign(&c1_o_y, sf_mex_create("y", c1_i_u, 2, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "brakes", c1_o_y, 12);
  c1_m_u = c1_b_u->size;
  c1_p_y = NULL;
  sf_mex_assign(&c1_p_y, sf_mex_createstruct("structure", 2, c1_sv1, 2, 1, 1),
                false);
  c1_n_u = c1_m_u.width;
  c1_q_y = NULL;
  sf_mex_assign(&c1_q_y, sf_mex_create("y", &c1_n_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_p_y, 0, "width", c1_q_y, 0);
  c1_o_u = c1_m_u.length;
  c1_r_y = NULL;
  sf_mex_assign(&c1_r_y, sf_mex_create("y", &c1_o_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_p_y, 0, "length", c1_r_y, 1);
  sf_mex_setfieldbynum(c1_b_y, 0, "size", c1_p_y, 13);
  sf_mex_setfieldbynum(c1_b_y, 0, "safetyExt", c1_e_emlrt_marshallOut
                       (chartInstance, &c1_b_u->safetyExt), 14);
  sf_mex_setfieldbynum(c1_b_y, 0, "status", c1_g_emlrt_marshallOut(chartInstance,
    &c1_b_u->status), 15);
  return c1_b_y;
}

static const mxArray *c1_e_emlrt_marshallOut
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const
   PRESCAN_V2X_FIXED_BSM_safetyExt *c1_b_u)
{
  const mxArray *c1_b_y;
  static const char * c1_sv12[4] = { "events", "pathHistory", "pathPrediction",
    "theRTCM" };

  int32_T c1_c_u;
  const mxArray *c1_c_y = NULL;
  PRESCAN_V2X_FIXED_BSM_pathHistory c1_d_u;
  const mxArray *c1_d_y = NULL;
  static const char * c1_sv13[4] = { "initialPosition", "currGPSstatus",
    "itemCnt", "crumbData" };

  PRESCAN_V2X_FIXED_BSM_initialPosition c1_e_u;
  const mxArray *c1_e_y = NULL;
  int32_T c1_f_u;
  const mxArray *c1_f_y = NULL;
  int32_T c1_g_u;
  const mxArray *c1_g_y = NULL;
  int32_T c1_i288;
  const mxArray *c1_h_y = NULL;
  int8_T c1_h_u[2];
  int32_T c1_i_u;
  const mxArray *c1_i_y = NULL;
  int32_T c1_i289;
  const mxArray *c1_j_y = NULL;
  int32_T c1_i290;
  const mxArray *c1_k_y = NULL;
  int8_T c1_j_u[4];
  int32_T c1_k_u;
  const mxArray *c1_l_y = NULL;
  int8_T c1_l_u;
  const mxArray *c1_m_y = NULL;
  int8_T c1_m_u;
  const mxArray *c1_n_y = NULL;
  int32_T c1_n_u;
  const mxArray *c1_o_y = NULL;
  int32_T c1_o_u;
  const mxArray *c1_p_y = NULL;
  PRESCAN_V2X_FIXED_BSM_crumbData c1_p_u;
  const mxArray *c1_q_y = NULL;
  static const char * c1_sv14[10] = { "pathHistoryPointSets_01",
    "pathHistoryPointSets_02", "pathHistoryPointSets_03",
    "pathHistoryPointSets_04", "pathHistoryPointSets_05",
    "pathHistoryPointSets_06", "pathHistoryPointSets_07",
    "pathHistoryPointSets_08", "pathHistoryPointSets_09",
    "pathHistoryPointSets_10" };

  int32_T c1_i291;
  const mxArray *c1_r_y = NULL;
  PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 c1_q_u[23];
  int32_T c1_iv0[1];
  static const char * c1_sv15[7] = { "latOffset", "longOffset",
    "elevationOffset", "timeOffset", "posAccuracy", "heading", "speed" };

  int32_T c1_i292;
  const PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *c1_r2;
  int32_T c1_i293;
  int32_T c1_r_u;
  const mxArray *c1_s_y = NULL;
  const mxArray *c1_t_y = NULL;
  int8_T c1_s_u[345];
  int32_T c1_t_u;
  const mxArray *c1_u_y = NULL;
  int32_T c1_i294;
  int32_T c1_u_u;
  const mxArray *c1_v_y = NULL;
  int8_T c1_v_u[276];
  const mxArray *c1_w_y = NULL;
  int32_T c1_i295;
  int32_T c1_w_u;
  const mxArray *c1_x_y = NULL;
  const mxArray *c1_y_y = NULL;
  int8_T c1_x_u[184];
  int32_T c1_i296;
  int32_T c1_i297;
  const mxArray *c1_ab_y = NULL;
  const mxArray *c1_bb_y = NULL;
  int8_T c1_y_u[230];
  int32_T c1_ab_u;
  const mxArray *c1_cb_y = NULL;
  int32_T c1_i298;
  int32_T c1_i299;
  const mxArray *c1_db_y = NULL;
  int8_T c1_bb_u[138];
  const mxArray *c1_eb_y = NULL;
  int32_T c1_i300;
  const mxArray *c1_fb_y = NULL;
  int8_T c1_cb_u[242];
  int32_T c1_i301;
  const mxArray *c1_gb_y = NULL;
  int8_T c1_db_u[161];
  int32_T c1_i302;
  const mxArray *c1_hb_y = NULL;
  int8_T c1_eb_u[196];
  int32_T c1_i303;
  const mxArray *c1_ib_y = NULL;
  int8_T c1_fb_u[104];
  PRESCAN_V2X_FIXED_BSM_pathPrediction c1_gb_u;
  const mxArray *c1_jb_y = NULL;
  static const char * c1_sv16[2] = { "radiusOfCurve", "confidence" };

  int32_T c1_hb_u;
  const mxArray *c1_kb_y = NULL;
  int32_T c1_ib_u;
  const mxArray *c1_lb_y = NULL;
  PRESCAN_V2X_FIXED_BSM_theRTCM c1_jb_u;
  const mxArray *c1_mb_y = NULL;
  static const char * c1_sv17[32] = { "anchorPoint", "rtcmHeader", "msg1001",
    "msg1002", "msg1003", "msg1004", "msg1005", "msg1006", "msg1007", "msg1008",
    "msg1009", "msg1010", "msg1011", "msg1012", "msg1013", "msg1014", "msg1015",
    "msg1016", "msg1017", "msg1019", "msg1020", "msg1021", "msg1022", "msg1023",
    "msg1024", "msg1025", "msg1026", "msg1027", "msg1029", "msg1030", "msg1031",
    "msg1032" };

  PRESCAN_V2X_FIXED_BSM_anchorPoint c1_kb_u;
  const mxArray *c1_nb_y = NULL;
  int32_T c1_lb_u;
  const mxArray *c1_ob_y = NULL;
  int32_T c1_mb_u;
  const mxArray *c1_pb_y = NULL;
  int32_T c1_i304;
  const mxArray *c1_qb_y = NULL;
  int32_T c1_nb_u;
  const mxArray *c1_rb_y = NULL;
  int32_T c1_i305;
  const mxArray *c1_sb_y = NULL;
  int32_T c1_i306;
  const mxArray *c1_tb_y = NULL;
  int32_T c1_ob_u;
  const mxArray *c1_ub_y = NULL;
  int8_T c1_pb_u;
  const mxArray *c1_vb_y = NULL;
  int8_T c1_qb_u;
  const mxArray *c1_wb_y = NULL;
  int32_T c1_i307;
  const mxArray *c1_xb_y = NULL;
  int8_T c1_rb_u[5];
  int32_T c1_i308;
  const mxArray *c1_yb_y = NULL;
  int8_T c1_sb_u[124];
  int32_T c1_i309;
  const mxArray *c1_ac_y = NULL;
  int8_T c1_tb_u[156];
  int32_T c1_i310;
  const mxArray *c1_bc_y = NULL;
  int8_T c1_ub_u[210];
  int32_T c1_i311;
  const mxArray *c1_cc_y = NULL;
  int8_T c1_vb_u[258];
  int32_T c1_i312;
  const mxArray *c1_dc_y = NULL;
  int8_T c1_wb_u[19];
  int32_T c1_i313;
  const mxArray *c1_ec_y = NULL;
  int8_T c1_xb_u[21];
  int32_T c1_i314;
  const mxArray *c1_fc_y = NULL;
  int8_T c1_yb_u[36];
  int32_T c1_i315;
  const mxArray *c1_gc_y = NULL;
  int8_T c1_ac_u[68];
  int32_T c1_i316;
  const mxArray *c1_hc_y = NULL;
  int8_T c1_bc_u[136];
  int32_T c1_i317;
  const mxArray *c1_ic_y = NULL;
  int8_T c1_cc_u[166];
  int32_T c1_i318;
  const mxArray *c1_jc_y = NULL;
  int8_T c1_dc_u[222];
  int32_T c1_i319;
  const mxArray *c1_kc_y = NULL;
  int8_T c1_ec_u[268];
  int32_T c1_i320;
  const mxArray *c1_lc_y = NULL;
  int8_T c1_fc_u[27];
  int32_T c1_i321;
  const mxArray *c1_mc_y = NULL;
  int8_T c1_gc_u[15];
  int32_T c1_i322;
  const mxArray *c1_nc_y = NULL;
  int8_T c1_hc_u[69];
  int32_T c1_i323;
  const mxArray *c1_oc_y = NULL;
  int8_T c1_ic_u[81];
  int32_T c1_i324;
  const mxArray *c1_pc_y = NULL;
  int8_T c1_jc_u[115];
  int32_T c1_i325;
  const mxArray *c1_qc_y = NULL;
  int8_T c1_kc_u[62];
  int32_T c1_i326;
  const mxArray *c1_rc_y = NULL;
  int8_T c1_lc_u[45];
  int32_T c1_i327;
  const mxArray *c1_sc_y = NULL;
  int32_T c1_i328;
  const mxArray *c1_tc_y = NULL;
  int8_T c1_mc_u[75];
  int32_T c1_i329;
  const mxArray *c1_uc_y = NULL;
  int8_T c1_nc_u[73];
  int32_T c1_i330;
  const mxArray *c1_vc_y = NULL;
  int8_T c1_oc_u[74];
  int32_T c1_i331;
  const mxArray *c1_wc_y = NULL;
  int8_T c1_pc_u[25];
  int32_T c1_i332;
  const mxArray *c1_xc_y = NULL;
  int8_T c1_qc_u[30];
  int32_T c1_i333;
  const mxArray *c1_yc_y = NULL;
  int8_T c1_rc_u[33];
  int32_T c1_i334;
  const mxArray *c1_ad_y = NULL;
  int32_T c1_i335;
  const mxArray *c1_bd_y = NULL;
  int8_T c1_sc_u[105];
  int32_T c1_i336;
  const mxArray *c1_cd_y = NULL;
  int8_T c1_tc_u[107];
  int32_T c1_i337;
  const mxArray *c1_dd_y = NULL;
  int8_T c1_uc_u[20];
  c1_b_y = NULL;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_createstruct("structure", 4, c1_sv12, 2, 1, 1),
                false);
  c1_c_u = c1_b_u->events;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_c_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "events", c1_c_y, 0);
  c1_d_u = c1_b_u->pathHistory;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_createstruct("structure", 4, c1_sv13, 2, 1, 1),
                false);
  c1_e_u = c1_d_u.initialPosition;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_createstruct("structure", 10, c1_sv2, 2, 1, 1),
                false);
  sf_mex_setfieldbynum(c1_e_y, 0, "utcTime", c1_f_emlrt_marshallOut
                       (chartInstance, c1_e_u.utcTime), 0);
  c1_f_u = c1_e_u.longitude;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_f_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_e_y, 0, "longitude", c1_f_y, 1);
  c1_g_u = c1_e_u.latitude;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_g_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_e_y, 0, "latitude", c1_g_y, 2);
  for (c1_i288 = 0; c1_i288 < 2; c1_i288++) {
    c1_h_u[c1_i288] = c1_e_u.elevation[c1_i288];
  }

  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y", c1_h_u, 2, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setfieldbynum(c1_e_y, 0, "elevation", c1_h_y, 3);
  c1_i_u = c1_e_u.heading;
  c1_i_y = NULL;
  sf_mex_assign(&c1_i_y, sf_mex_create("y", &c1_i_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_e_y, 0, "heading", c1_i_y, 4);
  for (c1_i289 = 0; c1_i289 < 2; c1_i289++) {
    c1_h_u[c1_i289] = c1_e_u.speed[c1_i289];
  }

  c1_j_y = NULL;
  sf_mex_assign(&c1_j_y, sf_mex_create("y", c1_h_u, 2, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setfieldbynum(c1_e_y, 0, "speed", c1_j_y, 5);
  for (c1_i290 = 0; c1_i290 < 4; c1_i290++) {
    c1_j_u[c1_i290] = c1_e_u.posAccuracy[c1_i290];
  }

  c1_k_y = NULL;
  sf_mex_assign(&c1_k_y, sf_mex_create("y", c1_j_u, 2, 0U, 1U, 0U, 1, 4), false);
  sf_mex_setfieldbynum(c1_e_y, 0, "posAccuracy", c1_k_y, 6);
  c1_k_u = c1_e_u.timeConfidence;
  c1_l_y = NULL;
  sf_mex_assign(&c1_l_y, sf_mex_create("y", &c1_k_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_e_y, 0, "timeConfidence", c1_l_y, 7);
  c1_l_u = c1_e_u.posConfidence;
  c1_m_y = NULL;
  sf_mex_assign(&c1_m_y, sf_mex_create("y", &c1_l_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_e_y, 0, "posConfidence", c1_m_y, 8);
  c1_m_u = c1_e_u.speedConfidence;
  c1_n_y = NULL;
  sf_mex_assign(&c1_n_y, sf_mex_create("y", &c1_m_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_e_y, 0, "speedConfidence", c1_n_y, 9);
  sf_mex_setfieldbynum(c1_d_y, 0, "initialPosition", c1_e_y, 0);
  c1_n_u = c1_d_u.currGPSstatus;
  c1_o_y = NULL;
  sf_mex_assign(&c1_o_y, sf_mex_create("y", &c1_n_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_d_y, 0, "currGPSstatus", c1_o_y, 1);
  c1_o_u = c1_d_u.itemCnt;
  c1_p_y = NULL;
  sf_mex_assign(&c1_p_y, sf_mex_create("y", &c1_o_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_d_y, 0, "itemCnt", c1_p_y, 2);
  c1_p_u = c1_d_u.crumbData;
  c1_q_y = NULL;
  sf_mex_assign(&c1_q_y, sf_mex_createstruct("structure", 10, c1_sv14, 2, 1, 1),
                false);
  for (c1_i291 = 0; c1_i291 < 23; c1_i291++) {
    c1_q_u[c1_i291] = c1_p_u.pathHistoryPointSets_01[c1_i291];
  }

  c1_r_y = NULL;
  c1_iv0[0] = 23;
  sf_mex_assign(&c1_r_y, sf_mex_createstructarray("structure", 1, c1_iv0, 7,
    c1_sv15), false);
  for (c1_i292 = 0; c1_i292 < 23; c1_i292++) {
    c1_r2 = &c1_q_u[c1_i292];
    c1_r_u = c1_r2->latOffset;
    c1_s_y = NULL;
    sf_mex_assign(&c1_s_y, sf_mex_create("y", &c1_r_u, 6, 0U, 0U, 0U, 0), false);
    sf_mex_setfieldbynum(c1_r_y, c1_i292, "latOffset", c1_s_y, 0);
    c1_t_u = c1_r2->longOffset;
    c1_u_y = NULL;
    sf_mex_assign(&c1_u_y, sf_mex_create("y", &c1_t_u, 6, 0U, 0U, 0U, 0), false);
    sf_mex_setfieldbynum(c1_r_y, c1_i292, "longOffset", c1_u_y, 1);
    c1_u_u = c1_r2->elevationOffset;
    c1_w_y = NULL;
    sf_mex_assign(&c1_w_y, sf_mex_create("y", &c1_u_u, 6, 0U, 0U, 0U, 0), false);
    sf_mex_setfieldbynum(c1_r_y, c1_i292, "elevationOffset", c1_w_y, 2);
    c1_w_u = c1_r2->timeOffset;
    c1_x_y = NULL;
    sf_mex_assign(&c1_x_y, sf_mex_create("y", &c1_w_u, 6, 0U, 0U, 0U, 0), false);
    sf_mex_setfieldbynum(c1_r_y, c1_i292, "timeOffset", c1_x_y, 3);
    for (c1_i296 = 0; c1_i296 < 4; c1_i296++) {
      c1_j_u[c1_i296] = c1_r2->posAccuracy[c1_i296];
    }

    c1_ab_y = NULL;
    sf_mex_assign(&c1_ab_y, sf_mex_create("y", c1_j_u, 2, 0U, 1U, 0U, 1, 4),
                  false);
    sf_mex_setfieldbynum(c1_r_y, c1_i292, "posAccuracy", c1_ab_y, 4);
    c1_ab_u = c1_r2->heading;
    c1_cb_y = NULL;
    sf_mex_assign(&c1_cb_y, sf_mex_create("y", &c1_ab_u, 6, 0U, 0U, 0U, 0),
                  false);
    sf_mex_setfieldbynum(c1_r_y, c1_i292, "heading", c1_cb_y, 5);
    for (c1_i299 = 0; c1_i299 < 2; c1_i299++) {
      c1_h_u[c1_i299] = c1_r2->speed[c1_i299];
    }

    c1_eb_y = NULL;
    sf_mex_assign(&c1_eb_y, sf_mex_create("y", c1_h_u, 2, 0U, 1U, 0U, 1, 2),
                  false);
    sf_mex_setfieldbynum(c1_r_y, c1_i292, "speed", c1_eb_y, 6);
  }

  sf_mex_setfieldbynum(c1_q_y, 0, "pathHistoryPointSets_01", c1_r_y, 0);
  for (c1_i293 = 0; c1_i293 < 345; c1_i293++) {
    c1_s_u[c1_i293] = c1_p_u.pathHistoryPointSets_02[c1_i293];
  }

  c1_t_y = NULL;
  sf_mex_assign(&c1_t_y, sf_mex_create("y", c1_s_u, 2, 0U, 1U, 0U, 1, 345),
                false);
  sf_mex_setfieldbynum(c1_q_y, 0, "pathHistoryPointSets_02", c1_t_y, 1);
  for (c1_i294 = 0; c1_i294 < 276; c1_i294++) {
    c1_v_u[c1_i294] = c1_p_u.pathHistoryPointSets_03[c1_i294];
  }

  c1_v_y = NULL;
  sf_mex_assign(&c1_v_y, sf_mex_create("y", c1_v_u, 2, 0U, 1U, 0U, 1, 276),
                false);
  sf_mex_setfieldbynum(c1_q_y, 0, "pathHistoryPointSets_03", c1_v_y, 2);
  for (c1_i295 = 0; c1_i295 < 184; c1_i295++) {
    c1_x_u[c1_i295] = c1_p_u.pathHistoryPointSets_04[c1_i295];
  }

  c1_y_y = NULL;
  sf_mex_assign(&c1_y_y, sf_mex_create("y", c1_x_u, 2, 0U, 1U, 0U, 1, 184),
                false);
  sf_mex_setfieldbynum(c1_q_y, 0, "pathHistoryPointSets_04", c1_y_y, 3);
  for (c1_i297 = 0; c1_i297 < 230; c1_i297++) {
    c1_y_u[c1_i297] = c1_p_u.pathHistoryPointSets_05[c1_i297];
  }

  c1_bb_y = NULL;
  sf_mex_assign(&c1_bb_y, sf_mex_create("y", c1_y_u, 2, 0U, 1U, 0U, 1, 230),
                false);
  sf_mex_setfieldbynum(c1_q_y, 0, "pathHistoryPointSets_05", c1_bb_y, 4);
  for (c1_i298 = 0; c1_i298 < 138; c1_i298++) {
    c1_bb_u[c1_i298] = c1_p_u.pathHistoryPointSets_06[c1_i298];
  }

  c1_db_y = NULL;
  sf_mex_assign(&c1_db_y, sf_mex_create("y", c1_bb_u, 2, 0U, 1U, 0U, 1, 138),
                false);
  sf_mex_setfieldbynum(c1_q_y, 0, "pathHistoryPointSets_06", c1_db_y, 5);
  for (c1_i300 = 0; c1_i300 < 242; c1_i300++) {
    c1_cb_u[c1_i300] = c1_p_u.pathHistoryPointSets_07[c1_i300];
  }

  c1_fb_y = NULL;
  sf_mex_assign(&c1_fb_y, sf_mex_create("y", c1_cb_u, 2, 0U, 1U, 0U, 1, 242),
                false);
  sf_mex_setfieldbynum(c1_q_y, 0, "pathHistoryPointSets_07", c1_fb_y, 6);
  for (c1_i301 = 0; c1_i301 < 161; c1_i301++) {
    c1_db_u[c1_i301] = c1_p_u.pathHistoryPointSets_08[c1_i301];
  }

  c1_gb_y = NULL;
  sf_mex_assign(&c1_gb_y, sf_mex_create("y", c1_db_u, 2, 0U, 1U, 0U, 1, 161),
                false);
  sf_mex_setfieldbynum(c1_q_y, 0, "pathHistoryPointSets_08", c1_gb_y, 7);
  for (c1_i302 = 0; c1_i302 < 196; c1_i302++) {
    c1_eb_u[c1_i302] = c1_p_u.pathHistoryPointSets_09[c1_i302];
  }

  c1_hb_y = NULL;
  sf_mex_assign(&c1_hb_y, sf_mex_create("y", c1_eb_u, 2, 0U, 1U, 0U, 1, 196),
                false);
  sf_mex_setfieldbynum(c1_q_y, 0, "pathHistoryPointSets_09", c1_hb_y, 8);
  for (c1_i303 = 0; c1_i303 < 104; c1_i303++) {
    c1_fb_u[c1_i303] = c1_p_u.pathHistoryPointSets_10[c1_i303];
  }

  c1_ib_y = NULL;
  sf_mex_assign(&c1_ib_y, sf_mex_create("y", c1_fb_u, 2, 0U, 1U, 0U, 1, 104),
                false);
  sf_mex_setfieldbynum(c1_q_y, 0, "pathHistoryPointSets_10", c1_ib_y, 9);
  sf_mex_setfieldbynum(c1_d_y, 0, "crumbData", c1_q_y, 3);
  sf_mex_setfieldbynum(c1_b_y, 0, "pathHistory", c1_d_y, 1);
  c1_gb_u = c1_b_u->pathPrediction;
  c1_jb_y = NULL;
  sf_mex_assign(&c1_jb_y, sf_mex_createstruct("structure", 2, c1_sv16, 2, 1, 1),
                false);
  c1_hb_u = c1_gb_u.radiusOfCurve;
  c1_kb_y = NULL;
  sf_mex_assign(&c1_kb_y, sf_mex_create("y", &c1_hb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_jb_y, 0, "radiusOfCurve", c1_kb_y, 0);
  c1_ib_u = c1_gb_u.confidence;
  c1_lb_y = NULL;
  sf_mex_assign(&c1_lb_y, sf_mex_create("y", &c1_ib_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_jb_y, 0, "confidence", c1_lb_y, 1);
  sf_mex_setfieldbynum(c1_b_y, 0, "pathPrediction", c1_jb_y, 2);
  c1_jb_u = c1_b_u->theRTCM;
  c1_mb_y = NULL;
  sf_mex_assign(&c1_mb_y, sf_mex_createstruct("structure", 32, c1_sv17, 2, 1, 1),
                false);
  c1_kb_u = c1_jb_u.anchorPoint;
  c1_nb_y = NULL;
  sf_mex_assign(&c1_nb_y, sf_mex_createstruct("structure", 10, c1_sv2, 2, 1, 1),
                false);
  sf_mex_setfieldbynum(c1_nb_y, 0, "utcTime", c1_f_emlrt_marshallOut
                       (chartInstance, c1_kb_u.utcTime), 0);
  c1_lb_u = c1_kb_u.longitude;
  c1_ob_y = NULL;
  sf_mex_assign(&c1_ob_y, sf_mex_create("y", &c1_lb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_nb_y, 0, "longitude", c1_ob_y, 1);
  c1_mb_u = c1_kb_u.latitude;
  c1_pb_y = NULL;
  sf_mex_assign(&c1_pb_y, sf_mex_create("y", &c1_mb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_nb_y, 0, "latitude", c1_pb_y, 2);
  for (c1_i304 = 0; c1_i304 < 2; c1_i304++) {
    c1_h_u[c1_i304] = c1_kb_u.elevation[c1_i304];
  }

  c1_qb_y = NULL;
  sf_mex_assign(&c1_qb_y, sf_mex_create("y", c1_h_u, 2, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setfieldbynum(c1_nb_y, 0, "elevation", c1_qb_y, 3);
  c1_nb_u = c1_kb_u.heading;
  c1_rb_y = NULL;
  sf_mex_assign(&c1_rb_y, sf_mex_create("y", &c1_nb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_nb_y, 0, "heading", c1_rb_y, 4);
  for (c1_i305 = 0; c1_i305 < 2; c1_i305++) {
    c1_h_u[c1_i305] = c1_kb_u.speed[c1_i305];
  }

  c1_sb_y = NULL;
  sf_mex_assign(&c1_sb_y, sf_mex_create("y", c1_h_u, 2, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setfieldbynum(c1_nb_y, 0, "speed", c1_sb_y, 5);
  for (c1_i306 = 0; c1_i306 < 4; c1_i306++) {
    c1_j_u[c1_i306] = c1_kb_u.posAccuracy[c1_i306];
  }

  c1_tb_y = NULL;
  sf_mex_assign(&c1_tb_y, sf_mex_create("y", c1_j_u, 2, 0U, 1U, 0U, 1, 4), false);
  sf_mex_setfieldbynum(c1_nb_y, 0, "posAccuracy", c1_tb_y, 6);
  c1_ob_u = c1_kb_u.timeConfidence;
  c1_ub_y = NULL;
  sf_mex_assign(&c1_ub_y, sf_mex_create("y", &c1_ob_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_nb_y, 0, "timeConfidence", c1_ub_y, 7);
  c1_pb_u = c1_kb_u.posConfidence;
  c1_vb_y = NULL;
  sf_mex_assign(&c1_vb_y, sf_mex_create("y", &c1_pb_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_nb_y, 0, "posConfidence", c1_vb_y, 8);
  c1_qb_u = c1_kb_u.speedConfidence;
  c1_wb_y = NULL;
  sf_mex_assign(&c1_wb_y, sf_mex_create("y", &c1_qb_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_nb_y, 0, "speedConfidence", c1_wb_y, 9);
  sf_mex_setfieldbynum(c1_mb_y, 0, "anchorPoint", c1_nb_y, 0);
  for (c1_i307 = 0; c1_i307 < 5; c1_i307++) {
    c1_rb_u[c1_i307] = c1_jb_u.rtcmHeader[c1_i307];
  }

  c1_xb_y = NULL;
  sf_mex_assign(&c1_xb_y, sf_mex_create("y", c1_rb_u, 2, 0U, 1U, 0U, 1, 5),
                false);
  sf_mex_setfieldbynum(c1_mb_y, 0, "rtcmHeader", c1_xb_y, 1);
  for (c1_i308 = 0; c1_i308 < 124; c1_i308++) {
    c1_sb_u[c1_i308] = c1_jb_u.msg1001[c1_i308];
  }

  c1_yb_y = NULL;
  sf_mex_assign(&c1_yb_y, sf_mex_create("y", c1_sb_u, 2, 0U, 1U, 0U, 1, 124),
                false);
  sf_mex_setfieldbynum(c1_mb_y, 0, "msg1001", c1_yb_y, 2);
  for (c1_i309 = 0; c1_i309 < 156; c1_i309++) {
    c1_tb_u[c1_i309] = c1_jb_u.msg1002[c1_i309];
  }

  c1_ac_y = NULL;
  sf_mex_assign(&c1_ac_y, sf_mex_create("y", c1_tb_u, 2, 0U, 1U, 0U, 1, 156),
                false);
  sf_mex_setfieldbynum(c1_mb_y, 0, "msg1002", c1_ac_y, 3);
  for (c1_i310 = 0; c1_i310 < 210; c1_i310++) {
    c1_ub_u[c1_i310] = c1_jb_u.msg1003[c1_i310];
  }

  c1_bc_y = NULL;
  sf_mex_assign(&c1_bc_y, sf_mex_create("y", c1_ub_u, 2, 0U, 1U, 0U, 1, 210),
                false);
  sf_mex_setfieldbynum(c1_mb_y, 0, "msg1003", c1_bc_y, 4);
  for (c1_i311 = 0; c1_i311 < 258; c1_i311++) {
    c1_vb_u[c1_i311] = c1_jb_u.msg1004[c1_i311];
  }

  c1_cc_y = NULL;
  sf_mex_assign(&c1_cc_y, sf_mex_create("y", c1_vb_u, 2, 0U, 1U, 0U, 1, 258),
                false);
  sf_mex_setfieldbynum(c1_mb_y, 0, "msg1004", c1_cc_y, 5);
  for (c1_i312 = 0; c1_i312 < 19; c1_i312++) {
    c1_wb_u[c1_i312] = c1_jb_u.msg1005[c1_i312];
  }

  c1_dc_y = NULL;
  sf_mex_assign(&c1_dc_y, sf_mex_create("y", c1_wb_u, 2, 0U, 1U, 0U, 1, 19),
                false);
  sf_mex_setfieldbynum(c1_mb_y, 0, "msg1005", c1_dc_y, 6);
  for (c1_i313 = 0; c1_i313 < 21; c1_i313++) {
    c1_xb_u[c1_i313] = c1_jb_u.msg1006[c1_i313];
  }

  c1_ec_y = NULL;
  sf_mex_assign(&c1_ec_y, sf_mex_create("y", c1_xb_u, 2, 0U, 1U, 0U, 1, 21),
                false);
  sf_mex_setfieldbynum(c1_mb_y, 0, "msg1006", c1_ec_y, 7);
  for (c1_i314 = 0; c1_i314 < 36; c1_i314++) {
    c1_yb_u[c1_i314] = c1_jb_u.msg1007[c1_i314];
  }

  c1_fc_y = NULL;
  sf_mex_assign(&c1_fc_y, sf_mex_create("y", c1_yb_u, 2, 0U, 1U, 0U, 1, 36),
                false);
  sf_mex_setfieldbynum(c1_mb_y, 0, "msg1007", c1_fc_y, 8);
  for (c1_i315 = 0; c1_i315 < 68; c1_i315++) {
    c1_ac_u[c1_i315] = c1_jb_u.msg1008[c1_i315];
  }

  c1_gc_y = NULL;
  sf_mex_assign(&c1_gc_y, sf_mex_create("y", c1_ac_u, 2, 0U, 1U, 0U, 1, 68),
                false);
  sf_mex_setfieldbynum(c1_mb_y, 0, "msg1008", c1_gc_y, 9);
  for (c1_i316 = 0; c1_i316 < 136; c1_i316++) {
    c1_bc_u[c1_i316] = c1_jb_u.msg1009[c1_i316];
  }

  c1_hc_y = NULL;
  sf_mex_assign(&c1_hc_y, sf_mex_create("y", c1_bc_u, 2, 0U, 1U, 0U, 1, 136),
                false);
  sf_mex_setfieldbynum(c1_mb_y, 0, "msg1009", c1_hc_y, 10);
  for (c1_i317 = 0; c1_i317 < 166; c1_i317++) {
    c1_cc_u[c1_i317] = c1_jb_u.msg1010[c1_i317];
  }

  c1_ic_y = NULL;
  sf_mex_assign(&c1_ic_y, sf_mex_create("y", c1_cc_u, 2, 0U, 1U, 0U, 1, 166),
                false);
  sf_mex_setfieldbynum(c1_mb_y, 0, "msg1010", c1_ic_y, 11);
  for (c1_i318 = 0; c1_i318 < 222; c1_i318++) {
    c1_dc_u[c1_i318] = c1_jb_u.msg1011[c1_i318];
  }

  c1_jc_y = NULL;
  sf_mex_assign(&c1_jc_y, sf_mex_create("y", c1_dc_u, 2, 0U, 1U, 0U, 1, 222),
                false);
  sf_mex_setfieldbynum(c1_mb_y, 0, "msg1011", c1_jc_y, 12);
  for (c1_i319 = 0; c1_i319 < 268; c1_i319++) {
    c1_ec_u[c1_i319] = c1_jb_u.msg1012[c1_i319];
  }

  c1_kc_y = NULL;
  sf_mex_assign(&c1_kc_y, sf_mex_create("y", c1_ec_u, 2, 0U, 1U, 0U, 1, 268),
                false);
  sf_mex_setfieldbynum(c1_mb_y, 0, "msg1012", c1_kc_y, 13);
  for (c1_i320 = 0; c1_i320 < 27; c1_i320++) {
    c1_fc_u[c1_i320] = c1_jb_u.msg1013[c1_i320];
  }

  c1_lc_y = NULL;
  sf_mex_assign(&c1_lc_y, sf_mex_create("y", c1_fc_u, 2, 0U, 1U, 0U, 1, 27),
                false);
  sf_mex_setfieldbynum(c1_mb_y, 0, "msg1013", c1_lc_y, 14);
  for (c1_i321 = 0; c1_i321 < 15; c1_i321++) {
    c1_gc_u[c1_i321] = c1_jb_u.msg1014[c1_i321];
  }

  c1_mc_y = NULL;
  sf_mex_assign(&c1_mc_y, sf_mex_create("y", c1_gc_u, 2, 0U, 1U, 0U, 1, 15),
                false);
  sf_mex_setfieldbynum(c1_mb_y, 0, "msg1014", c1_mc_y, 15);
  for (c1_i322 = 0; c1_i322 < 69; c1_i322++) {
    c1_hc_u[c1_i322] = c1_jb_u.msg1015[c1_i322];
  }

  c1_nc_y = NULL;
  sf_mex_assign(&c1_nc_y, sf_mex_create("y", c1_hc_u, 2, 0U, 1U, 0U, 1, 69),
                false);
  sf_mex_setfieldbynum(c1_mb_y, 0, "msg1015", c1_nc_y, 16);
  for (c1_i323 = 0; c1_i323 < 81; c1_i323++) {
    c1_ic_u[c1_i323] = c1_jb_u.msg1016[c1_i323];
  }

  c1_oc_y = NULL;
  sf_mex_assign(&c1_oc_y, sf_mex_create("y", c1_ic_u, 2, 0U, 1U, 0U, 1, 81),
                false);
  sf_mex_setfieldbynum(c1_mb_y, 0, "msg1016", c1_oc_y, 17);
  for (c1_i324 = 0; c1_i324 < 115; c1_i324++) {
    c1_jc_u[c1_i324] = c1_jb_u.msg1017[c1_i324];
  }

  c1_pc_y = NULL;
  sf_mex_assign(&c1_pc_y, sf_mex_create("y", c1_jc_u, 2, 0U, 1U, 0U, 1, 115),
                false);
  sf_mex_setfieldbynum(c1_mb_y, 0, "msg1017", c1_pc_y, 18);
  for (c1_i325 = 0; c1_i325 < 62; c1_i325++) {
    c1_kc_u[c1_i325] = c1_jb_u.msg1019[c1_i325];
  }

  c1_qc_y = NULL;
  sf_mex_assign(&c1_qc_y, sf_mex_create("y", c1_kc_u, 2, 0U, 1U, 0U, 1, 62),
                false);
  sf_mex_setfieldbynum(c1_mb_y, 0, "msg1019", c1_qc_y, 19);
  for (c1_i326 = 0; c1_i326 < 45; c1_i326++) {
    c1_lc_u[c1_i326] = c1_jb_u.msg1020[c1_i326];
  }

  c1_rc_y = NULL;
  sf_mex_assign(&c1_rc_y, sf_mex_create("y", c1_lc_u, 2, 0U, 1U, 0U, 1, 45),
                false);
  sf_mex_setfieldbynum(c1_mb_y, 0, "msg1020", c1_rc_y, 20);
  for (c1_i327 = 0; c1_i327 < 62; c1_i327++) {
    c1_kc_u[c1_i327] = c1_jb_u.msg1021[c1_i327];
  }

  c1_sc_y = NULL;
  sf_mex_assign(&c1_sc_y, sf_mex_create("y", c1_kc_u, 2, 0U, 1U, 0U, 1, 62),
                false);
  sf_mex_setfieldbynum(c1_mb_y, 0, "msg1021", c1_sc_y, 21);
  for (c1_i328 = 0; c1_i328 < 75; c1_i328++) {
    c1_mc_u[c1_i328] = c1_jb_u.msg1022[c1_i328];
  }

  c1_tc_y = NULL;
  sf_mex_assign(&c1_tc_y, sf_mex_create("y", c1_mc_u, 2, 0U, 1U, 0U, 1, 75),
                false);
  sf_mex_setfieldbynum(c1_mb_y, 0, "msg1022", c1_tc_y, 22);
  for (c1_i329 = 0; c1_i329 < 73; c1_i329++) {
    c1_nc_u[c1_i329] = c1_jb_u.msg1023[c1_i329];
  }

  c1_uc_y = NULL;
  sf_mex_assign(&c1_uc_y, sf_mex_create("y", c1_nc_u, 2, 0U, 1U, 0U, 1, 73),
                false);
  sf_mex_setfieldbynum(c1_mb_y, 0, "msg1023", c1_uc_y, 23);
  for (c1_i330 = 0; c1_i330 < 74; c1_i330++) {
    c1_oc_u[c1_i330] = c1_jb_u.msg1024[c1_i330];
  }

  c1_vc_y = NULL;
  sf_mex_assign(&c1_vc_y, sf_mex_create("y", c1_oc_u, 2, 0U, 1U, 0U, 1, 74),
                false);
  sf_mex_setfieldbynum(c1_mb_y, 0, "msg1024", c1_vc_y, 24);
  for (c1_i331 = 0; c1_i331 < 25; c1_i331++) {
    c1_pc_u[c1_i331] = c1_jb_u.msg1025[c1_i331];
  }

  c1_wc_y = NULL;
  sf_mex_assign(&c1_wc_y, sf_mex_create("y", c1_pc_u, 2, 0U, 1U, 0U, 1, 25),
                false);
  sf_mex_setfieldbynum(c1_mb_y, 0, "msg1025", c1_wc_y, 25);
  for (c1_i332 = 0; c1_i332 < 30; c1_i332++) {
    c1_qc_u[c1_i332] = c1_jb_u.msg1026[c1_i332];
  }

  c1_xc_y = NULL;
  sf_mex_assign(&c1_xc_y, sf_mex_create("y", c1_qc_u, 2, 0U, 1U, 0U, 1, 30),
                false);
  sf_mex_setfieldbynum(c1_mb_y, 0, "msg1026", c1_xc_y, 26);
  for (c1_i333 = 0; c1_i333 < 33; c1_i333++) {
    c1_rc_u[c1_i333] = c1_jb_u.msg1027[c1_i333];
  }

  c1_yc_y = NULL;
  sf_mex_assign(&c1_yc_y, sf_mex_create("y", c1_rc_u, 2, 0U, 1U, 0U, 1, 33),
                false);
  sf_mex_setfieldbynum(c1_mb_y, 0, "msg1027", c1_yc_y, 27);
  for (c1_i334 = 0; c1_i334 < 69; c1_i334++) {
    c1_hc_u[c1_i334] = c1_jb_u.msg1029[c1_i334];
  }

  c1_ad_y = NULL;
  sf_mex_assign(&c1_ad_y, sf_mex_create("y", c1_hc_u, 2, 0U, 1U, 0U, 1, 69),
                false);
  sf_mex_setfieldbynum(c1_mb_y, 0, "msg1029", c1_ad_y, 28);
  for (c1_i335 = 0; c1_i335 < 105; c1_i335++) {
    c1_sc_u[c1_i335] = c1_jb_u.msg1030[c1_i335];
  }

  c1_bd_y = NULL;
  sf_mex_assign(&c1_bd_y, sf_mex_create("y", c1_sc_u, 2, 0U, 1U, 0U, 1, 105),
                false);
  sf_mex_setfieldbynum(c1_mb_y, 0, "msg1030", c1_bd_y, 29);
  for (c1_i336 = 0; c1_i336 < 107; c1_i336++) {
    c1_tc_u[c1_i336] = c1_jb_u.msg1031[c1_i336];
  }

  c1_cd_y = NULL;
  sf_mex_assign(&c1_cd_y, sf_mex_create("y", c1_tc_u, 2, 0U, 1U, 0U, 1, 107),
                false);
  sf_mex_setfieldbynum(c1_mb_y, 0, "msg1031", c1_cd_y, 30);
  for (c1_i337 = 0; c1_i337 < 20; c1_i337++) {
    c1_uc_u[c1_i337] = c1_jb_u.msg1032[c1_i337];
  }

  c1_dd_y = NULL;
  sf_mex_assign(&c1_dd_y, sf_mex_create("y", c1_uc_u, 2, 0U, 1U, 0U, 1, 20),
                false);
  sf_mex_setfieldbynum(c1_mb_y, 0, "msg1032", c1_dd_y, 31);
  sf_mex_setfieldbynum(c1_b_y, 0, "theRTCM", c1_mb_y, 3);
  return c1_b_y;
}

static const mxArray *c1_f_emlrt_marshallOut
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const
   PRESCAN_V2X_FIXED_BSM_utcTime c1_b_u)
{
  const mxArray *c1_b_y;
  int32_T c1_c_u;
  const mxArray *c1_c_y = NULL;
  int32_T c1_d_u;
  const mxArray *c1_d_y = NULL;
  int32_T c1_e_u;
  const mxArray *c1_e_y = NULL;
  int32_T c1_f_u;
  const mxArray *c1_f_y = NULL;
  int32_T c1_g_u;
  const mxArray *c1_g_y = NULL;
  int32_T c1_h_u;
  const mxArray *c1_h_y = NULL;
  (void)chartInstance;
  c1_b_y = NULL;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_createstruct("structure", 6, c1_sv3, 2, 1, 1),
                false);
  c1_c_u = c1_b_u.year;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_c_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "year", c1_c_y, 0);
  c1_d_u = c1_b_u.month;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_d_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "month", c1_d_y, 1);
  c1_e_u = c1_b_u.day;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_e_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "day", c1_e_y, 2);
  c1_f_u = c1_b_u.hour;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_f_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "hour", c1_f_y, 3);
  c1_g_u = c1_b_u.minute;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_g_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "minute", c1_g_y, 4);
  c1_h_u = c1_b_u.second;
  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_h_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "second", c1_h_y, 5);
  return c1_b_y;
}

static const mxArray *c1_g_emlrt_marshallOut
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const
   PRESCAN_V2X_FIXED_BSM_status *c1_b_u)
{
  const mxArray *c1_b_y;
  static const char * c1_sv18[22] = { "lights", "lightBar", "wipers",
    "brakeStatus", "brakePressure", "roadFriction", "sunData", "rainData",
    "airTemp", "airPres", "steering", "accelSets", "object", "fullPos",
    "throttlePos", "speedHeadC", "speedC", "vehicleData", "vehicleIdent",
    "j1939data", "weatherReport", "gpsStatus" };

  int32_T c1_c_u;
  const mxArray *c1_c_y = NULL;
  int32_T c1_d_u;
  const mxArray *c1_d_y = NULL;
  int32_T c1_e_u;
  const mxArray *c1_e_y = NULL;
  PRESCAN_V2X_FIXED_BSM_steering c1_f_u;
  const mxArray *c1_f_y = NULL;
  static const char * c1_sv19[4] = { "angle", "confidence", "rate", "wheels" };

  int8_T c1_g_u;
  const mxArray *c1_g_y = NULL;
  int32_T c1_h_u;
  const mxArray *c1_h_y = NULL;
  int32_T c1_i_u;
  const mxArray *c1_i_y = NULL;
  int32_T c1_j_u;
  const mxArray *c1_j_y = NULL;
  PRESCAN_V2X_FIXED_BSM_accelSets c1_k_u;
  const mxArray *c1_k_y = NULL;
  static const char * c1_sv20[5] = { "accel4way", "vertAccelThres", "yawRateCon",
    "hozAccelCon", "confidenceSet" };

  int32_T c1_i338;
  const mxArray *c1_l_y = NULL;
  int8_T c1_l_u[7];
  int32_T c1_m_u;
  const mxArray *c1_m_y = NULL;
  int32_T c1_n_u;
  const mxArray *c1_n_y = NULL;
  int32_T c1_o_u;
  const mxArray *c1_o_y = NULL;
  PRESCAN_V2X_FIXED_BSM_confidenceSet c1_p_u;
  const mxArray *c1_p_y = NULL;
  static const char * c1_sv21[6] = { "accelConfidence", "speedConfidence",
    "timeConfidence", "posConfidence", "steerConfidence", "throttleConfidence" };

  PRESCAN_V2X_FIXED_BSM_accelConfidence c1_q_u;
  const mxArray *c1_q_y = NULL;
  static const char * c1_sv22[3] = { "yawRate", "acceleration",
    "steeringWheelAngle" };

  int32_T c1_r_u;
  const mxArray *c1_r_y = NULL;
  int32_T c1_s_u;
  const mxArray *c1_s_y = NULL;
  int32_T c1_t_u;
  const mxArray *c1_t_y = NULL;
  int8_T c1_u_u;
  const mxArray *c1_u_y = NULL;
  int32_T c1_v_u;
  const mxArray *c1_v_y = NULL;
  int8_T c1_w_u;
  const mxArray *c1_w_y = NULL;
  int32_T c1_x_u;
  const mxArray *c1_x_y = NULL;
  int32_T c1_y_u;
  const mxArray *c1_y_y = NULL;
  PRESCAN_V2X_FIXED_BSM_object c1_ab_u;
  const mxArray *c1_ab_y = NULL;
  static const char * c1_sv23[3] = { "obDist", "obDirect", "dateTime" };

  int32_T c1_bb_u;
  const mxArray *c1_bb_y = NULL;
  int32_T c1_cb_u;
  const mxArray *c1_cb_y = NULL;
  PRESCAN_V2X_FIXED_BSM_dateTime c1_db_u;
  const mxArray *c1_db_y = NULL;
  int32_T c1_eb_u;
  const mxArray *c1_eb_y = NULL;
  int32_T c1_fb_u;
  const mxArray *c1_fb_y = NULL;
  int32_T c1_gb_u;
  const mxArray *c1_gb_y = NULL;
  int32_T c1_hb_u;
  const mxArray *c1_hb_y = NULL;
  int32_T c1_ib_u;
  const mxArray *c1_ib_y = NULL;
  int32_T c1_jb_u;
  const mxArray *c1_jb_y = NULL;
  PRESCAN_V2X_FIXED_BSM_fullPos c1_kb_u;
  const mxArray *c1_kb_y = NULL;
  int32_T c1_lb_u;
  const mxArray *c1_lb_y = NULL;
  int32_T c1_mb_u;
  const mxArray *c1_mb_y = NULL;
  int32_T c1_i339;
  const mxArray *c1_nb_y = NULL;
  int8_T c1_nb_u[2];
  int32_T c1_ob_u;
  const mxArray *c1_ob_y = NULL;
  int32_T c1_i340;
  const mxArray *c1_pb_y = NULL;
  int32_T c1_i341;
  const mxArray *c1_qb_y = NULL;
  int8_T c1_pb_u[4];
  int32_T c1_qb_u;
  const mxArray *c1_rb_y = NULL;
  int8_T c1_rb_u;
  const mxArray *c1_sb_y = NULL;
  int8_T c1_sb_u;
  const mxArray *c1_tb_y = NULL;
  int32_T c1_tb_u;
  const mxArray *c1_ub_y = NULL;
  int8_T c1_ub_u;
  const mxArray *c1_vb_y = NULL;
  int32_T c1_vb_u;
  const mxArray *c1_wb_y = NULL;
  PRESCAN_V2X_FIXED_BSM_vehicleData c1_wb_u;
  const mxArray *c1_xb_y = NULL;
  static const char * c1_sv24[5] = { "height", "bumpers", "mass",
    "trailerWeight", "type" };

  int32_T c1_xb_u;
  const mxArray *c1_yb_y = NULL;
  PRESCAN_V2X_FIXED_BSM_bumpers c1_yb_u;
  const mxArray *c1_ac_y = NULL;
  static const char * c1_sv25[2] = { "frnt", "rear" };

  int32_T c1_ac_u;
  const mxArray *c1_bc_y = NULL;
  int32_T c1_bc_u;
  const mxArray *c1_cc_y = NULL;
  int32_T c1_cc_u;
  const mxArray *c1_dc_y = NULL;
  int32_T c1_dc_u;
  const mxArray *c1_ec_y = NULL;
  int32_T c1_ec_u;
  const mxArray *c1_fc_y = NULL;
  PRESCAN_V2X_FIXED_BSM_vehicleIdent c1_fc_u;
  const mxArray *c1_gc_y = NULL;
  static const char * c1_sv26[6] = { "name", "vin", "ownerCode", "id",
    "vehicleType", "vehicleClass" };

  int32_T c1_i342;
  const mxArray *c1_hc_y = NULL;
  int8_T c1_gc_u[63];
  int32_T c1_i343;
  const mxArray *c1_ic_y = NULL;
  int8_T c1_hc_u[17];
  int32_T c1_i344;
  const mxArray *c1_jc_y = NULL;
  int8_T c1_ic_u[32];
  int32_T c1_i345;
  const mxArray *c1_kc_y = NULL;
  int32_T c1_jc_u;
  const mxArray *c1_lc_y = NULL;
  PRESCAN_V2X_FIXED_BSM_vehicleClass c1_kc_u;
  const mxArray *c1_mc_y = NULL;
  static const char * c1_sv27[3] = { "vGroup", "rGroup", "rEquip" };

  int32_T c1_lc_u;
  const mxArray *c1_nc_y = NULL;
  int32_T c1_mc_u;
  const mxArray *c1_oc_y = NULL;
  int32_T c1_nc_u;
  const mxArray *c1_pc_y = NULL;
  PRESCAN_V2X_FIXED_BSM_j1939data c1_oc_u;
  const mxArray *c1_qc_y = NULL;
  static const char * c1_sv28[10] = { "tires", "axle", "trailerWeight",
    "cargoWeight", "steeringAxleTemperature", "driveAxleLocation",
    "driveAxleLiftAirPressure", "driveAxleTemperature", "driveAxleLubePressure",
    "steeringAxleLubePressure" };

  int32_T c1_i346;
  const mxArray *c1_rc_y = NULL;
  PRESCAN_V2X_FIXED_BSM_tires c1_pc_u[16];
  int32_T c1_iv1[1];
  static const char * c1_sv29[7] = { "location", "pressure", "temp",
    "wheelSensorStatus", "wheelEndElectFault", "leakageRate", "detection" };

  int32_T c1_i347;
  const PRESCAN_V2X_FIXED_BSM_tires *c1_r3;
  int32_T c1_i348;
  int32_T c1_qc_u;
  const mxArray *c1_sc_y = NULL;
  const mxArray *c1_tc_y = NULL;
  PRESCAN_V2X_FIXED_BSM_axle c1_rc_u[16];
  int32_T c1_iv2[1];
  int32_T c1_sc_u;
  static const char * c1_sv30[2] = { "location", "weight" };

  const mxArray *c1_uc_y = NULL;
  int32_T c1_i349;
  int32_T c1_tc_u;
  const PRESCAN_V2X_FIXED_BSM_axle *c1_r4;
  const mxArray *c1_vc_y = NULL;
  int32_T c1_uc_u;
  int32_T c1_vc_u;
  const mxArray *c1_wc_y = NULL;
  const mxArray *c1_xc_y = NULL;
  int32_T c1_wc_u;
  const mxArray *c1_yc_y = NULL;
  int32_T c1_xc_u;
  int32_T c1_yc_u;
  const mxArray *c1_ad_y = NULL;
  const mxArray *c1_bd_y = NULL;
  int32_T c1_ad_u;
  const mxArray *c1_cd_y = NULL;
  int32_T c1_bd_u;
  const mxArray *c1_dd_y = NULL;
  int32_T c1_cd_u;
  const mxArray *c1_ed_y = NULL;
  int32_T c1_dd_u;
  const mxArray *c1_fd_y = NULL;
  int32_T c1_ed_u;
  const mxArray *c1_gd_y = NULL;
  int32_T c1_fd_u;
  const mxArray *c1_hd_y = NULL;
  int32_T c1_gd_u;
  const mxArray *c1_id_y = NULL;
  int32_T c1_hd_u;
  const mxArray *c1_jd_y = NULL;
  int32_T c1_id_u;
  const mxArray *c1_kd_y = NULL;
  PRESCAN_V2X_FIXED_BSM_weatherReport c1_jd_u;
  const mxArray *c1_ld_y = NULL;
  static const char * c1_sv31[5] = { "isRaining", "rainRate", "precipSituation",
    "solarRadiation", "friction" };

  int32_T c1_kd_u;
  const mxArray *c1_md_y = NULL;
  int32_T c1_ld_u;
  const mxArray *c1_nd_y = NULL;
  int32_T c1_md_u;
  const mxArray *c1_od_y = NULL;
  int32_T c1_nd_u;
  const mxArray *c1_pd_y = NULL;
  int32_T c1_od_u;
  const mxArray *c1_qd_y = NULL;
  int32_T c1_pd_u;
  const mxArray *c1_rd_y = NULL;
  c1_b_y = NULL;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_createstruct("structure", 22, c1_sv18, 2, 1, 1),
                false);
  sf_mex_setfieldbynum(c1_b_y, 0, "lights", c1_b_emlrt_marshallOut(chartInstance,
    c1_b_u->lights), 0);
  sf_mex_setfieldbynum(c1_b_y, 0, "lightBar", c1_b_emlrt_marshallOut
                       (chartInstance, c1_b_u->lightBar), 1);
  sf_mex_setfieldbynum(c1_b_y, 0, "wipers", c1_h_emlrt_marshallOut(chartInstance,
    c1_b_u->wipers), 2);
  sf_mex_setfieldbynum(c1_b_y, 0, "brakeStatus", c1_c_emlrt_marshallOut
                       (chartInstance, c1_b_u->brakeStatus), 3);
  sf_mex_setfieldbynum(c1_b_y, 0, "brakePressure", c1_b_emlrt_marshallOut
                       (chartInstance, c1_b_u->brakePressure), 4);
  sf_mex_setfieldbynum(c1_b_y, 0, "roadFriction", c1_b_emlrt_marshallOut
                       (chartInstance, c1_b_u->roadFriction), 5);
  sf_mex_setfieldbynum(c1_b_y, 0, "sunData", c1_b_emlrt_marshallOut
                       (chartInstance, c1_b_u->sunData), 6);
  c1_c_u = c1_b_u->rainData;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_c_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "rainData", c1_c_y, 7);
  c1_d_u = c1_b_u->airTemp;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_d_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "airTemp", c1_d_y, 8);
  c1_e_u = c1_b_u->airPres;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_e_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "airPres", c1_e_y, 9);
  c1_f_u = c1_b_u->steering;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_createstruct("structure", 4, c1_sv19, 2, 1, 1),
                false);
  c1_g_u = c1_f_u.angle;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_g_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_f_y, 0, "angle", c1_g_y, 0);
  c1_h_u = c1_f_u.confidence;
  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_h_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_f_y, 0, "confidence", c1_h_y, 1);
  c1_i_u = c1_f_u.rate;
  c1_i_y = NULL;
  sf_mex_assign(&c1_i_y, sf_mex_create("y", &c1_i_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_f_y, 0, "rate", c1_i_y, 2);
  c1_j_u = c1_f_u.wheels;
  c1_j_y = NULL;
  sf_mex_assign(&c1_j_y, sf_mex_create("y", &c1_j_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_f_y, 0, "wheels", c1_j_y, 3);
  sf_mex_setfieldbynum(c1_b_y, 0, "steering", c1_f_y, 10);
  c1_k_u = c1_b_u->accelSets;
  c1_k_y = NULL;
  sf_mex_assign(&c1_k_y, sf_mex_createstruct("structure", 5, c1_sv20, 2, 1, 1),
                false);
  for (c1_i338 = 0; c1_i338 < 7; c1_i338++) {
    c1_l_u[c1_i338] = c1_k_u.accel4way[c1_i338];
  }

  c1_l_y = NULL;
  sf_mex_assign(&c1_l_y, sf_mex_create("y", c1_l_u, 2, 0U, 1U, 0U, 1, 7), false);
  sf_mex_setfieldbynum(c1_k_y, 0, "accel4way", c1_l_y, 0);
  c1_m_u = c1_k_u.vertAccelThres;
  c1_m_y = NULL;
  sf_mex_assign(&c1_m_y, sf_mex_create("y", &c1_m_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_k_y, 0, "vertAccelThres", c1_m_y, 1);
  c1_n_u = c1_k_u.yawRateCon;
  c1_n_y = NULL;
  sf_mex_assign(&c1_n_y, sf_mex_create("y", &c1_n_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_k_y, 0, "yawRateCon", c1_n_y, 2);
  c1_o_u = c1_k_u.hozAccelCon;
  c1_o_y = NULL;
  sf_mex_assign(&c1_o_y, sf_mex_create("y", &c1_o_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_k_y, 0, "hozAccelCon", c1_o_y, 3);
  c1_p_u = c1_k_u.confidenceSet;
  c1_p_y = NULL;
  sf_mex_assign(&c1_p_y, sf_mex_createstruct("structure", 6, c1_sv21, 2, 1, 1),
                false);
  c1_q_u = c1_p_u.accelConfidence;
  c1_q_y = NULL;
  sf_mex_assign(&c1_q_y, sf_mex_createstruct("structure", 3, c1_sv22, 2, 1, 1),
                false);
  c1_r_u = c1_q_u.yawRate;
  c1_r_y = NULL;
  sf_mex_assign(&c1_r_y, sf_mex_create("y", &c1_r_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_q_y, 0, "yawRate", c1_r_y, 0);
  c1_s_u = c1_q_u.acceleration;
  c1_s_y = NULL;
  sf_mex_assign(&c1_s_y, sf_mex_create("y", &c1_s_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_q_y, 0, "acceleration", c1_s_y, 1);
  c1_t_u = c1_q_u.steeringWheelAngle;
  c1_t_y = NULL;
  sf_mex_assign(&c1_t_y, sf_mex_create("y", &c1_t_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_q_y, 0, "steeringWheelAngle", c1_t_y, 2);
  sf_mex_setfieldbynum(c1_p_y, 0, "accelConfidence", c1_q_y, 0);
  c1_u_u = c1_p_u.speedConfidence;
  c1_u_y = NULL;
  sf_mex_assign(&c1_u_y, sf_mex_create("y", &c1_u_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_p_y, 0, "speedConfidence", c1_u_y, 1);
  c1_v_u = c1_p_u.timeConfidence;
  c1_v_y = NULL;
  sf_mex_assign(&c1_v_y, sf_mex_create("y", &c1_v_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_p_y, 0, "timeConfidence", c1_v_y, 2);
  c1_w_u = c1_p_u.posConfidence;
  c1_w_y = NULL;
  sf_mex_assign(&c1_w_y, sf_mex_create("y", &c1_w_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_p_y, 0, "posConfidence", c1_w_y, 3);
  c1_x_u = c1_p_u.steerConfidence;
  c1_x_y = NULL;
  sf_mex_assign(&c1_x_y, sf_mex_create("y", &c1_x_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_p_y, 0, "steerConfidence", c1_x_y, 4);
  c1_y_u = c1_p_u.throttleConfidence;
  c1_y_y = NULL;
  sf_mex_assign(&c1_y_y, sf_mex_create("y", &c1_y_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_p_y, 0, "throttleConfidence", c1_y_y, 5);
  sf_mex_setfieldbynum(c1_k_y, 0, "confidenceSet", c1_p_y, 4);
  sf_mex_setfieldbynum(c1_b_y, 0, "accelSets", c1_k_y, 11);
  c1_ab_u = c1_b_u->object;
  c1_ab_y = NULL;
  sf_mex_assign(&c1_ab_y, sf_mex_createstruct("structure", 3, c1_sv23, 2, 1, 1),
                false);
  c1_bb_u = c1_ab_u.obDist;
  c1_bb_y = NULL;
  sf_mex_assign(&c1_bb_y, sf_mex_create("y", &c1_bb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_ab_y, 0, "obDist", c1_bb_y, 0);
  c1_cb_u = c1_ab_u.obDirect;
  c1_cb_y = NULL;
  sf_mex_assign(&c1_cb_y, sf_mex_create("y", &c1_cb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_ab_y, 0, "obDirect", c1_cb_y, 1);
  c1_db_u = c1_ab_u.dateTime;
  c1_db_y = NULL;
  sf_mex_assign(&c1_db_y, sf_mex_createstruct("structure", 6, c1_sv3, 2, 1, 1),
                false);
  c1_eb_u = c1_db_u.year;
  c1_eb_y = NULL;
  sf_mex_assign(&c1_eb_y, sf_mex_create("y", &c1_eb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_db_y, 0, "year", c1_eb_y, 0);
  c1_fb_u = c1_db_u.month;
  c1_fb_y = NULL;
  sf_mex_assign(&c1_fb_y, sf_mex_create("y", &c1_fb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_db_y, 0, "month", c1_fb_y, 1);
  c1_gb_u = c1_db_u.day;
  c1_gb_y = NULL;
  sf_mex_assign(&c1_gb_y, sf_mex_create("y", &c1_gb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_db_y, 0, "day", c1_gb_y, 2);
  c1_hb_u = c1_db_u.hour;
  c1_hb_y = NULL;
  sf_mex_assign(&c1_hb_y, sf_mex_create("y", &c1_hb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_db_y, 0, "hour", c1_hb_y, 3);
  c1_ib_u = c1_db_u.minute;
  c1_ib_y = NULL;
  sf_mex_assign(&c1_ib_y, sf_mex_create("y", &c1_ib_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_db_y, 0, "minute", c1_ib_y, 4);
  c1_jb_u = c1_db_u.second;
  c1_jb_y = NULL;
  sf_mex_assign(&c1_jb_y, sf_mex_create("y", &c1_jb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_db_y, 0, "second", c1_jb_y, 5);
  sf_mex_setfieldbynum(c1_ab_y, 0, "dateTime", c1_db_y, 2);
  sf_mex_setfieldbynum(c1_b_y, 0, "object", c1_ab_y, 12);
  c1_kb_u = c1_b_u->fullPos;
  c1_kb_y = NULL;
  sf_mex_assign(&c1_kb_y, sf_mex_createstruct("structure", 10, c1_sv2, 2, 1, 1),
                false);
  sf_mex_setfieldbynum(c1_kb_y, 0, "utcTime", c1_f_emlrt_marshallOut
                       (chartInstance, c1_kb_u.utcTime), 0);
  c1_lb_u = c1_kb_u.longitude;
  c1_lb_y = NULL;
  sf_mex_assign(&c1_lb_y, sf_mex_create("y", &c1_lb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_kb_y, 0, "longitude", c1_lb_y, 1);
  c1_mb_u = c1_kb_u.latitude;
  c1_mb_y = NULL;
  sf_mex_assign(&c1_mb_y, sf_mex_create("y", &c1_mb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_kb_y, 0, "latitude", c1_mb_y, 2);
  for (c1_i339 = 0; c1_i339 < 2; c1_i339++) {
    c1_nb_u[c1_i339] = c1_kb_u.elevation[c1_i339];
  }

  c1_nb_y = NULL;
  sf_mex_assign(&c1_nb_y, sf_mex_create("y", c1_nb_u, 2, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_setfieldbynum(c1_kb_y, 0, "elevation", c1_nb_y, 3);
  c1_ob_u = c1_kb_u.heading;
  c1_ob_y = NULL;
  sf_mex_assign(&c1_ob_y, sf_mex_create("y", &c1_ob_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_kb_y, 0, "heading", c1_ob_y, 4);
  for (c1_i340 = 0; c1_i340 < 2; c1_i340++) {
    c1_nb_u[c1_i340] = c1_kb_u.speed[c1_i340];
  }

  c1_pb_y = NULL;
  sf_mex_assign(&c1_pb_y, sf_mex_create("y", c1_nb_u, 2, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_setfieldbynum(c1_kb_y, 0, "speed", c1_pb_y, 5);
  for (c1_i341 = 0; c1_i341 < 4; c1_i341++) {
    c1_pb_u[c1_i341] = c1_kb_u.posAccuracy[c1_i341];
  }

  c1_qb_y = NULL;
  sf_mex_assign(&c1_qb_y, sf_mex_create("y", c1_pb_u, 2, 0U, 1U, 0U, 1, 4),
                false);
  sf_mex_setfieldbynum(c1_kb_y, 0, "posAccuracy", c1_qb_y, 6);
  c1_qb_u = c1_kb_u.timeConfidence;
  c1_rb_y = NULL;
  sf_mex_assign(&c1_rb_y, sf_mex_create("y", &c1_qb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_kb_y, 0, "timeConfidence", c1_rb_y, 7);
  c1_rb_u = c1_kb_u.posConfidence;
  c1_sb_y = NULL;
  sf_mex_assign(&c1_sb_y, sf_mex_create("y", &c1_rb_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_kb_y, 0, "posConfidence", c1_sb_y, 8);
  c1_sb_u = c1_kb_u.speedConfidence;
  c1_tb_y = NULL;
  sf_mex_assign(&c1_tb_y, sf_mex_create("y", &c1_sb_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_kb_y, 0, "speedConfidence", c1_tb_y, 9);
  sf_mex_setfieldbynum(c1_b_y, 0, "fullPos", c1_kb_y, 13);
  c1_tb_u = c1_b_u->throttlePos;
  c1_ub_y = NULL;
  sf_mex_assign(&c1_ub_y, sf_mex_create("y", &c1_tb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "throttlePos", c1_ub_y, 14);
  c1_ub_u = c1_b_u->speedHeadC;
  c1_vb_y = NULL;
  sf_mex_assign(&c1_vb_y, sf_mex_create("y", &c1_ub_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "speedHeadC", c1_vb_y, 15);
  c1_vb_u = c1_b_u->speedC;
  c1_wb_y = NULL;
  sf_mex_assign(&c1_wb_y, sf_mex_create("y", &c1_vb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "speedC", c1_wb_y, 16);
  c1_wb_u = c1_b_u->vehicleData;
  c1_xb_y = NULL;
  sf_mex_assign(&c1_xb_y, sf_mex_createstruct("structure", 5, c1_sv24, 2, 1, 1),
                false);
  c1_xb_u = c1_wb_u.height;
  c1_yb_y = NULL;
  sf_mex_assign(&c1_yb_y, sf_mex_create("y", &c1_xb_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_xb_y, 0, "height", c1_yb_y, 0);
  c1_yb_u = c1_wb_u.bumpers;
  c1_ac_y = NULL;
  sf_mex_assign(&c1_ac_y, sf_mex_createstruct("structure", 2, c1_sv25, 2, 1, 1),
                false);
  c1_ac_u = c1_yb_u.frnt;
  c1_bc_y = NULL;
  sf_mex_assign(&c1_bc_y, sf_mex_create("y", &c1_ac_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_ac_y, 0, "frnt", c1_bc_y, 0);
  c1_bc_u = c1_yb_u.rear;
  c1_cc_y = NULL;
  sf_mex_assign(&c1_cc_y, sf_mex_create("y", &c1_bc_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_ac_y, 0, "rear", c1_cc_y, 1);
  sf_mex_setfieldbynum(c1_xb_y, 0, "bumpers", c1_ac_y, 1);
  c1_cc_u = c1_wb_u.mass;
  c1_dc_y = NULL;
  sf_mex_assign(&c1_dc_y, sf_mex_create("y", &c1_cc_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_xb_y, 0, "mass", c1_dc_y, 2);
  c1_dc_u = c1_wb_u.trailerWeight;
  c1_ec_y = NULL;
  sf_mex_assign(&c1_ec_y, sf_mex_create("y", &c1_dc_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_xb_y, 0, "trailerWeight", c1_ec_y, 3);
  c1_ec_u = c1_wb_u.type;
  c1_fc_y = NULL;
  sf_mex_assign(&c1_fc_y, sf_mex_create("y", &c1_ec_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_xb_y, 0, "type", c1_fc_y, 4);
  sf_mex_setfieldbynum(c1_b_y, 0, "vehicleData", c1_xb_y, 17);
  c1_fc_u = c1_b_u->vehicleIdent;
  c1_gc_y = NULL;
  sf_mex_assign(&c1_gc_y, sf_mex_createstruct("structure", 6, c1_sv26, 2, 1, 1),
                false);
  for (c1_i342 = 0; c1_i342 < 63; c1_i342++) {
    c1_gc_u[c1_i342] = c1_fc_u.name[c1_i342];
  }

  c1_hc_y = NULL;
  sf_mex_assign(&c1_hc_y, sf_mex_create("y", c1_gc_u, 2, 0U, 1U, 0U, 1, 63),
                false);
  sf_mex_setfieldbynum(c1_gc_y, 0, "name", c1_hc_y, 0);
  for (c1_i343 = 0; c1_i343 < 17; c1_i343++) {
    c1_hc_u[c1_i343] = c1_fc_u.vin[c1_i343];
  }

  c1_ic_y = NULL;
  sf_mex_assign(&c1_ic_y, sf_mex_create("y", c1_hc_u, 2, 0U, 1U, 0U, 1, 17),
                false);
  sf_mex_setfieldbynum(c1_gc_y, 0, "vin", c1_ic_y, 1);
  for (c1_i344 = 0; c1_i344 < 32; c1_i344++) {
    c1_ic_u[c1_i344] = c1_fc_u.ownerCode[c1_i344];
  }

  c1_jc_y = NULL;
  sf_mex_assign(&c1_jc_y, sf_mex_create("y", c1_ic_u, 2, 0U, 1U, 0U, 1, 32),
                false);
  sf_mex_setfieldbynum(c1_gc_y, 0, "ownerCode", c1_jc_y, 2);
  for (c1_i345 = 0; c1_i345 < 4; c1_i345++) {
    c1_pb_u[c1_i345] = c1_fc_u.id[c1_i345];
  }

  c1_kc_y = NULL;
  sf_mex_assign(&c1_kc_y, sf_mex_create("y", c1_pb_u, 2, 0U, 1U, 0U, 1, 4),
                false);
  sf_mex_setfieldbynum(c1_gc_y, 0, "id", c1_kc_y, 3);
  c1_jc_u = c1_fc_u.vehicleType;
  c1_lc_y = NULL;
  sf_mex_assign(&c1_lc_y, sf_mex_create("y", &c1_jc_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_gc_y, 0, "vehicleType", c1_lc_y, 4);
  c1_kc_u = c1_fc_u.vehicleClass;
  c1_mc_y = NULL;
  sf_mex_assign(&c1_mc_y, sf_mex_createstruct("structure", 3, c1_sv27, 2, 1, 1),
                false);
  c1_lc_u = c1_kc_u.vGroup;
  c1_nc_y = NULL;
  sf_mex_assign(&c1_nc_y, sf_mex_create("y", &c1_lc_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_mc_y, 0, "vGroup", c1_nc_y, 0);
  c1_mc_u = c1_kc_u.rGroup;
  c1_oc_y = NULL;
  sf_mex_assign(&c1_oc_y, sf_mex_create("y", &c1_mc_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_mc_y, 0, "rGroup", c1_oc_y, 1);
  c1_nc_u = c1_kc_u.rEquip;
  c1_pc_y = NULL;
  sf_mex_assign(&c1_pc_y, sf_mex_create("y", &c1_nc_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_mc_y, 0, "rEquip", c1_pc_y, 2);
  sf_mex_setfieldbynum(c1_gc_y, 0, "vehicleClass", c1_mc_y, 5);
  sf_mex_setfieldbynum(c1_b_y, 0, "vehicleIdent", c1_gc_y, 18);
  c1_oc_u = c1_b_u->j1939data;
  c1_qc_y = NULL;
  sf_mex_assign(&c1_qc_y, sf_mex_createstruct("structure", 10, c1_sv28, 2, 1, 1),
                false);
  for (c1_i346 = 0; c1_i346 < 16; c1_i346++) {
    c1_pc_u[c1_i346] = c1_oc_u.tires[c1_i346];
  }

  c1_rc_y = NULL;
  c1_iv1[0] = 16;
  sf_mex_assign(&c1_rc_y, sf_mex_createstructarray("structure", 1, c1_iv1, 7,
    c1_sv29), false);
  for (c1_i347 = 0; c1_i347 < 16; c1_i347++) {
    c1_r3 = &c1_pc_u[c1_i347];
    c1_qc_u = c1_r3->location;
    c1_sc_y = NULL;
    sf_mex_assign(&c1_sc_y, sf_mex_create("y", &c1_qc_u, 6, 0U, 0U, 0U, 0),
                  false);
    sf_mex_setfieldbynum(c1_rc_y, c1_i347, "location", c1_sc_y, 0);
    c1_sc_u = c1_r3->pressure;
    c1_uc_y = NULL;
    sf_mex_assign(&c1_uc_y, sf_mex_create("y", &c1_sc_u, 6, 0U, 0U, 0U, 0),
                  false);
    sf_mex_setfieldbynum(c1_rc_y, c1_i347, "pressure", c1_uc_y, 1);
    c1_tc_u = c1_r3->temp;
    c1_vc_y = NULL;
    sf_mex_assign(&c1_vc_y, sf_mex_create("y", &c1_tc_u, 6, 0U, 0U, 0U, 0),
                  false);
    sf_mex_setfieldbynum(c1_rc_y, c1_i347, "temp", c1_vc_y, 2);
    c1_wc_u = c1_r3->wheelSensorStatus;
    c1_yc_y = NULL;
    sf_mex_assign(&c1_yc_y, sf_mex_create("y", &c1_wc_u, 6, 0U, 0U, 0U, 0),
                  false);
    sf_mex_setfieldbynum(c1_rc_y, c1_i347, "wheelSensorStatus", c1_yc_y, 3);
    c1_ad_u = c1_r3->wheelEndElectFault;
    c1_cd_y = NULL;
    sf_mex_assign(&c1_cd_y, sf_mex_create("y", &c1_ad_u, 6, 0U, 0U, 0U, 0),
                  false);
    sf_mex_setfieldbynum(c1_rc_y, c1_i347, "wheelEndElectFault", c1_cd_y, 4);
    c1_cd_u = c1_r3->leakageRate;
    c1_ed_y = NULL;
    sf_mex_assign(&c1_ed_y, sf_mex_create("y", &c1_cd_u, 6, 0U, 0U, 0U, 0),
                  false);
    sf_mex_setfieldbynum(c1_rc_y, c1_i347, "leakageRate", c1_ed_y, 5);
    c1_ed_u = c1_r3->detection;
    c1_gd_y = NULL;
    sf_mex_assign(&c1_gd_y, sf_mex_create("y", &c1_ed_u, 6, 0U, 0U, 0U, 0),
                  false);
    sf_mex_setfieldbynum(c1_rc_y, c1_i347, "detection", c1_gd_y, 6);
  }

  sf_mex_setfieldbynum(c1_qc_y, 0, "tires", c1_rc_y, 0);
  for (c1_i348 = 0; c1_i348 < 16; c1_i348++) {
    c1_rc_u[c1_i348] = c1_oc_u.axle[c1_i348];
  }

  c1_tc_y = NULL;
  c1_iv2[0] = 16;
  sf_mex_assign(&c1_tc_y, sf_mex_createstructarray("structure", 1, c1_iv2, 2,
    c1_sv30), false);
  for (c1_i349 = 0; c1_i349 < 16; c1_i349++) {
    c1_r4 = &c1_rc_u[c1_i349];
    c1_vc_u = c1_r4->location;
    c1_xc_y = NULL;
    sf_mex_assign(&c1_xc_y, sf_mex_create("y", &c1_vc_u, 6, 0U, 0U, 0U, 0),
                  false);
    sf_mex_setfieldbynum(c1_tc_y, c1_i349, "location", c1_xc_y, 0);
    c1_yc_u = c1_r4->weight;
    c1_bd_y = NULL;
    sf_mex_assign(&c1_bd_y, sf_mex_create("y", &c1_yc_u, 6, 0U, 0U, 0U, 0),
                  false);
    sf_mex_setfieldbynum(c1_tc_y, c1_i349, "weight", c1_bd_y, 1);
  }

  sf_mex_setfieldbynum(c1_qc_y, 0, "axle", c1_tc_y, 1);
  c1_uc_u = c1_oc_u.trailerWeight;
  c1_wc_y = NULL;
  sf_mex_assign(&c1_wc_y, sf_mex_create("y", &c1_uc_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_qc_y, 0, "trailerWeight", c1_wc_y, 2);
  c1_xc_u = c1_oc_u.cargoWeight;
  c1_ad_y = NULL;
  sf_mex_assign(&c1_ad_y, sf_mex_create("y", &c1_xc_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_qc_y, 0, "cargoWeight", c1_ad_y, 3);
  c1_bd_u = c1_oc_u.steeringAxleTemperature;
  c1_dd_y = NULL;
  sf_mex_assign(&c1_dd_y, sf_mex_create("y", &c1_bd_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_qc_y, 0, "steeringAxleTemperature", c1_dd_y, 4);
  c1_dd_u = c1_oc_u.driveAxleLocation;
  c1_fd_y = NULL;
  sf_mex_assign(&c1_fd_y, sf_mex_create("y", &c1_dd_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_qc_y, 0, "driveAxleLocation", c1_fd_y, 5);
  c1_fd_u = c1_oc_u.driveAxleLiftAirPressure;
  c1_hd_y = NULL;
  sf_mex_assign(&c1_hd_y, sf_mex_create("y", &c1_fd_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_qc_y, 0, "driveAxleLiftAirPressure", c1_hd_y, 6);
  c1_gd_u = c1_oc_u.driveAxleTemperature;
  c1_id_y = NULL;
  sf_mex_assign(&c1_id_y, sf_mex_create("y", &c1_gd_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_qc_y, 0, "driveAxleTemperature", c1_id_y, 7);
  c1_hd_u = c1_oc_u.driveAxleLubePressure;
  c1_jd_y = NULL;
  sf_mex_assign(&c1_jd_y, sf_mex_create("y", &c1_hd_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_qc_y, 0, "driveAxleLubePressure", c1_jd_y, 8);
  c1_id_u = c1_oc_u.steeringAxleLubePressure;
  c1_kd_y = NULL;
  sf_mex_assign(&c1_kd_y, sf_mex_create("y", &c1_id_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_qc_y, 0, "steeringAxleLubePressure", c1_kd_y, 9);
  sf_mex_setfieldbynum(c1_b_y, 0, "j1939data", c1_qc_y, 19);
  c1_jd_u = c1_b_u->weatherReport;
  c1_ld_y = NULL;
  sf_mex_assign(&c1_ld_y, sf_mex_createstruct("structure", 5, c1_sv31, 2, 1, 1),
                false);
  c1_kd_u = c1_jd_u.isRaining;
  c1_md_y = NULL;
  sf_mex_assign(&c1_md_y, sf_mex_create("y", &c1_kd_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_ld_y, 0, "isRaining", c1_md_y, 0);
  c1_ld_u = c1_jd_u.rainRate;
  c1_nd_y = NULL;
  sf_mex_assign(&c1_nd_y, sf_mex_create("y", &c1_ld_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_ld_y, 0, "rainRate", c1_nd_y, 1);
  c1_md_u = c1_jd_u.precipSituation;
  c1_od_y = NULL;
  sf_mex_assign(&c1_od_y, sf_mex_create("y", &c1_md_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_ld_y, 0, "precipSituation", c1_od_y, 2);
  c1_nd_u = c1_jd_u.solarRadiation;
  c1_pd_y = NULL;
  sf_mex_assign(&c1_pd_y, sf_mex_create("y", &c1_nd_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_ld_y, 0, "solarRadiation", c1_pd_y, 3);
  c1_od_u = c1_jd_u.friction;
  c1_qd_y = NULL;
  sf_mex_assign(&c1_qd_y, sf_mex_create("y", &c1_od_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_ld_y, 0, "friction", c1_qd_y, 4);
  sf_mex_setfieldbynum(c1_b_y, 0, "weatherReport", c1_ld_y, 20);
  c1_pd_u = c1_b_u->gpsStatus;
  c1_rd_y = NULL;
  sf_mex_assign(&c1_rd_y, sf_mex_create("y", &c1_pd_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "gpsStatus", c1_rd_y, 21);
  return c1_b_y;
}

static const mxArray *c1_h_emlrt_marshallOut
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const
   PRESCAN_V2X_FIXED_BSM_wipers c1_b_u)
{
  const mxArray *c1_b_y;
  static const char * c1_sv32[4] = { "statusFront", "rateFront", "statusRear",
    "rateRear" };

  int32_T c1_c_u;
  const mxArray *c1_c_y = NULL;
  int32_T c1_d_u;
  const mxArray *c1_d_y = NULL;
  int32_T c1_e_u;
  const mxArray *c1_e_y = NULL;
  int32_T c1_f_u;
  const mxArray *c1_f_y = NULL;
  (void)chartInstance;
  c1_b_y = NULL;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_createstruct("structure", 4, c1_sv32, 2, 1, 1),
                false);
  c1_c_u = c1_b_u.statusFront;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_c_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "statusFront", c1_c_y, 0);
  c1_d_u = c1_b_u.rateFront;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_d_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "rateFront", c1_d_y, 1);
  c1_e_u = c1_b_u.statusRear;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_e_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "statusRear", c1_e_y, 2);
  c1_f_u = c1_b_u.rateRear;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_f_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "rateRear", c1_f_y, 3);
  return c1_b_y;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  PRESCAN_V2X_FIXED_BSM_MESSAGE c1_b_u;
  const mxArray *c1_b_y = NULL;
  PRESCAN_HEADER c1_c_u;
  const mxArray *c1_c_y = NULL;
  static const char * c1_sv33[1] = { "valid" };

  boolean_T c1_d_u;
  const mxArray *c1_d_y = NULL;
  SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc1_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_b_u = *(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_inData;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_createstruct("structure", 2, c1_sv0, 2, 1, 1),
                false);
  c1_c_u = c1_b_u.HEADER;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_createstruct("structure", 1, c1_sv33, 2, 1, 1),
                false);
  c1_d_u = c1_c_u.valid;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_d_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_c_y, 0, "valid", c1_d_y, 0);
  sf_mex_setfieldbynum(c1_b_y, 0, "HEADER", c1_c_y, 0);
  sf_mex_setfieldbynum(c1_b_y, 0, "DATA", c1_d_emlrt_marshallOut(chartInstance,
    &c1_b_u.DATA), 1);
  sf_mex_assign(&c1_mxArrayOutData, c1_b_y, false);
  return c1_mxArrayOutData;
}

static void c1_b_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_y, const char_T *c1_identifier,
  PRESCAN_V2X_FIXED_BSM_MESSAGE *c1_c_y)
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_y), &c1_thisId, c1_c_y);
  sf_mex_destroy(&c1_b_y);
}

static void c1_c_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  PRESCAN_V2X_FIXED_BSM_MESSAGE *c1_b_y)
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fParent = c1_parentId;
  c1_thisId.bParentIsCell = false;
  sf_mex_check_struct(c1_parentId, c1_b_u, 2, c1_sv4, 0U, NULL);
  c1_thisId.fIdentifier = "HEADER";
  c1_b_y->HEADER = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "HEADER", "HEADER", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "DATA";
  c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u, "DATA",
    "DATA", 0)), &c1_thisId, &c1_b_y->DATA);
  sf_mex_destroy(&c1_b_u);
}

static PRESCAN_HEADER c1_d_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId)
{
  PRESCAN_HEADER c1_b_y;
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[1] = { "valid" };

  c1_thisId.fParent = c1_parentId;
  c1_thisId.bParentIsCell = false;
  sf_mex_check_struct(c1_parentId, c1_b_u, 1, c1_fieldNames, 0U, NULL);
  c1_thisId.fIdentifier = "valid";
  c1_b_y.valid = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_b_u, "valid", "valid", 0)), &c1_thisId);
  sf_mex_destroy(&c1_b_u);
  return c1_b_y;
}

static boolean_T c1_e_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId)
{
  boolean_T c1_b_y;
  boolean_T c1_b0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), &c1_b0, 1, 11, 0U, 0, 0U, 0);
  c1_b_y = c1_b0;
  sf_mex_destroy(&c1_b_u);
  return c1_b_y;
}

static void c1_f_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  PRESCAN_V2X_FIXED_BSM_DATA *c1_b_y)
{
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[16] = { "msgID", "msgCnt", "id", "secMark",
    "latitude", "longitude", "elev", "accuracy", "speed", "heading", "angle",
    "accelSet", "brakes", "size", "safetyExt", "status" };

  c1_thisId.fParent = c1_parentId;
  c1_thisId.bParentIsCell = false;
  sf_mex_check_struct(c1_parentId, c1_b_u, 16, c1_fieldNames, 0U, NULL);
  c1_thisId.fIdentifier = "msgID";
  c1_b_y->msgID = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "msgID", "msgID", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "msgCnt";
  c1_b_y->msgCnt = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "msgCnt", "msgCnt", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "id";
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u, "id",
    "id", 0)), &c1_thisId, c1_b_y->id);
  c1_thisId.fIdentifier = "secMark";
  c1_b_y->secMark = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "secMark", "secMark", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "latitude";
  c1_b_y->latitude = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "latitude", "latitude", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "longitude";
  c1_b_y->longitude = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "longitude", "longitude", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "elev";
  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u, "elev",
    "elev", 0)), &c1_thisId, c1_b_y->elev);
  c1_thisId.fIdentifier = "accuracy";
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "accuracy", "accuracy", 0)), &c1_thisId, c1_b_y->accuracy);
  c1_thisId.fIdentifier = "speed";
  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "speed", "speed", 0)), &c1_thisId, c1_b_y->speed);
  c1_thisId.fIdentifier = "heading";
  c1_b_y->heading = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "heading", "heading", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "angle";
  c1_b_y->angle = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "angle", "angle", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "accelSet";
  c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "accelSet", "accelSet", 0)), &c1_thisId, c1_b_y->accelSet);
  c1_thisId.fIdentifier = "brakes";
  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "brakes", "brakes", 0)), &c1_thisId, c1_b_y->brakes);
  c1_thisId.fIdentifier = "size";
  c1_b_y->size = c1_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_b_u, "size", "size", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "safetyExt";
  c1_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "safetyExt", "safetyExt", 0)), &c1_thisId, &c1_b_y->safetyExt);
  c1_thisId.fIdentifier = "status";
  c1_jc_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "status", "status", 0)), &c1_thisId, &c1_b_y->status);
  sf_mex_destroy(&c1_b_u);
}

static int32_T c1_g_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_b_y;
  int32_T c1_i350;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), &c1_i350, 1, 6, 0U, 0, 0U, 0);
  c1_b_y = c1_i350;
  sf_mex_destroy(&c1_b_u);
  return c1_b_y;
}

static void c1_h_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[4])
{
  int8_T c1_iv3[4];
  int32_T c1_i351;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv3, 1, 2, 0U, 1, 0U, 1, 4);
  for (c1_i351 = 0; c1_i351 < 4; c1_i351++) {
    c1_b_y[c1_i351] = c1_iv3[c1_i351];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_i_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[2])
{
  int8_T c1_iv4[2];
  int32_T c1_i352;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv4, 1, 2, 0U, 1, 0U, 1, 2);
  for (c1_i352 = 0; c1_i352 < 2; c1_i352++) {
    c1_b_y[c1_i352] = c1_iv4[c1_i352];
  }

  sf_mex_destroy(&c1_b_u);
}

static int8_T c1_j_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId)
{
  int8_T c1_b_y;
  int8_T c1_i353;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), &c1_i353, 1, 2, 0U, 0, 0U, 0);
  c1_b_y = c1_i353;
  sf_mex_destroy(&c1_b_u);
  return c1_b_y;
}

static void c1_k_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[7])
{
  int8_T c1_iv5[7];
  int32_T c1_i354;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv5, 1, 2, 0U, 1, 0U, 1, 7);
  for (c1_i354 = 0; c1_i354 < 7; c1_i354++) {
    c1_b_y[c1_i354] = c1_iv5[c1_i354];
  }

  sf_mex_destroy(&c1_b_u);
}

static PRESCAN_V2X_FIXED_BSM_size c1_l_emlrt_marshallIn
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_b_u,
   const emlrtMsgIdentifier *c1_parentId)
{
  PRESCAN_V2X_FIXED_BSM_size c1_b_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fParent = c1_parentId;
  c1_thisId.bParentIsCell = false;
  sf_mex_check_struct(c1_parentId, c1_b_u, 2, c1_sv5, 0U, NULL);
  c1_thisId.fIdentifier = "width";
  c1_b_y.width = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_b_u, "width", "width", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "length";
  c1_b_y.length = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "length", "length", 0)), &c1_thisId);
  sf_mex_destroy(&c1_b_u);
  return c1_b_y;
}

static void c1_m_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  PRESCAN_V2X_FIXED_BSM_safetyExt *c1_b_y)
{
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[4] = { "events", "pathHistory",
    "pathPrediction", "theRTCM" };

  c1_thisId.fParent = c1_parentId;
  c1_thisId.bParentIsCell = false;
  sf_mex_check_struct(c1_parentId, c1_b_u, 4, c1_fieldNames, 0U, NULL);
  c1_thisId.fIdentifier = "events";
  c1_b_y->events = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "events", "events", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "pathHistory";
  c1_n_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "pathHistory", "pathHistory", 0)), &c1_thisId, &c1_b_y->pathHistory);
  c1_thisId.fIdentifier = "pathPrediction";
  c1_b_y->pathPrediction = c1_cb_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "pathPrediction", "pathPrediction", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "theRTCM";
  c1_db_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "theRTCM", "theRTCM", 0)), &c1_thisId, &c1_b_y->theRTCM);
  sf_mex_destroy(&c1_b_u);
}

static void c1_n_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  PRESCAN_V2X_FIXED_BSM_pathHistory *c1_b_y)
{
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[4] = { "initialPosition", "currGPSstatus",
    "itemCnt", "crumbData" };

  c1_thisId.fParent = c1_parentId;
  c1_thisId.bParentIsCell = false;
  sf_mex_check_struct(c1_parentId, c1_b_u, 4, c1_fieldNames, 0U, NULL);
  c1_thisId.fIdentifier = "initialPosition";
  c1_b_y->initialPosition = c1_o_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "initialPosition", "initialPosition", 0)),
    &c1_thisId);
  c1_thisId.fIdentifier = "currGPSstatus";
  c1_b_y->currGPSstatus = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "currGPSstatus", "currGPSstatus", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "itemCnt";
  c1_b_y->itemCnt = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "itemCnt", "itemCnt", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "crumbData";
  c1_q_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "crumbData", "crumbData", 0)), &c1_thisId, &c1_b_y->crumbData);
  sf_mex_destroy(&c1_b_u);
}

static PRESCAN_V2X_FIXED_BSM_initialPosition c1_o_emlrt_marshallIn
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_b_u,
   const emlrtMsgIdentifier *c1_parentId)
{
  PRESCAN_V2X_FIXED_BSM_initialPosition c1_b_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fParent = c1_parentId;
  c1_thisId.bParentIsCell = false;
  sf_mex_check_struct(c1_parentId, c1_b_u, 10, c1_sv6, 0U, NULL);
  c1_thisId.fIdentifier = "utcTime";
  c1_b_y.utcTime = c1_p_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "utcTime", "utcTime", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "longitude";
  c1_b_y.longitude = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "longitude", "longitude", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "latitude";
  c1_b_y.latitude = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "latitude", "latitude", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "elevation";
  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "elevation", "elevation", 0)), &c1_thisId, c1_b_y.elevation);
  c1_thisId.fIdentifier = "heading";
  c1_b_y.heading = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "heading", "heading", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "speed";
  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "speed", "speed", 0)), &c1_thisId, c1_b_y.speed);
  c1_thisId.fIdentifier = "posAccuracy";
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "posAccuracy", "posAccuracy", 0)), &c1_thisId, c1_b_y.posAccuracy);
  c1_thisId.fIdentifier = "timeConfidence";
  c1_b_y.timeConfidence = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "timeConfidence", "timeConfidence", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "posConfidence";
  c1_b_y.posConfidence = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "posConfidence", "posConfidence", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "speedConfidence";
  c1_b_y.speedConfidence = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "speedConfidence", "speedConfidence", 0)),
    &c1_thisId);
  sf_mex_destroy(&c1_b_u);
  return c1_b_y;
}

static PRESCAN_V2X_FIXED_BSM_utcTime c1_p_emlrt_marshallIn
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_b_u,
   const emlrtMsgIdentifier *c1_parentId)
{
  PRESCAN_V2X_FIXED_BSM_utcTime c1_b_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fParent = c1_parentId;
  c1_thisId.bParentIsCell = false;
  sf_mex_check_struct(c1_parentId, c1_b_u, 6, c1_sv7, 0U, NULL);
  c1_thisId.fIdentifier = "year";
  c1_b_y.year = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_b_u, "year", "year", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "month";
  c1_b_y.month = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_b_u, "month", "month", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "day";
  c1_b_y.day = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_b_u, "day", "day", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "hour";
  c1_b_y.hour = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_b_u, "hour", "hour", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "minute";
  c1_b_y.minute = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "minute", "minute", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "second";
  c1_b_y.second = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "second", "second", 0)), &c1_thisId);
  sf_mex_destroy(&c1_b_u);
  return c1_b_y;
}

static void c1_q_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  PRESCAN_V2X_FIXED_BSM_crumbData *c1_b_y)
{
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[10] = { "pathHistoryPointSets_01",
    "pathHistoryPointSets_02", "pathHistoryPointSets_03",
    "pathHistoryPointSets_04", "pathHistoryPointSets_05",
    "pathHistoryPointSets_06", "pathHistoryPointSets_07",
    "pathHistoryPointSets_08", "pathHistoryPointSets_09",
    "pathHistoryPointSets_10" };

  c1_thisId.fParent = c1_parentId;
  c1_thisId.bParentIsCell = false;
  sf_mex_check_struct(c1_parentId, c1_b_u, 10, c1_fieldNames, 0U, NULL);
  c1_thisId.fIdentifier = "pathHistoryPointSets_01";
  c1_r_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "pathHistoryPointSets_01", "pathHistoryPointSets_01", 0)), &c1_thisId,
                        c1_b_y->pathHistoryPointSets_01);
  c1_thisId.fIdentifier = "pathHistoryPointSets_02";
  c1_s_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "pathHistoryPointSets_02", "pathHistoryPointSets_02", 0)), &c1_thisId,
                        c1_b_y->pathHistoryPointSets_02);
  c1_thisId.fIdentifier = "pathHistoryPointSets_03";
  c1_t_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "pathHistoryPointSets_03", "pathHistoryPointSets_03", 0)), &c1_thisId,
                        c1_b_y->pathHistoryPointSets_03);
  c1_thisId.fIdentifier = "pathHistoryPointSets_04";
  c1_u_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "pathHistoryPointSets_04", "pathHistoryPointSets_04", 0)), &c1_thisId,
                        c1_b_y->pathHistoryPointSets_04);
  c1_thisId.fIdentifier = "pathHistoryPointSets_05";
  c1_v_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "pathHistoryPointSets_05", "pathHistoryPointSets_05", 0)), &c1_thisId,
                        c1_b_y->pathHistoryPointSets_05);
  c1_thisId.fIdentifier = "pathHistoryPointSets_06";
  c1_w_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "pathHistoryPointSets_06", "pathHistoryPointSets_06", 0)), &c1_thisId,
                        c1_b_y->pathHistoryPointSets_06);
  c1_thisId.fIdentifier = "pathHistoryPointSets_07";
  c1_x_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "pathHistoryPointSets_07", "pathHistoryPointSets_07", 0)), &c1_thisId,
                        c1_b_y->pathHistoryPointSets_07);
  c1_thisId.fIdentifier = "pathHistoryPointSets_08";
  c1_y_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "pathHistoryPointSets_08", "pathHistoryPointSets_08", 0)), &c1_thisId,
                        c1_b_y->pathHistoryPointSets_08);
  c1_thisId.fIdentifier = "pathHistoryPointSets_09";
  c1_ab_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "pathHistoryPointSets_09", "pathHistoryPointSets_09", 0)), &c1_thisId,
    c1_b_y->pathHistoryPointSets_09);
  c1_thisId.fIdentifier = "pathHistoryPointSets_10";
  c1_bb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "pathHistoryPointSets_10", "pathHistoryPointSets_10", 0)), &c1_thisId,
    c1_b_y->pathHistoryPointSets_10);
  sf_mex_destroy(&c1_b_u);
}

static void c1_r_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 c1_b_y[23])
{
  uint32_T c1_uv0[1];
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[7] = { "latOffset", "longOffset",
    "elevationOffset", "timeOffset", "posAccuracy", "heading", "speed" };

  int32_T c1_i355;
  c1_uv0[0] = 23U;
  c1_thisId.fParent = c1_parentId;
  c1_thisId.bParentIsCell = false;
  sf_mex_check_struct(c1_parentId, c1_b_u, 7, c1_fieldNames, 1U, c1_uv0);
  for (c1_i355 = 0; c1_i355 < 23; c1_i355++) {
    c1_thisId.fIdentifier = "latOffset";
    c1_b_y[c1_i355].latOffset = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c1_b_u, "latOffset", "latOffset", c1_i355)), &c1_thisId);
    c1_thisId.fIdentifier = "longOffset";
    c1_b_y[c1_i355].longOffset = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c1_b_u, "longOffset", "longOffset", c1_i355)), &c1_thisId);
    c1_thisId.fIdentifier = "elevationOffset";
    c1_b_y[c1_i355].elevationOffset = c1_g_emlrt_marshallIn(chartInstance,
      sf_mex_dup(sf_mex_getfield(c1_b_u, "elevationOffset", "elevationOffset",
      c1_i355)), &c1_thisId);
    c1_thisId.fIdentifier = "timeOffset";
    c1_b_y[c1_i355].timeOffset = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c1_b_u, "timeOffset", "timeOffset", c1_i355)), &c1_thisId);
    c1_thisId.fIdentifier = "posAccuracy";
    c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
      "posAccuracy", "posAccuracy", c1_i355)), &c1_thisId, c1_b_y[c1_i355].
                          posAccuracy);
    c1_thisId.fIdentifier = "heading";
    c1_b_y[c1_i355].heading = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c1_b_u, "heading", "heading", c1_i355)), &c1_thisId);
    c1_thisId.fIdentifier = "speed";
    c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
      "speed", "speed", c1_i355)), &c1_thisId, c1_b_y[c1_i355].speed);
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_s_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[345])
{
  int8_T c1_iv6[345];
  int32_T c1_i356;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv6, 1, 2, 0U, 1, 0U, 1, 345);
  for (c1_i356 = 0; c1_i356 < 345; c1_i356++) {
    c1_b_y[c1_i356] = c1_iv6[c1_i356];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_t_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[276])
{
  int8_T c1_iv7[276];
  int32_T c1_i357;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv7, 1, 2, 0U, 1, 0U, 1, 276);
  for (c1_i357 = 0; c1_i357 < 276; c1_i357++) {
    c1_b_y[c1_i357] = c1_iv7[c1_i357];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_u_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[184])
{
  int8_T c1_iv8[184];
  int32_T c1_i358;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv8, 1, 2, 0U, 1, 0U, 1, 184);
  for (c1_i358 = 0; c1_i358 < 184; c1_i358++) {
    c1_b_y[c1_i358] = c1_iv8[c1_i358];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_v_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[230])
{
  int8_T c1_iv9[230];
  int32_T c1_i359;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv9, 1, 2, 0U, 1, 0U, 1, 230);
  for (c1_i359 = 0; c1_i359 < 230; c1_i359++) {
    c1_b_y[c1_i359] = c1_iv9[c1_i359];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_w_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[138])
{
  int8_T c1_iv10[138];
  int32_T c1_i360;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv10, 1, 2, 0U, 1, 0U, 1,
                138);
  for (c1_i360 = 0; c1_i360 < 138; c1_i360++) {
    c1_b_y[c1_i360] = c1_iv10[c1_i360];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_x_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[242])
{
  int8_T c1_iv11[242];
  int32_T c1_i361;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv11, 1, 2, 0U, 1, 0U, 1,
                242);
  for (c1_i361 = 0; c1_i361 < 242; c1_i361++) {
    c1_b_y[c1_i361] = c1_iv11[c1_i361];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_y_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[161])
{
  int8_T c1_iv12[161];
  int32_T c1_i362;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv12, 1, 2, 0U, 1, 0U, 1,
                161);
  for (c1_i362 = 0; c1_i362 < 161; c1_i362++) {
    c1_b_y[c1_i362] = c1_iv12[c1_i362];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_ab_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[196])
{
  int8_T c1_iv13[196];
  int32_T c1_i363;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv13, 1, 2, 0U, 1, 0U, 1,
                196);
  for (c1_i363 = 0; c1_i363 < 196; c1_i363++) {
    c1_b_y[c1_i363] = c1_iv13[c1_i363];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_bb_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[104])
{
  int8_T c1_iv14[104];
  int32_T c1_i364;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv14, 1, 2, 0U, 1, 0U, 1,
                104);
  for (c1_i364 = 0; c1_i364 < 104; c1_i364++) {
    c1_b_y[c1_i364] = c1_iv14[c1_i364];
  }

  sf_mex_destroy(&c1_b_u);
}

static PRESCAN_V2X_FIXED_BSM_pathPrediction c1_cb_emlrt_marshallIn
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_b_u,
   const emlrtMsgIdentifier *c1_parentId)
{
  PRESCAN_V2X_FIXED_BSM_pathPrediction c1_b_y;
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[2] = { "radiusOfCurve", "confidence" };

  c1_thisId.fParent = c1_parentId;
  c1_thisId.bParentIsCell = false;
  sf_mex_check_struct(c1_parentId, c1_b_u, 2, c1_fieldNames, 0U, NULL);
  c1_thisId.fIdentifier = "radiusOfCurve";
  c1_b_y.radiusOfCurve = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "radiusOfCurve", "radiusOfCurve", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "confidence";
  c1_b_y.confidence = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "confidence", "confidence", 0)), &c1_thisId);
  sf_mex_destroy(&c1_b_u);
  return c1_b_y;
}

static void c1_db_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  PRESCAN_V2X_FIXED_BSM_theRTCM *c1_b_y)
{
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[32] = { "anchorPoint", "rtcmHeader",
    "msg1001", "msg1002", "msg1003", "msg1004", "msg1005", "msg1006", "msg1007",
    "msg1008", "msg1009", "msg1010", "msg1011", "msg1012", "msg1013", "msg1014",
    "msg1015", "msg1016", "msg1017", "msg1019", "msg1020", "msg1021", "msg1022",
    "msg1023", "msg1024", "msg1025", "msg1026", "msg1027", "msg1029", "msg1030",
    "msg1031", "msg1032" };

  c1_thisId.fParent = c1_parentId;
  c1_thisId.bParentIsCell = false;
  sf_mex_check_struct(c1_parentId, c1_b_u, 32, c1_fieldNames, 0U, NULL);
  c1_thisId.fIdentifier = "anchorPoint";
  c1_b_y->anchorPoint = c1_eb_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "anchorPoint", "anchorPoint", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "rtcmHeader";
  c1_fb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "rtcmHeader", "rtcmHeader", 0)), &c1_thisId, c1_b_y->rtcmHeader);
  c1_thisId.fIdentifier = "msg1001";
  c1_gb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "msg1001", "msg1001", 0)), &c1_thisId, c1_b_y->msg1001);
  c1_thisId.fIdentifier = "msg1002";
  c1_hb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "msg1002", "msg1002", 0)), &c1_thisId, c1_b_y->msg1002);
  c1_thisId.fIdentifier = "msg1003";
  c1_ib_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "msg1003", "msg1003", 0)), &c1_thisId, c1_b_y->msg1003);
  c1_thisId.fIdentifier = "msg1004";
  c1_jb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "msg1004", "msg1004", 0)), &c1_thisId, c1_b_y->msg1004);
  c1_thisId.fIdentifier = "msg1005";
  c1_kb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "msg1005", "msg1005", 0)), &c1_thisId, c1_b_y->msg1005);
  c1_thisId.fIdentifier = "msg1006";
  c1_lb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "msg1006", "msg1006", 0)), &c1_thisId, c1_b_y->msg1006);
  c1_thisId.fIdentifier = "msg1007";
  c1_mb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "msg1007", "msg1007", 0)), &c1_thisId, c1_b_y->msg1007);
  c1_thisId.fIdentifier = "msg1008";
  c1_nb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "msg1008", "msg1008", 0)), &c1_thisId, c1_b_y->msg1008);
  c1_thisId.fIdentifier = "msg1009";
  c1_ob_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "msg1009", "msg1009", 0)), &c1_thisId, c1_b_y->msg1009);
  c1_thisId.fIdentifier = "msg1010";
  c1_pb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "msg1010", "msg1010", 0)), &c1_thisId, c1_b_y->msg1010);
  c1_thisId.fIdentifier = "msg1011";
  c1_qb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "msg1011", "msg1011", 0)), &c1_thisId, c1_b_y->msg1011);
  c1_thisId.fIdentifier = "msg1012";
  c1_rb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "msg1012", "msg1012", 0)), &c1_thisId, c1_b_y->msg1012);
  c1_thisId.fIdentifier = "msg1013";
  c1_sb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "msg1013", "msg1013", 0)), &c1_thisId, c1_b_y->msg1013);
  c1_thisId.fIdentifier = "msg1014";
  c1_tb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "msg1014", "msg1014", 0)), &c1_thisId, c1_b_y->msg1014);
  c1_thisId.fIdentifier = "msg1015";
  c1_ub_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "msg1015", "msg1015", 0)), &c1_thisId, c1_b_y->msg1015);
  c1_thisId.fIdentifier = "msg1016";
  c1_vb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "msg1016", "msg1016", 0)), &c1_thisId, c1_b_y->msg1016);
  c1_thisId.fIdentifier = "msg1017";
  c1_wb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "msg1017", "msg1017", 0)), &c1_thisId, c1_b_y->msg1017);
  c1_thisId.fIdentifier = "msg1019";
  c1_xb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "msg1019", "msg1019", 0)), &c1_thisId, c1_b_y->msg1019);
  c1_thisId.fIdentifier = "msg1020";
  c1_yb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "msg1020", "msg1020", 0)), &c1_thisId, c1_b_y->msg1020);
  c1_thisId.fIdentifier = "msg1021";
  c1_xb_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "msg1021", "msg1021", 0)), &c1_thisId, c1_b_y->msg1021);
  c1_thisId.fIdentifier = "msg1022";
  c1_ac_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "msg1022", "msg1022", 0)), &c1_thisId, c1_b_y->msg1022);
  c1_thisId.fIdentifier = "msg1023";
  c1_bc_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "msg1023", "msg1023", 0)), &c1_thisId, c1_b_y->msg1023);
  c1_thisId.fIdentifier = "msg1024";
  c1_cc_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "msg1024", "msg1024", 0)), &c1_thisId, c1_b_y->msg1024);
  c1_thisId.fIdentifier = "msg1025";
  c1_dc_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "msg1025", "msg1025", 0)), &c1_thisId, c1_b_y->msg1025);
  c1_thisId.fIdentifier = "msg1026";
  c1_ec_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "msg1026", "msg1026", 0)), &c1_thisId, c1_b_y->msg1026);
  c1_thisId.fIdentifier = "msg1027";
  c1_fc_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "msg1027", "msg1027", 0)), &c1_thisId, c1_b_y->msg1027);
  c1_thisId.fIdentifier = "msg1029";
  c1_ub_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "msg1029", "msg1029", 0)), &c1_thisId, c1_b_y->msg1029);
  c1_thisId.fIdentifier = "msg1030";
  c1_gc_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "msg1030", "msg1030", 0)), &c1_thisId, c1_b_y->msg1030);
  c1_thisId.fIdentifier = "msg1031";
  c1_hc_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "msg1031", "msg1031", 0)), &c1_thisId, c1_b_y->msg1031);
  c1_thisId.fIdentifier = "msg1032";
  c1_ic_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "msg1032", "msg1032", 0)), &c1_thisId, c1_b_y->msg1032);
  sf_mex_destroy(&c1_b_u);
}

static PRESCAN_V2X_FIXED_BSM_anchorPoint c1_eb_emlrt_marshallIn
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_b_u,
   const emlrtMsgIdentifier *c1_parentId)
{
  PRESCAN_V2X_FIXED_BSM_anchorPoint c1_b_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fParent = c1_parentId;
  c1_thisId.bParentIsCell = false;
  sf_mex_check_struct(c1_parentId, c1_b_u, 10, c1_sv6, 0U, NULL);
  c1_thisId.fIdentifier = "utcTime";
  c1_b_y.utcTime = c1_p_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "utcTime", "utcTime", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "longitude";
  c1_b_y.longitude = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "longitude", "longitude", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "latitude";
  c1_b_y.latitude = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "latitude", "latitude", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "elevation";
  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "elevation", "elevation", 0)), &c1_thisId, c1_b_y.elevation);
  c1_thisId.fIdentifier = "heading";
  c1_b_y.heading = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "heading", "heading", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "speed";
  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "speed", "speed", 0)), &c1_thisId, c1_b_y.speed);
  c1_thisId.fIdentifier = "posAccuracy";
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "posAccuracy", "posAccuracy", 0)), &c1_thisId, c1_b_y.posAccuracy);
  c1_thisId.fIdentifier = "timeConfidence";
  c1_b_y.timeConfidence = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "timeConfidence", "timeConfidence", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "posConfidence";
  c1_b_y.posConfidence = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "posConfidence", "posConfidence", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "speedConfidence";
  c1_b_y.speedConfidence = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "speedConfidence", "speedConfidence", 0)),
    &c1_thisId);
  sf_mex_destroy(&c1_b_u);
  return c1_b_y;
}

static void c1_fb_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[5])
{
  int8_T c1_iv15[5];
  int32_T c1_i365;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv15, 1, 2, 0U, 1, 0U, 1, 5);
  for (c1_i365 = 0; c1_i365 < 5; c1_i365++) {
    c1_b_y[c1_i365] = c1_iv15[c1_i365];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_gb_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[124])
{
  int8_T c1_iv16[124];
  int32_T c1_i366;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv16, 1, 2, 0U, 1, 0U, 1,
                124);
  for (c1_i366 = 0; c1_i366 < 124; c1_i366++) {
    c1_b_y[c1_i366] = c1_iv16[c1_i366];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_hb_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[156])
{
  int8_T c1_iv17[156];
  int32_T c1_i367;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv17, 1, 2, 0U, 1, 0U, 1,
                156);
  for (c1_i367 = 0; c1_i367 < 156; c1_i367++) {
    c1_b_y[c1_i367] = c1_iv17[c1_i367];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_ib_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[210])
{
  int8_T c1_iv18[210];
  int32_T c1_i368;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv18, 1, 2, 0U, 1, 0U, 1,
                210);
  for (c1_i368 = 0; c1_i368 < 210; c1_i368++) {
    c1_b_y[c1_i368] = c1_iv18[c1_i368];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_jb_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[258])
{
  int8_T c1_iv19[258];
  int32_T c1_i369;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv19, 1, 2, 0U, 1, 0U, 1,
                258);
  for (c1_i369 = 0; c1_i369 < 258; c1_i369++) {
    c1_b_y[c1_i369] = c1_iv19[c1_i369];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_kb_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[19])
{
  int8_T c1_iv20[19];
  int32_T c1_i370;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv20, 1, 2, 0U, 1, 0U, 1, 19);
  for (c1_i370 = 0; c1_i370 < 19; c1_i370++) {
    c1_b_y[c1_i370] = c1_iv20[c1_i370];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_lb_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[21])
{
  int8_T c1_iv21[21];
  int32_T c1_i371;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv21, 1, 2, 0U, 1, 0U, 1, 21);
  for (c1_i371 = 0; c1_i371 < 21; c1_i371++) {
    c1_b_y[c1_i371] = c1_iv21[c1_i371];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_mb_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[36])
{
  int8_T c1_iv22[36];
  int32_T c1_i372;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv22, 1, 2, 0U, 1, 0U, 1, 36);
  for (c1_i372 = 0; c1_i372 < 36; c1_i372++) {
    c1_b_y[c1_i372] = c1_iv22[c1_i372];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_nb_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[68])
{
  int8_T c1_iv23[68];
  int32_T c1_i373;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv23, 1, 2, 0U, 1, 0U, 1, 68);
  for (c1_i373 = 0; c1_i373 < 68; c1_i373++) {
    c1_b_y[c1_i373] = c1_iv23[c1_i373];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_ob_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[136])
{
  int8_T c1_iv24[136];
  int32_T c1_i374;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv24, 1, 2, 0U, 1, 0U, 1,
                136);
  for (c1_i374 = 0; c1_i374 < 136; c1_i374++) {
    c1_b_y[c1_i374] = c1_iv24[c1_i374];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_pb_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[166])
{
  int8_T c1_iv25[166];
  int32_T c1_i375;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv25, 1, 2, 0U, 1, 0U, 1,
                166);
  for (c1_i375 = 0; c1_i375 < 166; c1_i375++) {
    c1_b_y[c1_i375] = c1_iv25[c1_i375];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_qb_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[222])
{
  int8_T c1_iv26[222];
  int32_T c1_i376;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv26, 1, 2, 0U, 1, 0U, 1,
                222);
  for (c1_i376 = 0; c1_i376 < 222; c1_i376++) {
    c1_b_y[c1_i376] = c1_iv26[c1_i376];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_rb_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[268])
{
  int8_T c1_iv27[268];
  int32_T c1_i377;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv27, 1, 2, 0U, 1, 0U, 1,
                268);
  for (c1_i377 = 0; c1_i377 < 268; c1_i377++) {
    c1_b_y[c1_i377] = c1_iv27[c1_i377];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_sb_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[27])
{
  int8_T c1_iv28[27];
  int32_T c1_i378;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv28, 1, 2, 0U, 1, 0U, 1, 27);
  for (c1_i378 = 0; c1_i378 < 27; c1_i378++) {
    c1_b_y[c1_i378] = c1_iv28[c1_i378];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_tb_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[15])
{
  int8_T c1_iv29[15];
  int32_T c1_i379;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv29, 1, 2, 0U, 1, 0U, 1, 15);
  for (c1_i379 = 0; c1_i379 < 15; c1_i379++) {
    c1_b_y[c1_i379] = c1_iv29[c1_i379];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_ub_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[69])
{
  int8_T c1_iv30[69];
  int32_T c1_i380;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv30, 1, 2, 0U, 1, 0U, 1, 69);
  for (c1_i380 = 0; c1_i380 < 69; c1_i380++) {
    c1_b_y[c1_i380] = c1_iv30[c1_i380];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_vb_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[81])
{
  int8_T c1_iv31[81];
  int32_T c1_i381;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv31, 1, 2, 0U, 1, 0U, 1, 81);
  for (c1_i381 = 0; c1_i381 < 81; c1_i381++) {
    c1_b_y[c1_i381] = c1_iv31[c1_i381];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_wb_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[115])
{
  int8_T c1_iv32[115];
  int32_T c1_i382;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv32, 1, 2, 0U, 1, 0U, 1,
                115);
  for (c1_i382 = 0; c1_i382 < 115; c1_i382++) {
    c1_b_y[c1_i382] = c1_iv32[c1_i382];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_xb_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[62])
{
  int8_T c1_iv33[62];
  int32_T c1_i383;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv33, 1, 2, 0U, 1, 0U, 1, 62);
  for (c1_i383 = 0; c1_i383 < 62; c1_i383++) {
    c1_b_y[c1_i383] = c1_iv33[c1_i383];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_yb_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[45])
{
  int8_T c1_iv34[45];
  int32_T c1_i384;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv34, 1, 2, 0U, 1, 0U, 1, 45);
  for (c1_i384 = 0; c1_i384 < 45; c1_i384++) {
    c1_b_y[c1_i384] = c1_iv34[c1_i384];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_ac_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[75])
{
  int8_T c1_iv35[75];
  int32_T c1_i385;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv35, 1, 2, 0U, 1, 0U, 1, 75);
  for (c1_i385 = 0; c1_i385 < 75; c1_i385++) {
    c1_b_y[c1_i385] = c1_iv35[c1_i385];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_bc_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[73])
{
  int8_T c1_iv36[73];
  int32_T c1_i386;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv36, 1, 2, 0U, 1, 0U, 1, 73);
  for (c1_i386 = 0; c1_i386 < 73; c1_i386++) {
    c1_b_y[c1_i386] = c1_iv36[c1_i386];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_cc_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[74])
{
  int8_T c1_iv37[74];
  int32_T c1_i387;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv37, 1, 2, 0U, 1, 0U, 1, 74);
  for (c1_i387 = 0; c1_i387 < 74; c1_i387++) {
    c1_b_y[c1_i387] = c1_iv37[c1_i387];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_dc_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[25])
{
  int8_T c1_iv38[25];
  int32_T c1_i388;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv38, 1, 2, 0U, 1, 0U, 1, 25);
  for (c1_i388 = 0; c1_i388 < 25; c1_i388++) {
    c1_b_y[c1_i388] = c1_iv38[c1_i388];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_ec_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[30])
{
  int8_T c1_iv39[30];
  int32_T c1_i389;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv39, 1, 2, 0U, 1, 0U, 1, 30);
  for (c1_i389 = 0; c1_i389 < 30; c1_i389++) {
    c1_b_y[c1_i389] = c1_iv39[c1_i389];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_fc_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[33])
{
  int8_T c1_iv40[33];
  int32_T c1_i390;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv40, 1, 2, 0U, 1, 0U, 1, 33);
  for (c1_i390 = 0; c1_i390 < 33; c1_i390++) {
    c1_b_y[c1_i390] = c1_iv40[c1_i390];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_gc_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[105])
{
  int8_T c1_iv41[105];
  int32_T c1_i391;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv41, 1, 2, 0U, 1, 0U, 1,
                105);
  for (c1_i391 = 0; c1_i391 < 105; c1_i391++) {
    c1_b_y[c1_i391] = c1_iv41[c1_i391];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_hc_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[107])
{
  int8_T c1_iv42[107];
  int32_T c1_i392;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv42, 1, 2, 0U, 1, 0U, 1,
                107);
  for (c1_i392 = 0; c1_i392 < 107; c1_i392++) {
    c1_b_y[c1_i392] = c1_iv42[c1_i392];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_ic_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[20])
{
  int8_T c1_iv43[20];
  int32_T c1_i393;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv43, 1, 2, 0U, 1, 0U, 1, 20);
  for (c1_i393 = 0; c1_i393 < 20; c1_i393++) {
    c1_b_y[c1_i393] = c1_iv43[c1_i393];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_jc_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  PRESCAN_V2X_FIXED_BSM_status *c1_b_y)
{
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[22] = { "lights", "lightBar", "wipers",
    "brakeStatus", "brakePressure", "roadFriction", "sunData", "rainData",
    "airTemp", "airPres", "steering", "accelSets", "object", "fullPos",
    "throttlePos", "speedHeadC", "speedC", "vehicleData", "vehicleIdent",
    "j1939data", "weatherReport", "gpsStatus" };

  c1_thisId.fParent = c1_parentId;
  c1_thisId.bParentIsCell = false;
  sf_mex_check_struct(c1_parentId, c1_b_u, 22, c1_fieldNames, 0U, NULL);
  c1_thisId.fIdentifier = "lights";
  c1_b_y->lights = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "lights", "lights", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "lightBar";
  c1_b_y->lightBar = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "lightBar", "lightBar", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "wipers";
  c1_b_y->wipers = c1_kc_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "wipers", "wipers", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "brakeStatus";
  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "brakeStatus", "brakeStatus", 0)), &c1_thisId, c1_b_y->brakeStatus);
  c1_thisId.fIdentifier = "brakePressure";
  c1_b_y->brakePressure = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "brakePressure", "brakePressure", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "roadFriction";
  c1_b_y->roadFriction = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "roadFriction", "roadFriction", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "sunData";
  c1_b_y->sunData = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "sunData", "sunData", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "rainData";
  c1_b_y->rainData = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "rainData", "rainData", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "airTemp";
  c1_b_y->airTemp = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "airTemp", "airTemp", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "airPres";
  c1_b_y->airPres = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "airPres", "airPres", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "steering";
  c1_b_y->steering = c1_lc_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "steering", "steering", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "accelSets";
  c1_b_y->accelSets = c1_mc_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "accelSets", "accelSets", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "object";
  c1_b_y->object = c1_pc_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "object", "object", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "fullPos";
  c1_b_y->fullPos = c1_rc_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "fullPos", "fullPos", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "throttlePos";
  c1_b_y->throttlePos = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "throttlePos", "throttlePos", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "speedHeadC";
  c1_b_y->speedHeadC = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "speedHeadC", "speedHeadC", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "speedC";
  c1_b_y->speedC = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "speedC", "speedC", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "vehicleData";
  c1_b_y->vehicleData = c1_sc_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "vehicleData", "vehicleData", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "vehicleIdent";
  c1_uc_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "vehicleIdent", "vehicleIdent", 0)), &c1_thisId, &c1_b_y->vehicleIdent);
  c1_thisId.fIdentifier = "j1939data";
  c1_ad_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "j1939data", "j1939data", 0)), &c1_thisId, &c1_b_y->j1939data);
  c1_thisId.fIdentifier = "weatherReport";
  c1_b_y->weatherReport = c1_dd_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "weatherReport", "weatherReport", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "gpsStatus";
  c1_b_y->gpsStatus = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "gpsStatus", "gpsStatus", 0)), &c1_thisId);
  sf_mex_destroy(&c1_b_u);
}

static PRESCAN_V2X_FIXED_BSM_wipers c1_kc_emlrt_marshallIn
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_b_u,
   const emlrtMsgIdentifier *c1_parentId)
{
  PRESCAN_V2X_FIXED_BSM_wipers c1_b_y;
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[4] = { "statusFront", "rateFront",
    "statusRear", "rateRear" };

  c1_thisId.fParent = c1_parentId;
  c1_thisId.bParentIsCell = false;
  sf_mex_check_struct(c1_parentId, c1_b_u, 4, c1_fieldNames, 0U, NULL);
  c1_thisId.fIdentifier = "statusFront";
  c1_b_y.statusFront = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "statusFront", "statusFront", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "rateFront";
  c1_b_y.rateFront = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "rateFront", "rateFront", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "statusRear";
  c1_b_y.statusRear = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "statusRear", "statusRear", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "rateRear";
  c1_b_y.rateRear = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "rateRear", "rateRear", 0)), &c1_thisId);
  sf_mex_destroy(&c1_b_u);
  return c1_b_y;
}

static PRESCAN_V2X_FIXED_BSM_steering c1_lc_emlrt_marshallIn
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_b_u,
   const emlrtMsgIdentifier *c1_parentId)
{
  PRESCAN_V2X_FIXED_BSM_steering c1_b_y;
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[4] = { "angle", "confidence", "rate",
    "wheels" };

  c1_thisId.fParent = c1_parentId;
  c1_thisId.bParentIsCell = false;
  sf_mex_check_struct(c1_parentId, c1_b_u, 4, c1_fieldNames, 0U, NULL);
  c1_thisId.fIdentifier = "angle";
  c1_b_y.angle = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_b_u, "angle", "angle", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "confidence";
  c1_b_y.confidence = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "confidence", "confidence", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "rate";
  c1_b_y.rate = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_b_u, "rate", "rate", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "wheels";
  c1_b_y.wheels = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "wheels", "wheels", 0)), &c1_thisId);
  sf_mex_destroy(&c1_b_u);
  return c1_b_y;
}

static PRESCAN_V2X_FIXED_BSM_accelSets c1_mc_emlrt_marshallIn
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_b_u,
   const emlrtMsgIdentifier *c1_parentId)
{
  PRESCAN_V2X_FIXED_BSM_accelSets c1_b_y;
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[5] = { "accel4way", "vertAccelThres",
    "yawRateCon", "hozAccelCon", "confidenceSet" };

  c1_thisId.fParent = c1_parentId;
  c1_thisId.bParentIsCell = false;
  sf_mex_check_struct(c1_parentId, c1_b_u, 5, c1_fieldNames, 0U, NULL);
  c1_thisId.fIdentifier = "accel4way";
  c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "accel4way", "accel4way", 0)), &c1_thisId, c1_b_y.accel4way);
  c1_thisId.fIdentifier = "vertAccelThres";
  c1_b_y.vertAccelThres = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "vertAccelThres", "vertAccelThres", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "yawRateCon";
  c1_b_y.yawRateCon = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "yawRateCon", "yawRateCon", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "hozAccelCon";
  c1_b_y.hozAccelCon = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "hozAccelCon", "hozAccelCon", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "confidenceSet";
  c1_b_y.confidenceSet = c1_nc_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "confidenceSet", "confidenceSet", 0)), &c1_thisId);
  sf_mex_destroy(&c1_b_u);
  return c1_b_y;
}

static PRESCAN_V2X_FIXED_BSM_confidenceSet c1_nc_emlrt_marshallIn
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_b_u,
   const emlrtMsgIdentifier *c1_parentId)
{
  PRESCAN_V2X_FIXED_BSM_confidenceSet c1_b_y;
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[6] = { "accelConfidence", "speedConfidence",
    "timeConfidence", "posConfidence", "steerConfidence", "throttleConfidence" };

  c1_thisId.fParent = c1_parentId;
  c1_thisId.bParentIsCell = false;
  sf_mex_check_struct(c1_parentId, c1_b_u, 6, c1_fieldNames, 0U, NULL);
  c1_thisId.fIdentifier = "accelConfidence";
  c1_b_y.accelConfidence = c1_oc_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "accelConfidence", "accelConfidence", 0)),
    &c1_thisId);
  c1_thisId.fIdentifier = "speedConfidence";
  c1_b_y.speedConfidence = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "speedConfidence", "speedConfidence", 0)),
    &c1_thisId);
  c1_thisId.fIdentifier = "timeConfidence";
  c1_b_y.timeConfidence = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "timeConfidence", "timeConfidence", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "posConfidence";
  c1_b_y.posConfidence = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "posConfidence", "posConfidence", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "steerConfidence";
  c1_b_y.steerConfidence = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "steerConfidence", "steerConfidence", 0)),
    &c1_thisId);
  c1_thisId.fIdentifier = "throttleConfidence";
  c1_b_y.throttleConfidence = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "throttleConfidence", "throttleConfidence", 0)),
    &c1_thisId);
  sf_mex_destroy(&c1_b_u);
  return c1_b_y;
}

static PRESCAN_V2X_FIXED_BSM_accelConfidence c1_oc_emlrt_marshallIn
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_b_u,
   const emlrtMsgIdentifier *c1_parentId)
{
  PRESCAN_V2X_FIXED_BSM_accelConfidence c1_b_y;
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[3] = { "yawRate", "acceleration",
    "steeringWheelAngle" };

  c1_thisId.fParent = c1_parentId;
  c1_thisId.bParentIsCell = false;
  sf_mex_check_struct(c1_parentId, c1_b_u, 3, c1_fieldNames, 0U, NULL);
  c1_thisId.fIdentifier = "yawRate";
  c1_b_y.yawRate = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "yawRate", "yawRate", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "acceleration";
  c1_b_y.acceleration = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "acceleration", "acceleration", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "steeringWheelAngle";
  c1_b_y.steeringWheelAngle = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "steeringWheelAngle", "steeringWheelAngle", 0)),
    &c1_thisId);
  sf_mex_destroy(&c1_b_u);
  return c1_b_y;
}

static PRESCAN_V2X_FIXED_BSM_object c1_pc_emlrt_marshallIn
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_b_u,
   const emlrtMsgIdentifier *c1_parentId)
{
  PRESCAN_V2X_FIXED_BSM_object c1_b_y;
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[3] = { "obDist", "obDirect", "dateTime" };

  c1_thisId.fParent = c1_parentId;
  c1_thisId.bParentIsCell = false;
  sf_mex_check_struct(c1_parentId, c1_b_u, 3, c1_fieldNames, 0U, NULL);
  c1_thisId.fIdentifier = "obDist";
  c1_b_y.obDist = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "obDist", "obDist", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "obDirect";
  c1_b_y.obDirect = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "obDirect", "obDirect", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "dateTime";
  c1_b_y.dateTime = c1_qc_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "dateTime", "dateTime", 0)), &c1_thisId);
  sf_mex_destroy(&c1_b_u);
  return c1_b_y;
}

static PRESCAN_V2X_FIXED_BSM_dateTime c1_qc_emlrt_marshallIn
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_b_u,
   const emlrtMsgIdentifier *c1_parentId)
{
  PRESCAN_V2X_FIXED_BSM_dateTime c1_b_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fParent = c1_parentId;
  c1_thisId.bParentIsCell = false;
  sf_mex_check_struct(c1_parentId, c1_b_u, 6, c1_sv7, 0U, NULL);
  c1_thisId.fIdentifier = "year";
  c1_b_y.year = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_b_u, "year", "year", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "month";
  c1_b_y.month = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_b_u, "month", "month", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "day";
  c1_b_y.day = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_b_u, "day", "day", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "hour";
  c1_b_y.hour = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_b_u, "hour", "hour", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "minute";
  c1_b_y.minute = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "minute", "minute", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "second";
  c1_b_y.second = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "second", "second", 0)), &c1_thisId);
  sf_mex_destroy(&c1_b_u);
  return c1_b_y;
}

static PRESCAN_V2X_FIXED_BSM_fullPos c1_rc_emlrt_marshallIn
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_b_u,
   const emlrtMsgIdentifier *c1_parentId)
{
  PRESCAN_V2X_FIXED_BSM_fullPos c1_b_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fParent = c1_parentId;
  c1_thisId.bParentIsCell = false;
  sf_mex_check_struct(c1_parentId, c1_b_u, 10, c1_sv6, 0U, NULL);
  c1_thisId.fIdentifier = "utcTime";
  c1_b_y.utcTime = c1_p_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "utcTime", "utcTime", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "longitude";
  c1_b_y.longitude = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "longitude", "longitude", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "latitude";
  c1_b_y.latitude = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "latitude", "latitude", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "elevation";
  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "elevation", "elevation", 0)), &c1_thisId, c1_b_y.elevation);
  c1_thisId.fIdentifier = "heading";
  c1_b_y.heading = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "heading", "heading", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "speed";
  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "speed", "speed", 0)), &c1_thisId, c1_b_y.speed);
  c1_thisId.fIdentifier = "posAccuracy";
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "posAccuracy", "posAccuracy", 0)), &c1_thisId, c1_b_y.posAccuracy);
  c1_thisId.fIdentifier = "timeConfidence";
  c1_b_y.timeConfidence = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "timeConfidence", "timeConfidence", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "posConfidence";
  c1_b_y.posConfidence = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "posConfidence", "posConfidence", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "speedConfidence";
  c1_b_y.speedConfidence = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "speedConfidence", "speedConfidence", 0)),
    &c1_thisId);
  sf_mex_destroy(&c1_b_u);
  return c1_b_y;
}

static PRESCAN_V2X_FIXED_BSM_vehicleData c1_sc_emlrt_marshallIn
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_b_u,
   const emlrtMsgIdentifier *c1_parentId)
{
  PRESCAN_V2X_FIXED_BSM_vehicleData c1_b_y;
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[5] = { "height", "bumpers", "mass",
    "trailerWeight", "type" };

  c1_thisId.fParent = c1_parentId;
  c1_thisId.bParentIsCell = false;
  sf_mex_check_struct(c1_parentId, c1_b_u, 5, c1_fieldNames, 0U, NULL);
  c1_thisId.fIdentifier = "height";
  c1_b_y.height = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "height", "height", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "bumpers";
  c1_b_y.bumpers = c1_tc_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "bumpers", "bumpers", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "mass";
  c1_b_y.mass = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_b_u, "mass", "mass", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "trailerWeight";
  c1_b_y.trailerWeight = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "trailerWeight", "trailerWeight", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "type";
  c1_b_y.type = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_b_u, "type", "type", 0)), &c1_thisId);
  sf_mex_destroy(&c1_b_u);
  return c1_b_y;
}

static PRESCAN_V2X_FIXED_BSM_bumpers c1_tc_emlrt_marshallIn
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_b_u,
   const emlrtMsgIdentifier *c1_parentId)
{
  PRESCAN_V2X_FIXED_BSM_bumpers c1_b_y;
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[2] = { "frnt", "rear" };

  c1_thisId.fParent = c1_parentId;
  c1_thisId.bParentIsCell = false;
  sf_mex_check_struct(c1_parentId, c1_b_u, 2, c1_fieldNames, 0U, NULL);
  c1_thisId.fIdentifier = "frnt";
  c1_b_y.frnt = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_b_u, "frnt", "frnt", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "rear";
  c1_b_y.rear = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_b_u, "rear", "rear", 0)), &c1_thisId);
  sf_mex_destroy(&c1_b_u);
  return c1_b_y;
}

static void c1_uc_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  PRESCAN_V2X_FIXED_BSM_vehicleIdent *c1_b_y)
{
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[6] = { "name", "vin", "ownerCode", "id",
    "vehicleType", "vehicleClass" };

  c1_thisId.fParent = c1_parentId;
  c1_thisId.bParentIsCell = false;
  sf_mex_check_struct(c1_parentId, c1_b_u, 6, c1_fieldNames, 0U, NULL);
  c1_thisId.fIdentifier = "name";
  c1_vc_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "name", "name", 0)), &c1_thisId, c1_b_y->name);
  c1_thisId.fIdentifier = "vin";
  c1_wc_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u, "vin",
    "vin", 0)), &c1_thisId, c1_b_y->vin);
  c1_thisId.fIdentifier = "ownerCode";
  c1_xc_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "ownerCode", "ownerCode", 0)), &c1_thisId, c1_b_y->ownerCode);
  c1_thisId.fIdentifier = "id";
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u, "id",
    "id", 0)), &c1_thisId, c1_b_y->id);
  c1_thisId.fIdentifier = "vehicleType";
  c1_b_y->vehicleType = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "vehicleType", "vehicleType", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "vehicleClass";
  c1_b_y->vehicleClass = c1_yc_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "vehicleClass", "vehicleClass", 0)), &c1_thisId);
  sf_mex_destroy(&c1_b_u);
}

static void c1_vc_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[63])
{
  int8_T c1_iv44[63];
  int32_T c1_i394;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv44, 1, 2, 0U, 1, 0U, 1, 63);
  for (c1_i394 = 0; c1_i394 < 63; c1_i394++) {
    c1_b_y[c1_i394] = c1_iv44[c1_i394];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_wc_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[17])
{
  int8_T c1_iv45[17];
  int32_T c1_i395;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv45, 1, 2, 0U, 1, 0U, 1, 17);
  for (c1_i395 = 0; c1_i395 < 17; c1_i395++) {
    c1_b_y[c1_i395] = c1_iv45[c1_i395];
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_xc_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  int8_T c1_b_y[32])
{
  int8_T c1_iv46[32];
  int32_T c1_i396;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), c1_iv46, 1, 2, 0U, 1, 0U, 1, 32);
  for (c1_i396 = 0; c1_i396 < 32; c1_i396++) {
    c1_b_y[c1_i396] = c1_iv46[c1_i396];
  }

  sf_mex_destroy(&c1_b_u);
}

static PRESCAN_V2X_FIXED_BSM_vehicleClass c1_yc_emlrt_marshallIn
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_b_u,
   const emlrtMsgIdentifier *c1_parentId)
{
  PRESCAN_V2X_FIXED_BSM_vehicleClass c1_b_y;
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[3] = { "vGroup", "rGroup", "rEquip" };

  c1_thisId.fParent = c1_parentId;
  c1_thisId.bParentIsCell = false;
  sf_mex_check_struct(c1_parentId, c1_b_u, 3, c1_fieldNames, 0U, NULL);
  c1_thisId.fIdentifier = "vGroup";
  c1_b_y.vGroup = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "vGroup", "vGroup", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "rGroup";
  c1_b_y.rGroup = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "rGroup", "rGroup", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "rEquip";
  c1_b_y.rEquip = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "rEquip", "rEquip", 0)), &c1_thisId);
  sf_mex_destroy(&c1_b_u);
  return c1_b_y;
}

static void c1_ad_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  PRESCAN_V2X_FIXED_BSM_j1939data *c1_b_y)
{
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[10] = { "tires", "axle", "trailerWeight",
    "cargoWeight", "steeringAxleTemperature", "driveAxleLocation",
    "driveAxleLiftAirPressure", "driveAxleTemperature", "driveAxleLubePressure",
    "steeringAxleLubePressure" };

  c1_thisId.fParent = c1_parentId;
  c1_thisId.bParentIsCell = false;
  sf_mex_check_struct(c1_parentId, c1_b_u, 10, c1_fieldNames, 0U, NULL);
  c1_thisId.fIdentifier = "tires";
  c1_bd_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "tires", "tires", 0)), &c1_thisId, c1_b_y->tires);
  c1_thisId.fIdentifier = "axle";
  c1_cd_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "axle", "axle", 0)), &c1_thisId, c1_b_y->axle);
  c1_thisId.fIdentifier = "trailerWeight";
  c1_b_y->trailerWeight = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "trailerWeight", "trailerWeight", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "cargoWeight";
  c1_b_y->cargoWeight = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "cargoWeight", "cargoWeight", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "steeringAxleTemperature";
  c1_b_y->steeringAxleTemperature = c1_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c1_b_u, "steeringAxleTemperature",
    "steeringAxleTemperature", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "driveAxleLocation";
  c1_b_y->driveAxleLocation = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "driveAxleLocation", "driveAxleLocation", 0)),
    &c1_thisId);
  c1_thisId.fIdentifier = "driveAxleLiftAirPressure";
  c1_b_y->driveAxleLiftAirPressure = c1_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c1_b_u, "driveAxleLiftAirPressure",
    "driveAxleLiftAirPressure", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "driveAxleTemperature";
  c1_b_y->driveAxleTemperature = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "driveAxleTemperature", "driveAxleTemperature", 0)),
    &c1_thisId);
  c1_thisId.fIdentifier = "driveAxleLubePressure";
  c1_b_y->driveAxleLubePressure = c1_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c1_b_u, "driveAxleLubePressure",
    "driveAxleLubePressure", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "steeringAxleLubePressure";
  c1_b_y->steeringAxleLubePressure = c1_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c1_b_u, "steeringAxleLubePressure",
    "steeringAxleLubePressure", 0)), &c1_thisId);
  sf_mex_destroy(&c1_b_u);
}

static void c1_bd_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  PRESCAN_V2X_FIXED_BSM_tires c1_b_y[16])
{
  uint32_T c1_uv1[1];
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[7] = { "location", "pressure", "temp",
    "wheelSensorStatus", "wheelEndElectFault", "leakageRate", "detection" };

  int32_T c1_i397;
  c1_uv1[0] = 16U;
  c1_thisId.fParent = c1_parentId;
  c1_thisId.bParentIsCell = false;
  sf_mex_check_struct(c1_parentId, c1_b_u, 7, c1_fieldNames, 1U, c1_uv1);
  for (c1_i397 = 0; c1_i397 < 16; c1_i397++) {
    c1_thisId.fIdentifier = "location";
    c1_b_y[c1_i397].location = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c1_b_u, "location", "location", c1_i397)), &c1_thisId);
    c1_thisId.fIdentifier = "pressure";
    c1_b_y[c1_i397].pressure = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c1_b_u, "pressure", "pressure", c1_i397)), &c1_thisId);
    c1_thisId.fIdentifier = "temp";
    c1_b_y[c1_i397].temp = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c1_b_u, "temp", "temp", c1_i397)), &c1_thisId);
    c1_thisId.fIdentifier = "wheelSensorStatus";
    c1_b_y[c1_i397].wheelSensorStatus = c1_g_emlrt_marshallIn(chartInstance,
      sf_mex_dup(sf_mex_getfield(c1_b_u, "wheelSensorStatus",
      "wheelSensorStatus", c1_i397)), &c1_thisId);
    c1_thisId.fIdentifier = "wheelEndElectFault";
    c1_b_y[c1_i397].wheelEndElectFault = c1_g_emlrt_marshallIn(chartInstance,
      sf_mex_dup(sf_mex_getfield(c1_b_u, "wheelEndElectFault",
      "wheelEndElectFault", c1_i397)), &c1_thisId);
    c1_thisId.fIdentifier = "leakageRate";
    c1_b_y[c1_i397].leakageRate = c1_g_emlrt_marshallIn(chartInstance,
      sf_mex_dup(sf_mex_getfield(c1_b_u, "leakageRate", "leakageRate", c1_i397)),
      &c1_thisId);
    c1_thisId.fIdentifier = "detection";
    c1_b_y[c1_i397].detection = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c1_b_u, "detection", "detection", c1_i397)), &c1_thisId);
  }

  sf_mex_destroy(&c1_b_u);
}

static void c1_cd_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId,
  PRESCAN_V2X_FIXED_BSM_axle c1_b_y[16])
{
  uint32_T c1_uv2[1];
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[2] = { "location", "weight" };

  int32_T c1_i398;
  c1_uv2[0] = 16U;
  c1_thisId.fParent = c1_parentId;
  c1_thisId.bParentIsCell = false;
  sf_mex_check_struct(c1_parentId, c1_b_u, 2, c1_fieldNames, 1U, c1_uv2);
  for (c1_i398 = 0; c1_i398 < 16; c1_i398++) {
    c1_thisId.fIdentifier = "location";
    c1_b_y[c1_i398].location = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c1_b_u, "location", "location", c1_i398)), &c1_thisId);
    c1_thisId.fIdentifier = "weight";
    c1_b_y[c1_i398].weight = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
      (sf_mex_getfield(c1_b_u, "weight", "weight", c1_i398)), &c1_thisId);
  }

  sf_mex_destroy(&c1_b_u);
}

static PRESCAN_V2X_FIXED_BSM_weatherReport c1_dd_emlrt_marshallIn
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_b_u,
   const emlrtMsgIdentifier *c1_parentId)
{
  PRESCAN_V2X_FIXED_BSM_weatherReport c1_b_y;
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[5] = { "isRaining", "rainRate",
    "precipSituation", "solarRadiation", "friction" };

  c1_thisId.fParent = c1_parentId;
  c1_thisId.bParentIsCell = false;
  sf_mex_check_struct(c1_parentId, c1_b_u, 5, c1_fieldNames, 0U, NULL);
  c1_thisId.fIdentifier = "isRaining";
  c1_b_y.isRaining = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "isRaining", "isRaining", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "rainRate";
  c1_b_y.rainRate = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "rainRate", "rainRate", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "precipSituation";
  c1_b_y.precipSituation = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "precipSituation", "precipSituation", 0)),
    &c1_thisId);
  c1_thisId.fIdentifier = "solarRadiation";
  c1_b_y.solarRadiation = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "solarRadiation", "solarRadiation", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "friction";
  c1_b_y.friction = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "friction", "friction", 0)), &c1_thisId);
  sf_mex_destroy(&c1_b_u);
  return c1_b_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_y;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  PRESCAN_V2X_FIXED_BSM_MESSAGE c1_c_y;
  SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc1_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c1_b_y = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_y), &c1_thisId, &c1_c_y);
  sf_mex_destroy(&c1_b_y);
  *(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_outData = c1_c_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  PRESCAN_HEADER c1_b_u;
  const mxArray *c1_b_y = NULL;
  static const char * c1_sv34[1] = { "valid" };

  boolean_T c1_c_u;
  const mxArray *c1_c_y = NULL;
  SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc1_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_b_u = *(PRESCAN_HEADER *)c1_inData;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_createstruct("structure", 1, c1_sv34, 2, 1, 1),
                false);
  c1_c_u = c1_b_u.valid;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_c_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "valid", c1_c_y, 0);
  sf_mex_assign(&c1_mxArrayOutData, c1_b_y, false);
  return c1_mxArrayOutData;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_u;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  PRESCAN_HEADER c1_b_y;
  SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc1_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c1_b_u = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_b_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_u), &c1_thisId);
  sf_mex_destroy(&c1_b_u);
  *(PRESCAN_HEADER *)c1_outData = c1_b_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  PRESCAN_V2X_FIXED_BSM_size c1_b_u;
  const mxArray *c1_b_y = NULL;
  int32_T c1_c_u;
  const mxArray *c1_c_y = NULL;
  int32_T c1_d_u;
  const mxArray *c1_d_y = NULL;
  SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc1_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_b_u = *(PRESCAN_V2X_FIXED_BSM_size *)c1_inData;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_createstruct("structure", 2, c1_sv1, 2, 1, 1),
                false);
  c1_c_u = c1_b_u.width;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_c_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "width", c1_c_y, 0);
  c1_d_u = c1_b_u.length;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_d_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "length", c1_d_y, 1);
  sf_mex_assign(&c1_mxArrayOutData, c1_b_y, false);
  return c1_mxArrayOutData;
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_u;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  PRESCAN_V2X_FIXED_BSM_size c1_b_y;
  SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc1_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c1_b_u = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_b_y = c1_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_u), &c1_thisId);
  sf_mex_destroy(&c1_b_u);
  *(PRESCAN_V2X_FIXED_BSM_size *)c1_outData = c1_b_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  c1_PRESCAN_V2X_USER_BSM_size c1_b_u;
  const mxArray *c1_b_y = NULL;
  int32_T c1_c_u;
  const mxArray *c1_c_y = NULL;
  int32_T c1_d_u;
  const mxArray *c1_d_y = NULL;
  SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc1_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_b_u = *(c1_PRESCAN_V2X_USER_BSM_size *)c1_inData;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_createstruct("structure", 2, c1_sv1, 2, 1, 1),
                false);
  c1_c_u = c1_b_u.width;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_c_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "width", c1_c_y, 0);
  c1_d_u = c1_b_u.length;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_d_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_setfieldbynum(c1_b_y, 0, "length", c1_d_y, 1);
  sf_mex_assign(&c1_mxArrayOutData, c1_b_y, false);
  return c1_mxArrayOutData;
}

static c1_PRESCAN_V2X_USER_BSM_size c1_ed_emlrt_marshallIn
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_b_u,
   const emlrtMsgIdentifier *c1_parentId)
{
  c1_PRESCAN_V2X_USER_BSM_size c1_b_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fParent = c1_parentId;
  c1_thisId.bParentIsCell = false;
  sf_mex_check_struct(c1_parentId, c1_b_u, 2, c1_sv5, 0U, NULL);
  c1_thisId.fIdentifier = "width";
  c1_b_y.width = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_b_u, "width", "width", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "length";
  c1_b_y.length = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "length", "length", 0)), &c1_thisId);
  sf_mex_destroy(&c1_b_u);
  return c1_b_y;
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_y;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  c1_PRESCAN_V2X_USER_BSM_size c1_c_y;
  SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc1_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c1_b_y = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_c_y = c1_ed_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_y), &c1_thisId);
  sf_mex_destroy(&c1_b_y);
  *(c1_PRESCAN_V2X_USER_BSM_size *)c1_outData = c1_c_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc1_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  sf_mex_assign(&c1_mxArrayOutData, c1_d_emlrt_marshallOut(chartInstance,
    (PRESCAN_V2X_FIXED_BSM_DATA *)c1_inData), false);
  return c1_mxArrayOutData;
}

static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_u;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  PRESCAN_V2X_FIXED_BSM_DATA c1_b_y;
  SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc1_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c1_b_u = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_u), &c1_thisId, &c1_b_y);
  sf_mex_destroy(&c1_b_u);
  *(PRESCAN_V2X_FIXED_BSM_DATA *)c1_outData = c1_b_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc1_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  sf_mex_assign(&c1_mxArrayOutData, c1_emlrt_marshallOut(chartInstance,
    *(c1_PRESCAN_V2X_USER_BSM_DATA *)c1_inData), false);
  return c1_mxArrayOutData;
}

static c1_PRESCAN_V2X_USER_BSM_DATA c1_fd_emlrt_marshallIn
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_b_u,
   const emlrtMsgIdentifier *c1_parentId)
{
  c1_PRESCAN_V2X_USER_BSM_DATA c1_b_y;
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[14] = { "msgID", "msgCnt", "id", "secMark",
    "latitude", "longitude", "elev", "accuracy", "speed", "heading", "angle",
    "accelSet", "brakes", "size" };

  c1_thisId.fParent = c1_parentId;
  c1_thisId.bParentIsCell = false;
  sf_mex_check_struct(c1_parentId, c1_b_u, 14, c1_fieldNames, 0U, NULL);
  c1_thisId.fIdentifier = "msgID";
  c1_b_y.msgID = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_b_u, "msgID", "msgID", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "msgCnt";
  c1_b_y.msgCnt = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "msgCnt", "msgCnt", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "id";
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u, "id",
    "id", 0)), &c1_thisId, c1_b_y.id);
  c1_thisId.fIdentifier = "secMark";
  c1_b_y.secMark = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "secMark", "secMark", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "latitude";
  c1_b_y.latitude = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "latitude", "latitude", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "longitude";
  c1_b_y.longitude = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "longitude", "longitude", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "elev";
  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u, "elev",
    "elev", 0)), &c1_thisId, c1_b_y.elev);
  c1_thisId.fIdentifier = "accuracy";
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "accuracy", "accuracy", 0)), &c1_thisId, c1_b_y.accuracy);
  c1_thisId.fIdentifier = "speed";
  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "speed", "speed", 0)), &c1_thisId, c1_b_y.speed);
  c1_thisId.fIdentifier = "heading";
  c1_b_y.heading = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "heading", "heading", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "angle";
  c1_b_y.angle = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_b_u, "angle", "angle", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "accelSet";
  c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "accelSet", "accelSet", 0)), &c1_thisId, c1_b_y.accelSet);
  c1_thisId.fIdentifier = "brakes";
  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_b_u,
    "brakes", "brakes", 0)), &c1_thisId, c1_b_y.brakes);
  c1_thisId.fIdentifier = "size";
  c1_b_y.size = c1_ed_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_b_u, "size", "size", 0)), &c1_thisId);
  sf_mex_destroy(&c1_b_u);
  return c1_b_y;
}

static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_y;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  c1_PRESCAN_V2X_USER_BSM_DATA c1_c_y;
  SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc1_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c1_b_y = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_c_y = c1_fd_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_y), &c1_thisId);
  sf_mex_destroy(&c1_b_y);
  *(c1_PRESCAN_V2X_USER_BSM_DATA *)c1_outData = c1_c_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static c1_PRESCAN_V2X_USER_BSM_MESSAGE c1_gd_emlrt_marshallIn
  (SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance, const mxArray *c1_b_u,
   const emlrtMsgIdentifier *c1_parentId)
{
  c1_PRESCAN_V2X_USER_BSM_MESSAGE c1_b_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fParent = c1_parentId;
  c1_thisId.bParentIsCell = false;
  sf_mex_check_struct(c1_parentId, c1_b_u, 2, c1_sv4, 0U, NULL);
  c1_thisId.fIdentifier = "HEADER";
  c1_b_y.HEADER = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c1_b_u, "HEADER", "HEADER", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "DATA";
  c1_b_y.DATA = c1_fd_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_b_u, "DATA", "DATA", 0)), &c1_thisId);
  sf_mex_destroy(&c1_b_u);
  return c1_b_y;
}

static void c1_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_y;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  c1_PRESCAN_V2X_USER_BSM_MESSAGE c1_c_y;
  SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc1_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c1_b_y = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_c_y = c1_gd_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_y), &c1_thisId);
  sf_mex_destroy(&c1_b_y);
  *(c1_PRESCAN_V2X_USER_BSM_MESSAGE *)c1_outData = c1_c_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_Jan22_DLforACC_cs_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  const char * c1_data[4] = {
    "789cc552cd4ec240109e1a247ac07030fa0e1e6c522fea49ac1045504cf13fa6d6328486eeb6d92da67af2417c008fbe8daf63a194ae9b362531e2249bd9afdf"
    "e6fb66a603ca495b0180b5e82c45e7a30c93a8c409aad3bc043f43e6959c9cc43294261a15897f9f66dba30186410c5c87e2d9883c218b00b508ce647a1e71a8",
    "4583ee8b8fc0907bee33f6264cdf71b1eb106c7902387622401a023503636a7cd707680f8d110136e069b9ae084098cf634effa582f9c821cf477e97e5a708ef"
    "ca197e225ff43f566145743f48fcfc1cbdacfeb2fc640cd2f7245f6937e6a1d13631f42dda4356d4efbcfe6509a7fe31c30336b28374be9fbff46b16f49bf0f7",
    "f5077d5fbde4c8b8ca35d71b308bab1d86866d51b31efac8a29da401579b16d534f3a8d5f7584dd755794edb24d65bdc7ebc6dad6f7ed516bb8f8bdefffff30b"
    "73f4e6ddbf8d1cbfaac4b72eeefce1f9f56bf7d6a07bae55dbf577ecd3465a47a7c0a7a80ec8c17fadff0dd01b615d",
    "" };

  c1_nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(c1_data, 1728U, &c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc1_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_b_u = *(int32_T *)c1_inData;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_b_y, false);
  return c1_mxArrayOutData;
}

static void c1_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_b_y;
  SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc1_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_b_y = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_b_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_u_bus_io(void *chartInstanceVoid, void *c1_pData)
{
  const mxArray *c1_mxVal = NULL;
  c1_PRESCAN_V2X_USER_BSM_MESSAGE c1_tmp;
  int32_T c1_i399;
  int32_T c1_i400;
  int32_T c1_i401;
  int32_T c1_i402;
  int32_T c1_i403;
  int32_T c1_i404;
  SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc1_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c1_mxVal = NULL;
  c1_tmp.HEADER.valid = *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)
    (c1_PRESCAN_V2X_USER_BSM_MESSAGE *)c1_pData)[0])[0];
  c1_tmp.DATA.msgID = *(int32_T *)&((char_T *)(c1_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)(c1_PRESCAN_V2X_USER_BSM_MESSAGE *)c1_pData)[8])[0];
  c1_tmp.DATA.msgCnt = *(int32_T *)&((char_T *)(c1_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)(c1_PRESCAN_V2X_USER_BSM_MESSAGE *)c1_pData)[8])[4];
  for (c1_i399 = 0; c1_i399 < 4; c1_i399++) {
    c1_tmp.DATA.id[c1_i399] = ((int8_T *)&((char_T *)
      (c1_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
      (c1_PRESCAN_V2X_USER_BSM_MESSAGE *)c1_pData)[8])[8])[c1_i399];
  }

  c1_tmp.DATA.secMark = *(int32_T *)&((char_T *)(c1_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)(c1_PRESCAN_V2X_USER_BSM_MESSAGE *)c1_pData)[8])[12];
  c1_tmp.DATA.latitude = *(int32_T *)&((char_T *)(c1_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)(c1_PRESCAN_V2X_USER_BSM_MESSAGE *)c1_pData)[8])[16];
  c1_tmp.DATA.longitude = *(int32_T *)&((char_T *)(c1_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)(c1_PRESCAN_V2X_USER_BSM_MESSAGE *)c1_pData)[8])[20];
  for (c1_i400 = 0; c1_i400 < 2; c1_i400++) {
    c1_tmp.DATA.elev[c1_i400] = ((int8_T *)&((char_T *)
      (c1_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
      (c1_PRESCAN_V2X_USER_BSM_MESSAGE *)c1_pData)[8])[24])[c1_i400];
  }

  for (c1_i401 = 0; c1_i401 < 4; c1_i401++) {
    c1_tmp.DATA.accuracy[c1_i401] = ((int8_T *)&((char_T *)
      (c1_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
      (c1_PRESCAN_V2X_USER_BSM_MESSAGE *)c1_pData)[8])[26])[c1_i401];
  }

  for (c1_i402 = 0; c1_i402 < 2; c1_i402++) {
    c1_tmp.DATA.speed[c1_i402] = ((int8_T *)&((char_T *)
      (c1_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
      (c1_PRESCAN_V2X_USER_BSM_MESSAGE *)c1_pData)[8])[30])[c1_i402];
  }

  c1_tmp.DATA.heading = *(int32_T *)&((char_T *)(c1_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)(c1_PRESCAN_V2X_USER_BSM_MESSAGE *)c1_pData)[8])[32];
  c1_tmp.DATA.angle = *(int8_T *)&((char_T *)(c1_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)(c1_PRESCAN_V2X_USER_BSM_MESSAGE *)c1_pData)[8])[36];
  for (c1_i403 = 0; c1_i403 < 7; c1_i403++) {
    c1_tmp.DATA.accelSet[c1_i403] = ((int8_T *)&((char_T *)
      (c1_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
      (c1_PRESCAN_V2X_USER_BSM_MESSAGE *)c1_pData)[8])[37])[c1_i403];
  }

  for (c1_i404 = 0; c1_i404 < 2; c1_i404++) {
    c1_tmp.DATA.brakes[c1_i404] = ((int8_T *)&((char_T *)
      (c1_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
      (c1_PRESCAN_V2X_USER_BSM_MESSAGE *)c1_pData)[8])[44])[c1_i404];
  }

  c1_tmp.DATA.size.width = *(int32_T *)&((char_T *)(c1_PRESCAN_V2X_USER_BSM_size
    *)&((char_T *)(c1_PRESCAN_V2X_USER_BSM_DATA *)&((char_T *)
    (c1_PRESCAN_V2X_USER_BSM_MESSAGE *)c1_pData)[8])[48])[0];
  c1_tmp.DATA.size.length = *(int32_T *)&((char_T *)
    (c1_PRESCAN_V2X_USER_BSM_size *)&((char_T *)(c1_PRESCAN_V2X_USER_BSM_DATA *)
    &((char_T *)(c1_PRESCAN_V2X_USER_BSM_MESSAGE *)c1_pData)[8])[48])[4];
  sf_mex_assign(&c1_mxVal, c1_b_sf_marshallOut(chartInstance, &c1_tmp), false);
  return c1_mxVal;
}

static const mxArray *c1_y_bus_io(void *chartInstanceVoid, void *c1_pData)
{
  const mxArray *c1_mxVal = NULL;
  PRESCAN_V2X_FIXED_BSM_MESSAGE c1_tmp;
  int32_T c1_i405;
  int32_T c1_i406;
  int32_T c1_i407;
  int32_T c1_i408;
  int32_T c1_i409;
  int32_T c1_i410;
  int32_T c1_i411;
  int32_T c1_i412;
  int32_T c1_i413;
  int32_T c1_i414;
  int32_T c1_i415;
  int32_T c1_i416;
  int32_T c1_i417;
  int32_T c1_i418;
  int32_T c1_i419;
  int32_T c1_i420;
  int32_T c1_i421;
  int32_T c1_i422;
  int32_T c1_i423;
  int32_T c1_i424;
  int32_T c1_i425;
  int32_T c1_i426;
  int32_T c1_i427;
  int32_T c1_i428;
  int32_T c1_i429;
  int32_T c1_i430;
  int32_T c1_i431;
  int32_T c1_i432;
  int32_T c1_i433;
  int32_T c1_i434;
  int32_T c1_i435;
  int32_T c1_i436;
  int32_T c1_i437;
  int32_T c1_i438;
  int32_T c1_i439;
  int32_T c1_i440;
  int32_T c1_i441;
  int32_T c1_i442;
  int32_T c1_i443;
  int32_T c1_i444;
  int32_T c1_i445;
  int32_T c1_i446;
  int32_T c1_i447;
  int32_T c1_i448;
  int32_T c1_i449;
  int32_T c1_i450;
  int32_T c1_i451;
  int32_T c1_i452;
  int32_T c1_i453;
  int32_T c1_i454;
  int32_T c1_i455;
  int32_T c1_i456;
  int32_T c1_i457;
  int32_T c1_i458;
  int32_T c1_i459;
  int32_T c1_i460;
  int32_T c1_i461;
  int32_T c1_i462;
  int32_T c1_i463;
  int32_T c1_i464;
  int32_T c1_i465;
  int32_T c1_i466;
  int32_T c1_i467;
  int32_T c1_i468;
  int32_T c1_i469;
  int32_T c1_i470;
  SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc1_Jan22_DLforACC_csInstanceStruct *)chartInstanceVoid;
  c1_mxVal = NULL;
  c1_tmp.HEADER.valid = *(boolean_T *)&((char_T *)(PRESCAN_HEADER *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[0])[0];
  c1_tmp.DATA.msgID = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[0];
  c1_tmp.DATA.msgCnt = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[4];
  for (c1_i405 = 0; c1_i405 < 4; c1_i405++) {
    c1_tmp.DATA.id[c1_i405] = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[8])[c1_i405];
  }

  c1_tmp.DATA.secMark = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[12];
  c1_tmp.DATA.latitude = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[16];
  c1_tmp.DATA.longitude = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[20];
  for (c1_i406 = 0; c1_i406 < 2; c1_i406++) {
    c1_tmp.DATA.elev[c1_i406] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
      c1_pData)[8])[24])[c1_i406];
  }

  for (c1_i407 = 0; c1_i407 < 4; c1_i407++) {
    c1_tmp.DATA.accuracy[c1_i407] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
      c1_pData)[8])[26])[c1_i407];
  }

  for (c1_i408 = 0; c1_i408 < 2; c1_i408++) {
    c1_tmp.DATA.speed[c1_i408] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
      c1_pData)[8])[30])[c1_i408];
  }

  c1_tmp.DATA.heading = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[32];
  c1_tmp.DATA.angle = *(int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[36];
  for (c1_i409 = 0; c1_i409 < 7; c1_i409++) {
    c1_tmp.DATA.accelSet[c1_i409] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
      c1_pData)[8])[37])[c1_i409];
  }

  for (c1_i410 = 0; c1_i410 < 2; c1_i410++) {
    c1_tmp.DATA.brakes[c1_i410] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
      c1_pData)[8])[44])[c1_i410];
  }

  c1_tmp.DATA.size.width = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_size *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[48])[0];
  c1_tmp.DATA.size.length = *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_size *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[48])[4];
  c1_tmp.DATA.safetyExt.events = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[0];
  c1_tmp.DATA.safetyExt.pathHistory.initialPosition.utcTime.year = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[8])[0])[0])[0];
  c1_tmp.DATA.safetyExt.pathHistory.initialPosition.utcTime.month = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[8])[0])[0])[4];
  c1_tmp.DATA.safetyExt.pathHistory.initialPosition.utcTime.day = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[8])[0])[0])[8];
  c1_tmp.DATA.safetyExt.pathHistory.initialPosition.utcTime.hour = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[8])[0])[0])[12];
  c1_tmp.DATA.safetyExt.pathHistory.initialPosition.utcTime.minute = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[8])[0])[0])[16];
  c1_tmp.DATA.safetyExt.pathHistory.initialPosition.utcTime.second = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[8])[0])[0])[20];
  c1_tmp.DATA.safetyExt.pathHistory.initialPosition.longitude = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[8])[0])[24];
  c1_tmp.DATA.safetyExt.pathHistory.initialPosition.latitude = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[8])[0])[28];
  for (c1_i411 = 0; c1_i411 < 2; c1_i411++) {
    c1_tmp.DATA.safetyExt.pathHistory.initialPosition.elevation[c1_i411] =
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[8])[0])[32])
      [c1_i411];
  }

  c1_tmp.DATA.safetyExt.pathHistory.initialPosition.heading = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[8])[0])[36];
  for (c1_i412 = 0; c1_i412 < 2; c1_i412++) {
    c1_tmp.DATA.safetyExt.pathHistory.initialPosition.speed[c1_i412] = ((int8_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[8])[0])
      [40])[c1_i412];
  }

  for (c1_i413 = 0; c1_i413 < 4; c1_i413++) {
    c1_tmp.DATA.safetyExt.pathHistory.initialPosition.posAccuracy[c1_i413] =
      ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[8])[0])[42])
      [c1_i413];
  }

  c1_tmp.DATA.safetyExt.pathHistory.initialPosition.timeConfidence = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[8])[0])[48];
  c1_tmp.DATA.safetyExt.pathHistory.initialPosition.posConfidence = *(int8_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[8])[0])[52];
  c1_tmp.DATA.safetyExt.pathHistory.initialPosition.speedConfidence = *(int8_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_initialPosition *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[8])[0])[53];
  c1_tmp.DATA.safetyExt.pathHistory.currGPSstatus = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[8])[56];
  c1_tmp.DATA.safetyExt.pathHistory.itemCnt = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[8])[60];
  for (c1_i414 = 0; c1_i414 < 23; c1_i414++) {
    c1_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c1_i414]
      .latOffset = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[8])[64])
      [0])[32 * (int32_T)c1_i414])[0];
    c1_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c1_i414]
      .longOffset = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[8])[64])
      [0])[32 * (int32_T)c1_i414])[4];
    c1_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c1_i414]
      .elevationOffset = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[8])[64])
      [0])[32 * (int32_T)c1_i414])[8];
    c1_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c1_i414]
      .timeOffset = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[8])[64])
      [0])[32 * (int32_T)c1_i414])[12];
    for (c1_i417 = 0; c1_i417 < 4; c1_i417++) {
      c1_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c1_i414]
        .posAccuracy[c1_i417] = ((int8_T *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE
        *)c1_pData)[8])[56])[8])[64])[0])[32 * (int32_T)c1_i414])[16])[c1_i417];
    }

    c1_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c1_i414]
      .heading = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[8])[64])
      [0])[32 * (int32_T)c1_i414])[20];
    for (c1_i419 = 0; c1_i419 < 2; c1_i419++) {
      c1_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_01[c1_i414]
        .speed[c1_i419] = ((int8_T *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistoryPointSets_01 *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE
        *)c1_pData)[8])[56])[8])[64])[0])[32 * (int32_T)c1_i414])[24])[c1_i419];
    }
  }

  for (c1_i415 = 0; c1_i415 < 345; c1_i415++) {
    c1_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_02[c1_i415]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
              (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[8])[64])[736])
      [c1_i415];
  }

  for (c1_i416 = 0; c1_i416 < 276; c1_i416++) {
    c1_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_03[c1_i416]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
              (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[8])[64])[1081])
      [c1_i416];
  }

  for (c1_i418 = 0; c1_i418 < 184; c1_i418++) {
    c1_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_04[c1_i418]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
              (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[8])[64])[1357])
      [c1_i418];
  }

  for (c1_i420 = 0; c1_i420 < 230; c1_i420++) {
    c1_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_05[c1_i420]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
              (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[8])[64])[1541])
      [c1_i420];
  }

  for (c1_i421 = 0; c1_i421 < 138; c1_i421++) {
    c1_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_06[c1_i421]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
              (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[8])[64])[1771])
      [c1_i421];
  }

  for (c1_i422 = 0; c1_i422 < 242; c1_i422++) {
    c1_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_07[c1_i422]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
              (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[8])[64])[1909])
      [c1_i422];
  }

  for (c1_i423 = 0; c1_i423 < 161; c1_i423++) {
    c1_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_08[c1_i423]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
              (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[8])[64])[2151])
      [c1_i423];
  }

  for (c1_i424 = 0; c1_i424 < 196; c1_i424++) {
    c1_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_09[c1_i424]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
              (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[8])[64])[2312])
      [c1_i424];
  }

  for (c1_i425 = 0; c1_i425 < 104; c1_i425++) {
    c1_tmp.DATA.safetyExt.pathHistory.crumbData.pathHistoryPointSets_10[c1_i425]
      = ((int8_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_crumbData *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_pathHistory *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
              (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[8])[64])[2508])
      [c1_i425];
  }

  c1_tmp.DATA.safetyExt.pathPrediction.radiusOfCurve = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathPrediction *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2688])[0];
  c1_tmp.DATA.safetyExt.pathPrediction.confidence = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_pathPrediction *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2688])[4];
  c1_tmp.DATA.safetyExt.theRTCM.anchorPoint.utcTime.year = *(int32_T *)&((char_T
    *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])[0])[0])
    [0];
  c1_tmp.DATA.safetyExt.theRTCM.anchorPoint.utcTime.month = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])[0])[0])[4];
  c1_tmp.DATA.safetyExt.theRTCM.anchorPoint.utcTime.day = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])[0])[0])
    [8];
  c1_tmp.DATA.safetyExt.theRTCM.anchorPoint.utcTime.hour = *(int32_T *)&((char_T
    *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])[0])[0])
    [12];
  c1_tmp.DATA.safetyExt.theRTCM.anchorPoint.utcTime.minute = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])[0])[0])[16];
  c1_tmp.DATA.safetyExt.theRTCM.anchorPoint.utcTime.second = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])[0])[0])[20];
  c1_tmp.DATA.safetyExt.theRTCM.anchorPoint.longitude = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])[0])
    [24];
  c1_tmp.DATA.safetyExt.theRTCM.anchorPoint.latitude = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])[0])
    [28];
  for (c1_i426 = 0; c1_i426 < 2; c1_i426++) {
    c1_tmp.DATA.safetyExt.theRTCM.anchorPoint.elevation[c1_i426] = ((int8_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])[0])
      [32])[c1_i426];
  }

  c1_tmp.DATA.safetyExt.theRTCM.anchorPoint.heading = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])[0])
    [36];
  for (c1_i427 = 0; c1_i427 < 2; c1_i427++) {
    c1_tmp.DATA.safetyExt.theRTCM.anchorPoint.speed[c1_i427] = ((int8_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])[0])
      [40])[c1_i427];
  }

  for (c1_i428 = 0; c1_i428 < 4; c1_i428++) {
    c1_tmp.DATA.safetyExt.theRTCM.anchorPoint.posAccuracy[c1_i428] = ((int8_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])[0])
      [42])[c1_i428];
  }

  c1_tmp.DATA.safetyExt.theRTCM.anchorPoint.timeConfidence = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])[0])[48];
  c1_tmp.DATA.safetyExt.theRTCM.anchorPoint.posConfidence = *(int8_T *)&((char_T
    *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])[0])
    [52];
  c1_tmp.DATA.safetyExt.theRTCM.anchorPoint.speedConfidence = *(int8_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_anchorPoint *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])[0])[53];
  for (c1_i429 = 0; c1_i429 < 5; c1_i429++) {
    c1_tmp.DATA.safetyExt.theRTCM.rtcmHeader[c1_i429] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])
      [56])[c1_i429];
  }

  for (c1_i430 = 0; c1_i430 < 124; c1_i430++) {
    c1_tmp.DATA.safetyExt.theRTCM.msg1001[c1_i430] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])
      [61])[c1_i430];
  }

  for (c1_i431 = 0; c1_i431 < 156; c1_i431++) {
    c1_tmp.DATA.safetyExt.theRTCM.msg1002[c1_i431] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])
      [185])[c1_i431];
  }

  for (c1_i432 = 0; c1_i432 < 210; c1_i432++) {
    c1_tmp.DATA.safetyExt.theRTCM.msg1003[c1_i432] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])
      [341])[c1_i432];
  }

  for (c1_i433 = 0; c1_i433 < 258; c1_i433++) {
    c1_tmp.DATA.safetyExt.theRTCM.msg1004[c1_i433] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])
      [551])[c1_i433];
  }

  for (c1_i434 = 0; c1_i434 < 19; c1_i434++) {
    c1_tmp.DATA.safetyExt.theRTCM.msg1005[c1_i434] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])
      [809])[c1_i434];
  }

  for (c1_i435 = 0; c1_i435 < 21; c1_i435++) {
    c1_tmp.DATA.safetyExt.theRTCM.msg1006[c1_i435] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])
      [828])[c1_i435];
  }

  for (c1_i436 = 0; c1_i436 < 36; c1_i436++) {
    c1_tmp.DATA.safetyExt.theRTCM.msg1007[c1_i436] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])
      [849])[c1_i436];
  }

  for (c1_i437 = 0; c1_i437 < 68; c1_i437++) {
    c1_tmp.DATA.safetyExt.theRTCM.msg1008[c1_i437] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])
      [885])[c1_i437];
  }

  for (c1_i438 = 0; c1_i438 < 136; c1_i438++) {
    c1_tmp.DATA.safetyExt.theRTCM.msg1009[c1_i438] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])
      [953])[c1_i438];
  }

  for (c1_i439 = 0; c1_i439 < 166; c1_i439++) {
    c1_tmp.DATA.safetyExt.theRTCM.msg1010[c1_i439] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])
      [1089])[c1_i439];
  }

  for (c1_i440 = 0; c1_i440 < 222; c1_i440++) {
    c1_tmp.DATA.safetyExt.theRTCM.msg1011[c1_i440] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])
      [1255])[c1_i440];
  }

  for (c1_i441 = 0; c1_i441 < 268; c1_i441++) {
    c1_tmp.DATA.safetyExt.theRTCM.msg1012[c1_i441] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])
      [1477])[c1_i441];
  }

  for (c1_i442 = 0; c1_i442 < 27; c1_i442++) {
    c1_tmp.DATA.safetyExt.theRTCM.msg1013[c1_i442] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])
      [1745])[c1_i442];
  }

  for (c1_i443 = 0; c1_i443 < 15; c1_i443++) {
    c1_tmp.DATA.safetyExt.theRTCM.msg1014[c1_i443] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])
      [1772])[c1_i443];
  }

  for (c1_i444 = 0; c1_i444 < 69; c1_i444++) {
    c1_tmp.DATA.safetyExt.theRTCM.msg1015[c1_i444] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])
      [1787])[c1_i444];
  }

  for (c1_i445 = 0; c1_i445 < 81; c1_i445++) {
    c1_tmp.DATA.safetyExt.theRTCM.msg1016[c1_i445] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])
      [1856])[c1_i445];
  }

  for (c1_i446 = 0; c1_i446 < 115; c1_i446++) {
    c1_tmp.DATA.safetyExt.theRTCM.msg1017[c1_i446] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])
      [1937])[c1_i446];
  }

  for (c1_i447 = 0; c1_i447 < 62; c1_i447++) {
    c1_tmp.DATA.safetyExt.theRTCM.msg1019[c1_i447] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])
      [2052])[c1_i447];
  }

  for (c1_i448 = 0; c1_i448 < 45; c1_i448++) {
    c1_tmp.DATA.safetyExt.theRTCM.msg1020[c1_i448] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])
      [2114])[c1_i448];
  }

  for (c1_i449 = 0; c1_i449 < 62; c1_i449++) {
    c1_tmp.DATA.safetyExt.theRTCM.msg1021[c1_i449] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])
      [2159])[c1_i449];
  }

  for (c1_i450 = 0; c1_i450 < 75; c1_i450++) {
    c1_tmp.DATA.safetyExt.theRTCM.msg1022[c1_i450] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])
      [2221])[c1_i450];
  }

  for (c1_i451 = 0; c1_i451 < 73; c1_i451++) {
    c1_tmp.DATA.safetyExt.theRTCM.msg1023[c1_i451] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])
      [2296])[c1_i451];
  }

  for (c1_i452 = 0; c1_i452 < 74; c1_i452++) {
    c1_tmp.DATA.safetyExt.theRTCM.msg1024[c1_i452] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])
      [2369])[c1_i452];
  }

  for (c1_i453 = 0; c1_i453 < 25; c1_i453++) {
    c1_tmp.DATA.safetyExt.theRTCM.msg1025[c1_i453] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])
      [2443])[c1_i453];
  }

  for (c1_i454 = 0; c1_i454 < 30; c1_i454++) {
    c1_tmp.DATA.safetyExt.theRTCM.msg1026[c1_i454] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])
      [2468])[c1_i454];
  }

  for (c1_i455 = 0; c1_i455 < 33; c1_i455++) {
    c1_tmp.DATA.safetyExt.theRTCM.msg1027[c1_i455] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])
      [2498])[c1_i455];
  }

  for (c1_i456 = 0; c1_i456 < 69; c1_i456++) {
    c1_tmp.DATA.safetyExt.theRTCM.msg1029[c1_i456] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])
      [2531])[c1_i456];
  }

  for (c1_i457 = 0; c1_i457 < 105; c1_i457++) {
    c1_tmp.DATA.safetyExt.theRTCM.msg1030[c1_i457] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])
      [2600])[c1_i457];
  }

  for (c1_i458 = 0; c1_i458 < 107; c1_i458++) {
    c1_tmp.DATA.safetyExt.theRTCM.msg1031[c1_i458] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])
      [2705])[c1_i458];
  }

  for (c1_i459 = 0; c1_i459 < 20; c1_i459++) {
    c1_tmp.DATA.safetyExt.theRTCM.msg1032[c1_i459] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_theRTCM *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_safetyExt *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[56])[2696])
      [2812])[c1_i459];
  }

  c1_tmp.DATA.status.lights = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[0];
  c1_tmp.DATA.status.lightBar = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[4];
  c1_tmp.DATA.status.wipers.statusFront = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[8])[0];
  c1_tmp.DATA.status.wipers.rateFront = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[8])[4];
  c1_tmp.DATA.status.wipers.statusRear = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[8])[8];
  c1_tmp.DATA.status.wipers.rateRear = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_wipers *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[8])[12];
  for (c1_i460 = 0; c1_i460 < 2; c1_i460++) {
    c1_tmp.DATA.status.brakeStatus[c1_i460] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[24])
      [c1_i460];
  }

  c1_tmp.DATA.status.brakePressure = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[28];
  c1_tmp.DATA.status.roadFriction = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[32];
  c1_tmp.DATA.status.sunData = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[36];
  c1_tmp.DATA.status.rainData = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[40];
  c1_tmp.DATA.status.airTemp = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[44];
  c1_tmp.DATA.status.airPres = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[48];
  c1_tmp.DATA.status.steering.angle = *(int8_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[56])[0];
  c1_tmp.DATA.status.steering.confidence = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[56])[4];
  c1_tmp.DATA.status.steering.rate = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[56])[8];
  c1_tmp.DATA.status.steering.wheels = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_steering *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[56])[12];
  for (c1_i461 = 0; c1_i461 < 7; c1_i461++) {
    c1_tmp.DATA.status.accelSets.accel4way[c1_i461] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[72])[0])
      [c1_i461];
  }

  c1_tmp.DATA.status.accelSets.vertAccelThres = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[72])[8];
  c1_tmp.DATA.status.accelSets.yawRateCon = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[72])[12];
  c1_tmp.DATA.status.accelSets.hozAccelCon = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[72])[16];
  c1_tmp.DATA.status.accelSets.confidenceSet.accelConfidence.yawRate = *(int32_T
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelConfidence *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[72])[24])[0])
    [0];
  c1_tmp.DATA.status.accelSets.confidenceSet.accelConfidence.acceleration =
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelConfidence *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[72])[24])[0])[4];
  c1_tmp.DATA.status.accelSets.confidenceSet.accelConfidence.steeringWheelAngle =
    *(int32_T *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_accelConfidence *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[72])[24])[0])[8];
  c1_tmp.DATA.status.accelSets.confidenceSet.speedConfidence = *(int8_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
         &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[72])
      [24])[16];
  c1_tmp.DATA.status.accelSets.confidenceSet.timeConfidence = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
         &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[72])
      [24])[20];
  c1_tmp.DATA.status.accelSets.confidenceSet.posConfidence = *(int8_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
         &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[72])
      [24])[24];
  c1_tmp.DATA.status.accelSets.confidenceSet.steerConfidence = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
         &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[72])
      [24])[28];
  c1_tmp.DATA.status.accelSets.confidenceSet.throttleConfidence = *(int32_T *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_confidenceSet *)&((char_T *)
       (PRESCAN_V2X_FIXED_BSM_accelSets *)&((char_T *)
        (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
         &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[72])
      [24])[32];
  c1_tmp.DATA.status.object.obDist = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[136])[0];
  c1_tmp.DATA.status.object.obDirect = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_object *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[136])[4];
  c1_tmp.DATA.status.object.dateTime.year = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    c1_pData)[8])[5584])[136])[8])[0];
  c1_tmp.DATA.status.object.dateTime.month = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    c1_pData)[8])[5584])[136])[8])[4];
  c1_tmp.DATA.status.object.dateTime.day = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    c1_pData)[8])[5584])[136])[8])[8];
  c1_tmp.DATA.status.object.dateTime.hour = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    c1_pData)[8])[5584])[136])[8])[12];
  c1_tmp.DATA.status.object.dateTime.minute = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    c1_pData)[8])[5584])[136])[8])[16];
  c1_tmp.DATA.status.object.dateTime.second = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_dateTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_object *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    c1_pData)[8])[5584])[136])[8])[20];
  c1_tmp.DATA.status.fullPos.utcTime.year = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    c1_pData)[8])[5584])[168])[0])[0];
  c1_tmp.DATA.status.fullPos.utcTime.month = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    c1_pData)[8])[5584])[168])[0])[4];
  c1_tmp.DATA.status.fullPos.utcTime.day = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    c1_pData)[8])[5584])[168])[0])[8];
  c1_tmp.DATA.status.fullPos.utcTime.hour = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    c1_pData)[8])[5584])[168])[0])[12];
  c1_tmp.DATA.status.fullPos.utcTime.minute = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    c1_pData)[8])[5584])[168])[0])[16];
  c1_tmp.DATA.status.fullPos.utcTime.second = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_utcTime *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_fullPos *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    c1_pData)[8])[5584])[168])[0])[20];
  c1_tmp.DATA.status.fullPos.longitude = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[168])[24];
  c1_tmp.DATA.status.fullPos.latitude = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[168])[28];
  for (c1_i462 = 0; c1_i462 < 2; c1_i462++) {
    c1_tmp.DATA.status.fullPos.elevation[c1_i462] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[168])[32])[c1_i462];
  }

  c1_tmp.DATA.status.fullPos.heading = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[168])[36];
  for (c1_i463 = 0; c1_i463 < 2; c1_i463++) {
    c1_tmp.DATA.status.fullPos.speed[c1_i463] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[168])[40])[c1_i463];
  }

  for (c1_i464 = 0; c1_i464 < 4; c1_i464++) {
    c1_tmp.DATA.status.fullPos.posAccuracy[c1_i464] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
      *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[168])[42])[c1_i464];
  }

  c1_tmp.DATA.status.fullPos.timeConfidence = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[168])[48];
  c1_tmp.DATA.status.fullPos.posConfidence = *(int8_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[168])[52];
  c1_tmp.DATA.status.fullPos.speedConfidence = *(int8_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_fullPos *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[168])[53];
  c1_tmp.DATA.status.throttlePos = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[224];
  c1_tmp.DATA.status.speedHeadC = *(int8_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[228];
  c1_tmp.DATA.status.speedC = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[232];
  c1_tmp.DATA.status.vehicleData.height = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[240])[0];
  c1_tmp.DATA.status.vehicleData.bumpers.frnt = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_bumpers *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[240])[8])
    [0];
  c1_tmp.DATA.status.vehicleData.bumpers.rear = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_bumpers *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[240])[8])
    [4];
  c1_tmp.DATA.status.vehicleData.mass = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[240])[16];
  c1_tmp.DATA.status.vehicleData.trailerWeight = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[240])[20];
  c1_tmp.DATA.status.vehicleData.type = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleData *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[240])[24];
  for (c1_i465 = 0; c1_i465 < 63; c1_i465++) {
    c1_tmp.DATA.status.vehicleIdent.name[c1_i465] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[272])[0])
      [c1_i465];
  }

  for (c1_i466 = 0; c1_i466 < 17; c1_i466++) {
    c1_tmp.DATA.status.vehicleIdent.vin[c1_i466] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[272])[63])
      [c1_i466];
  }

  for (c1_i467 = 0; c1_i467 < 32; c1_i467++) {
    c1_tmp.DATA.status.vehicleIdent.ownerCode[c1_i467] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[272])[80])
      [c1_i467];
  }

  for (c1_i468 = 0; c1_i468 < 4; c1_i468++) {
    c1_tmp.DATA.status.vehicleIdent.id[c1_i468] = ((int8_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[272])
      [112])[c1_i468];
  }

  c1_tmp.DATA.status.vehicleIdent.vehicleType = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[272])[116];
  c1_tmp.DATA.status.vehicleIdent.vehicleClass.vGroup = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleClass *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[272])[120])
    [0];
  c1_tmp.DATA.status.vehicleIdent.vehicleClass.rGroup = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleClass *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[272])[120])
    [4];
  c1_tmp.DATA.status.vehicleIdent.vehicleClass.rEquip = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleClass *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_vehicleIdent *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[272])[120])
    [8];
  for (c1_i469 = 0; c1_i469 < 16; c1_i469++) {
    c1_tmp.DATA.status.j1939data.tires[c1_i469].location = *(int32_T *)&((char_T
      *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[408])[0])
      [32 * (int32_T)c1_i469])[0];
    c1_tmp.DATA.status.j1939data.tires[c1_i469].pressure = *(int32_T *)&((char_T
      *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[408])[0])
      [32 * (int32_T)c1_i469])[4];
    c1_tmp.DATA.status.j1939data.tires[c1_i469].temp = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[408])[0])
      [32 * (int32_T)c1_i469])[8];
    c1_tmp.DATA.status.j1939data.tires[c1_i469].wheelSensorStatus = *(int32_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[408])[0])[32 *
        (int32_T)c1_i469])[12];
    c1_tmp.DATA.status.j1939data.tires[c1_i469].wheelEndElectFault = *(int32_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[408])[0])[32 *
        (int32_T)c1_i469])[16];
    c1_tmp.DATA.status.j1939data.tires[c1_i469].leakageRate = *(int32_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[408])[0])[32 *
        (int32_T)c1_i469])[20];
    c1_tmp.DATA.status.j1939data.tires[c1_i469].detection = *(int32_T *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
         (PRESCAN_V2X_FIXED_BSM_tires *)&((char_T *)
          (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
           (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)
            (PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
             (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[408])[0])[32 *
        (int32_T)c1_i469])[24];
  }

  for (c1_i470 = 0; c1_i470 < 16; c1_i470++) {
    c1_tmp.DATA.status.j1939data.axle[c1_i470].location = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_axle *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_axle *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[408])
      [512])[8 * (int32_T)c1_i470])[0];
    c1_tmp.DATA.status.j1939data.axle[c1_i470].weight = *(int32_T *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_axle *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_axle *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)
      (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
      &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[408])
      [512])[8 * (int32_T)c1_i470])[4];
  }

  c1_tmp.DATA.status.j1939data.trailerWeight = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[408])[640];
  c1_tmp.DATA.status.j1939data.cargoWeight = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[408])[644];
  c1_tmp.DATA.status.j1939data.steeringAxleTemperature = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[408])[648];
  c1_tmp.DATA.status.j1939data.driveAxleLocation = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[408])[652];
  c1_tmp.DATA.status.j1939data.driveAxleLiftAirPressure = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[408])[656];
  c1_tmp.DATA.status.j1939data.driveAxleTemperature = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[408])[660];
  c1_tmp.DATA.status.j1939data.driveAxleLubePressure = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[408])[664];
  c1_tmp.DATA.status.j1939data.steeringAxleLubePressure = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_j1939data *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_status
    *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[408])[668];
  c1_tmp.DATA.status.weatherReport.isRaining = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[1080])[0];
  c1_tmp.DATA.status.weatherReport.rainRate = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[1080])[4];
  c1_tmp.DATA.status.weatherReport.precipSituation = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[1080])[8];
  c1_tmp.DATA.status.weatherReport.solarRadiation = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[1080])[12];
  c1_tmp.DATA.status.weatherReport.friction = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_weatherReport *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[1080])[16];
  c1_tmp.DATA.status.gpsStatus = *(int32_T *)&((char_T *)
    (PRESCAN_V2X_FIXED_BSM_status *)&((char_T *)(PRESCAN_V2X_FIXED_BSM_DATA *)
    &((char_T *)(PRESCAN_V2X_FIXED_BSM_MESSAGE *)c1_pData)[8])[5584])[1104];
  sf_mex_assign(&c1_mxVal, c1_c_sf_marshallOut(chartInstance, &c1_tmp), false);
  return c1_mxVal;
}

static uint8_T c1_hd_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_Jan22_DLforACC_cs, const
  char_T *c1_identifier)
{
  uint8_T c1_b_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_b_y = c1_id_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_Jan22_DLforACC_cs), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_Jan22_DLforACC_cs);
  return c1_b_y;
}

static uint8_T c1_id_emlrt_marshallIn(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance, const mxArray *c1_b_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_b_y;
  uint8_T c1_u0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_b_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_b_y = c1_u0;
  sf_mex_destroy(&c1_b_u);
  return c1_b_y;
}

static void init_dsm_address_info(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc1_Jan22_DLforACC_csInstanceStruct
  *chartInstance)
{
  chartInstance->c1_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c1_u = (c1_PRESCAN_V2X_USER_BSM_MESSAGE *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c1_y = (PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c1_z = (PRESCAN_V2X_FIXED_BSM_MESSAGE *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 1);
}

/* SFunction Glue Code */
void sf_c1_Jan22_DLforACC_cs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1327072647U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(726601269U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2467005579U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3278161143U);
}

mxArray* sf_c1_Jan22_DLforACC_cs_get_post_codegen_info(void);
mxArray *sf_c1_Jan22_DLforACC_cs_get_autoinheritance_info(void)
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
    mxArray* mxPostCodegenInfo = sf_c1_Jan22_DLforACC_cs_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_Jan22_DLforACC_cs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_Jan22_DLforACC_cs_jit_fallback_info(void)
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

mxArray *sf_c1_Jan22_DLforACC_cs_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c1_Jan22_DLforACC_cs_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c1_Jan22_DLforACC_cs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c1_Jan22_DLforACC_cs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_Jan22_DLforACC_cs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance =
      (SFc1_Jan22_DLforACC_csInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Jan22_DLforACC_csMachineNumber_,
           1,
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
          (MexFcnForType)c1_u_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_y_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_y_bus_io,(MexInFcnForType)NULL);
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
    SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance =
      (SFc1_Jan22_DLforACC_csInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c1_u);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c1_y);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c1_z);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "s99X3kqVpXMuok8swRcg2o";
}

static void sf_opaque_initialize_c1_Jan22_DLforACC_cs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_Jan22_DLforACC_csInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_Jan22_DLforACC_cs((SFc1_Jan22_DLforACC_csInstanceStruct*)
    chartInstanceVar);
  initialize_c1_Jan22_DLforACC_cs((SFc1_Jan22_DLforACC_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_Jan22_DLforACC_cs(void *chartInstanceVar)
{
  enable_c1_Jan22_DLforACC_cs((SFc1_Jan22_DLforACC_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_Jan22_DLforACC_cs(void *chartInstanceVar)
{
  disable_c1_Jan22_DLforACC_cs((SFc1_Jan22_DLforACC_csInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_Jan22_DLforACC_cs(void *chartInstanceVar)
{
  sf_gateway_c1_Jan22_DLforACC_cs((SFc1_Jan22_DLforACC_csInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c1_Jan22_DLforACC_cs(SimStruct* S)
{
  return get_sim_state_c1_Jan22_DLforACC_cs
    ((SFc1_Jan22_DLforACC_csInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c1_Jan22_DLforACC_cs(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c1_Jan22_DLforACC_cs((SFc1_Jan22_DLforACC_csInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c1_Jan22_DLforACC_cs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_Jan22_DLforACC_csInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Jan22_DLforACC_cs_optimization_info();
    }

    finalize_c1_Jan22_DLforACC_cs((SFc1_Jan22_DLforACC_csInstanceStruct*)
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
  initSimStructsc1_Jan22_DLforACC_cs((SFc1_Jan22_DLforACC_csInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_Jan22_DLforACC_cs(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_Jan22_DLforACC_cs((SFc1_Jan22_DLforACC_csInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c1_Jan22_DLforACC_cs(SimStruct *S)
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
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetSupportedForRowMajorCodeGen(S, 1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,1,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 1);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
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

static void mdlRTW_c1_Jan22_DLforACC_cs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_Jan22_DLforACC_cs(SimStruct *S)
{
  SFc1_Jan22_DLforACC_csInstanceStruct *chartInstance;
  chartInstance = (SFc1_Jan22_DLforACC_csInstanceStruct *)utMalloc(sizeof
    (SFc1_Jan22_DLforACC_csInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc1_Jan22_DLforACC_csInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_Jan22_DLforACC_cs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_Jan22_DLforACC_cs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_Jan22_DLforACC_cs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_Jan22_DLforACC_cs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_Jan22_DLforACC_cs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_Jan22_DLforACC_cs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_Jan22_DLforACC_cs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_Jan22_DLforACC_cs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_Jan22_DLforACC_cs;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_Jan22_DLforACC_cs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_Jan22_DLforACC_cs;
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
  mdl_start_c1_Jan22_DLforACC_cs(chartInstance);
}

void c1_Jan22_DLforACC_cs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_Jan22_DLforACC_cs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_Jan22_DLforACC_cs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_Jan22_DLforACC_cs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_Jan22_DLforACC_cs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
