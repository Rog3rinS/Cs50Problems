#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 2 || strlen(argv[1]) != 26) {
    printf("Invalid key\n");
    return 1;
  }
  // arbitrary args, dont want to scann
  char text[] = "Gremio e o maior!";
  char *input_text = argv[1];
  char new_text[50];
  
  for (int i = 0; i < strlen(text); i++) {
    if (text[i] >= 65 && text[i] <= 90) {
      new_text[i] = input_text[text[i] - 65];
    } else if (text[i] >= 97 && text[i] <= 122) {
      new_text[i] = tolower(input_text[text[i] - 97]);
    } else {
      new_text[i] = text[i];
    }
  }

  new_text[strlen(text)] = '\0';

  printf("The text encrypted is: %s\n", new_text);
}
