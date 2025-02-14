//#include <iostream>
//#include "BigNumber.h"
//using namespace std;
//int BigNumber::getLength(const char * num)
//{
//	int i = 0;
//	while (num[i] != '\0')
//	{
//		i = i + 1;
//	}
//	return i;
//}
//bool BigNumber::isEmpty() const 
//{
//	if (numberLength == 0)
//		return true;
//	return false;
//} 
//bool BigNumber::isSame( BigNumber str) const 
//{
//	if (isEmpty() && str.isEmpty())
//		return 1;
//	if (numberLength != str.numberLength)
//	{
//		return false;
//	}
//	else
//	{
//		int i = 0;
//		while (i < numberLength)
//		{
//			if (number[i] != str.number[i])
//				return false;
//			i++;
//		}
//		return true;
//	}
//}
//void BigNumber::copyCharArray(const char* source)
//{
//	int i = 0;
//	while (source[i] != '\0')
//	{
//		number[i] = source[i];
//		i++;
//	}
//	number[i] = '\0';
//}
//BigNumber::BigNumber(const char* num)
//{
//	if (num==nullptr||num=="")
//	{
//		number = new char;
//		*number = '\0';
//		numberLength = 0;
//	}
//	else
//	{
//		int lengthOfNumber = getLength(num);
//		number = new char[lengthOfNumber + 1];
//		numberLength = lengthOfNumber;
//		copyCharArray(num);
//	}
//}
//BigNumber::BigNumber(const BigNumber& rfs)
//{
//	if (rfs.number == nullptr || rfs.number=="")
//	{
//		number = new char;
//		*number = '\0';
//		numberLength = 0;
//		return;
//	}
//	number = new char[rfs.numberLength + 1];
//	numberLength = rfs.numberLength;
//	copyCharArray(rfs.number);
//}
//BigNumber::~BigNumber()
//{
//	if (number != nullptr)
//	{
//		delete[] number;
//		number = nullptr;
//		numberLength = 0;
//	}
//
//}
//void BigNumber::print() const 
//{
//	if (number != nullptr )
//	{
//		if (numberLength != 0)
//		{
//			cout << number;
//		}
//		else
//		{
//			cout << "0";
//		}
//	}
//	
//}
//bool BigNumber::isCallingGreater ( BigNumber s2)  const 
//{
//	if (numberLength > s2.numberLength)
//		return true;
//	else if (numberLength < s2.numberLength)
//		return false;
//	int i = 0;
//	while (i < numberLength)
//	{
//		if (number[i] > s2.number[i])
//			return true;
//		i++;
//	}
//	return false;
//}
//Comparsion BigNumber::compare(BigNumber rfs) const 
//{
//	if (isSame(rfs))
//		return EQUAL;
//	else if (isCallingGreater(rfs))
//		return LARGE;
//	else
//		return SMALL;
//}
//BigNumber BigNumber::add(BigNumber rfs) const 
//{
//	int maxLength = (numberLength > rfs.numberLength) ? numberLength : rfs.numberLength;
//	char* result = new char[maxLength + 1];
//	result[maxLength] = '\0';
//	int carry = 0;
//	int callingObjectIndex = numberLength - 1;
//	int parameterIndex = rfs.numberLength - 1;
//	int resultIndex = maxLength - 1;
//	while (callingObjectIndex >= 0 || parameterIndex >= 0)
//	{
//		int digit1 = (callingObjectIndex >= 0) ? (number[callingObjectIndex] - '0') : 0;
//		int digit2 = (parameterIndex >= 0) ? (rfs.number[parameterIndex] - '0') : 0;
//		int sum = digit1 + digit2 + carry;
//		carry = sum / 10;
//		result[resultIndex] = (sum % 10) + '0';
//		resultIndex--;
//		callingObjectIndex--;
//		parameterIndex--;
//	}
//	if (carry > 0)
//		result[resultIndex] = carry + '0';
//	BigNumber sumNumber(result);
//	delete[] result;
//	return sumNumber;
//}
//BigNumber BigNumber::multiply(const BigNumber& other) const
//{
//	int resultLength = numberLength + other.numberLength;
//	char* result = new char[resultLength + 1];
//	result[resultLength] = '\0'; 
//	for (int i = 0; i < resultLength; i++)
//	{
//		result[i] = '0';
//	}
//	for (int i = numberLength - 1; i >= 0; i--)
//	{
//		int carry = 0;
//		for (int j = other.numberLength - 1; j >= 0; j--) 
//		{
//			int digit1 = number[i] - '0';
//			int digit2 = other.number[j] - '0';
//			int product = digit1 * digit2 + carry + (result[i + j + 1] - '0');
//			result[i + j + 1] = (product % 10) + '0';
//			carry = product / 10;
//		}
//		result[i] += carry;
//	}
//	int startPos = 0;
//	while (result[startPos] == '0' && startPos < resultLength - 1)
//	{
//		startPos++;
//	}
//	BigNumber resultBigNum(result + startPos);
//	delete[] result;
//	return resultBigNum;
//}
//BigNumber BigNumber::subtract(const BigNumber& other) const
//{
//	if (compare(other) == SMALL)
//	{
//		return BigNumber("0");
//	}
//
//	int len1 = numberLength;
//	int len2 = other.numberLength;
//	int carry = 0;
//	char* result = new char[len1 + 1];
//
//	for (int i = len1 - 1, j = len2 - 1, k = len1 - 1; i >= 0; --i, --j, --k)
//	{
//		int num1 = number[i] - '0';
//		int num2 = j >= 0 ? other.number[j] - '0' : 0;
//
//		if (num1 < num2 + carry)
//		{
//			num1 += 10;
//			result[k] = (num1 - num2 - carry) + '0';
//			carry = 1;
//		}
//		else 
//		{
//			result[k] = (num1 - num2 - carry) + '0';
//			carry = 0;
//		}
//	}
//
//	result[len1] = '\0';
//	int start = 0;
//	while (result[start] == '0') 
//	{
//		++start;
//	}
//
//	BigNumber res(result + start);
//	delete[] result;
//	return res;
//}
//
//
//void BigNumber::setNumber(const char* num)
//{
//	this->~BigNumber();
//	if (num == nullptr || num == "")
//	{
//		number = new char;
//		*number = '\0';
//		numberLength = 0;
//	}
//	else
//	{
//		int lengthOfNumber = getLength(num);
//		number = new char[lengthOfNumber + 1];
//		numberLength = lengthOfNumber;
//		copyCharArray(num);
//	}
//}
//
//
////BigNumber BigNumber::multiply(const BigNumber& other) const {
////	// Get the lengths of the input numbers
////	int len1 = numberLength;
////	int len2 = other.numberLength;
////
////	// Allocate memory for the result (maximum possible length)
////	int maxLen = len1 + len2;
////	char* result = new char[maxLen + 1]; // +1 for null terminator
////
////	// Initialize result with zeros
////	for (int i = 0; i < maxLen; ++i) {
////		result[i] = '0';
////	}
////
////	// Multiply each digit and accumulate the result
////	for (int i = len1 - 1; i >= 0; --i) {
////		int carry = 0;
////		for (int j = len2 - 1; j >= 0; --j) {
////			int product = (number[i] - '0') * (other.number[j] - '0') + carry;
////			carry = product / 10;
////			result[i + j + 1] += (product % 10);
////			if (result[i + j + 1] > '9') {
////				result[i + j + 1] -= 10;
////				++carry;
////			}
////		}
////		result[i] += carry; // Add remaining carry to the current digit
////	}
////
////	// Remove leading zeros
////	int startIdx = 0;
////	while (startIdx < maxLen && result[startIdx] == '0') {
////		++startIdx;
////	}
////
////	// Create the final BigNumber from the result
////	BigNumber multipliedResult(result + startIdx);
////
////	// Clean up memory
////	delete[] result;
////
////	return multipliedResult;
////}
//
//
////BigNumber BigNumber::add(BigNumber other) 
////{
////	//other.print();
////	if (other.isEmpty() )
////		return *this;
////	else if (isEmpty())
////		return other;
////
////	int maxLength = findMaxLength(numberLength, other.numberLength);
////	char* result = new char[maxLength+1];
////	result[maxLength] = '\0';
////	maxLength--;
////
////	int i = 0;
////	int currIndex = numberLength - 1;
////	int parameterObjectIndex = other.numberLength - 1;
////	int carry = 0;
////	while (i < numberLength && i < other.numberLength)
////	{
////
////		int sum = number[currIndex] + other.number[parameterObjectIndex]+carry;
////		sum >= 10 ? carry = sum / 10 : carry = 0;
////		if (carry != 0)
////		{
////			result[maxLength] = sum%10 + '0';
////		}
////		else
////		{
////			result[maxLength] = sum + '0';
////		}
////		maxLength--;
////		currIndex--;
////		parameterObjectIndex--;
////		i++;
////	}
////	BigNumber r{result};
////
////
////	return  r;
////	//int length;
////	//if (numberLength > other.numberLength)
////	//	length = numberLength;
////	//else
////	//	length = other.numberLength;
////
////	//char* result = new char[length + 1];
////	//int carry = 0;
////	//for (int i = 0; i < length; i++) 
////	//{
////	//	int digit1 = i < this->numberLength ? this->number[i] - '0' : 0;
////	//	int digit2 = i < other.numberLength ? other.number[i] - '0' : 0;
////
////	//	int sum = digit1 + digit2 + carry;
////	//	result[i] = sum % 10 + '0';
////	//	carry = sum / 10;
////	//}
////
////	//// If there is a carry left, add it to the result
////	//if (carry > 0) {
////	//	result[length++] = carry + '0';
////	//}
////
////	//// Null-terminate the string
////	//result[length] = '\0';
////
////	//// Create a new BigNumber with the result
////	//BigNumber sum(result);
////
////	//// Clean up
////	//delete[] result;
////
////	//return sum;
////}
//
#include <iostream>
#include "BigNumber.h"
using namespace std;

//Private Functions:
int BigNumber::getLength(const char* num)
{
	int i = 0;
	while (num[i] != '\0')
	{
		i = i + 1;
	}
	return i;
}

bool BigNumber::isEmpty() const
{
	if (numberLength == 0)
		return true;
	return false;
}

bool BigNumber::isSame(BigNumber str) const
{
	if (isEmpty() && str.isEmpty())
		return 1;
	if (numberLength != str.numberLength)
	{
		return false;
	}
	else
	{
		int i = 0;
		while (i < numberLength)
		{
			if (number[i] != str.number[i])
				return false;
			i++;
		}
		return true;
	}
}

void BigNumber::copyCharArray(const char* source)
{
	int i = 0;
	while (source[i] != '\0')
	{
		number[i] = source[i];
		i++;
	}
	number[i] = '\0';
}

bool BigNumber::isCallingGreater(BigNumber s2)  const
{
	if (numberLength > s2.numberLength)
		return true;
	else if (numberLength < s2.numberLength)
		return false;
	int i = 0;
	while (i < numberLength)
	{
		if (number[i] > s2.number[i])
			return true;
		i++;
	}
	return false;
}

//Public Functions:
BigNumber::BigNumber(const char* num)  // ---- (-0.5) if not created.
{
	if (num == nullptr || num == "")
	{
		number = new char;
		*number = '\0';
		numberLength = 0;
	}
	else
	{
		int lengthOfNumber = getLength(num);
		number = new char[lengthOfNumber + 1];
		numberLength = lengthOfNumber;
		copyCharArray(num);
	}
}

BigNumber::BigNumber(const BigNumber & rfs) // ---- (-0.5) if not created.
{
	if (rfs.number == nullptr || rfs.number == "")
	{
		number = new char;
		*number = '\0';
		numberLength = 0;
		return;
	}
	number = new char[rfs.numberLength + 1];
	numberLength = rfs.numberLength;
	copyCharArray(rfs.number);
}

BigNumber::~BigNumber()  // ---- (-0.5) if not created.
{
	if (number != nullptr)
	{
		delete[] number;
		number = nullptr;
		numberLength = 0;
	}

}

void BigNumber::print() const   // ---- (-0.5) if not created.
{
	if (number != nullptr)
	{
		if (numberLength != 0)
		{
			cout << number;
		}
		else
		{
			cout << "0";
		}
	}

}
Comparsion BigNumber::compare(const BigNumber & rfs) const   //---- (-0.5) if not created.
{
	if (isSame(rfs))
		return EQUAL;
	else if (isCallingGreater(rfs))
		return LARGE;
	else
		return SMALL;
}

BigNumber BigNumber::add(const BigNumber & rfs) const  //---- (-0.5) if not created.
{
	int maxLength = (numberLength > rfs.numberLength) ? numberLength : rfs.numberLength;
	char* result = new char[maxLength + 1];
	result[maxLength] = '\0';
	int carry = 0;
	int callingObjectIndex = numberLength - 1;
	int parameterIndex = rfs.numberLength - 1;
	int resultIndex = maxLength - 1;
	while (callingObjectIndex >= 0 || parameterIndex >= 0)
	{
		int digit1 = (callingObjectIndex >= 0) ? (number[callingObjectIndex] - '0') : 0;
		int digit2 = (parameterIndex >= 0) ? (rfs.number[parameterIndex] - '0') : 0;
		int sum = digit1 + digit2 + carry;
		carry = sum / 10;
		result[resultIndex] = (sum % 10) + '0';
		resultIndex--;
		callingObjectIndex--;
		parameterIndex--;
	}
	if (carry > 0)
		result[resultIndex] = carry + '0';
	BigNumber sumNumber(result);
	delete[] result;
	return sumNumber;
}

BigNumber BigNumber::multiply(const BigNumber & other) const   //     ---- (8)
{
	int resultLength = numberLength + other.numberLength;
	char* result = new char[resultLength + 1];
	result[resultLength] = '\0';
	for (int i = 0; i < resultLength; i++)
	{
		result[i] = '0';
	}
	for (int i = numberLength - 1; i >= 0; i--)
	{
		int carry = 0;
		for (int j = other.numberLength - 1; j >= 0; j--)
		{
			int digit1 = number[i] - '0';
			int digit2 = other.number[j] - '0';
			int product = digit1 * digit2 + carry + (result[i + j + 1] - '0');
			result[i + j + 1] = (product % 10) + '0';
			carry = product / 10;
		}
		result[i] += carry;
	}
	int startPos = 0;
	while (result[startPos] == '0' && startPos < resultLength - 1)
	{
		startPos++;
	}
	BigNumber resultBigNum(result + startPos);
	delete[] result;
	return resultBigNum;
}
//Sample Runs;
//1.	123 * 45 = 5535 ---- (2)
//2.	987654 * 123456 = 12193263184 ---- (2)
//3.	999 * 999 = 998001 ---- (1)
//4.	12345 * 0 = 0 ---- (1)
//5.	1 * 9999 = 9999 ---- (2)
//
//Automicity---- (-0.5)
BigNumber BigNumber::subtract(const BigNumber & other) const   // ---- (6)
{
	if (compare(other) == SMALL)
	{
		return BigNumber("0");
	}

	int len1 = numberLength;
	int len2 = other.numberLength;
	int carry = 0;
	char* result = new char[len1 + 1];

	for (int i = len1 - 1, j = len2 - 1, k = len1 - 1; i >= 0; --i, --j, --k)
	{
		int num1 = number[i] - '0';
		int num2 = j >= 0 ? other.number[j] - '0' : 0;

		if (num1 < num2 + carry)
		{
			num1 += 10;
			result[k] = (num1 - num2 - carry) + '0';
			carry = 1;
		}
		else
		{
			result[k] = (num1 - num2 - carry) + '0';
			carry = 0;
		}
	}

	result[len1] = '\0';
	int start = 0;
	while (result[start] == '0')
	{
		++start;
	}

	BigNumber res(result + start);
	delete[] result;
	return res;
}

//Sample Runs;
//1.	100 - 99 = 1 ---- (2)
//2.	12345 - 6789 = 5556 ---- (2)
//3.	500 - 500 = 0 ---- (1)
//4.	1234567890 - 987654321 = 24691356 ---- (1)
//
//Automicity---- (-0.5)

void BigNumber::setNumber(const char* num)     //   ---- (2)
{
	this->~BigNumber();   //---- (0.5)
		if (num == nullptr || num == "") //  ---- (0.5)
		{
			number = new char;
			*number = '\0';
			numberLength = 0;
		}
		else
		{
			int lengthOfNumber = getLength(num);
			number = new char[lengthOfNumber + 1];
			numberLength = lengthOfNumber;
			copyCharArray(num);
		}
}

