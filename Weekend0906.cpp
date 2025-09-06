
#include <iostream>
#include "Weekend.h"

int main()
{
	// 3개의 파라메터를 받아 평균값을 리턴하는 함수 만들기
	int Number1, Number2, Number3;

	printf("숫자 세개를 입력해주세요 : ");
	std::cin >> Number1 >> Number2 >> Number3;
	printf("\n평균값 : %.2f\n\n", AvarageReturn(Number1, Number2, Number3));

	printf("----------------------------------------------------------\n\n");
	
	float OriginPrice, RatePrice;

	printf("물건의 정가와 할인율을 입력해 주세요 : ");
	std::cin >> OriginPrice >> RatePrice;
	printf("\n물건의 할인가는 : %.2f원 입니다.\n\n", PriceReturn(OriginPrice, RatePrice));

	printf("----------------------------------------------------------\n\n");

	printf("주사위를 굴린 결과는 %d입니다.\n\n", PlayDice());

	printf("----------------------------------------------------------\n\n");

	int InputScore;

	printf("성적을 입력해 주세요 : ");
	std::cin >> InputScore;

	if (InputScore > 100 || InputScore < 0) {
		printf("점수를 잘못 입력하셨습니다.\n\n");
		printf("0 ~ 100사이의 점수를 입력해주세요.\n\n");
	}
	else { 
		ReturnGradeScore(InputScore);
	}
	
	printf("----------------------------------------------------------\n\n");

	int InputValue, InputMin, InputMax;

	
	printf("Value, Min, Max의 값을 입력해 주세요 : ");
	std::cin >> InputValue >> InputMin >> InputMax;
	
	Clamp(InputValue, InputMin, InputMax);
	

	return 0;
}
