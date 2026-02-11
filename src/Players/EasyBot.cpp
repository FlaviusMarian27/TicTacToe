#include "Players/EasyBot.hpp"
#include <vector>

EasyBot::EasyBot(Cell symbol, std::string name)
    : m_symbol(symbol), m_name(name){}

Move EasyBot::getMove(const sf::RenderWindow& window){
    return {-1,-1};
}

Move EasyBot::getMoveFromBoard(const Board& board){
    std::vector<Move> availableMoves;

    for (int row = 0; row < 3; row = row + 1){
        for (int col = 0; col < 3; col = col + 1){
            if (board.getCell(row,col) == Cell::Empty){
                availableMoves.push_back({row,col});
            }
        }
    }

    if (availableMoves.empty()){
        return {-1,-1};
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, availableMoves.size() - 1);

    return availableMoves[dis(gen)];
}

Cell EasyBot::getSymbol() const{
    return m_symbol;
}

std::string EasyBot::getName() const{
    return m_name;
}