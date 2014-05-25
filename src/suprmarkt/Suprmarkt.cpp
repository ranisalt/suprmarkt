/*
 * Suprmarkt.cpp
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#include <iostream>
using std::cout;

#include <string>
using std::string;

#include "suprmarkt/Suprmarkt.h"
#include "suprmarkt/client/ClientFactory.h"
using suprmarkt::client::ClientFactory;

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
	double _lostMoney = 0.0;

	while (_run < _time) {
		for (auto checkout : _queues) {
			checkout.dequeue(_run);
		}

		if (_run == _timeForNextClient) {
			auto client = ClientFactory::makeClient(_run);
			try {
				client.enterBestQueue(_queues);
			} catch (std::exception& e) {
				cout << "Cliente perdido no tempo " << _run << '\n';
				++_lostClients;
				_lostMoney += client.cartValue();
			}
			_timeForNextClient += (rand() % 3) + 6;
		}

		++_run;
	}

	for (auto checkout : _queues) {
		/*cout << checkout.cashier().name() << '\n';
		 cout << checkout.length() << '\n';
		 cout << _lostClients << '\n';*/
	}
}

} /* namespace suprmarkt */
