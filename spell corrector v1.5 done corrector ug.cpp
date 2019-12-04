
#include<iostream>
#include<fstream>
#include<windows.h>
#include<string.h>
#define size 50
using namespace std;
class node{
	public:
		string data;
		node *left, *right, *previous;
};
class BST{
	public:
		node *root;
	public:
		BST(){
			root = NULL;
		}
//compare strings
	int biggerString(string str1, string str2){
		int com = str1.compare(str2);
		return com;
	}
// 1- creating BST
		void creatList(string value){
			node *temp = new node;
			node *copyRoot = root;
			temp -> data = value;
			temp -> left = NULL;
			temp -> right = NULL;
			if(root == NULL){
				root = temp;
				copyRoot = temp;
			}
			else{
				while(copyRoot != NULL ){
					if(biggerString(temp -> data, copyRoot -> data) == 1){   //temp -> data < copyRoot -> data 
						if(copyRoot -> left == NULL){
							copyRoot -> left = temp;
							temp -> previous = copyRoot;
							return;
						}else{
							copyRoot = copyRoot -> left;
						}
					}else{
						if(copyRoot -> right == NULL){
							copyRoot -> right = temp;
							temp -> previous = copyRoot;
							return;
						}else{
							copyRoot = copyRoot -> right;
						}
					}
				}
			}
			
		}
// 2- printing BST in inorder
		void printInorder(node *temp){
			if(temp != NULL){
				printInorder(temp -> left);
				cout << endl << temp -> data;
				printInorder(temp -> right);
			}
		}
// 2- printing BST in postorder
		void printPostorder(node *temp){
			if(temp != NULL){
				printInorder(temp -> left);
				printInorder(temp -> right);
				cout << temp -> data;
			}
		}
// 2- printing BST in preorder
		void printPreorder(node *temp){
			if(temp != NULL){
				cout << temp -> data;
				printInorder(temp -> left);
				printInorder(temp -> right);
			}
		}
// 5- search in BST
		int search(string value, node *temp){
			if(temp == NULL){
				cout << endl << "Value is not found in BST!";
				return 0;
			}else if(biggerString(value, temp -> data) == 0){                       //value == temp -> data
				cout << endl << "value is found that is: " << temp -> data << endl;
				return 1;
			}else{
				if(biggerString(value, temp -> data) == 1){                         //value < temp -> data
					search(value, temp -> left);
				}else{
					search(value, temp -> right);
				}
			}
			
		}

//

		int hamingDistance(string str1, string str2){
			int i = 0;
			int distance = 0;
			while(i < str1.length() || i < str2.length()){
				if(str1[i] != str2[i]){
					distance++;
				}
				i++;
			}
			return distance;
		}

		void correct(string value, node *temp, int &i, string arr[50]){
			
			if(temp != NULL){
				correct(value, temp -> left, i, arr);
				if(hamingDistance(value, temp -> data) <= 2){
					arr[i] = temp -> data;
					
					i++;
				}
				correct(value, temp -> right, i, arr);
			}
		}


		
};
int main(){
	int i = 0;
	string arr[size];
	system("color 84");
	BST B;
	
	string line;
	ifstream mfile("spellDic.txt");
	if (mfile.is_open()){
		while(getline(mfile,line)){
    		B.creatList(line);
    	}
    	mfile.close();
	}
	else cout << "Unable to open file";

	cout << endl << "enter word that you want to find: ";
	string value = "";
	cin >> value;
	B.correct(value, B.root, i, arr);
	
	cout << endl << "select the nearest words by entering the number of word" << endl << endl;
	for(int j = 0; j < i; j++){
		cout << "\tEnter: " << j << " for: " << arr[j] << endl;
	}
	
	cout << endl << "Enter Number of Word you want to select: ";
	int selection;
	cin >> selection;
	cout << endl << "Your Selected word is: " << arr[selection];
	return 0;
}


