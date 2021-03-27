#pragma once
namespace myroom
{
	template<class  K>
	class set
	{
	public:
		void Insert(const K& k)
		{
			_t.Insert(k);
		}
	private:
		struct SetKeyOfValue
		{
			const K& opeartor()(const K& k)
			{
				return k;
			}
		};
		RBTree<K, K, SetKeyOfValue> _t;
	};
	void test_set()
	{
		set<int> st;
		st.Insert(1);
	}

}