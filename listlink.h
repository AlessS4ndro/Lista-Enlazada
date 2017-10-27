template <typename U>
void ListLink<U>::print()
{
    NodeSimple<U> *n=head;
    while(n){
      cout<<"->"<<n->value->data;
      n=n->left;
    }
    cout<<"->NULL"<<endl;
}

template<typename T>
void ListLink<T>::push_back(T val)
{
  NodeSimple<T> *n=new NodeSimple<T>(val);

  if(head){
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
  if(head){
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
  if(head){
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
  while(n && n->value!=key )
    n=n->left;
  if(n)
    return n->value;
}

template<typename T>
bool ListLink<T>::add(int indice,T val)
{
  if(indice<=size){
    NodeSimple<T> *nuevo=new NodeSimple<T>(val);
    NodeSimple<T> *n=head;
    if(indice==0){        /////   ----------------------------------
      nuevo->left=head;   ///////// esta es una exepcion del algoritmo-
      head=nuevo;         ////////  si el indice es cero solo movemos head
      return true;        ////////// ----------------------
    }                     /////////   ---------------------
    for(int i=0;i<indice-1;i++){
        n=n->left;
    }
    nuevo->left=n->left;
    n->left=nuevo;
    return true;
  }
  return false;
}

template<typename T>
ListLink<T>::~ListLink()
{
  cout<<"--------Trabajo terminado-----------"<<endl;
  NodeSimple<T> *n;
  do{
    n=head;
    head=head->left;  ////////  apuntas ,saltas ,borras
    delete n;
    cout<<">eliminando nodo........."<<endl;
  }while(head);
  head=tail=NULL;
}
template<typename T>
void delete_ ListLink::delete_(NodeSimple<T> *p)
{
	NodeSimple<T> *walk,*borrador
	walk=head;
	if(!head) return;
	if(walk==p){
		head=head->left;
		delete walk;
	}
	while(walk->lef){
		if(walk->left==p)
			borrador=walk->left;
			walk->left=walk->left->left;
			delete borrador;
	}
	
}
