/*
 * let num[i][j] is the number of occurrences of -a[i]-a[j] , ans[i][j] is the answer for the interval i..j 
 * ans[i][j] = ans[i+1][j] + ans[i][j-1] - ans[i+1][j-1] + num[i][j] 
 * filling these tabels cost O(n^2) ans answering the queries costs O(1) which is totally ok
 * note : I did not do excatly the same in the code cause of the strict time & memory limit but it is the same idea 
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 340
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ld pai=acos(-1);
int n , q , MX = 1e6;
int a[5009] , num[3000009];
ll ans[5009][5009];
int main () {
	freopen("threesum.in","r",stdin);
	freopen("threesum.out","w",stdout);
	scanf("%d%d",&n,&q);
	for ( int i = 0 ; i < n ; i ++ ) scanf("%d",&a[i]) ;
	for ( int i = 0 ; i < n ; i ++ ) {
		for ( int j = i+1 ; j < n-1 ; j ++ ) {
			num [ a[j] + MX ] ++ ;
			ans[i][j+1] += num [ - a[i] - a[j+1] + MX ] ;
		}
		for ( int j = i+1 ; j < n-1 ; j ++ ) num[ a[j] + MX ] = 0 ;
	}
	for ( int sz = 3 ; sz <= n ; sz ++ ) {
		for ( int i = 0 ; i < n ; i ++ ) {
			int j = i + sz - 1 ;
			if ( j >= n ) break ; 
			ans [i][j] += ans[i+1][j] + ans[i][j-1] - ans[i+1][j-1] ;
		}
	}
	while ( q -- ) {
		int l ,r ;
		scanf("%d%d",&l,&r);
		l -- , r -- ;
		printf("%lld\n",ans[l][r]); 
	}
}
