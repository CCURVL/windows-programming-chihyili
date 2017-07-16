﻿#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

#include <gtest\gtest.h>

using namespace std;


// getAscendingStr Function requirement
//
// Take space seperated digit string (ex. "1 2 3 5 4") and 
//   modify input string to ascending order ("1 2 3 4 5").
//
// return 0 if success, (empty string)
//       -1 if exception occur (ex. string containing non-digit character)
int getAscendingStr(string& inputStr)
{
	vector<string> v;
	string token;
	int x = 0;
	getline(cin, inputStr);
	istringstream delim(inputStr);
	while (getline(delim, token, ' ')) {
		v.push_back(token);
		x++;
	}
	string temp;
	for (int i = 0; i < 5; i++) {
		for (int j = 0 + i; j < 5; j++) {
			if (v[j - 1] > v[j]) {
				temp = v[j - 1];
				v[j - 1] = v[j];
				v[j] = temp;
			}
		}
	}

	return 0;
}

// solveQ Function requirement
// 
// solve quadratic function ax^2 + bx + c = 0
//
// return 1 if equation has two different real number root 
//          (return vector size should be 2 containing 2 solution.  
//          Greater value should put into smaller vector index)
//        0 there is only one possible solution to the quadratic equation 
//          (return vector size should be 1)
//       -1 complex roots 
//          (return vector size should be 0)
int solveQ(vector<double> &x, double a, double b, double c)
{
	double d = b*b - 4 * a*c;
	vector<double> q;
	double ans;
	if (d > 0) {
		ans = (-b + sqrt(b*b - 4 * a*c)) / (2 * a);
		q.push_back(ans);
		ans = (-b - sqrt(b*b - 4 * a*c)) / (2 * a);
		q.push_back(ans);
		return 1;
	}
	if (d == 0) {
		ans = -b / 2 * a;
		q.push_back(ans);
		return 0;
	}
	if (d < 0) {
		return -1;
	}

}

int main(int argc, char*argv[]) {
	
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	system("pause");
	return 0;
}

TEST(getAscendingStr, SimpleAscending)
{//Simple ascending test case

	string inputStr = "1 -3 2195 4 50";
	string tmpStr = inputStr;
	int err = getAscendingStr(tmpStr);
	EXPECT_EQ(tmpStr, "-3 1 4 50 2195");
	EXPECT_EQ(err, 0);
}

TEST(getAscendingStr, handleNonDigit)
{//getAscendingStr function should handle non digit case
	string tmpStr = "1 3 2 4 a 7f415";
	int err = getAscendingStr(tmpStr);
	EXPECT_EQ(err, -1);
}

TEST(solveQ, twoSolution)
{
	vector<double> sol;
	int iSol = solveQ(sol, 1, 2, -3);
	EXPECT_EQ(iSol, 1);
	EXPECT_EQ(sol.size(), 2);
	EXPECT_EQ(sol.at(0), 1);
	EXPECT_EQ(sol.at(1), -3);
}

TEST(solveQ, oneSolution)
{
	vector<double> sol;
	int iSol = solveQ(sol, 1, -8, 16);
	EXPECT_EQ(iSol, 0);
	EXPECT_EQ(sol.size(), 1);
	EXPECT_EQ(sol.at(0), 4);
}

TEST(solveQ, noSolution)
{
	vector<double> sol;
	int iSol = solveQ(sol, 1, 1, 16);
	EXPECT_EQ(iSol, -1);
	EXPECT_EQ(sol.size(), 0);
}