#include "AVL.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	Nodo<int> * n = new Nodo<int>(500);
	AVL<int> * arbol = new AVL<int>(n);

	srand((int) time(NULL));

	int busca;
	int borra;

	for (int i = 0; i < 20; i++)
	{
		int temp = rand() % 1000 + 1;
		Nodo<int> * nodulon = new Nodo<int>(temp);
		arbol->insertar(nodulon);
		if (i == 10)
			busca = temp;
		if (i == 15)
			borra = temp;
		arbol->imprimir();
		cout << endl << endl;
	}

	cout << "Buscar el elemnto " << busca << endl;

	if (arbol->encontrado(busca, arbol->getRaiz()))
		cout << "El elemento esta en el arbol\n";

	cout << "Borrar el elemento " << borra << endl;

	arbol->borrar(borra);

	arbol->imprimir();

	cout << endl << endl;

	arbol->impresionA();
	cout << endl;
	arbol->impresionD();

	delete arbol;

	system("PAUSE");
	return 0;
}