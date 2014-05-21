/*
 * PaymentMoney.cpp
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#include <suprmarkt/client/PaymentMoney.h>

namespace suprmarkt {
namespace client {

Payment& PaymentMoney::getInstance() {
	static PaymentMoney instance;
	return instance;
}

} /* namespace cashier */
} /* namespace suprmarkt */
