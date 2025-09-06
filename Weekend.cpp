#include "Weekend.h"
#include <time.h>
#include <cstdlib>
#include <stdio.h>
#include <iostream>

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

void ReturnGradeScore(int GradeScore)
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
}

int DevideNumber(int InputNumber)
{
    int SumInputNumber = 0;

    while (InputNumber != 0) {
        SumInputNumber += (InputNumber % 10);
        InputNumber /= 10;
    }

    return SumInputNumber;
}

void DecimalToBinary(int InputDecimal)
{
    if (InputDecimal == 0 || InputDecimal == 1)
        printf("%d ", InputDecimal);

    else {
        DecimalToBinary(InputDecimal / 2);
        printf("%d ", InputDecimal % 2);
    }
}

// 슬롯 머신 게임 만들기
// 시작 금액 10000
// 한판에 무조건 최소 100 배팅해야 함. 만약 소지금액이 100 이하일 경우 게임 종료.
// 같은 숫자 3개가 나오면 50배로 돌려 받는다.
// 만약 777이면 10000배 받음
void SlotMachine()
{
    const int MinBettingMoney = 100;
    int PlayerMoney = 10000, BettingMoney;
    int Slot1, Slot2, Slot3;

    srand(time(0));
    while (PlayerMoney > MinBettingMoney) {
        do {            
            printf("\n\n플레이어의 소지 금액 : %d\n", PlayerMoney);
            printf("베팅을 해 주세요. (최소 금액 100원) : ");
            std::cin >> BettingMoney;
        } while (PlayerMoney < BettingMoney || BettingMoney < 100);
        PlayerMoney -= BettingMoney;

        Slot1 = rand() % 10;
        Slot2 = rand() % 10;
        Slot3 = rand() % 10;
        
        printf("룰렛 결과 : %d %d %d ", Slot1, Slot2, Slot3);

        if (Slot1 == 7 && Slot2 == 7 && Slot3 == 7) {
            printf("$$$ 잭팟입니다! 베팅 금액의 10000배를 받습니다! $$$\n\n");
            PlayerMoney = BettingMoney * 10000;
        }
        else if ((Slot1 == Slot2) && (Slot1 == Slot3)) {
            printf("당첨입니다! 베팅 금액의 50배를 받습니다!\n\n");
            PlayerMoney = BettingMoney * 50;
        }
    }
    printf("\n\n플레이어의 소지 금액 : %d\n", PlayerMoney);
}

// 플레이어와 적의 턴제 전투 만들기
// HP는 100으로 시작
// 공격을 할 때 상대방에게 5~15의 데미지를 준다.
// 10 % 의 확률로 크리티컬이 발생해 2배의 데미지를 준다.
// 상대방의 HP가 0 이하가 되면 승리한다.
void TurnBasedGame()
{
    int PlayerHealth = 100, EnemyHealth = 100;
    int PlayerAttack, EnemyAttack;
    int PlayerCritical, EnemyCritical;
    int TurnCount = 1;
    
    srand(time(0));
    while (PlayerHealth > 0 && EnemyHealth > 0) {
        PlayerAttack = (rand() % 11) + 5;
        EnemyAttack = (rand() % 11) + 5;

        PlayerCritical = rand() % 10;
        EnemyCritical = rand() % 10;

        printf("○ 플레이어의 턴입니다.\n");
        if (PlayerCritical == 0) {
            printf("");
            EnemyHealth -= PlayerAttack * 2;
            printf("Critical! %d 데미지를 가했습니다.\n\n", PlayerAttack * 2);
        }
        else {
            printf("%d 데미지를 가했습니다.\n\n", PlayerAttack);
            EnemyHealth -= PlayerAttack;
        }

        if (EnemyHealth <= 0) {
            printf("플레이어의 남은 체력 : %d\n몬스터의 남은 체력 : %d\n\n", PlayerHealth, EnemyHealth);
            break;
        }
        
        printf("● 몬스터의 턴입니다.\n");
        if (EnemyCritical == 0) {
            printf("Critical! %d 데미지를 가했습니다.\n\n", EnemyAttack * 2);
            PlayerHealth -= EnemyAttack * 2;
        }
        else {
            printf("%d 데미지를 가했습니다.\n\n", EnemyAttack);
            PlayerHealth -= EnemyAttack;
        }

        printf("플레이어의 남은 체력 : %d\n몬스터의 남은 체력 : %d\n\n", PlayerHealth, EnemyHealth);
    }

    if (PlayerHealth > 0) {
        printf("플레이어의 승리입니다!\n\n");
    }
    else {
        printf("몬스터의 승리입니다 . . .\n\n");
    }
}

// 도둑 잡기 만들기
// 시작 금액 10000
// 한판에 무조건 최소 100 배팅해야 함.만약 소지금액이 100 이하일 경우 게임 종료.
// 딜러는 A~K까지의 트럼프 카드 중 2장을 중복없이 선택하고 조커 카드가 추가된다.
// 플레이어는 딜러의 카드 중 한장을 선택한다.
// 만약 플레이어가 조커를 뽑있다면 플레이어의 승리.배팅 금액의 2배를 받는다.
// 플레이어가 조커를 뽑지 못했다면 다음 게임을 시작하거나 배팅 금액의 2배를 추가로 지불하고 한번 더 선택할 수 있다.
void PickJoker()
{
    const int MinBettingMoney = 100;
    int UserInput, GetJoker;
    int PlayerMoney = 10000, BettingMoney;
    int DealerCardFirst, DealerCardSecond, DealerCardThird;

    srand(time(0));
    while (PlayerMoney > MinBettingMoney) {
        do {
            printf("\n\n플레이어의 소지 금액 : %d\n", PlayerMoney);
            printf("베팅을 해 주세요. (최소 금액 100원) : ");
            std::cin >> BettingMoney;
        } while (PlayerMoney < BettingMoney || BettingMoney < 100);
        PlayerMoney -= BettingMoney;

        GetJoker = rand() % 3 + 1;
        switch (GetJoker) {
        case 1:
            DealerCardFirst = 14;
            DealerCardSecond = rand() % 13 + 1;
            do {
                DealerCardThird = rand() % 13 + 1;
            } while (DealerCardSecond == DealerCardThird);
            break;
        case 2:
            DealerCardFirst = rand() % 13 + 1;
            DealerCardSecond = 14;
            do {
                DealerCardThird = rand() % 13 + 1;
            } while (DealerCardFirst == DealerCardThird);
            break;
        case 3:
            DealerCardFirst = rand() % 13 + 1;
            do {
                DealerCardSecond = rand() % 13 + 1;
            } while (DealerCardFirst == DealerCardSecond);
            DealerCardThird = 14;
            break;
        }

        printf("\n딜러의 카드 [1] | [2] | [3] 중에 하나를 선택해 주세요. ");
        std::cin >> UserInput;

        if (GetJoker == UserInput) {
            printf("\n플레이어가 승리했습니다. 베팅 금액의 2배를 받습니다.\n\n");
            PlayerMoney += BettingMoney * 2;
        }
        else if (PlayerMoney > BettingMoney * 2) {
            printf("\n플레이어가 패배했습니다 . . . 베팅 금액의 2배를 내고 한번 더 하시겠습니까? [1] 예 [2] 아니오 ");
            std::cin >> UserInput;
            if (UserInput == 1) {
                PlayerMoney -= BettingMoney * 2;
                printf("\n\n딜러의 카드 [1] | [2] 중에 하나를 선택해 주세요. ");
                std::cin >> UserInput;

                GetJoker = rand() % 2 + 1;
                switch (GetJoker) {
                case 1:
                    DealerCardFirst = 14;
                    DealerCardSecond = rand() % 13 + 1;
                case 2:
                    DealerCardFirst = rand() % 13 + 1;
                    DealerCardSecond = 14;
                    break;
                }
                
                if (GetJoker == UserInput) {
                    printf("\n플레이어가 승리했습니다. 베팅 금액의 2배를 받습니다.\n\n");
                    PlayerMoney += BettingMoney * 2;
                }
                else {
                    printf("\n플레이어가 패배했습니다 . . .\n\n");
                }
            } 
        }
        else {
            printf("\n플레이어가 패배했습니다 . . .\n\n");
        }
    }
}


