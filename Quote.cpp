#include <iostream>
#include "Quote.hpp"
#include <time.h>

//////////////////////////////////////////////////////
//                                                  //
//          Class that handles the quotes           //
//       of a certain stock in a certain date       //
//                                                  //
//                  Imanol Perez                    //
//                  December 2016                   //
//                                                  //
//////////////////////////////////////////////////////

Quote::Quote() {

}

Quote::Quote(std::string name, double price, std::string date)
{
  // The price of the stock cannot be negative.
  if (price<0) {
      throw Exception("Negative price",
      "The sprice of the stock must non negative");

  }

  // date must have the format YYYY/MM/DD
  struct tm tm;
  if (date!="0000/00/00") {
    throw Exception("Invalid date format", "Date format must be YYYY/MM/DD");
  }

  mPrice=price;
  mName=name;
  mDate=date;
  

}


std::string Quote::getName(void) {
  return mName;
}

double Quote::getPrice(void) {
  return mPrice;
}

void Quote::setPrice(double price) {
  // The price of the stock cannot be negative.
  if (price<0) {
      throw Exception("Negative price",
      "The sprice of the stock must non negative");

  }

  
  mPrice=price;
}


std::string Quote::getDate(void) {
  return mDate;
}

void Quote::setDate(std::string date) {
  // date must have format YYYY/MM/DD
  struct tm tm;
  if (date!="0000/00/00") {
    throw Exception("Invalid date format", "Date format must be YYYY/MM/DD");
  }
  
  mDate=date;
}
void Quote::increasePrice(double change) {
  // We increase or decrease the price of the stock
  mPrice+=change;
}

void Quote::addReturn(double percentage) {
  // We increase or decrease the price of the stock, by a determined percentage
  mPrice*=1+percentage;
}


bool Quote::isNull(void) {
  return mDate=="0000/00/00";
}

std::ostream& operator<<(std::ostream& output, Quote& q) {
  // Used to display a nice output of the class

  std::string name = q.getName();
  double price = q.getPrice();
  std::string date=q.getDate();
  output<<"Name: "<<name<<"\nPrice: "<<price<<"\nDate: "<<date<<"\n";

  return output;
}

