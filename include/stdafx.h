#ifndef STDAFX_H
#define STDAFX_H
#ifdef __GNUC__
#define DEPRECATED __attribute__((deprecated))
#elif defined(_MSC_VER)
#define DEPRECATED __declspec(deprecated)
#endif

//#define GLX_GLXEXT_LEGACY
//#define GL_GLEXT_PROTOTYPES 1
//#define GLX_GLXEXT_PROTOTYPES 1
//#define GL3_PROTOTYPES 1
//#define PI 3.1415926535897932384626433832795

//Standard Header
#include <fstream>
#include <iostream>
#include <ios>

#include <exception>
#include <vector>
#include <algorithm>
#include <time.h>
#include <typeinfo>
#include <math.h>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <stdlib.h>
#include <list>
#include <limits.h>
#include <string.h>
#include <sstream>
#include <mutex>
#include <map>

#ifdef  __linux__

#include <sys/time.h>
#include <dirent.h>

//X11
//#include<X11/X.h>
//#include<X11/Xlib.h>

//OpenGL
//#include <GL/gl.h>
//#include <GL/glu.h>

//GLX - GLUT
//#include <GL/glx.h>
//#include <GL/glut.h>

//OpenGL Extensions
//#include <GL/glext.h>      // OpenGL v1.2
//#include <GL/glxext.h>     // GLX 1.3 API
//#include <GL/glcorearb.h>  // ARB Extensions

#elif _WIN32

//#include <tkPlatDecls.h>
#include "windows.h"

#ifndef _DEBUG
#define _DEBUG
#endif


//OpenGL
//#include <GL/gl.h>
//#include <GL/glu.h>
//#include <GL/glext.h>
//#include <GL/glcorearb.h>
//#include <GL/wglext.h>

//#pragma warning( disable : 4290 )
//#pragma warning( disable : 4244 )

#else
//other OS
#endif

using namespace std;

#endif // STDAFX_H

