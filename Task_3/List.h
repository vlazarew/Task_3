#pragma once
class TNode {
public:
    int field;
	TNode* next;
	TNode* pred;

	TNode(int num);
	TNode();
};

class TList {
private:
	TNode* head;
	TNode* tail;
public:
	TList();

	void AddEl(int num);
		
	void DelEl();

	void Clear();

	void Print();

};

