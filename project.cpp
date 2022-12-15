#include<iostream>
#include <string>
#include <algorithm>

using namespace std;
//Encrypt function takes in a string  for the message to
// be encrpted and a key
string Encrypt(string message, string key)
{
    string encryptedMessage;
   //for loop goes through each element of the string
    //the element is added to the key and mod 26
    for (int i = 0; i < message.size(); i++)
    {
        char a = (message[i] + key[i]) % 26;
        a += 'A';
        //adds element to the encrypted string
        encryptedMessage.push_back(a);
    }
    return encryptedMessage;
}
//Decrypt function takes in a encrypted string and a
// key after its been matched
string Decrypt(string message, string key)
{
    string decryptedMessage;
    //for loop matched each element to the cipher to
    // decrypt the message
    for (int i = 0; i < message.size(); i++)
    {
        char a = (message[i] - key[i] + 26) % 26;
        a += 'A';
        decryptedMessage.push_back(a);
    }
    return decryptedMessage;
}
//keyMatch function matches the lenght of the key to the
// lenght of the message
string keyMatch(string message,string key)
{
    int l = message.size();
    
    for (int i = 0; ; i++)
    {
        if (l == i)
            i = 0;
        if(key.size() == message.size())
            break;
        key.push_back(key[i]);
    }
   
    return key;
}
int main()
{
    int choice;
    string message, key, fixedKey, encryptedmessage, decryptedmessage;
    //starting menu
    cout << "Choose wheather to encrypt or decrypt: " << endl;
    cout << "1. Encrypt" << endl;
    cout << "2. Decrypt" << endl;
    cin >> choice;
    // if else branch to either encrypt or decrypt 
    if (choice == 1)
    {
        cout << "Enter message to encrypt: " << endl;
        cin >> message;
        cout << "Enter the key: " << endl;
        cin >> key;
        fixedKey = keyMatch(message,key);
        encryptedmessage = Encrypt(message,fixedKey);
        cout <<"Encrypted message: "<< encryptedmessage << endl;
    }
    else if (choice == 2)
    {
        cout << "Enter message to decrypt: " << endl;
        cin >> message;
        cout << "Enter the key: " << endl;
        cin >> key;
        fixedKey = keyMatch(message,key);
        decryptedmessage = Decrypt(message,fixedKey);
        cout <<"Decrypted message: "<< decryptedmessage << endl;
        
    }
    else
        
    return 0;
}