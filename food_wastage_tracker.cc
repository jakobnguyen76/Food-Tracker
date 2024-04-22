// Please fill in below.
// <Your name>
// <Your section number> (e.g. CPSC 121L-01)
// <Date>
// <Your csu.fullerton.edu email>
// <Your GitHub username>

#include "food_wastage_tracker.h"

#include <vector>

// ========================= YOUR CODE HERE =========================
// This implementation file is where you should implement
// the member functions declared in the header (food_wastage_tracker.h), only
// if you didn't implement them inline within food_wastage_tracker.h.
//
// Remember to specify the name of the class with :: in this format:
//     <return type> MyClassName::MyFunction() {
//        ...
//     }
// to tell the compiler that each function belongs to the FoodWastageTracker
// class.
// ===================================================================
bool FoodWastageTracker::AddFoodWastageRecord(const FoodWastageRecord& record) {
  for (auto& r : tracker_) {
    if (r.Date() == record.Date() && r.Meal() == record.Meal() &&
        r.FoodName() == record.FoodName() &&
        r.Quantity() == record.Quantity() && r.Reason() == record.Reason() &&
        r.Disposal() == record.Disposal() && r.Cost() == record.Cost()) {
      return false;
    }
  }
  tracker_.push_back(record);
  return true;
}

bool FoodWastageTracker::DeleteFoodWastageRecord(
    const FoodWastageRecord& record) {
  for (int i = 0; i < tracker_.size(); i++) {
    if (tracker_[i].Date() == record.Date() &&
        tracker_[i].Meal() == record.Meal() &&
        tracker_[i].FoodName() == record.FoodName() &&
        tracker_[i].Quantity() == record.Quantity() &&
        tracker_[i].Reason() == record.Reason() &&
        tracker_[i].Disposal() == record.Disposal() &&
        tracker_[i].Cost() == record.Cost()) {
      tracker_.erase(tracker_.begin() + i);
      return true;
    }
  }
  return false;
}