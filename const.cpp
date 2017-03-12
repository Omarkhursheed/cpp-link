#include <iostream>
#include <string>
using namespace std;
class parent
{
private: 
  int age;
protected:
  string lastname;
public:
  parent(){}
  parent(string str, int n)
  {
    lastname = str;
    age = n;
  }
  void assign(string str1, int k)
  {
    lastname = str1;
    age = k;
  }
  void display()
  {
    cout << lastname << endl;
    cout << age << endl;
  }
};
class child: public parent
{
protected:
  int child_age;
  string firstname;
public:
  child(string s1, string s2, int n1, int n2):
  parent(s2, n2)
  {
    firstname = s1;
    child_age = n1;
  }
};
int main()  
{
  child one("Omar", "Khursheed", 12, 52);
  one.display();
  return 0;
}