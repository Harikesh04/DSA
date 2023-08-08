#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
//    string s;
//     cin>>s;

//     //TO TAKE INPUT OF A LINE
// !    getline(cin, s);

//    //INSERTION IN A STRING
//    string s="ilili";
//   s.insert(4,"kesh");//insertition will takes place in 4th index.
// !   s.insert(4,"k");
// s.push_back('a');
// cout<<s<<endl;//ililkeshi




// //DELETION IN STRING

// ! s.erase(s.begin()+2);

// s.pop_back();

// ! s.erase(s.begin()+2,s.begin()+4);

// //CLEAR THE STRING 

// s.clear();

// //reverse(s.begin(),s.end());

//  string s2=s;

//  //SEARCHING IN STRING
// string str="si";

// ? //this will return the positon of the begining of the string which we are searching in the string
// !  cout<<s.find(str);
//  //here op:0

//  int n=s.find(str);

// //**IF STRING WILL BE NOT FOUND IT WILL RETURN INFINITY.
//    if(n==string :: npos)
//     cout<<" NOT FOUND"<<endl;


// //SUBSTRING FUN IN STRING

 // ! s.substr(intitial_pos,length_of_the_substr_req);(here iterator is not required)

// //if initial position nothing passed then it will take begining of the string
// //if length_of_the_substr_req is not passed it will take default as the string length after the initial position

// cout<<s.substr(3,3);

 


// //VECTOR OF STRING {FOR MATRIX TYPE PROBLEM}
//    vector<string> v(8);
//     for(int i= 0 ;i<8; i++) cin>>v[i];
//     for(int i = 1; i<7; i++)
//     {
//         for(int j= 1; j<7; j++)
//         {
//             if(v[i-1][j-1] == '#' && v[i+1][j-1]=='#' && v[i+1][j+1]=='#' && v[i-1][j+1]=='#')
//             {
//                 cout<<(i+1)<<" "<<(j+1)<<endl;
//                 return;
//             }
//         }
//     }

// ? // CONVERT STRING TO INT

// ! int n=stoi(s);

 // !CONVERT A PARTICULAR CARACTER OF STRING TO INT
//  int a=s[2]-'0';
//  int b=s[3]-'0';
//  cout<<a+b<<endl;
   
 //TOTAL NUMBER OF NON EMPTY SUBSTRING FROM STRING OF SIZE N IS n*(n+1)/


// TO CONVERT ALPHABET FROM a TO z TO 1 TO 26.
// string s="abcdef";

// for (int i = 0; i < s.size(); i++)
// {
//   ! cout<<s[i]-'a'+1<<" "<<endl;
// }


//  ? TO GET ASCII VALUE OF A CHAR

// ! cout<<int(s[0]);

 // to convrt int to char

 // ! char(i+'a')

string s="hello how are you";

stringstream ss(s);
string token="";

// ? here with the help of stringstream we break string in token here we are breaking it on basis of ' '. 

string s2="/home//foo/";

// ! here we can break token with breaking point '/' by using getline(ss,token,'/')


while(getline(ss,token,' ')){
    cout<<token<<endl;
}


return 0;


    


}
