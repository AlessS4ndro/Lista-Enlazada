#include "clases.h"
#include "listlink.h"


int main(int argc,char *argv[])
{

  ListLink<int> l;

  for(int i=0;i<10;i++)
    l.push_back(i);
  l.print();
  l.push_back(-33);
  l.push_front(69);
  l.print();
  int x=l.pop_back();
  int y=l.pop_front();
  cout<<"x , y es  : "<<x<<" , "<<y<<endl;
  l.print();
  int z=l.find(5);
  cout<<"z es : "<<z<<endl;
  cout<<"modificamos valor 5"<<endl;
  l.find(5)=11111;
  l.print();

	/////////	ESTAMOS MODIFICANDO EL MAIN		//////7
  return 0;
}
