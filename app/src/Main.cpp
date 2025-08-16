//
//  CPU-A
//
//  (c) 2024-2025 TDolphin
//

#include "Main.hpp"

#include "App.hpp"

#include "AOS/Dos/Library.hpp"

#include "amiga_std_light/iostream.hpp"
#include <proto/exec.h>
#include <proto/dos.h>

using namespace std;

long minStackSize = 32000;

void check_stack_size(void) __attribute__((constructor));

void check_stack_size(void)
{
    auto process = AOS::Dos::Library::FindProcess();
    if (!process)
    {
        Printf("Failed to find current process!\n");
        exit(RETURN_FAIL);
    }

    if (process->pr_CLI) // run from CLI
    {
        auto cli = (struct CommandLineInterface *)BADDR(process->pr_CLI);
        if (cli->cli_DefaultStack * 4 < minStackSize)
        {
            Printf("Stack size is too small! Required 32000\n");
            exit(RETURN_FAIL);
        }
    }
    else
    {
        if (process->pr_StackSize < minStackSize)
        {
            Printf("Stack size is too small! Required 32000\n");
            exit(RETURN_FAIL);
        }
    }
}

int main(int argc, char **argv)
{
#ifdef TRACE
    std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif

    try
    {
        App::instance().Run();
    }
    catch (const runtime_error &e)
    {
        cerr << "Runtime exception: " << e.what() << endl;
        return -1;
    }
    catch (const exception &e)
    {
        cerr << "Exception: " << e.what() << endl;
        return RETURN_FAIL;
    }
    catch (...)
    {
        cerr << "Unknown exception (...)" << endl;
        return RETURN_FAIL;
    }

    return RETURN_OK;
}
