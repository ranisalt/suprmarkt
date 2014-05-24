/*
 * ClientTest.cpp
 *
 *  Created on: May 21, 2014
 *      Author: ranieri
 */

#include <gtest/gtest.h>

#include <suprmarkt/client/Client.h>
using suprmarkt::client::Client;
using suprmarkt::client::Payment;

#include <suprmarkt/client/ClientFactory.h>
using suprmarkt::client::ClientFactory;

class ClientTest: public testing::Test {
public:
	Client c = ClientFactory::makeClient(0);
};

TEST_F(ClientTest, clientHasCorrectData) {
	EXPECT_GT(101, c.cartSize());
	EXPECT_LT(1, c.cartSize());
	EXPECT_GT(90.01, c.cartValue());
	EXPECT_LT(0.99, c.cartValue());
}

TEST_F(ClientTest, clientHasCorrectProportions) {
	int check{0}, money{0};
	for (int i = 0; i < 1000000; ++i) {
		Payment p = ClientFactory::makeClient(0).paymentType();
		if (Payment::CHECK == p) {
			++check;
		} else {
			++money;
		}
	}
	EXPECT_NEAR(check, 200000, 1000);
	EXPECT_NEAR(money, 800000, 1000);
}
