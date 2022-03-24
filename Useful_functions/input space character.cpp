#include <bits/stdc++.h>
#include <string>
using namespace std;

int main ()
{
  string mystr="";

  while(1)
  {
  	  getline (cin, mystr);
  	  istringstream input(mystr);
		int value;
		while (input >> value)
		{
		    cout<<value<<endl;
		}
		if(mystr=="")
		break;
  }

  cout << "I like " << mystr << " too!\n";
  return 0;
}
