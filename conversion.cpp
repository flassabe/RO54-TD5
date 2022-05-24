#include "conversion.h"
#include <gdal/ogrsf_frmts.h>
#include <gdal/ogr_geometry.h>
#include <algorithm>
#include <iostream>

using namespace std;

/*!
 *  \brief dataset_conversion converts a landuse data structure coordinates system reference
 *  \param dataset the dataset to be converted
 *  \param dst the destination coordinates system reference
 *  \return a tuple whose first element is the largest envelop containing the data (updated for each layer), and whose second element is a vector of all geometries in the dataset
 */
tuple<OGREnvelope, vector<unique_ptr<OGRGeometry>>> dataset_conversion(GDALDataset *dataset, OGRSpatialReference *dst) {
  vector<unique_ptr<OGRGeometry>> v;
  OGREnvelope env, current_env;
  OGRSpatialReference *src_ref = dataset->GetLayers()[0]->GetSpatialRef();
  if (src_ref != nullptr) {
	  // TODO: your code here
    
    // End of your code
  }
  return make_tuple<OGREnvelope, vector<unique_ptr<OGRGeometry>>>(move(env), move(v));
}

void print_env(OGREnvelope env) {
  cout << "Envelope [" << env.MinX << " " << env.MinY << " "
       << env.MaxX << " " << env.MaxY << "]" << endl;
}
