/*
 * Suprmarkt.h
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#ifndef SUPRMARKT_H_
#define SUPRMARKT_H_

#include <structures/List.h>

#include <suprmarkt/checkout/Checkout.h>
using suprmarkt::checkout::Checkout;

namespace suprmarkt {

class Suprmarkt {
	string _name;
	List<Checkout> _queues;

public:
	Suprmarkt();
	virtual ~Suprmarkt();

	string name() const;
	void name(const string& name);

	void run();
};

} /* namespace suprmarkt */

#endif /* SUPRMARKT_H_ */
