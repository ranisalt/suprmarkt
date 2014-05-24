#include <iostream>
using std::cout;

#include <suprmarkt/Suprmarkt.h>
using suprmarkt::Suprmarkt;

#include <suprmarkt/SuprmarktFactory.h>
using suprmarkt::SuprmarktFactory;

int main(int argc, char** argv) {
	Suprmarkt super = SuprmarktFactory::makeSupermarket();

	for (int i = 0; i < argc; ++i) {
		cout << argv[i] << '\n';
	}

	super.run();

	auto _totalIncome = super.income();
	cout << _totalIncome;

	return 0;
}
