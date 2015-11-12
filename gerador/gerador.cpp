#include "gerador.hpp"

Gerador::Gerador(string nome, int pos_x, int pos_y, int recurso_produzido, int custo_gerador) {
  this->nome = nome;
  this->pos_x = pos_x;
  this->pos_y = pos_y;
  this->recurso_produzido = recurso_produzido;
  this->custo_gerador = custo_gerador;
}
