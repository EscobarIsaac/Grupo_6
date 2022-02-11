#include <iostream>
#include "piece.h"
#include "tabq.h"
#include <stdio.h>
#include <string>
#include <ctime>
#include <fstream>

void clear();
void fillByConsole(Piece& p);
int generateRandom(int from, int to);

using namespace std;

int main(int, char**) {
	srand(time(NULL));
	int select;
	int opc;
	std::ofstream file;
	do {
		clear();
		std::cout << "Elija una opcion: " << std::endl;
		std::cout << "1. Mostrar las posibles posiciones de una pieza " << std::endl;
		std::cout << "0. Salir" << std::endl;
		cin >> select;
		while (select > 1) {
			cout << "Intente de nuevo:";
			cin >> select;
		}
		if (select == 1) {
			int s1;
			clear();
			std::cout << "Elija una pieza: " << std::endl;
			std::cout << "\t" << "1. Reina " << std::endl;
			std::cout << "\t" << "2. Alfil " << std::endl;
			std::cout << "\t" << "3. Torre " << std::endl;
			std::cout << "\t" << "4. Caballo " << std::endl;
			cin >> s1;
			while (s1 >= 5) {
				cout << "Intente de nuevo:";
				cin >> s1;
			}
			if (s1 == 1) {
				Piece queen;
				queen.createQueen('R', 0, 0);
				fillByConsole(queen);
				Board board(8);
				board.drawPiece(queen);
				board.drawMovements(queen);
				board.printBoard();
				system("pause");
			}
			else if (s1 == 2) {
				Piece bishop;
				bishop.createBishop('A', 0, 0);
				fillByConsole(bishop);
				Board board(8);
				board.drawPiece(bishop);
				board.drawMovements(bishop);
				board.printBoard();
				system("pause");
			}
			else if (s1 == 3) {
				Piece tower;
				tower.createTower('T', 0, 0);
				fillByConsole(tower);
				Board board(8);
				board.drawPiece(tower);
				board.drawMovements(tower);
				board.printBoard();
				system("pause");
			}
			else if (s1 == 4) {
				Piece horse;
				horse.createQueen('C', 0, 0);
				fillByConsole(horse);
				Board board(8);
				board.drawPiece(horse);
				board.drawMovements(horse);
				board.printBoard();
				system("pause");
			}
		}
	} while (select != 0);
	file.close();
}

void clear() {
	std::cout << "\x1B[2J\x1B[H";
}

void fillByConsole(Piece& p) {
	int r, c;
	std::cout << "Ingrese la fila: ";
	cin >> r;
	while (r < 1 || r >8) {
		cout << "Intente de nuevo (rango 1 a 8):";
		cin >> r;
	}
	p.setRow(r - 1);

	std::cout << "Ingrese la columna: ";
	cin >> c;
	while (c < 1 || c >8) {
		cout << "Intente de nuevo (rango 1 a 8):";
		cin >> c;
	}
	p.setColumn(c - 1);
}

int generateRandom(int from, int to) {
	return rand() % (to - from + 1) + from;
}

