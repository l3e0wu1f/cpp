//
//  JoshLewisProj8.cpp
//
//
//  Created by Josh Lewis on 11/21/17.
//
//

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

void get_scores(vector<int> &v);
// get integer scores from keyboard and store in v.
// we assume that the user will input scores in range
// of 0 to 100, inclusive. User enter a negative
// number to stop the input and end the function

void print_stats(vector<int> &v);
// print out the stats of data that are stored in v
// includes: max, min, total number of data,
// and the average

bool is_palindrome(string sentence);
// return true if the sentence is a palindrome;
// false otherwise

int main() {
    
    // Problem 1
    vector<int> scores;
    get_scores(scores);
    print_stats(scores);
    
    // Problem 2
    string s;
    cout << "Enter a sentence...\n";
    cin >> s;
    getline(cin,s);
    if(is_palindrome(s))
        cout << "The sentence: \"" << s << "\" is a palindrome.\n";
    else
        cout << "The sentence: \"" << s << "\" is not a palindrome.\n";
    
    return 0;
}

void get_scores(vector<int> &v){
    int score;
    cout << "Please enter list of scores, and enter -1 to stop: \n";
    do{
        cin >> score;
        if(score >= 0)
            v.push_back(score);
    } while(score >= 0);
}

void print_stats(vector<int> &v){
    int minScore = 101, maxScore = -1, totalScore = 0;
    size_t size = v.size();
    for(size_t i = 0; i < size; i++){
        if(v[i] < minScore)
            minScore = v[i];
        if(v[i] > maxScore)
            maxScore = v[i];
        totalScore += v[i];
    }
    if(size == 0)
        cout << "There is no test score.\n";
    else{
        cout << "There are " << size << " scores.\n";
        cout << "The highest score is " << maxScore << ".\n";
        cout << "The lowest score is " << minScore << ".\n";
        cout << "The average score is " << 1.0 * totalScore/size << ".\n";
    }
}

bool is_palindrome(string sentence){
    int left = 0;
    int right = (int) sentence.length() - 1;
    while (left < right){
        while (!isalpha(sentence[left])){
            left++;
            if(left == right)
                return true;
        }
        while (!isalpha(sentence[right])){
            right--;
            if(left == right)
                return true;
        }
        if(sentence[left] != toupper(sentence[right]))
            return false;
        left++;
        right--;
    }
    return true;
}
