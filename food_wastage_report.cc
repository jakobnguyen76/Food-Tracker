// Please fill in below.
// <Your name>
// <Your section number> (e.g. CPSC 121L-01)
// <Date>
// <Your csu.fullerton.edu email>
// <Your GitHub username>

#include "food_wastage_report.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "food_wastage_record.h"

// ========================= YOUR CODE HERE =========================
// This implementation file is where you should implement
// the member functions declared in the header (food_wastage_report.h), only
// if you didn't implement them inline within food_wastage_report.h.
//
// Remember to specify the name of the class with :: in this format:
//     <return type> MyClassName::MyFunction() {
//        ...
//     }
// to tell the compiler that each function belongs to the FoodWastageReport
// class.
// ===================================================================
FoodWastageReport::FoodWastageReport() {}

FoodWastageReport::FoodWastageReport(std::vector<FoodWastageRecord> list) {
  int num;
  int big;
  FoodWastageRecord record;
  // creating vector of most commonly wasted food
  std::string most_common = list[0].FoodName();
  common_wasted_.push_back(most_common);
  big = 0;
  num = 0;
  bool same = false;
  for (int i = 0; i < list.size(); i++) {
    for (int j = 0; j < list.size(); j++) {
      if (list[i].FoodName() == list[j].FoodName()) {
        num++;
      }
    }
    if (num > big) {
      big = num;
      for (auto& z : common_wasted_) {
        if (list[i].FoodName() == z) {
          same = true;
        }
      }
      if (same == false) {
        common_wasted_.clear();
        common_wasted_.push_back(list[i].FoodName());
      }
    } else if (num == big) {
      for (auto& z : common_wasted_) {
        if (list[i].FoodName() == z) {
          same = true;
        }
      }
      if (same == false) {
        common_wasted_.push_back(list[i].FoodName());
      }
    }
    num = 0;
    same = false;
  }
  int check = 1;
  std::cout << check << "\n";
  check++;
  // calculates most costly food waste
  double breakfast = 0;
  double lunch = 0;
  double dinner = 0;
  for (auto& it : list) {
    if (it.Meal() == "Breakfast") {
      breakfast += it.Cost();
    } else if (it.Meal() == "Lunch") {
      lunch += it.Cost();
    } else if (it.Meal() == "Dinner") {
      dinner += it.Cost();
    }
  }
  if (breakfast > lunch && breakfast > dinner) {
    costly_.push_back("Breakfast");
  }
  if (breakfast > lunch && breakfast == dinner) {
    costly_.push_back("Breakfast");
    costly_.push_back("Dinner");
  }
  if (breakfast == lunch && breakfast > dinner) {
    costly_.push_back("Breakfast");
    costly_.push_back("Lunch");
  }
  if (lunch > breakfast && lunch > dinner) {
    costly_.push_back("Lunch");
  }
  if (lunch > breakfast && lunch == dinner) {
    costly_.push_back("Lunch");
    costly_.push_back("Dinner");
  }
  if (dinner > lunch && dinner > breakfast) {
    costly_.push_back("Dinner");
  }
  if (breakfast == lunch && breakfast == dinner) {
    costly_.push_back("Breakfast");
    costly_.push_back("Lunch");
    costly_.push_back("Dinner");
  }
  std::cout << check << "\n";
  check++;
  // calculates total cost
  for (auto& it : list) {
    total_cost_ += it.Cost();
  }
  std::cout << check << "\n";
  check++;
  // creates vector of most common reason
  std::string most_common_reason = list[0].Reason();
  common_reason_.push_back(most_common_reason);
  big = 0;
  num = 0;
  for (int i = 0; i < list.size(); i++) {
    for (int j = 0; j < list.size(); j++) {
      if (list[i].Reason() == list[j].Reason()) {
        num++;
      }
    }
    if (num > big) {
      big = num;
      for (auto& z : common_reason_) {
        if (list[i].Reason() == z) {
          same = true;
        }
      }
      if (same == false) {
        common_reason_.clear();
        common_reason_.push_back(list[i].Reason());
      }
    } else if (num == big) {
      for (auto& z : common_reason_) {
        if (list[i].Reason() == z) {
          same = true;
        }
      }
      if (same == false) {
        common_reason_.push_back(list[i].Reason());
      }
    }
    num = 0;
    same = false;
  }
  std::cout << check << "\n";
  check++;
  // creates vector of most common mechanism
  std::string most_common_mech = list[0].Disposal();
  common_mechanisms_.push_back(most_common_mech);
  big = 0;
  num = 0;
  for (int i = 0; i < list.size(); i++) {
    for (int j = 0; j < list.size(); j++) {
      if (list[i].Disposal() == list[j].Disposal()) {
        num++;
      }
    }
    if (num > big) {
      big = num;
      for (auto& z : common_mechanisms_) {
        if (list[i].Disposal() == z) {
          same = true;
        }
      }
      if (same == false) {
        common_mechanisms_.clear();
        common_mechanisms_.push_back(list[i].Disposal());
      }
    } else if (num == big) {
      for (auto& z : common_mechanisms_) {
        if (list[i].Disposal() == z) {
          same = true;
        }
      }
      if (same == false) {
        common_mechanisms_.push_back(list[i].Disposal());
      }
    }
    num = 0;
    same = false;
  }
  std::cout << check << "\n";
  check++;
  // creates a vector of suggested strategies
  bool buy_less = false;
  bool expired = false;

  for (auto& i : common_reason_) {
    if (i == "Expired") {
      strategies_.push_back("Donate before expiration");
      expired = true;
    } else if (i == "Tastes bad") {
      if (buy_less == false) {
        strategies_.push_back("Buy less food");
        buy_less = true;
      }
    } else if (i == "Too much left overs") {
      if (buy_less == false) {
        strategies_.push_back("Buy less food");
        buy_less = true;
      }
      strategies_.push_back("Cook small servings");
    }
  }
  if (expired == false) {
    strategies_.push_back("Recycle left overs");
  }
  std::cout << check << "\n";
  check++;
};