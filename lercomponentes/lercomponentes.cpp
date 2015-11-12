#include <fstream>
#include "lercomponentes.hpp"

componentesArray * lerComponentesDoArquivo(string arquivo) {

  ifstream fin(arquivo.c_str());

  componentesArray * componentes = new componentesArray();
  char tipo;

  while (fin >> tipo)
  {
      switch (tipo) {
        case 'C':
        {
          // Inicializa variaveis
          string nome;
          int pos_x, pos_y, recurso_necessario;

          // Lê linha do arquivo
          fin >> nome >> pos_x >> pos_y >> recurso_necessario;

          // Instancia cidade e coloca na array
          componentes->cidades.push_back(new Cidade(nome, pos_x, pos_y, recurso_necessario));

        }
        break;

        case 'A':
        {
          // Inicializa variaveis
          string nome;
          int pos_x, pos_y;

          // Lê linha do arquivo
          fin >> nome >> pos_x >> pos_y;

          // Instancia adaptador e coloca na array
          componentes->adaptadores.push_back(new Adaptador(nome, pos_x, pos_y));

        }
        break;

        case 'G':
        {
          // Inicializa variaveis
          string nome;
          int pos_x, pos_y, recurso_produzido, custo_gerador;

          // Lê linha do arquivo
          fin >> nome >> pos_x >> pos_y >> recurso_produzido >> custo_gerador;

          // Instancia gerador e coloca na array
          componentes->geradores.push_back(new Gerador(nome, pos_x, pos_y, recurso_produzido, custo_gerador));

        }
        break;

        case 'I':
        {
          // Inicializa variaveis
          string nome;
          int pos_inic_x, pos_inic_y, pos_final_x, pos_final_y, capacidade_max,
          tempo_conserto, custo_do_conserto;
          float chance_falha;

          // Lê linha do arquivo
          fin >> nome >> pos_inic_x >> pos_inic_y >> pos_final_x >> pos_final_y
          >> capacidade_max >> chance_falha >> tempo_conserto >> custo_do_conserto;

          // Instancia interconexao e coloca na array
          componentes->interconexoes.push_back(new Interconexao(nome, pos_inic_x, pos_inic_y, pos_final_x,
                pos_final_y, capacidade_max, chance_falha, tempo_conserto, custo_do_conserto));

        }
        break;
      }
  }
  return componentes;
}
