#include<bits/stdc++.h>
using namespace std;

int bsearch(vector<int>&v,int l,int r,int key){
    if(l>r)
    return -1;
    int mid=(l+r)/2;
    if(v[mid]==key)
    return mid;
    // left array is sorted or right array is sorted in case of rotated
    // for left 
    if(v[l]<=v[mid] ){
        // if key present in sorted part 
        if(v[l]<=key && v[mid]>=key)
        return bsearch(v,l,mid,key);
        // otherwise search in other part
        else 
        return bsearch(v,mid+1,r,key);
    }
    // if right part is sorted 
    else if(v[mid]<=v[r]){
        if(v[mid]<=key && v[r]>=key)
        return bsearch(v,mid,r,key);
        else return bsearch(v,l,mid-1,key);
    }
    return -1;
}

int main(){
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    int key;
    cin>>key;
    cout<<bsearch(v,0,n-1,key);
}