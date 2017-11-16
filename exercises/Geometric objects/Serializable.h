class Serializable 
{
public:
	std::string str() const { return to_str(); }
protected:
	Serializable() = default;
private:
	virtual std::string to_str() const = 0; 
};
