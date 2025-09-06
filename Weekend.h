#pragma once

// 3개의 파라메터를 받아 평균값을 리턴하는 함수 만들기
float AvarageReturn(int Number1, int Number2, int Number3);

// 정가와 할인율 입력 받아 할인가 구하는 함수 만들기
float PriceReturn(float OriginPrice, float RatePrice);

// 주사위를 굴린 결과를 리턴하는 함수 만들기
int PlayDice();

// 점수를 주면 성적(A~F)를 주는 함수 만들기
int ReturnGradeScore(int GradeScore);

template <typename T>
// 템플릿 함수로 Clamp 함수 구현하기
T Clamp(T value, T min, T max)
{
	if ((value - min) == (max - value)) {
		printf("Value / %d\n\n", value);
		return value;
	}
	else if (value < min) {
		printf("Min / %d\n\n", min);
		return min;
	}
	else if (value > max) {
		printf("Max / %d\n\n", max);
		return max;
	}
}