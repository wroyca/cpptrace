#include <sstream>
#include <stdexcept>
#include <iostream>

#include <cpptrace/cpptrace.hpp>

#undef NDEBUG
#include <cassert>

int main ()
{
  using namespace std;
  using namespace cpptrace;

  // Basic stacktrace test.
  //
  {
    auto trace = stacktrace::current();
    assert (!trace.empty());
  }

  // Test that we can create and print a trace.
  //
  try
  {
    auto trace = stacktrace::current();
    ostringstream o;
    trace.print(o);
    assert (!o.str().empty());

    // Print the stack trace to stdout
    cout << "Stack trace:" << endl;
    trace.print();
    cout << endl;
  }
  catch (const std::exception& e)
  {
    // Should not throw
    assert(false);
  }
}
