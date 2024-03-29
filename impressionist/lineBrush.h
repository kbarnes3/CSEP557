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

    static void DrawLine(_In_ const ImpressionistDoc* pDoc, _In_ const Point source, _In_ const Point target, _In_ int size, _In_ int angle);
};
