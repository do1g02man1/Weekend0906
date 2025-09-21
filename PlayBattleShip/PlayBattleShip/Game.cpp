#include "Game.h"

void Game::Start()
{
	//BattleShip battleShip(5);
	//Position position(0, 0);

	//battleShip.Place(position, true);
	//battleShip.IsHit(GetPlayerInput()) ? printf("true") : printf("false");
	MyBoard.PlaceAllShips();
	MyBoard.Display();

	bool IsWin = false;
	while (MyBoard.GetTurnCount() != 0)
	{
		MyBoard.Attack(GetPlayerInput());
		MyBoard.Display();
		
		if (MyBoard.IsAllSunk()) {
			IsWin = true;
			break;
		}
	}
	MyBoard.Reveal(IsWin);
}

Position Game::GetPlayerInput() const
{
	int InX, InY;
	printf("공격할 좌표를 입력해주세요 (x , y) : ");
	std::cin >> InX >> InY;
	return Position(InX, InY);
}
