#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <list>
using namespace std;
namespace assignment
{

template <typename T> 
T find(T start, T end, const T& val)
{
  for (; start != end; start=std::next(start))
    {
      if (val == (*start))
	{
	  return start;
	}
    }
    return end; // wasn't found
}
}
int main()
{
  //int arr [] = {1, 2, 5, 2, 7 ,8};
  //auto pos = Find(begin(arr), end(arr), 2);
  //if ( pos != end(arr) )
  //    cout << *pos << " found";
  //else
  //    cout << "not found";
    
    // After modifications:
    
    std::list<int> l{1,6,2,7,0,9};
    auto val = assignment::find(begin(l), end(l), 2);
    std::cout << val << "\n";
				
				/*[](int i) { return i % 2 == 0; });
    if ( val != end(l) )
        cout << "First even number: " << *val << endl;
    */
}
