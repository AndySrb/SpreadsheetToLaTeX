#include "plot.h"


Plot::Plot(const Table &tab)
{
	fileOut.open("chart.tex");
	fileOut << std::endl << "\\begin{tikzpicture}\n  \\begin{axis}[ \n title={" << tab.nameFile << "},\n";

}

void Plot::setLabels(const Table &tab, int x, int y)
{
	this->x =x;
	this->y =y;
	xlabel = tab.string_array[0][x];
	ylabel = tab.string_array[0][y];
	//std::cout << xlabel << " " << ylabel;
	fileOut << " xlabel={" << xlabel << "},\n";
	fileOut << " ylabel={" << ylabel << "},\n";
	

}

std::string Plot::getStringFormArray(const Table &tab,int y,int x)
{
	return tab.string_array[y][x];
}

void Plot::setTickMessage(const Table &tab)
{
	char menu;
	std::cout << "Would you like to set plot tick manually (Y/N): ";
	std::cin >> menu;
	menu = toupper(menu);	
	switch (menu)
	{

		case 'Y':
		setMaxTick(tab, false);
		break;
		default:
		setMaxTick(tab, true);
		break;
	}
}

void Plot::setMaxTick(const Table &tab,bool automate)
{
	char menu;
	if (automate == true)
	{
		std::cout << "Comming soon";
		setMaxTick(tab,false);
	}
	else 
		{
			do{
			std::cout << "Set max bound for xlabel: ";
			std::cin >> maxTickX;
			fileOut << "xmin=0, xmax=" << maxTickX << ",\n";
			
			std::cout << "Set max bound for ylabel: ";
			std::cin >> maxTickY;
			fileOut << "ymin=0, ymax=" << maxTickY << ",\n";
			
			
			std::cout << "Are you sure (Y/N) :";
			std::cin >> menu;
			menu = toupper(menu);

			} while(menu != 'Y');

		}

}

void Plot::convertToPlot(const Table &tab, const Convert &con)
{


	double xticks;
	double yticks;

	xticks = maxTickX / 5;
	yticks = maxTickY / 5;

	fileOut << "xtick={0";
	
	int count;

	for (count = 1; count <= 5; count++)
		fileOut << ',' <<  count * xticks;		
	
	fileOut << "}," << std::endl;

	
	
	fileOut << "ytick={0";
	for (count = 1; count <= 5; count++)
		fileOut << ',' <<  count * yticks;		

	fileOut << "}," << std::endl;

	fileOut << "legend pos=outer north" << std::endl <<  "ymajorgrids=true," << std::endl << "grid=both," << std::endl << "]";
	fileOut << "\\addplot[" << std::endl << "color=blue," << std::endl << "mark=+," << std::endl << "]" << std::endl << "coordinates { ";
	for (count = 1; count < con.maxRows; count++)
	{
		fileOut << "(" << tab.string_array[count][x] << ',' << tab.string_array[count][y]
			<< ')';
	}
	fileOut << "};" << std::endl << "\\legend{" << tab.nameFile << "}\n" << "\\end{axis}\n";
	fileOut << "\\end{tikzpicture}";
}

