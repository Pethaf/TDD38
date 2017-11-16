#include <stdexcept>
#include <iostream>
#include <limits>
using namespace std;
template<typename T, T min=numeric_limits<T>::min, T max=numeric_limits<T>::max>
class Modular
{
public:
    explicit Modular(T n)
    {
        if( (min <= n) && (n <= max ))
        {
            val =n ;
        }
        else
        {
            val = min;
        }
    }
 Modular& operator=(T const &n)
  {
    if( (min <= n) && (n <= max))
    {
        val =n;
    }
    else
    {
        throw domain_error{"RHS out of range"};
    }
    return *this;
  }  
 operator T() const { return val;}

Modular<T, min,max>& operator++() 
{
    if(val == max)
    {
        val = min; 
    }
    else
    {
        ++val;
    }
    return *this;
}

Modular<T, min,max>& operator++(int)
{
   auto tmp = *this;
   ++*this;
   return tmp;
}

Modular<T,o_min,o_max> 

private:
    T val; 

};



int main()
{
    Modular<int, 2, 10> m{3};
    cout << m << endl;
    try
    {
        m = 1;
    }
    catch ( std::domain_error const & e)
    {
        cout << e.what() << endl;
    } 
     Modular<char,'a','c'> mc{'b'};
    ++mc;
    cout << "\nShould print a: " << ++mc << endl;
    return 0;
}
