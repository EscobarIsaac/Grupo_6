#include "tabq.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <iostream>
const int INF = 99999;

Board::Board(int dim) {
    this->dim = dim;
    this->elements = (char**)malloc(dim * sizeof(char*));
    for (int i = 0; i < dim; i++) {
        *(this->elements + i) = (char*)malloc(dim * sizeof(char));
    }
    for (int j = 0; j < dim; j++) {
        for (int k = 0; k < dim; k++) {
            *(*(this->elements + j) + k) = '0';
        }
    }
}

Board::Board(Board& g) {
    this->dim = g.getDim();
    this->elements = (char**)malloc(g.getDim() * sizeof(char*));
    for (int i = 0; i < dim; i++) {
        *(this->elements + i) = (char*)malloc(g.getDim() * sizeof(char));
    }
    // Op::copyGrapp(this,g); alternativa no valida, no puede recibir como parametro this
    for (int j = 0; j < g.getDim(); j++) {
        for (int k = 0; k < g.getDim(); k++) {
            setElements(j, k, g.getij(j, k));
        }
    }
}

int Board::getDim() {
    return this->dim;
}

char** Board::getElements() {
    return this->elements;
}

char Board::getij(int i, int j) {
    return *(*(this->elements + j) + i);
}

void Board::setElements(int i, int j, char key) {
    if (i < 0 || j >= getDim() || j < 0 || i >= getDim()) {
        std::cout << "El nodo no existe" << std::endl;
    }
    else {
        *(*(this->elements + j) + i) = key;
    }
}

void Board::printBoard() {
    // std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    for (int i = 0; i < getDim(); i++) {
        for (int j = 0; j < getDim(); j++) {
            std::cout << "\t" << getij(i, j);
        }
        std::cout << "\n";
    }
}

void Board::drawPiece(Piece piece) {
    setElements(piece.getRow(), piece.getColumn(), piece.getName());
}

void Board::drawMovements(Piece piece) {
    if (piece.getName() == 'T') {
        int r = piece.getRow();
        int c = piece.getColumn();
        char k;
        for (int i = 2; i < 9; i++) {
            for (int j = 1; j < 8; j++) {
                piece.setRow(r);
                piece.setColumn(c);
                if (i != 3 && i != 5 && i != 7) {
                    piece.moveTower(j, i);
                    if (getij(piece.getRow(), piece.getColumn()) == '0' ||
                        getij(piece.getRow(), piece.getColumn()) == '*')
                        setElements(piece.getRow(), piece.getColumn(), '*');
                    //k = getij(piece.getRow(),piece.getColumn());

                }
            }
        }
        piece.setRow(r);
        piece.setColumn(c);
    }
    else if (piece.getName() == 'A') {
        int r = piece.getRow();
        int c = piece.getColumn();
        char k;
        for (int i = 1; i < 5; i++) {
            for (int j = 1; j < 8; j++) {
                piece.setRow(r);
                piece.setColumn(c);
                //if(i != 3 && i != 5 && i !=7){
                piece.moveBishop(j, i);
                if (getij(piece.getRow(), piece.getColumn()) == '0' ||
                    getij(piece.getRow(), piece.getColumn()) == '*')
                    setElements(piece.getRow(), piece.getColumn(), '*');
                //k = getij(piece.getRow(),piece.getColumn());
                //std::cout <<"se ingreso en "<< piece.getRow()<< " y "<<piece.getColumn()<< " el valor "<< k<<std::endl;
            //}
            }
        }
        piece.setRow(r);
        piece.setColumn(c);
    }
    else if (piece.getName() == 'R') {
        int r = piece.getRow();
        int c = piece.getColumn();
        char k;
        for (int i = 1; i < 9; i++) {
            for (int j = 1; j < 8; j++) {
                piece.setRow(r);
                piece.setColumn(c);
                //if(i != 3 && i != 5 && i !=7){
                piece.moveQueen(j, i);
                if (getij(piece.getRow(), piece.getColumn()) == '0' ||
                    getij(piece.getRow(), piece.getColumn()) == '*')
                    setElements(piece.getRow(), piece.getColumn(), '*');
                //k = getij(piece.getRow(),piece.getColumn());
                //std::cout <<"se ingreso en "<< piece.getRow()<< " y "<<piece.getColumn()<< " el valor "<< k<<std::endl;
            //}
            }
        }
        piece.setRow(r);
        piece.setColumn(c);
    }
    else if (piece.getName() == 'C') {
        int r = piece.getRow();
        int c = piece.getColumn();
        char k;
        for (int i = 1; i < 9; i++) {
            piece.setRow(r);
            piece.setColumn(c);
            piece.moveHorse(i);

            if (piece.getRow() != r || piece.getColumn() != c)
                if (getij(piece.getRow(), piece.getColumn()) == '0' ||
                    getij(piece.getRow(), piece.getColumn()) == '*')
                    setElements(piece.getRow(), piece.getColumn(), '*');
            //k = getij(piece.getRow(),piece.getColumn());
            //std::cout <<"se ingreso en "<< piece.getRow()<< " y "<<piece.getColumn()<< " el valor "<< k<<std::endl;
        }
        piece.setRow(r);
        piece.setColumn(c);
    }
}

void Board::createAttackBoard(Piece a, Piece b) {
    drawPiece(a);
    drawPiece(b);
    drawMovements(a);
    drawMovements(b);
}

bool Board::analyzeTwoPieces(Board a, Board b) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                for (int x = 0; x < 8; x++) {
                    if (a.getij(i, j) == b.getij(k, x)) {
                        if (a.getij(i, j) == '*' && b.getij(i, j) == '*') {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

int Board::calculateRowAtack(Board a, Board b) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                for (int x = 0; x < 8; x++) {
                    if (a.getij(i, j) == b.getij(k, x)) {
                        if (a.getij(i, j) == '*' && b.getij(i, j) == '*') {
                            return i;
                        }
                    }
                }
            }
        }
    }
    return INF;
}

int Board::calculateColumnAtack(Board a, Board b) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                for (int x = 0; x < 8; x++) {
                    if (a.getij(i, j) == b.getij(k, x)) {
                        if (a.getij(i, j) == '*' && b.getij(i, j) == '*') {
                            return j;
                        }
                    }
                }
            }
        }
    }
    return INF;
}
