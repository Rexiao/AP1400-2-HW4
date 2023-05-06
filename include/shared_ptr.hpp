
template <class T>
SharedPtr<T>::SharedPtr() : _p{nullptr}, _count_ptr{nullptr} {}

template <class T>
SharedPtr<T>::SharedPtr(T* p) : _p{p}, _count_ptr{new long(1)} {}

template <class T>
void clear(T*& _p, long*& _count_ptr) {
    if (!_p) {
        return;
    }
    if (--(*_count_ptr) == 0) {
        delete _p;
        delete _count_ptr;
    }
    _p = nullptr;
    _count_ptr = nullptr;
}

template <class T>
SharedPtr<T>::~SharedPtr() {
    clear(_p, _count_ptr);
}

template <class T, class... Args>
SharedPtr<T> make_shared(Args&&... args) {
    return SharedPtr<T>(new T(args...));
}

template <class T>
SharedPtr<T>::SharedPtr(const SharedPtr& other) : _p(other._p), _count_ptr(other._count_ptr) {
    *_count_ptr += 1;
}

template <class T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T>& other) {
    if (this == &other) {
        return *this;
    }
    if (_p == other._p) {
        return *this;
    }
    clear(_p, _count_ptr);
    _p = other._p;
    _count_ptr = other._count_ptr;
    ++*_count_ptr;
}

template <class T>
long SharedPtr<T>::use_count() {
    if (!_count_ptr) {
        return 0;
    }
    return *_count_ptr;
}

template <class T>
T* SharedPtr<T>::get() {
    return _p;
}

template <class T>
T& SharedPtr<T>::operator*() {
    return *_p;
}

template <class T>
T* SharedPtr<T>::operator->() {
    return _p;
}

template <class T>
void SharedPtr<T>::reset() {
    clear(_p, _count_ptr);
}

template <class T>
void SharedPtr<T>::reset(T* ptr) {
    clear(_p, _count_ptr);
    _p = ptr;
    _count_ptr = new long(1);
}

template <class T>
SharedPtr<T>::operator bool() const {
    return _p != nullptr;
}