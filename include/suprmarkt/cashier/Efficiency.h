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
using suprmarkt::client::Payment;

namespace suprmarkt {
namespace cashier {

class Efficiency {
public:
	virtual ~Efficiency();

	int processTime(const Client&) const;

protected:
	int itemFactor;
	virtual int paymentTime(const Payment& paymentType) const = 0;
};

} /* namespace cashier */
} /* namespace suprmarkt */

#endif /* EFFICIENCY_H_ */
