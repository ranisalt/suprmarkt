/*
 * Cashier.cpp
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#include <string>
#include "suprmarkt/cashier/Cashier.h"
using std::string;
using suprmarkt::client::Payment;

namespace suprmarkt {
namespace cashier {

Cashier::Cashier(const string& name, double salary, Efficiency efficiency) :
		_name(name), _salary(salary), _efficiency(efficiency), _clientsServed(), _totalSold(), _totalIncome() {
}

const string& Cashier::name() const {
	return _name;
}

void Cashier::name(const string &name) {
	_name = name;
}

double Cashier::salary() const {
	return _salary;
}

void Cashier::salary(double salary) {
	_salary = salary;
}

int Cashier::processTime(const Client& client) const {
	int time { client.cartSize() };
	switch (_efficiency) {
	case Efficiency::HIGH:
		if (Payment::CHECK == client.paymentType())
			time += 10;
		break;
	case Efficiency::MEDIUM:
		time = time << 1;
		if (Payment::CHECK == client.paymentType())
			time += 25;
		break;
	case Efficiency::LOW:
		time = time << 2;
		if (Payment::CHECK == client.paymentType())
			time += 60;
		break;
	}
	return time;
}

void Cashier::efficiency(Efficiency efficiency) {
	_efficiency = efficiency;
}

int Cashier::clientsServed() const {
	return _clientsServed;
}

void Cashier::clientsServed(int clientsServed) {
	_clientsServed = clientsServed;
}

int Cashier::totalSold() const {
	return _totalSold;
}

void Cashier::totalSold(int totalSold) {
	_totalSold = totalSold;
}

double Cashier::totalIncome() const {
	return _totalIncome;
}

void Cashier::totalIncome(double totalIncome) {
	_totalIncome = totalIncome;
}

} /* namespace cashier */
} /* namespace suprmarkt */
