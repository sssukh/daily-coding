#include <string>
#include <vector>
#include <algorithm>


using namespace std;



int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    vector<string> cache;
    int cities_idx = 0;
    while (cities_idx < cities.size())
    {
        string tmp = cities[cities_idx];
        for (int i = 0; i < tmp.size(); i++)
        {
            tmp[i] = (char)tolower(tmp[i]);
        }
        cities_idx++;
        if (cacheSize == 0)
        {
            answer += 5;
            continue;
        }
        auto city = find(cache.begin(), cache.end(),tmp);
        if (city == cache.end()) // cache miss
        {
            if (cache.size() == cacheSize)
                cache.erase(cache.begin());
            cache.push_back(tmp);
            answer += 5;
        }
        else // cache hit
        {
            cache.erase(city);
            cache.push_back(tmp);
            answer += 1;
        }
        
    }


    return answer;
}