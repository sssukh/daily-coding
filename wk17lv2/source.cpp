#include<math.h>
#include<iostream>
using namespace std;

long long solution(int w, int h) {
    long long answer = 0;
    
  
    
    long long nw = w;
    long long nh = h;
    if (w==h)
    {
        answer = nw * nh - nh;
        return answer;
    }
    else if(w>h)
    {
        for (int i = 1; i < h; i++)
        {
            
            answer +=(nw * i / h);
        }
    }
    else
    {
        for (int i = 1; i <w; i++) 
        {
            answer +=(nh * i / w);
            
        }
    }
 
    return answer*2;
}

int main()
{
    cout<<solution(8, 12);
    return 0;
}