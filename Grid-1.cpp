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

	int r, c;
	cin >> r >> c;

	int dp[r][c];

	int i, j;

	char ch[r][c];

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			cin >> ch[i][j];

	memset(dp, 0, sizeof dp);

	if (ch[r - 1][c - 1] == '#')
		dp[r - 1][c - 1] = 0;
	else
		dp[r - 1][c - 1] = 1;
	for (i = c - 2; i >= 0; i--)
	{
		if (ch[r - 1][i] == '#')
			dp[r - 1][i] = 0;

		else
			dp[r - 1][i] += dp[r - 1][i + 1];
	}
	for (i = r - 2; i >= 0; i--)
	{
		if (ch[i][c - 1] == '#')
			dp[i][c - 1] = 0;
		else
			dp[i][c - 1] += dp[i + 1][c - 1];
	}
	// for (i = 0; i < r; i++)
	// {
	// 	for (j = 0; j < c; j++)
	// 	{
	// 		cout << dp[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }

	for (i = r - 2; i >= 0; i--)
	{
		for (j = c - 2; j >= 0; j--)
		{
			if (ch[i][j] == '#')
				dp[i][j] = 0;

			else
			{
				int op1 = (ch[i + 1][j] == '#') ? 0 : dp[i + 1][j];
				int op2 = (ch[i][j + 1] == '#') ? 0 : dp[i][j + 1];

				dp[i][j] = (op1 + op2) % M;
			}
		}
	}
	// for (i = 0; i < r; i++)
	// {
	// 	for (j = 0; j < c; j++)
	// 	{
	// 		cout << dp[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }

	cout << dp[0][0] << endl;
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





