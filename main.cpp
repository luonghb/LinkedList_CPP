#include <iostream>
#include <conio.h>
#include "LinkedList.h"

void PrintList(const LinkedList<int> &list);

int main() {
	LinkedList<int> list;
	int chose = 0;
	int val = 0;
	int pos = 0;
	while (chose != 8) {
		std::cout << "\nCac chuc nang:\n1.Them vao dau;\n2.Them vao duoi;\n3.Them theo vi tri;\n4.Xoa dau;\n5.Xoa duoi;\n6.Xoa theo vi tri;\n7.In danh sach;\nChon chuc nang: ";
		std::cin >> chose;
		switch(chose) {
			case 1:
				std::cout << "\nNhap gia tri can them: ";
				std::cin >> val;
				list.AddHead(new Node<int>(val));
				break;
			case 2:
				std::cout << "\nNhap gia tri can them: ";
				std::cin >> val;
				list.AddTail(new Node<int>(val));
				break;
			case 3:
				std::cout << "\nNhap vi tri can chen: ";
				std::cin >> pos;
				std::cout << "\nNhap gia tri can them: ";
				std::cin >> val;
				list.AddByPosition(new Node<int>(val), pos);
				break;
			case 4:
				list.DeleteHead();
				break;
			case 5:
				list.DeleteTail();
				break;
			case 6:
				std::cout << "\nNhap vi tri can xoa: ";
				std::cin >> pos;
				list.DeleteByPosition(pos);
				break;
			case 7:
				PrintList(list);
				getch();
				break;
			case 8:
				break;
			default:
				break;
		}
		system("cls");
	}
	return 0;
}

void PrintList(const LinkedList<int> &list) {
	std::cout << "\nlist: ";
	for(Node<int> *pi = list.GetPHead(); pi != NULL; pi = pi->GetPNext()) {
		std::cout << pi->GetData() << ' ';
	}
	std::cout << '\n';
}
