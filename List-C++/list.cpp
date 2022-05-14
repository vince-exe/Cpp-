#include "list.hpp"

template<class T> void stl::List<T>::setHead(stn::Node<T> *newAddress) {
    this->head = newAddress;
}
 
template<class T> void stl::List<T>::setEnd(stn::Node<T> *newAddress) {
    this->end_ = newAddress;
}

template<class T> stn::Node<T> *stl::List<T>::getEnd() {
    return this->end_;
}

template<class T> inline stl::List<T>::List() {
    this->head = nullptr;
    this->end_ = nullptr;
    this->lenght_ = 0;
}

template<class T> void stl::List<T>::appendStart(T value) {
    struct stn::Node<T>* newNode = new stn::Node<T>;

    newNode->data = value;
    newNode->next = nullptr;

    if(this->head == nullptr) {
        this->head = newNode;
        this->end_ = newNode;
        this->head;
        this->lenght_ += 1;
        return;
    }else if(newNode == nullptr) {
        return;
    }

    newNode->next = this->head;
    this->end_ = head;
    this->head = newNode;
    this->lenght_ += 1;
}

template<class T> void stl::List<T>::appendEnd(T value) {
    struct stn::Node<T>* newNode = new stn::Node<T>;

    newNode->data = value;
    newNode->next = nullptr;

    if(this->head == nullptr) {
        this->head = newNode;
        this->end_ = newNode;
        this->lenght_ += 1;
        return;
    }else if(newNode == nullptr) {
        return;
    }    
    
    this->end_->next = newNode;
    this->end_ = newNode;
    this->lenght_ += 1;
}

template<class T> void stl::List<T>::free() {
    struct stn::Node<T>* tmp = this->head;

    while(this->head != nullptr) {
        this->head = this->head->next;
        delete tmp;

        tmp = this->head;
        this->lenght_ -= 1;
    }
    this->end_ = nullptr;
}

template<class T> stn::Node<T>* stl::List<T>::begin() {
    return this->head;
}

template<class T> stn::Node<T> *stl::List<T>::next(stn::Node<T> *it) {
    return (it = it->next);
}

template<class T> T stl::List<T>::getItem(int index) {
    struct stn::Node<T>* tmp = this->head;

    for(int i=0; i<index && tmp != nullptr; i++) {
        tmp = tmp->next;
    }

    return tmp->data;
}

template<class T> stn::Node<T> *stl::List<T>::getItemAddress(int index) {
    if(index < 0) {
        return this->head;
    }else if(index >= this->lenght_) {
        return this->end_;
    }
    
    struct stn::Node<T>* tmp = this->head;

    for(int i=0; i<index && tmp != nullptr; i++) {
        tmp = tmp->next;
    }
    
    return tmp;
}
 
template<class T> T stl::List<T>::getItem2(int index) {
    struct stn::Node<T>* tmp = this->head;

    if(index < 0 || index >= this->lenght_) {
        return tmp->data;
    } 

    for(int i=0; i<index && tmp; i++) {
        tmp = tmp->next;
    }

    return tmp->data;
}

template<class T> int stl::List<T>::lenght() {
    return this->lenght_;
}

template<class T> bool stl::List<T>::end(stn::Node<T>* it) {
    if(it == nullptr) {
        return true;
    }
    return false;
}

template<class T> bool stl::List<T>::remove(T value) {
    struct stn::Node<T>* tmp = this->head;

    if(this->head->data == value) {
        this->head = tmp->next;
        this->lenght_ -= 1;
        delete tmp;

        return true;
    }

    struct stn::Node<T>* prev = nullptr;
    while(tmp != nullptr && tmp->data != value) {
        prev = tmp;
        tmp = tmp->next;
    }

    if(tmp == nullptr) {
        return false;
    }

    prev->next = tmp->next;
    delete tmp;

    this->lenght_ -= 1;
    return true;
}

template<class T> void stl::List<T>::removeAll(T value) {
    stn::Node<T>* tmpHead = this->getItemAddress(0);
    stn::Node<T>* prev = nullptr;

    stl::List<T> newList;

    this->lenght_ = 0;

    while(tmpHead != nullptr) {
        if(tmpHead->data != value) {
            this->lenght_ += 1;
            newList.appendEnd(tmpHead->data);
        }

        prev = tmpHead;
        tmpHead = tmpHead->next;

        delete prev;
    }

    this->setHead(newList.getItemAddress(0));
    this->setEnd(newList.getEnd());
}
    
template<class T> int stl::List<T>::find(T value) {
    struct stn::Node<T>* tmp = this->head;
    int i = 0;

    while(tmp != nullptr && tmp->data != value) {
        tmp = tmp->next;
        i++;
    }

    if(tmp == nullptr) {
        return ITEM_NOT_FOUND;
    }

    return i;
}