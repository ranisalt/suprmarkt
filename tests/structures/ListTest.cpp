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
using structures::List;

class ListTest: public testing::Test {
public:
	List<int> list;
};

TEST_F(ListTest, isCreatedEmpty) {
	EXPECT_EQ(0, list.size());
}

TEST_F(ListTest, pushBackPushesOnBack) {
	list.push_back(42);
	EXPECT_EQ(1, list.size());
	EXPECT_EQ(42, list.at(0));
	list.push_back(1963);
	EXPECT_EQ(42, list.at(0));
	EXPECT_EQ(1963, list.at(1));
	EXPECT_EQ(2, list.size());
}

TEST_F(ListTest, pushFrontPushesOnFront) {
	list.push_front(42);
	EXPECT_EQ(1, list.size());
	EXPECT_EQ(42, list.at(0));
	list.push_front(1963);
	EXPECT_EQ(1963, list.at(0));
	EXPECT_EQ(42, list.at(1));
	EXPECT_EQ(2, list.size());
}

TEST_F(ListTest, insert) {
	list.push_back(42);
	list.push_back(13);
	list.push(1, 1963);
	EXPECT_EQ(42, list.at(0));
	EXPECT_EQ(1963, list.at(1));
	EXPECT_EQ(13, list.at(2));
	EXPECT_EQ(3, list.size());
}

TEST_F(ListTest, popBack) {
	list.push_back(42);
	list.push_back(1963);
	EXPECT_EQ(1963, list.pop_back());
	EXPECT_EQ(1, list.size());
}

TEST_F(ListTest, popFront) {
	list.push_back(42);
	list.push_back(1963);
	EXPECT_EQ(42, list.pop_front());
	EXPECT_EQ(1, list.size());
}

TEST_F(ListTest, remove) {
	list.push_back(42);
	list.push_back(1963);
	list.push_back(13);
	EXPECT_EQ(1963, list.pop(1));
	EXPECT_EQ(2, list.size());
}

TEST_F(ListTest, accessOutOfRange) {
	EXPECT_THROW(list.at(13), std::out_of_range);
	EXPECT_THROW(list.push(13, 42), std::out_of_range);
	EXPECT_THROW(list.pop(13), std::out_of_range);
}

TEST_F(ListTest, boundariesWithNoProblems) {
	list.push(0, 42);
	EXPECT_EQ(1, list.size());
	EXPECT_EQ(42, list.at(0));
	EXPECT_EQ(42, list.pop(0));
	EXPECT_EQ(0, list.size());
}

TEST_F(ListTest, removalsFromEmptyThrow) {
	EXPECT_THROW(list.pop_back(), std::out_of_range);
	EXPECT_THROW(list.pop_front(), std::out_of_range);
	EXPECT_THROW(list.pop(13), std::out_of_range);
}

TEST_F(ListTest, forwardIteratorIsCreatedCorrect) {
	list.push_back(42);
	list.push_back(1963);
	list.push_back(13);
	auto it = list.begin();
	EXPECT_EQ(42, *it);
}

TEST_F(ListTest, forwardIteratorAdvance) {
	list.push_back(42);
	list.push_back(1963);
	list.push_back(13);
	auto it = list.begin();
	EXPECT_EQ(42, *it);
	++it;
	EXPECT_EQ(1963, *it);
	++it;
	EXPECT_EQ(13, *it);
}

TEST_F(ListTest, backwardIteratorIsCreatedCorrect) {
	list.push_back(42);
	list.push_back(1963);
	list.push_back(13);
	auto it = list.rbegin();
	EXPECT_EQ(13, *it);
}

TEST_F(ListTest, backwardIteratorAdvance) {
	list.push_back(42);
	list.push_back(1963);
	list.push_back(13);
	auto it = list.rbegin();
	EXPECT_EQ(13, *it);
	--it;
	EXPECT_EQ(1963, *it);
	--it;
	EXPECT_EQ(42, *it);
}
