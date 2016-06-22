/*Make an island tour going between islands.
Instead of making an array, which you can't add values to, make links between
each struct to the next! */

//TO RUN: ./dynamic-memory.c < island_list.txt

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct island{ //because you're referencing it recursively, needs full declaration (not just alias)
  char *name;
  char *opens;
  char *closes;
  struct island *next; //link to next island
}island;

//Uncomment for manual creation of islands (otherwise, run as $ ./dynamic-memory.c < island_list.txt)
/*
island amity = {"Amity", "09:00", "17:00", NULL};
island craggy = ("Craggy", "09:00", "17:00", NULL};
island isla_nublar = {"Isla Nublar", "09:00", "17:00", NULL};
island shutter = {"Shutter", "09:00", "17:00", NULL};

//set path between islands
amity.next = &craggy;
craggy.next = &isla_nublar;
isla_nublar.next = &shutter;

//inserting values into the tour:
island skull = {"Skull", "09:00", "17:00", NULL};
isla_nublar.next = &skull;
skull.next = &shutter;
*/

void display(island *start){
  island *i = start;
  for(; i!=NULL; i = i->next){ //keep looping until current island has no next value, at end of each loop, skip to next island
    printf("Name: %s open: %s-%s\n", i->name, i->opens, i->closes);
  }
}


//HEAP DATA
island* create(char *name){ //will return an island based on input name
  island *i = malloc(sizeof(island)); //Creates new struct on heap: uses malloc() to create space on the heap, sizeof() returns how many bytes needed
  i->name = strdup(name); //copies string to heap -- make sure to use free() to release memory at end!
  i->opens = "09:00";
  i->closes = "17:00";
  i->next = NULL;
  return i; //returns address of new struct
}

void release(island *start){ //releases all islands and names one by one going through the sequence
  island *i = start;
  island *next = NULL;
  for(; i!=NULL; i=i->next){
    free(i->name); //free the name copied by strdup earlier
    free(i); //free the island struct
  }
}

void main(){
  island *start=NULL;
  island *i = NULL;
  island *next=NULL;
  char name[80];
  for(; fgets(name,80,stdin)!=NULL; i=next){ //read input string as name, keep looping until no more input strings
    next = create(name);
    if (start==NULL){
      start=next; //first time through, start is set to NULL, so set it to the first island
    }
    if(i!=NULL){
      i->next = next; // -> notation used because i is a pointer
    }
  }

display(start);
release(start);
}
