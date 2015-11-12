#ifndef DEFAULT_H
#define DEFAULT_H
#include "default.hpp"
#endif

#ifndef FILESTREAM_H
#define FILESTREAM_H
#include "filestream.hpp"
#endif

#include "cidade.hpp"
#include "gerador.hpp"
#include "adaptador.hpp"
#include "interconexao.hpp"

int main()
{
    // Lê o arquivo de configuração
    ifstream fin("rede_distribuicao.conf");

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

            // Instancia cidade
            Cidade cidade(nome, pos_x, pos_y, recurso_necessario);

            // Imprime cidade
            cout << cidade.getNome() << " - pos_x " << cidade.getPosX()
            << " pos_y " << cidade.getPosY() << " recurso_necessario " << cidade.getRecursoNecessario()
            << endl;
          }
          break;

          case 'A':
          {
            // Inicializa variaveis
            string nome;
            int pos_x, pos_y;

            // Lê linha do arquivo
            fin >> nome >> pos_x >> pos_y;

            // Instancia adaptador
            Adaptador adaptador(nome, pos_x, pos_y);

            // Imprime adaptador
            cout << adaptador.getNome() << " - pos_x " << adaptador.getPosX()
            << " pos_y " << adaptador.getPosY() << endl;
          }
          break;

          case 'G':
          {
            // Inicializa variaveis
            string nome;
            int pos_x, pos_y, recurso_produzido, custo_gerador;

            // Lê linha do arquivo
            fin >> nome >> pos_x >> pos_y >> recurso_produzido >> custo_gerador;

            // Instancia gerador
            Gerador gerador(nome, pos_x, pos_y, recurso_produzido, custo_gerador);

            // Imprime gerador
            cout << gerador.getNome() << " - pos_x " << gerador.getPosX()
            << " pos_y " << gerador.getPosY() << " recurso_produzido " << gerador.getRecursoProduzido()
            << " custo_gerador " << gerador.getCustoGerador() << endl;
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

            // Instancia interconexao
            Interconexao interconexao(nome, pos_inic_x, pos_inic_y, pos_final_x, pos_final_y,
                capacidade_max, chance_falha, tempo_conserto, custo_do_conserto);

            // Imprime interconexao
            cout << interconexao.getNome()
            << " - pos_inic_x " << interconexao.getPosInicX()
            << " pos_inic_y " << interconexao.getPosInicY()
            << " pos_final_x "<< interconexao.getPosFinalX()
            << " pos_final_y " << interconexao.getPosFinalY()
            << " capacidade_max " << interconexao.getCapacidadeMax()
            << " chance_falha " << interconexao.getChanceFalha()
            << " tempo_conserto " << interconexao.getTempoConserto()
            << " custo_do_conserto " << interconexao.getCustoDoConserto() << endl;
          }
          break;
        }
    }
}
