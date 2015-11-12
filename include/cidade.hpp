#ifndef DEFAULT_H
#define DEFAULT_H
#include "default.hpp"
#endif

#ifndef CIDADE_H
#define CIDADE_H

class Cidade {
  private:
    string nome;
    int pos_x;
    int pos_y;
    int recurso_necessario;
  public:
    string getNome() {return nome;}
    int getPosX() {return pos_x;}
    int getPosY() {return pos_y;}
    int getRecursoNecessario() {return recurso_necessario;}

    Cidade(string, int, int, int);
};

#endif
