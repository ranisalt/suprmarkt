/*
 * Checkout.h
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#ifndef CHECKOUT_H_
#define CHECKOUT_H_

//#include <structures/List.h>
#include <deque>
using std::deque;

#include <suprmarkt/cashier/Cashier.h>
using suprmarkt::cashier::Cashier;

#include <suprmarkt/client/Client.h>
using suprmarkt::client::Client;

namespace suprmarkt {
namespace checkout {

class Checkout {
	Cashier _cashier;
	//List<Client> _queue;
	deque<Client> _queue;

public:
	//Checkout(const Cashier&, const List<Client>&);
	Checkout(const Cashier&, const deque<Client>&);
	virtual ~Checkout();

	Cashier cashier() const;

	void dequeue(int time);
	void enqueue(Client&);

	int countItems() const;
	int length() const;
};

} /* namespace checkout */
} /* namespace suprmarkt */

#endif /* CHECKOUT_H_ */
