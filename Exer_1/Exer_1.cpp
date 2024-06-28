/* Write an application that can calculate a number of Fibonacci numbers concurrently. For example, your code
   should be able to calculate the 4, 9, 14, and 17 number in the Fibonacci series in parallel. The Fibonacci
   sereies starts with 0 and 1, and any subsequent value is the sum of the two previous values, so: 0, 1, 1, 2, 
   3, 5, 8, 13, 21, 34, 55, 89, and so on. Once all results are avaliable, output them to the standard output.
   Finally, calculate their sum using a Standard Library algorithm. */

#include <iostream>
#include <chrono>
#include <future>
#include <numeric>

using namespace std;

unsigned long long fibonacci(unsigned int n)
{
	if (n == 0) { return 0; }
	else if (n == 1) { return 1; }

	unsigned long long a{ 0 };
	unsigned long long b{ 1 };

	unsigned long long result{ 0 };
	for (unsigned int i{ 1 }; i < n; ++i) {
		result = a + b;
		a = b;
		b = result;
	}
	return result;
}

int main()
{
	// Indices of Fibonacci numbers to calculate.
	vector fibonacciNumbersToCalculate{ 4, 9, 14, 17 };

	// Launch threads to calculate the required numbers concurrently.
	vector<future<unsigned long long>> futures;
	for (auto& index : fibonacciNumbersToCalculate) {
		futures.push_back(async(launch::async, fibonacci, index));
	}

	// Wait for all threads to finish and collect results.
	vector<unsigned long long> fibonacciNumbers;
	for (auto& f : futures) {
		fibonacciNumbers.push_back(f.get());
	}

	// Output the calculated numbers.
	for (auto& number : fibonacciNumbers) {
		cout << number << " ";
	}
	cout << endl;

	// Calculate their sum.
	cout << accumulate(begin(fibonacciNumbers), end(fibonacciNumbers), 0ull) << endl;
}