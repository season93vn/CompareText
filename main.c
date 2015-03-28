#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream infile, sourcefile;
	char c,s;
	bool flag_s = false, flag_i = false;
	
	sourcefile.open("source.dat");
	infile.open("infile.dat");
	// Check open file error !
	if(sourcefile.fail()) {
		cout << "Error opending source file !";
		return 0;
	}
	if(infile.fail()) {
		cout << "Error opending compare file !";
		return 0;
	}
	while(1){
		sourcefile >> s;
		infile >> c;
		if(sourcefile.eof()) flag_s = true;
		if(infile.eof()) flag_i = true;
		
		if((flag_s != flag_i)||(s!=c)){
			cout << "Not Match !";
			break;
		}else if(flag_s||flag_i) {
			cout << "Match !";
			break;
		}	
	}
	sourcefile.close();
	infile.close();
	return 0;
}
