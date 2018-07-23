#ifndef __VCAST_C_OPTIONS_H__
#define __VCAST_C_OPTIONS_H__
#ifndef VCAST_MAX_COVERED_SUBPROGRAMS
#define VCAST_MAX_COVERED_SUBPROGRAMS 1000
#endif
#ifndef VCAST_MAX_MCDC_STATEMENTS
#define VCAST_MAX_MCDC_STATEMENTS  1000
#endif
#define VCAST_COVERAGE_IO_REAL_TIME
#ifndef VCAST_NUMBER_SUBPROGRAM_STRUCTS
#define VCAST_NUMBER_SUBPROGRAM_STRUCTS  1
#endif
#ifndef VCAST_NUMBER_BINARY_BYTES
#define VCAST_NUMBER_BINARY_BYTES  1
#endif
#ifndef VCAST_NUMBER_AVLTREE_POINTERS
#define VCAST_NUMBER_AVLTREE_POINTERS  1
#endif
#ifndef VCAST_NUMBER_STATEMENT_STRUCTS
#define VCAST_NUMBER_STATEMENT_STRUCTS  0
#endif
#ifndef VCAST_NUMBER_BRANCH_STRUCTS
#define VCAST_NUMBER_BRANCH_STRUCTS  0
#endif
#ifndef VCAST_NUMBER_MCDC_STRUCTS
#define VCAST_NUMBER_MCDC_STRUCTS  2
#endif
#ifndef VCAST_PROBE_POINTS_AVAILABLE
#define VCAST_PROBE_POINTS_AVAILABLE 1
#endif
#ifndef VCAST_NUMBER_STATEMENT_MCDC_STRUCTS
#define VCAST_NUMBER_STATEMENT_MCDC_STRUCTS 0
#endif
#ifndef VCAST_NUMBER_STATEMENT_BRANCH_STRUCTS
#define VCAST_NUMBER_STATEMENT_BRANCH_STRUCTS 0
#endif
#ifndef VCAST_HAS_LONGLONG
#define VCAST_HAS_LONGLONG
#endif
#define VCAST_COVERAGE_TYPE_STATEMENT_MCDC
#ifndef VCAST_USE_OPTIMIZED_MCDC_INSTRUMENTATION
#define VCAST_USE_OPTIMIZED_MCDC_INSTRUMENTATION
#endif
#ifndef VCAST_OPTIMIZED_MCDC_STORAGE_THRESHOLD
#define VCAST_OPTIMIZED_MCDC_STORAGE_THRESHOLD  8
#endif

#ifndef VCAST_PACK_INSTRUMENTATION_STORAGE
#define VCAST_PACK_INSTRUMENTATION_STORAGE
#endif
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
 *   statement bit array:.................size: 1          count: 1      bytes:  1
 *   mcdc avltree array:..................size: 2          bytes:  0 *
 *   mcdc bit array 0:....................size (bits): 2   count: 2      bytes:  1
 *   mcdc bit array 1:....................size (bits): 4   bytes:  1 *
 *   mcdc bit array 2:....................size (bits): 12  bytes:  1 *
 *   mcdc bit array 3:....................size (bits): 32  bytes:  1 *
 *   mcdc bit array 4:....................size (bits): 80  bytes:  1 *
 *   mcdc bit array 5:....................size (bits): 192 bytes:  1 *
 *   mcdc bit array 6:....................size (bits): 448 bytes:  1 *
 *   mcdc bit array 7:....................size (bits): 1024 bytes:  1 *
 *   mcdc bit array 8:....................size (bits): 2304 bytes:  1 *
 *   Total (no MC/DC pool storage):......................................bytes:  10 *
 *   
 *   mcdc_statement_pool:.................size: 8          count: 1000   bytes:  8000
 *   avlnode_pool:........................size: 8          count: 1000   bytes:  8000
 *   Total (with user configurable MC/DC pool storage):..................bytes:  16010 *
 * 
 * For a 32 bit executable configuration:
 *   statement bit array:.................size: 1          count: 1      bytes:  1
 *   mcdc avltree array:..................size: 4          bytes:  0 *
 *   mcdc bit array 0:....................size (bits): 2   count: 2      bytes:  1
 *   mcdc bit array 1:....................size (bits): 4   bytes:  1 *
 *   mcdc bit array 2:....................size (bits): 12  bytes:  1 *
 *   mcdc bit array 3:....................size (bits): 32  bytes:  1 *
 *   mcdc bit array 4:....................size (bits): 80  bytes:  1 *
 *   mcdc bit array 5:....................size (bits): 192 bytes:  1 *
 *   mcdc bit array 6:....................size (bits): 448 bytes:  1 *
 *   mcdc bit array 7:....................size (bits): 1024 bytes:  1 *
 *   mcdc bit array 8:....................size (bits): 2304 bytes:  1 *
 *   Total (no MC/DC pool storage):......................................bytes:  10 *
 *   
 *   mcdc_statement_pool:.................size: 16         count: 1000   bytes:  16000
 *   avlnode_pool:........................size: 16         count: 1000   bytes:  16000
 *   Total (with user configurable MC/DC pool storage):..................bytes:  32010 *
 * 
 * For a 64 bit executable configuration:
 *   statement bit array:.................size: 1          count: 1      bytes:  1
 *   mcdc avltree array:..................size: 8          bytes:  0 *
 *   mcdc bit array 0:....................size (bits): 2   count: 2      bytes:  1
 *   mcdc bit array 1:....................size (bits): 4   bytes:  1 *
 *   mcdc bit array 2:....................size (bits): 12  bytes:  1 *
 *   mcdc bit array 3:....................size (bits): 32  bytes:  1 *
 *   mcdc bit array 4:....................size (bits): 80  bytes:  1 *
 *   mcdc bit array 5:....................size (bits): 192 bytes:  1 *
 *   mcdc bit array 6:....................size (bits): 448 bytes:  1 *
 *   mcdc bit array 7:....................size (bits): 1024 bytes:  1 *
 *   mcdc bit array 8:....................size (bits): 2304 bytes:  1 *
 *   Total (no MC/DC pool storage):......................................bytes:  10 *
 *   
 *   mcdc_statement_pool:.................size: 16         count: 1000   bytes:  16000
 *   avlnode_pool:........................size: 28         count: 1000   bytes:  28000
 *   Total (with user configurable MC/DC pool storage):..................bytes:  44010 *
 */
#ifndef VCAST_CONDITION_TYP
#define VCAST_CONDITION_TYP long long
#endif



#endif /* __VCAST_C_OPTIONS_H__ */
#ifdef VCAST_DEFINE_COVER_VARIABLES
#ifdef __cplusplus
extern "C" {
#endif
#define VCAST_OPTIMIZED_MCDC_BYTES_0_SIZE(statements) (statements / 4 + ((statements%4)?1:0))
#define VCAST_OPTIMIZED_MCDC_BYTES_1_SIZE(statements) (statements / 2 + statements % 2)
#define VCAST_OPTIMIZED_MCDC_BYTES_2_SIZE(statements) (statements*3/ 2 + statements*3 % 2)
#define VCAST_OPTIMIZED_MCDC_BYTES_3_SIZE(statements) (statements*4)
#define VCAST_OPTIMIZED_MCDC_BYTES_4_SIZE(statements) (statements*10)
#define VCAST_OPTIMIZED_MCDC_BYTES_5_SIZE(statements) (statements*24)
#define VCAST_OPTIMIZED_MCDC_BYTES_6_SIZE(statements) (statements*56)
#define VCAST_OPTIMIZED_MCDC_BYTES_7_SIZE(statements) (statements*128)
#define VCAST_OPTIMIZED_MCDC_BYTES_8_SIZE(statements) (statements*288)
char vcast_unit_stmt_bytes_9[1] = { 0 };
char vcast_unit_optimized_mcdc_bytes_9_0[1] = { 0 };
char vcast_unit_optimized_mcdc_bytes_9_1[1] = { 0 };
char vcast_unit_optimized_mcdc_bytes_9_2[1] = { 0 };
char vcast_unit_optimized_mcdc_bytes_9_3[1] = { 0 };
char vcast_unit_optimized_mcdc_bytes_9_4[1] = { 0 };
char vcast_unit_optimized_mcdc_bytes_9_5[1] = { 0 };
char vcast_unit_optimized_mcdc_bytes_9_6[1] = { 0 };
char vcast_unit_optimized_mcdc_bytes_9_7[1] = { 0 };
char vcast_unit_optimized_mcdc_bytes_9_8[1] = { 0 };

#ifdef VCAST_COVERAGE_IO_BUFFERED
struct vcast_unit_list {
  int vcast_unit;
  char *vcast_statement_array;
  int vcast_statement_bytes;
  char *vcast_optimized_mcdc_array_0;
  int vcast_optimized_mcdc_bytes_0;
  char *vcast_optimized_mcdc_array_1;
  int vcast_optimized_mcdc_bytes_1;
  char *vcast_optimized_mcdc_array_2;
  int vcast_optimized_mcdc_bytes_2;
  char *vcast_optimized_mcdc_array_3;
  int vcast_optimized_mcdc_bytes_3;
  char *vcast_optimized_mcdc_array_4;
  int vcast_optimized_mcdc_bytes_4;
  char *vcast_optimized_mcdc_array_5;
  int vcast_optimized_mcdc_bytes_5;
  char *vcast_optimized_mcdc_array_6;
  int vcast_optimized_mcdc_bytes_6;
  char *vcast_optimized_mcdc_array_7;
  int vcast_optimized_mcdc_bytes_7;
  char *vcast_optimized_mcdc_array_8;
  int vcast_optimized_mcdc_bytes_8;
};

#ifndef VCAST_UNIT_LIST_VALUES_ATTR
#define VCAST_UNIT_LIST_VALUES_ATTR
#endif

VCAST_UNIT_LIST_VALUES_ATTR
static const struct vcast_unit_list vcast_unit_list_values[] = {
  {9, (char *)vcast_unit_stmt_bytes_9, 1, (char *)vcast_unit_optimized_mcdc_bytes_9_0, 2, (char *)0, 0, (char *)0, 0, (char *)0, 0, (char *)0, 0, (char *)0, 0, (char *)0, 0, (char *)0, 0, (char *)0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

#endif
#ifdef __cplusplus
}
#endif
#endif
