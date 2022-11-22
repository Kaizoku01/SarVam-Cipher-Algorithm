#include <bits/stdc++.h>
#include "SarVam_Cipher.h"
using namespace std;

int main(){

    SarVamCipher obj;
    string x = obj.SarVamEncrypt("You are awesome");
    cout<<x<<endl;

    string y = obj.SarVamDecrypt(x);
    cout<<y;


    return 0;
}