#ifndef SHARED_PTR
#define SHARED_PTR

#include <iostream>
template <class T>
class SharedPtr {
   public:
    SharedPtr(T* ptr);
    SharedPtr();
    ~SharedPtr();
    SharedPtr(const SharedPtr&);
    SharedPtr& operator=(const SharedPtr&);
    long use_count();
    T* get();
    T& operator*();
    T* operator->();
    void reset();
    void reset(T* ptr);
    operator bool() const;

    template <class A>
    friend std::ostream& operator<<(std::ostream& os, const SharedPtr<A>& obj);

   private:
    T* _p;
    long* _count_ptr;
};

template <class T, class... Args>
SharedPtr<T> make_shared(Args&&... args);

template <class T>
std::ostream& operator<<(std::ostream& os, const SharedPtr<T>& obj) {
    std::cout << obj._p << ' ' << obj._count_ptr << ' ';
    if (obj._count_ptr) {
        std::cout << *obj._count_ptr << ' ';
    }
    std::cout << std::endl;
}

#include "shared_ptr.hpp"
#endif  // SHARED_PTR