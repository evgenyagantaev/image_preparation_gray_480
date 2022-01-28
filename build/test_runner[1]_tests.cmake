add_test( image480gray.initial /home/oem/workspace/cpp/image_preparation_gray_480/build/test_runner [==[--gtest_filter=image480gray.initial]==] --gtest_also_run_disabled_tests)
set_tests_properties( image480gray.initial PROPERTIES WORKING_DIRECTORY /home/oem/workspace/cpp/image_preparation_gray_480/build)
set( test_runner_TESTS image480gray.initial)
