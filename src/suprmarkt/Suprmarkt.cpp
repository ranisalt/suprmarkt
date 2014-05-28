/*
 * Suprmarkt.cpp
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#include <iostream>
#include <string>

#include "suprmarkt/Suprmarkt.h"
#include "suprmarkt/client/ClientFactory.h"

using std::string;
using suprmarkt::client::ClientFactory::makeClient;
using structures::List;

namespace suprmarkt {

Suprmarkt::Suprmarkt(const string& name, int time, int avgClientArrival, const List<Checkout>& queues):
	_name{name}, _time{time}, _avgClientArrival{avgClientArrival}, _queues{queues} {
}

string Suprmarkt::name() const {
	return _name;
}

void Suprmarkt::name(const string& name) {
	_name = name;
}

int Suprmarkt::time() const {
	return _time;
}

void Suprmarkt::time(int time) {
	_time = time;
}

int Suprmarkt::avgClientArrival() const {
	return _avgClientArrival;
}

void Suprmarkt::avgClientArrival(int avgClientArrival) {
	_avgClientArrival = avgClientArrival;
}

const List<Checkout>& Suprmarkt::checkouts() const {
	return _queues;
}

void Suprmarkt::addCheckout(const Checkout& checkout) {
	_queues.push_back(checkout);
}

bool Suprmarkt::empty() const {
	for (const auto& queue : _queues)
		if (queue.length())
			return false;
	return true;
}

double Suprmarkt::income() const {
	auto total = 0.0;
	for (const auto& checkout : _queues)
		total += checkout.cashier().totalIncome();
	return total;
}

int Suprmarkt::totalClients() const {
	return _totalClients;
}

int Suprmarkt::lostClients() const {
	return _lostClients;
}

double Suprmarkt::lostMoney() const {
	return _lostMoney;
}

void Suprmarkt::run() {
	_lostClients = _totalClients = 0;
	_lostMoney = 0.0;
	auto running_time = 0;
	auto _timeForNextClient = (rand() % 3) + _avgClientArrival - 1;

	while (running_time < _time) {
		for (auto& queue : _queues)
			queue.dequeue(running_time);

		if (running_time == _timeForNextClient) {
			auto client = makeClient(running_time);
			++_totalClients;
			try {
				client.enterBestQueue(_queues);
			} catch (const std::exception& e) {
				++_lostClients;
				_lostMoney += client.cartValue();
			}
			_timeForNextClient += (rand() % 3) + _avgClientArrival - 1;
		}

		++running_time;
	}

	while (!empty()) {
		for (auto& queue : _queues)
			queue.dequeue(running_time);
		++running_time;
	}
}

} /* namespace suprmarkt */
