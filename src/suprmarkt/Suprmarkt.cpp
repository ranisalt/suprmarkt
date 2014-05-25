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
		_name(), _time(), _avgClientArrival(), _queues() {
}

Suprmarkt::~Suprmarkt() {
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

void Suprmarkt::addCheckout(const Checkout& checkout) {
	_queues.push_back(checkout);
}

double Suprmarkt::income() const {
	double total = 0.0;
	for (auto checkout : _queues) {
		total += checkout.cashier().totalIncome();
	}
	return total;
}

void Suprmarkt::run() {
	int _run = 0;
	int _timeForNextClient = (rand() % 3) + 6;
	int _lostClients = 0;
	int _totalClients = 0;
	double _lostMoney = 0.0;

	while (_run < _time) {
		for (auto it = _queues.begin(); it != _queues.end(); ++it) {
			std::cout << "Cashier\n";
			it->dequeue(_run);
		}

		if (_run == _timeForNextClient) {
			auto client = makeClient(_run);
			++_totalClients;
			try {
				client.enterBestQueue(_queues);
			} catch (std::exception& e) {
				++_lostClients;
				_lostMoney += client.cartValue();
			}
			_timeForNextClient += (rand() % 3) + _avgClientArrival - 1;
		}

		++_run;
	}

	cout << _lostClients << '/' << _totalClients;

	for (auto checkout : _queues) {
		/*cout << checkout.cashier().name() << '\n';
		 cout << checkout.length() << '\n';
		 cout << _lostClients << '\n';*/
	}
}

} /* namespace suprmarkt */
