#include<cstdio>
#include<set>
#include<vector>
using namespace std;
set<int>elem;
set<int>::iterator it;
int resp[100000],i,nodo,path,cases,auxpath;
int main(){
	scanf("%i",&cases);
	while(cases--){
		//for(i=0;i<100000;i++)resp[i]=0;
		scanf("%i",&path);
		//auxpath = path;
		i=-1;
		while(path--){
			scanf("%i",&nodo);
			it = elem.find(nodo);
			if(it==elem.end()){
				i++;
				elem.insert(nodo);
				resp[i]=nodo;
			}else{
				elem.clear();
				for(int j=0;j<=i;j++){
					if(resp[j]==nodo){
						i=j;
					} 
					elem.insert(resp[j]);
				}
			}
		}
		if(i==0)puts("Camila esto no va a dar");
		//else if(i==0)puts("1");
		else{
			for(int j=0;j<i;j++)printf("%i ",resp[j]);
			printf("%i\n",resp[i]);
		}
		elem.clear();
	}
	return 0;
}