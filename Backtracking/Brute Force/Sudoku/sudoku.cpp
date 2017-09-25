#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int **a=new int*[9];
int **column=new int*[9];
int **row=new int*[9];
int **square=new int*[9];

void init(){

     for(int i=0;i<9;i++){
        column[i]=new int[9];
        row[i]=new int[9];
        square[i]=new int[9];
        for(int j=0;j<9;j++){
            column[i][j]=-1;
            row[i][j]=-1;
            square[i][j]=-1;
        }
    }
    fstream f;
    f.open("input.txt",ios::in);
    string data;
    string line;
	while (!f.eof())
	{
		getline(f, line);
		data += line;
	}
    f.close();
    int dem=0;
    for(int i=0;i<9;i++){
        a[i]=new int[9];
        for(int j=0;j<9;j++){
            if(data.at(dem)!='-'){
                a[i][j]=data.at(dem)-49;
                column[j][data.at(dem)-49]=1;
                row[i][data.at(dem)-49]=1;
                square[(i/3)*3+j/3][data.at(dem)-49]=1;
            }
            else{
                a[i][j]=-1;
            }
            dem++;
////            cout<<a[i][j]<<" ";
        }
//        cout<<endl;
    }
}
bool solve(int **a,int x,int y){
    if(x==9&&y==0){
            return true;
    }
    else{
        if(a[x][y]==-1){
            for(int i=0;i<9;i++){
                if(column[y][i]==-1&&row[x][i]==-1&&square[(x/3)*3+y/3][i]==-1)
                {
                    a[x][y]=i;
                    column[y][i]=1;
                    row[x][i]=1;
                    square[(x/3)*3+y/3][i]=1;
                    if((y+1)==9){
                        if(solve(a,x+1,0))
                            return true;
                    }
                    else{
                        if(solve(a,x,y+1))
                            return true;
                    }
                    a[x][y]=-1;
                    column[y][i]=-1;
                    row[x][i]=-1;
                    square[(x/3)*3+y/3][i]=-1;
                }
            }
        }
        else{
            if((y+1)==9){
                if(solve(a,x+1,0))
                    return true;
                }
                else{
                    if(solve(a,x,y+1))
                        return true;
                }
            }
        }
    return false;
}

int main() {
    init();
    bool x=solve(a,0,0);
    cout<<endl;
     for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<a[i][j]+1<<" ";
        }
        cout<<endl;
    }
//    cout<<data;
    for(int i=0; i<9;i++)
        delete []a[i]; // giai phong cac hang
    delete []a;
    return 0;
}
