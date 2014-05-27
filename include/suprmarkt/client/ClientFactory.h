/*
 * ClientFactory.h
 *
 *  Created on: 21/05/2014
 *      Author: ranieri
 */

#ifndef CLIENTFACTORY_H_
#define CLIENTFACTORY_H_

#include "suprmarkt/client/Client.h"

namespace suprmarkt {
namespace client {
namespace ClientFactory {

/**
 * @brief Fabrica um Client que chega no supermercado.
 * @param time Tempo de chegada do Client.
 * @return Client fabricado.
 */
Client makeClient(int time);

} /* namespace ClientFactory */
} /* namespace client */
} /* namespace suprmarkt */

#endif /* CLIENTFACTORY_H_ */
