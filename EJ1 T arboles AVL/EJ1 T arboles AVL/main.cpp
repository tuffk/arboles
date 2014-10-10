#include "AVL.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	Nodo<int> * n = new Nodo<int>(50);
	AVL<int> * arbol = new AVL<int>(n);

	srand((int) time(NULL));


	for (int i = 0; i < 14; i++)
	{
		Nodo<int> * nodulon = new Nodo<int>(rand() % 100 + 1);
		arbol->insertar(nodulon);
	}


	arbol->imprimir();

	cout << endl << endl;

	arbol->borrar(50);

	arbol->imprimir();

	cout << endl;

	system("PAUSE");
	return 0;
}