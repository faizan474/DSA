#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define maxN 101
#define mod 1000000007
using namespace std;


struct Mat {
     
	Mat(ll a) {
		N = a;
		Mt.resize(N, vector<ll >(N, 0));
	}
	int N;
	vector<vector<ll > > Mt;
	
};
Mat operator * (Mat a, Mat b)  {
	ll N = a.N;
	Mat Ans(N);
	for (ll i = 0;i < N;i++) {
		for (ll j = 0;j < N;j++) {
			Ans.Mt[i][j] = 0;
			for (ll k = 0;k < N;k++) {
				Ans.Mt[i][j] = (Ans.Mt[i][j] + (a.Mt[i][k] * b.Mt[k][j] ) % mod) % mod;
			}
		}
	}
	return Ans;
}
void solve(){
ll N;

	//cin >> N;
    N=10e17;
	Mat dp(3), Ans(3);
    for(ll i=0;i<3;i++){
        dp.Mt[0][i]=1;
    }
	for (ll i = 1;i < 3;i++) {
		dp.Mt[i][i - 1] = 1;
	}
	for (ll i = 0;i < 3;i++) {
		Ans.Mt[i][i] = 1;
	}
    N+=1;
            while(N>0){
                if(N&1)
                Ans= Ans*dp;
                dp=dp * dp;
                N>>=1;
            }
//cout << Ans.Mt[0][0]<<'\n';
   
}
int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll t;
    cin>>t;
    while(t--){
        for(ll i=0;i<10e5;i++)
        solve();
    }
	/// /////////////////////
	cerr <<'\n' << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << '\n';
	return 0;
}