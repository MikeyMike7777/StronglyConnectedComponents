/*
Author: Michael Mathews
Assignment Title: Strongly Connected Components
Assignment Description: Find the members at a UN meeting that should be
    uninvited based on their lack of ability to communicate based on the
    languages they speak
Due Date: 10/3/22
Date Created: 10/3/22
Date Last Modified: 10/3/22
*/

#ifndef Person_hpp
#define Person_hpp

#include <list>
#include <string>
#include <vector>

using namespace std;

class Person {
private:
    int index;
    string name;
    vector<string> languages;
public:
    int getIndex(){
        return this->index;
    }
    void setIndex(int i){
        this->index = i;
    }
    string getName(){
        return this->name;
    }
    void setName(string n){
        this->name = n;
    }
    void addLanguage(string language){
        languages.push_back(language);
    }
    int getSize(){
        return languages.size();
    }
    string getLanguage(int i){
        return languages[i];
    }
    Person getPerson(){
        return *this;
    }
    void clear(){
        languages.clear();
    }
};
#endif /* Person_hpp */
