#include <stdio.h>

#define LEN 100
int input(int *mas, int *length);
void output(int *mas, int length);
void sum(int *buff1, int len1, int *buff2, int len2, int *result,
         int *result_length);
void sub(int *buff1, int len1, int *buff2, int len2, int *result,
         int *result_length);
int min(int x, int y);
void rev(int *a, int i, int j);
int correctSymbol(char c);
void clear_arr(int *result);
/*
    Беззнаковая целочисленная длинная арифметика
    с использованием массивов.
    Ввод:
     * 2 длинных числа в виде массивов до 100 элементов
     * В один элемент массива нельзя вводить число > 9
    Вывод:
     * Результат сложения и разности чисел-массивов
    Пример:
     * 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1
       2 9

       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0
       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2
*/

int main() {
  int buff1[LEN];
  int buff2[LEN];
  int res[LEN + 1];
  int len1;
  int len2;
  int lenres;
  if (input(buff1, &len1) && input(buff2, &len2)) {
    rev(buff1, 0, len1 - 1);
    rev(buff2, 0, len2 - 1);
    sum(buff1, len1, buff2, len2, res, &lenres);
    output(res, lenres);
    printf("\n");
    sub(buff1, len1, buff2, len2, res, &lenres);
    output(res, lenres);
  } else {
    printf("n/a");
  }
  return 0;
}
int correctSymbol(char c) { return c == '\n' || c == ' ' || c == EOF ? 1 : 0; }
int input(int *mas, int *length) {
  int check = 1;
  int inp;
  char c;
  *length = 0;
  while (1) {
    if (scanf("%d%c", &inp, &c) == 2 && correctSymbol(c)) {
      if (inp / 10 != 0) {
        check = 0;
        break;
      }
      mas[*length] = inp;
      (*length)++;
      if (c == '\n') {
        break;
      }
    } else {
      check = 0;
      break;
    }
  }
  return check;
}

void output(int *mas, int length) {
  for (int *p = mas; p - mas < length - 1; p++) printf("%d ", *p);
  printf("%d", *(mas + length - 1));
}

void clear_arr(int *result) {
  for (int i = 0; i < LEN + 2; i++) result[i] = 0;
}

void sum(int *buff1, int len1, int *buff2, int len2, int *result,
         int *result_length) {
  *result_length = len1;
  clear_arr(result);

  for (int i = 0; i < min(len1, len2); i++) {
    result[i] += buff1[i] + buff2[i];
    if (result[i] / 10 != 0) {
      result[i + 1] += result[i] / 10;
      result[i] %= 10;
      if (i + 1 == min(len1, len2)) (*result_length)++;
    }
  }
  if (len2 < len1) {
    for (int i = len2; i < len1; i++) result[i] = buff1[i];
  }

  rev(result, 0, *result_length - 1);
}

void sub(int *buff1, int len1, int *buff2, int len2, int *result,
         int *result_length) {
  clear_arr(result);

  *result_length = len1;
  for (int i = 0; i < min(len1, len2); i++) {
    if (buff1[i] < buff2[i]) {
      buff1[i] += 10;
      buff1[i + 1] -= 1;
      if (i + 1 == len1) {
        (*result_length)--;
      }
    }

    result[i] = buff1[i] - buff2[i];
  }
  if (len2 < len1) {
    for (int i = len2; i < len1; i++) result[i] = buff1[i];
  }
  rev(result, 0, *result_length - 1);
}

void rev(int *a, int i, int j) {
  while (i < j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
    i++;
    j--;
  }
}

int min(int x, int y) { return x > y ? y : x; }
