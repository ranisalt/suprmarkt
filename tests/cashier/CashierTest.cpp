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

class CashierTest : public testing::Test {
public:
	Cashier a = Cashier("Alice", 700.0, EfficiencyMedium());
	Cashier b = Cashier("Bob", 1200.0, EfficiencyHigh());
};

TEST_F(CashierTest, cashierHasName) {
	EXPECT_EQ("Alice", a.name());
	EXPECT_EQ("Bob", b.name());
}
