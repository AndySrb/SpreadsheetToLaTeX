# SpreadsheetToLaTeX
A generic c++ program that converts spreadsheet (.csv) file to LaTeX code.

![alt text](https://raw.githubusercontent.com/AndySrb/SpreadsheetToLaTeX/master/pictures/example.png)

0. Clone repository.

1. You have to do is unzip file with command:
unzip <NameOffile>
cd <Directory that you unziped>/build
or you can use tool that you got pre-installed in your distro.

2. Compile it manualy with command:
g++ --std:c++14 main.cpp -o SpreadsheetToLaTeX

3. Install it with command (this is not linked with your package menager so if you need to upgrade to new version you have to remove it manualy)
sudo mv SpreadsheetToLaTeX /bin/SpreadsheetToLaTeX

To remove it:
sudo rm /bin/SpreadsheetToLaTeX

4. You have to go to World or any spreadsheet program that can save file in format .csv (mostly all programs support that).
If program asks gives option to change anything just leave it as default and continue, and even if it warns to save to any other format just continue. IT IS RECCOMENDED TO HAVE BACKUP IN DEFAULT FORMAT FOR ANY SPREADSHEET CALC PROGRAM.

5. cd into directory where is located your spreadsheet file and run in terminal:
SpreadsheetToLaTeX
(Just enter file name with ".csv" at the end and inport that code into your latex file.)

Tested od: libreoffice,SC-IM.

I need someone to make makefile and ability to call it and use it as normal linux package.
