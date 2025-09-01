#-------------------------------------------------------------------------------------------------------------
add_library(dlibtmic SHARED "libtmic.cpp" libtmic.h)  # create .dll
#-------------------------------------------------------------------------------------------------------------
target_compile_definitions(dlibtmic PRIVATE DLIBTMIC_EXPORTS)  # export func for windows
#-------------------------------------------------------------------------------------------------------------

# set_property(TARGET dlibtmic PROPERTY CXX_STANDARD 23)  # sed STD23

target_include_directories(dlibtmic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})  # export folder for other project
#-------------------------------------------------------------------------------------------------------------
