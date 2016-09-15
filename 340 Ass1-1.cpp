// Example program
#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>
using namespace std;

struct Word{
	string wordAct;
	int count = 1;
};

void getLeastFreqLetter(int array[]){
	int index = 0;
	/*this for loop finds the first element in array that does not equal 0
	cant find the least used character if starting value is 0, everything will 
	be less greater than starting comparison value*/
	for(int i = 0; i < 26; i++){
		if(array[i] != 0){
			index = i;
			break;
		}
	}
    for(int i = 0; i < 26; i++){
        if(array[i] != 0){
            if(array[index] > array[i]){
                index = i;
            }
        }
    }
    char c = index + 'a';
	cout << "The least frequent letter in the string is " << c << ", only occuring " << array[index] << " times." << endl;
}
vector <Word> countWordFreq(string str2){
	vector <Word> vect;
	int x = 0;
	int y = 0;
	string str3 = "";
	for(int i = 0; i < str2.length(); i++){
		if(isspace(str2[i]) || ispunct(str2[i])){//checks for space/punctuation deliminator
			Word word;
			word.wordAct = str3;
			vect.push_back(word);
			x++;
			str3 = "";//resets str3
		}else{
			str3 += tolower(str2[i]);//creates string of word with space/punct deliminator by contatinating characters
		}
	}for (int i = 0; i < vect.size()-1; i++){
		if(vect[i].wordAct == ""){
			vect.erase(vect.begin() + i);
		}
		for(int j = i+1; j < vect.size(); j++){
			if(vect[j].wordAct == ""){
				vect.erase(vect.begin() + j);//erases empty strings
			}/*
			compares worcAct of word object, if they are equal, deletes second 
			instance of word object, and incriments count of word*/
			if(vect[i].wordAct == vect[j].wordAct){
				vect[i].count++;
				vect.erase(vect.begin() + j);
				if(i != j){
					j--;
				}
			}
		}
	}
	for(unsigned i = 0; i < vect.size(); ++i){
		cout << "word : " << vect[i].wordAct << ", frequency: " << vect[i].count << endl;
	}
	return vect;
}void getMostFreqWord (vector <Word> vect){
	Word temp = vect[0];
	for(int i = 1; i < vect.size(); i++){
		if(vect[i].count > temp.count){
			temp = vect[i];
		}//seeking algorithm for finding word object with highest count
	}cout << "The most frequent word is: " << temp.wordAct << " occuring " << temp.count << " times" << endl;
}

int main()
{
    string str1 =  "";
    string str2 = "";
    bool foo = true;
    bool foo1 = true;
    int letters [26];
    for(int i = 0; i < 26; i++){
    	letters[i] = 0;
    }
    while(foo1){
    	cout << "Enter a string: " << endl;
    	getline(cin, str1);
    	if(str1 == ""){
    		cout << "not a valid string." << endl;
    	}else{
    		cout << "you entered " << str1 << endl;
    		for (int i = 0; i < str1.length(); i++){
        		letters[tolower(str1[i]) - 'a']++;
    		}for(int  i = 0; i < 26; i++){
    			if(letters[i] != 0){
    				getLeastFreqLetter(letters);
    				foo1 = false;
    				break;
    			}
    		}if(foo1){
    			cout << "Invalid entry, please re enter a string containing letters." << endl;
    			str1 = "";
    		}
    	}	
    }while(foo){
    	cout << "Enter a string: " << endl;
    	getline (cin, str2);
    	cout << "you entered: " << str2 << endl;
    	char c = str2[str2.size()-1];
    	if(ispunct(c) || isspace(c)){
    	    vector <Word> vect = countWordFreq(str2);
    		getMostFreqWord(vect);
    		foo = false;
    		break;
    	}else if (str2 == ""){
    		cout << "Not a valid string, please re-enter" << endl;
		}else{
			cout << "Please end your string with a space or punctuation." << endl;
		}
    }
    
    

    
    return 0;
    
}

