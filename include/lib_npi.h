/**
* @file     lib_npi.h
* @brief    declaração dos prototipos das funções que resolvem uma expressão em notação polonesa inversa
* @author   Leonardo Matos (matos_leo95@live.com)
* @since    17/06/2018
* @date	    21/06/2018
* @sa      https://github.com/matosleo/labs4-prog1
*/

#ifndef LIB_NPI_H
#define LIB_NPI_H

#include <cstdlib>
#include <string>
#include "pilha.h"
#include <iostream>

void preenchePilhaExpressao(Pilha<std::string> &pilha, std::string s, int size);


void resolverNPI (Pilha<std::string> &pilha, Pilha<int> &aux_pilha);




#endif