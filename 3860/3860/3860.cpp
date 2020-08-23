#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

#define N 1010
#define INF 999999999999

struct Edge{
    int s,e,d;
};

int W,H;
int G;
int map[N];
int E;
long long dis[N];
vector<Edge> edge;

int main(){
    
    while(1){
        cin>>W>>H;
        if(W==0 && H==0) break;
        
        cin>>G;
        for(int i=1;i<=G;i++){
            int x,y;
            cin>>x>>y;
            map[x+y*W] = 1;
        }
        
        cin>>E;
        for(int i=1;i<=E;i++){
            int sx,sy,ex,ey,d;
            cin>>sx>>sy>>ex>>ey>>d;
            map[sx+sy*W] = 2;
            edge.push_back({sx+sy*W,ex+ey*W,d});
        }
        for(int i=0;i<W*H;i++){
            dis[i] = INF;
            
            if(i == W*H-1 ) break;
            
            if(map[i] > 0) continue;
            
            if( i+1 < W*H && (i+1) % W != 0) if( map[i+1] != 1) edge.push_back({i,i+1,1});
            if( i-1 >= 0 && i%W !=0 ) if( map[i-1] != 1) edge.push_back({i,i-1,1});
            if( i+W < W*H) if( map[i+W] != 1) edge.push_back({i,i+W,1});
            if( i-W >= 0 ) if( map[i-W] !=1 ) edge.push_back({i,i-W,1});
            
        }
        dis[0] = 0;
        
        for(int i=0;i<W*H-1;i++){
            for(int j=0;j<edge.size();j++){
                if(dis[edge[j].s] == INF) continue;
                if(dis[edge[j].e] > dis[edge[j].s] + edge[j].d){
                    dis[edge[j].e] = dis[edge[j].s] + edge[j].d;
                }
            }
        }
        bool flag = false;
        for(int j=0;j<edge.size();j++){
            if(dis[edge[j].s] == INF) continue;
            
            if(dis[edge[j].e] > dis[edge[j].s] + edge[j].d){
                flag = true;
                break;
            }
        }
        
        if(flag) cout<<"Never\n";
        
        else if(dis[W*H-1] == INF) cout<<"Impossible\n";
        
        else cout<<dis[W*H-1]<<"\n";
        
        
        edge.clear();
        for(int i=0;i<W*H;i++) map[i] = 0;
    }
    
    
    return 0;
}
