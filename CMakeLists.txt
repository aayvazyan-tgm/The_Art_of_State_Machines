cmake_minimum_required(VERSION 2.8.4)
project(States)

set(SOURCE_FILES StateCentricStateMachine.c StateCentricHiddenTransactionsStateMachine.c EventCentricStateMachine.c StatePatternStateMachine.c TableDrivenStateMachine.c)
add_executable(States ${SOURCE_FILES})