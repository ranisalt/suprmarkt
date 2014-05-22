/*
 * PreferenceFewerItems.cpp
 *
 *  Created on: May 21, 2014
 *      Author: ranieri
 */

#include <suprmarkt/client/PreferenceFewerItems.h>

namespace suprmarkt {
namespace client {

//Checkout& PreferenceShorterQueue::chooseQueue(List<Checkout>& queues) {
Checkout& PreferenceFewerItems::chooseQueue(deque<Checkout>& queues) {
	if (queues.size()) {
		auto chosen = queues.begin();
		for (auto it = ++queues.begin(); it != queues.end(); ++it) {
			if (it->countItems() < chosen->countItems())
				chosen = it;
		}
		if (chosen->length() < 10)
			return *chosen;
	}
	throw std::exception();
}

} /* namespace client */
} /* namespace suprmarkt */
