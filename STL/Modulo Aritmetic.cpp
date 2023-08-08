#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

//Rules 
// (a+b)%M=((a%M)+(b%M))%M;
// (a-b)%M=((a%M)-(b%M))%M;
// (a*b)%M=((a%M)*(b%M))%M;
// (a/b)%M=((a%M)*((b^-1)%M))%M;




int modmul(int a,int b){
    return((long long)(a%mod)*(b%mod))%mod;
}
int binExpo(int a,int b){
    if(!b)return 1;
    int res=binExpo(a,b/2);
    if(b&1){
        return modmul(a,modmul(res,res));
    }else{
        return modmul(res,res);
    }
}

int modmulinv(int a){
    return binExpo(a,mod-2);
}

int main(int argc, char const *argv[])
{
    //PRINTING THE FACTORIAL OF A NUMBER %M

    int n;cin>>n;
    int M=47;
    long long fact =1;
    for (int i = 1; i <= n; i++)
    {
        fact=(fact*i)%M;
    }
    cout<<fact%M<<endl;
    cout<<fact<<endl;

    //both are equal.

    //same applicable on addition and subtraction apply the same at each step while adding 
    //and subtracting.
    
    return 0;
}
