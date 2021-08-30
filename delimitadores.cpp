#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define DELMITADOR_CAMPO ","
#define DELIMITADOR_ARCHIVO "|"
#define SALTO "\n"


class student{
	public:
	    string name;
	    int age;
	    student(string n, int a){
	    	this->name = n;
		this->age = a;
	    }

	    string get_data(){
		return this->name + " " + to_string(this->age); 
	    }
};


void saveFile(vector<student> arr){
	ofstream file;
	cout << "saved file \n";
	file.open("file.txt", ios::out);
	if(!file.fail()){
		file << to_string(arr.size()) << DELMITADOR_CAMPO << "Total" << endl;
		for(int i = 0; i < arr.size(); i++){
			file << arr[i].name << DELMITADOR_CAMPO << to_string(arr[i].age) << SALTO;
		}
		file.close();
		cout << "donde!" << endl;
	}
	else
	{
		cout << "file could not open" << endl;
	}
}

void loadStudents(vector<student> arr){

	ifstream file;
	string cadena, substring;
	int pos;
	int size;
	cout << "Opening file \n";
	file.open("file.txt", ios::in);
	if(!file.fail())
	{
		file >> size;
		getline(file, cadena);
		for(int i = 0; i < size; i++){
			stringstream ss;
			getline(file, cadena);
			cout << "read: " << cadena << endl;
			pos = cadena.find_first_of(DELMITADOR_CAMPO, 0);
			arr[i].name = substring=cadena.substr(0, pos);
			cout << "nombre: " << substring << endl;
			substring=cadena.substr(pos+1);
			cout << "age: " << substring << endl; 

		}
	}
	else{
		cout << "file could not open \n";
	}
}







int main(){

	vector<student> students;	
	student a =  student("Oliver", 18);
	student b =  student("Anyela", 19);
	student c =  student("Mario", 21);
	students.push_back(a);
	students.push_back(b);
	students.push_back(c);	
	saveFile(students);
	loadStudents(students);
}



