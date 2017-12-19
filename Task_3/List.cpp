#include "stdafx.h"
#include "List.h"


TNode::TNode(int num) : field(num), next(nullptr), pred(nullptr) {}
TNode::TNode() {
	TNode::TNode(0);
}

TList::TList() : head(nullptr), tail(nullptr) {}

void TList::AddEl(int num) {
	if (head == nullptr) {
		head = new TNode(num);
		tail = head;
	}
	else {
		tail->next = new TNode(num);
		tail->next->pred = tail;
		tail = tail->next;
	}
}

void TList::DelEl() {
	if (tail->pred != nullptr) {
		tail = tail->pred;
		delete tail->next;
		tail->next = nullptr;
	}
	else {
		delete tail;
		tail = nullptr;
		head = nullptr;
	}
}

void TList::Clear() {
	while (head != nullptr) {
		DelEl();
	}
}

void TList::Print() {
	TNode* p = head;
	if (p != nullptr) {
		std::cout << p->field;
		p = p->next;
	}
	while (p != nullptr) {
		std::cout << '-' << p->field;
		p = p->next;
	}
}

