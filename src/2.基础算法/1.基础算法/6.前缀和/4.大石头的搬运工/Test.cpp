#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

#define ll long long
#define f first
#define s second
using namespace std;

ll ans = std::numeric_limits<ll>::max();

int main()
{
    int n;
    cin >> n;

    vector<pair<ll, ll>> a(n + 1);
    vector<ll> pre(n + 1, 0), fin(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int w, p;
        cin >> w >> p;
        a[i] = make_pair(w, p);
    }

    sort(a.begin() + 1, a.end(), [](pair<ll, ll> a, pair<ll, ll> b){ 
        return a.s < b.s; 
    });

    ll tot = 0;
    for (int i = 2; i <= n; ++i)
    {
        tot += a[i - 1].f;
        pre[i] = pre[i - 1] + tot * (a[i].s - a[i - 1].s);
    }

    tot = 0;
    for (int i = n - 1; i >= 1; --i)
    {
        tot += a[i + 1].f;
        fin[i] = fin[i + 1] + tot * (a[i + 1].s - a[i].s);
    }

    for (int i = 1; i <= n; i++)
    {
        ans = 1ll * min(pre[i] + fin[i], ans);
    }

    cout << ans << endl;

    return 0;
}