#include "median_cut.h"
#include <algorithm>
#include <vector>


//custom compare functions for the median cut algorithm
bool cmpR(Color * a, Color * b){
    return a->Red() > b->Red();
}

bool cmpG(Color * a, Color * b){
    return a->Green() > b->Green();
}
bool cmpB(Color * a, Color * b){
    return a->Blue() > b->Blue();
}


int getRangeR(std::vector<Color *> colors) {

    int range = 0;

    auto max = std::max_element(colors.begin(), colors.end(), cmpR);
    
    auto min = std::min_element(colors.begin(), colors.end(), cmpR);
    
    range = (*max)->Red() - (*min)->Red();

    return range;
}

void MedianCut::median_cut(std::vector<Color *> colors, int k) {

    if(colors.size() == 0) {
        return;
    }

    if(k==0) {
        getAverageColor(colors);
    }

    int rangeR = getRangeR(colors);    




}

std::string MedianCut::getAverageColor(std::vector<Color *> colors) {

    int aveR = 0;
    int aveG = 0;
    int aveB = 0;
    int size = colors.size();

    for (Color *c : colors) {
        aveR += c->r;
        aveG += c->g;
        aveB += c->b;
    }

    Color *aveColor = new Color(aveR / size, aveG / size, aveB / size);
    std::string aveAsHex = aveColor->asHex();
    delete aveColor;
    return aveAsHex;
}

std::vector<std::string> MedianCut::makePalette(std::vector<Color *> colors,
                                                int k) {

    median_cut(colors, k);

    return this->colors;
}


