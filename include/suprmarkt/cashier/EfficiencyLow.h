/*
 * EfficiencyLow.h
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#ifndef EFFICIENCYLOW_H_
#define EFFICIENCYLOW_H_

#include <suprmarkt/cashier/Efficiency.h>

namespace suprmarkt {
namespace cashier {

class EfficiencyLow: public Efficiency {
public:
	Efficiency* copy() const;

protected:
	int paymentTime(const Payment&) const;
};

} /* namespace cashier */
} /* namespace suprmarkt */

#endif /* EFFICIENCYLOW_H_ */
