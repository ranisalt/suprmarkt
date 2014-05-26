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
using std::cout;
using std::string;
using suprmarkt::client::ClientFactory::makeClient;

namespace suprmarkt {

Suprmarkt::Suprmarkt() :
		_name(), _time(), _avgClientArrival(), _totalClients(), _lostClients(), _lostMoney(), _queues() {
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

List<Checkout> Suprmarkt::checkouts() const {
	return _queues;
}

void Suprmarkt::addCheckout(const Checkout& checkout) {
	_queues.push_back(checkout);
}

double Suprmarkt::income() const {
	auto total = 0.0;
	for (auto checkout : _queues) {
		total += checkout.cashier().totalIncome();
	}
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
	auto _run = 0;
	auto _timeForNextClient = rand() % 3 + _avgClientArrival;

	while (_run < _time) {
		for (auto it = _queues.begin(); it != _queues.end(); ++it)
			it->dequeue(_run);

		if (_run == _timeForNextClient) {
			auto client = makeClient(_run);
			++_totalClients;
			try {
				client.enterBestQueue(_queues);
			} catch (std::exception& e) {
				++_lostClients;
				_lostMoney += client.cartValue();
			}
			_timeForNextClient += rand() % 3 + _avgClientArrival - 1;
		}

		++_run;
	}

	cout << _lostClients << '/' << _totalClients << '\n';

	for (auto checkout : _queues) {
		/*cout << checkout.cashier().name() << '\n';
		 cout << checkout.length() << '\n';
		 cout << _lostClients << '\n';*/
	}
}

} /* namespace suprmarkt */
