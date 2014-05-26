/*
 * Suprmarkt.h
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#ifndef SUPRMARKT_H_
#define SUPRMARKT_H_

#include <string>
#include "structures/List.h"
#include "suprmarkt/checkout/Checkout.h"
using suprmarkt::checkout::Checkout;

namespace suprmarkt {

class Suprmarkt {
	typedef std::string string;

	string _name;
	int _time;
	int _avgClientArrival;
	int _totalClients;
	int _lostClients;
	double _lostMoney;
	List<Checkout> _queues;

public:
	/**
	 * @brief Construtor padrão do Suprmarkt.
	 */
	Suprmarkt();

	/**
	 * @brief Acesso ao nome do Suprmarkt.
	 *
	 * @return Nome do Suprmarkt.
	 */
	string name() const;

	/**
	 * @brief Mutação do nome do Suprmarkt.
	 * @param name Novo nome do Suprmarkt.
	 */
	void name(const string& name);

	/**
	 * @brief Acesso ao tempo atual da simulação do Suprmarkt.
	 *
	 * @return Tempo atual da simulação.
	 */
	int time() const;

	/**
	 * @brief Mutação do tempo atual da simulação do Suprmarkt.
	 *
	 * @param time Novo tempo atual da simulação.
	 */
	void time(int time);

	/**
	 * @brief Acesso ao tempo médio de chegada de Clients.
	 *
	 * @return Tempo médio de chegada de Clients.
	 */
	int avgClientArrival() const;

	/**
	 * @brief Mutação do tempo médio de chegada de Clients.
	 *
	 * @param avgClientArrival Novo tempo médio de chegada de Clients.
	 */
	void avgClientArrival(int avgClientArrival);

	/**
	 * @brief Contar Checkouts em um Suprmarkt.
	 * @return Contagem de Checkouts.
	 */
	List<Checkout> checkouts() const;

	/**
	 * @brief Adicionar Checkout ao Suprmarkt.
	 *
	 * Adiciona um Checkout completo à lista de Checkouts do Suprmarkt.
	 *
	 * @param checkout Novo Checkout.
	 */
	void addCheckout(const Checkout& checkout);

	/**
	 * @brief Calcular lucro do Suprmarkt.
	 *
	 * Percorre todos os caixas do Suprmarkt e soma os seus lucros.
	 *
	 * @return Lucro total do Suprmarkt.
	 */
	double income() const;

	int totalClients() const;

	int lostClients() const;

	double lostMoney() const;

	/**
	 * @brief Executar simulação.
	 */
	void run();
};

} /* namespace suprmarkt */

#endif /* SUPRMARKT_H_ */
