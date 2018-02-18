#ifndef CONVERT_H
#define CONVERT_H 
class Convert
{
	private:
		int maxRows;
		int maxCol;
		int colCount;

	public:	
	Convert(const Table& tab);
	void toTex(const Table& tab);
	friend class Table;
};
#endif
