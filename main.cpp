/*
Author: Michael Mathews
Assignment Title: Strongly Connected Components
Assignment Description: Find the members at the UN that should be uninvited
    based on their lack of ability to communicate based on the languages
    they speak
Due Date: 10/3/22
Date Created: 10/3/22
Date Last Modified: 10/3/22
*/

#include "Graph.h"
#include "Person.h"
#include <string>
#include <sstream>

using namespace std;

/*
Data Abstraction: 5 files are initiallized
Input: number of members and each member's name and languages.
 <First Name> <One language the person can speak>
 <As many languages the person can understand>
Process: Creates a graph of members and determines SCC of graph to determine
    who can communicate with who
Output: The number of members who should be uninvited from a gathering based
    on the languages they can speak
Assumptions: the number of members is between 1 and 100 and the input is
    inputted in the correct format. Input comes in from c standard in
*/
int main(){
    int members;
    cin >> members;
    cin.ignore();
    
    stringstream ss;
    Person p;
    string line, word;
    vector<Person> people;
    for(int i = 0; i < members; i++){
        getline(cin, line, '\n');
        ss << line;
        ss >> word;
        p.setIndex(i);
        p.setName(word);
        while(ss >> word){
            p.addLanguage(word);
        }
        ss.clear();
        people.push_back(p);
        p.clear();
    }
    
    Graph g(members);
    //if person speaks language and another person understands it,
    //add directed edge
    //go through people
    string spoken;
    for(int i = 0; i < people.size(); i++){
        //determine spoken language
        spoken = people[i].getLanguage(0);
        //go through an find people this person can communicate with
        //add edge if can communicate
        for(int j = 0; j < people.size(); j++){
            //make sure not current person
            if(&people[i] != &people[j]){
                //go through each language of each person
                for(int k = 0; k < people[j].getSize(); k++){
                    //if language spoken is on list, add an edge
                    if(people[j].getLanguage(k) == spoken){
                        g.addEdge(i, j);
                    }
                }
            }
        }
    }
    
    //add each group of scc to a list
    //find longest list
    //output all members - longest list length
    int largestScc = 0;
    vector<vector<int>> tot = g.getSCC();
    for(int i = 0; i < tot.size(); i++){
        if(tot[i].size() > largestScc){
            largestScc = tot[i].size();
        }
    }
    cout << members-largestScc << endl;

    return 0;
}
