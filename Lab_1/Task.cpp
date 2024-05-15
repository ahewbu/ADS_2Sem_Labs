#include "Set.h"
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

vector<int> Unique(vector<int>& base) {
    if (base.empty())
        return base;

    vector<int> unique;
    vector<int> duplicate;
    vector<int> ret;
    Set search_tree;

    while (!base.empty()) {
        bool flag = search_tree.Insert(base.back());
        //search_tree.Print();
        if (flag)
            unique.push_back(base.back());
        else
            duplicate.push_back(base.back());
        base.pop_back();
    }
    //search_tree.Print();

    for (int & i : unique) {
        auto it = find(duplicate.begin(), duplicate.end(), i);
        if (it == duplicate.end()) {
            ret.push_back(i);
        }
    }

    //return   duplicate;
    return   ret;
}


int main() {
    vector<int> base{ 1,3,4,4,3,2,3,2,5,0 };
    vector<int> new_vector = Unique(base);
    sort(new_vector.begin(), new_vector.end());
    for (int i : new_vector)
        cout << i << " ";
}