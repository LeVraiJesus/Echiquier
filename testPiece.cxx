/** 
 * Programme test de Piece
 *
 * @file testPiece.cxx
 */

// Utile pour l'affichage
#include <iostream>
#include "Piece.h"
#include "Joueur.h"
#include "Echiquier.h"
#include <sstream>
#include <string>
#include <stdlib.h>


// Pour utiliser les flux de iostream sans mettre "std::" tout le temps.
using namespace std;

bool compare(Piece p, Piece q)
{
  return ((p.x()==q.x()) && (p.y()==q.y()));
}

Piece* allouePiece( int x, int y, bool white )
{
  Piece* ptr = new Piece( x, y, white );
  return ptr; 
}

void initJeu( JoueurBlanc * jb, JoueurNoir * jn, Echiquier * e)
{
	  jn->affiche();
	  jb->affiche();

	  jb->placerPieces(*e);
	  jn->placerPieces(*e);

	  e->affiche();
}

void selectCaseParJoueur(int & xDepart,int & yDepart,int & xArrive,int & yArrive)
{
	bool enter=false;
	int posCin=0;
	//Boucle selectionnement de case de départ
	enter = false;
	while (!enter){
		cout << "Entrez la case de depart a selectionner (votre piece)" << endl;
		cin >> posCin;

		(posCin<11 || posCin>88)?enter=false:enter=true;

		(posCin<11 || posCin>88)?cout << "position hors map" <<endl:cout << ""<<endl;

		xDepart=(posCin/10)%10;
		yDepart=posCin%10;
	}

	//Boucle selectionnement de case d'arrive
	enter = false;
	while (!enter){
		cout << "Entrez la case d'arrive a selectionner" << endl;
		cin >> posCin;

		(posCin<11 || posCin>88)?enter=false:enter=true;

		(posCin<11 || posCin>88)?cout << "position hors map" <<endl:cout << ""<<endl;

		xArrive=(posCin/10)%10;
		yArrive=posCin%10;
	}
}

/**
 * Programme principal
 */
int main( int argc, char** argv )
{
	//CrÃ©ation Joueurs
	JoueurBlanc * jb = new JoueurBlanc();
	JoueurNoir * jn = new JoueurNoir();

	//creation echiquier
	Echiquier * e = new Echiquier();

	//Initialisation du plateau
	initJeu(jb,jn,e);

	//
	bool end=false;
	bool rndIsWhite=false;
	int round=1;
	int xDepart=0;
	int yDepart=0;
	int xArrive=0;
	int yArrive=0;

	/*cout << jb->getM_Pieces().size() << endl;
	
	for(int i=0; i<16; i++){
		cout << i << " " << jb->getM_Pieces()[i]->myCode() << endl;
	}*/
	
	while(!end)
	{
		rndIsWhite = (round%2==1);

		//mise en page du debut de round
		cout<<""<<endl;
		(rndIsWhite)?(cout<< "Joueur blanc" <<endl):(cout<< "Joueur noir" <<endl);


		//selection des 2 positions tant que la case de départ ne comporte pas de piéce valide
		selectCaseParJoueur(xDepart,yDepart,xArrive,yArrive);
		while( e->getPiece(xDepart,yDepart)==0 || (rndIsWhite)?(false==e->getPiece(xDepart,yDepart)->isWhite()):(true==e->getPiece(xDepart,yDepart)->isWhite()))
		{
			selectCaseParJoueur(xDepart,yDepart,xArrive,yArrive);
		}
		

		//deplacement de la piece
		if(e->getPiece(xDepart,yDepart)->mouvementValide(*e,xArrive,yArrive)){
			e->deplacer(e->getPiece(xDepart,yDepart), xArrive, yArrive);
			round++;
		}else{
			cout << "Veuillez selectionner un mouvement valide" << endl;
		}


		//
		e->affiche();
	}
	
	delete jb;
	delete jn;
	delete e;
	
}
