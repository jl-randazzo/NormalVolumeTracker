#include "FunctionTester.h"
#include "debugMode.h"
#include <functional>
#include <cmath>

using namespace std;

FunctionTester::FunctionTester() {}

FunctionTester* FunctionTester::_instance;

FunctionTester* FunctionTester::getInstance() {
	if (!_instance) {
		_instance = new FunctionTester();
	}
	return _instance;
}

function<double(double)>* FunctionTester::bernsteinPolynomials(const int n) {
	ASSERT(n > 0, "Attempted to initialize a bernstein polynomial with n <= 0");

	function<double(double)> * bernsteinFuncs = new function<double(double)>[n + 1];

	for (int i = 0; i <= n; i++) {
		bernsteinFuncs[i] = [=](double t) -> double {
			ASSERT(0 <= t && t <= 1, "t was not within range of [0, 1] in bernstein function");
			return (nChooseK(n, i) * pow(t, i) * pow((1 - t), n - i));
		};
	}

	return bernsteinFuncs;
}

double FunctionTester::nChooseK(const int n, const int k) {
	if (!(n >= 0 && k >= 0)) {
			std::perror("nChooseK was passed a negative integer in FunctionTester");
			std::abort();
	}

	return (double)partialFactorial(n, k) / (double)partialFactorial(k, k);
}

int FunctionTester::partialFactorial(const int target, const int iterations) {
	ASSERT((target - iterations) >= 0, "An invalid number of combination of iterations was assigned to partialFactorial in FunctionTester");

	if (target == 0) {
		return 1;
	}

	int retval = 1;
	for (int i = target; i > target - iterations; i--) {
		retval *= i;
	}

	return retval;
}