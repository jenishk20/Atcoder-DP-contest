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
int arr[100001][4];
int dp[100001][4];
int n;
int recur(int idx, int flag)
{
	if (idx == n)
		return 0;

	if (dp[idx][flag] != -1)
		return dp[idx][flag];
	int maxi = INT_MIN;

	if (flag == 0)
	{
		maxi = max(maxi, arr[idx][1] + recur(idx + 1, 1));
		maxi = max(maxi, arr[idx][2] + recur(idx + 1, 2));

		maxi = max(maxi, arr[idx][3] + recur(idx + 1, 3));
	}
	else if (flag == 1)
	{
		maxi = max(maxi, arr[idx][2] + recur(idx + 1, 2));
		maxi = max(maxi, arr[idx][3] + recur(idx + 1, 3));
	}
	else if (flag == 2)
	{
		maxi = max(maxi, arr[idx][1] + recur(idx + 1, 1));
		maxi = max(maxi, arr[idx][3] + recur(idx + 1, 3));

	}
	else
	{
		maxi = max(maxi, arr[idx][1] + recur(idx + 1, 1));
		maxi = max(maxi, arr[idx][2] + recur(idx + 1, 2));
	}
	return dp[idx][flag] = maxi;
}

void solve() {


	cin >> n;
	memset(dp, -1, sizeof dp);

	int i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 1; j <= 3; j++)
			cin >> arr[i][j];

	}
	cout << recur(0, 0);


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





