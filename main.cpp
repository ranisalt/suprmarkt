#include <iostream>
#include <cstring>
#include "suprmarkt/Suprmarkt.h"
#include "suprmarkt/SuprmarktFactory.h"
using std::cout;
using suprmarkt::Suprmarkt;
using suprmarkt::SuprmarktFactory::makeSupermarket;

int main(int argc, char** argv) {
	Suprmarkt super;
	if (argc == 3 && !strcmp("-f", argv[1]))
		super = makeSupermarket(argv[2]);
	else
		super = makeSupermarket();

	super.run();

	/*auto _totalIncome = super.income();
	 cout << _totalIncome;*/

	return 0;
}
