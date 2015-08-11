//SortNumbers.c
/*
���� �̸�: SortNumbers.c
��     ��: 100���� ���� �Է¹޾� ���� ���� ����, ���� ���� ����,
			Ȧ���� ����, ¦���� ������ ����Ѵ�.
��  �� ��: �� �� ��
�ۼ� ����: 2015�� 8�� 11��
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100
typedef signed long int Long;

int main(int argc, char *argv[]);
void Input(Long(*numbers));
void SortNumbers(Long(*numbers), Long *evenNumber, Long *oddNumber,
	Long *positiveNumber, Long *negativeNumber);
void Output(Long evenNumber, Long oddNumber,
	Long positiveNumber, Long negativeNumber);

int main(int argc, char *argv[]) {
	Long numbers[MAX];
	Long evenNumber;
	Long oddNumber;
	Long positiveNumber;
	Long negativeNumber;

	Input(numbers);
	SortNumbers(numbers, &evenNumber, &oddNumber,
		&positiveNumber, &negativeNumber);
	Output(evenNumber, oddNumber, positiveNumber,
		negativeNumber);

	return 0;
}

/*
�Լ� �̸�: Input
��     ��: Ű����� ���� 100���� �Է¹޾� ����Ѵ�.
��     ��: ����
��     ��: ����
*/
void Input(Long(*numbers)) {
	Long i;
	for (i = 0; i < MAX; i++) {
		scanf("%d", numbers + i);
	}
}

/*
�Լ� �̸�: SortNumbers
��     ��: 100���� ������ ��� ����, ���� ����, 
			¦�� ����, Ȧ�� ������ ���Ѵ�.
��     ��: ����
��     ��: ��� ����, ���� ����, ¦�� ����,
			Ȧ�� ����
*/
void SortNumbers(Long(*numbers), Long *evenNumber, Long *oddNumber,
	Long *positiveNumber, Long *negativeNumber) {
	
	Long remainder;
	Long i;
	*positiveNumber = 0;
	*evenNumber = 0;
	*oddNumber = 0;
	*negativeNumber = 0;

	for (i = 0; i < MAX; i++) {
		if (numbers[i] > 0) {
			(*positiveNumber)++;
			remainder = numbers[i] % 2;

			if (remainder == 0) {
				(*evenNumber)++;
			}
			else {
				(*oddNumber)++;
			}
		}
		else if (numbers[i] < 0) {
			(*negativeNumber)++;
		}

	}

}

/*
�Լ� �̸�: Output
��     ��: ¦�� ����, Ȧ�� ����, ��� ����, ���� ������
			�Է¹޾� ����Ϳ� �޽����� ����Ѵ�.
��     ��: ¦�� ����, Ȧ�� ����, ��� ����, ���� ����
��     ��: ����
*/
void Output(Long evenNumber, Long oddNumber,
	Long positiveNumber, Long negativeNumber) {

	printf("¦�� ����: %d\nȦ�� ����: %d\n��� ����: %d\n���� ����: %d\n",
		evenNumber, oddNumber, positiveNumber, negativeNumber);
}