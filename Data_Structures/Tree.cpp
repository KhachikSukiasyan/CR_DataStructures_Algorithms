#include <iostream>
using namespace std;
#include <queue>

template <class T>
struct Node {
	T info;
	Node<T>* left;
	Node<T>* right;
	Node(T x, Node<T>* left = 0, Node<T>* right = 0) {
		info = x;
		this->left = left;
		this->right = right;
	}
};
template <class T>
class Tree {
public:
	Node<T>* root;
	Tree(Node<T>* r) { root = r; }
};

template <class T>
void visit(Node<T>* t) {
	if (t != NULL)
		cout << t->info << ' ';
}

template <class T>
void treeLengthTraverse(Node<T>* root, void visit(Node<T>* t))
{
	Node<T>* p = root;
	queue<Node<T>*> q;

	q.push(p);
	while (!q.empty())
	{
		p = q.front();
		q.pop();
		visit(p);
		if (p->left != NULL)
			q.push(p->left);
		if (p->right != NULL)
			q.push(p->right);
	}
}
template <class T>
int maxDepth(Node<T>* node)
{
	if (node == NULL)
		return -1;
	else
	{
		int lDepth = maxDepth(node->left);
		int rDepth = maxDepth(node->right);

		if (lDepth > rDepth)
			return(lDepth + 1);
		else return(rDepth + 1);
	}
}

std::queue<Node<char>*> Q;
template <class T>
void treeLengthTraverseV2(Node<T>* root, void visit(Node<T>* t))
{
	visit(root);
	if (root->left != NULL)
		Q.push(root->left);
	if (root->right != NULL)
		Q.push(root->right);

	if (!Q.empty())
	{
		root = Q.front();
		Q.pop();
		treeLengthTraverseV2(root, visit);
	}
}


//int main()
//{
//	Node<char> g('G');
//	Node<char> d('D', NULL, &g);
//	Node<char> b('B', &d, NULL);
//	Node<char> h('H');
//	Node<char> i('I');
//	Node<char> e('E', &h, &i);
//	Node<char> f('F');
//	Node<char> c('C', &e, &f);
//	Node<char> a('A', &b, &c);
//	Tree<char> tree(&a);
//	//-----------
//	Node<char> Ba('B');
//	Node<char> Aa('A', &Ba);
//
//
//	treeLengthTraverseV2(tree.root, visit);
//	cout << maxDepth(&Aa);
//}


