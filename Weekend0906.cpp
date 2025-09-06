
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
	
	// 정가와 할인율 입력 받아 할인가 구하는 함수 만들기
	float OriginPrice, RatePrice;

	printf("물건의 정가와 할인율을 입력해 주세요 : ");
	std::cin >> OriginPrice >> RatePrice;
	printf("\n물건의 할인가는 : %.2f원 입니다.\n\n", PriceReturn(OriginPrice, RatePrice));

	printf("----------------------------------------------------------\n\n");

	// 주사위를 굴린 결과를 리턴하는 함수 만들기
	printf("주사위를 굴린 결과는 %d입니다.\n\n", PlayDice());

	printf("----------------------------------------------------------\n\n");

	// 점수를 주면 성적(A~F)를 주는 함수 만들기
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
	
	//printf("----------------------------------------------------------\n\n");

	// 템플릿 함수로 Clamp 함수 구현하기
	int InputValue, InputMin, InputMax;
	
	printf("Value, Min, Max의 값을 입력해 주세요 : ");
	std::cin >> InputValue >> InputMin >> InputMax;
	
	Clamp(InputValue, InputMin, InputMax);
	
	// 각 자리의 수를 합해서 출력하기
	int UserInput;
	
	printf("자리수를 분리할 숫자를 입력해 주세요 : ");
	std::cin >> UserInput;

	printf("\n자리수의 총 합은 : %d입니다.\n\n", DevideNumber(UserInput));

	printf("----------------------------------------------------------\n\n");

	// 재귀 함수를 이용하여 10진수를 입력받아 2진수로 출력하는 함수 만들기
	int InputDecimal;

	printf("10진수를 입력해 주세요 : ");
	std::cin >> InputDecimal;

	DecimalToBinary(InputDecimal);
	printf("\n\n");

	printf("----------------------------------------------------------\n\n");

	// 슬롯 머신 게임 만들기
	// 시작 금액 10000
	// 한판에 무조건  최소 100 배팅해야 함.만약 소지금액이 100 이하일 경우 게임 종료.
	// 같은 숫자 3개가 나오면 50배로 돌려 받는다.
	// 만약 777이면 10000배 받음
	SlotMachine();
	
	printf("----------------------------------------------------------\n\n");

	// 플레이어와 적의 턴제 전투 만들기
	// HP는 100으로 시작
	// 공격을 할 때 상대방에게 5~15의 데미지를 준다.
	// 10 % 의 확률로 크리티컬이 발생해 2배의 데미지를 준다.
	// 상대방의 HP가 0 이하가 되면 승리한다.
	TurnBasedGame();

	printf("----------------------------------------------------------\n\n");

	// 도둑 잡기 만들기
	// 시작 금액 10000
	// 한판에 무조건 최소 100 배팅해야 함.만약 소지금액이 100 이하일 경우 게임 종료.
	// 딜러는 A~K까지의 트럼프 카드 중 2장을 중복없이 선택하고 조커 카드가 추가된다.
	// 플레이어는 딜러의 카드 중 한장을 선택한다.
	// 만약 플레이어가 조커를 뽑있다면 플레이어의 승리.배팅 금액의 2배를 받는다.
	// 플레이어가 조커를 뽑지 못했다면 다음 게임을 시작하거나 배팅 금액의 2배를 추가로 지불하고 한번 더 선택할 수 있다.
	PickJoker();

	return 0;
}
