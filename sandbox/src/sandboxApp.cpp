#include <illusion.h>

class Sandbox : public Illusion::App
{
    public:
    Sandbox()
    {
    }

    ~Sandbox()
    {
    }
};

Illusion::App *Illusion::CreateApp()
{
    return new Sandbox();
}