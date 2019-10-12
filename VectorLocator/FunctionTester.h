#pragma once
#include <functional>

class FunctionTester {
public:
	std::function<double(double)>* BernsteinPolynomials(const int n);
	static FunctionTester* GetInstance();
private:
	FunctionTester();
	double NChooseK(const int n, const int k);
	int PartialFactorial(const int target, const int iterations);
	static FunctionTester* _instance;
};