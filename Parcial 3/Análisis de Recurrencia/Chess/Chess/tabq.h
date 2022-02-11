#pragma once
#include "piece.h"

class Board {
private:
    char** elements;
    int dim;

public:
    Board() = default;
    Board(int dim);
    Board(Board& g);

    int getDim();
    char** getElements();
    char getij(int i, int j);
    void setElements(int i, int j, char key);

    void drawPiece(Piece piece);
    void printBoard();
    void drawMovements(Piece piece);
    void createAttackBoard(Piece a, Piece b);
    static bool analyzeTwoPieces(Board A, Board B);
    static int calculateRowAtack(Board a, Board b);
    static int calculateColumnAtack(Board a, Board b);
    // void connect(int from, int to, int key);
    // void connect(int from, int to);
};

