//
// Created by Euwaq on 30.04.2021.
//
#include <iostream>
#ifndef SEMESTER_WORK_TEMPLATE_ROPE_HPP
#define SEMESTER_WORK_TEMPLATE_ROPE_HPP
#endif  //SEMESTER_WORK_TEMPLATE_ROPE_HPP
#pragma once
#include "traversal_algorithm.hpp"
#include "vector"


namespace itis{
  struct Rope {
   private:
     explicit Rope(std::string str="", Rope *left= nullptr, Rope *right= nullptr);
   public:
    std::string value{""};
     Rope *left{nullptr};
     Rope *right{nullptr};
    int weight;
    int length{left->weight};

    static Rope * concat(Rope *s1, Rope *s2);
    Rope* split(int i); //первые i символов в left, остальные(все,начиная с i-го) в right
    void insert(int i,std::string S);
    char charAt(int i);
    void del(int i,int j);
    std::string report(int i,int j);
    std::string toString();
    static Rope* arrayToRope(std::vector<Rope*>* ropes);
    static std::vector<Rope*>* stringsToRopes(std::vector<std::string>* strings);
    static Rope* stringsToTheRope(std::vector<std::string>* strings)ж
  };
}