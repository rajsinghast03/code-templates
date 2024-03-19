#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

int a[N],seg[4*N+1],lazy[4*N+1];

void build(int ind,int low,int high) {

  if(low == high) {
    seg[ind] = a[low];
    return;
  }

  int mid = low + (high-low)/2;
  build(2*ind+1,low,mid);
  build(2*ind+2,mid+1,high);

  seg[ind] = max(seg[2*ind+1],seg[2*ind+2]);
}

void updateRange(int ind, int start, int end, int l, int r, int val)
{
    if(lazy[ind] != 0)
    { 
        // This ind needs to be updated
        seg[ind] += (end - start + 1) * lazy[ind];    // Update it
        if(start != end)
        {
            lazy[ind*2+1] += lazy[ind];                  // Mark child as lazy
            lazy[ind*2+2] += lazy[ind];                // Mark child as lazy
        }
        lazy[ind] = 0;                                  // Reset it
    }
    if(start > end or start > r or end < l)              // Current segment is not within range [l, r]
        return;
    if(start >= l and end <= r)
    {
        // Segment is fully within range
        seg[ind] += (end - start + 1) * val;
        if(start != end)
        {
            // Not leaf ind
            lazy[ind*2+1] += val;
            lazy[ind*2+2] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRange(ind*2+1, start, mid, l, r, val);        // Updating left child
    updateRange(ind*2 + 2, mid + 1, end, l, r, val);   // Updating right child
    seg[ind] = max(seg[ind*2],seg[ind*2+1]);        // Updating root with max value 
}

int queryRange(int ind, int start, int end, int l, int r)
{
    if(start > end or start > r or end < l)
        return INT_MIN;         // Out of range
    if(lazy[ind] != 0)
    {
        // This ind needs to be updated
        seg[ind] += (end - start + 1) * lazy[ind];            // Update it
        if(start != end)
        {
            lazy[ind*2+1] += lazy[ind];         // Mark child as lazy
            lazy[ind*2+2] += lazy[ind];    // Mark child as lazy
        }
        lazy[ind] = 0;                 // Reset it
    }
    if(start >= l and end <= r)             // Current segment is totally within range [l, r]
        return seg[ind];
    int mid = (start + end) / 2;
    int p1 = queryRange(ind*2+1, start, mid, l, r);         // Query left child
    int p2 = queryRange(ind*2 + 2, mid + 1, end, l, r); // Query right child
    return max(p1,p2);
}
int main() {
    int n ;
    cin >> n;


    for(int i = 0;i<n;++i) {
      cin >> a[i];
    }

    build(0,0,n-1);
  
   updateRange(0,0,n-1,2,3,100);
   cout << queryRange(0,0,n-1,2,3);
}