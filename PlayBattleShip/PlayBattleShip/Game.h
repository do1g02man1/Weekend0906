#pragma once
#include "Board.h"
#include <stdio.h>
#include <iostream>

// ======================= Game 클래스 =======================
class Game : public Board {
public:
    Game() = default;

    void Start();                      // 게임 루프
    Position GetPlayerInput() const;   // 좌표 입력
     
private:
    Board MyBoard;
    int RemainingShots;
        
};
