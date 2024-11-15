#include <iostream>  
using namespace std;
void pattern1(int n) {
//	int n = 5;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << "* ";
		}
		cout << endl;
	}
}
void pattern2(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cout << "* ";
		}
		cout << endl;
	}
}
void pattern3(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cout << j << " ";
		}
		cout << endl;
	}
}
void pattern4(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cout << i << " ";
		}
		cout << endl;
	}
}
void pattern5(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n - i + 1; j++) {
			cout << "* ";
		}
		cout << endl;
	}
}
void pattern6(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - i + 1; j++) {
			cout << j << " ";
		}
		cout << endl;
	}
}
void pattern7(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= n - i - 1; j++) {
			cout << " ";
		}
		for (int k = 1; k <= 2 * i + 1; k++) {
			cout << "*";
		}
		for (int l = 1; l <= n - i - 1; l++) {
			cout << " ";
		}
		cout << endl;
	}
}
void pattern8(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			cout << " ";
		}
		for (int j = 0; j < 2*n - (2 * i + 1); j++) {
			cout << "*";
		}
		for (int j = 0; j< i; j++) {
			cout << " ";
		}
		cout << endl;
	}
}
void pattern10(int n) {
	for (int i = 1; i <= 2*n-1; i++)
	{
		int stars = i;
		if (i > n) 
		{
			stars = 2 * n - i;
		}
		for (int j = 1; j <= stars; j++)
		{
			cout << "* ";
		}

		cout << endl;
	}
}
void pattern11(int n) {
	for (int i = 0; i < n; i++)
	{
		int start = 1;
		if (i % 2 == 0)
		{
			start = 1;
		}
		else start = 0;
		for (int j = 0; j <= i; j++)
		{
			cout << start << " ";
			start = 1 - start;
		}
		cout << endl;
	}
}
void pattern12(int n) {
	int space = 2 * (n - 1);
	for (int i = 1; i <= n; i++)
	{
		//numbers
		for (int j = 1; j <= i; j++)
		{
			cout << j;
		}
		//spaces
		for (int j = 1; j <= space; j++)
		{
			cout << " ";
		}

		//numbers
		for (int j = i; j >= 1; j--)
		{
			cout << j;
		}
		cout << endl;
		space -= 2;
	}
}
void pattern13(int n) {
	int num = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << num << " ";
			num += 1;
		}
		cout << endl;
	}
}
void pattern14(int n) {
	
	for (int i = 1; i <= n; i++)
	{
		char letter = 65;
		for (int j = 0; j < i; j++)
		{
			cout << letter << " ";
			letter += 1;
		}
		cout << endl;

	}
}
void pattern15(int n) {
	for (int i = 1; i <= n; i++)
	{
		char letter = 65;
		for (int j = n; j >= i; j--)
		{
			cout << letter << " ";
			letter += 1;
		}
		cout << endl;

	}
}
void pattern16(int n) {
	char letter = 65;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{

			cout << letter << " ";
		}
		cout << endl;
		letter += 1;

	}
}
void pattern17(int n) {
	for (int i = 0; i < n; i++) {
		char c = 65;

		for (int j = 1; j <= n - i - 1; j++) {
			cout << " ";
		}
		for (int k = 1; k <= 2 * i + 1; k++) {
			cout << c;
			
			if (k > i)
			{
				c -= 1;
			}
			else
			{
				c += 1;
			}
		}
		for (int l = 1; l <= n - i - 1; l++) {
			cout << " ";
		}
		cout << endl;
	}
}
void pattern18(int n) {
	for (int i = 0; i < n; i++)
	{
		char c = 65 + n - 1;
		for (int j = 0; j <= i; j++) {
			cout << c;
			c--;
		}
		cout << endl;
	}
}
void pattern19(int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			cout << "*";
		}
		for (int j = 0; j < 2 * i; j++)
		{
			cout << " ";
		}
		for (int j = 0; j < n - i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	int iniState = 2*n - 2;
	for (int i = 1; i <= n; i++)
	{
		
		for (int j = 1; j <= i; j++) {
			cout << "*";
		}
		for (int j = 0; j < iniState; j++)
		{
			cout << " ";
		}
		for (int j = 1; j <= i; j++) {
			cout << "*";
		}
		iniState -= 2;
		cout << endl;
	}
}
void pattern20(int n) {
	int iniState = 2 * n - 2;
	for (int i = 1; i <= 2*n-1; i++)
	{
		int stars = i;
		if (i > n) 
		{
			stars = 2 * n - i; 
		}
		//stars
		for (int j = 1; j <= stars; j++) {
			cout << "*";
		}
		//spaces
		for (int j = 1; j <= iniState; j++)
		{
			
			cout << " ";
		}
		//stars
		for (int j = 1; j <= stars; j++) {
			cout << "*";
		}
		
		cout << endl;
		if (i < n)
		{
			iniState -= 2;
		}
		else
		iniState += 2;
	}
} //needs revision
void pattern21(int n) {
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) {
			if (i == 1 || i == n  || j == 1 || j == n )
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
			
		}
		cout << endl;
	}
}
void pattern22(int n) {
	for (int i = 0; i < 2*n-1; i++)
	{
		for (int j = 0; j < 2 * n - 1; j++) {
			int top = i;
			int left = j;
			int right = (2 * n - 2) - j;
			int down = (2 * n - 2) - i;
			cout << (n - min(min(top, down), min(left, right)));
		}
		cout << endl;
	}

	//cout << "bk teri mkc randi ke pille";
} //revision needed
 
int main() {
	pattern22(3);
}
	//cout <<p.first << " " <<p.second.second <<
/*
#include <iostream>
#include <vector>

using namespace std;


//struct Node {
//	int data;
//	struct Node* left;
//	struct Node* right;
//
//	Node(int val) {
//		data = val;
//		left = NULL;
//		right = NULL;
	}
};

void preorder(struct Node* root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(struct Node* root) {
	if (root == NULL)
	{
		return;
	}
	inorder(root->left);
	cout << root->data<<" ";
	inorder(root->right);
}

void postorder(struct Node* root) {
	if (root == NULL)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}

/*
			1
		   / \
		  2    3
		 / \  /  \ 
		4   5 6   7


int main() {
	struct Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	preorder(root);
	cout << endl;
	inorder(root);
	cout << endl;
	postorder(root);
	return 0;
}
*/