#pragma once
#include "Board.h"
#include <stdio.h>
#include <iostream>

// ======================= Game Ŭ���� =======================
class Game : public Board {
public:
    Game() = default;

    void Start();                      // ���� ����
    Position GetPlayerInput() const;   // ��ǥ �Է�
     
private:
    Board MyBoard;
    int RemainingShots;
        
};
