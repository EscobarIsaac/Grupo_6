#include<iostream>
#include "Pascal.h"
using namespace std;

int main(){
	Pascal<int> c1;
	for(int i=0; i<5; i++){
		for(int ii=0; ii<=i; ii++)
		cout<<c1.combination(i,ii)<< " ";
		cout<<endl;
	}

    return 0;
}
