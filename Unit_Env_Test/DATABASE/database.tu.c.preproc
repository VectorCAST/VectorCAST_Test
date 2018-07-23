#line 3 "vcast_preprocess.15124.10.c"                                                                                                                            
# 1 "vcast_preprocess.15124.8.c" 1

typedef int VECTORCAST_MARKER__UNIT_PREFIX_START;

typedef int VECTORCAST_MARKER__UNIT_PREFIX_END;
# 1 "C:/VCAST/Tutorial/c/database.c" 1
# 1 "C:/VCAST/Tutorial/c/ctypes.h" 1
# 14 "C:/VCAST/Tutorial/c/ctypes.h"
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
# 2 "C:/VCAST/Tutorial/c/database.c" 2

struct table_data_type Table_Data[6];

struct table_data_type Get_Table_Record(table_index_type Table)
{
  return (Table_Data[Table]);
}

void Update_Table_Record(table_index_type Table, struct table_data_type Data)
{
  Table_Data[Table] = Data;
}
# 6 "vcast_preprocess.15124.8.c" 2

typedef int VECTORCAST_MARKER__UNIT_APPENDIX_START;

typedef int VECTORCAST_MARKER__UNIT_APPENDIX_END;
# 4 "vcast_preprocess.15124.10.c" 2

                                               
