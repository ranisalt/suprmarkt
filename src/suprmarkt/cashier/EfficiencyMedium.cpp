/*
 * EfficiencyMedium.cpp
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#include <suprmarkt/cashier/EfficiencyMedium.h>

#include <suprmarkt/client/Client.h>
using suprmarkt::client::Payment;

namespace suprmarkt {
namespace cashier {

int EfficiencyMedium::processTime(const Client& client) const {
	int time = client.cartSize() * 2;
	if (Payment::CHECK == client.paymentType()) {
		time += 25;
	}
	return time;
}

} /* namespace cashier */
} /* namespace suprmarkt */
