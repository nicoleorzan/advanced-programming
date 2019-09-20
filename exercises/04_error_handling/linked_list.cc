#include <iostream>
#include <string>

enum class Insertion_method { push_back, push_front };

template<typename value_type>
Class List<V>{
  struct Node{
    value_type val;
    std::unique_ptr<node> next;
  
    //constructor for the node
    Node(const T& v, Node* n = nullptr) : val{v}, next{n} {}
  };

  // append the newly created node at the end of the list
  void push_back(const value_type& v);
  // insert the newly created node in front of the list
  void push_front(const value_type& v);

  std::unique_ptr<node> head;
  unsigned int size;
  
 public:
  void print() const;
  unsigned int size();
  void reset();
  void prune_node(const value_type& v);
  void insert(const value_type& v, const Insertion_method method);

  class Iterator;
  Iterator begin() { return Iterator{head.get()}; }
  Iterator end() { return Iterator{nullptr}; }

  class ConstIterator;
  ConstIterator begin() const { return ConstIterator{head.get()}; }
  ConstIterator end() const { return ConstIterator{nullptr}; }

  ConstIterator cbegin() const { return ConstIterator{head.get()}; }
  ConstIterator cend() const { return ConstIterator{nullptr}; }
};
template <typename T>
class List<T>::Iterator : public std::iterator<std::forward_iterator_tag, T> {
  using Node = List<T>::Node;
  Node* current;

 public:
  Iterator(Node* n) : current{n} {}
  T& operator*() const { return current->val; }

  // ++it
  Iterator& operator++() {
    current = current->next.get();
    return *this;
  }

  // it++
  Iterator operator++(int) {
    Iterator it{current};
    ++(*this);
    return it;
  }

  bool operator==(const Iterator& other) {
    return this->current == other.current;
  }

  bool operator!=(const Iterator& other) { return !(*this == other); }
};

template <typename T>
class List<T>::ConstIterator : public List<T>::Iterator {
  using parent = List<T>::Iterator;

 public:
  using parent::Iterator;
  const T& operator*() const { return parent::operator*(); }
};

template <typename T>
void List<T>::insert(const value_type& v, const Insertion_Method method) {
  if (head.get() == nullptr)
    // head.reset(new Node{v,nullptr});
    head.reset(new Node{v});
  else {
    switch (method) {
    case IM::push_back:
      push_back(v);
      break;

    case IM::push_front:
      push_front(v);
      break;

    default:
      std::cerr << "error\n";
      break;
    }
  }
}


template <typename T>
void List<T>::push_front(const T& v) {
  head.reset(new Node{v, head.release()});
}

template <typename T>
void List<T>::push_back(const T& v) {
  Node* tmp{head.get()};
  while (tmp->next.get() != nullptr)
    tmp = tmp->next.get();
  tmp->next.reset(new Node{v});
}


template <typename T>
void List<T>::print() const {

  auto it = this->begin();
  auto it_end = this->end();
  for (; it != it_end; ++it)
    std::cout << *it << std::endl;
}
