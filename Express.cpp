#include "Express.h"
Express::Express() :PhoneNumber(""), OwnerName(""), CompanyName("") 
{

}
Express::Express(string pn, string on, string cn) : PhoneNumber(pn), OwnerName(on), CompanyName(cn)
{

}
Express::~Express() {

}