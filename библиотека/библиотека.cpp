#include<iostream>
using namespace std;


struct book
{
	char name[20];
	char autor[30];
	char publisher[10];
	char genre[10];


};



void edit_book(book arr[]) {
	size_t choice;
	cout << "Выберите книгу котроую хотите редактировать(введите только номер книги):";
	cin >> choice;
	int choice2;

	cout << "Что хотите поменять?" << endl;
	cout << "1)автора     2)название   3)издательство    4)жанр" << endl;
	cin >> choice2;
	switch (choice2) {
	case 1:
		cout << "Введите нового автора--> ";
		cin >> arr[choice - 1].autor;
		break;

	case 2:
		cout << "Введите новое название--> ";
		cin >> arr[choice - 1].name;
		break;

	case 3:
		cout << "Введите новое издательство--> ";
		cin >> arr[choice - 1].publisher;
		break;

	case 4:
		cout << "Введите новый жанр--> ";
		cin >> arr[choice - 1].genre;
		break;
	}

	cout << "спасибо за изменения";
}

void print(book arr[]) {
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << ". " << arr[i].name << " (автор-> " << arr[i].autor << ", издательство-> " << arr[i].publisher << " ,жанр-> " << arr[i].genre << ")" << endl;
		cout << "-----------------------------------------------------------------------------------" << endl;
	}
}


int main() {

	//1 Разработайте программу «Библиотека».
	//Создайте структуру «Книга»(название, автор, издательство, жанр).
		//Создайте массив из 5 книг.Реализуйте для библиотеки следующие возможности :
	/*■ Редактировать книгу;
	■ Печать всех книг;
	■ Поиск книг по автору;
	■ Поиск книги по названию;
	■ Сортировка массива по названию книг;
	■ Сортировка массива по автору;
	■ Сортировка массива по издательству.*/

	setlocale(LC_ALL, "rus");
	book book1 = { "Forest song","Lesya Ukrainka","Folio","drama" };
	book book2 = { "Kobsar","Taras Shevchenko","Prosvita","prosa" };
	book book3 = { "Mojsej","Ivan Franco","Kolo","poema" };
	book book4 = { "Fedko halamidnyk","Volodimir Vinnichenko","Prosvita","story" };
	book book5 = { "Marusya churaj","Lina Kostenco","Vivat","romance" };
	book arr[5] = { book1,book2,book3,book4,book5 };

	cout << "|-------------------------------------------------\------ библиотека ------/----------------------------------------|" << endl << endl;
	cout << "книги:" << endl;
	print(arr);
	cout << endl;
	cout << "выберите операцыю:" << endl;
	cout << "1)редактировать книгу";
	int choice;
	cin >> choice;
	edit_book(arr);
	cout << endl;
	print(arr);

	return(0);
}
