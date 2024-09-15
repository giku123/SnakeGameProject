Snake.hpp
#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <vector>

// Structura Position reprezintă o poziție (x, y) în joc.
struct Position {
    int x;
    int y;
    
    // Constructor implicit.
    Position(int x = 0, int y = 0) : x(x), y(y) {}
};

// Clasa Snake va controla mișcarea și creșterea șarpelui.
class Snake {
private:
    std::vector<Position> body;  // Corpul șarpelui reprezentat de un vector de poziții.
    int direction;               // Direcția șarpelui (0 = sus, 1 = dreapta, 2 = jos, 3 = stânga).

public:
    Snake();                     // Constructor pentru inițializarea șarpelui.

    void move();                 // Mișcă șarpele în direcția curentă.
    void grow();                 // Crește lungimea șarpelui.
    void setDirection(int dir);  // Schimbă direcția șarpelui.
    
    const std::vector<Position>& getBody() const;  // Returnează corpul șarpelui.
    Position getHead() const;                      // Returnează capul șarpelui.

    bool checkCollision() const;  // Verifică coliziunea cu propriul corp.
};

#endif

Game.hpp
#ifndef GAME_HPP
#define GAME_HPP

#include "Snake.hpp"

// Clasa Game gestionează logica principală a jocului.
class Game {
private:
    Snake snake;             // Instanța șarpelui.
    Position fruit;          // Poziția fructului.
    int score;               // Scorul curent.
    int width, height;       // Dimensiunile hărții de joc.

public:
    Game(int width, int height);   // Constructor care inițializează jocul.
    
    void generateFruit();          // Generează un fruct la o poziție aleatorie.
    void update();                 // Actualizează starea jocului (mișcări, coliziuni, scor).
    bool isGameOver() const;       // Verifică dacă jocul s-a terminat.
    
    int getScore() const;          // Returnează scorul.
    const Snake& getSnake() const; // Returnează instanța șarpelui.
    const Position& getFruit() const;  // Returnează poziția fructului.
};

#endif


Utils.hpp
  #ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <chrono>
#include <thread>

// Funcție pentru curățarea ecranului.
inline void clearScreen() {
    #ifdef _WIN32
        system("cls");  // Pentru Windows.
    #else
        system("clear");  // Pentru Linux/Mac.
    #endif
}

// Funcție pentru așteptarea unui timp specificat (delay).
inline void wait(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

// Funcție pentru afișarea stării curente a jocului.
void printGameState(const Snake& snake, const Position& fruit, int score, int width, int height);

#endif


