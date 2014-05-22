/*
 * EfficiencyHigh.cpp
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#include <suprmarkt/cashier/EfficiencyHigh.h>

#include <suprmarkt/client/Client.h>
using suprmarkt::client::Payment;

namespace suprmarkt {
namespace cashier {

int EfficiencyHigh::paymentTime(const Payment& paymentType) const {
	if (Payment::CHECK == paymentType) {
		return 10;
	}
	return 0;
}

} /* namespace cashier */
} /* namespace suprmarkt */
