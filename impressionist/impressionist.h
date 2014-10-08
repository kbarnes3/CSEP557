#ifndef IMPRESSIONIST_H
#define IMPRESSIONIST_H
#include <stdio.h>

#include <FL/Fl.H>
#include <FL/gl.h>

#ifdef __APPLE__
    #include <OpenGL/glu.h>
#else
    #include <GL/glu.h>
#endif

#pragma warning (disable : 4244)

#include "impBrush.h"

#define TRUE	1
#define FALSE	0

#ifdef WIN32
#define _USE_MATH_DEFINES
#include <cmath>
#endif


#endif

