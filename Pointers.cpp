#include <iostream>
#include <memory> //library for smart pointers

/*
types of smart pointers:
auto_ptr
unique_ptr
shared_ptr
weak_ptr
*/


template <typename T>
class SmartPointer
{
public:
    SmartPointer(T *ptr)
    {
        this->ptr = ptr;
        std::cout << "constructor" << std::endl;
    }

    ~SmartPointer()
    {
        delete ptr;
        std::cout << "destructor" << std::endl;
    }

    T& operator*()
    {
        return *ptr;
    }

private:
    T* ptr;
};

class MyClass
{
public:
    MyClass()
    {
        std::cout<<"Constructor invoked"<<std::endl;
    }
    ~MyClass()
    {
        std::cout<<"Destructor invoked" << std::endl;
    }
};

int main()
{

/*
    int* ptr = new int(5);
    delete ptr;
*/


/*
    SmartPointer<int> pointer = new int(5);
    *pointer = 1553;
    std::cout << *pointer << std::endl;
*/

/*
    //problem with smart pointers
    SmartPointer<int> sp1 = new int(5);
    SmartPointer<int> sp2 = sp1;
    // Error
*/

/*
    // auto_ptr
    std::auto_ptr<int>ap1(new int(5));
    std::auto_ptr<int>ap2(ap1);

    // There is data in ap2
    std::cout << *ap2;
*/

/*
    std::cout << *ap1;
    // Error
*/

/*
    //unique_ptr
    std::unique_ptr<int>p1(new int(5));
    std::unique_ptr<int>p2(p1);
    // Error
*/

/*
    int* raw1 = new int(5);
    std::unique_ptr<int>uPtr(raw1);
    std::unique_ptr<int>uPtr2;
    uPtr2 = uPtr;
    //Error
*/


/*
    //function move
    std::unique_ptr<int>p1(new int(5));
    std::unique_ptr<int>p2;
    p2 = move(p1);
    std::cout << *p2;
*/


    /*
    //shared_ptr
    std::shared_ptr<MyClass>shPtr1 = std::make_shared<MyClass>();
    std::cout << "Shared count: " << shPtr1.use_count() << std::endl;
    //use_count() - number of pointers for one object
    {
        std::shared_ptr<MyClass>shPtr2 = shPtr1;
        std::cout << "Shared count: " << shPtr1.use_count() << std::endl;
    }
    std::cout << "Shared count: " << shPtr1.use_count() << std::endl;
    */
    /*
    int SIZE = 5;
    std::shared_ptr<int[]> ptr(new int[SIZE]);
    for (int i=0; i<SIZE; i++)
    {
        ptr[i] = rand() % 10;
        std::cout<<ptr[i]<<std::endl;
    }
    */

    //weak_ptr
    std::cout << std::endl << "WEAK POINTERS" << std::endl;

    std::shared_ptr<int> sptr = std::make_shared<int>(10);
    std::weak_ptr<int> weak1 = sptr;

    sptr.reset(new int);
    *sptr = 5;

    std::weak_ptr<int> weak2 = sptr;

    // weak1 is expired!
    if(auto tmp = weak1.lock())
        std::cout << *tmp << '\n';
    else
        std::cout << "weak1 is expired\n";

    // weak2 points to new data (5)
    if(auto tmp = weak2.lock())
        std::cout << *tmp << '\n';
    else
        std::cout << "weak2 is expired\n";


}
