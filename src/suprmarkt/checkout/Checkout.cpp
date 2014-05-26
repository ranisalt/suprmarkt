/*
 * Checkout.cpp
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#include "suprmarkt/checkout/Checkout.h"

namespace suprmarkt {
namespace checkout {

Checkout::Checkout() :
		_totalWaiting() {
}

Checkout::Checkout(const Cashier& cashier) :
		_cashier(cashier), _queue(), _totalWaiting() {
}

Cashier Checkout::cashier() const {
	return _cashier;
}

int Checkout::totalWaiting() const {
	return _totalWaiting;
}

void Checkout::dequeue(int time) {
	if (_queue.empty()) {
		std::cout << "empty";
		return;
	}

	auto client = _queue.front();
	if (time == client.leavingTime()) {
		std::cout << "Chegou aqui alguma vez";
		_cashier.clientsServed(_cashier.clientsServed() + 1);
		_cashier.totalIncome(_cashier.totalIncome() + client.cartValue());
		_totalWaiting += time - client.arrivalTime();
		_queue.pop_front();
	}
}

void Checkout::enqueue(Client& client) {
	auto leavingTime = _cashier.processTime(client);
	if (_queue.empty())
		leavingTime += client.arrivalTime();
	else
		leavingTime += _queue.back().leavingTime();

	client.leavingTime(leavingTime);
	_queue.push_back(client);
}

int Checkout::countItems() const {
	auto count = 0;
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
