cmake_minimum_required(VERSION 2.8.4)
project(States)

set(SOURCE_FILESStateCentric StateCentricStateMachine.c)
set(SOURCE_FILESStateCentricHidden StateCentricHiddenTransactionsStateMachine.c)
set(SOURCE_FILESEventCentric EventCentricStateMachine.c)
set(SOURCE_FILESStatePattern StatePatternStateMachine.c)
set(SOURCE_FILESTableDriven TableDrivenStateMachine.c)


add_executable(StateCentric ${SOURCE_FILESStateCentric})
add_executable(StateCentricHidden ${SOURCE_FILESStateCentricHidden})
add_executable(EventCentric ${SOURCE_FILESEventCentric})
add_executable(StatePattern ${SOURCE_FILESStatePattern})
add_executable(TableDriven ${SOURCE_FILESTableDriven})