
#include "../include/hanzi2pinyin.h"
#include <stdlib.h>
using namespace std;

bool ReadWordSymbol(const string &filename, std::map<int, string> &word2pinyin, bool all_tone) {                                                                                                                               std::ifstream in(filename);
  string line;
  std::regex rgx(",");
  while (std::getline(in, line)) {
    vector<string> items;
    std::istringstream iss(line);
    for(std::string s; iss >> s; )
      items.push_back(s);
    TTS_ASSERT((items.size() == 4), "dict should be paired")
    int id = strtol(items[0].c_str(), NULL, 16);
    if(all_tone) {
        std::string word = items[1];
        word2pinyin[id] = word; 
    } else {
        std::string all_word = items[1];
        std::sregex_token_iterator iter(all_word.begin(), all_word.end(), rgx, -1);
        string word = *iter;
        word2pinyin[id] = word; 
    }
  }
  return true;
}

bool ReadPhraseSymbol(const string &filename, std::map<string, int> &phrase2pinyin) {                                                                                                                            std::ifstream in(filename);
  string line;
  while (std::getline(in, line)) {
    vector<string> items;
    std::istringstream iss(line);
    for(std::string s; iss >> s; )
      items.push_back(s);
    TTS_ASSERT((items.size() == 2), "dict should be paired")
    std::string phase = items[0];
    int id = std::stoi(items[1]);
    phrase2pinyin[phase] = id; 
  }
  return true;
}

void Sentence2Pinyin(const std::u16string &text, std::map<int, std::string> &word2pinyin, std::string &pinyin) {
    for (char16_t c : text)
      pinyin += word2pinyin[int(c)];
}

