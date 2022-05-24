// Project includes
#include "../Event/Event.h"

// Third-party includes

// stdlib

namespace Falltergeist
{
    namespace Event
    {
        Event::Event(const std::string& name) : _name(name) {
        }

        const std::string& Event::name() const
        {
            return _name;
        }

        bool Event::isHandled() const
        {
            return _handled;
        }

        void Event::stopPropagation()
        {
            _handled = true;
        }
    }
}
