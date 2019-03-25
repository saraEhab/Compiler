#include <iostream>
#include "NFAToDFAEngine.h"

int n;
//int add(int *n) {
//    *n=10;
//    return *n;
//}

void setn(int *k){
    n=*k;
}

int getn(){
    return n;
}

int main() {
    NFAToDFA nfaToDFA;
    nfaToDFA.engine();
    Node dfaRoot;
    dfaRoot=(nfaToDFA.dfa.getDFARoot());
    cout<<"we get it :D"<<endl;

    ///////////////////////////////////
int p=9;
setn(&p);
int h=getn();
cout<<h<<endl;


//    int i = 9;
//     int *ptr;
//    ptr = &i;
//    // cout << add(ptr) << endl;/*the same as cout<<add(&i)<<endl;*/
//    int j;
//    j=add(ptr);
//    cout<<j<<endl;
//    add(&i);
//     cout<<*ptr<<endl;
//    cout << i << endl;
//    //cout << &i << endl;
//    //cout << *ptr << endl;
//    //cout << *&i << endl;
    return 0;
}