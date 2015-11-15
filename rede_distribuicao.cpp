#ifndef DEFAULT_H
#define DEFAULT_H
#include "default.hpp"
#endif

#include <vector>
#include <typeinfo>

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
    /**
    * A seguir, para cada interconexao é verificado:
    *   - se o inicio se dá em um gerador, entao:
    *       - se o fim se dá em um adaptador: new interconexoesGA e pula para proxima interconexao
    *       - se o fim se dá em uma cidade: new interconexoesGC e pula para proxima interconexao
    *   - se o inicio se dá em um adaptador, entao:
    *       - se o fim se dá em uma cidade: new interconexoesAC e pula para proxima interconexao
    *       - se o fim se dá em um adaptador: new interconexoesAA e pula para proxima interconexao
    */

    // Para todas interconexoes
    for(i_iter = componentes->interconexoes.begin(), i_end = componentes->interconexoes.end() ; i_iter != i_end; ++i_iter) {
      connected = 0;
      // Para cada gerador
      for(g_iter = componentes->geradores.begin(), g_end = componentes->geradores.end() ; g_iter != g_end; ++g_iter) {
        // Verifica se a posicao inicial da interconexao bate com a posicao dos geradores
        if((*i_iter)->getPosInicX() == (*g_iter)->getPosX() && (*i_iter)->getPosInicY() == (*g_iter)->getPosY()) {
          // Para cada adaptador
          for(a_iter = componentes->adaptadores.begin(), a_end = componentes->adaptadores.end() ; a_iter != a_end; ++a_iter) {
            // Verifica se a posicao final da interconexao é a mesma posicao do adaptador
            if((*i_iter)->getPosFinalX() == (*a_iter)->getPosX() && (*i_iter)->getPosFinalY() == (*a_iter)->getPosY()) {
              // Cria objeto interconexaoGA (Gerador -> Adaptador)
              componentes->interconexoesGA.push_back(new InterconexaoGA((*i_iter)->getNome(), (*i_iter)->getPosInicX(),
                    (*i_iter)->getPosInicY(), (*i_iter)->getPosFinalX(), (*i_iter)->getPosFinalY(), (*i_iter)->getCapacidadeMax(),
                    (*i_iter)->getChanceFalha(), (*i_iter)->getTempoConserto(), (*i_iter)->getCustoDoConserto(),(*g_iter), (*a_iter)));
              // Interconexao conectada, agora pula para a proxima
              connected = 1;
              break;
            } // Fim IF pos final
          }// Fim FOR adapt
          if(connected) break;
          // Para cada cidade
          for(c_iter = componentes->cidades.begin(), c_end = componentes->cidades.end() ; c_iter != c_end; ++c_iter) {
            // Verifica se a posicao final da interconexao bate com a posicao da cidade
            if((*i_iter)->getPosFinalX() == (*c_iter)->getPosX() && (*i_iter)->getPosFinalY() == (*c_iter)->getPosY()) {
              // Cria objeto interconexaoGC (Gerador -> Cidade)
              componentes->interconexoesGC.push_back(new InterconexaoGC((*i_iter)->getNome(), (*i_iter)->getPosInicX(),
                    (*i_iter)->getPosInicY(), (*i_iter)->getPosFinalX(), (*i_iter)->getPosFinalY(), (*i_iter)->getCapacidadeMax(),
                    (*i_iter)->getChanceFalha(), (*i_iter)->getTempoConserto(), (*i_iter)->getCustoDoConserto(),(*g_iter), (*c_iter)));
              // Interconexao conectada, agora pula para a proxima
              connected = 1;
              break;
            }
          }
          if(connected) break;
          // TODO: REPORTA ERRO -> CONEXAO DE SAIDA INEXISTENTE
          cout << "Conexao de saida da Interconexao: " << (*i_iter)->getNome() << " inexistente!" << endl;
        } // Fim IF pos inic
      } // Fim FOR gerador
      // Para cada adaptador
      for(a_iter = componentes->adaptadores.begin(), a_end = componentes->adaptadores.end() ; a_iter != a_end; ++a_iter) {
        // Verifica se a posicao inicial da interconexao bate com a posicao dos adaptadores
        if((*i_iter)->getPosInicX() == (*a_iter)->getPosX() && (*i_iter)->getPosInicY() == (*a_iter)->getPosY()) {
          // Para cada cidade
          for(c_iter = componentes->cidades.begin(), c_end = componentes->cidades.end() ; c_iter != c_end; ++c_iter) {
            // Verifica se a posicao final da interconexao bate com a posicao da cidade
            if((*i_iter)->getPosFinalX() == (*c_iter)->getPosX() && (*i_iter)->getPosFinalY() == (*c_iter)->getPosY()) {
              // Cria objeto interconexaoAC (Adaptador -> Cidade)
              componentes->interconexoesAC.push_back(new InterconexaoAC((*i_iter)->getNome(), (*i_iter)->getPosInicX(),
                    (*i_iter)->getPosInicY(), (*i_iter)->getPosFinalX(), (*i_iter)->getPosFinalY(), (*i_iter)->getCapacidadeMax(),
                    (*i_iter)->getChanceFalha(), (*i_iter)->getTempoConserto(), (*i_iter)->getCustoDoConserto(),(*a_iter), (*c_iter)));
              // Interconexao conectada, agora pula para a proxima
              connected = 1;
              break;
            }
          }
          if(connected) break;
          // Para cada adaptador
          vector<Adaptador*>::iterator a_iter2, a_end2;
          for(a_iter2 = componentes->adaptadores.begin(), a_end2 = componentes->adaptadores.end() ; a_iter2 != a_end2; ++a_iter2) {
            // Verifica se a posicao final da interconexao bate com a posicao do adaptador
            if((*i_iter)->getPosFinalX() == (*a_iter2)->getPosX() && (*i_iter)->getPosFinalY() == (*a_iter2)->getPosY()) {
              // Cria objeto interconexaoAA (Adaptador -> Adaptador)
              componentes->interconexoesAA.push_back(new InterconexaoAA((*i_iter)->getNome(), (*i_iter)->getPosInicX(),
                    (*i_iter)->getPosInicY(), (*i_iter)->getPosFinalX(), (*i_iter)->getPosFinalY(), (*i_iter)->getCapacidadeMax(),
                    (*i_iter)->getChanceFalha(), (*i_iter)->getTempoConserto(), (*i_iter)->getCustoDoConserto(),(*a_iter), (*a_iter2)));
              // Interconexao conectada, agora pula para a proxima
              connected = 1;
              break;
            } // Fim IF pos final
          }// Fim FOR adapt
          if(connected) break;
          // TODO: REPORTA ERRO -> CONEXAO DE SAIDA INEXISTENTE
        } // Fim IF pos inic
      } // Fim FOR gerador
      // TODO: REPORTA ERRO -> CONEXAO DE ENTRADA E SAIDA INEXISTENTE
    } // Fim FOR todas intercon

    vector<InterconexaoGA*>::iterator ga_iter, ga_end;
    for(ga_iter = componentes->interconexoesGA.begin(), ga_end = componentes->interconexoesGA.end() ; ga_iter != ga_end; ++ga_iter) {
      (*ga_iter)->getSaida()->addCarga((*ga_iter)->getCarga());
      cout << "Gerador " << (*ga_iter)->getEntrada()->getNome()
      << " (getRecursoProduzido:" << (*ga_iter)->getEntrada()->getRecursoProduzido() << ")"
      << " -> InterconexaoGA " << (*ga_iter)->getNome()
      << " (getCapacidadeMax:" << (*ga_iter)->getCapacidadeMax()
      << ", getCarga:" << (*ga_iter)->getCarga() << ")"
      << " -> Adaptador " << (*ga_iter)->getSaida()->getNome()
      << " (getCarga:" << (*ga_iter)->getSaida()->getCarga() << ")" << endl;
    }

    vector<InterconexaoGC*>::iterator gc_iter, gc_end;
    for(gc_iter = componentes->interconexoesGC.begin(), gc_end = componentes->interconexoesGC.end() ; gc_iter != gc_end; ++gc_iter) {
      cout << "Gerador " << (*gc_iter)->getEntrada()->getNome()
      << " (getRecursoProduzido:" << (*gc_iter)->getEntrada()->getRecursoProduzido() << ")"
      << "-> InterconexaoGC " << (*gc_iter)->getNome()
      << " (getCapacidadeMax:" << (*gc_iter)->getCapacidadeMax()
      << ", getCarga:" << (*gc_iter)->getCarga() << ")"
      << " -> Cidade " << (*gc_iter)->getSaida()->getNome() << endl;
    }

    vector<InterconexaoAA*>::iterator aa_iter, aa_end;
    for(aa_iter = componentes->interconexoesAA.begin(), aa_end = componentes->interconexoesAA.end() ; aa_iter != aa_end; ++aa_iter) {
      (*aa_iter)->getSaida()->addCarga((*aa_iter)->getCarga());
      cout << "Adaptador " << (*aa_iter)->getEntrada()->getNome()
      << " (getCarga:" << (*aa_iter)->getEntrada()->getCarga() << ")"
      << "-> InterconexaoAA " << (*aa_iter)->getNome()
      << " (getCapacidadeMax:" << (*aa_iter)->getCapacidadeMax()
      << ", getCarga:" << (*aa_iter)->getCarga() << ")"
      << " -> Adaptador " << (*aa_iter)->getSaida()->getNome()
      << " (getCarga:" << (*aa_iter)->getSaida()->getCarga() << ")"
      << endl;
    }

    vector<InterconexaoAC*>::iterator ac_iter, ac_end;
    for(ac_iter = componentes->interconexoesAC.begin(), ac_end = componentes->interconexoesAC.end() ; ac_iter != ac_end; ++ac_iter) {
      (*ac_iter)->getSaida()->addCarga((*ac_iter)->getCarga());
      cout << "Adaptador " << (*ac_iter)->getEntrada()->getNome()
      << " (getCarga:" << (*ac_iter)->getEntrada()->getCarga() << ")"
      << "-> InterconexaoAC " << (*ac_iter)->getNome()
      << " (getCapacidadeMax:" << (*ac_iter)->getCapacidadeMax()
      << ", getCarga:" << (*ac_iter)->getCarga() << ")"
      << " -> Cidade " << (*ac_iter)->getSaida()->getNome()
      << " (getCarga:" << (*ac_iter)->getSaida()->getCarga() << ")"
      << endl;
    }

}
