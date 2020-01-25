#include<iostream>
//#include<stdlib.h>
using namespace std;
#define max_size 20

//ԭ��(n����)�����ݽṹ 
typedef struct origin_tree {
	char data;
	origin_tree *parent;
	int cnChild;
	origin_tree *child[max_size];
}origin_tree;

//�������ֵܱ�ʾ�� 
typedef struct LCR
{
	char element;
	LCR *first_child;
	LCR *next_sibling;
}LCR;

//ԭ���Ľ���������ͺ������ 
origin_tree *InitTree(char ch);
origin_tree *InsertNode(origin_tree *T, char ch);
void post_order(origin_tree *T);

//LCR�������Ľ����������������� 
LCR *newTree(char ch);
LCR *addSibling(LCR *T, char ch);
LCR *addChild(LCR *T, char ch);
void in_order(LCR *T);

void transform(LCR *tree, origin_tree *T);

void input1();
void input2();

int main()
{
	input1();
	input2();
}

origin_tree *InitTree(char ch) {
	origin_tree *Tree;
	//Tree = (origin_tree *)malloc(sizeof(origin_tree));
	Tree = new origin_tree[sizeof(origin_tree)];
	Tree->data = ch;
	Tree->cnChild = 0;
	Tree->parent = NULL;
	//memset;
	return Tree;
}

origin_tree *InsertNode(origin_tree *T, char ch) {
	int cnChild = T->cnChild;
	origin_tree *Temp;
	Temp = new origin_tree[sizeof(origin_tree)];
	Temp->data = ch;
	Temp->parent = T;
	T->child[cnChild] = Temp;
	T->cnChild++;
	//cout << Temp->data;
	return Temp;
}

void post_order(origin_tree *T) {
	int depth = 0;
	int i;
	if (T == NULL) return;
	for (i = 0; i < T->cnChild; i++) {
		//depth++;
		post_order(T->child[i]);
		//depth--;
		//cout << T->data << " ";
	}
	cout << T->data << " ";
}

LCR *newTree(char ch) {
	LCR *T = new LCR;
	T->element = ch;
	T->first_child = T->next_sibling = NULL;
	return T;
}

LCR *addSibling(LCR *T, char ch) {
	if (T == NULL) return NULL;
	while (T->next_sibling) {
		T = T->next_sibling;
	}
	T->next_sibling = newTree(ch);
	return T->next_sibling;
}

LCR *addChild(LCR *T, char ch) {
	if (T == NULL) return NULL;
	if (T->first_child) {
		return addSibling(T->first_child, ch);
	}
	else {
		T->first_child = newTree(ch);
		return T->first_child;
	}
}

void in_order(LCR *T) {
	if (T) {
		in_order(T->first_child);
		cout << T->element << " ";
		in_order(T->next_sibling);
	}
}

void transform(LCR *tree, origin_tree *T) {
	LCR *Node;
	Node = new LCR[sizeof(LCR)];
	if (T == NULL) return;
	for (int i = 0; i < T->cnChild; i++) {
		Node = addChild(tree,T->child[i]->data);
		transform(Node, T->child[i]);
	}
}

void input1() {
	cout << "��������1��" << endl;
	
	origin_tree *Tree = InitTree('R');
	origin_tree *p1 = InsertNode(Tree, 'A');
	origin_tree *p2 = InsertNode(Tree, 'B');
	origin_tree *p3 = InsertNode(Tree, 'C');
	InsertNode(p1, 'D');
	InsertNode(p1, 'E');
	origin_tree *p4 = InsertNode(p3, 'F');
	InsertNode(p4, 'G');
	InsertNode(p4, 'H');
	InsertNode(p4, 'K');
	cout << "ԭ���ĺ��������      ";
	post_order(Tree);

	cout << endl;

	
	LCR *tree = newTree(Tree->data);
	transform(tree, Tree); //Kruth transform 
	cout << "LCRS�����������������";
	in_order(tree);
	cout << endl;
}

void input2(){
	cout << endl << "��������2��" << endl;
	
	origin_tree *Tree = InitTree('A');
	origin_tree *p1 = InsertNode(Tree, 'B');
	origin_tree *p2 = InsertNode(Tree, 'C');
	origin_tree *p3 = InsertNode(Tree, 'D');
	InsertNode(p1, 'E');
	InsertNode(p1, 'F');
	InsertNode(p1, 'G');
	InsertNode(p2, 'H');
	InsertNode(p3, 'K');
	InsertNode(p3, 'I');
	InsertNode(p3, 'J');
	cout << "ԭ���ĺ��������      ";
	post_order(Tree);

	cout << endl;

	
	LCR *tree = newTree(Tree->data);
	transform(tree, Tree); //Kruth transform 
	cout << "LCRS�����������������";
	in_order(tree);
	cout << endl;	
}
