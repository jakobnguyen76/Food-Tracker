#ifndef FOOD_WASTAGE_REPORT_H_
#define FOOD_WASTAGE_REPORT_H_

#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "food_wastage_record.h"

// Please fill in below.
// <Your name>
// <Your section number> (e.g. CPSC 121L-01)
// <Date>
// <Your csu.fullerton.edu email>
// <Your GitHub username>

class FoodWastageReport {
  // ======================= YOUR CODE HERE =======================
  // Write the FoodWastageReport class here. Refer to your class design for the
  // member variables, constructors, and member functions needed.
  //
  // Note: mark functions that do not modify the member variables
  // as const, by writing `const` after the parameter list.
  // Pass objects by const reference when appropriate.
  // Remember that std::string is an object!
  // ===============================================================
 public:
  FoodWastageReport();
  FoodWastageReport(std::vector<FoodWastageRecord> list);

  std::vector<std::string> CommonWasted() const { return common_wasted_; }
  std::vector<std::string> Costly() const { return costly_; }
  double TotalCost() const { return total_cost_; }
  std::vector<std::string> CommonReasons() const { return common_reason_; }
  std::vector<std::string> CommonMechanisms() const {
    return common_mechanisms_;
  }
  std::vector<std::string> Strategies() const { return strategies_; }

 private:
  std::vector<std::string> common_wasted_;
  std::vector<std::string> costly_;
  double total_cost_;
  std::vector<std::string> common_reason_;
  std::vector<std::string> common_mechanisms_;
  std::vector<std::string> strategies_;
};

#endif