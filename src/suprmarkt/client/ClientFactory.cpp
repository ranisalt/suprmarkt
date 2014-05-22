/*
 * ClientFactory.cpp
 *
 *  Created on: 21/05/2014
 *      Author: ranieri
 */

#include <suprmarkt/client/ClientFactory.h>

using suprmarkt::client::Payment;

// rand()
#include <stdlib.h>

namespace suprmarkt {
namespace client {

Client ClientFactory::makeClient() {
	Payment paymentType = (rand() % 5) ? Payment::MONEY : Payment::CHECK;

	int cartSize = (rand() % 99) + 2;
	double cartValue = (rand() % 8901 / 100.0) + 1;

	Client c = Client(cartSize, cartValue, paymentType);
	return c;
}

} /* namespace client */
} /* namespace suprmarkt */
