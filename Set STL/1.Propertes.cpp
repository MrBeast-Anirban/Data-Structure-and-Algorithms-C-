//Insert and Erase property of set stl
#include<iostream>
#include<set>
using namespace std;
int main(){
    int arr[] = {10, 20, 11, 9, 8, 10, 11};
    int n = sizeof(arr)/sizeof(int);
    set<int> s;
    for(int i = 0; i < n; i++){
        s.insert(arr[i]);
    }
    //Print all the elements in set
    for(set<int>::iterator it = s.begin(); it != s.end(); it++){
        cout << *(it) << ", ";
    }
    //erase an element
    s.erase(10);
    //erase element using an iterator
    auto it = s.find(11);
    s.erase(it);
    //Print all the elements in set
    cout << endl;
    for(set<int>::iterator it = s.begin(); it != s.end(); it++){
        cout << *(it) << ", ";
    }
    return 0;
}