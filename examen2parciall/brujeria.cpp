#include<cstdio>
#include<vector>
using namespace std;
int pesos[1000],nroDulces,pesofin,pesotot,cont,i,j,sum,cases,resp[2],aux;
vector<vector<int>>dp,ind;
vector<int>resf;

void iniciardp(){
    for(i=0;i<=nroDulces;i++){
        dp[i].reserve(pesofin+1);
        ind[i].reserve(pesofin+1);
    }
    for(i=0;i<=pesofin;i++)ind[0][i]=dp[0][i]=0;
    for(i=0;i<=nroDulces;i++)ind[i][0]=dp[i][0]=0;
}
int main(){
    scanf("%i",&cases);
    while(cases--){
        scanf("%i %i",&nroDulces,&pesofin);
        dp.reserve(nroDulces+1);
        ind.reserve(nroDulces+1);
        pesotot=0;
        for(i=1;i<=nroDulces;i++){
            scanf("%i",&pesos[i]);
            pesotot += pesos[i];
        }        
        if(pesotot==pesofin){
            printf("-\n");
            continue;
        } 
        pesofin = pesotot-pesofin;
        iniciardp();
        for(i=1;i<=nroDulces;i++){
            for(j=1;j<=pesofin;j++){
                if(j<pesos[i]){
                    dp[i][j]=dp[i-1][j];
                    ind[i][j]=ind[i-1][j];
                }
                else{
                    sum = pesos[i]+dp[i-1][j-pesos[i]];
                    dp[i][j]=sum>dp[i-1][j]?sum:dp[i-1][j];
                    ind[i][j]=sum>=dp[i-1][j]?i:ind[i-1][j];    
                }
            }
        }
        cont=0;
        for(i=1;i<=nroDulces;i++){
            if(dp[i][pesofin]==pesofin && pesos[i]==pesos[ind[i][pesofin]]){
                cont++;
                resp[0]=i;
                resp[1]=pesofin;
            }
        }
        
        if(cont!=1) puts("Brian, Kevin faltan caramelos !!!");
        else{
            i=resp[0];
            j=resp[1];
            while(ind[i][j]!=0){
                resf.push_back(i);
                aux = i;
                i=ind[i-1][j-pesos[i]];
                j=j-pesos[aux];
            }
            printf("Brian, Kevin faltan ");
            j=resf.size();
            for(i=j-1;i>=0;i--){
                printf("%i ",resf[i]);
            }
            puts("!!!");
        }
        resf.clear();
    }
    return 0;
}