#pragma once

#include "impBrush.h"

class CircleBrush : public ImpBrush
{
public:
    CircleBrush( ImpressionistDoc* pDoc = NULL, char* name = NULL );

    void BrushBegin( const Point source, const Point target );
    void BrushMove( const Point source, const Point target );
    void BrushEnd( const Point source, const Point target );
    char* BrushName( void );

    static void DrawCircle(_In_ const ImpressionistDoc* pDoc, _In_ const Point source, _In_ const Point target, _In_ double radius);
};
