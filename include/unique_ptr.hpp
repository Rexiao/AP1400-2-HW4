
template <class T>
UniquePtr<T>::UniquePtr() : _p{nullptr} {}

template <class T>
UniquePtr<T>::UniquePtr(T* p) : _p{p} {}

template <class T>
UniquePtr<T>::~UniquePtr() {
    delete _p;
    _p = nullptr;
}

template <class T, class... Args>
UniquePtr<T> make_unique(Args&&... args) {
    return UniquePtr<T>(new T(args...));
}

template <class T>
T* UniquePtr<T>::get() {
    return _p;
}

template <class T>
T& UniquePtr<T>::operator*() {
    return *_p;
}

template <class T>
T* UniquePtr<T>::operator->() {
    return _p;
}

template <class T>
void UniquePtr<T>::reset() {
    delete _p;
    _p = nullptr;
}

template <class T>
void UniquePtr<T>::reset(T* ptr) {
    delete _p;
    _p = ptr;
}

template <class T>
T* UniquePtr<T>::release() {
    T* ret = _p;
    _p = nullptr;
    return ret;
}

template <class T>
UniquePtr<T>::operator bool() const {
    return _p != nullptr;
}