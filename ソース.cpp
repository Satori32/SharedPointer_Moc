#include <stdio.h>
#include <stdlib.h>

#include "ReferenceCounter.h"

template<class T>
struct SharedPointer {
	T* P = NULL;
	ReferenceCounter R;
	bool (*Deleter)(const T&);
};

template<class T>
SharedPointer<T> ConstructSharedPonter<T>(T* P,bool (*F)(const T&)) {
	SharedPointer S;
	S.P = P;
	S.R = ConstructReferenceCounter();
	S.Deleter = F;

	return S;

}template<class T>
SharedPointer<T> ConstructSharedPonter<T>(T* P) {
	SharedPointer S;
	S.P = P;
	S.R = ConstructReferenceCounter();
	S.Deleter = NULL;

	return S;
}

template<class T>
SharedPointer<T> SharowCopy(SharedPointer<T>& In) {
	Inc(In.R);

	return In;
}
template<class T>
T* GetPointer(SharedPointer<T>& In) {
	return In.P;
}

template<class T>
bool Free(SharedPointer<T>& In) {
	if (Free(In.R) == false) { return false; };
	if (In.Deleter != NULL) { return In.Deleter(*In.P); }
	Free(In.R);
	In.Deleter = NULL;
	free(In.P);
	
	return true;
}

int main() {
	SharedPointer<int> P = ConstructSharedPonter<int>(calloc(1, sizeof(int)));
	(*GetPointer(P))=10;

	Free(P);

	return true;
}
