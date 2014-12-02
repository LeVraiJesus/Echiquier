/**
 * Mise en oeuvre de Piece.h
 *
 * @file Piece.cxx
 */

#include <iostream>
// A besoin de la declaration de la classe
#include "Piece.h"
#include "Echiquier.h"

using namespace std;

Piece::Piece()
{
  // ne fait rien => objet instancie mais non valide.
 // cout << "Constructeur Piece" << endl;
}

Piece::~Piece()
{
  //cout << "Destructeur Piece" << endl;
}

Piece::Piece(const Piece & autre)
{
  m_x = autre.m_x;
  m_y = autre.m_y;
  m_white = autre.m_white;
  nb_mouv = 0;
  //cout << "Constructeur Piece par copie" << endl;
}

Piece &
Piece::operator=(const Piece & autre)
{
  m_x = autre.m_x;
  m_y = autre.m_y;
  m_white = autre.m_white;
  //cout << "Affectation Piece" << endl;
  return *this;
}

Piece::Piece( int x, int y, bool white )
{
  m_x = x;
  m_y = y;
  m_white = white;
  //cout << "Constructeur Piece specialise" << endl;
}

void
Piece::init( int x, int y, bool white )
{
  m_x = x;
  m_y = y;
  m_white = white;
}

void
Piece::move( int x, int y )
{
  m_x = x;
  m_y = y;
}

int
Piece::x()
{
  return m_x;
}

int
Piece::y()
{
  return m_y;
}

bool
Piece::isWhite()
{
  return m_white;
}

bool
Piece::isBlack()
{
  return !m_white;
}

void
Piece::affiche()
{
  cout << "Piece: x=" << m_x << " y=" << m_y << " "
       << ( m_white ? "B" : "N" ) << endl;
}

Piece
Piece::plusforte(const Piece & p) const
{
  cout << "plusforte" << endl;
  if (true) return p;
  return *this;
}

bool
Piece::mouvementValide(Echiquier &e, int x, int y)
{
	nb_mouv ++;
	if(this->isWhite()){
		cout << "pion blanc joue" <<endl;
		if(nb_mouv==1 && y<=this->m_y+2 && y>=this->m_y ){
			cout << "Mouvement Valide Pion blanc premier deplacement" << endl;
			return true;
		}
		else if ( y<=this->m_y+1 && y>=this->m_y ) {
			cout << "Mouvement Valide Pion blanc" << endl;
			return true;
		}
	}
	if(this->isBlack()){
		if(nb_mouv==1 && y>=this->m_y-2 && y<=this->m_y ){
			cout << "Mouvement Valide Pion noir premier deplacement" << endl;
			return true;
		}
		else if ( y>=this->m_y-1 && y<=this->m_y ) {
			cout << "Mouvement Valide Pion noir" << endl;
			return true;
		}
	}

	nb_mouv --;
	cout << "Mouvement invalide Pion" << endl;
	return false;
}

char
Piece::myCode()
{
  return (m_white)?'B':'N';
}

Roi::Roi(bool white) : Piece(5,(white)?1:8,white)
{
  //cout << "Constructeur Roi" << endl;
}

bool
Roi::mouvementValide(Echiquier &e, int x, int y)
{
    if( x>=this->m_x-1 && x<=this->m_x+1 && y>=this->m_y-1 && y<=this->m_y+1){
        cout << "Mouvement Valide Roi ";
        (this->m_white)?(cout << "Blanc"<< endl):(cout << "Noir"<< endl);
        return true;
    }

    cout << "Mouvement Invalide Roi ";
    (this->m_white)?(cout << "Blanc"<< endl):(cout << "Noir"<< endl);
    return false;
}

char
Roi::myCode()
{
  return (m_white)?'R':'r';
}

Tour::Tour(bool white,bool left) : Piece((left)?1:8,(white)?1:8,white)
{
 // cout << "Constructeur Tour" << endl;
}

bool
Tour::mouvementValide(Echiquier &e, int x, int y)
{
    int * out = NULL;

    if( (x>this->m_x && y==this->m_y) || (x<this->m_x && y==this->m_y) || (x==this->m_x && y>this->m_y) || (x==this->m_x && y<this->m_y) )
    	out = e.getCaseDirection(this->m_x,this->m_y,x,y);

    if(out!=NULL){
        cout << "Mouvement Valide Tour, max : " << out[0] << " " << out[1] << endl;
        return true;
    }

    cout << "Mouvement Invalide Tour" << endl;
    return false;
}

char
Tour::myCode()
{
  return (m_white)?'T':'t';
}

Fou::Fou(bool white,bool left) : Piece((left)?3:6,(white)?1:8,white)
{
  //cout << "Constructeur Fou" << endl;
}

bool
Fou::mouvementValide(Echiquier &e, int x, int y)
{
    int * out = NULL;
    if((x>this->m_x && y>this->m_y) || (x<this->m_x && y>this->m_y) || (x<this->m_x && y<this->m_y) || (x>this->m_x && y<this->m_y))
    	out = e.getCaseDirection(this->m_x,this->m_y,x,y);

    if(out!=NULL){
        cout << "Mouvement Valide Fou, max : " << out[0] << " " << out[1] << endl;
        return true;
    }

    cout << "Mouvement Invalide Fou" << endl;
    return false;
}

char
Fou::myCode()
{
  return (m_white)?'F':'f';
}

Reine::Reine(bool white) : Piece(4,(white)?1:8,white), Tour(white,true), Fou(white,true)
{
  //cout << "Constructeur Reine" << endl;
}

bool
Reine::mouvementValide(Echiquier &e, int x, int y)
{
  if(Tour::mouvementValide(e,x,y) || Fou::mouvementValide(e,x,y)){
	  cout << "Mouvement Valide Reine" << endl;
	  return true;
  }
  cout << "Mouvement Invalide Reine" << endl;
  return false;
}

char
Reine::myCode()
{
  return (m_white)?'Q':'q';
}

Cavalier::Cavalier(bool white, bool left) : Piece((left)?2:7,(white)?1:8,white), Tour(white,left)
{
	//cout << "Constructeur Cavalier" << endl;
}

bool
Cavalier::mouvementValide(Echiquier &e, int x, int y)
{
	 cout << "Mouvement Valide Cavalier" << endl;
	 return true;
}

char
Cavalier::myCode()
{
  return (m_white)?'C':'c';
}
