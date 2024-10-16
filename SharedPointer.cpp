#include "SharedPointer.h"

template<class T>
SharedPointer<T> ConstructSharedPonter<T>(T* P, bool (*F)(const T&)) {
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
