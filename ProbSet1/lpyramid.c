#include <stdio.h>

int main(void) {
  int size = 8;
  int count = size;

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < count - 1; j++) {
      printf(" ");
    }
    int more = size - count;
    for (int z = 0; z <= i; z++) {
      printf("#");
    }
    printf("\n");
    count -= 1;
  }
}
