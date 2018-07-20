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
#ifndef VCAST_DRIVER_ONLY
/* Include the file which contains function prototypes
for stub processing and value/expected user code */
#include "vcast_uc_prototypes.h"
#include "vcast_basics.h"
/* STUB_DEPENDENCY_USER_CODE */
/* STUB_DEPENDENCY_USER_CODE_END */
#else
#include "vcast_env_defines.h"
#define __VCAST_BASICS_H__
#endif /* VCAST_DRIVER_ONLY */
#ifndef VCAST_DRIVER_ONLY
#ifndef VCAST_DONT_RENAME_EXIT
#ifdef __cplusplus
extern "C" {
#endif
void exit (int status);
#ifdef __cplusplus
}
#endif
/* used to capture the exit call */
#define exit VCAST_exit
#endif /* VCAST_DONT_RENAME_EXIT */
#endif /* VCAST_DRIVER_ONLY */
#ifndef VCAST_DRIVER_ONLY
#define VCAST_HEADER_EXPANSION
#ifdef VCAST_COVERAGE
#include "database_inst_prefix.c"
#else
#include "database_vcast_prefix.c"
#endif
#ifdef VCAST_COVERAGE
/* If coverage is enabled, include the instrumented UUT */
#include "database_inst.c"
#else
/* If coverage is not enabled, include the original UUT */
#include "database_vcast.c"
#endif
#ifdef VCAST_COVERAGE
#include "database_inst_appendix.c"
#else
#include "database_vcast_appendix.c"
#endif
#endif /* VCAST_DRIVER_ONLY */
#include "database_driver_prefix.c"
#ifdef VCAST_HEADER_EXPANSION
#ifdef VCAST_COVERAGE
#include "database_exp_inst_driver.c"
#else
#include "database_expanded_driver.c"
#endif /*VCAST_COVERAGE*/
#else
#include "S0000009.h"
#include "vcast_undef_9.h"
/* Include the file which contains function prototypes
for stub processing and value/expected user code */
#include "vcast_uc_prototypes.h"
#include "vcast_stubs_9.c"
/* begin declarations of inlined friends */
/* end declarations of inlined friends */
void VCAST_DRIVER_9( int VC_SUBPROGRAM, char *VC_EVENT_FLAGS, char *VC_SLOT_DESCR ) {
#ifdef VCAST_SBF_UNITS_AVAILABLE
  vCAST_MODIFY_SBF_TABLE(9, VC_SUBPROGRAM, vCAST_false);
#endif
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
#include "vcast_ti_decls_9.h"
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
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_1 ( struct table_data_type vcast_param[6] ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_1 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
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
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* An integer */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_5 ( unsigned short *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_5 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
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
    *vcast_param = ( unsigned short  ) vCAST_VALUE_INT;
    break;
  case vCAST_FIRST_VAL :
    *vcast_param = USHRT_MIN;
    break;
  case vCAST_MID_VAL :
    *vcast_param = (USHRT_MIN / 2) + (USHRT_MAX / 2);
    break;
  case vCAST_LAST_VAL :
    *vcast_param = USHRT_MAX;
    break;
  case vCAST_MIN_MINUS_1_VAL :
    *vcast_param = USHRT_MIN;
    *vcast_param = *vcast_param - 1;
    break;
  case vCAST_MAX_PLUS_1_VAL :
    *vcast_param = USHRT_MAX;
    *vcast_param = *vcast_param + 1;
    break;
  case vCAST_ZERO_VAL :
    *vcast_param = 0;
    break;
  default:
    break;
} /* end switch */
} /* end VCAST_TI_9_5 */
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A struct */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_2 ( struct table_data_type *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_2 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
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
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* An enumeration */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_6 ( enum boolean *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_6 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_6 ( enum boolean *vcast_param ) 
{
  switch ( vCAST_COMMAND ) {
    case vCAST_PRINT: {
      if ( vcast_param == 0 )
        vectorcast_fprint_string (vCAST_OUTPUT_FILE,"null\n");
      else {
        vectorcast_fprint_long_long(vCAST_OUTPUT_FILE, (VCAST_LONGEST_INT)*vcast_param);
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
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* An array */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_13 ( char vcast_param[10] ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_13 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
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
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* An array */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_14 ( struct order_type vcast_param[4] ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_14 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
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
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* A struct */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_12 ( struct order_type *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_12 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
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
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* An enumeration */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_7 ( enum soups *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_7 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_7 ( enum soups *vcast_param ) 
{
  switch ( vCAST_COMMAND ) {
    case vCAST_PRINT: {
      if ( vcast_param == 0 )
        vectorcast_fprint_string (vCAST_OUTPUT_FILE,"null\n");
      else {
        vectorcast_fprint_long_long(vCAST_OUTPUT_FILE, (VCAST_LONGEST_INT)*vcast_param);
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
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* An enumeration */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_8 ( enum salads *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_8 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_8 ( enum salads *vcast_param ) 
{
  switch ( vCAST_COMMAND ) {
    case vCAST_PRINT: {
      if ( vcast_param == 0 )
        vectorcast_fprint_string (vCAST_OUTPUT_FILE,"null\n");
      else {
        vectorcast_fprint_long_long(vCAST_OUTPUT_FILE, (VCAST_LONGEST_INT)*vcast_param);
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
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* An enumeration */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_9 ( enum entrees *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_9 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_9 ( enum entrees *vcast_param ) 
{
  switch ( vCAST_COMMAND ) {
    case vCAST_PRINT: {
      if ( vcast_param == 0 )
        vectorcast_fprint_string (vCAST_OUTPUT_FILE,"null\n");
      else {
        vectorcast_fprint_long_long(vCAST_OUTPUT_FILE, (VCAST_LONGEST_INT)*vcast_param);
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
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* An enumeration */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_10 ( enum desserts *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_10 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_10 ( enum desserts *vcast_param ) 
{
  switch ( vCAST_COMMAND ) {
    case vCAST_PRINT: {
      if ( vcast_param == 0 )
        vectorcast_fprint_string (vCAST_OUTPUT_FILE,"null\n");
      else {
        vectorcast_fprint_long_long(vCAST_OUTPUT_FILE, (VCAST_LONGEST_INT)*vcast_param);
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
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


/* An enumeration */
#if (defined(VCAST_NO_TYPE_SUPPORT))
void VCAST_TI_9_11 ( enum beverages *vcast_param ) 
{
  /* User code: type is not supported */
  vcast_not_supported();
} /* end VCAST_TI_9_11 */
#else /*(defined(VCAST_NO_TYPE_SUPPORT))*/
void VCAST_TI_9_11 ( enum beverages *vcast_param ) 
{
  switch ( vCAST_COMMAND ) {
    case vCAST_PRINT: {
      if ( vcast_param == 0 )
        vectorcast_fprint_string (vCAST_OUTPUT_FILE,"null\n");
      else {
        vectorcast_fprint_long_long(vCAST_OUTPUT_FILE, (VCAST_LONGEST_INT)*vcast_param);
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
#endif /*(defined(VCAST_NO_TYPE_SUPPORT))*/


#ifdef VCAST_PARADIGM_ADD_SEGMENT
#pragma new_codesegment(1)
#endif
void VCAST_TI_RANGE_DATA_9 ( void ) {
#define VCAST_TI_SCALAR_TYPE "NEW_SCALAR\n"
#define VCAST_TI_ARRAY_TYPE  "NEW_ARRAY\n"
  /* Range Data for TI (array) VCAST_TI_9_1 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_ARRAY_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100003\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,6);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (scalar) VCAST_TI_8_1 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_SCALAR_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"900002\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,CHAR_MIN );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,(CHAR_MIN/2) + (CHAR_MAX/2) );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,CHAR_MAX );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
#ifndef VCAST_NO_FLOAT
  /* Range Data for TI (scalar) VCAST_TI_8_3 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_SCALAR_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"900004\n" );
  vectorcast_fprint_long_float (vCAST_OUTPUT_FILE,-(FLT_MAX) );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_long_float (vCAST_OUTPUT_FILE,VCAST_FLT_MID );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_long_float (vCAST_OUTPUT_FILE,FLT_MAX );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
#endif
  /* Range Data for TI (scalar) VCAST_TI_9_5 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_SCALAR_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"900005\n" );
  vectorcast_fprint_unsigned_short (vCAST_OUTPUT_FILE,USHRT_MIN );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_unsigned_short (vCAST_OUTPUT_FILE,(USHRT_MIN / 2) + (USHRT_MAX / 2) );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  vectorcast_fprint_unsigned_short (vCAST_OUTPUT_FILE,USHRT_MAX );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"\n" );
  /* Range Data for TI (array) VCAST_TI_9_13 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_ARRAY_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100004\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,10);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
  /* Range Data for TI (array) VCAST_TI_9_14 */
  vectorcast_fprint_string (vCAST_OUTPUT_FILE, VCAST_TI_ARRAY_TYPE );
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"100005\n" );
  vectorcast_fprint_integer (vCAST_OUTPUT_FILE,4);
  vectorcast_fprint_string (vCAST_OUTPUT_FILE,"%%\n");
}
/* Include the file which contains function implementations
for stub processing and value/expected user code */
#include "database_uc.c"

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
#endif /* VCAST_HEADER_EXPANSION */
