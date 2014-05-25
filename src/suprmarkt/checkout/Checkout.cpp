/*
 * Checkout.cpp
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#include "suprmarkt/checkout/Checkout.h"

namespace suprmarkt {
namespace checkout {

Checkout::Checkout() {
}

Checkout::Checkout(const Cashier& cashier) :
		_cashier(cashier), _queue() {
}

Checkout::~Checkout() {
}

Cashier Checkout::cashier() const {
	return _cashier;
}

void Checkout::dequeue(int time) {
	if (_queue.empty())
		return;

	Client client = _queue.front();
	if (time == client.leavingTime()) {
		std::cout << "Chegou aqui alguma vez";
		_cashier.clientsServed(_cashier.clientsServed() + 1);
		_cashier.totalIncome(_cashier.totalIncome() + client.cartValue());
		_queue.pop_front();
	}
}

void Checkout::enqueue(Client& client) {
	int leavingTime = _cashier.processTime(client);
	if (_queue.empty())
		leavingTime += client.arrivalTime();
	else
		leavingTime += _queue.back().leavingTime();

	client.leavingTime(leavingTime);
	_queue.push_back(client);
}

int Checkout::countItems() const {
	int count = 0;
	for (auto client : _queue) {
		count += client.cartSize();
	}
	return count;
}

int Checkout::length() const {
	return _queue.size();
}

} /* namespace checkout */
} /* namespace suprmarkt */
