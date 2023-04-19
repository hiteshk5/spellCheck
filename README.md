# Spell-Checker

This is a spell-checker class implementation that stores a set of words in a hash table and provides a function `spellCheck(s)` which performs a spell check on the given string `s` with respect to the set of words.

## Problem Statement

Write a spell-checker class that stores a set of words, W, in a hash table and implements a function, spellCheck(s), which performs a spell check on the string s with respect to the set of words, W. If s is in W, then the call to spellCheck(s) returns an iterable collection that contains only s, since it is assumed to be spelled correctly in this case. Otherwise, if s is not in W, then the call to spellCheck(s) returns a list of every word in W that could be a correct spelling of s. Your program should be able to handle all the common ways that s might be a misspelling of a word in W, including swapping adjacent characters in a word, inserting a single character in-between two adjacent characters in a word, deleting a single character from a word, and replacing a character in a word with another character.

## Requirements

- C++11 or higher

## Usage

- Clone the repository
- Compile the code using a C++ compiler
- Run the program
- Enter the input string to check the spelling

## Example

```cpp
#include "spellChecker.h"
#include <iostream>

using namespace std;

int main()
{
    spellChecker obj;
    obj.loadDictionary("words.txt");
    string input;
    cout<<"Enter the word to spell-check: ";
    cin>>input;
    vector<string> suggestions = obj.spellCheck(input);
    cout<<"Did you mean: ";
    for(string word : suggestions){
        cout<<word<<" ";
    }
    cout<<endl;
    return 0;
}
```

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.
