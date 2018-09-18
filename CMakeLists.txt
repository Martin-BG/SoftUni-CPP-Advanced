cmake_minimum_required(VERSION 3.12)
project(CPP_Advanced)

set(CMAKE_CXX_STANDARD 11)

#######################################
set(L01 "01. C++ Pointers and References/")

set(L01_DEMOS "${L01}Demos/")
add_executable(L01_D01.ReferencesModifyingParameters "${L01_DEMOS}01. ReferencesModifyingParameters.cpp")
add_executable(L01_D02.ReferencesPerformance "${L01_DEMOS}02. ReferencesPerformance.cpp")
add_executable(L01_D03.PitfallReturningReferences "${L01_DEMOS}03. PitfallReturningReferences.cpp")
add_executable(L01_D04.ReferenceLimitations "${L01_DEMOS}04. ReferenceLimitations.cpp")
add_executable(L01_D05.GettingAddressesInCpp "${L01_DEMOS}05. GettingAddressesInCpp.cpp")
add_executable(L01_D06.ReferencingAndDereferencing "${L01_DEMOS}06. ReferencingAndDereferencing.cpp")
add_executable(L01_D07.PitfallIncrementBeforeDereferencePrecedence "${L01_DEMOS}07. PitfallIncrementBeforeDereferencePrecedence.cpp")
add_executable(L01_D08.UsingNullptr "${L01_DEMOS}08. UsingNullptr.cpp")
add_executable(L01_D09.PointersToConstData "${L01_DEMOS}09. PointersToConstData.cpp")
add_executable(L01_D10.PointerArithmetic "${L01_DEMOS}10. PointerArithmetic.cpp")
add_executable(L01_D11.PointersAsArrays "${L01_DEMOS}11. PointersAsArrays.cpp")
add_executable(L01_D12.FunFactIndexingOperatorSyntax "${L01_DEMOS}12. FunFactIndexingOperatorSyntax.cpp")

set(L01_EXERCISES "${L01}Exercises/")
set(L01_EXERCISES_E01 "${L01_EXERCISES}01. FollowPointers/")
add_executable(L01_E01.FollowPointers ${L01_EXERCISES_E01}main.cpp ${L01_EXERCISES_E01}Node.h ${L01_EXERCISES_E01}FollowPointers.h)

set(L01_HOMEWORK "${L01}Homework/")
set(L01_HOMEWORK_01 "${L01_HOMEWORK}01. TryParse/")
set(L01_HOMEWORK_02 "${L01_HOMEWORK}02. Find/")
set(L01_HOMEWORK_03 "${L01_HOMEWORK}03. Order/")
set(L01_HOMEWORK_04 "${L01_HOMEWORK}04. Profits/")
set(L01_HOMEWORK_05 "${L01_HOMEWORK}05. Memory/")
add_executable(L01_H01.TryParse ${L01_HOMEWORK_01}Main.cpp ${L01_HOMEWORK_01}TryParse.h)
add_executable(L01_H02.Find ${L01_HOMEWORK_02}Main.cpp ${L01_HOMEWORK_02}Company.h ${L01_HOMEWORK_02}Find.h)
add_executable(L01_H03.Order ${L01_HOMEWORK_03}OrderMain.cpp ${L01_HOMEWORK_03}Company.h ${L01_HOMEWORK_03}OrderedInserter.h)
add_executable(L01_H04.Profits ${L01_HOMEWORK_04}ProfitsMain.cpp ${L01_HOMEWORK_04}Company.h ${L01_HOMEWORK_04}ProfitCalculator.h ${L01_HOMEWORK_04}ProfitReport.h)
add_executable(L01_H05.Memory ${L01_HOMEWORK_05}MemoryMain.cpp ${L01_HOMEWORK_05}Company.h ${L01_HOMEWORK_05}CompanyMemoryUtils.h)

#######################################
set(L02 "02. Memory Management/")

set(L02_DEMOS "${L02}Demos/")
add_executable(L02_D01.FunctionPointers "${L02_DEMOS}01. FunctionPointers.cpp")
add_executable(L02_D02.VoidPointer "${L02_DEMOS}02. VoidPointer.cpp")
add_executable(L02_D03.PitfallUncheckedCStyleCasting "${L02_DEMOS}03. PitfallUncheckedCStyleCasting.cpp")
add_executable(L02_D04.CastingPointers "${L02_DEMOS}04. CastingPointers.cpp")
add_executable(L02_D05.AutomaticStorage "${L02_DEMOS}05. AutomaticStorage.cpp")
add_executable(L02_D06.OperatorNew "${L02_DEMOS}06. OperatorNew.cpp")
add_executable(L02_D07.ReleasingUnusedMemory "${L02_DEMOS}07. ReleasingUnusedMemory.cpp")
add_executable(L02_D08.PitfallDeletingMemoryMoreThanOnce "${L02_DEMOS}08. PitfallDeletingMemoryMoreThanOnce.cpp")
add_executable(L02_D09.PitfallDeletingPointerContainerBeforePointersInside "${L02_DEMOS}09. PitfallDeletingPointerContainerBeforePointersInside.cpp")
add_executable(L02_D10.UniquePtr "${L02_DEMOS}10. UniquePtr.cpp")
add_executable(L02_D11.SharedPtr "${L02_DEMOS}11. SharedPtr.cpp")

set(L02_EXERCISES "${L02}Exercises/")
set(L02_EXERCISES_E01 "${L02_EXERCISES}01. Filter/")
set(L02_EXERCISES_E02 "${L02_EXERCISES}02. LargestSumArrayNewDelete/")
add_executable(L02_E01.Filter ${L02_EXERCISES_E01}Filter.cpp)
add_executable(L02_E02.LargestSumArrayNewDelete ${L02_EXERCISES_E02}LargestSumArrayNewDelete.cpp)

set(L02_HOMEWORK "${L02}Homework/")
set(L02_HOMEWORK_01 "${L02_HOMEWORK}01. MinBy/")
set(L02_HOMEWORK_02 "${L02_HOMEWORK}02. Remove Invalid/")
set(L02_HOMEWORK_03 "${L02_HOMEWORK}03. Make Company/")
set(L02_HOMEWORK_04 "${L02_HOMEWORK}04. Parse Unique Companies/")
set(L02_HOMEWORK_05 "${L02_HOMEWORK}05. Serialize/")
add_executable(L02_H01.MinBy ${L02_HOMEWORK_01}MinByMain.cpp ${L02_HOMEWORK_01}MinBy.h)
add_executable(L02_H02.RemoveInvalid ${L02_HOMEWORK_02}RemoveInvlalidMain.cpp ${L02_HOMEWORK_02}Company.h ${L02_HOMEWORK_02}RemoveInvalid.h)
add_executable(L02_H03.MakeCompany ${L02_HOMEWORK_03}MakeCompanyMain.cpp ${L02_HOMEWORK_03}Company.h ${L02_HOMEWORK_03}MakeCompany.h)
add_executable(L02_H04.ParseUniqueCompanies ${L02_HOMEWORK_04}ParseUniqueCompaniesMain.cpp ${L02_HOMEWORK_04}Company.h ${L02_HOMEWORK_04}ParseCompanies.h)
add_executable(L02_H05.Serialize ${L02_HOMEWORK_05}SerializeMain.cpp ${L02_HOMEWORK_05}Company.h ${L02_HOMEWORK_05}Serialize.h)

#######################################
set(L03 "03. Exercises/")

set(L03_TASK_01 "${L03}01. Sort/")
set(L03_TASK_02 "${L03}02. Sort Pointers/")
set(L03_TASK_03 "${L03}03. Duplicates/")
set(L03_TASK_04 "${L03}04. Ranges/")
add_executable(L03_T01.Sort ${L03_TASK_01}SortMain.cpp ${L03_TASK_01}Company.h)
add_executable(L03_T02.SortPointers ${L03_TASK_02}SortPointersMain.cpp ${L03_TASK_02}Company.h ${L03_TASK_02}Sortby.h)
add_executable(L03_T03.Duplicates ${L03_TASK_03}DuplicatesMain.cpp ${L03_TASK_03}Company.h ${L03_TASK_03}RemoveDuplicates.h)
add_executable(L03_T04.Ranges ${L03_TASK_04}RangesMain.cpp)