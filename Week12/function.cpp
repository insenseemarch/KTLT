#include "Header.h"


void StudentList::addStudent(Student student)
{
	Node* node = createNode(student);
	if (head == nullptr)
	{
		head = node;
	}
	else
	{
		Node* temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = node;
	}
	size++;
}

void StudentList::readData()
{
	fstream input;
	input.open("data.txt", ios::in);
	if (input.fail())
	{
		cout << "Cannot open file!" << endl;
		return;
	}
	while (!input.eof())
	{
		Student student;
		getline(input,student.name, ' ');

		getline(input,student.gender,' ');
		string date;
		getline(input, date, '/');
		student.date = stoi(date);
		string month;
		getline(input, month, '/');
		student.month = stoi(month);
		//input.seekg(1, 1);
		string year;
		getline(input, year, ' ');
		student.year = stoi(year);

		string mathScore;
		getline(input, mathScore, ' ');
		student.mathScore = stoi(mathScore);

		string literatureScore;
		getline(input, literatureScore, ' ');
		student.literatureScore = stoi(literatureScore);

		string englishScore;
		getline(input, englishScore, '\n');
		student.englishScore = stoi(englishScore);

		addStudent(student);
	}
}

void StudentList::printData(Node* node)
{
	if (node == nullptr)
	{
		return;
	}
	cout << node->s.name << " " << node->s.gender << " " << node->s.date << "/" << node->s.month << "/" << node->s.year << " " << node->s.mathScore << " " << node->s.literatureScore << " " << node->s.englishScore << endl;
	StudentList::printData(node->next);
}

void StudentList::removeNode(int k)
{
	int tmp = 1;
	Node* node = head;
	if (k > size || k <= 0 )
	{
		cout << "Invalid value k." << endl;
		return;
	}
	else if (k == 1)
	{
		Node* remove = head;
		head = head->next;
		delete remove;
		remove = nullptr;
		size--;
		StudentList::printData(head);
	}
	else
	{
		while (tmp < k-1)
		{
			node = node->next;
			tmp++;
		}
		Node* remove = node->next;
		node->next = node->next->next;
		delete remove;
		remove = nullptr;
		size--;
		StudentList::printData(head);
	}
}

bool StudentList::checkDate(Node* node, int date, int count)
{
	if (node->s.date == date)
	{
		cout << "Sinh vien " << node->s.name << " co ngay sinh trung voi ngay " << date << " (hien tai)." << endl;
	}
	else
	{
		count++;
	}
	if (count == size)
	{
		return false;
	}
	StudentList::checkDate(node->next, date, count);
}

void StudentList::removeyounger_2005year(Node* node, int k)
{
	if (node == nullptr)
	{
		return;
	}
	if (node->s.year > 2005)
	{
		StudentList::removeNode(k);
		// Cap nhat lai con tro
		node = head;
		for (int i = 1; i < k && node != nullptr; i++)
		{
			node = node->next;
		}
		StudentList::removeyounger_2005year(node, k);
	}
	else
	{
		StudentList::removeyounger_2005year(node->next, ++k);
	}
}

Node* StudentList::partition(Node* head, Node* end, Node** newHead, Node** newEnd)
{
	Node* pivot = end;
	Node* prev = nullptr, * cur = head, * tail = pivot;

	while (cur != pivot)
	{
		if (cur->s.mathScore < pivot->s.mathScore)
		{
			if (*newHead == nullptr)
			{
				*newHead = cur;
			}
			prev = cur;
			cur = cur->next;
		}
		else
		{
			if (prev != nullptr)
			{
				prev->next = cur->next;
			}
			Node* tmp = cur->next;
			cur->next = nullptr;
			tail->next = cur;
			tail = cur;
			cur = tmp;
		}
	}
	if (*newHead == nullptr)
	{
		*newHead = pivot;
	}
	*newEnd = tail;
	return pivot;
}

Node* StudentList::getTail(Node* cur)
{
	while (cur != nullptr && cur->next != nullptr)
	{
		cur = cur->next;
	}
	return cur;
}

Node* StudentList::quickSortRecur(Node* head, Node* end)
{
	if (!head || head == end)
	{
		return head;
	}

	Node* newHead = nullptr, * newEnd = nullptr;
	Node* pivot = partition(head, end, &newHead, &newEnd);

	if (newHead != pivot)
	{
		Node* tmp = newHead;
		while (tmp->next != pivot)
		{
			tmp = tmp->next;
		}
		tmp->next = nullptr;

		newHead = quickSortRecur(newHead, tmp);

		tmp = getTail(newHead);
		tmp->next = pivot;
	}

	pivot->next = quickSortRecur(pivot->next, newEnd);
	return newHead;
}

void StudentList::quickSort(Node** headRef)
{
	*headRef = quickSortRecur(*headRef, getTail(*headRef));

}


