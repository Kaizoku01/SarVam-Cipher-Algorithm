#include <bits/stdc++.h>
using namespace std;

class SarVamCipherOperations{
private:
    //data members
    string plainText;
    string cipherText;
    string reGenText = "";
    int keyArr[5] = {2,3,5,7,11};
    vector<pair<int, int>> matchinTable;

    //operational Functions
    long int encryptOperation(int ascii){
    int keyArr[5] = {2,3,5,7,11};
    long int temp = ascii;
    for (int i = 0; i < 5; i++) temp = temp * keyArr[i];
    return temp;
    }

    char decryptOperation(string cipher){
    int temp = stoi(cipher);
        for (int i = 4; i >= 0; i--) temp = temp / keyArr[i];
    return (char)temp;
    }

public:
    //encrypt fn
    string encrypt(){
        string newAsciiStr = "";
        for (int i = 0; i < plainText.length(); i++){
            int ascii = plainText[i];

            long int newAsciiInt = encryptOperation(ascii);

            newAsciiStr = to_string(newAsciiInt);

            matchinTable.push_back(make_pair(newAsciiStr.length(), i));

            cipherText = cipherText + (newAsciiStr + to_string(i+11));
        }
        return cipherText;
    }

    //decrypt fn
    string decrypt(){
        int y = 0;
        int w  = 0;
        int k = 0;
        for(auto it: matchinTable){
            k = k + 2;
            int codeLength = it.first;
            string temp = "";
            for(int i = y; i < y + codeLength; i++){
                temp = temp + cipherText[i];
                w++;
            }
            //cout<<"Temp : "<<temp;
            char de = decryptOperation(temp);
            reGenText = reGenText + de;
        
            y = w + k;

        }
        return reGenText;
    }

    void plainTextSetter(string plainText){
        this->plainText = plainText;
    }

    void cipherTextSetter(string cipherText){
        this->cipherText = cipherText;
    }
};



class SarVamCipher{
    SarVamCipherOperations obj;

public:
    string SarVamEncrypt(string x){
        obj.plainTextSetter(x);
        return obj.encrypt();
    }

    string SarVamDecrypt(string x){
        obj.cipherTextSetter(x);
        return obj.decrypt();
    }
    
};
