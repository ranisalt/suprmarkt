/*
 * PreferenceShorterQueue.h
 *
 *  Created on: 21/05/2014
 *      Author: ranieri
 */

#ifndef PREFERENCESHORTERQUEUE_H_
#define PREFERENCESHORTERQUEUE_H_

#include <suprmarkt/client/Preference.h>

#include <structures/List.h>

#include <suprmarkt/checkout/Checkout.h>
using suprmarkt::checkout::Checkout;

namespace suprmarkt {
namespace client {

class PreferenceShorterQueue: public Preference {
public:
	static Checkout& chooseQueue(List<Checkout>&);
};

} /* namespace client */
} /* namespace suprmarkt */

#endif /* PREFERENCESHORTERQUEUE_H_ */
