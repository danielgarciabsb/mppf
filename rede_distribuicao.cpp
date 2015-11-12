#ifndef DEFAULT_H
#define DEFAULT_H
#include "default.hpp"
#endif

#include "cidade.hpp"
#include "gerador.hpp"

int main() {
  Cidade c1("C1",10,5,20);
  Gerador g1("G1", 15,10,30,1000);

  // Imprime cidade
  cout << c1.getNome() << " - pos_x: " << c1.getPosX()
  << " pos_y: " << c1.getPosY() << " rec " << c1.getRecursoNecessario()
  << endl;

  // Imprime Gerador

  cout << g1.getNome() << " - pos_x: " << g1.getPosX()
  << " pos_y: " << g1.getPosY() << " recprod " << g1.getRecursoProduzido()
  << " custo " << g1.getCustoGerador() << endl;
}
