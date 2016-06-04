#ifndef AUTO_PTR_H
#define AUTO_PTR_H

template<class T>
class auto_ptr
{
    public:
        explicit auto_ptr(T *p = 0);

        template<class U>
        auto_ptr(auto_ptr<U>& rhs);

        ~auto_ptr();

        template<class U>
        auto_ptr<T>& operator=(auto_ptr<U>& rhs);

        T& operator*() const;
        T* operator->() const;

        T* get() const;

        T* release();

        void reset(T *p = 0);

    protected:
    private:
        T *pointee;
};

#endif // AUTO_PTR_H
