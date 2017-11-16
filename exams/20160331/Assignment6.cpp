#include <iostream>
#include <vector>
#include <algorithm>
using std::string;
using std::vector;
class Score_Variant
{
public:
  virtual string name() const = 0;
  virtual int score(vector<int>) const = 0;
  virtual ~Score_Variant() = default;
protected:
   Score_Variant() = default;
private:
  Score_Variant(const Score_Variant&) = delete;
  Score_Variant& operator=(const Score_Variant&) = delete;
  Score_Variant& operator=(const Score_Variant&&) = delete;
 };

class Counted_Dice: public Score_Variant
{
public:
   virtual string name() const override = 0;
   virtual int score(vector<int> dice) const override
   { return lookup*std::count(begin(dice),end(dice), lookup);}
   int get_number() const { return lookup; }
virtual ~Counted_Dice() = default; 
protected:
   Counted_Dice(int whatToLookFor): lookup(whatToLookFor) {  }  
private:
  Counted_Dice() = delete;
  Counted_Dice(const Counted_Dice&) = delete;
  Counted_Dice& operator=(const Counted_Dice&) = delete;
  Counted_Dice& operator=(const Counted_Dice&&) = delete;
int lookup;
  
};

class Ones: public Counted_Dice
{
public:
Ones(): Counted_Dice(1) {}
virtual string name() const override { return "Ones";}
virtual ~Ones() = default;
private:
Ones(const Ones&) = delete;
Ones& operator=(const Ones&) = delete;
Ones& operator=(const Ones&&) = delete;
};

class Twos: public Counted_Dice
{
public:
 Twos(): Counted_Dice(2) { }
virtual string name() const override { return "Twos"; }
virtual ~Twos() = default;
private:
 Twos(const Twos&) = delete;
 Twos& operator=(const Twos&) = delete;
 Twos& operator=(const Twos&&) = delete; 
};

class Pair: public Score_Variant
{
public:
virtual string name() const override { return "Pair"; }
virtual int score(vector<int> dice) const override
{
std::sort(begin(dice),end(dice), std::greater<int>{});

auto tmp=std::adjacent_find(begin(dice),end(dice));

if(tmp != end(dice)) 
 {
   return 2*(*tmp);
 }
 else
{
   return 0;
}
}
};
  
int main()
{

vector<Score_Variant*>sVec{ new Pair(), new Ones(), new Twos() };
vector<int> iVec{13,2,2,3,5};

for(auto & x: sVec)
{
auto tmp = x->score(iVec);
if(tmp)
{
std::cout << x->name() << ":\t"  << tmp; 
if(auto gl = dynamic_cast<Counted_Dice*>(x))
  {
std::cout << " (" << tmp/(gl->get_number()) <<  ")" ;
}
std::cout << std::endl;
}
}
return 0;
}
