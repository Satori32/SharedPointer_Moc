#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct ReferenceCounter {
	intmax_t* P = NULL;
};

ReferenceCounter ConstructReferenceCounter();
bool Inc(ReferenceCounter& In);
bool Dec(ReferenceCounter& In);
bool IsUnderZero(ReferenceCounter& In);
intmax_t Now(ReferenceCounter& In);
bool Free(ReferenceCounter& In);