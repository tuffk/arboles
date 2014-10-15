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
	vector<Nodo<T> *> * hijos;
	Nodo<T> * padre;

public:
	Nodo(T i)
	{
		elementos->push_back(i);
		hijos = NULL;
		padre = NULL;
	}

	Nodo(vector<T> * v)
	{
		elementos = v;
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