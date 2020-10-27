#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <iterator>
#include <unordered_map>
using namespace std;

void printFrequencies(const string &str) {
  // declaring map of <string, int> type, each word
  // is mapped to its frequency
  unordered_map<string, int> wordFreq;

  // breaking input into word using string stream
  stringstream ss(str); // Used for breaking words
  string word;          // To store individual words
  while (ss >> word)
    wordFreq[word]++;

  // now iterating over word, freq pair and printing
  // them in <, > format
  unordered_map<string, int>::iterator p;
  for (p = wordFreq.begin(); p != wordFreq.end(); p++)
    cout << "(" << p->first << ", " << p->second << ")\n";
}

int main() {
  unordered_map<string, double> umap;
  // inserting values by using [] operator
  umap["PI"] = 3.14;
  umap["root2"] = 1.414;
  umap["root3"] = 1.732;
  umap["log10"] = 2.302;
  umap["loge"] = 1.0;

  // inserting value by insert function
  umap.insert(make_pair("e", 2.718));
  // Traversing an unordered map
  for (auto x : umap)
    cout << x.first << " " << x.second << endl;
  string key = "YOLO";
  if (umap.find(key) == umap.end())
    cout << key << " not found\n\n";
  else
    cout << "Found " << key << "\n\n";
  // unordered_map<string, double>::iterator itr;
  for (auto itr = umap.begin(); itr != umap.end(); itr++) {
    cout << itr->first << "  " << itr->second << endl;
  }
  // update content
  string str = "geeks for geeks geeks quiz "
               "practice qa for";
  printFrequencies(str);


  return 0;
}

