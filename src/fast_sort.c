#include <stdio.h>

#define ArrSize 10

int input(int *a);
void output(int *a);
void deepCopy(int *a, int *b);
void swap(int *a, int i, int j);
void sort(int *a);
void Qsort(int *a, int first, int last);

int main() {
    int mas[ArrSize];
    int mas2[ArrSize];
    if (input(mas)) {
        deepCopy(mas, mas2);
        sort(mas);
        Qsort(mas2, 0, ArrSize - 1);
        output(mas);
        output(mas2);
    } else {
        printf("n/a");
    }
    return 0;
}


int input(int *a) {
    char c = 0;
    int check = 1;
    for (int *p = a; p - a < ArrSize; p++)
        if (scanf("%d%c", p, &c) && (c == ' ' || c == '\n' || c == EOF)) {
            continue;
        } else {
            check = 0;
        }
    return check;
}

void output(int *a) {
    for (int *p = a; p - a < ArrSize - 1; p++)
        printf("%d ", *p);
    printf("%d\n", *(a + ArrSize - 1));
}

void deepCopy(int *a, int *b) {
    for (int i = 0; i < ArrSize; i++)
        *(b + i) = *(a + i);
}

void swap(int *a, int i, int j) {
    int temp = *(a + i);
    *(a + i) = *(a + j);
    *(a + j) = temp;
}

void sort(int *a) {
    for (int i = 0; i < ArrSize; i++)
        for (int j = 0; j < ArrSize - 1 ; j++)
            if (*(a + j) > *(a + j + 1))
                swap(a, j, j + 1);
}

void Qsort(int *a, int first, int last) {
    int mid;
    int f = first, l = last;
    mid = *(a + (f + l)/2);
    while (f < l) {
        while (*(a + f) < mid)
            f++;
        while (*(a + l) > mid)
            l--;
        if (f <= l) {
            swap(a, l, f);
            f++;
            l--;
        }
    }
    if (first < l)
        Qsort(a, first, l);
    if (f < last)
        Qsort(a, f, last);
}
