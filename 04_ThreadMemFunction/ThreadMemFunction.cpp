#include <thread>
#include <iostream>

class Request
{
public:
	Request(int id) : m_id{ id } { }

	void process()
	{
		std::cout << "Processing request " << m_id << std::endl;
	}

private:
	int m_id;
};

int main()
{
	Request req{ 100 };
	std::thread t{ &Request::process, &req };

	t.join();
}
