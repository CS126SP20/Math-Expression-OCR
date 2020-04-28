//
// Created by Rohini Sharma on 4/28/20.
//

#ifndef FINALPROJECT_LABELS_H
#define FINALPROJECT_LABELS_H

#include <boost/bimap.hpp>
#include <string>

using boost::bimap;
using std::string;
namespace ocr {

typedef bimap<string, size_t> LabelMap;

LabelMap label_and_num_map_({{"0", 0}, {"1", 1}, {"2", 2}, {"3", 3}, {"4", 4},
                             {"5", 5}, {"6", 6}, {"7", 7}, {"8", 8}, {"9", 9},
                             {"(", 10}, {")", 11}, {"[", 12}, {"]", 13}, {"+", 14},
                             {"-", 15}, {"=", 16}, {"\\times", 17}, {"\\in", 18},
                             {"\\pm", 19}, {"!", 20}, {"\\rightarrow", 21},
                             {"\\sin", 22}, {"\\cos", 23}, {"\\tan", 24},
                             {"\\lim", 25}, {"\\log", 26}, {"\\exists", 27},
                             {"\\forall", 28}, {"\\sqrt", 29}, {"/", 30},
                             {"\\geq", 31}, {"\\gt", 32}, {"\\leq", 33}, {"\\lt", 34},
                             {"\\neq", 35}, {"\\div", 36}, {"\\int", 37}, {"\\inf", 38}
});



}



#endif  // FINALPROJECT_LABELS_H
