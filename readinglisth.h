#ifndef _BOOKS_H_
#define _BOOKS_H

#include <string>
#include <iostream>


class ReadingList {
	class Book {
	  std::string title;
	  std::string author;
	}
	size_t size;
	size_t capacity;
	Book *first;

	void doubleMem();
	void swap(ReadingList &);

public:
	ReadingList();
	~ReadingList();
	ReadingList(const ReadingList &);
	ReadingList(const ReadingList &&);
	ReadingList &operator=(const ReadingList &);
	ReadingList &operator=(const ReadingList &&);
	
	ReadingList &addBook(const std::string, const std::string);
	bool inReadingList(std::string);
	friend ostream &operator<<(ostream &, const ReadingList &);

}



#endif
