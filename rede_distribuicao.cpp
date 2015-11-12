#ifndef DEFAULT_H
#define DEFAULT_H
#include "default.hpp"
#endif

#include "cidade.hpp"

int main() {
  Cidade c1("C1",10,5,20);
  cout << c1.getNome() << " - pos_x: " << c1.getPosX()
  << " pos_y: " << c1.getPosY() << " rec " << c1.getRecursoNecessario()
  << endl;
}
