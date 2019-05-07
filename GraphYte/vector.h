#ifndef VECTOR_H
#define VECTOR_H

#include <algorithm> /** copy **/
using namespace std;

namespace MyVector
{
    //Templated vector
    template <typename T>
    class Vector {
    public:
        //Constructor
        Vector(): _size{0}, _capacity{0}, elem(nullptr) {}

        //alternate constructor
        Vector(int size) : _size{size}, _capacity{size}, elem(new T[size])
        {
            for(int i = 0; i < _size; i++) elem[i] = T();
        }

        // copy constructor
        Vector(const Vector<T>& RHS)  // copy constructor
        :_size(RHS._size), _capacity(RHS._capacity), elem{new T[RHS._size]}
        {
            copy(RHS.elem, RHS.elem + _size, elem); // copy elements
        }

        // Copy Assignment
        Vector<T>& operator=(const Vector<T>& RHS)
        {  // move constructor
            if(this != &RHS)
            {
                T *ptr = new T[RHS._size];
                copy(RHS.elem, RHS.elem + RHS._size, ptr); // copy elements

                if(elem != nullptr){delete [] elem;}

                elem      = ptr;
                _size     = RHS._size;
                _capacity = RHS._capacity;
            }
            return *this;
        }

        // move constructor
        Vector(Vector&& RHS) : _size(0), _capacity(0), elem(nullptr)
        {
            _size     = RHS._size;
            _capacity = RHS._capacity;
            elem      = RHS.elem;

            RHS._size     = 0;
            RHS._capacity = 0;
            RHS.elem      = nullptr;
        }

        // Move Assignment
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

        //Deconstructor
        ~Vector(){delete [] elem;}

        // access: return reference
        T& operator[](const int& NUM){return elem[NUM];}

        // const access: return reference
        const T& operator[](const int& NUM)const{return elem[NUM];}

        // current size
        int size() const{return _size;}

        // current available space
        int capacity() const{return _capacity;}

        // grow
        void resize(const int& NEW_SIZE)
        {
            reserve(NEW_SIZE);
            for(int i = _size; i < NEW_SIZE; i++) elem[i] = T();
            _size = NEW_SIZE;
        }

        // add element
        void push_back(const T& val)
        {
             // start with space for 8 elements
            if(_capacity == 0){reserve(8);}

            // get more space
            else if(_size == _capacity){reserve(2 * _capacity);}

            elem[_size] = val; // add at the end
            _size++;           // increase size by q
        }

        // get more space
        void reserve(const int& NEW_ALLOC)
        {
            if(NEW_ALLOC <= _capacity){return;}

            T *ptr = new T[NEW_ALLOC];

            for(int i = 0; i < _size; i++) ptr[i] = elem[i];

            delete [] elem;
            elem      = ptr;
            _capacity = NEW_ALLOC;
        }

        // removes all elements from the vector
        void clear()
        {
            delete [] elem;
            _size = 0;
        }

        //Get the element from the list
        T GetElem(const int& INDEX){return elem[INDEX];}

        using iterator       = T*;
        using const_iterator = const T*;

        // points to first element
        iterator begin()
        {
            if(_size == 0){return nullptr;}

            return &elem[0];
        }

        // points to first element
        const_iterator begin() const
        {
            if(_size == 0){return nullptr;}

            return &elem[0];
        }

        // points to one beyond the last element
        iterator end()
        {
            if(_size == 0){return nullptr;}

            return &elem[_size];
        }

        // points to one beyond the last element
        const_iterator end() const
        {
            if(_size == 0){return nullptr;}

            return &elem[_size];
        }

        // insert a new element v before p
        iterator insert(iterator p, const T& v)
        {
            int index = p - begin();

            //make sure we have space
            if(size() == capacity()){reserve(size() == 0 ? 8: 2 * size());}

            _size++;

            // the place to put the value
            iterator pp = begin() + index;

            // copy element one position to the right
            for(iterator pos = end() - 1; pos != pp; pos--){*pos = *(pos - 1);}

            // insert value
            *(begin() + index) = v;

            return pp;
        }

        // remove element pointed to by p
        iterator erase(iterator p)
        { // remove element pointed to by p

            if(p == end()){return p;}

            // copy element one position to the left
            for(iterator pos = p + 1; pos != end(); pos++){*(pos - 1) = *pos;}

            _size--;

            return p;
        }

    private:
        int _size;      //The size of the vector
        int _capacity;  //The capacity of the vector
        T*  elem;       //The element in the vector
    };
}

#endif // VECTOR_H
