cmake_minimum_required(VERSION 3.12)
project(CPP_Advanced)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wcast-align -Wcast-qual -Wconversion -Wdouble-promotion -Werror -Wextra -Wnon-virtual-dtor -Wnull-dereference -Woverloaded-virtual -Wpedantic -Wpointer-arith -Wreorder -Wshadow -Wsign-conversion -Wundef -Wuninitialized -Wunused-parameter -Wextra-semi -Wunused -Wimplicit-fallthrough -Wformat=2")

#######################################
set(L01 "01. Pointers and References/")

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
add_executable(L03_T02.SortPointers ${L03_TASK_02}SortPointersMain.cpp ${L03_TASK_02}Company.h ${L03_TASK_02}SortBy.h)
add_executable(L03_T03.Duplicates ${L03_TASK_03}DuplicatesMain.cpp ${L03_TASK_03}Company.h ${L03_TASK_03}RemoveDuplicates.h)
add_executable(L03_T04.Ranges ${L03_TASK_04}RangesMain.cpp)

#######################################
set(L04 "04. Class Members/")

set(L04_DEMOS "${L04}Demos/")
add_executable(L04_D01.Namespaces "${L04_DEMOS}01. Namespaces.cpp")
add_executable(L04_D02.StaticMembers "${L04_DEMOS}02. StaticMembers.cpp")
add_executable(L04_D03.ConstMembers "${L04_DEMOS}03. ConstMembers.cpp")
add_executable(L04_D04.PitfallForgettingToMarkMethodConst "${L04_DEMOS}04. PitfallForgettingToMarkMethodConst.cpp")
add_executable(L04_D05.Friends "${L04_DEMOS}05. Friends.cpp")
add_executable(L04_D06.MemberOperatorOverload "${L04_DEMOS}06. MemberOperatorOverload.cpp")
add_executable(L04_D07.NonMemberOperatorOverload "${L04_DEMOS}07. NonMemberOperatorOverload.cpp")
add_executable(L04_D08.PitfallMissingReturnStreamOperatorOverload "${L04_DEMOS}08. PitfallMissingReturnStreamOperatorOverload.cpp")
add_executable(L04_D09.ComparisonOperatorOverloading "${L04_DEMOS}09. ComparisonOperatorOverloading.cpp")
add_executable(L04_D10.PitfallMissingConstOnOverloadForSTL "${L04_DEMOS}10. PitfallMissingConstOnOverloadForSTL.cpp")

set(L04_EXERCISES "${L04}Exercises/")
set(L04_EXERCISES_E01 "${L04_EXERCISES}01. Rolling Sticks/")
set(L04_EXERCISES_E02 "${L04_EXERCISES}02. Fraction/")
add_executable(L04_E01.RollingSticks ${L04_EXERCISES_E01}RollingSticksMain.cpp ${L04_EXERCISES_E01}Stick.h)
add_executable(L04_E02.Fraction ${L04_EXERCISES_E02}FractionMain.cpp ${L04_EXERCISES_E02}Fraction.cpp)

set(L04_HOMEWORK "${L04}Homework/")
set(L04_HOMEWORK_01 "${L04_HOMEWORK}01. Car/")
set(L04_HOMEWORK_02 "${L04_HOMEWORK}02. Sum Of Vectors/")
set(L04_HOMEWORK_03 "${L04_HOMEWORK}03. Operators/")
set(L04_HOMEWORK_04 "${L04_HOMEWORK}04. Resources/")
set(L04_HOMEWORK_05 "${L04_HOMEWORK}05. Lectures/")
add_executable(L04_H01.Car ${L04_HOMEWORK_01}CarMain.cpp ${L04_HOMEWORK_01}Car.h)
add_executable(L04_H02.SumOfVectors ${L04_HOMEWORK_02}Main.cpp ${L04_HOMEWORK_02}SumOfVectors.h)
add_executable(L04_H03.Operators ${L04_HOMEWORK_03}OperatorsMain.cpp ${L04_HOMEWORK_03}Operators.h)
add_executable(L04_H04.Resources ${L04_HOMEWORK_04}ResourcesMain.cpp ${L04_HOMEWORK_04}ResourceType.h ${L04_HOMEWORK_04}Resource.h)
add_executable(L04_H05.Lectures ${L04_HOMEWORK_05}LecturesMain.cpp ${L04_HOMEWORK_05}ResourceType.h ${L04_HOMEWORK_05}Lecture.h)

#######################################
set(L05 "05. Code Organization and Templates/")

set(L05_DEMOS "${L05}Demos/")

set(L05_D01 "${L05_DEMOS}01. IncludeAndDefine/")
add_executable(L05_D01.IncludeAndDefine ${L05_D01}IncludeAndDefineMain.cpp ${L05_D01}Macros.h)

set(L05_D02 "${L05_DEMOS}02. PitfallMacrosBracketsInExpressions/")
add_executable(L05_D02.PitfallMacrosBracketsInExpressions ${L05_D02}PitfallMissingBracketsInMacroExpressions.cpp)

set(L05_D03 "${L05_DEMOS}03. ConditionalInclusionsAndIncludeGuards/")
add_executable(L05_D03.ConditionalInclusionsAndIncludeGuards ${L05_D03}ConditionalInclusionsAndIncludeGuards.cpp
        ${L05_D03}HeaderGuardedFile.h ${L05_D03}OtherFileAlsoIncludingHeaderGuardedFile.h)

set(L05_D04 "${L05_DEMOS}04. SeparatingDeclarationAndImplementation/")
add_executable(L05_D04.SeparatingDeclarationAndImplementation "${L05_D04}SeparatingMemberDefinitions.cpp")

set(L05_D05 "${L05_DEMOS}05. HeaderAndSourceFiles/")
add_executable(L05_D05.HeaderAndSourceFiles ${L05_D05}HeaderAndSourceFilesMain.cpp ${L05_D05}Company.cpp)

set(L05_D06 "${L05_DEMOS}06. FunctionTemplates/")
add_executable(L05_D06.FunctionTemplates ${L05_D06}FunctionTemplatesMain.cpp ${L05_D06}Fraction.h)

set(L05_D07 "${L05_DEMOS}07. ClassTemplates/")
add_executable(L05_D07.ClassTemplates ${L05_D07}ClassTemplatesMain.cpp ${L05_D07}Pair.h)

set(L05_D08 "${L05_DEMOS}08. AccessingTemplateSubtype/")
add_executable(L05_D08.AccessingTemplateSubtype ${L05_D08}AccessingTemplateSubtype.cpp)

set(L05_D09 "${L05_DEMOS}09. TemplateSpecialization/")
add_executable(L05_D09.TemplateSpecialization ${L05_D09}TemplateSpecialization.cpp)

set(L05_HOMEWORK "${L05}Homework/")
set(L05_HOMEWORK_01 "${L05_HOMEWORK}01. Compile/")
set(L05_HOMEWORK_02 "${L05_HOMEWORK}02. Censorship/")
set(L05_HOMEWORK_03 "${L05_HOMEWORK}03. Parser/")
set(L05_HOMEWORK_04 "${L05_HOMEWORK}04. Split and Join/")
set(L05_HOMEWORK_05 "${L05_HOMEWORK}05. Sorting/")
add_executable(L05_H01.Compile ${L05_HOMEWORK_01}CompileMain.cpp ${L05_HOMEWORK_01}Defines.h)
add_executable(L05_H02.Censorship ${L05_HOMEWORK_02}CensorshipMain.cpp ${L05_HOMEWORK_02}Article13Filter.cpp)
add_executable(L05_H03.Parser ${L05_HOMEWORK_03}ParserMain.cpp ${L05_HOMEWORK_03}Parser.h ${L05_HOMEWORK_03}PrintUtils.h)
add_executable(L05_H04.SplitAndJoin ${L05_HOMEWORK_04}SplitAndJoinMain.cpp
        ${L05_HOMEWORK_04}Join.h ${L05_HOMEWORK_04}Split.h)
add_executable(L05_H05.Sorting ${L05_HOMEWORK_05}SortingMain.cpp ${L05_HOMEWORK_05}Song.h ${L05_HOMEWORK_05}Parser.h
        ${L05_HOMEWORK_05}Comparators.h ${L05_HOMEWORK_05}PrintUtils.h)

#######################################
set(L06 "06. Exercises/")

set(L06_TASK_01 "${L06}01. Echo/")
set(L06_TASK_02 "${L06}02. Notes/")
set(L06_TASK_03 "${L06}03. Vectors/")
set(L06_TASK_04 "${L06}04. DivisibleBy45/")
set(L06_TASK_05 "${L06}05. Sequences/")
add_executable(L06_T01.Echo ${L06_TASK_01}EchoMain.cpp ${L06_TASK_01}ContactManagerUI.cpp ${L06_TASK_01}EmailContact.cpp ${L06_TASK_01}Echo.cpp)
add_executable(L06_T02.Notes ${L06_TASK_02}NotesMain.cpp ${L06_TASK_02}NoteName.h ${L06_TASK_02}SolfegeNoteNaming.h)
add_executable(L06_T03.Vectors ${L06_TASK_03}VectorsMain.cpp ${L06_TASK_03}Vector.h ${L06_TASK_03}VectorComparisons.h)
add_executable(L06_T04.DivisibleBy45 ${L06_TASK_04}DivisibleBy45Main.cpp ${L06_TASK_04}BigInt.h)
add_executable(L06_T05.Sequences ${L06_TASK_05}SequencesMain.cpp ${L06_TASK_05}Sequence.h)

#######################################
set(L07 "07. Destructors, Constructors, Copy-Assignment/")

set(L07_DEMOS "${L07}Demos/")
add_executable(L07_D01.DefaultConstructor "${L07_DEMOS}01. DefaultConstructor.cpp")
add_executable(L07_D02.CopyConstructionAndAssignment "${L07_DEMOS}02. CopyConstructionAndAssignment.cpp")
add_executable(L07_D03.Destructor "${L07_DEMOS}03. Destructor.cpp")
add_executable(L07_D04.DefaultAndDeletedMembers "${L07_DEMOS}04. DefaultAndDeletedMembers.cpp")
add_executable(L07_D05.ObjectCopyInCopyConstructor "${L07_DEMOS}05. ObjectCopyInCopyConstructor.cpp")
add_executable(L07_D06.ConstructorAndDestructorNotSufficient "${L07_DEMOS}06. ConstructorAndDestructorNotSufficient.cpp")
add_executable(L07_D07.RuleOfThree "${L07_DEMOS}07. RuleOfThree.cpp")
add_executable(L07_D08.PitfallMissingSelfAssignmentCheck "${L07_DEMOS}08. PitfallMissingSelfAssignmentCheck.cpp")
add_executable(L07_D09.RuleOfZero "${L07_DEMOS}09. RuleOfZero.cpp")

set(L07_EXERCISE "${L07}Exercises/")
set(L07_EXERCISES_E01 "${L07_EXERCISE}01. SmartArray/")
add_executable(L07_E01.SmartArray ${L07_EXERCISES_E01}/SmartArrayMain.cpp ${L07_EXERCISES_E01}/SmartArray.h)

set(L07_HOMEWORK "${L07}Homework/")
set(L07_HOMEWORK_01 "${L07_HOMEWORK}01. Register/")
set(L07_HOMEWORK_02 "${L07_HOMEWORK}02. Register of Three/")
set(L07_HOMEWORK_03 "${L07_HOMEWORK}03. Array of Pointers/")
set(L07_HOMEWORK_04 "${L07_HOMEWORK}04. Words/")
set(L07_HOMEWORK_05 "${L07_HOMEWORK}05. List/")
add_executable(L07_H01.Register ${L07_HOMEWORK_01}RegisterMain.cpp ${L07_HOMEWORK_01}Register.cpp ${L07_HOMEWORK_01}Company.h)
add_executable(L07_H02.RegisterOfThree ${L07_HOMEWORK_02}RegisterMain.cpp ${L07_HOMEWORK_02}Register.cpp ${L07_HOMEWORK_02}Company.h)
add_executable(L07_H03.ArrayOfPointers ${L07_HOMEWORK_03}ArrayOfPointersMain.cpp ${L07_HOMEWORK_03}Company.h ${L07_HOMEWORK_03}ArrayOfPointers.h)
add_executable(L07_H04.Words ${L07_HOMEWORK_04}WordsMain.cpp ${L07_HOMEWORK_04}Word.h)
add_executable(L07_H05.List ${L07_HOMEWORK_05}ListMain.cpp ${L07_HOMEWORK_05}List.cpp)

#######################################
set(L08 "08. Inheritance and Polymorphism/")

set(L08_DEMOS "${L08}Demos/")
add_executable(L08_D01.Inheritance "${L08_DEMOS}01. Inheritance.cpp")
add_executable(L08_D02.ProtectedMembers "${L08_DEMOS}02. ProtectedMembers.cpp")
add_executable(L08_D03.CallingBaseConstructorsAndMethods "${L08_DEMOS}03. CallingBaseConstructorsAndMethods.cpp")
add_executable(L08_D04.ObjectSlicing "${L08_DEMOS}04. ObjectSlicing.cpp")
add_executable(L08_D05.PitfallSlicingOutAHiddenField "${L08_DEMOS}05. PitfallSlicingOutAHiddenField.cpp")
add_executable(L08_D06.BasePointerToDerived "${L08_DEMOS}06. BasePointerToDerived.cpp")
add_executable(L08_D07.VirtualMembersAndBasePointers "${L08_DEMOS}07. VirtualMembersAndBasePointers.cpp")
add_executable(L08_D08.PitfallNoVirtualDestructor "${L08_DEMOS}08. PitfallNoVirtualDestructor.cpp")
add_executable(L08_D09.UsingPolymorphism "${L08_DEMOS}09. UsingPolymorphism.cpp")

set(L08_EXERCISE "${L08}Exercises/")
set(L08_EXERCISES_E01 "${L08_EXERCISE}ParticleSystem/")
file(GLOB L08_EXERCISES_E01_H "L08_EXERCISES_E01/*.h")
add_executable(L08_E01.ParticleSystem ${L08_EXERCISES_E01}/ParticleSystemMain.cpp ${L08_EXERCISES_E01_H})

set(L08_HOMEWORK "${L08}Homework/")
set(L08_HOMEWORK_01 "${L08_HOMEWORK}01. Shapes/")
file(GLOB L08_HOMEWORK_01_H ${L08_HOMEWORK_01}/*.h)
set(L08_HOMEWORK_02 "${L08_HOMEWORK}02. Aggregators/")
file(GLOB L08_HOMEWORK_02_H ${L08_HOMEWORK_02}/*.h)
set(L08_HOMEWORK_03 "${L08_HOMEWORK}03. Typed Stream/")
file(GLOB L08_HOMEWORK_03_H ${L08_HOMEWORK_03}/*.h)
set(L08_HOMEWORK_04 "${L08_HOMEWORK}04. Word/")
file(GLOB L08_HOMEWORK_04_H ${L08_HOMEWORK_04}/*.h)
set(L08_HOMEWORK_05 "${L08_HOMEWORK}05. Calculator/")
file(GLOB L08_HOMEWORK_05_H ${L08_HOMEWORK_05}/*.h)
add_executable(L08_H01.Shapes ${L08_HOMEWORK_01}/ShapesMain.cpp ${L08_HOMEWORK_01}/Constants.cpp ${L08_HOMEWORK_01_H})
add_executable(L08_H02.Aggregators ${L08_HOMEWORK_02}/AggregatorsMain.cpp ${L08_HOMEWORK_02_H})
add_executable(L08_H03.TypedStream ${L08_HOMEWORK_03}/TypedStreamMain.cpp ${L08_HOMEWORK_03_H})
add_executable(L08_H04.Word ${L08_HOMEWORK_04}/WordSkeleton.cpp ${L08_HOMEWORK_04_H})
add_executable(L08_H05.Calculator ${L08_HOMEWORK_05}/CalculatorMain.cpp ${L08_HOMEWORK_05_H})

#######################################
set(L09 "09. Pure Virtual Members and Multiple Inheritance/")

set(L09_DEMOS "${L09}Demos/")
add_executable(L09_D01.InheritanceInMemory "${L09_DEMOS}01. InheritanceInMemory.cpp")
add_executable(L09_D02.PolymorphismInMemory "${L09_DEMOS}02. PolymorphismInMemory.cpp")
add_executable(L09_D03.PureVirtualMethods "${L09_DEMOS}03. PureVirtualMethods.cpp")
add_executable(L09_D04.OOPInterfacesUsage "${L09_DEMOS}04. OOPInterfacesUsage.cpp")
add_executable(L09_D05.MultipleInheritance "${L09_DEMOS}05. MultipleInheritance.cpp")
add_executable(L09_D06.VirtualInheritance "${L09_DEMOS}06. VirtualInheritance.cpp")
add_executable(L09_D07.DynamicCast "${L09_DEMOS}07. DynamicCast.cpp")


set(L09_EXERCISE "${L09}Exercises/")

set(L09_EXERCISES_E01 "${L09_EXERCISE}Zoo/")
file(GLOB L09_EXERCISES_E01_H "L09_EXERCISES_E01/*.h")
add_executable(L09_E01.Zoo ${L09_EXERCISES_E01}/ZooMain.cpp ${L09_EXERCISES_E01_H})


set(L09_HOMEWORK "${L09}Homework/")

set(L09_HOMEWORK_01 "${L09_HOMEWORK}01. Filters/")
file(GLOB L09_HOMEWORK_01_H ${L09_HOMEWORK_01}/*.h)
add_executable(L09_H01.Filters ${L09_HOMEWORK_01}/FiltersMain.cpp ${L09_HOMEWORK_01_H})

set(L09_HOMEWORK_02 "${L09_HOMEWORK}02. IDs/")
file(GLOB L09_HOMEWORK_02_H ${L09_HOMEWORK_02}/*.h)
add_executable(L09_H02.IDs ${L09_HOMEWORK_02}/IDsMain.cpp ${L09_HOMEWORK_02}/Company.cpp ${L09_HOMEWORK_02_H})

set(L09_HOMEWORK_03 "${L09_HOMEWORK}03. Files/")
file(GLOB L09_HOMEWORK_03_H ${L09_HOMEWORK_03}/*.h)
add_executable(L09_H03.Files ${L09_HOMEWORK_03}/FilesMain.cpp ${L09_HOMEWORK_03_H})

set(L09_HOMEWORK_04 "${L09_HOMEWORK}04. Tree/")
file(GLOB L09_HOMEWORK_04_H ${L09_HOMEWORK_04}/*.h)
add_executable(L09_H04.Tree ${L09_HOMEWORK_04}/TreeMain.cpp ${L09_HOMEWORK_04_H})

set(L09_HOMEWORK_05 "${L09_HOMEWORK}05. Explorer/")
file(GLOB L09_HOMEWORK_05_H ${L09_HOMEWORK_05}/*.h)
add_executable(L09_H05.Explorer ${L09_HOMEWORK_05}/ExplorerMain.cpp ${L09_HOMEWORK_05_H})


#######################################
set(L10 "10. Exercises/")

set(L10_TASK_01 "${L10}01. MaxSumArray/")
file(GLOB L10_TASK_01_H ${L10_TASK_01}/*.h)
add_executable(L10_T01.MaxSumArray ${L10_TASK_01}MaxSumArrayMain.cpp ${L10_TASK_01_H})

set(L10_TASK_02 "${L10}02. IndexedSet/")
file(GLOB L10_TASK_02_H ${L10_TASK_02}/*.h)
add_executable(L10_T02.IndexedSet ${L10_TASK_02}main.cpp ${L10_TASK_02}IndexedSet.cpp ${L10_TASK_02_H})

set(L10_TASK_03 "${L10}03. Extractor/")
file(GLOB L10_TASK_03_H ${L10_TASK_03}/*.h)
add_executable(L10_T03.Extractor ${L10_TASK_03}ExtractorMain.cpp ${L10_TASK_03_H})

set(L10_TASK_04 "${L10}04. Word/")
file(GLOB L10_TASK_04_H ${L10_TASK_04}/*.h)
add_executable(L10_T04.Word ${L10_TASK_04}WordSkeleton.cpp ${L10_TASK_04_H})

#######################################
set(L11 "11. Exam Preparation/")

set(L11_TASK_01 "${L11}01. Census/")
file(GLOB L11_TASK_01_H ${L11_TASK_01}/*.h)
add_executable(L11_T01.Census ${L11_TASK_01}CensusMain.cpp ${L11_TASK_01_H})

set(L11_TASK_02 "${L11}02. Differences/")
file(GLOB L11_TASK_02_H ${L11_TASK_02}/*.h)
add_executable(L11_T02.Differences ${L11_TASK_02}ChangesMain.cpp ${L11_TASK_02_H})

set(L11_TASK_03 "${L11}03. Range/")
file(GLOB L11_TASK_03_H ${L11_TASK_03}/*.h)
add_executable(L11_T03.Range ${L11_TASK_03}RangeMain.cpp ${L11_TASK_03}Range.cpp ${L11_TASK_03_H})

set(L11_TASK_04 "${L11}04. Calculator/")
file(GLOB L11_TASK_04_H ${L11_TASK_04}/*.h)
add_executable(L11_T04.Calculator ${L11_TASK_04}CalculatorMain.cpp ${L11_TASK_04_H})

#######################################
set(L12 "12. Exam/")

set(L12_TASK_01 "${L12}01. Strings/")
file(GLOB L12_TASK_01_H ${L12_TASK_01}/*.h)
add_executable(L12_T01.Strings ${L12_TASK_01}StringsMain.cpp ${L12_TASK_01_H})

set(L12_TASK_02 "${L12}02. Max Reader/")
file(GLOB L12_TASK_02_H ${L12_TASK_02}/*.h)
add_executable(L12_T02.MaxReader ${L12_TASK_02}ReaderMain.cpp ${L12_TASK_02_H})

set(L12_TASK_03 "${L12}03. Groups/")
file(GLOB L12_TASK_03_H ${L12_TASK_03}/*.h)
add_executable(L12_T03.Groups ${L12_TASK_03}GroupsMain.cpp ${L12_TASK_03}Unit.cpp ${L12_TASK_03}Group.cpp ${L12_TASK_03_H})

set(L12_TASK_04 "${L12}04. Terran/")
file(GLOB L12_TASK_04_H ${L12_TASK_04}/*.h)
add_executable(L12_T04.Terran ${L12_TASK_04}TerranMain.cpp ${L12_TASK_04_H})

#######################################
set(L13 "13. Exam Retake/")

set(L13_TASK_01 "${L13}01. Bytes/")
file(GLOB L13_TASK_01_H ${L13_TASK_01}/*.h)
add_executable(L13_T01.Bytes ${L13_TASK_01}BytesMain.cpp ${L13_TASK_01_H})

set(L13_TASK_02 "${L13}02. Iterator/")
file(GLOB L13_TASK_02_H ${L13_TASK_02}/*.h)
add_executable(L13_T02.Iterator ${L13_TASK_02}IteratorMain.cpp ${L13_TASK_02_H})

set(L13_TASK_03 "${L13}03. UnitPtr/")
file(GLOB L13_TASK_03_H ${L13_TASK_03}/*.h)
add_executable(L13_T03.UnitPtr ${L13_TASK_03}UnitPtrMain.cpp ${L13_TASK_03}Unit.cpp ${L13_TASK_03}Group.cpp ${L13_TASK_03}UnitPtr.cpp ${L13_TASK_03_H})

set(L13_TASK_04 "${L13}04. Nodes/")
file(GLOB L13_TASK_04_H ${L13_TASK_04}/*.h)
add_executable(L13_T04.Nodes ${L13_TASK_04}NodesMain.cpp ${L13_TASK_04_H})

#######################################
set(L14 "14. Exams/")

###
set(L14_01 "${L14}2019.04.07/")

set(L14_01_TASK_01 "${L14_01}01. Memory Allocator/")
file(GLOB L14_01_TASK_01_H ${L14_01_TASK_01}/*.h)
file(GLOB L14_01_TASK_01_CPP ${L14_01_TASK_01}/*.cpp)
add_executable(L14_01_T01.MemoryAllocator ${L14_01_TASK_01_CPP} ${L14_01_TASK_01_H})

set(L14_01_TASK_02 "${L14_01}02. Bytes Parsing/")
file(GLOB L14_01_TASK_02_H ${L14_01_TASK_02}/*.h)
file(GLOB L14_01_TASK_02_CPP ${L14_01_TASK_02}/*.cpp)
add_executable(L14_01_T02.BytesParsing ${L14_01_TASK_02_CPP} ${L14_01_TASK_02_H})

set(L14_01_TASK_03 "${L14_01}03. Hardware Store/")
file(GLOB L14_01_TASK_03_H ${L14_01_TASK_03}/*.h)
file(GLOB L14_01_TASK_03_CPP ${L14_01_TASK_03}/*.cpp)
add_executable(L14_01_T03.HardwareStore ${L14_01_TASK_03_CPP} ${L14_01_TASK_03_H})

set(L14_01_TASK_04 "${L14_01}04. Warcraft IV/")
file(GLOB L14_01_TASK_04_H ${L14_01_TASK_04}/*.h)
file(GLOB L14_01_TASK_04_CPP ${L14_01_TASK_04}/*.cpp)
add_executable(L14_01_T04.WarcraftIV ${L14_01_TASK_04_CPP} ${L14_01_TASK_04_H})

###
set(L14_02 "${L14}2019.04.21/")

set(L14_02_TASK_01 "${L14_02}01. Cipher/")
file(GLOB L14_02_TASK_01_H ${L14_02_TASK_01}/*.h)
file(GLOB L14_02_TASK_01_CPP ${L14_02_TASK_01}/*.cpp)
add_executable(L14_02_T01.Cipher ${L14_02_TASK_01_CPP} ${L14_02_TASK_01_H})

set(L14_02_TASK_02 "${L14_02}02. Memory Allocator Reforged/")
file(GLOB L14_02_TASK_02_H ${L14_02_TASK_02}/*.h)
file(GLOB L14_02_TASK_02_CPP ${L14_02_TASK_02}/*.cpp)
add_executable(L14_02_T02.MemoryAllocatorReforged ${L14_02_TASK_02_CPP} ${L14_02_TASK_02_H})

set(L14_02_TASK_03 "${L14_02}03. Memory Nightmare/")
file(GLOB L14_02_TASK_03_H ${L14_02_TASK_03}/*.h)
file(GLOB L14_02_TASK_03_CPP ${L14_02_TASK_03}/*.cpp)
add_executable(L14_02_T03.MemoryNightmare ${L14_02_TASK_03_CPP} ${L14_02_TASK_03_H})

set(L14_02_TASK_04 "${L14_02}04. Overloading Madness/")
file(GLOB L14_02_TASK_04_H ${L14_02_TASK_04}/*.h)
file(GLOB L14_02_TASK_04_CPP ${L14_02_TASK_04}/*.cpp)
add_executable(L14_02_T04.OverloadingMadness ${L14_02_TASK_04_CPP} ${L14_02_TASK_04_H})

###
set(L14_03 "${L14}2020.02.29/")

set(L14_03_TASK_01 "${L14_03}01. Statistics/")
file(GLOB L14_03_TASK_01_H ${L14_03_TASK_01}/*.h)
file(GLOB L14_03_TASK_01_CPP ${L14_03_TASK_01}/*.cpp)
add_executable(L14_03_T01.Statistics ${L14_03_TASK_01_CPP} ${L14_03_TASK_01_H})

set(L14_03_TASK_02 "${L14_03}02. Array Trouble/")
file(GLOB L14_03_TASK_02_H ${L14_03_TASK_02}/*.h)
file(GLOB L14_03_TASK_02_CPP ${L14_03_TASK_02}/*.cpp)
add_executable(L14_03_T02.ArrayTrouble ${L14_03_TASK_02_CPP} ${L14_03_TASK_02_H})

set(L14_03_TASK_03 "${L14_03}03. Memory Pool/")
file(GLOB L14_03_TASK_03_H ${L14_03_TASK_03}/*.h)
file(GLOB L14_03_TASK_03_CPP ${L14_03_TASK_03}/*.cpp)
add_executable(L14_03_T03.MemoryPool ${L14_03_TASK_03_CPP} ${L14_03_TASK_03_H})

set(L14_03_TASK_04 "${L14_03}04. Starcraft III/")
file(GLOB L14_03_TASK_04_H ${L14_03_TASK_04}/*.h)
file(GLOB L14_03_TASK_04_CPP ${L14_03_TASK_04}/*.cpp)
add_executable(L14_03_T04.StarcraftIII ${L14_03_TASK_04_CPP} ${L14_03_TASK_04_H})

###
set(L14_04 "${L14}2020.03.15/")

set(L14_04_TASK_01 "${L14_04}01. String Concatenator/")
file(GLOB L14_04_TASK_01_H ${L14_04_TASK_01}/*.h)
file(GLOB L14_04_TASK_01_CPP ${L14_04_TASK_01}/*.cpp)
add_executable(L14_04_T01.StringConcatenator ${L14_04_TASK_01_CPP} ${L14_04_TASK_01_H})

set(L14_04_TASK_02 "${L14_04}02. Memory Monitor/")
file(GLOB L14_04_TASK_02_H ${L14_04_TASK_02}/*.h)
file(GLOB L14_04_TASK_02_CPP ${L14_04_TASK_02}/*.cpp)
add_executable(L14_04_T02.MemoryMonitor ${L14_04_TASK_02_CPP} ${L14_04_TASK_02_H})

set(L14_04_TASK_03 "${L14_04}03. Snake/")
file(GLOB L14_04_TASK_03_H ${L14_04_TASK_03}/*.h)
file(GLOB L14_04_TASK_03_CPP ${L14_04_TASK_03}/*.cpp)
add_executable(L14_04_T03.Snake ${L14_04_TASK_03_CPP} ${L14_04_TASK_03_H})

set(L14_04_TASK_04 "${L14_04}04. Pistol Round/")
file(GLOB L14_04_TASK_04_H ${L14_04_TASK_04}/*.h)
file(GLOB L14_04_TASK_04_CPP ${L14_04_TASK_04}/*.cpp)
add_executable(L14_04_T04.PistolRound ${L14_04_TASK_04_CPP} ${L14_04_TASK_04_H})

###
set(L14_05 "${L14}2020.09.05/")

set(L14_05_TASK_01 "${L14_05}01. Magic Kingdom/")
file(GLOB L14_05_TASK_01_H ${L14_05_TASK_01}/*.h)
file(GLOB L14_05_TASK_01_CPP ${L14_05_TASK_01}/*.cpp)
add_executable(L14_05_T01.MagicKingdom ${L14_05_TASK_01_CPP} ${L14_05_TASK_01_H})

set(L14_05_TASK_02 "${L14_05}02. Discoveries/")
file(GLOB L14_05_TASK_02_H ${L14_05_TASK_02}/*.h)
file(GLOB L14_05_TASK_02_CPP ${L14_05_TASK_02}/*.cpp)
add_executable(L14_05_T02.Discoveries ${L14_05_TASK_02_CPP} ${L14_05_TASK_02_H})

set(L14_05_TASK_03 "${L14_05}03. My Tropico/")
file(GLOB L14_05_TASK_03_H ${L14_05_TASK_03}/*.h)
file(GLOB L14_05_TASK_03_CPP ${L14_05_TASK_03}/*.cpp)
add_executable(L14_05_T03.MyTropico ${L14_05_TASK_03_CPP} ${L14_05_TASK_03_H})

###
set(L14_06 "${L14}2020.09.12/")

set(L14_06_TASK_01 "${L14_06}01. Animal Categories/")
file(GLOB L14_06_TASK_01_H ${L14_06_TASK_01}/*.h)
file(GLOB L14_06_TASK_01_CPP ${L14_06_TASK_01}/*.cpp)
add_executable(L14_06_T01.AnimalCategories ${L14_06_TASK_01_CPP} ${L14_06_TASK_01_H})

set(L14_06_TASK_02 "${L14_06}02. Scientists/")
file(GLOB L14_06_TASK_02_H ${L14_06_TASK_02}/*.h)
file(GLOB L14_06_TASK_02_CPP ${L14_06_TASK_02}/*.cpp)
add_executable(L14_06_T02.Scientists ${L14_06_TASK_02_CPP} ${L14_06_TASK_02_H})

set(L14_06_TASK_03 "${L14_06}03. Summer Festival/")
file(GLOB L14_06_TASK_03_H ${L14_06_TASK_03}/*.h)
file(GLOB L14_06_TASK_03_CPP ${L14_06_TASK_03}/*.cpp)
add_executable(L14_06_T03.SummerFestival ${L14_06_TASK_03_CPP} ${L14_06_TASK_03_H})

###
set(L14_07 "${L14}2021.07.03/")

add_executable(L14_07_TASK_01.FormatLines "${L14_07}01. Format Lines.cpp")
add_executable(L14_07_TASK_02.Ranges "${L14_07}02. Ranges.cpp")
add_executable(L14_07_TASK_03.Glitches "${L14_07}03. Glitches.cpp")

###
set(L14_08 "${L14}2021.07.10/")

add_executable(L14_08_TASK_01.Entities "${L14_08}01. Entities.cpp")
add_executable(L14_08_TASK_02.Code "${L14_08}02. Code.cpp")
add_executable(L14_08_TASK_03.Data "${L14_08}03. Data.cpp")

###
set(L14_09 "${L14}2021.09.12/")

set(L14_09_TASK_01 "${L14_09}01. String Wrapper/")
file(GLOB L14_09_TASK_01_H ${L14_09_TASK_01}/*.h)
file(GLOB L14_09_TASK_01_CPP ${L14_09_TASK_01}/*.cpp)
add_executable(L14_09_T01.StringWrapper ${L14_09_TASK_01_CPP} ${L14_09_TASK_01_H})

set(L14_09_TASK_02 "${L14_09}02. Console Store/")
file(GLOB L14_09_TASK_02_H ${L14_09_TASK_02}/*.h)
file(GLOB L14_09_TASK_02_CPP ${L14_09_TASK_02}/*.cpp)
add_executable(L14_09_T02.ConsoleStore ${L14_09_TASK_02_CPP} ${L14_09_TASK_02_H})

set(L14_09_TASK_03 "${L14_09}03. Diablo/")
file(GLOB L14_09_TASK_03_H ${L14_09_TASK_03}/*.h)
file(GLOB L14_09_TASK_03_CPP ${L14_09_TASK_03}/*.cpp)
add_executable(L14_09_T03.Diablo ${L14_09_TASK_03_CPP} ${L14_09_TASK_03_H})

###
set(L14_10 "${L14}2021.09.19/")

set(L14_10_TASK_01 "${L14_10}01. Virtual Book/")
file(GLOB L14_10_TASK_01_H ${L14_10_TASK_01}/*.h)
file(GLOB L14_10_TASK_01_CPP ${L14_10_TASK_01}/*.cpp)
add_executable(L14_10_T01.VirtualBook ${L14_10_TASK_01_CPP} ${L14_10_TASK_01_H})

set(L14_10_TASK_02 "${L14_10}02. Vehicles/")
file(GLOB L14_10_TASK_02_H ${L14_10_TASK_02}/*.h)
file(GLOB L14_10_TASK_02_CPP ${L14_10_TASK_02}/*.cpp)
add_executable(L14_10_T02.Vehicles ${L14_10_TASK_02_CPP} ${L14_10_TASK_02_H})

set(L14_10_TASK_03 "${L14_10}03. Bomberman Reforged/")
file(GLOB L14_10_TASK_03_H ${L14_10_TASK_03}/*.h)
file(GLOB L14_10_TASK_03_CPP ${L14_10_TASK_03}/*.cpp)
add_executable(L14_10_T03.BombermanReforged ${L14_10_TASK_03_CPP} ${L14_10_TASK_03_H})

###
set(L14_11 "${L14}2022.06.18/")

add_executable(L14_11_T01.MinMaxTemperature ${L14_11}01.\ Min-Max\ Temperature.cpp)
add_executable(L14_11_T02.SumOfOdds ${L14_11}02.\ Sum\ Of\ Odds.cpp)
add_executable(L14_11_T03.Twins ${L14_11}03.\ Twins.cpp)

###
set(L14_12 "${L14}2022.06.25/")

add_executable(L14_12_T01.ShoppingList ${L14_12}01.\ Shopping\ List.cpp)
add_executable(L14_12_T02.TheMatrix ${L14_12}02.\ The\ Matrix.cpp)
add_executable(L14_12_T03.ProductsAndCities ${L14_12}03.\ Products\ and\ Cities.cpp)

###
set(L14_13 "${L14}2023.08.20/")

set(L14_13_TASK_01 "${L14_13}01. Vehicles Statistics/")
file(GLOB L14_13_TASK_01_H ${L14_13_TASK_01}/*.h)
file(GLOB L14_13_TASK_01_CPP ${L14_13_TASK_01}/*.cpp)
add_executable(L14_13_T01.VehiclesStatistics ${L14_13_TASK_01_CPP} ${L14_13_TASK_01_H})

set(L14_13_TASK_02 "${L14_13}02. Library/")
file(GLOB L14_13_TASK_02_H ${L14_13_TASK_02}/*.h)
file(GLOB L14_13_TASK_02_CPP ${L14_13_TASK_02}/*.cpp)
add_executable(L14_13_T02.Library ${L14_13_TASK_02_CPP} ${L14_13_TASK_02_H})

set(L14_13_TASK_03 "${L14_13}03. Cute Animals/")
file(GLOB L14_13_TASK_03_H ${L14_13_TASK_03}/*.h)
file(GLOB L14_13_TASK_03_CPP ${L14_13_TASK_03}/*.cpp)
add_executable(L14_13_T03.CuteAnimals ${L14_13_TASK_03_CPP} ${L14_13_TASK_03_H})

###
set(L14_14 "${L14}2023.08.27/")

set(L14_14_TASK_02 "${L14_14}02. Gas Pumps/")
file(GLOB L14_14_TASK_02_H ${L14_14_TASK_02}/*.h)
file(GLOB L14_14_TASK_02_CPP ${L14_14_TASK_02}/*.cpp)
add_executable(L14_14_T02.GasPumps ${L14_14_TASK_02_CPP} ${L14_14_TASK_02_H})
