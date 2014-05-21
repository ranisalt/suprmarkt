/*
 * Efficiency.cpp
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#include <suprmarkt/cashier/Efficiency.h>

namespace suprmarkt {
namespace cashier {

Efficiency::~Efficiency() {
}

int Efficiency::processTime(const Client& client) const {
	return client.cartSize() * itemFactor
			+ this->paymentTime(client.paymentType());
}

} /* namespace cashier */
} /* namespace suprmarkt */
