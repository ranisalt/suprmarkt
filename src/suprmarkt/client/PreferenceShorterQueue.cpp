/*
 * PreferenceShorterQueue.cpp
 *
 *  Created on: 21/05/2014
 *      Author: ranieri
 */

#include <suprmarkt/client/PreferenceShorterQueue.h>

#include <stdexcept>

namespace suprmarkt {
namespace client {

//Checkout& PreferenceShorterQueue::chooseQueue(List<Checkout>& queues) {
Checkout& PreferenceShorterQueue::chooseQueue(deque<Checkout>& queues) {
	if (queues.size()) {
		auto chosen = queues.begin();
		for (auto it = ++queues.begin(); it != queues.end(); ++it) {
			if (it->length() < chosen->length())
				chosen = it;
		}
		if (chosen->length() < 10)
			return *chosen;
	}
	throw std::exception();
}

} /* namespace client */
} /* namespace suprmarkt */
