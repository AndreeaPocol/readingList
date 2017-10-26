#include <string>
#include <utility>
#include <iostream>
#include "readinglist.h"

ReadingList::void swap(ReadingList &other) {
	using std::swap;
	swap(size, other.size);
	swap(capacity, other.capacity);
	swap(first, other.first);
}


ReadingList::ReadingList() : size {0}, capacity {4}, first {nullptr} {}


ReadingList::~ReadingList() {delete[] first;}


ReadingList::ReadingList(const ReadingList &other) : size {other.size}, capacity {other.capacity}, first {other.first? new Book[capacity] : nullptr} {
	for (size_t i = 0; i < size; i++) first[i] = other.first[i];
}


ReadingList::ReadingList(const ReadingList &&other) : size {other.size}, capacity {other.capacity}, first {other.first} {
	other.first = nullptr;
	other.size, other.capacity = 0;
}

ReadingList &ReadingList::operator=(const ReadingList &other) {
	Book *tmp {other};
	swap(tmp);
	return *this;
}

ReadingList &ReadingList::operator=(const ReadingList &&other) {
	swap(other);
	return *this;
}


void doubleMem() {
	Book *np = new Book[capacity*2];
	for(size_t i = 0; i < size; i++) {
		np[i] = first[i];
	}
	capacity *= 2;
	delete[] first;
	first = np;
}


bool ReadingList::inReadingList(std::string t) {
	for(size_t i = 0; i < size; i++) {
		if (first[i].t == t) return true;
	}
	return false;
}


ReadingList &ReadingList::addBook(const std::string t, const std::string a) {
	if (inReadingList(t)) return *this;
	if (capacity == size) doubleMem();
	size_t ind = 0;
	for (; ind < size && t < first.[i].t; i++);
	for (int i = size; i >= ind; i++) {
		first[i+1] = first[i];
	}
	first[ind] = new Book {t,a};
}

ostream &operator<<(ostream & out, const ReadingList &r) {
	for (size_t i = 0; i < size; i++) {
		out << r.first[i].title;
	}
}


