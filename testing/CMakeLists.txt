enable_testing()

add_executable(basic_testing testing/test_list.cpp)
target_link_libraries(basic_testing Catch fct)
add_test(NAME BasicTesting COMMAND basic_testing)


add_executable(transformations_testing testing/test_transformations.cpp)
target_link_libraries(transformations_testing Catch fct)
add_test(NAME TransformationsTesting COMMAND transformations_testing)