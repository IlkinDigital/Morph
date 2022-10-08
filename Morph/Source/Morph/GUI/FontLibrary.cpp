#include "FontLibrary.h"

namespace Morph {

    ImFont* Font::GetNative() const
    {
        return m_Fonts[(uint16)m_CurrentWeight];
    }

    void Font::Set(FontWeight weight, const Filepath& path)
    {
        ImGuiIO& io = ImGui::GetIO();
        ImFont* font = io.Fonts->AddFontFromFileTTF(path.string().c_str(), 20.0f);
        
        if (font) 
        {
            m_Fonts[(uint16)weight] = font;
            for (int i = 0; i < 3; i++)
            {
                if (m_Fonts[i] == nullptr)
                    m_Fonts[i] = font;
            }
        }
        else
        {
            MORPH_ERROR("FAILED to retrieve font!");
        }
    }

    void Font::SwitchWeight(FontWeight weight)
    {
        m_CurrentWeight = weight;
    }
}