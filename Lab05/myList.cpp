#include "mylist.h"

template<class T>
bool MyList<T>::iterator::operator!=(const MyList::iterator &itr) const {
    return node != itr.node;
}

template<class T>
T &MyList<T>::iterator::operator*() const {
    return node->next->value;
}

template<class T>
MyList<T>::MyList() {
    head.reset(new Node());
    head->next.reset();
}

template<class T>
int MyList<T>::size() const {
    Node* elem = this->head.get();
    int s = 0;
    while(elem->next) {
        s++;
        elem = elem->next.get();
    }
    return s;
}

template<class T>
void MyList<T>::push_front(T newElem) {
    std::unique_ptr<Node> newNode(new Node(newElem));
    newNode->next.reset(head->next.release());
    head->next.reset(newNode.release());
}

template<class T>
T MyList<T>::pop_front() {
    if(!head->next) {
        throw std::out_of_range("List is empty");
    }
    T retval = head->next->value;
    head->next.reset(head->next->next.release());
    return retval;
}

template<class T>
T MyList<T>::front() {
    return head->next->value;
}

template<class T>
typename MyList<T>::Node *MyList<T>::getTail() {
    Node* elem = this->head;
    while(elem->next) {
        elem = elem->next;
    }
    return elem;
}

template<class T>
void MyList<T>::remove(T elem) {
    for(auto iter = this->begin(); iter != this->end();) {
        if(*iter == elem) {
            iter.node->next.reset(iter.node->next->next.release());
        }
        else ++iter;
    }
}

// template<class T>
// std::ostream &operator<<(std::ostream &output, const MyList<T> &mylist) {
//     for(auto iter = mylist.begin(); iter != mylist.end(); ++iter) {
//         output << *iter << ", ";
//     }
//     return output;
// }

//////////////////////////////////////////////////

template <typename T>
MyList<T>::Node::Node(T dataIn) {
    value = dataIn;
    next = nullptr;
}
