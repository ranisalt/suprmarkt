/*
 * Checkout.h
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#ifndef CHECKOUT_H_
#define CHECKOUT_H_

#include "structures/List.h"
#include "suprmarkt/cashier/Cashier.h"
#include "suprmarkt/client/Client.h"
using suprmarkt::cashier::Cashier;
using suprmarkt::client::Client;

namespace suprmarkt {
namespace checkout {

class Checkout {
	Cashier _cashier;
	List<Client> _queue;
	int _totalWaiting;

public:
	/**
	 * @brief Construtor padrão de Checkout.
	 */
	Checkout();

	/**
	 * @brief Construtor completo de Checkout.
	 *
	 * @param cashier Cashier que atente neste Checkout.
	 */
	Checkout(const Cashier& cashier);

	/**
	 * @brief Acesso ao Cashier do Checkout.
	 *
	 * @return Cópia do Cashier do Checkout.
	 */
	Cashier cashier() const;

	/**
	 * @brief Acesso ao tempo total de espera para o Checkout.
	 * @return Tempo total de espera.
	 */
	int totalWaiting() const;

	/**
	 * @brief Mutação do tempo total de espera para o Checkout.
	 * @param totalWaiting Novo tempo de espera.
	 */
	void totalWaiting(int totalWaiting);

	/**
	 * @brief Desenfileirar e processar Client.
	 *
	 * Se o Client que estiver na frente da fila já estiver em seu momento de ser atendido, processa e desenfileira o Client e altera o Cashier.
	 *
	 * @param time Tempo atual para saber se é tempo de desenfileirar.
	 */
	void dequeue(int time);

	/**
	 * @brief Enfileirar Client.
	 *
	 * Insere o Client na fila do Checkout e altera o seu tempo de saída para refletir o tempo esperado do fim do processamento.
	 *
	 * @param client Client a ser enfileirado.
	 */
	void enqueue(Client& client);

	/**
	 * @brief Calcular total de itens em todos os carrinhos da fila.
	 *
	 * @return Soma de itens em todos os carrinhos da fila.
	 */
	int countItems() const;

	/**
	 * @brief Calcular comprimento da fila.
	 *
	 * @return Comprimento da fila.
	 */
	int length() const;
};

} /* namespace checkout */
} /* namespace suprmarkt */

#endif /* CHECKOUT_H_ */
