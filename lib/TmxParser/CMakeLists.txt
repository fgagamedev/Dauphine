# Library
subdirs(base64 tinyxml zlib)

add_library(TmxParser OBJECT TmxEllipse.cpp TmxImage.cpp TmxImageLayer.cpp TmxLayer.cpp TmxMap.cpp TmxObject.cpp TmxObjectGroup.cpp TmxPolygon.cpp TmxPolyline.cpp TmxPropertySet.cpp TmxTile.cpp TmxTileset.cpp TmxUtil.cpp)

include_directories(base64)
include_directories(tinyxml)
include_directories(zlib)

add_library(tmxparser STATIC $<TARGET_OBJECTS:base64> $<TARGET_OBJECTS:tinyxml> $<TARGET_OBJECTS:zlib> $<TARGET_OBJECTS:TmxParser>)
