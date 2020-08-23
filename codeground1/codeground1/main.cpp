#include <iostream>

using namespace std;

int Answer;

int d[1000010];
int sum[1000010];
int main()
{
    int T, test_case;

    cin >> T;
    d[2] = 1;
    for(int i=4;i<=1000000;i+=2){
        d[i] = d[i/2]+1;
        d[i-1] = d[i]+1;
    }
    for(int i=2;i<=1000000;i++) sum[i]= sum[i-1]+d[i];
    
    for(test_case = 0; test_case  < T; test_case++)
    {

        Answer = 0;
        int a,b;
        cin>>a>>b;
        Answer = sum[b] - sum[a-1];
        cout << "Case #" << test_case+1 << "\n";
        cout << Answer << "\n";
    }

    return 0;//Your program should return 0 on normal termination.
}
