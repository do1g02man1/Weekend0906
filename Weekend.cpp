#include "Weekend.h"
#include <time.h>
#include <cstdlib>
#include <stdio.h>

float AvarageReturn(int Number1, int Number2, int Number3)
{

	return (Number1 + Number2 + Number3) / 3.f;
}

float PriceReturn(float OriginPrice, float RatePrice)
{
	
	return (OriginPrice / 100) * (100.0f - RatePrice);
}

int PlayDice()
{
	const int DiceScale = 6;
	srand(time(0));
	
	return rand() % DiceScale + 1;
}

int ReturnGradeScore(int GradeScore)
{

    switch (GradeScore / 10) {
    case 10:
    case 9:
        printf("����� ������ A�Դϴ�.\n\n");
        break;
    case 8:
        printf("����� ������ B�Դϴ�.\n\n");
        break;
    case 7:
        printf("����� ������ C�Դϴ�.\n\n");
        break;
    case 6:
        printf("����� ������ D�Դϴ�.\n\n");
        break;
    default:
        printf("����� ������ F�Դϴ�.\n\n");
        break;
    }

    return GradeScore;
}
