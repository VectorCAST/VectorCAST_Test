/***********************************************
 *      VectorCAST Test Harness Component      *
 *     Copyright 2018 Vector Informatik, GmbH.    *
 *              18.sp2 (07/02/18)              *
 ***********************************************/
#ifndef S3_SWITCH_H
#define S3_SWITCH_H   

void vcast_S3_switch( int, int, char *, char * );

#ifdef VCAST_SBF_UNITS_AVAILABLE
void vcast_initialize_sbf_flag( int, int );
#endif /* VCAST_SBF_UNITS_AVAILABLE */

#endif /* S3_SWITCH_H */
