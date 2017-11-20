#include <iostream>
#include <memory>

enum class Insertion_method { push_back, push_front };

template <typename value_type>
class List {
 public:
  struct Invalid_insertion_method {};
  struct Double_removal_attempt {};

  // insert a new node with the value v according to the method m
  // this method should be used to fill the list
  void insert(const value_type& v, const Insertion_method m) {
    switch (m) {
      case Insertion_method::push_back:
        push_back(v);
        break;
      case Insertion_method::push_front:
        push_front(v);
        break;
      default:
        throw(Invalid_insertion_method{});
    }
  }

  // print the values of the nodes
  void print() const;

  // return the size of the list
  unsigned int size() const {return _size;}

  // delete all the nodes of the list
  void reset() {
    delete head;
    _size = 0;
  }

  // prune node storing the value v
  void prune_node(const value_type& v);

  // implement suitable constructor(s) for List
  List() {_size = 0;}

 private:
 
  // private struct node with the proper value_type
  struct node {
    value_type val;
    std::unique_ptr<node> next;

    // implement suitable constructor(s) for node
  };

  // append the newly created node at the end of the list
  void push_back(const value_type& v);

  // insert the newly created node in front of the list
  void push_front(const value_type& v);

  std::unique_ptr<node> head;
  unsigned int _size;
};

template <typename value_type>
void List<value_type>::push_front(const value_type& v) {
  node *newnode { new node{v, std::move(head)} };
  head = std::unique_ptr<node>(newnode);
  _size++;
}

template <typename value_type>
void List<value_type>::push_back(const value_type& v) {
  std::unique_ptr<node> *currentnode;
  currentnode = &head;
  while (*currentnode) {
    currentnode = &((*currentnode)->next);
  }
  node* newnode { new node{v} };
  *currentnode = std::unique_ptr<node>(newnode);
  _size++;
}

template <typename value_type>
void List<value_type>::print() const {
  const std::unique_ptr<node> *currentnode {&head};
  while (*currentnode) {
    std::cout << (*currentnode)->val << " ";
    currentnode = &((*currentnode)->next);
  }
  std::cout << std::endl;
}

template <typename value_type>
void List<value_type>::prune_node(const value_type& v) {
  std::unique_ptr<node> *currentnode {&head};
  while (*currentnode) {
    if ((*currentnode)->val == v) {
      *currentnode = std::move((*currentnode)->next);
      _size--;
      return;
    }
    currentnode = &((*currentnode)->next);
  }
  throw(Double_removal_attempt{});
}

int main() {
  List<int> *mylist = new List<int>;
  mylist->insert(1,Insertion_method::push_back);
  mylist->insert(5,Insertion_method::push_back);
  mylist->insert(3,Insertion_method::push_front);
  mylist->print();
  try {
    mylist->prune_node(1);
  } catch (...) {
    std::cerr << "Exception" << std::endl;
  }
  mylist->print();
}



















