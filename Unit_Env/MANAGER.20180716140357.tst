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
TEST.VALUE_USER_CODE:manager.<<GLOBAL>>.vcast_SCU_CCUCON5
<<manager.<<GLOBAL>>.vcast_SCU_CCUCON5>> = ( 1 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: Place_Order

-- Test Case: BASIS-PATH-002
TEST.UNIT:manager
TEST.SUBPROGRAM:Place_Order
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 5
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) case (Order.Entree) ==> NO_ENTREE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:manager.Place_Order.Table:<<MIN>>
TEST.VALUE:manager.Place_Order.Seat:<<MIN>>
TEST.VALUE:manager.Place_Order.Order.Entree:NO_ENTREE
TEST.END

-- Test Case: BASIS-PATH-003
TEST.UNIT:manager
TEST.SUBPROGRAM:Place_Order
TEST.NEW
TEST.NAME:BASIS-PATH-003
TEST.BASIS_PATH:3 of 5
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (2) case (Order.Entree) ==> STEAK
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:manager.Place_Order.Table:<<MIN>>
TEST.VALUE:manager.Place_Order.Seat:<<MIN>>
TEST.VALUE:manager.Place_Order.Order.Entree:STEAK
TEST.END

-- Test Case: BASIS-PATH-004
TEST.UNIT:manager
TEST.SUBPROGRAM:Place_Order
TEST.NEW
TEST.NAME:BASIS-PATH-004
TEST.BASIS_PATH:4 of 5
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (3) case (Order.Entree) ==> CHICKEN
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:manager.Place_Order.Table:<<MIN>>
TEST.VALUE:manager.Place_Order.Seat:<<MIN>>
TEST.VALUE:manager.Place_Order.Order.Entree:CHICKEN
TEST.END

-- Test Case: BASIS-PATH-005
TEST.UNIT:manager
TEST.SUBPROGRAM:Place_Order
TEST.NEW
TEST.NAME:BASIS-PATH-005
TEST.BASIS_PATH:5 of 5
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (4) case (Order.Entree) ==> LOBSTER
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:manager.Place_Order.Table:<<MIN>>
TEST.VALUE:manager.Place_Order.Seat:<<MIN>>
TEST.VALUE:manager.Place_Order.Order.Entree:LOBSTER
TEST.END

-- Test Case: Place_Order.001
TEST.UNIT:manager
TEST.SUBPROGRAM:Place_Order
TEST.NEW
TEST.NAME:Place_Order.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (5) case (Order.Entree) ==> PASTA
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.END
