/*
 * Efficiency.h
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#ifndef EFFICIENCY_H_
#define EFFICIENCY_H_

#include <suprmarkt/client/Client.h>
using suprmarkt::client::Client;

#include <suprmarkt/client/Payment.h>
using suprmarkt::client::Payment;

namespace suprmarkt {
namespace cashier {

class Efficiency {
public:
	virtual ~Efficiency();
	virtual Efficiency* copy() const = 0;

	int processTime(const Client&) const;

protected:
	int itemFactor;
	virtual int paymentTime(const Payment&) const = 0;
};

} /* namespace cashier */
} /* namespace suprmarkt */

#endif /* EFFICIENCY_H_ */
