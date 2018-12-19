#ifndef READ_FILE_H
#define READ_FILE_H

#include <regex>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <map>
#include <string>
#include <vector>
#include <fstream>

#define TTS_ASSERT(f, err_code) { \
    if (!f) { \
        fprintf(stderr, "[%s:%d] assert faild (%s)\n", __FILE__, __LINE__, err_code); \
    } \
}

using namespace std;

bool ReadWordSymbol(const string &filename, std::map<int, string> &word2pinyin, bool all_tone=false);
void Sentence2Pinyin(const std::u16string &text, std::map<int, std::string> &word2pinyin, std::string &pinyin);
bool ReadPhraseSymbol(const string &filename, std::map<string, string> &phrase2pinyin);

#endif
