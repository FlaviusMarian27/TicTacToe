#pragma once

//starea unei celule
enum class Cell{
    Empty,
    X,
    O
};

//dimensiunea pentru interfata
const int WINDOW_SIZE = 600;
const int CELL_SIZE = WINDOW_SIZE / 3;