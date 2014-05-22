/*
 * Checkout.cpp
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#include <suprmarkt/checkout/Checkout.h>

namespace suprmarkt {
namespace checkout {

//Checkout::Checkout(const Cashier& cashier, const List<Client>& queue) :
Checkout::Checkout(const Cashier& cashier, const deque<Client>& queue) :
		_cashier(cashier), _queue(queue) {
}

Checkout::~Checkout() {
}

void Checkout::dequeue(int time) {
	if (_queue.empty())
		return;

	const Client& client = _queue.front();
	if (time == client.leavingTime()) {
		_cashier.clientsServed(_cashier.clientsServed() + 1);
		_cashier.totalIncome(_cashier.totalIncome() + client.cartValue());
		_queue.pop_front();
	}
}

void Checkout::enqueue(Client& client) {
	int leavingTime = _cashier.efficiency().processTime(client);
	leavingTime +=
			_queue.size() ? _queue.back().leavingTime() : client.arrivalTime();
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
