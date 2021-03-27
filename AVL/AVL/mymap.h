#pragma once
#include"RBT.h"
namespace myroom
{
	template<class  K,class V>
	class map
	{
	public:
		void Insert(const pair<K, V>& kv)
		{
			_t.Insert(kv);
		}
	private:
		struct MapKeyOfValue
		{
			const K& opeartor()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
		RBTree<K, pair<K, V>, MapKeyOfValue> _t;
	};
	void test_map()
	{
		map<int, int> m;
		m.Insert(make_pair(1, 1));
	}

}