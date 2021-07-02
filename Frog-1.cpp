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
int dp[N];
int recur(int idx, int arr[])
{
	if (idx < 0)
		return INT_MAX;
	if (idx == 0)
		return 0;
	if (dp[idx] != -1)
		return dp[idx];

	int op1 = recur(idx - 1, arr) + abs(arr[idx] - arr[idx - 1]);
	int op2 = recur(idx - 2, arr) + abs(arr[idx] - arr[idx - 2]);


	return dp[idx] = min(op1, op2);
}
void solve() {

	int n;
	cin >> n;
	int a[n];
	int i;
	for (i = 0; i < n; i++)
		cin >> a[i];
	memset(dp, -1, sizeof dp);
	cout << recur(n - 1, a);
}


int32_t main()
{

	//File I/O
	c_p_c();

	FIO;

	int tt = 1;
	//w(t)
	solve();

	return 0;



}





