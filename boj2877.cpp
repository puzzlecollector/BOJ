/*
Problem Link: https://www.acmicpc.net/problem/2877
4와 7을 이진법처럼 변환해서 연산을 해준다. 
그냥 k를 이진법으로 변환해주면 패턴을 찾기 쉽지 않기 때문에 k+1을 이진법으로 변환한다. 
*/
#include <iostream> 
#include <cstdlib> 
#include <string> 
#include <sstream> 
#include <algorithm> 
#include <vector> 
using namespace std; 
 
void convertDecimal(vector<int> &v, int k)
{
    while (k > 0)
    {
        v.push_back(k%2); 
        k /= 2; 
    }
    reverse(v.begin(),v.end()); 
}
 
int main()
{
    vector<int> v; 
    int k; 
    cin >> k; 
    ++k; 
    convertDecimal(v,k); 
    string t = ""; 
    for (vector<int>::size_type i = v.size()-1; i > 0; --i)
    {
        if (v[i] == 0) t = '4' + t; 
        else if (v[i] == 1) t = '7' + t; 
    }
    cout << t << endl;
    return 0; 
}
[출처] 4와 7|작성자 Stardust
