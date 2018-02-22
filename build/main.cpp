#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include "base.h"
#include "convert.h"
#include "plot.h"
#include "plot.cpp"
#include "convert.cpp"
#include "base.cpp"



int main()
{
	bool plotGraph = false;
	char menu;
	int x,y;
	Table table;
	table.start();
//	table.print();
	Convert convert(table);
	convert.toTex(table);
	Plot plot(table);
	std::cout << "Would you like to make plot? (Y/N) :";
		std::cin >> menu;
		menu = toupper(menu);
		switch (menu)
		{

			case 'Y':
			plotGraph = true;
			break;
			case 'N':
			break;

			default:
			break;


		};
	if (plotGraph == true)
	{std::cout << "Enter positions of your labes (form first row)\n";
	do {std::cout << "x:";
	std::cin >> x;
	std::cout << "y:";
	std::cin >> y;
	std::cout << "x:" << plot.getStringFormArray(table,0,x) << std::endl;
	std::cout << "y:" << plot.getStringFormArray(table,0,y);
	std::cout << "Are you sure (Y/N): ";
	std::cin >> menu;
	menu = toupper(menu);
	}while(menu != 'Y');
	plot.setLabels(table,x,y);
	plot.setTickMessage(table);
	plot.convertToPlot(table,convert);
	
	}
	return 0;
//	std::shared_ptr<Table> table = std::make_shared<Table>();
//	table->start();	
//	table->print();

}

