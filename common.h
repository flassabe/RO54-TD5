#include <gdal/ogr_geometry.h>

OGRGeometry *create(const char *wkt) {
  OGRGeometry *g;
  if (OGRGeometryFactory::createFromWkt(wkt, nullptr, &g) == OGRERR_NONE)
    return g;
  else
    return nullptr;
}
