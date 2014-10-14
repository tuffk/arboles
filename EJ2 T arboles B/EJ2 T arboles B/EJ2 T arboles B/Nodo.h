#include <iostream>
#include <vector>
using namespace std;



template <class T> class Nodo;
template <typename T> ostream & operator <<(ostream & os, Nodo<T>  & n);

template <class T>

class Nodo
{
private:
	vector<T> * elementos;
	Nodo<T> * izq;
	Nodo<T> * der;
	Nodo<T> * padre;
	Nodo<T> * siguiente;

public:
	Nodo(T i)
	{
		elementos->push_back(i);
		izq = NULL;
		der = NULL;
		padre = NULL;
	}

	Nodo(vector<T> * v)
	{
		elementos = v;
		izq = NULL;
		der = NULL;
		padre = NULL;
	}

	T getInfo()
	{
		return info;
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

	vector<T> * getElementos()
	{
		return elementos;
	}

	void setInfo(T value)
	{
		info = value;
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

	void setElementos(vector<T> * value)
	{
		elementos = value;
	}

	friend std::ostream & operator << <>(std::ostream & os, Nodo<T> & n);
};


template <typename T>
ostream & operator <<(ostream & os, Nodo<T>  & n)
{

	for (int i = 0; n.elementos->size(); i++)
		os << "|" << n.elementos->at(i);
	return os;
}