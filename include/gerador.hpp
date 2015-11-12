#ifndef DEFAULT_H
#define DEFAULT_H
#include "default.hpp"
#endif

#ifndef GERADOR_H
#define GERADOR_H

class Gerador {
  private:
    string nome;
    int pos_x;
    int pos_y;
    int recurso_produzido;
    int custo_gerador;
  public:
    string getNome() {return nome;}
    int getPosX() {return pos_x;}
    int getPosY() {return pos_y;}
    int getRecursoProduzido() {return recurso_produzido;}
    int getCustoGerador() {return custo_gerador;}

    Gerador(string, int, int, int, int);
};

#endif
