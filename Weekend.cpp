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
        printf("당신의 학점은 A입니다.\n\n");
        break;
    case 8:
        printf("당신의 학점은 B입니다.\n\n");
        break;
    case 7:
        printf("당신의 학점은 C입니다.\n\n");
        break;
    case 6:
        printf("당신의 학점은 D입니다.\n\n");
        break;
    default:
        printf("당신의 학점은 F입니다.\n\n");
        break;
    }

    return GradeScore;
}
