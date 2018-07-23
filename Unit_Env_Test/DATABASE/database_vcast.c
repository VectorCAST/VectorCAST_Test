/*vcast_header_expansion_start:C:/VCAST/Tutorial/c/ctypes.h*/
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
struct table_data_type Table_Data[6];
struct table_data_type Get_Table_Record(table_index_type Table)
{/*vcast_internal_start*/
extern unsigned short P_9_1_1
;
extern struct table_data_type R_9_1;
extern unsigned char SBF_9_1;
if(SBF_9_1) {
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_9_1
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_9_1
  if ( vcast_is_in_driver ) {
    P_9_1_1 = Table;
    vCAST_COMMON_STUB_PROC_9( 9, 1, 2, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_9_1
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_9_1
  vCAST_USER_CODE_TIMER_START();
  return R_9_1;
}
/*vcast_internal_end*/
/*vcast_internal_start*/{/*vcast_internal_end*/
  return (Table_Data[Table]);
/*vcast_internal_start*/}/*vcast_internal_end*/
}
void Update_Table_Record(table_index_type Table, struct table_data_type Data)
{/*vcast_internal_start*/
extern unsigned short P_9_2_1
;
extern struct table_data_type P_9_2_2
;
extern unsigned char SBF_9_2;
if(SBF_9_2) {
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_9_2
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_9_2
  if ( vcast_is_in_driver ) {
    P_9_2_1 = Table;
    P_9_2_2 = Data;
    vCAST_COMMON_STUB_PROC_9( 9, 2, 3, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_9_2
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_9_2
  vCAST_USER_CODE_TIMER_START();
  return;
}
/*vcast_internal_end*/
/*vcast_internal_start*/{/*vcast_internal_end*/
  Table_Data[Table] = Data;
/*vcast_internal_start*/}/*vcast_internal_end*/
}
/*vcast_internal_start*/unsigned short P_9_1_1
;
struct table_data_type R_9_1;
unsigned char SBF_9_1 = 0;
/*vcast_internal_end*/
/*vcast_internal_start*/unsigned short P_9_2_1
;
struct table_data_type P_9_2_2
;
unsigned char SBF_9_2 = 0;
/*vcast_internal_end*/
