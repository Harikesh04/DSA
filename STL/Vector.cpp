#include <bits/stdc++.h>
using namespace std;
bool static sortbysec(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.second < b.second);
}


int main(int argc, char const *argv[])
{
        int n = 5;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        v.push_back(5);

        // ! sort vector in reverse order

        sort(v.begin(), v.end(),greater<int>());

        // printing of vector
        for (auto it : v)
            cout << it << " ";
        cout << endl;

        //searaching in a vector
        auto it = find (v.begin(), v.end(), 5);
    if (it != v.end()){
      cout<<"found"<<endl;
    }

        //**insertion in vector

        v.insert(v.begin() + 2, 12);
         for (auto it : v)
            cout << it << " ";
        cout << endl;

       // ** assignment in vector

     //   1.creating copy of vector;

        vector<int>v1;

       // *first method
        v1=v;

       // *second method
        v1.assign(v.begin(),v.end());

        //**DELETION IN VECTOR

      //  1. v.erase(iterator);
        //this is for deleting a single  element from the vector.

        v.erase(v.begin()+5);

      //  2.v.erase(first_iterator,last_iterator);//THIS IF FOR DELETING THE MULTIPLE ELEMENT IN A RANGE

        v.erase(v.begin()+1,v.begin()+3);
      //  TO DELETE ELEMENT FROM THE BACK
        v.pop_back();

     //   TO CLEAR THE COMPLETE VECTOR
        v.clear();

     //   VECTOR PAIR

        vector<pair<int, int>> vp;
        for (int i = 0; i < 5; i++)
        {
            int x, y;
            cin >> x >> y;
            vp.push_back({x, y});
        }
        for (auto it : vp)
        {

            cout << it.first << " " << it.second << endl;
        }

        // THIS WILL SORT THE VECTOR IN INCREASING ORDER BY THE FIRST  ELEMENT
        sort(vp.begin(),vp.end());

        sort(vp.begin(), vp.end(), sortbysec);
  
    // VECTOR OF ARRAY

    //it is always a best option for solving matrix type problem instead of creating a 2d array

    vector<int> v3[2];
    for (int i = 0; i < 2; i++)//number of rows
    {
        for (int j = 0; j < 3; j++)//no. of columns
        {
            int x;
            cin >> x;
            v3[i].push_back(x);
        }
    }

   for (int i = 0; i <2; i++)
   {
     for (int j = 0; j < 3; j++)
     {
        cout<<v3[i][j]<<" ";
     }
     cout<<endl;
     
   }

   cout<<v3[0][2]<<endl;


//VECTOR OF VECTOR

//REMEMBER **:- THE INDEXING OF BOTH ROWS AND COLUMN IN BOTH VECTOR OF VECTOR AND VECTOR OF VECTOR OF ARRAY IS 0 BASED 
int N;
cin>>N;
 vector<vector<int>>vv;

 for (int i = 0; i < N; i++)//no. of rows
 {
  int n=3;
    vector<int>temp;
    for (int j = 0; j < n; j++)//no. of col
    {
        int x;cin>>x;
        temp.push_back(x);
    }

    vv.push_back(temp);
    
    
 }
  for (int i = 0; i <N; i++)
   {
     for (int j = 0; j < vv[i].size(); j++)
     {
        cout<<vv[i][j]<<" ";
     }
     cout<<endl;
     
   }

cout<<vv[1][2];


   

vector<vector<int>>v3(3,vector<int>(3));
vector<vector<int>>v3(3,vector<int>(3,-1));//intializing the matrix with -1

for(int i=0;i<3;i++){
  for(int j=0;j<3;j++){
    cin>>v3[i][j];

  }
}
for(int i=0;i<3;i++ ){
  for(int j=0;j<3;j++){
   cout<<v3[i][j]<<" ";

  }
  cout<<endl;
}





}
