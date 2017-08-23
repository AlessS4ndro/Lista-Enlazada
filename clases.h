#include <iostream>
using namespace std;

template<typename T>
struct NodeSimple
{
  T value;
  NodeSimple *left;
  int index;

  NodeSimple(T v):value(v),left(NULL){}
  ~NodeSimple(){}
};

template <typename U>
struct NodeDouble:private NodeSimple<U>
{
  NodeDouble *right;

  NodeDouble(U v):NodeSimple<U>(v),right(NULL){}
  ~NodeDouble(){}
};

template <typename T>
class ListLink
{
  NodeSimple<T> *head;
  NodeSimple<T> *tail;
  int size;
public:
  ListLink():head(NULL),tail(NULL),size(0){}
  ~ListLink(){}
  bool add(int,T );
  void push_back(T );
  void push_front(T);
  T pop_back();
  T pop_front();
  T& find(T);

  void print();
};
