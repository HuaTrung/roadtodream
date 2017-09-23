
#include <iostream>
#include <vector>
using namespace std;
int length;
int *a;
void print(int *a){
    for(int i=0;i<length;i++){
        cout<<a[i];
    }
    cout<<endl;
}

void solve(int x){
    if(x>=length){
        print(a);
    }
    else{
        for(int j=0;j<2;j++){
            a[x]=j;
            solve(++x);
            x--;
        }
    }
}

int main() {
    cin>>length;
    a=new int[n];
    solve(0);
    return 0;
}
