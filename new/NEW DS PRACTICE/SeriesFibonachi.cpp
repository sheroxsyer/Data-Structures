#include <iostream>
using namespace std;

int main() {
    int n, t1 , t2,t3, nextTerm = 0;
    cout<<"Enter term1"<<endl;
    cin>>t1;
    cout<<"Enter term2"<<endl;
    cin>>t2;
    cout<<"Enter term3"<<endl;
    cin>>t3;

    cout << "Enter the number of terms: ";
    cin >> n;

    

    for (int i = 1; i <= n; ++i) {
        // Prints the first two terms.
        if(i == 1) {
            cout << t1 << ", ";
            continue;
        }
        if(i == 2) {
            cout << t2 << ", ";
            continue;
        }
		if(i == 3)
		{
			cout<<t3<<" ; ";
			continue;
		}
        nextTerm = t1 + t2+ t3;
        t1 = t2;
        t2 = t3;
		t3 = nextTerm;
        
        cout << nextTerm << ", ";
    }
    return 0;
}