#include <stdio.h>

#define ArrSize 10

int input(int *a);
void output(int *a);
void swap(int *a, int i);
void sort(int *a);

int main() {
    int mas[ArrSize];
    if (input(mas)) {
        sort(mas);
        output(mas);
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
            check =  0;
        }
    return check;
}

void output(int *a) {
    for (int *p = a; p - a < ArrSize - 1; p++)
        printf("%d ", *p);
    printf("%d", *(a + ArrSize - 1));
}


void swap(int *a, int i) {
    int temp = *(a + i);
    *(a + i) = *(a + i + 1);
    *(a + i + 1) = temp;
}

void sort(int *a) {
    for (int i = 0; i < ArrSize; i++)
        for (int j = 0; j < ArrSize - 1 ; j++)
            if (*(a + j) > *(a + j + 1))
                swap(a, j);
}
