/*
 * Suprmarkt.h
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#ifndef SUPRMARKT_H_
#define SUPRMARKT_H_

//#include <structures/List.h>
#include <deque>
using std::deque;

#include <suprmarkt/checkout/Checkout.h>

using suprmarkt::checkout::Checkout;

namespace suprmarkt {

class Suprmarkt {
	//List<Checkout> _queues;
	deque<Checkout> _queues;

public:
	//Suprmarkt(const List<Checkout>&);
	Suprmarkt(const deque<Checkout>&);
	virtual ~Suprmarkt();

	void run();
};

} /* namespace suprmarkt */

#endif /* SUPRMARKT_H_ */
