// run by using: ./categorize [] [delineation word] [file1.csv] [delineation word] [file2.csv]
// example run statement: ./categorize WH_FirstYears_2015-16.csv Female females.csv Male males.csv
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
  char line[80];

  if(argc!=7){
    fprintf(stderr, "You must give a read file, and two words and output files each, and an overflow file.\n");
    return 1;
  }
  FILE *in = fopen(argv[1],"r");
  FILE *file1 = fopen(argv[3], "w");
  FILE *file2 = fopen(argv[5], "w");
  FILE *file3 = fopen(argv[6],"w");

  while(fscanf(in, "%79s[^\n]\n", line)==1){
    if(strstr(line, argv[2])){
      fprintf(file1, "%s\n", line);
    }else if(strstr(line, argv[4])){
      fprintf(file2, "%s\n", line);
    }else{
      fprintf(file3, "%s\n", line);
    }
  }

  fclose(file1);
  fclose(file2);
  fclose(file3);
  return 0;
}
