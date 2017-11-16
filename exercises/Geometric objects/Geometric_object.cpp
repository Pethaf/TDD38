#include "Geometric_object.h"
#include <iostream>
int main()
{
	Point tmp{};
	Line tmp2{};
	std::cout << tmp.x << " " << tmp.y << std::endl;
	std::cout << tmp2.getLength() << std::endl;
	std::cout << tmp.str() << std::endl;
	std::cout << tmp2.str() << std::endl;
	Point* tmp3 = tmp.clone();
	tmp3->x = 2;
	tmp3->y = 5;
	std::cout << tmp3->str();
	std::cout << tmp.str();
	return 0;
}