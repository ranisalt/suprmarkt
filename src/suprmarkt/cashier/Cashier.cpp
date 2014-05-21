/*
 * Cashier.cpp
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#include <suprmarkt/cashier/Cashier.h>

namespace suprmarkt {
namespace cashier {

Cashier::Cashier(string name, double salary, const Efficiency& efficiency) :
		_name(name), _salary(salary), _efficiency(efficiency.copy()), _clientsServed(), _totalIncome() {
}

Cashier::~Cashier() {
}

string Cashier::name() const {
	return _name;
}

void Cashier::name(string name) {
	_name = name;
}

double Cashier::salary() const {
	return _salary;
}

void Cashier::salary(double salary) {
	_salary = salary;
}

Efficiency& Cashier::efficiency() const {
	return *_efficiency;
}

int Cashier::clientsServed() const {
	return _clientsServed;
}

void Cashier::clientsServed(int clientsServed) {
	_clientsServed = clientsServed;
}

double Cashier::totalIncome() const {
	return _totalIncome;
}

void Cashier::totalIncome(double totalIncome) {
	_totalIncome = totalIncome;
}

} /* namespace cashier */
} /* namespace suprmarkt */
