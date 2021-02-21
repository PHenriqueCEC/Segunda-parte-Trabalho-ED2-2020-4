#include "./TreeNode.h"

TreeNode::TreeNode(){
    this->SE=NULL;
    this->NE=NULL;
    this->NW = NULL;
    this->SW = NULL;
}

void TreeNode::setNW(CityInfo *NW){
    this->NW = NW;
}

void TreeNode::setSE(CityInfo *SE){
    this->SE = SE;
}

void TreeNode::setNE(CityInfo *NE){
    this->NE = NE;
}

void TreeNode::setSW(CityInfo *SW){
    this->SW = SW;
}

