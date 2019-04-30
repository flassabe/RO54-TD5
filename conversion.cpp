#include "conversion.h"
#include <gdal/ogrsf_frmts.h>
#include <gdal/ogr_geometry.h>
#include <algorithm>
#include <iostream>

using namespace std;

/*!
 * \function dataset_conversion converts the data from WGS84 to dst (Lambert93 in this work)
 * \param dataset a GDALDataset to be converted
 * \param dst a target spatial reference (source is within the dataset members)
 * \return the envelope of the whole dataset (must be updated for each geometry)
 */
OGREnvelope dataset_conversion(GDALDataset *dataset, OGRSpatialReference *dst) {
  OGREnvelope env, current_env;
  // TODO: your code here
  return env;
}

void print_env(OGREnvelope env) {
  cout << "Envelope [" << env.MinX << " " << env.MinY << " "
       << env.MaxX << " " << env.MaxY << "]" << endl;
}
