// Code by Krushikesh Shashikant Pisal

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#define all(x) (x).begin(), (x).end()
#define pb push_back;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

ll factorial(ll num)
{

    return (num == 1 or num == 0) ? 1 : (num * factorial(num - 1)) % 1000000007;
}

bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    if (n <= 3)
    {
        return true;
    }

    if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }
    // Using concept of prime number
    // can be represented in form of
    // (6*n + 1) or(6*n - 1) hence
    // we have to go for every multiple of 6 and
    // prime number would always be 1 less or 1 more than
    // the multiple of 6.
    for (int i = 5; i * i <= n; i = i + 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

ll ceil_fun(ll n, ll num)
{
    ll num2 = n / num;
    if (n % num == 0)
        return num2;
    else
        return num2 + 1;
}

bool is_par(string s)
{
    int i = 0;
    int j = s.length() - 1;
    while (i < j)
    {
        if (s[i] != s[j])
        {
            return 0;
        }
        i++;
        j--;
    }

    return 1;
}

int solve(int len,vector<int> &v,int count,vector<int> &dp){
    if(len<0){
        return INT_MIN;
    }
    if(len==0){
        return count;
    }

    if(dp[len]!=-1){
        return dp[len];
    }
    int a=solve(len-v[1],v,count+1,dp);
    int b=solve(len-v[2],v,count+1,dp);
    int c=solve(len-v[3],v,count+1,dp);

    return dp[len]=max(a,max(b,c));
}
void krushikesh(){
    vector<int> v(4);
    for(int i=0;i<4;i++){
        cin>>v[i];
    }

    vector<int> dp(4001,-1);
    cout<<solve(v[0],v,0,dp);
}
int main()
{
    fast_cin();
    ll T = 1;
    string ans;
    ll answer;
    // cin>>T;

    while (T--)
    {
        krushikesh();
    }
    return 0;
}
