# TWS BMS Modbus protocol (used by daemon)
add_library(tws_bms_protocol STATIC
    protocol.cpp
)
target_include_directories(tws_bms_protocol PUBLIC ./ ${PROJECT_SOURCE_DIR}/include)

# TWS BMS client driver (used by client library)
add_library(tws_bms STATIC
    tws_bms_driver.cpp
)
target_include_directories(tws_bms PUBLIC ./ ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(tws_bms PUBLIC ${PUBLIC_DEPENDENCIES})
