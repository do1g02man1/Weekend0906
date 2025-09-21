#pragma once

// ��ǥ ����ü
struct Position {
    int X;
    int Y;

    Position() = default;
    Position(int InX, int InY)
        : X(InX), Y(InY) {
    }
};

// ======================= BattleShip Ŭ���� =======================
class BattleShip {
public:
    BattleShip() = default;
    BattleShip(int Size)
        : Size(Size){ }

    void Place(Position Start, bool Horizontal);  // ��ǥ ��ġ
    bool IsHit(Position Pos);                     // ����
    bool IsSunk();
    int GetSize() const { return Size; }
    bool GetSunk() const { return Sunk; }
    Position GetPosition(int Index) const;


private:
    Position Positions[5]{};   // �ִ� ũ�� 5 (���� ū ��)
    bool Hits[5]{};            // �ǰ� ����
    int Size{};
    bool Sunk{};
};