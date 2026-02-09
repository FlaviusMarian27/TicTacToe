# 🎮 Tic-Tac-Toe (C++)

O implementare clasică a jocului **X și 0**, scrisă în C++ modern. Proiectul demonstrează utilizarea principiilor **OOP** (Programare Orientată pe Obiecte).

### ✨ Caracteristici
* **Arhitectură Modulară:** Clase separate pentru Tabla de joc, Jucător și Logică.
* **Polimorfism:** Suportă extinderea ușoară a tipurilor de jucători (ex: AI).
* **Interfață:** Linie de comandă (CLI) curată și intuitivă.

### 🛠️ Tehnologii
* C++
* CMake" > README.md

```text
TicTacToe-Pro/
├── CMakeLists.txt                # Creierul compilării (configurarea SFML)
├── include/                      # Toate fișierele .hpp (interfețe)
│   ├── Core/
│   │   ├── Board.hpp             # Logica tablei (matricea jocului)
│   │   ├── GameEngine.hpp        # Controller-ul (state machine-ul jocului)
│   │   └── Constants.hpp         # Enum-uri (X, O, Empty) și setări de culori
│   ├── Players/
│   │   ├── Player.hpp            # Interfața de bază (clasă abstractă)
│   │   ├── HumanPlayer.hpp       # Jucător controlat prin input (click)
│   │   ├── AIPlayer.hpp          # AI Easy (Random) și Hard (Minimax)
│   │   └── NetworkPlayer.hpp     # Jucător pentru multiplayer (socket-uri)
│   └── Graphics/
│       └── Renderer.hpp          # Randarea jocului folosind SFML
├── src/                          # Implementările (.cpp)
│   ├── Core/                     # Board.cpp, GameEngine.cpp
│   ├── Players/                  # HumanPlayer, AIPlayer, NetworkPlayer
│   ├── Graphics/                 # Renderer.cpp
│   └── main.cpp                  # Punctul de start (inițializează jocul)
├── assets/                       # Resurse externe
│   ├── fonts/                    # Fonturi (.ttf) pentru UI, scor, meniu
│   └── textures/                 # Texturi pentru fundal sau X/O (opțional)
└── build/                        # Folder generat automat (executabilul)
```