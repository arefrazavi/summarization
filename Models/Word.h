//
// Created by Aref Razavi on 2019-04-08.
//

#ifndef SUMMARIZATION_WORD_H
#define SUMMARIZATION_WORD_H

#include <string> // std::wstring, std::to_wstring

using namespace std;

class Word {
public:
    int id;
    int category_id;
    wstring value;
    int count;
    string occurrences;
    string entropy;
    char sentiment_polarity;
};


#endif //SUMMARIZATION_WORD_H
