#include <iostream>
#include<cstdlib>
#include <time.h>
#include"AVL.h"
#define N 100000
using namespace std;

int main(int argc, const char * argv[])
{
	/*
	ArbolBinario<int> * ab = new ArbolBinario<int>();

	Nodo<int> *raiz = new Nodo<int>(5);
	ab->insertar(NULL, 1, raiz);

	Nodo<int> *n1 = new Nodo<int>(8);
	ab->insertar(raiz, 1, n1);

	Nodo<int> *n2 = new Nodo<int>(10);
	ab->insertar(raiz, 0, n2);

	Nodo<int> *n3 = new Nodo<int>(11);
	ab->insertar(n2, 1, n3);

	Nodo<int> *n4 = new Nodo<int>(25);
	ab->insertar(n1, 1, n4);

	Nodo<int> *n5 = new Nodo<int>(30);
	ab->insertar(n1, 1, n5);

	std::cout << *ab << std::endl;

	Nodo<int> * buscado = ab->buscar(25);

	if (buscado != NULL) {
	std::cout << "El nodo SI se encuentra y su valor es = " << *buscado << std::endl;
	}
	else {
	std::cout << "El nodo NO se encuentra" << std::endl;
	}

	if (ab->sonHermanos(8, 10)) {
	std::cout << "Son hermanos" << std::endl;
	}
	else {
	std::cout << "No son hermanos" << std::endl;
	}

	//cout << *n4 <<endl;

	std::cout << "Nivel de " << *n4 << " = " << ab->nivel(n4) << std::endl;

	ab->primos(n3);

	std::cout << "Número de nodos: " << ab->size() << std::endl;

	//probando ancestro
	cout<< *n1 << " es ancestro de " << *n4 << " = " << ab->esAncestro(n4,n1) << endl;

	//probando metodo de desendiente
	cout<< *n4 << " es desendiente de " << *n1 << " = " << ab->esDesendiente(n1,n4) << endl;

	//probando imprime ancestros
	ab->ancestros(n3);

	//probando imprime desendientes
	cout << "desendientes de " << * n1 << endl;
	ab->desendientes(n1, false);
	cout << endl;

	ab->caminoMasLargo();


	ab->clear();

	std::cout << "Número de nodos: " << ab->size() << std::endl;
	*/

	srand((int)time(NULL));
	AVL<int>* ab = new AVL<int>();


	clock_t t;
	t = clock();



	for (int i = 0; i < 1000; i++)
	{
		cout << i << " ";
		Nodo<int>* nod = new Nodo<int>(i);
		ab->insertar(nod);
	}




	t = clock() - t;
	//printf("It took me %d clicks (%f seconds).\n", t, ((float)t) / CLOCKS_PER_SEC);
	cout << "tardo " << t << " clicks, y " << (((float)t) / CLOCKS_PER_SEC) << " segundos" << endl;

	system("PAUSE");

	//delete ab;

	return 0;
}

