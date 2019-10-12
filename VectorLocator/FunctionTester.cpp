#include "FunctionTester.h"
#include <cmath>

using namespace std;

FunctionTester::FunctionTester() {}

FunctionTester* FunctionTester::_instance;

FunctionTester* FunctionTester::GetInstance() {
	if (!_instance) {
		_instance = new FunctionTester();
	}
	return _instance;
}

function<double(double)>* FunctionTester::BernsteinPolynomials(const int n) {
	LOGGER_ASSERT(n > 0, this, "Attempted to initialize a bernstein polynomial with n <= 0", "Entering BernSteinPolynomials function");

	function<double(double)> * bernsteinFuncs = new function<double(double)>[n + 1];

	for (int i = 0; i <= n; i++) {
		bernsteinFuncs[i] = [=](double t) -> double {
			LOGGER_ASSERT(0 <= t && t <= 1, this, "t was not within range of [0, 1] in bernstein function", "bernsteinFunction created");
			return (NChooseK(n, i) * pow(t, i) * pow((1 - t), n - i));
		};
	}

	return bernsteinFuncs;
}

double FunctionTester::NChooseK(const int n, const int k) {
	if (!(n >= 0 && k >= 0)) {
			std::perror("nChooseK was passed a negative integer in FunctionTester");
			std::abort();
	}

	return (double)PartialFactorial(n, k) / (double)PartialFactorial(k, k);
}

int FunctionTester::PartialFactorial(const int target, const int iterations) {
	LOGGER_ASSERT((target - iterations) >= 0, this, "An invalid number of combination of iterations was assigned to partialFactorial in FunctionTester", "Entering PartialFactorial");

	if (target == 0) {
		return 1;
	}

	int retval = 1;
	for (int i = target; i > target - iterations; i--) {
		retval *= i;
	}

	return retval;
}

const char* FunctionTester::Report() const {
	const char* report = "{FunctionTester}";
	return report;
}