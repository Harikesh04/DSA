#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    // ordered map
    // time complexity of insertion O(logn).
    // only unique element are present
    // if we put duplicate then the ele will be updated automatically.

    map<int, string> mp;
    mp[3] = "dfc";
    mp[1] = "abc";
    mp[2] = "dbc";


  //  here passing by adddress so that the copy of the map will not created.
    for (auto &it : mp)
    {
        cout << it.first << " " << it.second << endl;
    }

    // searching in map

    auto it = mp.find(1);
    //this will return interator;
    // this is condition so that we will not error
    if (it == mp.end())
    {
        cout << "NO VALUE" << endl;
    }
    else
    {
        cout << (*it).first << " " << (*it).second << endl;
    }

    // DELETION IN MAP

    mp.erase(3);

    mp.clear();

    // MAP DECLARATION
    map<string, int> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        m[s]++;
    }
    for (auto &it : m)
    {
        cout << it.first << " " << it.second << endl;
    }

    //** ELEMENT WILL WE STORED IN SORTED ORDER WITH RESPECT TO KEY ELEMENT i.e the first element.

    auto it2 = m.find("abc");
    if (it2 == m.end())
    {
        cout << "NO VALUE" << endl;
    }

    cout << (*it2).first << " " << (*it2).second << endl;

    // UNORDERED MAP

    //    unordered map is similar to ordered map

    //    but it do not store data in sorted order

    //    elements get store,insrt,delete,etc in O(1) time.

    unordered_map<int, int> um;

    return 0;

    //PRINT MAX OCCURING ELEMENT IN A MAP
    map<int,int>hash;
    int max_cnt =0,max_ele=0;
     for (auto i : hash) {
        if (max_cnt < i.second) {
            max_ele = i.first;
            max_cnt = i.second;
        }
    }

    cout<<max_ele<<endl;
}
