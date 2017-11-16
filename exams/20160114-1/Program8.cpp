#include <stdexcept>
#include <iostream>
#include <array>
using namespace std;
template <size_t N>
class Wrap
{
public:
  static size_t next(size_t n) noexcept
  {
    if (n == N)
      {
	return 0; 
      }
    else
      {
	return n+1; 
      }
  }
  static size_t prev(size_t n) noexcept
  {
    if( n == 0 )
      {
	return N-1; 
      }
    else
      {
	return n-1;
      }
     }
};

template <size_t N>
class Out_Of_Bounds
{
public:
  static size_t next(size_t n)
  {
    if(n ==(N-1))
      {
	throw std::out_of_range("Bounds out of range"); 
      }
    else
      {
	return n+1;
      }
  }
  static size_t prev(size_t n)
  {
    if( n == 0)
      {
      throw std::out_of_range("Out of bounds"); 
      }
    else
      {
	return n+1;
      }
  }
  
};

template <typename T, size_t N, template <size_t> class Access_Policy= Wrap>
class Fixed_Buffer  
{
 public: 
  Fixed_Buffer() = default;
  Fixed_Buffer(const Fixed_Buffer&) = delete;
  Fixed_Buffer(Fixed_Buffer&&) = delete;
  void push(T const & t)
  {
    std::cout << "Push" << std::endl;
    std::cout << t;
    std::cout << std::endl;
    arr[nextPos] = t;
    if( nextPos = 0)
    { 
    std::cout << arr[0];
    }
    else
      {
	std::cout << arr[nextPos-1];
      } 
    nextPos = AP::next(nextPos); 
  }
  void pop() 
  {
    nextPos = AP::prev(nextPos);  
  }
  T& top()
  {
    return arr[AP::prev(nextPos)]; 
  }
 private:
  using AP = Access_Policy<N>;
  std::array<T,N> arr{};
  size_t nextPos{};
};


int  main()
{
	Fixed_Buffer<int, 10> ring10;

	for (int i = 1; i < 13; ++i)
	{
		ring10.push(i);
	}
	for(int j = 0; j != 10;j++)
	  {
	    std::cout << ring10.top() << endl;
	  }
	ring10.pop();
	cout << "Shall be 11: " << ring10.top() << endl;

	try {
		Fixed_Buffer<int, 5, Out_Of_Bounds> fb;
		for ( int i {}; i < 7; ++i )
		{
			fb.push(i);
		}
	}
	catch (std::out_of_range const & e)
	{
		cout << "Can't add more elements!" << endl;
	}

	try {
		Fixed_Buffer<int, 5, Out_Of_Bounds> fb;
		fb.pop();
	}
	catch (std::out_of_range const & e)
	{
		cout << "Can't remove without adding first..." << endl;
	}
}

