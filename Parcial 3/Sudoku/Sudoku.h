/******************  Universidad de las Fuerzas Armadas ESPE  ************************
 *				Carrera: Software													 *
 *				Autores:Isaac Escobar, Josue Ferrin,							     *
 *				Fecha de creación: 13/10/2022										 *
 *				Fecha de modificación: 13/02/2022									 *
 *************************************************************************************/
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

class Sudoku {
private:
    int **matriz;
    int detente;
    int aleatorio;
    int contador1;
    int contador2;
public:
    int** inicializar(int);
    void tablero(int**);
    int** hacerSolucion(int**);
    int controlar(int, int, int, int, int**);
};
