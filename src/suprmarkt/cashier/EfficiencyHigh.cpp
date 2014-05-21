/*
 * EfficiencyHigh.cpp
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#include <suprmarkt/cashier/EfficiencyHigh.h>

#include <suprmarkt/client/PaymentCheck.h>
using suprmarkt::client::PaymentCheck;

#include <suprmarkt/client/PaymentMoney.h>
using suprmarkt::client::PaymentMoney;

namespace suprmarkt {
namespace cashier {

Efficiency* EfficiencyHigh::copy() const {
	return new EfficiencyHigh();
}

int EfficiencyHigh::paymentTime(const Payment& paymentType) const {
	if (&PaymentCheck::getInstance() == &paymentType) {
		return 10;
	}
	return 0;
}

} /* namespace cashier */
} /* namespace suprmarkt */
