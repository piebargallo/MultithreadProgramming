#include <thread>
#include <iostream>
#include <format>

int k;
thread_local int n;

void threadFunction(int id)
{
	std::cout << std::format("Thread {}: k={}, n={}\n", id, k, n);
	++n;
	++k;
}

int main()
{
	std::thread t1{ threadFunction, 1 };
	t1.join();

	std::thread t2{ threadFunction, 2 };
	t2.join();
}