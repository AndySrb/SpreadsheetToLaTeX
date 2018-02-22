#ifndef PLOT_H
#define PLOT_H

class Plot
{
		
	private:
		int maxX;
		int maxY;
		int maxTickX;
		int maxTickY;
		int x;
		int y;
		std::string xlabel, ylabel;
		std::ofstream fileOut;

	public:
		Plot(const Table &tab);
		std::string getStringFormArray(const Table &tab,int y,int x);
		void setLabels(const Table &tab,int x, int y);
		void setTickMessage(const Table &tab);
		void setMaxTick(const Table &tab,bool automate);
		void convertToPlot(const Table &tab,const Convert &con);

};

#endif
