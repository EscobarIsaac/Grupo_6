#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include<iostream>
using namespace std;
template<class P>
class Pascal{
public:
    factorial(P);
    P factorial();
    combination(P,P);
    P combination();
    triangulo_Pascal();

};
template<class P>
Pascal<P>::factorial(P n)
{
    if(n<2)
        return 1;
    else
        return n * factorial(n-1);
}
template<class P>
Pascal<P>::combination(P n, P r)
{
    if(r==1)
        return n;
    else
    {
        if(n==r)
            return 1;
        else
            return factorial(n) / (factorial(r) * factorial(n - r));
    }
}



#endif
