#include <stdio.h>

int main(void) {
  char s[5] = "TEST";
  for (int i = 0; i < 4; i++) {
    printf("%p\n", &s[i]);
  }
  return 0;
}