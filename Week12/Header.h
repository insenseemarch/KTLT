#pragma once
#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

struct Student 
{
	string name;
	string gender;
	int date;
	int month;
	int year;
	int mathScore;
	int literatureScore;
	int englishScore;
};

struct Node 
{
	Student s;
	Node* next;
};

struct StudentList 
{
	Node* head;
	int size;

	StudentList()
	{
		head = nullptr;
		size = 0;
	}

	Node* createNode(Student student)
	{
		Node* node = new Node;
		node->s = student;
		node->next = nullptr;
		return node;
	}

	void addStudent(Student student);
	void readData();
	void printData(Node* node);
	void removeNode(int k);
	bool checkDate(Node* node, int date, int count);
	void removeyounger_2005year(Node* node, int k);
	Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd);
	Node* quickSortRecur(Node* head, Node* end);
	Node* getTail(Node* cur);
	void quickSort(Node** headRef);

};



#endif

