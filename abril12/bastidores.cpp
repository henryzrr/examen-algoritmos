#include<stdio.h>
#include<vector>
#include<forward_list>


using namespace std;
vector<int>ls;
vector<forward_list<int>> res;
int bast,groups,ti,cases;

int main(){
    scanf("%i",&cases);
    while(cases--){
        scanf("%i %i",&bast,&groups);
        ls.assign(bast+1,0);
        res.reserve(groups);
        for(int i=0;i<bast;i++){
            scanf("%i",&ti);
            ls[ti] +=1;
        }
     
        int aux =0;
        for(int i=bast;i>0;i--){
            while(ls[i]>0){
                if(!res[aux].empty() && res[aux].front()==i)break;
                res[aux].push_front(i);
                aux++;
                ls[i]--;
                if(aux==groups)aux=0;
            }
        }
        int j=1;
        for(int i=groups-1;i>=0;i--){
            printf("Grupo %i: [",j);
            int num;
            while(true){
                num = res[i].front();
                res[i].pop_front();
                if(!res[i].empty()){
                    printf("%i, ",num);
                }else{
                    printf("%i]\n",num);
                    break;
                }
            }
            j++;
        }

    }
    return 0;
}