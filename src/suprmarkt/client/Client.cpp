/*
 * Client.cpp
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#include <suprmarkt/client/Client.h>
#include <suprmarkt/checkout/Checkout.h>

using suprmarkt::checkout::Checkout;

namespace suprmarkt {
namespace client {

Client::Client() :
		_arrivalTime(), _leavingTime(), _cartSize(), _cartValue(), _paymentType(), _preferenceQueue() {
}

Client::Client(int cartSize, double cartValue, int arrivalTime,
		const Payment& paymentType, const Preference& preference) :
		_arrivalTime(arrivalTime), _leavingTime(), _cartSize(cartSize), _cartValue(
				cartValue), _paymentType(paymentType), _preferenceQueue(
				preference) {
}

Client::Client(const Client& rhs) :
		_arrivalTime(rhs._arrivalTime), _leavingTime(rhs._leavingTime), _cartSize(
				rhs._cartSize), _cartValue(rhs._cartValue), _paymentType(
				rhs._paymentType), _preferenceQueue(rhs._preferenceQueue) {

}

Client::~Client() {
	// TODO Auto-generated destructor stub
}

int Client::arrivalTime() const {
	return _arrivalTime;
}

void Client::arrivalTime(int arrivalTime) {
	_arrivalTime = arrivalTime;
}

int Client::leavingTime() const {
	return _leavingTime;
}

void Client::leavingTime(int leavingTime) {
	using std::cout;
	cout << "adicionando, n, mais que adicionando:" << leavingTime << '\n';
	_leavingTime = leavingTime;
}

int Client::cartSize() const {
	return _cartSize;
}

double Client::cartValue() const {
	return _cartValue;
}

Payment Client::paymentType() const {
	return _paymentType;
}

void Client::enterBestQueue(List<Checkout>& queues) {
	if (Preference::FEWER == _preferenceQueue) {
		auto chosen = queues.begin();
		for (auto it = ++queues.begin(); it != queues.end(); ++it) {
			if (it->countItems() < chosen->countItems() && it->length() < 10)
				chosen = it;
		}
		if (chosen->length() < 10) {
			chosen->enqueue(*this);
			return;
		}
	} else if (Preference::SHORTER == _preferenceQueue) {
		auto chosen = queues.begin();
		for (auto it = ++queues.begin(); it != queues.end(); ++it) {
			if (it->length() < chosen->length())
				chosen = it;
		}
		if (chosen->length() < 10) {
			chosen->enqueue(*this);
			return;
		}
	}
	throw std::exception();
}

} /* namespace client */
} /* namespace suprmarkt */
