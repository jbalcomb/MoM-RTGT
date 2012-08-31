/* File : momprocess.i */
%module momprocess

%{
#include "MoMProcess.h"
%}

%inline %{

int getByte(uint8_t* ptr, int index) {
	return (int)(int8_t)ptr[index];
}
uint8_t* setByte(uint8_t* ptr, int index, int value) {
	ptr[index] = (uint8_t)value;
	return ptr + index;
}
int getWord(uint8_t* ptr, int index) {
	return (int)*(int16_t*)&ptr[index];
}
uint8_t* setWord(uint8_t* ptr, int index, int value) {
	*(int16_t*)&ptr[index] = (int16_t)value;
	return ptr + index;
}
char* getData(uint8_t* ptr, int index, int size) {
	return (char*)&ptr[index];
}
void setData(uint8_t* ptr, int index, const char* value, int size) {
	memmove(ptr + index, value, size);
}
uint8_t* getPointer(uint8_t* ptr, int index) {
	return ptr + index;
}

%}

// Swig wrappers for the standard C++ library
%include "cdata.i"
%include "std_string.i"

%include "MoMCommon.h"
%include "MoMProcess.h"

