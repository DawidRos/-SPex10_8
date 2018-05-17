// prymitywna lista przechowujaca dłużnikow ;-)
//17.05.2018

#include <iostream>
#include "lista.cpp"
#include <cctype>

void zmien(Item &);
void show(Item &);

int main()
{
	dluznik d;
	Lista jeden;
	std::cout << "Podaj imie pierwszego dluznika: ";
	std::cin >> d.imie;
	std::cout << "Podaj kwote zadluzenia: ";
	std::cin >> d.dlug;
	Lista j(d);
	char ch = 'a';
	while (toupper(ch)!= 'Q' )
	{
		std::cout << "\n***** M E N U *****\n"
			<< " <d>\tdodaj nowego dluznika\n <z>\tzmien wartosc zadluzenia dluznikow (wszyscy po kolei)\n <p>\tpokaz wszytkich dluznikow\n <q>\tzakoncz program\n";
		std::cin >> ch;
		while (std::cin.get() != '\n') { continue; }
		switch (ch)
		{
		case 'D':
		case 'd':
			if (j.isFull())
				std::cout << "Lista jest pelna !\n";
			else
			{
				std::cout << "Podaj imie dluznika: ";
				std::cin >> d.imie;
				std::cout << "Podaj kwote zadluzenia: ";
				while (!(std::cin >> d.dlug))
				{
					std::cout << "To powinna byc liczba, podaj jeszcze raz: ";
					std::cin.clear();
					std::cin.get();
				}
				j.add(d);
			}
			break;

		case 'Z':
		case'z':
			j.visit(zmien);
			break;

		case 'P':
		case'p':
			j.visit(show);
			break;
		case 'Q':
		case 'q':
			break;
		default :
			std::cout << "Sprobuj jeszcze raz.\n";
		}
	}

	std::cout << "Do widzenia.";
    return 0;
}

void zmien(Item & s)
{
	std::cout << "Dluznik: " << s.imie << "\t stan konta: " << s.dlug << " zl\nZmien stan konta o: ";
	double n;
	std::cin >> n;
	s.dlug += n;
	std::cout << "Po zmianie:\nDluznik: " << s.imie << "\t stan konta: " << s.dlug<<"\n\n";
}

void show(Item & s)
{
	std::cout << "Dluznik: " << s.imie << "\t stan konta: " << s.dlug << " zl\n";
}