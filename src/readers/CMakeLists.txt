
add_library(SvtDataReader SvtDataReader.cxx)
target_link_libraries(SvtDataReader ${ROGUE_LIBRARIES})

add_executable(test_reader test_reader.cxx)
target_link_libraries(test_reader LINK_PUBLIC
    SvtDataReader
    ${ROGUE_LIBRARIES}
)
