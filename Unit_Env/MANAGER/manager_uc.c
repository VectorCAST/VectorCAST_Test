
/********************/
void vCAST_VALUE_USER_CODE_9 (
         int vcast_slot_index ) {
/* BEGIN VALUE_USER_CODE_9 */
/* BEGIN C-000001.DAT */
if ( ( vCAST_UNIT == 9 ) &&
     ( vCAST_SUBPROGRAM == 1 ) &&
     ( VCAST_test_name_cmp ( "Add.001" ) == 0 ) ) {
{
vcast_SCU_CCUCON5 = ( 0 );
}

} /* Add.001 */
/* END C-000001.DAT */

/* DONE VALUE_USER_CODE_9 */
}

/********************/
void vCAST_EXPECTED_USER_CODE_9 (
         int vcast_slot_index ) {
/* BEGIN EXPECTED_USER_CODE_9 */
/* DONE EXPECTED_USER_CODE_9 */
}

/********************/
void vCAST_EGLOBALS_USER_CODE_9 (
         int vcast_slot_index ) {
/* BEGIN EXPECTED_GLOBALS_USER_CODE_9 */
/* DONE EXPECTED_GLOBALS_USER_CODE_9 */
}

/********************/
void vCAST_STUB_PROCESSING_9 (
         int UnitIndex,
         int SubprogramIndex ) {
    vCAST_GLOBAL_STUB_PROCESSING();
/* BEGIN STUB_VAL_USER_CODE_9 */
/* DONE STUB_VAL_USER_CODE_9 */
}

/********************/
void vCAST_BEGIN_STUB_PROC_9 (
         int UnitIndex,
         int SubprogramIndex ) {
    vCAST_GLOBAL_BEGINNING_OF_STUB_PROCESSING();
/* BEGIN STUB_EXP_USER_CODE_9 */
/* DONE STUB_EXP_USER_CODE_9 */
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
