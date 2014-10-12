#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "scatteredCircleBrush.h"
#include "circleBrush.h"

extern float frand();

ScatteredCircleBrush::ScatteredCircleBrush( ImpressionistDoc* pDoc, char* name ) :
    ImpBrush(pDoc,name)
{
}

void ScatteredCircleBrush::BrushBegin( const Point source, const Point target )
{
    ImpressionistDoc* pDoc = GetDocument();
    //ImpressionistUI* dlg=pDoc->m_pUI;

    int width = pDoc->getLineWidth();

    glLineWidth(static_cast<float>(width));

    BrushMove( source, target );
}

void ScatteredCircleBrush::BrushMove( const Point source, const Point target )
{
    ImpressionistDoc* pDoc = GetDocument();
    //ImpressionistUI* dlg=pDoc->m_pUI;

    if ( pDoc == NULL ) {
        printf( "ScatteredCircleBrush::BrushMove document is NULL\n" );
        return;
    }

    int size = pDoc->getSize();
    double radius = static_cast<double>(size);
    int scatterDistance = size;

    int offsetX = target.x - source.x;
    int offsetY = target.y - source.y;
    int minX = source.x - scatterDistance;
    int minY = source.y - scatterDistance;

    for (int i = 0; i < 3; i++)
    {
        int x = rand() % scatterDistance + minX;
        int y = rand() % scatterDistance + minY;
        Point individualSource = Point(x, y);
        Point individualTarget = Point(x + offsetX, y + offsetY);
        CircleBrush::DrawCircle(pDoc, individualSource, individualTarget, radius);
    }
}

void ScatteredCircleBrush::BrushEnd( const Point /*source*/, const Point /*target*/ )
{
    // do nothing so far
}

