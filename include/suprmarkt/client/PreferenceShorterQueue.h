/*
 * PreferenceShorterQueue.h
 *
 *  Created on: 21/05/2014
 *      Author: ranieri
 */

#ifndef PREFERENCESHORTERQUEUE_H_
#define PREFERENCESHORTERQUEUE_H_

#include <suprmarkt/client/Preference.h>

namespace suprmarkt {
namespace client {

class PreferenceShorterQueue: public Preference {
public:
	using Preference::chooseQueue;
	Checkout& chooseQueue(deque<Checkout>&);
};

} /* namespace client */
} /* namespace suprmarkt */

#endif /* PREFERENCESHORTERQUEUE_H_ */
