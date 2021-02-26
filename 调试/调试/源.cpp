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

//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//
//int main()
//{
//    int M;
//    int N;
//    cin >> M >> N;
//
//    int res = 0;
//    if (N <= 9)
//    {
//        while (M)
//        {
//            res = res * 10 + (M % N);
//            M /= 10;
//        }
//        cout << res << endl;
//    }
//    else
//    {
//        string s;
//        while (M)
//        {
//            if (M % N > 9)
//                s += ('A' + (M % N));
//            else
//                s += ('0' + (M % N));
//            M /= 10;
//        }
//        reverse(s.begin(), s.end());
//        cout << s << endl;
//    }
//    return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//
////f(n,m)=f(n,m-1)+f(n-1,m)
//
//
//int main()
//{
//    int n, m;
//    cin >> n >> m;
//    vector<vector<int>> path;
//    path.resize(n + 1);
//    for (int i = 0; i <= n; ++i)
//    {
//        path[i].resize(m + 1);
//    }
//    for (int i = 0; i < m+1; ++i)
//    {
//        path[0][i] = 1;
//    }
//    for (int i = 0; i < n+1; ++i)
//    {
//        path[i][0] = 1;
//    }
//    for (int i = 1; i < n+1; ++i)
//    {
//        for (int j = 1; j < m+1; ++j)
//        {
//            path[i][j] = path[i - 1][j] + path[i][j - 1];
//        }
//    }
//    cout << path[n][m] << endl;
//    return 0;
//}
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//int main()
//{
//    string str;
//    getline(cin, str);
//    vector<string> res;
//    string temp = "";
//    int flag = 0;//标记引号的出现
//    for (int i = 0; i < str.size(); ++i)
//    {
//        if (str[i] != ' ' && str[i] != '"')
//        {
//            temp += str[i];
//        }
//        else if (str[i] == ' ' && flag == 0)
//        {
//            res.push_back(temp);
//            temp = "";
//        }
//        else if (str[i] == ' ' && flag == 1)
//        {
//            temp += ' ';
//        }
//        else if (str[i] == '"')
//        {
//            ++flag;
//        }
//        if (flag == 2)
//        {
//            res.push_back(temp);
//            temp = "";
//            flag = 0;
//            ++i;
//        }
//    }
//    if(!temp.empty())
//        res.push_back(temp);
//    cout << res.size() << endl;
//    for (auto e : res)
//    {
//        cout << e << endl;
//    }
//
//    return 0;
//}

/*
void ListCreat_Tail(List* phead)
{
    assert(phead != NULL);
    if(*phead == NULL)
    {
        *phead = (ListNode*)malloc(sizeof(ListNode));
        assert(*phead != NULL);
        (*phead)->data = 1;
        (*phead)->next = NULL;
    }
    ListNode* p = *phead;
    for(int i = 2; i <= 10; ++i)
    {
        ListNode *s = (ListNode*)malloc(sizeof(ListNode));
        assert(s != NULL);
        s->data = i;

        s->next = p;

        p = s;

    }
}*/
//#include<iostream>
//using namespace std;
//int main()
//{
//    long double a, b, i;
//    long double c;
//    cin >> a >> b >> i;
//    if (i == 1)
//    {
//        c = a;
//        cout << c << endl;
//    }
//    else if (i == 2)
//    {
//        c = b;
//        cout << c << endl;
//    }
//    else if (i > 2)
//    {
//        int n = i - 2;
//        while (n--)
//        {
//            c = (1 + b) / a;
//            a = b;
//            b = c;
//        }
//        cout << c << endl;
//    }
//    return 0;
//}
//
//#include<iostream>
//using namespace std;
//  struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode() : val(0), next(nullptr) {}
//      ListNode(int x) : val(x), next(nullptr) {}
//      ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
//
//
//bool isPalindrome(ListNode* head)
//{
//    if (head == nullptr || head->next == nullptr)
//        return true;
//    ListNode* slow = head;
//    ListNode* fast = head;
//    ListNode* firsthead = head;
//    ListNode* secondhead = nullptr;
//    while (fast != nullptr && fast->next != nullptr)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//    }
//    if (fast == nullptr)
//        secondhead = slow;
//    else
//        secondhead = slow->next;
//
//    ListNode* cur = secondhead;
//    ListNode* p = secondhead->next;
//    cur->next = nullptr;
//
//    while (p != nullptr)
//    {
//        cur = p;
//        p = p->next;
//        cur->next = secondhead;
//        secondhead = cur;
//    }
//    while (firsthead != nullptr && secondhead != nullptr)
//    {
//        if (firsthead->val == secondhead->val)
//        {
//            firsthead = firsthead->next;
//            secondhead = secondhead->next;
//        }
//        else
//            return false;
//    }
//    return true;
//}
//
//int main()
//{
//    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
//    head->val = 1;
//
//    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
//    p->val = 2;
//    head->next = p;
//
//    ListNode* q = (ListNode*)malloc(sizeof(ListNode));
//    q->val = 2;
//    p->next = q;
//
//    ListNode* x = (ListNode*)malloc(sizeof(ListNode));
//    x->val = 1;
//    q->next = x;
//    x->next = nullptr;
//
//    cout<<isPalindrome(head);
//    return 0;
//}

//#include<stdio.h>
//#define MAX_SIZE 255
//void main()
//{
//    unsigned char buff[MAX_SIZE + 1];
//    unsigned char i;
//    for (i = 0; i <= MAX_SIZE; i++)
//    {
//        buff[i] = i;
//    }
//}

#include<iostream>
#include<string>
using namespace std;

typedef struct BinTreeNode
{
    char data;
    BinTreeNode* left;
    BinTreeNode* right;
}BinTreeNode;
typedef BinTreeNode* BinTree;

BinTreeNode* BinTreeCreat(const string str,int* i)
{
    if (*i == str.size() || str[*i] == '#')
        return nullptr;
    BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
    t->data = str[*i];
    ++(*i);
    t->left = BinTreeCreat(str,i);
    ++(*i);
    t->right = BinTreeCreat(str,i);
    return t;
}
void InOrder(BinTree t)
{
    if (t == nullptr)
        return;
    InOrder(t->left);
    cout << t->data << " ";
    InOrder(t->right);
}
int main()
{

    BinTree t;
    t = nullptr;
    string str;
    cin >> str;
    int index = 0;
    t = BinTreeCreat(str,&index);
    InOrder(t);
    return 0;
}
