/**
 * Header de Joueur.cxx
 *
 * @file Joueur.h
 */

#if !defined Joueur_h
#define Joueur_h

#include "Piece.h"
#include "Echiquier.h"
#include <vector>

using namespace std;

/**
 * Declaration d'une classe modelisant un joueur.
 */
class Joueur
{
 protected:
  //Piece m_pieces[ 16 ];
  vector<Piece*> m_pieces;

 public:
 ~Joueur();
  Joueur();
  Joueur( bool white );

  virtual bool isWhite()=0;
  void affiche();
  void placerPieces(Echiquier &e);
};

class JoueurBlanc : public Joueur
{
 public:
  JoueurBlanc();
  bool isWhite();
};

class JoueurNoir : public Joueur
{
 public:
  JoueurNoir();
  bool isWhite();
};

#endif
