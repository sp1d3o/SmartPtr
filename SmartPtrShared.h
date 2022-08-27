#ifndef SMARTPOINTER_SMARTPTRSHARED_H
#define SMARTPOINTER_SMARTPTRSHARED_H

#include "SmartPtrBase.h"

typedef unsigned int uint;

template <typename T>
class SharedPtr : public SmartPtr<T> {
private:
    uint *ref_count;
    T * pointer;
    void _cleanup_() {
        (*ref_count)--;
        if(*ref_count == 0) {
            if(nullptr!= pointer) {
                delete pointer;
            }
            delete ref_count;
        }
    }
public:
    SharedPtr() : pointer(nullptr), ref_count(new uint(0)) {}

    SharedPtr(T * ptr) : pointer(ptr), ref_count(new uint(1)) {}

    SharedPtr(const SharedPtr & obj) {
        this->pointer = obj.pointer;
        this->ref_count = obj.ref_count;
        if(nullptr != obj.pointer) {
            ((*this).ref_count)++;
        }
    }

    SharedPtr & operator=(const SharedPtr & obj) {
        _cleanup_();

        this->pointer = obj.pointer;
        this->ref_count = obj.ref_count;
        if(nullptr != obj.pointer) {
            (*this->ref_count)++;
        }
    }

    SharedPtr(SharedPtr && obj) {
        this->pointer = obj.pointer;
        this->ref_count = obj.ref_count;

        obj.pointer = obj.ref_count = nullptr;
    }

    SharedPtr & operator=(SharedPtr && obj) {
        _cleanup_();

        this->pointer = obj.pointer;
        this->ref_count = obj.ref_count;

        obj.pointer = obj.ref_count = nullptr;
    }

    uint counter() const {
        return *ref_count;
    }

    T * get() const {
        return this->pointer;
    }

    T * operator->() const {
        return this->pointer;
    }

    T & operator*() const {
        return this->pointer;
    }

    ~SharedPtr() {
        _cleanup_();
    }
};

#endif //SMARTPOINTER_SMARTPTRSHARED_H
