/******************  Universidad de las Fuerzas Armadas ESPE  ************************
 *				Carrera: Software													 *
 *				Autores:Isaac Escobar, Josue Ferrin,							     *
 *				Fecha de creación: 05/10/2022										 *
 *				Fecha de modificación: 07/02/2022									 *
 *************************************************************************************/
 #include<iostream>
#include "Pascal.h"
using namespace std;

int main(){
	Pascal<int> c1;
	int p;
	cout<< "Ingresa el valor :" <<endl;
	cin>>p;
	for(int i=p; i>=0; i--){
		for(int ii=0; ii<=i; ii++)
		cout<<c1.combination(i,ii)<< " ";
		cout<<endl;
	}

    return 0;
}
