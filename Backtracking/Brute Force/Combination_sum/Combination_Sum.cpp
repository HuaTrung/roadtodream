#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> a;
void print(){
    cout<<n<<" = ";
    for(int i=0;i<a.size();i++){
        if(i==(a.size()-1))
            cout<<a[i];
        else
            cout<<a[i]<<" + ";
    }
    cout<<endl;
}
//kjjh

int sum=0;
void solve(int x){
    sum+=x;
    if(sum>=n){
        if(sum==n){
            print();
        }
    }
    else{
        if(x==0) x=1;
        for(int i=x;i<=n;i++){
            a.push_back(i);
            solve(i);
            a.pop_back();
            sum-=i;
        }
    }
}

int main() {
    cin>>n;;
    solve(0);
    return 0;
}
