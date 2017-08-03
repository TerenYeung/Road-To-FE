struct POINT;
typedef struct POINT *PPOINT;

PPOINT PtCreate(int x, int y);
void PtDestroy( PPOINT point);
void PtGetValue( POINT point, int *x, int *y );
void PtSetValue( PPOINT point, int x, int y );
bool PtCompare( PPOINT point1, PPOINT point2 );
char *PtTransformIntoString( PPOINT point );
void PtPrint( PPOINT point );
