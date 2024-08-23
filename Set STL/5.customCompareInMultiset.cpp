//Implementing custom compare funtion for multiset stl
#include <iostream>
#include <set>
using namespace std;

// Custom comparator class for sorting pairs based on the second element
class PersonCompare {
public:
    bool operator()(const pair<string, int>& p1, const pair<string, int>& p2) const {
        return p1.second < p2.second;
    }
};

int main() {
    // Create pairs with names and money values
    pair<string, int> p1 = make_pair("B", 100);
    pair<string, int> p2 = make_pair("A", 40);
    pair<string, int> p3 = make_pair("C", 120);
    pair<string, int> p4 = make_pair("D", 10);

    // Create a multiset with custom comparator
    multiset<pair<string, int>, PersonCompare> m;
    m.insert(p1);
    m.insert(p2);
    m.insert(p3);
    m.insert(p4);

    // Print the elements of the multiset
    for (const auto& p : m) {
        cout << p.first << " - " << p.second << endl;
    }

    return 0;
}
