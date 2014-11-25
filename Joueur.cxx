#include <iostream>
#include "Joueur.h"

// Pour utiliser les flux de iostream sans mettre "std::" tout le temps.
using namespace std;

Joueur::Joueur()
{
  cout << "Constructeur Joueur" << endl;
}

Joueur::~Joueur()
{
  vector<Piece*>::iterator p = m_pieces.begin();
  while ( p != m_pieces.end() )
    {
      delete *p;
      p++;
    }
  cout << "Destructeur Joueur" << endl;
}

Joueur::Joueur(bool white)
{}

/*
bool
Joueur::isWhite()
{
  return m_pieces[0].isWhite();
}
*/

void
Joueur::affiche()
{
  vector<Piece*>::iterator p = m_pieces.begin();
  while ( p != m_pieces.end() )
    {
      (*p)->affiche();
      cout << (*p)->myCode() << endl;
      p++;
    }
  /*
  for (int i=0;i<16;i++)
  m_pieces[i].affiche();
  */
}

void 
Joueur::placerPieces(Echiquier &e)
{
  vector<Piece*>::iterator p = m_pieces.begin();
  while ( p != m_pieces.end() )
    {
      e.placer(*p);
      p++;
    }
  /*
  for (int i=0; i<16; i++)
  e.placer(m_pieces+i);
  */
}

vector<Piece*>
Joueur::getM_Pieces()
{
	return m_pieces;
}

JoueurBlanc::JoueurBlanc() //: Joueur(true)
{
  Roi *pr = new Roi(true);
  Reine *pq = new Reine(true);
  Cavalier *pcl = new Cavalier(true,true);
  Cavalier *pcr = new Cavalier(true,false);
  Fou *pfl = new Fou(true,true);
  Fou *pfr = new Fou(true,false);
  Tour *ptl = new Tour(true,true);
  Tour *ptr = new Tour(true,false);

  m_pieces.push_back(pr);
  m_pieces.push_back(pq);
  m_pieces.push_back(pcl);
  m_pieces.push_back(pcr);
  m_pieces.push_back(pfl);
  m_pieces.push_back(pfr);
  m_pieces.push_back(ptl);
  m_pieces.push_back(ptr);

  for (int i=1; i<=8; i++)
    {
      Piece *p = new Piece(i,2,true);
      m_pieces.push_back(p);
    }
  cout << "Constructeur Joueur Blanc" << endl;
}

JoueurNoir::JoueurNoir() //: Joueur(false)
{
  Roi *pr = new Roi(false);
  Reine *pq = new Reine(false);
  Cavalier *pcl = new Cavalier(false,true);
  Cavalier *pcr = new Cavalier(false,false);
  Fou *pfl = new Fou(false,true);
  Fou *pfr = new Fou(false,false);
  Tour *ptl = new Tour(false,true);
  Tour *ptr = new Tour(false,false);

  m_pieces.push_back(pr);
  m_pieces.push_back(pq);
  m_pieces.push_back(pcl);
  m_pieces.push_back(pcr);
  m_pieces.push_back(pfl);
  m_pieces.push_back(pfr);
  m_pieces.push_back(ptl);
  m_pieces.push_back(ptr);

  for (int i=1; i<=8; i++)
    {
      Piece *p = new Piece(i,7,false);
      m_pieces.push_back(p);
    }
  cout << "Constructeur Joueur Noir" << endl;
}

bool
JoueurBlanc::isWhite()
{
  return true;
}

bool
JoueurNoir::isWhite()
{
  return false;
}
