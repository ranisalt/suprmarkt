/*
 * ClientFactory.cpp
 *
 *  Created on: 21/05/2014
 *      Author: ranieri
 */

#include <suprmarkt/client/ClientFactory.h>

#include <stdlib.h>

namespace suprmarkt {
namespace client {

Client ClientFactory::makeClient(int time) {
	Payment paymentType = (rand() % 5) ? Payment::MONEY : Payment::CHECK;
	Preference preference = (rand() % 2) ? Preference::FEWER : Preference::SHORTER;

	int cartSize = (rand() % 99) + 2;
	double cartValue = (rand() % 8901 / 100.0) + 1;

	Client c = Client(cartSize, cartValue, time, paymentType, preference);
	return c;
}

} /* namespace client */
} /* namespace suprmarkt */
