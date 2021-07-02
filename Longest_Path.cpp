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
const int N = 2e5 + 5;
vi vis;
vi dp;
vi graph[N];
void dfs(int node)
{
	vis[node] = 1;
	for (auto &it : graph[node])
	{
		if (vis[it] == 0)
			dfs(it);

		dp[node] = max(dp[node], 1 + dp[it]);
	}
}
void solve() {

	int n, m;
	cin >> n >> m;


	int i, j;

	for (i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;

		graph[u].pb(v);
	}
	dp.resize(n + 1, 0);
	vis.resize(n + 1, 0);

	for (i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			dfs(i);
		}
	}
	// for (i = 1; i <= n; i++)
	// {
	// 	cout << dp[i] << " ";
	// }
	// cout << endl;
	cout << *max_element(all(dp)) << endl;

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





