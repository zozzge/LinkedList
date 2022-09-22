#pragma once
#include <fstream>
#include <string> 

class Person {

public:

	std::string name;
	std::string city;

	Person* next;
	Person* prev;

	Person()
	{
	}

	Person(std::string aN, std::string aC) {

		name = aN;
		city = aC;
	}

};

class LinkedList {

	Person *first;
	Person *last;
	Person *current;

public:
	
	LinkedList()
	{
		first = NULL;
		last = NULL;
		current = NULL;
	}

	void Add(Person *person) {
		
		if (first == NULL) {
			first = person;
			last = person;

			(*person).prev = NULL;
			(*person).next = NULL;
		}
		else {
			(*last).next = person;

			(*person).prev = last;
			(*person).next = NULL;

			last = person;
		}

		current = last;
	}

	void Insert(Person *target, Person *person) {

		((*target).prev)->next = person;

		(*person).prev = (*target).prev;
		(*person).next = target;

		(*target).prev = person;

	}


	void Remove(Person *person) {

		(*person).prev->next = (*person).next;
		(*person).next->prev = (*person).prev;

	}

	bool First() {
		if (first == NULL)
			return false;

		current = first;
		return true;
	}

	bool Last() {
		if (last == NULL)
			return false;

		current = last;
		return true;
	}

	bool Next() {
		if (current->next == NULL)
			return false;

		current = current->next;
		return true;
	}

	bool Prev() {
		if (current->prev == NULL)
			return false;

		current = current->prev;
		return true;
	}

	Person Current() {
		return (*current);
	}

	bool IsEmpty()
	{
		if (first == NULL) {
			return true;
		}
		else {
			return false;
		}
	}

	Person* Find(std::string name, std::string city)
	{
		First();

		if (current->name == name && current->city == city) {
			return (current);
		}

		while (Next())
		{
			if (current->name == name && current->city == city) {
				return (current);
			}
		}

		return NULL;
	}

	void SaveToFile() {

		std::ofstream MyFile("data.txt");

		First();
		MyFile << current->name<< "\n";
		MyFile << current->city<< "\n";

		while (Next()) {

			MyFile << current->name << "\n";
			MyFile << current->city << "\n";

		}

		MyFile.close();
	}

	void LoadFromFile() {

		std::ifstream MyLoadFile("data.txt");

		std::string name;
		std::string city;

		while (getline(MyLoadFile, name)) {
						
			getline(MyLoadFile, city);

			Person* prs = new Person();
			prs->name = name;
			prs->city = city;

			Add(prs);

		}
		MyLoadFile.close();

	}

};
