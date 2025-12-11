#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int main(){
    int N;          
    int M;               
    std::cin >> N >> M;
    std::vector<std::pair<int, int>> segs; 

    int b, e;
    for (int i = 0; i < M; ++i){          
        std::cin >> b >> e;
        segs.emplace_back(b, e);
    }

    if (segs.empty()) {
        std::cout << N;
        return 0;
    }

    std::sort(segs.begin(), segs.end());
    int covered = 0;
    int cur_l = segs[0].first;
    int cur_r = segs[0].second;

    for (size_t i = 1; i < segs.size(); ++i) {
        int l = segs[i].first;
        int r = segs[i].second;
        if (l <= cur_r + 1) { 
            if (r > cur_r) cur_r = r;
        } else {
            covered += (cur_r - cur_l + 1);
            cur_l = l;
            cur_r = r;
        }
    }
    covered += (cur_r - cur_l + 1);

    int ans = N - covered;
    if (ans < 0) ans = 0;
    std::cout << ans;
    return 0;
}
