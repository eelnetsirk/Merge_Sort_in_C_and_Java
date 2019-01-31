#include <stdio.h>
#include <string.h>

int main() {
  // char greet[] = "Here's an array: ";
  // printf("%s\n", greet);
  // int nums[5] = {1,3,4,6,7};
  // int i;
  // for(i = 0; i < 5; i++){
  //   printf("%d ", nums[i]);
  // }
  // printf("\n");
  // int arrlength = sizeof(nums)/sizeof(int);
  // char length[] = "size of this array: ";
  // printf("%s", length);
  // printf("%d", arrlength);
  // int input;
  // printf("give me an int: ");
  // scanf("%d", &input);
  char name[10];
  printf("Who are you? ");
  fgets(name,10,stdin);


  return 0;
}
