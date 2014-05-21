/*
 * PaymentMoney.h
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#ifndef PAYMENTMONEY_H_
#define PAYMENTMONEY_H_

#include <suprmarkt/client/Payment.h>

namespace suprmarkt {
namespace client {

class PaymentMoney: public Payment {
public:
	static Payment& getInstance();
};

} /* namespace cashier */
} /* namespace suprmarkt */

#endif /* PAYMENTMONEY_H_ */
