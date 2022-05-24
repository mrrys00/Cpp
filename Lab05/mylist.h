#include <iostream>
#include <stdlib.h>
#include <memory>

template <typename T>
class MyListNode;


template <class T>
class MyList {
public:
    MyList();
    //~MyList();
    void push_front(T);
    T pop_front();
    T front();
    [[nodiscard]] int size() const;

    MyList(const MyList&) = delete;
    MyList & operator=(const MyList&) = delete;

    // DODANE # # # # # #

    typedef T value_type;

    friend std::ostream& operator<<(std::ostream &output, const MyList<T> &l) {
        for(auto iter = l.begin(); iter != l.end(); ++iter)
            output << *iter << " -> ";
        return output;
    }

    // DODANE # # # # # #

    class Node {
        friend class MyList;
    public:
        explicit Node(T);
        Node() : next(nullptr) {}
        T value;
        std::unique_ptr<Node> next;
    };

    class iterator {
        friend class MyList;
    private:
        Node *node;
        explicit iterator(Node *newElem) : node(newElem) {}
    public:
        iterator() : node(nullptr) { }
        bool operator!=(const iterator& itr) const;
        T& operator*() const;
        iterator operator++(int) {
            iterator temp = *this;
            node = node->next;
            return temp;
        }
        iterator operator++() {
            iterator temp = *this;
            node = node->next.get();
            return temp;
        }
    };

    iterator begin() const {
        return iterator(head.get());
    }

    iterator end() const {
        Node* elem = this->head.get();
        while(elem->next) {
            elem = elem->next.get();
        }
        return iterator(elem);
    }

    iterator insert(iterator position,const T& value) {
        Node* newNode = new Node(value, position.nodePtr->next);
        if (position.nodePtr == getTail()) getTail() = newNode;
        position.nodePtr->next = newNode;
        return position;
    }

    void remove(T elem);

protected:
    std::unique_ptr<Node> head;
private:
    Node* getTail();
};


