class Table 
{
	private:

	
		//std::string* string_array[,]= new std::string*[nRows,nColumns];
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
	public:
		Table()
		{
			std::string nameFile;
	
			std::cout << "Enter spreadsheet file (.csv): ";
			std::cin >> nameFile;
			fileIn.open(nameFile.c_str());
			if (fileIn.fail())
			{
				std::cout << "Failed to open " << nameFile << std::endl << "Program will end";
				exit(1);
			}
			

		
		}
		void start()
		{
				
			while (!fileIn.eof())
			{
			fileIn.getline(input,127);
			lengthOfString = std::strlen(input);
			store();
			maxRows++;
			countY=0;
			}
			maxRows--;
		}
				

		void store()
		{
			if ( colCount > maxCol)
				maxCol = colCount;
			int index = 0;
			int pos1 =0,
			    pos2 =-1;
			colCount = 0;
			bool firstConversation = true;
			do{

				if ( input[index] == ',')
				{
					if ( input[index-1] == '"')
					{	
						if ( input[index+1] == '"')
							continue;
					}
					pos2 = index;
					if ( firstConversation == true)
					{
						firstConversation = false;
						copy_part(pos1, pos2);
						colCount++;
					}
						else
					{
						copy_part(pos1 + 1,pos2);
						colCount++;
					}
					pos1 = pos2;
					pos2 = -1;
				}
			
				index++;
			}while(index < lengthOfString);		
			countX++;
			
		}

		void copy_part(int pos1, int pos2)
		{
			int limit = pos2 - pos1;
			char temp[256];
			std::string returnStr;
			char ch;
			int localCount = 0;
			while (pos1 < pos2)
			{
				ch = input[pos1];
				if (input[pos1] == ',' && input[pos1+1] == ',')
					continue;
				temp[localCount] = ch;
				pos1++;
				localCount++;
			}
			temp[localCount] = '\0';
			returnStr = temp;	

			string_array[countX][countY] = returnStr;
			countY++;
		}


		void print()
		{
			int x;
			int y;

		for (x = 0; x < 16;x++)
		{
			for (y = 0; y < 16; y++)
			{
				std::cout << string_array[x][y] << " ";
			}
			std::cout << std::endl;
		}


		}

		void output_code()
		{
			
			fileOut.open("out.tex");
			fileOut << "\\begin{tabular}{ ";
			int index;
			int x,y;
			for (index = 0; index < maxCol; index++)
			{
				fileOut << "| c ";
			}
			fileOut << "| } \n \\hline \n";	
					
			
			
			
			
					for (x = 0; x < maxRows;x++)
				{
					for (y = 0; y < maxCol; y++)
					{
						fileOut << " " << string_array[x][y];
						if (!(y == maxCol -1))
							fileOut << " &";
					}

					fileOut << " \\\\\ \n";
				}
					fileOut << "\\hline \n \\end{tabular} "; 

					fileOut.close();
				
		}


};	

