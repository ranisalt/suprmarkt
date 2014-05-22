/*
 * ClientTest.cpp
 *
 *  Created on: May 21, 2014
 *      Author: ranieri
 */

#include <gtest/gtest.h>

#include <suprmarkt/client/Client.h>
using suprmarkt::client::Client;

#include <suprmarkt/client/ClientFactory.h>
using suprmarkt::client::ClientFactory;

class ClientTest: public testing::Test {
public:
	Client c = ClientFactory::makeClient();
};

TEST_F(ClientTest, clientHasCorrectData) {
	EXPECT_GT(101, c.cartSize());
	EXPECT_LT(1, c.cartSize());
	EXPECT_GT(90.01, c.cartValue());
	EXPECT_LT(0.99, c.cartValue());
}

TEST_F(ClientTest, cashierAcceptDataChange) {
}
