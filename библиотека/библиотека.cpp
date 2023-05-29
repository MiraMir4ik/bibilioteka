#include<iostream>
using namespace std;

struct book
{
	char name[20];
	char autor[30];
	char publisher[10];
	char genre[10];


};

void print(book arr[]) {
	cout << endl;
	cout << "|-----------------------------------------------------------------------------------|" << endl;
	for (int i = 0; i < 5; i++) {
		cout << "|" << i + 1 << ". " << arr[i].name << " (автор-> " << arr[i].autor << ", издательство-> " << arr[i].publisher << " ,жанр-> " << arr[i].genre << ")" << "|" << endl;
		cout << "|-----------------------------------------------------------------------------------|" << endl;
	}
}

void searchByAuthor(book library[], int size, const char* author) {
	bool found = false;
	for (int i = 0; i < size; i++) {
		if (strcmp(library[i].autor, author) == 0) {
			cout << library[i].name << " by " << library[i].autor << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "No books found by " << author << endl;
	}
}

void searchByTitle(book library[], int size, const char* title) {
	bool found = false;
	for (int i = 0; i < size; i++) {
		if (strcmp(library[i].name, title) == 0) {
			cout << library[i].name << " by " << library[i].autor << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "No books found with title \"" << title << "\"" << endl;
	}
}


void sort_byName(book arr[], int size) {//Сахаров Михайло
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (strcmp(arr[j].name, arr[j + 1].name) > 0) {
				book temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	print(arr);
}


void sort_byPublisher(book arr[], int size ) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (strcmp(arr[j].publisher, arr[j + 1].publisher) > 0) {
				book temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	print(arr);
}


void sort_byAutor(book arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (strcmp(arr[j].autor, arr[j + 1].autor) > 0) {
				book temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	print(arr);
}



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
	print(arr);
	cout << "спасибо за изменения";
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

	int choice_glob = 1;
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

	while (choice_glob) {

		cout << endl;
		cout << "->Выберите операцыю:" << endl<<endl;
		cout << "1)редактировать книгу               2)Вывести все книги\n3)Поиск по автору                   4)Поиск по названию\n5)Сортировка книг по названию       6)Сортировка книг по автору\n7)Сортировка книг по издательству";
		int choice;
		cout << endl;
		cin >> choice;

		switch (choice) {
		case 1:
			edit_book(arr);
			break;
		case 2:
			print(arr);
			break;

		case 3:
			char autor[20];
			cout << "Введите автора книги";
			cin.ignore();
			cin.get(autor, 20);
			searchByAuthor(arr, 5,autor);
			break;

		case 4:
			char title[20];
			cout << "Введите название книги";
			cin.ignore();
			cin.get(title, 20);
			searchByTitle(arr, 5, title);
			
			break;

		case 5:
			sort_byName(arr, 5);
			break;

		case 6:
			sort_byAutor(arr, 5);
			break;

		case 7:
			sort_byPublisher(arr, 5);
			break;

		default:
			cout << "Такой операцыи нет...";
			break;
		}
		cout << endl;
		cout << "Хотите что-то еще сделать?(1-да.0-нет)";
		cin >> choice_glob;
	}
	return(0);
}
