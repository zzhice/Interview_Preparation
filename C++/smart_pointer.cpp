// #include<iostream>
// using namespace std;

// // A smart pointer is a warpper class over a pointer with an operator like * and -< overloaded.
// template <class T>
// class SmartPtr
// {
// private:
//     T* ptr;
// public:
//     explicit SmartPtr(T* p = NULL){ ptr = p;}
//     ~SmartPtr(){delete (ptr);}
//     T& operator*(){ return *ptr;}
//     T* operator->(){ return ptr;}
// };

// int main()
// {
//     SmartPtr<int> ptr(new int());
//     *ptr = 20;
//     cout << *ptr;
//     return 0;
// }


// unique_ptr: if one object is created and pointer P1 is pointing to this one then others cannot point this one at the same time.
// we cannot share with another pointer, but we can transfer control to P2 by removing P1.
#include <iostream>
using namespace std;
#include <memory>

class Rectangle
{
private:
    int width;
    int height;
public:
    Rectangle(int w, int h)
    {
        width = w;
        height = h;
    }
    int area()
    {
        return width*height;
    }
};

// int main()
// {
//     unique_ptr<Rectangle> P1(new Rectangle(10, 5));
//     cout << P1->area() << endl;
//     // unique_ptr<Rectangle> P3(P1);

//     unique_ptr<Rectangle> P2;
//     P2 = move(P1);
//     cout << P2->area() << endl;
//     // cout << P1->area() << endl;

//     return 0;
// }


// shared_ptr: if you're using shared_ptr then more than one pointer can pointer to this one
// object at a time and it'll maintain a reference counter using use_count()

// int main()
// {
//     shared_ptr<Rectangle> P1(new Rectangle(10, 5));
//     cout << P1->area() << endl;
//     shared_ptr<Rectangle> P2;
//     P2 = P1;

//     cout << P2->area() << endl;

//     cout << P1->area() << endl;

//     cout << P1.use_count() << endl;
//     return 0;
// }


// weak_ptr: similar to shared_ptr except it'll not maintain a reference counter.
 