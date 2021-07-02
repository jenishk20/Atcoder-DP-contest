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

void solve() {


	string s, t;
	cin >> s >> t;

	int n = s.size();
	int m = t.size();
	//memset(dp,	 0, sizeof dp);

	int dp[n + 1][m + 1];
	int i, j;
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= m; j++)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (s[i - 1] == t[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	// for (i = 0; i <= n; i++)
	// {
	// 	for (j = 0; j <= m; j++)
	// 	{
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	int idx = dp[n][m];
	i = n;
	j = m;
	vector<char>ans;
	while (i > 0 && j > 0)
	{
		if (s[i - 1] == t[j - 1])
		{
			ans.pb(s[i - 1]);
			i--;
			j--;
			idx--;
		}
		else if (dp[i - 1][j] > dp[i][j - 1])
		{
			i--;
		}
		else
		{
			j--;
		}
	}
	reverse(ans.begin(), ans.end());
	//cout << endl;
	for (auto &it : ans)
		cout << it;

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





