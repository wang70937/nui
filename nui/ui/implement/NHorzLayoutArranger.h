#pragma once


#include "../NLayoutArranger.h"

namespace nui
{
    namespace Ui
    {
        class NHorzLayoutArranger : public NLayoutArranger
        {
        public:
            virtual void RelayoutChild(NFrameBase* child, Base::NSize& size) const;
            virtual bool IfCouldLayout(const NFrameBase* const &child) const;
        };
    }
}