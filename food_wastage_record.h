#ifndef FOOD_WASTAGE_RECORD_H_
#define FOOD_WASTAGE_RECORD_H_

#include <iostream>
#include <string>

// Please fill in below.
// <Your name>
// <Your section number> (e.g. CPSC 121L-01)
// <Date>
// <Your csu.fullerton.edu email>
// <Your GitHub username>

class FoodWastageRecord {
  // ======================= YOUR CODE HERE =======================
  // Write the FoodWastageRecord class here. Refer to your class design for the
  // member variables, constructors, and member functions needed.
  //
  // Note: mark functions that do not modify the member variables
  // as const, by writing `const` after the parameter list.
  // Pass objects by const reference when appropriate.
  // Remember that std::string is an object!
  // ===============================================================
 public:
  FoodWastageRecord() {}
  FoodWastageRecord(std::string date, std::string meal, std::string food_name,
                    double quantity, std::string reason, std::string disposal,
                    double cost)
      : date_{date},
        meal_{meal},
        food_name_{food_name},
        quantity_{quantity},
        reason_{reason},
        disposal_{disposal},
        cost_{cost} {}

  void SetDate(std::string date) { date_ = date; }
  void SetMeal(std::string meal) { meal_ = meal; }
  void SetFoodName(std::string food_name) { food_name_ = food_name; }
  void SetQuantity(double quantity) { quantity_ = quantity; }
  void SetReason(std::string reason) { reason_ = reason; }
  void SetDisposal(std::string disposal) { disposal_ = disposal; }
  void SetCost(double cost) { cost_ = cost; }

  std::string Date() const { return date_; }
  std::string Meal() const { return meal_; }
  std::string FoodName() const { return food_name_; }
  double Quantity() const { return quantity_; }
  std::string Reason() const { return reason_; }
  std::string Disposal() const { return disposal_; }
  double Cost() const { return cost_; }

 private:
  std::string date_;
  std::string meal_;
  std::string food_name_;
  double quantity_;
  std::string reason_;
  std::string disposal_;
  double cost_;
};

#endif