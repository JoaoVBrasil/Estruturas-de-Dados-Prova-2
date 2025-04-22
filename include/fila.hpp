#pragma once
#include <stdint.h>

#include <stdexcept>

/**
 * @brief Classe template para implementação de uma Fila (estrutura FIFO).
 *
 * @tparam T Tipo de dado armazenado na fila.
 */
template <class T>
class Fila {
 public:
  /**
   * @brief Construtor da fila com capacidade personalizada.
   *
   * Inicializa a fila com a capacidade especificada pelo usuário.
   *
   * @param capacidade A capacidade máxima da fila.
   */
  Fila(size_t capacidade);

  /**
   * @brief Destrutor da fila.
   *
   * Libera os recursos alocados dinamicamente.
   */
  ~Fila();

  /**
   * @brief Insere um novo elemento no final da fila.
   *
   * @param valor Valor a ser enfileirado.
   * @throws std::runtime_error Se a fila estiver cheia.
   */
  void enfileirar(const T& valor);

  /**
   * @brief Remove e retorna o elemento do início da fila.
   *
   * @return Elemento removido do início.
   * @throws std::runtime_error Se a fila estiver vazia.
   */
  T desenfileirar();

  /**
   * @brief Acessa o elemento do início da fila.
   *
   * @return Referência ao elemento no início da fila.
   * @throws std::runtime_error Se a fila estiver vazia.
   */
  T& frente();

  /**
   * @brief Acessa o elemento do início da fila (versão constante).
   *
   * @return Referência constante ao elemento no início da fila.
   * @throws std::runtime_error Se a fila estiver vazia.
   */
  const T& frente() const;

  /**
   * @brief Verifica se a fila está vazia.
   *
   * @return true Se a fila estiver vazia.
   * @return false Caso contrário.
   */
  bool esta_vazia() const;

  /**
   * @brief Verifica se a fila está cheia.
   *
   * @return true Se a fila estiver cheia.
   * @return false Caso contrário.
   */
  bool esta_cheia() const;

  const size_t capacidade; /**< Capacidade máxima da fila. */
 private:
  size_t tamanho;       /**< Número atual de elementos na fila. */
  size_t indice_inicio; /**< Índice do elemento da frente da fila. */
  size_t indice_fim;    /**< Índice do último elemento da fila. */
  T* dados;             /**< Ponteiro para o array de elementos. */

 public:
  // Necessário apenas para os testes automatizados.
  // ---
  Fila(const Fila&) = delete;
  Fila& operator=(const Fila&) = delete;
  Fila(Fila&& other) noexcept
      : capacidade(other.capacidade),
        tamanho(other.tamanho),
        indice_inicio(other.indice_inicio),
        índice_fim(other.indice_fim),
        dados(other.dados) {
    other.dados = nullptr;
    other.tamanho = 0;
    other.indice_inicio = 0;
    other.indice_fim = 0;
  }
  // ---
};

template <class T>
Fila<T>::Fila(size_t capacidade)
    : capacidade(capacidade), tamanho(0), indice_inicio(0), indice_fim(0) {
  dados = new T[capacidade];
}

template <class T>
Fila<T>::~Fila() {
  delete[] dados;
}

template <class T>
void Fila<T>::enfileirar(const T& valor) {
  if (esta_cheia()) throw std::runtime_error("Fila está cheia");
  dados[indice_fim] = valor;
  indice_fim = (indice_fim + 1) % capacidade;
  tamanho++;
}

template <class T>
T Fila<T>::desenfileirar() {
  if (esta_vazia()) throw std::runtime_error("Fila está vazia");
  T valor = dados[indice_inicio];
  indice_inicio = (indice_inicio + 1) % capacidade;
  tamanho--;
  return valor;
}

template <class T>
T& Fila<T>::frente() {
  if (esta_vazia()) throw std::runtime_error("Fila está vazia");
  return dados[indice_inicio];
}

template <class T>
const T& Fila<T>::frente() const {
  if (esta_vazia()) throw std::runtime_error("Fila está vazia");
  return dados[indice_inicio];
}

template <class T>
bool Fila<T>::esta_vazia() const {
  return tamanho == 0;
}

template <class T>
bool Fila<T>::esta_cheia() const {
  return tamanho == capacidade;
}
