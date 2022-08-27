#ifndef SMARTPOINTER_SMARTPTRUNIQUE_H
#define SMARTPOINTER_SMARTPTRUNIQUE_H

#include "SmartPtrBase.h"

template <typename T>
class UniquePtr : public SmartPtr<T> {
private:
    bool is_used = false;
public:
    UniquePtr(T * ptr) : SmartPtr<T>(ptr) {
        if(is_used == true) {
            std::cerr << "Cannot point to more than one object/variable" << std::endl;
            std::exit(EXIT_FAILURE);
        }
        else {
            is_used = true;
        }
    }
    UniquePtr(const UniquePtr &) = delete;
    UniquePtr &operator=(const UniquePtr &) = delete;
};

#endif //SMARTPOINTER_SMARTPTRUNIQUE_H
