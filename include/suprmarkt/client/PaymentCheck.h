/*
 * PaymentCheck.h
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#ifndef PAYMENTCHECK_H_
#define PAYMENTCHECK_H_

#include <suprmarkt/client/Payment.h>

namespace suprmarkt {
namespace client {

class PaymentCheck: public Payment {
public:
	static Payment& getInstance();
};

} /* namespace cashier */
} /* namespace suprmarkt */

#endif /* PAYMENTCHECK_H_ */
