//
// lineBrush.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "lineBrush.h"

extern float frand();

LineBrush::LineBrush( ImpressionistDoc* pDoc, char* name ) :
    ImpBrush(pDoc,name)
{
}

void LineBrush::BrushBegin( const Point source, const Point target )
{
    ImpressionistDoc* pDoc = GetDocument();
    //ImpressionistUI* dlg=pDoc->m_pUI;

    int width = pDoc->getLineWidth();

    glLineWidth(static_cast<float>(width));

    BrushMove( source, target );
}

void LineBrush::BrushMove( const Point source, const Point target )
{
    ImpressionistDoc* pDoc = GetDocument();
    //ImpressionistUI* dlg=pDoc->m_pUI;

    if ( pDoc == NULL ) {
        printf( "LineBrush::BrushMove  document is NULL\n" );
        return;
    }

    int size = pDoc->getSize();
    int halfSize = size / 2;
    int angle = pDoc->getLineAngle();

    glPushMatrix();
        glTranslatef(target.x, target.y, 0.0);
        glRotatef(angle, 0.0, 0.0, 1.0);

        glBegin( GL_LINES );
            SetColor( source );

            glVertex2d(-halfSize, 0);
            glVertex2d(size - halfSize, 0);

        glEnd();
    glPopMatrix();
}

void LineBrush::BrushEnd( const Point /*source*/, const Point /*target*/ )
{
    // do nothing so far
}

