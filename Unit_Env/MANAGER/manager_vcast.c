/*vcast_header_expansion_start:C:/VCAST/Tutorial/c/ctypes.h*/
/*vcast_header_expansion_end*/
struct table_data_type Get_Table_Record(table_index_type Table);
void Update_Table_Record(table_index_type Table, struct table_data_type Data);
/* Allow 10 Parties to wait */
static name_type WaitingList[10];
static unsigned int WaitingListSize = 0;
static unsigned int WaitingListIndex = 0;
int Add(int a, int b)
{/*vcast_internal_start*/
extern int P_9_1_1
;
extern int P_9_1_2
;
extern int R_9_1;
extern unsigned char SBF_9_1;
if(SBF_9_1) {
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_9_1
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_9_1
  if ( vcast_is_in_driver ) {
    P_9_1_1 = a;
    P_9_1_2 = b;
    vCAST_COMMON_STUB_PROC_9( 9, 1, 3, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_9_1
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_9_1
  vCAST_USER_CODE_TIMER_START();
  return R_9_1;
}
/*vcast_internal_end*/
/*vcast_internal_start*/{/*vcast_internal_end*/
   int sum = 0;
   sum = a + b;
   return sum;
/*vcast_internal_start*/}/*vcast_internal_end*/
}
/* This function will add a free dessert to specific orders based on the 
   entree, salad, and beverage choice */
void Add_Included_Dessert(struct order_type* Order)
{/*vcast_internal_start*/
extern struct order_type *P_9_2_1
;
extern unsigned char SBF_9_2;
if(SBF_9_2) {
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_9_2
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_9_2
  if ( vcast_is_in_driver ) {
    P_9_2_1 = Order;
    vCAST_COMMON_STUB_PROC_9( 9, 2, 2, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_9_2
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_9_2
  vCAST_USER_CODE_TIMER_START();
  return;
}
/*vcast_internal_end*/
/*vcast_internal_start*/{/*vcast_internal_end*/
  if(Order->Entree == STEAK &&
     Order->Salad == CAESAR &&
     Order->Beverage == MIXED_DRINK) {
    Order->Dessert = PIE;
  } else if(Order->Entree == LOBSTER &&
            Order->Salad == GREEN &&
            Order->Beverage == WINE) {
    Order->Dessert = CAKE;
  }
/*vcast_internal_start*/}/*vcast_internal_end*/
}
int Place_Order(table_index_type Table,
                seat_index_type Seat,
                struct order_type Order)
{/*vcast_internal_start*/
extern unsigned short P_9_3_1
;
extern unsigned short P_9_3_2
;
extern struct order_type P_9_3_3
;
extern int R_9_3;
extern unsigned char SBF_9_3;
if(SBF_9_3) {
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_9_3
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_9_3
  if ( vcast_is_in_driver ) {
    P_9_3_1 = Table;
    P_9_3_2 = Seat;
    P_9_3_3 = Order;
    vCAST_COMMON_STUB_PROC_9( 9, 3, 4, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_9_3
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_9_3
  vCAST_USER_CODE_TIMER_START();
  return R_9_3;
}
/*vcast_internal_end*/
/*vcast_internal_start*/{/*vcast_internal_end*/
  struct table_data_type Table_Data;
  Table_Data = Get_Table_Record(Table);
  Table_Data.Is_Occupied = v_true;
  Table_Data.Number_In_Party = Table_Data.Number_In_Party + 1;
  Table_Data.Order[Seat] = Order;
  /* Add a free dessert in some cases */
  Add_Included_Dessert(&Table_Data.Order[Seat]);
  switch(Order.Entree)
    {
    case NO_ENTREE :
       break;
    case STEAK :
       Table_Data.Check_Total = Table_Data.Check_Total + 14.0;
       break;
    case CHICKEN :
       Table_Data.Check_Total = Table_Data.Check_Total + 10.0;
       break;
    case LOBSTER :
       Table_Data.Check_Total = Table_Data.Check_Total + 18.0;
       break;
    case PASTA :
       Table_Data.Check_Total = Table_Data.Check_Total + 12.0;
       break;
    }
  Update_Table_Record(Table, Table_Data);
  return 0;
/*vcast_internal_start*/}/*vcast_internal_end*/
}
int Clear_Table(table_index_type Table)
{/*vcast_internal_start*/
extern unsigned short P_9_4_1
;
extern int R_9_4;
extern unsigned char SBF_9_4;
if(SBF_9_4) {
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_9_4
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_9_4
  if ( vcast_is_in_driver ) {
    P_9_4_1 = Table;
    vCAST_COMMON_STUB_PROC_9( 9, 4, 2, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_9_4
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_9_4
  vCAST_USER_CODE_TIMER_START();
  return R_9_4;
}
/*vcast_internal_end*/
/*vcast_internal_start*/{/*vcast_internal_end*/
  struct table_data_type Table_Data;
  seat_index_type Seat;
  Table_Data = Get_Table_Record(Table);
  Table_Data.Is_Occupied = v_false;
  Table_Data.Number_In_Party = 1;
  for (Seat=0; Seat < 4; Seat++){
      Table_Data.Order[Seat].Soup = NO_SOUP;
      Table_Data.Order[Seat].Salad = NO_SALAD;
      Table_Data.Order[Seat].Entree = NO_ENTREE;
      Table_Data.Order[Seat].Dessert = NO_DESSERT;
      Table_Data.Order[Seat].Beverage = NO_BEVERAGE;
   }
  Table_Data.Check_Total = 0;
  Update_Table_Record(Table, Table_Data);
  return 0;
/*vcast_internal_start*/}/*vcast_internal_end*/
}
FLOAT Get_Check_Total(table_index_type Table)
{/*vcast_internal_start*/
extern unsigned short P_9_5_1
;
extern float R_9_5;
extern unsigned char SBF_9_5;
if(SBF_9_5) {
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_9_5
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_9_5
  if ( vcast_is_in_driver ) {
    P_9_5_1 = Table;
    vCAST_COMMON_STUB_PROC_9( 9, 5, 2, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_9_5
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_9_5
  vCAST_USER_CODE_TIMER_START();
  return R_9_5;
}
/*vcast_internal_end*/
/*vcast_internal_start*/{/*vcast_internal_end*/
  struct table_data_type Table_Data;
  Table_Data = Get_Table_Record(Table);
  return (Table_Data.Check_Total);
/*vcast_internal_start*/}/*vcast_internal_end*/
}
void Add_Party_To_Waiting_List(char* Name)
{/*vcast_internal_start*/
extern char *P_9_6_1
;
extern unsigned char SBF_9_6;
if(SBF_9_6) {
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_9_6
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_9_6
  if ( vcast_is_in_driver ) {
    P_9_6_1 = Name;
    vCAST_COMMON_STUB_PROC_9( 9, 6, 2, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_9_6
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_9_6
  vCAST_USER_CODE_TIMER_START();
  return;
}
/*vcast_internal_end*/
/*vcast_internal_start*/{/*vcast_internal_end*/
  int i = 0;
  if(WaitingListSize > 9)
    WaitingListSize = 0;
  while(Name && *Name) {
    WaitingList[WaitingListSize][i++] = *Name;
    Name++;
  }
  WaitingList[WaitingListSize++][i] = 0;
/*vcast_internal_start*/}/*vcast_internal_end*/
}
char* Get_Next_Party_To_Be_Seated(void)
{/*vcast_internal_start*/
extern char *R_9_7;
extern unsigned char SBF_9_7;
if(SBF_9_7) {
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_9_7
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_9_7
  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 9, 7, 1, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_9_7
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_9_7
  vCAST_USER_CODE_TIMER_START();
  return R_9_7;
}
/*vcast_internal_end*/
/*vcast_internal_start*/{/*vcast_internal_end*/
  if(WaitingListIndex > 9)
    WaitingListIndex = 0;
  return WaitingList[WaitingListIndex++];
/*vcast_internal_start*/}/*vcast_internal_end*/
}
/*vcast_internal_start*/int P_9_1_1
;
int P_9_1_2
;
int R_9_1;
unsigned char SBF_9_1 = 0;
/*vcast_internal_end*/
/*vcast_internal_start*/struct order_type *P_9_2_1
;
unsigned char SBF_9_2 = 0;
/*vcast_internal_end*/
/*vcast_internal_start*/unsigned short P_9_3_1
;
unsigned short P_9_3_2
;
struct order_type P_9_3_3
;
int R_9_3;
unsigned char SBF_9_3 = 0;
/*vcast_internal_end*/
/*vcast_internal_start*/unsigned short P_9_4_1
;
int R_9_4;
unsigned char SBF_9_4 = 0;
/*vcast_internal_end*/
/*vcast_internal_start*/unsigned short P_9_5_1
;
float R_9_5;
unsigned char SBF_9_5 = 0;
/*vcast_internal_end*/
/*vcast_internal_start*/char *P_9_6_1
;
unsigned char SBF_9_6 = 0;
/*vcast_internal_end*/
/*vcast_internal_start*/char *R_9_7;
unsigned char SBF_9_7 = 0;
/*vcast_internal_end*/
