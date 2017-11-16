#include <vector>
#include <iostream>
#include <random>
#include <iterator>
#include <algorithm>
#include <functional>
using namespace std; 
using num_type = unsigned long long;

bool is_prime(num_type val, num_type divisor=2)
{
    if ( divisor*divisor > val )
    {
        return true;
    }
    if ( val % divisor == 0 )
    {
        return false;
    }
    return is_prime(val, ++divisor);
}

int main()
{
	vector<num_type> primeVect(10);
	std::default_random_engine e;
    std::uniform_int_distribution<> d(2, 75);
    std::function<int()> rnd = std::bind(d, e);
	std::generate(begin(primeVect),primeVect.end(), rnd);
		std::cout << std::endl;
	 primeVect.erase(std::remove_if(begin(primeVect), 
                              end(primeVect),
                              [](num_type x){return !is_prime(x);}),
               end(primeVect));
	std::sort(primeVect.begin(), primeVect.end(), std::less<int>());
    std::copy(begin(primeVect), end(primeVect),
              std::ostream_iterator<num_type>(std::cout, " "));

    cout << endl << std::accumulate(primeVect.begin(), primeVect.end(), 1, std::multiplies<num_type>());
	return 0;
}