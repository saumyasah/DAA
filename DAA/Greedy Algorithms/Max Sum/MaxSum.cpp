#include<bits/stdc++.h>
using namespace std;
 
struct Node {
    long long _max;
    long long _pre;
    long long _suf;
    long long _sum;
};
Node getNode(long long x){
    Node a;
    a._max = x;
    a._pre = x;
    a._suf = x;
    a._sum = x;
    return a;
}
Node merg(const Node &l, const Node &r){
    Node ans ;
 
    ans._max = ans._pre = ans._suf = ans._sum = 0;
    ans._pre = max({l._pre, l._sum+r._pre, l._sum+r._sum});
    ans._suf = max({r._suf, r._sum+l._suf, l._sum+r._sum});
    ans._sum = l._sum + r._sum;
    ans._max = max({ans._pre, ans._suf, ans._sum,l._max, r._max, l._suf+r._pre});
    return ans;
}
Node getMaxSumSubArray(int l, int r, vector<long long> &ar){
 
    if (l == r) return getNode(ar[l]);
 
    int mid = (l + r) >> 1;
    Node left = getMaxSumSubArray(l, mid, ar);
    Node right = getMaxSumSubArray(mid+1, r, ar);
    return merg(left, right);
 
}
int main(){
 
    vector<long long> ar = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = ar.size();
    Node ans = getMaxSumSubArray(0, n-1, ar);
    cout << "Answer is " << ans._max << "\n";
 
    return 0;
}