#pragma once
class Piece {
private:
    int row;
    int column;
    char name;
public:
    Piece() = default;
    int getColumn();
    void setColumn(int c);
    int getRow();
    void setRow(int r);
    char getName();
    void createQueen(char name, int r, int c);
    void createKing(char name, int r, int c);
    void createHorse(char name, int r, int c);
    void createBishop(char name, int r, int c);
    void createTower(char name, int r, int c);
    void createPawn(char name, int r, int c);
    void moveQueen(int numberStep, int direction);
    void moveKing(int direction);
    void moveHorse(int direction);
    void moveBishop(int numberStep, int direction);
    void moveTower(int numberStep, int direction);
    void movePawn(int direction);
    void moveAtackPawn(int direction);
};

