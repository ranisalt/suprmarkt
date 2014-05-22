/*
 * EfficiencyMedium.h
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#ifndef EFFICIENCYMEDIUM_H_
#define EFFICIENCYMEDIUM_H_

#include <suprmarkt/cashier/Efficiency.h>

namespace suprmarkt {
namespace cashier {

class EfficiencyMedium: public Efficiency {
protected:
	int paymentTime(const Payment& paymentType) const;
};

} /* namespace cashier */
} /* namespace suprmarkt */

#endif /* EFFICIENCYMEDIUM_H_ */
