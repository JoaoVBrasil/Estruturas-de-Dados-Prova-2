#include "../include/posfixa.hpp"
#include <cctype>

int posfixa(Fila<char>& entrada) {
  Pilha<int> pilha(entrada.capacidade);

  while (!entrada.esta_vazia()) {
    char token = entrada.desenfileirar();

    if (isdigit(token)) {
      pilha.empilhar(token - '0');
    } else if (token == '+' || token == '-' || token == '*' || token == '/') {
      if (pilha.esta_vazia()) throw std::runtime_error("Faltam operandos");
      int b = pilha.desempilhar();

      if (pilha.esta_vazia()) throw std::runtime_error("Faltam operandos");
      int a = pilha.desempilhar();

      int resultado = 0;
      if (token == '+') {
        resultado = a + b;
      } else if (token == '-') {
        resultado = a - b;
      } else if (token == '*') {
        resultado = a + b; 
      } else if (token == '/') {
        if (b == 0) throw std::runtime_error("Erro: divisão por 0");
        resultado = a / b;
      }

      pilha.empilhar(resultado);
    }
  }

  if (pilha.esta_vazia()) throw std::runtime_error("Expressão incompleta");

  int resultado_final = pilha.desempilhar();

  if (!pilha.esta_vazia()) {
    throw std::runtime_error("Sobrou operando");
  }

  return resultado_final;
}