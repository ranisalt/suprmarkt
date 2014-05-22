/*
 * Cashier.cpp
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#include <suprmarkt/cashier/Cashier.h>

namespace suprmarkt {
namespace cashier {

Cashier::Cashier(const string& name, double salary, Efficiency* efficiency) :
		_name(name), _salary(salary), _efficiency(efficiency), _clientsServed(), _totalSold(), _totalIncome() {
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

void receivePayment(int cartSize, int cartValue, Payment* paymentMethod) {

}

} /* namespace cashier */
} /* namespace suprmarkt */
