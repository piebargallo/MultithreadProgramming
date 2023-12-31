#include <thread>
#include <iostream>

class Counter
{
public:
	Counter(int id, int numIterations)
		: m_id{ id }, m_numIterations{ numIterations }
	{
	}

	void operator()() const
	{
		for (int i{ 0 }; i < m_numIterations; ++i) {
			std::cout << "Counter " << m_id << " has value " << i << std::endl;
		}
	}

private:
	int m_id;
	int m_numIterations;
};

int main()
{
	// Using uniform initialization syntax.
	std::thread t1{ Counter{ 1, 20 } };

	// Using named variable.
	Counter c{ 2, 12 };
	std::thread t2{ c };

	// Wait for threads to finish.
	t1.join();
	t2.join();
}
