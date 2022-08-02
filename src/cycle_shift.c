#include <stdio.h>

#define ArrSize 10
int input(int *mas, int *length);
void output(int *mas, int length);
void shift(int *mas, int length, int c);
void cycle_shift(int *mas, int length, int c);
void rev(int *mas, int i, int j);

int main() {
  int mas[ArrSize];
  int length;
  int c;
  if (input(mas, &length) && scanf("%d", &c)) {
    // int l = length;
    cycle_shift(mas, length, c);
    output(mas, length);
  }
}

int input(int *mas, int *length) {
  char c = 0;
  int check = 1;
  if (scanf("%d%c", length, &c) && c == '\n' && *length >= 0 &&
      *length <= ArrSize) {
    for (int *p = mas; p - mas < *length; p++)
      if (scanf("%d%c", p, &c) && (c == ' ' || c == '\n' || c == EOF)) {
        continue;
      } else {
        printf("n/a");
        check = 0;
      }
  } else {
    printf("n/a");
    check = 0;
  }
  return check;
}

void output(int *mas, int length) {
  for (int *p = mas; p - mas < length - 1; p++) printf("%d ", *p);
  printf("%d", *(mas + length - 1));
}

void cycle_shift(int *mas, int length, int c) {
  if (c > 0) {
    for (int i = 0; i < c; i++) {
      int el = mas[0];
      for (int j = 0; j < length - 1; j++) {
        mas[j] = mas[j + 1];
      }
      mas[length - 1] = el;
    }
  } else {
    c *= -1;
    for (int i = 0; i < c; i++) {
      int el = mas[length - 1];
      for (int j = length - 1; j > 0; j--) {
        mas[j] = mas[j - 1];
      }
      mas[0] = el;
    }
  }
}
