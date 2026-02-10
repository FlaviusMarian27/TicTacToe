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
TicTacToe/
├── include/              <-- Aici pui doar "CUPRINSUL" (ce funcții/clase avem)
│   ├── Board.hpp         # Regulile: "X aici, O acolo, cine a câștigat?"
│   ├── Renderer.hpp      # Desenul: "Cum desenez un cerc sau un X?"
│   ├── Player.hpp        # Jucătorii: Interfața comună (Om sau Bot)
│   └── GameEngine.hpp    # Șeful: Dirijează traficul între cele de mai sus
│
├── src/                  <-- Aici pui "POVESTEA" (codul propriu-zis)
│   ├── Board.cpp
│   ├── Renderer.cpp
│   ├── Player.cpp
│   ├── GameEngine.cpp
│   └── main.cpp          # Butonul de ON: Doar 3 linii de cod care pornesc totul
│
└── CMakeLists.txt        # Rețeta: Îi spune lui CLion cum să asambleze totul
```