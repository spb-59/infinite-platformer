add_test( [==[Player class tests]==] /home/spb/oop-project/test_runner [==[Player class tests]==]  )
set_tests_properties( [==[Player class tests]==] PROPERTIES WORKING_DIRECTORY /home/spb/oop-project)
add_test( [==[Platform class tests]==] /home/spb/oop-project/test_runner [==[Platform class tests]==]  )
set_tests_properties( [==[Platform class tests]==] PROPERTIES WORKING_DIRECTORY /home/spb/oop-project)
add_test( [==[LavaPit class tests]==] /home/spb/oop-project/test_runner [==[LavaPit class tests]==]  )
set_tests_properties( [==[LavaPit class tests]==] PROPERTIES WORKING_DIRECTORY /home/spb/oop-project)
add_test( [==[Spikes class tests]==] /home/spb/oop-project/test_runner [==[Spikes class tests]==]  )
set_tests_properties( [==[Spikes class tests]==] PROPERTIES WORKING_DIRECTORY /home/spb/oop-project)
add_test( [==[Collision detection]==] /home/spb/oop-project/test_runner [==[Collision detection]==]  )
set_tests_properties( [==[Collision detection]==] PROPERTIES WORKING_DIRECTORY /home/spb/oop-project)
add_test( [==[Generation Methods]==] /home/spb/oop-project/test_runner [==[Generation Methods]==]  )
set_tests_properties( [==[Generation Methods]==] PROPERTIES WORKING_DIRECTORY /home/spb/oop-project)
add_test( [==[Entity class tests]==] /home/spb/oop-project/test_runner [==[Entity class tests]==]  )
set_tests_properties( [==[Entity class tests]==] PROPERTIES WORKING_DIRECTORY /home/spb/oop-project)
set( test_runner_TESTS [==[Player class tests]==] [==[Platform class tests]==] [==[LavaPit class tests]==] [==[Spikes class tests]==] [==[Collision detection]==] [==[Generation Methods]==] [==[Entity class tests]==])
