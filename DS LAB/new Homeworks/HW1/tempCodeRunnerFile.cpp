 
#include<iostream>
using namespace std; 
  
void password_Validator(string& password) 
{ 
    int n = password.length();      
    bool hasLower = false, hasUpper = false, hasDigit = false; 
  
    for (int i = 0; i < n; i++) { 
        if (islower(password[i])) 
            hasLower = true; 
        if (isupper(password[i])) 
            hasUpper = true; 
        if (isdigit(password[i])) 
            hasDigit = true; 
    } 
  
    
    
    cout << "The password you  entered is :"; 
    
    if ( hasUpper && hasDigit && hasLower && (n > 5)&&(n<11))
        cout << "password validated succesfully" << endl; 
    else if ((hasLower || hasUpper) && hasDigit && (n >5)&&(n<11)) 
        
        cout << "Normal" << endl; 
    else
        cout << "your password is weak" << endl; 
} 
  
 
int main() 
{   
    
    string password;
    cout <<"Enter your password"<<endl;
  getline(cin,password);
    password_Validator(password); 
    return 0; 
}