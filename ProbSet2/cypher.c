#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int key = atoi(argv[1]);
  if (argc != 2 || key == 0) {
    printf("Invalid key\n");
    return 1;
  } else {
    printf("The key is %i\n", key);
  }

  // arbitrary args, dont want to scann
  char text[] = "Hi There!";
  for (int i = 0; i < strlen(text); i++) {
    if (text[i] >= 65 && text[i] <= 90) {
      text[i] = (text[i] - 65 + key) % 26 + 65;
    }
    else if (text[i] >= 97 && text[i] <= 120) {
      text[i] = (text[i] - 97 + key) % 26 + 97;
    }
  }

  printf("The text encrypted is: %s\n", text);
}
