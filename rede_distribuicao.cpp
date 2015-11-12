#ifndef DEFAULT_H
#define DEFAULT_H
#include "default.hpp"
#endif

#ifndef FILESTREAM_H
#define FILESTREAM_H
#include "filestream.hpp"
#endif

#include <vector>

#include "cidade.hpp"
#include "gerador.hpp"
#include "adaptador.hpp"
#include "interconexao.hpp"

int main()
{
    // Lê o arquivo de configuração
    ifstream fin("rede_distribuicao.conf");

    vector<Cidade*> cidades;
    vector<Adaptador*> adaptadores;
    vector<Gerador*> geradores;
    vector<Interconexao*> interconexoes;

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
            cidades.push_back(new Cidade(nome, pos_x, pos_y, recurso_necessario));

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
            adaptadores.push_back(new Adaptador(nome, pos_x, pos_y));

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
            geradores.push_back(new Gerador(nome, pos_x, pos_y, recurso_produzido, custo_gerador));

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
            interconexoes.push_back(new Interconexao(nome, pos_inic_x, pos_inic_y, pos_final_x,
                  pos_final_y, capacidade_max, chance_falha, tempo_conserto, custo_do_conserto));

          }
          break;
        }
    }

    // Imprime todas cidades
    vector<Cidade*>::iterator c_iter, c_end;
    for(c_iter = cidades.begin(), c_end = cidades.end() ; c_iter != c_end; ++c_iter) {
      cout << (*c_iter)->getNome() << " - pos_x " << (*c_iter)->getPosX()
      << " pos_y " << (*c_iter)->getPosY() << " recurso_necessario " << (*c_iter)->getRecursoNecessario()
      << endl;
    }

    // Imprime todos adaptadores
    vector<Adaptador*>::iterator a_iter, a_end;
    for(a_iter = adaptadores.begin(), a_end = adaptadores.end() ; a_iter != a_end; ++a_iter) {
      cout << (*a_iter)->getNome() << " - pos_x " << (*a_iter)->getPosX()
      << " pos_y " << (*a_iter)->getPosY() << endl;
    }

    // Imprime todos geradores
    vector<Gerador*>::iterator g_iter, g_end;
    for(g_iter = geradores.begin(), g_end = geradores.end() ; g_iter != g_end; ++g_iter) {
      cout << (*g_iter)->getNome() << " - pos_x " << (*g_iter)->getPosX()
      << " pos_y " << (*g_iter)->getPosY() << " recurso_produzido " << (*g_iter)->getRecursoProduzido()
      << " custo_gerador " << (*g_iter)->getCustoGerador() << endl;
    }

    vector<Interconexao*>::iterator i_iter, i_end;
    for(i_iter = interconexoes.begin(), i_end = interconexoes.end() ; i_iter != i_end; ++i_iter) {
      cout << (*i_iter)->getNome()
      << " - pos_inic_x " << (*i_iter)->getPosInicX()
      << " pos_inic_y " << (*i_iter)->getPosInicY()
      << " pos_final_x "<< (*i_iter)->getPosFinalX()
      << " pos_final_y " << (*i_iter)->getPosFinalY()
      << " capacidade_max " << (*i_iter)->getCapacidadeMax()
      << " chance_falha " << (*i_iter)->getChanceFalha()
      << " tempo_conserto " << (*i_iter)->getTempoConserto()
      << " custo_do_conserto " << (*i_iter)->getCustoDoConserto() << endl;
    }
}
