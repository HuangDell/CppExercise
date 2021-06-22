 #include <memory>
#include <iostream>
#ifndef __TEST_H__
#define __TEST_H__
 class testAllocator : public std::allocator<int> {
    public:
        typedef std::allocator<int> Base;
        int * allocate(std::size_t size) {
            std::cout << "Test Allocator: allocate" << std::endl;
            return Base::allocate(size);
        }
        void deallocate(int * p, std::size_t size) {
            std::cout << "Test Allocator: deallocate" << std::endl;
            Base::deallocate(p, size);
        }
        void construct(int * p, int val) {
            std::cout << "Test Allocator: Construct, value: " << val
                      << std::endl;
            Base::construct(p, val);
        }
        void destroy(int * p) {
            std::cout << "Test Allocator: Destroy, value: " << *p << std::endl;
            Base::destroy(p);
        }
};
 #endif
 
 #ifndef __BASE_H__
#define __BASE_H__
 #define vector NOT_ALLOWED
#define define NOT_ALLOWED
 class Base {};
 #endif
using namespace std;
 template <typename T, typename Alloc = std::allocator<T>>
 class myVector : public Base
 {
 private:
     T *_data;
     std::size_t _size, _capacity;

 public:
     // Constructor
     myVector(Alloc a=Alloc()):_data(NULL),_size(0),_capacity(0)
     {
         _data=a.allocate(0);
     }

     myVector(const std::size_t &size, const T &val,Alloc a = Alloc()):_size(size),_capacity(size)
     {
         _data=a.allocate(size);
         for(int i=0;i<size;i++)
            a.construct(_data+i,val);
     }
     template <typename InputIterator>
     myVector(InputIterator begin, InputIterator end,Alloc a = Alloc())
     {
         
         auto size=end-begin;
         _data=a.allocate(size);
         _size=size;
         _capacity=size;
         for(int i=0;i<size;i++)
            a.construct(_data+i,*begin++);
     }
     myVector(const myVector &other):_size(other._size),_capacity(other._capacity)
     {
         Alloc a;
         _data=a.allocate(_capacity);
         for(int i=0;i<_size;i++)
            a.construct(_data+i,other._data[i]);
     }
     ~myVector()
     {
         if (_data)
         {
             Alloc a;
             for (int i = 0; i < _size; i++)
                 a.destroy(_data + i);
             _size = 0;
             a.deallocate(_data,_capacity);
         }
     }
     // Copy Operator
     myVector &operator=(const myVector &other)
     {
         if(this==&other)
            return *this;
         Alloc a;
         clear();
         a.deallocate(_data,_capacity);
         _size=other._size;
         _capacity=other._capacity;
         _data=a.allocate(_capacity);
         for(int i=0;i<_size;i++)
            a.construct(_data+i,other._data[i]);
        return *this;
     }

     // Iterator
     typedef T *iterator;
     typedef const T *const_iterator;
     inline iterator begin(){return _data;}
     inline const_iterator begin() const{return _data;}
     inline iterator end(){return _data+_size;}
     inline const_iterator end() const{return _data+_size;}
     // Capacity
     inline std::size_t size() { return _size; }
     void resize(const std::size_t &newSize) 
     {
         resize(newSize,T());
     }
     void resize(const std::size_t &newSize, const T &val)
     {
         Alloc a;
         if(newSize<_size)
         {
             for(int i=newSize;i<_size;i++)
                a.destroy(_data+i);
         }
         else
         {
             auto *new_data = a.allocate(_capacity);
             for(int i=0;i<_size;i++)
             {
                a.construct(new_data+i,_data[i]);
                a.destroy(_data+i);
             }
             a.deallocate(_data,_capacity);
             for (int i = _size; i < newSize; i++)
                a.construct(new_data+i,val);
             _data = new_data;
         }
        _size=newSize;
     }
     inline std::size_t capacity() const
     {
         return _capacity;
     }
     inline bool empty() const
     {
         return _size==0;
     }
     void reserve(const std::size_t &newCapacity)
     {
         if(newCapacity<_capacity)
         return;
         Alloc a;
         auto *new_data = a.allocate(newCapacity);
         for (int i = 0; i < _size; i++)
         {
             a.construct(new_data + i, _data[i]);
             a.destroy(_data + i);
         }
         a.deallocate(_data, _capacity);
         _data = new_data;
         _capacity=newCapacity;
     }
     // Element Access
     inline T &operator[](const std::size_t &index)
     {return _data[index];}
     inline const T &operator[](const std::size_t &index) const
     {return _data[index];}
     inline T &front()
     {return _data[0];}
     inline const T &front() const
     {return _data[0];}
     inline T &back()
     {return _data[_size-1];}
     inline const T &back() const
     {return _data[_size-1];}
     inline T *data()
     {return _data;}
     inline const T *data() const
     {return _data;}
     // Modifiers
     template <typename InputIterator>
     void assign(InputIterator begin, InputIterator end)
     {
         Alloc a;
         auto size=end-begin;
         for(int i=0;i<size;i++)
            a.construct(_data+i,*begin++);
        _size=size;
     }
     void assign(const std::size_t &newSize, const T &val)
     {
         Alloc a;
         resize(newSize);
         for(int i=0;i<_size;i++)
            a.construct(_data+i,val);
     }
     void push_back(const T &val)
     {
         if(_size==_capacity)
            reserve(2*_size);
         _data[_size++]=val;
     }
     void pop_back()
     {
         Alloc a;
         a.destroy(_data+_size-1);
         _size--;
     }
     void clear()
     {
         if (_data)
         {
             Alloc a;
             for (int i = 0; i < _size; i++)
                 a.destroy(_data+i);
             _size=0;
         }
     }


 };


 int main() {
    typedef myVector<int, testAllocator> v;
    Base * test = new v;
    delete static_cast<v *>(test);
    v * p1, * p2;
    int t;
     std::cout << "Test Constructor1:" << std::endl;
    p1 = new v;
    std::cout << "Size: " << p1->size() << std::endl;
    delete p1;
     std::cout << "Test Constructor2 and operator[]:" << std::endl;
    p1 = new v(static_cast<std::size_t>(6), 6);
    std::cout << "Size: " << p1->size() << std::endl;
    std::cout << "Content:";
    for (int i = 0; i < 2; ++i)
        std::cout << ' ' << (*p1)[i];
    std::cout << std::endl;
    std::cin >> t;
    std::cout << "Content after change:";
    (*p1)[0] = t;
    const v & r(*p1);
    for (int i = 0; i < 2; ++i)
        std::cout << ' ' << r[i];
    std::cout << std::endl;
     std::cout << "Test Constructor3 and iterators, including begin(), end():"
              << std::endl;
    p2 = new v(r.begin(), r.end());
    delete p1;
    std::cout << "Content:";
    for (v::iterator it = p2->begin(); it != p2->end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl;
     std::cout << "Test Constructor4:" << std::endl;
    *(p2->begin()) = 0;
    p1 = new v(*p2);
    delete p2;
    std::cout << "Content:";
    for (std::size_t i = 0; i < p1->size(); ++i)
        std::cout << ' ' << (*p1)[i];
    std::cout << std::endl;
     std::cout << "Test operator=:" << std::endl;
    p2 = new v(static_cast<std::size_t>(8), 8);
    *p2 = *p1;
    *p2 = *p2;
    delete p1;
    std::cout << "Content:";
    for (std::size_t i = 0; i < p2->size(); ++i)
        std::cout << ' ' << (*p2)[i];
    std::cout << std::endl;
     std::cout << "Test resize1:" << std::endl;
    p2->resize(2);
    std::cout << "Content:";
    for (std::size_t i = 0; i < p2->size(); ++i)
        std::cout << ' ' << (*p2)[i];
    std::cout << std::endl;
     std::cout << "Test resize2:" << std::endl;
    p2->resize(8, 8);
    std::cout << "Content:";
    for (std::size_t i = 0; i < p2->size(); ++i)
        std::cout << ' ' << (*p2)[i];
    std::cout << std::endl;
     std::cout << "Test reserve and capacity:" << std::endl;
    p2->reserve(33);
    std::cout << "Capacity: " << p2->capacity() << std::endl
              << "Size: " << p2->size() << std::endl;
    p2->reserve(2);
    std::cout << "Capacity: " << p2->capacity() << std::endl
              << "Size: " << p2->size() << std::endl;
     std::cout << "Test clear and empty:" << std::endl;
    if (p2->empty())
        std::cout << "True" << std::endl;
    else
        std::cout << "False" << std::endl;
    p2->clear();
    if (p2->empty())
        std::cout << "True" << std::endl;
    else
        std::cout << "False" << std::endl;
    std::cout << "Capcaity: " << p2->capacity() << std::endl
              << "Size: " << p2->size() << std::endl;
     int * arr = new int[5];
    for (int i = 0; i < 5; ++i)
        arr[i] = i+1;
    std::cout << "Test assign:" << std::endl;
    p2->assign(arr, arr+5);
    std::cout << "Content:";
    for (v::const_iterator it = p2->begin(); it != p2->end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl << "Size: " << p2->size()
              << std::endl << "Capacity: " << p2->capacity()
              << std::endl;
     delete [] arr;
    delete p2;
    return 0;
}
 