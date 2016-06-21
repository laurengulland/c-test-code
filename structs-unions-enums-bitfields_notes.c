//STRUCTS

//Declaring structs
struct bicycle{
  const char *color;
  int height;
  int gears;
}
struct bicycle a = {"blue", 17, 21}; //have to declare struct and type when creating

//Declaring structs with a typedef and alias
typedef struct bicycle2{
  const char *color;
  int gears;
  int height;
} bike; //bike is now an alias for "struct bicycle2"
struct bicycle2 b = {"blue", 17, 21};
bike b = {"blue", 17, 21} //declaration using alias

//Declaration using dot notation
bike c = {.height=17, .gears=21};


//UNIONS
//stores only one of the fields in its definition
typedef union{
  short count;
  float weight;
  float volume;
}quantity; //this union, "quantity", will store either a count, a weight, or a volume.

typedef struct{
  const char *name;
  const char *country;
  quantity amount; //uses union "quantity" data type within struct
}fruit_order;

fruit_order apples = {"apples", "England", .amount.weight=4.2};
printf("This order contains %2.2f lbs of %s\n", apples.amount.weight, apples.name);


//ENUMS: lets you create a list of symbols, helps for keeping track of what you can assign.
enum colors {RED, YELLOW, BLUE};
enum colors favorite = BLUE; //checks to see if BLUE is in colors enum
enum colors second_favorite = ORANGE; //will not compile because ORANGE is not in colors enum

typedef enum{
  COUNT, POUNDS, PINTS
} unit_of_measure;

typedef struct{
  const char *name;
  unit_of_measure units; //units assigned must be in unit_of_measure enum or won't compile
} name_and_units;

name_and_units d = {"Pitcher", PINTS};


//BITFIELDS: allows you to define exactly how many bits a variable should store
typedef struct{ //bitfields can save space if collected together into a struct because they're grouped
  unsigned int true_false:1; //a single bit can store a 0/1, like a boolean
  unsigned int quadrant:2; //can store 0-3
  unsigned int month_no:4; //can store 0-15
  //etc.
}
