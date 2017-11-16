#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::vector;
using std::string;

class Grill
{
public:
  string get__model() const { return model;}
  double get__price() const { return price; }
  void set__price(double newPrice) { price=newPrice;  } //This member function should really do a sanity check and throw a range_error
  Grill* clone() const { return getClone(); }
  virtual ~Grill() = default; 
protected:
  Grill(const Grill&) = default;
  Grill(const string model_,const double price_): model(model_), price(price_) { } 
  string model;
  double price;
private:
  Grill& operator=(const Grill& other) = delete;
  virtual Grill* getClone() const = 0; 
};

class Grill_Charcoal: public Grill
{
   public:
     Grill_Charcoal(const string model_,const double price_): Grill(model_, price_) { }
     virtual ~Grill_Charcoal() = default;
   protected:
     Grill_Charcoal(const Grill_Charcoal&) = default; 
  private:
   Grill_Charcoal& operator=(const Grill_Charcoal&) = delete;
   virtual Grill_Charcoal* getClone() const override { return new Grill_Charcoal(*this); } 
};

class Grill_LPG: public Grill
{
public: 
  Grill_LPG(const string& model_, const double& price_, const string& fuel_ = "Propane"): Grill(model_, price_), fuel(fuel_)  { }
  string get__lpg() const { return fuel; }
  virtual ~Grill_LPG() = default;
protected:
  Grill_LPG(const Grill_LPG&)  = default;
  string fuel;
private:
  Grill_LPG& operator=(const Grill_LPG&) = delete; 
  virtual Grill_LPG* getClone() const override { return new Grill_LPG(*this); }
};  

class Grill_LPG_Side: public Grill_LPG
{
public:
  Grill_LPG_Side(const string& model_, const double& price_, const string& fuel_ ="Propane"): Grill_LPG(model_,price_,fuel_) {}
  virtual ~Grill_LPG_Side() = default; 
private:
  Grill_LPG_Side(const Grill_LPG_Side&) = default;
  Grill_LPG_Side& operator=(const Grill_LPG_Side&) = delete;
  virtual Grill_LPG_Side* getClone() const override { return new Grill_LPG_Side(*this); } 
};

int main()
{
  vector<Grill*> grillVect{ new Grill_Charcoal("El Charador", 42.5), new Grill_LPG("El Gasso", 45.5), new Grill_LPG_Side("El Gasso Deluxe",532.5)};
  for (auto && x: grillVect)
    {
      auto tmp = x->clone();
      if( dynamic_cast<Grill_Charcoal*>(tmp))
	{ cout << "Charlcoal"; }
      else if( auto gl = (dynamic_cast<Grill_LPG*>(tmp)))
	{
	  cout << "LPG " << gl->get__lpg() << " ";
	}
      cout << tmp->get__model() << " " << tmp->get__price() << "\n" << endl;
      delete tmp;
      tmp = nullptr; 
    }
  for (auto &&y : grillVect)
    {
      cout << y->get__model();
      delete y;
      y = nullptr; 
    }
  return 0;
}
  
