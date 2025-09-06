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

// ���� �ӽ� ���� �����
// ���� �ݾ� 10000
// ���ǿ� ������ �ּ� 100 �����ؾ� ��. ���� �����ݾ��� 100 ������ ��� ���� ����.
// ���� ���� 3���� ������ 50��� ���� �޴´�.
// ���� 777�̸� 10000�� ����
void SlotMachine()
{
    const int MinBettingMoney = 100;
    int PlayerMoney = 10000, BettingMoney;
    int Slot1, Slot2, Slot3;

    srand(time(0));
    while (PlayerMoney > MinBettingMoney) {
        do {            
            printf("\n\n�÷��̾��� ���� �ݾ� : %d\n", PlayerMoney);
            printf("������ �� �ּ���. (�ּ� �ݾ� 100��) : ");
            std::cin >> BettingMoney;
        } while (PlayerMoney < BettingMoney || BettingMoney < 100);
        PlayerMoney -= BettingMoney;

        Slot1 = rand() % 10;
        Slot2 = rand() % 10;
        Slot3 = rand() % 10;
        
        printf("�귿 ��� : %d %d %d ", Slot1, Slot2, Slot3);

        if (Slot1 == 7 && Slot2 == 7 && Slot3 == 7) {
            printf("$$$ �����Դϴ�! ���� �ݾ��� 10000�踦 �޽��ϴ�! $$$\n\n");
            PlayerMoney = BettingMoney * 10000;
        }
        else if ((Slot1 == Slot2) && (Slot1 == Slot3)) {
            printf("��÷�Դϴ�! ���� �ݾ��� 50�踦 �޽��ϴ�!\n\n");
            PlayerMoney = BettingMoney * 50;
        }
    }
    printf("\n\n�÷��̾��� ���� �ݾ� : %d\n", PlayerMoney);
}

// �÷��̾�� ���� ���� ���� �����
// HP�� 100���� ����
// ������ �� �� ���濡�� 5~15�� �������� �ش�.
// 10 % �� Ȯ���� ũ��Ƽ���� �߻��� 2���� �������� �ش�.
// ������ HP�� 0 ���ϰ� �Ǹ� �¸��Ѵ�.
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

        printf("�� �÷��̾��� ���Դϴ�.\n");
        if (PlayerCritical == 0) {
            printf("");
            EnemyHealth -= PlayerAttack * 2;
            printf("Critical! %d �������� ���߽��ϴ�.\n\n", PlayerAttack * 2);
        }
        else {
            printf("%d �������� ���߽��ϴ�.\n\n", PlayerAttack);
            EnemyHealth -= PlayerAttack;
        }

        if (EnemyHealth <= 0) {
            printf("�÷��̾��� ���� ü�� : %d\n������ ���� ü�� : %d\n\n", PlayerHealth, EnemyHealth);
            break;
        }
        
        printf("�� ������ ���Դϴ�.\n");
        if (EnemyCritical == 0) {
            printf("Critical! %d �������� ���߽��ϴ�.\n\n", EnemyAttack * 2);
            PlayerHealth -= EnemyAttack * 2;
        }
        else {
            printf("%d �������� ���߽��ϴ�.\n\n", EnemyAttack);
            PlayerHealth -= EnemyAttack;
        }

        printf("�÷��̾��� ���� ü�� : %d\n������ ���� ü�� : %d\n\n", PlayerHealth, EnemyHealth);
    }

    if (PlayerHealth > 0) {
        printf("�÷��̾��� �¸��Դϴ�!\n\n");
    }
    else {
        printf("������ �¸��Դϴ� . . .\n\n");
    }
}

// ���� ��� �����
// ���� �ݾ� 10000
// ���ǿ� ������ �ּ� 100 �����ؾ� ��.���� �����ݾ��� 100 ������ ��� ���� ����.
// ������ A~K������ Ʈ���� ī�� �� 2���� �ߺ����� �����ϰ� ��Ŀ ī�尡 �߰��ȴ�.
// �÷��̾�� ������ ī�� �� ������ �����Ѵ�.
// ���� �÷��̾ ��Ŀ�� ���ִٸ� �÷��̾��� �¸�.���� �ݾ��� 2�踦 �޴´�.
// �÷��̾ ��Ŀ�� ���� ���ߴٸ� ���� ������ �����ϰų� ���� �ݾ��� 2�踦 �߰��� �����ϰ� �ѹ� �� ������ �� �ִ�.
void PickJoker()
{
    const int MinBettingMoney = 100;
    int UserInput, GetJoker;
    int PlayerMoney = 10000, BettingMoney;
    int DealerCardFirst, DealerCardSecond, DealerCardThird;

    srand(time(0));
    while (PlayerMoney > MinBettingMoney) {
        do {
            printf("\n\n�÷��̾��� ���� �ݾ� : %d\n", PlayerMoney);
            printf("������ �� �ּ���. (�ּ� �ݾ� 100��) : ");
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

        printf("\n������ ī�� [1] | [2] | [3] �߿� �ϳ��� ������ �ּ���. ");
        std::cin >> UserInput;

        if (GetJoker == UserInput) {
            printf("\n�÷��̾ �¸��߽��ϴ�. ���� �ݾ��� 2�踦 �޽��ϴ�.\n\n");
            PlayerMoney += BettingMoney * 2;
        }
        else if (PlayerMoney > BettingMoney * 2) {
            printf("\n�÷��̾ �й��߽��ϴ� . . . ���� �ݾ��� 2�踦 ���� �ѹ� �� �Ͻðڽ��ϱ�? [1] �� [2] �ƴϿ� ");
            std::cin >> UserInput;
            if (UserInput == 1) {
                PlayerMoney -= BettingMoney * 2;
                printf("\n\n������ ī�� [1] | [2] �߿� �ϳ��� ������ �ּ���. ");
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
                    printf("\n�÷��̾ �¸��߽��ϴ�. ���� �ݾ��� 2�踦 �޽��ϴ�.\n\n");
                    PlayerMoney += BettingMoney * 2;
                }
                else {
                    printf("\n�÷��̾ �й��߽��ϴ� . . .\n\n");
                }
            } 
        }
        else {
            printf("\n�÷��̾ �й��߽��ϴ� . . .\n\n");
        }
    }
}


