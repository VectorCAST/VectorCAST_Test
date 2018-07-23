
void vCAST_VALUE_USER_CODE_8(int vcast_slot_index ) {
  {
      /* BEGIN VALUE_USER_CODE_8 */
      /* DONE VALUE_USER_CODE_8 */
  }
}

void vCAST_EXPECTED_USER_CODE_8(int vcast_slot_index ) {
  {
      /* BEGIN EXPECTED_USER_CODE_8 */
      /* DONE EXPECTED_USER_CODE_8 */
  }
}

void vCAST_EGLOBALS_USER_CODE_8(int vcast_slot_index ) {
  {
      /* BEGIN EXPECTED_GLOBALS_USER_CODE_8 */
      /* DONE EXPECTED_GLOBALS_USER_CODE_8 */
  }
}

void vCAST_STUB_PROCESSING_8(
        int  UnitIndex, 
        int  SubprogramIndex ) {
  vCAST_GLOBAL_STUB_PROCESSING();
  {
      /* BEGIN STUB_VAL_USER_CODE_8 */
      /* DONE STUB_VAL_USER_CODE_8 */
  }
}

void vCAST_BEGIN_STUB_PROC_8(
        int  UnitIndex, 
        int  SubprogramIndex ) {
  vCAST_GLOBAL_BEGINNING_OF_STUB_PROCESSING();
  {
      /* BEGIN STUB_EXP_USER_CODE_8 */
      /* DONE STUB_EXP_USER_CODE_8 */
  }
}

void VCAST_USER_CODE_UNIT_8( VCAST_USER_CODE_TYPE uct, int vcast_slot_index ) {
  switch( uct ) {
    case VCAST_UCT_VALUE:
      vCAST_VALUE_USER_CODE_8(vcast_slot_index);
      break;
    case VCAST_UCT_EXPECTED:
      vCAST_EXPECTED_USER_CODE_8(vcast_slot_index);
      break;
    case VCAST_UCT_EXPECTED_GLOBALS:
      vCAST_EGLOBALS_USER_CODE_8(vcast_slot_index);
      break;
  } /* switch( uct ) */
}
