#include <vector>
#include <iostream>
using namespace std;

int main()
{
	vector<int> v1 { 2, 3};
	vector<int> v2 (2 ,3);
	for(auto && x: v1)
	{
		std::cout << x << "\t";
	}
	cout << endl;
	for(auto && x: v2)
	{
		std::cout << x << "\t";
	}
	return 0;
}