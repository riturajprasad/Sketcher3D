#include "Export.h"

// This class is exported from the dll
class GEOMETRY3D_API CGeometry3D {
public:
	CGeometry3D(void);
	// TODO: add your methods here.
};

extern GEOMETRY3D_API int nGeometry3D;

GEOMETRY3D_API int fnGeometry3D(void);
