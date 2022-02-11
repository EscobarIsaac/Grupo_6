#include <iostream>
#include <conio.h>

using namespace std;

void printPascal(int n)
{

	for (int line = n; line >= 1; line--)
	{

		int C = 1;

		for (int i = 1; i < (n - line + 1); i++){
			cout << " ";
		}

		for (int i = 1; i <= line; i++)
		{

			cout << C << " ";
			C = C * (line - i) / i;
		}

		cout << "\n";
	}
}

int main()
{
	int n;

	cout << "Proporciona el numero de filas del triangulo: ";

	cin >> n;
	printPascal(n);

	_getch();

	return 0;
}
