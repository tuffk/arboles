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

	Nodo<N> * getRaiz()
	{
		return raiz;
	}

	void insertar(N);

};

template<class N>
void ArbolB<N>::insertar(N i)
{



}