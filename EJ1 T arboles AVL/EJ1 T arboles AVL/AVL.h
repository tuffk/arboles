#include "Nodo.h"
#include <string>

template<class N>
class AVL
{
private:
	Nodo<N> * raiz;

public:
	AVL()
	{
		raiz = NULL;
	}

	AVL(Nodo<N> * r)
	{
		raiz = r;
	}

	Nodo<N> * getRaiz()
	{
		return raiz;
	}

	void insertar(Nodo<N> *);
	void insertar(Nodo<N> *, Nodo<N> *);

	Nodo<N> * borrar(N);

	Nodo<N> * buscar(N);
	bool encontrado(N, Nodo<N> *);
	Nodo<N> * buscar(N, Nodo<N> *);
	Nodo<N> * sucesor(Nodo<N> *);
	Nodo<N> * predecesor(Nodo<N> *);

	void impresionA();
	void impresionA(Nodo<N> *);
	void impresionD();
	void impresionD(Nodo<N> *);

	int profundidad(N);
	int profundidad(N, Nodo<N> *, int);
	int profundiddadTotal();
	int profundiddadTotal(Nodo<N> *);

	int nivel(N);
	int altura(N info);

	void clear();
	void clear(Nodo<N> *);

	void imprimir();
	void imprimir(Nodo<N> *, string, string, string);

	~AVL();
};

template<class N>
void AVL<N>::insertar(Nodo<N> * n)
{

	if (raiz == NULL)
		raiz = n;
	else
		insertar(raiz, n);

}

template<class N>
void AVL<N>::insertar(Nodo<N> * p, Nodo<N> * n)
{

	if (p->getInfo() < n->getInfo())
	{
		if (p->getDer() == NULL)
		{
			p->setDer(n);
			n->setPadre(p);
		}
		else
			insertar(p->getDer(), n);
	}
	else
	{
		if (p->getIzq() == NULL)
		{
			p->setIzq(n);
			n->setPadre(p);
		}
		else
			insertar(p->getIzq(), n);
	}

}

template<class N>
Nodo<N> * AVL<N>::borrar(N info)
{

	Nodo<N> * nodo = buscar(info);
	Nodo<N> * temp;
	Nodo<N> * temp1;
	N aux;

	if (nodo != NULL)
	{
		if (nodo->getIzq() == NULL  && nodo->getDer() == NULL)
		{
			temp = nodo->getPadre();
			if (temp->getIzq() == nodo)
				temp->setIzq(NULL);
			else
				temp->setDer(NULL);

			nodo->setPadre(NULL);
		}
		else
		{
			if (nodo->getIzq() != NULL  && nodo->getDer() != NULL)
			{
				temp = predecesor(nodo);
				aux = temp->getInfo();
				temp1 = borrar(temp->getInfo());
				nodo->setInfo(aux);
				return temp1;
			}
			else
			{
				
				if (nodo->getIzq() != NULL && nodo->getDer() == NULL)
				{

					temp = nodo->getPadre();
					temp1 = nodo->getIzq();

					if (temp->getIzq() == nodo)
						temp->setIzq(temp1);
					else
						temp->setDer(temp1);

					nodo->setPadre(NULL);
					temp1->setPadre(temp);
				}
				else
				{
					temp = nodo->getPadre();
					temp1 = nodo->getDer();

					if (temp->getIzq() == nodo)
						temp->setIzq(temp1);
					else
						temp->setDer(temp1);

					nodo->setPadre(NULL);
					temp1->setPadre(temp);
				}
			}
		}
	}

	return nodo;
}

template<class N>
Nodo<N> * AVL<N>::buscar(N info)
{

	if (encontrado(info, raiz))
		return buscar(info, raiz);
	else
	{
		cout << "NO SE ENCONTRO EL NODO\n";
		return NULL;
	}
}

template<class N>
bool AVL<N>::encontrado(N info, Nodo<N> * n)
{

	bool indica = false;

	if (n != NULL)
	{
		if (n->getInfo() == info)
			return true;
		else
		{
			indica = encontrado(info, n->getIzq());

			if (!indica)
				indica = encontrado(info, n->getDer());

			return indica;
		}
	}

	return indica;
}

template<class N>
Nodo<N> * AVL<N>::buscar(N info, Nodo<N> * n)
{

	Nodo<N> * temp = NULL;

	if (n != NULL)
	{
		if (n->getInfo() == info)
			return n;
		else
		{
			temp = buscar(info, n->getIzq());

			if (temp == NULL)
				temp = buscar(info, n->getDer());
			
			return temp;
		}
	}

	return temp;

}

template<class N>
Nodo<N> * AVL<N>::sucesor(Nodo<N> * n)
{
	Nodo<N> * p = n->getDer();
	while (p->getIzq() != NULL)
		p = p->getIzq();

	return p;
}

template<class N>
Nodo<N> * AVL<N>::predecesor(Nodo<N> * n)
{
	Nodo<N> * p = n->getIzq();
	while (p->getDer() != NULL)
		p = p->getDer();

	return p;
}

template<class N>
void AVL<N>::impresionD()
{
	impresionA(raiz);
}

template<class N>
void AVL<N>::impresionD(Nodo<N> * n)
{
	if (n != NULL)
	{
		impresionA(n->getDer());
		cout << *n;
		impresionA(n->getIzq());
	}
}

template<class N>
void AVL<N>::impresionA()
{
	impresionD(raiz);
}

template<class N>
void AVL<N>::impresionA(Nodo<N> * n)
{
	if (n != NULL)
	{
		impresionD(n->getIzq());
		cout << *n;
		impresionD(n->getDer());
	}
}

template<class N>
int AVL<N>::profundidad(N i)
{
	return profundidad(i, raiz, 0)
}

template<class N>
int AVL<N>::profundidad(N i, Nodo<N> * n, int num)
{

	int izq = 0;
	int der = 0;

	if (n != NULL)
	{
		if (n->getInfo() != i)
		{
			izq = profundidad(i, n->getIzq(), num + 1);
			der = profundidad(i, n->getDer(), num + 1);

			if (izq != 0)
				return (izq);
			else
				return (der);
		}
		else
			return num;
	}

	return 0;
}

template<class N>
int AVL<N>::profundiddadTotal()
{
	return profundidadTotal(raiz);
}

template<class N>
int AVL<N>::profundiddadTotal(Nodo<N> * n)
{
	int izq = 0;
	int der = 0;

	if (n != NULL)
	{
		izq = profundidad(n->getIzq());
		der = profundidad(n->getDer());

		if (izq > der)
			return 1 + izq;
		else
			return 1 + der;
	}

	return 0;
}

template<class N>
int AVL<N>::nivel(N i)
{
	return profundiddadTotal() - profundidad(i);
}

template<class N>
int AVL<N>::altura(N info)
{
	if (encontrado(info, raiz))
		return profundidad(buscar(info));
	else
		return 0;
}

template<class N>
void AVL<N>::clear()
{
	clear(raiz);
	raiz = NULL;
}

template<class N>
void AVL<N>::clear(Nodo<N> * n)
{
	if (n != NULL)
	{
		clear(n->getIzq());
		clear(n->getDer());
		delete n;
	}
}

template<class N>
void AVL<N>::imprimir()
{
	imprimir(raiz, "", "", "");
}

template <class N>
void AVL<N>::imprimir(Nodo<N> *n, string s, string i, string d)
{
	if (n != NULL)
	{
		imprimir(n->getDer(), d + "    ", d + "    |", d + "     ");
		cout << s << "|--" << *n << endl;
		imprimir(n->getIzq(), i + "    ", i + "     ", i + "    |");
	}
}

template<class N>
AVL<N>::~AVL()
{
	clear();
}