#pragma once
#include <stdint.h>

#include <stdexcept>

/**
 * @brief Classe template para implementação de uma Pilha (estrutura LIFO).
 *
 * @tparam T Tipo de dado armazenado na pilha.
 */
template <class T>
class Pilha {
 public:
  /**
   * @brief Construtor da pilha com capacidade personalizada.
   *
   * Inicializa a pilha com a capacidade especificada pelo usuário.
   *
   * @param capacidade A capacidade máxima da pilha.
   */
  Pilha(size_t capacidade);

  /**
   * @brief Destrutor da pilha.
   *
   * Libera os recursos alocados dinamicamente.
   */
  ~Pilha();

  /**
   * @brief Insere um novo elemento no topo da pilha.
   *
   * @param valor Valor a ser empilhado.
   * @throws std::runtime_error Se a pilha estiver cheia.
   */
  void empilhar(const T& valor);

  /**
   * @brief Remove e retorna o elemento do topo da pilha.
   *
   * @return Elemento removido do topo.
   * @throws std::runtime_error Se a pilha estiver vazia.
   */
  T desempilhar();

  /**
   * @brief Acessa o elemento do topo da pilha.
   *
   * @return Referência ao elemento no topo.
   * @throws std::runtime_error Se a pilha estiver vazia.
   */
  T& topo();

  /**
   * @brief Acessa o elemento do topo da pilha (versão constante).
   *
   * @return Referência constante ao elemento no topo.
   * @throws std::runtime_error Se a pilha estiver vazia.
   */
  const T& topo() const;

  /**
   * @brief Verifica se a pilha está vazia.
   *
   * @return true Se a pilha estiver vazia.
   * @return false Caso contrário.
   */
  bool esta_vazia() const;

  /**
   * @brief Verifica se a pilha está cheia.
   *
   * @return true Se a pilha estiver cheia.
   * @return false Caso contrário.
   */
  bool esta_cheia() const;

  const size_t capacidade; /**< Capacidade máxima da pilha. */
 private:
  size_t tamanho; /**< Número atual de elementos na pilha. */
  T* dados;       /**< Ponteiro para o array de elementos. */

 public:
  // Necessário apenas para os testes automatizados.
  // ---
  Pilha(const Pilha&) = delete;
  Pilha& operator=(const Pilha&) = delete;
  // ---
};


template <class T>
Pilha<T>::Pilha(size_t capacidade)
    : capacidade(capacidade), tamanho(0) {
  dados = new T[capacidade];
}

template <class T>
Pilha<T>::~Pilha() {
  delete[] dados;
}

template <class T>
void Pilha<T>::empilhar(const T& valor) {
  if (esta_cheia()) throw std::runtime_error("Pilha cheia");
  dados[tamanho++] = valor;
}

template <class T>
T Pilha<T>::desempilhar() {
  if (esta_vazia()) throw std::runtime_error("Pilha está vazia");
  return dados[--tamanho];
}

template <class T>
T& Pilha<T>::topo() {
  if (esta_vazia()) throw std::runtime_error("Pilha está vazia");
  return dados[tamanho - 1];
}

template <class T>
const T& Pilha<T>::topo() const {
  if (esta_vazia()) throw std::runtime_error("Pilha está vazia");
  return dados[tamanho -1];
}

template <class T>
bool Pilha<T>::esta_vazia() const {
  return tamanho == 0;
}

template <class T>
bool Pilha<T>::esta_cheia() const {
  return tamanho == capacidade;
}


