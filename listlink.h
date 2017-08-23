template <typename U>
void ListLink<U>::print()
{
    NodeSimple<U> *n=head;
    while(n!=NULL){
      cout<<n->value<<"--";
      n=n->left;
    }
    cout<<endl;
}

template<typename T>
void ListLink<T>::push_back(T val)
{
  NodeSimple<T> *n=new NodeSimple<T>(val);

  if(head!=NULL){
    tail->left=n;
    tail=tail->left;
  }
  else{
    head=n;
    tail=n;
  }
  size++;

}

template <typename T>
void ListLink<T>::push_front(T val)
{
  NodeSimple<T> *n=new NodeSimple<T>(val);

  if(head==NULL){
    tail=n;
  }
  n->left=head;
  head=n;
  size++;
}

template<typename T>
T ListLink<T>::pop_front()
{
  if(head!=NULL){
    NodeSimple<T> *n=head;
    T retornable;
    head=head->left;
    retornable=n->value;    //////7   para no perder  el valor
    delete n;
    size--;
    return retornable;
  }
}
template<typename T>
T ListLink<T>::pop_back()
{
  if(head!=NULL){
    NodeSimple<T> *n=head;
    T retornable;
    while(n->left!=tail)
      n=n->left;
    retornable=tail->value;   ////////    para no perder el valor
    delete tail;
    tail=n;
    n->left=NULL;
    size--;
    return retornable;
  }
}
template<typename T>
T& ListLink<T>::find(T key)
{
  NodeSimple<T> *n=head;
  while(n!=NULL && n->value!=key )
    n=n->left;
  if(n!=NULL)
    return n->value;
}
/*
template<typename T>
bool ListLink<T>::add(int indice,T val)
{
  if(indice<=size){
    NodeSimple<T> *nuevo=new NodeSimple<T>(val);
    NodeSimple<T> *n=head;
    if(indice==0){
      head=nuevo;
      head->left=n;
    }

    for(int i=0;i<indice-1;i++){
        n=n->left;
    }


  }
  return false;
}
*/
