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

int EfficiencyMedium::itemFactor() const {
	return 2;
}

int EfficiencyMedium::paymentTime(const Payment& paymentType) const {
	if (Payment::CHECK == paymentType) {
		return 25;
	}
	return 0;
}

} /* namespace cashier */
} /* namespace suprmarkt */
