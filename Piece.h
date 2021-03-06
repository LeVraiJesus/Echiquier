/** 
 * Header de Piece.cxx
 *
 * @file Piece.h
 */

#if !defined Piece_h
#define Piece_h

//#include "Echiquier.h"
class Echiquier;

/**
 * Declaration d'une classe mod�lisant une piece de jeu d'echec.
 */
class Piece 
{
protected:
  int m_x;
  int m_y;
  bool m_white;
  int nb_mouv;
  
public:
  Piece();
  virtual ~Piece();
  Piece(const Piece & autre);
  Piece( int x, int y, bool white );
  Piece & operator=(const Piece & autre);
  void init( int x, int y, bool white );
  void move( int x, int y );
  int x();
  int y();
  bool isWhite();
  bool isBlack();
  void affiche();
  Piece plusforte(const Piece & p) const;
  virtual bool mouvementValide(Echiquier &e, int x, int y);
  virtual char myCode();
}; 

class Roi : public Piece
{
 public:
  Roi(bool white);
  bool mouvementValide(Echiquier &e, int x, int y);
  char myCode();
};

class Tour : public virtual Piece
{
 public:
  Tour(bool white, bool left);
  bool mouvementValide(Echiquier &e, int x, int y);
  char myCode();
};

class Fou : public virtual Piece
{
 public:
  Fou(bool white, bool left);
  bool mouvementValide(Echiquier &e, int x, int y);
  char myCode();
};

class Reine : public Tour, public Fou
{
 public:
  Reine(bool white);
  bool mouvementValide(Echiquier &e, int x, int y);
  char myCode();
};

class Cavalier : public Tour
{
 public:
  Cavalier(bool white, bool left);
  bool mouvementValide(Echiquier &e, int x, int y);
  char myCode();
};

#endif // !defined Piece_h
