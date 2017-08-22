#include "clases.h"
#include "methods.h"


int main(int argc,char *argv[])
{

  ListLink<int> l;

  for(int i=0;i<10;i++)
    l.push_back(i);
  l.print();


  return 0;
}
