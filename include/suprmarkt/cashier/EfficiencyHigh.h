/*
 * EfficiencyHigh.h
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#ifndef EFFICIENCYHIGH_H_
#define EFFICIENCYHIGH_H_

#include <suprmarkt/cashier/Efficiency.h>

namespace suprmarkt {
namespace cashier {

class EfficiencyHigh: public Efficiency {
protected:
	int paymentTime(const Payment& paymentType) const;
};

} /* namespace cashier */
} /* namespace suprmarkt */

#endif /* EFFICIENCYHIGH_H_ */
