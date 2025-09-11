#include <iostream>
#include <vector>
#include <unordered_map>
using ll= long long ;
using namespace std;
int main(){
         
           ll t;
           cin>>t;
        //    vector<ll>s(t,0);
           unordered_map<ll,ll>mp;
           for(ll i=0;i<t;i++) {
                 
                  ll k ;
                  cin>>k;
             
                  mp[k]++;
               
           }
           ll q;
           cin>>q;
           while(q--){
                 ll a;
                 cin>>a;
                 if (mp.count(a))cout<<mp[a]<<endl;
                 else cout<<"NOT PRESENT"<<endl;
           }
         
     
}
