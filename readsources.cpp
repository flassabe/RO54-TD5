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
 * \function readfiles read sources files and put their GDALDatasets in wrappers indexed by landuse name
 * \param landuses_sources a map whose keys are landuse names and values are source files paths
 * \return a map whose keys are landuse names and values are the resulting GDALDatasets extracted from files
 */
map<string, GDALDatasetWrapper> readfiles(const map<string, string> &landuses_sources) {
  map<string, GDALDatasetWrapper> data;
  // TODO: your code here
  return data;
}

