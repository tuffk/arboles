////
////  Nodo.h
////  t7c1e2
////
////  Created by Vicente Cubells Nonell on 24/03/14.
////  Copyright (c) 2014 Vicente Cubells Nonell. All rights reserved.
////
//
//#ifndef __t7c1e2__Nodo__
//#define __t7c1e2__Nodo__
//
//#include <iostream>
//#include<cstdlib>
//
//using namespace std;
//
//template <class T> class Nodo;
//template <typename T> std::ostream & operator <<(std::ostream & os, Nodo<T>  & nodo);
//
//template <class T>
//class Nodo {
//	T info;
//	Nodo<T> * izquierdo;
//	Nodo<T> * derecho;
//
//	Nodo<T> * padre;
//
//	bool rojo;
//
//public:
//	Nodo();
//	Nodo(T info);
//
//	T getInfo();
//	void setInfo(T value);
//
//	Nodo<T> * getIzquierdo();
//	void setIzquierdo(Nodo<T> * value);
//
//	Nodo<T> * getDerecho();
//	void setDerecho(Nodo<T> * value);
//
//	Nodo<T> * getPadre();
//	void setPadre(Nodo<T> * value);
//
//	void setColor(bool color);
//	bool esRojo();
//
//	Nodo<T>* abuelo(Nodo<T>* n);
//	Nodo<T>* tio(Nodo<T>* n);
//
//	friend std::ostream & operator<< <>(std::ostream & os, Nodo<T> & nodo);
//};
//
//template <class T>
//Nodo<T>::Nodo()
//{
//	izquierdo = NULL;
//	derecho = NULL;
//	padre = NULL;
//	rojo = true;
//}
//
//template <class T>
//Nodo<T>::Nodo(T info)
//{
//	this->info = info;
//	izquierdo = derecho = NULL;
//	padre = NULL;
//	rojo = true;
//}
//
//template <class T>
//T Nodo<T>::getInfo()
//{
//	return info;
//}
//
//template <class T>
//void Nodo<T>::setInfo(T value)
//{
//	info = value;
//}
//
//template <class T>
//Nodo<T> * Nodo<T>::getIzquierdo()
//{
//	return izquierdo;
//}
//
//template <class T>
//void Nodo<T>::setIzquierdo(Nodo<T> * value)
//{
//	izquierdo = value;
//}
//
//template <class T>
//Nodo<T> * Nodo<T>::getDerecho()
//{
//	return derecho;
//}
//
//template <class T>
//void Nodo<T>::setDerecho(Nodo<T> * value)
//{
//	derecho = value;
//}
//
//template <class T>
//Nodo<T> * Nodo<T>::getPadre()
//{
//	return padre;
//}
//
//template <class T>
//void Nodo<T>::setPadre(Nodo<T> * value)
//{
//	padre = value;
//}
//
//template <class T>
//void Nodo<T>::setColor(bool color)
//{
//	rojo = color;
//}
//
//template <class T>
//bool Nodo<T>::esRojo()
//{
//	return rojo;
//}
//
//template <class T>
//Nodo<T>* Nodo<T>::abuelo(Nodo<T>* n)
//{
//	if ((n != NULL) && (n->getPadre() != NULL))
//	{
//		return n->getPadre()->getPadre();
//	}
//	else
//	{
//		return NULL;
//	}
//}
//
//
//template <class T>
//Nodo<T>* Nodo<T>::tio(Nodo<T>* n)
//{
//	Nodo<T>* temp = abuelo(n);
//	if (temp != NULL)
//	{
//		if (n->getPadre() == temp->getDerecho)
//		{
//			return temp->getIzquierdo();
//		}
//		else if (n->getPadre() == temp->getIzquierdo())
//		{
//			return temp->getDerecho();
//		}
//	}
//	else
//	{
//		return NULL;
//	}
//}
//
//
//template <typename T>
//std::ostream & operator<<(std::ostream & os, Nodo<T> & nodo)
//{
//	os << nodo.info;
//
//	return os;
//}
//
//
//#endif /* defined(__t7c1e2__Nodo__) */

#include <iostream>
using namespace std;



template <class T> class Nodo;
template <typename T> ostream & operator <<(ostream & os, Nodo<T>  & n);

template <class T>

class Nodo
{
private:
	T info;
	int factorBalanceo;
	Nodo<T> * izq;
	Nodo<T> * der;
	Nodo<T> * padre;
	bool rojo;

public:
	Nodo(T i)
	{
		info = i;
		izq = NULL;
		der = NULL;
		padre = NULL;
		factorBalanceo = 0;
		rojo = 1;
	}

	T getInfo()
	{
		return info;
	}

	int getFactorBalanceo()
	{
		return factorBalanceo;
	}

	void setColor(bool c)
	{
		rojo = c;
	}

	bool getColor()
	{
		return rojo;
	}

	Nodo<T> * getIzq()
	{
		return izq;
	}

	Nodo<T> * getDer()
	{
		return der;
	}

	Nodo<T> * getPadre()
	{
		return padre;
	}

	void setInfo(T value)
	{
		info = value;
	}

	void setFactorBalanceo(int f)
	{
		factorBalanceo = f;
	}

	void setIzq(Nodo<T> * value)
	{
		izq = value;
	}

	void setDer(Nodo<T> * value)
	{
		der = value;
	}

	void setPadre(Nodo<T> * value)
	{
		padre = value;
	}

	void abuelo(Nodo<T>* n)
	{
		if ((n != NULL) && (n->getPadre() != NULL))
		{
			return n->getPadre()->getPadre();
		}
		else
		{
			return NULL;
		}

	}

	void tio(Nodo<T>* n)
	{
		Nodo<T>* temp = abuelo(n);
		if (temp != NULL)
		{
			if (n->getPadre() == temp->getDerecho)
			{
				return temp->getIzquierdo();
			}
			else if (n->getPadre() == temp->getIzquierdo())
			{
				return temp->getDerecho();
			}
		}
		else
		{
			return NULL;
		}
	}

	friend std::ostream & operator << <>(std::ostream & os, Nodo<T> & n);
};


template <typename T>
ostream & operator <<(ostream & os, Nodo<T>  & n)
{
	os << "-" << n.info;
	return os;
}