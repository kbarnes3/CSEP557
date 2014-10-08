#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "circleBrush.h"

extern float frand();

CircleBrush::CircleBrush( ImpressionistDoc* pDoc, char* name ) :
    ImpBrush(pDoc,name)
{
}

void CircleBrush::BrushBegin( const Point source, const Point target )
{
    //ImpressionistDoc* pDoc = GetDocument();
    //ImpressionistUI* dlg=pDoc->m_pUI;

    BrushMove( source, target );
}

void CircleBrush::BrushMove( const Point source, const Point target )
{
    ImpressionistDoc* pDoc = GetDocument();
    //ImpressionistUI* dlg=pDoc->m_pUI;

    if ( pDoc == NULL ) {
        printf( "CircleBrush::BrushMove  document is NULL\n" );
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

void CircleBrush::BrushEnd( const Point /*source*/, const Point /*target*/ )
{
    // do nothing so far
}

