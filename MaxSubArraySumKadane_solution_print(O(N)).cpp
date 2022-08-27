#include<bits/stdc++.h>
using namespace std;
#define  ll             long long int

class KadaneResult{
public:
    ll maxSum, startIndex, endIndex;
    KadaneResult(ll maxSum, ll startIndex, ll endIndex) {
        this->maxSum = maxSum;
        this->startIndex = startIndex;
        this->endIndex = endIndex;
    }
};

KadaneResult kadaneMaxSubArraySum(vector<ll>&arr){
    ll mx = 0, maxStart = -1, maxEnd = -1, currentStart = 0, maxSoFar = 0;
    for(ll i=0; i < arr.size(); i++){
        maxSoFar += arr[i];
        if(maxSoFar < 0){
            maxSoFar = 0;
            currentStart = i+1;
        }
        if(mx < maxSoFar){
            maxStart = currentStart;
            maxEnd = i;
            mx = maxSoFar;
        }
    }
    return KadaneResult(mx, maxStart, maxEnd);
}

int main()
{
    ll  a;
    while(true)
    {
        cin>>a;
        vector<ll>v1 = { 5, -2, 6, 3, -5 , 20};
        KadaneResult res =  kadaneMaxSubArraySum(v1);
        cout<<res.maxSum<<" "<<res.startIndex<<" "<<res.endIndex<<endl;
    }
    return 0 ;
}
