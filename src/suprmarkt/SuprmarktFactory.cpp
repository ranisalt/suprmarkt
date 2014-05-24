/*
 * SuprmarktFactory.cpp
 *
 *  Created on: 22/05/2014
 *      Author: ranieri
 */

#include <suprmarkt/SuprmarktFactory.h>

#include <suprmarkt/cashier/EfficiencyLow.h>
using suprmarkt::cashier::EfficiencyLow;

#include <suprmarkt/cashier/EfficiencyMedium.h>
using suprmarkt::cashier::EfficiencyMedium;

#include <suprmarkt/cashier/EfficiencyHigh.h>
using suprmarkt::cashier::EfficiencyHigh;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::streamsize;

#include <limits>
using std::numeric_limits;

namespace suprmarkt {

Suprmarkt SuprmarktFactory::makeSupermarket() {
	Suprmarkt super = Suprmarkt();

	{
		string name;
		cout << "Informe o nome do supermercado: ";
		getline(cin, name);
		super.name(name);
	}

	{
		int time = 0;
		cout << "Informe o tempo de simulação (em horas): ";
		while (!(cin >> time) || time <= 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Tempo inválido! Tente novamente: ";
		}
		super.time(time * 60 * 60);
	}

	{
		int checkouts = 0;
		cout << "Informe a quantidade de caixas: ";
		while (!(cin >> checkouts) || checkouts <= 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Quantidade inválido! Tente novamente: ";
		}

		for (int i = 0; i < checkouts; ++i) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			Cashier cashier = Cashier();

			{
				string name;
				cout << "Informe o nome do caixa " << i + 1 << ": ";
				getline(cin, name);
				cashier.name(name);
			}

			{
				double salary = 0.0;
				cout << "Informe o salário do caixa " << i + 1 << ": ";
				while (!(cin >> salary) || salary <= 0.0) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Salário inválido! Tente novamente: ";
				}
				cashier.salary(salary);
			}

			{
				int efficiency = 0;
				cout << "Informe a eficiência do caixa " << i + 1 << "\n"
						<< "1) baixa\n" << "2) média\n" << "3) alta: ";
				while (!(cin >> efficiency) || efficiency <= 0
						|| efficiency >= 4) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Eficiência inválido! Tente novamente: ";
				}

				cin.clear();

				switch (efficiency) {
				case 1:
					cashier.efficiency(new EfficiencyLow());
					break;
				case 2:
					cashier.efficiency(new EfficiencyMedium());
					break;
				case 3:
					cashier.efficiency(new EfficiencyHigh());
					break;
				}
			}

			Checkout queue = Checkout(cashier);

			super.addCheckout(queue);
		}
	}

	return super;
}

Suprmarkt SuprmarktFactory::makeSupermarket(string filename) {
	Suprmarkt super = Suprmarkt();

	{
		string nome;
		cout << "Informe o nome do supermercado: ";
		cin >> nome;
		super.name(nome);
	}

	{

	}

	return super;
}

} /* namespace suprmarkt */
