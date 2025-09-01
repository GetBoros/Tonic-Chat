#-------------------------------------------------------------------------------------------------------------
add_library(dlibtmic SHARED "libtmic.cpp" libtmic.h)  # create .dll
#-------------------------------------------------------------------------------------------------------------
target_compile_features(dlibtmic PUBLIC cxx_std_23)  # enable STD23 modules features
if(MSVC)
    target_compile_options(dlibtmic PRIVATE /EHsc /W4 /WX /experimental:module /std:c++latest)
else()
    # Флаги для других компиляторов (GCC, Clang), если понадобятся
    # target_compile_options(dlibtmic PRIVATE -Wall -Wextra -Werror -std=c++2b)
endif()
target_compile_definitions(dlibtmic PRIVATE DLIBTMIC_EXPORTS)  # export func for windows
#-------------------------------------------------------------------------------------------------------------
target_sources(dlibtmic
    PUBLIC
        FILE_SET cxx_modules TYPE CXX_MODULES FILES
            "Modules/Clients/Clients.ixx"
)  # if .ixx(cpp modules) scan and generate .ifc || if PRIVATE only for this .dll
#-------------------------------------------------------------------------------------------------------------
target_include_directories(dlibtmic
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Modules
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)
# target_include_directories(dlibtmic PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Modules)  # header and folders see only current dll
# target_include_directories(dlibtmic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})  # export folder for other project
#-------------------------------------------------------------------------------------------------------------
