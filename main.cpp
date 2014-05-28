#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include "suprmarkt/Suprmarkt.h"
#include "suprmarkt/SuprmarktFactory.h"
using std::cout;
using suprmarkt::Suprmarkt;
using suprmarkt::SuprmarktFactory::makeSupermarket;

int main(int argc, char** argv) {
	srand(time(0));

	auto super = (argc == 3 && !strcmp("-f", argv[1])) ? makeSupermarket(argv[2]) : makeSupermarket();

	super.run();

	auto _totalIncome = super.income();
	cout << "Faturamento total: R$" << _totalIncome << '\n';

	auto checkouts = super.checkouts();
	cout << "Faturamento médio por caixa: R$" << _totalIncome / checkouts.size()
			<< '\n';

	cout << '\n';

	auto _totalWaiting = 0;
	auto _totalClients = 0;

	for (auto checkout : checkouts) {
		auto cashier = checkout.cashier();
		cout << cashier.name() << '\n';
		cout << "\tFaturamento: R$" << cashier.totalIncome() << '\n';
		cout << "\tLucro: R$" << cashier.totalIncome() - cashier.salary()
				<< '\n';
		_totalClients += cashier.clientsServed();
		_totalWaiting += checkout.totalWaiting();
	}

	cout << '\n';

	cout << "Tempo médio na fila: " << (double) _totalWaiting / _totalClients
			<< "s\n";

	cout << "Clientes desistentes: " << super.lostClients() << '\n';
	cout << "Faturamento perdido: R$" << super.lostMoney() << '\n';
	cout << "Seja bem-vindo ao " << super.name() << " :)\n";

	return 0;
}
