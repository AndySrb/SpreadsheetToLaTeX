# SpreadsheetToLaTeX
A generic c++ program that converts spreadsheet (.csv) file to LaTeX code.

0. Clone repository.

1. You have to do is unzip file with command:
unzip <NameOffile>
or you can use tool that you got pre-installed in your distro.

2. Compile it manualy with command:
g++ main.cpp -o run

3. You have to go to World or any spreadsheet program that can save file in format .csv (mostly all programs support that).

4. Copy that file you saved in .csv file format and paste in same folder where is located compiled file "run".

5. Open terminal cd into directory where is program located and run command:
run.out

6. Just enter file name with ".csv" at the end and inport that code into your latex file.

I need someone to make cmake file and ability to call it and use it as normal linux package with headers file that will output its latex code.
