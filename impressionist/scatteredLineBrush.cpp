#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "scatteredLineBrush.h"
#include "lineBrush.h"

extern float frand();

ScatteredLineBrush::ScatteredLineBrush( ImpressionistDoc* pDoc, char* name ) :
    ImpBrush(pDoc,name)
{
}

void ScatteredLineBrush::BrushBegin( const Point source, const Point target )
{
    ImpressionistDoc* pDoc = GetDocument();
    //ImpressionistUI* dlg=pDoc->m_pUI;

    int width = pDoc->getLineWidth();

    glLineWidth(static_cast<float>(width));

    BrushMove( source, target );
}

void ScatteredLineBrush::BrushMove( const Point source, const Point target )
{
    ImpressionistDoc* pDoc = GetDocument();
    //ImpressionistUI* dlg=pDoc->m_pUI;

    if ( pDoc == NULL ) {
        printf( "ScatteredLineBrush::BrushMove document is NULL\n" );
        return;
    }

    int size = pDoc->getSize();
    int scatterDistance = size;
    int angle = pDoc->getLineAngle();

    int offsetX = target.x - source.x;
    int offsetY = target.y - source.y;
    int minX = source.x - scatterDistance;
    int minY = source.y - scatterDistance;

    for (int i = 0; i < 4; i++)
    {
        int x = rand() % scatterDistance + minX;
        int y = rand() % scatterDistance + minY;
        Point individualSource = Point(x, y);
        Point individualTarget = Point(x + offsetX, y + offsetY);
        LineBrush::DrawLine(pDoc, individualSource, individualTarget, size, angle);
    }
}

void ScatteredLineBrush::BrushEnd( const Point /*source*/, const Point /*target*/ )
{
    // do nothing so far
}

