#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int *a;
int *l;
int length;
int *g;
void init(){
    cin>>length;
    l=new int[length+2];
    g=new int[length+2];
    a=new int[length+2];
    l[0]=0;
    g[0]=0;
    a[0]=-32768;
    for(int i=1;i<(length+1);i++){
        cin>>a[i];
    }
    a[length+1]=32767;
}
void solve(){
    int lengthmax=0;
    int posmax=0;
    for(int i=1;i<(length+2);i++){
        lengthmax=0;
        for(int j=0;j<i;j++){
            if(a[j]<=a[i]){
                if(l[j]>lengthmax){
                    lengthmax=l[j];
                    posmax=j;
                }
            }
        }
        l[i]=lengthmax+1;
        g[i]=posmax;
    }
}

int main() {
    init();
    solve();
    cout<<endl;
    for(int i=0;i<(length+2);i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<(length+2);i++){
        cout<<l[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<(length+2);i++){
        cout<<g[i]<<" ";
    }
    cout<<endl;
    cout<<l[length]<<endl;
    int i=length+1;
    while(a[g[i]]!=-32768){
        cout<<a[g[i]]<<" ";
        i=g[i];
    }
//    for(int i=0; i<16;i++)
//        delete []a[i]; // giai phong cac hang
//    delete []a;
    return 0;
}
