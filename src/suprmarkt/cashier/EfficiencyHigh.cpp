/*
 * EfficiencyHigh.cpp
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#include "suprmarkt/cashier/EfficiencyHigh.h"

#include "suprmarkt/client/Client.h"
using suprmarkt::client::Payment;

namespace suprmarkt {
namespace cashier {

int EfficiencyHigh::processTime(const Client& client) const {
	int time = client.cartSize();
	if (Payment::CHECK == client.paymentType()) {
		time += 10;
	}
	return time;
}

} /* namespace cashier */
} /* namespace suprmarkt */
