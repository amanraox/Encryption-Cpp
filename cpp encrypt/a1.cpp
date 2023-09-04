#include <bits/stdc++.h>
#include <fstream>
using namespace std;
 
// encdec class with encrypt() and decrypt() member functions
class encdec {
    int key;
 
    // File name to be encrypt
    string file = "aman.txt";
    char c;
 
public:
    void encrypt();
    void decrypt();
};
 
void encdec::encrypt()
{
    cout << "key: ";
    cin >> key;
 
    // Input stream
    fstream fin, fout;
 
    // Open input file
    // ios::binary- reading file
    // character by character
    fin.open(file, fstream::in);
    fout.open("encrypt.txt", fstream::out);
 
    // Reading original file till
    // end of file
    while (fin >> noskipws >> c) {
        int temp = (c + key);
 
        // Write temp as char in
        // output file
        fout << (char)temp;
    }
 
    // Closing both files
    fin.close();
    fout.close();
}
 
// Definition of decryption function
void encdec::decrypt()
{
    cout << "key: ";
    cin >> key;
    fstream fin;
    fstream fout;
    fin.open("encrypt.txt", fstream::in);
    fout.open("decrypt.txt", fstream::out);
 
    while (fin >> noskipws >> c) {
 
        // Remove the key from the
        // character
        int temp = (c - key);
        fout << (char)temp;
    }
 
    fin.close();
    fout.close();
}
 
// Driver Code
int main()
{
    encdec enc;
    char c;
    cout << "\n";
    cout << "Choice : -> \n1. encrypt \n2. decrypt \n\t\t\t\t\tCreator:\n\t\t\t\t\t-Aman Umrao\n";
    cin >> c;
    cin.ignore();
 
    switch (c) {
    case '1': {
        enc.encrypt();
        break;
    }
    case '2': {
        enc.decrypt();
        break;
    }
    }
}
