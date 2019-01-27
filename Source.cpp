#include <iostream>
#include <string>
#include <ctime>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;



class LL {
public:
	LL() {
		head = nullptr;
	}
	// insert element a
	void insert(int a) {
		Node* n = new Node(a);
		if (head == nullptr) {
			head = n;
			return;
		}
		Node* p = head;
		while ((p->next != nullptr) && (p->data > a)) {
			p = p->next;
		}
		if (p->next != nullptr) {
			n->next = p->next;
			p->next = n;
		} else {
			p->next = n;
		}
	}

	void insert_at_head(int a) {
		Node* n = new Node(a);
		n->next = head;
		head = n;
	}

	// remove the first element
	int remove_first() {
		int ret;
		if (head != nullptr) {
			ret = head->data;
			Node* temp = head;
			head = head->next;
			delete temp;
			return ret;
		}
		else {
			return -1;
		}

	}
	//return the element at a certain index
	int withdraw(int a) {
		Node* p = head;
		int index = 0;
		while (p != nullptr && index != a) {
			p = p->next;
			index++;
		}
		if (p != nullptr) {
			return p->data;
		}
		return -1;
	}

private:
	struct Node {
		int data;
		Node* next;
		Node(int a) {
			data = a;
			next = nullptr;
		}
	};
	Node* head;
};

int writeFile(string name, int* nums, int len)
{
	ofstream myfile;
	myfile.open(name + ".txt");
	myfile << "Output File: " + name + "\n";
	for (int i = 0; i < len; i++) {
		myfile << nums[i] << endl;
	}

	myfile.close();
	return 0;
}

int main() {
	//comment here
	
	
	const int MAX_ITERS = 1000;
	const int MAX_RAND = 1000;
	
	srand (time(NULL));
	int extraction_order[MAX_ITERS];
	int nums_to_insert[MAX_ITERS];
	for (int i = 0; i < MAX_ITERS; i++) { 
		extraction_order[i] = i; 
		nums_to_insert[i] = rand() % MAX_RAND;
	}
	random_shuffle(&extraction_order[0], &extraction_order[MAX_ITERS]);

	//Example 1: Array
	cout << "starting to test Array:" << endl;
	clock_t begin = clock();

	int arr[MAX_ITERS];

	cout << "inserting " << MAX_ITERS << " random numbers into Array" << endl;
	for (int i = 0; i < MAX_ITERS; i++) {
		arr[i] = nums_to_insert[i];
	}

	cout << "retrieving " << MAX_ITERS << " random numbers from Array" << endl;
	for (int i = 0; i < MAX_ITERS; i++) {
		cout << arr[extraction_order[i]] << " ";
		int x = arr[extraction_order[i]];
	}


	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

	cout << endl << "Elapsed Time for Array: " << elapsed_secs << endl << endl << endl;
	//writeFile("example1_array", arr, MAX_ITERS);

	//LL
	begin = clock();

	LL linkedList;

	cout << "inserting " << MAX_ITERS << " random numbers into Linked List" << endl;
	for (int i = 0; i < MAX_ITERS; i++) {
		linkedList.insert(nums_to_insert[i]);
	}

	cout << "retrieving " << MAX_ITERS << " random numbers from Linked List" << endl;
	for (int i = 0; i < MAX_ITERS; i++) {
		cout << linkedList.withdraw(extraction_order[i]) << " ";
		int x = linkedList.withdraw(extraction_order[i]);
	}

	end = clock();
	elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

	cout << endl << "Elapsed Time for Linked List: " << elapsed_secs << endl;

	/*const int MAX_ITERS = 100000;
	const int MAX_RAND = 100000;
	//Example 2
	srand(time(NULL));
	int rand_iters = rand() % MAX_ITERS;
	int nums_to_insert[MAX_ITERS];
	for (int i = 0; i < rand_iters; i++) {
		nums_to_insert[i] = rand() % MAX_RAND;
	}

	// Array
	cout << "starting to test Array:" << endl;
	clock_t begin = clock();

	int arr[MAX_ITERS];

	cout << "inserting " << rand_iters << " random numbers into Array" << endl;
	for (int i = 0; i < rand_iters; i++) {
		arr[i] = nums_to_insert[i];
	}

	cout << "retrieving " << rand_iters << " random numbers from Array" << endl;
	for (int i = rand_iters - 1; i >= 0; i--) {
		//cout << arr[i] << " ";
		int x = arr[i];
	}


	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

	cout << endl << "Elapsed Time for Array: " << elapsed_secs << endl;
	//cout << "Wasted space " << sizeof(int) * (MAX_ITERS - rand_iters) << " bytes" << endl << endl;

	//LL
	begin = clock();

	LL linkedList;

	cout << "inserting " << rand_iters << " random numbers into Linked List" << endl;
	for (int i = 0; i < rand_iters; i++) {
		linkedList.insert_at_head(nums_to_insert[i]);
	}

	cout << "retrieving " << rand_iters << " random numbers from Linked List" << endl;
	for (int i = 0; i < rand_iters; i++) {
		int x = linkedList.remove_first();
		//cout << x << " ";
	}

	end = clock();
	elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

	cout << endl << "Elapsed Time for Linked List: " << elapsed_secs << endl;
	//cout << "Wasted space " << sizeof(int *) * (rand_iters) << " bytes" << endl;*/

}