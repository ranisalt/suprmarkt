/*
 * Client.cpp
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#include "suprmarkt/client/Client.h"
#include "suprmarkt/checkout/Checkout.h"

using suprmarkt::checkout::Checkout;

namespace suprmarkt {
namespace client {

Client::Client(int cartSize, double cartValue, int arrivalTime,
		const Payment& paymentType, const Preference& preference) :
		_arrivalTime(arrivalTime),  _cartSize(cartSize),
		_cartValue(cartValue), _paymentType(paymentType),
		_preferenceQueue(preference) {
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
	auto chosen = begin(queues);
	if (Preference::FEWER == _preferenceQueue) {
		for (auto it = ++begin(queues); it != end(queues); ++it) {
			if (it->countItems() < chosen->countItems() && it->length() < 10)
				chosen = it;
		}
	} else if (Preference::SHORTER == _preferenceQueue) {
		for (auto it = ++queues.begin(); it != queues.end(); ++it)
			if (it->length() < chosen->length())
				chosen = it;
	}

	if (chosen->length() < 10) {
		chosen->enqueue(*this);
		return;
	}

	throw std::exception();
}

} /* namespace client */
} /* namespace suprmarkt */
