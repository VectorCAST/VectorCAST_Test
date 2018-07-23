/*vcast_separate_expansion_start:S0000009.c*/
/***********************************************
 *      VectorCAST Test Harness Component      *
 *     Copyright 2018 Vector Informatik, GmbH.    *
 *              18.sp2 (07/02/18)              *
 ***********************************************/
/***********************************************
 * VectorCAST Unit Information
 *
 * Name: database
 *
 * Path: C:/VCAST/Tutorial/c/database.c
 *
 * Type: stub-by-function
 *
 * Unit Number: 9
 *
 ***********************************************/
/*vcast_header_expansion_start:vcast_env_defines.h*/
/*vcast_header_expansion_end*/
/*vcast_header_expansion_start:database_driver_prefix.c*/
/*vcast_header_expansion_end*/
/*vcast_header_expansion_start:S0000009.h*/
/***********************************************
 *      VectorCAST Test Harness Component      *
 *     Copyright 2018 Vector Informatik, GmbH.    *
 *              18.sp2 (07/02/18)              *
 ***********************************************/
/***********************************************
 *      VectorCAST Test Harness Component      *
 *     Copyright 2018 Vector Informatik, GmbH.    *
 *              18.sp2 (07/02/18)              *
 ***********************************************/
/***********************************************
 *      VectorCAST Test Harness Component      *
 *     Copyright 2018 Vector Informatik, GmbH.    *
 *              18.sp2 (07/02/18)              *
 ***********************************************/
/* ----------------------------------------------------------------------------
-- VectorCAST IO File
-- 
-- DISCLAIMER :
-- This file is provided "AS IS"  by  for the convenience of Vector Software.
-- Inconsistent modifications may cause VectorCAST to fail to work properly
-- 
-------------------------------------------------------------------------------*/
/* setup for "long long" capability */
/* setup for Microsoft "long long" */
/* setup for MinGW "long long" formats */
/* setup for other "long long" formats */
/* end "long long" formats */
/* end "long long" support */
/* no "long long" support */
/* end "long long" check */
/***********************************************
 *      VectorCAST Test Harness Component      *
 *     Copyright 2018 Vector Informatik, GmbH.    *
 *              18.sp2 (07/02/18)              *
 ***********************************************/
/* ----------------------------------------------------------------------------
-- These funtions are called at the start and end of the test harenss
-- and contain conditionally compiled code to setup for the particular I/O
-- mode and in some case the particular target.
-------------------------------------------------------------------------------*/
void vectorcast_initialize_io (int inst_status, int inst_fd);
void vectorcast_terminate_io (void);
void vectorcast_write_vcast_end (void);
int vectorcast_fflush(int fpn);
void vectorcast_fclose(int fpn);
int vectorcast_feof(int fpn);
int vectorcast_fopen(char *filename, char *mode);
char *vectorcast_fgets (char *line, int maxline, int fpn);
/* return failure condition if the line we read is too long */
int vectorcast_readline(char *vcast_buf, int fpn);
void vectorcast_fprint_char (int fpn, char vcast_str);
void vectorcast_fprint_char_hex ( int fpn, char vcast_value );
void vectorcast_fprint_char_octl ( int fpn, char vcast_value );
void vectorcast_fprint_string (int fpn, const char *vcast_str);
void vectorcast_fprint_string_with_cr (int fpn, const char *vcast_str);
void vectorcast_print_string (const char *vcast_str);
void vectorcast_fprint_string_with_length(int fpn, const char *vcast_str, int length);
void vectorcast_fprint_short (int vcast_fpn, short vcast_value );
void vectorcast_fprint_integer (int vcast_fpn, int vcast_value );
void vectorcast_fprint_long (int vcast_fpn, long vcast_value );
void vectorcast_fprint_long_long (int vcast_fpn, long long vcast_value );
void vectorcast_fprint_unsigned_short (int vcast_fpn,
                                       unsigned short vcast_value );
void vectorcast_fprint_unsigned_integer (int vcast_fpn,
                                         unsigned int vcast_value );
void vectorcast_fprint_unsigned_long (int vcast_fpn,
                                      unsigned long vcast_value );
void vectorcast_fprint_unsigned_long_long (int vcast_fpn,
                                           unsigned long long vcast_value );
void vectorcast_fprint_long_float (int fpn, vCAST_long_double);
/* numeric conversion routines */
void vcast_signed_to_string ( char vcDest[],
                              long long vcSrc );
void vcast_unsigned_to_string ( char vcDest[],
                                unsigned long long vcSrc );
void vcast_float_to_string ( char *mixed_str, vCAST_long_double vcast_f );
/* ----------------------------------------------------------------------------
-- API for Harness Trace Functions
-----------------------------------------------------------------------------*/
/* To write output, the normal API is: vectorcast_print_string
   vectorcast_write_to_std_out should only be used for abnormal termination
   and debug trace messages */
void vectorcast_write_to_std_out (const char *s);
/*---------------------------------------------------------------------------*/
void vcast_char_to_based_string ( char vcDest[],
                                  unsigned char vcSrc,
                                  unsigned vcUseHex );
/* ----------------------------------------------------------------------------
-- To Save Output Size, for some targets using stdout mode, we output a 
-- number rather than a filename.  So for example, we put out: 
-- "1: data" instead of: "ASCIIRES.DAT: data"
-- JJP TBD: Not sure why this needs to be in the header --
-------------------------------------------------------------------------------*/
enum vcast_env_file_kind
{
   VCAST_ASCIIRES_DAT = 1,
   VCAST_EXPECTED_DAT = 2,
   VCAST_TEMP_DIF_DAT = 3,
   VCAST_TESTINSS_DAT = 4,
   VCAST_THISTORY_DAT = 5,
   VCAST_USERDATA_DAT = 6
};
/* Get the name of the file */
char *vcast_get_filename(enum vcast_env_file_kind kind);
/* ----------------------------------------------------------------------------
-- Need to evaluate these items
-- JJP TBD
-------------------------------------------------------------------------------*/
/* -------------------------------------------------------------------------------*/
/* -------------------------------------------------------------------------------*/
/* End of File, close the Extern C block */
extern int vCAST_ITERATION_COUNTERS [3][3];
/***********************************************
 *      VectorCAST Test Harness Component      *
 *     Copyright 2018 Vector Informatik, GmbH.    *
 *              18.sp2 (07/02/18)              *
 ***********************************************/
extern vCAST_array_boolean vCAST_GLOBALS_TOUCHED[6];
enum vCAST_testcase_options_type {
        vCAST_MULTI_RETURN_SPANS_RANGE,
        vCAST_MULTI_RETURN_SPANS_COMPOUND_ITERATIONS,
        vCAST_DISPLAY_INTEGER_RESULTS_IN_HEX,
        vCAST_DISPLAY_FULL_STRING_DATA,
        vCAST_HEX_NOTATION_FOR_UNPRINTABLE_CHARS,
        vCAST_DO_COMBINATION,
        vCAST_REFERENCED_GLOBALS,
        vCAST_FLOAT_POINT_DIGITS_OF_PRECISION,
        vCAST_FLOAT_POINT_TOLERANCE,
        vCAST_EVENT_LIMIT,
        vCAST_GLOBAL_DATA_DISPLAY,
        vCAST_EXPECTED_BEFORE_UUT_CALL,
        vCAST_DATA_PARTITIONS,
        vCAST_SHOW_ONLY_DATA_WITH_EXPECTED_RESULTS,
        vCAST_SHOW_ONLY_EVENTS_WITH_EXPECTED_RESULTS};
enum vCAST_globals_display_type {
        vCAST_EACH_EVENT,
        vCAST_RANGE_ITERATION,
        vCAST_SLOT_ITERATION,
        vCAST_TESTCASE};
/***********************************************
 *      VectorCAST Test Harness Component      *
 *     Copyright 2018 Vector Informatik, GmbH.    *
 *              18.sp2 (07/02/18)              *
 ***********************************************/
/*************************************************************************
File : S0000004.c
Description : This file contains the declarations of functions in the 
   B0000004.c file.
***************************************************************************/
void vCAST_INITIALIZE_PARAMETERS(void);
void vCAST_USER_CODE_INITIALIZE(int vcast_slot_index, vCAST_boolean commands_read);
void vCAST_USER_CODE_CAPTURE (void);
void vCAST_USER_CODE_CAPTURE_GLOBALS (void);
void vCAST_ONE_SHOT_INIT(void);
void vCAST_ONE_SHOT_TERM(void);
void vCAST_GLOBAL_STUB_PROCESSING(void);
void vCAST_GLOBAL_BEGINNING_OF_STUB_PROCESSING(void);
typedef enum {
   VCAST_UCT_VALUE,
   VCAST_UCT_EXPECTED,
   VCAST_UCT_EXPECTED_GLOBALS
} VCAST_USER_CODE_TYPE;
void vCAST_USER_CODE( VCAST_USER_CODE_TYPE uct, int vcast_slot_index );
/***********************************************
 *      VectorCAST Test Harness Component      *
 *     Copyright 2018 Vector Informatik, GmbH.    *
 *              18.sp2 (07/02/18)              *
 ***********************************************/
#include "c:/vcast/mingw/include/stdlib.h"
#include "c:/vcast/mingw/include/setjmp.h"
#include "c:/vcast/mingw/include/stdio.h"
#include "c:/vcast/mingw/include/string.h"
/* Wrappers for malloc and realloc are provided in B2.c */
void * VCAST_malloc (unsigned int vcast_size);
long long VCAST_atoi (const char *vcast_str );
unsigned long long VCAST_strtoul(const char *vcast_nptr, char **vcast_endptr, int vcast_base);
int VCAST_signed_strlen (const signed char *vcast_str );
void VCAST_signed_strcpy ( signed char *VC_S, const signed char *VC_T );
 extern jmp_buf VCAST_env;
/* This define use to define the temporary strings that we use
   when we are breaking down the harness commands like: "0.0.3.4%0\n"
   We use 8 because we do not expect a unit, subprogram, parameter, or field
   to be larger than 999999\n\0
*/
typedef long int vCAST_BIG_INT;
enum vCAST_COMMAND_TYPE { vCAST_SET_VAL,
                             vCAST_PRINT,
                             vCAST_FIRST_VAL,
                             vCAST_MID_VAL,
                             vCAST_LAST_VAL,
                             vCAST_POS_INF_VAL,
                             vCAST_NEG_INF_VAL,
                             vCAST_NAN_VAL,
                             vCAST_MIN_MINUS_1_VAL,
                             vCAST_MAX_PLUS_1_VAL,
                             vCAST_ZERO_VAL,
                             vCAST_KEEP_VAL,
                             vCAST_ALLOCATE,
                             vCAST_STUB_FUNCTION,
                             vCAST_FUNCTION };
struct vCAST_HIST_ENTRY {
  int VC_U;
  int VC_S;
};
struct vCAST_ORDER_ENTRY {
  int VC_I;
  char VC_N[13];
  char VC_T[1000];
  char VC_SLOT_DESCR[1000];
  char VC_PRINT_DATA[1000];
};
enum VCAST_RANGE_DATA_TYPE {
   VCAST_NULL_TYPE = 0,
   VCAST_RANGE_TYPE,
   VCAST_LIST_TYPE
};
/* If the max range is not set by the user at all
   we default to 20 */
/* if the user explicitly sets the max range to be 0,
   it means they don't want range processing at all */
struct vCAST_RANGE_DATA
{
  char *vCAST_COMMAND; /* command */
  enum VCAST_RANGE_DATA_TYPE vCAST_type; /* Determines range, list or null */
  /* For Range */
  vCAST_long_double vCAST_MIN; /* Min value */
  vCAST_long_double vCAST_MAX; /* Max value */
  vCAST_long_double vCAST_INC; /* Increment value */
  /* For List */
  char *vCAST_list; /* The actual list values */
  /* Is integer */
  int isInteger; /* 1 if min/mid/max is integer, 0 otherwise */
  int vCAST_COMBO_GROUPING; /* Number of times to repeat a command for combination testing before resetting */
  int vCAST_NUM_VALS;
};
/* vCAST function prototypes */
vCAST_double vCAST_power (short vcast_bits);
vCAST_long_double VCAST_itod ( char vcastStringParam[] );
void vCAST_SET_TESTCASE_CONFIGURATION_OPTIONS( int VCAST_option,int VCAST_value, int VCAST_set_default);
void vCAST_SET_TESTCASE_OPTIONS ( char vcast_options[] );
void vCAST_RUN_DATA_IF (char VCAST_PARAM[], vCAST_boolean POST_CONSTRUCTOR_USER_CODE);
void vCAST_slice (char vcast_target[], char vcast_source[], int vcast_first, int vcast_last);
void vCAST_EXTRACT_DATA_FROM_COMMAND_LINE (char *vcast_buf, char VCAST_PARAM[], int VC_POSITION);
void vCAST_STR_TO_LONG_DOUBLE(char vcastStringParam[], vCAST_long_double * vcastFloatParam);
void vCAST_DOUBLE_TO_STR (vCAST_long_double VC_F, char VC_S[], int VC_AS_INT);
void vCAST_RESET_LIST_VALUES(void);
void vCAST_ITERATION_COUNTER_RESET(void);
void vCAST_RESET_ITERATION_COUNTERS(enum vCAST_testcase_options_type );
int vCAST_GET_ITERATION_COUNTER_VALUE(int, int);
void vCAST_INCREMENT_ITERATION_COUNTER(int, int);
void vCAST_EXECUTE_RANGE_COMMANDS (int);
/* if range processing is disabled, no need to do this stuff!*/
void vCAST_GET_RANGE_VALUES(char *vcast_S, struct vCAST_RANGE_DATA *vcast_range_data);
void vCAST_MODIFY_SBF_TABLE(int sbf_unit, int vcast_sub, vCAST_boolean stubbed);
void vCAST_INITIALIZE_SBF_TABLE(void);
vCAST_boolean vCAST_is_sbf(long long vcast_unit, long long vcast_sub);
typedef unsigned char vcast_sbf_object_type;
void VCAST_TI_SBF_OBJECT(vcast_sbf_object_type* vcast_param);
void vCAST_RESET_RANGE_VALUES (void);
void vCAST_INITIALIZE_RANGE_VALUES (void);
void vCAST_FREE_RANGE_VALUES(void);
void vCAST_STORE_GLOBAL_ASCII_DATA (void);
void vCAST_CREATE_EVENT_FILE (void);
void vCAST_CREATE_HIST_FILE (void);
void vCAST_OPEN_HIST_FILE (void);
void vCAST_CREATE_INST_FILE (void);
int VCAST_test_name_cmp(char *vcast_tn);
long VCAST_convert_encoded_field(const char *vcast_str);
/* Code coverage-related functions */
void vCAST_CREATE_INST_FILE (void);
void VCAST_WRITE_TO_INST_FILE (const char VC_S[]);
/* An explanation for the number of bytes required for VectorCAST/Cover.

 * 

 * This represents the maximum amount of RAM that will be required

 * to record coverage data when 100% of your application is executed.

 * It is likely that only a percentage of this storage will be 

 * required during a single program execution.

 * 

 * Please note, when using the static memory option, all of this data 

 * must be reserved in the instrumented executable through global arrays.

 * When you are not using the static memory option, this data is not 

 * reserved in the instrumented executable, and it is allocated on 

 * demand through the use of the malloc system call.

 * 

 * When instrumenting for MCDC, the size of the variables 

 * mcdc_statement_pool and avlnode_pool are controlled with the option 

 * "Maximum MC/DC expressions". The default is set to 1000, 

 * so that a large test case can execute with out fear of 

 * over flowing these buffers. The number chosen (e.g. 1000) will 

 * provide storage for that many unique MC/DC expressions.

 * 

 * For a 16 bit executable configuration:

 *   Total (no MC/DC pool storage):......................................bytes:  0 *

 * 

 * For a 32 bit executable configuration:

 *   Total (no MC/DC pool storage):......................................bytes:  0 *

 * 

 * For a 64 bit executable configuration:

 *   Total (no MC/DC pool storage):......................................bytes:  0 *

 */
void vCAST_SET_OUTPUT_TO_EVENT_FILE (void);
void vCAST_CLOSE_INST_FILE (void);
/* Coverage data */
void vCAST_SET_OUTPUT_TO_EVENT_FILE (void);
void vCAST_CLOSE_INST_FILE (void);
void vCAST_CLOSE_EVENT_FILE (void);
void vCAST_CLOSE_HIST_FILE (void);
void vCAST_WRITE_END_FILE(void);
void vCAST_OPEN_E0_FILE (void);
void vCAST_OPEN_HARNOPTS_FILE(void);
void vCAST_RESET_HARNOPTS_FILE(void);
void vCAST_OPEN_TESTORDR_FILE (void);
void VCAST_READ_TESTORDER_LINE ( char[] );
void vCAST_STORE_ASCII_DATA ( int, int, char[] );
vCAST_boolean vCAST_READ_NEXT_ORDER (void);
vCAST_boolean vCAST_SHOULD_DISPLAY_GLOBALS ( int, char[] );
extern int vcast_user_file;
extern int VCAST_EXP_FILE;
extern int vCAST_UNIT;
extern int vCAST_SUBPROGRAM;
extern vCAST_boolean vCAST_DO_DATA_IF;
extern char vCAST_TEST_NAME[];
extern int vCAST_CURRENT_SLOT;
extern int vCAST_CURRENT_ITERATION;
extern int vCAST_HIST_INDEX;
extern int vCAST_HIST_LIMIT;
extern int vCAST_ENV_HIST_LIMIT;
extern vCAST_boolean vCAST_HAS_RANGE;
extern vCAST_boolean vCAST_SKIP_ITER;
extern int vCAST_NUM_RANGE_ITERATIONS;
extern int vCAST_RANGE_COUNTER;
extern struct vCAST_RANGE_DATA vCAST_RANGE_COUNT[];
extern struct vCAST_ORDER_ENTRY vCAST_ORDER_OBJECT;
extern vCAST_long_double vCAST_PARTITIONS;
extern vCAST_boolean vCAST_COMMAND_IS_MIN_MAX;
extern int vCAST_INST_FILE;
/* file identificastion number for the ASCIIRES.DAT file */
extern int vCAST_EVENT_FILE;
/* file identification number for the THISTORY.DAT file */
extern int vCAST_HIST_FILE;
extern int vCAST_ORDER_FILE;
extern int vCAST_E0_FILE;
/* file identification number for the TEMP_DIF.DAT file */
extern int vCAST_OUTPUT_FILE;
extern int vCAST_COUNT;
extern int vCAST_CURRENT_COUNT;
extern vCAST_array_boolean vCAST_TESTCASE_OPTIONS[15];
extern vCAST_boolean vcast_is_in_union;
extern vCAST_boolean vCAST_INST_FILE_OPEN;
/* true if the ASCIIRES.DAT file is open */
extern vCAST_boolean vCAST_EVENT_FILE_OPEN;
/* true if the THISTORY.DAT file is open */
extern vCAST_boolean vCAST_HIST_FILE_OPEN;
/* default harness options (from HARNOPTS.DAT) */
extern vCAST_boolean VCAST_DEFAULT_FULL_STRINGS;
extern vCAST_boolean VCAST_DEFAULT_HEX_NOTATION;
extern vCAST_boolean VCAST_DEFAULT_DO_COMBINATION;
extern unsigned short VCAST_GLOBALS_DISPLAY; /* when to capture global data */
extern vCAST_boolean VCAST_GLOBAL_FIRST_EVENT;
extern vCAST_boolean vCAST_HEX_NOTATION; /* use hex notation or not */
extern vCAST_boolean vCAST_DO_COMBINATION_TESTING;/* generate combination or not */
struct vCAST_ORDER_ENTRY* vCAST_ORDER(void);
void vCAST_signal(int sig);
void VCAST_driver_termination(int vcast_status, int eventCode);
int vcast_get_hc_id (char *vcast_command);
void vcast_get_unit_id_str (char *vcast_command, char *vcast_unit);
int vcast_get_unit_id (char *vcast_command);
void vcast_get_subprogram_id_str (char *vcast_command, char *vcast_subprogram);
int vcast_get_subprogram_id (char *vcast_command);
void vcast_get_parameter_id_str (char *vcast_command, char *vcast_subprogram);
int vcast_get_parameter_id (char *vcast_command);
int vcast_get_percent_pos (char *vcast_command);
void vCAST_END(void);
void VCAST_SLOT_SEPARATOR ( int VC_EndOfSlot, char VC_SLOT_DESCR );
/* "limits.h" and "float.h" has limits on base types
   If we don't use it, or some types do
   not have limits, define them here */
#include "c:/vcast/mingw/include/limits.h"
#include "c:/vcast/mingw/lib/gcc/mingw32/6.3.0/include/float.h"
/* FUNCTION PROTOTYPES */
void VCAST_get_indices(char *str_val, int *array_size);
void vCAST_signal(int sig);
void vcast_not_supported (void);
void vcast_get_range_value ( int *vCAST_FIRST_VAL,
                             int *vCAST_LAST_VAL,
                             int *vCAST_MORE_DATA);
int vcast_get_param (void);
int VCAST_FIND_INDEX (void);
/*------------------------------------------------------------------*/
vCAST_double vCAST_power (short vcast_bits);
void VCAST_TI_BITFIELD ( long long *vc_VAL, int Bits, vCAST_boolean is_signed );
void VCAST_TI_STRING (
      char **vcast_param,
      int vCAST_Size,
      int from_bounded_array,
      int size_of_bounded_array );
int vcast_add_to_hex(int previousNumber, char latestDigit);
char vcast_get_non_numerical_escape(char character);
int vcast_convert_size(char * input);
char * VCAST_convert(char * input);
/* ASCII value of the first char that can be displayed */
/* ASCII value of the last char that can be displayed */
/**************************************************************************
Function: isUnprintable
Parameters: character - character to check
Description: This function returns true if the character it is given is
a nongraphical one. 
 *************************************************************************/
void vCAST_slice ( char vcast_target[], char source[], int vcast_first, int vcast_last );
vCAST_boolean vcast_proc_handles_command(int vc_m);
void VCAST_SET_GLOBAL_SIZE(unsigned int *vcast_size);
unsigned int *VCAST_GET_GLOBAL_SIZE(void);
/* EXTERNED VARIABLES */
extern int vCAST_FILE;
extern char vCAST_PARAMETER[1000];
extern char vCAST_PARAMETER_KEY[1000];
extern long long vCAST_VALUE_INT;
extern unsigned long long vCAST_VALUE_UNSIGNED;
extern vCAST_long_double vCAST_VALUE;
extern int vCAST_PARAM_LENGTH;
extern int vCAST_INDEX;
extern int vCAST_DATA_FIELD;
extern int *VCAST_index_size;
extern int VCAST_index_count;
extern enum vCAST_COMMAND_TYPE vCAST_COMMAND;
extern vCAST_boolean vCAST_VALUE_NUL;
extern vCAST_boolean vCAST_SIZE;
extern vCAST_boolean vCAST_can_print_constructor;
struct VCAST_CSU_Data_Item
{
  void *vcast_item;
  char *vcast_command;
  struct VCAST_CSU_Data_Item *vcast_next;
};
struct VCAST_CSU_Data;
void VCAST_Add_CSU_Data (struct VCAST_CSU_Data **vcast_data,
                         struct VCAST_CSU_Data_Item *vcast_data_item);
struct VCAST_CSU_Data_Item *VCAST_Get_CSU_Data (
                         struct VCAST_CSU_Data **vcast_data,
                         char *vcast_command);
void VCAST_DRIVER_8( int VC_SUBPROGRAM, char *VC_EVENT_FLAGS, char *VC_SLOT_DESCR );
void VCAST_DRIVER_9( int VC_SUBPROGRAM, char *VC_EVENT_FLAGS, char *VC_SLOT_DESCR );void VCAST_SBF_9( int VC_SUBPROGRAM );
/*vcast_header_expansion_end*/
#include "vcast_undef_9.h"
/* Include the file which contains function prototypes
for stub processing and value/expected user code */
/*vcast_header_expansion_start:vcast_uc_prototypes.h*/
void vCAST_VALUE_USER_CODE_8(int vcast_slot_index );
void vCAST_EXPECTED_USER_CODE_8(int vcast_slot_index );
void vCAST_EGLOBALS_USER_CODE_8(int vcast_slot_index );
void vCAST_STUB_PROCESSING_8(
        int UnitIndex,
        int SubprogramIndex );
void vCAST_BEGIN_STUB_PROC_8(
        int UnitIndex,
        int SubprogramIndex );
void vCAST_COMMON_STUB_PROC_8(
            int unitIndex,
            int subprogramIndex,
            int robjectIndex,
            int readEobjectData );
void vCAST_VALUE_USER_CODE_9(int vcast_slot_index );
void vCAST_EXPECTED_USER_CODE_9(int vcast_slot_index );
void vCAST_EGLOBALS_USER_CODE_9(int vcast_slot_index );
void vCAST_STUB_PROCESSING_9(
        int UnitIndex,
        int SubprogramIndex );
void vCAST_BEGIN_STUB_PROC_9(
        int UnitIndex,
        int SubprogramIndex );
void vCAST_COMMON_STUB_PROC_9(
            int unitIndex,
            int subprogramIndex,
            int robjectIndex,
            int readEobjectData );
void vCAST_VALUE_USER_CODE_9(int vcast_slot_index );
void vCAST_EXPECTED_USER_CODE_9(int vcast_slot_index );
void vCAST_EGLOBALS_USER_CODE_9(int vcast_slot_index );
void vCAST_STUB_PROCESSING_9(
        int UnitIndex,
        int SubprogramIndex );
void vCAST_BEGIN_STUB_PROC_9(
        int UnitIndex,
        int SubprogramIndex );
void vCAST_COMMON_STUB_PROC_9(
            int unitIndex,
            int subprogramIndex,
            int robjectIndex,
            int readEobjectData );
/*vcast_header_expansion_end*/
/*vcast_header_expansion_start:vcast_stubs_9.c*/
/* Begin defined extern variables */
/* End defined extern variables */
/* Begin defined static member variables */
/* End defined static member variables */
/* BEGIN PROTOTYPE STUBS */
/* END PROTOTYPE STUBS */
/*vcast_header_expansion_end*/
/* begin declarations of inlined friends */
/* end declarations of inlined friends */
void VCAST_DRIVER_9( int VC_SUBPROGRAM, char *VC_EVENT_FLAGS, char *VC_SLOT_DESCR ) {
  vCAST_MODIFY_SBF_TABLE(9, VC_SUBPROGRAM, vCAST_false);
  switch( VC_SUBPROGRAM ) {
    case 0:
      vCAST_SET_HISTORY_FLAGS ( 9, 0, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      break;
    case 1: {
      /* struct table_data_type Get_Table_Record(table_index_type Table) */
      vCAST_SET_HISTORY_FLAGS ( 9, 1, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      R_9_1 =
      ( Get_Table_Record(
        ( P_9_1_1 ) ) );
      break; }
    case 2: {
      /* void Update_Table_Record(table_index_type Table, struct table_data_type Data) */
      vCAST_SET_HISTORY_FLAGS ( 9, 2, VC_EVENT_FLAGS, VC_SLOT_DESCR );
      ( Update_Table_Record(
        ( P_9_2_1 ),
        ( P_9_2_2 ) ) );
      break; }
    default:
      vectorcast_print_string("ERROR: Internal Tool Error\n");
      break;
  } /* switch */
}
void VCAST_SBF_9( int VC_SUBPROGRAM ) {
  switch( VC_SUBPROGRAM ) {
    case 1: {
      SBF_9_1 = 0;
      break; }
    case 2: {
      SBF_9_2 = 0;
      break; }
    default:
      break;
  } /* switch */
}
/*vcast_header_expansion_start:vcast_ti_decls_9.h*/
void VCAST_TI_8_1 ( char *vcast_param ) ;
void VCAST_TI_8_3 ( float *vcast_param ) ;
void VCAST_TI_9_1 ( struct table_data_type vcast_param[6] ) ;
void VCAST_TI_9_10 ( enum desserts *vcast_param ) ;
void VCAST_TI_9_11 ( enum beverages *vcast_param ) ;
void VCAST_TI_9_12 ( struct order_type *vcast_param ) ;
void VCAST_TI_9_13 ( char vcast_param[10] ) ;
void VCAST_TI_9_14 ( struct order_type vcast_param[4] ) ;
void VCAST_TI_9_2 ( struct table_data_type *vcast_param ) ;
void VCAST_TI_9_5 ( unsigned short *vcast_param ) ;
void VCAST_TI_9_6 ( enum boolean *vcast_param ) ;
void VCAST_TI_9_7 ( enum soups *vcast_param ) ;
void VCAST_TI_9_8 ( enum salads *vcast_param ) ;
void VCAST_TI_9_9 ( enum entrees *vcast_param ) ;
/*vcast_header_expansion_end*/
void VCAST_RUN_DATA_IF_9( int VCAST_SUB_INDEX, int VCAST_PARAM_INDEX ) {
  switch ( VCAST_SUB_INDEX ) {
    case 0: /* for global objects */
      switch( VCAST_PARAM_INDEX ) {
        case 1: /* for global object Table_Data */
          VCAST_TI_9_1 ( Table_Data);
          break;
        default:
          vCAST_TOOL_ERROR = vCAST_true;
          break;
      } /* switch( VCAST_PARAM_INDEX ) */
      break; /* case 0 (global objects) */
    case 1: /* function Get_Table_Record */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_5 ( &(P_9_1_1));
          break;
        case 2:
          VCAST_TI_9_2 ( &(R_9_1));
          break;
        case 3:
          VCAST_TI_SBF_OBJECT( &SBF_9_1 );
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function Get_Table_Record */
    case 2: /* function Update_Table_Record */
      switch ( VCAST_PARAM_INDEX ) {
        case 1:
          VCAST_TI_9_5 ( &(P_9_2_1));
          break;
        case 2:
          VCAST_TI_9_2 ( &(P_9_2_2));
          break;
        case 3:
          VCAST_TI_SBF_OBJECT( &SBF_9_2 );
          break;
      } /* switch ( VCAST_PARAM_INDEX ) */
      break; /* function Update_Table_Record */
    default:
      vCAST_TOOL_ERROR = vCAST_true;
      break;
  } /* switch ( VCAST_SUB_INDEX ) */
}
/* An array */
void VCAST_TI_9_1 ( struct table_data_type vcast_param[6] )
{
  {
    int VCAST_TI_9_1_array_index = 0;
    int VCAST_TI_9_1_index = 0;
    int VCAST_TI_9_1_first, VCAST_TI_9_1_last;
    int VCAST_TI_9_1_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_1_local_field = 0;
    int VCAST_TI_9_1_value_printed = 0;
    vcast_get_range_value (&VCAST_TI_9_1_first, &VCAST_TI_9_1_last, &VCAST_TI_9_1_more_data);
    VCAST_TI_9_1_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_1_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,6);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_1_upper = 6;
      for (VCAST_TI_9_1_array_index=0; VCAST_TI_9_1_array_index< VCAST_TI_9_1_upper; VCAST_TI_9_1_array_index++){
        if ( (VCAST_TI_9_1_index >= VCAST_TI_9_1_first) && ( VCAST_TI_9_1_index <= VCAST_TI_9_1_last)){
          VCAST_TI_9_2 ( &(vcast_param[VCAST_TI_9_1_index]));
          VCAST_TI_9_1_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_1_local_field;
        } /* if */
        if (VCAST_TI_9_1_index >= VCAST_TI_9_1_last)
          break;
        VCAST_TI_9_1_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_1_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_1 */
/* An integer */
void VCAST_TI_9_5 ( unsigned short *vcast_param )
{
  switch (vCAST_COMMAND) {
    case vCAST_PRINT :
      if ( vcast_param == 0)
        vectorcast_fprint_string (vCAST_OUTPUT_FILE,"null\n");
      else {
        vectorcast_fprint_unsigned_short(vCAST_OUTPUT_FILE, *vcast_param);
        vectorcast_fprint_string(vCAST_OUTPUT_FILE, "\n");
      }
      break;
    case vCAST_KEEP_VAL:
      break; /* KEEP doesn't do anything */
  case vCAST_SET_VAL :
    *vcast_param = ( unsigned short ) vCAST_VALUE_INT;
    break;
  case vCAST_FIRST_VAL :
    *vcast_param = 0;
    break;
  case vCAST_MID_VAL :
    *vcast_param = (0 / 2) + (
                                     0xFFFF 
                                               / 2);
    break;
  case vCAST_LAST_VAL :
    *vcast_param = 
                  0xFFFF
                           ;
    break;
  case vCAST_MIN_MINUS_1_VAL :
    *vcast_param = 0;
    *vcast_param = *vcast_param - 1;
    break;
  case vCAST_MAX_PLUS_1_VAL :
    *vcast_param = 
                  0xFFFF
                           ;
    *vcast_param = *vcast_param + 1;
    break;
  case vCAST_ZERO_VAL :
    *vcast_param = 0;
    break;
  default:
    break;
} /* end switch */
} /* end VCAST_TI_9_5 */
/* A struct */
void VCAST_TI_9_2 ( struct table_data_type *vcast_param )
{
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->Is_Occupied */
      case 1: {
        VCAST_TI_9_6 ( &(vcast_param->Is_Occupied));
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->Number_In_Party */
      case 2: {
        VCAST_TI_9_5 ( &(vcast_param->Number_In_Party));
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->Designator */
      case 3: {
        VCAST_TI_8_1 ( &(vcast_param->Designator));
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->Wait_Person */
      case 4: {
        VCAST_TI_9_13 ( vcast_param->Wait_Person);
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->Order */
      case 5: {
        VCAST_TI_9_14 ( vcast_param->Order);
        break; /* end case 5*/
      } /* end case */
      /* Setting member variable vcast_param->Check_Total */
      case 6: {
        VCAST_TI_8_3 ( &(vcast_param->Check_Total));
        break; /* end case 6*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */
  }
} /* end VCAST_TI_9_2 */
/* An enumeration */
void VCAST_TI_9_6 ( enum boolean *vcast_param )
{
  switch ( vCAST_COMMAND ) {
    case vCAST_PRINT: {
      if ( vcast_param == 0 )
        vectorcast_fprint_string (vCAST_OUTPUT_FILE,"null\n");
      else {
        vectorcast_fprint_long_long(vCAST_OUTPUT_FILE, (long long)*vcast_param);
        vectorcast_fprint_string(vCAST_OUTPUT_FILE, "\n");
      } /* end else */
      } /* end vCAST_PRINT block */
      break; /* end case vCAST_PRINT */
    case vCAST_KEEP_VAL:
      break; /* KEEP doesn't do anything */
  case vCAST_SET_VAL:
    *vcast_param = (enum boolean ) vCAST_VALUE_INT;
    break;
  case vCAST_FIRST_VAL:
    *vcast_param = v_false;
    break; /* end case vCAST_FIRST_VAL */
  case vCAST_LAST_VAL:
    *vcast_param = v_true;
    break; /* end case vCAST_LAST_VAL */
  default:
    vCAST_TOOL_ERROR = vCAST_true;
    break; /* end case default */
} /* end switch */
} /* end VCAST_TI_9_6 */
/* An array */
void VCAST_TI_9_13 ( char vcast_param[10] )
{
  {
    int VCAST_TI_9_13_array_index = 0;
    int VCAST_TI_9_13_index = 0;
    int VCAST_TI_9_13_first, VCAST_TI_9_13_last;
    int VCAST_TI_9_13_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_13_local_field = 0;
    int VCAST_TI_9_13_value_printed = 0;
    int VCAST_TI_9_13_is_string = (VCAST_FIND_INDEX()==-1);
    vcast_get_range_value (&VCAST_TI_9_13_first, &VCAST_TI_9_13_last, &VCAST_TI_9_13_more_data);
    VCAST_TI_9_13_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_13_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,10);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_13_upper = 10;
      for (VCAST_TI_9_13_array_index=0; VCAST_TI_9_13_array_index< VCAST_TI_9_13_upper; VCAST_TI_9_13_array_index++){
        if ( (VCAST_TI_9_13_index >= VCAST_TI_9_13_first) && ( VCAST_TI_9_13_index <= VCAST_TI_9_13_last)){
          if ( VCAST_TI_9_13_is_string )
            VCAST_TI_STRING ( (char**)&vcast_param, sizeof ( vcast_param ), 1,VCAST_TI_9_13_upper);
          else
            VCAST_TI_8_1 ( &(vcast_param[VCAST_TI_9_13_index]));
          VCAST_TI_9_13_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_13_local_field;
        } /* if */
        if (VCAST_TI_9_13_index >= VCAST_TI_9_13_last)
          break;
        VCAST_TI_9_13_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_13_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_13 */
/* An array */
void VCAST_TI_9_14 ( struct order_type vcast_param[4] )
{
  {
    int VCAST_TI_9_14_array_index = 0;
    int VCAST_TI_9_14_index = 0;
    int VCAST_TI_9_14_first, VCAST_TI_9_14_last;
    int VCAST_TI_9_14_more_data; /* true if there is more data in the current command */
    int VCAST_TI_9_14_local_field = 0;
    int VCAST_TI_9_14_value_printed = 0;
    vcast_get_range_value (&VCAST_TI_9_14_first, &VCAST_TI_9_14_last, &VCAST_TI_9_14_more_data);
    VCAST_TI_9_14_local_field = vCAST_DATA_FIELD;
    if ( vCAST_SIZE && (!VCAST_TI_9_14_more_data)) { /* get the size of the array */
      vectorcast_fprint_integer (vCAST_OUTPUT_FILE,4);
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
      vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n");
    } else {
      int VCAST_TI_9_14_upper = 4;
      for (VCAST_TI_9_14_array_index=0; VCAST_TI_9_14_array_index< VCAST_TI_9_14_upper; VCAST_TI_9_14_array_index++){
        if ( (VCAST_TI_9_14_index >= VCAST_TI_9_14_first) && ( VCAST_TI_9_14_index <= VCAST_TI_9_14_last)){
          VCAST_TI_9_12 ( &(vcast_param[VCAST_TI_9_14_index]));
          VCAST_TI_9_14_value_printed = 1;
          vCAST_DATA_FIELD = VCAST_TI_9_14_local_field;
        } /* if */
        if (VCAST_TI_9_14_index >= VCAST_TI_9_14_last)
          break;
        VCAST_TI_9_14_index++;
      } /* loop */
      if ((vCAST_COMMAND == vCAST_PRINT)&&(!VCAST_TI_9_14_value_printed))
        vectorcast_fprint_string(vCAST_OUTPUT_FILE,"<<past end of array>>\n");
    } /* if */
  }
} /* end VCAST_TI_9_14 */
/* A struct */
void VCAST_TI_9_12 ( struct order_type *vcast_param )
{
  {
    switch ( vcast_get_param () ) { /* Choose field member */
      /* Setting member variable vcast_param->Soup */
      case 1: {
        VCAST_TI_9_7 ( &(vcast_param->Soup));
        break; /* end case 1*/
      } /* end case */
      /* Setting member variable vcast_param->Salad */
      case 2: {
        VCAST_TI_9_8 ( &(vcast_param->Salad));
        break; /* end case 2*/
      } /* end case */
      /* Setting member variable vcast_param->Entree */
      case 3: {
        VCAST_TI_9_9 ( &(vcast_param->Entree));
        break; /* end case 3*/
      } /* end case */
      /* Setting member variable vcast_param->Dessert */
      case 4: {
        VCAST_TI_9_10 ( &(vcast_param->Dessert));
        break; /* end case 4*/
      } /* end case */
      /* Setting member variable vcast_param->Beverage */
      case 5: {
        VCAST_TI_9_11 ( &(vcast_param->Beverage));
        break; /* end case 5*/
      } /* end case */
      default:
        vCAST_TOOL_ERROR = vCAST_true;
    } /* end switch */
  }
} /* end VCAST_TI_9_12 */
/* An enumeration */
void VCAST_TI_9_7 ( enum soups *vcast_param )
{
  switch ( vCAST_COMMAND ) {
    case vCAST_PRINT: {
      if ( vcast_param == 0 )
        vectorcast_fprint_string (vCAST_OUTPUT_FILE,"null\n");
      else {
        vectorcast_fprint_long_long(vCAST_OUTPUT_FILE, (long long)*vcast_param);
        vectorcast_fprint_string(vCAST_OUTPUT_FILE, "\n");
      } /* end else */
      } /* end vCAST_PRINT block */
      break; /* end case vCAST_PRINT */
    case vCAST_KEEP_VAL:
      break; /* KEEP doesn't do anything */
  case vCAST_SET_VAL:
    *vcast_param = (enum soups ) vCAST_VALUE_INT;
    break;
  case vCAST_FIRST_VAL:
    *vcast_param = NO_SOUP;
    break; /* end case vCAST_FIRST_VAL */
  case vCAST_LAST_VAL:
    *vcast_param = CHOWDER;
    break; /* end case vCAST_LAST_VAL */
  default:
    vCAST_TOOL_ERROR = vCAST_true;
    break; /* end case default */
} /* end switch */
} /* end VCAST_TI_9_7 */
/* An enumeration */
void VCAST_TI_9_8 ( enum salads *vcast_param )
{
  switch ( vCAST_COMMAND ) {
    case vCAST_PRINT: {
      if ( vcast_param == 0 )
        vectorcast_fprint_string (vCAST_OUTPUT_FILE,"null\n");
      else {
        vectorcast_fprint_long_long(vCAST_OUTPUT_FILE, (long long)*vcast_param);
        vectorcast_fprint_string(vCAST_OUTPUT_FILE, "\n");
      } /* end else */
      } /* end vCAST_PRINT block */
      break; /* end case vCAST_PRINT */
    case vCAST_KEEP_VAL:
      break; /* KEEP doesn't do anything */
  case vCAST_SET_VAL:
    *vcast_param = (enum salads ) vCAST_VALUE_INT;
    break;
  case vCAST_FIRST_VAL:
    *vcast_param = NO_SALAD;
    break; /* end case vCAST_FIRST_VAL */
  case vCAST_LAST_VAL:
    *vcast_param = GREEN;
    break; /* end case vCAST_LAST_VAL */
  default:
    vCAST_TOOL_ERROR = vCAST_true;
    break; /* end case default */
} /* end switch */
} /* end VCAST_TI_9_8 */
/* An enumeration */
void VCAST_TI_9_9 ( enum entrees *vcast_param )
{
  switch ( vCAST_COMMAND ) {
    case vCAST_PRINT: {
      if ( vcast_param == 0 )
        vectorcast_fprint_string (vCAST_OUTPUT_FILE,"null\n");
      else {
        vectorcast_fprint_long_long(vCAST_OUTPUT_FILE, (long long)*vcast_param);
        vectorcast_fprint_string(vCAST_OUTPUT_FILE, "\n");
      } /* end else */
      } /* end vCAST_PRINT block */
      break; /* end case vCAST_PRINT */
    case vCAST_KEEP_VAL:
      break; /* KEEP doesn't do anything */
  case vCAST_SET_VAL:
    *vcast_param = (enum entrees ) vCAST_VALUE_INT;
    break;
  case vCAST_FIRST_VAL:
    *vcast_param = NO_ENTREE;
    break; /* end case vCAST_FIRST_VAL */
  case vCAST_LAST_VAL:
    *vcast_param = PASTA;
    break; /* end case vCAST_LAST_VAL */
  default:
    vCAST_TOOL_ERROR = vCAST_true;
    break; /* end case default */
} /* end switch */
} /* end VCAST_TI_9_9 */
/* An enumeration */
void VCAST_TI_9_10 ( enum desserts *vcast_param )
{
  switch ( vCAST_COMMAND ) {
    case vCAST_PRINT: {
      if ( vcast_param == 0 )
        vectorcast_fprint_string (vCAST_OUTPUT_FILE,"null\n");
      else {
        vectorcast_fprint_long_long(vCAST_OUTPUT_FILE, (long long)*vcast_param);
        vectorcast_fprint_string(vCAST_OUTPUT_FILE, "\n");
      } /* end else */
      } /* end vCAST_PRINT block */
      break; /* end case vCAST_PRINT */
    case vCAST_KEEP_VAL:
      break; /* KEEP doesn't do anything */
  case vCAST_SET_VAL:
    *vcast_param = (enum desserts ) vCAST_VALUE_INT;
    break;
  case vCAST_FIRST_VAL:
    *vcast_param = NO_DESSERT;
    break; /* end case vCAST_FIRST_VAL */
  case vCAST_LAST_VAL:
    *vcast_param = FRUIT;
    break; /* end case vCAST_LAST_VAL */
  default:
    vCAST_TOOL_ERROR = vCAST_true;
    break; /* end case default */
} /* end switch */
} /* end VCAST_TI_9_10 */
/* An enumeration */
void VCAST_TI_9_11 ( enum beverages *vcast_param )
{
  switch ( vCAST_COMMAND ) {
    case vCAST_PRINT: {
      if ( vcast_param == 0 )
        vectorcast_fprint_string (vCAST_OUTPUT_FILE,"null\n");
      else {
        vectorcast_fprint_long_long(vCAST_OUTPUT_FILE, (long long)*vcast_param);
        vectorcast_fprint_string(vCAST_OUTPUT_FILE, "\n");
      } /* end else */
      } /* end vCAST_PRINT block */
      break; /* end case vCAST_PRINT */
    case vCAST_KEEP_VAL:
      break; /* KEEP doesn't do anything */
  case vCAST_SET_VAL:
    *vcast_param = (enum beverages ) vCAST_VALUE_INT;
    break;
  case vCAST_FIRST_VAL:
    *vcast_param = NO_BEVERAGE;
    break; /* end case vCAST_FIRST_VAL */
  case vCAST_LAST_VAL:
    *vcast_param = SODA;
    break; /* end case vCAST_LAST_VAL */
  default:
    vCAST_TOOL_ERROR = vCAST_true;
    break; /* end case default */
} /* end switch */
} /* end VCAST_TI_9_11 */
void VCAST_TI_RANGE_DATA_9 ( void ) {
  /* Range Data for TI (array) VCAST_TI_9_1 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100003\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,6);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (scalar) VCAST_TI_8_1 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_SCALAR\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"900002\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,
                                              (-128) 
                                                       );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,(
                                               (-128)
                                                       /2) + (
                                                              127
                                                                      /2) );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,
                                              127 
                                                       );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  /* Range Data for TI (scalar) VCAST_TI_8_3 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_SCALAR\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"900004\n" );
  vectorcast_fprint_long_float (vCAST_OUTPUT_FILE,-(3.40282346638528859812e+38F) );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_long_float (vCAST_OUTPUT_FILE,0 );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_long_float (vCAST_OUTPUT_FILE,3.40282346638528859812e+38F );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  /* Range Data for TI (scalar) VCAST_TI_9_5 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_SCALAR\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"900005\n" );
  vectorcast_fprint_unsigned_short (vCAST_OUTPUT_FILE,0 );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_unsigned_short (vCAST_OUTPUT_FILE,(0 / 2) + (
                                                                        0xFFFF 
                                                                                  / 2) );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_unsigned_short (vCAST_OUTPUT_FILE,
                                                     0xFFFF 
                                                               );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  /* Range Data for TI (array) VCAST_TI_9_13 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100004\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,10);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_14 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, "NEW_ARRAY\n" );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100005\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,4);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
}
/* Include the file which contains function implementations
for stub processing and value/expected user code */
/*vcast_header_expansion_start:database_uc.c*/
void vCAST_VALUE_USER_CODE_9(int vcast_slot_index ) {
  {
  /* INSERT VALUE_USER_CODE_9 */
  }
}
void vCAST_EXPECTED_USER_CODE_9(int vcast_slot_index ) {
  {
  /* INSERT EXPECTED_USER_CODE_9 */
  }
}
void vCAST_EGLOBALS_USER_CODE_9(int vcast_slot_index ) {
  {
  /* INSERT EXPECTED_GLOBALS_USER_CODE_9 */
  }
}
void vCAST_STUB_PROCESSING_9(
        int UnitIndex,
        int SubprogramIndex ) {
  vCAST_GLOBAL_STUB_PROCESSING();
  {
  /* INSERT STUB_VAL_USER_CODE_9 */
  }
}
void vCAST_BEGIN_STUB_PROC_9(
        int UnitIndex,
        int SubprogramIndex ) {
  vCAST_GLOBAL_BEGINNING_OF_STUB_PROCESSING();
  {
  /* INSERT STUB_EXP_USER_CODE_9 */
  }
}
void VCAST_USER_CODE_UNIT_9( VCAST_USER_CODE_TYPE uct, int vcast_slot_index ) {
  switch( uct ) {
    case VCAST_UCT_VALUE:
      vCAST_VALUE_USER_CODE_9(vcast_slot_index);
      break;
    case VCAST_UCT_EXPECTED:
      vCAST_EXPECTED_USER_CODE_9(vcast_slot_index);
      break;
    case VCAST_UCT_EXPECTED_GLOBALS:
      vCAST_EGLOBALS_USER_CODE_9(vcast_slot_index);
      break;
  } /* switch( uct ) */
}
/*vcast_header_expansion_end*/
void vCAST_COMMON_STUB_PROC_9(
            int unitIndex,
            int subprogramIndex,
            int robjectIndex,
            int readEobjectData )
{
   vCAST_BEGIN_STUB_PROC_9(unitIndex, subprogramIndex);
   if ( robjectIndex )
      vCAST_READ_COMMAND_DATA_FOR_ONE_PARAM( unitIndex, subprogramIndex, robjectIndex );
   if ( readEobjectData )
      vCAST_READ_COMMAND_DATA_FOR_ONE_PARAM( unitIndex, subprogramIndex, 0 );
   vCAST_SET_HISTORY( unitIndex, subprogramIndex );
   vCAST_READ_COMMAND_DATA( vCAST_CURRENT_SLOT, unitIndex, subprogramIndex, vCAST_true, vCAST_false );
   vCAST_READ_COMMAND_DATA_FOR_USER_GLOBALS();
   vCAST_STUB_PROCESSING_9(unitIndex, subprogramIndex);
}
/*vcast_separate_expansion_end*/
