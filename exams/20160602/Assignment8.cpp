#include <iostream>
#include <vector>
using namespace std;

struct Ascending 
{
    template<typename T> static bool less(const T& a, const T& b) 
    {
        return a < b;
    }
};

struct Descending 
{
    template<typename T> static bool less(const T& a, const T& b)
    {
        return b < a && a != b;   
    }
};


template<typename T, class orderingPolicy=Ascending>
struct Sort
{
template<typename Iter>
void static sort(Iter begin, Iter end)
{
    for ( ; next(begin) != end; ++begin)
    {
        int* min = begin;
        for (Iter pos = next(begin); pos != end; ++begin)
            if (orderingPolicy::less(pos,min))
                min = pos;
        std::iter_swap(begin, min);
    }
}
};

int main()
{
    int arr[] = {2,3,5,1,6,8};
    Sort<int>::sort(begin(arr), end(arr));
    bool first {true};
    for ( auto i : arr )
     {
         if ( !first )
             cout << ", ";
         first = false;
         cout << i;
     }
     cout << endl;

    
    vector<int> values {2,3,6,8,3};
    Sort<int, Ascending>::sort(begin(values), end(values));

    list<string> words {"hi", "hello", "all", "students"};
    Sort<string, Descending>::sort(begin(words), end(words));
    for(auto && tmp: values)
     {
         std::cout << value << ' '; 
     }
    return 0;
}
