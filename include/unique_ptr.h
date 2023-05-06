#ifndef UNIQUE_PTR
#define UNIQUE_PTR

template <class T>
class UniquePtr {
   public:
    UniquePtr(T* p);
    UniquePtr();
    ~UniquePtr();
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;
    T* get();
    T& operator*();
    T* operator->();
    void reset();
    void reset(T* ptr);
    T* release();
    operator bool() const;

   private:
    T* _p;
};

template <class T, class... Args>
UniquePtr<T> make_unique(Args&&... args);

#include "unique_ptr.hpp"
#endif  // UNIQUE_PTR