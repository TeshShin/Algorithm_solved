#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int,int>;
using vpii = vector<pii>;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), [](const vi& a, const vi& b)
         {
             if(a[1] == b[1])
                 return a[0] < b[0];
             return a[1] < b[1];
         });
    vpii cameraRoutes;
    for(const vi& route : routes)
    {
        int start = route[0];
        int end = route[1];
        bool bIsSameCam = false;
        for(pii& cameraRoute : cameraRoutes)
        {
            int& camStart = cameraRoute.first;
            int& camEnd = cameraRoute.second;
            if(!(start > camEnd))
            {
                camStart = max(start, camStart);
                camEnd = min(end, camEnd);
                bIsSameCam = true;
                break;
            }
        }
        if(!bIsSameCam)
        {
            cameraRoutes.push_back({start, end});
        }
    }
    answer = cameraRoutes.size();
    return answer;
}