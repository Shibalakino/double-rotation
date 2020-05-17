#include <iostream>
using namespace std;
#define STOP '*'
typedef struct Node* Point;
struct Node {
	char info;
	Point left;
	Point right;
};
void PushInDoubleLinkedList(Point& left, Point& right, char c);
void WriteDoubleLinkedList(Point& left, Point& right);
void ReadStack(Point left);
int main()
{
	char c;
	Point node = new(Node);
	cout << "Plese input the first symbol\n";
	cin >> c;
	node->info = c;
	node->left = NULL;
	node->right = NULL;
	Point leftNode = node;
	Point rightNode = node;
	cout << "Please input the next symbols:\n";
	WriteDoubleLinkedList(leftNode, rightNode);
	cout << "Your deck contains the next symbols:\n";
	ReadStack(leftNode);
	return 0;
}
void PushInDoubleLinkedList(Point& leftNode, Point& rightNode, char c)
{
	Point node = new (Node);
	node->info = c; 
	node->left = NULL;
	leftNode->left = node;
	node->right = leftNode; 
	leftNode = node;
}

void WriteDoubleLinkedList(Point& leftNode, Point& rightNode)
{
	char c;
	do
	{
		cin >> c;
		if (c != STOP)
		{
			PushInDoubleLinkedList(leftNode, rightNode, c);
		}
	} while (c != STOP);
}
int Eof(Point top)
{
	return top == NULL;
}
void ReadTop(Point* top, char* c)
{
	*c = (*top)->info;
	*top = (*top)->left;
}

void ReadStack(Point top)
{
	char c;
	while (!Eof(top))
	{
		ReadTop(&top, &c);
		cout << c << endl;
	}
}
void Pop(Point& top)
{
	Point tmp;
	tmp = top;
	top = top->left;
	delete tmp;
}