#include<iostream>
using namespace std;


class A {

    int a;

};

class B:virtual public A{

    virtual void myfunB(){}

};

class C:virtual public A{

    virtual void myfunC(){}

};

class D:public B,public C{

    virtual void myfunD(){}

};

int main(void)  
{  
    cout<<"A="<<sizeof(A)<<endl;    
    cout<<"B="<<sizeof(B)<<endl;   
    cout<<"C="<<sizeof(C)<<endl;   
    cout<<"D="<<sizeof(D)<<endl;   
    return 0;  
}  
