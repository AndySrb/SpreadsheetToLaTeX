#include "convert.h"
Convert::Convert(const Table& tab)
{
	int tempCol = 0;
	maxCol = 0;
	int x,y;
	x=y=0;
	for (x = 0; x < tab.constX; x++)
	{
		for (y = 0; y < tab.constY; y++)
		{
			if ( tab.string_array[x][y].length() > 0)
			{
				tempCol = y;
				maxRows = x;
			}
			if (tempCol > maxCol)
				maxCol = tempCol;
		}

	}

}

void Convert::toTex(const Table& tab)
{
	std::ofstream fileOut;
	fileOut.open("out.tex");
	fileOut << "\\begin{tabular}{ ";
	int index;
	int x,y;
	for (index = 0; index <= maxCol; index++)
	{
		fileOut << "| c ";
	}
	fileOut << "| } \n \\hline \n";	

		for (x = 0; x <= maxRows;x++)
	{
		for (y = 0; y <= maxCol; y++)
		{
			fileOut << " " << tab.string_array[x][y];
			if (!(y == maxCol))
				fileOut << " &";
		}

		fileOut << " \\" << "\\" << "\n";
	}
		fileOut << "\\hline \n \\end{tabular} "; 

		fileOut.close();
}

