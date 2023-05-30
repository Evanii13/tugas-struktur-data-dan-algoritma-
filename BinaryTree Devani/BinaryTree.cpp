#include <iostream>
#include "BinaryTree.h"

using namespace std;

BinaryTree::BinaryTree () {
    root = NULL;
}
void BinaryTree::insertNode(int insertData){
	root = insertNodeRecursive(root, insertData);
}

Node *BinaryTree::insertNodeRecursive(Node *currentRoot, int insertData){
	if (currentRoot==NULL){
		currentRoot = new Node();
		currentRoot->data = insertData;
		return currentRoot;
	}
	
	if (insertData < currentRoot->data){
		currentRoot->left = insertNodeRecursive(currentRoot->left, insertData);
	}
	
	else if (insertData > currentRoot->data){
		currentRoot->right = insertNodeRecursive(currentRoot->right, insertData);
	}
	
	return currentRoot;
}




void BinaryTree::inOrder(){
	inOrderRecursive(root);
}

void BinaryTree::inOrderRecursive(Node *currentRoot){
	if (currentRoot!=NULL){
		inOrderRecursive(currentRoot->left);
		cout << currentRoot->data << ", ";
		inOrderRecursive(currentRoot->right);
	}
}

void BinaryTree::preOrder(){
	preOrderRecursive(root);
}

void BinaryTree::preOrderRecursive(Node *currentRoot){
	if (currentRoot!=NULL){
		cout << currentRoot->data << ", ";
		preOrderRecursive(currentRoot->left);
		preOrderRecursive(currentRoot->right);
	}
}


void BinaryTree::postOrder(){
	postOrderRecursive(root);
}

void BinaryTree::postOrderRecursive(Node *currentRoot){
	if (currentRoot!=NULL){
		postOrderRecursive(currentRoot->left);
		postOrderRecursive(currentRoot->right);
		cout << currentRoot->data << ", ";
	}
}
void BinaryTree::searchNode(int nilai) {
    Node* hasil = searchNodeRecursive(root, nilai);
    if (hasil != NULL) {
        cout << "Node dengan nilai " << hasil->data << " ditemukan" << endl;
    } else {
        cout << "Node tidak ditemukan" << endl;
    }
}


Node* BinaryTree::searchNodeRecursive(Node*currentRoot, int nilai){
	
	if (currentRoot == NULL || currentRoot->data == nilai) {
        return currentRoot;
    } else if (nilai < currentRoot->data) {
        return searchNodeRecursive(currentRoot->left, nilai);
    } else {
        return searchNodeRecursive(currentRoot->right, nilai);
    }
	
	return currentRoot; 
}















