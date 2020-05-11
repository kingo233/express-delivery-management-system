#include "Express.h"
Express::Express() :PhoneNumber(0), OwnerName(""), CompanyName("") 
{

}
Express::Express(int pn, string on, string cn) : PhoneNumber(pn), OwnerName(on), CompanyName(cn)
{

}
Express::~Express() {

}