/*
 * Suprmarkt.h
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#ifndef SUPRMARKT_H_
#define SUPRMARKT_H_

#include <string>
#include "structures/List.h"

#include "suprmarkt/checkout/Checkout.h"
using suprmarkt::checkout::Checkout;

namespace suprmarkt {

class Suprmarkt {
	typedef std::string string;

	string _name;
	int _time;
	List<Checkout> _queues;

public:
	Suprmarkt();
	virtual ~Suprmarkt();

	string name() const;
	void name(const string& name);

	int time() const;
	void time(int time);

	void addCheckout(const Checkout& checkout);

	double income() const;

	void run();
};

} /* namespace suprmarkt */

#endif /* SUPRMARKT_H_ */
