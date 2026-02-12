#pragma once
#include "Constants.hpp"

class Board{
private:
    Cell m_grid[3][3];

public:
    Board();

    bool makeMove(int row, int column, Cell piece);
    void resetBoard();
    Cell checkWinner() const;
    bool isFull() const;
    Cell getCell(int row, int column) const;
    void setCell(int row, int column, Cell cell);

    //metoda pentru a verifica ar duce la victoria playerului
    bool isWinningMove(int row, int col, Cell piece);
};