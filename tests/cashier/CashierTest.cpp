/*
 * CashierTest.cpp
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#include <gtest/gtest.h>

#include <suprmarkt/cashier/Cashier.h>
using suprmarkt::cashier::Cashier;

#include <suprmarkt/cashier/EfficiencyHigh.h>
using suprmarkt::cashier::EfficiencyHigh;

#include <suprmarkt/cashier/EfficiencyMedium.h>
using suprmarkt::cashier::EfficiencyMedium;

class CashierTest: public testing::Test {
public:
	Cashier a = Cashier("Alice", 700.0, EfficiencyMedium());
	Cashier b = Cashier("Bob", 1200.0, EfficiencyHigh());
};

TEST_F(CashierTest, cashierHasCorrectData) {
	EXPECT_EQ("Alice", a.name());
	EXPECT_DOUBLE_EQ(700.0, a.salary());
	EXPECT_EQ("Bob", b.name());
	EXPECT_DOUBLE_EQ(1200.0, b.salary());
}

TEST_F(CashierTest, cashierAcceptDataChange) {
	a.name("Alessandra");
	EXPECT_EQ("Alessandra", a.name());
	a.salary(1000.0);
	EXPECT_DOUBLE_EQ(1000.0, a.salary());

	b.name("Bulba");
	EXPECT_EQ("Bulba", b.name());
	b.salary(1337.1337);
	EXPECT_DOUBLE_EQ(1337.1337, b.salary());
}
