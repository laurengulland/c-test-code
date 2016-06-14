/* from Head First C */
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

void main(){
  char card_name[3];
  int count = 0;
  while(1==1){
    puts("Enter the card name, or \"X\" to break: ");
    scanf("%2s", card_name);
    if(card_name[0]=='X') break;
    int val = find_card_val(card_name[0]);

    if ((val>=3)&&(val<=6)) count++;
    else if(val==10) count--;

    printf("Current count: %i\n", count);
  }
}

int find_card_val(card_num){
  switch(card_num){
    case 'K':
    case 'Q':
    case 'J':
      return 10;
    case 'A':
      return 11;
    default:
      return (card_num-'0');
  }
  return 0;
}
