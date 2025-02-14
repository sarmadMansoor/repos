#include <iostream>
#include "IndexOutOfBound.h"
#include "String.h"
IndexOutOfBound::IndexOutOfBound(String a):msg(a)
{

}
void IndexOutOfBound::operator +=(const String& a)
{
	msg += a;
}
String IndexOutOfBound::what()
{
	return msg;
}
int var = 0;
