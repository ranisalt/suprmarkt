/*
 * Preference.h
 *
 *  Created on: 21/05/2014
 *      Author: ranieri
 */

#ifndef PREFERENCE_H_
#define PREFERENCE_H_

//#include <structures/List.h>
#include <deque>
using std::deque;

#include <suprmarkt/checkout/Checkout.h>
using suprmarkt::checkout::Checkout;

namespace suprmarkt {
namespace client {

class Preference {
public:
	virtual ~Preference();
	virtual Checkout& chooseQueue(const deque<Checkout>&) = 0;
};

} /* namespace client */
} /* namespace suprmarkt */

#endif /* PREFERENCE_H_ */
