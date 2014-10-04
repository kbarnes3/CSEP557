//
// lineBrush.h
//
// The header file for Point Brush. 
//
#pragma once

#include "impBrush.h"

class LineBrush : public ImpBrush
{
public:
    LineBrush( ImpressionistDoc* pDoc = NULL, char* name = NULL );

    void BrushBegin( const Point source, const Point target );
    void BrushMove( const Point source, const Point target );
    void BrushEnd( const Point source, const Point target );
    char* BrushName( void );
};
