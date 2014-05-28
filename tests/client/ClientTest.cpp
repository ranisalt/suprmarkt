/*
 * ClientTest.cpp
 *
 *  Created on: May 21, 2014
 *      Author: ranieri
 */

#include <gtest/gtest.h>

#include "suprmarkt/client/Client.h"
#include "suprmarkt/client/ClientFactory.h"
using suprmarkt::client::Client;
using suprmarkt::client::ClientFactory::makeClient;
using suprmarkt::client::Payment;

class ClientTest: public testing::Test {
public:
	Client c = makeClient(0);
};

TEST_F(ClientTest, clientHasCorrectData) {
	EXPECT_GT(101, c.cartSize());
	EXPECT_LT(1, c.cartSize());
	EXPECT_GT(9000.1, c.cartValue());
	EXPECT_LT(1.99, c.cartValue());
}

TEST_F(ClientTest, clientHasCorrectProportions) {
	int check{0}, money{0};
	for (int i = 0; i < 1000000; ++i) {
		auto client = makeClient(0);
		auto payment = client.paymentType();
		if (Payment::CHECK == payment) {
			++check;
		} else {
			++money;
		}
	}
	EXPECT_NEAR(check, 200000, 1000);
	EXPECT_NEAR(money, 800000, 1000);
}

TEST_F(ClientTest, clientCopiesCorrectly) {
	auto c = makeClient(60);
	auto d = Client(c);
	EXPECT_EQ(c.leavingTime(), d.leavingTime());
}
