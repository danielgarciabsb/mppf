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
    int carga;
  public:
    string getNome() {return nome;}
    int getPosX() {return pos_x;}
    int getPosY() {return pos_y;}
    int getRecursoNecessario() {return recurso_necessario;}
    int getCarga() {return carga;}
    void addCarga(int carga) {this->carga += carga;}
    void subCarga(int carga) {this->carga -= carga;}
    void setCarga(int carga) {this->carga = carga;}

    Cidade(string, int, int, int);
};

#endif
