#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


#define N 110
#define INF 21000000000000

struct edge{
    int x,y,d;
    
};

int n,m,S,E;
int arr[N];
long long dis[N];

vector<edge> e;

long long d[N][N];

bool isp(int st,int en){
    if(st == en) return true;
    queue<int> q;
    bool chk[N]={false};
    
    q.push(st);
    chk[st] = true;
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(d[x][i] == INF) continue;
            
            if(chk[i]) continue;
            
            chk[i] = true;
            if( i == en) return true;
            q.push(i);
            
            
        }
    }
    return false;
    
}
int main(){

    cin>>n>>S>>E>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            d[i][j] = INF;
    
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        
        d[x][y] = 1;
        e.push_back({x,y,z});
    }
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<m;i++){
        e[i].d -= arr[e[i]. y];
    }
    for(int i=0;i<n;i++) dis[i] = INF;
    dis[S] = -arr[S];
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            if(dis[e[j].x] == INF) continue;
            
            if(dis[e[j].x]+ e[j].d < dis[e[j].y]){
                dis[e[j].y] = dis[e[j].x]+ e[j].d ;
            }
            
        }
    }
    bool flag = false;
    for(int j=0;j<m;j++){
        if(dis[e[j].x] == INF) continue;
        
        if(dis[e[j].x]+ e[j].d < dis[e[j].y]){
         
            if(isp(e[j].y,E)){
                flag = true;
                break;
            }
        }
    }
    if(flag) cout<< "Gee";
    else if( dis[E] == INF ) cout<<"gg\n";
    else cout<< -dis[E];
    
    return 0;
}
