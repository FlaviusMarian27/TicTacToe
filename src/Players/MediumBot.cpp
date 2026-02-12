#include "Players/MediumBot.hpp"
#include <vector>

MediumBot::MediumBot(Cell symbol, std::string name) : m_symbol(symbol), m_name(name){
    if (m_symbol == Cell::X){
        m_opponentSymbol = Cell::O;
    }else{
        m_opponentSymbol = Cell::X;
    }
}

Move MediumBot::getMove(const sf::RenderWindow& window){
    return {-1,-1};
}

Move MediumBot::getSmartMove(Board& board){
    std::vector<Move> emptySpots;

    for (int row = 0; row < 3; row = row + 1){
        for (int col = 0; col < 3; col = col + 1){
            if (board.getCell(row, col) == Cell::Empty){
                //incearca sa castige
                if (board.isWinningMove(row,col,m_symbol)){
                    return {row,col};
                }

                //blocam adversarul
                if (board.isWinningMove(row,col,m_opponentSymbol)){
                    return {row,col};
                }

                emptySpots.push_back({row,col});
            }
        }
    }

    //daca nu ii ceva urgent punem random
    if (!emptySpots.empty()){
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, emptySpots.size()-1);
        return emptySpots[dis(gen)];
    }

    return {-1,-1};
}

Cell MediumBot::getSymbol() const{
    return m_symbol;
}

std::string MediumBot::getName() const{
    return m_name;
}
