#include "auto_ptr.h"

template<class T>
inline auto_ptr<T>::auto_ptr(T *p):pointee(p)
{
    //ctor
}

template<class T>
template<class U>
inline auto_ptr<T>::auto_ptr(auto_ptr<U>& rhs):pointee(rhs.release()){}

template<class T>
inline auto_ptr<T>::~auto_ptr()
{
    delete pointee;
}

template<class T>
template<class U>
inline auto_ptr<T>& auto_ptr<T>::operator=(auto_ptr<U>& rhs)
{
    if(this != &rhs)
        reset(rhs.release());
    return *this;
}

template<class T>
inline T& auto_ptr<T>::operator*() const
{
    return *pointee;
}

template<class T>
inline T* auto_ptr<T>::operator->() const
{
    return pointee;
}

template<class T>
inline T* auto_ptr<T>::get() const
{
    return pointee;
}

template<class T>
inline T* auto_ptr<T>::release()
{
    T *oldPointee = pointee;
    pointee = 0;
    return oldPointee;
}

template<class T>
inline void auto_ptr<T>::reset(T *p)
{
    if(pointee != p)
    {
        delete pointee;
        pointee = p;
    }
}
