/*
** FileName     : CodeConverter.h
** Author       : pigautumn
** Date         : 2016/8/23
** Description  : ����ת���ࣨ�ṩ��̬������
*/

#pragma once

#include <string>
#include <xstring>

using std::string;
using std::wstring;

class CodeConverter
{
public:
	static wstring AsciiToUnicode(const string& ascii_string);		//ASCIIתUnicode
	static string AsciiToUtf8(const string& ascii_string);			//ASCIIתUTF8

	static string UnicodeToAscii(const wstring& unicode_string);	//UnicodeתASCII
	static string UnicodeToUtf8(const wstring& unicode_string);		//UnicodeתUTF8

	static string Utf8ToAscii(const string& utf8_string);			//UTF8תASCII
	static wstring Utf8ToUnicode(const string& utf8_string);		//UTF8תUnicode

	static string BSTRToString(const BSTR& str);					//BSTRתstring
	static BSTR StringToBSTR(const string& str);					//stringתBSTR
};
