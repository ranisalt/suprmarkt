/*
 * ClientFactory.h
 *
 *  Created on: 21/05/2014
 *      Author: ranieri
 */

#ifndef CLIENTFACTORY_H_
#define CLIENTFACTORY_H_

#include <suprmarkt/client/Client.h>

namespace suprmarkt {
namespace client {

class ClientFactory {
public:
	static Client makeClient(int time);
};

} /* namespace client */
} /* namespace suprmarkt */

#endif /* CLIENTFACTORY_H_ */
