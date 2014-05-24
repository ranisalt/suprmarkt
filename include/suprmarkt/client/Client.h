/*
 * Client.h
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include "structures/List.h"

namespace suprmarkt {

namespace checkout {
class Checkout;
}

namespace client {
	enum Payment {
		CHECK, MONEY
	};
	enum Preference {
		FEWER, SHORTER
	};

class Client {
public:
    typedef checkout::Checkout Checkout;

	Client();
	Client(int, double, int arrivalTime, const Payment&, const Preference&);
	Client(const Client&);
	virtual ~Client();

	int arrivalTime() const;
	void arrivalTime(int arrivalTime);

	int leavingTime() const;
	void leavingTime(int leavingTime);

	int cartSize() const;
	double cartValue() const;

	Payment paymentType() const;
	void enterBestQueue(List<Checkout>& queues);

private:
	int _arrivalTime;
	int _leavingTime;

	int _cartSize;
	double _cartValue;
	Payment _paymentType;
	Preference _preferenceQueue;
};

} /* namespace client */
} /* namespace suprmarkt */

#endif /* CLIENT_H_ */
