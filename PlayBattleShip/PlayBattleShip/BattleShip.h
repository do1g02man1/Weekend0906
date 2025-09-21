#pragma once

// 좌표 구조체
struct Position {
    int X;
    int Y;

    Position() = default;
    Position(int InX, int InY)
        : X(InX), Y(InY) {
    }
};

// ======================= BattleShip 클래스 =======================
class BattleShip {
public:
    BattleShip() = default;
    BattleShip(int Size)
        : Size(Size){ }

    void Place(Position Start, bool Horizontal);  // 좌표 배치
    bool IsHit(Position Pos);                     // 공격
    bool IsSunk();
    int GetSize() const { return Size; }
    bool GetSunk() const { return Sunk; }
    Position GetPosition(int Index) const;


private:
    Position Positions[5]{};   // 최대 크기 5 (가장 큰 배)
    bool Hits[5]{};            // 피격 여부
    int Size{};
    bool Sunk{};
};