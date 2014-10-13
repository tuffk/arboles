#include "AVL.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	Nodo<int> * n = new Nodo<int>(500);
	AVL<int> * arbol = new AVL<int>(n);

	srand((int) time(NULL));


	for (int i = 0; i < 14; i++)
	{
		Nodo<int> * nodulon = new Nodo<int>(rand() % 1000 + 1);
		arbol->insertar(nodulon);
		arbol->imprimir();
		cout << endl << endl;
	}


	delete arbol;

	system("PAUSE");
	return 0;
}