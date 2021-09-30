#include <bits/stdc++.h>
#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{
    OJ
     int tests;
     cin >> tests;
     while (tests--)
     {
          int n, m, k;
          cin >> n >> m >> k;

          vector<int> c(n + 1);
          vector<int> t(n + 1);
          vector<vector<int>> subject(m + 1);

          for (int i = 1; i <= n; i++)
               cin >> c[i];
          for (int i = 1; i <= n; i++)
               cin >> t[i];

          for (int i = 1; i <= n; i++)
               subject[c[i]].push_back(t[i]);

          for (int i = 1; i <= m; i++)
               sort(subject[i].begin(), subject[i].end());

          //simulates min heap
          set<pair<int, pair<int, int>>> min_heap;

          for (int i = 1; i <= m; i++)
          {
               if (!subject[i].empty())
               {
                    int x = 1;
                    int cost = subject[i][0];
                    min_heap.insert({cost, {x, i}});
               }
          }

          int score = 0, time = 0;

          while (!min_heap.empty())
          {
               pair<int, pair<int, int>> p = *min_heap.begin();

               int cost = p.first, x = p.second.first, ind = p.second.second;

               min_heap.erase(min_heap.begin());

               if (cost > k - time)
                    break;

               time += cost;
               score++;

               if (x + 1 < (int)subject[ind].size())
               {
                    int cost1 = subject[ind][x] + subject[ind][x + 1];
                    min_heap.insert({cost1, {x + 2, ind}});
               }
          }

          cout << score << endl;
     }
}