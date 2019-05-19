#include<cstdio>
#include<stack>
#include<unordered_map>
#include<vector>

using namespace std;
typedef struct  nodo{
	vector<int> ar;
}nodos;

unordered_map<int,int>um;
unordered_map<int,int>::iterator it;
//vector<nodos>grafo;
int grafo[10000][10000];
int visitado[10000];
stack<int>pila;
int cases,path,i,ant,nodo,auxnodo;
bool first;

void iniciarGrafo(){
	for(i=0;i<10000;i++){
		visitado[i]=-1;
		for(int j=0;j<10000;j++){
			grafo[i][j]=0;
		}
	}
}

int main(){
	scanf("%i",&cases);
	while(cases--){	
		iniciarGrafo();
		//grafo.reserve(10000);
		scanf("%i",&path);
		i=0;
		first=true;
		while(path--){
			scanf("%i",&nodo);
			it = um.find(nodo);
			if(it!=um.end()) auxnodo = it->second;
			else{
				um[nodo]=i;
				auxnodo = i;
				i++;
			}
			if(first){
				ant=auxnodo;
				first=false;
			}else{
				//(grafo[ant]).ar.push_back(auxnodo);
				grafo[ant][auxnodo]=1;
				//printf("%i %i\n",ant,grafo[ant].ar[auxnodo]);
				ant=auxnodo;
			}

		}
		pila.push(0);
		while(!pila.empty()){
			auxnodo = pila.top();
			pila.pop();
			for(int j=0;j<i;j++){
				
			}
		}
				/*
		puts("");
		for(int j=0;j<i;j++){
			printf("%i: ",j);
			for(int k=0;k<i;k++){
				printf("%i ",grafo[j][k]);
			}
			puts("");
		}
		*/
		um.clear();
	}
	return 0;
}