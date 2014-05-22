/*
 * PreferenceFewerItems.h
 *
 *  Created on: May 21, 2014
 *      Author: ranieri
 */

#ifndef PREFERENCEFEWERITEMS_H_
#define PREFERENCEFEWERITEMS_H_

#include <suprmarkt/client/Preference.h>

namespace suprmarkt {
namespace client {

class PreferenceFewerItems: public Preference {
public:
	using Preference::chooseQueue;
	Checkout& chooseQueue(deque<Checkout>& queues);
};

} /* namespace client */
} /* namespace suprmarkt */

#endif /* PREFERENCEFEWERITEMS_H_ */
