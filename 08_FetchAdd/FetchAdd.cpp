#include <iostream>
#include <atomic>

int main()
{
	std::atomic<int> value{ 10 };
	std::cout << "Value = " << value << std::endl;
	int fetched{ value.fetch_add(4) };
	std::cout << "Fetched = " << fetched << std::endl;
	std::cout << "Value = " << value << std::endl;

	return 0;
}
