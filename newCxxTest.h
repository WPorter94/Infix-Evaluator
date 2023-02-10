//Copyright 2021
#pragma once

#ifndef INFIX_NEWCXXTEST_H
#define INFIX_NEWCXXTEST_H

#include "Infix_Evaluator.h"
//#include "Syntax_Error.h"
#include <iostream>
#include <cxxtest/TestSuite.h>
class newCxxTest : public CxxTest::TestSuite {
public:

	void test1() {
		Infix_Evaluator IE;
		std::string mathFormula = "1+1";
		int answer = IE.eval(mathFormula);
		TS_ASSERT_EQUALS(answer,2);
	}
	void test2() {
		Infix_Evaluator IE;
		std::string mathFormula = "2-1";
		TS_ASSERT_EQUALS(IE.eval(mathFormula), 1);
	}
	void test3() {
		Infix_Evaluator IE;
		std::string mathFormula = "2*2";
		TS_ASSERT_EQUALS(IE.eval(mathFormula), 4);
	}
	void test4() {
		Infix_Evaluator IE;
		std::string mathFormula = "4/2";
		TS_ASSERT_EQUALS(IE.eval(mathFormula), 2);
	}
	void test5() {
		Infix_Evaluator IE;
		std::string mathFormula = "2^3";
		TS_ASSERT_EQUALS(IE.eval(mathFormula), 8);
	}
	void test6() {
		Infix_Evaluator IE;
		std::string mathFormula = "5%2";
		TS_ASSERT_EQUALS(IE.eval(mathFormula), 1);
	}
	void test7() {
		Infix_Evaluator IE;
		std::string mathFormula = "1+1+1";
		TS_ASSERT_EQUALS(IE.eval(mathFormula), 3);
	}
	void test8() {
		Infix_Evaluator IE;
		std::string mathFormula = "2*2-1";
		TS_ASSERT_EQUALS(IE.eval(mathFormula), 3);
	}
	void test9() {
		Infix_Evaluator IE;
		std::string mathFormula = "4/2-1";
		TS_ASSERT_EQUALS(IE.eval(mathFormula), 1);
	}
	void test10() {
		Infix_Evaluator IE;
		std::string mathFormula = "2+2/2";
		TS_ASSERT_EQUALS(IE.eval(mathFormula), 3);
	}
	void test11() {
		Infix_Evaluator IE;
		std::string mathFormula = "1+1*3";
		TS_ASSERT_EQUALS(IE.eval(mathFormula), 4);
	}
	void test12() {
		Infix_Evaluator IE;
		std::string mathFormula = "1+5%2";
		TS_ASSERT_EQUALS(IE.eval(mathFormula), 2);
	}
	void test13() {
		Infix_Evaluator IE;
		std::string mathFormula = "2+4^2";
		TS_ASSERT_EQUALS(IE.eval(mathFormula), 18);
	}
	void test14() {
		Infix_Evaluator IE;
		std::string mathFormula = "(2+2)^2";
		TS_ASSERT_EQUALS(IE.eval(mathFormula), 16);
	}
	void test15() {
		Infix_Evaluator IE;
		std::string mathFormula = "2*(3-1)";
		TS_ASSERT_EQUALS(IE.eval(mathFormula), 4);
	}
	void test16() {
		Infix_Evaluator IE;
		std::string mathFormula = "10*((33-1)%3)";
		TS_ASSERT_EQUALS(IE.eval(mathFormula), 20);
	}
	void test17() {
		Infix_Evaluator IE;
		std::string mathFormula = "32/((10-6)^2)";
		TS_ASSERT_EQUALS(IE.eval(mathFormula), 2);
	}
	void test18() {
		Infix_Evaluator IE;
		std::string mathFormula = "(4-2)*(2+1)";
		TS_ASSERT_EQUALS(IE.eval(mathFormula), 6);
	}
	void test19() {
		Infix_Evaluator IE;
		std::string mathFormula = "(3+1)*((2+1)^2)";
		TS_ASSERT_EQUALS(IE.eval(mathFormula), 36);
	}
	void test20() {
		Infix_Evaluator IE;
		std::string mathFormula = "(6+2^2)-(2*(12-1))";
		TS_ASSERT_EQUALS(IE.eval(mathFormula), -12);
	}
};
#endif /*INFIX_NEWCXXTEST_H*/
