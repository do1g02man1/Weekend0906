#pragma once
#include "BattleShip.h"

// ======================= Board 클래스 =======================
class Board : public BattleShip {
public:
    Board();

    void PlaceAllShips();                          // 모든 함선 랜덤 배치
    bool CanPlaceShip(Position Start, int Size, bool Horizontal) const;
    void PlaceShip(int Index, int Size);           // 특정 크기 배 배치
    bool Attack(Position Target);                  // 공격
    bool IsAllSunk() const;                        // 모든 격침 여부
    void Reveal(bool IsWin) const;                           // 모든 위치 공개
    void Display() const;                          // 플레이어에게 보여주는 맵
    bool AlreadyAttacked(Position Target) const;
    int GetTurnCount() const { return TurnCount; }

private:
    static const int ShipSize = 4;
    static const int ArraySize = 10;
    char RevealGrid[ArraySize][ArraySize];
    char Grid[ArraySize][ArraySize];            // '.' = 빈칸, 'O' = 빗나감, 'X' = 명중, 'S' = 배 위치
    bool AlreadyCounted[ShipSize]{ false };
    BattleShip BattleShips[ShipSize];           // 4척 배
    int ShipCount = 0;                          // 실제 배치된 함선 수
    int TurnCount = 2;                         // 남은 턴
};
