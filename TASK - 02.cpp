/*                    TASK 2
                SIMPLE CALCULATOR
Develop a calculator program that performs basic arithmetic
operations such as addition, subtraction, multiplication, and
division. Allow the user to input two numbers and choose an
operation to perform.*/

#include<iostream>
#include<cstdlib>
using namespace std ;

inline void Division (int x, int y)
{
    if (y != 0)
        cout<<"\n"<<x<<" / "<<y<<" = "<<x/(y*1.0)<<endl ;
    else
        cout<<"\nError : Division by Zero" ;
}

int main ()
{
    cout<<"*******************"<<endl ;
    cout<<"1. Addition"<<endl ;
    cout<<"2. Subtraction"<<endl ;
    cout<<"3. Multiplication"<<endl ;
    cout<<"4. Division"<<endl ;
    cout<<"0. Exit"<<endl ;
    cout<<"*******************\n";

    int x , a, b ;
    while (1)
    {
        cout<<"\nEnter your choice : " ;
        cin>>x ;
        switch (x)
        {
            case 1:
                cout<<"\nPlease enter two numbers to perform Addition : ";
                cin>>a>>b ;
                cout<<"\n"<<a<<" + "<<b<<" = "<<a+b<<endl ;
                break ;
            case 2:
                cout<<"\nPlease enter two numbers to perform Subtraction : ";
                cin>>a>>b ;
                cout<<"\n"<<a<<" - "<<b<<" = "<<a-b<<endl ;
                break ;
            case 3:
                cout<<"\nPlease enter two numbers to perform Multiplication : ";
                cin>>a>>b ;
                cout<<"\n"<<a<<" * "<<b<<" = "<<a*b<<endl ;
                break ;
            case 4:
                cout<<"\nPlease enter Numerator and Denominator to perform Division : ";
                cin>>a>>b ;
                Division(a,b) ;
                break ;
            case 0:
                exit(0) ;
            default :
                cout<<"\nInvalid Choice :("<<endl ;
        }
    }
    return 0 ;
}
