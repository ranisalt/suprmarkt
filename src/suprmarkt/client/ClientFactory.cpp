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
	auto paymentType = (rand() % 5) ? Payment::MONEY : Payment::CHECK;
	auto preference = (rand() % 2) ? Preference::FEWER : Preference::SHORTER;

	auto cartSize = rand() % 99 + 2;
	auto cartValue = 0.0;
	for (int i = 0; i < cartSize; ++i)
		cartValue += rand() % 8901 / 100.0 + 1;

	auto c = Client { cartSize, cartValue, time, paymentType, preference };
	return c;
}

} /* namespace client */
} /* namespace suprmarkt */
