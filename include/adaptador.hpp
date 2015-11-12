#ifndef DEFAULT_H
#define DEFAULT_H
#include "default.hpp"
#endif

#ifndef ADAPTADOR_H
#define ADAPTADOR_H

class Adaptador {
  private:
    string nome;
    int pos_x;
    int pos_y;
  public:
    string getNome() {return nome;}
    int getPosX() {return pos_x;}
    int getPosY() {return pos_y;}

    Adaptador(string, int, int);
};

#endif
