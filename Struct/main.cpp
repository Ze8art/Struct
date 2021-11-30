#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

struct book{
	long id;
	char name[255];
	char author[255];
	char publishHouse[255];
	int pageNum;
	char genre[100];
	float price;
	void toString() {
		printf("\033[37mBook: %d, %s, %s, %s, %d, %s, %.2f\033\n", // [37m is WHITE COLOR
			id, name, author, publishHouse, pageNum, genre, price);
			printf("\033[0m\033"); // Default color
	}
};

bool sortBooks(book* books, int size, const char* option);
void printBooks(book* books, int size);

int main() {
	book books[] = {
		{ 1, "Metro2033", "Dmitry Glykhovsky", "Rainbow", 350, "Sci-fi", 125.50 },
		{ 2, "The Da Vinci Code", "Den Brown", "Sunshine", 450, "Detective", 200 },
		{ 3, "Sherlock Holmse", "Arthur Conan Doyle", "Twillight", 189, "detective", 350.50},
		{ 4, "Harry Potter and Death Hallows", "J. K. Rowling", "Moonlight", 500, "Fantasy", 215.75}
	};
	printf("\033[35mBooks before sorting:\033\n");
	printBooks(books, 4);
	printf("\033[33mPlease, input sort options (name, pages, price or author): \033");
	printf("\033[0m\033");
	char sortOption[20];
	scanf("%s", sortOption);
	if (sortBooks(books, 4, sortOption) == true){
		printf("\033[35mBooks after sorting\033\n");
		sortBooks(books, 4, sortOption);
	printBooks(books, 4);
	}
}

bool sortBooks(book* books, int size, const char* option)
{
	if (strcmp(option, "name") == 0) {
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - 1; j++) {
				if (strcmp(books[j].name, books[j + 1].name) > 0)
					std::swap(books[j], books[j + 1]);
			}
		}
		return true;
	}
	else if (strcmp(option, "pages") == 0) {
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - 1; j++) {
				if (books[j].pageNum > books[j + 1].pageNum) {
					std::swap(books[j], books[j + 1]);
				}
			}
		}
		return true;
	}
	else if (strcmp(option, "price") == 0) {
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - 1; j++) {
				if (books[j].price > books[j + 1].price) {
					std::swap(books[j], books[j + 1]);
				}
			}
		}
		return true;
	}
	else if (strcmp(option, "author") == 0) {
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - 1; j++) {
				if (strcmp(books[j].author, books[j + 1].author) > 0) {
					std::swap(books[j], books[j + 1]);
				}
			}
		}
		return true;
	}
	else {
		printf("\033[31mUnknown sortOption\033"); // [31m is RED COLOR
		printf("\033[0m"); // [0 is DEFAULT COLOR
		return false;
	}
}

void printBooks(book* books, int size)
{
	for (int i = 0; i < size; i++) {
		books[i].toString();
	}
}
