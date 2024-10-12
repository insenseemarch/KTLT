#include "Header.h"

int main()
{
	StudentList l;
	l.readData();
	l.printData(l.head);

	cout << endl;
	cout << "Danh sach sau khi xoa di node 2: " << endl;
	//l.removeNode(2);

	cout << endl;
	time_t now = time(0);
	struct tm ltm;
	localtime_s(&ltm, &now);
	int date = ltm.tm_mday;
	int count = 0;
	bool checkDate = l.checkDate(l.head, date, count);
	if (checkDate == false)
	{
		cout << "Khong co ai trong danh sach co ngay sinh trung voi ngay " << date << " (ngay hien tai)" << endl;
	}

	cout << endl;
	cout << "Danh sach sau khi xoa di cac sinh vien co nam sinh lon hon 2005: " << endl;
	//l.removeyounger_2005year(l.head, 1);

	cout << endl;
	cout << "Danh sach sau khi sap xep tang dan theo diem Toan: " << endl;
	l.quickSort(&l.head);
	l.printData(l.head);
}
