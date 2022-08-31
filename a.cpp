#include<iostream>
#include<iomanip>

using std::cout;
using std::cin;
using std::string;

int main () 
{
  int table;
  cout<<"Enter any number";
  cin>>table;
  int result;
  for(int i=1;i!=11;i++)
  {
  result=i*table;
  cout<<result<<std::endl;
  }
}