//#include<iostream>
//#include<vector>
//#include<list>
//using namespace std;
//
//
//bool duplicate(int numbers[], int length, int* duplication)
//{
//    if (numbers == nullptr || length <= 0)//数组为空
//        return false;
//    for (int i = 0; i < length; ++i)
//    {
//        if (numbers[i] < 0 || numbers[i] > length - 1)//数字不在正确范围之内
//            return false;
//    }
//    for (int i = 0; i < length; ++i)
//    {
//        while (i != numbers[i])
//        {
//            if (numbers[i] == numbers[numbers[i]])
//            {
//                duplication[0] = numbers[i];
//                return true;
//            }
//            swap(numbers[i], numbers[numbers[i]]);
//        }
//    }
//    return false;
//}
//
//
//void FindNumsAppearOnce(vector<int> data, int* num1, int* num2)
//{
//    int n = 0;
//    for (size_t i = 0; i < data.size(); ++i)
//    {
//        n ^= data[i];
//    }
//    int i = 0;
//    for (; i < 32; ++i)
//    {
//        if (n & (1 << i))
//            break;
//    }
//    int n1 = 0;
//    int n2 = 0;
//    for (size_t j = 0; j < data.size(); ++j)
//    {
//        if (data[j] & (1 << i))
//            n1 ^= data[j];
//        else
//            n2 ^= data[j];
//    }
//    * num1 = n1;
//    * num2 = n2;
//}
//
//
//
//int LastRemaining_Solution(int n, int m)
//{
//    list<int> children;
//    for (int i = 0; i < n; ++i)
//    {
//        children.push_back(i);
//    }
//    list<int>::iterator cur = children.begin();
//    while (children.size() > 1)
//    {
//        for (int i = 1; i < m; ++i)
//        {
//            ++cur;
//            if (cur == children.end())
//                cur = children.begin();
//        }
//        list<int>::iterator next = ++cur;
//        if (next == children.end())
//            next = children.begin();
//        --cur;
//        children.erase(cur);
//        cur = next;
//    }
//    return *cur;
//}
//
//int main()
//{
//
//    cout << LastRemaining_Solution(5, 3) << endl;
//    return 0;
//}
//int main()
//{
//    int numbers[] = { 6,3,2,0,2,5,0 };
//    int* duplication = nullptr;
//    cout << duplicate(numbers, 7, duplication) << endl;
//    return 0;
//}
//int main()
//{
//    vector<int> data = { 2,4,3,6,3,2,5,5 };
//    int* num1 = 0;
//    int* num2 = 0;
//    FindNumsAppearOnce(data, num1, num2);
//
//    return 0;
//}

//#include<iostream>
//#include<string>
//#include<algorithm>
//#include<stack>
//using namespace std;
//
//int main()
//{
//    string str1;
//    getline(cin, str1);
//    stack<string> st;
//    string res;
//    for (size_t i = 0; i < str1.size(); ++i)
//    {
//        if (str1[i] != ' ')
//        {
//            res += str1[i];
//        }
//        else
//        {
//            st.push(res);
//            res = "";
//        }
//    }
//    st.push(res);
//    string str = st.top();
//    st.pop();
//    while (!st.empty())
//    {
//        str += " ";
//        str += st.top();
//        st.pop();
//    }
//    cout << str << endl;
//    return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//    int n;
//    cin >> n;
//    vector<int> arr;
//    while (n--)
//    {
//        int x;
//        cin >> x;
//        arr.push_back(x);
//    }
//
//    int r = 0;
//    int flag = 0;
//    for (size_t i = 1; i < arr.size(); ++i)
//    {
//        while (arr[i - 1] <= arr[i])
//        {
//            ++i;
//            flag = 1;
//        }
//        if (flag == 1)
//        {
//            ++r;
//            flag = 0;
//        }
//        while (arr[i - 1] >= arr[i])
//        {
//            ++i;
//            flag = 1;
//        }
//        if (flag == 1)
//        {
//            ++r;
//            flag = 0;
//        }
//    }
//    cout << r << endl;
//    return 0;
//}

#include<iostream>
#include<algorithm>
using namespace std;


int main()
{
    int M;
    int N;
    cin >> M >> N;

    int res = 0;
    if (N <= 9)
    {
        while (M)
        {
            res = res * 10 + (M % N);
            M /= 10;
        }
        cout << res << endl;
    }
    else
    {
        string s;
        while (M)
        {
            if (M % N > 9)
                s += ('A' + (M % N));
            else
                s += ('0' + (M % N));
            M /= 10;
        }
        reverse(s.begin(), s.end());
        cout << s << endl;
    }
    return 0;
}