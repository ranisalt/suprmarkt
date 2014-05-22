/*
 * ListTest.cpp
 *
 *  Created on: 22/05/2014
 *      Author: ranieri
 */

#include <gtest/gtest.h>

#include <iostream>

#include <structures/List.h>

class ListTest: public testing::Test {
public:
	List<int> l = List<int>();

	ListTest() {
	}
};

TEST_F(ListTest, sizeIsCorrect) {
	EXPECT_EQ(0, l.size());
	l.push_back(42);
	EXPECT_EQ(1, l.size());
	l.pop_back();
	EXPECT_EQ(0, l.size());
}

TEST_F(ListTest, pushAndPop) {
	l.push_back(42);
	l.push_back(25);
	EXPECT_EQ(2, l.size());
	EXPECT_EQ(42, l.front());
	l.pop_front();
	EXPECT_EQ(25, l.front());
	l.pop_front();
}

TEST_F(ListTest, pushToPosition) {
	l.push_back(42);
	l.push_back(25);
	l.push(1, 200);
	EXPECT_EQ(3, l.size());
	EXPECT_EQ(200, l.pop(1));
}
