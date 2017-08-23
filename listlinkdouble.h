template <typename U>
void ListLinkDouble<U>::print()
{
    NodeDouble<U> *n=head;
    while(n){
      cout<<n->value<<"--";
      n=n->left;
    }
    cout<<endl;
}

template<typename T>
void ListLinkDouble<T>::push_back(T val)
{
  NodeDouble<T> *nuevo=new NodeDouble<T>(val);

  if(head){
    tail->left=nuevo;
    nuevo->right=tail;
    tail=tail->left;
  }
  else{
    head=nuevo;
    tail=nuevo;
  }
  size++;
}

template<typename T>
void ListLinkDouble<T>::push_front(T val)
{
  NodeDouble<T> *nuevo=new NodeDouble<T>(val);

  if(head){
    head->right=nuevo;
    nuevo->left=head;
    head=nuevo;
  }
  else{
    head=tail=nuevo;
  }
  size++;
}

template<typename T>
void ListLinkDouble<T>::pop_back()
{
  if(head){
    NodeDouble<T> *n=tail;
    tail=tail->right;
    tail->left= NULL;
    delete n;
    size--;
  }
}

template<typename T>
void ListLinkDouble<T>::pop_front()
{
  if(head){
    NodeDouble<T> *n=head;
    head=head->left;
    head->right=NULL;
    delete n;
    size--;
  }
}

template<typename T>
bool ListLinkDouble<T>::add(int indice,T val)
{
  if(indice<=size){
    NodeDouble<T> *nuevo=new NodeDouble<T>(val);
    NodeDouble<T> *n;
    if(indice==0){            ////////// si el indice es cero
      nuevo->left=head;       ////////// solo movemos la cabeza
      if(head){               ///////// exepcion si head!=NULL
        head->right=nuevo;    //////////  --------------------
      }
    }
    if(size-1-n>=n){          ////////////////--------------
      n=head;                   /////////////////------------
      for(int i=0;i<indice-1;i++){    //////////  empezamos
        n=n->left;              ///////// por la cabeza y
      }                         /////// recorremos hasta
      nuevo->left=n->left;      /////// una posicion antes
      nuevo->right=n;           /////////   -> -> -> ->
      n->left->right=nuevo;       ////// NULL<-[]<->[]<->[]->NULL
      n->left=nuevo;            /////////////------------
    }
    else{
      n=tail;                         ////////----------
      for(int i=size-1;i>indice;i--){ //////////---------
        n=n->right;                   /////// empezamos
      }                               ////// por la cola y
      nuevo->left=n;                  ////// recorremos hasta
      nuevo->right=n->right;          //////// una posicion
      n->right->left=nuevo;           /////// antes
      n->right=nuevo;                 //////  <- <- <- <-
    }                             ////// NULL<-[]<->[]<->[]->NULL
    return true;
  }
  return false;
}
