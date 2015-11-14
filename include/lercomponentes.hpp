#include <vector>
#include "cidade.hpp"
#include "gerador.hpp"
#include "adaptador.hpp"
#include "interconexao.hpp"

typedef struct componentesType
{
  vector<Cidade*> cidades;
  vector<Adaptador*> adaptadores;
  vector<Gerador*> geradores;
  vector<Interconexao*> interconexoes;
  vector<InterconexaoGA*> interconexoesGA;
  vector<InterconexaoGC*> interconexoesGC;
  vector<InterconexaoAC*> interconexoesAC;
  vector<InterconexaoAA*> interconexoesAA;
} componentesArray;

componentesArray * lerComponentesDoArquivo(string arquivo);
