#ifndef _CONVERSION_H_
#define _CONVERSION_H_

#include <gdal/ogr_spatialref.h>
#include <gdal/gdal_priv.h>

OGREnvelope dataset_conversion(GDALDataset *dataset, OGRSpatialReference *dst);
void print_env(OGREnvelope env);

#endif // _CONVERSION_H_
