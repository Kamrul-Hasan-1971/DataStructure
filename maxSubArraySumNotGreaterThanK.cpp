#include<bits/stdc++.h>
using namespace std;
#define  ll             long long int

ll maxSubArraySumNotGreaterThanK(vector<ll>&arr, ll K)
{
	set<ll> cum_set;
	cum_set.insert(0);
	ll max_sum = LLONG_MIN, cSum = 0;
	for (ll i = 0; i < arr.size(); i++) {
		cSum += arr[i];
		auto it = cum_set.lower_bound(cSum - K); // we need to deduct the extra value more than k from the beginning of current subarraysum
		if (it != cum_set.end()) max_sum = max(max_sum, cSum - *it);
		cum_set.insert(cSum);
	}
	return max_sum;
}

int main()
{
    vector<ll>arr = { 5, -2, 6, 3, -5 , 20};
	ll K = 15;
	cout << maxSubarraySumLessThanOrEqualK(arr, K)<<endl;
    return 0 ;
}
