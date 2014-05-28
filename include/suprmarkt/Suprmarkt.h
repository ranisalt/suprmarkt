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
	using string = std::string;
	template<typename T> using List = structures::List<T>;

public:
	/**
	 * @brief Construtor completo de Suprmarkt.
	 * @param name Nome do Suprmarkt.
	 * @param time Tempo de simulação em segundos.
	 * @param avgClientArrival Tempo médio de chegada de clientes em segundos.
	 * @param queues Filas do Suprmarkt.
	 */
	Suprmarkt(const string& name, int time, int avgClientArrival,
			const List<Checkout> &queues);

	/**
	 * @brief Acesso ao nome do Suprmarkt.
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
	 * @return Tempo atual da simulação.
	 */
	int time() const;

	/**
	 * @brief Mutação do tempo atual da simulação do Suprmarkt.
	 * @param time Novo tempo atual da simulação.
	 */
	void time(int time);

	/**
	 * @brief Acesso ao tempo médio de chegada de Clients.
	 * @return Tempo médio de chegada de Clients.
	 */
	int avgClientArrival() const;

	/**
	 * @brief Mutação do tempo médio de chegada de Clients.
	 * @param avgClientArrival Novo tempo médio de chegada de Clients.
	 */
	void avgClientArrival(int avgClientArrival);

	/**
	 * @brief Contar Checkouts em um Suprmarkt.
	 * @return Contagem de Checkouts.
	 */
	const List<Checkout> &checkouts() const;

	/**
	 * @brief Adicionar Checkout ao Suprmarkt.
	 * @details Adiciona um Checkout completo à lista de Checkouts do Suprmarkt.
	 * @param checkout Novo Checkout.
	 */
	void addCheckout(const Checkout& checkout);

	/**
	 * @brief Verifica se os Checkouts estão vazios.
	 * @return Checkouts estão vazios.
	 */
	bool empty() const;

	/**
	 * @brief Calcular lucro do Suprmarkt.
	 * @details Percorre todos os caixas do Suprmarkt e soma os seus lucros.
	 * @return Lucro total do Suprmarkt.
	 */
	double income() const;

	/**
	 * @brief Calcular o total de clientes do Suprmarkt.
	 * @return Total de clientes.
	 */
	int totalClients() const;

	/**
	 * @brief Calcular o total de clientes que abandonaram o Suprmarkt.
	 * @return Total de clientes que abandonaram.
	 */
	int lostClients() const;

	/**
	 * @brief Calcular o total de dinheiro perdido por clientes que abandonaram.
	 * @return Total de dinheiro perdido.
	 */
	double lostMoney() const;

	/**
	 * @brief Executar simulação.
	 */
	void run();

private:
	string _name;
	int _time;
	int _avgClientArrival;
	int _totalClients { };
	int _lostClients { };
	double _lostMoney { };
	List<Checkout> _queues;
};

} /* namespace suprmarkt */

#endif /* SUPRMARKT_H_ */
