#include "Core/Board.hpp"

Board::Board(){
    resetBoard();
}

void Board::resetBoard(){
    for (int row = 0; row < 3; row = row + 1){
        for (int column = 0; column < 3; column = column + 1){
            m_grid[row][column] = Cell::Empty;
        }
    }
}

bool Board::makeMove(int row, int column, Cell piece){
    if (row < 0 || row >= 3 || column < 0 || column >= 3 || m_grid[row][column] != Cell::Empty){
        return false;
    }
    m_grid[row][column] = piece;

    return true;
}

Cell Board::checkWinner() const{
    for (int row = 0; row < 3; row = row + 1){
        //pentru linii
        if (m_grid[row][0] != Cell::Empty &&
            m_grid[row][0] == m_grid[row][1] &&
            m_grid[row][0] == m_grid[row][2]){
            return m_grid[row][0];
        }

        //pentru coloane
        if (m_grid[0][row] != Cell::Empty &&
            m_grid[0][row] == m_grid[1][row] &&
            m_grid[0][row] == m_grid[2][row]){
            return m_grid[0][row];
        }
    }

    //pentru diagonala principala
    if (m_grid[0][0] != Cell::Empty &&
        m_grid[0][0] == m_grid[1][1] &&
        m_grid[0][0] == m_grid[2][2]){
        return m_grid[0][0];
    }

    //pentru diagonala secundara
    if (m_grid[2][0] != Cell::Empty &&
        m_grid[2][0] == m_grid[1][2] &&
        m_grid[2][0] == m_grid[0][2]){
        return m_grid[2][0];s
    }

    return Cell::Empty;
}

bool Board::isFull() const{
    for (int row = 0; row < 3; row = row + 1){
        for (int column = 0; column < 3; column = column + 1){
            if (m_grid[row][column] == Cell::Empty){
                return false;
            }
        }
    }

    return true;
}

Cell Board::getCell(int row, int column) const{
    return m_grid[row][column];
}