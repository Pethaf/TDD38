#ifndef SMART_POINTER_H

class incompatible
{

};
template<bool flag, typename T1, typename T2>
struct select_type {
	typedef T1 result;
};

template<typename T1, typename T2>
struct select_type<false, T1, T2>
{
	typedef T2 result;
};

struct allow_conversion
{
	static const bool allow = true;
};

struct disallow_conversion
{
	static const bool allow = false; 
};


template<typename T, class copy_policy = diallow_conversion>
class smart_pointer
{
public:
	smart_pointer() = default;
	explicit smart_pointer(T* p): ptr_{p} { }
	smart_pointer(const smart_pointer& rhs) { ptr_ = copy(rhs);}
	~smart_pointer() { delete ptr_;}
	smart_pointer& operator=(const smart_pointer& rhs)
	{
		if (this != &rhs)
		{
			delete ptr_;
			ptr_ = copy(rhs);
		}
		return *this;
	}
	T& operator*() const { return *ptr_;}
	T& operator*() { return *ptr_;}
	T& operator->() const {return ptr_; }
	T& operator->() { return ptr_;}
private:
	T* ptr_;
	T* copy(const smart_pointer& sp)
	{
		return sp.ptr_ ? new T{sp.ptr_} : nullptr;
	}
	class disallowed {};
	using implicit_conversion_type = typename select_type<conversion_policy::allow, T*, disallowed>::result;
	operator implicit_conversion_type() const { return ptr_; }
};


template<typename
#endif