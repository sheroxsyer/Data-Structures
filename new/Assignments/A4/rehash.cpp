#include<iostream>
using namespace std;

class Hashtable{
private:
    int sze; //size: number of values are currently in the hashtable
    int cap; //capacity: the size of the hashtable

    struct HashNode{
        string value;
    };

    HashNode** arr;  //bucket

    //determine whether the number is prime or not
    bool IsPrime(int number){
        if (number == 2 || number == 3)
            return true;

        if (number % 2 == 0 || number % 3 == 0)
            return false;

        int divisor = 6;
        while (divisor * divisor - 2 * divisor + 1 <= number)
        {

            if (number % (divisor - 1) == 0)
                return false;

            if (number % (divisor + 1) == 0)
                return false;

            divisor += 6;

        }

        return true;

    }

    //find the next prime number that is >= a
    int NextPrime(int a){
        while (!IsPrime(++a)){ }
        return a;
    }

    int hashing(const string &s) const{
        int h = 0;
        for (int i = 0; i < s.size(); i++)
        {
            h += int(s[i]);
        }

        return h;
    }

    void rehashing ()
    {
        int oldCap = cap;
        sze = 0;
        //Doubling the capacity
        cap = NextPrime(cap*2);

        HashNode** oldArr = arr;
        arr = new HashNode*[cap]();

        //moving the values to the new after rehashing
        for (int i = 0; i < oldCap; i++){
            if (oldArr[i] != nullptr){
                for (int j = 0; j < cap; j++){
                    int index = (hashing(oldArr[i]->value) + j*j) % cap;
                    if (arr[index] == nullptr){
                        arr[index] = new HashNode {oldArr[i]->value};
                        sze++;
                        break;
                    } //if
                } //for
                delete oldArr[i];
                oldArr[i] = nullptr;
            } //if
        } //for

        delete[] oldArr;
    }

public:
    // Constructor
    Hashtable(int ini_cap = 101) : sze(0), cap(ini_cap), arr(new HashNode*[cap]){
        for (int i = 0; i < cap; i++)
        {
            arr[i] = nullptr;
        }

    }

    //Destructor
    ~Hashtable(){
        for (int i = 0; i < cap; i++){
            if (arr[i] != nullptr){
                delete arr[i];
                arr[i] = nullptr;
            }
        }
        delete[] arr;
    }

    double load_factor() const {return double(sze)/cap;}

    void put(const string& s){
        //Initialize a new node for the new input
        HashNode* temp = new HashNode{s};

        //Insert using quadratic probing
        for (int i = 0; i < cap; i++){
            int index = (hashing(s) + i*i) % cap;
            if (arr[index] == nullptr){
                arr[index] = temp;
                sze++;
                break;
            }
        }

        if (load_factor() > 0.5){
            rehashing();
        } //if 

    } //add
 };