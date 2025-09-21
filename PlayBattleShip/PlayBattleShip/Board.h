#pragma once
#include "BattleShip.h"

// ======================= Board Ŭ���� =======================
class Board : public BattleShip {
public:
    Board();

    void PlaceAllShips();                          // ��� �Լ� ���� ��ġ
    bool CanPlaceShip(Position Start, int Size, bool Horizontal) const;
    void PlaceShip(int Index, int Size);           // Ư�� ũ�� �� ��ġ
    bool Attack(Position Target);                  // ����
    bool IsAllSunk() const;                        // ��� ��ħ ����
    void Reveal(bool IsWin) const;                           // ��� ��ġ ����
    void Display() const;                          // �÷��̾�� �����ִ� ��
    bool AlreadyAttacked(Position Target) const;
    int GetTurnCount() const { return TurnCount; }

private:
    static const int ShipSize = 4;
    static const int ArraySize = 10;
    char RevealGrid[ArraySize][ArraySize];
    char Grid[ArraySize][ArraySize];            // '.' = ��ĭ, 'O' = ������, 'X' = ����, 'S' = �� ��ġ
    bool AlreadyCounted[ShipSize]{ false };
    BattleShip BattleShips[ShipSize];           // 4ô ��
    int ShipCount = 0;                          // ���� ��ġ�� �Լ� ��
    int TurnCount = 2;                         // ���� ��
};
