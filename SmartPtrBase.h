#ifndef SMARTPOINTER_SMARTPTRBASE_H
#define SMARTPOINTER_SMARTPTRBASE_H

#include <iostream>

template <typename T>
class SmartPtr {
private:
    T * pointer = nullptr;
public:
    SmartPtr() : pointer(nullptr) {}
    SmartPtr(T * ptr) : pointer(ptr) {}
    SmartPtr(SmartPtr && pastobj);
    void operator=(SmartPtr && pastobj) {
        this->pointer = pastobj.pointer;
        pastobj.pointer = nullptr;
    }
    T * operator->() {
        return this->pointer;
    }

    T & operator*() {
        return *(this->pointer);
    }

    virtual ~SmartPtr() {
        if(pointer != nullptr) {
            delete pointer;
        }
    }
};

#endif //SMARTPOINTER_SMARTPTRBASE_H
