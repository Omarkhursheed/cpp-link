#include <iostream>

using namespace std;
class SimpleCat
{
  public:
    SimpleCat();
    SimpleCat(SimpleCat&);
    ~SimpleCat();

    int GetAge() const {return itsAge;}
    void SetAge(int age){ itsAge = age;}

  private:
    int itsAge;

};

SimpleCat::SimpleCat()
{
  cout << "SimpleCat Constructor..." << endl;
  itsAge = 1;
}

SimpleCat::SimpleCat(SimpleCat&)
{
  cout << "SimpleCat Copy Constructor..." << endl;
}

SimpleCat::~SimpleCat()
{
  cout << "SimpleCat Destructor..." << endl;
}

const SimpleCat * const FunctionTwo
  (const SimpleCat * const theCat);

int main()
{
  cout <<"Making a cat..."<< endl;
  SimpleCat Frisky;
  cout << "Frisky is ";
  cout << Frisky.GetAge();
  cout << " years old" << endl;
  int age = 5;
  Frisky.SetAge(age);
  cout << "Frisky is ";
  cout << Frisky.GetAge();
  cout << " years old" << endl;
  cout << "Calling FunctionTwo..." << endl;
  FunctionTwo(&Frisky);
  cout << "Frisky is ";
  cout << Frisky.GetAge();
  cout << " years old" << endl;
  return 0;
}

const SimpleCat * const FunctionTwo
  (const SimpleCat * const theCat)
  {
    cout << "FunctionTwo. Returning..." << endl;
    cout << "Frisky us now " << theCat -> GetAge();
    return theCat;
  }