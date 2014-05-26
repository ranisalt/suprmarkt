/*
 * SuprmarktFactory.cpp
 *
 *  Created on: 22/05/2014
 *      Author: ranieri
 */

#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include "suprmarkt/cashier/Cashier.h"
#include "suprmarkt/SuprmarktFactory.h"
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::ios;
using std::numeric_limits;
using std::streamsize;
using std::string;
using std::stringstream;
using suprmarkt::cashier::Efficiency;

namespace suprmarkt {
namespace SuprmarktFactory {

Suprmarkt makeSupermarket() {
	Suprmarkt super = Suprmarkt();

	{
		string name;
		cout << "Informe o nome do supermercado: ";
		getline(cin, name);
		super.name(name);
	}

	{
		auto time = 0;
		cout << "Informe o tempo de simulação (em horas): ";
		while (!(cin >> time) || time <= 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Tempo inválido! Tente novamente: ";
		}
		super.time(time * 60 * 60);
	}

	{
		auto checkouts = 0;
		cout << "Informe a quantidade de caixas: ";
		while (!(cin >> checkouts) || checkouts <= 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Quantidade inválido! Tente novamente: ";
		}

		for (auto i = 0; i < checkouts; ++i) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			auto cashier = Cashier { };

			{
				string name;
				cout << "Informe o nome do caixa " << i + 1 << ": ";
				getline(cin, name);
				cashier.name(name);
			}

			{
				auto salary = 0.0;
				cout << "Informe o salário do caixa " << i + 1 << ": ";
				while (!(cin >> salary) || salary <= 0.0) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Salário inválido! Tente novamente: ";
				}
				cashier.salary(salary);
			}

			{
				auto efficiency = 0;
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
					cashier.efficiency(Efficiency::LOW);
					break;
				case 2:
					cashier.efficiency(Efficiency::MEDIUM);
					break;
				case 3:
					cashier.efficiency(Efficiency::HIGH);
					break;
				}
			}

			auto queue = Checkout { cashier };

			super.addCheckout(queue);
		}
	}

	return super;
}

string getLine(ifstream& file) {
	string input;
	do {
		getline(file, input);
		input = input.substr(input.find_first_not_of(' '),
				input.find_first_of('#'));
	} while (input.empty());
	return input;
}

Suprmarkt makeSupermarket(char* filename) {
	auto super = Suprmarkt { };

	ifstream file;
	file.open(filename);

	if (file.is_open()) {
		{
			string name = getLine(file);
			super.name(name);
		}

		{
			auto time = 0;

			if (!(stringstream(getLine(file)) >> time)) {
				cout
						<< "Erro: o tempo não está corretamente formatado. Leia a documentação.\n";
				exit(2);
			}
			if (time <= 0) {
				cout
						<< "Erro: o tempo não pode ser menor ou igual a zero. Leia a documentação.\n";
				exit(2);
			}
			super.time(time * 60 * 60);
		}

		{
			auto avgClientArrival = 0;
			if (!(stringstream(getLine(file)) >> avgClientArrival)) {
				cout
						<< "Erro: o tempo médio de chegada de clientes não está corretamente formatado. Leia a documentação.\n";
				exit(2);
			} else if (avgClientArrival <= 0) {
				cout
						<< "Erro: o tempo médio de chegada de clientes não pode ser menor ou igual a zero. Leia a documentação.\n";
				exit(2);
			}
			super.avgClientArrival(avgClientArrival);
		}

		{
			auto numCashiers = 0;
			if (!(stringstream(getLine(file)) >> numCashiers)) {
				cout
						<< "Erro: a número de caixas não está corretamente formatado. Leia a documentação.\n";
				exit(2);
			} else if (numCashiers <= 0) {
				cout
						<< "Erro: o número de caixas não pode ser menor ou igual a zero. Leia a documentação.\n";
				exit(2);
			}

			for (auto i = 0; i < numCashiers; ++i) {
				Cashier cashier;
				string name;
				int efficiency;
				double salary;
				if (stringstream(getLine(file)) >> name >> efficiency
						>> salary) {
					cashier.name(name);
					cashier.salary(salary);
					switch (efficiency) {
					case 1:
						cashier.efficiency(Efficiency::LOW);
						break;
					case 2:
						cashier.efficiency(Efficiency::MEDIUM);
						break;
					case 3:
						cashier.efficiency(Efficiency::HIGH);
						break;
					default:
						cout << "Erro: o caixa " << name
								<< " não está configurado corretamente. Leia a documentação.\n";
						exit(3);
						break;
					}
				} else {
					cout << "Erro: o caixa " << name
							<< " não está configurado corretamente. Leia a documentação.\n";
					exit(3);
				}
				auto queue = Checkout { cashier };

				super.addCheckout(queue);
			}
		}
	} else {
		cout
				<< "Erro: o arquivo de configuração não pôde ser aberto. Leia a documentação.\n";
		exit(1);
	}

	file.close();

	return super;
}

} /* namespace SuprmarktFactory */
} /* namespace suprmarkt */
