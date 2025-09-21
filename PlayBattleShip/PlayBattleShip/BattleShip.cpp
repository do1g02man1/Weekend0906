#include "BattleShip.h"
#include <stdio.h>

void BattleShip::Place(Position Start, bool Horizontal)
{
	if (Horizontal == true)
	{
		for (int i = 0; i < Size; i++)
		{
			Positions[i].X = Start.X + i;
			Positions[i].Y = Start.Y;
			Hits[i] = false;
		}
	}
	else
	{
		for (int i = 0; i < Size; i++)
		{
			Positions[i].X = Start.X;
			Positions[i].Y = Start.Y + i;
			Hits[i] = false;
		}
	}
	Sunk = false;
}

bool BattleShip::IsHit(Position Pos)
{
	for (int i = 0; i < Size; i++)
	{
		if (Positions[i].X == Pos.X)
		{
			if (Positions[i].Y == Pos.Y)
			{
				printf("Hit!\n");
				Hits[i] = true;
				if (IsSunk() == true)
				{
					printf("¹è Ä§¸ô!\n");
				}
				return true;
			}
		}
	}

	return false;
}

bool BattleShip::IsSunk()
{
	for (int i = 0; i < Size; i++)
	{
		if (Hits[i] == false)
		{
			return false;
		}
	}

	Sunk = true;
	return true;
}

Position BattleShip::GetPosition(int Index) const
{
	if (Index >= 0 && Index < Size)
		return Positions[Index];

	return Position(-1, -1);  
}
