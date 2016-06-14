#include <stdio.h>
#include <string.h>

char tracks[][20]={"One","Two","Three","Four five six","Seven ten", "five"};

int find_track(char search_for[]){
  int i;
  int num_tracks = sizeof(tracks)/sizeof(tracks[0]);
  for(i=0; i<num_tracks; i++){
    if(strstr(tracks[i], search_for)){
      printf("Track %i: '%s'\n", i, tracks[i]);
    }else{
      printf("Nope. '%s'\n", tracks[i]);
    }
  }
  return 0;
}

int main(){
  char search_for[80];
  printf("Search for: ");
  fgets(search_for, 80, stdin);
  search_for[strcspn(search_for, "\n")] = 0; //removes newline character
  find_track(search_for);
  return 0;
}
