#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include "base.h"
#include "base.cpp"
#include "convert.h"
#include "convert.cpp"
#include <memory>
int main()
{
	
	Table table;
	table.start();
	table.print();
	Convert convert(table);
	convert.toTex(table);
	return 0;
//	std::shared_ptr<Table> table = std::make_shared<Table>();
//	table->start();	
//	table->print();

}

