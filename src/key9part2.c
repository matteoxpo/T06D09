#include <stdio.h>

#define LEN 100
int input (int *mas, int *length);
void output (int *mas, int length);
void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void rev(int * a, int i, int j);
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



int main(){
    int buff1[LEN];
    int buff2[LEN];
    int res[LEN + 1];
    int len1;
    int len2;
    int lenres;
    if (input(buff1, &len1) && input(buff2, &len2)) {
        //printf("%d\n", len1);
        //output(buff1, len1);
        //sum(buff1, len1, buff2, len2, res, &lenres);
        output(buff1,len1);
    } else {
      printf("n/a");
    }
    return 0;
}

int input(int *mas, int* length) {
    int check = 1;
    int input;
    char c;
    *length = 0;
    int zalupa = 1;
    while (1) {
      if (zalupa && scanf("%d%c", &input, &c) == 2 && c != '\n') {
        mas[*length] = input;
        (*length)++;
      }
      if (c == '\n') {
        printf("fuck");
        mas[*length] = input;
        (*length)++;
        zalupa = 0;
        break;
      }
      if (c != '\n' && c != ' ') {
        check = 0;
        break;
      }

    }
    return check;
}


void output(int *mas, int length) {
    for (int *p = mas; p - mas < length - 1; p++)
        printf("%d ", *p);
    printf("%d", *(mas + length - 1));
}

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
  rev(buff1, 0, len1 - 1);
  rev(buff2, 0, len2 - 1);
  result = 0;
  *result_length = len1;
  for (int i = 0; i < len1; i++) {
    result[i] = buff1[i] + buff2[i];
    if (result[i] / 10 != 0) {
      result[i + 1] += result[i] / 10;
      result[i] %= 10;
      if (i == len1 - 1)
        (*result_length)++;  
    }
  }
  rev(buff1, 0, len1 - 1);
  rev(buff2, 0, len2 - 1);
}

void rev(int * a, int i, int j) {
    while(i < j) {
        int tmp = a[i]; 
        a[i] = a[j]; 
        a[j] = tmp;
        i++; 
        j--;
    }
}