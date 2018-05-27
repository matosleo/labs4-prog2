/**
* @file	    main.cpp
* @brief	Arquivo com a função principal do programa
* @author   Leonardo Matos (matos_leo95@live.com)
* @since	17/05/2018
* @date	    21/05/2018
* @sa		https://github.com/matosleo/labs4-prog2
*/

#include <iostream>
#include "lib_npi.h"

int main(int argc, char const *argv[])
{
	std::string expressao;
	getline(std::cin, expressao);

	int tam = expressao.length();
	
	Pilha<std:: string> pilha(tam);
	Pilha<int> aux_pilha;

	preenchePilhaExpressao(pilha, expressao, tam);

	resolverNPI(pilha, aux_pilha);


	std::cout << "Resultado: " << aux_pilha.top() << std::endl;
 
	return 0;
}