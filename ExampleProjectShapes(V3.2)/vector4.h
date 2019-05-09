#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <algorithm>
using namespace std;

namespace MyVector
{
    template <typename T>
    class Vector {
    public:
        Vector(): _size{0}, _capacity{0}, elem(nullptr) {}

        Vector(int size) : _size{size}, _capacity{size}, elem(new T[size])
        { //alternate constructor
            for(int i = 0; i < _size; i++)
                elem[i] = T(); // elements are initialized
        }

        Vector(const Vector<T>& RHS)  // copy constructor
        :_size(RHS._size), _capacity(RHS._capacity), elem{new T[RHS._size]}
        {
            copy(RHS.elem, RHS.elem + _size, elem); // copy elements
        }

        Vector<T>& operator=(const Vector<T>& RHS)
        {  // move constructor
            if(this != &RHS)
            {
                T *ptr = new T[RHS._size];
                copy(RHS.elem, RHS.elem + RHS._size, ptr); // copy elements

                if(elem != nullptr)
                    delete [] elem;
                elem = ptr;
                _size = RHS._size;
                _capacity = RHS._capacity;
            }
            return *this;
        }

        Vector(Vector&& RHS) : _size(0), _capacity(0), elem(nullptr)
        {
            _size     = RHS._size;
            _capacity = RHS._capacity;
            elem      = RHS.elem;

            RHS._size     = 0;
            RHS._capacity = 0;
            RHS.elem      = nullptr;
        }

        Vector& operator=(Vector&& RHS)
        {
            if(this != &RHS)
            {
                delete [] elem;

                elem = RHS.elem;
                _size = RHS._size;
                _capacity = RHS._capacity;

                RHS.elem = nullptr;
                RHS._size = 0;
                RHS._capacity = 0;
            }
            return *this;
        }

        ~Vector()
        {
            delete [] elem;
        }

        T& operator[](int num)
        { // access: return reference
            return elem[num];
        }

        const T& operator[](int num)const
        {	// access: return reference
            return elem[num];
        }

        int size() const
        { // current size
            return _size;
        }

        int capacity() const
        { // current available space
            return _capacity;
        }

        void resize(int newSize)
        { // grow
            reserve(newSize);
            for(int i = _size; i < newSize; i++) elem[i] = T();
            _size = newSize;
        }

        void push_back(const T& val)
        { // add element
            if(_capacity == 0)
                reserve(8);   // start with space for 8 elements

            else if(_size == _capacity)
                reserve(2 * _capacity); // get more space

            elem[_size] = val; // add at the end
            _size++;           // increase size by q
        }

        void reserve(const int& newAlloc)
        { // get more space

            if(newAlloc <= _capacity)
                return;

            T *ptr = new T[newAlloc];

            for(int i = 0; i < _size; i++) ptr[i] = elem[i];

            delete [] elem;
            elem = ptr;
            _capacity = newAlloc;
        }

        void clear()
        { // removes all elements from the vector
            delete [] elem;
            _size = 0;
        }

        T GetElem(int index)
        {
            return elem[index];
        }

        using iterator = T*;
        using const_iterator = const T*;

        iterator begin()
        { // points to first element
            if(_size == 0)
                return nullptr;

            return &elem[0];
        }
        const_iterator begin() const
        {
            if(_size == 0)
                return nullptr;

            return &elem[0];
        }

        iterator end()
        { // points to one beyond the last element
            if(_size == 0)
                return nullptr;

            return &elem[_size];
        }

        const_iterator end() const
        {
            if(_size == 0)
                return nullptr;

            return &elem[_size];
        }

        iterator insert(iterator p, const T& v)
        { // insert a new element v before p
            int index = p - begin();

            if(size() == capacity())
                reserve(size() == 0 ? 8: 2 * size()); //make sure we have space

            _size++;
            iterator pp = begin() + index; // the place to put the value

            for(iterator pos = end() - 1; pos != pp; pos--)
                *pos = *(pos - 1); // copy element one position to the right

            *(begin() + index) = v; // insert value

            return pp;
        }

        iterator erase(iterator p)
        { // remove element pointed to by p

            if(p == end())
                return p;

            for(iterator pos = p + 1; pos != end(); pos++)
                *(pos - 1) = *pos; // copy element one position to the left

            _size--;
            return p;
        }

    private:
        int _size;
        int _capacity;
        T*  elem;
    };
}

#endif // VECTOR_H
