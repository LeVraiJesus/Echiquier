/**
 * Mise en oeuvre de Echiquier.h
 *
 * @file Echiquier.cxx
 */

#include <iostream>

// A besoin de la declaration de la classe
#include "Echiquier.h"

using namespace std;

/**
 * Constructeur par défaut.
 * Initialise à vide l'echiquier.
 */
Echiquier::Echiquier()
{
  for (int i=0;i<64;i++)
    m_cases[i]=NULL;
}


/**
 * Recupere la piece situee sur une case.
 *
 * @param x un entier entre 1 et 8
 * @param y un entier entre 1 et 8
 *
 * @return 0 si aucune piece n'est sur cette case et un pointeur
 * vers une piece sinon.
 */
Piece*
Echiquier::getPiece( int x, int y )
{
  if ((x>=1) && (x<=8) && (y>=1) && (y<=8))
    return m_cases[(x-1)+8*(y-1)];
  return NULL;
}

/**
 * renvoi la case la plus éloigner accessible
 * depuis une position initial dans la direction voulu
 *
 * @param x un entier entre 1 et 8
 * @param y un entier entre 1 et 8
 * @param aX un entier entre 1 et 8
 * @param aY un entier entre 1 et 8
 *
 * @return 0 si aucune case n'est disponible dans cette
 * direction retourne un tableau de 2 entier x et y.
 */
int*
Echiquier::getCaseDirection( int x, int y, int aX, int aY )
{
  int* tabOut = new int[2];
  tabOut[0] = x;
  tabOut[1] = y;
  int dirX;
  int dirY;

  if( aX > x )
	  dirX = 1;
  else if( aX == x)
	  dirX = 0;
  else if( aX < x )
	  dirX = -1;

  if( aY > y )
	  dirY = 1;
  else if( aY == y)
	  dirY = 0;
  else if( aY < y )
	  dirY = -1;

  if ((x>=1) && (x<=8) && (y>=1) && (y<=8)){
    if((dirX>=-1) && (dirX<=1) && (dirY>=-1) && (dirY<=1)){
        if(dirX!=0 && dirY!=0){//diagonales
            if(dirX > 0 && dirY > 0)//bas droite
            {
                bool end=false;
                bool goodMove=false;
                while(!end){
                    if(tabOut[0]+1>=1 && tabOut[0]+1<=8 && tabOut[1]+1>=1 && tabOut[1]+1<=8) {
                        tabOut[0]++;
                        tabOut[1]++;
                        if( tabOut[0]==aX && tabOut[1]==aY )
                        	goodMove=true;
                    }
                    else {
                        end=true;
                    }

                    if(this->getPiece(tabOut[0],tabOut[1])!=NULL){
                        end=true;
//                        tabOut[0]--;
//                        tabOut[1]--;
                    }
                }
                if((tabOut[0]==x&&tabOut[1]==y)||(!goodMove)){return NULL;}else{return tabOut;}
            } else if(dirX < 0 && dirY > 0) {//bas gauche
                bool end=false;
                bool goodMove=false;
                while(!end){
                    if(tabOut[0]-1>=1 && tabOut[0]-1<=8 && tabOut[1]+1>=1 && tabOut[1]+1<=8) {
                        tabOut[0]--;
                        tabOut[1]++;
                        if( tabOut[0]==aX && tabOut[1]==aY )
                        	goodMove=true;
                    }
                    else {
                        end=true;
                    }

                    if(this->getPiece(tabOut[0],tabOut[1])!=NULL){
                        end=true;
//                        tabOut[0]++;
//                        tabOut[1]--;
                    }
                }
                if((tabOut[0]==x&&tabOut[1]==y)||(!goodMove)){return NULL;}else{return tabOut;}
            } else if(dirX < 0 && dirY < 0) {//haut gauche
                bool end=false;
                bool goodMove=false;
                while(!end){
                    if(tabOut[0]-1>=1 && tabOut[0]-1<=8 && tabOut[1]-1>=1 && tabOut[1]-1<=8) {
                        tabOut[0]--;
                        tabOut[1]--;
                        if( tabOut[0]==aX && tabOut[1]==aY )
                        	goodMove=true;
                    }
                    else {
                        end=true;
                    }

                    if(this->getPiece(tabOut[0],tabOut[1])!=NULL){
                        end=true;
//                        tabOut[0]++;
//                        tabOut[1]++;
                    }
                }
                if((tabOut[0]==x&&tabOut[1]==y)||(!goodMove)){return NULL;}else{return tabOut;}
            } else if(dirX > 0 && dirY < 0) {//haut droite
                bool end=false;
                bool goodMove=false;
                while(!end){
                    if(tabOut[0]+1>=1 && tabOut[0]+1<=8 && tabOut[1]-1>=1 && tabOut[1]-1<=8) {
                        tabOut[0]++;
                        tabOut[1]--;
                        if( tabOut[0]==aX && tabOut[1]==aY )
                        	goodMove=true;
                    }
                    else {
                        end=true;
                    }

                    if(this->getPiece(tabOut[0],tabOut[1])!=NULL){
                        end=true;
//                        tabOut[0]--;
//                        tabOut[1]++;
                    }
                }
                if((tabOut[0]==x&&tabOut[1]==y)||(!goodMove)){return NULL;}else{return tabOut;}
            }
        } else {//Colonnes
            if(dirX!=0){
                if( dirX < 0){//gauche
                    bool end=false;
                    while(!end){
                        if(tabOut[0]-1>=1 && (tabOut[0]-1<=8))
                            tabOut[0]--;
                        else {
                            end=true;
                        }

                        if(this->getPiece(tabOut[0],tabOut[1])!=NULL){
                            end=true;
//                            tabOut[0]++;
                        }
                    }
                    if(tabOut[0]==x){return NULL;}else{return tabOut;}
                } else if( dirX > 0){//droite
                    bool end=false;
                    while(!end){
                        if(tabOut[0]+1>=1 && (tabOut[0]+1<=8))
                            tabOut[0]++;
                        else {
                            end=true;
                        }

                        if(this->getPiece(tabOut[0],tabOut[1])!=NULL){
                            end=true;
//                            tabOut[0]--;
                        }
                    }
                    if(tabOut[0]==x){return NULL;}else{return tabOut;}
                }
            } else if (dirY!=0) {
                if( dirY < 0 ){//bas
                    bool end=false;
                    while(!end){
                        if(tabOut[1]-1>=1 && (tabOut[1]-1<=8))
                            tabOut[1]--;
                        else {
                            end=true;
                        }

                        if(this->getPiece(tabOut[0],tabOut[1])!=NULL){
//                            tabOut[1]++;
                            end=true;
                        }
                    }
                    if(tabOut[1]==y){return NULL;}else{return tabOut;}
                } else if( dirY > 0 ){//haut
                    bool end=false;
                    while(!end){
                        if(tabOut[1]+1>=1 && (tabOut[1]+1<=8))
                            tabOut[1]++;
                        else {
                            end=true;
                        }

                        if(this->getPiece(tabOut[0],tabOut[1])!=NULL){
                            end=true;
//                            tabOut[1]--;
                        }
                    }
                    if(tabOut[1]==y){return NULL;}else{return tabOut;}
                }
            }
        }
    } else {
        cout << "getCaseDirection : direction invalide" << endl;
    }
  } else {
    cout << "getCaseDirection : position invalide" << endl;
  }

//return m_cases[(x-1)+8*(y-1)];
//return NULL;
}


/**
 * Place une piece sur l'echiquier, aux coordonnees specifiees dans la piece.
 *
 * @param p un pointeur vers une piece
 *
 * @return 'true' si le placement s'est bien passe, 'false' sinon
 * (case occupee, coordonnees invalides, piece vide )
 */
bool
Echiquier::placer( Piece* p )
{
  if (p==NULL) return false;
  if ((p->x()>=1) && (p->x()<=8) && (p->y()>=1) && (p->y()<=8) &&
      m_cases[(p->x()-1)+8*(p->y()-1)]==NULL)
    {
      m_cases[(p->x()-1)+8*(p->y()-1)]=p;
      return true;
    }
  return false;
}


/**
 * Deplace une piece sur l'echiquier, des coordonnees specifiees
 * dans la piece aux coordonnees x,y.
 *
 * @param p un pointeur vers une piece
 * @param x un entier entre 1 et 8
 * @param y un entier entre 1 et 8
 *
 * @return 'true' si le placement s'est bien passe, 'false' sinon
 * (case occupee, coordonnees invalides, piece vide, piece pas
 * presente au bon endroit sur l'echiquier)
 */
bool
Echiquier::deplacer( Piece* p, int x, int y )
{
	Piece * tmp = enleverPiece(p->x(),p->y());
	tmp->move(x,y);
	placer(tmp);
}

/**
 * Enleve la piece situee sur une case (qui devient vide).
 *
 * @param x un entier entre 1 et 8
 * @param y un entier entre 1 et 8
 *
 * @return 0 si aucune piece n'est sur cette case et le pointeur
 * vers la piece enlevee sinon.
 */
Piece*
Echiquier::enleverPiece( int x, int y )
{
  if ( ( x >= 1 ) && ( x <= 8 )
       && ( y >= 1 ) && ( y <= 8 )
       && ( getPiece( x, y ) != NULL ) )
    {
      Piece *tmp;
      tmp=m_cases[ x - 1 + ( y - 1 ) * 8 ];
      m_cases[ x - 1 + ( y - 1 ) * 8 ] = NULL;
      return tmp;
    }
  return NULL;
}


/**
 * Affiche l'echiquier avec des # pour les cases noires et . pour
 * les blanches si elles sont vides, et avec B pour les pieces
 * blanches et N pour les pieces noires.
 */
void
Echiquier::affiche()
{
  cout << endl << "  12345678" << endl;
  for ( int y = 1; y <= 8; ++y )
    {
      cout << y << " ";
      for ( int x = 1; x <= 8; ++x )
	{
	  char c;
	  Piece* p = getPiece( x, y );
	  if ( p == 0 )
	    c = ( ( x + y ) % 2 ) == 0 ? '#' : '.';
	  else
	    c = p->myCode();
	  cout << c;
	}
      cout << " " << y << endl;
    }
  cout << "  12345678" << endl;
}



