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