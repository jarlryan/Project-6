/* Strings and Enumerations By Ryan Jarl
   Created on: Apr 3, 2021
   This program accepts an input file (mp6names.txt)
   that contains data that consists of several lines,
   each with one person and information about them
   regarding their gender, and marital status, along
   with their names in an unorganized fashion. The program
   utilizes strings and enumerations to decide their 
   standardized name and prefixes in an organized style,
   written to an output file (mp6output.txt).*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void header(ofstream& output);
string getOriginal(ifstream& input, ofstream& output);
enum gender{MALE, FEMALE};
enum status{SINGLE, MARRIED, DIVORCED};

int main()
{
	ifstream input;
	ofstream output;
	input.open("mp6names.txt");
	output.open("mp6output.txt");
	status relation;
	gender type;
	string first, middle, last, str;
	int i = 0, j = 0;
	header(output);
	str = getOriginal(input, output);
	while(input){
		middle = "";
		if(str[0] == 'M'){
			type = MALE;
		}
		else{
			type = FEMALE;
		}
		if(str[1] == 'S'){
			relation = SINGLE;
		}
		else if(str[1] == 'D'){
			relation = DIVORCED;
		}
		else if(str[1] == 'M'){
			relation = MARRIED;
		}
		if(type == MALE){
			output << "Mr. ";
		}
		else if(relation == SINGLE || relation == DIVORCED){
			output << "Ms. ";
		}
		else if(type == FEMALE && relation == MARRIED){
			output << "Mrs. ";
		}
		i = str.find(',');
		first = str.substr(i + 1);
		last = str.substr(2, i - 2);
		i = 0;
		while(first[i] == ' '){
			i++;
		}
		first = first.substr(i);
		while(first[i] != ' '){
			i++;
		}
		first = first.substr(0, i);
		i = 0;
		while(last[i] == ' '){
			i++;
		}
		last = last.substr(i);
		j = str.find('.');
		if(j != -1){
			middle = str.substr(j - 1, 1);
		}
		output << first << " ";
		if(middle != ""){
			output << middle << ". ";
		}
		output << last << endl;
		str = getOriginal(input, output);
	}
	input.close();
	output.close();
}
void header(ofstream& output){
	output << "Original Name:" << "\t\t\t\t" << "Standardized Name:" << endl << endl;
}
string getOriginal(ifstream& input, ofstream& output){
	string original;
	getline(input, original);
	if(original != ""){
		output << original;
	}
	if(original.length() == 16){
		output << "\t";
	}
	if(original.length() == 21){
		output << "\t";
	}
	if(original.length() == 22){
		output << "\t\t\t";
	}
	else{
		output << "\t\t";
		}
	return original;
}
