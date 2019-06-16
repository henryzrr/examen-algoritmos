#include<cstdio>
#include<vector>
#include<unordered_set>
#include<cmath>

using namespace std;
typedef struct punto{
    int x;
    int y;
}punto;
vector<punto>pts;
unordered_set<int>ptsfin;
vector<int>poligono;
int cases,ambientes,i,aux,pos,p2,p3,p1,aux2,area;

void buscarNodoIni(){
    pos=0;
    aux=ambientes*4;
    for(i=1;i<aux;i++){
        if(pts[i].x<pts[pos].x)pos=i;
        else if(pts[i].x==pts[pos].x && pts[i].y>pts[pos].y)pos=i;
    }
}
int productoCruz(){
    return ( ((pts[p1].x*pts[p2].y)+(pts[p2].x*pts[p3].y)+(pts[p3].x*pts[p1].y))-
        ((pts[p1].y*pts[p2].x)+(pts[p2].y*pts[p3].x)+(pts[p3].y*pts[p1].x)) );
}
void armarPoligono(){
    poligono.clear();
    ptsfin.clear();
    p1=pos;
    do{
        p2=-1;
        int ii=0;
        while(p2==-1){
            if(ptsfin.find(ii)==ptsfin.end())p2=ii;
            ii++;
        }
        while(ii<aux){
            p3=ii;
            if(ptsfin.find(ii)!=ptsfin.end()){
                ii++;
                continue;
            };
            aux2 = productoCruz();
            if(aux2>0)p2=p3;
            else if (aux2==0){
                double l3=sqrt(pow(pts[p3].x-pts[p1].x,2)+pow(pts[p3].y-pts[p1].x,2));
                double l2=sqrt(pow(pts[p2].x-pts[p1].x,2)+pow(pts[p2].y-pts[p1].x,2));
                if(l3>l2)p2=p3;
            }
            ii++;
        }
        p1=p2;
        ptsfin.insert(p1);
        poligono.push_back(p1);
    }
    while(p1!=pos);
}
int calcularArea(){
    pos=poligono.size();
    p1=p2=0;
    poligono.push_back(poligono[0]);
    for(i=0;i<pos;i++){
        p1+=(pts[poligono[i]].x*pts[poligono[i+1]].y);
        p2+=(pts[poligono[i]].y*pts[poligono[i+1]].x);
    }
    return abs((p1-p2)/2);
}
int main(){
    scanf("%i",&cases);
    while(cases--){
        scanf("%i",&ambientes);        
        pts.reserve(ambientes*4);
        i=0;
        aux=ambientes;
        while(aux--){
            scanf("%i %i %i %i",&pts[i].x,&pts[i].y,&pts[i+1].x,&pts[i+1].y);
            pts[i+2].x=pts[i].x;
            pts[i+2].y=pts[i+1].y;
            pts[i+3].x=pts[i+1].x;
            pts[i+3].y=pts[i].y;
            i+=4;
        }
        buscarNodoIni();
        armarPoligono();
        area=calcularArea();
        printf("%i\n",area);
    }

    return 0;
}