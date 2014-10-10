//
// pointBrush.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "pointBrush.h"

extern float frand();

PointBrush::PointBrush( ImpressionistDoc* pDoc, char* name ) :
    ImpBrush(pDoc,name)
{
}

void PointBrush::BrushBegin( const Point source, const Point target )
{
    BrushMove( source, target );
}

void PointBrush::BrushMove( const Point source, const Point target )
{
    ImpressionistDoc* pDoc = GetDocument();

    int size = pDoc->getSize();

    glPointSize(static_cast<float>(size));

    glBegin(GL_POINTS);
        DrawPoint(pDoc, source, target);
    glEnd();
}

void PointBrush::BrushEnd( const Point /*source*/, const Point /*target*/ )
{
    // do nothing so far
}

/*static*/ void PointBrush::DrawPoint(_In_ const ImpressionistDoc* pDoc, _In_ const Point source, _In_ const Point target)
{
    // This should be inside a glBegin(GL_POINTS)/glEnd() block
    SetColorFromDocument(pDoc, source);

    glVertex2d( target.x, target.y );
}

