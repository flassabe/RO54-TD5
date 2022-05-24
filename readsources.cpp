#include "readsources.h"
#include <gdal/ogrsf_frmts.h>

using namespace std;

GDALDatasetWrapper::~GDALDatasetWrapper() {
  if(dataset)
    GDALClose(dataset);
}

GDALDataset *GDALDatasetWrapper::operator->() {
  return dataset;
}

GDALDatasetWrapper::GDALDatasetWrapper(GDALDatasetWrapper &&other) {
  dataset=other.dataset;
  other.dataset=nullptr;
}

GDALDatasetWrapper &GDALDatasetWrapper::operator=(GDALDatasetWrapper &&other) {
  dataset=other.dataset;
  other.dataset=nullptr;
  return *this;
}

/*!
 * \function readfiles imports the buildings from files (one per landuse type)
 * \param landuse_sources maps landuse text descriptors ("residential", "school", etc.) to the corresponding OSM files
 * \return a map associating landuse text descriptors with the resulting GDALDatasets after reading the source file
 * The GDALDatasets are returned in GDALDatasetWrappers to ensure their correct lifecycle.
 */
map<string, GDALDatasetWrapper> readfiles(const map<string, string> &landuses_sources) {
  map<string, GDALDatasetWrapper> data;
  GDALAllRegister();
  char **options = nullptr;
  options = CSLAddNameValue(options, "USE_CUSTOM_INDEXING", "NO");
  for (const auto &entry: landuses_sources) { // entry has two fields named first and second: first is the landuse type, second is the source file for this source
  // TODO: your code here: --------------------------------
    
  // END TODO ---------------------------------------------
  }
  CSLDestroy(options);
  return data;
}

