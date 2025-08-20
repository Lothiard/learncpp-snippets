### https://www.learncpp.com/cpp-tutorial/aggregation/

> Implement the simplest relationship type that meets the needs of your program, not what seems right in real-life.

### https://www.learncpp.com/cpp-tutorial/array-indexing-and-length-using-enumerators/

> Use a
static_assert
to ensure the length of your constexpr array matches your count enumerator.
Use an
assert
to ensure the length of your non-constexpr array matches your count enumerator.

### https://www.learncpp.com/cpp-tutorial/arrays-loops-and-sign-challenge-solutions/

> Avoid array indexing with integral values whenever possible.

### https://www.learncpp.com/cpp-tutorial/arrays-part-ii/

> Explicitly initialize your arrays (even when the element type is self-initializing).

### https://www.learncpp.com/cpp-tutorial/assert-and-static_assert/

> Favor
static_assert
over
assert()
whenever possible.

### https://www.learncpp.com/cpp-tutorial/bit-flags-and-bit-manipulation-via-stdbitset/

> Bit manipulation is one of the few times when you should unambiguously use unsigned integers (or
std::bitset
).

### https://www.learncpp.com/cpp-tutorial/bitwise-operators/

> To avoid surprises, use the bitwise operators with unsigned integral operands or
std::bitset
.

### https://www.learncpp.com/cpp-tutorial/bitwise-operators/

> Avoid bit shifting on integral types smaller than
int
whenever possible.

### https://www.learncpp.com/cpp-tutorial/break-and-continue/

> Use break and continue when they simplify your loop logic.

### https://www.learncpp.com/cpp-tutorial/break-and-continue/

> Use early returns when they simplify your function’s logic.

### https://www.learncpp.com/cpp-tutorial/c-style-array-decay/

> A function parameter expecting a C-style array type should use the array syntax (e.g.
int arr[]
) rather than pointer syntax (e.g.
int *arr
).

### https://www.learncpp.com/cpp-tutorial/c-style-array-decay/

> Avoid C-style arrays whenever practical.
Prefer
std::string_view
for read-only strings (string literal symbolic constants and string parameters).
Prefer
std::string
for modifiable strings.
Prefer
std::array
for non-global constexpr arrays.
Prefer
std::vector
for non-constexpr arrays.
It is okay to use C-style arrays for global constexpr arrays. We’ll discuss this in a moment.

### https://www.learncpp.com/cpp-tutorial/c-style-array-decay/

> It is okay to use C-style arrays for global constexpr arrays. We’ll discuss this in a moment.

### https://www.learncpp.com/cpp-tutorial/c-style-string-symbolic-constants/

> Avoid C-style string symbolic constants in favor of
constexpr std::string_view
.

### https://www.learncpp.com/cpp-tutorial/c-style-strings/

> Avoid non-const C-style string objects in favor of
std::string
.

### https://www.learncpp.com/cpp-tutorial/chars/

> Single characters should usually be single-quoted, not double-quoted (e.g.
't'
or
'\n'
, not
"t"
or
"\n"
). One possible exception occurs when doing output, where it can be preferential to double quote everything for consistency (see lesson
1.5 -- Introduction to iostream: cout, cin, and endl
).

### https://www.learncpp.com/cpp-tutorial/chars/

> Avoid multicharacter literals (e.g.
'56'
).

### https://www.learncpp.com/cpp-tutorial/class-templates-with-member-functions/

> Any member function templates defined outside the class definition should be defined just below the class definition (in the same file).

### https://www.learncpp.com/cpp-tutorial/classes-and-header-files/

> Prefer to put your class definitions in a header file with the same name as the class. Trivial member functions (such as access functions, constructors with empty bodies, etc…) can be defined inside the class definition.
Prefer to define non-trivial member functions in a source file with the same name as the class.

### https://www.learncpp.com/cpp-tutorial/classes-and-header-files/

> Prefer to define non-trivial member functions in a source file with the same name as the class.

### https://www.learncpp.com/cpp-tutorial/classes-and-header-files/

> Put any default arguments for member functions inside the class definition.

### https://www.learncpp.com/cpp-tutorial/code-coverage/

> Aim for 100% branch coverage of your code.

### https://www.learncpp.com/cpp-tutorial/code-coverage/

> Use the
0, 1, 2 test
to ensure your loops work correctly with different number of iterations.

### https://www.learncpp.com/cpp-tutorial/code-coverage/

> Test different categories of input values to make sure your unit handles them properly.

### https://www.learncpp.com/cpp-tutorial/comments/

> Comment your code liberally, and write your comments as if speaking to someone who has no idea what the code does. Don’t assume you’ll remember why you made specific choices.

### https://www.learncpp.com/cpp-tutorial/compiling-your-first-program/

> Create a new project for each new program you write.

### https://www.learncpp.com/cpp-tutorial/compound-statements-blocks/

> Keep the nesting level of your functions to 3 or less. If your function has a need for more nested levels, consider refactoring your function into sub-functions.

### https://www.learncpp.com/cpp-tutorial/configuring-your-compiler-build-configurations/

> Use the
debug
build configuration when developing your programs. When you’re ready to release your executable to others, or want to test performance, use the
release
build configuration.

### https://www.learncpp.com/cpp-tutorial/configuring-your-compiler-compiler-extensions/

> Disable compiler extensions to ensure your programs (and coding practices) remain compliant with C++ standards and will work on any system.

### https://www.learncpp.com/cpp-tutorial/configuring-your-compiler-warning-and-error-levels/

> Don’t let warnings pile up. Resolve them as you encounter them (as if they were errors). Otherwise a warning about a serious issue may be lost amongst warnings about non-serious issues.

### https://www.learncpp.com/cpp-tutorial/configuring-your-compiler-warning-and-error-levels/

> Turn your warning levels up, especially while you are learning. The additional diagnostic information may help in identifying programming mistakes that can cause your program to malfunction.

### https://www.learncpp.com/cpp-tutorial/configuring-your-compiler-warning-and-error-levels/

> Enable “Treat warnings as errors”. This will force you to resolve all issues causing warnings.

### https://www.learncpp.com/cpp-tutorial/const-class-objects-and-const-member-functions/

> A member function that does not (and will not ever) modify the state of the object should be made const, so that it can be called on both const and non-const objects.

### https://www.learncpp.com/cpp-tutorial/constant-variables-named-constants/

> Place
const
before the type (because it is more conventional to do so).

### https://www.learncpp.com/cpp-tutorial/constant-variables-named-constants/

> Don’t use
const
for value parameters.

### https://www.learncpp.com/cpp-tutorial/constant-variables-named-constants/

> Don’t use
const
when returning by value.

### https://www.learncpp.com/cpp-tutorial/constant-variables-named-constants/

> Make variables constant whenever possible. Exception cases include by-value function parameters and by-value return types, which should generally not be made constant.

### https://www.learncpp.com/cpp-tutorial/constant-variables-named-constants/

> Prefer constant variables over object-like macros with substitution text.

### https://www.learncpp.com/cpp-tutorial/constexpr-aggregates-and-classes/

> If you want your class to be able to be evaluated at compile-time, make your member functions and constructor constexpr.

### https://www.learncpp.com/cpp-tutorial/constexpr-functions-part-2/

> All constexpr functions should be evaluatable at compile-time, as they will be required to do so in contexts that require a constant expression.
Always test your constexpr functions in a context that requires a constant expression, as the constexpr function may work when evaluated at runtime but fail when evaluated at compile-time.

### https://www.learncpp.com/cpp-tutorial/constexpr-functions-part-2/

> Always test your constexpr functions in a context that requires a constant expression, as the constexpr function may work when evaluated at runtime but fail when evaluated at compile-time.

### https://www.learncpp.com/cpp-tutorial/constexpr-functions-part-2/

> Constexpr/consteval functions used in a single source file (.cpp) should be defined in the source file above where they are used.
Constexpr/consteval functions used in multiple source files should be defined in a header file so they can be included into each source file.

### https://www.learncpp.com/cpp-tutorial/constexpr-functions-part-2/

> Constexpr/consteval functions used in multiple source files should be defined in a header file so they can be included into each source file.

### https://www.learncpp.com/cpp-tutorial/constexpr-functions-part-3-and-consteval/

> Use
consteval
if you have a function that must evaluate at compile-time for some reason (e.g. because it does something that can only be done at compile time).

### https://www.learncpp.com/cpp-tutorial/constexpr-functions-part-4/

> Unless you have a specific reason not to, a function that can be evaluated as part of a constant expression should be made
constexpr
(even if it isn’t currently used that way).
A function that cannot be evaluated as part of a required constant expression should not be marked as
constexpr
.

### https://www.learncpp.com/cpp-tutorial/constexpr-functions-part-4/

> A function that cannot be evaluated as part of a required constant expression should not be marked as
constexpr
.

### https://www.learncpp.com/cpp-tutorial/constexpr-if-statements/

> Favor constexpr if statements over non-constexpr if statements when the conditional is a constant expression.

### https://www.learncpp.com/cpp-tutorial/constexpr-variables/

> Any constant variable whose initializer is a constant expression should be declared as
constexpr
.
Any constant variable whose initializer is not a constant expression (making it a runtime constant) should be declared as
const
.
Caveat: In the future we will discuss some types that are not fully compatible with
constexpr
(including
std::string
,
std::vector
, and other types that use dynamic memory allocation). For constant objects of these types, either use
const
instead of
constexpr
, or pick a different type that is constexpr compatible (e.g.
std::string_view
or
std::array
).

### https://www.learncpp.com/cpp-tutorial/constexpr-variables/

> Any constant variable whose initializer is not a constant expression (making it a runtime constant) should be declared as
const
.
Caveat: In the future we will discuss some types that are not fully compatible with
constexpr
(including
std::string
,
std::vector
, and other types that use dynamic memory allocation). For constant objects of these types, either use
const
instead of
constexpr
, or pick a different type that is constexpr compatible (e.g.
std::string_view
or
std::array
).

### https://www.learncpp.com/cpp-tutorial/constexpr-variables/

> Caveat: In the future we will discuss some types that are not fully compatible with
constexpr
(including
std::string
,
std::vector
, and other types that use dynamic memory allocation). For constant objects of these types, either use
const
instead of
constexpr
, or pick a different type that is constexpr compatible (e.g.
std::string_view
or
std::array
).

### https://www.learncpp.com/cpp-tutorial/constructor-member-initializer-lists/

> Member variables in a member initializer list should be listed in order that they are defined in the class.

### https://www.learncpp.com/cpp-tutorial/constructor-member-initializer-lists/

> Prefer using the member initializer list to initialize your members over assigning values in the body of the constructor.

### https://www.learncpp.com/cpp-tutorial/converting-constructors-and-the-explicit-keyword/

> Make any constructor that accepts a single argument
explicit
by default. If an implicit conversion between types is both semantically equivalent and performant, you can consider making the constructor non-explicit.
Do not make copy or move constructors explicit, as these do not perform conversions.

### https://www.learncpp.com/cpp-tutorial/converting-constructors-and-the-explicit-keyword/

> Do not make copy or move constructors explicit, as these do not perform conversions.

### https://www.learncpp.com/cpp-tutorial/default-arguments/

> If the function has a forward declaration (especially one in a header file), put the default argument there. Otherwise, put the default argument in the function definition.

### https://www.learncpp.com/cpp-tutorial/default-constructors-and-default-arguments/

> Prefer value initialization over default initialization for all class types.

### https://www.learncpp.com/cpp-tutorial/default-constructors-and-default-arguments/

> Prefer an explicitly defaulted default constructor (
= default
) over a default constructor with an empty body.

### https://www.learncpp.com/cpp-tutorial/default-member-initialization/

> Provide a default value for all members. This ensures that your members will be initialized even if the variable definition doesn’t include an initializer list.

### https://www.learncpp.com/cpp-tutorial/default-member-initialization/

> For aggregates, prefer value initialization (with an empty braces initializer) to default initialization (with no braces).

### https://www.learncpp.com/cpp-tutorial/delegating-constructors/

> Constructors should not be called directly from the body of another function. Doing so will either result in a compilation error, or will direct-initialize a temporary object.
If you do want a temporary object, prefer list-initialization (which makes it clear you are intending to create an object).

### https://www.learncpp.com/cpp-tutorial/delegating-constructors/

> If you have multiple constructors, consider whether you can use delegating constructors to reduce duplicate code.

### https://www.learncpp.com/cpp-tutorial/delegating-constructors/

> Members for which the user must provide initialization values should be defined first (and as the leftmost parameters of the constructor). Members for which the user can optionally provide initialization values (because the default values are acceptable) should be defined second (and as the rightmost parameters of the constructor).

### https://www.learncpp.com/cpp-tutorial/developing-your-first-program/

> New programmers often try to write an entire program all at once, and then get overwhelmed when it produces a lot of errors. A better strategy is to add one piece at a time, make sure it compiles, and test it. Then when you’re sure it’s working, move on to the next piece.

### https://www.learncpp.com/cpp-tutorial/do-while-statements/

> Favor while loops over do-while when given an equal choice.

### https://www.learncpp.com/cpp-tutorial/dynamic-memory-allocation-with-new-and-delete/

> Set deleted pointers to nullptr unless they are going out of scope immediately afterward.

### https://www.learncpp.com/cpp-tutorial/dynamic-memory-allocation-with-new-and-delete/

> Deleting a null pointer is okay, and does nothing. There is no need to conditionalize your delete statements.

### https://www.learncpp.com/cpp-tutorial/exception-specifications-and-noexcept/

> Always make move constructors, move assignment, and swap functions
noexcept
.
Make copy constructors and copy assignment operators
noexcept
when you can.
Use
noexcept
on other functions to express a no-fail or no-throw guarantee.

### https://www.learncpp.com/cpp-tutorial/exception-specifications-and-noexcept/

> Make copy constructors and copy assignment operators
noexcept
when you can.
Use
noexcept
on other functions to express a no-fail or no-throw guarantee.

### https://www.learncpp.com/cpp-tutorial/exception-specifications-and-noexcept/

> Use
noexcept
on other functions to express a no-fail or no-throw guarantee.

### https://www.learncpp.com/cpp-tutorial/exception-specifications-and-noexcept/

> If you are uncertain whether a function should have a no-fail/no-throw guarantee, err on the side of caution and do not mark it with
noexcept
. Reversing a decision to use noexcept violates an interface commitment to the user about the behavior of the function, and may break existing code. Making guarantees stronger by later adding noexcept to a function that was not originally noexcept is considered safe.

### https://www.learncpp.com/cpp-tutorial/exceptions-classes-and-inheritance/

> Exceptions of a fundamental type can be caught by value since they are cheap to copy.
Exceptions of a class type should be caught by (const) reference to prevent expensive copying and slicing.

### https://www.learncpp.com/cpp-tutorial/explicit-type-conversion-casting-and-static-cast/

> Avoid using C-style casts.

### https://www.learncpp.com/cpp-tutorial/explicit-type-conversion-casting-and-static-cast/

> Favor
static_cast
when you need to convert a value from one type to another type.

### https://www.learncpp.com/cpp-tutorial/explicit-type-conversion-casting-and-static-cast/

> Prefer
static_cast
over initializing a temporary object when a conversion is desired.

### https://www.learncpp.com/cpp-tutorial/external-linkage-and-variable-forward-declarations/

> Only use
extern
for global variable forward declarations or const global variable definitions.
Do not use
extern
for non-const global variable definitions (they are implicitly
extern
).

### https://www.learncpp.com/cpp-tutorial/finding-issues-before-they-become-problems/

> Use a static analysis tool on your programs to help find areas where your code is non-compliant with best practices.

### https://www.learncpp.com/cpp-tutorial/fixed-width-integers-and-size-t/

> Use a fixed-width integer type when you need an integral type that has a guaranteed range.

### https://www.learncpp.com/cpp-tutorial/fixed-width-integers-and-size-t/

> Avoid the fast and least integral types because they may exhibit different behaviors on architectures where they resolve to different sizes.

### https://www.learncpp.com/cpp-tutorial/fixed-width-integers-and-size-t/

> Avoid the following when possible:
short
and
long
integers (prefer a fixed-width integer type instead).
The fast and least integral types (prefer a fixed-width integer type instead).
Unsigned types for holding quantities (prefer a signed integer type instead).
The 8-bit fixed-width integer types (prefer a 16-bit fixed-width integer type instead).
Any compiler-specific fixed-width integers (for example, Visual Studio defines __int8, __int16, etc…)

### https://www.learncpp.com/cpp-tutorial/fixed-width-integers-and-size-t/

> If you use
std::size_t
explicitly in your code, #include one of the headers that defines
std::size_t
(we recommend <cstddef>).
Using
sizeof
does not require a header (even though it returns a value whose type is
std::size_t
).

### https://www.learncpp.com/cpp-tutorial/fixed-width-integers-and-size-t/

> Using
sizeof
does not require a header (even though it returns a value whose type is
std::size_t
).

### https://www.learncpp.com/cpp-tutorial/floating-point-numbers/

> Always make sure the type of your literals match the type of the variables they’re being assigned to or used to initialize. Otherwise an unnecessary conversion will result, possibly with a loss of precision.

### https://www.learncpp.com/cpp-tutorial/floating-point-numbers/

> Favor double over float unless space is at a premium, as the lack of precision in a float will often lead to inaccuracies.

### https://www.learncpp.com/cpp-tutorial/floating-point-numbers/

> Avoid division by
0.0
, even if your compiler supports it.

### https://www.learncpp.com/cpp-tutorial/for-statements/

> Avoid
operator!=
when doing numeric comparisons in the for-loop condition. Prefer
operator<
or
operator<=
where possible.

### https://www.learncpp.com/cpp-tutorial/for-statements/

> Defining multiple variables (in the init-statement) and using the comma operator (in the end-expression) is acceptable inside a for-statement.

### https://www.learncpp.com/cpp-tutorial/for-statements/

> Variables used only inside a loop should be defined inside the scope of the loop.

### https://www.learncpp.com/cpp-tutorial/for-statements/

> Prefer for-loops over while-loops when there is an obvious loop variable.
Prefer while-loops over for-loops when there is no obvious loop variable.

### https://www.learncpp.com/cpp-tutorial/forward-declarations/

> When addressing compilation errors or warnings in your programs, resolve the first issue listed and then compile again.

### https://www.learncpp.com/cpp-tutorial/forward-declarations/

> Keep the parameter names in your function declarations.

### https://www.learncpp.com/cpp-tutorial/friend-non-member-functions/

> A friend function should prefer to use the class interface over direct access whenever possible.

### https://www.learncpp.com/cpp-tutorial/friend-non-member-functions/

> Prefer to implement a function as a non-friend when possible and reasonable.

### https://www.learncpp.com/cpp-tutorial/function-parameters-and-arguments/

> When a function parameter exists but is not used in the body of the function, do not give it a name. You can optionally put a name inside a comment.

### https://www.learncpp.com/cpp-tutorial/function-return-values-value-returning-functions/

> Your
main
function should return the value
0
if the program ran normally.

### https://www.learncpp.com/cpp-tutorial/function-return-values-value-returning-functions/

> Make sure your functions with non-void return types return a value in all cases.
Failure to return a value from a value-returning function will cause undefined behavior.

### https://www.learncpp.com/cpp-tutorial/function-return-values-value-returning-functions/

> Failure to return a value from a value-returning function will cause undefined behavior.

### https://www.learncpp.com/cpp-tutorial/function-return-values-value-returning-functions/

> Follow DRY: “Don’t repeat yourself”. If you need to do something more than once, consider how to modify your code to remove as much redundancy as possible. Variables can be used to store the results of calculations that need to be used more than once (so we don’t have to repeat the calculation). Functions can be used to define a sequence of statements we want to execute more than once. And loops (which we’ll cover in a later chapter) can be used to execute a statement more than once.
Like all best practices, DRY is meant to be a guideline, not an absolute. Reader Yariv has
noted
that DRY can harm overall comprehension when code is broken into pieces that are too small.

### https://www.learncpp.com/cpp-tutorial/function-return-values-value-returning-functions/

> Like all best practices, DRY is meant to be a guideline, not an absolute. Reader Yariv has
noted
that DRY can harm overall comprehension when code is broken into pieces that are too small.

### https://www.learncpp.com/cpp-tutorial/function-template-instantiation/

> Favor the normal function call syntax when making calls to a function instantiated from a function template (unless you need the function template version to be preferred over a matching non-template function).

### https://www.learncpp.com/cpp-tutorial/function-template-instantiation/

> Use function templates to write generic code that can work with a wide variety of types whenever you have the need.

### https://www.learncpp.com/cpp-tutorial/function-templates-with-multiple-template-types/

> Feel free to use abbreviated function templates with a single auto parameter, or where each auto parameter should be an independent type (and your language standard is set to C++20 or newer).

### https://www.learncpp.com/cpp-tutorial/function-templates/

> Use a single capital letter starting with
T
(e.g.
T
,
U
,
V
, etc…) to name type template parameters that are used in trivial or obvious ways and represent “any reasonable type”.
If the type template parameter has a non-obvious usage or specific requirements that must be met, then a more descriptive name is warranted (e.g.
Allocator
or
TAllocator
).

### https://www.learncpp.com/cpp-tutorial/function-templates/

> If the type template parameter has a non-obvious usage or specific requirements that must be met, then a more descriptive name is warranted (e.g.
Allocator
or
TAllocator
).

### https://www.learncpp.com/cpp-tutorial/function-try-blocks/

> Use function try blocks when you need a constructor to handle an exception thrown in the member initializer list.

### https://www.learncpp.com/cpp-tutorial/function-try-blocks/

> Avoid letting control reach the end of a function-level catch block. Instead, explicitly throw, rethrow, or return.

### https://www.learncpp.com/cpp-tutorial/generating-random-numbers-using-mersenne-twister/

> Use
std::random_device
to seed your PRNGs (unless it’s not implemented properly for your target compiler/architecture).

### https://www.learncpp.com/cpp-tutorial/generating-random-numbers-using-mersenne-twister/

> Only seed a given pseudo-random number generator once, and do not reseed it.

### https://www.learncpp.com/cpp-tutorial/goto-statements/

> Avoid goto statements (unless the alternatives are significantly worse for code readability).

### https://www.learncpp.com/cpp-tutorial/halts-exiting-your-program-early/

> Only use a halt if there is no safe or reasonable way to return normally from the main function. If you haven’t disabled exceptions, prefer using exceptions for handling errors safely.

### https://www.learncpp.com/cpp-tutorial/header-files/

> Prefer a .h suffix when naming your header files (unless your project already follows some other convention).
This is a longstanding convention for C++ header files, and most IDEs still default to .h over other options.

### https://www.learncpp.com/cpp-tutorial/header-files/

> This is a longstanding convention for C++ header files, and most IDEs still default to .h over other options.

### https://www.learncpp.com/cpp-tutorial/header-files/

> If a header file is paired with a code file (e.g. add.h with add.cpp), they should both have the same base name (add).

### https://www.learncpp.com/cpp-tutorial/header-files/

> Do not put function and variable definitions in your header files (for now).
Defining either of these in a header file will likely result in a violation of the one-definition rule (ODR) if that header is then #included into more than one source (.cpp) file.

### https://www.learncpp.com/cpp-tutorial/header-files/

> Defining either of these in a header file will likely result in a violation of the one-definition rule (ODR) if that header is then #included into more than one source (.cpp) file.

### https://www.learncpp.com/cpp-tutorial/header-files/

> Source files should #include their paired header file (if one exists).

### https://www.learncpp.com/cpp-tutorial/header-files/

> Avoid #including .cpp files.

### https://www.learncpp.com/cpp-tutorial/header-files/

> Use the standard library header files without the .h extension. User-defined headers should still use a .h extension.

### https://www.learncpp.com/cpp-tutorial/header-files/

> Each file should explicitly #include all of the header files it needs to compile. Do not rely on headers included transitively from other headers.

### https://www.learncpp.com/cpp-tutorial/header-files/

> To maximize the chance that missing includes will be flagged by compiler, order your #includes as follows (skipping any that are not relevant):
The paired header file for this code file (e.g.
add.cpp
should
#include "add.h"
)
Other headers from the same project (e.g.
#include "mymath.h"
)
3rd party library headers (e.g.
#include <boost/tuple/tuple.hpp>
)
Standard library headers (e.g.
#include <iostream>
)
The headers for each grouping should be sorted alphabetically (unless the documentation for a 3rd party library instructs you to do otherwise).

### https://www.learncpp.com/cpp-tutorial/header-files/

> The headers for each grouping should be sorted alphabetically (unless the documentation for a 3rd party library instructs you to do otherwise).

### https://www.learncpp.com/cpp-tutorial/if-statements-and-blocks/

> Consider putting single statements associated with an
if
or
else
in blocks (particularly while you are learning). More experienced C++ developers sometimes disregard this practice in favor of tighter vertical spacing.

### https://www.learncpp.com/cpp-tutorial/in-and-out-parameters/

> Avoid out-parameters (except in the rare case where no better options exist).
Prefer pass by reference for non-optional out-parameters.

### https://www.learncpp.com/cpp-tutorial/in-and-out-parameters/

> Prefer pass by reference for non-optional out-parameters.

### https://www.learncpp.com/cpp-tutorial/increment-decrement-operators-and-side-effects/

> Favor the prefix versions, as they are more performant and less likely to cause surprises.

### https://www.learncpp.com/cpp-tutorial/inheritance-and-access-specifiers/

> Favor private members over protected members.

### https://www.learncpp.com/cpp-tutorial/inheritance-and-access-specifiers/

> Use public inheritance unless you have a specific reason to do otherwise.

### https://www.learncpp.com/cpp-tutorial/inline-functions-and-variables/

> Do not use the
inline
keyword to request inline expansion for your functions.

### https://www.learncpp.com/cpp-tutorial/inline-functions-and-variables/

> Avoid the use of the
inline
keyword unless you have a specific, compelling reason to do so (e.g. you’re defining those functions or variables in a header file).

### https://www.learncpp.com/cpp-tutorial/internal-linkage/

> Give identifiers internal linkage when you have an explicit reason to disallow access from other files.
Consider giving all identifiers you don’t want accessible to other files internal linkage (use an unnamed namespace for this).

### https://www.learncpp.com/cpp-tutorial/internal-linkage/

> Consider giving all identifiers you don’t want accessible to other files internal linkage (use an unnamed namespace for this).

### https://www.learncpp.com/cpp-tutorial/introduction-to-c-style-arrays/

> Prefer omitting the length of a C-style array when explicitly initializing every array element with a value.

### https://www.learncpp.com/cpp-tutorial/introduction-to-cpp-development/

> Name the first/primary source code file in each program
main.cpp
. This makes it easy to determine which source code file is the primary one.

### https://www.learncpp.com/cpp-tutorial/introduction-to-function-overloading/

> Use function overloading to make your program simpler.

### https://www.learncpp.com/cpp-tutorial/introduction-to-function-parameters-and-arguments/

> When a function parameter exists but is not used in the body of the function, do not give it a name. You can optionally put a name inside a comment.

### https://www.learncpp.com/cpp-tutorial/introduction-to-global-variables/

> Prefer defining global variables inside a namespace rather than in the global namespace.

### https://www.learncpp.com/cpp-tutorial/introduction-to-global-variables/

> Consider using a “g” or “g_” prefix when naming global variables (especially those defined in the global namespace), to help differentiate them from local variables and function parameters.

### https://www.learncpp.com/cpp-tutorial/introduction-to-iostream-cout-cin-and-endl/

> Output a newline whenever a line of output is complete.

### https://www.learncpp.com/cpp-tutorial/introduction-to-iostream-cout-cin-and-endl/

> Prefer
\n
over
std::endl
when outputting text to the console.

### https://www.learncpp.com/cpp-tutorial/introduction-to-lambdas-anonymous-functions/

> Following the best practice of defining things in the smallest scope and closest to first use, lambdas are preferred over normal functions when we need a trivial, one-off function to pass as an argument to some other function.

### https://www.learncpp.com/cpp-tutorial/introduction-to-lambdas-anonymous-functions/

> When storing a lambda in a variable, use
auto
as the variable’s type.
When passing a lambda to a function:
If C++20 capable, use
auto
as the parameter’s type.
Otherwise, use a function with a type template parameter or
std::function
parameter (or a function pointer if the lambda has no captures).

### https://www.learncpp.com/cpp-tutorial/introduction-to-lambdas-anonymous-functions/

> When passing a lambda to a function:
If C++20 capable, use
auto
as the parameter’s type.
Otherwise, use a function with a type template parameter or
std::function
parameter (or a function pointer if the lambda has no captures).

### https://www.learncpp.com/cpp-tutorial/introduction-to-local-scope/

> Define your local variables as close to their first use as reasonable.

### https://www.learncpp.com/cpp-tutorial/introduction-to-local-scope/

> When a variable is needed within a function:
Use a function parameter when the caller will pass in the initialization value for the variable as an argument.
Use a local variable otherwise.

### https://www.learncpp.com/cpp-tutorial/introduction-to-loops-and-while-statements/

> Favor
while(true)
for intentional infinite loops.

### https://www.learncpp.com/cpp-tutorial/introduction-to-loops-and-while-statements/

> Integral loop variables should generally be a signed integral type.

### https://www.learncpp.com/cpp-tutorial/introduction-to-objects-and-variables/

> Although the language allows you to do so, avoid defining multiple variables of the same type in a single statement. Instead, define each variable in a separate statement on its own line (and then use a single-line comment to document what it is used for).

### https://www.learncpp.com/cpp-tutorial/introduction-to-operator-overloading/

> An overloaded operator should operate on at least one program-defined type (either as a parameter of the function, or the implicit object).

### https://www.learncpp.com/cpp-tutorial/introduction-to-operator-overloading/

> When overloading operators, it’s best to keep the function of the operators as close to the original intent of the operators as possible.

### https://www.learncpp.com/cpp-tutorial/introduction-to-operator-overloading/

> If the meaning of an overloaded operator is not clear and intuitive, use a named function instead.

### https://www.learncpp.com/cpp-tutorial/introduction-to-operator-overloading/

> Operators that do not modify their operands (e.g. arithmetic operators) should generally return results by value.
Operators that modify their leftmost operand (e.g. pre-increment, any of the assignment operators) should generally return the leftmost operand by reference.

### https://www.learncpp.com/cpp-tutorial/introduction-to-operator-overloading/

> Operators that modify their leftmost operand (e.g. pre-increment, any of the assignment operators) should generally return the leftmost operand by reference.

### https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/

> When declaring a pointer type, place the asterisk next to the type name.

### https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/

> Always initialize your pointers.

### https://www.learncpp.com/cpp-tutorial/introduction-to-program-defined-user-defined-types/

> Name your program-defined types starting with a capital letter and do not use a suffix.

### https://www.learncpp.com/cpp-tutorial/introduction-to-program-defined-user-defined-types/

> A program-defined type used in only one code file should be defined in that code file as close to the first point of use as possible.
A program-defined type used in multiple code files should be defined in a header file with the same name as the program-defined type and then #included into each code file as needed.

### https://www.learncpp.com/cpp-tutorial/introduction-to-program-defined-user-defined-types/

> A program-defined type used in multiple code files should be defined in a header file with the same name as the program-defined type and then #included into each code file as needed.

### https://www.learncpp.com/cpp-tutorial/introduction-to-programming-languages/

> Best practices are things that you
should
do, because that way of doing things is either conventional (idiomatic) or recommended. That is, either everybody does it that way (and if you do otherwise, you’ll be doing something people don’t expect), or it is generally superior to the alternatives.

### https://www.learncpp.com/cpp-tutorial/introduction-to-standard-library-algorithms/

> Before using a particular algorithm, make sure performance and execution order guarantees work for your particular use case.

### https://www.learncpp.com/cpp-tutorial/introduction-to-standard-library-algorithms/

> Favor using functions from the algorithms library over writing your own functionality to do the same thing.

### https://www.learncpp.com/cpp-tutorial/introduction-to-stdarray/

> Use
std::array
for constexpr arrays, and
std::vector
for non-constexpr arrays.

### https://www.learncpp.com/cpp-tutorial/introduction-to-stdarray/

> Define your
std::array
as constexpr whenever possible. If your
std::array
is not constexpr, consider using a
std::vector
instead.

### https://www.learncpp.com/cpp-tutorial/introduction-to-stdarray/

> Use class template argument deduction (CTAD) to have the compiler deduce the type and length of a
std::array
from its initializers.

### https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring/

> If using
std::getline()
to read strings, use
std::cin >> std::ws
input manipulator to ignore leading whitespace. This needs to be done for each
std::getline()
call, as
std::ws
is not preserved across calls.

### https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring/

> Do not pass
std::string
by value, as it makes an expensive copy.

### https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring_view/

> Prefer
std::string_view
over
std::string
when you need a read-only string, especially for function parameters.

### https://www.learncpp.com/cpp-tutorial/introduction-to-stdvector-and-list-constructors/

> Use list initialization with an initializer list of values to construct a container with those element values.

### https://www.learncpp.com/cpp-tutorial/introduction-to-stdvector-and-list-constructors/

> When constructing a container (or any type that has a list constructor) with initializers that are not element values, use direct initialization.

### https://www.learncpp.com/cpp-tutorial/introduction-to-testing-your-code/

> Write your program in small, well defined units (functions or classes), compile often, and test your code as you go.

### https://www.learncpp.com/cpp-tutorial/introduction-to-the-copy-constructor/

> Copy constructors should have no side effects beyond copying.

### https://www.learncpp.com/cpp-tutorial/introduction-to-the-copy-constructor/

> Prefer the implicit copy constructor, unless you have a specific reason to create your own.

### https://www.learncpp.com/cpp-tutorial/introduction-to-the-copy-constructor/

> If you write your own copy constructor, the parameter should be a const lvalue reference.

### https://www.learncpp.com/cpp-tutorial/introduction-to-the-preprocessor/

> Macro names should be written in all uppercase letters, with words separated by underscores.

### https://www.learncpp.com/cpp-tutorial/introduction-to-the-preprocessor/

> Avoid macros with substitution text unless no viable alternatives exist.

### https://www.learncpp.com/cpp-tutorial/keywords-and-naming-identifiers/

> When working in an existing program, use the conventions of that program (even if they don’t conform to modern best practices). Use modern best practices when you’re writing new programs.

### https://www.learncpp.com/cpp-tutorial/lambda-captures/

> Only initialize variables in the capture if their value is short and their type is obvious. Otherwise it’s best to define the variable outside of the lambda and capture it.

### https://www.learncpp.com/cpp-tutorial/lambda-captures/

> Try to avoid mutable lambdas. Non-mutable lambdas are easier to understand and don’t suffer from the above issues, as well as more dangerous issues that arise when you add parallel execution.

### https://www.learncpp.com/cpp-tutorial/literals/

> Prefer literal suffix L (upper case) over l (lower case).

### https://www.learncpp.com/cpp-tutorial/literals/

> Avoid magic numbers in your code (use constexpr variables instead, see lesson
5.6 -- Constexpr variables
).

### https://www.learncpp.com/cpp-tutorial/local-variables/

> Define variables in the most limited existing scope. Avoid creating new blocks whose only purpose is to limit the scope of variables.

### https://www.learncpp.com/cpp-tutorial/logical-operators/

> If
logical NOT
is intended to operate on the result of other operators, the other operators and their operands need to be enclosed in parentheses.

### https://www.learncpp.com/cpp-tutorial/logical-operators/

> When mixing
logical AND
and
logical OR
in a single expression, explicitly parenthesize each operation to ensure they evaluate how you intend.

### https://www.learncpp.com/cpp-tutorial/lvalue-references-to-const/

> Favor
lvalue references to const
over
lvalue references to non-const
unless you need to modify the object being referenced.

### https://www.learncpp.com/cpp-tutorial/lvalue-references/

> When defining a reference, place the ampersand next to the type (not the reference variable’s name).

### https://www.learncpp.com/cpp-tutorial/member-functions-returning-references-to-data-members/

> A member function returning a reference should return a reference of the same type as the data member being returned, to avoid unnecessary conversions.

### https://www.learncpp.com/cpp-tutorial/member-functions-returning-references-to-data-members/

> Prefer to use the return value of a member function that returns by reference immediately, to avoid issues with dangling references when the implicit object is an rvalue.

### https://www.learncpp.com/cpp-tutorial/member-functions/

> Member functions can be used with both structs and classes.
However, structs should avoid defining constructor member functions, as doing so makes them a non-aggregate.

### https://www.learncpp.com/cpp-tutorial/member-functions/

> However, structs should avoid defining constructor member functions, as doing so makes them a non-aggregate.

### https://www.learncpp.com/cpp-tutorial/member-functions/

> If your class type has no data members, prefer using a namespace.

### https://www.learncpp.com/cpp-tutorial/member-selection-with-pointers-and-references/

> When using a pointer to access a member, use the member selection from pointer operator (->) instead of the member selection operator (.).

### https://www.learncpp.com/cpp-tutorial/multiple-inheritance/

> Avoid multiple inheritance unless alternatives lead to more complexity.

### https://www.learncpp.com/cpp-tutorial/naming-collisions-and-an-introduction-to-namespaces/

> Use explicit namespace prefixes to access identifiers defined in a namespace.

### https://www.learncpp.com/cpp-tutorial/narrowing-conversions-list-initialization-and-constexpr-initializers/

> Because they can be unsafe and are a source of errors, avoid narrowing conversions whenever possible.

### https://www.learncpp.com/cpp-tutorial/narrowing-conversions-list-initialization-and-constexpr-initializers/

> If you need to perform a narrowing conversion, use
static_cast
to convert it into an explicit conversion.

### https://www.learncpp.com/cpp-tutorial/nested-types-member-types/

> Define any nested types at the top of your class type.

### https://www.learncpp.com/cpp-tutorial/non-static-member-initialization/

> Provide a default value for all members. This ensures that your members will be initialized even if the variable definition doesn’t include an initializer list.

### https://www.learncpp.com/cpp-tutorial/non-static-member-initialization/

> For aggregates, prefer value initialization (with an empty braces initializer) to default initialization (with no braces).

### https://www.learncpp.com/cpp-tutorial/non-type-template-parameters/

> Use
N
as the name of an int non-type template parameter.

### https://www.learncpp.com/cpp-tutorial/null-pointers/

> Value initialize your pointers (to be null pointers) if you are not initializing them with the address of a valid object.

### https://www.learncpp.com/cpp-tutorial/null-pointers/

> Use
nullptr
when you need a null pointer literal for initialization, assignment, or passing a null pointer to a function.

### https://www.learncpp.com/cpp-tutorial/null-pointers/

> A pointer should either hold the address of a valid object, or be set to nullptr. That way we only need to test pointers for null, and can assume any non-null pointer is valid.

### https://www.learncpp.com/cpp-tutorial/null-pointers/

> Favor references over pointers unless the additional capabilities provided by pointers are needed.

### https://www.learncpp.com/cpp-tutorial/operator-precedence-and-associativity/

> Use parentheses to make it clear how a non-trivial compound expression should evaluate (even if they are technically unnecessary).

### https://www.learncpp.com/cpp-tutorial/operator-precedence-and-associativity/

> Expressions with a single assignment operator do not need to have the right operand of the assignment wrapped in parenthesis.

### https://www.learncpp.com/cpp-tutorial/overloading-operators-using-normal-functions/

> Prefer overloading operators as normal functions instead of friends if it’s possible to do so without adding additional functions.

### https://www.learncpp.com/cpp-tutorial/overloading-the-comparison-operators/

> Only define overloaded operators that make intuitive sense for your class.

### https://www.learncpp.com/cpp-tutorial/overloading-typecasts/

> Just like single-parameter converting constructors should be marked as explicit, typecasts should be marked as explicit, except in cases where the type to be converted to is essentially synonymous with the destination type.

### https://www.learncpp.com/cpp-tutorial/overloading-typecasts/

> When possible, prefer converting constructors, and avoid overloaded typecasts.

### https://www.learncpp.com/cpp-tutorial/overloading-typecasts/

> When you need to define how convert type A to type B:
If B is a class type you can modify, prefer using a converting constructor to create B from A.
Otherwise, if A is a class type you can modify, use an overloaded typecast to convert A to B.
Otherwise use a non-member function to convert A to B.

### https://www.learncpp.com/cpp-tutorial/pass-by-address/

> Prefer pointer-to-const function parameters over pointer-to-non-const function parameters, unless the function needs to modify the object passed in.
Do not make function parameters const pointers unless there is some specific reason to do so.

### https://www.learncpp.com/cpp-tutorial/pass-by-address/

> Prefer pass by reference to pass by address unless you have a specific reason to use pass by address.

### https://www.learncpp.com/cpp-tutorial/pass-by-const-lvalue-reference/

> Favor passing by const reference over passing by non-const reference unless you have a specific reason to do otherwise (e.g. the function needs to change the value of an argument).

### https://www.learncpp.com/cpp-tutorial/pass-by-const-lvalue-reference/

> As a rule of thumb, pass fundamental types by value and class types by const reference.
If you aren’t sure what to do, pass by const reference, as you’re less likely to encounter unexpected behavior.

### https://www.learncpp.com/cpp-tutorial/pass-by-const-lvalue-reference/

> If you aren’t sure what to do, pass by const reference, as you’re less likely to encounter unexpected behavior.

### https://www.learncpp.com/cpp-tutorial/pass-by-const-lvalue-reference/

> Prefer passing strings using
std::string_view
(by value) instead of
const std::string&
, unless your function calls other functions that require C-style strings or
std::string
parameters.

### https://www.learncpp.com/cpp-tutorial/passing-arguments-by-value/

> When a function parameter exists but is not used in the body of the function, do not give it a name. You can optionally put a name inside a comment.

### https://www.learncpp.com/cpp-tutorial/pointer-arithmetic-and-subscripting/

> Favor subscripting when indexing from the start of the array (element 0), so the array indices line up with the element.
Favor pointer arithmetic when doing relative positioning from a given element.

### https://www.learncpp.com/cpp-tutorial/pointer-arithmetic-and-subscripting/

> Favor pointer arithmetic when doing relative positioning from a given element.

### https://www.learncpp.com/cpp-tutorial/programs-with-multiple-code-files/

> When you add new code files to your project, give them a .cpp extension.

### https://www.learncpp.com/cpp-tutorial/public-and-private-members-and-access-specifiers/

> Consider naming your private data members starting with an “m_” prefix to help distinguish them from the names of local variables, function parameters, and member functions.
Public members of classes may also follow this convention if desired. However, the public members of structs typically do not use this prefix since structs generally do not have many member functions (if any).

### https://www.learncpp.com/cpp-tutorial/public-and-private-members-and-access-specifiers/

> Public members of classes may also follow this convention if desired. However, the public members of structs typically do not use this prefix since structs generally do not have many member functions (if any).

### https://www.learncpp.com/cpp-tutorial/public-and-private-members-and-access-specifiers/

> Classes should generally make member variables private (or protected), and member functions public.
Structs should generally avoid using access specifiers (all members will default to public).

### https://www.learncpp.com/cpp-tutorial/public-and-private-members-and-access-specifiers/

> Structs should generally avoid using access specifiers (all members will default to public).

### https://www.learncpp.com/cpp-tutorial/range-based-for-loops-for-each/

> Favor range-based for loops over regular for-loops when traversing containers.

### https://www.learncpp.com/cpp-tutorial/range-based-for-loops-for-each/

> Use type deduction (
auto
) with range-based for loops to have the compiler deduce the type of the array element.

### https://www.learncpp.com/cpp-tutorial/range-based-for-loops-for-each/

> For range-based for loops, prefer to define the element type as:
auto
when you want to modify copies of the elements.
auto&
when you want to modify the original elements.
const auto&
otherwise (when you just need to view the original elements).

### https://www.learncpp.com/cpp-tutorial/recursion/

> Generally favor iteration over recursion, except when recursion really makes sense.

### https://www.learncpp.com/cpp-tutorial/relational-operators-and-floating-point-comparisons/

> Don’t add unnecessary == or != to conditions. It makes them harder to read without offering any additional value.

### https://www.learncpp.com/cpp-tutorial/remainder-and-exponentiation/

> Prefer to compare the result of the remainder operator (
operator%
) against 0 if possible.

### https://www.learncpp.com/cpp-tutorial/return-by-reference-and-return-by-address/

> Avoid returning references to non-const local static variables.

### https://www.learncpp.com/cpp-tutorial/return-by-reference-and-return-by-address/

> Prefer return by reference over return by address unless the ability to return “no object” (using
nullptr
) is important.

### https://www.learncpp.com/cpp-tutorial/scoped-enumerations-enum-classes/

> Favor scoped enumerations over unscoped enumerations unless there’s a compelling reason to do otherwise.

### https://www.learncpp.com/cpp-tutorial/sharing-global-constants-across-multiple-files-using-inline-variables/

> If you need global constants and your compiler is C++17 capable, prefer defining inline constexpr global variables in a header file.

### https://www.learncpp.com/cpp-tutorial/signed-integers/

> Prefer the shorthand types that do not use the
int
suffix or
signed
prefix.

### https://www.learncpp.com/cpp-tutorial/static-local-variables/

> Initialize your static local variables. Static local variables are only initialized the first time the code is executed, not on subsequent calls.

### https://www.learncpp.com/cpp-tutorial/static-local-variables/

> Const static local variables are generally okay to use.
Non-const static local variables should generally be avoided. If you do use them, ensure the variable never needs to be reset, and isn’t used to alter program flow.

### https://www.learncpp.com/cpp-tutorial/static-local-variables/

> Non-const static local variables should generally be avoided. If you do use them, ensure the variable never needs to be reset, and isn’t used to alter program flow.

### https://www.learncpp.com/cpp-tutorial/static-member-variables/

> Access static members using the class name and the scope resolution operator (::).

### https://www.learncpp.com/cpp-tutorial/static-member-variables/

> Make your static members
inline
or
constexpr
so they can be initialized inside the class definition.

### https://www.learncpp.com/cpp-tutorial/stdinitializer_list/

> When initializing a container that has a list constructor:
Use brace initialization when intending to call the list constructor (e.g. because your initializers are element values)
Use direct initialization when intending to call a non-list constructor (e.g. because your initializers are not element values).

### https://www.learncpp.com/cpp-tutorial/stdinitializer_list/

> If you provide list construction, it’s a good idea to provide list assignment as well.

### https://www.learncpp.com/cpp-tutorial/stdoptional/

> Return a
std::optional
(instead of a sentinel value) for functions that may fail, unless your function needs to return additional information about why it failed.

### https://www.learncpp.com/cpp-tutorial/stdoptional/

> Prefer
std::optional
for optional return types.
Prefer function overloading for optional function parameters (when possible). Otherwise, use
std::optional<T>
for optional arguments when
T
would normally be passed by value. Favor
const T*
when
T
is expensive to copy.

### https://www.learncpp.com/cpp-tutorial/stdoptional/

> Prefer function overloading for optional function parameters (when possible). Otherwise, use
std::optional<T>
for optional arguments when
T
would normally be passed by value. Favor
const T*
when
T
is expensive to copy.

### https://www.learncpp.com/cpp-tutorial/stdshared_ptr/

> Always make a copy of an existing std::shared_ptr if you need more than one std::shared_ptr pointing to the same resource.

### https://www.learncpp.com/cpp-tutorial/stdunique_ptr/

> Favor std::array, std::vector, or std::string over a smart pointer managing a fixed array, dynamic array, or C-style string.

### https://www.learncpp.com/cpp-tutorial/stdunique_ptr/

> Use std::make_unique() instead of creating std::unique_ptr and using new yourself.

### https://www.learncpp.com/cpp-tutorial/stdvector-and-stack-behavior/

> Prefer
emplace_back()
when creating a new temporary object to add to the container, or when you need to access an explicit constructor.
Prefer
push_back()
otherwise.
This article
has more explanation for this best practice.

### https://www.learncpp.com/cpp-tutorial/stdvector-and-stack-behavior/

> Prefer
push_back()
otherwise.
This article
has more explanation for this best practice.

### https://www.learncpp.com/cpp-tutorial/stdvector-and-stack-behavior/

> This article
has more explanation for this best practice.

### https://www.learncpp.com/cpp-tutorial/stdvector-bool/

> Favor
constexpr std::bitset
,
std::vector<char>
, or 3rd party dynamic bitsets over
std::vector<bool>
.

### https://www.learncpp.com/cpp-tutorial/struct-aggregate-initialization/

> Prefer the (non-copy) braced list form when initializing aggregates.

### https://www.learncpp.com/cpp-tutorial/struct-aggregate-initialization/

> When adding a new member to an aggregate, it’s safest to add it to the bottom of the definition list so the initializers for other members don’t shift.

### https://www.learncpp.com/cpp-tutorial/struct-miscellany/

> In most cases, we want our structs (and classes) to be owners. The easiest way to enable this is to ensure each data member has an owning type (e.g. not a viewer, pointer, or reference).

### https://www.learncpp.com/cpp-tutorial/switch-fallthrough-and-scoping/

> Use the
[[fallthrough]]
attribute (along with a null statement) to indicate intentional fallthrough.

### https://www.learncpp.com/cpp-tutorial/switch-fallthrough-and-scoping/

> If defining variables used in a case statement, do so in a block inside the case.

### https://www.learncpp.com/cpp-tutorial/switch-statement-basics/

> Place the default case last in the switch block.

### https://www.learncpp.com/cpp-tutorial/switch-statement-basics/

> Each set of statements underneath a label should end in a break-statement or a return-statement. This includes the statements underneath the last label in the switch.

### https://www.learncpp.com/cpp-tutorial/switch-statement-basics/

> Prefer not to indent labels. This allows them to stand out from the surrounding code without implying that they are defining a nested scope region.

### https://www.learncpp.com/cpp-tutorial/switch-statement-basics/

> Prefer a switch-statement over if-else statements when testing a single expression (with a non-boolean integral type or an enumerated type) for equality against a small set of values.

### https://www.learncpp.com/cpp-tutorial/temporary-class-objects/

> As a quick rule of thumb: Prefer
static_cast
when converting to a fundamental type, and a list-initialized temporary when converting to a class type.
Prefer
static_cast
when to create a temporary object when any of the following are true:
We need to performing a narrowing conversion.
We want to make it really obvious that we’re converting to a type that will result in some different behavior (e.g. a
char
to an
int
).
We want to use direct-initialization for some reason (e.g. to avoid list constructors taking precedence).
Prefer creating a new object (using list initialization) to create a temporary object when any of the following are true:
We want to use list-initialization (e.g. for the protection against narrowing conversions, or because we need to invoke a list constructor).
We need to provide additional arguments to a constructor to facilitate the conversion.

### https://www.learncpp.com/cpp-tutorial/temporary-class-objects/

> Prefer
static_cast
when to create a temporary object when any of the following are true:
We need to performing a narrowing conversion.
We want to make it really obvious that we’re converting to a type that will result in some different behavior (e.g. a
char
to an
int
).
We want to use direct-initialization for some reason (e.g. to avoid list constructors taking precedence).
Prefer creating a new object (using list initialization) to create a temporary object when any of the following are true:
We want to use list-initialization (e.g. for the protection against narrowing conversions, or because we need to invoke a list constructor).
We need to provide additional arguments to a constructor to facilitate the conversion.

### https://www.learncpp.com/cpp-tutorial/temporary-class-objects/

> Prefer creating a new object (using list initialization) to create a temporary object when any of the following are true:
We want to use list-initialization (e.g. for the protection against narrowing conversions, or because we need to invoke a list constructor).
We need to provide additional arguments to a constructor to facilitate the conversion.

### https://www.learncpp.com/cpp-tutorial/the-benefits-of-data-hiding-encapsulation/

> Prefer implementing functions as non-members when possible (especially functions that contain application specific data or logic).

### https://www.learncpp.com/cpp-tutorial/the-benefits-of-data-hiding-encapsulation/

> Declare public members first, protected members next, and private members last. This spotlights the public interface and de-emphasizes implementation details.

### https://www.learncpp.com/cpp-tutorial/the-comma-operator/

> Avoid using the comma operator, except within
for loops
.

### https://www.learncpp.com/cpp-tutorial/the-conditional-operator/

> Parenthesize the entire conditional operation (including operands) when used in a compound expression.
For readability, consider parenthesizing the condition if it contains any operators (other than the function call operator).

### https://www.learncpp.com/cpp-tutorial/the-conditional-operator/

> For readability, consider parenthesizing the condition if it contains any operators (other than the function call operator).

### https://www.learncpp.com/cpp-tutorial/the-conditional-operator/

> Prefer to avoid the conditional operator in complicated expressions.

### https://www.learncpp.com/cpp-tutorial/the-override-and-final-specifiers-and-covariant-return-types/

> Use the virtual keyword on virtual functions in a base class.
Use the override specifier (but not the virtual keyword) on override functions in derived classes. This includes virtual destructors.

### https://www.learncpp.com/cpp-tutorial/the-override-and-final-specifiers-and-covariant-return-types/

> Use the override specifier (but not the virtual keyword) on override functions in derived classes. This includes virtual destructors.

### https://www.learncpp.com/cpp-tutorial/type-deduction-for-functions/

> Prefer explicit return types over return type deduction (except in cases where the return type is unimportant, difficult to express, or fragile).

### https://www.learncpp.com/cpp-tutorial/type-deduction-for-objects-using-the-auto-keyword/

> Use type deduction for your variables when the type of the object doesn’t matter.
Favor an explicit type when you require a specific type that differs from the type of the initializer, or when your object is used in a context where making the type obvious is useful.

### https://www.learncpp.com/cpp-tutorial/type-deduction-for-objects-using-the-auto-keyword/

> Favor an explicit type when you require a specific type that differs from the type of the initializer, or when your object is used in a context where making the type obvious is useful.

### https://www.learncpp.com/cpp-tutorial/type-deduction-with-pointers-references-and-const/

> If you want a const reference, reapply the
const
qualifier even when it’s not strictly necessary, as it makes your intent clear and helps prevent mistakes.

### https://www.learncpp.com/cpp-tutorial/type-deduction-with-pointers-references-and-const/

> If you want a const pointer, pointer to const, or const pointer to const, reapply the
const
qualifier(s) even when it’s not strictly necessary, as it makes your intent clear and helps prevent mistakes.

### https://www.learncpp.com/cpp-tutorial/typedefs-and-type-aliases/

> Name your type aliases starting with a capital letter and do not use a suffix (unless you have a specific reason to do otherwise).

### https://www.learncpp.com/cpp-tutorial/typedefs-and-type-aliases/

> Prefer type aliases over typedefs.

### https://www.learncpp.com/cpp-tutorial/typedefs-and-type-aliases/

> Use type aliases judiciously, when they provide a clear benefit to code readability or code maintenance.

### https://www.learncpp.com/cpp-tutorial/uninitialized-variables-and-undefined-behavior/

> Avoid implementation-defined and unspecified behavior whenever possible, as they may cause your program to malfunction on other implementations.

### https://www.learncpp.com/cpp-tutorial/unnamed-and-inline-namespaces/

> Prefer unnamed namespaces when you have content you want to keep local to a translation unit.
Avoid unnamed namespaces in header files.

### https://www.learncpp.com/cpp-tutorial/unnamed-and-inline-namespaces/

> Avoid unnamed namespaces in header files.

### https://www.learncpp.com/cpp-tutorial/unscoped-enumerations/

> Name your enumerated types starting with a capital letter. Name your enumerators starting with a lower case letter.

### https://www.learncpp.com/cpp-tutorial/unscoped-enumerations/

> Prefer putting your enumerations inside a named scope region (such as a namespace or class) so the enumerators don’t pollute the global namespace.

### https://www.learncpp.com/cpp-tutorial/unscoped-enumerator-integral-conversions/

> Avoid assigning explicit values to your enumerators unless you have a compelling reason to do so.

### https://www.learncpp.com/cpp-tutorial/unscoped-enumerator-integral-conversions/

> Make the enumerator representing 0 the one that is the best default meaning for your enumeration. If no good default meaning exists, consider adding an “invalid” or “unknown” enumerator that has value 0, so that state is explicitly documented and can be explicitly handled where appropriate.

### https://www.learncpp.com/cpp-tutorial/unscoped-enumerator-integral-conversions/

> Specify the base type of an enumeration only when necessary.

### https://www.learncpp.com/cpp-tutorial/unsigned-integers-and-why-to-avoid-them/

> Favor signed numbers over unsigned numbers for holding quantities (even quantities that should be non-negative) and mathematical operations. Avoid mixing signed and unsigned numbers.

### https://www.learncpp.com/cpp-tutorial/using-declarations-and-using-directives/

> Prefer explicit namespace qualifiers over using-statements.
Avoid using-directives altogether (except
using namespace std::literals
to access the
s
and
sv
literal suffixes). Using-declarations are okay in .cpp files, after the #include directives. Do not use using-statements in header files (especially in the global namespace of header files).

### https://www.learncpp.com/cpp-tutorial/using-declarations-and-using-directives/

> Avoid using-directives altogether (except
using namespace std::literals
to access the
s
and
sv
literal suffixes). Using-declarations are okay in .cpp files, after the #include directives. Do not use using-statements in header files (especially in the global namespace of header files).

### https://www.learncpp.com/cpp-tutorial/using-function-templates-in-multiple-files/

> Templates that are needed in multiple files should be defined in a header file, and then #included wherever needed. This allows the compiler to see the full template definition and instantiate the template when needed.

### https://www.learncpp.com/cpp-tutorial/variable-assignment-and-initialization/

> Prefer direct-list-initialization or value-initialization to initialize your variables.

### https://www.learncpp.com/cpp-tutorial/variable-assignment-and-initialization/

> Initialize your variables upon creation.

### https://www.learncpp.com/cpp-tutorial/variable-shadowing-name-hiding/

> Avoid variable shadowing.

### https://www.learncpp.com/cpp-tutorial/virtual-functions/

> Never call virtual functions from constructors or destructors.

### https://www.learncpp.com/cpp-tutorial/void-functions-non-value-returning-functions/

> Do not put a return statement at the end of a non-value returning function.

### https://www.learncpp.com/cpp-tutorial/void/

> Use an empty parameter list instead of
void
to indicate that a function has no parameters.

### https://www.learncpp.com/cpp-tutorial/whitespace-and-basic-formatting/

> Consider keeping your lines to 80 chars or less in length.

### https://www.learncpp.com/cpp-tutorial/whitespace-and-basic-formatting/

> When working in an existing project, be consistent with whatever style has already been adopted.

### https://www.learncpp.com/cpp-tutorial/whitespace-and-basic-formatting/

> Using the automatic formatting feature is highly recommended to keep your code’s formatting style consistent.

### https://www.learncpp.com/cpp-tutorial/why-non-const-global-variables-are-evil/

> Use local variables instead of global variables whenever possible.

