

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double Answer;

const double PI = 3.14159265358979;

int main(int argc, char** argv)
{
    int T, test_case;
    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {

        Answer = 0;
        
        int S,E;
        double R;
        cin>>R>>S>>E;
        
        
        int n;
        
        
        cin>>n;
        int l,r,h,pre;
    
        pre = S;
        
        Answer = E-S;
        
        for(int i=1;i<=n;i++){
            cin>>l>>r>>h;
            
            if(h>= R){
                Answer += 2.0*(h-R);
                Answer += PI* R;
                Answer -= 2 * R;
                
            }
            else{
                double tmp = sqrt(R*R - (R-h)*(R-h));
      
                Answer += 2 * (R*acos((R-h)/R));
                Answer -= 2 * tmp;
            }
            
            pre = r;
        }
        
        //Answer+= E-(pre);
        
        cout << "Case #" << test_case+1 << endl;
        cout << std::setprecision(12);
        cout << Answer << "\n";
        
    }

    return 0;//Your program should return 0 on normal termination.
}
