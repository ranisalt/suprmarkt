/*
 * EfficiencyMedium.cpp
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#include <suprmarkt/cashier/EfficiencyMedium.h>

#include <suprmarkt/client/PaymentCheck.h>
using suprmarkt::client::PaymentCheck;

#include <suprmarkt/client/PaymentMoney.h>
using suprmarkt::client::PaymentMoney;

namespace suprmarkt {
namespace cashier {

Efficiency* EfficiencyMedium::copy() const {
	return new EfficiencyMedium();
}

int EfficiencyMedium::paymentTime(const Payment& paymentType) const {
	if (&PaymentCheck::getInstance() == &paymentType) {
		return 10;
	}
	return 0;
}

} /* namespace cashier */
} /* namespace suprmarkt */
