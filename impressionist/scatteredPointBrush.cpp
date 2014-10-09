#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "scatteredPointBrush.h"

extern float frand();

ScatteredPointBrush::ScatteredPointBrush( ImpressionistDoc* pDoc, char* name ) :
    ImpBrush(pDoc,name)
{
}

void ScatteredPointBrush::BrushBegin( const Point source, const Point target )
{
    //ImpressionistDoc* pDoc = GetDocument();
    //ImpressionistUI* dlg=pDoc->m_pUI;

    BrushMove( source, target );
}

void ScatteredPointBrush::BrushMove( const Point source, const Point target )
{
    ImpressionistDoc* pDoc = GetDocument();
    //ImpressionistUI* dlg=pDoc->m_pUI;

    if ( pDoc == NULL ) {
        printf( "ScatteredPointBrush::BrushMove  document is NULL\n" );
        return;
    }

    double radius = static_cast<double>(pDoc->getSize());
    double drawingStep = 2.0 * M_PI / 100.0; // Draw a triangular fan with 100 parts to approximate a circle

    glBegin(GL_TRIANGLE_FAN);
        SetColor( source );

        glVertex2d(target.x, target.y);

        for (double theta = 0.0; theta < 2.0 * M_PI; theta += drawingStep)
        {
            glVertex2d(target.x + (sin(theta) * radius), target.y + (cos(theta) * radius));
        }

    glEnd();
}

void ScatteredPointBrush::BrushEnd( const Point /*source*/, const Point /*target*/ )
{
    // do nothing so far
}

