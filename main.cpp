#include <iostream>
using std::cout;

#include <string.h>

#include "suprmarkt/Suprmarkt.h"
using suprmarkt::Suprmarkt;

#include "suprmarkt/SuprmarktFactory.h"
using suprmarkt::SuprmarktFactory;

int main(int argc, char** argv) {
	Suprmarkt super;
	if (argc == 3 && !strcmp("-f", argv[1]))
		super = SuprmarktFactory::makeSupermarket(argv[2]);
	else
		super = SuprmarktFactory::makeSupermarket();

	super.run();

	/*auto _totalIncome = super.income();
	 cout << _totalIncome;*/

	return 0;
}
