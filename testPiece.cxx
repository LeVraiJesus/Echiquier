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

		if(posCin<11 || posCin>88){
		    enter=false;
        }else {
            xDepart=(posCin/10)%10;
            yDepart=posCin%10;
            enter=true;
        }

		(posCin<11 || posCin>88)?cout << "position hors map" <<endl:cout << ""<<endl;


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

	e->deplacer(e->getPiece(1,1),4,4);
	e->affiche();

    bool selectionOk =false;

	while(!end)
	{
	    //Affectation variable de jeu
		rndIsWhite = (round%2==1);

        xDepart = 0;
        yDepart = 0;
        selectionOk =false;

		//mise en page du debut de round
		cout<<""<<endl;
		(rndIsWhite)?(cout<< "Joueur blanc" <<endl):(cout<< "Joueur noir" <<endl);


		//selection des 2 positions tant que la case de départ ne comporte pas de piéce valide
		while( !selectionOk )
		{
		    if( xDepart == 0 && yDepart ==0 )
            {
                selectCaseParJoueur(xDepart,yDepart,xArrive,yArrive);
            }

		    if(e->getPiece(xDepart,yDepart)==NULL){
                cout << "Aucune piece selectionne" << endl;
                selectCaseParJoueur(xDepart,yDepart,xArrive,yArrive);
                selectionOk =false;
		    }else if(e->getPiece(xDepart,yDepart)!=NULL){
		        if((rndIsWhite)?(e->getPiece(xDepart,yDepart)->isWhite()):(!e->getPiece(xDepart,yDepart)->isWhite()))
                {
                    selectionOk = true;
                }else{
                    cout << "Cette piece n'est pas dans votre jeu" << endl;
                    selectionOk =false;
                }
		    }
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
