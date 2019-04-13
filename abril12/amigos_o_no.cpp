#include<stdio.h>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
using namespace std;
///--------------------------
typedef struct amigos{
    string a;
    string b;
}amigo;
map<string,vector<int>>amistad;
amigo lsres[10005];

int d,n,t,nroAmigos;
string a1,a2,aux[2];

set<set<string>> paresamigos;

int main(){
    scanf("%i %i",&n,&d);
    
    for(int i=0;i<n;i++){
     
        cin>>a1>>a2>>t;
        
        amistad[a1+a2].push_back(t);
        set<string>s;
        s.insert(a1);
        s.insert(a2);
        paresamigos.insert(s);
    }
    nroAmigos =0;
    for(auto &x:paresamigos){
        int k=0;
        for(auto&y:x){
            aux[k]=y;
            k++;
        }
        auto g1 = amistad.find(aux[0]+aux[1]);
        auto g2 = amistad.find(aux[1]+aux[0]);
        if(g1==amistad.end()||g2==amistad.end()) continue;
        
        int res=100000;
        for(auto&xx:(*g1).second){
            for(auto&yy:(*g2).second){
                int resta = abs(xx-yy);
                res = resta<res && resta>0?resta:res;
            }
        }
    
        if(res>0&&res<=d){
            amigos a;
            a.a=aux[0];
            a.b=aux[1];
            lsres[nroAmigos]=a;
            nroAmigos++;
        }
    }
    printf("%i\n",nroAmigos);
    for(int i=0;i<nroAmigos;i++){
        amigo am = lsres[i];
        cout<<am.a<<" "<<am.b<<"\n";
    }
  
    return 0;
}