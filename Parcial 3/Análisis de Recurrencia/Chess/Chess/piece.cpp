#include "piece.h"

void Piece::setColumn(int c) {
    this->column = c;
}

int Piece::getColumn() {
    return this->column;
}

void Piece::setRow(int r) {
    this->row = r;
}

int Piece::getRow() {
    return this->row;
}

char Piece::getName() {
    return this->name;
}

void Piece::createTower(char name, int r, int c) {
    this->name = name;
    setRow(r);
    setColumn(c);
}

void Piece::moveTower(int ns, int d) {
    if (ns == 0) return;
    if (d == 8) {
        if (ns == 1 && getColumn() < 7) {
            setColumn(getColumn() + 1);
            return;
        }
        if (getColumn() == 7) {
            return;
        }
        setColumn(getColumn() + 1);
        moveTower(ns - 1, d);
    }
    else if (d == 2) {
        if (ns == 1 && getColumn() > 0) {
            setColumn(getColumn() - 1);
            return;
        }
        if (getColumn() == 0) {
            return;
        }
        setColumn(getColumn() - 1);
        moveTower(ns - 1, d);
    }
    else if (d == 4) {
        if (ns == 1 && getRow() > 0) {
            setRow(getRow() - 1);
            return;
        }
        if (getRow() == 0) {
            return;
        }
        setRow(getRow() - 1);
        moveTower(ns - 1, d);
    }
    else if (d == 6) {
        if (ns == 1 && getRow() < 7) {
            setRow(getRow() + 1);
            return;
        }
        if (getRow() == 7) {
            return;
        }
        setRow(getRow() + 1);
        moveTower(ns - 1, d);
    }
}

void Piece::createBishop(char name, int r, int c) {
    this->name = name;
    setRow(r);
    setColumn(c);
}

void Piece::moveBishop(int ns, int d) {
    if (ns == 0) return;
    if (d == 1) {
        if (getRow() == 7 || getColumn() == 7) {
            return;
        }
        if (ns == 1 && getColumn() < 7 || ns == 1 && getRow() < 7) {
            setColumn(getColumn() + 1);
            setRow(getRow() + 1);
            return;
        }
        setColumn(getColumn() + 1);
        setRow(getRow() + 1);
        moveBishop(ns - 1, d);
    }
    else if (d == 2) {
        if (getRow() == 7 || getColumn() == 0) {
            return;
        }
        if (ns == 1 && getColumn() > 0 || ns == 1 && getRow() < 7) {
            setColumn(getColumn() - 1);
            setRow(getRow() + 1);
            return;
        }
        setColumn(getColumn() - 1);
        setRow(getRow() + 1);
        moveBishop(ns - 1, d);
    }
    else if (d == 3) {
        if (getRow() == 0 || getColumn() == 0) {
            return;
        }
        if (ns == 1 && getColumn() > 0 || ns == 1 && getRow() > 0) {
            setColumn(getColumn() - 1);
            setRow(getRow() - 1);
            return;
        }
        setColumn(getColumn() - 1);
        setRow(getRow() - 1);
        moveBishop(ns - 1, d);
    }
    else if (d == 4) {
        if (getRow() == 0 || getColumn() == 7) {
            return;
        }
        if (ns == 1 && getColumn() < 7 || ns == 1 && getRow() > 0) {
            setColumn(getColumn() + 1);
            setRow(getRow() - 1);
            return;
        }
        setColumn(getColumn() + 1);
        setRow(getRow() - 1);
        moveBishop(ns - 1, d);
    }
}

void Piece::createQueen(char name, int r, int c) {
    this->name = name;
    setRow(r);
    setColumn(c);
}

void Piece::moveQueen(int ns, int d) {
    if (ns == 0) return;
    if (d == 1) {
        moveBishop(ns, 1);
    }
    else if (d == 2) {
        moveTower(ns, d);
    }
    else if (d == 3) {
        moveBishop(ns, 2);
    }
    else if (d == 4) {
        moveTower(ns, d);
    }
    else if (d == 5) {
        moveBishop(ns, 3);
    }
    else if (d == 6) {
        moveTower(ns, d);
    }
    else if (d == 7) {
        moveBishop(ns, 4);
    }
    else if (d == 8) {
        moveTower(ns, d);
    }
}

void Piece::createHorse(char name, int r, int c) {
    this->name = name;
    setRow(r);
    setColumn(c);
}

void Piece::moveHorse(int d) {
    if (d == 1) {
        if ((getColumn() + 2) > 7 || (getRow() + 1) > 7) {
            return;
        }
        else {
            moveTower(2, 8);
            moveTower(1, 6);
            return;
        }
    }
    else if (d == 2) {
        if ((getColumn() + 2) > 7 || (getRow() - 1) < 0) {
            return;
        }
        else {
            moveTower(2, 8);
            moveTower(1, 4);
            return;
        }
    }
    else if (d == 3) {
        if ((getColumn() - 2) < 0 || (getRow() + 1) > 7) {
            return;
        }
        else {
            moveTower(2, 2);
            moveTower(1, 6);
            return;
        }
    }
    else if (d == 4) {
        if ((getColumn() - 2) < 0 || (getRow() - 1) < 0) {
            return;
        }
        else {
            moveTower(2, 2);
            moveTower(1, 4);
            return;
        }
    }
    else if (d == 5) {
        if ((getRow() + 2) > 7 || (getColumn() + 1) > 7) {
            return;
        }
        else {
            moveTower(1, 8);
            moveTower(2, 6);
            return;
        }
    }
    else if (d == 6) {
        if ((getRow() + 2) > 7 || (getColumn() - 1) < 0) {
            return;
        }
        else {
            moveTower(1, 2);
            moveTower(2, 6);
            return;
        }
    }
    else if (d == 7) {
        if ((getRow() - 2) < 0 || (getColumn() + 1) > 7) {
            return;
        }
        else {
            moveTower(1, 8);
            moveTower(2, 4);
            return;
        }
    }
    else if (d == 8) {
        if ((getRow() - 2) < 0 || (getColumn() - 1) < 0) {
            return;
        }
        else {
            moveTower(1, 2);
            moveTower(2, 4);
            return;
        }
    }
}

void Piece::createPawn(char name, int r, int c) {
    this->name = name;
    setRow(r);
    setColumn(c);
}

void Piece::movePawn(int direction) {
    if (direction == 1) {
        if (getColumn() > 7) {
            return;
        }
        else {
            moveTower(1, 8);
            return;
        }
    }
    else if (direction == 2) {
        if (getColumn() < 0) {
            return;
        }
        else {
            moveTower(1, 2);
            return;
        }
    }
    else if (direction == 3) {
        moveBishop(1, 1);
        return;
    }
    else if (direction == 4) {
        moveBishop(1, 2);
        return;
    }
    else if (direction == 5) {
        moveBishop(1, 3);
        return;
    }
    else if (direction == 6) {
        moveBishop(1, 4);
        return;
    }
}

void Piece::moveAtackPawn(int direction) {
    if (direction == 1) {
        moveBishop(1, 1);
        return;
    }
    else if (direction == 2) {
        moveBishop(1, 2);
        return;
    }
    else if (direction == 3) {
        moveBishop(1, 3);
        return;
    }
    else if (direction == 4) {
        moveBishop(1, 4);
        return;
    }
    else   return;
}
