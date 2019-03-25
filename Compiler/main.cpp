#include <iostream>
#include "NFAToDFAEngine.h"


void add(int *n) {
    *n=10;
}

int main() {
    NFAToDFA nfaToDFA;
    nfaToDFA.engine();
//    int i = 9;
//     int *ptr;
//    ptr = &i;
//    // cout << add(ptr) << endl;/*the same as cout<<add(&i)<<endl;*/
//    add(ptr);
//    add(&i);
//     cout<<*ptr<<endl;
//    cout << i << endl;
//    //cout << &i << endl;
//    //cout << *ptr << endl;
//    //cout << *&i << endl;
    return 0;
}