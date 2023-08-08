#include<bits/stdc++.h>
using namespace std;

// let say we are given first and last name of students and we have to save marks of every student

int main(int argc, char const *argv[])
{
    map<pair<string,string>,vector<int>>m;

    int n;cin>>n;
    for (int i = 0; i < n; i++)
    {
            string fn,ln;
            int cnt;
            cin>>fn>>ln>>cnt;
            for (int i = 0; i < cnt; i++)
            {
                int x;cin>>x;
                m[{fn,ln}].push_back(x);
            }
           // m[{fn,ln}]. iske aage apn ne vector bnaya h isliye ab ye vector bn gya ab apn vo sb likh skte h jo vector ke samne likh skte h
    }

    for (auto &it:m)
    {
       cout<<"firstname"<<it.first.first<<"  lastname"<<it.first.second<<endl;
       auto list_of_marks = it.second;
       for (int i = 0; i < list_of_marks.size(); i++)
       {
         cout<<list_of_marks[i]<<" ";
       }
       cout<<endl;

       int mx= *max_element(list_of_marks.begin(),list_of_marks.end());
       cout<<mx<<":-" <<"max marks obtained "<<endl;
       
    }
    
    
    return 0;
}

 bool isValidSudoku(vector<vector<char>>& board) {
       
        
        vector<set<int>>row(9),col(9),block(9);
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                
                if(board[i][j]>='1'&& board[i][j]<='9'){
                    
                    int cur= board[i][j]-'0';
                    if(row[i].count(cur) || col[j].count(cur) || block[i/3*3+j/3].count(cur) ){
                        return false;
                    }
                    row[i].insert(cur);
                    col[j].insert(cur);
                    block[i/3*3+j/3].insert(cur);
                }
            }
        }
    
        
        return true;
    }
    

// NESTED LOOPING IN SET

int main(int argc, char const *argv[])
{
    set<pair<int,int>>s;
    
    return 0;
}
