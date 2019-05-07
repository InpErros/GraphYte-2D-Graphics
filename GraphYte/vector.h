#ifndef VECTOR_H
#define VECTOR_H

#include <algorithm> /** copy **/
using namespace std;

// Templated Vector class within namespace MyVector
namespace MyVector
{
/************************************************************************
* Templated Vector Class
* 	This class represents a vector. It manages 3 attributes:
* 		size, capacity, and elem
*************************************************************************/
    template <typename T>
    class Vector {
    public:
        /******************************
         ** CONSTRUCTOR & DESTRUCTOR **
         ******************************/

        /****************************************************************
         * Vector();
         *   Constructor; this method initializes the vectors attributes
         *   Paramteres: none
         *   Return: none
         ****************************************************************/
        Vector(): _size{0}, _capacity{0}, elem(nullptr) {}

        /****************************************************************
         * Vector(int size);
         *   Alternate Constructor; this method initializes the vector
         *                            attributes given a size
         *   Parameters: size (int) - the size of the vector
         *   Return: none
         ***************************************************************/
        Vector(int size) : _size{size}, _capacity{size}, elem(new T[size])
        {
            for(int i = 0; i < _size; i++) elem[i] = T();
        }

        /****************************************************************
         * Vector(int size);
         *   Copy Constructor; initializes the vector attributes given
         *                       another vector to copy from using
         *                       constructor implementation
         *   Parameters: RHS (const Vector<T>&) - the vector to be copied
         *                                          from
         *   Return: none
         ***************************************************************/
        Vector(const Vector<T>& RHS)
        :_size(RHS._size), _capacity(RHS._capacity), elem{new T[RHS._size]}
        {
            copy(RHS.elem, RHS.elem + _size, elem); // copy elements
        }

        /****************************************************************
         * Vector<T>& operator=(const Vector<T>& RHS);
         *   Copy Assignment; initializes the vector attributes given
         *                       another vector to copy from using
         *                       the overloaded "=" operator
         *   Parameters: RHS (const Vector<T>&) - the vector to be copied
         *                                          from
         *   Return: none
         ***************************************************************/
        Vector<T>& operator=(const Vector<T>& RHS)
        {
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

        /****************************************************************
         * Vector(Vector&& RHS);
         *   Move Constructor; initializes the vector attributes given
         *                       another vector to take from using
         *                       constructor implementation, then removes
         *                       the data of the copied vector
         *   Parameters: RHS (Vector<T>&&) - the vector to take data from
         *   Return: none
         ***************************************************************/
        Vector(Vector&& RHS) : _size(0), _capacity(0), elem(nullptr)
        {
            _size     = RHS._size;
            _capacity = RHS._capacity;
            elem      = RHS.elem;

            RHS._size     = 0;
            RHS._capacity = 0;
            RHS.elem      = nullptr;
        }

        /****************************************************************
         * Vector& operator=(Vector&& RHS);
         *   Move Constructor; initializes the vector attributes given
         *                       another vector to take from using
         *                       the overloaded "=" operator, then removes
         *                       the data of the copied vector
         *   Parameters: RHS (Vector&&) - the vector to take data from
         *   Return: none
         ***************************************************************/
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

        /****************************************************************
         * ~Vector ();
         *   Deconstructor; removes the vector array (frees memory)
         *   Parameters: none
         *   Return: none
         ***************************************************************/
        ~Vector(){delete [] elem;}

        /*******************
         **** MUTATORS  ****
         *******************/

        // Iterators
        using iterator       = T*;
        using const_iterator = const T*;

        /****************************************************************
         * T& operator[](const int& NUM);
         *   Mutator; returns the element of the vector equal to the
         *            number that was passed in to the method
         *   Parameters: NUM (const int&) - the number pertaining to the
         *                                  element in the array
         *   Return: the element of the vector
         ***************************************************************/
        T& operator[](const int& NUM) {return elem[NUM];}

        /****************************************************************
         * void resize(const int& NEW_SIZE);
         *   Mutator; creates a new size of the vector and initializes
         *             each element
         *   Parameters: NEW_SIZE (const int&) - the number pertaining to
         *                                       the new size of the vector
         *   Return: none
         ***************************************************************/
        void resize(const int& NEW_SIZE)
        {
            reserve(NEW_SIZE);
            for(int i = _size; i < NEW_SIZE; i++) elem[i] = T();
            _size = NEW_SIZE;
        }

        /****************************************************************
         * void push_back(const T& val);
         *   Mutator; adds a new element of new values to the end of
         *             the vector
         *   Parameters: val (const T&) - the data pertaining to the
         *                                  new element in the array
         *   Return: none
         ***************************************************************/
        void push_back(const T& val)
        {
             // start with space for 8 elements
            if(_capacity == 0){reserve(8);}

            // get more space
            else if(_size == _capacity){reserve(2 * _capacity);}

            elem[_size] = val; // add at the end
            _size++;           // increase size by q
        }

        /****************************************************************
         * void reserve(const int& NEW_ALLOC);
         *   Mutator; creates a vector with a bigger size and initializes
         *             the vector
         *   Parameters: NEW_ALLOC (const int&) - the new size of the
         *                                        vector
         *   Return: none
         ***************************************************************/
        void reserve(const int& NEW_ALLOC)
        {
            if(NEW_ALLOC <= _capacity){return;}

            T *ptr = new T[NEW_ALLOC];

            for(int i = 0; i < _size; i++) ptr[i] = elem[i];

            delete [] elem;
            elem      = ptr;
            _capacity = NEW_ALLOC;
        }

        /****************************************************************
         * void clear();
         *   Mutator; deletes all of the elements in the vector
         *   Parameters: none
         *   Return: none
         ***************************************************************/
        void clear()
        {
            delete [] elem;
            _size = 0;
        }

        /****************************************************************
         * T GetElem(const int& INDEX);
         *   Mutator; returns the element in the vector based on the
         *            index passed in to the method
         *   Parameters: INDEX (const int&) - the index of the vector
         *   Return: the element of the vector
         ***************************************************************/
        T GetElem(const int& INDEX) {return elem[INDEX];}

        /****************************************************************
         * iterator begin();
         *   Mutator; returns the element at the front of the vector
         *   Parameters: none
         *   Return: element at the front of the vector
         ***************************************************************/
        iterator begin()
        {
            if(_size == 0){return nullptr;}

            return &elem[0];
        }

        /****************************************************************
         * iterator end();
         *   Mutator; returns the element at the end of the vector
         *   Parameters: none
         *   Return: element at the end of the vector
         ***************************************************************/
        iterator end()
        {
            if(_size == 0){return nullptr;}

            return &elem[_size];
        }

        /****************************************************************
         * iterator insert(iterator p, const T& v);
         *   Mutator; inserts a new element of new values into the vector
         *             before the element passed in
         *   Parameters: p (iterator) - pointer of the element to place
         *                              the new element in front of
         *               v (const T&) - values of the new element
         *   Return: the place where the value was inserted
         ***************************************************************/
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

        /****************************************************************
         * iterator erase(iterator p);
         *   Mutator; removes the element pointed to by the pointer
         *            passed in to the method
         *   Parameters: p (iterator) - pointer referring to the element
         *                              to remove from the vector
         *   Return: the element that was removed
         ***************************************************************/
        iterator erase(iterator p)
        { // remove element pointed to by p

            if(p == end()){return p;}

            // copy element one position to the left
            for(iterator pos = p + 1; pos != end(); pos++){*(pos - 1) = *pos;}

            _size--;

            return p;
        }

        /*******************
         **** ACCESSORS ****
         *******************/

        /****************************************************************
         * const T& operator[](const int& NUM) const;
         *   Accessor; returns the element of the vector equal to the
         *            number that was passed in to the method
         *   Parameters: NUM (const int&) - the number pertaining to the
         *                                  element in the array
         *   Return: the element of the vector
         ***************************************************************/
        const T& operator[](const int& NUM)const {return elem[NUM];}

        /****************************************************************
         * int size() const;
         *   Accessor; returns the size of the vector
         *   Parameters: none
         *   Return: size
         ***************************************************************/
        int size() const{return _size;}

        /****************************************************************
         * int capacity() const;
         *   Accessor; returns the capacity of the vector
         *   Parameters: none
         *   Return: capacity
         ***************************************************************/
        int capacity() const{return _capacity;}

        /****************************************************************
         * const_iterator begin() const;
         *   Accessor; returns the element at the front of the vector
         *   Parameters: none
         *   Return: element at the front of the vector
         ***************************************************************/
        const_iterator begin() const
        {
            if(_size == 0){return nullptr;}

            return &elem[0];
        }

        /****************************************************************
         * const_iterator end() const;
         *   Mutator; returns the element at the end of the vector
         *   Parameters: none
         *   Return: element at the end of the vector
         ***************************************************************/
        const_iterator end() const
        {
            if(_size == 0){return nullptr;}

            return &elem[_size];
        }

    private:
        int _size;      //The size of the vector
        int _capacity;  //The capacity of the vector
        T*  elem;       //The element in the vector
    };
}

#endif // VECTOR_H
