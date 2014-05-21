/*
 * PaymentCheck.cpp
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#include <suprmarkt/client/PaymentCheck.h>

namespace suprmarkt {
namespace client {

Payment& PaymentCheck::getInstance() {
	static PaymentCheck instance;
	return instance;
}

} /* namespace cashier */
} /* namespace suprmarkt */
