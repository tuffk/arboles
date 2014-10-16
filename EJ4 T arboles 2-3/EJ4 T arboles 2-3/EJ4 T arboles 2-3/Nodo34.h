#pragma once
#include "Nodo23.h"

template <typename T> ostream & operator <<(ostream & os, Nodo34<T>  & n);

template <class T>

class Nodo34
{
private:
	T info1;
	T info2;
	T info3;
	Nodo34<T> * izq34;
	Nodo34<T> * medi34;
	Nodo34<T> * medd34;
	Nodo34<T> * der34;
	Nodo23<T> * izq23;
	Nodo23<T> * medi23;
	Nodo23<T> * medd23;
	Nodo23<T> * der23;
	Nodo34<T> * padre34;
	Nodo23<T> * padre23;

public:

	Nodo34(T i)
	{
		info1 = i;
		info2 = NULL;
		info3 = NULL;
		izq34 = NULL;
		medi34 = NULL;
		medd34 = NULL;
		der34 = NULL;
		izq23 = NULL;
		medi23 = NULL;
		medd23 = NULL;
		der23 = NULL;
		padre34 = NULL;
		padre23 = NULL;
	}

	Nodo34(T i1, T i2)
	{
		info1 = i1;
		info2 = i2;
		info3 = NULL;
		izq34 = NULL;
		medi34 = NULL;
		medd34 = NULL;
		der34 = NULL;
		izq23 = NULL;
		medi23 = NULL;
		medd23 = NULL;
		der23 = NULL;
		padre34 = NULL;
		padre23 = NULL;
	}

	Nodo34(T i1, T i2, T i3)
	{
		info1 = i1;
		info2 = i2;
		info3 = i3;
		izq34 = NULL;
		medi34 = NULL;
		medd34 = NULL;
		der34 = NULL;
		izq23 = NULL;
		medi23 = NULL;
		medd23 = NULL;
		der23 = NULL;
		padre34 = NULL;
		padre23 = NULL;
	}

	Nodo34<T> * getPadre34()
	{
		return padre34;
	}

	Nodo23<T> * getPadre23()
	{
		return padre23;
	}

	Nodo34<T> * getIzq34()
	{
		return izq34;
	}

	Nodo34<T> * getMedi34()
	{
		return medi34;
	}

	Nodo34<T> * getMedd34()
	{
		return medd34;
	}

	Nodo34<T> * getDer34()
	{
		return der34;
	}

	Nodo23<T> * getIzq23()
	{
		return izq23;
	}

	Nodo23<T> * getMedi23()
	{
		return medi23;
	}

	Nodo23<T> * getMedd23()
	{
		return medd23;
	}

	Nodo23<T> * getDer23()
	{
		return der23;
	}

	T getInfo1()
	{
		return info1;
	}

	T getInfo2()
	{
		return info2;
	}

	T getInfo3()
	{
		return info3;
	}

	void setPadre34(Nodo34<T> * value)
	{
		padre34 = value;
		padre23 = NULL;
	}

	void setPadre23(Nodo23<T> * value)
	{
		padre23 = value;
		padre34 = NULL;
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

	void setMedi34(Nodo34<T> * value)
	{
		medi34 = value;
		medi23 = NULL;
	}

	void setMedd34(Nodo34<T> * value)
	{
		medd34 = value;
		medd23 = NULL;
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

	void setMedi23(Nodo23<T> * value)
	{
		medi23 = value;
		medi34 = NULL;
	}

	void setMedd23(Nodo23<T> * value)
	{
		medd23 = value;
		medd34 = NULL;
	}

	void setInfo1(T i)
	{
		info1 = i;
	}

	void setInfo2(T i)
	{
		info2 = i;
	}

	void setInfo3(T i)
	{
		info3 = i;
	}

	bool esHoja();

	friend std::ostream & operator << <>(std::ostream & os, Nodo34<T> & n);
};

template<class T>
bool Nodo34<T>::esHoja()
{
	if (izq23 == NULL && medi23 == NULL && medd23 == NULL && der23 == NULL)
		return true;
	else
		return false;

}

template <typename T>
ostream & operator <<(ostream & os, Nodo34<T>  & n)
{
	os << '-' << n.info1 << "|" << n.info2 << "|" << n.info3;
	return os;
}