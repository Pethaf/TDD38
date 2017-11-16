#include <vector>
#include <iostream>
#include <string>
class Grill
{
public:
  std::string get__model() const { return model; }
  double get__price() const { return price;}
  void set__price(double newPrice) { price = newPrice;} 
  Grill* clone() { return get_clone(); }
  virtual ~Grill() = default; 
protected:
  Grill(const std::string& model_, const double price_): model(model_), price(price_) { }
  Grill(const Grill&) = default;
private:
  Grill& operator=(const Grill&) = delete;
  Grill& operator=(const Grill&&) = delete;
  virtual Grill* get_clone() const = 0;
  double price;
  std::string model;
};

class Grill_Charcoal : public Grill
{
public:
  Grill_Charcoal(const std::string& model_, double price_): Grill(model_,price_) { }
  virtual ~Grill_Charcoal() = default;
private:
  Grill_Charcoal(const Grill_Charcoal&) = default;
  Grill_Charcoal& operator=(const Grill_Charcoal&) = delete;
  Grill_Charcoal& operator=(const Grill_Charcoal&&) = delete;
  virtual Grill_Charcoal* get_clone() const override { return new Grill_Charcoal(*this); }
};

class Grill_LPG: public Grill
{
public:
  Grill_LPG(const std::string& model_, double price_, const std::string& fuel_="Propane"): Grill(model_,price_),fuel(fuel_) { }
  std::string get__lpg() const { return fuel; }
protected:
  std::string fuel;
  Grill_LPG(const Grill_LPG&) = default;
  virtual ~Grill_LPG() = default; 
private:
  Grill_LPG& operator=(const Grill_LPG&) = delete;
  Grill_LPG& operator=(const Grill_LPG&&) = delete;
  virtual Grill_LPG* get_clone() const override { return new Grill_LPG(*this); }
};

class Grill_LPG_Side: public Grill_LPG
{
public:
  Grill_LPG_Side(const std::string& model_, double price_, const std::string& fuel_ = "Propane"): Grill_LPG(model_,price_,fuel_) {}
  virtual ~Grill_LPG_Side() = default;
private:  
  Grill_LPG_Side(const Grill_LPG_Side&) = default;
  virtual Grill_LPG_Side* get_clone() const override { return new Grill_LPG_Side(*this); }
  Grill_LPG_Side& operator=(const Grill_LPG_Side&) = delete;
  Grill_LPG_Side& operator=(const Grill_LPG_Side&&) = delete;
};


int main()
{
  std::vector<Grill*> grillVect{ new Grill_Charcoal{"El Charro",52}, new Grill_LPG{"El Gasso",52.2}, new Grill_LPG_Side{"El Gasso Primo", 443.3}};
  for(auto &x: grillVect)
    {
      auto tmp = x->clone();
      std::cout << x->get__model() << "\t" << x->get__price();
      if(auto gl = dynamic_cast<Grill_LPG*>(tmp))
	{
	  std::cout << "\t" << "LPG" << gl->get__lpg();
	}
      else
	{
	  std::cout << "\t" << "Charcoal"; 
	}
      std::cout << "\n";
    }
  for(auto &x: grillVect)
    {
      delete x;
      x = nullptr;
    }
  return 0;
}
