//SortNumbers.c
/*
파일 이름: SortNumbers.c
기     능: 100개의 수를 입력받아 양의 정수 개수, 음의 정수 개수,
			홀수의 개수, 짝수의 개수를 출력한다.
작  성 자: 송 용 단
작성 일자: 2015년 8월 11일
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
함수 이름: Input
기     능: 키보드로 숫자 100개를 입력받아 출력한다.
입     력: 없음
출     력: 수들
*/
void Input(Long(*numbers)) {
	Long i;
	for (i = 0; i < MAX; i++) {
		scanf("%d", numbers + i);
	}
}

/*
함수 이름: SortNumbers
기     능: 100개의 수들의 양수 개수, 음수 개수, 
			짝수 개수, 홀수 개수를 구한다.
입     력: 수들
출     력: 양수 개수, 음수 개수, 짝수 개수,
			홀수 개수
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
함수 이름: Output
기     능: 짝수 개수, 홀수 개수, 양수 개수, 음수 개수를
			입력받아 모니터에 메시지를 출력한다.
입     력: 짝수 개수, 홀수 개수, 양수 개수, 음수 개수
출     력: 없음
*/
void Output(Long evenNumber, Long oddNumber,
	Long positiveNumber, Long negativeNumber) {

	printf("짝수 개수: %d\n홀수 개수: %d\n양수 개수: %d\n음수 개수: %d\n",
		evenNumber, oddNumber, positiveNumber, negativeNumber);
}