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

class MaximumRectangleSumResult{
public:
    ll maxSum, leftBound, rightBound, upBound, lowBound;
    MaximumRectangleSumResult(ll maxSum, ll leftBound, ll rightBound,ll upBound,ll lowBound) {
        this->maxSum = maxSum;
        this->leftBound = leftBound;
        this->rightBound = rightBound;
        this->upBound = upBound;
        this->lowBound = lowBound;
    }
};

MaximumRectangleSumResult maxRectSum(vector<vector<ll>>&input){
    ll rows = input.size();
    MaximumRectangleSumResult result = {LLONG_MIN, -1, -1, -1, -1};
    if(rows == 0) return result;
    ll cols = input[0].size();
    for(ll left = 0; left < cols ; left++){
        vector<ll>temp(rows,0);
        for(ll right = left; right < cols; right++){
            for(ll i=0; i < rows; i++){
                temp[i] += input[i][right];
            }
            KadaneResult kadaneResult = kadaneMaxSubArraySum(temp);
            if(kadaneResult.maxSum > result.maxSum){
                result.maxSum = kadaneResult.maxSum;
                result.leftBound = left;
                result.rightBound = right;
                result.upBound = kadaneResult.startIndex;
                result.lowBound = kadaneResult.endIndex;
            }
        }
    }
    return result;
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
        vector<vector<ll>>input = {{ 2,  1, -3, -4,  5},
                         { 0,  6,  3,  4,  1},
                         { 2, -2, -1,  4, -5},
                         {-3,  3,  1,  0,  3}};
        MaximumRectangleSumResult rectMaxSum = maxRectSum(input);
        cout<<"Result [maxSum=" << rectMaxSum.maxSum <<", leftBound=" << rectMaxSum.leftBound
                    << ", rightBound=" << rectMaxSum.rightBound << ", upBound=" << rectMaxSum.upBound
                    << ", lowBound=" << rectMaxSum.lowBound << "]"<<endl;
    }
    return 0 ;
}
