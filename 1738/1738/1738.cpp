#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

struct Edge{
    int s,e,d;
};

#define N 110
#define INF 9999999

int n,m;


vector<Edge> v;

int dis[N];
int pre[N];
int map[N][N];

bool isp(int st){
    queue<int> q;
    q.push(st);
    bool chk[N] = {false};
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            if(chk[i]) continue;
            if(!map[x][i]) continue;
            
            if(i == n) return true;
            chk[i] = true;
            q.push(i);
        }
    }
    return false;
}

int main(){
    cin>>n>>m;
    
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        map[x][y] = 1;
        v.push_back({x,y,-z});
    }
    for(int i=1;i<=n;i++) dis[i]=INF;
    
    dis[1] =0;
    
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            if(dis[v[j].s] == INF) continue;
            
            if(dis[v[j].e] > dis[v[j].s]+v[j].d){
                dis[v[j].e] = dis[v[j].s]+v[j].d;
                pre[v[j].e] = v[j].s;
            }
        }
    }
    for(int j=0;j<m;j++){
        if(dis[v[j].s] == INF) continue;
        
        if(dis[v[j].e] > dis[v[j].s]+v[j].d){
            if(isp(v[j].e)){
                cout<<"-1";
                return 0;
            }
        }
    }
    
    if(pre[n] == 0) cout<<"-1";
    else{
        stack<int> st;
        for(int i = n;i != 0 ; i= pre[i]){
            st.push(i);
        }
        while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
        }
    }
    
    
    
    return 0;
}
