// to run: ./order-pizza [options (-t -d+delivery time)] [toppings]
// example run statement: ./test -t Anchovies Artichokes
// exaple run statement: ./test -d now Cheese Pepperoni
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
  char *delivery = "";
  int thick=0;
  char ch;

  while((ch=getopt(argc,argv, "d: t"))!=EOF){
    // can't handle using both -t and -d at the same time...
    switch(ch){
      case 'd':
        delivery=optarg;
        break;
      case 't':
        thick=1;
        break;
      default:
        fprintf(stderr, "Unknown option: '%s'\n", optarg);
        return 1;
    }
    argc -= optind;
    argv += optind;

    if(thick) puts("Thick crust.");
    if(delivery[0]) printf("To be delivered %s.\n", delivery);
    puts("Ingredients:");

    int i;
    for(i=0; i<argc; i++){
      puts(argv[i]);
    }
    return 0;
  }
}
