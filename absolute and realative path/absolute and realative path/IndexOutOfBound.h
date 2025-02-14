#ifndef INDEX_OUT_OF_BOUND_H
#define INDEX_OUT_OF_BOUND_H
#include "String.h"
class IndexOutOfBound
{
	String msg;
public:
	IndexOutOfBound(String a={"INDEX IS OUT OF BOUND"});
	void operator +=(const String& a);
	String what();
};
extern int name =0;
#endif INDEX_OUT_OF_BOUND_H


