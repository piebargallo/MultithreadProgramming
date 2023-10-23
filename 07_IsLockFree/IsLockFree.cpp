#include <atomic>
#include <iostream>
#include <type_traits>

class Foo { private: int m_array[123]; };
class Bar { private: int m_int; };

int main()
{
	std::atomic<Foo> f;
	std::cout << std::is_trivially_copyable_v<Foo> << " " << f.is_lock_free() << std::endl;

	std::atomic<Bar> b;
	std::cout << std::is_trivially_copyable_v<Bar> << " " << b.is_lock_free() << std::endl;

	return 0;
}