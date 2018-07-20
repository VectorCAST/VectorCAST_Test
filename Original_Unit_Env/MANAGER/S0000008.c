
/*****************************************************************************
S0000008.c: This file contains the definitions of variables used in user code.
Preface all variable declarations with VCAST_USER_GLOBALS_EXTERN to ensure 
that only one definition of the variable is created in the test harness. 
*****************************************************************************/

#ifndef VCAST_USER_GLOBALS_EXTERN
#define VCAST_USER_GLOBALS_EXTERN
#endif

#ifdef __cplusplus
extern "C"{
#endif
  VCAST_USER_GLOBALS_EXTERN int VECTORCAST_INT1;
  VCAST_USER_GLOBALS_EXTERN int VECTORCAST_INT2;
  VCAST_USER_GLOBALS_EXTERN int VECTORCAST_INT3;
#ifndef VCAST_NO_FLOAT 
  VCAST_USER_GLOBALS_EXTERN float VECTORCAST_FLT1;
#endif   
  VCAST_USER_GLOBALS_EXTERN char VECTORCAST_STR1[8];

  VCAST_USER_GLOBALS_EXTERN int  VECTORCAST_BUFFER[4];
#ifdef __cplusplus
}
#endif
