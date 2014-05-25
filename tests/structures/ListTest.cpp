/*
 * ListTest.cpp
 *
 *  Created on: 22/05/2014
 *      Author: ranieri
 */

#include <iostream>
#include <string>
#include <gtest/gtest.h>
#include "structures/List.h"
#include "suprmarkt/cashier/Cashier.h"
#include "suprmarkt/checkout/Checkout.h"
using std::string;
using testing::Test;

class ListTest: public Test {
public:
	List<suprmarkt::checkout::Checkout> l;
};

TEST_F(ListTest, sizeIsCorrect) {
	EXPECT_EQ(0, l.size());

	suprmarkt::cashier::Cashier c("Jorge", 200.0,
			suprmarkt::cashier::Efficiency::HIGH);
	suprmarkt::checkout::Checkout f(c);

	suprmarkt::cashier::Cashier d("Frida", 300.0,
			suprmarkt::cashier::Efficiency::LOW);
	suprmarkt::checkout::Checkout g(c);

	l.push_back(f);
	l.push_back(g);

	EXPECT_EQ(2, l.size());

	auto a = l.pop_front();
	auto b = l.pop_front();

	EXPECT_EQ(0, l.size());
	EXPECT_EQ("Jorge", a.cashier().name());
	EXPECT_EQ(200.0, a.cashier().salary());

	EXPECT_EQ("Frida", b.cashier().name());
	EXPECT_EQ(300.0, b.cashier().salary());
}

/*TEST_F(ListTest, pushAndPop) {
 l.push_back("42");
 l.push_back("25");
 EXPECT_EQ(2, l.size());
 EXPECT_EQ("42", l.front());
 l.pop_front();
 EXPECT_EQ("25", l.front());
 l.pop_front();
 }

 TEST_F(ListTest, pushAndPopToPosition) {
 l.push_back("42");
 l.push_back("25");
 l.push(1, "200");
 EXPECT_EQ(3, l.size());
 EXPECT_EQ("200", l.pop(1));
 }

 TEST_F(ListTest, iterateForward) {
 l.push_back("42");
 l.push_back("25");
 auto it = l.begin();
 EXPECT_EQ("42", *it);
 ++it;
 EXPECT_EQ("25", *it);
 ++it;
 std::cout << *it << '\n';
 ++it;
 EXPECT_EQ("42", *it);
 ++it;
 EXPECT_EQ("25", *it);
 }*/
