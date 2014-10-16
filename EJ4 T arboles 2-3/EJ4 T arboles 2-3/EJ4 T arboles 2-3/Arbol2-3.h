#pragma once
#include "Nodo34.h"
#include <string>

template<class N>
class Arbol23
{
private:
	Nodo23<N> * raiz;
	
public:
	Arbol23()
	{
		raiz = NULL;
	}

	Arbol23(Nodo23<N> * r)
	{
		raiz = r;
	}

	Arbol23(N i)
	{
		raiz = new Nodo23<N>(i);
	}

	Nodo23<N> * getRaiz()
	{
		return raiz;
	}

	void insertar(N);
	void insertar(N, Nodo23<N> *);
	void dividir(N, Nodo23<N> *);

	void imprimirD();
	void imprimirD(Nodo23<N> *);

	void imprimirA();
	void imprimirA(Nodo23<N> *);

	bool encontrado(N);
	bool encontrado(N, Nodo23<N> *);
	Nodo23<N> * buscar(N);
	Nodo23<N> * buscar(N, Nodo23<N> *);

	void borrar(N);
	Nodo23<N> * intercambio(N, Nodo23<N> *);
	void redistribuir(Nodo23<N> *);
	void fusionar(Nodo23<N> *);


	~Arbol23();
};

template<class N>
void Arbol23<N>::insertar(N info)
{
	if (raiz == NULL)
		raiz = new Nodo23<N>(info);
	else
		insertar(info, raiz);
}

template<class N>
void Arbol23<N>::insertar(N info, Nodo23<N> * n)
{

	if (info > n->getInfo1())
	{
		if (n->esHoja())
		{
			if (n->getInfo2() == NULL)
				n->setInfo2(info);
			else
			{
				dividir(info, n);
			}
		}
		else
		{
			if (n->getInfo2() == NULL)
			{
				insertar(info, n->getMed23());
			}
			else
			{
				if (info > n->getInfo2())
				{
					insertar(info, n->getDer23());
				}
				else
				{
					insertar(info, n->getMed23());
				}
			}
		}
	}
	else
	{
		if (n->esHoja())
		{
			if (n->getInfo2() == NULL)
			{
				n->setInfo2(n->getInfo1());
				n->setInfo1(info);
			}
			else
			{
				dividir(info, n);
			}
		}
		else
		{
			insertar(info, n->getIzq23());
		}
	}

}

template<class N>
void Arbol23<N>::dividir(N info, Nodo23<N> * n)
{

	Nodo34<N> * nodulon = new Nodo34<N>(n->getInfo1(), n->getInfo2());

	if (n->esHoja())
	{
		if (info > n->getInfo1() && info > n->getInfo2())
			nodulon->setInfo3(info);
		else
		{
			if (info < n->getInfo1() && info < n->getInfo2())
			{
				nodulon->setInfo3(nodulon->getInfo2());
				nodulon->setInfo2(nodulon->getInfo1());
				nodulon->setInfo1(info);
			}
			else
			{
				nodulon->setInfo3(nodulon->getInfo2());
				nodulon->setInfo2(info);
			}
		}

		if (raiz == n)
		{
			Nodo23<N> * nodoP = new Nodo23<N>(nodulon->getInfo2());
			Nodo23<N> * nodo1 = new Nodo23<N>(nodulon->getInfo1());
			Nodo23<N> * nodo2 = new Nodo23<N>(nodulon->getInfo3());
			
			nodoP->setIzq23(nodo1);
			nodoP->setMed23(nodo2);
			nodo1->setPadre23(nodoP);
			nodo2->setPadre23(nodoP);

			raiz = nodoP;
		}
		else
		{

			if (n->getPadre23()->getInfo2() == NULL)
			{
				if (nodulon->getInfo2() < n->getPadre23()->getInfo1())
				{
					n->getPadre23()->setInfo2(n->getPadre23()->getInfo1());
					n->getPadre23()->setInfo1(nodulon->getInfo2());
					n->getPadre23()->setDer23(n->getPadre23()->getMed23());
					Nodo23<N> * nodo1 = new Nodo23<N>(nodulon->getInfo1());
					Nodo23<N> * nodo2 = new Nodo23<N>(nodulon->getInfo3());
					n->getPadre23()->setIzq23(nodo1);
					n->getPadre23()->setMed23(nodo2);
					nodo1->setPadre23(n->getPadre23());
					nodo2->setPadre23(n->getPadre23());
					n->setPadre23(NULL);
				}
				else
				{
					n->getPadre23()->setInfo2(nodulon->getInfo2());
					Nodo23<N> * nodo1 = new Nodo23<N>(nodulon->getInfo1());
					Nodo23<N> * nodo2 = new Nodo23<N>(nodulon->getInfo3());
					n->getPadre23()->setMed23(nodo1);
					n->getPadre23()->setDer23(nodo2);
					nodo1->setPadre23(n->getPadre23());
					nodo2->setPadre23(n->getPadre23());
					n->setPadre23(NULL);
				}
			}
			else
			{
				nodulon->setPadre23(n->getPadre23());

				if (nodulon->getInfo2() > n->getPadre23()->getInfo1() && nodulon->getInfo2() > n->getPadre23()->getInfo2())
					n->getPadre23()->setDer34(nodulon);
				else if (nodulon->getInfo2() > n->getPadre23()->getInfo1())		
						n->getPadre23()->setMed34(nodulon);
					else
						n->getPadre23()->setIzq34(nodulon);

				n->setPadre23(NULL);
				dividir(nodulon->getInfo2(), nodulon->getPadre23());

			}
		}
	}
	else
	{
		if (info > n->getInfo1() && info > n->getInfo2())
		{
			nodulon->setInfo3(info);
			nodulon->setDer34(n->getDer34());
			nodulon->setIzq23(n->getIzq23());
			nodulon->setMedi23(n->getMed23());
			n->getDer34()->setPadre34(nodulon);
			n->getIzq23()->setPadre34(nodulon);
			n->getMed23()->setPadre34(nodulon);

			n->setDer34(NULL);
			n->setMed23(NULL);
			n->setIzq23(NULL);
			
			Nodo23<N> * nodo2 = new Nodo23<N>(nodulon->getDer34()->getInfo3());
			Nodo23<N> * nodo1 = new Nodo23<N>(nodulon->getDer34()->getInfo1());

			nodo1->setIzq23(nodulon->getDer34()->getIzq23());
			nodo1->setMed23(nodulon->getDer34()->getMedi23());
			nodo2->setIzq23(nodulon->getDer34()->getMedd23());
			nodo2->setMed23(nodulon->getDer34()->getDer23());

			if (!nodulon->getDer34()->esHoja())
			{
				nodulon->getDer34()->getIzq23()->setPadre23(nodo1);
				nodulon->getDer34()->getMedi23()->setPadre23(nodo1);
				nodulon->getDer34()->getMedd23()->setPadre23(nodo2);
				nodulon->getDer34()->getDer23()->setPadre23(nodo2);
			}

			nodulon->getDer34()->setPadre34(NULL);

			nodulon->getDer34()->setIzq23(NULL);
			nodulon->getDer34()->setMedi23(NULL);
			nodulon->getDer34()->setMedd23(NULL);
			nodulon->getDer34()->setDer23(NULL);

			nodulon->setMedd23(nodo1);
			nodulon->setDer23(nodo2);
			nodo1->setPadre34(nodulon);
			nodo2->setPadre34(nodulon);



			if (raiz == n)
			{
				Nodo23<N> * nodoP = new Nodo23<N>(nodulon->getInfo2());
				Nodo23<N> * nodo1 = new Nodo23<N>(nodulon->getInfo1());
				Nodo23<N> * nodo2 = new Nodo23<N>(nodulon->getInfo3());

				nodoP->setIzq23(nodo1);
				nodoP->setMed23(nodo2);
				nodo1->setPadre23(nodoP);
				nodo2->setPadre23(nodoP);

				nodo1->setIzq23(nodulon->getIzq23());
				nodulon->getIzq23()->setPadre23(nodo1);
				nodo1->setMed23(nodulon->getMedi23());
				nodulon->getMedi23()->setPadre23(nodo1);

				nodo2->setIzq23(nodulon->getMedd23());
				nodulon->getMedd23()->setPadre23(nodo2);
				nodo2->setMed23(nodulon->getDer23());
				nodulon->getDer23()->setPadre23(nodo2);

				raiz = nodoP;

				nodulon->setIzq23(NULL);
				nodulon->setMedi23(NULL);
				nodulon->setMedd23(NULL);
				nodulon->setDer23(NULL);
			}
			else
			{

				if (n->getPadre23()->getInfo2() == NULL)
				{
					if (nodulon->getInfo2() < n->getPadre23()->getInfo1())
					{
						n->getPadre23()->setInfo2(n->getPadre23()->getInfo1());
						n->getPadre23()->setInfo1(nodulon->getInfo2());
						n->getPadre23()->setDer23(n->getPadre23()->getMed23());
						Nodo23<N> * nodo1 = new Nodo23<N>(nodulon->getInfo1());
						Nodo23<N> * nodo2 = new Nodo23<N>(nodulon->getInfo3());
						n->getPadre23()->setIzq23(nodo1);
						n->getPadre23()->setMed23(nodo2);
						nodo1->setPadre23(n->getPadre23());
						nodo2->setPadre23(n->getPadre23());

						nodo1->setIzq23(nodulon->getIzq23());
						nodulon->getIzq23()->setPadre23(nodo1);
						nodo1->setMed23(nodulon->getMedi23());
						nodulon->getMedi23()->setPadre23(nodo1);

						nodo2->setIzq23(nodulon->getMedd23());
						nodulon->getMedd23()->setPadre23(nodo2);
						nodo2->setMed23(nodulon->getDer23());
						nodulon->getDer23()->setPadre23(nodo2);

						nodulon->setIzq23(NULL);
						nodulon->setMedi23(NULL);
						nodulon->setMedd23(NULL);
						nodulon->setDer23(NULL);

						n->setPadre23(NULL);
					}
					else
					{
						n->getPadre23()->setInfo2(nodulon->getInfo2());
						Nodo23<N> * nodo1 = new Nodo23<N>(nodulon->getInfo1());
						Nodo23<N> * nodo2 = new Nodo23<N>(nodulon->getInfo3());
						n->getPadre23()->setMed23(nodo1);
						n->getPadre23()->setDer23(nodo2);
						nodo1->setPadre23(n->getPadre23());
						nodo2->setPadre23(n->getPadre23());

						nodo1->setIzq23(nodulon->getIzq23());
						nodulon->getIzq23()->setPadre23(nodo1);
						nodo1->setMed23(nodulon->getMedi23());
						nodulon->getMedi23()->setPadre23(nodo1);

						nodo2->setIzq23(nodulon->getMedd23());
						nodulon->getMedd23()->setPadre23(nodo2);
						nodo2->setMed23(nodulon->getDer23());
						nodulon->getDer23()->setPadre23(nodo2);

						nodulon->setIzq23(NULL);
						nodulon->setMedi23(NULL);
						nodulon->setMedd23(NULL);
						nodulon->setDer23(NULL);

						n->setPadre23(NULL);
					}
				}
				else
				{
					nodulon->setPadre23(n->getPadre23());

					if (nodulon->getInfo2() > n->getPadre23()->getInfo1() && nodulon->getInfo2() > n->getPadre23()->getInfo2())
						n->getPadre23()->setDer34(nodulon);
					else if (nodulon->getInfo2() > n->getPadre23()->getInfo1())
						n->getPadre23()->setMed34(nodulon);
					else
						n->getPadre23()->setIzq34(nodulon);

					n->setPadre23(NULL);
					dividir(nodulon->getInfo2(), nodulon->getPadre23());
				}

			}
		}
		else
		{
			if (info < n->getInfo1() && info < n->getInfo2())
			{
				nodulon->setInfo3(nodulon->getInfo2());
				nodulon->setInfo2(nodulon->getInfo1());
				nodulon->setInfo1(info);
				nodulon->setIzq34(n->getIzq34());
				nodulon->setMedd23(n->getMed23());
				nodulon->setDer23(n->getDer23());

				n->setDer23(NULL);
				n->setMed23(NULL);
				n->setIzq34(NULL);

				Nodo23<N> * nodo2 = new Nodo23<N>(nodulon->getIzq34()->getInfo3());
				Nodo23<N> * nodo1 = new Nodo23<N>(nodulon->getIzq34()->getInfo1());

				nodo1->setIzq23(nodulon->getIzq34()->getIzq23());
				nodo1->setMed23(nodulon->getIzq34()->getMedi23());
				nodo2->setIzq23(nodulon->getIzq34()->getMedd23());
				nodo2->setMed23(nodulon->getIzq34()->getDer23());

				if (!nodulon->getIzq34()->esHoja())
				{
					nodulon->getIzq34()->getIzq23()->setPadre23(nodo1);
					nodulon->getIzq34()->getMedi23()->setPadre23(nodo1);
					nodulon->getIzq34()->getMedd23()->setPadre23(nodo2);
					nodulon->getIzq34()->getDer23()->setPadre23(nodo2);
				}

				nodulon->getIzq34()->setPadre34(NULL);

				nodulon->getIzq34()->setIzq23(NULL);
				nodulon->getIzq34()->setMedi23(NULL);
				nodulon->getIzq34()->setMedd23(NULL);
				nodulon->getIzq34()->setDer23(NULL);

				nodulon->setIzq23(nodo1);
				nodulon->setMedi23(nodo2);
				nodo1->setPadre34(nodulon);
				nodo2->setPadre34(nodulon);

				if (raiz == n)
				{
					Nodo23<N> * nodoP = new Nodo23<N>(nodulon->getInfo2());
					Nodo23<N> * nodo1 = new Nodo23<N>(nodulon->getInfo1());
					Nodo23<N> * nodo2 = new Nodo23<N>(nodulon->getInfo3());

					nodoP->setIzq23(nodo1);
					nodoP->setMed23(nodo2);
					nodo1->setPadre23(nodoP);
					nodo2->setPadre23(nodoP);

					nodo1->setIzq23(nodulon->getIzq23());
					nodulon->getIzq23()->setPadre23(nodo1);
					nodo1->setMed23(nodulon->getMedi23());
					nodulon->getMedi23()->setPadre23(nodo1);

					nodo2->setIzq23(nodulon->getMedd23());
					nodulon->getMedd23()->setPadre23(nodo2);
					nodo2->setMed23(nodulon->getDer23());
					nodulon->getDer23()->setPadre23(nodo2);

					raiz = nodoP;

					nodulon->setIzq23(NULL);
					nodulon->setMedi23(NULL);
					nodulon->setMedd23(NULL);
					nodulon->setDer23(NULL);
				}
				else
				{
					if (n->getPadre23()->getInfo2() == NULL)
					{
						if (nodulon->getInfo2() < n->getPadre23()->getInfo1())
						{
							n->getPadre23()->setInfo2(n->getPadre23()->getInfo1());
							n->getPadre23()->setInfo1(nodulon->getInfo2());
							n->getPadre23()->setDer23(n->getPadre23()->getMed23());
							Nodo23<N> * nodo1 = new Nodo23<N>(nodulon->getInfo1());
							Nodo23<N> * nodo2 = new Nodo23<N>(nodulon->getInfo3());
							n->getPadre23()->setIzq23(nodo1);
							n->getPadre23()->setMed23(nodo2);
							nodo1->setPadre23(n->getPadre23());
							nodo2->setPadre23(n->getPadre23());

							nodo1->setIzq23(nodulon->getIzq23());
							nodulon->getIzq23()->setPadre23(nodo1);
							nodo1->setMed23(nodulon->getMedi23());
							nodulon->getMedi23()->setPadre23(nodo1);

							nodo2->setIzq23(nodulon->getMedd23());
							nodulon->getMedd23()->setPadre23(nodo2);
							nodo2->setMed23(nodulon->getDer23());
							nodulon->getDer23()->setPadre23(nodo2);

							nodulon->setIzq23(NULL);
							nodulon->setMedi23(NULL);
							nodulon->setMedd23(NULL);
							nodulon->setDer23(NULL);

							n->setPadre23(NULL);
						}
						else
						{
							n->getPadre23()->setInfo2(nodulon->getInfo2());
							Nodo23<N> * nodo1 = new Nodo23<N>(nodulon->getInfo1());
							Nodo23<N> * nodo2 = new Nodo23<N>(nodulon->getInfo3());
							n->getPadre23()->setMed23(nodo1);
							n->getPadre23()->setDer23(nodo2);
							nodo1->setPadre23(n->getPadre23());
							nodo2->setPadre23(n->getPadre23());

							nodo1->setIzq23(nodulon->getIzq23());
							nodulon->getIzq23()->setPadre23(nodo1);
							nodo1->setMed23(nodulon->getMedi23());
							nodulon->getMedi23()->setPadre23(nodo1);

							nodo2->setIzq23(nodulon->getMedd23());
							nodulon->getMedd23()->setPadre23(nodo2);
							nodo2->setMed23(nodulon->getDer23());
							nodulon->getDer23()->setPadre23(nodo2);

							nodulon->setIzq23(NULL);
							nodulon->setMedi23(NULL);
							nodulon->setMedd23(NULL);
							nodulon->setDer23(NULL);

							n->setPadre23(NULL);
						}
					}
					else
					{
						nodulon->setPadre23(n->getPadre23());

						if (nodulon->getInfo2() > n->getPadre23()->getInfo1() && nodulon->getInfo2() > n->getPadre23()->getInfo2())
							n->getPadre23()->setDer34(nodulon);
						else if (nodulon->getInfo2() > n->getPadre23()->getInfo1())
							n->getPadre23()->setMed34(nodulon);
						else
							n->getPadre23()->setIzq34(nodulon);

						n->setPadre23(NULL);
						dividir(nodulon->getInfo2(), nodulon->getPadre23());
					}
				}
			}
			else
			{
				nodulon->setInfo3(nodulon->getInfo2());
				nodulon->setInfo2(info);
				nodulon->setIzq23(n->getIzq23());
				nodulon->setDer23(n->getDer23());
				nodulon->setMedi34(n->getMed34());

				n->setDer23(NULL);
				n->setMed34(NULL);
				n->setIzq23(NULL);

				Nodo23<N> * nodo2 = new Nodo23<N>(nodulon->getMedi34()->getInfo3());
				Nodo23<N> * nodo1 = new Nodo23<N>(nodulon->getMedi34()->getInfo1());

				
				nodo1->setIzq23(nodulon->getMedi34()->getIzq23());
				nodo1->setMed23(nodulon->getMedi34()->getMedi23());
				nodo2->setIzq23(nodulon->getMedi34()->getMedd23());
				nodo2->setMed23(nodulon->getMedi34()->getDer23());

				if (!nodulon->getMedi34()->esHoja())
				{
					nodulon->getMedi34()->getIzq23()->setPadre23(nodo1);
					nodulon->getMedi34()->getMedi23()->setPadre23(nodo1);
					nodulon->getMedi34()->getMedd23()->setPadre23(nodo2);
					nodulon->getMedi34()->getDer23()->setPadre23(nodo2);
				}

				nodulon->getMedi34()->setPadre34(NULL);

				nodulon->getMedi34()->setIzq23(NULL);
				nodulon->getMedi34()->setMedi23(NULL);
				nodulon->getMedi34()->setMedd23(NULL);
				nodulon->getMedi34()->setDer23(NULL);

				nodulon->setMedi23(nodo1);
				nodulon->setMedd23(nodo2);
				nodo1->setPadre34(nodulon);
				nodo2->setPadre34(nodulon);

				if (raiz == n)
				{
					Nodo23<N> * nodoP = new Nodo23<N>(nodulon->getInfo2());
					Nodo23<N> * nodo1 = new Nodo23<N>(nodulon->getInfo1());
					Nodo23<N> * nodo2 = new Nodo23<N>(nodulon->getInfo3());

					nodoP->setIzq23(nodo1);
					nodoP->setMed23(nodo2);
					nodo1->setPadre23(nodoP);
					nodo2->setPadre23(nodoP);

					nodo1->setIzq23(nodulon->getIzq23());
					nodulon->getIzq23()->setPadre23(nodo1);
					nodo1->setMed23(nodulon->getMedi23());
					nodulon->getMedi23()->setPadre23(nodo1);

					nodo2->setIzq23(nodulon->getMedd23());
					nodulon->getMedd23()->setPadre23(nodo2);
					nodo2->setMed23(nodulon->getDer23());
					nodulon->getDer23()->setPadre23(nodo2);

					raiz = nodoP;

					nodulon->setIzq23(NULL);
					nodulon->setMedi23(NULL);
					nodulon->setMedd23(NULL);
					nodulon->setDer23(NULL);
				}
				else
				{
					if (n->getPadre23()->getInfo2() == NULL)
					{
						if (nodulon->getInfo2() < n->getPadre23()->getInfo1())
						{
							n->getPadre23()->setInfo2(n->getPadre23()->getInfo1());
							n->getPadre23()->setInfo1(nodulon->getInfo2());
							n->getPadre23()->setDer23(n->getPadre23()->getMed23());
							Nodo23<N> * nodo1 = new Nodo23<N>(nodulon->getInfo1());
							Nodo23<N> * nodo2 = new Nodo23<N>(nodulon->getInfo3());
							n->getPadre23()->setIzq23(nodo1);
							n->getPadre23()->setMed23(nodo2);
							nodo1->setPadre23(n->getPadre23());
							nodo2->setPadre23(n->getPadre23());

							nodo1->setIzq23(nodulon->getIzq23());
							nodulon->getIzq23()->setPadre23(nodo1);
							nodo1->setMed23(nodulon->getMedi23());
							nodulon->getMedi23()->setPadre23(nodo1);

							nodo2->setIzq23(nodulon->getMedd23());
							nodulon->getMedd23()->setPadre23(nodo2);
							nodo2->setMed23(nodulon->getDer23());
							nodulon->getDer23()->setPadre23(nodo2);

							nodulon->setIzq23(NULL);
							nodulon->setMedi23(NULL);
							nodulon->setMedd23(NULL);
							nodulon->setDer23(NULL);

							n->setPadre23(NULL);
						}
						else
						{
							n->getPadre23()->setInfo2(nodulon->getInfo2());
							Nodo23<N> * nodo1 = new Nodo23<N>(nodulon->getInfo1());
							Nodo23<N> * nodo2 = new Nodo23<N>(nodulon->getInfo3());
							n->getPadre23()->setMed23(nodo1);
							n->getPadre23()->setDer23(nodo2);
							nodo1->setPadre23(n->getPadre23());
							nodo2->setPadre23(n->getPadre23());

							nodo1->setIzq23(nodulon->getIzq23());
							nodulon->getIzq23()->setPadre23(nodo1);
							nodo1->setMed23(nodulon->getMedi23());
							nodulon->getMedi23()->setPadre23(nodo1);

							nodo2->setIzq23(nodulon->getMedd23());
							nodulon->getMedd23()->setPadre23(nodo2);
							nodo2->setMed23(nodulon->getDer23());
							nodulon->getDer23()->setPadre23(nodo2);

							nodulon->setIzq23(NULL);
							nodulon->setMedi23(NULL);
							nodulon->setMedd23(NULL);
							nodulon->setDer23(NULL);

							n->setPadre23(NULL);
						}
					}
					else
					{
						nodulon->setPadre23(n->getPadre23());

						if (nodulon->getInfo2() > n->getPadre23()->getInfo1() && nodulon->getInfo2() > n->getPadre23()->getInfo2())
							n->getPadre23()->setDer34(nodulon);
						else if (nodulon->getInfo2() > n->getPadre23()->getInfo1())
							n->getPadre23()->setMed34(nodulon);
						else
							n->getPadre23()->setIzq34(nodulon);

						n->setPadre23(NULL);
						dividir(nodulon->getInfo2(), nodulon->getPadre23());
					}
				}
			}
		}
	}

	

}

template<class N>
void Arbol23<N>::imprimirA()
{
	imprimirA(raiz);
	cout << endl;
}

template<class N>
void Arbol23<N>::imprimirA(Nodo23<N> * n)
{
	if (n != NULL)
	{
		imprimirA(n->getIzq23());
		cout << "-" << n->getInfo1();
		imprimirA(n->getMed23());
		if (n->getInfo2() != NULL)
		{
			cout << "-" << n->getInfo2();
		}
		imprimirA(n->getDer23());
	}
}

template<class N>
void Arbol23<N>::imprimirD()
{
	imprimirD(raiz);
	cout << endl;
}

template<class N>
void Arbol23<N>::imprimirD(Nodo23<N> * n)
{
	if (n != NULL)
	{
		imprimirD(n->getDer23());
		if (n->getInfo2() != NULL)
		{
			cout << "-" << n->getInfo2();
		}
		imprimirD(n->getMed23());
		cout << "-" << n->getInfo1();
		imprimirD(n->getIzq23());
	}
}

template<class N>
bool Arbol23<N>::encontrado(N i)
{
	return encontrado(i, raiz);
}

template<class N>
bool Arbol23<N>::encontrado(N i, Nodo23<N> * n)
{
	Nodo23<N> * temp = n;
	while (temp != NULL)
	{
		if (i == temp->getInfo1() || i == temp->getInfo2())
			return true;
		else
		{
			if (temp->getInfo1() > i)
				temp = temp->getIzq23();
			else if (temp->getInfo2() == NULL)
				temp = temp->getMed23();
			else if (temp->getInfo2() > i)
				temp = temp->getMed23();
			else
				temp = temp->getDer23();
		}
		
	}

	return false;

}

template<class N>
Nodo23<N> * Arbol23<N>::buscar(N i)
{
	if (encontrado(i))
		return buscar(i, raiz);
	else
	{
		cout << "No se encontro el elemento\n";
		return NULL;
	}
}

template<class N>
Nodo23<N> * Arbol23<N>::buscar(N i, Nodo23<N> * n)
{
	Nodo23<N> * temp = n;
	while (true)
	{
		if (i == temp->getInfo1() || i == temp->getInfo2())
			return temp;
		else
		{
			if (temp->getInfo1() > i)
				temp = temp->getIzq23();
			else if (temp->getInfo2() == NULL)
				temp = temp->getMed23();
			else if (temp->getInfo2() > i)
				temp = temp->getMed23();
			else
				temp = temp->getDer23();
		}

	}

}

template<class N>
void Arbol23<N>::borrar(N i)
{

	Nodo23<N> * nodo = buscar(i);
	
	if (!nodo->esHoja())
	{
		nodo = intercambio(i, nodo);
	}

	if (nodo->getInfo2() != NULL)
	{
		nodo->setInfo1(nodo->getInfo2());
		nodo->setInfo2(NULL);
	}
	else
	{
		if (nodo->getPadre23()->getIzq23() == nodo)
		{
			if (nodo->getPadre23()->getMed23()->getInfo2() != NULL)
			{
				nodo->setInfo1(nodo->getPadre23()->getInfo1());
				nodo->getPadre23()->setInfo1(nodo->getPadre23()->getMed23()->getInfo1());
				nodo->getPadre23()->getMed23()->setInfo1(nodo->getPadre23()->getMed23()->getInfo2());
				nodo->getPadre23()->getMed23()->setInfo2(NULL);
			}
			else
			{
				if (nodo->getPadre23()->getInfo2() != NULL)
				{
					nodo->setInfo1(nodo->getPadre23()->getInfo1());
					nodo->getPadre23()->setInfo1(nodo->getPadre23()->getMed23()->getInfo1());
					nodo->getPadre23()->getMed23()->setInfo1(nodo->getPadre23()->getInfo2());
					nodo->getPadre23()->setInfo2(nodo->getPadre23()->getDer23()->getInfo1());
					if (nodo->getPadre23()->getDer23()->getInfo2() != NULL)
					{
						nodo->getPadre23()->getDer23()->setInfo1(nodo->getPadre23()->getDer23()->getInfo2());
						nodo->getPadre23()->getDer23()->setInfo2(NULL);
					}
					else
					{
						nodo->getPadre23()->getMed23()->setInfo2(nodo->getPadre23()->getDer34()->getInfo1());
						nodo->getPadre23()->getDer23()->setPadre23(NULL);
						nodo->getPadre23()->setDer23(NULL);
					}
				}
				else
				{
					nodo->setInfo1(nodo->getPadre23()->getInfo1());
					nodo->setInfo2(nodo->getPadre23()->getMed23()->getInfo1());
					nodo->getPadre23()->setInfo1(NULL);
					nodo->getPadre23()->setInfo2(NULL);
					nodo->getPadre23()->getMed23()->setPadre23(NULL);
					fusionar(nodo->getPadre23());
				}
			}
		}
		else
		{
			if (nodo->getPadre23()->getMed23() == nodo)
			{
				if (nodo->getPadre23()->getIzq23()->getInfo2() != NULL)
				{
					if (nodo->getPadre23()->getInfo2() != NULL)
					{
						if (nodo->getPadre23()->getDer23()->getInfo2() != NULL)
						{
							nodo->setInfo1(nodo->getPadre23()->getInfo2());
							nodo->getPadre23()->setInfo2(nodo->getPadre23()->getDer23()->getInfo1());
							nodo->getPadre23()->getDer23()->setInfo1(nodo->getPadre23()->getDer23()->getInfo2());
							nodo->getPadre23()->getDer23()->setInfo2(NULL);
						}
						else
						{
							nodo->setInfo1(nodo->getPadre23()->getInfo2());
							nodo->setInfo2(nodo->getPadre23()->getDer23()->getInfo1());
							nodo->getPadre23()->setInfo2(NULL);
							nodo->getPadre23()->getDer23()->setPadre23(NULL);
							nodo->getPadre23()->setDer23(NULL);

						}
					}
					else
					{
						
					}
				}
			}
			else
			{

			}
		}
	}

}

template<class N>
Nodo23<N> * Arbol23<N>::intercambio(N i, Nodo23<N> * n)
{
	bool primero;
	Nodo23<N> * temp = n;
	if (n->getInfo1() == i)
		temp = temp->getMed23();
	else
		temp = temp->getDer23();

	while (!temp->esHoja())
		temp = temp->getIzq23();
	

	if (n->getInfo1() == i)
	{
		n->setInfo1(temp->getInfo1());
		temp->setInfo1(i);
	}
	else
	{
		n->setInfo2(temp->getInfo1());
		temp->setInfo1(i)
	}

	return temp;
	
}

template<class N>
void Arbol23<N>::redistribuir(Nodo23<N> * n)
{



}

template<class N>
void Arbol23<N>::fusionar(Nodo23<N> *)
{

}
/*#include "Nodo.h"
#include <string>

template<class N>
class Arbol23
{
private:
	Nodo<N> * raiz;

public:
	Arbol23()
	{
		raiz = NULL;
	}

	Arbol23(Nodo<N> * r)
	{
		raiz = r;
	}

	Arbol23(N i)
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
void Arbol23<N>::insertar(N i)
{

	if (raiz != NULL)
		raiz = new Nodo<N>(i);
	else
		insertar(i, raiz);

}

template<class N>
void Arbol23<N>::insertar(N info, Nodo<N> * n)
{


	if (info > n->getElementos()->at(0))
	{
		if (n->getElementos()->size() == 1)
		{
			n->insertarElemento(info);
		}
		else
		{
			if (n->getElementos()->at(1) < info)
			{
				Nodo<N> * nodo = new Nodo<N>(n->getElementos()->at(1));
				Nodo<N> * nodo1 = new Nodo<N>(n->getElementos()->at(0));
				Nodo<N> * nodo2 = new Nodo<N>(info);
				nodo->getHijos()->at(0) = nodo1;
				nodo->getHijos()->at(1) = nodo2;
				nodo1->setPadre(nodo);
				nodo2->setPadre(nodo);
				raiz = nodo;
			}
		}
	}
	else
	{
		if (n->getHijos()->at(0) != NULL)
			insertar(info, n->getHijos()->at(0));
		else
		{
			if (n->getElementos()->size() == 1)
				n->insertarElemento(info);
			else
			{
				n->getPadre()->insertarElemento(n->getElementos()->at(0));
				Nodo<N> * nodo1 = new Nodo<N>(info);
				Nodo<N> * nodo2 = new Nodo<N>(n->getElementos()->at(1));
				n->getPadre()->getHijos()->at(0) = nodo1;
				n->getPadre()->getHijos()->at(2) = n->getPadre()->getHijos()->at(1);
				n->getPadre()->getHijos()->at(1) = nodo2;
				nodo1->setPadre(n->getPadre());
				nodo2->setPadre(n->getPadre());
				n->setPadre(NULL);
			}
		}
	}

}*/