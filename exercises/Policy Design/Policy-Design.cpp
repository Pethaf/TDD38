template<typename T>
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
};


template<typename