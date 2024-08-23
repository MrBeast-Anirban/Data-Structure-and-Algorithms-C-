#include<iostream>
#include<set>
using namespace std;
typedef multiset<int>::iterator IT;
int main(){
    //Multiset - that can store multiple elements that have same elements
    // stored in a specific -> sorted according to interal comparison object
    // values once inserted can't be modified
    //associative container - elements are refered by their value and not by the index
    // underlying data structure = BST
    int arr[] = {10, 20, 30, 20, 30, 30, 30, 30, 30, 10};
    int n = sizeof(arr)/sizeof(int);
    multiset<int> m(arr, arr+n);
    //iterate 
    for(int x : m){
        cout << x << ", ";
    }
    cout << endl << "Erased 20 :- ";
    //erase 20 (all occurances of 20 will be erased)
    m.erase(20);
    for(int x : m){
        cout << x << ", ";
    }
    cout << endl << "Inserted 80 :- ";
    //insert 80
    m.insert(80);
    for(int x : m){
        cout << x << ", ";
    }
    //count the occurance of element in multiset
    cout << endl << "Count = " << m.count(10) << endl;
    
    //find the first element that is equal to 30
    auto it = m.find(30);
    cout << *it << endl;
    
    //get all the element in a continuous range which is equal to 30
    pair<IT, IT> range = m.equal_range(30);
    for(auto it = range.first; it != range.second; it++){
        cout << *it << " - ";
    }
    cout << endl;
    
    // Print element in range of Lower Bound and Upper Bound
    //lower_bound >= and upper_bound >
    for(auto it = m.lower_bound(10); it != m.upper_bound(80); it++){
        cout << *it << " - ";
    }
    return 0;
}