//
// Created by Rohini Sharma on 4/28/20.
//

#ifndef FINALPROJECT_LABELS_H
#define FINALPROJECT_LABELS_H

#include <string>
#include <boost/bimap.hpp>
using std::string;
using std::vector;

namespace ocr {

typedef boost::bimap<string, size_t> LabelMap;

/**
 * Vector of values to create the label bimap from
 */
vector<LabelMap::value_type> labels_vec{{"0", 0}, {"1", 1}, {"2", 2},
                                        {"3", 3}, {"4", 4}, {"5", 5},
                                        {"6", 6}, {"7", 7}, {"8", 8},
                                        {"9", 9}, {"(", 10}, {")", 11},
                                        {"[", 12}, {"]", 13}, {"+", 14},
                                        {"-", 15}, {"=", 16}, {"\\times", 17},
                                        {"\\in", 18}, {"\\pm", 19}, {"!", 20},
                                        {"\\rightarrow", 21}, {"\\sin", 22},
                                        {"\\cos", 23}, {"\\tan", 24},
                                        {"\\lim", 25}, {"\\log", 26},
                                        {"\\exists", 27}, {"\\forall", 28},
                                        {"\\sqrt", 29}, {"/", 30},
                                        {"\\geq", 31}, {"\\gt", 32},
                                        {"\\leq", 33}, {"\\lt", 34},
                                        {"\\neq", 35}, {"\\div", 36},
                                        {"\\int", 37}, {"\\inf", 38}};

/**
 * Bimap containing labels as strings and numercial class of each label.
 * Left map has string as the key
 * Right map has numerical class as the key
 */
LabelMap label_and_num_map_(labels_vec.begin(), labels_vec.end());



}



#endif  // FINALPROJECT_LABELS_H
