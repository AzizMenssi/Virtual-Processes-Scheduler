

#include "biblio.h"
using namespace std;
void main() {
	system("color 30");
	cout << "                          << Programme Ordonnanceur >>                          " << endl << endl << endl << endl << endl << endl;
	int pause, Rep, Rep1 = 1, Rep2 = 1, i = 1,Repp=0,Repd=0;
	Tableau T,K;
	T.Saisir();
	T.afficher();
	K = T;
	
		cout <<" Vous pouvez gerer ces processus selon plusieurs algorithmes" << endl;
		cout << " Taper 1 pour choisir l'algorithme FIFO" << endl;
		cout << " Taper 2 pour choisir l'algorithme SJF" << endl;
		cout << " Taper 3 pour choisir l'algorithme RR" << endl;
		cout << " Taper 4 pour choisir l'algorithme PCTER" << endl;
		cout << " Taper 5 pour choisir l'algorithme Priorite" << endl;
		cin >> Rep;
		if (Rep == 1) { T.afficher_FIFO(); }
		else if (Rep == 2) { T.afficher_SJF();}
		else if (Rep == 3) { T.afficher_RR(); }
		else if (Rep == 4)
		{
			cout << "Taper 1 pour 'version sans quantum (SRT) '" << endl;
			cout << "Taper 2 pour 'version avec quantum '" << endl;
			cin >> Repd;
			if (Repd == 1) { T.afficher_PCTER_SQ(); }
			else if (Repd == 2) { T.afficher_PCTER_AQ(); }
		}
		else if (Rep == 5)
		{
			cout << "La priorite des processus est croissante entre 0 et 20 " << endl;
			T.Saisir_P();
			cout << "Taper 1 pour 'Statique'" << endl;
			cout << "Taper 2 pour 'Dynamique'" << endl;
			cin >> Repp;
			if (Repp == 1) { T.afficher_Priorité_Statique(); }
			else if (Repp == 2) {T.afficher_Priorité_Dynamique(); }
		}
		
	while (Rep1 != 0) {
		Tableau A = K;
		cout << "Voulez vous utiliser un autre algorithme ? (Taper 1 pour oui , 0 pour non)" << endl;
		cin >> Rep1;
		if (Rep1 == 1) {
			cout << " Taper 1 pour choisir l'algorithme FIFO" << endl;
			cout << " Taper 2 pour choisir l'algorithme SJF" << endl;
			cout << " Taper 3 pour choisir l'algorithme RR" << endl;
			cout << " Taper 4 pour choisir l'algorithme PCTER" << endl;
			cout << " Taper 5 pour choisir l'algorithme Priorite" << endl;
			cin >> Rep;
			if (Rep == 1) { A.afficher_FIFO(); }
			else if (Rep == 2) { A.afficher_SJF(); }
			else if (Rep == 3 ) { A.afficher_RR(); }
			else if (Rep == 4)
			{
				cout << "Taper 1 pour 'version sans quantum (SRT) '" << endl;
				cout << "Taper 2 pour 'version avec quantum '" << endl;
				cin >> Repd;
				if (Repd == 1) { A.afficher_PCTER_SQ(); }
				else if (Repd == 2) { A.afficher_PCTER_AQ(); }
			}
			else if (Rep == 5) 
			{
				cout << "La priorite des processus est croissante entre 0 et 20 " << endl;
				A.Saisir_P();
				cout << "Taper 1 pour 'Statique'" << endl;
				cout << "Taper 2 pour 'Dynamique'" << endl;
				cin >> Repp;
				if (Repp == 1) { A.afficher_Priorité_Statique(); }
				else if (Repp == 2) {A.afficher_Priorité_Dynamique(); }
				}
	
		}
	}
	cin >> pause;
}
