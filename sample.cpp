#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
int T;
cin>>T;
int N;
int X;
int count = 0;

for(int j = 0; j < T; j++){
    cin>>N>>X;
    if(N == 1)return 0 ;
    if(X == 0 || X > N)return 0;
for(int i = 1; i <= N; i++){
    if (X != i){
    if ((X + i) % 2 == 0){
        count = count + 1;
    cout<<count<<endl;}
    }
    else{cout<<"0"<<endl;}
}

}
}