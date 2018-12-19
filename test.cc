#include "include/hanzi2pinyin.h"
#include <codecvt>
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc < 2) {
         std::cout << "You did not enter the text " << "\n"; 
        return 0;
    }
    std::map<int, std::string> word2pinyin;
    std::string word_syms_filename="pinyin_update.txt";
    ReadWordSymbol(word_syms_filename, word2pinyin);
    std::string text = argv[1];
    std::u16string u16_conv = std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t>{}.from_bytes(text);
    std::string rst = "";
    Sentence2Pinyin(u16_conv, word2pinyin, rst);
    std::cout << "原始数据为：" << text<< endl;
    std::cout << "拼音结果为：" << rst << endl;
}
