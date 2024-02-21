// Credit To Andrew Bartling (KHS CPC) for most of the following code


#include <iostream>
#include <cmath>
#include <vector>
#define l long
using namespace std;

int main(){
    l n,s;
    cin>>n>>s;
    l k=1;
    l x=s-1;
    vector<pair<int,l>> line;
    l output=0;
    
    for(int i=0; i<n; i++){
        line.push_back(make_pair(0,0));
        cin>>line[i].first>>line[i].second;
    }
    
    
    while(x>=0 && x<n){
        
        //Targets and Jump pads
        if(line[x].first==0){
            
            if(k>0){
                k=-1*(k+line[x].second);
            }else{
                k=abs(k)+line[x].second;
            }
            
        }else if(line[x].first==1){
            
            if(abs(k)>=line[x].second){
                line[x].first=2;
                output++;
            }
            
        }
        
        
        //Movement
        if(line[x].first==0 && line[x].second==0 && line[x+k].first==0 && line[x+k].second==0){
            break;
        }
        
        x+=k;
    }
    
    cout<<output<<endl;
    
    return 0;
}
