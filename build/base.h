#ifndef BASE_H
#define BASE_H

class Table 
{
	private:

	
		//std::string* string_array[,]= new std::string*[nRows,nColumns];
		const short int constX = 64;
		const short int constY = 64;
		std::string string_array[64][64];
		char input[128];
		short int limit_Y = 0;
		int lengthOfString;
		std::ifstream fileIn;
		std::ofstream fileOut;
		int maxRows;
		int maxCol;
		int colCount = 0;
		int countX = 0;
		int countY = 0;
		std::string nameFile;
	public:
		Table()
		{
	
			std::cout << "Enter spreadsheet file (.csv): ";
			std::cin >> nameFile;
			fileIn.open(nameFile.c_str());
			if (fileIn.fail())
			{
				std::cout << "Failed to open " << nameFile << std::endl << "Program will end";
				exit(1);
			}
		
		}
		

		Table(std::string name)
		{
			nameFile = name;
	
			fileIn.open(nameFile.c_str());
			if (fileIn.fail())
			{
				std::cout << "Failed to open " << nameFile << std::endl << "Program will end";
				exit(1);
			}
		
		}
		
		void start();
		void store();
		void copy_part(int pos1, int pos2);
		void print();
		friend class Convert;
		friend class Plot;

};	
#endif
