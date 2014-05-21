/*
 * Client.h
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include <suprmarkt/client/Payment.h>

namespace suprmarkt {
namespace client {

class Client {
public:
	Client();
	Client(int, double, Payment*);
	virtual ~Client();

	int arrivalTime() const;
	void arrivalTime(int arrivalTime);

	int leavingTime() const;
	void leavingTime(int leavingTime);

	int cartSize() const;
	double cartValue() const;

	Payment& paymentType() const;

private:
	int _arrivalTime;
	int _leavingTime;

	int _cartSize;
	double _cartValue;
	Payment* _paymentType;
};

} /* namespace client */
} /* namespace suprmarkt */

#endif /* CLIENT_H_ */
