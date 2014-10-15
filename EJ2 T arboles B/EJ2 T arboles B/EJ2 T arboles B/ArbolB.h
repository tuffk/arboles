#include "Nodo.h"
#include <string>

template<class N>
class ArbolB
{
private:
	Nodo<N> * raiz;

public:
	ArbolB()
	{
		raiz = NULL;
	}

	ArbolB(Nodo<N> * r)
	{
		raiz = r;
	}

	ArbolB(N i)
	{
		raiz = new Nodo<N>(i);
	}

	Nodo<N> * getRaiz()
	{
		return raiz;
	}

	void insertar(N);
	void insertar(N, Nodo<N> *);

	~ArbolB();
};

template<class N>
void ArbolB<N>::insertar(N i)
{

	if (raiz != NULL)
		raiz = new Nodo<N>(i);
	else
		insertar(i, raiz);

}

template<class N>
void ArbolB<N>::insertar(N info, Nodo<N> * n)
{

	int j = 0;

	while (info > n->elementos->at(j))
		j++;

	if ()

}