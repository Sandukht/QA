#include <iostream>
#include <fstream>
using namespace std;
struct node { int data; node* next; };

bool is_equal(node* p1, node* p2) {
	node* l1 = p1;
	node* l2 = p2;
	while (l1 != nullptr && l2 != nullptr)
	{
		if (l1->data != l2->data) {
			return false;
		}
		else {
			l1 = l1->next;
			l2 = l2->next;
		}
	}
	if (!l1 && !l2) {
		return true;
	}
	else return false;

}
void add_element(node*& f, int x) {
	node* p;
	if (f == 0) {
		node* q = new node;
		q->data = x;
		q->next = nullptr;
		f = q;
		return;
	}

	for (p = f; p->next != nullptr; p = p->next)
	{
	}
	node* q = new node;
	q->data = x;
	q->next = nullptr;
	p->next = q;

}
int main() {
	ifstream a("testcase.txt");
	ofstream b("logfile.txt");
	while (!a.eof()) {
		node* first = nullptr;
		int n;
		a >> n;
		for (int i = 0; i < n; i++) {
			int c;
			a >> c;
			add_element(first, c);
		}
		//cucakin avelacni element
		int d;
		a >> d;
		add_element(first, d);
		//creating result
		node* result = nullptr;
		for (int i = 0; i < n + 1; i++) {
			int c;
			a >> c;
			add_element(result, c);
		}
		if (is_equal(first, result)) {
			b << "passed" << "\n";
		}
		else
			b << "failed\n";

	}
	return 0;
}


