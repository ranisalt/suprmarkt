/*
 * SuprmarktFactory.cpp
 *
 *  Created on: 22/05/2014
 *      Author: ranieri
 */

#include <suprmarkt/SuprmarktFactory.h>

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

namespace suprmarkt {

Suprmarkt SuprmarktFactory::makeSupermarket() {

}

Suprmarkt SuprmarktFactory::makeSupermarket(string filename) {
	string input;

	Suprmarkt super = Suprmarkt{};

	cout << "Informe o nome do supermercado: ";
	cin >> input;
	super.name(input);

	return super;
}

} /* namespace suprmarkt */
