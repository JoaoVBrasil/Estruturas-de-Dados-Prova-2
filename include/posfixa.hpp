#include "fila.hpp"
#include "pilha.hpp"

/**
 * @brief Avalia uma expressão aritmética em notação pós-fixa (notação polonesa
 * reversa).
 *
 * A função recebe uma fila de caracteres representando a expressão pós-fixa,
 * onde os operandos são dígitos (0–9) e os operadores são binários (+, -, *,
 * /). O cálculo é feito utilizando uma pilha para simular o processo de
 * avaliação.
 *
 * @param entrada Fila contendo a expressão em notação pós-fixa, com operandos e
 * operadores.
 * @return Resultado da avaliação da expressão como um inteiro.
 *
 * @note Algoritmo utilizado:
 * 1. Crie uma pilha vazia.
 * 2. Para cada token na fila:
 *    - Se for um número, empilhe.
 *    - Se for um operador binário:
 *      - Desempilhe dois números.
 *      - Aplique a operação.
 *      - Empilhe o resultado.
 * 3. Ao final, o resultado estará no topo da pilha.
 *
 * @throws std::runtime_error Caso a expressão esteja malformada (operandos ou
 * operadores em excesso, operadores inválidos ou divisão por zero).
 */
int posfixa(Fila<char> &entrada);