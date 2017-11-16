#include <iostream>
#include <string>
#include <iostream>
#include <vector>
#include <typeinfo>
#include <memory>

const int ROOM_TEMPERATURE = 22; 

class Sauna
{
public:
	virtual ~Sauna() = default;
	Sauna* get_clone() const { return clone();}
	double getTemperature() const { return temperature; }
	void setTemperature(double newTemp) {temperature = newTemp; }
	friend ostream& operator<<(std::ostream& os, const Sauna& s) 
	{
		if(s.isOn) 
		{
			os << str()<< "[ON]" << temperature << "degrees" ;
		}
		else
		{
			os << "[OFF]"
		}
		return os;
	}
	void turnOn()  {isOn = true; setTemperature(ROOM_TEMP);}
	void turnOff() {itOn = true; setTemperature(default_temp);}
protected:
	Sauna(const Sauna& otherSauna) = default;
	Sauna(double def = ROOM_TEMP): default_temp{ROOM_TEMP} { }
private:
	bool isOn{ };
	double temperature{ROOM_TEMP}; 
	Sauna* clone() const = 0;
    double default_temp;
    virtual std::string str() const { return "Sauna"; }

};

class Steam_Heater: Sauna
{
public:
	Steam_Heater(): default_temp{38} { }
	virtual ~Steam_Heater() = default;
private:
	Steam_Heater* clone() const override { return new Steam_Heater(*this)}
	virtual Steam_Heater(const Steam_Heater& rhs) = default; 
	virtual std::string str() const override { return "Steam sauna";}

};

class Electric_Heater: Sauna
{
public:
	Electric_Heater(): default_temp{85} 
	virtual ~Electric_Heater() = default;
private:
	Electric_Heater(const Electric_Heater& lhs) = default;
	Electric_Heater* clone() const override { return new Electric_Heater(*this);}
	virtual std::string str() const override{ return "Electric heater";}
};

class Wood_Sauna: Sauna
{
public:
	Wood_Sauna() = default;
	virtual ~Wood_Sauna() = default;
	void add_log() { setTemperature(getTemperature() +5);}
private:
	Wood_Sauna(const Wood_Sauna& otherSauna) = default;
	Wood_Sauna* close() const override { return new Wood_Sauna(*this);}
	virtual std::string str() const override { return "Wood heated sauna";}
};

void theMagicFunction(sauna* theSauna)
{
	std::cout << *theSauna << std::endl;
	theSauna->turnOn();
	if(typeid(*theSauna) == typeid(Wood_Sauna))
	{
		for(int i=0;i!=9;i++)
		{
			theSauna->add_log();
		}
	}
	std::cout << *theSauna << std::endl;
}
int main()
{
	std::vector<*Sauna>(3) saunaVect;
	saunaVect.push_back(new )


}