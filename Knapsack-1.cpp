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
int n, w;
const int N = 2e5 + 4;
int wt[1001];
int val[1001];
int dp[101][N];
int recur(int idx, int capacity)
{
	if (idx == 0)
		return 0;
	if (dp[idx][capacity] != -1)
		return dp[idx][capacity];
	if (wt[idx - 1] > capacity)
		return dp[idx][capacity] = recur(idx - 1, capacity);

	int op1 = val[idx - 1] + recur(idx - 1, capacity - wt[idx - 1]);
	int op2 = recur(idx - 1, capacity);

	return dp[idx][capacity] = max(op1, op2);
}

void solve() {


	cin >> n >> w;
	int i, j;
	memset(dp, -1, sizeof dp);
	for (i = 0; i < n; i++)
	{
		cin >> wt[i] >> val[i];
	}

	cout << recur(n, w);



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





