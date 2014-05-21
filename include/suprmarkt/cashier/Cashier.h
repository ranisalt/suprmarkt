/*
 * Cashier.h
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#ifndef CASHIER_H_
#define CASHIER_H_

#include <string>
using std::string;

#include <suprmarkt/cashier/Efficiency.h>

namespace suprmarkt {
namespace cashier {

class Cashier {
public:
	Cashier(string, double, const Efficiency&);
	virtual ~Cashier();

	string name() const;
	void name(string name);

	double salary() const;
	void salary(double name);

	Efficiency& efficiency() const;

	int clientsServed() const;
	void clientsServed(int clientsServed);

	double totalIncome() const;
	void totalIncome(double totalIncome);

private:
	string _name;
	double _salary;
	Efficiency* _efficiency;

	int _clientsServed;
	double _totalIncome;
};

} /* namespace cashier */
} /* namespace suprmarkt */

#endif /* CASHIER_H_ */
