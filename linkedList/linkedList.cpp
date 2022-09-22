
#include <iostream>
#include "linkedList.h"
#include <fstream>

void print(LinkedList linkedList) {

	linkedList.First();
	Person prs = linkedList.Current();
	std::cout << prs.name << "\t" << prs.city << std::endl;

	while (linkedList.Next()) {

		Person prs = linkedList.Current();
		std::cout << prs.name << "\t" << prs.city << std::endl;

	}
	std::cout << "----------------------------------------" << std::endl;

}

int main()
{

	LinkedList linkedList;

	std::string choice;
	std::string n;
	std::string c;

	std::cout << "ZEYNEP'IN ADRES DEFTERÝ" << std::endl;
	std::cout << "\n" << std::endl;

	while (choice != "4") {

		std::cout << "1) Ekle" << std::endl;
		std::cout << "2) Sil" << std::endl;
		std::cout << "3) Listele" << std::endl;
		std::cout << "4) Cikis" << std::endl;
		std::cout << "\n" << std::endl;

		std::cin >> choice;

		if (choice != "1" && choice != "2" && choice != "3" && choice != "4") {
			std::cout << "Lutfen seceneklerden birini giriniz!" << std::endl;
			std::cout << "\n" << std::endl;
		}

		else if (choice == "1") { //save to file
			std::cout << "Eklemek istediginiz kisinin ismini giriniz: " << std::endl;
			std::cin >> n;

			std::cout << "Eklemek istediginiz kisinin sehrini giriniz: " << std::endl;
			std::cin >> c;
			std::cout << "\n" << std::endl;

			//Person prs;
			Person* prs = new Person();
			prs->name = n;
			prs->city = c;
			
			linkedList.Add(prs);
			
			linkedList.SaveToFile();

		}

		else if (choice == "2") {//save to file

			if (linkedList.IsEmpty() == true) {
				std::cout << "Kisi ekleyiniz" << std::endl;
				std::cout << "\n" << std::endl;
			}

			else {
				std::cout << "Silmek istediginiz kisinin ismini giriniz: " << std::endl;
				std::cin >> n;

				std::cout << "Silmek istediginiz kisinin sehrini giriniz: " << std::endl;
				std::cin >> c;
				std::cout << "\n" << std::endl;

				Person* x = linkedList.Find(n, c);

				if (x == NULL) {
					std::cout << "Bulamadým" << std::endl;
					std::cout << "\n" << std::endl;
				}
				else {
					linkedList.Remove(x);
					linkedList.SaveToFile();

				}
			}

		}

		else if (choice == "3") {//load from file
			linkedList.LoadFromFile();

			print(linkedList);
			std::cout << "\n" << std::endl;
		}


		else if (choice == "4") {//save to file
			linkedList.SaveToFile();
			break;
		}
	}
}