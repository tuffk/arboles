#include "Arbol2-3.h"
#include <ctime>

int main()
{

	Arbol23<int> * arbol = new Arbol23<int>(50);
	arbol->insertar(60);
	arbol->insertar(70);
	arbol->insertar(40);
	arbol->insertar(30);
	arbol->insertar(20);
	arbol->insertar(10);
	arbol->insertar(80);
	arbol->insertar(90);
	arbol->insertar(100);

	/*srand((int) time(NULL));

	for (int i = 0; i < 15; i++)
		arbol->insertar(rand() % 1000 + 1);*/
	
	arbol->imprimirA();

	Nodo23<int> * nodulon = arbol->buscar(30);

	if (nodulon != NULL)
		cout << "10 se encuentra en el nodo " << *nodulon << endl;
	else
		cout << "como que no esta\n";

	system("pause");
	return 0;
}