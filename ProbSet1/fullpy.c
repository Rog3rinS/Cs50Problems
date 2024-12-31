#include <stdio.h>

int main(void) {
  int size = 6;
  int count = size;

  for (int i = 0; i < size; i++) {
    // right part
    for (int j = 0; j < count - 1; j++) {
      printf(" ");
    }
    for (int j = 0; j <= i; j++) {
      printf("#");
    }
    count -= 1;
    
    // separator
    printf("  ");
    
    // left part
    for (int j = 0; j <= i; j++) {
      printf("#");
    }
    printf("\n");
  }
}
