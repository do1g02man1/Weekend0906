#pragma once

float AvarageReturn(int Number1, int Number2, int Number3);
float PriceReturn(float OriginPrice, float RatePrice);
int PlayDice();
int ReturnGradeScore(int GradeScore);

template <typename T>
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