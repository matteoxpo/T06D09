/*------------------------------------
	Здравствуй, человек!
	Чтобы получить ключ 
	поработай с комментариями.
-------------------------------------*/

#include <stdio.h>

#define ArrSize 10
int input (int *buffer, int *length);
void output (int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int* buffer, int length, int number, int* numbers);

/*------------------------------------
	Функция получает массив данных 
	через stdin.
	Выдает в stdout особую сумму
	и сформированный массив 
	специальных элементов
	(выбранных с помощью найденной суммы):
	это и будет частью ключа
-------------------------------------*/
int main() {
	int mas[ArrSize];
	int numbers[ArrSize];
	int length;
	if (input(mas, &length)) {
		int sum = sum_numbers(mas, length);
		int num_length = find_numbers(mas, length, sum, numbers);
		printf("%d\n",sum);
		output(numbers, num_length);
	}
}

int input(int *buffer, int *length) {
    char c = 0;
	int check = 1;
    if (scanf("%d%c", length, &c) && c == '\n' && *length >= 0 && *length <= ArrSize) {
        for (int *p = buffer; p - buffer < *length; p++)
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

void output(int *buffer, int length) {
    for (int *p = buffer; p - buffer < length - 1; p++)
        printf("%d ", *p);
    printf("%d", *(buffer + length - 1));
}




/*------------------------------------
	Функция должна находить
	сумму четных элементов 
	с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
	int sum = 0;
	for (int i = 1; i < length; i++)
		if ( *(buffer + i) % 2 == 0)
			sum = sum + *(buffer + i);
	return sum;
}

/*------------------------------------
	Функция должна находить
	все элементы, на которые нацело
	делится переданное число и
	записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int* buffer, int length, int number, int* numbers) {
	int num_length = 0;
	for (int i = 0; i < length; i++)
		if (*(buffer + i) != 0 && number % *(buffer + i) == 0) {
			*(numbers + num_length) = *(buffer + i);
			num_length++;
		}
	return num_length;
}
