#include <iostream>
#include <list>
#include <map>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>

using namespace std;

enum { 
	__START_POS_ = -1,
	NONTERM_PARAMS, NONTERM_GLOBE, NONTERM_ARRAYP, NONTERM_VECTOR, NONTERM_DECLR, NONTERM_EXPR10, NONTERM_ACCESS, NONTERM_FOREX, NONTERM_CASE, NONTERM_STMTS, NONTERM_STMT, NONTERM_MATRIX, NONTERM_ARRAY, NONTERM_ELSE, NONTERM_GLOBE1, NONTERM_FACTOR, NONTERM_MATRIXR, NONTERM_STACC, NONTERM_EXPR, NONTERM_BOOLEAN, NONTERM_MEMLIST, NONTERM_INITIAL, NONTERM_CALLPAR, NONTERM_EXPR11, NONTERM_BLOCK, NONTERM_EXPR6, NONTERM_EXPR5, NONTERM_EXPR4, NONTERM_EXPR3, NONTERM_EXPR2, NONTERM_EXPR1, NONTERM_DECLROP, NONTERM_EXPR7, NONTERM_EXPR9, NONTERM_EXPR8, 
	T_ID, T_MH, T_FH, T_LT, T_ASSIGN, T_GT, T_LB, T_RB, T_MUL, T_ADD, T_COMMA, T_SUB, T_DOT, T_DIV, T_NOT, T_BITWISE_AND, T_KW_SWITCH, T_INCREASE, T_KW_ELSE, T_KW_FUNCTION, T_LLB, T_KW_BREAK, T_KW_WHILE, T_KW_NEW, T_KW_TRUE, T_KW_IF, T_DECREASE, T_KW_ECHO, T_KW_NULL, T_STRING, T_KW_FALL, T_KW_INPUT, T_POWER, T_LMB, T_RMB, T_BITWISE_XOR, T_KW_STRUCT, T_KW_CASE, T_KW_FALSE, T_KW_TYPEOF, T_KW_ARRAY, T_AND, T_KW_FOR, T_ASSIGN_POWER, T_KW_MARTIX, T_KW_CONTINUE, T_NUMBER, T_RLB, T_KW_DEFAULT, T_KW_CROSS, T_LTE, T_EQ, T_GTE, T_KW_DOT, T_ASSIGN_MUL, T_ASSIGN_ADD, T_ASSIGN_SUB, T_TYPE, T_ASSIGN_DIV, T_NEQ, T_KW_VECTOR, T_OR, T_BITWISE_NOT, T_KW_VAR, T_RELOP, T_BITWISE_OR, T_KW_DO,  T_EOI
};

const char exprs[103][20] = { 
	"Params", "Globe", "ArrayP", "Vector", "Declr", "Expr10", "Access", "Forex", "Case", "Stmts", "Stmt", "Matrix", "Array", "Else", "Globe1", "Factor", "MatrixR", "StAcc", "Expr", "Boolean", "MemList", "Initial", "CallPar", "Expr11", "Block", "Expr6", "Expr5", "Expr4", "Expr3", "Expr2", "Expr1", "DeclrOp", "Expr7", "Expr9", "Expr8", "id", ":", ";", "<", "=", ">", "(", ")", "*", "+", ",", "-", ".", "/", "!", "&", "switch", "++", "else", "function", "{", "break", "while", "new", "true", "if", "--", "echo", "null", "string", "fall", "input", "**", "[", "]", "^", "struct", "case", "false", "typeof", "array", "&&", "for", "**=", "martix", "continue", "number", "}", "default", "cross", "<=", "==", ">=", "dot", "*=", "+=", "-=", "type", "/=", "!=", "vector", "||", "~", "var", "relop", "|", "do",  "$"
};
const char exprs2[103][20] = { 
	"NONTERM_PARAMS", "NONTERM_GLOBE", "NONTERM_ARRAYP", "NONTERM_VECTOR", "NONTERM_DECLR", "NONTERM_EXPR10", "NONTERM_ACCESS", "NONTERM_FOREX", "NONTERM_CASE", "NONTERM_STMTS", "NONTERM_STMT", "NONTERM_MATRIX", "NONTERM_ARRAY", "NONTERM_ELSE", "NONTERM_GLOBE1", "NONTERM_FACTOR", "NONTERM_MATRIXR", "NONTERM_STACC", "NONTERM_EXPR", "NONTERM_BOOLEAN", "NONTERM_MEMLIST", "NONTERM_INITIAL", "NONTERM_CALLPAR", "NONTERM_EXPR11", "NONTERM_BLOCK", "NONTERM_EXPR6", "NONTERM_EXPR5", "NONTERM_EXPR4", "NONTERM_EXPR3", "NONTERM_EXPR2", "NONTERM_EXPR1", "NONTERM_DECLROP", "NONTERM_EXPR7", "NONTERM_EXPR9", "NONTERM_EXPR8", "T_ID", "T_MH", "T_FH", "T_LT", "T_ASSIGN", "T_GT", "T_LB", "T_RB", "T_MUL", "T_ADD", "T_COMMA", "T_SUB", "T_DOT", "T_DIV", "T_NOT", "T_BITWISE_AND", "T_KW_SWITCH", "T_INCREASE", "T_KW_ELSE", "T_KW_FUNCTION", "T_LLB", "T_KW_BREAK", "T_KW_WHILE", "T_KW_NEW", "T_KW_TRUE", "T_KW_IF", "T_DECREASE", "T_KW_ECHO", "T_KW_NULL", "T_STRING", "T_KW_FALL", "T_KW_INPUT", "T_POWER", "T_LMB", "T_RMB", "T_BITWISE_XOR", "T_KW_STRUCT", "T_KW_CASE", "T_KW_FALSE", "T_KW_TYPEOF", "T_KW_ARRAY", "T_AND", "T_KW_FOR", "T_ASSIGN_POWER", "T_KW_MARTIX", "T_KW_CONTINUE", "T_NUMBER", "T_RLB", "T_KW_DEFAULT", "T_KW_CROSS", "T_LTE", "T_EQ", "T_GTE", "T_KW_DOT", "T_ASSIGN_MUL", "T_ASSIGN_ADD", "T_ASSIGN_SUB", "T_TYPE", "T_ASSIGN_DIV", "T_NEQ", "T_KW_VECTOR", "T_OR", "T_BITWISE_NOT", "T_KW_VAR", "T_RELOP", "T_BITWISE_OR", "T_KW_DO",  "T_EOF"
};

constexpr int TOKEN_NUM = 103; 
constexpr int NONTERM_NUM = 35;
const int LAST_NONTERM = 34;
const int FIRST_TERM = 35;
const int AUG_G_PROD = NONTERM_GLOBE1;
const int END_PARSE_FLAG = T_EOI;
const int START_SIGN = NONTERM_GLOBE1;

int product_id = 0;
struct product {
	int name;
	list<int> body;
	int index;

	product(int n, initializer_list<int> list){
		for (auto it = list.begin(); it != list.end(); ++it){
			body.push_back(*it);
		}
		name = n;
		index = product_id++;
	}

	void output() {
		cerr <<exprs[name] << " -> ";
		for (auto it = body.begin(); it != body.end(); ++it) {
			cerr <<exprs[*it] << " ";
		}
		if (body.size() == 0) {
			cerr <<"e";
		}
		cerr <<endl;
	}
};

product prod[] = {
	
	product(NONTERM_GLOBE1, { NONTERM_GLOBE }),
	product(NONTERM_GLOBE, { NONTERM_GLOBE, NONTERM_STMT }),
	product(NONTERM_GLOBE, { NONTERM_GLOBE, T_KW_VAR, NONTERM_DECLR, T_FH }),
	product(NONTERM_GLOBE, { NONTERM_GLOBE, T_KW_FUNCTION, T_ID, T_LB, NONTERM_PARAMS, T_RB, T_LLB, NONTERM_STMT, T_RLB }),
	product(NONTERM_GLOBE, { NONTERM_GLOBE, T_KW_FUNCTION, T_ID, T_LB, T_RB, T_LLB, NONTERM_STMT, T_RLB }),
	product(NONTERM_GLOBE, { NONTERM_GLOBE, T_KW_STRUCT, T_TYPE, T_LLB, T_RLB, T_FH }),
	product(NONTERM_GLOBE, { NONTERM_GLOBE, T_KW_STRUCT, T_TYPE, T_LLB, NONTERM_MEMLIST, T_RLB, T_FH }),
	product(NONTERM_GLOBE, {  }),
	product(NONTERM_STMTS, { NONTERM_STMTS, NONTERM_BLOCK }),
	product(NONTERM_BLOCK, { T_LLB, NONTERM_STMTS, T_RLB }),
	product(NONTERM_BLOCK, { NONTERM_STMT }),
	product(NONTERM_STMT, { T_KW_VAR, NONTERM_DECLR, T_FH }),
	product(NONTERM_STMT, { T_KW_BREAK, T_FH }),
	product(NONTERM_STMT, { T_KW_CONTINUE, T_FH }),
	product(NONTERM_STMT, { T_KW_DO, NONTERM_BLOCK, T_KW_WHILE, T_LB, NONTERM_BOOLEAN, T_RB, T_FH }),
	product(NONTERM_STMT, { T_KW_ECHO, NONTERM_EXPR, T_FH }),
	product(NONTERM_STMT, { T_KW_FALL, T_FH }),
	product(NONTERM_STMT, { T_KW_FOR, T_LB, NONTERM_FOREX, T_FH, NONTERM_BOOLEAN, T_FH, NONTERM_EXPR, T_RB, NONTERM_BLOCK }),
	product(NONTERM_STMT, { T_KW_IF, T_LB, NONTERM_BOOLEAN, T_RB, NONTERM_BLOCK, NONTERM_ELSE }),
	product(NONTERM_STMT, { T_KW_INPUT, T_ID }),
	product(NONTERM_STMT, { T_KW_SWITCH, T_LB, NONTERM_EXPR, T_RB, T_LLB, NONTERM_CASE, T_RLB }),
	product(NONTERM_STMT, { T_KW_WHILE, T_LB, NONTERM_BOOLEAN, T_RB, NONTERM_BLOCK }),
	product(NONTERM_STMT, { NONTERM_EXPR, T_FH }),
	product(NONTERM_STMT, { T_FH }),
	product(NONTERM_DECLR, { NONTERM_DECLR, T_COMMA, T_ID, NONTERM_DECLROP }),
	product(NONTERM_DECLR, { T_ID, NONTERM_DECLROP }),
	product(NONTERM_DECLROP, { T_ASSIGN, NONTERM_EXPR }),
	product(NONTERM_DECLROP, {  }),
	product(NONTERM_INITIAL, { NONTERM_EXPR }),
	product(NONTERM_INITIAL, { T_LLB, NONTERM_ARRAY, T_RLB }),
	product(NONTERM_INITIAL, { T_LMB, NONTERM_MATRIX, T_RMB }),
	product(NONTERM_INITIAL, { T_LT, NONTERM_VECTOR, T_GT }),
	product(NONTERM_INITIAL, { T_LLB, T_RLB }),
	product(NONTERM_INITIAL, { T_LMB, T_RMB }),
	product(NONTERM_INITIAL, { T_LT, T_GT }),
	product(NONTERM_ELSE, { T_KW_ELSE, NONTERM_BLOCK }),
	product(NONTERM_ELSE, {  }),
	product(NONTERM_PARAMS, { NONTERM_PARAMS, T_COMMA, T_ID }),
	product(NONTERM_PARAMS, { T_ID }),
	product(NONTERM_MEMLIST, { NONTERM_MEMLIST, T_KW_VAR, NONTERM_DECLR, T_FH }),
	product(NONTERM_CASE, { NONTERM_CASE, T_KW_CASE, T_NUMBER, T_MH, NONTERM_BLOCK }),
	product(NONTERM_CASE, { NONTERM_CASE, T_KW_DEFAULT, T_MH, NONTERM_BLOCK }),
	product(NONTERM_CASE, {  }),
	product(NONTERM_FOREX, { NONTERM_EXPR }),
	product(NONTERM_FOREX, { T_KW_VAR, NONTERM_DECLR }),
	product(NONTERM_FOREX, {  }),
	product(NONTERM_EXPR, { NONTERM_EXPR11 }),
	product(NONTERM_EXPR11, { NONTERM_EXPR11, T_COMMA, NONTERM_EXPR10 }),
	product(NONTERM_EXPR11, { NONTERM_EXPR10 }),
	product(NONTERM_EXPR10, { NONTERM_EXPR9, T_ASSIGN, NONTERM_EXPR10 }),
	product(NONTERM_EXPR10, { NONTERM_EXPR9, T_ASSIGN_ADD, NONTERM_EXPR10 }),
	product(NONTERM_EXPR10, { NONTERM_EXPR9, T_ASSIGN_SUB, NONTERM_EXPR10 }),
	product(NONTERM_EXPR10, { NONTERM_EXPR9, T_ASSIGN_MUL, NONTERM_EXPR10 }),
	product(NONTERM_EXPR10, { NONTERM_EXPR9, T_ASSIGN_DIV, NONTERM_EXPR10 }),
	product(NONTERM_EXPR10, { NONTERM_EXPR9, T_ASSIGN_POWER, NONTERM_EXPR10 }),
	product(NONTERM_EXPR10, { NONTERM_EXPR9 }),
	product(NONTERM_EXPR9, { NONTERM_EXPR9, T_OR, NONTERM_EXPR8 }),
	product(NONTERM_EXPR9, { NONTERM_EXPR8 }),
	product(NONTERM_EXPR8, { NONTERM_EXPR8, T_AND, NONTERM_EXPR7 }),
	product(NONTERM_EXPR8, { NONTERM_EXPR7 }),
	product(NONTERM_EXPR7, { NONTERM_EXPR7, T_BITWISE_OR, NONTERM_EXPR6 }),
	product(NONTERM_EXPR7, { NONTERM_EXPR7, T_BITWISE_AND, NONTERM_EXPR6 }),
	product(NONTERM_EXPR7, { NONTERM_EXPR7, T_BITWISE_XOR, NONTERM_EXPR6 }),
	product(NONTERM_EXPR7, { NONTERM_EXPR6 }),
	product(NONTERM_EXPR6, { NONTERM_EXPR6, T_RELOP, NONTERM_EXPR5 }),
	product(NONTERM_EXPR6, { NONTERM_EXPR5 }),
	product(NONTERM_EXPR5, { NONTERM_EXPR5, T_ADD, NONTERM_EXPR4 }),
	product(NONTERM_EXPR5, { NONTERM_EXPR5, T_SUB, NONTERM_EXPR4 }),
	product(NONTERM_EXPR5, { NONTERM_EXPR4 }),
	product(NONTERM_EXPR4, { NONTERM_EXPR4, T_MUL, NONTERM_EXPR3 }),
	product(NONTERM_EXPR4, { NONTERM_EXPR4, T_DIV, NONTERM_EXPR3 }),
	product(NONTERM_EXPR4, { NONTERM_EXPR4, T_KW_DOT, NONTERM_EXPR3 }),
	product(NONTERM_EXPR4, { NONTERM_EXPR3 }),
	product(NONTERM_EXPR3, { NONTERM_EXPR3, T_POWER, NONTERM_EXPR2 }),
	product(NONTERM_EXPR3, { NONTERM_EXPR3, T_KW_CROSS, NONTERM_EXPR2 }),
	product(NONTERM_EXPR3, { NONTERM_EXPR2 }),
	product(NONTERM_EXPR2, { T_NOT, NONTERM_EXPR2 }),
	product(NONTERM_EXPR2, { T_BITWISE_NOT, NONTERM_EXPR2 }),
	product(NONTERM_EXPR2, { T_INCREASE, NONTERM_EXPR2 }),
	product(NONTERM_EXPR2, { T_DECREASE, NONTERM_EXPR2 }),
	product(NONTERM_EXPR2, { T_SUB, NONTERM_EXPR2 }),
	product(NONTERM_EXPR2, { T_ADD, NONTERM_EXPR2 }),
	product(NONTERM_EXPR2, { NONTERM_EXPR1 }),
	product(NONTERM_EXPR1, { T_LB, NONTERM_EXPR, T_RB }),
	product(NONTERM_EXPR1, { NONTERM_EXPR1, T_INCREASE }),
	product(NONTERM_EXPR1, { NONTERM_EXPR1, T_DECREASE }),
	product(NONTERM_EXPR1, { NONTERM_FACTOR }),
	product(NONTERM_FACTOR, { T_NUMBER }),
	product(NONTERM_FACTOR, { T_STRING }),
	product(NONTERM_FACTOR, { T_ID }),
	product(NONTERM_FACTOR, { T_KW_NULL }),
	product(NONTERM_FACTOR, { T_KW_TRUE }),
	product(NONTERM_FACTOR, { T_KW_FALSE }),
	product(NONTERM_FACTOR, { T_ID, T_LB, NONTERM_CALLPAR, T_RB }),
	product(NONTERM_FACTOR, { T_ID, T_LB, T_RB }),
	product(NONTERM_FACTOR, { T_ID, NONTERM_STACC }),
	product(NONTERM_FACTOR, { T_KW_NEW, T_TYPE }),
	product(NONTERM_FACTOR, { T_KW_TYPEOF, T_LB, NONTERM_EXPR11, T_RB }),
	product(NONTERM_FACTOR, { T_KW_CROSS, T_LB, NONTERM_EXPR11, T_COMMA, NONTERM_EXPR11, T_RB }),
	product(NONTERM_FACTOR, { T_KW_DOT, T_LB, NONTERM_EXPR11, T_COMMA, NONTERM_EXPR11, T_RB }),
	product(NONTERM_FACTOR, { T_KW_ARRAY, T_LB, NONTERM_ARRAYP, T_RB }),
	product(NONTERM_FACTOR, { T_KW_MARTIX, T_LB, NONTERM_EXPR, T_COMMA, NONTERM_EXPR, T_RB }),
	product(NONTERM_FACTOR, { T_KW_VECTOR, T_LB, NONTERM_EXPR, T_RB }),
	product(NONTERM_FACTOR, { T_LT, NONTERM_VECTOR, T_GT }),
	product(NONTERM_FACTOR, { T_LT, T_GT }),
	product(NONTERM_FACTOR, { NONTERM_FACTOR, NONTERM_ACCESS }),
	product(NONTERM_ACCESS, { NONTERM_ACCESS, T_LMB, NONTERM_EXPR, T_RMB }),
	product(NONTERM_ACCESS, {  }),
	product(NONTERM_STACC, { NONTERM_STACC, T_DOT, T_ID }),
	product(NONTERM_STACC, {  }),
	product(NONTERM_ARRAY, { NONTERM_ARRAY, T_COMMA, NONTERM_EXPR }),
	product(NONTERM_ARRAY, { NONTERM_EXPR }),
	product(NONTERM_MATRIX, { NONTERM_MATRIX }),
	product(NONTERM_MATRIX, { NONTERM_MATRIXR }),
	product(NONTERM_MATRIX, { NONTERM_MATRIXR }),
	product(NONTERM_MATRIXR, { NONTERM_MATRIXR, T_COMMA, NONTERM_EXPR }),
	product(NONTERM_MATRIXR, { NONTERM_EXPR }),
	product(NONTERM_VECTOR, { NONTERM_VECTOR, T_COMMA, NONTERM_EXPR }),
	product(NONTERM_VECTOR, { NONTERM_EXPR }),
	product(NONTERM_CALLPAR, { NONTERM_CALLPAR, T_COMMA, NONTERM_EXPR }),
	product(NONTERM_CALLPAR, { NONTERM_EXPR }),
	product(NONTERM_BOOLEAN, { NONTERM_EXPR, T_RELOP, NONTERM_EXPR }),
	product(NONTERM_BOOLEAN, { NONTERM_BOOLEAN, T_AND, NONTERM_BOOLEAN }),
	product(NONTERM_BOOLEAN, { NONTERM_BOOLEAN, T_OR, NONTERM_BOOLEAN }),
	product(NONTERM_BOOLEAN, { T_NOT, NONTERM_BOOLEAN }),
	product(NONTERM_BOOLEAN, { T_LB, NONTERM_BOOLEAN, T_RB }),
	product(NONTERM_BOOLEAN, { T_KW_TRUE }),
	product(NONTERM_BOOLEAN, { T_KW_FALSE }),
	product(NONTERM_ARRAYP, { NONTERM_ARRAYP, T_COMMA, NONTERM_EXPR }),
	product(NONTERM_ARRAYP, { NONTERM_EXPR })

};

const int PRODUCT_NUM = sizeof(prod)/sizeof(product);

class item;

item * items[1000] = {0};
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
	product * core[200];
	int core_dot_at[200];
	product * noncore[200];
	int goto_from_token = -1;

	// int: 文法符号  int: 项（状态）
	map<int, int> goto_to_token;

	int reduce_prod = -1;

	bool added[PRODUCT_NUM] = {0};
	bool core_added[PRODUCT_NUM] = { 0};

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

	item() {
		id = item_id++;
	}

	void calc() {
		int add = 0;
		int d = 0;

		//cerr <<"ITEM " << id << "**************************************\n";
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
				if (it >= FIRST_TERM)
					return;
				//cerr <<"[dot_at=" << dot_at << "]\n" ;
				//p->output();
				//cerr <<exprs[it] << endl;
				for (int index=0 ;index<PRODUCT_NUM; index++) {
					//cerr <<"added[" << index << "]=" << added[index] << endl;
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
				//cerr<< endl;
			};

			for (int i=0; i<core_num; i++) {
				//cerr <<"core: " << i << endl;
				f(core[i], core_dot_at[i]);
			}
			for (int i=0; i<noncore_num; i++) {
				//cerr <<"Non-core: " << i << endl;
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
					goto_to_token.insert({ first_token, already });
				}
				else {
					item * _item = new item;
					items[current_item++] = _item;
					generated_items[first_token] = _item;
					goto_map.insert({ { p , first_token }, current_item - 1 });
					goto_to_token.insert({ first_token, current_item - 1 });
				}
			}
			if (_dot_at <= p->body.size())
				generated_items[first_token]->add_core(p, core_dot_at[i] + 1);
		}
		for (int i=0; i<noncore_num; i++) {
			product * p = noncore[i];
			// 如果这个表达式空，不产生新项
			if (p->body.size() == 0) {
				continue;
			}

			// 获得第一个词法单元
			int first_token = *(p->body.begin());
			// 如果这个文法符号已经有了对应的项那么直接加入核心产生式，否则新建项并加入
			if (generated_items[first_token] == nullptr) {
				// 如果这个项已经有对应的项了
				int already = check_goto(p, first_token);
				if (already != -1) {
					generated_items[first_token]=items[already];
					goto_to_token.insert({ first_token, already });
				}
				else {
					item * _item = new item;
					items[current_item++] = _item;
					generated_items[first_token] = _item;
					goto_map.insert({ { p , first_token }, current_item - 1 });
					goto_to_token.insert({ first_token, current_item - 1 });
				}
			}
			if (_dot_at <= p->body.size())
				generated_items[first_token]->add_core(p, 1);
		}
	}
};

vector<int>* first_list[100] = {0};
vector<int>* follow_list[100] = {0}; 

void first(int term);

int empty_num = 0;

//检查term是否可以推导出空串
bool first_has_empty(int term) {
	empty_num++;
	vector<int>* First = first_list[term];
	if (First == nullptr) {
		first(term);
		First = first_list[term];
	}
	for (auto it: *First) {
		if (it == -1) {
			cerr <<" ** Checked!";
			return true;
		}
	}
	empty_num--;

	return false;
}

bool check_ep_in_prod(int term) {
	for (int i=0; i<PRODUCT_NUM; i++) {
		if (prod[i].name == term && prod[i].body.size() == 0)
			return true;
	}
	return false;
}

int first_f_num = 0;

void push_back(vector<int>* First, int e) {
	if (find(First->begin(), First->end(), e) == First->end())
		First->push_back(e);
}

deque<int> first_statck;

void first(int term) {
	vector<int>* First = first_list[term];
	first_statck.push_back(term);
	if (First == nullptr) {
		first_list[term] = new vector<int>;
		First = first_list[term];
	}
	for (int i=0; i<PRODUCT_NUM; i++) {
		product * p = prod+i;
		if (p->name != term)
			continue;
		for (auto e: p->body) {
			if (e >= FIRST_TERM) {
				push_back(First, e);
				break;
			}
			//检查是不是有epselon
			// 如果是直接或间接左递归，因为当前表达式必须要构造完成
			if (find(first_statck.begin(), first_statck.end(), e) != first_statck.end()) {
				if (!check_ep_in_prod(e)) {
					break;
				}
				continue;
			}
			bool empty = first_has_empty(e);
			for (auto ee: *first_list[e]){
				if (ee != -1)
					push_back(First, ee);
			}
			if (!empty) {
				break;
			}

		}

		//这个产生式可以产生空串
		if (p->body.size() == 0) {
			cerr <<"Empty:" << term << endl;
			push_back(First, -1);
		}
	}
	first_statck.pop_back();
}

void follow(int nonterm, bool is_start) {
	//cerr <<"entering FOLLOW(" << exprs[nonterm] << ")\n";
	vector<int>* Follow = follow_list[nonterm];
	if (Follow == nullptr){
		vector<int>* v = new vector<int>;
		follow_list[nonterm] = v;
		if (is_start)
			v->push_back(T_EOI);
		Follow = v;
	}
	
	for (int i=0; i<PRODUCT_NUM; i++) {
		product * p = prod+i;
		auto it=p->body.begin();
		for (; it!=p->body.end(); ++it) {
			if (*it == nonterm)
				break;
		}
		if (it == p->body.end()) {
			continue;
		}
		auto it1 = it;
		it1++;
		if (it1 == p->body.end()) {
			//case 3
			vector<int>* FollowThis = follow_list[p->name];
			if (FollowThis == nullptr) {
				follow(p->name, p->name == START_SIGN);
				FollowThis = follow_list[p->name];
			}
			for (auto eee: *FollowThis) {
				push_back(Follow, eee);
			}
			continue;
		}
		//case 2
		for (it++; it != p->body.end(); ++it) {
			if (*it >= FIRST_TERM) {
				push_back(Follow, *it);
				break;
			}
			int has_empty = false;
			for (auto ee: *first_list[*it]) {
				if (ee == -1){
					has_empty = true;
					continue;
				}
				push_back(Follow, ee);
			}
			if (!has_empty)
				break;
		}
		// 如果beta每一项都有empty符号的话，最后出循环肯定it等于end();
		if (it == p->body.end()) {
			//another of case 3
			vector<int>* FollowThis = follow_list[p->name];
			if (FollowThis == nullptr) {
				follow(p->name, p->name == START_SIGN);
				FollowThis = follow_list[p->name];
			}
			for (auto eee: *FollowThis) {
				push_back(Follow, eee);
			}
		}
	}
	//cerr <<"exit FOLLOW(" << exprs[nonterm] << ")\n";
}

// 检查goto函数是否存在
int check_goto(product * p, int token) {
	auto it = goto_map.find(pair<product*, int> (p, token));
	if (it == goto_map.end()) {
		return -1;
	}
	return it->second;
}

int main() {
	cerr <<"Production: \n";
	for (product& t: prod)
		t.output();

	for (int i=0; i<=LAST_NONTERM; i++) {
		if (first_list[i] == nullptr)
			first(i);
	}
	
	cerr <<"\nFirst functions:\n";
	for (int i=0; i<100; i++) {
		vector<int>* First = first_list[i];
		if (!First)
			continue;

		cerr <<"FIRST(" << exprs[i] << ")={ ";
		for (int e: *First) {
			cerr <<(e == -1? "e" : exprs[e]) << " , ";
		}
		cerr <<" }" << endl;
	}

	for (int i=0; i<=LAST_NONTERM; i++) {
		if (follow_list[i] == nullptr)
			follow(i, i == START_SIGN);
	}

	cerr <<endl;
	cerr <<"\nFollow functions:\n";
	for (int i=0; i<100; i++) {
		vector<int>* Follow = follow_list[i];
		if (!Follow)
			continue;

		cerr <<"FOLLOW(" << exprs[i] << ")={";
		for (int e: *Follow) {
			cerr <<(e == -1? "e" : exprs[e]) << " , ";
		}
		cerr <<" }" << endl;
	}

	items[0] = new item;
	
	items[0]->add_core(prod, 0);
	items[0]->calc();
	items[0]->generate_next();

	current_calced_item+=1;
	while (current_calced_item != current_item) {
		///cerr <<"calced = " << current_calced_item << ", all = " << current_item;
		//getchar();
		item * it = items[current_calced_item];
		it->calc();
		it->generate_next();

		current_calced_item++;
	}

	int sat[400][400];
	memset((void*)sat, -1, 400*400*sizeof(int));

	cerr <<endl;
	for(int k=0; k<current_item; k++) {
		item * it = items[k];
		cerr <<"Item I["<< k <<"]:\n";
		for (int i=0; i< it->core_num; i++) {
			cerr  << "(" << it->core_dot_at[i] << ") ";
			it->core[i]->output();
		}
		for (int i=0; i< it->noncore_num; i++) {
			cerr <<"(0) ";
			it->noncore[i]->output(); 
		}
		cerr <<endl;
	}

	//cerr <<check_goto(prod, N_E);
	cerr <<"GOTO(I[i], a) values:\n";
	for (int i=0; i<current_item; i++) {
		for (auto it : items[i]->goto_to_token) {
			cerr <<"GOTO(i[" << i << "], " << exprs[it.first] << " )=s" << it.second << endl;
			sat[i][it.first] = it.second;
		}	
	}

	cerr <<"Reduces:\n";
	for (int i=0; i<current_item; i++) {
		if (items[i]->reduce_prod == -1)
			continue;
		product * p = prod + items[i]->reduce_prod;
		if (follow_list[p->name] == nullptr)
			continue;
		for (int e : *follow_list[p->name]) {
			if (p->name == AUG_G_PROD && e == END_PARSE_FLAG){
				cerr <<"I[" << i << ", " << exprs[e] << "]=accept \n";
				sat[i][e] = -2;
				continue;
			}
			cerr <<"I[" << i << ", " << exprs[e] << "]=r" << items[i]->reduce_prod << " (aka: ";
			prod[items[i]->reduce_prod].output();
			sat[i][e] = items[i]->reduce_prod + 1000;
		}
	}

	cerr <<endl;
	cout <<"#ifndef _MIYUKI_SATABLE_H\n"
			"#define _MIYUKI_SATABLE_H\n\n"
			"#include <stdint.h>\n\n"
			"#define err -1\n"
			"#define accept -2\n"
			"#define S(x) x\n"
			"#define R(x) (x+1000)\n\n"
			"namespace Miyuki {\n"
			"	enum _grammer_syms {\n"
			"		__START_POS = -1, ";

	for (int i=0; i<TOKEN_NUM; i++) {
		if (i % 10 == 0)
			cout << endl << "		";
		if (i == NONTERM_NUM)
			cout << endl << "		";
		cout << exprs2[i] << ",";
	}

	cout <<"\n"
			"	};\n\n"
			"	const int16_t _syntax_analyse_table[" << current_item << "][" << (TOKEN_NUM-1) << "] = {";

	for (int i=0; i<current_item; i++) {
	cout <<"\n		{";
		for (int j=1; j<TOKEN_NUM; j++) {
			int v = sat[i][j];

			if (v == -1) {
				cout <<"err, ";
			}
			else if (v == -2) {
				cout <<"accept, ";
			}
			else if (v >= 1000) {
				cout <<"R(" << (v-1000) << "), ";
			}
			else
				cout <<"S(" << v << "), ";
		}
		//for (auto it : items[i]->goto_to_token) {
		//	cerr <<"GOTO(i[" << i << "], " << exprs[it.second] << " )=s" << it.first << endl;
		//}	
	cout <<" },";
	}

	cout <<" \n	};\n"
			"}\n\n"
			"#undef accept\n"
			"#undef S\n"
			"#undef R\n"
			"#undef err\n\n"
			"#endif";

	for (int i=0; i<current_item; i++) {
		if (items[i])
			delete items[i];
	}

	for (int i=0; i<100; i++) {
		if (follow_list[i])
			delete follow_list[i];
		if (first_list[i])
			delete first_list[i];
	}
}