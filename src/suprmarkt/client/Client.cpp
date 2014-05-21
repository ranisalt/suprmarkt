/*
 * Client.cpp
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#include <suprmarkt/client/Client.h>

namespace suprmarkt {
namespace client {

Client::Client(int cartSize, double cartValue, const Payment& paymentType) :
		_arrivalTime(), _leavingTime(), _cartSize(cartSize), _cartValue(
				cartValue), _paymentType(paymentType) {
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

} /* namespace client */
} /* namespace suprmarkt */
