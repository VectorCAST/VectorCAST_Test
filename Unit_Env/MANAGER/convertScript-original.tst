-- VectorCAST 18.sp2 (07/02/18)
-- Test Case Script
-- 
-- Environment    : MANAGER
-- Unit(s) Under Test: manager
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: Add

-- Test Case: Add.001
TEST.UNIT:manager
TEST.SUBPROGRAM:Add
TEST.NEW
TEST.NAME:Add.001
TEST.EXPECTED:manager.Add.return:2
TEST.VALUE_USER_CODE:manager.<<GLOBAL>>.vcast_SCU_CCUCON5
<<manager.<<GLOBAL>>.vcast_SCU_CCUCON5>> = ( 0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: Add_Party_To_Waiting_List

-- Test Case: Add_Party_To_Waiting_List.001
TEST.UNIT:manager
TEST.SUBPROGRAM:Add_Party_To_Waiting_List
TEST.NEW
TEST.NAME:Add_Party_To_Waiting_List.001
TEST.VALUE:manager.Add_Party_To_Waiting_List.Name:<<malloc 3>>
TEST.END

-- Subprogram: Place_Order

-- Test Case: Place_Order.001
TEST.UNIT:manager
TEST.SUBPROGRAM:Place_Order
TEST.NEW
TEST.NAME:Place_Order.001
TEST.STUB:manager.Add_Party_To_Waiting_List
TEST.END
