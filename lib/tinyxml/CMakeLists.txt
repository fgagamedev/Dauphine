# Directories
#include_directories(${Jack_SOURCE_DIR}/include ${SYSTEM_LIB_DIR}/SDL-1.2/include)
#link_directories(${SYSTEM_LIB_DIR}/SDL-1.2/lib)

# Game library and executable
add_library(tinyxml tinystr.cpp tinyxml.cpp tinyxmlerror.cpp tinyxmlparser.cpp xmltest.cpp)
#add_executable(Jack_the_Janitor main.cpp)
#target_link_libraries(Jack_the_Janitor JackLib ${SYSTEM_LIBRARIES})

# Install files and directories
#install(TARGETS Jack_the_Janitor DESTINATION jtj/bin)
#install(PROGRAMS ${SYSTEM_DIR}/JackTheJanitor DESTINATION .)
#install(DIRECTORY ${SYSTEM_BIN_DIR}/lib/ DESTINATION jtj/lib)
#install(DIRECTORY ${ROOT_DIR}/resources DESTINATION jtj/)
