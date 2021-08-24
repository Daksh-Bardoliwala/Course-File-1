#include <stdio.h>
#include <string.h>

char *encode(char text[]) {
  int len = strlen(text);
  char *result;
  for (int i = 0; i < len; i++) {
    result[i] = (char) ((int) text[i] + 1);
  }
  return result;
}

// Encoding - Decoding
int main() {
  char *text = encode("HI");
  printf("%s", text);
  return 0;
}