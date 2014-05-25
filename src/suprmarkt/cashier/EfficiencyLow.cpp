/*
 * EfficiencyLow.cpp
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#include <suprmarkt/cashier/EfficiencyLow.h>

#include <suprmarkt/client/Client.h>
using suprmarkt::client::Payment;

namespace suprmarkt {
namespace cashier {

int EfficiencyLow::processTime(const Client& client) const {
	int time = client.cartSize() * 4;
	if (Payment::CHECK == client.paymentType()) {
		time += 60;
	}
	return time;
}

} /* namespace cashier */
} /* namespace suprmarkt */
