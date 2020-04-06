#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    int N;
    scanf("%d", &N);
    std::vector<std::pair<int, std::pair<int, int> > > activities;
    for (int i = 0; i < N; ++i) {
      int S, E;
      scanf("%d%d", &S, &E);
      activities.push_back(std::make_pair(S, std::make_pair(E, i)));
    }
    std::sort(activities.begin(), activities.end());
    std::string ans(N, ' ');
    int response[2000] = {};
    for (int i = 0; i < N; ++i) {
      int S = activities[i].first;
      int E = activities[i].second.first;
      int C = true, J = true;
      for (int time = S; time < E; ++time) {
        if (response[time] & 1) {
          C = false;
        }
        if (response[time] & 2) {
          J = false;
        }
      }
      if (C || J) {
        for (int time = S; time < E; ++time) {
          response[time] |= C ? 1 : 2;
        }
        ans[activities[i].second.second] = C ? 'C' : 'J';
      } else {
        ans = "IMPOSSIBLE";
        break;
      }
    }
    printf("Case #%d: %s\n", t, ans.c_str());
  }
  return 0;
}
