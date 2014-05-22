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
	Cashier(const string& name, double salary, Efficiency* efficiency);
	virtual ~Cashier();

	string name() const;
	void name(string name);

	double salary() const;
	void salary(double name);

	Efficiency& efficiency() const;

	int clientsServed() const;
	void clientsServed(int clientsServed);

	int totalSold() const;
	void totalSold(int totalSold);

	double totalIncome() const;
	void totalIncome(double totalIncome);

	void receivePayment(int cartSize, int cartValue, Payment paymentMethod);

private:
	string _name;
	double _salary;
	Efficiency* _efficiency;

	int _clientsServed;
	int _totalSold;
	double _totalIncome;
};

} /* namespace cashier */
} /* namespace suprmarkt */

#endif /* CASHIER_H_ */
