#include <iostream>

struct Base
{
public:
	Base() = default;
	Base(const Base& lhs): a{lhs.a},b{lhs.b} { }
	void getA() const { std::cout << a;}
	void getB() const { std::cout << b;}
private:
	int a,b; 
};

struct Derived: Base
{
	public:
		Derived() = default;
		Derived(int tmp): c{tmp} { }
		Derived(const Derived&) = default;
		void getC() { std::cout << c;}
	private:
		int c; 
};	

int main()
{
	Base tmp; 
	Derived tmp2(3);
	Base tmp3{tmp2};
	return 0;
}