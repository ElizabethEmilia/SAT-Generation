#include <iostream>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

enum { 
	N_E1 = 0, N_E, N_T, N_F,
	T_ADD, T_MUL, T_LB, T_RB, T_ID
};

const char exprs[10][10] = { "E'", "E", "T", "F", "+", "*", "(", ")", "id" };

constexpr int TOKEN_NUM = T_ID - N_E1 + 1; 
constexpr int NONTERM_NUM = N_F - N_E1 + 1;
#define _nt(x) (x - 5)

struct product {
	int name;
	list<int> body;
	int index;

	product(int p_index, int n, initializer_list<int> list){
		for (auto it = list.begin(); it != list.end(); ++it){
			body.push_back(*it);
		}
		name = n;
		index = p_index;
	}

	void output() {
		cout << exprs[name] << " -> ";
		for (auto it = body.begin(); it != body.end(); ++it) {
			cout << exprs[*it] << " ";
		}
		//cout << body.size();
		cout << endl;
	}
};

product prod[7] = {
	product(0, N_E1, { N_E }),
	product(1, N_E, { N_E, T_ADD, N_T }),
	product(2, N_E, { N_T }),
	product(3, N_T, { N_T, T_MUL, N_F }),
	product(4, N_T, { N_F }),
	product(5, N_F, { T_LB, N_E, T_RB }),
	product(6, N_F, { T_ID })	
};

class item;

item * items[50];
int current_calced_item = 0;
int current_item = 1;

// Production , token,    item
map<pair<product *, int>, int> goto_map;

int item_id = 0;
class item {
public:
	int id;

	int core_num = 0;
	int noncore_num = 0;
	product * core[20];
	int core_dot_at[20];
	product * noncore[20];
	int goto_from_token = -1;

	//int: 项（状态） int: 文法符号
	map<int, int> goto_to_token;

	int reduce_prod = -1;

	bool added[7] = {0, 0, 0, 0, 0, 0};
	bool core_added[7] = {0, 0, 0, 0, 0, 0};

	void add_core(product* p, int _dot_at) {
		//如果已经添加则不重复添加
		if (core_added[p->index])
			return;
		core_dot_at[core_num] = _dot_at;
		core[core_num++] = p;
		core_added[p->index] = true;
	}

	void add_noncore(product* p) {
		noncore[noncore_num++] = p;
		added[p->index] = true;
	}

	int check_goto(int item_id, int token) {
		//auto it = find(goto_to_token.begin(), goto_to_token.end(), item_id);
		//return (it == goto_to_token.end() && it->second == token);
	}

	item() {
		id = item_id++;
	}

	void calc() {
		int add = 0;
		int d = 0;

		//cout << "ITEM " << id << "**************************************\n";
		do {
			add = 0;			
			auto f = [&](product * p, int dot_at) {
				if (dot_at >= p->body.size())
					return;
				auto itt = p->body.begin();
				for (int i=0; i<dot_at; i++)
					itt++;
				int it = *itt;
				//这个it是在tags里面的位置并不是产生式在数组里面的位置
				//这个it只是代表产生式的名称

				// 如果it是终结符号
				if (it >= T_ADD)
					return;
				//cout << "[dot_at=" << dot_at << "]\n" ;
				//p->output();
				//cout << exprs[it] << endl;
				for (int index=0 ;index<7; index++) {
					//cout << "added[" << index << "]=" << added[index] << endl;
					if (prod[index].name != it)
						continue;

					//如果当前产生式是这个非终结符号的产生式
					//判断如果没有加入过，那么加入
					if (!added[index]) {
						add_noncore(prod+index);
						added[index] = true;
						//(prod+index)->output();
						add += 1;
					}
				}
				//cout<< endl;
			};

			for (int i=0; i<core_num; i++) {
				//cout << "core: " << i << endl;
				f(core[i], core_dot_at[i]);
			}
			for (int i=0; i<noncore_num; i++) {
				//cout << "Non-core: " << i << endl;
				f(noncore[i], 0);
			}

		}
		while (add);
	}

	void generate_next() {
		int check_goto(product * p, int token);
		//在第一个for循环复制
		int _dot_at;

		item * generated_items[TOKEN_NUM] = {0};

		for (int i=0; i<core_num; i++)  {
			int dot_at = core_dot_at[i];
			_dot_at = dot_at+1;
			product * p = core[i];
			// 获得第dot_at个词法单元
			auto iterat = p->body.begin();
			for (int i=0 ; i<dot_at; i++) {
				iterat++;
			}
			int first_token = *(iterat);
			
			// 如果点位于产生式后部，说明可以归约，并且不产生新项
			if (_dot_at > p->body.size()) {
				///处理归约
				reduce_prod = p->index;
				continue;
			}

			// 如果这个文法符号已经有了对应的项那么直接加入核心产生式，否则新建项并加入
			if (generated_items[first_token] == nullptr) {
				// 如果这个项已经有对应的项了
				int already = check_goto(p, first_token);
				if (already != -1) {
					generated_items[first_token]=items[already];
				}
				else {
					item * _item = new item;
					items[current_item++] = _item;
					generated_items[first_token] = _item;
					goto_map.insert({ { p , first_token }, current_item - 1 });
					goto_to_token.insert({ current_item - 1, first_token });
				}
			}
			if (_dot_at <= p->body.size())
				generated_items[first_token]->add_core(p, core_dot_at[i] + 1);
		}
		for (int i=0; i<noncore_num; i++) {
			product * p = noncore[i];
			// 获得第一个词法单元
			int first_token = *(p->body.begin());
			// 如果这个文法符号已经有了对应的项那么直接加入核心产生式，否则新建项并加入
			if (generated_items[first_token] == nullptr) {
				// 如果这个项已经有对应的项了
				int already = check_goto(p, first_token);
				if (already != -1) {
					generated_items[first_token]=items[already];
				}
				else {
					item * _item = new item;
					items[current_item++] = _item;
					generated_items[first_token] = _item;
					goto_map.insert({ { p , first_token }, current_item - 1 });
					goto_to_token.insert({ current_item - 1, first_token });
				}
			}
			if (_dot_at <= p->body.size())
				generated_items[first_token]->add_core(p, 1);
		}
	}
};

// 检查goto函数是否存在
int check_goto(product * p, int token) {
	auto it = goto_map.find(pair<product*, int> (p, token));
	if (it == goto_map.end()) {
		return -1;
	}
	return it->second;
}

void create_sal() {

}

int main() {
	cout << "Production: \n";
	for (product& t: prod)
		t.output();

	items[0] = new item;
	
	items[0]->add_core(prod, 0);
	items[0]->calc();
	items[0]->generate_next();

	current_calced_item+=1;
	while (current_calced_item != current_item) {
		///cout << "calced = " << current_calced_item << ", all = " << current_item;
		//getchar();
		item * it = items[current_calced_item];
		it->calc();
		it->generate_next();

		current_calced_item++;
	}

	cout << endl;
	for(int k=0; k<current_item; k++) {
		item * it = items[k];
		cout << "Item I["<< k <<"]:\n";
		for (int i=0; i< it->core_num; i++) {
			cout  << "(" << it->core_dot_at[i] << ") ";
			it->core[i]->output();
		}
		for (int i=0; i< it->noncore_num; i++) {
			cout << "(0) ";
			it->noncore[i]->output(); 
		}
		cout << endl;
	}

	//cout << check_goto(prod, N_E);
	cout << "GOTO(I[i], a) values:\n";
	for (int i=0; i<current_item; i++) {
		for (auto it : items[i]->goto_to_token) {
			cout << "GOTO(i[" << i << "], " << exprs[it.second] << " )=s" << it.first << endl;
		}	
	}

	cout << "Reduces:\n";
	for (int i=0; i<current_item; i++) {
		if (items[i]->reduce_prod == -1)
			continue;
		cout << "I[" << i << "]=r" << items[i]->reduce_prod << " (aka: ";
		prod[items[i]->reduce_prod].output();
	}
}