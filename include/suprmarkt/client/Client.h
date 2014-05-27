/*
 * Client.h
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include "structures/List.h"

namespace suprmarkt {

namespace checkout {
class Checkout;
}

namespace client {
	enum Payment {
		CHECK, MONEY
	};
	enum Preference {
		FEWER, SHORTER
	};

class Client {
	template <typename T>
	using List = structures::List<T>;

public:
    using Checkout = checkout::Checkout;

    Client() = default;

	/**
	 * @brief Construtor completo de Client.
	 * @param cartSize Quantidade de itens no carrinho do Client.
	 * @param cartValue Valor total de itens no carrinho do Client.
	 * @param arrivalTime Tempo de chegada do Client ao supermercado.
	 * @param payment Método de pagamento do Client.
	 * @param preference Preferência por fila do Client.
	 */
	Client(int cartSize, double cartValue, int arrivalTime, const Payment& payment, const Preference& preference);

	/**
	 * @brief Acesso ao tempo de chegada do Client.
	 * @return Tempo de chegada do Client.
	 */
	int arrivalTime() const;

	/**
	 * @brief Mutação do tempo de chegada do Client.
	 * @param arrivalTime Novo tempo de chegada do Client.
	 */
	void arrivalTime(int arrivalTime);

	/**
	 * @brief Acesso ao tempo de saída do Client.
	 * @return Tempo de saída do Client.
	 */
	int leavingTime() const;

	/**
	 * @brief Mutação do tempo de saída do Client.
	 * @param leavingTime Novo tempo de saída do Client.
	 */
	void leavingTime(int leavingTime);

	/**
	 * @brief Acesso à quantidade de itens no carrinho do Client.
	 * @return Quantidade de itens no carrinho do Client.
	 */
	int cartSize() const;

	/**
	 * @brief Acesso ao valor total dos itens no carrinho do Client.
	 * @return Valor total dos itens no carrinho do Client.
	 */
	double cartValue() const;

	/**
	 * @brief Acesso ao método de pagamento do Client.
	 * @return Método de pagamento do Client.
	 */
	Payment paymentType() const;

	/**
	 * @brief Procurar e inserir o Client na melhor fila.
	 * @details A melhor fila que o Client pode escolher depende de sua estratégia de escolha de fila. A fila então escolhida receberá o Client pelo método enqueue, modificará o tempo de saída do Client e o inserirá na fila.
	 * @param queues
	 */
	void enterBestQueue(List<Checkout>& queues);

private:
	int _arrivalTime {};
	int _leavingTime {};

	int _cartSize {};
	double _cartValue {};
	Payment _paymentType {};
	Preference _preferenceQueue {};
};

} /* namespace client */
} /* namespace suprmarkt */

#endif /* CLIENT_H_ */
