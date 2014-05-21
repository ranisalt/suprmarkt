/*
 * ClientFactory.cpp
 *
 *  Created on: 21/05/2014
 *      Author: ranieri
 */

#include <suprmarkt/client/ClientFactory.h>

#include <suprmarkt/client/Payment.h>
#include <suprmarkt/client/PaymentCheck.h>
#include <suprmarkt/client/PaymentMoney.h>

// rand()
#include <stdlib.h>

namespace suprmarkt {
namespace client {

Client ClientFactory::makeClient() {
	Payment paymentType;
	if (rand() % 5)
		paymentType = PaymentMoney();
	else
		paymentType = PaymentCheck();

	int cartSize = rand() % 99 + 2;
	double cartValue = rand() % 8901 / 100.0 + 1;

	Client c = Client(cartSize, cartValue, paymentType);
	return c;
}

} /* namespace client */
} /* namespace suprmarkt */
