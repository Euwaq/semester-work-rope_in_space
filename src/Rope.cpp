//
// Created by Euwaq on 01.05.2021.
//
#include "Rope.hpp"

namespace itis{

  Rope::Rope(std::string str, Rope *left, Rope *right): value{str},left{left},right{right}{
    if(left==nullptr)
    weight=value.length();
    else {
      weight = left->weight + right->weight;
      length = left->weight;
    }
  }

  Rope * Rope::concat(Rope *s1, Rope *s2) {
    if (s1== nullptr) return s2;
    if (s2== nullptr) return s1;
    return new Rope("",s1,s2);
  }
  Rope * Rope::split(int i) {
    if (left== nullptr){
      return concat(new Rope(value.substr(0,i)),new Rope(value.substr(i+1)));
    }
    if (i==length){return concat(left,right);}
    if (i<length){
      Rope *L=left->split(i);
      return concat(L->left,concat(L->right,right));
    }
    if (i>length){
      Rope *r=right->split(i-length);
      return concat(concat(left,r->left),right);
    }
  }
  void Rope::insert(int i, std::string S) {
    Rope *q=split(i);
    left=q->left;
    right=concat(new Rope(S),q->right);
  }//наивная реализация
  char Rope::charAt(int i) {
    /*Rope *q= split(i)->right;
    q=q->split(1);
    return q->value[0];*/

    if (i>=length&&right!= nullptr)
      return right->charAt(i-length);
    if(left!= nullptr)
      return left->charAt(i);
    return value[i];
  }
  void Rope::del(int i, int j) {
    Rope *q= split(i);
    Rope *p=q->split(j);
    left=q->left;
    right=p->right;
  }
  std::string Rope::report(int i, int j) {
    Rope *q= split(i);
    Rope *p=q->right->split(j);
    return p->left->toString();
  }
  std::string Rope::toString() {
    if (left!= nullptr)
      return left->toString()+right->toString();
    else
      return value;
  }

  Rope * Rope::arrayToRope(std::vector<Rope *> *ropes) {
    int s = sizeof(ropes);
    if (s<2)return ropes->at(0);
    for (int i = 0; i < s /2; ++i) {
      ropes->at(i)=new Rope("",ropes->at(2*i),ropes->at(2*i+1));
    }
    if (s %2>0)
      ropes->at(s/2)=ropes->at(ropes->size()-1);
    while (ropes->size()<s-s/2)
      ropes->pop_back();
    return arrayToRope(ropes);
  }

  std::vector<Rope *> * Rope::stringsToRopes(std::vector<std::string> *strings) {
    std::vector<Rope *>* ropes;
    for (int i = 0; i < strings->size(); ++i) {
      ropes->push_back(new Rope(strings->at(i)));
    }
    return ropes;
  }

  Rope * Rope::stringsToTheRope(std::vector<std::string> *strings) {
    arrayToRope(stringsToRopes(strings));
  }
}