#pragma once

#include "../../VM/IFalloutOpcode.h"

namespace Falltergeist
{
    namespace VM
    {
        namespace Handler
        {
            class Opcode8132 : virtual public IFalloutOpcode
            {
                public:
                    Opcode8132() = default;
            };
        }
    }
}
