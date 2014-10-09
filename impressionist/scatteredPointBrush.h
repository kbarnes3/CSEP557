#pragma once

#include "impBrush.h"

class ScatteredPointBrush : public ImpBrush
{
public:
    ScatteredPointBrush( ImpressionistDoc* pDoc = NULL, char* name = NULL );

    void BrushBegin( const Point source, const Point target );
    void BrushMove( const Point source, const Point target );
    void BrushEnd( const Point source, const Point target );
    char* BrushName( void );
};
