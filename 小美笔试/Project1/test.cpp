//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//bool IsChangeReverse(string& s)
//{
//    int left = 0;
//    int right = s.size() - 1;
//    int count = 0;
//    int indexa = -1;
//    int indexb = -1;
//
//    while (left <= right)
//    {
//        if (s[left] != s[right])
//        {
//            ++count;
//            indexa = left;
//            indexb = right;
//        }
//        ++left;
//        --right;
//    }
//    if (count == 1)
//    {
//        if (s[indexa] < s[indexb])
//            s[indexb] = s[indexa];
//        else
//            s[indexa] = s[indexb];
//        return true;
//    }
//    else if (count == 0)
//        return true;
//    else
//        return false;
//}
//void changnum(string& s)
//{
//    for (int i = 0; i < s.size(); ++i)
//    {
//        if (s[i] != '0')
//        {
//            s[i] = '0';
//            break;
//        }
//    }
//}
//void Print(const string& s)
//{
//    for (const auto e : s)
//    {
//        cout << e;
//    }
//    cout << endl;
//}
//int main()
//{
//    int N;
//    cin >> N;
//    while (N--)
//    {
//        int len;
//        cin >> len;
//        string s;
//        cin >> s;
//        bool flag = IsChangeReverse(s);
//        if (!flag)
//            changnum(s);
//        Print(s);
//    }
//    return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//
//bool func(vector<int>& ant, int& first, int& last, int key)
//{
//    int begin = 0;
//    int end = ant.size() - 1;
//
//    while (begin <= end && ant[begin] != key)
//        ++begin;
//    while (begin <= end && ant[end] != key)
//        --end;
//    if (begin <= end && ant[begin] == ant[end] && ant[begin] == key)
//    {
//        first = begin;
//        last = end;
//        return true;
//    }
//    return false;
//}
//int main()
//{
//    int times,len;
//    cin >> len >> times;
//    vector<int> ant;
//    while (len--)
//    {
//        int x;
//        cin >> x;
//        ant.push_back(x);
//    }
//    while (times--)
//    {
//        int first, last, key;
//        cin >> key;
//        bool flag = func(ant, first, last, key);
//        if (flag)
//        {
//            cout << first+1 << " " << last+1 << endl;
//        }
//        else
//            cout << "0" << endl;
//    }
//    
//    return 0;
//}




#include<iostream>
#include<vector>
using namespace std;
int dp(vector<int>& res, int& k)
{
    int cur = 0, count = 0, Max = 0,Temp = 0;
    for (int i = 0; i < res.size(); ++i)
    {
        cur = Temp ^ res[i];
        if (count < k && cur > Max)
        {
            Temp = cur;
            ++count;
        }
        else if(count == k && Temp > Max)
        {
            Max = Temp;
            Temp = res[--i];
            count = 0;
        }
    }
    return Temp;
}
int main()
{
    int len, k;
    cin >> len >> k;
    vector<int> res;
    while (len--)
    {
        int x;
        cin >> x;
        res.push_back(x);
    }
    cout << dp(res, k) << endl;

    return 0;
}