#include <string>
#include <vector>
#include <iostream>


using namespace std;




int answer = 1;

int solution(vector<vector<string>> clothes) {
  
    vector<string> cloth_list;
    vector<int> clothes_qty;
   
    cloth_list.push_back(clothes[0][1]);
    clothes_qty.push_back(1);
    for (int i = 1; i < clothes.size(); i++) //옷 종류별 개수 구하기
    {
        bool exist = false;
        for (int j=0;j<cloth_list.size();j++)
        {
            if (clothes[i][1] == cloth_list[j])// 만약 cloth_list에 옷이 이미 있으면 개수 추가
            {
                exist = true;
                clothes_qty[j] += 1;
                break;
            }
        }
        if (!exist)
        {
            cloth_list.push_back(clothes[i][1]);
            clothes_qty.push_back(1);
        }
      
    }

    for (int i = 0; i < clothes_qty.size(); i++)
    {
        answer *= clothes_qty[i] + 1;
        cout << cloth_list[i] << " : " << clothes_qty[i] << endl;
    }

   
    
    return answer-1;
}

int main()
{
    vector<vector<string>> clothes;
    vector<string> v1;
    vector<string> v2;
    vector<string> v3;
    v1.push_back("yellow"); v1.push_back("headgear"); clothes.push_back(v1);
    v2.push_back("bvlu"); v2.push_back("eyewear"); clothes.push_back(v2);
    v3.push_back("red"); v3.push_back("headgear"); clothes.push_back(v3);

    solution(clothes);
}