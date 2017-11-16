#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
using namespace std;
struct format_container
{
    format_container(char delim='[')
    {
        if (delim == '{')
        {
            start='{';
            end = '}';
        }
    }
    char start{'['}, end{']'};
    mutable ostream* os{};
  operator<<(vector<int>& tmp)
  {
    std::cout << "Testing";
  }
};
  
format_container const & operator<<(ostream & os, format_container const & cp)
{
    cp.os = &os;
    return cp;
}

int main()
{
    // Part a
    vector<int> vec {2, 5, 1, 7, 10};
    cout << format_container() << vec << endl;
    cout << format_container('{') << vec << endl;

    // part b
    /*
    list<string> lst{"hi", "does", "this", "work?"};
    forward_list<int> fl{3,65,1,8};
    cout << format_container() << lst << "\n"
         << format_container() << fl << endl;
    */
}
