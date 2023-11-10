#include "string.h"

using namespace my_string;

const size_t string::npos = -1;

void test()
{
	string s1 = "hello abcd";
	string s2 = "efg";
	s1.erase(0, 6);
	std::cout << s1.c_str() << ' ' << s1.size() << ' ' << s1.capacity() << std::endl;
}

int main()
{
	test();
	return 0;
}