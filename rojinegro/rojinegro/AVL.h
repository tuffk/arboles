#pragma once
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
	int profundidadTotal();
	int profundidadTotal(Nodo<N> *);

	int nivel(N);
	int altura(N);

	void clear();
	void clear(Nodo<N> *);

	void calcularBalanceo();
	void calcularBalanceo(Nodo<N> *);
	bool balanceado();
	bool balanceado(Nodo<N> *);

	void rotacion();
	void rotacion(Nodo<N> *);

	void rotacionSimple();
	void rotacionSimple(Nodo<N> *);

	void rotacionDoble();
	void rotacionDoble(Nodo<N> *);

	void imprimir();
	void imprimir(Nodo<N> *, string, string, string);

	void rotIzq(Nodo<N>* pivote);
	void rotDer(Nodo<N>* pivote);

	~AVL();
};

template<class N>
void AVL<N>::insertar(Nodo<N> * n)
{

	if (raiz == NULL)
	{
		raiz = n;
		raiz->setColor(0);
	}
	else
	{
		insertar(raiz, n);
	}

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

	calcularBalanceo();

	if (!balanceado())
	{
		//imprimir();
		rotacion();
		calcularBalanceo();
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

	calcularBalanceo();

	if (!balanceado())
	{
		imprimir();
		rotacion();
		calcularBalanceo();
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
	return profundidad(i, raiz, 0);
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
int AVL<N>::profundidadTotal()
{
	return profundidadTotal(raiz);
}

template<class N>
int AVL<N>::profundidadTotal(Nodo<N> * n)
{
	int izq = 0;
	int der = 0;

	if (n != NULL)
	{
		izq = profundidadTotal(n->getIzq());
		der = profundidadTotal(n->getDer());

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
	return profundidadTotal() - profundidad(i);
}

template<class N>
int AVL<N>::altura(N info)
{
	if (encontrado(info, raiz))
		return profundidadTotal(buscar(info));
	else
		return 0;
}

template<class N>
void AVL<N>::calcularBalanceo()
{
	calcularBalanceo(raiz);
}

template<class N>
void AVL<N>::calcularBalanceo(Nodo<N> * n)
{
	if (n != NULL)
	{
		if (n->getDer() != NULL && n->getIzq() != NULL)
		{
			n->setFactorBalanceo(altura(n->getDer()->getInfo()) - altura(n->getIzq()->getInfo()));
			calcularBalanceo(n->getDer());
			calcularBalanceo(n->getIzq());
		}
		else
		{
			if (n->getDer() == NULL && n->getIzq() == NULL)
			{
				n->setFactorBalanceo(0);
			}
			else
			{
				if (n->getDer() != NULL && n->getIzq() == NULL)
				{
					n->setFactorBalanceo(altura(n->getDer()->getInfo()));
					calcularBalanceo(n->getDer());
				}
				else
				{
					n->setFactorBalanceo(0 - altura(n->getIzq()->getInfo()));
					calcularBalanceo(n->getIzq());
				}
			}
		}
	}
}

template<class N>
bool AVL<N>::balanceado()
{
	return balanceado(raiz);
}

template<class N>
bool AVL<N>::balanceado(Nodo<N> * n)
{
	if (n != NULL)
	{
		if (1 >= n->getFactorBalanceo() && n->getFactorBalanceo() >= -1)
			return (balanceado(n->getDer()) && balanceado(n->getIzq()) && true);
		else
			return false;
	}

	return true;
}

template<class N>
void AVL<N>::rotacion()
{
	rotacion(raiz);
}

template<class N>
void AVL<N>::rotacion(Nodo<N> * n)
{

	if (n != NULL)
	{
		if (n->getFactorBalanceo() >= 2 || n->getFactorBalanceo() <= -2)
		{
			Nodo<N> * temp = n;

			while (temp->getFactorBalanceo() >= 2 || temp->getFactorBalanceo() <= -2)
			{
				if (temp->getFactorBalanceo() >= 2)
					temp = temp->getDer();
				else if (temp->getFactorBalanceo() <= -2)
					temp = temp->getIzq();
			}


			Nodo<N> * pivote = temp->getPadre();

			if (pivote->getFactorBalanceo() > 0)
			{
				if (temp->getFactorBalanceo() > 0)
				{
					//cout << "Rotacion simple a la izquierda\n";
					rotacionSimple(temp);
				}
				else
				{
					//cout << "Rotacion doble a la izquierda\n";
					rotacionDoble(temp);
				}
			}
			else
			{
				if (temp->getFactorBalanceo() < 0)
				{
					//cout << "Rotacion simple a la derecha\n";
					rotacionSimple(temp);
				}
				else
				{
					//cout << "Rotacion doble a la derecha\n";
					rotacionDoble(temp);
				}
			}

		}
		else
		{
			rotacion(n->getIzq());
			rotacion(n->getDer());
		}
	}

}

template<class N>
void AVL<N>::rotacionSimple()
{
	rotacionSimple(raiz);
}

template<class N>
void AVL<N>::rotacionSimple(Nodo<N> * n)
{

	if (n != NULL)
	{
		Nodo<N> * temp = n;
		Nodo<N> * pivote = temp->getPadre();
		Nodo<N> * aux;

		if (pivote->getPadre() != NULL)
			aux = pivote->getPadre();
		else
			aux = NULL;

		Nodo<N> * aux1;

		if (pivote->getFactorBalanceo() > 0)
		{
			if (aux != NULL)
			{
				if (aux->getDer() == pivote)
				{
					aux->setDer(temp);
					temp->setPadre(aux);
				}
				else
				{
					aux->setIzq(temp);
					temp->setPadre(aux);
				}
			}
			else
			{
				temp->setPadre(NULL);
				raiz = temp;
			}

			if (temp->getIzq() != NULL)
			{
				aux1 = temp->getIzq();
				pivote->setDer(aux1);
				aux1->setPadre(pivote);
			}
			else
				pivote->setDer(NULL);

			pivote->setPadre(temp);
			temp->setIzq(pivote);

		}
		else
		{
			if (aux != NULL)
			{
				if (aux->getDer() == pivote)
				{
					aux->setDer(temp);
					temp->setPadre(aux);
				}
				else
				{
					aux->setIzq(temp);
					temp->setPadre(aux);
				}
			}
			else
			{
				temp->setPadre(NULL);
				raiz = temp;
			}

			if (temp->getDer() != NULL)
			{
				aux1 = temp->getDer();
				pivote->setIzq(aux1);
				aux1->setPadre(pivote);
			}
			else
				pivote->setIzq(NULL);

			temp->setDer(pivote);
			pivote->setPadre(temp);
		}
	}

}

template<class N>
void AVL<N>::rotacionDoble()
{
	rotacionDoble(raiz);
}

template<class N>
void AVL<N>::rotacionDoble(Nodo<N> * n)
{

	if (n != NULL)
	{

		Nodo<N> * temp = n;
		Nodo<N> * pivote = temp->getPadre();
		Nodo<N> * aux;

		if (pivote->getPadre() != NULL)
			aux = pivote->getPadre();
		else
			aux = NULL;

		Nodo<N> * aux1;
		Nodo<N> * aux2;
		Nodo<N> * aux3;

		if (pivote->getFactorBalanceo() > 0)
		{

			aux1 = temp->getIzq();

			if (aux != NULL)
			{
				if (aux->getDer() == pivote)
				{
					aux->setDer(aux1);
					aux1->setPadre(aux);
				}
				else
				{
					aux->setIzq(aux1);
					aux1->setPadre(aux);
				}
			}
			else
			{
				aux1->setPadre(NULL);
				raiz = aux1;
			}

			if (aux1->getIzq() != NULL)
			{
				aux2 = aux1->getIzq();
				pivote->setDer(aux2);
				aux2->setPadre(pivote);
			}
			else
				pivote->setDer(NULL);

			if (aux1->getDer() != NULL)
			{
				aux3 = aux1->getDer();
				temp->setIzq(aux3);
				aux3->setPadre(temp);
			}
			else
				temp->setIzq(NULL);

			aux1->setIzq(pivote);
			pivote->setPadre(aux1);
			aux1->setDer(temp);
			temp->setPadre(aux1);

		}
		else
		{

			aux1 = temp->getDer();

			if (aux != NULL)
			{
				if (aux->getDer() == pivote)
				{
					aux->setDer(aux1);
					aux1->setPadre(aux);
				}
				else
				{
					aux->setIzq(aux1);
					aux1->setPadre(aux);
				}
			}
			else
			{
				aux1->setPadre(NULL);
				raiz = aux1;
			}

			if (aux1->getIzq() != NULL)
			{
				aux2 = aux1->getIzq();
				temp->setDer(aux2);
				aux2->setPadre(temp);
			}
			else
				temp->setDer(NULL);

			if (aux1->getDer() != NULL)
			{
				aux3 = aux1->getDer();
				pivote->setIzq(aux3);
				aux3->setPadre(pivote);
			}
			else
				pivote->setIzq(NULL);

			aux1->setIzq(temp);
			temp->setPadre(aux1);
			aux1->setDer(pivote);
			pivote->setPadre(aux1);
		}

	}

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


template<class N>
void AVL<N>::rotIzq(Nodo<N>* pivote)
{
	Nodo<T>* temp = raiz;
	temp = pivote;
	pivote->getPadre()->setDerecho(pivote->getDerecho());
	pivote->setPadre(pivote->getDerecho());
	temp = pivote->getPadre()->getIzquierdo();
	pivote->getDerecho()->setIzquierdo(pivote);
	pivote->setDerecho(temp);
	temp->setPadre(pivote);
}

template<class N>
void AVL<N>::rotDer(Nodo<N>* pivote)
{
	Nodo<T>* temp = raiz;
	temp = pivote;
	pivote->getPadre()->setIzquierdo(pivote->getIzquierdo());
	pivote->setPadre(pivote->getIzquierdo());
	temp = pivote->getPadre()->getDerecho();
	pivote->getIzquierdo()->setDerecho(pivote);
	pivote->setIzquierdo(temp);
	temp->setPadre(pivote);
}