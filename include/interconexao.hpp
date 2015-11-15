#ifndef DEFAULT_H
#define DEFAULT_H
#include "default.hpp"
#endif

#include "cidade.hpp"
#include "gerador.hpp"
#include "adaptador.hpp"

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

#ifndef INTERCONEXAO_GA_H
#define INTERCONEXAO_GA_H

class InterconexaoGA: public Interconexao {
  private:
    Gerador * entrada;
    Adaptador * saida;
  public:
    Gerador * getEntrada() {return entrada;}
    Adaptador * getSaida() {return saida;}
    int getCarga() {
      return entrada->getRecursoProduzido() > this->getCapacidadeMax() ? this->getCapacidadeMax() : entrada->getRecursoProduzido();
    }

    InterconexaoGA(string nome, int pos_inic_x, int pos_inic_y,
      int pos_final_x, int pos_final_y, int capacidade_max, float chance_falha,
      int tempo_conserto, int custo_do_conserto, Gerador * entrada, Adaptador * saida):
      Interconexao(nome, pos_inic_x, pos_inic_y, pos_final_x, pos_final_y,
                  capacidade_max, chance_falha, tempo_conserto, custo_do_conserto) {
                    this->entrada = entrada;
                    this->saida = saida;
                  };
};

#endif

#ifndef INTERCONEXAO_GC_H
#define INTERCONEXAO_GC_H

class InterconexaoGC: public Interconexao {
  private:
    Gerador * entrada;
    Cidade * saida;
  public:
    Gerador * getEntrada() {return entrada;}
    Cidade * getSaida() {return saida;}
    int getCarga() {
      return entrada->getRecursoProduzido() > this->getCapacidadeMax() ? this->getCapacidadeMax() : entrada->getRecursoProduzido();
    }

    InterconexaoGC(string nome, int pos_inic_x, int pos_inic_y,
      int pos_final_x, int pos_final_y, int capacidade_max, float chance_falha,
      int tempo_conserto, int custo_do_conserto, Gerador * entrada, Cidade * saida):
      Interconexao(nome, pos_inic_x, pos_inic_y, pos_final_x, pos_final_y,
                  capacidade_max, chance_falha, tempo_conserto, custo_do_conserto) {
                    this->entrada = entrada;
                    this->saida = saida;
                  };
};

#endif

#ifndef INTERCONEXAO_AA_H
#define INTERCONEXAO_AA_H

class InterconexaoAA: public Interconexao {
  private:
    Adaptador * entrada;
    Adaptador * saida;
  public:
    Adaptador * getEntrada() {return entrada;}
    Adaptador * getSaida() {return saida;}
    int getCarga() {
      return entrada->getCarga() > this->getCapacidadeMax() ? this->getCapacidadeMax() : entrada->getCarga();
    }

    InterconexaoAA(string nome, int pos_inic_x, int pos_inic_y,
      int pos_final_x, int pos_final_y, int capacidade_max, float chance_falha,
      int tempo_conserto, int custo_do_conserto, Adaptador * entrada, Adaptador * saida):
      Interconexao(nome, pos_inic_x, pos_inic_y, pos_final_x, pos_final_y,
                  capacidade_max, chance_falha, tempo_conserto, custo_do_conserto) {
                    this->entrada = entrada;
                    this->saida = saida;
                  };
};

#endif

#ifndef INTERCONEXAO_AC_H
#define INTERCONEXAO_AC_H

class InterconexaoAC: public Interconexao {
  private:
    Adaptador * entrada;
    Cidade * saida;
  public:
    Adaptador * getEntrada() {return entrada;}
    Cidade * getSaida() {return saida;}
    int getCarga() {
      return entrada->getCarga() > this->getCapacidadeMax() ? this->getCapacidadeMax() : entrada->getCarga();
    }

    InterconexaoAC(string nome, int pos_inic_x, int pos_inic_y,
      int pos_final_x, int pos_final_y, int capacidade_max, float chance_falha,
      int tempo_conserto, int custo_do_conserto, Adaptador * entrada, Cidade * saida):
      Interconexao(nome, pos_inic_x, pos_inic_y, pos_final_x, pos_final_y,
                  capacidade_max, chance_falha, tempo_conserto, custo_do_conserto) {
                    this->entrada = entrada;
                    this->saida = saida;
                  };
};

#endif
