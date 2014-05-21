/*
 * Payment.h
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#ifndef PAYMENT_H_
#define PAYMENT_H_

namespace suprmarkt {
namespace client {

class Payment {
public:
	virtual ~Payment();
	static Payment& getInstance();

protected:
	Payment();
	Payment(const Payment&);
	Payment& operator=(const Payment&);
};

} /* namespace client */
} /* namespace suprmarkt */

#endif /* PAYMENT_H_ */
