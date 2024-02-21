// Credit To Andrew Bartling (KHS CPC) for most of the following code

#include <iostream>
#include <vector>
#include <set>
#define l long
using namespace std;


void calculate(){
    l n;
    cin>>n;
    vector<l> nums;
    set<l> output;
    for(l i=0; i<n; i++){
        nums.push_back(0);
        cin>>nums[i];
    }
    if(n==2){
        if(nums[0]==nums[1]){
            output.insert(nums[0]);
        }
    }else{
        for(l i=0; i<n-1; i++){
            if(nums[i]==nums[i+1]|| (i!=n-1 && nums[i]==nums[i+2])){
                output.insert(nums[i]);
            }
        }
    }
    if(output.empty()){
        cout<<"-1"<<endl;
    }else{
        set<l>::iterator itr;
        for(itr=output.begin(); itr!=output.end();itr++){
            cout<<*itr;
            if (itr != (--output.end())) {
                cout << " ";
            } 
        }
        cout<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        calculate();
    }
}
