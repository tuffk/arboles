#pragma once
#include <iostream>
using namespace std;

template <class T> class Nodo34;
template <class T> class Nodo23;
template <typename T> ostream & operator <<(ostream & os, Nodo23<T>  & n);

template <class T>

class Nodo23
{
private:
	T info1;
	T info2;
	Nodo23<T> * izq23;
	Nodo23<T> * med23;
	Nodo23<T> * der23;
	Nodo34<T> * izq34;
	Nodo34<T> * med34;
	Nodo34<T> * der34;
	Nodo23<T> * padre23;
	Nodo34<T> * padre34;

public:

	Nodo23(T i)
	{
		info1 = i;
		info2 = NULL;
		izq23 = NULL;
		med23 = NULL;
		der23 = NULL;
		izq34 = NULL;
		med34 = NULL;
		der34 = NULL;
		padre23 = NULL;
		padre34 = NULL;
	}

	Nodo23(T i1, T i2)
	{
		info1 = i1;
		info2 = i2;
		izq23 = NULL;
		med23 = NULL;
		der23 = NULL;
		izq34 = NULL;
		med34 = NULL;
		der34 = NULL;
		padre23 = NULL;
		padre34 = NULL;
	}

	Nodo23<T> * getPadre23()
	{
		return padre23;
	}

	Nodo34<T> * getPadre34()
	{
		return padre34;
	}

	Nodo23<T> * getIzq23()
	{
		return izq23;
	}

	Nodo23<T> * getMed23()
	{
		return med23;
	}

	Nodo23<T> * getDer23()
	{
		return der23;
	}

	Nodo34<T> * getIzq34()
	{
		return izq34;
	}

	Nodo34<T> * getMed34()
	{
		return med34;
	}

	Nodo34<T> * getDer34()
	{
		return der34;
	}

	T getInfo1()
	{
		return info1;
	}

	T getInfo2()
	{
		return info2;
	}

	void setPadre23(Nodo23<T> * value)
	{
		padre23 = value;
		padre34 = NULL;
	}

	void setPadre34(Nodo34<T> * value)
	{
		padre34 = value;
		padre23 = NULL;
	}

	void setIzq23(Nodo23<T> * value)
	{
		izq23 = value;
		izq34 = NULL;
	}

	void setDer23(Nodo23<T> * value)
	{
		der23 = value;
		der34 = NULL;
	}

	void setMed23(Nodo23<T> * value)
	{
		med23 = value;
		med34 = NULL;
	}

	void setIzq34(Nodo34<T> * value)
	{
		izq34 = value;
		izq23 = NULL;
	}

	void setDer34(Nodo34<T> * value)
	{
		der34 = value;
		der23 = NULL;
	}

	void setMed34(Nodo34<T> * value)
	{
		med34 = value;
		med23 = NULL;
	}

	void setInfo1(T i)
	{
		info1 = i;
	}

	void setInfo2(T i)
	{
		info2 = i;
	}

	bool esHoja();

	friend std::ostream & operator << <>(std::ostream & os, Nodo23<T> & n);
};

template<class T>
bool Nodo23<T>::esHoja()
{
	if (izq23 == NULL && med23 == NULL && der23 == NULL)
		return true;
	else
		return false;
}

template <typename T>
ostream & operator <<(ostream & os, Nodo23<T>  & n)
{
	os << '-' << n.info1 << "|" << n.info2;
	return os;
}


/*#include <iostream>
#include <vector>
using namespace std;



template <class T> class Nodo;
template <typename T> ostream & operator <<(ostream & os, Nodo<T>  & n);

template <class T>

class Nodo
{
private:
	vector<T> * elementos;
	vector<Nodo<T> *> * hijos;
	Nodo<T> * padre;

public:

	Nodo(T i)
	{
		elementos = new vector<T>();
		elementos->push_back(i);
		hijos->push_back(NULL);
		hijos->push_back(NULL);
		hijos = NULL;
		padre = NULL;
	}

	Nodo(vector<T> * v)
	{
		elementos = v;
		for (int i = 0; i < elementos->size() + 1; i++)
			hijos->push_back(NULL);
		hijos = NULL;
		padre = NULL;
	}

	Nodo<T> * getPadre()
	{
		return padre;
	}

	vector<Nodo<T> *> * getHijos()
	{
		return hijos;
	}

	vector<T> * getElementos()
	{
		return elementos;
	}

	void setHijos(vector<Nodo<T> *> * value)
	{
		hijos = value;
	}

	void setPadre(Nodo<T> * value)
	{
		padre = value;
	}

	void setElementos(vector<T> * value)
	{
		elementos = value;
		for (int i = 0; i < elementos->size() + 1; i++)
			hijos->push_back(NULL);
	}

	void insertarElemento(T i)
	{
		if (i > elementos->at(0))
			elementos->push_back(i);
		else
		{
			elementos->push_back(elementos->at(0));
			elementos->at(0) = i;
		}

		hijos->push_back(NULL);
		/*if (elementos->size() <= 2)
			return true;
		else
			return false;*/
/*	}

	friend std::ostream & operator << <>(std::ostream & os, Nodo<T> & n);
};


template <typename T>
ostream & operator <<(ostream & os, Nodo<T>  & n)
{

	for (int i = 0; i < n.elementos->size(); i++)
		os << " | " << n.elementos->at(i);
	os << " |\n";
	return os;
}*/