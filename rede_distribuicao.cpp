#ifndef DEFAULT_H
#define DEFAULT_H
#include "default.hpp"
#endif

#include <vector>

#include "lercomponentes.hpp"

int main()
{
    componentesArray * componentes = lerComponentesDoArquivo("rede_distribuicao.conf");

    // Imprime todas cidades
    vector<Cidade*>::iterator c_iter, c_end;
    for(c_iter = componentes->cidades.begin(), c_end = componentes->cidades.end() ; c_iter != c_end; ++c_iter) {
      cout << (*c_iter)->getNome() << " - pos_x " << (*c_iter)->getPosX()
      << " pos_y " << (*c_iter)->getPosY() << " recurso_necessario " << (*c_iter)->getRecursoNecessario()
      << endl;
    }

    // Imprime todos adaptadores
    vector<Adaptador*>::iterator a_iter, a_end;
    for(a_iter = componentes->adaptadores.begin(), a_end = componentes->adaptadores.end() ; a_iter != a_end; ++a_iter) {
      cout << (*a_iter)->getNome() << " - pos_x " << (*a_iter)->getPosX()
      << " pos_y " << (*a_iter)->getPosY() << endl;
    }

    // Imprime todos geradores
    vector<Gerador*>::iterator g_iter, g_end;
    for(g_iter = componentes->geradores.begin(), g_end = componentes->geradores.end() ; g_iter != g_end; ++g_iter) {
      cout << (*g_iter)->getNome() << " - pos_x " << (*g_iter)->getPosX()
      << " pos_y " << (*g_iter)->getPosY() << " recurso_produzido " << (*g_iter)->getRecursoProduzido()
      << " custo_gerador " << (*g_iter)->getCustoGerador() << endl;
    }

    // Imprime todas interconexoes
    vector<Interconexao*>::iterator i_iter, i_end;
    for(i_iter = componentes->interconexoes.begin(), i_end = componentes->interconexoes.end() ; i_iter != i_end; ++i_iter) {
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

    int connected = 0;
    // Para todas interconexoes
    for(i_iter = componentes->interconexoes.begin(), i_end = componentes->interconexoes.end() ; i_iter != i_end; ++i_iter) {
      connected = 0;
      // Para cada gerador
      for(g_iter = componentes->geradores.begin(), g_end = componentes->geradores.end() ; g_iter != g_end; ++g_iter) {
        // Verifica se a posicao inicial da interconexao bate com a posicao dos geradores
        if((*i_iter)->getPosInicX() == (*g_iter)->getPosX() && (*i_iter)->getPosInicY() == (*g_iter)->getPosY()) {
          // Imprime posicao do gerador e interconexao
          cout << "Gerador " << (*g_iter)->getNome() << " (" << (*g_iter)->getPosX() << "," << (*g_iter)->getPosY() << ")" << "-> Interconexao " << (*i_iter)->getNome();
          // Para cada adaptador
          for(a_iter = componentes->adaptadores.begin(), a_end = componentes->adaptadores.end() ; a_iter != a_end; ++a_iter) {
            // Verifica se a posicao final da interconexao bate com a posicao do adaptador
            if((*i_iter)->getPosFinalX() == (*a_iter)->getPosX() && (*i_iter)->getPosFinalY() == (*a_iter)->getPosY()) {
              // Imprime posicao final da interconexao e o adaptador
              cout << "-> Adaptador " << (*a_iter)->getNome() << " (" << (*a_iter)->getPosX() << "," << (*a_iter)->getPosY() << ")" << endl;
              connected = 1;
              break;
            } // Fim IF pos final
          }// Fim FOR adapt
          if(connected) break;
          // Para cada cidade
          for(c_iter = componentes->cidades.begin(), c_end = componentes->cidades.end() ; c_iter != c_end; ++c_iter) {
            // Verifica se a posicao final da interconexao bate com a posicao da cidade
            if((*i_iter)->getPosFinalX() == (*c_iter)->getPosX() && (*i_iter)->getPosFinalY() == (*c_iter)->getPosY()) {
              // Imprime posicao final da interconexao e o adaptador
              cout << "-> Cidade " << (*c_iter)->getNome() << " (" << (*c_iter)->getPosX() << "," << (*c_iter)->getPosY() << ")" << endl;
              connected = 1;
              break;
            }
          }
          if(connected) break;
        } // Fim IF pos inic
      } // Fim FOR gerador
      // Para cada adaptador
      for(a_iter = componentes->adaptadores.begin(), a_end = componentes->adaptadores.end() ; a_iter != a_end; ++a_iter) {
        // Verifica se a posicao inicial da interconexao bate com a posicao dos adaptadores
        if((*i_iter)->getPosInicX() == (*a_iter)->getPosX() && (*i_iter)->getPosInicY() == (*a_iter)->getPosY()) {
          // Imprime posicao do adaptador e interconexao
          cout << "Adaptador " << (*a_iter)->getNome() << " (" << (*a_iter)->getPosX() << "," << (*a_iter)->getPosY() << ")" << "-> Interconexao " << (*i_iter)->getNome();
          // Para cada adaptador
          vector<Adaptador*>::iterator a_iter2, a_end2;
          for(a_iter2 = componentes->adaptadores.begin(), a_end2 = componentes->adaptadores.end() ; a_iter2 != a_end2; ++a_iter2) {
            // Verifica se a posicao final da interconexao bate com a posicao do adaptador
            if((*i_iter)->getPosFinalX() == (*a_iter2)->getPosX() && (*i_iter)->getPosFinalY() == (*a_iter2)->getPosY()) {
              // Imprime posicao final da interconexao e o adaptador
              cout << "-> Adaptador " << (*a_iter2)->getNome() << " (" << (*a_iter2)->getPosX() << "," << (*a_iter2)->getPosY() << ")" << endl;
              connected = 1;
              break;
            } // Fim IF pos final
          }// Fim FOR adapt
          if(connected) break;
          // Para cada cidade
          for(c_iter = componentes->cidades.begin(), c_end = componentes->cidades.end() ; c_iter != c_end; ++c_iter) {
            // Verifica se a posicao final da interconexao bate com a posicao da cidade
            if((*i_iter)->getPosFinalX() == (*c_iter)->getPosX() && (*i_iter)->getPosFinalY() == (*c_iter)->getPosY()) {
              // Imprime posicao final da interconexao e o adaptador
              cout << "-> Cidade " << (*c_iter)->getNome() << " (" << (*c_iter)->getPosX() << "," << (*c_iter)->getPosY() << ")" << endl;
              connected = 1;
              break;
            }
          }
          if(connected) break;
        } // Fim IF pos inic
      } // Fim FOR gerador
    } // Fim FOR todas intercon
}
