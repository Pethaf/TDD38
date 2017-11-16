class Clonable 
{
public: 
	virtual Clonable* clone() const = 0; 
	Clonable()  =default;
	Clonable(const Clonable&) =default;
	virtual ~Clonable() = default;

};