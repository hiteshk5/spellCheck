#include <bits/stdc++.h>
using namespace std;

// Function to split sentence into words (tokens)
vector<string> tokenize(string s, string delim = " ")
{
  int start, end = -1 * delim.size();
  vector<string> tokens;
  do
  {
    start = end + delim.size();
    end = s.find(delim, start);
    tokens.push_back(s.substr(start, end - start));
  } while (end != -1);
  return tokens;
}

// Spell Check Function
vector<string> spellCheck(unordered_map<string, int> umap, string word)
{
  vector<string> vec;
  if (umap.find(word) != umap.end())
  {
    vec.push_back(word);
    return vec;
  }
  else
  {
    for (unsigned x = 0; x < word.length(); ++x)
    {
      string altered_word = word;
      for (char c = 'a'; c <= 'z'; ++c)
      {
        // To check if one character of a string is changed to different character.
        altered_word[x] = c;
        if (umap.find(altered_word) != umap.end())
        {
          vec.push_back(altered_word);
        }
        // To Check if an extra character is inserted in a word
        string insertion_in_word = word.substr(0, x) + c + word.substr(x);
        if (umap.find(insertion_in_word) != umap.end())
        {
          vec.push_back(insertion_in_word);
        }
      }
    }
    for (char c = 'a'; c <= 'z'; ++c)
    {
      string insertion_in_word = word + c;
      if (umap.find(insertion_in_word) != umap.end())
      {
        vec.push_back(insertion_in_word);
      }
    }
    for (unsigned x = 0; x < word.length() - 1; ++x)
    {
      // To Check if adjacent characters are interchanged in word
      string interchanged_word = word.substr(0, x) + word[x + 1] + word[x] + word.substr(x + 2);
      if (umap.find(interchanged_word) != umap.end())
      {
        vec.push_back(interchanged_word);
      }
      // To Check if a character is deleted in word
      string deletion_in_word = word.substr(0, x) + word.substr(x + 1);
      if (umap.find(deletion_in_word) != umap.end())
      {
        vec.push_back(deletion_in_word);
      }
    }
    // place the removed items back inside the hash table
  } // end of SpellCheck
  return vec;
}
// Function to display current word and it's corrected spellings (if any)
void display(string currWord, vector<string> vec)
{
  cout << currWord << ": ";
  for (int i = 0; i < vec.size(); i++)
  {
    cout << vec[i] << " ";
  }
  cout << endl;
}

int main()
{
  // Vector to store corrected spellings
  vector<string> vec;
  string userInput;
  string currWord;
  char response;
  ifstream infile;
  unordered_map<string, int> umap;
  // open the dictionary file
  infile.open("words.txt");
  // check if the file exists, EXIT if it doesnt
  if (infile.fail())
  {
    cout << "Cannot find dict file. Please check if it exist in same directory as program. \n";
    exit(1);
  }
  cout << "Loading dictionary.";
  while (infile >> currWord)
  {
    // Inserting Word in unordered map
    if (umap.find(currWord) == umap.end())
    {
      umap[currWord] = 1;
    }
  }
  infile.close();
  cout << endl;
  do
  { // get user input
    cout << "\nPlease enter a sentence: ";
    cin.clear();
    getline(cin >> ws, userInput);
    // split each word from the string into individual words to check if they are spelled correctly
    vector<string> tokens = tokenize(userInput);
    for (int i = 0; i < tokens.size(); i++)
    {
      currWord = tokens.at(i);
      transform(currWord.begin(), currWord.end(), currWord.begin(), ::tolower); // Convert word to lowercase
      vec = spellCheck(umap, currWord);
      display(currWord, vec);
    }
    // ask for more data
    cout << "\nDo you want to enter another word/sequence? (y/n): ";
    cin >> response;
  } while (response == 'y' || response == 'Y');
  cout << "\nExiting";
  return 0;
}