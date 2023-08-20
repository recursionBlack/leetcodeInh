#include<string>
#include<unordered_set>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution013 {
private:
    unordered_map<char, int> symbolValues = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };

public:
    int romanToInt(string s) {
        int ans = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            int value = symbolValues[s[i]];
            if (i < n - 1 && value < symbolValues[s[i + 1]]) {
                ans -= value;
            } else {
                ans += value;
            }
        }
        return ans;
    }

    // 测例
    // s = "MCMXCIV" 1994
    // s = "LVIII"   58
    void ShuRu()
    {
        cout << " plase putin string" << endl;
        char c;
        while(cin >> c)
        {
            m_String += c;
        }
        
    }

    void ChuShu()
    {
        int res = romanToInt(m_String);

        cout << "the res is " << res << endl;
    }

public:

    int m_K;
    int m_N;
    string m_String;


};

