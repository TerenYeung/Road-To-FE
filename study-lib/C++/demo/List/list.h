#include "point.h"

struct LIST;
typedef struct LIST *PLIST;

PLIST LICreate();
void LIDestory(PLIST list);
void LIAppend(PLIST list, PPOINT point);
void LIInsert(PLIST list, PPOINT point, unsigned int);
void LIDelete(PLIST list, unsigned int pos);
void LIClear(PLIST list);
void LITraverse(PLIST list);
bool LISearch(PLIST list, PPOINT point);
unsigned int LIGetCount(PLIST list);
bool LIIsEmpty(PLIST list);