//Set storing pair
#include<iostream>
#include<set>
using namespace std;
int main(){
    set<pair<int, int>> s;
    s.insert(make_pair(10,1));
    s.insert(make_pair(20,1));
    s.insert(make_pair(20,100));
    s.insert(make_pair(5,1));
    s.insert(make_pair(5,3));
    s.insert(make_pair(5,3));
    s.insert(make_pair(6,7));
    s.insert(make_pair(70,80));
    s.insert(make_pair(80,90));
    //print the set
    for(set<pair<int,int>>::iterator it = s.begin(); it != s.end(); it++){
        cout << "(" << it->first << "," << it->second << ")" << ", ";
    }
    //Lower Bound of an element
    auto i = s.lower_bound(make_pair(20, 1));
    cout << endl << "Lower Bound of (20,1) " << i->first << "," << i->second;
    //upper Bound of an element
    auto it = s.upper_bound(make_pair(20, 1));
    cout << endl << "Upper Bound of (20,1)" << it->first << "," << it->second << endl;
    return 0;
}