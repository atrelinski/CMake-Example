#include <iostream>
#include "d-hello.h"
#include "s-hello.h"

int main()
{
	sHelloFun();
	dHelloFun();
	
	std::cout << std::endl;
	std::cout << "Type any char and press Enter" << std::endl;
	
	char c;
	std::cin >> c;
	
	return 0;
}