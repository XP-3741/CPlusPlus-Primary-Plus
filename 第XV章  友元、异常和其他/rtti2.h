#pragma once
// rtti2.cpp  -- using dynamic_cast, typeid, and type_info
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<typeinfo>
#include"rtti1.h"   // for Grand,Superb,Magnificent,GetOne()
using namespace std;

void rtti2_main()
{
    srand(time(0));
    Grand* pg;
    Superb* ps;
    for (int i = 0; i < 5; i++)
    {
        pg = GetOne();
        cout << "Now processing type " << typeid(*pg).name() << ".\n";
        pg->Speak();
        if (ps = dynamic_cast<Superb*>(pg))
            ps->Say();
        if(typeid(Magnificent)==typeid(*pg))
            cout << "Yes, you're really magnificent.\n";
        cout << endl;
    }
}
