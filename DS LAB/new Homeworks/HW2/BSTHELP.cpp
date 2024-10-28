 #include <iostream>
  #include<stack> 
  using namespace std;
    class BST 
    {
             int *arr;
                  bool *contains_node;
                       int arr_size;  
                       public:
                            BST()
                                 {   
                                          arr_size = 100;
                                                   arr = new int[100];
                                                            contains_node = new bool[100];
                                                                     for(int i = 0; i < arr_size; i++) 
                                                                                 contains_node[i] = false;  
                                                                                    }    
                                                                                      BST(int arr_size) 
                                                                                          {
     this->arr_size = arr_size; 
             arr = new int[arr_size];
                      contains_node = new bool[arr_size];
                               for(int i = 0; i < arr_size; i++)
                                            contains_node[i] = false; 
                                                } 
                                                     bool Insert(int ele)
                                                          {         
                                                            int curr = 0; 
                                                                    while(curr < arr_size) 
                                                                             {             
                                                                                if(contains_node[curr] == false)
                                                                                             { 
         arr[curr] = ele;
                          contains_node[curr] = true; 
                                          return true;   
                                                    }  
                                                                if(arr[curr] < ele)
                                                                                 curr = 2*curr + 1;
                                                                                              else
       curr = 2*curr + 2;   
             }  
                    return false;  
                       }      
                       bool Search(int ele)
                            { 
                                        int curr = 0; 
                                                while(curr < arr_size) 
                                                        {
                                                                         if(contains_node[curr] == false)
                                                                                          return false; 
       if(arr[curr] == ele) 
                       return true;
                                    else if(arr[curr] < ele) 
                                                    curr = 2*curr + 1;
                                                                 else
                                                                                  curr = 2*curr + 2; 
                                                                                          } 
                                                                                                  return false; 
                                                                                                      }
        int Minimum()    
         {
                     stack<int> s;
                              s.push(0);     
                                       int min_ele = arr[0];
                                                while(!s.empty())
                                                          { 
                                                                        int curr = s.top(); 
 int left = 2*curr + 1, right = 2*curr + 2;
              min_ele = min(min_ele, arr[curr]);   
                        s.pop(); 
                                    if(left < arr_size && contains_node[left])  
                                                    s.push(left);
                                                                 if(right < arr_size && contains_node[right])
                                                                                   s.push(right);
                                                                                            } 
return min_ele;
     }
           int Maximum()
                {
                             stack<int> s;
                                      s.push(0);    
                                                int max_ele = arr[0];
                                                         while(!s.empty())   
                                                                {    
                                                                     int curr = s.top();
  int left = 2*curr + 1, right = 2*curr + 2;
               max_ele = max(max_ele, arr[curr]);   
                         s.pop();
                                      if(left < arr_size && contains_node[left])    
                                                    s.push(left);  
                                                               if(right < arr_size && contains_node[right])
                                                                                 s.push(right);   
                                                                                       }      
return max_ele;
     } 
         };
           int main()
             {
                     BST b; 
                         b.Insert(10);  
                            b.Insert(20);
                                 b.Insert(30);  
                                    b.Insert(5);    
                                     b.Insert(3);  
                                        cout<<"The minimum element is: "<<b.Minimum()<<"\n";
                                             cout<<"The maximum element is: "<<b.Maximum()<<"\n";
    return 0; 
    }