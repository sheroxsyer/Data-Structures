    #include <iostream>
    #include <regex>
    #include <string>
    #include <cctype>
    using namespace std;
    bool Email_validator(string email)
    {
        const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+") ;  
        std :: string Email_validator = "[_a-z0-9-]+(.[_a-z0-9-]+)*@[a-z0-9-]+(.[a- z0-9-]+)*(.[a-z]{2,4})";
    ;
        return regex_match(email, pattern);
        
    }

    int main()
    {
        system("cls");
        cout << " Email Validation......."<<endl;
        string Email;
        cout << "Enter Your Email Account: ";
        
        cin >> Email;
        // bool valid=validate(Email_validator,Email)
        // {

        // }
        if (Email_validator(Email))
        {
            
            cout << "...............Your Email Account is Valid.............." << endl;
        }
        else
        {
            cout << "...............Your Email Id is Invalid.................." << endl;
        }

        return 0;
    }

            
            