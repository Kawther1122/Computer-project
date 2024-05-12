#include <iostream>
#include <string>
using namespace std;

// Function to check if Key A is valid
void checkKeyA(int a) {
    if (a < 26) {
        
        while (a < 26) {
            
            cout << "Key A: " << a << " is valid" << endl;
            break;
            cout << "Enter the value of Key A:" << endl;
            cin >> a;
        
    } 
}	 else {
        
        cout << "Key A: " << a << " Is not valid" << endl;
      

        cout << "Invalid value for Key A, possible values are:(1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25)" ;
        cout << "Enter the value of Key A:" << endl;
        cin >> a;
        checkKeyA(a);
    }
}
    

void checkKeyB(int b){

if(b <= 26) {

cout << "Key B:" << b << " is valid." << endl;

}else {

cout <<"Key B:" << b << " is not valid, choose value that is <= 26" <<endl;
cout<<"enter the value of Key B:"<<endl; 
cin>>b;

checkKeyB(b);

}
}

// Function to check if Key B is valid


// Function to encrypt the plaintext
string encrypt(string pt, int a, int b) {
    string ct = " ";
    for (int i = 0; i < pt.length(); i++) {
        if (pt[i] != ' ') {
            pt[i] = toupper(pt[i]);
            ct += char(((a * (pt[i] - 'A')) + b) % 26 + 'A');
        } else {
            ct += pt[i];
        }
    }
    return ct;
}

// Function to decrypt the ciphertext
string decrypt(string ct, int a, int b) {
    string pt = "";
    int a_inv = 0;
    int flag = 0;
    for (int i = 1; i < 26; i++) {
        flag = (a * i) % 26;
        if (flag == 1) {
            a_inv = i;
        }
    }
    for (int i = 0; i < ct.length(); i++) {
        if (ct[i] != ' ') {
         ct[i] =toupper(ct[i]);
		 pt=pt+ char(a_inv *((ct[i] + 'A' )- b ) %26+ 'A');
        } else 
            pt += ct[i];
        
    }
    return pt;
}


int main() {
    int choice;
    int A, B;
    string ptext, ctext;
    cout<<"==========================================\n";
    cout<<"            Main Menu                     \n ";
    cout<<"==========================================\n";

    cout <<"      WELCOME Affine Cipher Program      \n" << endl;
    cout<<"===========================================\n";
    cout <<" please choose the needed method for your text:\n"<< endl;
    cout<<  "| 0. exite                              |\n";
    cout << "| 1. Encrypt                            |\n";
    cout << "| 2. Decrypt                            |\n"; 
    cout<<"===========================================\n";
   

    cin >> choice;
    while (choice != 0) {
        if (choice == 1) {
            cout << "\nEnter the value of Key A: ";
            cin >> A;
            checkKeyA(A);
            cout << "Enter the value of Key B: ";
            cin >> B;
            checkKeyB(B);
            
            cout << "Enter your message: ";
            cin>>ptext;
            
            cout << "Encryption message is: " << encrypt(ptext, A, B) << endl;
            cout<< " ----------------------------------------------------"<<endl;
        } else if (choice == 2) {
            cout << "Enter the value of Key A: ";
            cin >> A;
            checkKeyA(A);
            cout << "Enter the value of Key B: ";
            cin >> B;
            checkKeyB(B);
            cout << "Enter your ciphertext: ";
    
            cin >>ctext;
            cout << "Decryption message is: " << decrypt(ctext, A, B) << endl;
            cout<<" ------------------------------------------------------"<<endl;
        }
        cout << "if you want to stay encrypting or decrypting enter your choice as following:" << endl;
        cout << "encrypt: 1, decrypt: 2, exit: 0" << endl;
        cin >> choice;
    }

    return 0;
}

