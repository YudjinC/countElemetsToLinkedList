#include <iostream>
#include <ctime>

using namespace std;

struct Node {
	int data;
	Node *next;
};

Node *createNode(int data);
void pushBack(Node *&head, int data);
int countListValue(Node *head);
void outputList(Node *head);

int main() {
	srand(time(NULL));

	int count;

	Node *head = new Node;
	head = nullptr;

	for (int i = 0; i < (rand() % 10 + 1); i++) {
		pushBack(head, rand() % 90);
	}

	count = countListValue(head);

	cout << "Count: " << count << endl;
	cout << "List elements:" << endl;
	outputList(head);
}

Node *createNode(int data) {
	Node *newNode = new Node;
	newNode->data = data;
	newNode->next = nullptr;

	return newNode;
}

void pushBack(Node *&head, int data) {
	Node *newNode = new Node;
	newNode = createNode(data);

	if (head == nullptr) {
		head = newNode;
		return;
	}

	Node *current = new Node;
	current = head;
	while (current->next != nullptr) {
		current = current->next;
	}
	current->next = newNode;
}

int countListValue(Node *head) {
	Node *current = head;

	int i = 0;
	while (current != nullptr) {
		current = current->next;
		i++;
	}

	return i;
}

void outputList(Node *head) {
	Node* current = head;

	while (current != nullptr) {
		cout << current->data << "\t";
		current = current->next;
	}
}