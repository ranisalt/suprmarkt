/*
 * SuprmarktFactory.h
 *
 *  Created on: 22/05/2014
 *      Author: ranieri
 */

#ifndef SUPRMARKTFACTORY_H_
#define SUPRMARKTFACTORY_H_

#include <string>
#include "suprmarkt/Suprmarkt.h"
using std::string;

namespace suprmarkt {
namespace SuprmarktFactory {

/**
 * @brief Fabrica um supermercado recebendo input direto do usuário.
 * @return Supermercado fabricado.
 */
Suprmarkt makeSupermarket();

/**
 * @brief Fabrica um supermercado de acordo com o conteúdo de um arquivo.
 * @param filename Nome do arquivo de configuração.
 * @return Supermercado fabricado.
 */
Suprmarkt makeSupermarket(char* filename);

}
} /* namespace suprmarkt */

#endif /* SUPRMARKTFACTORY_H_ */
