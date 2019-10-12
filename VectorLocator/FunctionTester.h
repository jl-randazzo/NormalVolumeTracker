#pragma once
#include <functional>

class FunctionTester {
public:
	std::function<double(double)>* bernsteinPolynomials(const int n);
	static FunctionTester* getInstance();
private:
	FunctionTester();
	double nChooseK(const int n, const int k);
	int partialFactorial(const int target, const int iterations);
	static FunctionTester* _instance;
};