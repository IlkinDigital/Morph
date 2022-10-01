#include "FontLibrary.h"

namespace Morph::GUI {

    ImFont* Font::Get() const
    {
        return m_Fonts[(uint16)m_CurrentWeight];
    }

}