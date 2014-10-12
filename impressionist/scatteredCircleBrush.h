#pragma once

#include "impBrush.h"

class ScatteredCircleBrush : public ImpBrush
{
public:
    ScatteredCircleBrush( ImpressionistDoc* pDoc = NULL, char* name = NULL );

    void BrushBegin( const Point source, const Point target );
    void BrushMove( const Point source, const Point target );
    void BrushEnd( const Point source, const Point target );
    char* BrushName( void );
};
