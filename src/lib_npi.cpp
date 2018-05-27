/**
* @file     lib_npi.cpp
* @brief    Implementacao da biblioteca de funcões que resolvem a Notação Polonesa Inversa (RPN)
* @author   Leonardo Matos (matos_leo95@live.com)
* @since    17/06/2018
* @date	    21/06/2018
* @sa      https://github.com/matosleo/labs4-prog2
*/

#include "lib_npi.h"

/** 
 * @brief   Função que preenche a pilha 
 * @param   pilha Pilha<string> vazia para ser preenchida
 * @param   s String que será a expressao a ser empilhada na pilha
 * @param   size que é o tamanho da expressao
 */
void preenchePilhaExpressao(Pilha<std::string> &pilha, std::string s, int size)
{
    std::string concatena;
    for (int i = 0; i < size; i++)
    {
        if(s[i] != ' ')
        {
            concatena += s[i];
        }
        else
        {
            pilha.push(concatena);
            concatena = s[i+1];
            i++;
        }
    }
    pilha.push(concatena);
}

/** 
 * @brief	Função faz a resolucao de uma rpn utilizando pilhas
 * @param 	pilha Pilha com os dados da rpn (numeros e operandos)
 * @param	aux_pilha Pilha para auxiliar na resolucao da rpn, armazenando os numeros com os resultados
 */
void resolverNPI (Pilha<std::string> &pilha, Pilha<int> &aux_pilha)
{
    int numero1 = 0;
    int numero2 = 0;

    Pilha<std::string> operadores;
    std::string carac;
    
    //separa as operadores dos numeros em diferentes pilhas
    while(!pilha.empty())
    {
        carac = pilha.top();
        pilha.pop();

        if(carac == "+" || carac == "-" || carac == "*" || carac == "/")
        {
            operadores.push(carac);
        }
        else
        {
            aux_pilha.push(std::stoi(carac));
        }
    }

    //
    while(aux_pilha.size() != 1)
    {   
        if(operadores.top() == "+")
        {
            operadores.pop();
            numero1 = aux_pilha.top();
            aux_pilha.pop();

            numero2 = aux_pilha.top();
            aux_pilha.pop();

            aux_pilha.push(numero1 + numero2);
        }
        else if(operadores.top() == "-")
        {
            operadores.pop();
            numero1 = aux_pilha.top();
            aux_pilha.pop();

            numero2 = aux_pilha.top();
            aux_pilha.pop();

            aux_pilha.push(numero1 - numero2);
        }
        else if(operadores.top() == "*")
        {
            operadores.pop();
            numero1 = aux_pilha.top();
            aux_pilha.pop();

            numero2 = aux_pilha.top();
            aux_pilha.pop();

            aux_pilha.push(numero1 * numero2);
        }
        else if(operadores.top() == "/")
        {
            operadores.pop();
            numero1 = aux_pilha.top();
            aux_pilha.pop();

            numero2 = aux_pilha.top();
            aux_pilha.pop();

            aux_pilha.push(numero1 / numero2);
        }
    }
}
