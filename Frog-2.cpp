#include<bits/stdc++.h>

using namespace std;


#define ff              first
#define ss              second
#define int 			long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define all(a)      (a).begin(),(a).end()
#define mt               make_tuple
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define REP(i,n) for(i=0;i<n;i++)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll 				long long
const long long   M = 1e9 + 7;

void c_p_c()
{
#ifndef  ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
#endif
}

int mod(int x) {
	return (x % M + M) % M;
}
int  add(int a, int b)
{
	return mod(mod(a) + mod(b));
}
bool f(int x, int y)
{
	return x > y;
}
const int N = 2e5 + 4;
vi dp;
void solve() {

	int n, k;
	cin >> n >> k;
	int a[n];
	int i;
	for (i = 0; i < n; i++)
		cin >> a[i];

	dp.resize(n + 1, INT_MAX);
	dp[0] = 0;

	int j;
	for (i = 1; i < n; i++)
	{
		for (j = i - 1; j >= max(0ll, i - k); j--)
		{
			dp[i] = min(dp[i], abs(a[i] - a[j]) + dp[j]);
		}
	}
	cout << dp[n - 1] << endl;
}


int32_t main()
{

	c_p_c();

	FIO;

	int tt = 1;
	//w(t)
	solve();

	return 0;



}





