# LO53 -- TD7: GIS

## Context

In this session, your task is to build a representation of a landuse (i.e. what the geographical area is used to) map based on openstreetmap data. The main flow is the following:
1. Create a mesh grid
2. Import all OSM files
3. Convert all data to Lambert93
4. Go through the GDALDatasets and find the polygons defining buildings shapes
5. Compute the intersection between building shapes and the landuse mesh grid
6. Write their coverage rate in the mesh grid array.

## Creating a grid mesh

This is already implemented in the provided code.

## Importing all OSM files

Based on the lecture examples, use GDAL to import each OSM file into an element of the corresponding map (it is defined in the provided code). Your code will be located in the readsources.cpp file, according to the comments. Use the GDALDatasetWrapper to ensure proper cleaning of your class instances (see [RAII](https://en.wikipedia.org/wiki/Resource_acquisition_is_initialization) for more information).

The data files are available on moodle.

## Convert to Lambert93

With an instance of an OGRCoordinateTransformation, go through the datasets and convert every OGRGeometry to Lambert93. Your code will be located in conversion.cpp.

## Going through the datasets and computing landuse

Go through the datasets to find the polygons (based on GetType method provided by the OGRGeomFieldDefnRef pointer in OGRFeature), and compute the area of their intersections with meshes. You can use create from common.h to provide a well known text defining a mesh (with 5 points in it, first and last point being the same ones), then use Intersection and get_Area from OGR API. Then, landuse qualification is computed by the intersection area divided by the mesh area. This part requires to be a bit smart to avoid hours of computation.

## Output the results in files

For each landuse defined (in the map instanciated in the landuse.cpp), write its content into a file, one file line for each grid row, values separated by spaces. Files are named with the map key, and a .dat suffix.

## Upload your contribution

You must upload your work:
* C++ code in a new branch on the git repository
* Output files in the corresponding Moodle upload section.

The deadline is May, 19th 2019, 23:59 GMT+02.


