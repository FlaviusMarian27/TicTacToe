#include "Players/HardBot.hpp"
#include <algorithm>

HardBot::HardBot(Cell symbol, std::string name)
    : m_symbol(symbol), m_name(name){
    if (m_symbol == Cell::X){
        m_opponentSymbol = Cell::O;
    }else{
        m_opponentSymbol = Cell::X;
    }

    //m_opponentSymbol = (m_symbol == Cell::X) ? Cell::O : Cell::X;
}

Move HardBot::getMove(const sf::RenderWindow& window){
    return {-1,-1};
}

int HardBot::minimax(Board& board, int depth, bool isMaximize){
    Cell winner = board.checkWinner();
    if (winner == m_symbol){
        return 10 - depth; //castiga botul
    }

    if (winner == m_opponentSymbol){
        return depth - 10;
    }

    if (board.isFull()){
        return 0;
    }

    if (isMaximize){
        int bestScore = -1000;
        for (int row = 0; row < 3; row = row + 1){
            for (int column = 0; column < 3; column = column + 1){
                if (board.getCell(row, column) == Cell::Empty){
                    board.setCell(row, column, m_symbol);
                    int score = minimax(board, depth + 1, false);
                    board.setCell(row, column, Cell::Empty); //undo
                    bestScore = std::max(score,bestScore);
                }
            }
        }

        return bestScore;
    }else{
        int bestScore = 1000;
        for (int row = 0; row < 3; row = row + 1){
            for (int column = 0; column < 3; column = column + 1){
                if (board.getCell(row, column) == Cell::Empty){
                    board.setCell(row, column, m_opponentSymbol);
                    int score = minimax(board, depth + 1, true);
                    board.setCell(row, column, Cell::Empty);
                    bestScore = std::min(score,bestScore);
                }
            }
        }

        return bestScore;
    }
}

Move HardBot::getBestMove(Board& board){
    int bestScore = -1000;
    Move bestMove = {-1,-1};

    for (int row = 0; row < 3; row = row + 1){
        for (int column = 0; column < 3; column = column + 1){
            if (board.getCell(row, column) == Cell::Empty){
                board.setCell(row, column, m_symbol);
                int score = minimax(board,0,false);
                board.setCell(row, column, Cell::Empty);
                if (score > bestScore){
                    bestScore = score;
                    bestMove = {row, column};
                }
            }
        }
    }

    return bestMove;
}

Cell HardBot::getSymbol() const{
    return m_symbol;
}

std::string HardBot::getName() const{
    return m_name;
}
