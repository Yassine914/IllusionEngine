#include "defines.h"

namespace Illusion {
class IAPI App
{
    public:
    App();
    virtual ~App();

    void Run();
};

// to be defined in client
App *CreateApp();

} // namespace Illusion