

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

template <typename U>
void ListLink<U>::print()
{
    NodeSimple<U> *n=head;
    while(n!=NULL){
      cout<<n->value<<"--";
      n=n->left;
    }
}
