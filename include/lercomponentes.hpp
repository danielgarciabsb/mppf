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
} componentesArray;

componentesArray * lerComponentesDoArquivo(string arquivo);
