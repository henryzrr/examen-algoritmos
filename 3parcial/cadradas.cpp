#include<cstdio>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
typedef struct resp{
    int x;
    int y;
}resp;

vector<string>patron,texto;
vector<resp>r;
vector<int>kmp;
int np,nt,i,j;
string aux;

void prepararKMP(){
    kmp.reserve(np);
    i=0;
    j=1;
    kmp[0]=0;

    while(j<np){
        if(patron[0][i]==patron[0][j]){
            kmp[j]=i+1;
            i++;
            j++;
        }else if(i==0){
            kmp[j]=0;
            j++;
        }
        else i=kmp[i-1];
    }

}
int auxBusqueda(int pos,int ii){
    int l = ii+(np-1);
    int kk=1;
    int pp=0;
    int pi=ii;
    for(;ii<l;ii++){
        int jj=pos;
        for(int pp=0;pp<np;pp++){
            if(texto[ii][jj]!=patron[kk][pp]){
                return -1;
            }
            jj++;
        }
        kk++;
    }
    resp rr;
    rr.x=pi-1;
    rr.y=pos;
    r.push_back(rr);
    return 1;
}
void buscarmatch(){
    int k;
    int lim = nt-np;
    for(i=0;i<=lim;i++){
        k=0;
        j=0;
        while(j<nt){
            if(k==np){
                auxBusqueda(j-k,i+1);
                k=kmp[k-1];
            }else if(texto[i][j]==patron[0][k]){
                j++;
                k++;
            }else if(k==0)j++;
            else k=kmp[k-1];
        }
        if(k==np)auxBusqueda(j-k,i+1);
    }
}
void mostrarmactch(){
    cout<<r.size()<<"\n";
    for(auto&xx:r)cout<<xx.x<<" "<<xx.y<<" \n";
}
int main(){
    cin>>np;
    for(i=0;i<np;i++){
        cin>>aux;
        patron.push_back(aux);
    }
    cin>>nt;
    for(i=0;i<nt;i++){
        cin>>aux;
        texto.push_back(aux);
    }
    prepararKMP();
    buscarmatch();
    mostrarmactch();

    return 0;
}