#ifndef _READSOURCES_H_
#define _READSOURCES_H_

#include <map>
#include <string>
#include <gdal/gdal_priv.h>

/*!
 * \class GDALDatasetWrapper provides a wrapper to handle safely the dataset type (manipulated in OGR through a pointer)
 */
class GDALDatasetWrapper {
  GDALDataset *dataset;

public:
  GDALDatasetWrapper(GDALDataset *d): dataset(d) {}
  ~GDALDatasetWrapper();
  GDALDatasetWrapper(const GDALDatasetWrapper &other) = delete;
  GDALDatasetWrapper &operator=(const GDALDatasetWrapper &other) = delete;
  GDALDataset *operator->();
  GDALDataset *get() {return dataset;}
  GDALDatasetWrapper(GDALDatasetWrapper &&other);
  GDALDatasetWrapper &operator=(GDALDatasetWrapper &&other);
};

/*!
 * \function readfiles imports the buildings from files (one per landuse type)
 * \param landuse_sources maps landuse text descriptors ("residential", "school", etc.) to the corresponding OSM files
 * \return a map associating landuse text descriptors with the resulting GDALDatasets after reading the source file
 * The GDALDatasets are returned in GDALDatasetWrappers to ensure their correct lifecycle.
 */
std::map<std::string, GDALDatasetWrapper> readfiles(const std::map<std::string, std::string> &landuses_sources);

#endif // _READSOURCES_H_
