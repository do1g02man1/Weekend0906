#pragma once

// 3���� �Ķ���͸� �޾� ��հ��� �����ϴ� �Լ� �����
float AvarageReturn(int Number1, int Number2, int Number3);

// ������ ������ �Է� �޾� ���ΰ� ���ϴ� �Լ� �����
float PriceReturn(float OriginPrice, float RatePrice);

// �ֻ����� ���� ����� �����ϴ� �Լ� �����
int PlayDice();

// ������ �ָ� ����(A~F)�� �ִ� �Լ� �����
int ReturnGradeScore(int GradeScore);

template <typename T>
// ���ø� �Լ��� Clamp �Լ� �����ϱ�
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