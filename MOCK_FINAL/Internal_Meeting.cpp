#include <bits/stdc++.h>
using namespace std;
using pull = pair<unsigned long long, unsigned long long>;

unsigned long long n, m, k, s;

void permute(unsigned long long n, unsigned long long k, string s, map<unsigned long long, unsigned long long> &m)
{
    if (n == k)
    {
        cout << s << '\n';
        return;
    }
    if (m[n] == 2)
    {
        permute(n + 1, k, s + '0', m);
        permute(n + 1, k, s + '1', m);
    }
    else
        permute(n + 1, k, s + to_string(m[n]), m);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k >> s;
    vector<vector<vector<pull>>> G(2, vector<vector<pull>>(n + 1));
    vector<vector<unsigned long long>> Dist(2, vector<unsigned long long>(n + 1, ULLONG_MAX));
    vector<vector<bool>> Visit(2, vector<bool>(n + 1, false));
    map<unsigned long long, unsigned long long> check;

    while (m--)
    {
        unsigned long long u, v, d, t;
        cin >> u >> v >> d >> t;
        G[t][v].push_back({d, u});
    }

    priority_queue<pair<pull, unsigned long long>, vector<pair<pull, unsigned long long>>, greater<pair<pull, unsigned long long>>> pq;
    pq.push({{0, s}, 0});
    pq.push({{0, s}, 1});
    Dist[0][s] = 0;
    Dist[1][s] = 0;
    while (!pq.empty())
    {
        auto [p, c] = pq.top();
        auto [w, u] = p;
        pq.pop();
        Visit[c][u] = true;
        for (auto [d, v] : G[c][u])
        {
            if (Dist[c][v] > w + d && !Visit[c][v])
            {
                Dist[c][v] = w + d;
                pq.push({{Dist[c][v], v}, c});
            }
        }
    }
    unsigned long long ans = 0;
    for (unsigned long long i = 0; i < k; i++)
    {
        unsigned long long t;
        cin >> t;
        ans += min(Dist[0][t], Dist[1][t]);
        if (Dist[0][t] < Dist[1][t])
            check[i] = 0;
        else if (Dist[0][t] > Dist[1][t])
            check[i] = 1;
        else
            check[i] = 2;
    }
    cout << ans << '\n';
    permute(0, k, "", check);
}