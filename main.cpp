#include <iostream>
#include "smartPointer.h"

int main(){
	int *p = new int(8);
	SmartPointer<int> sp1(p);
	std::cout << sp1.use_count() << std::endl;
	SmartPointer<int> sp2;
	sp2 = sp1;
	std::cout << sp2.use_count() << std::endl;
	std::cout << *sp1 << std::endl;
	return 0;
}
