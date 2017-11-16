#include <stdexcept>
#include <iostream>
#include <array>
using namespace std;
template <size_t N>
class Wrap 
{
public:
  static size_t next(size_t n) noexecpt
  {
    return (n+1)%N; 
  }
  static size_t prev(size_t n) noexecpt
  {
    return n ? n-1 : N-1;
  }
};

template <size_t N>
class Out_Of_Bounds
{
public:
  static size_t next(size_t n)
  {
    if (n == N -1 )
      {
	throw std::out_of_range_exception("Out of bounds")
      }
    else
      {
	return n-1; 
      }
    static size_t prev(size_t n)
    {
      if ( n == 0)
	{
	  throw std::out_of_range_exception("Out of bounds"); 
	}
      else
	{
	  return n-1; 
	}
    }
  }
};

template <typename T,size_t size, template<size_t> class Access_Protocol = Wrap>
class Fixed_Buffer
{
public:
  Fixed_Buffer() = default;
  Fixed_Buffer(Fixed_Buffer const &) = delete;
  Fixed_Buffer(Fixed_Buffer &&) = delete;
  void push(T const& val ) { arr[next_pos] = t;
		next_pos = AP::next(next_pos);}
  void pop() { next_pos = AP::prev(next_pos);}
  T& top() { return arr[AP::prev(next_pos)]; }
private:
  using AP = Access_Protocol<N>;
  std::array<N,T> arr {};
  size_t next_pos {} ;
};

int main()
{
	Fixed_Buffer<int, 10> ring10;

	for (int i = 1; i < 13; ++i)
	{
		ring10.push(i);
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

