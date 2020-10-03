#include<iostream>
#include<vector>
using namespace std;

 void solve(){
     string str1,str2; cin>>str1>>str2;

     //****************************************************************************************************************
     int n=str1.size(),m=str2.size(),i=1,len=0;   // len is length of previous prefix suffix  i is unexplored character 
     vector<int>pat(m,0);
     while(i<m){
         if(str2[i]==str2[len]){
            pat[i]=len+1;
            i++;len++;
         }
         else{ 
             if(len!=0){
                 len=pat[len-1];
             }
             else {
                 pat[i]=0;
                 i++;
             }
         }
     }

     //***********************************************KMP*****************************************************************

     i=0; j=0;  // i for given string  j for  pattern
     while(i<n){
         if(str1[i]==str2[j]){
             i++;j++;
         }
         if(j==m){
             cout<<"found"<<endl;
         }
         if(i<n && str1[i]!=str2[j]){
             if(j!=0){
                  j=pat[j-1];
             }
             else i++;
         }
     }
 }
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();

    }
    return 0;
}