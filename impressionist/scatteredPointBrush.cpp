#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "scatteredPointBrush.h"
#include "pointBrush.h"

extern float frand();

ScatteredPointBrush::ScatteredPointBrush( ImpressionistDoc* pDoc, char* name ) :
    ImpBrush(pDoc,name)
{
}

void ScatteredPointBrush::BrushBegin( const Point source, const Point target )
{
    //ImpressionistDoc* pDoc = GetDocument();
    //ImpressionistUI* dlg=pDoc->m_pUI;

    glPointSize(1.0f);

    BrushMove( source, target );
}

void ScatteredPointBrush::BrushMove( const Point source, const Point target )
{
    ImpressionistDoc* pDoc = GetDocument();
    //ImpressionistUI* dlg=pDoc->m_pUI;

    if ( pDoc == NULL ) {
        printf( "ScatteredPointBrush::BrushMove document is NULL\n" );
        return;
    }

    int size = pDoc->getSize();
    int halfSize = size / 2;
    int minX = source.x - halfSize;
    int maxX = minX + size;
    int minY = source.y - halfSize;
    int maxY = minY + size;
    int offsetX = target.x - source.x;
    int offsetY = target.y - source.y;

    glBegin(GL_POINTS);
        for (int x = minX; x <= maxX; x++)
        {
            for (int y = minY; y <= maxY; y++)
            {
                int paintPoint = rand() % 100;

                if (paintPoint >= 75)
                {
                    Point individualSource(x, y);
                    Point individualTarget(x + offsetX, y + offsetY);
                    PointBrush::DrawPoint(pDoc, individualSource, individualTarget);
                }
            }
        }
    glEnd();
}

void ScatteredPointBrush::BrushEnd( const Point /*source*/, const Point /*target*/ )
{
    // do nothing so far
}

