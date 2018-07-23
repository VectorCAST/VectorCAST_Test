/***********************************************
 *      VectorCAST Test Harness Component      *
 *     Copyright 2018 Vector Informatik, GmbH.    *
 *              18.sp2 (07/02/18)              *
 ***********************************************/
#include "S0000002.h"
#include "S0000007.h"
#include "B4_switch.h"

#ifdef VCAST_CPP_ENVIRONMENT
vCAST_boolean vcast_initializing;
vCAST_boolean vcast_commands_read;
#endif

      /* BEGIN USER_CODE_DEPENDENCIES_9 */
      
      /* DONE USER_CODE_DEPENDENCIES_9 */
      /* BEGIN USER_CODE_OBJECTS_9 */
      
      /* DONE USER_CODE_OBJECTS_9 */

void vCAST_INITIALIZE_PARAMETERS(void) {
  } /* INITIALIZE_PARAMETERS */

void vCAST_USER_CODE_INITIALIZE (int vcast_slot_index, vCAST_boolean commands_read)
   {
      /* BEGIN USER_CODE_INITIALIZE_9 */
      
      /* DONE USER_CODE_INITIALIZE_9 */
#if defined(VCAST_CPP_ENVIRONMENT)
     vcast_commands_read = commands_read;
#endif
     vCAST_USER_CODE( VCAST_UCT_VALUE, vcast_slot_index );

   } /* end vCAST_USER_CODE_INITIALIZE */

#ifdef VCAST_ENABLE_TIMER_USER_CODE
void vCAST_USER_CODE_TIMER_START (void)
{
      /* BEGIN USER_CODE_TIMER_START_9 */
      
      /* DONE USER_CODE_TIMER_START_9 */

}

void vCAST_USER_CODE_TIMER_STOP (void)
{
      /* BEGIN USER_CODE_TIMER_STOP_9 */
      
      /* DONE USER_CODE_TIMER_STOP_9 */
}
#endif

void vCAST_USER_CODE_CAPTURE (void)
   {

   /*
   This procedure should be used as defined
   in the CCAST User Guide to capture
   any test-specific results after the
   test case is executed. 
   */

   /* insert any calls to fprintf to write data
      e.g. vectorcast_fprint_string ( vcast_user_file, "My Value:");
      e.g. vectorcast_fprint_integer( vcast_user_file, P009_001_001 );
      e.g. vectorcast_fprint_string ( vcast_user_file, "\n");
   */

      /* BEGIN USER_CODE_CAPTURE_9 */
      
      /* DONE USER_CODE_CAPTURE_9 */
     vCAST_USER_CODE( VCAST_UCT_EXPECTED, 0 );

   } /* end CAPTURE */

void vCAST_USER_CODE_CAPTURE_GLOBALS (void)
   {

     vCAST_USER_CODE( VCAST_UCT_EXPECTED_GLOBALS, 0 );

   } /* end CAPTURE */


void vCAST_ONE_SHOT_INIT(void)
{


   /*
    * This procedure is executed first during
    * an execution and should be used for any
    * initialization that may be necessary.
    */
   vcast_user_file = vectorcast_fopen (
      vcast_get_filename(VCAST_USERDATA_DAT), "w" );
   VCAST_EXP_FILE  = vectorcast_fopen (
      vcast_get_filename(VCAST_EXPECTED_DAT), "w" );
      /* BEGIN USER_CODE_ONE_SHOT_INIT_9 */
      
      /* DONE USER_CODE_ONE_SHOT_INIT_9 */

}

void vCAST_ONE_SHOT_TERM(void)
{
   /*
    * This procedure is executed last during
    * execution and should be used for any
    * processing that may be necessary here.
    */
      /* BEGIN USER_CODE_ONE_SHOT_TERM_9 */
      
      /* DONE USER_CODE_ONE_SHOT_TERM_9 */
   vectorcast_fclose ( vcast_user_file );
   vectorcast_fclose ( VCAST_EXP_FILE );
}

void vCAST_GLOBAL_STUB_PROCESSING(void) {
      /* BEGIN USER_CODE_STUB_PROCESSING_9 */
      
      /* DONE USER_CODE_STUB_PROCESSING_9 */

      /* BEGIN STUB_EXIT_USER_CODE_9 */
      
      /* DONE STUB_EXIT_USER_CODE_9 */
}

void vCAST_GLOBAL_BEGINNING_OF_STUB_PROCESSING(void) {
      /* BEGIN STUB_ENTRY_USER_CODE_9 */
      
      /* DONE STUB_ENTRY_USER_CODE_9 */
}

void vCAST_USER_CODE( VCAST_USER_CODE_TYPE uct, int vcast_slot_index ) {
   vcast_B4_switch( 0, uct, vcast_slot_index ); /* call for all units */
}
