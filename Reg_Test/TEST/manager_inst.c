/* VectorCAST/Cover */
#ifndef VCAST_CONDITION_TYP
#define VCAST_CONDITION_TYP long long
#endif


#ifdef __cplusplus
extern "C" {
#endif

/*
---------------------------------------
-- Copyright 2010 Vector Software    --
-- East Greenwich, Rhode Island USA --
---------------------------------------
*/

/* Defined variable usage for this file:

   Variable names that are indented apply only if the enclosing variable is set

   <<no defined variables set>>    : Output is written to the file TESTINSS.DAT

   VCAST_USE_STDOUT                : Output is written to stdout using puts
      VCAST_USE_PUTCHAR            : Output is written to stdout using putchar
      VCAST_USE_GH_SYSCALL         : Output is written to stdout using the GH syscall
                                     (For Green Hills INTEGRITY 178B)

   VCAST_CUSTOM_STD_OUTPUT         : custom user code required to write Output 
                                     to stdout or serial port interface
                                   : Need to also define VCAST_USE_STDOUT in order
                                     to set the stdout flag. 

   VCAST_CUSTOM_FILE_OUTPUT        : custom user file i/o code required to write 
                                     Output to TESTINSS.DAT 

   VCAST_USE_STD_STRING            : This define turns ON the use of memset from the
                                     system header string.h.

   VCAST_USE_STATIC_MEMORY         : No malloc is available, use alternate data.
      VCAST_MAX_MCDC_STATEMENTS    : The number of MCDC statement conditions 
                                     that can be reached when malloc is not 
                                     available. 
   VCAST_MAX_COVERED_SUBPROGRAMS   : The number of subprograms that may be
                                     covered. 
   VCAST_ENABLE_DATA_CLEAR_API     : Enable this macro to add the API
                                     VCAST_CLEAR_COVERAGE_DATA, which allows
                                     you to clear the currently collected
                                     coverage data during the execution of
                                     the instrumented executable.
   VCAST_ATTRIBUTE_CODE            : Allows the user to specify an attribute
                                     that will be placed before the ascii, 
                                     binary and subprogram coverage pool 
                                     global variables. This is useful for 
                                     putting this data in specific places
                                     in memory.
   VCAST_DUMP_CALLBACK             : If this is defined to a function name, 
                                     then when the user calls 
                                     VCAST_DUMP_COVERAGE_DATA, the function
                                     this was defined to will be called. The 
                                     purpose is to allow the users main loop
                                     to be given a chance to run within a 
                                     certain time frame.
   VCAST_FLUSH_DATA                : Use the flush system call after each
                                     string is written with fprintf in
                                     VCAST_WRITE_TO_INST_FILE_COVERAGE. The
                                     default is disabled. Define to any value
                                     to enable.
   VCAST_APPEND_WIN32_PID          : Append the process id to the TESTINSS.DAT
                                     file. This uses windows specific system
                                     calls to get the pid.
   VCAST_APPEND_POSIX_PID          : Append the process id to the TESTINSS.DAT
                                     file. This uses Posix specific system
                                     calls to get the pid.
   VCAST_APPEND_SECONDS_SINCE_EPOCH: Append the number of seconds since the
                                     epoch to the TESTINSS.DAT
                                     file. This uses the C library time() call.
*/

#ifndef __C_COVER_H__
#define __C_COVER_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifndef VCAST_PRINTF_INTEGER 
#define VCAST_PRINTF_INTEGER "%d"
#endif
#ifndef VCAST_PRINTF_STRING
#define VCAST_PRINTF_STRING "%s"
#endif

#ifndef VCAST_MCDC_STORAGE_TYPE
#ifdef VCAST_UNSIGNED_LONG_MCDC_STORAGE
#define VCAST_MCDC_STORAGE_TYPE unsigned long
#else 
#ifdef VCAST_HAS_LONGLONG
#ifdef VCAST_MICROSOFT_LONG_LONG
#define VCAST_MCDC_STORAGE_TYPE unsigned __int64
#else 
#define VCAST_MCDC_STORAGE_TYPE unsigned long long
#endif /* VCAST_MICROSOFT_LONG_LONG */
#else 
#define VCAST_MCDC_STORAGE_TYPE unsigned long
#endif /* VCAST_HAS_LONGLONG */
#endif /* VCAST_UNSIGNED_LONG_MCDC_STORAGE */
#endif /* VCAST_MCDC_STORAGE_TYPE */

/* AVL prototypes */
typedef struct vcast_mcdc_statement* VCAST_elementType;
struct AVLNode;
typedef struct AVLNode *VCAST_position;
typedef struct AVLNode *AVLTree;
VCAST_position vcast_find (VCAST_elementType VCAST_X, AVLTree VCAST_T);
AVLTree vcast_insert (VCAST_elementType VCAST_X, AVLTree VCAST_T);

struct vcast_mcdc_statement
{
  VCAST_MCDC_STORAGE_TYPE mcdc_bits;
  VCAST_MCDC_STORAGE_TYPE mcdc_bits_used;
};
typedef struct vcast_mcdc_statement *vcast_mcdc_statement_ptr;

void VCAST_REGISTER_DUMP_AT_EXIT (void);
void VCAST_CLEAR_COVERAGE_DATA (void);
void VCAST_DUMP_COVERAGE_DATA (void);

int VCAST_WRITE_FN_CALL_ID(short unit, int id);
int VCAST_WRITE_STATEMENT_ID(short unit, int id);
int VCAST_WRITE_BRANCH_ID(short unit, int id, const char* TorF);
int VCAST_WRITE_OPTIMIZED_MCDC_ID(short unit, int id, char num_conditions,
                                  VCAST_MCDC_STORAGE_TYPE mcdc_bits, 
                                  VCAST_MCDC_STORAGE_TYPE mcdc_bits_used);

#ifdef VCAST_COVERAGE_POINTS_AS_MACROS

/*
 * The instrumentation macros provide an alternative to the
 * instrumentation point functions, which are used by default. If you
 * need to add additional statements to the instrumentation points, we
 * suggest modifying the functions, and not the macros. First, ensure
 * the "Instrument using macros in c_cover.h" option is disabled and
 * then modify the functions of the same names in the c_cover_io.c file.
 *
 * The instrumentation point macros must be expressions or a
 * comma-separated list of expressions. To use them, enable the
 * "Instrument using macros in c_cover.h" option and reinstrument all
 * source files. Modification of the macros is allowed, but very
 * difficult.  You are strongly encouranged to verify coverage data when
 * using modified macros.
 */

#define VCAST_FN_CALL_INSTRUMENTATION_POINT_REALTIME(covdata, unit, id) (\
  ((covdata[id >> 3] & (((unsigned long)1) << id % 8)) == 0) ? \
  (covdata[id >> 3] |= (((unsigned long)1) << id % 8),         \
   VCAST_WRITE_FN_CALL_ID(unit, id)) : 1                             \
)
#define VCAST_FN_CALL_INSTRUMENTATION_POINT_BUFFERED(covdata, unit, id) (\
  covdata[id >> 3] |= (((unsigned long)1) << (id % 8)) \
)
#define VCAST_FN_CALL_INSTRUMENTATION_POINT_ANIMATION(unit, id) (\
  VCAST_WRITE_FN_CALL_ID(unit, id) \
)

#if !defined(VCAST_PACK_INSTRUMENTATION_STORAGE)
#define VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(covdata, unit, id) (\
  (covdata[id] == 0) ? (covdata[id] = 1, VCAST_WRITE_STATEMENT_ID(unit, id)) : 1 \
)
#else
#define VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(covdata, unit, id) (\
  ((covdata[id >> 3] & (((unsigned long)1) << id % 8)) == 0) ? \
  (covdata[id >> 3] |= (((unsigned long)1) << id % 8), \
   VCAST_WRITE_STATEMENT_ID(unit, id)) : 1 \
)
#endif

#if !defined(VCAST_PACK_INSTRUMENTATION_STORAGE)
#define VCAST_STATEMENT_INSTRUMENTATION_POINT_BUFFERED(covdata, unit, id) (\
  covdata[id] = 1 \
)
#else
#define VCAST_STATEMENT_INSTRUMENTATION_POINT_BUFFERED(covdata, unit, id) (\
  covdata[id >> 3] |= (((unsigned long)1) << (id % 8)) \
)
#endif
#define VCAST_STATEMENT_INSTRUMENTATION_POINT_ANIMATION(unit, id) (\
  VCAST_WRITE_STATEMENT_ID(unit, id) \
)

/* The first half of a byte stores the true conditions, and the second
   half stores the false conditions.  Thus, the bits are indexed as:

   id  cond  bit
   1    T     1
   2    T     2
   3    T     3
   4    T     4
   1    F     5
   2    F     6
   3    F     7
   4    F     8
*/
#if !defined(VCAST_PACK_INSTRUMENTATION_STORAGE)
#define VCAST_BRANCH_INSTRUMENTATION_POINT_REALTIME(covdata, unit, id, condition) ( \
  condition ? \
  ((covdata[id * 2] == 0) ? (covdata[id * 2] = 1, VCAST_WRITE_BRANCH_ID(unit, id, "T"), 1) : 1) \
  : \
  ((covdata[id * 2 + 1] == 0) ? (covdata[id * 2 + 1] = 1, VCAST_WRITE_BRANCH_ID(unit, id, "F"), 0) : 0) \
)
#else
#define VCAST_BRANCH_INSTRUMENTATION_POINT_REALTIME(covdata, unit, id, condition) ( \
  condition ? \
  (((covdata[id >> 2] & (((unsigned long)1) << (id % 4 << 1))) == 0) ?       \
   (covdata[id >> 2] |= (((unsigned long)1) << (id % 4 << 1)),               \
    VCAST_WRITE_BRANCH_ID(unit, id, "T"), 1) : 1)      \
  : \
  (((covdata[id >> 2] & (((unsigned long)1) << ((id % 4 << 1) + 1))) == 0) ?   \
   (covdata[id >> 2] |= (((unsigned long)1) << ((id % 4 << 1) + 1)),       \
    VCAST_WRITE_BRANCH_ID(unit, id, "F"), 0) : 0)          \
)
#endif

#if !defined(VCAST_PACK_INSTRUMENTATION_STORAGE)
#define VCAST_BRANCH_INSTRUMENTATION_POINT_BUFFERED(covdata, unit, id, condition) ( \
  condition ? \
  ((covdata[id * 2] == 0) ? (covdata[id * 2] = 1, 1) : 1) \
  : \
  ((covdata[id * 2 + 1] == 0) ? (covdata[id * 2 + 1] = 1, 0) : 0) \
)
#else
#define VCAST_BRANCH_INSTRUMENTATION_POINT_BUFFERED(covdata, unit, id, condition) (\
  condition ? \
  (covdata[id >> 2] |= (((unsigned long)1) << (id % 4 << 1)), 1)     \
  : \
  (covdata[id >> 2] |= (((unsigned long)1) << ((id % 4 << 1) + 1)), 0)     \
)
#endif

#define VCAST_BRANCH_INSTRUMENTATION_POINT_ANIMATION(unit, id, condition, onPath) ( \
  condition ? \
  (VCAST_WRITE_BRANCH_ID(unit, id, onPath ? "T" : "TX"), 1)      \
  : \
  (VCAST_WRITE_BRANCH_ID(unit, id, onPath ? "F" : "FX"), 0)      \
)

#define VCAST_OPTIMIZED_MCDC_CONDITION_INSTRUMENTATION_POINT_REALTIME_0(covdata, unit, id, condition) (\
  condition ?                                                                                \
  (((covdata[id >> 2] & ((1 << ((id << 1) % 8)) | (1 << (((id << 1) + 1) % 8)))) == 0) ?     \
    (covdata[id >> 2] |= ((1 << ((id << 1) % 8)) | (1 << (((id << 1) + 1) % 8))),            \
     VCAST_WRITE_OPTIMIZED_MCDC_ID(unit, id, 'a', (VCAST_MCDC_STORAGE_TYPE)1,(VCAST_MCDC_STORAGE_TYPE)1), 1) : 1) \
      :                                                                                      \
      (((covdata[id >> 2] & ((1 << ((id << 1) % 8)) | (0 << (((id << 1) + 1) % 8)))) == 0) ? \
       (covdata[id >> 2] |= ((1 << ((id << 1) % 8)) | (0 << (((id << 1) + 1) % 8))),         \
        VCAST_WRITE_OPTIMIZED_MCDC_ID(unit, id, 'a', (VCAST_MCDC_STORAGE_TYPE)0, (VCAST_MCDC_STORAGE_TYPE)1), 0) : 0) \
)

#define VCAST_OPTIMIZED_MCDC_CONDITION_INSTRUMENTATION_POINT_BUFFERED_0(covdata, unit, id, condition) (\
  condition ?                                                                      \
  (covdata[id >> 2] |= ((1 << ((id << 1) % 8)) | (1 << (((id << 1) + 1) % 8))), 1) \
  :                                                                                \
  (covdata[id >> 2] |= ((1 << ((id << 1) % 8)) | (0 << (((id << 1) + 1) % 8))), 0) \
)

#else

int VCAST_FN_CALL_INSTRUMENTATION_POINT_REALTIME(char* covdata, int unit, int id);
int VCAST_FN_CALL_INSTRUMENTATION_POINT_BUFFERED(char* covdata, int unit, int id);
int VCAST_FN_CALL_INSTRUMENTATION_POINT_ANIMATION(int unit, int id);
int VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(char* covdata, int unit, int id);
int VCAST_STATEMENT_INSTRUMENTATION_POINT_BUFFERED(char* covdata, int unit, int id);
int VCAST_STATEMENT_INSTRUMENTATION_POINT_ANIMATION(int unit, int id);
int VCAST_BRANCH_INSTRUMENTATION_POINT_REALTIME(char* covdata, int unit, int id, VCAST_CONDITION_TYP condition);
int VCAST_BRANCH_INSTRUMENTATION_POINT_BUFFERED(char* covdata, int unit, int id, VCAST_CONDITION_TYP condition);
int VCAST_BRANCH_INSTRUMENTATION_POINT_ANIMATION(int unit, int id, VCAST_CONDITION_TYP condition, int onPath);
VCAST_CONDITION_TYP 
VCAST_OPTIMIZED_MCDC_CONDITION_INSTRUMENTATION_POINT_REALTIME_0(char* covdata,
                                                            int unit, int id,
                                                            VCAST_CONDITION_TYP condition);
VCAST_CONDITION_TYP 
VCAST_OPTIMIZED_MCDC_CONDITION_INSTRUMENTATION_POINT_BUFFERED_0(char* covdata,
                                                            int unit, int id,
                                                            VCAST_CONDITION_TYP condition);

#endif /* VCAST_COVERAGE_POINTS_AS_MACROS */

VCAST_CONDITION_TYP
VCAST_SAVE_MCDC_SUBCONDITION (struct vcast_mcdc_statement *mcdc_statement,
                              int bit_index, VCAST_CONDITION_TYP condition);

VCAST_CONDITION_TYP 
VCAST_MCDC_CONDITION_INSTRUMENTATION_POINT_REALTIME(AVLTree *vcast_mcdc_array,
                                                    struct vcast_mcdc_statement *mcdc_statement,
                                                    int unit, int id,
                                                    VCAST_CONDITION_TYP condition);

VCAST_CONDITION_TYP 
VCAST_MCDC_CONDITION_INSTRUMENTATION_POINT_ANIMATION(struct vcast_mcdc_statement *mcdc_statement,
                                                     int unit, int id, VCAST_CONDITION_TYP condition);

VCAST_CONDITION_TYP 
VCAST_MCDC_CONDITION_INSTRUMENTATION_POINT_BUFFERED(AVLTree *vcast_mcdc_array,
                                                    struct vcast_mcdc_statement *coverage,
                                                    int unit, int id,
                                                    VCAST_CONDITION_TYP condition);

VCAST_CONDITION_TYP 
VCAST_OPTIMIZED_MCDC_CONDITION_INSTRUMENTATION_POINT_REALTIME_1(char* covdata,
                                                            struct vcast_mcdc_statement *mcdc_statement,
                                                            int unit, int id,
                                                            VCAST_CONDITION_TYP condition);
VCAST_CONDITION_TYP 
VCAST_OPTIMIZED_MCDC_CONDITION_INSTRUMENTATION_POINT_REALTIME(char* covdata,
                                                          struct vcast_mcdc_statement *mcdc_statement,
                                                          int unit, int id,
                                                          int num_conditions,
                                                          VCAST_CONDITION_TYP condition);

VCAST_CONDITION_TYP 
VCAST_OPTIMIZED_MCDC_CONDITION_INSTRUMENTATION_POINT_BUFFERED_1(char* covdata,
                                                            struct vcast_mcdc_statement *mcdc_statement,
                                                            int unit, int id,
                                                            VCAST_CONDITION_TYP condition);
VCAST_CONDITION_TYP 
VCAST_OPTIMIZED_MCDC_CONDITION_INSTRUMENTATION_POINT_BUFFERED_2(char* covdata,
                                                            struct vcast_mcdc_statement *mcdc_statement,
                                                            int unit, int id,
                                                            VCAST_CONDITION_TYP condition);

VCAST_CONDITION_TYP 
VCAST_OPTIMIZED_MCDC_CONDITION_INSTRUMENTATION_POINT_BUFFERED(char* covdata,
                                                          struct vcast_mcdc_statement *mcdc_statement,
                                                          int unit, int id,
                                                          int num_conditions,
                                                          VCAST_CONDITION_TYP condition);

VCAST_CONDITION_TYP 
VCAST_OPTIMIZED_MCDC_CONDITION_INSTRUMENTATION_POINT_ANIMATION(struct vcast_mcdc_statement *mcdc_statement,
                                                           int unit, int id,
                                                           int num_conditions,
                                                           VCAST_CONDITION_TYP condition);
                                                           
                                                           
int vcastDataCoupleRead (int vc_probeIndex);
int vcastDataCoupleWrite (
       int vc_probeIndex,  
       int vc_dataType,  
       void* vc_value);   
int vcastControlCoupleCall (int vc_probeIndex);
void vcastDumpCouplingData (void);
void vcastCouplingDataInit (void);
                                                           

char * vcast_strcat (char *VC_S, const char *VC_T);
char * vcast_int_to_string (char *buf, VCAST_MCDC_STORAGE_TYPE vc_x);
void VCAST_WRITE_TO_INST_FILE_COVERAGE (const char *S, int flush);
                                                           

#ifndef VCAST_UNIT_TEST_TOOL

#ifdef VCAST_HAS_LONGLONG
  #ifdef VCAST_MICROSOFT_LONG_LONG
  #define VCAST_LONGEST_INT __int64
  #else
  #define VCAST_LONGEST_INT long long
  #endif
#else
  #define VCAST_LONGEST_INT long
#endif

#ifndef VCAST_UNSIGNED_CONVERSION_TYPE
#define VCAST_UNSIGNED_CONVERSION_TYPE unsigned VCAST_LONGEST_INT
#endif
#ifndef VCAST_SIGNED_CONVERSION_TYPE
#define VCAST_SIGNED_CONVERSION_TYPE VCAST_LONGEST_INT
#endif

/* types */
/* ifdef VCAST_NO_FLOAT */
#ifdef VCAST_NO_FLOAT
typedef long vCAST_double;
typedef long vCAST_long_double;
/* else */
#else
typedef double vCAST_double;
/* ifdef VCAST_ALLOW_LONG_DOUBLE */
#if defined(VCAST_ALLOW_LONG_DOUBLE) || !defined(VCAST_NO_LONG_DOUBLE)
typedef long double vCAST_long_double;
#else
typedef double vCAST_long_double;
#endif
/* endif VCAST_ALLOW_LONG_DOUBLE */
#endif
/* endif VCAST_NO_FLOAT */

VCAST_LONGEST_INT vcast_abs ( VCAST_LONGEST_INT vcNum );
void vectorcast_signed_to_string ( char vcDest[], VCAST_LONGEST_INT vcSrc );
int VCAST_special_compare ( char *vcDouble1, char *vcDouble2, int vcLen );
void vectorcast_strcpy ( char *VC_S, const char *VC_T );
void vectorcast_float_to_string( char *mixed_str, vCAST_long_double f );

/* This macro is always defined, because, it "tells" the c_cover_io.c 
   file that the prototypes are available to it. */
#define VCAST_PROBE_PRINT_AVAILABLE

void vcast_probe_print (const char *S);
void vcast_probe_print_int (VCAST_SIGNED_CONVERSION_TYPE i);
void vcast_probe_print_unsigned (VCAST_UNSIGNED_CONVERSION_TYPE i);
void vcast_probe_print_float (vCAST_long_double f);

#endif /* VCAST_UNIT_TEST_TOOL */

#ifdef __cplusplus
}
#endif

#endif

#ifdef __cplusplus
}
#endif
#ifdef __cplusplus
extern "C" {
#endif
extern char vcast_unit_stmt_bytes_9[];
extern AVLTree vcast_unit_mcdc_bytes_9[];
extern char vcast_unit_optimized_mcdc_bytes_9_0[];
extern char vcast_unit_optimized_mcdc_bytes_9_1[];
extern char vcast_unit_optimized_mcdc_bytes_9_2[];
extern char vcast_unit_optimized_mcdc_bytes_9_3[];
extern char vcast_unit_optimized_mcdc_bytes_9_4[];
extern char vcast_unit_optimized_mcdc_bytes_9_5[];
extern char vcast_unit_optimized_mcdc_bytes_9_6[];
extern char vcast_unit_optimized_mcdc_bytes_9_7[];
extern char vcast_unit_optimized_mcdc_bytes_9_8[];
#ifdef __cplusplus
}
#endif
/*vcast_header_expansion_start:C:/VCAST/Tutorial/c/ctypes.h*/
typedef struct _Ifx_SCU_ACCEN0_Bits
{
    unsigned int EN0 : 1;
    unsigned int EN1 : 1;
    unsigned int EN2 : 1;
    unsigned int EN3 : 1;
    unsigned int EN4 : 1;
    unsigned int EN5 : 1;
    unsigned int EN6 : 1;
    unsigned int EN7 : 1;
    unsigned int EN8 : 1;
    unsigned int EN9 : 1;
    unsigned int EN10 : 1;
    unsigned int EN11 : 1;
    unsigned int EN12 : 1;
    unsigned int EN13 : 1;
    unsigned int EN14 : 1;
    unsigned int EN15 : 1;
    unsigned int EN16 : 1;
    unsigned int EN17 : 1;
    unsigned int EN18 : 1;
    unsigned int EN19 : 1;
    unsigned int EN20 : 1;
    unsigned int EN21 : 1;
    unsigned int EN22 : 1;
    unsigned int EN23 : 1;
    unsigned int EN24 : 1;
    unsigned int EN25 : 1;
    unsigned int EN26 : 1;
    unsigned int EN27 : 1;
    unsigned int EN28 : 1;
    unsigned int EN29 : 1;
    unsigned int EN30 : 1;
    unsigned int EN31 : 1;
} Ifx_SCU_ACCEN0_Bits;
typedef struct _Ifx_SCU_ACCEN1_Bits
{
    unsigned int reserved_0 : 32;
} Ifx_SCU_ACCEN1_Bits;
typedef struct _Ifx_SCU_ARSTDIS_Bits
{
    unsigned int STM0DIS : 1;
    unsigned int STM1DIS : 1;
    unsigned int STM2DIS : 1;
    unsigned int reserved_3 : 29;
} Ifx_SCU_ARSTDIS_Bits;
typedef struct _Ifx_SCU_CCUCON0_Bits
{
    unsigned int reserved_0 : 4;
    unsigned int BAUD2DIV : 4;
    unsigned int SRIDIV : 4;
    unsigned int LPDIV : 4;
    unsigned int SPBDIV : 4;
    unsigned int FSI2DIV : 2;
    unsigned int reserved_22 : 2;
    unsigned int FSIDIV : 2;
    unsigned int reserved_26 : 2;
    unsigned int CLKSEL : 2;
    unsigned int UP : 1;
    unsigned int LCK : 1;
} Ifx_SCU_CCUCON0_Bits;
typedef struct _Ifx_SCU_CCUCON1_Bits
{
    unsigned int CANDIV : 4;
    unsigned int ERAYDIV : 4;
    unsigned int STMDIV : 4;
    unsigned int GTMDIV : 4;
    unsigned int ETHDIV : 4;
    unsigned int ASCLINFDIV : 4;
    unsigned int ASCLINSDIV : 4;
    unsigned int INSEL : 2;
    unsigned int UP : 1;
    unsigned int LCK : 1;
} Ifx_SCU_CCUCON1_Bits;
typedef struct _Ifx_SCU_CCUCON2_Bits
{
    unsigned int BBBDIV : 4;
    unsigned int reserved_4 : 26;
    unsigned int UP : 1;
    unsigned int LCK : 1;
} Ifx_SCU_CCUCON2_Bits;
typedef struct _Ifx_SCU_CCUCON3_Bits
{
    unsigned int PLLDIV : 6;
    unsigned int PLLSEL : 2;
    unsigned int PLLERAYDIV : 6;
    unsigned int PLLERAYSEL : 2;
    unsigned int SRIDIV : 6;
    unsigned int SRISEL : 2;
    unsigned int reserved_24 : 6;
    unsigned int UP : 1;
    unsigned int LCK : 1;
} Ifx_SCU_CCUCON3_Bits;
typedef struct _Ifx_SCU_CCUCON4_Bits
{
    unsigned int SPBDIV : 6;
    unsigned int SPBSEL : 2;
    unsigned int GTMDIV : 6;
    unsigned int GTMSEL : 2;
    unsigned int STMDIV : 6;
    unsigned int STMSEL : 2;
    unsigned int reserved_24 : 6;
    unsigned int UP : 1;
    unsigned int LCK : 1;
} Ifx_SCU_CCUCON4_Bits;
typedef struct _Ifx_SCU_CCUCON5_Bits
{
    unsigned int MAXDIV : 4;
    unsigned int reserved_4 : 26;
    unsigned int UP : 1;
    unsigned int LCK : 1;
} Ifx_SCU_CCUCON5_Bits;
typedef struct _Ifx_SCU_CCUCON6_Bits
{
    unsigned int CPU0DIV : 6;
    unsigned int reserved_6 : 26;
} Ifx_SCU_CCUCON6_Bits;
typedef struct _Ifx_SCU_CHIPID_Bits
{
    unsigned int CHREV : 6;
    unsigned int CHTEC : 2;
    unsigned int CHID : 8;
    unsigned int EEA : 1;
    unsigned int UCODE : 7;
    unsigned int FSIZE : 4;
    unsigned int SP : 2;
    unsigned int SEC : 1;
    unsigned int reserved_31 : 1;
} Ifx_SCU_CHIPID_Bits;
typedef struct _Ifx_SCU_DTSCON_Bits
{
    unsigned int PWD : 1;
    unsigned int START : 1;
    unsigned int reserved_2 : 2;
    unsigned int CAL : 22;
    unsigned int reserved_26 : 5;
    unsigned int SLCK : 1;
} Ifx_SCU_DTSCON_Bits;
typedef struct _Ifx_SCU_DTSLIM_Bits
{
    unsigned int LOWER : 10;
    unsigned int reserved_10 : 5;
    unsigned int LLU : 1;
    unsigned int UPPER : 10;
    unsigned int reserved_26 : 4;
    unsigned int SLCK : 1;
    unsigned int UOF : 1;
} Ifx_SCU_DTSLIM_Bits;
typedef struct _Ifx_SCU_DTSSTAT_Bits
{
    unsigned int RESULT : 10;
    unsigned int reserved_10 : 4;
    unsigned int RDY : 1;
    unsigned int BUSY : 1;
    unsigned int reserved_16 : 16;
} Ifx_SCU_DTSSTAT_Bits;
typedef struct _Ifx_SCU_EICR_Bits
{
    unsigned int reserved_0 : 4;
    unsigned int EXIS0 : 3;
    unsigned int reserved_7 : 1;
    unsigned int FEN0 : 1;
    unsigned int REN0 : 1;
    unsigned int LDEN0 : 1;
    unsigned int EIEN0 : 1;
    unsigned int INP0 : 3;
    unsigned int reserved_15 : 5;
    unsigned int EXIS1 : 3;
    unsigned int reserved_23 : 1;
    unsigned int FEN1 : 1;
    unsigned int REN1 : 1;
    unsigned int LDEN1 : 1;
    unsigned int EIEN1 : 1;
    unsigned int INP1 : 3;
    unsigned int reserved_31 : 1;
} Ifx_SCU_EICR_Bits;
typedef struct _Ifx_SCU_EIFR_Bits
{
    unsigned int INTF0 : 1;
    unsigned int INTF1 : 1;
    unsigned int INTF2 : 1;
    unsigned int INTF3 : 1;
    unsigned int INTF4 : 1;
    unsigned int INTF5 : 1;
    unsigned int INTF6 : 1;
    unsigned int INTF7 : 1;
    unsigned int reserved_8 : 24;
} Ifx_SCU_EIFR_Bits;
typedef struct _Ifx_SCU_EMSR_Bits
{
    unsigned int POL : 1;
    unsigned int MODE : 1;
    unsigned int ENON : 1;
    unsigned int PSEL : 1;
    unsigned int reserved_4 : 12;
    unsigned int EMSF : 1;
    unsigned int SEMSF : 1;
    unsigned int reserved_18 : 6;
    unsigned int EMSFM : 2;
    unsigned int SEMSFM : 2;
    unsigned int reserved_28 : 4;
} Ifx_SCU_EMSR_Bits;
typedef struct _Ifx_SCU_ESRCFG_Bits
{
    unsigned int reserved_0 : 7;
    unsigned int EDCON : 2;
    unsigned int reserved_9 : 23;
} Ifx_SCU_ESRCFG_Bits;
typedef struct _Ifx_SCU_ESROCFG_Bits
{
    unsigned int ARI : 1;
    unsigned int ARC : 1;
    unsigned int reserved_2 : 30;
} Ifx_SCU_ESROCFG_Bits;
typedef struct _Ifx_SCU_EVR13CON_Bits
{
    unsigned int reserved_0 : 28;
    unsigned int EVR13OFF : 1;
    unsigned int BPEVR13OFF : 1;
    unsigned int reserved_30 : 1;
    unsigned int LCK : 1;
} Ifx_SCU_EVR13CON_Bits;
typedef struct _Ifx_SCU_EVRADCSTAT_Bits
{
    unsigned int ADC13V : 8;
    unsigned int reserved_8 : 8;
    unsigned int ADCSWDV : 8;
    unsigned int reserved_24 : 7;
    unsigned int VAL : 1;
} Ifx_SCU_EVRADCSTAT_Bits;
typedef struct _Ifx_SCU_EVRMONCTRL_Bits
{
    unsigned int EVR13OVMOD : 2;
    unsigned int reserved_2 : 2;
    unsigned int EVR13UVMOD : 2;
    unsigned int reserved_6 : 10;
    unsigned int SWDOVMOD : 2;
    unsigned int reserved_18 : 2;
    unsigned int SWDUVMOD : 2;
    unsigned int reserved_22 : 8;
    unsigned int SLCK : 1;
    unsigned int reserved_31 : 1;
} Ifx_SCU_EVRMONCTRL_Bits;
typedef struct _Ifx_SCU_EVROVMON_Bits
{
    unsigned int EVR13OVVAL : 8;
    unsigned int reserved_8 : 8;
    unsigned int SWDOVVAL : 8;
    unsigned int reserved_24 : 6;
    unsigned int SLCK : 1;
    unsigned int LCK : 1;
} Ifx_SCU_EVROVMON_Bits;
typedef struct _Ifx_SCU_EVRRSTCON_Bits
{
    unsigned int reserved_0 : 28;
    unsigned int RSTSWDOFF : 1;
    unsigned int BPRSTSWDOFF : 1;
    unsigned int SLCK : 1;
    unsigned int LCK : 1;
} Ifx_SCU_EVRRSTCON_Bits;
typedef struct _Ifx_SCU_EVRSDCOEFF2_Bits
{
    unsigned int SD33P : 4;
    unsigned int reserved_4 : 4;
    unsigned int SD33I : 4;
    unsigned int reserved_12 : 19;
    unsigned int LCK : 1;
} Ifx_SCU_EVRSDCOEFF2_Bits;
typedef struct _Ifx_SCU_EVRSDCTRL1_Bits
{
    unsigned int SDFREQSPRD : 4;
    unsigned int reserved_4 : 4;
    unsigned int TON : 8;
    unsigned int TOFF : 8;
    unsigned int SDSTEP : 4;
    unsigned int SYNCDIV : 3;
    unsigned int LCK : 1;
} Ifx_SCU_EVRSDCTRL1_Bits;
typedef struct _Ifx_SCU_EVRSDCTRL2_Bits
{
    unsigned int reserved_0 : 8;
    unsigned int STBS : 2;
    unsigned int STSP : 2;
    unsigned int NS : 2;
    unsigned int OL : 1;
    unsigned int PIAD : 1;
    unsigned int ADCMODE : 4;
    unsigned int ADCLPF : 2;
    unsigned int ADCLSB : 1;
    unsigned int reserved_23 : 1;
    unsigned int SDLUT : 6;
    unsigned int reserved_30 : 1;
    unsigned int LCK : 1;
} Ifx_SCU_EVRSDCTRL2_Bits;
typedef struct _Ifx_SCU_EVRSDCTRL3_Bits
{
    unsigned int SDOLCON : 7;
    unsigned int MODSEL : 1;
    unsigned int MODLOW : 7;
    unsigned int reserved_15 : 1;
    unsigned int SDVOKLVL : 6;
    unsigned int MODMAN : 2;
    unsigned int MODHIGH : 7;
    unsigned int LCK : 1;
} Ifx_SCU_EVRSDCTRL3_Bits;
typedef struct _Ifx_SCU_EVRSTAT_Bits
{
    unsigned int EVR13 : 1;
    unsigned int OV13 : 1;
    unsigned int reserved_2 : 2;
    unsigned int OVSWD : 1;
    unsigned int UV13 : 1;
    unsigned int reserved_6 : 1;
    unsigned int UVSWD : 1;
    unsigned int reserved_8 : 2;
    unsigned int BGPROK : 1;
    unsigned int reserved_11 : 1;
    unsigned int SCMOD : 2;
    unsigned int reserved_14 : 18;
} Ifx_SCU_EVRSTAT_Bits;
typedef struct _Ifx_SCU_EVRUVMON_Bits
{
    unsigned int EVR13UVVAL : 8;
    unsigned int reserved_8 : 8;
    unsigned int SWDUVVAL : 8;
    unsigned int reserved_24 : 6;
    unsigned int SLCK : 1;
    unsigned int LCK : 1;
} Ifx_SCU_EVRUVMON_Bits;
typedef struct _Ifx_SCU_EXTCON_Bits
{
    unsigned int EN0 : 1;
    unsigned int reserved_1 : 1;
    unsigned int SEL0 : 4;
    unsigned int reserved_6 : 10;
    unsigned int EN1 : 1;
    unsigned int NSEL : 1;
    unsigned int SEL1 : 4;
    unsigned int reserved_22 : 2;
    unsigned int DIV1 : 8;
} Ifx_SCU_EXTCON_Bits;
typedef struct _Ifx_SCU_FDR_Bits
{
    unsigned int STEP : 10;
    unsigned int reserved_10 : 4;
    unsigned int DM : 2;
    unsigned int RESULT : 10;
    unsigned int reserved_26 : 5;
    unsigned int DISCLK : 1;
} Ifx_SCU_FDR_Bits;
typedef struct _Ifx_SCU_FMR_Bits
{
    unsigned int FS0 : 1;
    unsigned int FS1 : 1;
    unsigned int FS2 : 1;
    unsigned int FS3 : 1;
    unsigned int FS4 : 1;
    unsigned int FS5 : 1;
    unsigned int FS6 : 1;
    unsigned int FS7 : 1;
    unsigned int reserved_8 : 8;
    unsigned int FC0 : 1;
    unsigned int FC1 : 1;
    unsigned int FC2 : 1;
    unsigned int FC3 : 1;
    unsigned int FC4 : 1;
    unsigned int FC5 : 1;
    unsigned int FC6 : 1;
    unsigned int FC7 : 1;
    unsigned int reserved_24 : 8;
} Ifx_SCU_FMR_Bits;
typedef struct _Ifx_SCU_ID_Bits
{
    unsigned int MODREV : 8;
    unsigned int MODTYPE : 8;
    unsigned int MODNUMBER : 16;
} Ifx_SCU_ID_Bits;
typedef struct _Ifx_SCU_IGCR_Bits
{
    unsigned int IPEN00 : 1;
    unsigned int IPEN01 : 1;
    unsigned int IPEN02 : 1;
    unsigned int IPEN03 : 1;
    unsigned int IPEN04 : 1;
    unsigned int IPEN05 : 1;
    unsigned int IPEN06 : 1;
    unsigned int IPEN07 : 1;
    unsigned int reserved_8 : 5;
    unsigned int GEEN0 : 1;
    unsigned int IGP0 : 2;
    unsigned int IPEN10 : 1;
    unsigned int IPEN11 : 1;
    unsigned int IPEN12 : 1;
    unsigned int IPEN13 : 1;
    unsigned int IPEN14 : 1;
    unsigned int IPEN15 : 1;
    unsigned int IPEN16 : 1;
    unsigned int IPEN17 : 1;
    unsigned int reserved_24 : 5;
    unsigned int GEEN1 : 1;
    unsigned int IGP1 : 2;
} Ifx_SCU_IGCR_Bits;
typedef struct _Ifx_SCU_IN_Bits
{
    unsigned int P0 : 1;
    unsigned int P1 : 1;
    unsigned int reserved_2 : 30;
} Ifx_SCU_IN_Bits;
typedef struct _Ifx_SCU_IOCR_Bits
{
    unsigned int reserved_0 : 4;
    unsigned int PC0 : 4;
    unsigned int reserved_8 : 4;
    unsigned int PC1 : 4;
    unsigned int reserved_16 : 16;
} Ifx_SCU_IOCR_Bits;
typedef struct _Ifx_SCU_LBISTCTRL0_Bits
{
    unsigned int LBISTREQ : 1;
    unsigned int LBISTREQP : 1;
    unsigned int PATTERNS : 14;
    unsigned int reserved_16 : 16;
} Ifx_SCU_LBISTCTRL0_Bits;
typedef struct _Ifx_SCU_LBISTCTRL1_Bits
{
    unsigned int SEED : 23;
    unsigned int reserved_23 : 1;
    unsigned int SPLITSH : 3;
    unsigned int BODY : 1;
    unsigned int LBISTFREQU : 4;
} Ifx_SCU_LBISTCTRL1_Bits;
typedef struct _Ifx_SCU_LBISTCTRL2_Bits
{
    unsigned int SIGNATURE : 24;
    unsigned int reserved_24 : 7;
    unsigned int LBISTDONE : 1;
} Ifx_SCU_LBISTCTRL2_Bits;
typedef struct _Ifx_SCU_LCLCON0_Bits
{
    unsigned int reserved_0 : 16;
    unsigned int LS : 1;
    unsigned int reserved_17 : 14;
    unsigned int LSEN : 1;
} Ifx_SCU_LCLCON0_Bits;
typedef struct _Ifx_SCU_LCLTEST_Bits
{
    unsigned int LCLT0 : 1;
    unsigned int LCLT1 : 1;
    unsigned int reserved_2 : 30;
} Ifx_SCU_LCLTEST_Bits;
typedef struct _Ifx_SCU_MANID_Bits
{
    unsigned int DEPT : 5;
    unsigned int MANUF : 11;
    unsigned int reserved_16 : 16;
} Ifx_SCU_MANID_Bits;
typedef struct _Ifx_SCU_OMR_Bits
{
    unsigned int PS0 : 1;
    unsigned int PS1 : 1;
    unsigned int reserved_2 : 14;
    unsigned int PCL0 : 1;
    unsigned int PCL1 : 1;
    unsigned int reserved_18 : 14;
} Ifx_SCU_OMR_Bits;
typedef struct _Ifx_SCU_OSCCON_Bits
{
    unsigned int reserved_0 : 1;
    unsigned int PLLLV : 1;
    unsigned int OSCRES : 1;
    unsigned int GAINSEL : 2;
    unsigned int MODE : 2;
    unsigned int SHBY : 1;
    unsigned int PLLHV : 1;
    unsigned int reserved_9 : 1;
    unsigned int X1D : 1;
    unsigned int X1DEN : 1;
    unsigned int reserved_12 : 4;
    unsigned int OSCVAL : 5;
    unsigned int reserved_21 : 2;
    unsigned int APREN : 1;
    unsigned int reserved_24 : 8;
} Ifx_SCU_OSCCON_Bits;
typedef struct _Ifx_SCU_OUT_Bits
{
    unsigned int P0 : 1;
    unsigned int P1 : 1;
    unsigned int reserved_2 : 30;
} Ifx_SCU_OUT_Bits;
typedef struct _Ifx_SCU_OVCCON_Bits
{
    unsigned int CSEL0 : 1;
    unsigned int CSEL1 : 1;
    unsigned int CSEL2 : 1;
    unsigned int reserved_3 : 13;
    unsigned int OVSTRT : 1;
    unsigned int OVSTP : 1;
    unsigned int DCINVAL : 1;
    unsigned int reserved_19 : 5;
    unsigned int OVCONF : 1;
    unsigned int POVCONF : 1;
    unsigned int reserved_26 : 6;
} Ifx_SCU_OVCCON_Bits;
typedef struct _Ifx_SCU_OVCENABLE_Bits
{
    unsigned int OVEN0 : 1;
    unsigned int OVEN1 : 1;
    unsigned int OVEN2 : 1;
    unsigned int reserved_3 : 29;
} Ifx_SCU_OVCENABLE_Bits;
typedef struct _Ifx_SCU_PDISC_Bits
{
    unsigned int PDIS0 : 1;
    unsigned int PDIS1 : 1;
    unsigned int reserved_2 : 30;
} Ifx_SCU_PDISC_Bits;
typedef struct _Ifx_SCU_PDR_Bits
{
    unsigned int PD0 : 3;
    unsigned int PL0 : 1;
    unsigned int PD1 : 3;
    unsigned int PL1 : 1;
    unsigned int reserved_8 : 24;
} Ifx_SCU_PDR_Bits;
typedef struct _Ifx_SCU_PDRR_Bits
{
    unsigned int PDR0 : 1;
    unsigned int PDR1 : 1;
    unsigned int PDR2 : 1;
    unsigned int PDR3 : 1;
    unsigned int PDR4 : 1;
    unsigned int PDR5 : 1;
    unsigned int PDR6 : 1;
    unsigned int PDR7 : 1;
    unsigned int reserved_8 : 24;
} Ifx_SCU_PDRR_Bits;
typedef struct _Ifx_SCU_PLLCON0_Bits
{
    unsigned int VCOBYP : 1;
    unsigned int VCOPWD : 1;
    unsigned int MODEN : 1;
    unsigned int reserved_3 : 1;
    unsigned int SETFINDIS : 1;
    unsigned int CLRFINDIS : 1;
    unsigned int OSCDISCDIS : 1;
    unsigned int reserved_7 : 2;
    unsigned int NDIV : 7;
    unsigned int PLLPWD : 1;
    unsigned int reserved_17 : 1;
    unsigned int RESLD : 1;
    unsigned int reserved_19 : 5;
    unsigned int PDIV : 4;
    unsigned int reserved_28 : 4;
} Ifx_SCU_PLLCON0_Bits;
typedef struct _Ifx_SCU_PLLCON1_Bits
{
    unsigned int K2DIV : 7;
    unsigned int reserved_7 : 1;
    unsigned int K3DIV : 7;
    unsigned int reserved_15 : 1;
    unsigned int K1DIV : 7;
    unsigned int reserved_23 : 9;
} Ifx_SCU_PLLCON1_Bits;
typedef struct _Ifx_SCU_PLLCON2_Bits
{
    unsigned int MODCFG : 16;
    unsigned int reserved_16 : 16;
} Ifx_SCU_PLLCON2_Bits;
typedef struct _Ifx_SCU_PLLERAYCON0_Bits
{
    unsigned int VCOBYP : 1;
    unsigned int VCOPWD : 1;
    unsigned int reserved_2 : 2;
    unsigned int SETFINDIS : 1;
    unsigned int CLRFINDIS : 1;
    unsigned int OSCDISCDIS : 1;
    unsigned int reserved_7 : 2;
    unsigned int NDIV : 5;
    unsigned int reserved_14 : 2;
    unsigned int PLLPWD : 1;
    unsigned int reserved_17 : 1;
    unsigned int RESLD : 1;
    unsigned int reserved_19 : 5;
    unsigned int PDIV : 4;
    unsigned int reserved_28 : 4;
} Ifx_SCU_PLLERAYCON0_Bits;
typedef struct _Ifx_SCU_PLLERAYCON1_Bits
{
    unsigned int K2DIV : 7;
    unsigned int reserved_7 : 1;
    unsigned int K3DIV : 4;
    unsigned int reserved_12 : 4;
    unsigned int K1DIV : 7;
    unsigned int reserved_23 : 9;
} Ifx_SCU_PLLERAYCON1_Bits;
typedef struct _Ifx_SCU_PLLERAYSTAT_Bits
{
    unsigned int VCOBYST : 1;
    unsigned int PWDSTAT : 1;
    unsigned int VCOLOCK : 1;
    unsigned int FINDIS : 1;
    unsigned int K1RDY : 1;
    unsigned int K2RDY : 1;
    unsigned int reserved_6 : 26;
} Ifx_SCU_PLLERAYSTAT_Bits;
typedef struct _Ifx_SCU_PLLSTAT_Bits
{
    unsigned int VCOBYST : 1;
    unsigned int reserved_1 : 1;
    unsigned int VCOLOCK : 1;
    unsigned int FINDIS : 1;
    unsigned int K1RDY : 1;
    unsigned int K2RDY : 1;
    unsigned int reserved_6 : 1;
    unsigned int MODRUN : 1;
    unsigned int reserved_8 : 24;
} Ifx_SCU_PLLSTAT_Bits;
typedef struct _Ifx_SCU_PMCSR_Bits
{
    unsigned int REQSLP : 2;
    unsigned int SMUSLP : 1;
    unsigned int reserved_3 : 5;
    unsigned int PMST : 3;
    unsigned int reserved_11 : 21;
} Ifx_SCU_PMCSR_Bits;
typedef struct _Ifx_SCU_PMSWCR0_Bits
{
    unsigned int reserved_0 : 1;
    unsigned int ESR1WKEN : 1;
    unsigned int PINAWKEN : 1;
    unsigned int PINBWKEN : 1;
    unsigned int ESR0DFEN : 1;
    unsigned int ESR0EDCON : 2;
    unsigned int ESR1DFEN : 1;
    unsigned int ESR1EDCON : 2;
    unsigned int PINADFEN : 1;
    unsigned int PINAEDCON : 2;
    unsigned int PINBDFEN : 1;
    unsigned int PINBEDCON : 2;
    unsigned int reserved_16 : 1;
    unsigned int STBYRAMSEL : 2;
    unsigned int reserved_19 : 1;
    unsigned int WUTWKEN : 1;
    unsigned int reserved_21 : 2;
    unsigned int PORSTDF : 1;
    unsigned int reserved_24 : 1;
    unsigned int DCDCSYNC : 1;
    unsigned int reserved_26 : 3;
    unsigned int ESR0TRIST : 1;
    unsigned int reserved_30 : 1;
    unsigned int LCK : 1;
} Ifx_SCU_PMSWCR0_Bits;
typedef struct _Ifx_SCU_PMSWCR1_Bits
{
    unsigned int reserved_0 : 12;
    unsigned int IRADIS : 1;
    unsigned int reserved_13 : 14;
    unsigned int STBYEVEN : 1;
    unsigned int STBYEV : 3;
    unsigned int reserved_31 : 1;
} Ifx_SCU_PMSWCR1_Bits;
typedef struct _Ifx_SCU_PMSWCR3_Bits
{
    unsigned int WUTREL : 24;
    unsigned int reserved_24 : 4;
    unsigned int WUTDIV : 1;
    unsigned int WUTEN : 1;
    unsigned int WUTMODE : 1;
    unsigned int LCK : 1;
} Ifx_SCU_PMSWCR3_Bits;
typedef struct _Ifx_SCU_PMSWSTAT_Bits
{
    unsigned int reserved_0 : 2;
    unsigned int ESR1WKP : 1;
    unsigned int ESR1OVRUN : 1;
    unsigned int PINAWKP : 1;
    unsigned int PINAOVRUN : 1;
    unsigned int PINBWKP : 1;
    unsigned int PINBOVRUN : 1;
    unsigned int reserved_8 : 1;
    unsigned int PORSTDF : 1;
    unsigned int HWCFGEVR : 3;
    unsigned int STBYRAM : 2;
    unsigned int reserved_15 : 1;
    unsigned int WUTWKP : 1;
    unsigned int WUTOVRUN : 1;
    unsigned int reserved_18 : 1;
    unsigned int WUTWKEN : 1;
    unsigned int ESR1WKEN : 1;
    unsigned int PINAWKEN : 1;
    unsigned int PINBWKEN : 1;
    unsigned int reserved_23 : 4;
    unsigned int ESR0TRIST : 1;
    unsigned int reserved_28 : 1;
    unsigned int WUTEN : 1;
    unsigned int WUTMODE : 1;
    unsigned int WUTRUN : 1;
} Ifx_SCU_PMSWSTAT_Bits;
typedef struct _Ifx_SCU_PMSWSTATCLR_Bits
{
    unsigned int reserved_0 : 2;
    unsigned int ESR1WKPCLR : 1;
    unsigned int ESR1OVRUNCLR : 1;
    unsigned int PINAWKPCLR : 1;
    unsigned int PINAOVRUNCLR : 1;
    unsigned int PINBWKPCLR : 1;
    unsigned int PINBOVRUNCLR : 1;
    unsigned int reserved_8 : 8;
    unsigned int WUTWKPCLR : 1;
    unsigned int WUTOVRUNCLR : 1;
    unsigned int reserved_18 : 14;
} Ifx_SCU_PMSWSTATCLR_Bits;
typedef struct _Ifx_SCU_PMSWUTCNT_Bits
{
    unsigned int WUTCNT : 24;
    unsigned int reserved_24 : 7;
    unsigned int VAL : 1;
} Ifx_SCU_PMSWUTCNT_Bits;
typedef struct _Ifx_SCU_RSTCON2_Bits
{
    unsigned int reserved_0 : 1;
    unsigned int CLRC : 1;
    unsigned int reserved_2 : 10;
    unsigned int CSS0 : 1;
    unsigned int CSS1 : 1;
    unsigned int CSS2 : 1;
    unsigned int reserved_15 : 1;
    unsigned int USRINFO : 16;
} Ifx_SCU_RSTCON2_Bits;
typedef struct _Ifx_SCU_RSTCON_Bits
{
    unsigned int ESR0 : 2;
    unsigned int ESR1 : 2;
    unsigned int reserved_4 : 2;
    unsigned int SMU : 2;
    unsigned int SW : 2;
    unsigned int STM0 : 2;
    unsigned int STM1 : 2;
    unsigned int STM2 : 2;
    unsigned int reserved_16 : 16;
} Ifx_SCU_RSTCON_Bits;
typedef struct _Ifx_SCU_RSTSTAT_Bits
{
    unsigned int ESR0 : 1;
    unsigned int ESR1 : 1;
    unsigned int reserved_2 : 1;
    unsigned int SMU : 1;
    unsigned int SW : 1;
    unsigned int STM0 : 1;
    unsigned int STM1 : 1;
    unsigned int STM2 : 1;
    unsigned int reserved_8 : 8;
    unsigned int PORST : 1;
    unsigned int reserved_17 : 1;
    unsigned int CB0 : 1;
    unsigned int CB1 : 1;
    unsigned int CB3 : 1;
    unsigned int reserved_21 : 2;
    unsigned int EVR13 : 1;
    unsigned int EVR33 : 1;
    unsigned int SWD : 1;
    unsigned int reserved_26 : 2;
    unsigned int STBYR : 1;
    unsigned int reserved_29 : 3;
} Ifx_SCU_RSTSTAT_Bits;
typedef struct _Ifx_SCU_SAFECON_Bits
{
    unsigned int HBT : 1;
    unsigned int reserved_1 : 31;
} Ifx_SCU_SAFECON_Bits;
typedef struct _Ifx_SCU_STSTAT_Bits
{
    unsigned int HWCFG : 8;
    unsigned int FTM : 7;
    unsigned int MODE : 1;
    unsigned int FCBAE : 1;
    unsigned int LUDIS : 1;
    unsigned int reserved_18 : 1;
    unsigned int TRSTL : 1;
    unsigned int SPDEN : 1;
    unsigned int reserved_21 : 3;
    unsigned int RAMINT : 1;
    unsigned int reserved_25 : 7;
} Ifx_SCU_STSTAT_Bits;
typedef struct _Ifx_SCU_SWRSTCON_Bits
{
    unsigned int reserved_0 : 1;
    unsigned int SWRSTREQ : 1;
    unsigned int reserved_2 : 30;
} Ifx_SCU_SWRSTCON_Bits;
typedef struct _Ifx_SCU_SYSCON_Bits
{
    unsigned int CCTRIG0 : 1;
    unsigned int reserved_1 : 1;
    unsigned int RAMINTM : 2;
    unsigned int SETLUDIS : 1;
    unsigned int reserved_5 : 3;
    unsigned int DATM : 1;
    unsigned int reserved_9 : 23;
} Ifx_SCU_SYSCON_Bits;
typedef struct _Ifx_SCU_TRAPCLR_Bits
{
    unsigned int ESR0T : 1;
    unsigned int ESR1T : 1;
    unsigned int reserved_2 : 1;
    unsigned int SMUT : 1;
    unsigned int reserved_4 : 28;
} Ifx_SCU_TRAPCLR_Bits;
typedef struct _Ifx_SCU_TRAPDIS_Bits
{
    unsigned int ESR0T : 1;
    unsigned int ESR1T : 1;
    unsigned int reserved_2 : 1;
    unsigned int SMUT : 1;
    unsigned int reserved_4 : 28;
} Ifx_SCU_TRAPDIS_Bits;
typedef struct _Ifx_SCU_TRAPSET_Bits
{
    unsigned int ESR0T : 1;
    unsigned int ESR1T : 1;
    unsigned int reserved_2 : 1;
    unsigned int SMUT : 1;
    unsigned int reserved_4 : 28;
} Ifx_SCU_TRAPSET_Bits;
typedef struct _Ifx_SCU_TRAPSTAT_Bits
{
    unsigned int ESR0T : 1;
    unsigned int ESR1T : 1;
    unsigned int reserved_2 : 1;
    unsigned int SMUT : 1;
    unsigned int reserved_4 : 28;
} Ifx_SCU_TRAPSTAT_Bits;
typedef struct _Ifx_SCU_WDTCPU_CON0_Bits
{
    unsigned int ENDINIT : 1;
    unsigned int LCK : 1;
    unsigned int PW : 14;
    unsigned int REL : 16;
} Ifx_SCU_WDTCPU_CON0_Bits;
typedef struct _Ifx_SCU_WDTCPU_CON1_Bits
{
    unsigned int reserved_0 : 2;
    unsigned int IR0 : 1;
    unsigned int DR : 1;
    unsigned int reserved_4 : 1;
    unsigned int IR1 : 1;
    unsigned int UR : 1;
    unsigned int PAR : 1;
    unsigned int TCR : 1;
    unsigned int TCTR : 7;
    unsigned int reserved_16 : 16;
} Ifx_SCU_WDTCPU_CON1_Bits;
typedef struct _Ifx_SCU_WDTCPU_SR_Bits
{
    unsigned int AE : 1;
    unsigned int OE : 1;
    unsigned int IS0 : 1;
    unsigned int DS : 1;
    unsigned int TO : 1;
    unsigned int IS1 : 1;
    unsigned int US : 1;
    unsigned int PAS : 1;
    unsigned int TCS : 1;
    unsigned int TCT : 7;
    unsigned int TIM : 16;
} Ifx_SCU_WDTCPU_SR_Bits;
typedef struct _Ifx_SCU_WDTS_CON0_Bits
{
    unsigned int ENDINIT : 1;
    unsigned int LCK : 1;
    unsigned int PW : 14;
    unsigned int REL : 16;
} Ifx_SCU_WDTS_CON0_Bits;
typedef struct _Ifx_SCU_WDTS_CON1_Bits
{
    unsigned int CLRIRF : 1;
    unsigned int reserved_1 : 1;
    unsigned int IR0 : 1;
    unsigned int DR : 1;
    unsigned int reserved_4 : 1;
    unsigned int IR1 : 1;
    unsigned int UR : 1;
    unsigned int PAR : 1;
    unsigned int TCR : 1;
    unsigned int TCTR : 7;
    unsigned int reserved_16 : 16;
} Ifx_SCU_WDTS_CON1_Bits;
typedef struct _Ifx_SCU_WDTS_SR_Bits
{
    unsigned int AE : 1;
    unsigned int OE : 1;
    unsigned int IS0 : 1;
    unsigned int DS : 1;
    unsigned int TO : 1;
    unsigned int IS1 : 1;
    unsigned int US : 1;
    unsigned int PAS : 1;
    unsigned int TCS : 1;
    unsigned int TCT : 7;
    unsigned int TIM : 16;
} Ifx_SCU_WDTS_SR_Bits;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_ACCEN0_Bits B;
} Ifx_SCU_ACCEN0;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_ACCEN1_Bits B;
} Ifx_SCU_ACCEN1;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_ARSTDIS_Bits B;
} Ifx_SCU_ARSTDIS;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_CCUCON0_Bits B;
} Ifx_SCU_CCUCON0;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_CCUCON1_Bits B;
} Ifx_SCU_CCUCON1;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_CCUCON2_Bits B;
} Ifx_SCU_CCUCON2;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_CCUCON3_Bits B;
} Ifx_SCU_CCUCON3;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_CCUCON4_Bits B;
} Ifx_SCU_CCUCON4;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_CCUCON5_Bits B;
} Ifx_SCU_CCUCON5;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_CCUCON6_Bits B;
} Ifx_SCU_CCUCON6;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_CHIPID_Bits B;
} Ifx_SCU_CHIPID;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_DTSCON_Bits B;
} Ifx_SCU_DTSCON;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_DTSLIM_Bits B;
} Ifx_SCU_DTSLIM;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_DTSSTAT_Bits B;
} Ifx_SCU_DTSSTAT;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_EICR_Bits B;
} Ifx_SCU_EICR;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_EIFR_Bits B;
} Ifx_SCU_EIFR;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_EMSR_Bits B;
} Ifx_SCU_EMSR;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_ESRCFG_Bits B;
} Ifx_SCU_ESRCFG;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_ESROCFG_Bits B;
} Ifx_SCU_ESROCFG;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_EVR13CON_Bits B;
} Ifx_SCU_EVR13CON;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_EVRADCSTAT_Bits B;
} Ifx_SCU_EVRADCSTAT;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_EVRMONCTRL_Bits B;
} Ifx_SCU_EVRMONCTRL;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_EVROVMON_Bits B;
} Ifx_SCU_EVROVMON;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_EVRRSTCON_Bits B;
} Ifx_SCU_EVRRSTCON;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_EVRSDCOEFF2_Bits B;
} Ifx_SCU_EVRSDCOEFF2;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_EVRSDCTRL1_Bits B;
} Ifx_SCU_EVRSDCTRL1;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_EVRSDCTRL2_Bits B;
} Ifx_SCU_EVRSDCTRL2;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_EVRSDCTRL3_Bits B;
} Ifx_SCU_EVRSDCTRL3;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_EVRSTAT_Bits B;
} Ifx_SCU_EVRSTAT;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_EVRUVMON_Bits B;
} Ifx_SCU_EVRUVMON;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_EXTCON_Bits B;
} Ifx_SCU_EXTCON;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_FDR_Bits B;
} Ifx_SCU_FDR;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_FMR_Bits B;
} Ifx_SCU_FMR;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_ID_Bits B;
} Ifx_SCU_ID;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_IGCR_Bits B;
} Ifx_SCU_IGCR;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_IN_Bits B;
} Ifx_SCU_IN;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_IOCR_Bits B;
} Ifx_SCU_IOCR;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_LBISTCTRL0_Bits B;
} Ifx_SCU_LBISTCTRL0;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_LBISTCTRL1_Bits B;
} Ifx_SCU_LBISTCTRL1;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_LBISTCTRL2_Bits B;
} Ifx_SCU_LBISTCTRL2;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_LCLCON0_Bits B;
} Ifx_SCU_LCLCON0;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_LCLTEST_Bits B;
} Ifx_SCU_LCLTEST;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_MANID_Bits B;
} Ifx_SCU_MANID;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_OMR_Bits B;
} Ifx_SCU_OMR;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_OSCCON_Bits B;
} Ifx_SCU_OSCCON;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_OUT_Bits B;
} Ifx_SCU_OUT;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_OVCCON_Bits B;
} Ifx_SCU_OVCCON;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_OVCENABLE_Bits B;
} Ifx_SCU_OVCENABLE;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_PDISC_Bits B;
} Ifx_SCU_PDISC;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_PDR_Bits B;
} Ifx_SCU_PDR;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_PDRR_Bits B;
} Ifx_SCU_PDRR;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_PLLCON0_Bits B;
} Ifx_SCU_PLLCON0;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_PLLCON1_Bits B;
} Ifx_SCU_PLLCON1;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_PLLCON2_Bits B;
} Ifx_SCU_PLLCON2;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_PLLERAYCON0_Bits B;
} Ifx_SCU_PLLERAYCON0;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_PLLERAYCON1_Bits B;
} Ifx_SCU_PLLERAYCON1;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_PLLERAYSTAT_Bits B;
} Ifx_SCU_PLLERAYSTAT;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_PLLSTAT_Bits B;
} Ifx_SCU_PLLSTAT;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_PMCSR_Bits B;
} Ifx_SCU_PMCSR;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_PMSWCR0_Bits B;
} Ifx_SCU_PMSWCR0;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_PMSWCR1_Bits B;
} Ifx_SCU_PMSWCR1;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_PMSWCR3_Bits B;
} Ifx_SCU_PMSWCR3;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_PMSWSTAT_Bits B;
} Ifx_SCU_PMSWSTAT;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_PMSWSTATCLR_Bits B;
} Ifx_SCU_PMSWSTATCLR;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_PMSWUTCNT_Bits B;
} Ifx_SCU_PMSWUTCNT;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_RSTCON_Bits B;
} Ifx_SCU_RSTCON;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_RSTCON2_Bits B;
} Ifx_SCU_RSTCON2;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_RSTSTAT_Bits B;
} Ifx_SCU_RSTSTAT;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_SAFECON_Bits B;
} Ifx_SCU_SAFECON;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_STSTAT_Bits B;
} Ifx_SCU_STSTAT;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_SWRSTCON_Bits B;
} Ifx_SCU_SWRSTCON;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_SYSCON_Bits B;
} Ifx_SCU_SYSCON;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_TRAPCLR_Bits B;
} Ifx_SCU_TRAPCLR;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_TRAPDIS_Bits B;
} Ifx_SCU_TRAPDIS;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_TRAPSET_Bits B;
} Ifx_SCU_TRAPSET;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_TRAPSTAT_Bits B;
} Ifx_SCU_TRAPSTAT;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_WDTCPU_CON0_Bits B;
} Ifx_SCU_WDTCPU_CON0;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_WDTCPU_CON1_Bits B;
} Ifx_SCU_WDTCPU_CON1;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_WDTCPU_SR_Bits B;
} Ifx_SCU_WDTCPU_SR;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_WDTS_CON0_Bits B;
} Ifx_SCU_WDTS_CON0;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_WDTS_CON1_Bits B;
} Ifx_SCU_WDTS_CON1;
typedef union
{
    unsigned int U;
    signed int I;
    Ifx_SCU_WDTS_SR_Bits B;
} Ifx_SCU_WDTS_SR;
typedef struct _Ifx_SCU_WDTCPU
{
    Ifx_SCU_WDTCPU_CON0 CON0;
    Ifx_SCU_WDTCPU_CON1 CON1;
    Ifx_SCU_WDTCPU_SR SR;
} Ifx_SCU_WDTCPU;
typedef struct _Ifx_SCU_WDTS
{
    Ifx_SCU_WDTS_CON0 CON0;
    Ifx_SCU_WDTS_CON1 CON1;
    Ifx_SCU_WDTS_SR SR;
} Ifx_SCU_WDTS;
typedef struct _Ifx_SCU
{
    unsigned char reserved_0[8];
    Ifx_SCU_ID ID;
    unsigned char reserved_C[4];
    Ifx_SCU_OSCCON OSCCON;
    Ifx_SCU_PLLSTAT PLLSTAT;
    Ifx_SCU_PLLCON0 PLLCON0;
    Ifx_SCU_PLLCON1 PLLCON1;
    Ifx_SCU_PLLCON2 PLLCON2;
    Ifx_SCU_PLLERAYSTAT PLLERAYSTAT;
    Ifx_SCU_PLLERAYCON0 PLLERAYCON0;
    Ifx_SCU_PLLERAYCON1 PLLERAYCON1;
    Ifx_SCU_CCUCON0 CCUCON0;
    Ifx_SCU_CCUCON1 CCUCON1;
    Ifx_SCU_FDR FDR;
    Ifx_SCU_EXTCON EXTCON;
    Ifx_SCU_CCUCON2 CCUCON2;
    Ifx_SCU_CCUCON3 CCUCON3;
    Ifx_SCU_CCUCON4 CCUCON4;
    Ifx_SCU_CCUCON5 CCUCON5;
    Ifx_SCU_RSTSTAT RSTSTAT;
    unsigned char reserved_54[4];
    Ifx_SCU_RSTCON RSTCON;
    Ifx_SCU_ARSTDIS ARSTDIS;
    Ifx_SCU_SWRSTCON SWRSTCON;
    Ifx_SCU_RSTCON2 RSTCON2;
    unsigned char reserved_68[4];
    Ifx_SCU_EVRRSTCON EVRRSTCON;
    Ifx_SCU_ESRCFG ESRCFG[2];
    Ifx_SCU_ESROCFG ESROCFG;
    Ifx_SCU_SYSCON SYSCON;
    Ifx_SCU_CCUCON6 CCUCON6;
    unsigned char reserved_84[24];
    Ifx_SCU_PDR PDR;
    Ifx_SCU_IOCR IOCR;
    Ifx_SCU_OUT OUT;
    Ifx_SCU_OMR OMR;
    Ifx_SCU_IN IN;
    Ifx_SCU_EVRSTAT EVRSTAT;
    unsigned char reserved_B4[4];
    Ifx_SCU_EVR13CON EVR13CON;
    unsigned char reserved_BC[4];
    Ifx_SCU_STSTAT STSTAT;
    unsigned char reserved_C4[4];
    Ifx_SCU_PMSWCR0 PMSWCR0;
    Ifx_SCU_PMSWSTAT PMSWSTAT;
    Ifx_SCU_PMSWSTATCLR PMSWSTATCLR;
    Ifx_SCU_PMCSR PMCSR[1];
    unsigned char reserved_D8[8];
    Ifx_SCU_DTSSTAT DTSSTAT;
    Ifx_SCU_DTSCON DTSCON;
    Ifx_SCU_PMSWCR1 PMSWCR1;
    unsigned char reserved_EC[4];
    Ifx_SCU_WDTS WDTS;
    Ifx_SCU_EMSR EMSR;
    Ifx_SCU_WDTCPU WDTCPU[1];
    unsigned char reserved_10C[24];
    Ifx_SCU_TRAPSTAT TRAPSTAT;
    Ifx_SCU_TRAPSET TRAPSET;
    Ifx_SCU_TRAPCLR TRAPCLR;
    Ifx_SCU_TRAPDIS TRAPDIS;
    Ifx_SCU_LCLCON0 LCLCON0;
    unsigned char reserved_138[4];
    Ifx_SCU_LCLTEST LCLTEST;
    Ifx_SCU_CHIPID CHIPID;
    Ifx_SCU_MANID MANID;
    unsigned char reserved_148[8];
    Ifx_SCU_SAFECON SAFECON;
    unsigned char reserved_154[16];
    Ifx_SCU_LBISTCTRL0 LBISTCTRL0;
    Ifx_SCU_LBISTCTRL1 LBISTCTRL1;
    Ifx_SCU_LBISTCTRL2 LBISTCTRL2;
    unsigned char reserved_170[28];
    Ifx_SCU_PDISC PDISC;
    unsigned char reserved_190[12];
    Ifx_SCU_EVRADCSTAT EVRADCSTAT;
    Ifx_SCU_EVRUVMON EVRUVMON;
    Ifx_SCU_EVROVMON EVROVMON;
    Ifx_SCU_EVRMONCTRL EVRMONCTRL;
    unsigned char reserved_1AC[4];
    Ifx_SCU_EVRSDCTRL1 EVRSDCTRL1;
    Ifx_SCU_EVRSDCTRL2 EVRSDCTRL2;
    Ifx_SCU_EVRSDCTRL3 EVRSDCTRL3;
    unsigned char reserved_1BC[8];
    Ifx_SCU_EVRSDCOEFF2 EVRSDCOEFF2;
    unsigned char reserved_1C8[20];
    Ifx_SCU_PMSWUTCNT PMSWUTCNT;
    Ifx_SCU_OVCENABLE OVCENABLE;
    Ifx_SCU_OVCCON OVCCON;
    unsigned char reserved_1E8[40];
    Ifx_SCU_EICR EICR[4];
    Ifx_SCU_EIFR EIFR;
    Ifx_SCU_FMR FMR;
    Ifx_SCU_PDRR PDRR;
    Ifx_SCU_IGCR IGCR[4];
    unsigned char reserved_23C[4];
    Ifx_SCU_DTSLIM DTSLIM;
    unsigned char reserved_244[188];
    Ifx_SCU_PMSWCR3 PMSWCR3;
    unsigned char reserved_304[244];
    Ifx_SCU_ACCEN1 ACCEN1;
    Ifx_SCU_ACCEN0 ACCEN0;
} Ifx_SCU;
typedef float FLOAT;
enum boolean { v_false, v_true };
enum soups { NO_SOUP, ONION, CHOWDER };
enum salads { NO_SALAD, CAESAR, GREEN };
enum entrees { NO_ENTREE, STEAK, CHICKEN, LOBSTER, PASTA };
enum desserts { NO_DESSERT, CAKE, PIE, FRUIT };
enum beverages { NO_BEVERAGE, WINE, BEER, MIXED_DRINK, SODA };
struct order_type
{
  enum soups Soup;
  enum salads Salad;
  enum entrees Entree;
  enum desserts Dessert;
  enum beverages Beverage;
};
typedef unsigned short seat_index_type;
typedef unsigned short table_index_type;
struct table_data_type
{
  enum boolean Is_Occupied;
  seat_index_type Number_In_Party;
  char Designator;
  char Wait_Person[10];
  struct order_type Order[4];
  FLOAT Check_Total;
};
typedef char name_type[32];
/*vcast_header_expansion_end*/
struct table_data_type Get_Table_Record(table_index_type Table);
void Update_Table_Record(table_index_type Table, struct table_data_type Data);
/* Allow 10 Parties to wait */
static name_type WaitingList[10];
static unsigned int WaitingListSize = 0;
static unsigned int WaitingListIndex = 0;
int Add(int a, int b)
{  struct vcast_mcdc_statement vcast_mcdc_statement = {0, 0};/*vcast_internal_start*/
extern int P_9_1_1
;
extern int P_9_1_2
;
extern int R_9_1;
extern unsigned char SBF_9_1;
if(SBF_9_1) {
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_9_1
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_9_1
  if ( vcast_is_in_driver ) {
    P_9_1_1 = a;
    P_9_1_2 = b;
    vCAST_COMMON_STUB_PROC_9( 9, 1, 3, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_9_1
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_9_1
  vCAST_USER_CODE_TIMER_START();
  return R_9_1;
}
/*vcast_internal_end*/
/*vcast_internal_start*/{/*vcast_internal_end*/
   int sum = (VCAST_OPTIMIZED_MCDC_CONDITION_INSTRUMENTATION_POINT_REALTIME_0(vcast_unit_optimized_mcdc_bytes_9_0, 9, 0, 1),(VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,0),0));
   VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,1);
sum = a + b;
   VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,2);
return sum;
/*vcast_internal_start*/}/*vcast_internal_end*/
}
/* This function will add a free dessert to specific orders based on the 
   entree, salad, and beverage choice */
void Add_Included_Dessert(struct order_type* Order)
{  struct vcast_mcdc_statement vcast_mcdc_statement = {0, 0};/*vcast_internal_start*/
extern struct order_type *P_9_2_1
;
extern unsigned char SBF_9_2;
if(SBF_9_2) {
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_9_2
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_9_2
  if ( vcast_is_in_driver ) {
    P_9_2_1 = Order;
    vCAST_COMMON_STUB_PROC_9( 9, 2, 2, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_9_2
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_9_2
  vCAST_USER_CODE_TIMER_START();
  return;
}
/*vcast_internal_end*/
/*vcast_internal_start*/{/*vcast_internal_end*/
  VCAST_OPTIMIZED_MCDC_CONDITION_INSTRUMENTATION_POINT_REALTIME_0(vcast_unit_optimized_mcdc_bytes_9_0, 9, 1, 1);
if(VCAST_OPTIMIZED_MCDC_CONDITION_INSTRUMENTATION_POINT_REALTIME(vcast_unit_optimized_mcdc_bytes_9_3, &vcast_mcdc_statement, 9, 0, 3, (VCAST_CONDITION_TYP)(VCAST_SAVE_MCDC_SUBCONDITION(&vcast_mcdc_statement, 1, (VCAST_CONDITION_TYP)(Order->Entree == STEAK))
 &&
     VCAST_SAVE_MCDC_SUBCONDITION(&vcast_mcdc_statement, 2, (VCAST_CONDITION_TYP)(Order->Salad == CAESAR))
 &&
     VCAST_SAVE_MCDC_SUBCONDITION(&vcast_mcdc_statement, 3, (VCAST_CONDITION_TYP)(Order->Beverage == MIXED_DRINK))
))) {
    VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,3);
Order->Dessert = PIE;
  } else {
if(VCAST_OPTIMIZED_MCDC_CONDITION_INSTRUMENTATION_POINT_REALTIME(vcast_unit_optimized_mcdc_bytes_9_3, &vcast_mcdc_statement, 9, 1, 3, (VCAST_CONDITION_TYP)(VCAST_SAVE_MCDC_SUBCONDITION(&vcast_mcdc_statement, 1, (VCAST_CONDITION_TYP)(Order->Entree == LOBSTER))
 &&
            VCAST_SAVE_MCDC_SUBCONDITION(&vcast_mcdc_statement, 2, (VCAST_CONDITION_TYP)(Order->Salad == GREEN))
 &&
            VCAST_SAVE_MCDC_SUBCONDITION(&vcast_mcdc_statement, 3, (VCAST_CONDITION_TYP)(Order->Beverage == WINE))
))) {
    VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,4);
Order->Dessert = CAKE;
  }}
/*vcast_internal_start*/}/*vcast_internal_end*/
}
int Place_Order(table_index_type Table,
                seat_index_type Seat,
                struct order_type Order)
{int vcast_switch_taken_1 = 0;
  struct vcast_mcdc_statement vcast_mcdc_statement = {0, 0};/*vcast_internal_start*/
extern unsigned short P_9_3_1
;
extern unsigned short P_9_3_2
;
extern struct order_type P_9_3_3
;
extern int R_9_3;
extern unsigned char SBF_9_3;
if(SBF_9_3) {
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_9_3
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_9_3
  if ( vcast_is_in_driver ) {
    P_9_3_1 = Table;
    P_9_3_2 = Seat;
    P_9_3_3 = Order;
    vCAST_COMMON_STUB_PROC_9( 9, 3, 4, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_9_3
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_9_3
  vCAST_USER_CODE_TIMER_START();
  return R_9_3;
}
/*vcast_internal_end*/
/*vcast_internal_start*/{/*vcast_internal_end*/
  struct table_data_type Table_Data;
  VCAST_OPTIMIZED_MCDC_CONDITION_INSTRUMENTATION_POINT_REALTIME_0(vcast_unit_optimized_mcdc_bytes_9_0, 9, 2, 1);
VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,5);
Table_Data = Get_Table_Record(Table);
  VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,6);
Table_Data.Is_Occupied = v_true;
  VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,7);
Table_Data.Number_In_Party = Table_Data.Number_In_Party + 1;
  VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,8);
Table_Data.Order[Seat] = Order;
  /* Add a free dessert in some cases */
  VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,9);
Add_Included_Dessert(&Table_Data.Order[Seat]);
  {
VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,10);
{vcast_switch_taken_1 = 0;
switch(Order.Entree)
    {
    case NO_ENTREE :VCAST_OPTIMIZED_MCDC_CONDITION_INSTRUMENTATION_POINT_REALTIME_0(vcast_unit_optimized_mcdc_bytes_9_0, 9, 3, 1);
vcast_switch_taken_1 = 1;
       VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,11);
break;
    case STEAK :if (!vcast_switch_taken_1) VCAST_OPTIMIZED_MCDC_CONDITION_INSTRUMENTATION_POINT_REALTIME_0(vcast_unit_optimized_mcdc_bytes_9_0, 9, 4, 1);
vcast_switch_taken_1 = 1;
       VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,12);
Table_Data.Check_Total = Table_Data.Check_Total + 14.0;
       VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,13);
break;
    case CHICKEN :if (!vcast_switch_taken_1) VCAST_OPTIMIZED_MCDC_CONDITION_INSTRUMENTATION_POINT_REALTIME_0(vcast_unit_optimized_mcdc_bytes_9_0, 9, 5, 1);
vcast_switch_taken_1 = 1;
       VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,14);
Table_Data.Check_Total = Table_Data.Check_Total + 10.0;
       VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,15);
break;
    case LOBSTER :if (!vcast_switch_taken_1) VCAST_OPTIMIZED_MCDC_CONDITION_INSTRUMENTATION_POINT_REALTIME_0(vcast_unit_optimized_mcdc_bytes_9_0, 9, 6, 1);
vcast_switch_taken_1 = 1;
       VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,16);
Table_Data.Check_Total = Table_Data.Check_Total + 18.0;
       VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,17);
break;
    case PASTA :if (!vcast_switch_taken_1) VCAST_OPTIMIZED_MCDC_CONDITION_INSTRUMENTATION_POINT_REALTIME_0(vcast_unit_optimized_mcdc_bytes_9_0, 9, 7, 1);
vcast_switch_taken_1 = 1;
       VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,18);
Table_Data.Check_Total = Table_Data.Check_Total + 12.0;
       VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,19);
break;
    }}
}
  VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,20);
Update_Table_Record(Table, Table_Data);
  VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,21);
return 0;
/*vcast_internal_start*/}/*vcast_internal_end*/
}
int Clear_Table(table_index_type Table)
{  struct vcast_mcdc_statement vcast_mcdc_statement = {0, 0};/*vcast_internal_start*/
extern unsigned short P_9_4_1
;
extern int R_9_4;
extern unsigned char SBF_9_4;
if(SBF_9_4) {
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_9_4
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_9_4
  if ( vcast_is_in_driver ) {
    P_9_4_1 = Table;
    vCAST_COMMON_STUB_PROC_9( 9, 4, 2, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_9_4
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_9_4
  vCAST_USER_CODE_TIMER_START();
  return R_9_4;
}
/*vcast_internal_end*/
/*vcast_internal_start*/{/*vcast_internal_end*/
  struct table_data_type Table_Data;
  seat_index_type Seat;
  VCAST_OPTIMIZED_MCDC_CONDITION_INSTRUMENTATION_POINT_REALTIME_0(vcast_unit_optimized_mcdc_bytes_9_0, 9, 8, 1);
VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,22);
Table_Data = Get_Table_Record(Table);
  VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,23);
Table_Data.Is_Occupied = v_false;
  VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,24);
Table_Data.Number_In_Party = 1;
  {
for (Seat=0; VCAST_OPTIMIZED_MCDC_CONDITION_INSTRUMENTATION_POINT_REALTIME_1(vcast_unit_optimized_mcdc_bytes_9_1, &vcast_mcdc_statement, 9, 0, (VCAST_CONDITION_TYP)(VCAST_SAVE_MCDC_SUBCONDITION(&vcast_mcdc_statement, 1, (VCAST_CONDITION_TYP)(Seat < 4))
)); Seat++){
      VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,25);
Table_Data.Order[Seat].Soup = NO_SOUP;
      VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,26);
Table_Data.Order[Seat].Salad = NO_SALAD;
      VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,27);
Table_Data.Order[Seat].Entree = NO_ENTREE;
      VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,28);
Table_Data.Order[Seat].Dessert = NO_DESSERT;
      VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,29);
Table_Data.Order[Seat].Beverage = NO_BEVERAGE;
   }}
  VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,30);
Table_Data.Check_Total = 0;
  VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,31);
Update_Table_Record(Table, Table_Data);
  VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,32);
return 0;
/*vcast_internal_start*/}/*vcast_internal_end*/
}
FLOAT Get_Check_Total(table_index_type Table)
{  struct vcast_mcdc_statement vcast_mcdc_statement = {0, 0};/*vcast_internal_start*/
extern unsigned short P_9_5_1
;
extern float R_9_5;
extern unsigned char SBF_9_5;
if(SBF_9_5) {
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_9_5
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_9_5
  if ( vcast_is_in_driver ) {
    P_9_5_1 = Table;
    vCAST_COMMON_STUB_PROC_9( 9, 5, 2, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_9_5
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_9_5
  vCAST_USER_CODE_TIMER_START();
  return R_9_5;
}
/*vcast_internal_end*/
/*vcast_internal_start*/{/*vcast_internal_end*/
  struct table_data_type Table_Data;
  VCAST_OPTIMIZED_MCDC_CONDITION_INSTRUMENTATION_POINT_REALTIME_0(vcast_unit_optimized_mcdc_bytes_9_0, 9, 9, 1);
VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,33);
Table_Data = Get_Table_Record(Table);
  VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,34);
return (Table_Data.Check_Total);
/*vcast_internal_start*/}/*vcast_internal_end*/
}
void Add_Party_To_Waiting_List(char* Name)
{  struct vcast_mcdc_statement vcast_mcdc_statement = {0, 0};/*vcast_internal_start*/
extern char *P_9_6_1
;
extern unsigned char SBF_9_6;
if(SBF_9_6) {
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_9_6
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_9_6
  if ( vcast_is_in_driver ) {
    P_9_6_1 = Name;
    vCAST_COMMON_STUB_PROC_9( 9, 6, 2, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_9_6
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_9_6
  vCAST_USER_CODE_TIMER_START();
  return;
}
/*vcast_internal_end*/
/*vcast_internal_start*/{/*vcast_internal_end*/
  int i = (VCAST_OPTIMIZED_MCDC_CONDITION_INSTRUMENTATION_POINT_REALTIME_0(vcast_unit_optimized_mcdc_bytes_9_0, 9, 10, 1),(VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,35),0));
  if(VCAST_OPTIMIZED_MCDC_CONDITION_INSTRUMENTATION_POINT_REALTIME_1(vcast_unit_optimized_mcdc_bytes_9_1, &vcast_mcdc_statement, 9, 1, (VCAST_CONDITION_TYP)(VCAST_SAVE_MCDC_SUBCONDITION(&vcast_mcdc_statement, 1, (VCAST_CONDITION_TYP)(WaitingListSize > 9))
)))
    {
VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,36);
WaitingListSize = 0;}
  {
while(VCAST_OPTIMIZED_MCDC_CONDITION_INSTRUMENTATION_POINT_REALTIME(vcast_unit_optimized_mcdc_bytes_9_2, &vcast_mcdc_statement, 9, 0, 2, (VCAST_CONDITION_TYP)(VCAST_SAVE_MCDC_SUBCONDITION(&vcast_mcdc_statement, 1, (VCAST_CONDITION_TYP)(!!(Name)))
 && VCAST_SAVE_MCDC_SUBCONDITION(&vcast_mcdc_statement, 2, (VCAST_CONDITION_TYP)(*Name))
))) {
    VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,37);
WaitingList[WaitingListSize][i++] = *Name;
    VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,38);
Name++;
  }}
  VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,39);
WaitingList[WaitingListSize++][i] = 0;
/*vcast_internal_start*/}/*vcast_internal_end*/
}
char* Get_Next_Party_To_Be_Seated(void)
{  struct vcast_mcdc_statement vcast_mcdc_statement = {0, 0};/*vcast_internal_start*/
extern char *R_9_7;
extern unsigned char SBF_9_7;
if(SBF_9_7) {
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_9_7
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_9_7
  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 9, 7, 1, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_9_7
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_9_7
  vCAST_USER_CODE_TIMER_START();
  return R_9_7;
}
/*vcast_internal_end*/
/*vcast_internal_start*/{/*vcast_internal_end*/
  VCAST_OPTIMIZED_MCDC_CONDITION_INSTRUMENTATION_POINT_REALTIME_0(vcast_unit_optimized_mcdc_bytes_9_0, 9, 11, 1);
if(VCAST_OPTIMIZED_MCDC_CONDITION_INSTRUMENTATION_POINT_REALTIME_1(vcast_unit_optimized_mcdc_bytes_9_1, &vcast_mcdc_statement, 9, 2, (VCAST_CONDITION_TYP)(VCAST_SAVE_MCDC_SUBCONDITION(&vcast_mcdc_statement, 1, (VCAST_CONDITION_TYP)(WaitingListIndex > 9))
)))
    {
VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,40);
WaitingListIndex = 0;}
  VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(vcast_unit_stmt_bytes_9,9,41);
return WaitingList[WaitingListIndex++];
/*vcast_internal_start*/}/*vcast_internal_end*/
}
/*vcast_internal_start*/int P_9_1_1
;
int P_9_1_2
;
int R_9_1;
unsigned char SBF_9_1 = 0;
/*vcast_internal_end*/
/*vcast_internal_start*/struct order_type *P_9_2_1
;
unsigned char SBF_9_2 = 0;
/*vcast_internal_end*/
/*vcast_internal_start*/unsigned short P_9_3_1
;
unsigned short P_9_3_2
;
struct order_type P_9_3_3
;
int R_9_3;
unsigned char SBF_9_3 = 0;
/*vcast_internal_end*/
/*vcast_internal_start*/unsigned short P_9_4_1
;
int R_9_4;
unsigned char SBF_9_4 = 0;
/*vcast_internal_end*/
/*vcast_internal_start*/unsigned short P_9_5_1
;
float R_9_5;
unsigned char SBF_9_5 = 0;
/*vcast_internal_end*/
/*vcast_internal_start*/char *P_9_6_1
;
unsigned char SBF_9_6 = 0;
/*vcast_internal_end*/
/*vcast_internal_start*/char *R_9_7;
unsigned char SBF_9_7 = 0;
/*vcast_internal_end*/

