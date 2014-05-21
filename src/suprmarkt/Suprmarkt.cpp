/*
 * Suprmarkt.cpp
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#include <suprmarkt/Suprmarkt.h>

namespace suprmarkt {

Suprmarkt::Suprmarkt(const List<Checkout>& queues) :
		_queues(queues) {
}

Suprmarkt::~Suprmarkt() {
}

} /* namespace suprmarkt */
