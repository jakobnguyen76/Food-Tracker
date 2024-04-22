#ifndef FOOD_WASTAGE_TRACKER_H_
#define FOOD_WASTAGE_TRACKER_H_

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "food_wastage_record.h"
#include "food_wastage_report.h"

// Please fill in below.
// <Your name>
// <Your section number> (e.g. CPSC 121L-01)
// <Date>
// <Your csu.fullerton.edu email>
// <Your GitHub username>

class FoodWastageTracker {
  // ======================= YOUR CODE HERE =======================
  // Write the FoodWastageTracker class here. Refer to your class design for the
  // member variables, constructors, and member functions needed.
  //
  // Note: mark functions that do not modify the member variables
  // as const, by writing `const` after the parameter list.
  // Pass objects by const reference when appropriate.
  // Remember that std::string is an object!
  // ===============================================================
 public:
  bool AddFoodWastageRecord(const FoodWastageRecord& record);

  bool DeleteFoodWastageRecord(const FoodWastageRecord& record);

  std::vector<FoodWastageRecord> GetTracker() const { return tracker_; }

  FoodWastageReport GenerateReport() {
    FoodWastageReport report(tracker_);
    return report;
  }

 private:
  std::vector<FoodWastageRecord> tracker_;
};

#endif