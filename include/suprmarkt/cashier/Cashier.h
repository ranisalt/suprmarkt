/*
 * Cashier.h
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#ifndef CASHIER_H_
#define CASHIER_H_

#include <memory>
#include <string>
#include "suprmarkt/client/Client.h"

namespace suprmarkt {
namespace cashier {

enum Efficiency {
	LOW, MEDIUM, HIGH,
};

class Cashier {
public:
	typedef std::string string;
	typedef client::Client Client;
	typedef client::Payment Payment;

	/**
	 *  @brief Construtor padrão de Cashier.
	 */
	Cashier();

	/**
	 * @brief Construtor completo de Cashier.
	 *
	 * @param name Nome do Cashier.
	 * @param salary Salário do Cashier.
	 * @param efficiency Ponteiro para a classe de eficiência do Cashier.
	 */
	Cashier(const string& name, double salary, Efficiency efficiency);

	/**
	 * @brief Acesso ao nome do Cashier.
	 *
	 * @return Nome do Cashier.
	 */
	string name() const;

	/**
	 * @brief Mutação do nome do Cashier.
	 *
	 * @param name Novo nome do Cashier.
	 */
	void name(string name);

	/**
	 * @brief Acesso ao salário do Cashier.
	 *
	 * @return Salário do Cashier.
	 */
	double salary() const;

	/**
	 * @brief Mutação do salário do Cashier.
	 *
	 * @param salary Novo salário do Cashier.
	 */
	void salary(double salary);

	/**
	 * @brief Cálculo do tempo necessário para processar o Client informado.
	 *
	 * Cada Cashier, de acordo com sua eficiência, possui um fator de tempo para cada unidade de item no carrinho do Client e um tempo de demora dependendo do método de pagamento do Client.
	 *
	 * @return Tempo necessário para processar o Client.
	 */
	int processTime(const Client& client) const;

	/**
	 * @brief Mutação da eficiência do Cashier
	 *
	 * @param efficiency Ponteiro para a nova classe de eficiência do Cashier.
	 */
	void efficiency(Efficiency efficiency);

	/**
	 * @brief Acesso à contagem de clientes atendidos pelo Cashier.
	 *
	 * @return Contagem de clientes atendidos pelo Cashier.
	 */
	int clientsServed() const;

	/**
	 * @brief Mutação da contagem de clientes atendidos pelo Cashier.
	 *
	 * @param clientsServed Nova contagem de clientes atendidos pelo Cashier.
	 */
	void clientsServed(int clientsServed);

	/**
	 * @brief Acesso ao total de itens vendidos pelo Cashier.
	 *
	 * @return Total de itens vendidos pelo Cashier.
	 */
	int totalSold() const;

	/**
	 * @brief Mutação do total de itens vendidos pelo Cashier.
	 *
	 * @param totalSold Novo total de itens vendidos pelo Cashier.
	 */
	void totalSold(int totalSold);

	/**
	 * @brief Acesso ao lucro total obtido pelo Cashier.
	 *
	 * @return Lucro total obtido pelo Cashier.
	 */
	double totalIncome() const;

	/**
	 * @brief Mutação do lucro total obtido pelo Cashier.
	 *
	 * @param totalIncome Novo lucro total obtido pelo Cashier.
	 */
	void totalIncome(double totalIncome);

private:
	string _name;
	double _salary;
	Efficiency _efficiency;

	int _clientsServed;
	int _totalSold;
	double _totalIncome;
};

} /* namespace cashier */
} /* namespace suprmarkt */

#endif /* CASHIER_H_ */
