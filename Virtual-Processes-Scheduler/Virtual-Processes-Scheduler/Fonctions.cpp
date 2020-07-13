#include "biblio.h"
using namespace std;
#define MAX 10

Processus::Processus()
{
	nom= "";
	DA = 0;
	DE = 0;
	Prio =0 ;
	FD =0;
	DET = DE;
	DAT = DA;
}
string Processus::get_nom()
{
	
	return nom;
}
int Processus::get_DA()
{
	return DA;
}
int Processus::get_DE()
{
	return DE;
}
int Processus::get_Prio()
{
	return Prio;
}
void Processus::set_DE(int x)
{
	DE = x;
}
void Processus::set_DA(int x)
{
	DA = x;
}
void Processus::set_P(int x)
{
	Prio = x;
}
void Processus::Saisie()
{
	
	cout << "Taper le nom du processus" << endl;
	cin >> nom;
	cout << "Taper la durée esitmée du processus" << endl;
	cin >> DE;
	cout << "Taper la date d'arrivée du processus" << endl;
	cin >> DA;
	DET = DE;
	DAT = DA;
}
void Processus::Affiche()
{
	cout << "Le nom du processus est : " << nom << endl;
	cout << "La durée esitmée du processus est " << DE << endl;
	cout << "La date d'arrivée du processus :" << DA << endl;
}
Tableau::Tableau()
{
	x = 0;
}
void Tableau::Trie_DE()
{
	/*Trier le tableau selon l'ordre decroissant de la durée estimée des procesus*/
	int i, compt, marqueur;
	Processus memory;
	for (i = 1; i<x; i++)
	{
		memory = P[i];
		compt = i - 1;

		do
		{
			marqueur = false;
			if (P[compt].DE >= memory.DE)
			{
				P[compt + 1] = P[compt];
				compt--;
				marqueur = true;
			}
			if (compt<0) marqueur = false;
		} while (marqueur);
		P[compt + 1] = memory;
	}
}
void Tableau::Trie_DA()
{
	/*Trier le tableau selon l'ordre decroissant de la durée estimée des procesus*/
	int i, compt, marqueur;
	Processus memory;
	for (i = 1; i<x; i++)
	{
		memory = P[i];
		compt = i - 1;

		do
		{
			marqueur = false;
			if (P[compt].DA > memory.DA)
			{
				P[compt + 1] = P[compt];
				compt--;
				marqueur = true;
			}
			if (compt<0) marqueur = false;
		} while (marqueur);
		P[compt + 1] = memory;
	}
}
void Tableau::Trie_P()
{
	int i, compt, marqueur;
	Processus memory;
	for (i = 1; i<x; i++)
	{
		memory = P[i];
		compt = i - 1;

		do
		{
			marqueur = false;
			if (P[compt].Prio>memory.Prio)
			{
				P[compt + 1] = P[compt];
				compt--;
				marqueur = true;
			}
			if (compt<0) marqueur = false;
		} while (marqueur);
		P[compt + 1] = memory;
	}
}
void Tableau::Trie_PD()
{
	int i, compt, marqueur;
	Processus memory;
	for (i = 1; i<x; i++)
	{
		memory = P[i];
		compt = i - 1;

		do
		{
			marqueur = false;
			if (P[compt].Prio<memory.Prio)
			{
				P[compt + 1] = P[compt];
				compt--;
				marqueur = true;
			}
			if (compt<0) marqueur = false;
		} while (marqueur);
		P[compt + 1] = memory;
	}
}
Processus& Tableau::MIN_DA()
{
	int r = 0;
	Trie_DA();/*Trier le tableau selon l'ordre decroissant de la date d'arivée des procesus*/
	Trie_DA();
	while (P[r].DA < 0) { r++; }/*dépasser les processus ayant des dates d'arrivées négatives */
	return P[r];/*retourner le premier processus ayant une date d'arrivée positive */
	
}
Processus& Tableau::MIN_DE(int i)
{
	int p = 1;
	Trie_DE();/*Trier le tableau selon la durée estèimée la plus courte*/
	while ((P[p-1].DA > i)&&(P[p].DE!=1000)){ p++; }/*s'arrêter au premier processus pret , ayant une date d'arrivée inférierue à l'indice i (une durée quelconque) et vu que le tableau est trié , ce procesus va être un processus pret ayant la durée estimée la plus courte*/
		return P[p-1];
	
}
Processus& Tableau::MAX_P()
{
	Trie_P();
	return P[x-1];
}
void Processus::operator=(Processus& rhs) {
	nom = rhs.nom;
	DA = rhs.DA;
	DE = rhs.DE;
	Prio = rhs.Prio;
	FD = rhs.FD;
	DET = rhs.DET;
	DAT = rhs.DAT;
}
void Tableau::operator=(Tableau& rhs) {
	x = rhs.x;
	for (int i = 0; i < x; i++) 
	{
		P[i] = rhs.P[i];
	}
}
int Tableau::get_x()
{
	return this->x;
}
void Tableau::Saisir() {
	int Rep = 1, i = -1, a = 0;
	
	while (Rep != 0) {
		
		cout << "Voulez vous ajouter un processus ? (Taper 1 pour oui , 0 pour non)" << endl;
		cin >> Rep;
		if (Rep == 1) {
			i++;
			P[i].Saisie();
			x++;
		}
	}
}
void Tableau::afficher() {
	for (int t = 0; t < x; t++) { P[t].Affiche(); }
}
void Tableau::Diagramme()
{
	int z = P[0].DA;
	for (int t = 0; t < x; t++)
	{
		cout << "< " << P[t].nom << " > " << endl;
		cout << "          ( " << z << " ) " << endl;
		for (int a = 0; a < P[t].DE; a++)
		{
			cout << "                    *"<<endl;
					}
		z = z + P[t].DE;
		P[t].FD = z;
		cout << "          ( " << z << " ) "<<endl;
	}
	double Ta = 0, Tm = 0, TA = 0, TM = 0;
	for (int u = 0; u < x; u++)
	{
		Tm = P[u].FD - P[u].DAT;
		Ta = P[u].FD - P[u].DAT - P[u].DET;
		TA = TA + Ta;
		TM = TM + Tm;
		cout << "Le Processus " << P[u].nom << endl;
		cout << "Le Temps D'execution : " << Tm << endl;
		cout << "Le Temps D'attente : " << Ta << endl;
	}
	TM = TM / x;
	TA = TA / x;
	cout << "Le Temps Moyen D'execution" << endl;
	cout << "Tm = " << TM << endl;
	cout << "Le Temps Moyen D'attente" << endl;
	cout << "Ta = " << TA << endl;
}
void Tableau::afficher_FIFO() 
{cout<<"<<< Algorithme FIFO >>>"<<endl;
	Trie_DA();
  Diagramme();

}
void Tableau::afficher_RR() 
{
	cout << "<<< Algorithme RR >>>" << endl;
	int q, S = 0, A = 0;
	cout << "Taper un qunatum" << endl;
	cin >> q;
	Processus& Z = MIN_DA();
	A = Z.DA;
	for (int e = 0; e < x; e++) { S = S + P[e].DE; }/*Calculer la durée estimée totale des processus (S)*/
	S = S + A;
	while (S > A)/*A va prendre la durée de chaque processus au cours de l'algorithme , pour qu'on dépasse pas la durée totale des processus*/
	{
		Processus& Z = MIN_DA();
		
		if (Z.DE > q)/*Si la durée estimée du processus ayant la date d'arivée minimale est supérieure au quantum*/
		{
			Z.set_DE(Z.DE - q);/*diminiuer la duréé estimée du processus d'un quantum*/
			cout << Z.nom << endl;/*Affichage du nom*/
			cout << "          ( " << A << " ) " << endl;
			for (int a = 0; a < q; a++)/*affichage du diagramme*/
			{
				cout << "                    *" << endl;
			}
			A = A + q;/*Incrementation de A*/
			cout << "          ( " << A << " ) " << endl;
			Z.set_DA(A);/*Modifier la date d'arrivée du processus*/
		}
		else/*Si la durée estimée du processus ayant la date d'arivée minimale est inférieure au quantum*/
		{
			
			cout << Z.nom << endl;/*Affichage du nom*/
			cout << "          ( " << A << " ) " << endl;
			for (int a = 0; a < Z.DE; a++)/*affichage du diagramme*/
			{
				cout << "                    *" << endl;
			}
			A = A + Z.DE;/*Incrementation de A*/
			cout << "          ( " << A << " ) " << endl;
			Z.FD = A;
			Z.set_DE(-1);/*changer la valeur du durée estimée du processus avec -1 pour l'éliminier car la fonction ne prends pas en consideration les processus ayant des valeurs negatives*/
			Z.set_DA(1000);/*changer la valeur du durée estimée du processus avec 1000 pour l'éliminier*/
		}
	}

	double Ta = 0, Tm = 0, TA = 0, TM = 0;
	for (int u = 0; u < x; u++)
	{
		Tm = P[u].FD - P[u].DAT;
		Ta = P[u].FD - P[u].DAT - P[u].DET;
		TA = TA + Ta;
		TM = TM + Tm;
		cout << "Le Processus " << P[u].nom << endl;
		cout << "Le Temps D'execution : " << Tm << endl;
		cout << "Le Temps D'attente : " << Ta << endl;
	}
	TM = TM / x;
	TA = TA / x;
	cout << "Le Temps Moyen D'execution" << endl;
	cout << "Tm = " << TM << endl;
	cout << "Le Temps Moyen D'attente" << endl;
	cout << "Ta = " << TA << endl;
}
void Tableau::afficher_SJF()
{
	
	cout << "<<< Algorithme SJF >>>" << endl;
	Trie_DA();/*Trier le tableau de processus selon la date d'arrivée*/
	int A = P[0].DA;
	for (int u=0; u < x; u++)/*Parcourir le tableau de processus*/
	{
		Processus& Y = MIN_DE(A);
		cout << "< " << Y.nom << " > " << endl;/*la fonction d'indice A veut dire que cette fonction va chercher le processus ayant la durée estimée minimale tel que sa date d'arrivéé est inférieure ou égale à A (pret)*/
		cout << "          ( " << A << " ) " << endl;
		for (int a = 0; a < Y.DE; a++)/*Affichage du diagramme pour chaque processus*/
		{
			cout << "                    *" << endl;
		}
		A = A+ Y.DE;
		Y.FD = A;
		Y.set_DE(1000);/*augmenter la valeur de la duréé du processus afin de l'eliminer*/

				cout << "          ( " << A << " ) " << endl;

	}
	double Ta = 0, Tm = 0,TA=0,TM=0;
	for (int u = 0; u < x; u++)
	{
		Tm = P[u].FD - P[u].DA;
		Ta =  P[u].FD - P[u].DA - P[u].DET;
		TA = TA + Ta;
		TM = TM + Tm;
		cout << "Le Processus " << P[u].nom << endl;
		cout << "Le Temps D'execution : " <<Tm << endl;
		cout << "Le Temps D'attente : " << Ta << endl;
	}
	TM = TM / x;
	TA = TA / x;
	cout << "Le Temps Moyen D'execution"<<endl;
	cout << "Tm = " << TM << endl;
	cout << "Le Temps Moyen D'attente" << endl;
	cout << "Ta = " << TA << endl;
}
void Tableau::afficher_PCTER_AQ() 
{
	cout << "<<< Algorithme PCTER_AQ >>>" << endl;
	int q , S = 0;
	Trie_DA();/*Trier le tableau de processus selon la date d'arrivée*/
	int A = P[0].DA;
	for (int e = 0; e < x; e++) { S = S + P[e].DE; }
	cout << "Taper un quantum " << endl;
	cin >> q;
	while (S > A)
	{
		Processus& V = MIN_DE(A);
		if (V.DE > q)
		{
			V.set_DE(V.DE - q);

			cout << V.nom << endl;
			cout << "          ( " << A << " ) " << endl;
			for (int a = 0; a < q; a++)
			{
				cout << "                    *" << endl;
			}
			A = A + q;
			cout << "          ( " << A << " ) " << endl;
		}
		else if ((V.DE <= q) && (V.DE > 0))
		{


			cout << V.nom << endl;
			cout << "          ( " << A << " ) " << endl;
			for (int a = 0; a < V.DE; a++)
			{
				cout << "                    *" << endl;
			}
			A = A + V.DE;
			V.FD = A;
			cout << "          ( " << A << " ) " << endl;
			V.set_DE(1000);
		}
	}
	double Ta = 0, Tm = 0, TA = 0, TM = 0;
	for (int u = 0; u < x; u++)
	{
		Tm = P[u].FD - P[u].DAT;
		Ta = P[u].FD - P[u].DAT - P[u].DET;
		TA = TA + Ta;
		TM = TM + Tm;
		cout << "Le Processus " << P[u].nom << endl;
		cout << "Le Temps D'execution : " << Tm << endl;
		cout << "Le Temps D'attente : " << Ta << endl;
	}
	TM = TM / x;
	TA = TA / x;
	cout << "Le Temps Moyen D'execution" << endl;
	cout << "Tm = " << TM << endl;
	cout << "Le Temps Moyen D'attente" << endl;
	cout << "Ta = " << TA << endl;
}
void Tableau::afficher_PCTER_SQ()
{
	cout << "<<< Algorithme PCTER_SQ >>>" << endl;
	int q=1, S = 0;
	Trie_DA();/*Trier le tableau de processus selon la date d'arrivée*/
	int A = P[0].DA;
	for (int e = 0; e < x; e++) { S = S + P[e].DE; }
	while (S > A)
	{
		Processus& V = MIN_DE(A);
		if (V.DE > q)
		{
			V.set_DE(V.DE - q);

			cout << V.nom << endl;
			cout << "          ( " << A << " ) " << endl;
			for (int a = 0; a < q; a++)
			{
				cout << "                    *" << endl;
			}
			A = A + q;
			cout << "          ( " << A << " ) " << endl;
		}
		else if ((V.DE <= q) && (V.DE > 0))
		{


			cout << V.nom << endl;
			cout << "          ( " << A << " ) " << endl;
			for (int a = 0; a < V.DE; a++)
			{
				cout << "                    *" << endl;
			}
			A = A + V.DE;
			V.FD = A;
			cout << "          ( " << A << " ) " << endl;
			V.set_DE(1000);
		}
	}
	double Ta = 0, Tm = 0, TA = 0, TM = 0;
	for (int u = 0; u < x; u++)
	{
		Tm = P[u].FD - P[u].DAT;
		Ta = P[u].FD - P[u].DAT - P[u].DET;
		TA = TA + Ta;
		TM = TM + Tm;
		cout << "Le Processus " << P[u].nom << endl;
		cout << "Le Temps D'execution : " << Tm << endl;
		cout << "Le Temps D'attente : " << Ta << endl;
	}
	TM = TM / x;
	TA = TA / x;
	cout << "Le Temps Moyen D'execution" << endl;
	cout << "Tm = " << TM << endl;
	cout << "Le Temps Moyen D'attente" << endl;
	cout << "Ta = " << TA << endl;
}
void Tableau::Saisir_P()
{
	int pr;
	for (int t = 0; t < x; t++) {
		cout << "Taper la priorite du processus " << P[t].nom << endl;
		cin >> pr;
		P[t].Prio=pr;
	}
}
void Tableau::afficher_Priorité_Statique()
{
	cout << "<<< Algorithme Priorité_Statique >>>" << endl;
	Trie_PD();
	Diagramme();
}
void Tableau::afficher_Priorité_Dynamique()
{
	cout << "<<< Algorithme Priorité_Dynamique >>>" << endl;
	
	Processus& D = MAX_P();
	int q, S = 0, A = D.DA;
	cout << "Taper un qunatum" << endl;
	cin >> q;
	for (int e = 0; e < x; e++) { S = S + P[e].DE; }
	S = S + A;
	while (S > A)
	{
		Processus& D = MAX_P();
		if (D.DE > q)
		{
			D.set_DE(D.DE - q);
			cout << D.nom << endl;
			cout << "          ( " << A << " ) " << endl;
			for (int a = 0; a < q; a++)
			{
				cout << "                    *" << endl;
			}
			A = A + q;
			cout << "          ( " << A << " ) " << endl;
			D.set_P(D.Prio - 1);
		}
		else if((D.DE <= q) && (D.DE > 0))
		{
			
			
			cout << D.nom << endl;
			cout << "          ( " << A << " ) " << endl;
			for (int a = 0; a < D.DE; a++)
			{
				cout << "                    *" << endl;
			}
			A = A + D.DE;
			D.FD = A;
			cout << "          ( " << A << " ) " << endl;
			D.set_DE(-1);
			D.set_P(-100);
		}
	}
	double Ta = 0, Tm = 0, TA = 0, TM = 0;
	for (int u = 0; u < x; u++)
	{
		Tm = P[u].FD - P[u].DAT;
		Ta = P[u].FD - P[u].DAT - P[u].DET;
		TA = TA + Ta;
		TM = TM + Tm;
		cout << "Le Processus " << P[u].nom << endl;
		cout << "Le Temps D'execution : " << Tm << endl;
		cout << "Le Temps D'attente : " << Ta << endl;
	}
	TM = TM / x;
	TA = TA / x;
	cout << "Le Temps Moyen D'execution" << endl;
	cout << "Tm = " << TM << endl;
	cout << "Le Temps Moyen D'attente" << endl;
	cout << "Ta = " << TA << endl;
}