#ifndef DEFAULT_H
#define DEFAULT_H
#include "default.hpp"
#endif

#include "cidade.hpp"
#include "gerador.hpp"
#include "interconexao.hpp"

int main() {
  Cidade c1("C1",10,5,20);
  Gerador g1("G1", 15,10,30,1000);
  Interconexao i1("I1", 15,10,10,5,100,0.1,5,1000);

  // Imprime cidade
  cout << c1.getNome() << " - pos_x: " << c1.getPosX()
  << " pos_y: " << c1.getPosY() << " rec " << c1.getRecursoNecessario()
  << endl;

  // Imprime Gerador
  cout << g1.getNome() << " - pos_x: " << g1.getPosX()
  << " pos_y: " << g1.getPosY() << " recprod " << g1.getRecursoProduzido()
  << " custo " << g1.getCustoGerador() << endl;

  // Imprime Interconexao
  cout << i1.getNome()
  << " - pos_inic_x: " << i1.getPosInicX()
  << " pos_inic_y: " << i1.getPosInicY()
  << " pos_final_x: "<< i1.getPosFinalX()
  << " pos_final_y: " << i1.getPosFinalY()
  << " capacidade_max: " << i1.getCapacidadeMax()
  << " chance_falha " << i1.getChanceFalha()
  << " tempo_conserto " << i1.getTempoConserto()
  << " custo_do_conserto " << i1.getCustoDoConserto() << endl;
}
