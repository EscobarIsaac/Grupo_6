#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include <iostream>
using namespace std;

class Suma{
	public:
	    Suma();
	    Suma(int _sz);
	    ~Suma();
		void LlenarMatriz();

	private:
		int sz;

};
Suma::Suma(int _sz){
    sz = _sz;

}

Suma::Suma()
{
}

Suma::~Suma()
{
}
void Suma::LlenarMatriz()
{
    sz=3;

    const int constMagica = (sz * ( sz * sz + 1 )) / 2;
    int matriz[sz][sz];

    cout << "\nRellenar cuadrado (1 al " << sz * sz << "):\n";
    for( int i = 0; i < sz; i++ )
        for( int j = 0; j < sz; j++ ) {
            cout << "[" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }

    cout << "\nImprimir cuadrado:\n\n";
    for( int i = 0; i < sz; i++ ) {
        cout << " | ";
        for( int j = 0; j < sz; j++ )
            cout << matriz[i][j] << " ";

        cout << "| " << endl;
    }

    bool esMagico = true;
    int i = 0;
    while( i < sz && esMagico == true ) {
        int suma = 0;
        for( int j = 0; j < sz; j++ ) {
            suma += matriz[i][j];
        }
        if( suma != constMagica ) esMagico = false;
        i++;
    }
    int j = 0;
    while( j < sz && esMagico == true ) {
        int suma = 0;
        for( int i = 0; i < sz; i++ ) {
            suma += matriz[i][j];
        }
        if( suma != constMagica ) esMagico = false;
        j++;
    }

    if( !esMagico )  cout << "\nLos valores no corresponden a un cuadrado magico" << endl;
    else cout << "\nLos valores SI corresponden a un cuadrado magico" << endl;

}


#endif
