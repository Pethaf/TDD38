#include <vector>
#include <iostream>
#include <string>
#include <memory>
#include <typeinfo>
using std::vector;
using std::cout;
using std::string; 
using std::make_shared;
using std::make_unique;
using std::shared_ptr;
class Grill
{
public:
  Grill() = default;
  virtual ~Grill() = default;
  Grill* clone() const { return get_clone(); }
  string get__model() const { return getModel(); }
  double get__price() const { return getPrice(); }
  void set_price(double newPrice) { price = newPrice; } //This member function should probably do a sanity check on the new price and throw a range_error exception.
protected:
  Grill(const Grill&) = default;
  Grill(const string model_, const double price_): model(model_), price(price_) { } 
  string model;
  double price;
private:
  virtual Grill* get_clone() const = 0; 
  virtual string getModel() const = 0;
  virtual double getPrice() const = 0; 
};

class Grill_charcoal: public Grill
{
public:
  Grill_charcoal(string model_, double price_ ) : Grill(model_, price_) { }  
  virtual ~Grill_charcoal() = default;
private:
  virtual Grill_charcoal* get_clone() const override { return new Grill_charcoal(*this); }
  virtual string getModel() const override { return model;}
  virtual double getPrice() const override { return price;} 
  Grill_charcoal(const Grill_charcoal&) = default;
};

class Grill_LPG: public Grill
{
public:
  Grill_LPG(string model_, double price_, string fuel_ = "Propane"): Grill(model_, price_), fuel(fuel_) {}
  virtual ~Grill_LPG() = default;
  string get__lpg() const {return fuel; } 
protected:
  Grill_LPG(const Grill_LPG&) = default; 
  string fuel;
private:
  virtual Grill_LPG* get_clone() const override {return new Grill_LPG(*this); }
  virtual double getPrice() const override { return price;}
  virtual string getModel() const override { return model;}
};

class Grill_LPG_Side: public Grill_LPG
{
public:
  Grill_LPG_Side(string model_, double price_, string fuel_ = "Propane"): Grill_LPG(model_, price_,fuel_) {}
  virtual ~Grill_LPG_Side() = default;
private:
  Grill_LPG_Side(const Grill_LPG_Side&) = default;
  virtual Grill_LPG_Side* get_clone() const override { return new Grill_LPG_Side(*this); }
  virtual string getModel() const override { return model;}
  virtual double getPrice() const override { return price;}
};

void print_contents(std::unique_ptr<Grill> grillPtr)
{
  /*if(std::typeid(grillPtr) == std::typeid(Grill_charcoal*))
    {
      cout << "Charcoal" << std::endl; 
      }*/
  /*else if(std::typeid(grillPtr) == std::typeid(Grill_LPG_Side) ||
	  std::typeid(grillPtr) == std::typeid(Grillptr_LPG))
    {
      cout << "LPG" << std::endl;   
      }*/
  std::cout << grillPtr->get__model() << " " << grillPtr->get__price() << std::endl; 
  }
int main()
{
  vector<Grill*> grillVect{ new Grill_charcoal("Charcole 1", 42), new Grill_LPG("LPG Grill", 44), new Grill_LPG_Side("LPG Side Grill", 46)}; 
  for(auto x: grillVect)
    {
      Grill* tmp = x->clone();
      if(dynamic_cast<Grill_charcoal*>(tmp))
	{
	  cout << "Charcole" << std::endl;
	}
      else if(dynamic_cast<Grill_LPG*>(tmp) || dynamic_cast<Grill_LPG_Side*>(tmp))
	{
	  cout << "LPG" << std::endl;
	}
      cout << tmp->get__model() << "\t" << x->get__price() << std::endl;
    }
  return 0;
}
