#include <iostream>
#include <string>
#include <Windows.h>
#define LONGEUR 10
#define MAX 20
using namespace std;
class Processus
{
	friend class Tableau;
private:
	string nom;
	int DA;
	int DE;
	int Prio;
	int FD;
	int DET;
	int DAT;
	
public:
	Processus();
	void Saisie();
	void Affiche();
	string get_nom();
	int get_DA();
	int get_Prio();
	int get_DE();
	void set_DE(int x);
	void set_DA(int x);
	void set_P(int x);
	void operator=(Processus& rhs);
};
class Tableau
{
	friend class Processus;
	Processus P[MAX];
	int x;
	public:
	Tableau();
	void Saisir();
	void afficher();
	Processus& MIN_DA();
	Processus& MIN_DE(int i);
	Processus& MAX_P();
	void operator=(Tableau & rhs);
	int get_x();
	void Trie_DE();
	void Trie_DA();
	void Trie_P();
	void Trie_PD();
	void Diagramme();
	void afficher_FIFO();
	void afficher_RR();
	void afficher_SJF();
	void afficher_PCTER_AQ();
	void afficher_PCTER_SQ();
	void Saisir_P();
	void afficher_Priorité_Statique();
	void afficher_Priorité_Dynamique();
};

