#include "Board.h"
#include <stdio.h>
#include <cstdlib>
#include <time.h>

Board::Board()
{
	for (int x = 0; x < ArraySize; x++)
	{
		for (int y = 0; y < ArraySize; y++)
		{
			Grid[y][x] = '.';
			RevealGrid[y][x] = '.';
		}
	}

	BattleShips[0] = BattleShip(5); 
	BattleShips[1] = BattleShip(4); 
	BattleShips[2] = BattleShip(3); 
	BattleShips[3] = BattleShip(2); 
}

void Board::PlaceAllShips()
{
	for (int i = 0; i < ShipSize; i++)
	{
		PlaceShip(i, BattleShips[i].GetSize());
		ShipCount++;
	}
}

bool Board::CanPlaceShip(Position Start, int Size, bool Horizontal) const
{
	int X, Y;

	if (Horizontal)
	{
		if (Start.X + Size > ArraySize)
		{
			return false;
		}
	}
	else
	{
		if (Start.Y + Size > ArraySize)
		{
			return false;
		}
	}

	for (int i = 0; i < Size; i++)
	{
		X = Horizontal ? Start.X + i : Start.X;
		Y = Horizontal ? Start.Y : Start.Y + i;

		if (Grid[Y][X] != '.')
		{
			return false;
		}
	}

	return true;
}

void Board::PlaceShip(int Index, int Size)
{
	srand(time(0));
	Position Start{};
	bool CanHorizontal = false;
	bool CanVertical = false;
	bool Direction = false;
	int X = 0;
	int Y = 0;

	do
	{
		X = rand() % 10;
		Y = rand() % 10;

		Start = Position(X, Y);
		CanHorizontal = CanPlaceShip(Start, Size, true);
		CanVertical = CanPlaceShip(Start, Size, false);
	} while ((CanHorizontal != true) && (CanVertical != true));	// �� ��ġ�� �� ���� �� �ϳ��� �������� �ʴ´ٸ� �ݺ�

	if ((CanHorizontal == true) && (CanVertical == true))	// �谡 �� ���� ��� ������ �� �������� �� ���� �� ����
	{
		Direction = rand() % 2;
	}
	else if (CanHorizontal == true)
	{
		Direction = true;
	}
	BattleShips[Index].Place(Start, Direction);

	for (int i = 0; i < Size; i++)
	{
		X = Direction? Start.X + i : Start.X;
		Y = Direction? Start.Y : Start.Y + i;
		Grid[Y][X] = 'S';
		RevealGrid[Y][X] = 'S';
	}
}

bool Board::Attack(Position Target)
{
	int X = Target.X;
	int Y = Target.Y;

	if (AlreadyAttacked(Target))
	{
		printf("�̹� ������ ���Դϴ�.\n");
		return false;
	}

	bool Hit = false;

	for (int i = 0; i < ShipSize; i++)
	{
		if (BattleShips[i].IsHit(Target))
		{
			Hit = true;
			if (BattleShips[i].IsSunk() && !AlreadyCounted[i])
			{
				ShipCount--;
				AlreadyCounted[i] = true;
			}
			break;
		}
	}

	if (Hit)
		Grid[Y][X] = 'X';
	else
		Grid[Y][X] = 'O';

	TurnCount--;
	return Hit;
}

bool Board::IsAllSunk() const
{
	for (int i = 0; i < ShipSize; i++)
	{
		if (BattleShips[i].GetSunk() == false)
		{
			return false;
		}
	}
	return true;
}

void Board::Reveal(bool IsWin) const
{
	printf("   0  1  2  3  4  5  6  7  8  9\n");
	for (int x = 0; x < ArraySize; x++)
	{
		printf("%d  ", x);
		for (int y = 0; y < ArraySize; y++)
		{
			printf("%c  ", RevealGrid[y][x]);
		}
		printf("\n");
	}

	if (IsWin)
	{
		printf("�¸��ϼ̽��ϴ� ! ! !\n");
	}
	else
	{
		printf("�й��ϼ̽��ϴ� . . .\n");
	}
}

void Board::Display() const
{
	printf("   0  1  2  3  4  5  6  7  8  9\n");
	for (int X = 0; X < ArraySize; X++)
	{
		printf("%d  ", X);
		for (int Y = 0; Y < ArraySize; Y++)
		{
			if (Grid[Y][X] == 'X')
			{
				printf("X  ");
			}
			else if (Grid[Y][X] == 'O')
			{
				printf("O  ");
			}
			//else if (Grid[Y][X] == 'S')	// ����׿�
			//{
			//	printf("S  ");
			//}	
			else
			{
				printf(".  ");
			}
		}
		printf("\n");
	}
	printf("���� �� : %d\n", TurnCount);
	printf("���� ���� �� : %d ��\n", ShipCount);
}

bool Board::AlreadyAttacked(Position Target) const
{
	int X = Target.X;
	int Y = Target.Y;

	return Grid[Y][X] == 'O' || Grid[Y][X] == 'X';
}
