#include<iostream>
using namespace std;

class abstractcar
{
  virtual void evorgas() = 0;
};

class car : abstractcar
{
  public:
    string Type;
    string Name;
    string Colour;
    int Model;
    
  car(string type,string name,string colour,int model)
  {
    Type=type;
    Name=name;
    Colour=colour;
    Model=model;
  }
  void evorgas() {
    if (Type=="ev")
    cout<<Name<<" is electric";
    else 
    cout<<Name<<" is internal combustion";
  }
};

int main () 
{
    car car1("ev","tesla","silver",2019);
    car1.evorgas();
}