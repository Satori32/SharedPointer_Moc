#pragma once
#include <stdio.h>
#include <stdlib.h>

#include "ReferenceCounter.h"

template<class T>
struct SharedPointer {
	T* P = NULL;
	ReferenceCounter R;
	bool (*Deleter)(const T&);
};

template<class T> SharedPointer<T> ConstructSharedPonter<T>(T* P, bool (*F)(const T&));
template<class T> SharedPointer<T> ConstructSharedPonter<T>(T* P);
template<class T> SharedPointer<T> SharowCopy(SharedPointer<T>& In);
template<class T> T* GetPointer(SharedPointer<T>& In);
template<class T> bool Free(SharedPointer<T>& In);
