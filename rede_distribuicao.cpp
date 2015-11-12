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
}
