#include "interconexao.hpp"

Interconexao::Interconexao(string nome, int pos_inic_x, int pos_inic_y,
  int pos_final_x, int pos_final_y, int capacidade_max, float chance_falha,
  int tempo_conserto, int custo_do_conserto) {
  this->nome = nome;
  this->pos_inic_x = pos_inic_x;
  this->pos_inic_y = pos_inic_y;
  this->pos_final_x = pos_final_x;
  this->pos_final_y = pos_final_y;
  this->capacidade_max = capacidade_max;
  this->chance_falha = chance_falha;
  this->tempo_conserto = tempo_conserto;
  this->custo_do_conserto = custo_do_conserto;
}
