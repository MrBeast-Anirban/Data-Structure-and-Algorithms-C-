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
    //find a elment
    auto it = s.find(make_pair(70, 80));
    if (it != s.end()) {
        cout << endl << "Found pair: (" << it->first << "," << it->second << ")" << endl;
    } else {
        cout << endl << "Pair (70, 80) not found" << endl;
    }
    //erase pair
    s.erase(make_pair(5, 3));
    //erase an element/pair if its present
    s.erase(s.find(make_pair(70, 80)));
    //print the set
    cout << "After Erasing som elements :- " << endl;
    for(auto it = s.begin(); it != s.end(); it++){
        cout << "(" << it->first << "," << it->second << ")" << ", ";
    }

    return 0;
}