#ifndef DEFAULT_H
#define DEFAULT_H
#include "default.hpp"
#endif

#ifndef INTERCONEXAO_H
#define INTERCONEXAO_H

class Interconexao {
  private:
    string nome;
    int pos_inic_x;
    int pos_inic_y;
    int pos_final_x;
    int pos_final_y;
    int capacidade_max;
    float chance_falha;
    int tempo_conserto;
    int custo_do_conserto;
  public:
    string getNome() {return nome;}
    int getPosInicX() {return pos_inic_x;}
    int getPosInicY() {return pos_inic_y;}
    int getPosFinalX() {return pos_final_x;}
    int getPosFinalY() {return pos_final_y;}
    int getCapacidadeMax() {return capacidade_max;}
    float getChanceFalha() {return chance_falha;}
    int getTempoConserto() {return tempo_conserto;}
    int getCustoDoConserto() {return custo_do_conserto;}

    Interconexao(string, int, int, int, int, int, float, int, int);
};

#endif
