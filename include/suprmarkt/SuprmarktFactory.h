/*
 * SuprmarktFactory.h
 *
 *  Created on: 22/05/2014
 *      Author: ranieri
 */

#ifndef SUPRMARKTFACTORY_H_
#define SUPRMARKTFACTORY_H_

#include <string>
using std::string;

#include <suprmarkt/Suprmarkt.h>

namespace suprmarkt {

class SuprmarktFactory {
public:
	static Suprmarkt makeSupermarket();
	static Suprmarkt makeSupermarket(string filename);
};

} /* namespace suprmarkt */

#endif /* SUPRMARKTFACTORY_H_ */
