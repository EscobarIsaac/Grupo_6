/******************  Universidad de las Fuerzas Armadas ESPE  ************************
 *				Carrera: Software													 *
 *				Autores:Isaac Escobar, Josue Ferrin,							     *
 *				Fecha de creaci�n: 13/10/2022										 *
 *				Fecha de modificaci�n: 13/02/2022									 *
 *************************************************************************************/
#include "Sudoku.cpp"

int main() {
    Sudoku sudoku;
    int **matriz;
    matriz = sudoku.hacerSolucion(matriz);
    sudoku.tablero(matriz);
    return 0;
}

