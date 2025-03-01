#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
int T, N, X;
cin >>T;
for(int i = 1; i < T; ++i){
    cin>>N>>X;
    if((N + X) % 2 == 0){cout<<"1"<<endl;}
    else{cout<<"0"<<endl;}
}
//if((T == 0 )|| (N == 1 )|| (X == 0)) return;

}